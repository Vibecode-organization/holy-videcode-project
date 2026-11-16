#!/usr/bin/env bash
# Wait for the iPhone, preserve any completed run, otherwise launch and pull.
# Never deletes a completed latest.log before saving it.
set -u

BUNDLE="${BUNDLE:-app.lake9674.aquila8809}"
UDID="${UDID:-REDACTED-UDID}"
OUT="/home/femboychik/Рабочий стол/chainlogs"
mkdir -p "$OUT"
LOG="$OUT/watcher2.log"
SAVED="$OUT/saved.sha"
exec >>"$LOG" 2>&1

echo "=== watcher2 start $(date) ==="
END=$((SECONDS + 28800))
ATTEMPT=0

save_run() {
    local src="$1"
    local ts
    ts="$(date +%Y%m%d-%H%M%S)"
    cp "$src" "$OUT/overnight-$ts.log"
    timeout 45 pymobiledevice3 apps pull "$BUNDLE" IOGPUChain27/latest.json \
        "$OUT/overnight-$ts.json" --documents >/dev/null 2>&1 || true
    sha256sum "$src" | awk '{print $1}' > "$SAVED"
    echo "[+] saved $OUT/overnight-$ts.log"
    tail -40 "$src"
}

while [ "$SECONDS" -lt "$END" ]; do
    ATTEMPT=$((ATTEMPT + 1))

    if ! idevice_id -l 2>/dev/null | grep -q "$UDID"; then
        sleep 30
        continue
    fi
    if ! timeout 15 ideviceinfo -k ProductVersion >/dev/null 2>&1; then
        echo "[$ATTEMPT] lockdownd not ready $(date)"
        sleep 30
        continue
    fi

    echo "[$ATTEMPT] device ready $(date)"

    # 1. Preserve a run that already completed on the device.
    rm -f "$OUT/overnight.log"
    timeout 45 pymobiledevice3 apps pull "$BUNDLE" IOGPUChain27/latest.log \
        "$OUT/overnight.log" --documents >/dev/null 2>&1 || true
    if [ -s "$OUT/overnight.log" ] && grep -q '=== done ===' "$OUT/overnight.log"; then
        SHA="$(sha256sum "$OUT/overnight.log" | awk '{print $1}')"
        if [ ! -f "$SAVED" ] || [ "$SHA" != "$(cat "$SAVED")" ]; then
            save_run "$OUT/overnight.log"
            exit 0
        fi
        echo "[$ATTEMPT] already saved; launching a fresh run"
    fi

    # 2. Launch a fresh run.
    echo "[$ATTEMPT] launching $BUNDLE"
    timeout 45 pymobiledevice3 developer core-device launch-application \
        --kill-existing "$BUNDLE" >/dev/null 2>&1 || true

    # 3. Poll for completion; do not delete the device log.
    for i in $(seq 1 60); do
        sleep 5
        rm -f "$OUT/overnight.log"
        timeout 45 pymobiledevice3 apps pull "$BUNDLE" IOGPUChain27/latest.log \
            "$OUT/overnight.log" --documents >/dev/null 2>&1 || true
        if [ -s "$OUT/overnight.log" ] && grep -q '=== done ===' "$OUT/overnight.log"; then
            SHA="$(sha256sum "$OUT/overnight.log" | awk '{print $1}')"
            if [ ! -f "$SAVED" ] || [ "$SHA" != "$(cat "$SAVED")" ]; then
                save_run "$OUT/overnight.log"
                exit 0
            fi
        fi
    done

    echo "[$ATTEMPT] no completed run; retry $(date)"
    sleep 30
done

echo "=== watcher2 timeout $(date) ==="
exit 2
