"""Safe filesystem helpers: path jail, listing, range reads, atomic writes."""
from __future__ import annotations

import base64
import hashlib
import os
import re
import shutil
import time
from pathlib import Path
from typing import Any

from . import config

NAME_RE = re.compile(r"^[\w.\-]{1,64}$", re.UNICODE)
RESERVED = {"agents", "00_ADMIN", "99_QUARANTINE", "логи работы ИИ", ".trash"}


class PathError(ValueError):
    pass


def valid_folder_name(name: str) -> bool:
    if not name or name in {".", ".."} or name in RESERVED:
        return False
    return bool(NAME_RE.fullmatch(name))


def valid_agent_name(name: str) -> bool:
    return valid_folder_name(name)


def _within(path: Path, root: Path) -> bool:
    try:
        path.resolve().relative_to(root.resolve())
        return True
    except (ValueError, OSError):
        return False


def resolve(root: Path, rel: str = "", *, must_exist: bool = False) -> Path:
    rel = (rel or "").strip()
    if "\x00" in rel:
        raise PathError("Недопустимый путь")
    if rel.startswith(("/", "\\")) or re.match(r"^[A-Za-z]:", rel):
        raise PathError("Абсолютные пути запрещены")
    parts = [p for p in Path(rel).parts if p not in ("", ".")]
    if any(p == ".." for p in parts):
        raise PathError("Выход за пределы каталога запрещён")
    target = root.joinpath(*parts)
    probe = target if target.exists() else target.parent
    if not _within(probe, root):
        raise PathError("Выход за пределы каталога запрещён")
    if must_exist and not target.exists():
        raise PathError("Файл или каталог не найден")
    return target


def workspace(agent: str, *, must_exist: bool = True) -> Path:
    if not valid_agent_name(agent):
        raise PathError("Недопустимое имя агента")
    path = config.AGENTS_DIR / agent
    if path.is_symlink():
        raise PathError("Рабочая папка не может быть символической ссылкой")
    if not _within(path, config.AGENTS_DIR):
        raise PathError("Рабочая папка вне каталога agents")
    if must_exist and not path.is_dir():
        raise PathError("Рабочая папка агента не найдена")
    return path


def shared_root() -> Path:
    config.SHARED_DIR.mkdir(parents=True, exist_ok=True)
    return config.SHARED_DIR


def human_size(size: int) -> str:
    value = float(size)
    for unit in ("B", "KB", "MB", "GB", "TB"):
        if value < 1024 or unit == "TB":
            return f"{value:.0f} {unit}" if unit == "B" else f"{value:.1f} {unit}"
        value /= 1024
    return f"{size} B"


def file_entry(path: Path, rel: str) -> dict[str, Any]:
    try:
        stat = path.lstat()
        size = stat.st_size
        mtime = stat.st_mtime
        is_dir = path.is_dir()
    except OSError:
        size, mtime, is_dir = 0, 0.0, False
    return {
        "name": path.name,
        "path": rel.replace(os.sep, "/"),
        "is_dir": is_dir,
        "is_symlink": path.is_symlink(),
        "size": size,
        "size_h": human_size(size),
        "mtime": mtime,
    }


def list_dir(root: Path, rel: str = "", limit: int | None = None) -> list[dict[str, Any]]:
    base = resolve(root, rel, must_exist=True)
    if not base.is_dir():
        raise PathError("Это не каталог")
    limit = limit or config.MAX_LIST_ENTRIES
    out: list[dict[str, Any]] = []
    try:
        entries = list(os.scandir(base))
    except OSError as exc:
        raise PathError(f"Не удалось прочитать каталог: {exc}") from exc
    for entry in entries:
        if entry.name in config.HIDDEN_NAMES:
            continue
        child_rel = f"{rel.rstrip('/')}/{entry.name}".lstrip("/")
        out.append(file_entry(Path(entry.path), child_rel))
        if len(out) >= limit:
            break
    out.sort(key=lambda e: (not e["is_dir"], e["name"].casefold()))
    return out


def read_slice(root: Path, rel: str, offset: int = 0, length: int | None = None
               ) -> dict[str, Any]:
    path = resolve(root, rel, must_exist=True)
    if not path.is_file():
        raise PathError("Это не файл")
    total = path.stat().st_size
    offset = max(0, min(int(offset), total))
    want = min(int(length or config.MAX_READ_BYTES), config.MAX_READ_BYTES * 8)
    with path.open("rb") as fh:
        fh.seek(offset)
        data = fh.read(want)
    binary = b"\x00" in data[:8192]
    result: dict[str, Any] = {
        "path": rel.replace(os.sep, "/"),
        "size": total,
        "size_h": human_size(total),
        "offset": offset,
        "bytes": len(data),
        "truncated": offset + len(data) < total,
        "binary": binary,
        "sha256_slice": hashlib.sha256(data).hexdigest(),
    }
    if binary:
        result["content_b64"] = base64.b64encode(data).decode()
        result["note"] = "Бинарный файл: content_b64 содержит запрошенный срез."
    else:
        result["content"] = data.decode("utf-8", errors="replace")
    return result


def read_text(root: Path, rel: str, limit: int | None = None) -> str:
    info = read_slice(root, rel, 0, limit or config.MAX_PREVIEW_BYTES)
    if info["binary"]:
        return ""
    return info["content"]


def write_text(rel: str, content: str, *, agent: str, append: bool = False,
               max_bytes: int | None = None) -> dict[str, Any]:
    root = workspace(agent)
    target = resolve(root, rel)
    if target.exists() and target.is_symlink():
        raise PathError("Запись через символические ссылки запрещена")
    if target.is_dir():
        raise PathError("Это каталог")
    data = content.encode("utf-8")
    limit = max_bytes or config.MAX_WRITE_BYTES
    if len(data) > limit:
        raise PathError(f"Слишком большой файл (лимит {human_size(limit)})")
    target.parent.mkdir(parents=True, exist_ok=True)
    if not _within(target.parent, root):
        raise PathError("Выход за пределы рабочей папки")
    if append and target.exists():
        with target.open("ab") as fh:
            fh.write(data)
    else:
        tmp = target.with_name(f".{target.name}.tmp-{os.getpid()}-{int(time.time() * 1000)}")
        with tmp.open("wb") as fh:
            fh.write(data)
        os.replace(tmp, target)
    stat = target.stat()
    return {
        "path": rel.replace(os.sep, "/"),
        "size": stat.st_size,
        "size_h": human_size(stat.st_size),
        "sha256": hashlib.sha256(data).hexdigest(),
    }


def delete_own_file(rel: str, agent: str) -> dict[str, Any]:
    root = workspace(agent)
    target = resolve(root, rel, must_exist=True)
    if target == root:
        raise PathError("Нельзя удалить корень рабочей папки")
    if target.is_dir():
        raise PathError("Удаление каталогов через MCP запрещено")
    trash = root / ".trash"
    trash.mkdir(exist_ok=True)
    dest = trash / f"{target.name}.{int(time.time())}"
    shutil.move(str(target), str(dest))
    return {"path": rel, "trashed_as": str(dest.relative_to(root))}


def ensure_workspace(agent: str, note: str = "") -> Path:
    root = workspace(agent, must_exist=False)
    if root.is_symlink():
        raise PathError("Рабочая папка не может быть символической ссылкой")
    root.mkdir(parents=True, exist_ok=True)
    for sub in ("notes", "evidence", "scripts"):
        (root / sub).mkdir(exist_ok=True)
    readme = root / "README.md"
    if not readme.exists():
        readme.write_text(
            f"# {agent}\n\n"
            "Рабочая папка исследователя в ASUKA4SCAPE HUB.\n\n"
            f"- Создана: {time.strftime('%Y-%m-%d %H:%M')}\n"
            f"- Заметка: {note or '—'}\n\n"
            "Пиши сюда черновики, доказательства и скрипты. Итоги — в общую папку "
            "`логи работы ИИ` через инструмент `create_report`.\n",
            encoding="utf-8",
        )
    return root


def slugify(text: str, fallback: str = "report") -> str:
    text = text.strip()[:80]
    text = re.sub(r"[^\w.\- ]+", "", text, flags=re.UNICODE).strip()
    text = re.sub(r"[\s]+", "-", text)
    return text or fallback


def write_report(agent: str, title: str, summary: str, body: str,
                 tags: str = "") -> tuple[Path, str]:
    root = shared_root()
    day = time.strftime("%Y-%m-%d")
    folder = root / day
    folder.mkdir(parents=True, exist_ok=True)
    stamp = time.strftime("%H%M%S")
    name = f"{stamp}_{slugify(title)}_{agent}.md"
    path = folder / name
    if path.exists():
        path = folder / f"{stamp}_{slugify(title)}_{agent}_{os.getpid()}.md"
    front = (
        "---\n"
        f"title: {title}\n"
        f"agent: {agent}\n"
        f"created: {time.strftime('%Y-%m-%d %H:%M:%S')}\n"
        f"tags: {tags}\n"
        "---\n\n"
    )
    text = front + f"# {title}\n\n"
    if summary:
        text += f"**Кратко:** {summary}\n\n"
    text += body.strip() + "\n"
    path.write_text(text, encoding="utf-8")
    return path, path.relative_to(root).as_posix()


def tree_stats(path: Path, limit: int = 200000) -> tuple[int, int]:
    files = 0
    total = 0
    for root, dirs, names in os.walk(path, followlinks=False):
        dirs[:] = [d for d in dirs if d not in config.HIDDEN_NAMES]
        for name in names:
            try:
                total += (Path(root) / name).lstat().st_size
                files += 1
            except OSError:
                pass
            if files >= limit:
                return files, total
    return files, total


def move_folder_to_trash(name: str) -> Path:
    src = workspace(name)
    trash = config.AGENTS_DIR / ".trash"
    trash.mkdir(exist_ok=True)
    dest = trash / f"{name}-{int(time.time())}"
    shutil.move(str(src), str(dest))
    return dest


def research_root() -> Path:
    return config.BASE_DIR


def research_resolve(rel: str = "", *, must_exist: bool = True) -> Path:
    rel = (rel or "").strip()
    first = Path(rel).parts[0] if Path(rel).parts else ""
    if first in config.PROTECTED_RESEARCH_DIRS:
        raise PathError("Этот раздел закрыт для агентов")
    if any(p in config.HIDDEN_NAMES for p in Path(rel).parts):
        raise PathError("Служебный каталог закрыт")
    return resolve(config.BASE_DIR, rel, must_exist=must_exist)


def list_research(rel: str = "", limit: int | None = None) -> list[dict[str, Any]]:
    research_resolve(rel, must_exist=True)
    entries = list_dir(config.BASE_DIR, rel, limit=limit)
    if not rel.strip("/"):
        entries = [
            e for e in entries
            if e["name"] not in config.PROTECTED_RESEARCH_DIRS
            and not e["name"].startswith(".")
        ]
    return entries


def search_research(query: str, limit: int = 60) -> list[dict[str, Any]]:
    q = query.casefold().strip()
    if len(q) < 2:
        raise PathError("Слишком короткий запрос")
    out: list[dict[str, Any]] = []
    base = config.BASE_DIR
    stop = time.time() + 5.0
    for root, dirs, names in os.walk(base, followlinks=False):
        dirs[:] = [
            d for d in dirs
            if d not in config.HIDDEN_NAMES
            and not d.startswith(".")
            and str(Path(root, d).relative_to(base)) not in config.PROTECTED_RESEARCH_DIRS
        ]
        if time.time() > stop:
            break
        for d in dirs:
            if q in d.casefold():
                p = Path(root) / d
                rel = p.relative_to(base).as_posix()
                out.append(file_entry(p, rel))
                if len(out) >= limit:
                    return out
        for name in names:
            if name.startswith(".") or name in config.HIDDEN_NAMES:
                continue
            if q in name.casefold():
                p = Path(root) / name
                rel = p.relative_to(base).as_posix()
                out.append(file_entry(p, rel))
                if len(out) >= limit:
                    return out
    return out
