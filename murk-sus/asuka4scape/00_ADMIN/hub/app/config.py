"""Central configuration for the Asuka4scape research hub."""
from __future__ import annotations

import os
from pathlib import Path

APP_DIR = Path(__file__).resolve().parent.parent
WEB_DIR = APP_DIR / "web"
DATA_DIR = Path(os.environ.get("ASUKA_DATA", str(APP_DIR / "data"))).resolve()
LOG_DIR = Path(os.environ.get("ASUKA_LOG_DIR", str(APP_DIR / "logs"))).resolve()

BASE_DIR = Path(os.environ.get("ASUKA_BASE", "/home/femboychik/asuka4scape")).resolve()
AGENTS_DIR = BASE_DIR / "agents"
SHARED_DIR = BASE_DIR / "логи работы ИИ"

DB_PATH = Path(os.environ.get("ASUKA_DB", str(DATA_DIR / "asuka.db"))).resolve()

HOST = os.environ.get("ASUKA_HOST", "0.0.0.0")
PORT = int(os.environ.get("ASUKA_PORT", "8080"))
PUBLIC_URL = os.environ.get("ASUKA_PUBLIC_URL", "").rstrip("/")
TRUST_PROXY = os.environ.get("ASUKA_TRUST_PROXY", "0") == "1"

ADMIN_USER = os.environ.get("ASUKA_ADMIN_USER", "murk")
ADMIN_PASSWORD = os.environ.get("ASUKA_ADMIN_PASSWORD", "HomaHomachkin31")

SESSION_COOKIE = "asuka_session"
SESSION_TTL = 7 * 24 * 3600
ONLINE_WINDOW = 120.0

MAX_READ_BYTES = 256 * 1024
MAX_WRITE_BYTES = 8 * 1024 * 1024
MAX_PREVIEW_BYTES = 512 * 1024
MAX_LIST_ENTRIES = 800

SERVER_NAME = "asuka4scape-hub"
SERVER_VERSION = "1.0.0"
MCP_PATH = "/mcp"

PROTECTED_RESEARCH_DIRS = {"00_ADMIN", "99_QUARANTINE", ".git", "agents", "opencode-studio"}
HIDDEN_NAMES = {".git", "__pycache__", ".trash", "node_modules"}


def ensure_dirs() -> None:
    for path, mode in (
        (DATA_DIR, 0o700),
        (LOG_DIR, 0o700),
        (AGENTS_DIR, 0o755),
        (SHARED_DIR, 0o755),
    ):
        path.mkdir(parents=True, exist_ok=True)
        try:
            os.chmod(path, mode)
        except OSError:
            pass
