#!/usr/bin/env python3
"""Entry point used by the asuka4scape_project launcher."""
from __future__ import annotations

import os
import sys
from pathlib import Path

os.umask(0o077)
sys.path.insert(0, str(Path(__file__).resolve().parent))

import uvicorn  # noqa: E402

from app import config  # noqa: E402


def main() -> None:
    uvicorn.run(
        "app.main:app",
        host=config.HOST,
        port=config.PORT,
        log_level=os.environ.get("ASUKA_LOG_LEVEL", "info"),
        access_log=True,
        proxy_headers=True if config.TRUST_PROXY else False,
        forwarded_allow_ips="127.0.0.1" if config.TRUST_PROXY else None,
        timeout_keep_alive=30,
    )


if __name__ == "__main__":
    main()
