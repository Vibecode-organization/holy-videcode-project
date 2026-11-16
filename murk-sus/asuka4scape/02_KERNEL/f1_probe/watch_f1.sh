#!/usr/bin/env bash
# Wait for the iPhone, install F1Probe, run it, pull the real log.
# 12-hour window. All output -> chainlogs/f1_watcher.log
set -u

BUNDLE="${BUNDLE:-app.lake9674.aquila8809}"
UDID="${UDID:-REDACTED-UDID}"
IPA="/home/femboychik/Рабочий стол/F1Probe-signed.ipa"
OUT="/home/femboychik/Рабочий стол/chainlogs"
mkdir -p "$OUT"
LOG="$OUT/f1_watcher.log"
exec >>"$LOG" 2>&1

echo "=== f1_watcher start $(date) ==="
END=$((SECONDS + 43200))
ATTEMPT=0
INSTALLED=0

while [ "$SECONDS" -lt "$END" ]; do
    ATTEMPT=$((ATTEMPT + 1))
    if ! idevice_id -l 2>/dev/null | grep -q "$UDID"; then
        sleep 30; continue
    fi
    if ! timeout 15 ideviceinfo -k ProductVersion >/dev/null 2>&1; then
        echo "[$ATTEMPT] lockdownd not ready $(date)"; sleep 30; continue
    fi
    echo "[$ATTEMPT] device ready $(date)"

    if [ "$INSTALLED" -eq 0 ]; then
        echo "[$ATTEMPT] installing $IPA"
        if timeout 240 pymobiledevice3 apps install "$IPA" >/dev/null 2>&1; then
            echo "[$ATTEMPT] install OK"
            INSTALLED=1
        else
            echo "[$ATTEMPT] install failed; retry next unlock"
            sleep 30; continue
        fi
    fi

    echo "[$ATTEMPT] launching $BUNDLE"
    timeout 60 pymobiledevice3 developer core-device launch-application \
        --kill-existing "$BUNDLE" >/dev/null 2>&1 || true

    for i in $(seq 1 48); do
        sleep 5
        rm -f "$OUT/f1-latest.log"
        timeout 45 pymobiledevice3 apps pull "$BUNDLE" F1Probe/latest.log \
            "$OUT/f1-latest.log" --documents >/dev/null 2>&1 || true
        if [ -s "$OUT/f1-latest.log" ] && grep -q 'F1Probe done' "$OUT/f1-latest.log"; then
            TS="$(date +%Y%m%d-%H%M%S)"
            cp "$OUT/f1-latest.log" "$OUT/f1-$TS.log"
            echo "[$ATTEMPT] F1 DONE $(date) -> f1-$TS.log"
            tail -80 "$OUT/f1-latest.log"
            exit 0
        fi
    done
    echo "[$ATTEMPT] no completed F1 run; retry $(date)"
    sleep 60
done

echo "=== f1_watcher timeout $(date) ==="
exit 2
