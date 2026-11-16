#!/bin/bash
# Wait for Kai to install CFProbe/MCMProbe, launch them, pull logs.
L=/home/femboychik/claude_code/smith/logs/signed_watch.log
mkdir -p /home/femboychik/claude_code/smith/logs
echo "=== signed watch start $(date -u) ===" >> "$L"
while true; do
  timeout 30 pymobiledevice3 apps list > /tmp/apps_now.json 2>/dev/null
  if [ -s /tmp/apps_now.json ]; then
    python3 - <<'PY' > /tmp/signed_hit.txt
import json
try: d=json.load(open('/tmp/apps_now.json'))
except Exception: raise SystemExit
for k,v in d.items():
    if v.get('CFBundleDisplayName') in ('CFProbe','MCMProbe'):
        print(k, v.get('CFBundleDisplayName'), v.get('Path'))
PY
    hit=$(cat /tmp/signed_hit.txt)
    if [ -n "$hit" ]; then
      echo "HIT $hit at $(date -u)" >> "$L"
      bundle=$(echo "$hit" | awk '{print $1}')
      name=$(echo "$hit" | awk '{print $2}')
      timeout 60 pymobiledevice3 developer core-device launch-application "$bundle" >> "$L" 2>&1 || true
      sleep 10
      logname=cfprobe.log; [ "$name" = "MCMProbe" ] && logname=mcmprobe.log
      timeout 60 pymobiledevice3 apps pull --documents "$bundle" "$logname" "/tmp/$logname" >> "$L" 2>&1 || true
      [ -f "/tmp/$logname" ] && cp "/tmp/$logname" /home/femboychik/claude_code/smith/logs/
      echo "DONE $name" >> "$L"
      exit 0
    fi
  fi
  sleep 10
done
