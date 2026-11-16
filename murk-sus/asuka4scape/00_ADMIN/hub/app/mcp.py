"""Minimal Streamable-HTTP MCP server for the research hub.

Implements JSON-RPC 2.0 over POST /mcp with Bearer API-key auth.
"""
from __future__ import annotations

import json
import secrets
import time
from dataclasses import dataclass
from typing import Any, Callable

from fastapi import HTTPException, Request, Response
from fastapi.responses import JSONResponse

from . import config, db, files, mcp_brief, security

JSON = dict[str, Any]
SUPPORTED_PROTOCOLS = {"2024-11-05", "2025-03-26", "2025-06-18"}


# --------------------------------------------------------------------------
# context / auth
# --------------------------------------------------------------------------

@dataclass
class Ctx:
    key: JSON
    agent: str
    ip: str
    ua: str
    workspace: str
    scopes: set[str]

    @property
    def can_write(self) -> bool:
        return "write_own" in self.scopes

    @property
    def can_report(self) -> bool:
        return "report_shared" in self.scopes


def _extract_token(request: Request) -> str:
    auth = request.headers.get("authorization", "")
    if auth.lower().startswith("bearer "):
        return auth[7:].strip()
    return request.headers.get("x-api-key", "").strip()


def _log_auth_fail(ip: str, detail: str) -> None:
    # Never let an unauthenticated scanner grow the event table without bound.
    if security.login_limiter.allow(f"mcpfail:{ip}", 20, 60):
        db.add_event("auth_fail", ip=ip, detail=detail)


def authenticate(request: Request) -> Ctx:
    ip = security.client_ip(request)
    ua = security.user_agent(request)
    token = _extract_token(request)
    if not token:
        _log_auth_fail(ip, "missing token")
        raise HTTPException(
            status_code=401,
            detail="Нужен Bearer-ключ",
            headers={"WWW-Authenticate": "Bearer"},
        )
    key = security.authenticate_api_key(token)
    if not key:
        _log_auth_fail(ip, "invalid or revoked token")
        raise HTTPException(
            status_code=401,
            detail="Ключ недействителен или отозван",
            headers={"WWW-Authenticate": "Bearer"},
        )
    if not security.key_limiter.allow(f"key:{key['id']}", 300, 60):
        db.add_event("rate_limit", agent=key["folder"], ip=ip, detail="tool rate limit")
        raise HTTPException(status_code=429, detail="Слишком много запросов, подожди минуту")

    first_seen = not key["last_used"] or key["last_used"] < time.time() - config.ONLINE_WINDOW
    if first_seen or key["last_ip"] != ip:
        db.add_event("connect", agent=key["folder"], ip=ip,
                     detail=f"{key['name']} · {ua[:120]}")
    security.touch_api_key(key, ip, ua)

    try:
        ws = files.workspace(key["folder"])
    except files.PathError:
        raise HTTPException(status_code=403, detail="Рабочая папка агента не найдена")
    scopes = {s.strip() for s in (key["scopes"] or "").split(",") if s.strip()}
    return Ctx(key=key, agent=key["folder"], ip=ip, ua=ua,
               workspace=str(ws), scopes=scopes)


# --------------------------------------------------------------------------
# tool catalogue
# --------------------------------------------------------------------------

def _schema(props: dict[str, Any] | None = None, required: list[str] | None = None) -> JSON:
    return {
        "type": "object",
        "properties": props or {},
        "required": required or [],
        "additionalProperties": False,
    }


def _p(desc: str, **kw: Any) -> JSON:
    out = {"type": "string", "description": desc}
    out.update(kw)
    return out


TOOLS: list[JSON] = [
    {
        "name": "whoami",
        "description": "Show your identity, bound workspace, scopes, peers online, unread messages and open tasks.",
        "inputSchema": _schema(),
    },
    {
        "name": "project_brief",
        "description": "Read the full mission, boundaries, collaboration protocol and report template for this hub.",
        "inputSchema": _schema(),
    },
    {
        "name": "set_status",
        "description": "Publish a short live status for the admin dashboard (e.g. 'auditing IOSurface272').",
        "inputSchema": _schema({"status": _p("Short status, max 200 chars", maxLength=200)}, ["status"]),
    },
    {
        "name": "list_agents",
        "description": "List all researchers, their online state, current status and workspace.",
        "inputSchema": _schema(),
    },
    {
        "name": "list_files",
        "description": "List files in your workspace, a peer's workspace, or the shared report folder.",
        "inputSchema": _schema({
            "path": _p("Relative path inside the chosen root; empty for root", default=""),
            "agent": _p("Peer agent name; omit for your own workspace"),
            "shared": {"type": "boolean", "description": "List the shared report folder instead", "default": False},
        }),
    },
    {
        "name": "read_file",
        "description": "Read a file (text or binary slice) from your workspace, a peer's workspace, or shared reports.",
        "inputSchema": _schema({
            "path": _p("Relative file path"),
            "agent": _p("Peer agent name; omit for your own workspace"),
            "shared": {"type": "boolean", "description": "Read from the shared report folder", "default": False},
            "offset": {"type": "integer", "description": "Byte offset", "default": 0, "minimum": 0},
            "length": {"type": "integer", "description": "Bytes to read (max 512 KiB)", "default": 262144, "minimum": 1, "maximum": 524288},
        }, ["path"]),
    },
    {
        "name": "write_file",
        "description": "Write or append a UTF-8 text file inside YOUR workspace only. Parent folders are created.",
        "inputSchema": _schema({
            "path": _p("Relative path inside your workspace"),
            "content": _p("File content (UTF-8)"),
            "append": {"type": "boolean", "description": "Append instead of overwrite", "default": False},
        }, ["path", "content"]),
    },
    {
        "name": "delete_file",
        "description": "Move a file from YOUR workspace to its .trash folder (recoverable).",
        "inputSchema": _schema({"path": _p("Relative file path")}, ["path"]),
    },
    {
        "name": "list_research",
        "description": "List the read-only research archive (kernelcaches, reports, crash logs, tools).",
        "inputSchema": _schema({"path": _p("Relative path from the archive root", default="")}),
    },
    {
        "name": "read_research",
        "description": "Read a file from the research archive. Use offset/length for large binaries; binary slices are base64.",
        "inputSchema": _schema({
            "path": _p("Relative path from the archive root"),
            "offset": {"type": "integer", "default": 0, "minimum": 0},
            "length": {"type": "integer", "default": 262144, "minimum": 1, "maximum": 524288},
        }, ["path"]),
    },
    {
        "name": "search_research",
        "description": "Search the research archive by filename (case-insensitive substring).",
        "inputSchema": _schema({
            "query": _p("Filename substring, at least 2 chars"),
            "limit": {"type": "integer", "default": 40, "minimum": 1, "maximum": 200},
        }, ["query"]),
    },
    {
        "name": "send_message",
        "description": "Send a message to the team ('all'), the admin, or one peer. Use for findings, blockers and hand-offs.",
        "inputSchema": _schema({
            "to": _p("'all', 'admin', or an agent name", default="all"),
            "subject": _p("Short subject", default=""),
            "body": _p("Message body"),
        }, ["body"]),
    },
    {
        "name": "read_messages",
        "description": "Read messages addressed to you or to everyone. Returns unread messages and marks them read.",
        "inputSchema": _schema({
            "limit": {"type": "integer", "default": 30, "minimum": 1, "maximum": 100},
            "unread_only": {"type": "boolean", "default": True},
        }),
    },
    {
        "name": "create_report",
        "description": "Publish a Markdown report into the shared report folder and the report index.",
        "inputSchema": _schema({
            "title": _p("Report title"),
            "summary": _p("One-paragraph summary", default=""),
            "body": _p("Markdown body"),
            "tags": _p("Comma-separated tags", default=""),
        }, ["title", "body"]),
    },
    {
        "name": "list_reports",
        "description": "List shared reports, newest first.",
        "inputSchema": _schema({
            "limit": {"type": "integer", "default": 30, "minimum": 1, "maximum": 100},
            "agent": _p("Filter by author"),
        }),
    },
    {
        "name": "read_report",
        "description": "Read a shared report by id (see list_reports).",
        "inputSchema": _schema({"id": {"type": "integer", "minimum": 1}}, ["id"]),
    },
    {
        "name": "list_tasks",
        "description": "List the shared task board. Check this before starting work.",
        "inputSchema": _schema({"status": _p("open | claimed | blocked | done | all", default="all")}),
    },
    {
        "name": "create_task",
        "description": "Create a task on the shared board.",
        "inputSchema": _schema({
            "title": _p("Task title"),
            "detail": _p("Scope, hypothesis, acceptance criteria", default=""),
            "priority": _p("low | normal | high | critical", default="normal"),
        }, ["title"]),
    },
    {
        "name": "claim_task",
        "description": "Claim an open task so the team can see who is working on it.",
        "inputSchema": _schema({"id": {"type": "integer", "minimum": 1}}, ["id"]),
    },
    {
        "name": "update_task",
        "description": "Update a task you own: status (open/claimed/blocked/done) and an optional note.",
        "inputSchema": _schema({
            "id": {"type": "integer", "minimum": 1},
            "status": _p("open | claimed | blocked | done"),
            "note": _p("Progress note", default=""),
        }, ["id", "status"]),
    },
    {
        "name": "get_activity",
        "description": "Recent team activity: status changes, tool calls, messages, reports and tasks.",
        "inputSchema": _schema({
            "limit": {"type": "integer", "default": 40, "minimum": 1, "maximum": 200},
        }),
    },
]

TOOL_NAMES = {t["name"] for t in TOOLS}


# --------------------------------------------------------------------------
# helpers
# --------------------------------------------------------------------------

def _fmt(ts: float | None) -> str:
    if not ts:
        return ""
    return time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(ts))


def _ok(data: Any) -> JSON:
    if isinstance(data, str):
        text = data
    else:
        text = json.dumps(data, ensure_ascii=False, indent=2, default=str)
    if len(text) > 900_000:
        text = text[:900_000] + "\n… (truncated)"
    return {"content": [{"type": "text", "text": text}], "isError": False}


def _err(message: str) -> JSON:
    return {"content": [{"type": "text", "text": message}], "isError": True}


def _tool(name: str) -> Callable[[Ctx, JSON], Any]:
    return TOOL_HANDLERS[name]


def _require_write(ctx: Ctx) -> None:
    if not ctx.can_write:
        raise files.PathError("Ключ только для чтения")


# --------------------------------------------------------------------------
# tool handlers
# --------------------------------------------------------------------------

def t_whoami(ctx: Ctx, args: JSON) -> Any:
    peers = db.rows("SELECT name, status, status_at, last_seen FROM agents ORDER BY name")
    now = time.time()
    online = [p["name"] for p in peers if p["last_seen"] and now - p["last_seen"] < config.ONLINE_WINDOW]
    unread = db.row(
        "SELECT COUNT(*) AS n FROM messages m WHERE (m.recipient = 'all' OR m.recipient = ?) "
        "AND m.sender <> ? AND NOT EXISTS (SELECT 1 FROM message_reads r "
        "WHERE r.message_id = m.id AND r.agent = ?)",
        (ctx.agent, ctx.agent, ctx.agent),
    )
    tasks = db.row("SELECT COUNT(*) AS n FROM tasks WHERE status IN ('open','claimed')")
    return {
        "agent": ctx.agent,
        "key_name": ctx.key["name"],
        "workspace": ctx.workspace,
        "shared_reports": str(config.SHARED_DIR),
        "archive": str(config.BASE_DIR),
        "scopes": sorted(ctx.scopes),
        "online_peers": online,
        "unread_messages": int(unread["n"]) if unread else 0,
        "open_tasks": int(tasks["n"]) if tasks else 0,
        "server_time": _fmt(time.time()),
    }


def t_project_brief(ctx: Ctx, args: JSON) -> Any:
    return mcp_brief.render(ctx.agent, ctx.workspace)


def t_set_status(ctx: Ctx, args: JSON) -> Any:
    status = str(args.get("status", "")).strip()[:200]
    if not status:
        raise files.PathError("status не может быть пустым")
    now = time.time()
    db.execute(
        "UPDATE agents SET status = ?, status_at = ?, last_seen = ? WHERE name = ?",
        (status, now, now, ctx.agent),
    )
    db.add_event("status", ctx.agent, ctx.ip, status)
    return {"ok": True, "status": status, "at": _fmt(now)}


def t_list_agents(ctx: Ctx, args: JSON) -> Any:
    now = time.time()
    out = []
    for r in db.rows("SELECT name, note, status, status_at, last_seen FROM agents ORDER BY name"):
        out.append({
            "agent": r["name"],
            "online": bool(r["last_seen"] and now - r["last_seen"] < config.ONLINE_WINDOW),
            "status": r["status"] or "",
            "status_at": _fmt(r["status_at"]),
            "last_seen": _fmt(r["last_seen"]),
            "workspace": str(config.AGENTS_DIR / r["name"]),
            "note": r["note"] or "",
        })
    return {"agents": out, "now": _fmt(now)}


def _root_for(ctx: Ctx, args: JSON) -> tuple[Any, str]:
    if args.get("shared"):
        return files.shared_root(), "shared"
    peer = str(args.get("agent") or "").strip()
    if peer and peer != ctx.agent:
        return files.workspace(peer), peer
    return files.workspace(ctx.agent), ctx.agent


def t_list_files(ctx: Ctx, args: JSON) -> Any:
    root, label = _root_for(ctx, args)
    rel = str(args.get("path") or "")
    entries = files.list_dir(root, rel)
    return {
        "root": label,
        "path": rel,
        "abs": str(root / rel if rel else root),
        "entries": entries,
        "count": len(entries),
    }


def t_read_file(ctx: Ctx, args: JSON) -> Any:
    root, label = _root_for(ctx, args)
    rel = str(args.get("path") or "")
    length = min(int(args.get("length") or config.MAX_READ_BYTES), 524288)
    info = files.read_slice(
        root, rel,
        int(args.get("offset") or 0),
        length,
    )
    info["root"] = label
    return info


def t_write_file(ctx: Ctx, args: JSON) -> Any:
    _require_write(ctx)
    path = str(args.get("path") or "")
    content = args.get("content")
    if not isinstance(content, str):
        raise files.PathError("content должен быть строкой")
    info = files.write_text(path, content, agent=ctx.agent, append=bool(args.get("append")))
    db.add_event("file_write", ctx.agent, ctx.ip, f"{path} · {info['size_h']}")
    return {"ok": True, **info}


def t_delete_file(ctx: Ctx, args: JSON) -> Any:
    _require_write(ctx)
    info = files.delete_own_file(str(args.get("path") or ""), ctx.agent)
    db.add_event("file_delete", ctx.agent, ctx.ip, info["path"])
    return {"ok": True, **info}


def t_list_research(ctx: Ctx, args: JSON) -> Any:
    rel = str(args.get("path") or "")
    entries = files.list_research(rel)
    return {"path": rel, "entries": entries, "count": len(entries)}


def t_read_research(ctx: Ctx, args: JSON) -> Any:
    rel = str(args.get("path") or "")
    files.research_resolve(rel, must_exist=True)
    length = min(int(args.get("length") or config.MAX_READ_BYTES), 524288)
    info = files.read_slice(
        files.research_root(), rel,
        int(args.get("offset") or 0),
        length,
    )
    info["root"] = "research"
    return info


def t_search_research(ctx: Ctx, args: JSON) -> Any:
    query = str(args.get("query") or "")
    results = files.search_research(query, int(args.get("limit") or 40))
    return {"query": query, "results": results, "count": len(results)}


def t_send_message(ctx: Ctx, args: JSON) -> Any:
    _require_write(ctx)
    to = str(args.get("to") or "all").strip()
    body = str(args.get("body") or "").strip()
    subject = str(args.get("subject") or "").strip()[:160]
    if not body:
        raise files.PathError("body не может быть пустым")
    if len(body) > 20000:
        raise files.PathError("Сообщение слишком длинное (лимит 20 КБ)")
    if to not in ("all", "admin"):
        if not files.valid_agent_name(to) or not (config.AGENTS_DIR / to).is_dir():
            raise files.PathError("Получатель не найден")
    mid = db.execute(
        "INSERT INTO messages (ts, sender, recipient, subject, body) VALUES (?, ?, ?, ?, ?)",
        (time.time(), ctx.agent, to, subject, body),
    )
    db.add_event("message", ctx.agent, ctx.ip, f"→ {to}: {subject or body[:80]}")
    return {"ok": True, "id": mid, "to": to}


def t_read_messages(ctx: Ctx, args: JSON) -> Any:
    limit = int(args.get("limit") or 30)
    unread_only = bool(args.get("unread_only", True))
    sql = (
        "SELECT m.id, m.ts, m.sender, m.recipient, m.subject, m.body FROM messages m "
        "WHERE (m.recipient = 'all' OR m.recipient = ?) AND m.sender <> ?"
    )
    params: list[Any] = [ctx.agent, ctx.agent]
    if unread_only:
        sql += (
            " AND NOT EXISTS (SELECT 1 FROM message_reads r "
            "WHERE r.message_id = m.id AND r.agent = ?)"
        )
        params.append(ctx.agent)
    sql += " ORDER BY m.id DESC LIMIT ?"
    params.append(limit)
    rows = db.rows(sql, tuple(params))
    rows.reverse()
    now = time.time()
    if rows:
        with db.db() as conn:
            for r in rows:
                conn.execute(
                    "INSERT OR IGNORE INTO message_reads (message_id, agent, ts) VALUES (?, ?, ?)",
                    (r["id"], ctx.agent, now),
                )
    for r in rows:
        r["at"] = _fmt(r["ts"])
    return {"messages": rows, "count": len(rows)}


def t_create_report(ctx: Ctx, args: JSON) -> Any:
    if not ctx.can_report:
        raise files.PathError("Ключ не имеет права писать отчёты")
    title = str(args.get("title") or "").strip()[:200]
    body = str(args.get("body") or "")
    summary = str(args.get("summary") or "").strip()[:2000]
    tags = str(args.get("tags") or "").strip()[:300]
    if not title or not body.strip():
        raise files.PathError("Нужны title и body")
    if len(body) > 400_000:
        raise files.PathError("Отчёт слишком большой (лимит 400 КБ)")
    path, rel = files.write_report(ctx.agent, title, summary, body, tags)
    rid = db.execute(
        "INSERT INTO reports (ts, agent, title, summary, path, tags) VALUES (?, ?, ?, ?, ?, ?)",
        (time.time(), ctx.agent, title, summary, rel, tags),
    )
    db.add_event("report", ctx.agent, ctx.ip, title)
    return {"ok": True, "id": rid, "path": str(path), "relative": rel}


def t_list_reports(ctx: Ctx, args: JSON) -> Any:
    limit = int(args.get("limit") or 30)
    agent = str(args.get("agent") or "").strip()
    if agent:
        rows = db.rows(
            "SELECT id, ts, agent, title, summary, path, tags FROM reports "
            "WHERE agent = ? ORDER BY id DESC LIMIT ?", (agent, limit))
    else:
        rows = db.rows(
            "SELECT id, ts, agent, title, summary, path, tags FROM reports "
            "ORDER BY id DESC LIMIT ?", (limit,))
    for r in rows:
        r["at"] = _fmt(r["ts"])
    return {"reports": rows, "count": len(rows)}


def t_read_report(ctx: Ctx, args: JSON) -> Any:
    rid = int(args.get("id") or 0)
    r = db.row("SELECT * FROM reports WHERE id = ?", (rid,))
    if not r:
        raise files.PathError("Отчёт не найден")
    if not r["path"]:
        raise files.PathError("У отчёта нет файла")
    target = files.resolve(files.shared_root(), r["path"], must_exist=True)
    content = files.read_text(files.shared_root(), r["path"], 400_000)
    return {
        "id": r["id"], "agent": r["agent"], "title": r["title"],
        "summary": r["summary"], "at": _fmt(r["ts"]), "path": str(target),
        "content": content,
    }


def _task_public(r: JSON) -> JSON:
    r = dict(r)
    r["at"] = _fmt(r["ts"])
    r["updated_at"] = _fmt(r["updated"])
    return r


def t_list_tasks(ctx: Ctx, args: JSON) -> Any:
    status = str(args.get("status") or "all").strip()
    if status and status != "all":
        rows = db.rows(
            "SELECT * FROM tasks WHERE status = ? ORDER BY "
            "CASE priority WHEN 'critical' THEN 0 WHEN 'high' THEN 1 "
            "WHEN 'normal' THEN 2 ELSE 3 END, id DESC LIMIT 200", (status,))
    else:
        rows = db.rows(
            "SELECT * FROM tasks ORDER BY "
            "CASE status WHEN 'claimed' THEN 0 WHEN 'open' THEN 1 WHEN 'blocked' THEN 2 ELSE 3 END, "
            "CASE priority WHEN 'critical' THEN 0 WHEN 'high' THEN 1 "
            "WHEN 'normal' THEN 2 ELSE 3 END, id DESC LIMIT 200")
    return {"tasks": [_task_public(r) for r in rows], "count": len(rows)}


def t_create_task(ctx: Ctx, args: JSON) -> Any:
    _require_write(ctx)
    title = str(args.get("title") or "").strip()[:200]
    detail = str(args.get("detail") or "").strip()[:20000]
    priority = str(args.get("priority") or "normal").strip()
    if not title:
        raise files.PathError("title не может быть пустым")
    if priority not in ("low", "normal", "high", "critical"):
        priority = "normal"
    now = time.time()
    tid = db.execute(
        "INSERT INTO tasks (ts, updated, title, detail, status, owner, created_by, priority) "
        "VALUES (?, ?, ?, ?, 'open', NULL, ?, ?)",
        (now, now, title, detail, ctx.agent, priority),
    )
    db.add_event("task", ctx.agent, ctx.ip, f"создана #{tid}: {title}")
    return {"ok": True, "id": tid}


def t_claim_task(ctx: Ctx, args: JSON) -> Any:
    _require_write(ctx)
    tid = int(args.get("id") or 0)
    with db.db() as conn:
        r = conn.execute("SELECT * FROM tasks WHERE id = ?", (tid,)).fetchone()
        if not r:
            raise files.PathError("Задача не найдена")
        if r["status"] == "done":
            raise files.PathError("Задача уже завершена")
        if r["owner"] and r["owner"] != ctx.agent:
            raise files.PathError(f"Задачу уже взял {r['owner']}")
        now = time.time()
        conn.execute(
            "UPDATE tasks SET status = 'claimed', owner = ?, updated = ? WHERE id = ?",
            (ctx.agent, now, tid),
        )
    db.add_event("task", ctx.agent, ctx.ip, f"взял задачу #{tid}")
    return {"ok": True, "id": tid, "owner": ctx.agent, "status": "claimed"}


def t_update_task(ctx: Ctx, args: JSON) -> Any:
    _require_write(ctx)
    tid = int(args.get("id") or 0)
    status = str(args.get("status") or "").strip()
    note = str(args.get("note") or "").strip()[:4000]
    if status not in ("open", "claimed", "blocked", "done"):
        raise files.PathError("status: open | claimed | blocked | done")
    with db.db() as conn:
        r = conn.execute("SELECT * FROM tasks WHERE id = ?", (tid,)).fetchone()
        if not r:
            raise files.PathError("Задача не найдена")
        if r["owner"] and r["owner"] != ctx.agent and r["created_by"] != ctx.agent:
            raise files.PathError(f"Задача принадлежит {r['owner']}")
        detail = r["detail"] or ""
        if note:
            stamp = time.strftime("%Y-%m-%d %H:%M")
            detail = (detail + f"\n\n[{stamp} {ctx.agent}] {note}").strip()
        conn.execute(
            "UPDATE tasks SET status = ?, updated = ?, detail = ?, "
            "owner = COALESCE(owner, ?) WHERE id = ?",
            (status, time.time(), detail, ctx.agent, tid),
        )
    db.add_event("task", ctx.agent, ctx.ip, f"#{tid} → {status}" + (f": {note[:80]}" if note else ""))
    return {"ok": True, "id": tid, "status": status}


def t_get_activity(ctx: Ctx, args: JSON) -> Any:
    limit = int(args.get("limit") or 40)
    rows = db.rows(
        "SELECT id, ts, kind, agent, detail FROM events "
        "WHERE kind NOT IN ('login_ok','login_fail','key_created','key_revoked',"
        "'folder_created','folder_deleted','server_start','rate_limit') "
        "ORDER BY id DESC LIMIT ?", (limit,))
    rows.reverse()
    for r in rows:
        r["at"] = _fmt(r["ts"])
    return {"events": rows}


TOOL_HANDLERS: dict[str, Callable[[Ctx, JSON], Any]] = {
    "whoami": t_whoami,
    "project_brief": t_project_brief,
    "set_status": t_set_status,
    "list_agents": t_list_agents,
    "list_files": t_list_files,
    "read_file": t_read_file,
    "write_file": t_write_file,
    "delete_file": t_delete_file,
    "list_research": t_list_research,
    "read_research": t_read_research,
    "search_research": t_search_research,
    "send_message": t_send_message,
    "read_messages": t_read_messages,
    "create_report": t_create_report,
    "list_reports": t_list_reports,
    "read_report": t_read_report,
    "list_tasks": t_list_tasks,
    "create_task": t_create_task,
    "claim_task": t_claim_task,
    "update_task": t_update_task,
    "get_activity": t_get_activity,
}


# --------------------------------------------------------------------------
# JSON-RPC
# --------------------------------------------------------------------------

def _rpc_error(id_: Any, code: int, message: str) -> JSON:
    return {"jsonrpc": "2.0", "id": id_, "error": {"code": code, "message": message}}


def _rpc_result(id_: Any, result: Any) -> JSON:
    return {"jsonrpc": "2.0", "id": id_, "result": result}


def _handle_one(payload: JSON, ctx: Ctx) -> tuple[JSON | None, JSON | None]:
    """Return (response, error). Notifications return (None, None)."""
    if not isinstance(payload, dict) or payload.get("jsonrpc") != "2.0":
        return None, _rpc_error(payload.get("id") if isinstance(payload, dict) else None,
                                -32600, "Invalid Request")
    method = payload.get("method")
    id_ = payload.get("id")
    is_notification = "id" not in payload
    params = payload.get("params") or {}

    if method in ("notifications/initialized", "notifications/cancelled",
                  "notifications/roots/list_changed", "notifications/progress"):
        return None, None
    if method == "ping":
        return (None, None) if is_notification else (_rpc_result(id_, {}), None)
    if method == "initialize":
        requested = str(params.get("protocolVersion") or "2025-06-18")
        version = requested if requested in SUPPORTED_PROTOCOLS else "2025-06-18"
        result = {
            "protocolVersion": version,
            "capabilities": {"tools": {"listChanged": False}},
            "serverInfo": {"name": config.SERVER_NAME, "version": config.SERVER_VERSION},
            "instructions": mcp_brief.render(ctx.agent, ctx.workspace),
        }
        return (None, None) if is_notification else (_rpc_result(id_, result), None)
    if method == "tools/list":
        return (None, None) if is_notification else (_rpc_result(id_, {"tools": TOOLS}), None)
    if method == "resources/list":
        return (None, None) if is_notification else (_rpc_result(id_, {"resources": []}), None)
    if method == "prompts/list":
        return (None, None) if is_notification else (_rpc_result(id_, {"prompts": []}), None)
    if method == "tools/call":
        name = str(params.get("name") or "")
        args = params.get("arguments") or {}
        if name not in TOOL_NAMES:
            return None, _rpc_error(id_, -32602, f"Unknown tool: {name}")
        if not isinstance(args, dict):
            return None, _rpc_error(id_, -32602, "arguments must be an object")
        started = time.time()
        try:
            data = TOOL_HANDLERS[name](ctx, args)
            result = _ok(data)
        except (files.PathError, ValueError) as exc:
            result = _err(str(exc))
        except Exception as exc:  # pragma: no cover - defensive
            db.add_event("tool_error", ctx.agent, ctx.ip, f"{name}: {exc}"[:300])
            result = _err(f"Внутренняя ошибка инструмента: {exc}")
        elapsed = int((time.time() - started) * 1000)
        if name not in ("whoami", "project_brief", "list_agents", "list_tasks", "get_activity"):
            db.add_event("tool", ctx.agent, ctx.ip, f"{name} · {elapsed} ms")
        if is_notification:
            return None, None
        return _rpc_result(id_, result), None
    return None, _rpc_error(id_, -32601, f"Method not found: {method}")


async def handle_mcp(request: Request) -> Response:
    ctx = authenticate(request)
    try:
        payload = await request.json()
    except Exception:
        return JSONResponse(_rpc_error(None, -32700, "Parse error"), status_code=400)

    headers = {"Cache-Control": "no-store"}
    if isinstance(payload, list):
        responses = []
        for item in payload:
            response, error = _handle_one(item, ctx)
            if error:
                responses.append(error)
            elif response:
                responses.append(response)
        if not responses:
            return Response(status_code=202, headers=headers)
        return JSONResponse(responses, headers=headers)

    response, error = _handle_one(payload, ctx)
    if error:
        return JSONResponse(error, status_code=200, headers=headers)
    if not response:
        return Response(status_code=202, headers=headers)
    if payload.get("method") == "initialize":
        headers["Mcp-Session-Id"] = secrets.token_urlsafe(24)
    return JSONResponse(response, headers=headers)


def mcp_options() -> Response:
    return Response(
        status_code=204,
        headers={
            "Access-Control-Allow-Origin": "*",
            "Access-Control-Allow-Methods": "POST, GET, OPTIONS",
            "Access-Control-Allow-Headers": "Authorization, Content-Type, Mcp-Session-Id, MCP-Protocol-Version",
            "Access-Control-Max-Age": "86400",
        },
    )
