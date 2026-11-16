"""Password hashing, sessions, API keys, rate limiting, client IP."""
from __future__ import annotations

import base64
import hashlib
import hmac
import ipaddress
import os
import secrets
import threading
import time
from collections import defaultdict, deque
from typing import Any

from fastapi import HTTPException, Request

from . import config, db


# --------------------------------------------------------------------------
# passwords
# --------------------------------------------------------------------------

def _b64(data: bytes) -> str:
    return base64.urlsafe_b64encode(data).decode().rstrip("=")


def _unb64(text: str) -> bytes:
    return base64.urlsafe_b64decode(text + "=" * (-len(text) % 4))


def hash_password(password: str) -> str:
    salt = os.urandom(16)
    dk = hashlib.scrypt(
        password.encode("utf-8"), salt=salt, n=16384, r=8, p=1, dklen=32
    )
    return f"scrypt$16384$8$1${_b64(salt)}${_b64(dk)}"


def verify_password(password: str, stored: str) -> bool:
    try:
        algo, n, r, p, salt, digest = stored.split("$")
        if algo != "scrypt":
            return False
        dk = hashlib.scrypt(
            password.encode("utf-8"),
            salt=_unb64(salt),
            n=int(n),
            r=int(r),
            p=int(p),
            dklen=len(_unb64(digest)),
        )
        return hmac.compare_digest(dk, _unb64(digest))
    except Exception:
        return False


def change_password(user_id: int, password: str) -> None:
    db.execute(
        "UPDATE users SET pw_hash = ? WHERE id = ?",
        (hash_password(password), user_id),
    )
    db.execute("DELETE FROM sessions WHERE user_id = ?", (user_id,))


# --------------------------------------------------------------------------
# client IP
# --------------------------------------------------------------------------

def normalize_ip(value: str | None) -> str:
    if not value:
        return ""
    value = value.strip()
    if value.startswith("[") and "]" in value:
        value = value[1:value.index("]")]
    if value.startswith("::ffff:"):
        value = value[7:]
    try:
        return str(ipaddress.ip_address(value))
    except ValueError:
        return value[:64]


def client_ip(request: Request) -> str:
    if config.TRUST_PROXY:
        for header in ("cf-connecting-ip", "true-client-ip", "x-real-ip"):
            value = request.headers.get(header)
            if value:
                return normalize_ip(value)
        forwarded = request.headers.get("x-forwarded-for")
        if forwarded:
            return normalize_ip(forwarded.split(",")[0])
    if request.client and request.client.host:
        return normalize_ip(request.client.host)
    return ""


def is_lan_ip(ip: str) -> bool:
    try:
        addr = ipaddress.ip_address(ip)
        return addr.is_private or addr.is_loopback or addr.is_link_local
    except ValueError:
        return False


def geo_hint(request: Request) -> dict[str, str]:
    country = request.headers.get("cf-ipcountry", "")
    return {"country": country} if country and country != "XX" else {}


def user_agent(request: Request) -> str:
    return (request.headers.get("user-agent") or "")[:400]


# --------------------------------------------------------------------------
# sessions
# --------------------------------------------------------------------------

def _token_hash(token: str) -> str:
    return hashlib.sha256(token.encode()).hexdigest()


def create_session(user_id: int, ip: str, ua: str) -> tuple[str, str]:
    token = secrets.token_urlsafe(36)
    csrf = secrets.token_urlsafe(32)
    now = time.time()
    db.execute(
        "INSERT INTO sessions (id, csrf, user_id, created, expires, ip, ua) "
        "VALUES (?, ?, ?, ?, ?, ?, ?)",
        (_token_hash(token), csrf, user_id, now, now + config.SESSION_TTL, ip, ua),
    )
    db.execute("DELETE FROM sessions WHERE expires < ?", (now,))
    return token, csrf


def get_session(request: Request) -> dict[str, Any] | None:
    token = request.cookies.get(config.SESSION_COOKIE)
    if not token:
        return None
    r = db.row(
        "SELECT s.*, u.username FROM sessions s JOIN users u ON u.id = s.user_id "
        "WHERE s.id = ? AND s.expires > ?",
        (_token_hash(token), time.time()),
    )
    if not r:
        return None
    return r


def destroy_session(request: Request) -> None:
    token = request.cookies.get(config.SESSION_COOKIE)
    if token:
        db.execute("DELETE FROM sessions WHERE id = ?", (_token_hash(token),))


def require_admin(request: Request) -> dict[str, Any]:
    session = get_session(request)
    if not session:
        raise HTTPException(status_code=401, detail="Требуется вход")
    return session


def require_csrf(request: Request) -> dict[str, Any]:
    session = require_admin(request)
    sent = request.headers.get("x-csrf-token", "")
    if not sent or not hmac.compare_digest(sent, session["csrf"]):
        raise HTTPException(status_code=403, detail="Неверный CSRF-токен")
    return session


# --------------------------------------------------------------------------
# API keys
# --------------------------------------------------------------------------

SCOPES_DEFAULT = "read_all,write_own,report_shared"


def create_api_key(name: str, folder: str, ttl_days: int | None = None,
                   scopes: str = SCOPES_DEFAULT) -> tuple[str, dict[str, Any]]:
    token = "ask_" + secrets.token_urlsafe(36)
    now = time.time()
    expires = now + ttl_days * 86400 if ttl_days else None
    key_id = db.execute(
        "INSERT INTO api_keys (name, prefix, key_hash, folder, scopes, created, expires) "
        "VALUES (?, ?, ?, ?, ?, ?, ?)",
        (name, token[:12], _token_hash(token), folder, scopes, now, expires),
    )
    return token, {
        "id": key_id,
        "name": name,
        "folder": folder,
        "prefix": token[:12],
        "created": now,
        "expires": expires,
        "scopes": scopes,
    }


def authenticate_api_key(token: str) -> dict[str, Any] | None:
    if not token:
        return None
    r = db.row("SELECT * FROM api_keys WHERE key_hash = ?", (_token_hash(token),))
    if not r:
        return None
    if r["revoked"]:
        return None
    if r["expires"] and r["expires"] < time.time():
        return None
    return r


def touch_api_key(key: dict[str, Any], ip: str, ua: str) -> None:
    now = time.time()
    db.execute(
        "UPDATE api_keys SET last_used = ?, last_ip = ?, last_ua = ?, requests = requests + 1 "
        "WHERE id = ?",
        (now, ip, ua, key["id"]),
    )
    db.execute(
        "UPDATE agents SET last_seen = ? WHERE name = ?",
        (now, key["folder"]),
    )


def revoke_keys_for_folder(folder: str) -> int:
    with db.db() as conn:
        cur = conn.execute(
            "UPDATE api_keys SET revoked = 1 WHERE folder = ? AND revoked = 0", (folder,)
        )
        return cur.rowcount


# --------------------------------------------------------------------------
# rate limiting (single-process, in-memory)
# --------------------------------------------------------------------------

class RateLimiter:
    def __init__(self) -> None:
        self._events: dict[str, deque[float]] = defaultdict(deque)
        self._lock = threading.Lock()

    def allow(self, key: str, limit: int, window: float) -> bool:
        now = time.time()
        with self._lock:
            q = self._events[key]
            while q and q[0] < now - window:
                q.popleft()
            if len(q) >= limit:
                return False
            q.append(now)
            if len(self._events) > 5000:
                self._sweep(now, window)
            return True

    def retry_after(self, key: str, window: float) -> int:
        with self._lock:
            q = self._events.get(key)
            if not q:
                return 0
            return max(1, int(window - (time.time() - q[0])))

    def _sweep(self, now: float, window: float) -> None:
        dead = [k for k, q in self._events.items() if not q or q[-1] < now - window]
        for k in dead[:2000]:
            self._events.pop(k, None)


login_limiter = RateLimiter()
key_limiter = RateLimiter()
