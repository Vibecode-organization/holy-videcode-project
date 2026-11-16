"""FastAPI application: admin panel + MCP endpoint."""
from __future__ import annotations

import asyncio
import hmac
import json
import os
import shutil
import time
from contextlib import asynccontextmanager
from pathlib import Path
from typing import Any

import httpx
from fastapi import BackgroundTasks, Depends, FastAPI, HTTPException, Request, Response
from fastapi.responses import (
    FileResponse,
    HTMLResponse,
    JSONResponse,
    RedirectResponse,
    StreamingResponse,
)
from fastapi.staticfiles import StaticFiles
from pydantic import BaseModel, Field

from . import config, db, files, mcp, mcp_brief, security


# --------------------------------------------------------------------------
# models
# --------------------------------------------------------------------------

class LoginIn(BaseModel):
    username: str = Field(max_length=128)
    password: str = Field(max_length=512)


class FolderIn(BaseModel):
    name: str = Field(max_length=64)
    note: str = Field(default="", max_length=500)


class KeyIn(BaseModel):
    name: str = Field(max_length=80)
    folder: str = Field(max_length=64)
    ttl_days: int = Field(default=0, ge=0, le=3650)
    read_only: bool = False


class MessageIn(BaseModel):
    recipient: str = Field(default="all", max_length=64)
    subject: str = Field(default="", max_length=160)
    body: str = Field(min_length=1, max_length=20000)


class TaskIn(BaseModel):
    title: str = Field(min_length=1, max_length=200)
    detail: str = Field(default="", max_length=20000)
    priority: str = Field(default="normal", max_length=16)


class TaskPatch(BaseModel):
    status: str | None = None
    note: str = Field(default="", max_length=4000)


class PasswordIn(BaseModel):
    current: str = Field(max_length=512)
    new: str = Field(min_length=10, max_length=256)


class SettingsIn(BaseModel):
    public_url: str = Field(default="", max_length=300)


# --------------------------------------------------------------------------
# helpers
# --------------------------------------------------------------------------

def fmt(ts: float | None) -> str:
    if not ts:
        return ""
    return time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(ts))


def is_https(request: Request) -> bool:
    if request.url.scheme == "https":
        return True
    if config.TRUST_PROXY:
        proto = request.headers.get("x-forwarded-proto", "").split(",")[0].strip()
        if proto == "https":
            return True
        if '"scheme":"https"' in request.headers.get("cf-visitor", ""):
            return True
    return False


def stored_public_url() -> str:
    try:
        return (db.get_setting("public_url", "") or config.PUBLIC_URL).rstrip("/")
    except Exception:
        return config.PUBLIC_URL


def request_origin(request: Request) -> str:
    stored = stored_public_url()
    if stored:
        return stored
    proto = request.headers.get("x-forwarded-proto", "").split(",")[0].strip()
    if not proto:
        proto = request.url.scheme
    host = request.headers.get("x-forwarded-host") or request.headers.get("host") or ""
    if host:
        return f"{proto}://{host}".rstrip("/")
    return str(request.base_url).rstrip("/")


def set_session_cookie(response: Response, token: str, request: Request) -> None:
    response.set_cookie(
        config.SESSION_COOKIE,
        token,
        max_age=config.SESSION_TTL,
        httponly=True,
        samesite="lax",
        secure=is_https(request),
        path="/",
    )


def clear_session_cookie(response: Response) -> None:
    response.delete_cookie(config.SESSION_COOKIE, path="/")


def agent_public(row: dict[str, Any]) -> dict[str, Any]:
    now = time.time()
    return {
        "name": row["name"],
        "note": row.get("note") or "",
        "status": row.get("status") or "",
        "status_at": fmt(row.get("status_at")),
        "last_seen": fmt(row.get("last_seen")),
        "online": bool(row.get("last_seen") and now - row["last_seen"] < config.ONLINE_WINDOW),
        "workspace": str(config.AGENTS_DIR / row["name"]),
    }


def key_public(row: dict[str, Any], geo: dict[str, Any] | None = None) -> dict[str, Any]:
    now = time.time()
    revoked = bool(row["revoked"])
    expired = bool(row["expires"] and row["expires"] < now)
    online = bool(row.get("last_used") and now - row["last_used"] < config.ONLINE_WINDOW)
    g = geo or {}
    return {
        "id": row["id"],
        "name": row["name"],
        "prefix": row["prefix"],
        "folder": row["folder"],
        "scopes": row["scopes"],
        "created": fmt(row["created"]),
        "expires": fmt(row["expires"]),
        "revoked": revoked,
        "expired": expired,
        "status": "revoked" if revoked else ("expired" if expired else "active"),
        "last_used": fmt(row.get("last_used")),
        "last_ip": row.get("last_ip") or "",
        "last_ua": row.get("last_ua") or "",
        "requests": row.get("requests") or 0,
        "online": online and not revoked and not expired,
        "country": g.get("country") or "",
        "city": g.get("city") or "",
        "isp": g.get("isp") or "",
    }


def snippets(origin: str, token: str) -> dict[str, str]:
    claude = (
        f'claude mcp add --transport http asuka4scape {origin}{config.MCP_PATH} '
        f'--header "Authorization: Bearer {token}"'
    )
    generic = json.dumps(
        {
            "mcpServers": {
                "asuka4scape": {
                    "type": "http",
                    "url": f"{origin}{config.MCP_PATH}",
                    "headers": {"Authorization": f"Bearer {token}"},
                }
            }
        },
        ensure_ascii=False,
        indent=2,
    )
    opencode = json.dumps(
        {
            "$schema": "https://opencode.ai/config.json",
            "mcp": {
                "servers": {
                    "asuka4scape": {
                        "type": "remote",
                        "url": f"{origin}{config.MCP_PATH}",
                        "oauth": False,
                        "codemode": False,
                        "headers": {"Authorization": f"Bearer {token}"},
                    }
                }
            },
            "permissions": [
                {"action": "shell", "resource": "*", "effect": "deny"},
                {"action": "edit", "resource": "*", "effect": "deny"},
                {"action": "read", "resource": "*", "effect": "deny"},
                {"action": "glob", "resource": "*", "effect": "deny"},
                {"action": "grep", "resource": "*", "effect": "deny"},
                {"action": "webfetch", "resource": "*", "effect": "deny"},
                {"action": "websearch", "resource": "*", "effect": "deny"},
                {"action": "external_directory", "resource": "*", "effect": "deny"},
                {"action": "subagent", "resource": "*", "effect": "deny"},
                {"action": "execute", "resource": "*", "effect": "deny"},
                {"action": "asuka4scape_*", "resource": "*", "effect": "allow"},
            ],
        },
        ensure_ascii=False,
        indent=2,
    )
    return {"claude": claude, "generic": generic, "opencode": opencode,
            "prompt": mcp_brief.REMOTE_PROMPT, "worker": mcp_brief.WORKER_PROMPT}


def seed_agents() -> None:
    config.AGENTS_DIR.mkdir(parents=True, exist_ok=True)
    now = time.time()
    for path in sorted(config.AGENTS_DIR.iterdir()):
        if not path.is_dir() or path.name.startswith("."):
            continue
        if not files.valid_agent_name(path.name):
            continue
        db.execute(
            "INSERT OR IGNORE INTO agents (name, display_name, note, created) VALUES (?, ?, '', ?)",
            (path.name, path.name, now),
        )


async def geo_lookup(ip: str) -> None:
    if not ip:
        return
    if security.is_lan_ip(ip):
        db.execute(
            "INSERT INTO geo (ip, country, region, city, isp, ts) VALUES (?, 'LAN', '', '', "
            "'локальная сеть', ?) ON CONFLICT(ip) DO UPDATE SET ts = excluded.ts",
            (ip, time.time()),
        )
        return
    try:
        async with httpx.AsyncClient(timeout=6.0) as client:
            resp = await client.get(
                f"http://ip-api.com/json/{ip}",
                params={"fields": "status,country,regionName,city,isp"},
            )
            data = resp.json()
        if data.get("status") == "success":
            db.execute(
                "INSERT INTO geo (ip, country, region, city, isp, ts) VALUES (?, ?, ?, ?, ?, ?) "
                "ON CONFLICT(ip) DO UPDATE SET country=excluded.country, region=excluded.region, "
                "city=excluded.city, isp=excluded.isp, ts=excluded.ts",
                (ip, data.get("country", ""), data.get("regionName", ""),
                 data.get("city", ""), data.get("isp", ""), time.time()),
            )
        else:
            raise ValueError("lookup failed")
    except Exception:
        db.execute(
            "INSERT INTO geo (ip, country, region, city, isp, ts) VALUES (?, '', '', '', '', ?) "
            "ON CONFLICT(ip) DO UPDATE SET ts = excluded.ts",
            (ip, time.time()),
        )


def geo_for(ip: str) -> dict[str, Any]:
    if not ip:
        return {}
    if security.is_lan_ip(ip):
        return {"country": "LAN", "region": "", "city": "", "isp": "локальная сеть"}
    r = db.row("SELECT * FROM geo WHERE ip = ?", (ip,))
    if r and time.time() - (r["ts"] or 0) < 7 * 86400:
        return r
    return {}


def maybe_queue_geo(ip: str, background: BackgroundTasks) -> dict[str, Any]:
    g = geo_for(ip)
    if not g and ip and not security.is_lan_ip(ip):
        background.add_task(geo_lookup, ip)
    return g


@asynccontextmanager
async def lifespan(app: FastAPI):
    db.init_db()
    seed_agents()
    db.add_event("server_start", detail=f"{config.HOST}:{config.PORT}")
    yield
    db.add_event("server_stop")


app = FastAPI(
    title="ASUKA4SCAPE HUB",
    version=config.SERVER_VERSION,
    docs_url=None,
    redoc_url=None,
    openapi_url=None,
    lifespan=lifespan,
)


# --------------------------------------------------------------------------
# middleware
# --------------------------------------------------------------------------

@app.middleware("http")
async def guard(request: Request, call_next):
    length = request.headers.get("content-length")
    if length:
        try:
            if int(length) > 16 * 1024 * 1024:
                return JSONResponse({"detail": "Слишком большое тело запроса"}, status_code=413)
        except ValueError:
            pass

    path = request.url.path
    if (
        request.method in ("POST", "PUT", "PATCH", "DELETE")
        and path.startswith("/api/")
        and path != "/api/login"
    ):
        session = security.get_session(request)
        if not session:
            return JSONResponse({"detail": "Требуется вход"}, status_code=401)
        sent = request.headers.get("x-csrf-token", "")
        if not sent or not hmac.compare_digest(sent, session["csrf"]):
            return JSONResponse({"detail": "Неверный CSRF-токен"}, status_code=403)

    response = await call_next(request)
    response.headers.setdefault("X-Content-Type-Options", "nosniff")
    response.headers.setdefault("Referrer-Policy", "no-referrer")
    response.headers.setdefault("X-Frame-Options", "DENY")
    response.headers.setdefault("Permissions-Policy", "camera=(), microphone=(), geolocation=()")
    if path in ("/login", "/admin") or path.startswith("/api/"):
        response.headers.setdefault(
            "Content-Security-Policy",
            "default-src 'self'; img-src 'self' data:; style-src 'self'; script-src 'self'; "
            "connect-src 'self'; font-src 'self'; base-uri 'none'; form-action 'self'; "
            "frame-ancestors 'none'",
        )
    return response


# --------------------------------------------------------------------------
# pages
# --------------------------------------------------------------------------

@app.get("/", include_in_schema=False)
async def root() -> RedirectResponse:
    return RedirectResponse("/admin")


@app.get("/login", response_class=HTMLResponse, include_in_schema=False)
async def login_page(request: Request):
    if security.get_session(request):
        return RedirectResponse("/admin")
    return HTMLResponse((config.WEB_DIR / "login.html").read_text(encoding="utf-8"))


@app.get("/admin", response_class=HTMLResponse, include_in_schema=False)
async def admin_page(request: Request):
    if not security.get_session(request):
        return RedirectResponse("/login")
    return HTMLResponse(
        (config.WEB_DIR / "admin.html").read_text(encoding="utf-8"),
        headers={"Cache-Control": "no-store"},
    )


@app.get("/favicon.ico", include_in_schema=False)
async def favicon() -> Response:
    svg = (
        '<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 64 64">'
        '<rect width="64" height="64" rx="14" fill="#0b1114"/>'
        '<path d="M18 46 32 16l14 30h-8l-6-13-6 13z" fill="#3ee0b0"/>'
        "</svg>"
    )
    return Response(svg, media_type="image/svg+xml", headers={"Cache-Control": "max-age=86400"})


@app.get("/healthz", include_in_schema=False)
async def healthz() -> dict[str, Any]:
    return {"ok": True, "service": config.SERVER_NAME, "version": config.SERVER_VERSION}


# --------------------------------------------------------------------------
# auth
# --------------------------------------------------------------------------

@app.post("/api/login")
async def api_login(body: LoginIn, request: Request):
    ip = security.client_ip(request)
    ua = security.user_agent(request)
    bucket = f"login:{ip}"
    if not security.login_limiter.allow(bucket, 10, 900):
        db.add_event("login_fail", ip=ip, detail="rate limited")
        raise HTTPException(status_code=429, detail="Слишком много попыток. Подожди 15 минут.")
    if not security.login_limiter.allow(f"user:{body.username}", 25, 900):
        raise HTTPException(status_code=429, detail="Слишком много попыток. Подожди 15 минут.")

    user = db.row("SELECT * FROM users WHERE username = ?", (body.username.strip(),))
    if not user or not security.verify_password(body.password, user["pw_hash"]):
        db.add_event("login_fail", ip=ip, detail=f"user={body.username[:40]} · {ua[:100]}")
        raise HTTPException(status_code=401, detail="Неверный логин или пароль")

    token, csrf = security.create_session(user["id"], ip, ua)
    db.add_event("login_ok", ip=ip, detail=user["username"])
    response = JSONResponse({"ok": True, "csrf": csrf, "username": user["username"]})
    set_session_cookie(response, token, request)
    response.headers["Cache-Control"] = "no-store"
    return response


@app.post("/api/logout")
async def api_logout(request: Request, session: dict = Depends(security.require_csrf)):
    security.destroy_session(request)
    db.add_event("logout", ip=security.client_ip(request), detail=session.get("username", ""))
    response = JSONResponse({"ok": True})
    clear_session_cookie(response)
    return response


@app.get("/api/me")
async def api_me(request: Request, session: dict = Depends(security.require_admin)):
    return {
        "username": session["username"],
        "csrf": session["csrf"],
        "origin": request_origin(request),
    }


@app.get("/api/config")
async def api_config(request: Request, session: dict = Depends(security.require_admin)):
    return {
        "username": session["username"],
        "csrf": session["csrf"],
        "origin": request_origin(request),
        "mcp_path": config.MCP_PATH,
        "base": str(config.BASE_DIR),
        "shared": str(config.SHARED_DIR),
        "version": config.SERVER_VERSION,
    }


@app.post("/api/password")
async def api_password(body: PasswordIn, request: Request,
                       session: dict = Depends(security.require_csrf)):
    user = db.row("SELECT * FROM users WHERE id = ?", (session["user_id"],))
    if not user or not security.verify_password(body.current, user["pw_hash"]):
        raise HTTPException(status_code=400, detail="Текущий пароль неверен")
    if body.new == body.current:
        raise HTTPException(status_code=400, detail="Новый пароль совпадает со старым")
    security.change_password(user["id"], body.new)
    token, csrf = security.create_session(
        user["id"], security.client_ip(request), security.user_agent(request)
    )
    db.add_event("password_change", ip=security.client_ip(request), detail=user["username"])
    response = JSONResponse({"ok": True, "csrf": csrf})
    set_session_cookie(response, token, request)
    return response


# --------------------------------------------------------------------------
# overview / agents
# --------------------------------------------------------------------------

@app.get("/api/overview")
async def api_overview(request: Request, background: BackgroundTasks,
                       session: dict = Depends(security.require_admin)):
    now = time.time()
    midnight = time.mktime(time.localtime()[:3] + (0, 0, 0, 0, 0, -1))
    agents = [agent_public(r) for r in db.rows("SELECT * FROM agents ORDER BY name")]
    folders = [p for p in config.AGENTS_DIR.iterdir() if p.is_dir() and not p.name.startswith(".")]
    keys = db.rows("SELECT * FROM api_keys")
    active_keys = sum(
        1 for k in keys
        if not k["revoked"] and not (k["expires"] and k["expires"] < now)
    )
    online = sum(1 for a in agents if a["online"])
    events_today = db.row("SELECT COUNT(*) AS n FROM events WHERE ts >= ?", (midnight,))
    reports = db.row("SELECT COUNT(*) AS n FROM reports")
    tasks = db.row("SELECT COUNT(*) AS n FROM tasks WHERE status IN ('open','claimed','blocked')")
    messages = db.row("SELECT COUNT(*) AS n FROM messages")
    usage = shutil.disk_usage(str(config.BASE_DIR))
    started = float(db.get_setting("started_at", str(now)) or now)
    return {
        "stats": {
            "online": online,
            "agents": len(agents),
            "folders": len(folders),
            "active_keys": active_keys,
            "total_keys": len(keys),
            "events_today": int(events_today["n"]) if events_today else 0,
            "reports": int(reports["n"]) if reports else 0,
            "open_tasks": int(tasks["n"]) if tasks else 0,
            "messages": int(messages["n"]) if messages else 0,
            "disk_total": usage.total,
            "disk_free": usage.free,
        },
        "agents": agents,
        "server": {
            "version": config.SERVER_VERSION,
            "base": str(config.BASE_DIR),
            "shared": str(config.SHARED_DIR),
            "mcp_path": config.MCP_PATH,
            "origin": request_origin(request),
            "uptime": int(now - started),
            "started": fmt(started),
        },
    }


@app.get("/api/agents")
async def api_agents(session: dict = Depends(security.require_admin)):
    return {"agents": [agent_public(r) for r in db.rows("SELECT * FROM agents ORDER BY name")]}


# --------------------------------------------------------------------------
# folders & files
# --------------------------------------------------------------------------

@app.get("/api/folders")
async def api_folders(session: dict = Depends(security.require_admin)):
    out = []
    for r in db.rows("SELECT * FROM agents ORDER BY name"):
        path = config.AGENTS_DIR / r["name"]
        exists = path.is_dir()
        count, size = files.tree_stats(path, 20000) if exists else (0, 0)
        item = agent_public(r)
        item.update({"exists": exists, "file_count": count, "size": size,
                     "size_h": files.human_size(size), "created": fmt(r["created"])})
        out.append(item)
    return {"folders": out}


@app.post("/api/folders")
async def api_folder_create(body: FolderIn, request: Request,
                            session: dict = Depends(security.require_csrf)):
    name = body.name.strip()
    if not files.valid_folder_name(name):
        raise HTTPException(status_code=400, detail="Имя: буквы/цифры/._- до 64 символов, без пробелов")
    path = config.AGENTS_DIR / name
    if path.exists() or db.row("SELECT name FROM agents WHERE name = ?", (name,)):
        raise HTTPException(status_code=409, detail="Такая папка уже существует")
    files.ensure_workspace(name, body.note.strip())
    db.execute(
        "INSERT OR REPLACE INTO agents (name, display_name, note, created) VALUES (?, ?, ?, ?)",
        (name, name, body.note.strip(), time.time()),
    )
    db.add_event("folder_created", agent=name, ip=security.client_ip(request), detail=name)
    return {"ok": True, "name": name, "path": str(path)}


@app.delete("/api/folders/{name}")
async def api_folder_delete(name: str, request: Request, confirm: str = "",
                            session: dict = Depends(security.require_csrf)):
    if confirm != name:
        raise HTTPException(status_code=400, detail="Подтверди удаление: confirm должен совпадать с именем")
    try:
        path = files.workspace(name)
    except files.PathError as exc:
        raise HTTPException(status_code=404, detail=str(exc))
    dest = files.move_folder_to_trash(name)
    revoked = security.revoke_keys_for_folder(name)
    db.execute("DELETE FROM agents WHERE name = ?", (name,))
    db.add_event("folder_deleted", agent=name, ip=security.client_ip(request),
                 detail=f"→ {dest.name}, keys revoked: {revoked}")
    return {"ok": True, "trashed_as": str(dest), "revoked_keys": revoked}


@app.post("/api/trash/empty")
async def api_trash_empty(request: Request, session: dict = Depends(security.require_csrf)):
    trash = config.AGENTS_DIR / ".trash"
    removed = 0
    if trash.is_dir():
        for item in trash.iterdir():
            try:
                if item.is_dir():
                    shutil.rmtree(item)
                else:
                    item.unlink()
                removed += 1
            except OSError:
                pass
    db.add_event("trash_empty", ip=security.client_ip(request), detail=str(removed))
    return {"ok": True, "removed": removed}


def _fs_root(root: str, agent: str) -> tuple[Path, Path]:
    if root == "agent":
        ws = files.workspace(agent)
        return ws, ws
    if root == "shared":
        shared = files.shared_root()
        return shared, shared
    if root == "research":
        base = files.research_root()
        return base, base
    raise HTTPException(status_code=400, detail="root: agent | shared | research")


@app.get("/api/fs/list")
async def api_fs_list(root: str = "agent", agent: str = "", path: str = "",
                      session: dict = Depends(security.require_admin)):
    if root == "agent" and not agent:
        raise HTTPException(status_code=400, detail="agent обязателен")
    try:
        _, effective = _fs_root(root, agent)
        if root == "research":
            entries = files.list_research(path)
            target = files.research_resolve(path, must_exist=True)
        else:
            target = files.resolve(effective, path, must_exist=True)
            entries = files.list_dir(effective, path)
        return {
            "root": root,
            "agent": agent,
            "path": path,
            "abs": str(target),
            "entries": entries,
        }
    except files.PathError as exc:
        raise HTTPException(status_code=400, detail=str(exc))


@app.get("/api/fs/read")
async def api_fs_read(root: str = "agent", agent: str = "", path: str = "",
                      offset: int = 0, length: int = 262144,
                      session: dict = Depends(security.require_admin)):
    if root == "agent" and not agent:
        raise HTTPException(status_code=400, detail="agent обязателен")
    try:
        _, effective = _fs_root(root, agent)
        if root == "research":
            files.research_resolve(path, must_exist=True)
            info = files.read_slice(files.research_root(), path, offset, length)
        else:
            info = files.read_slice(effective, path, offset, length)
        if info.get("binary"):
            info.pop("content_b64", None)
            info["content"] = ""
        return info
    except files.PathError as exc:
        raise HTTPException(status_code=400, detail=str(exc))


@app.get("/api/fs/download")
async def api_fs_download(root: str = "agent", agent: str = "", path: str = "",
                          session: dict = Depends(security.require_admin)):
    if root == "agent" and not agent:
        raise HTTPException(status_code=400, detail="agent обязателен")
    try:
        base, effective = _fs_root(root, agent)
        if root == "research":
            target = files.research_resolve(path, must_exist=True)
        else:
            target = files.resolve(effective, path, must_exist=True)
        if not target.is_file():
            raise HTTPException(status_code=400, detail="Это не файл")
        return FileResponse(str(target), filename=target.name)
    except files.PathError as exc:
        raise HTTPException(status_code=400, detail=str(exc))


# --------------------------------------------------------------------------
# keys / connections
# --------------------------------------------------------------------------

@app.get("/api/keys")
async def api_keys(background: BackgroundTasks,
                   session: dict = Depends(security.require_admin)):
    rows = db.rows("SELECT * FROM api_keys ORDER BY COALESCE(last_used, created) DESC")
    out = []
    for r in rows:
        g = maybe_queue_geo(r.get("last_ip") or "", background)
        out.append(key_public(r, g))
    return {"keys": out}


@app.post("/api/keys")
async def api_key_create(body: KeyIn, request: Request,
                         session: dict = Depends(security.require_csrf)):
    folder = body.folder.strip()
    if not files.valid_agent_name(folder):
        raise HTTPException(status_code=400, detail="Некорректное имя папки")
    path = config.AGENTS_DIR / folder
    if not path.is_dir():
        raise HTTPException(status_code=404, detail="Сначала создай папку агента")
    name = body.name.strip() or f"key-{folder}"
    scopes = "read_all" if body.read_only else security.SCOPES_DEFAULT
    if not db.row("SELECT name FROM agents WHERE name = ?", (folder,)):
        db.execute(
            "INSERT OR IGNORE INTO agents (name, display_name, note, created) VALUES (?, ?, '', ?)",
            (folder, folder, time.time()),
        )
    token, row = security.create_api_key(name, folder, body.ttl_days or None, scopes)
    db.add_event("key_created", agent=folder, ip=security.client_ip(request),
                 detail=f"{name} · {token[:12]}…")
    origin = request_origin(request)
    return {
        "ok": True,
        "token": token,
        "key": {**row, "created": fmt(row["created"]), "expires": fmt(row["expires"])},
        "snippets": snippets(origin, token),
    }


@app.post("/api/keys/{key_id}/revoke")
async def api_key_revoke(key_id: int, request: Request,
                         session: dict = Depends(security.require_csrf)):
    row = db.row("SELECT * FROM api_keys WHERE id = ?", (key_id,))
    if not row:
        raise HTTPException(status_code=404, detail="Ключ не найден")
    db.execute("UPDATE api_keys SET revoked = 1 WHERE id = ?", (key_id,))
    db.add_event("key_revoked", agent=row["folder"], ip=security.client_ip(request),
                 detail=f"{row['name']} · {row['prefix']}…")
    return {"ok": True}


@app.delete("/api/keys/{key_id}")
async def api_key_delete(key_id: int, request: Request,
                         session: dict = Depends(security.require_csrf)):
    row = db.row("SELECT * FROM api_keys WHERE id = ?", (key_id,))
    if not row:
        raise HTTPException(status_code=404, detail="Ключ не найден")
    db.execute("DELETE FROM api_keys WHERE id = ?", (key_id,))
    db.add_event("key_deleted", agent=row["folder"], ip=security.client_ip(request),
                 detail=f"{row['name']} · {row['prefix']}…")
    return {"ok": True}


@app.get("/api/connections")
async def api_connections(background: BackgroundTasks,
                          session: dict = Depends(security.require_admin)):
    rows = db.rows(
        "SELECT * FROM api_keys ORDER BY COALESCE(last_used, created) DESC LIMIT 200"
    )
    out = []
    for r in rows:
        g = maybe_queue_geo(r.get("last_ip") or "", background)
        item = key_public(r, g)
        item["user_agent"] = item.pop("last_ua", "")
        out.append(item)
    fails = db.rows(
        "SELECT id, ts, ip, detail FROM events WHERE kind = 'auth_fail' "
        "ORDER BY id DESC LIMIT 30"
    )
    for f in fails:
        f["at"] = fmt(f["ts"])
    return {"connections": out, "failures": fails}


# --------------------------------------------------------------------------
# events / messages / reports / tasks
# --------------------------------------------------------------------------

def event_public(r: dict[str, Any]) -> dict[str, Any]:
    return {
        "id": r["id"],
        "ts": r["ts"],
        "at": fmt(r["ts"]),
        "kind": r["kind"],
        "agent": r.get("agent") or "",
        "ip": r.get("ip") or "",
        "detail": r.get("detail") or "",
    }


@app.get("/api/events")
async def api_events(after_id: int = 0, limit: int = 80,
                     session: dict = Depends(security.require_admin)):
    limit = max(1, min(limit, 300))
    if after_id:
        rows = db.rows(
            "SELECT * FROM events WHERE id > ? ORDER BY id ASC LIMIT ?", (after_id, limit)
        )
    else:
        rows = db.rows("SELECT * FROM events ORDER BY id DESC LIMIT ?", (limit,))
        rows.reverse()
    return {"events": [event_public(r) for r in rows]}


@app.get("/api/stream")
async def api_stream(request: Request, after: int = 0,
                     session: dict = Depends(security.require_admin)):
    async def gen():
        header_id = 0
        try:
            header_id = int(request.headers.get("last-event-id", "0") or 0)
        except ValueError:
            header_id = 0
        last = max(int(after or 0), header_id)
        if last <= 0:
            last_row = db.row("SELECT COALESCE(MAX(id), 0) AS n FROM events")
            last = int(last_row["n"]) if last_row else 0
        yield ": connected\n\n"
        idle = 0.0
        while True:
            if await request.is_disconnected():
                break
            rows = db.rows(
                "SELECT * FROM events WHERE id > ? ORDER BY id ASC LIMIT 100", (last,)
            )
            for r in rows:
                last = int(r["id"])
                data = json.dumps(event_public(r), ensure_ascii=False)
                yield f"id: {last}\nevent: hub\ndata: {data}\n\n"
            idle += 1.5
            if idle >= 15:
                idle = 0.0
                yield ": ping\n\n"
            await asyncio.sleep(1.5)

    return StreamingResponse(
        gen(),
        media_type="text/event-stream",
        headers={
            "Cache-Control": "no-store",
            "X-Accel-Buffering": "no",
            "Connection": "keep-alive",
        },
    )


@app.get("/api/messages")
async def api_messages(limit: int = 100, session: dict = Depends(security.require_admin)):
    limit = max(1, min(limit, 300))
    rows = db.rows(
        "SELECT m.*, (SELECT COUNT(*) FROM message_reads r WHERE r.message_id = m.id) AS reads "
        "FROM messages m ORDER BY m.id DESC LIMIT ?", (limit,)
    )
    rows.reverse()
    for r in rows:
        r["at"] = fmt(r["ts"])
    return {"messages": rows}


@app.post("/api/messages")
async def api_message_send(body: MessageIn, request: Request,
                           session: dict = Depends(security.require_csrf)):
    recipient = body.recipient.strip() or "all"
    if recipient not in ("all", "admin"):
        if not files.valid_agent_name(recipient) or not (config.AGENTS_DIR / recipient).is_dir():
            raise HTTPException(status_code=400, detail="Получатель не найден")
    mid = db.execute(
        "INSERT INTO messages (ts, sender, recipient, subject, body) VALUES (?, 'admin', ?, ?, ?)",
        (time.time(), recipient, body.subject.strip(), body.body.strip()),
    )
    db.add_event("message", agent="admin", ip=security.client_ip(request),
                 detail=f"→ {recipient}: {body.subject or body.body[:80]}")
    return {"ok": True, "id": mid}


@app.get("/api/reports")
async def api_reports(limit: int = 60, session: dict = Depends(security.require_admin)):
    rows = db.rows("SELECT * FROM reports ORDER BY id DESC LIMIT ?", (max(1, min(limit, 300)),))
    for r in rows:
        r["at"] = fmt(r["ts"])
    return {"reports": rows}


@app.get("/api/reports/{report_id}")
async def api_report(report_id: int, session: dict = Depends(security.require_admin)):
    r = db.row("SELECT * FROM reports WHERE id = ?", (report_id,))
    if not r:
        raise HTTPException(status_code=404, detail="Отчёт не найден")
    content = ""
    try:
        content = files.read_text(files.shared_root(), r["path"], 600_000)
    except Exception:
        content = "(файл отчёта не найден)"
    return {**r, "at": fmt(r["ts"]), "content": content}


@app.get("/api/reports/{report_id}/download")
async def api_report_download(report_id: int, session: dict = Depends(security.require_admin)):
    r = db.row("SELECT * FROM reports WHERE id = ?", (report_id,))
    if not r:
        raise HTTPException(status_code=404, detail="Отчёт не найден")
    target = files.resolve(files.shared_root(), r["path"], must_exist=True)
    return FileResponse(str(target), filename=target.name)


@app.get("/api/tasks")
async def api_tasks(session: dict = Depends(security.require_admin)):
    rows = db.rows(
        "SELECT * FROM tasks ORDER BY CASE status WHEN 'claimed' THEN 0 WHEN 'open' THEN 1 "
        "WHEN 'blocked' THEN 2 ELSE 3 END, id DESC LIMIT 300"
    )
    for r in rows:
        r["at"] = fmt(r["ts"])
        r["updated_at"] = fmt(r["updated"])
    return {"tasks": rows}


@app.post("/api/tasks")
async def api_task_create(body: TaskIn, request: Request,
                          session: dict = Depends(security.require_csrf)):
    priority = body.priority if body.priority in ("low", "normal", "high", "critical") else "normal"
    now = time.time()
    tid = db.execute(
        "INSERT INTO tasks (ts, updated, title, detail, status, owner, created_by, priority) "
        "VALUES (?, ?, ?, ?, 'open', NULL, 'admin', ?)",
        (now, now, body.title.strip(), body.detail.strip(), priority),
    )
    db.add_event("task", agent="admin", ip=security.client_ip(request),
                 detail=f"создана #{tid}: {body.title}")
    return {"ok": True, "id": tid}


@app.patch("/api/tasks/{task_id}")
async def api_task_update(task_id: int, body: TaskPatch, request: Request,
                          session: dict = Depends(security.require_csrf)):
    r = db.row("SELECT * FROM tasks WHERE id = ?", (task_id,))
    if not r:
        raise HTTPException(status_code=404, detail="Задача не найдена")
    status = body.status or r["status"]
    if status not in ("open", "claimed", "blocked", "done"):
        raise HTTPException(status_code=400, detail="Некорректный статус")
    detail = r["detail"] or ""
    if body.note.strip():
        detail = (detail + f"\n\n[{fmt(time.time())} admin] {body.note.strip()}").strip()
    db.execute(
        "UPDATE tasks SET status = ?, updated = ?, detail = ? WHERE id = ?",
        (status, time.time(), detail, task_id),
    )
    db.add_event("task", agent="admin", ip=security.client_ip(request),
                 detail=f"#{task_id} → {status}")
    return {"ok": True}


# --------------------------------------------------------------------------
# settings
# --------------------------------------------------------------------------

@app.get("/api/settings")
async def api_settings(request: Request, session: dict = Depends(security.require_admin)):
    usage = shutil.disk_usage(str(config.BASE_DIR))
    return {
        "username": session["username"],
        "origin": request_origin(request),
        "public_url": stored_public_url(),
        "trust_proxy": config.TRUST_PROXY,
        "base": str(config.BASE_DIR),
        "shared": str(config.SHARED_DIR),
        "data": str(config.DATA_DIR),
        "mcp": f"{request_origin(request)}{config.MCP_PATH}",
        "version": config.SERVER_VERSION,
        "disk_total": usage.total,
        "disk_free": usage.free,
        "db_bytes": config.DB_PATH.stat().st_size if config.DB_PATH.exists() else 0,
    }


@app.post("/api/settings")
async def api_settings_update(body: SettingsIn, request: Request,
                              session: dict = Depends(security.require_csrf)):
    url = body.public_url.strip().rstrip("/")
    if url and not (url.startswith("http://") or url.startswith("https://")):
        raise HTTPException(status_code=400, detail="URL должен начинаться с http:// или https://")
    db.set_setting("public_url", url)
    db.add_event("settings", ip=security.client_ip(request), detail=f"public_url={url}")
    return {"ok": True, "public_url": url}


@app.get("/api/health")
async def api_health(session: dict = Depends(security.require_admin)):
    return {"ok": True, "time": fmt(time.time())}


# --------------------------------------------------------------------------
# MCP
# --------------------------------------------------------------------------

@app.post(config.MCP_PATH)
async def mcp_post(request: Request):
    response = await mcp.handle_mcp(request)
    response.headers["Access-Control-Allow-Origin"] = "*"
    response.headers["Access-Control-Expose-Headers"] = "Mcp-Session-Id"
    return response


@app.options(config.MCP_PATH)
async def mcp_options():
    return mcp.mcp_options()


@app.get(config.MCP_PATH)
async def mcp_get():
    return JSONResponse(
        {
            "jsonrpc": "2.0",
            "error": {"code": -32000, "message": "Use POST for Streamable HTTP MCP"},
            "id": None,
        },
        status_code=405,
        headers={"Allow": "POST, OPTIONS"},
    )


# static last
app.mount("/static", StaticFiles(directory=str(config.WEB_DIR)), name="static")
