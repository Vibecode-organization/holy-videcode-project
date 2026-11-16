#!/bin/bash
# Wait for the iPhone, then try the crafted RootKey IPAs in order.
B=/home/femboychik/claude_code/smith/build
L=/home/femboychik/claude_code/smith/logs/watch.log
mkdir -p /home/femboychik/claude_code/smith/logs
echo "=== watcher start $(date -u) ===" >> "$L"
last=""
while true; do
  ids=$(idevice_id -l 2>/dev/null | tr '\n' ' ')
  if [ -n "$ids" ] && [ "$ids" != "$last" ]; then
    echo "DEVICE $ids at $(date -u)" >> "$L"
    last="$ids"
    for tag in modcd modcdours ts tsrev iphone iphone_noext applesign wwdr control; do
      ipa=$B/RootKey-$tag.ipa
      [ -f "$ipa" ] || continue
      for mode in "" "--developer"; do
        echo "--- install $tag $mode $(date -u)" >> "$L"
        timeout 180 pymobiledevice3 apps install $mode "$ipa" >> "$L" 2>&1
        rc=$?
        echo "install rc=$rc" >> "$L"
        if [ $rc -eq 0 ]; then
          echo "INSTALLED $tag $mode" >> "$L"
          sleep 3
          timeout 60 pymobiledevice3 developer core-device launch-application com.smith.rootkey >> "$L" 2>&1 || \
          timeout 60 pymobiledevice3 developer dvt launch com.smith.rootkey >> "$L" 2>&1 || true
          sleep 8
          timeout 60 pymobiledevice3 apps pull --documents com.smith.rootkey rootkey.log /tmp/rootkey.log >> "$L" 2>&1 || true
          [ -f /tmp/rootkey.log ] && cp /tmp/rootkey.log /home/femboychik/claude_code/smith/logs/rootkey.log
          exit 0
        fi
      done
    done
  fi
  if [ -z "$ids" ]; then last=""; fi
  sleep 20
done
