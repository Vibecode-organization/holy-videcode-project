#!/bin/bash
# AVEMCTFProbe runner — install, launch, pull log/panic. Works only when the
# iPhone is connected and unlocked. Usage:
#   ./run.sh            # properties-only pass (safe)
#   ./run.sh encode     # also push Documents/run_encode -> encoder pass (may panic)
set -u
BUNDLE=app.lake9674.aquila8809
DIR="$(cd "$(dirname "$0")" && pwd)"
IPA="$DIR/AVEMCTFProbe-signed.ipa"
OUT="$DIR/AVE_MCTF_RESULT"
mkdir -p "$OUT"

echo "waiting for device..." | tee "$OUT/status.txt"
for i in $(seq 1 3600); do
  if timeout 3 ideviceinfo -k ProductVersion >/dev/null 2>&1; then
    echo "device at $(date)" >> "$OUT/status.txt"; break
  fi
  sleep 1
done
if ! timeout 3 ideviceinfo -k ProductVersion >/dev/null 2>&1; then
  echo "no device; abort" >> "$OUT/status.txt"; exit 1
fi

echo "installing..." >> "$OUT/status.txt"
timeout 120 pymobiledevice3 apps install "$IPA" >> "$OUT/install.log" 2>&1
echo "install rc=$?" >> "$OUT/status.txt"

GATES=""
case "${1:-}" in
  encode) GATES="run_encode" ;;
  ave2)   GATES="run_ave2" ;;
  scaler) GATES="run_scaler" ;;
  all)    GATES="run_encode run_ave2 run_scaler" ;;
esac
for g in $GATES; do
  printf 'x' > "/tmp/opencode/$g"
  timeout 30 pymobiledevice3 apps push "$BUNDLE" "/tmp/opencode/$g" "/Documents/$g" >> "$OUT/status.txt" 2>&1
  echo "push $g rc=$?" >> "$OUT/status.txt"
done

echo "launching..." >> "$OUT/status.txt"
timeout 30 pymobiledevice3 developer core-device launch-application --kill-existing "$BUNDLE" >> "$OUT/status.txt" 2>&1
echo "launch rc=$?" >> "$OUT/status.txt"
sleep 25

echo "pulling log..." >> "$OUT/status.txt"
timeout 30 pymobiledevice3 developer core-device read-file appDataContainer /Documents/avemctf.log \
  --identifier "$BUNDLE" --output "$OUT/avemctf.log" >> "$OUT/status.txt" 2>&1
echo "read log rc=$?" >> "$OUT/status.txt"
timeout 30 pymobiledevice3 crash parse-latest -m panic -n 3 > "$OUT/panic.txt" 2>&1
timeout 30 pymobiledevice3 crash ls / -d 1 > "$OUT/crash_ls.txt" 2>&1
echo "done at $(date)" >> "$OUT/status.txt"
