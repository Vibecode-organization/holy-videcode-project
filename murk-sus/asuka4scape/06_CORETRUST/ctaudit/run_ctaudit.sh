#!/bin/bash
# Autonomous CoreTrust oracle runner for the separate bundle id.
set -u
BUNDLE="app.lake9674.aquila8809.ctaudit"
HERE="/home/femboychik/asuka4scape/06_CORETRUST/ctaudit"
LOG="/tmp/ctaudit_run.log"
: > "$LOG"
say() { echo "[$(date +%H:%M:%S)] $*" | tee -a "$LOG"; }

say "start; bundle=$BUNDLE"
for i in $(seq 1 30); do
  say "install attempt $i"
  out=$(timeout 120 pymobiledevice3 apps install /tmp/ctaudit-signed.ipa 2>&1)
  rc=$?
  echo "$out" | tail -5 >> "$LOG"
  if [ $rc -eq 0 ] && echo "$out" | grep -qiE "succeed|installed|Installation"; then
    say "install ok"
    break
  fi
  sleep 20
done

if ! echo "$out" | grep -qiE "succeed|installed|Installation"; then
  say "install not confirmed; checking app list"
  timeout 60 pymobiledevice3 apps list 2>/dev/null | grep -q "$BUNDLE" && say "app present" || { say "app missing, abort"; exit 1; }
fi

for f in "$HERE"/cases/*; do
  name=$(basename "$f")
  say "push $name"
  timeout 40 pymobiledevice3 developer core-device write-file appDataContainer "Documents/$name" --identifier "$BUNDLE" "$f" >> "$LOG" 2>&1 || \
  timeout 40 pymobiledevice3 apps push --documents "$BUNDLE" "$f" "Documents/$name" >> "$LOG" 2>&1 || \
  say "push failed: $name"
done

say "launch"
timeout 60 pymobiledevice3 developer core-device launch-application --kill-existing "$BUNDLE" >> "$LOG" 2>&1
sleep 20

say "pull log"
rm -f /tmp/ctaudit_result.log
timeout 40 pymobiledevice3 apps pull "$BUNDLE" Documents/ctaudit.log /tmp/ctaudit_result.log >> "$LOG" 2>&1 || \
timeout 40 pymobiledevice3 developer core-device read-file appDataContainer Documents/ctaudit.log --output /tmp/ctaudit_result.log >> "$LOG" 2>&1
if [ -f /tmp/ctaudit_result.log ]; then
  say "result:"
  cat /tmp/ctaudit_result.log | tee -a "$LOG"
else
  say "no result log"
fi
say "done"
