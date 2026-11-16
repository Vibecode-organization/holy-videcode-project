#!/usr/bin/env bash
# Pull the latest IOGPUChain27 run from the connected iPhone.
# Usage: ./pull_chain.sh [bundle-id]
set -u

BUNDLE="${1:-app.lake9674.aquila8809}"
OUT="/home/femboychik/Рабочий стол/chainlogs"
mkdir -p "$OUT"

echo "[*] launching $BUNDLE"
timeout 45 pymobiledevice3 developer core-device launch-application \
    --kill-existing "$BUNDLE" >/dev/null 2>&1 || \
    echo "[!] CoreDevice launch failed (device locked?) — tap the app manually"

echo "[*] waiting for run to finish"
for i in $(seq 1 24); do
    sleep 5
    rm -f "$OUT/latest.log"
    # Preferred path: house_arrest (Documents root).
    timeout 30 pymobiledevice3 apps pull "$BUNDLE" IOGPUChain27/latest.log \
        "$OUT/latest.log" --documents >/dev/null 2>&1 || true
    # Fallback: CoreDevice read-file.
    if [ ! -s "$OUT/latest.log" ]; then
        timeout 30 pymobiledevice3 developer core-device read-file appDataContainer \
            Documents/IOGPUChain27/latest.log --identifier "$BUNDLE" \
            --output "$OUT/latest.log" >/dev/null 2>&1 || true
    fi
    if [ -s "$OUT/latest.log" ] && grep -q '=== done ===' "$OUT/latest.log"; then
        echo "[*] done after $((i*5))s"
        break
    fi
done

rm -f "$OUT/latest.json"
timeout 30 pymobiledevice3 apps pull "$BUNDLE" IOGPUChain27/latest.json \
    "$OUT/latest.json" --documents >/dev/null 2>&1 || \
timeout 30 pymobiledevice3 developer core-device read-file appDataContainer \
    Documents/IOGPUChain27/latest.json --identifier "$BUNDLE" \
    --output "$OUT/latest.json" >/dev/null 2>&1 || true

echo "===== latest.log ====="
cat "$OUT/latest.log" 2>/dev/null || echo "(no log)"
echo
echo "===== latest.json ====="
cat "$OUT/latest.json" 2>/dev/null || echo "(no json)"
