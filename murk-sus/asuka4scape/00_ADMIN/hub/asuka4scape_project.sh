#!/usr/bin/env bash
# ASUKA4SCAPE HUB launcher — one command starts the admin panel, MCP server and optional tunnel.
set -euo pipefail
umask 077

BASE="${ASUKA_BASE:-/home/femboychik/asuka4scape}"
HUB="$BASE/00_ADMIN/hub"
DATA="$HUB/data"
LOGS="$HUB/logs"
PIDFILE="$DATA/asuka.pid"
TUNNELPID="$DATA/cloudflared.pid"
SERVER_LOG="$LOGS/server.log"
TUNNEL_LOG="$LOGS/tunnel.log"

PORT="${ASUKA_PORT:-8080}"
HOST="${ASUKA_HOST:-0.0.0.0}"
TUNNEL=0
DAEMON=0
OPEN_BROWSER=0
PUBLIC_URL=""
TUNNEL_PID=""
SERVER_PID=""

usage() {
  cat <<'EOF'
ASUKA4SCAPE HUB

  asuka4scape_project [опции]

Опции:
  --port N        порт (по умолчанию 8080)
  --host ADDR     адрес (по умолчанию 0.0.0.0)
  --tunnel        поднять публичный Cloudflare quick tunnel
  --daemon        запустить в фоне
  --open          открыть панель в браузере
  --stop          остановить сервер и туннель
  --status        показать состояние
  --version       версия хаба
  --help          эта справка

Примеры:
  asuka4scape_project
  asuka4scape_project --tunnel
  asuka4scape_project --daemon --tunnel
  asuka4scape_project --stop
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --port) PORT="${2:?нужен номер порта}"; shift 2 ;;
    --host) HOST="${2:?нужен адрес}"; shift 2 ;;
    --tunnel) TUNNEL=1; shift ;;
    --daemon) DAEMON=1; shift ;;
    --open) OPEN_BROWSER=1; shift ;;
    --stop) STOP=1; shift ;;
    --status) STATUS=1; shift ;;
    --version|-V) echo "ASUKA4SCAPE HUB 1.0.0"; exit 0 ;;
    --help|-h) usage; exit 0 ;;
    *) echo "Неизвестная опция: $1" >&2; usage; exit 2 ;;
  esac
done

[[ "$PORT" =~ ^[0-9]+$ ]] || { echo "Порт должен быть числом" >&2; exit 2; }
mkdir -p "$DATA" "$LOGS" "$BASE/agents" "$BASE/логи работы ИИ"

find_cloudflared() {
  if [[ -n "${CLOUDFLARED_BIN:-}" && -x "$CLOUDFLARED_BIN" ]]; then
    echo "$CLOUDFLARED_BIN"; return 0
  fi
  if command -v cloudflared >/dev/null 2>&1; then
    command -v cloudflared; return 0
  fi
  if [[ -x "$HOME/.local/bin/cloudflared" ]]; then
    echo "$HOME/.local/bin/cloudflared"; return 0
  fi
  return 1
}

lan_urls() {
  ip -4 -o addr show scope global 2>/dev/null \
    | awk '{print $4}' | cut -d/ -f1 \
    | grep -v '^10\.8\.' \
    | while read -r ip; do echo "  LAN        http://$ip:$PORT"; done || true
}

public_url() {
  curl -s --max-time 4 https://api.ipify.org 2>/dev/null || true
}

stop_all() {
  if [[ -f "$PIDFILE" ]]; then
    local pid; pid="$(cat "$PIDFILE" 2>/dev/null || true)"
    if [[ -n "$pid" ]] && kill -0 "$pid" 2>/dev/null; then
      kill "$pid" 2>/dev/null || true
      for _ in 1 2 3 4 5; do kill -0 "$pid" 2>/dev/null || break; sleep 0.4; done
      kill -9 "$pid" 2>/dev/null || true
      echo "остановлен сервер (pid $pid)"
    fi
    rm -f "$PIDFILE"
  fi
  if [[ -f "$TUNNELPID" ]]; then
    local pid; pid="$(cat "$TUNNELPID" 2>/dev/null || true)"
    if [[ -n "$pid" ]] && kill -0 "$pid" 2>/dev/null; then
      kill "$pid" 2>/dev/null || true
      echo "остановлен туннель (pid $pid)"
    fi
    rm -f "$TUNNELPID"
  fi
  for pid in $(pgrep -f 'python3 run.py' 2>/dev/null || true); do
    if [[ "$(readlink "/proc/$pid/cwd" 2>/dev/null || true)" == "$HUB" ]]; then
      kill "$pid" 2>/dev/null || true
      echo "остановлен сервер (pid $pid)"
    fi
  done
  pkill -f "$HUB/run.py" 2>/dev/null || true
}

status_all() {
  local running=0
  if [[ -f "$PIDFILE" ]] && kill -0 "$(cat "$PIDFILE" 2>/dev/null || echo 0)" 2>/dev/null; then
    echo "сервер:  запущен (pid $(cat "$PIDFILE"))"
    running=1
  else
    echo "сервер:  pid-файла нет (возможно, foreground)"
  fi
  if [[ -f "$TUNNELPID" ]] && kill -0 "$(cat "$TUNNELPID" 2>/dev/null || echo 0)" 2>/dev/null; then
    echo "туннель: запущен (pid $(cat "$TUNNELPID"))"
    [[ -f "$DATA/public_url.txt" ]] && echo "URL:     $(cat "$DATA/public_url.txt")"
  fi
  if curl -fsS --max-time 2 "http://127.0.0.1:$PORT/healthz" >/dev/null 2>&1; then
    echo "health:  ok (http://127.0.0.1:$PORT)"
    running=1
  else
    echo "health:  нет ответа на 127.0.0.1:$PORT"
  fi
  [[ $running -eq 1 ]]
}

if [[ "${STOP:-0}" == "1" ]]; then stop_all; exit 0; fi
if [[ "${STATUS:-0}" == "1" ]]; then status_all; exit $?; fi

if ! python3 -c 'import fastapi, uvicorn' >/dev/null 2>&1; then
  echo "Не найдены fastapi/uvicorn для python3." >&2
  echo "Установи: python3 -m pip install --user fastapi uvicorn" >&2
  exit 1
fi

start_tunnel() {
  local bin
  if ! bin="$(find_cloudflared)"; then
    echo "cloudflared не найден." >&2
    echo "Скачай: https://github.com/cloudflare/cloudflared/releases/latest/download/cloudflared-linux-amd64" >&2
    echo "в ~/.local/bin/cloudflared и chmod +x." >&2
    return 1
  fi
  : > "$TUNNEL_LOG"
  "$bin" tunnel --url "http://127.0.0.1:$PORT" --no-autoupdate >"$TUNNEL_LOG" 2>&1 &
  TUNNEL_PID=$!
  echo "$TUNNEL_PID" > "$TUNNELPID"
  for _ in $(seq 1 80); do
    PUBLIC_URL="$(grep -Eo 'https://[a-zA-Z0-9._-]+\.trycloudflare\.com' "$TUNNEL_LOG" | head -1 || true)"
    [[ -n "$PUBLIC_URL" ]] && break
    if ! kill -0 "$TUNNEL_PID" 2>/dev/null; then break; fi
    sleep 0.5
  done
  if [[ -z "$PUBLIC_URL" ]]; then
    echo "Не удалось получить URL туннеля. Лог: $TUNNEL_LOG" >&2
    tail -20 "$TUNNEL_LOG" >&2 || true
    return 1
  fi
  export ASUKA_TRUST_PROXY=1
  export ASUKA_PUBLIC_URL="$PUBLIC_URL"
  echo "$PUBLIC_URL" > "$DATA/public_url.txt"
}

cleanup() {
  if [[ -n "$TUNNEL_PID" ]] && kill -0 "$TUNNEL_PID" 2>/dev/null; then
    kill "$TUNNEL_PID" 2>/dev/null || true
  fi
  if [[ -n "$SERVER_PID" ]] && kill -0 "$SERVER_PID" 2>/dev/null; then
    kill "$SERVER_PID" 2>/dev/null || true
  fi
  rm -f "$TUNNELPID"
}
trap cleanup EXIT INT TERM

if [[ "$TUNNEL" == "1" ]]; then
  if [[ -f "$PIDFILE" ]] && kill -0 "$(cat "$PIDFILE" 2>/dev/null || echo 0)" 2>/dev/null; then
    echo "Сервер уже запущен (pid $(cat "$PIDFILE")). Сначала: asuka4scape_project --stop" >&2
    exit 1
  fi
  if curl -fsS --max-time 1 "http://127.0.0.1:$PORT/healthz" >/dev/null 2>&1; then
    echo "Порт $PORT уже отвечает (возможно, сервер запущен в foreground). Сначала: asuka4scape_project --stop" >&2
    exit 1
  fi
  start_tunnel || exit 1
fi

export ASUKA_BASE="$BASE"
export ASUKA_HOST="$HOST"
export ASUKA_PORT="$PORT"

echo
echo "  █ ASUKA4SCAPE HUB"
echo "  ─────────────────────────────────────────────"
echo "  локально   http://127.0.0.1:$PORT"
lan_urls
if [[ -n "$PUBLIC_URL" ]]; then
  echo "  публично   $PUBLIC_URL"
fi
if [[ -z "$PUBLIC_URL" ]]; then
  local_ip="$(public_url)"
  [[ -n "$local_ip" ]] && echo "  внешний IP $local_ip (нужен проброс порта или --tunnel)"
fi
echo "  MCP        ${PUBLIC_URL:-http://127.0.0.1:$PORT}/mcp"
echo "  логин      murk"
echo "  стоп       asuka4scape_project --stop"
echo

if [[ "$DAEMON" == "1" ]]; then
  if [[ -f "$PIDFILE" ]] && kill -0 "$(cat "$PIDFILE" 2>/dev/null || echo 0)" 2>/dev/null; then
    echo "Сервер уже запущен (pid $(cat "$PIDFILE"))." >&2
    exit 1
  fi
  if curl -fsS --max-time 1 "http://127.0.0.1:$PORT/healthz" >/dev/null 2>&1; then
    echo "Порт $PORT уже занят отвечающим сервером. Сначала: asuka4scape_project --stop" >&2
    exit 1
  fi
  cd "$HUB"
  nohup python3 run.py >>"$SERVER_LOG" 2>&1 &
  SERVER_PID=$!
  echo "$SERVER_PID" > "$PIDFILE"
  disown || true
  ready=0
  for _ in $(seq 1 40); do
    if curl -fsS --max-time 1 "http://127.0.0.1:$PORT/healthz" >/dev/null 2>&1; then ready=1; break; fi
    if ! kill -0 "$SERVER_PID" 2>/dev/null; then break; fi
    sleep 0.25
  done
  if ! kill -0 "$SERVER_PID" 2>/dev/null; then
    echo "Сервер не запустился. Смотри $SERVER_LOG" >&2
    tail -30 "$SERVER_LOG" >&2 || true
    exit 1
  fi
  if [[ "$ready" != "1" ]]; then
    echo "Сервер запущен, но health ещё не отвечает. Проверь: asuka4scape_project --status" >&2
  fi
  echo "Сервер в фоне (pid $SERVER_PID). Лог: $SERVER_LOG"
  if [[ "$OPEN_BROWSER" == "1" ]]; then
    xdg-open "${PUBLIC_URL:-http://127.0.0.1:$PORT}/admin" >/dev/null 2>&1 || true
  fi
  # daemon mode: detach tunnel from this shell's trap
  trap - EXIT INT TERM
  exit 0
fi

if [[ "$OPEN_BROWSER" == "1" ]]; then
  xdg-open "${PUBLIC_URL:-http://127.0.0.1:$PORT}/admin" >/dev/null 2>&1 || true
fi

cd "$HUB"
python3 run.py &
SERVER_PID=$!
wait "$SERVER_PID"
