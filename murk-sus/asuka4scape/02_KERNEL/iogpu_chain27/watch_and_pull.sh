#!/usr/bin/env bash
# Wait for the iPhone to become available, launch IOGPUChain27, pull the run.
# Runs up to 8 hours. All output goes to chainlogs/watcher.log.
set -u

BUNDLE="${BUNDLE:-app.lake9674.aquila8809}"
UDID="${UDID:-REDACTED-UDID}"
OUT="/home/femboychik/Рабочий стол/chainlogs"
mkdir -p "$OUT"
LOG="$OUT/watcher.log"
exec >>"$LOG" 2>&1

echo "=== watcher start $(date) ==="
END=$((SECONDS + 28800))
ATTEMPT=0

while [ "$SECONDS" -lt "$END" ]; do
    ATTEMPT=$((ATTEMPT + 1))
    if ! idevice_id -l 2>/dev/null | grep -q "$UDID"; then
        sleep 30
        continue
    fi

    if ! timeout 15 ideviceinfo -k ProductVersion >/dev/null 2>&1; then
        echo "[$ATTEMPT] device visible, lockdownd not ready $(date)"
        sleep 30
        continue
    fi

    echo "[$ATTEMPT] device ready $(date)"
    # Remove stale latest.log so we cannot pull an old run.
    timeout 30 pymobiledevice3 apps rm "$BUNDLE" IOGPUChain27/latest.log --documents >/dev/null 2>&1 || true

    echo "[$ATTEMPT] launching $BUNDLE"
    timeout 45 pymobiledevice3 developer core-device launch-application --kill-existing "$BUNDLE" >/dev/null 2>&1 || true

    for i in $(seq 1 36); do
        sleep 5
        rm -f "$OUT/overnight.log"
        timeout 30 pymobiledevice3 apps pull "$BUNDLE" IOGPUChain27/latest.log \
            "$OUT/overnight.log" --documents >/dev/null 2>&1 || true
        if [ -s "$OUT/overnight.log" ] && grep -q '=== done ===' "$OUT/overnight.log"; then
            TS="$(date +%Y%m%d-%H%M%S)"
            cp "$OUT/overnight.log" "$OUT/overnight-$TS.log"
            timeout 30 pymobiledevice3 apps pull "$BUNDLE" IOGPUChain27/latest.json \
                "$OUT/overnight.json" --documents >/dev/null 2>&1 || true
            cp "$OUT/overnight.json" "$OUT/overnight-$TS.json" 2>/dev/null || true
            echo "[$ATTEMPT] DONE $(date) -> overnight-$TS.log"
            tail -30 "$OUT/overnight.log"
            exit 0
        fi
    done
    echo "[$ATTEMPT] no completed run; retry in 60s $(date)"
    sleep 60
done

echo "=== watcher timeout $(date) ==="
exit 2
