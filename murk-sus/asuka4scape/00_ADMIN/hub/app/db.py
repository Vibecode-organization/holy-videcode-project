"""SQLite layer for the hub. Small, dependency-free, WAL mode."""
from __future__ import annotations

import os
import sqlite3
import time
from contextlib import contextmanager
from typing import Any, Iterator

from . import config

SCHEMA = """
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT UNIQUE NOT NULL,
    pw_hash TEXT NOT NULL,
    created REAL NOT NULL
);

CREATE TABLE IF NOT EXISTS sessions (
    id TEXT PRIMARY KEY,
    csrf TEXT NOT NULL,
    user_id INTEGER NOT NULL,
    created REAL NOT NULL,
    expires REAL NOT NULL,
    ip TEXT,
    ua TEXT,
    FOREIGN KEY(user_id) REFERENCES users(id)
);

CREATE TABLE IF NOT EXISTS api_keys (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    prefix TEXT NOT NULL,
    key_hash TEXT UNIQUE NOT NULL,
    folder TEXT NOT NULL,
    scopes TEXT NOT NULL DEFAULT 'read_all,write_own,report_shared',
    created REAL NOT NULL,
    expires REAL,
    revoked INTEGER NOT NULL DEFAULT 0,
    last_used REAL,
    last_ip TEXT,
    last_ua TEXT,
    requests INTEGER NOT NULL DEFAULT 0
);
CREATE INDEX IF NOT EXISTS idx_api_keys_hash ON api_keys(key_hash);

CREATE TABLE IF NOT EXISTS agents (
    name TEXT PRIMARY KEY,
    display_name TEXT,
    note TEXT,
    created REAL NOT NULL,
    status TEXT NOT NULL DEFAULT '',
    status_at REAL,
    last_seen REAL
);

CREATE TABLE IF NOT EXISTS events (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    ts REAL NOT NULL,
    kind TEXT NOT NULL,
    agent TEXT,
    ip TEXT,
    detail TEXT
);
CREATE INDEX IF NOT EXISTS idx_events_id ON events(id);

CREATE TABLE IF NOT EXISTS messages (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    ts REAL NOT NULL,
    sender TEXT NOT NULL,
    recipient TEXT NOT NULL DEFAULT 'all',
    subject TEXT NOT NULL DEFAULT '',
    body TEXT NOT NULL
);
CREATE INDEX IF NOT EXISTS idx_messages_id ON messages(id);

CREATE TABLE IF NOT EXISTS message_reads (
    message_id INTEGER NOT NULL,
    agent TEXT NOT NULL,
    ts REAL NOT NULL,
    PRIMARY KEY(message_id, agent)
);

CREATE TABLE IF NOT EXISTS reports (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    ts REAL NOT NULL,
    agent TEXT,
    title TEXT NOT NULL,
    summary TEXT,
    path TEXT,
    tags TEXT
);

CREATE TABLE IF NOT EXISTS tasks (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    ts REAL NOT NULL,
    updated REAL NOT NULL,
    title TEXT NOT NULL,
    detail TEXT,
    status TEXT NOT NULL DEFAULT 'open',
    owner TEXT,
    created_by TEXT,
    priority TEXT NOT NULL DEFAULT 'normal'
);
CREATE INDEX IF NOT EXISTS idx_tasks_status ON tasks(status);

CREATE TABLE IF NOT EXISTS geo (
    ip TEXT PRIMARY KEY,
    country TEXT,
    region TEXT,
    city TEXT,
    isp TEXT,
    ts REAL
);

CREATE TABLE IF NOT EXISTS settings (
    k TEXT PRIMARY KEY,
    v TEXT
);
"""


def connect() -> sqlite3.Connection:
    config.DB_PATH.parent.mkdir(parents=True, exist_ok=True)
    conn = sqlite3.connect(config.DB_PATH, timeout=15)
    conn.row_factory = sqlite3.Row
    conn.execute("PRAGMA journal_mode=WAL")
    conn.execute("PRAGMA synchronous=NORMAL")
    conn.execute("PRAGMA busy_timeout=10000")
    conn.execute("PRAGMA foreign_keys=ON")
    return conn


@contextmanager
def db() -> Iterator[sqlite3.Connection]:
    conn = connect()
    try:
        yield conn
        conn.commit()
    except Exception:
        conn.rollback()
        raise
    finally:
        conn.close()


def init_db() -> None:
    os.umask(0o077)
    config.ensure_dirs()
    os.chmod(config.DATA_DIR, 0o700)
    os.chmod(config.LOG_DIR, 0o700)
    from .security import hash_password

    with db() as conn:
        conn.executescript(SCHEMA)
        row = conn.execute(
            "SELECT id FROM users WHERE username = ?", (config.ADMIN_USER,)
        ).fetchone()
        if row is None:
            conn.execute(
                "INSERT INTO users (username, pw_hash, created) VALUES (?, ?, ?)",
                (config.ADMIN_USER, hash_password(config.ADMIN_PASSWORD), time.time()),
            )
        conn.execute(
            "INSERT OR IGNORE INTO settings (k, v) VALUES ('started_at', ?)",
            (str(time.time()),),
        )
        conn.execute("DELETE FROM sessions WHERE expires < ?", (time.time(),))
        conn.execute("DELETE FROM events WHERE ts < ?", (time.time() - 30 * 86400,))
        conn.execute(
            "DELETE FROM events WHERE id <= "
            "(SELECT COALESCE(MAX(id), 0) - 200000 FROM events)"
        )
    try:
        os.chmod(config.DB_PATH, 0o600)
    except OSError:
        pass


def rows(query: str, params: tuple[Any, ...] = ()) -> list[dict[str, Any]]:
    with db() as conn:
        return [dict(r) for r in conn.execute(query, params).fetchall()]


def row(query: str, params: tuple[Any, ...] = ()) -> dict[str, Any] | None:
    with db() as conn:
        r = conn.execute(query, params).fetchone()
        return dict(r) if r else None


def execute(query: str, params: tuple[Any, ...] = ()) -> int:
    with db() as conn:
        cur = conn.execute(query, params)
        return int(cur.lastrowid or 0)


def add_event(kind: str, agent: str | None = None, ip: str | None = None,
              detail: str | None = None) -> int:
    return execute(
        "INSERT INTO events (ts, kind, agent, ip, detail) VALUES (?, ?, ?, ?, ?)",
        (time.time(), kind, agent, ip, detail),
    )


def get_setting(key: str, default: str = "") -> str:
    r = row("SELECT v FROM settings WHERE k = ?", (key,))
    return r["v"] if r and r["v"] is not None else default


def set_setting(key: str, value: str) -> None:
    execute(
        "INSERT INTO settings (k, v) VALUES (?, ?) "
        "ON CONFLICT(k) DO UPDATE SET v = excluded.v",
        (key, value),
    )
