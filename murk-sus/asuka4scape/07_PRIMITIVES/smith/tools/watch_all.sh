#!/bin/bash
# Wait for the iPhone, then try the crafted apps in order. Logs everything.
B=/home/femboychik/claude_code/smith/build
L=/home/femboychik/claude_code/smith/logs/watch.log
mkdir -p /home/femboychik/claude_code/smith/logs
echo "=== watch_all start $(date -u) ===" >> "$L"
last=""
while true; do
  ids=$(idevice_id -l 2>/dev/null | tr '\n' ' ')
  if [ -n "$ids" ] && [ "$ids" != "$last" ]; then
    echo "DEVICE $ids at $(date -u)" >> "$L"
    last="$ids"
    for spec in "RootKey-modcd|com.smith.rootkey|rootkey.log" \
                "RootKey-modcdours|com.smith.rootkey|rootkey.log" \
                "RootKey-ts|com.smith.rootkey|rootkey.log" \
                "RootKey-tsrev|com.smith.rootkey|rootkey.log" \
                "RootKey-iphone|com.smith.rootkey|rootkey.log" \
                "RootKey-applesign|com.smith.rootkey|rootkey.log" \
                "RootKey-wwdr|com.smith.rootkey|rootkey.log" \
                "CFProbe-HSBC-ts|hk.com.hsbc.enterprise.hsbchkrewards.local2|cfprobe.log" \
                "CFProbe-HSBC-tsrev|hk.com.hsbc.enterprise.hsbchkrewards.local2|cfprobe.log" \
                "CFProbe-HSBC-modcd|hk.com.hsbc.enterprise.hsbchkrewards.local2|cfprobe.log" \
                "CFProbe-HSBC-modcdours|hk.com.hsbc.enterprise.hsbchkrewards.local2|cfprobe.log" \
                "CFProbe-modcd|com.smith.cfprobe|cfprobe.log" \
                "CFProbe-modcdours|com.smith.cfprobe|cfprobe.log" \
                "CFProbe-ts|com.smith.cfprobe|cfprobe.log" \
                "CFProbe-tsrev|com.smith.cfprobe|cfprobe.log" \
                "CFProbe-iphone|com.smith.cfprobe|cfprobe.log" \
                "CFProbe-applesign|com.smith.cfprobe|cfprobe.log" \
                "CFProbe-wwdr|com.smith.cfprobe|cfprobe.log" \
                "MCMProbe-modcd|com.smith.mcmprobe|mcmprobe.log" \
                "MCMProbe-ts|com.smith.mcmprobe|mcmprobe.log" \
                "MCMProbe-iphone|com.smith.mcmprobe|mcmprobe.log"; do
      IFS='|' read -r tag bundle logname <<< "$spec"
      ipa=$B/$tag.ipa
      [ -f "$ipa" ] || continue
      for mode in "" "--developer"; do
        echo "--- install $tag $mode $(date -u)" >> "$L"
        timeout 180 pymobiledevice3 apps install $mode "$ipa" >> "$L" 2>&1
        rc=$?
        echo "install rc=$rc" >> "$L"
        if [ $rc -eq 0 ]; then
          echo "INSTALLED $tag $mode" >> "$L"
          sleep 3
          timeout 60 pymobiledevice3 developer core-device launch-application "$bundle" >> "$L" 2>&1 || true
          sleep 8
          timeout 60 pymobiledevice3 apps pull --documents "$bundle" "$logname" "/tmp/$logname" >> "$L" 2>&1 || true
          [ -f "/tmp/$logname" ] && cp "/tmp/$logname" /home/femboychik/claude_code/smith/logs/
          echo "DONE $tag" >> "$L"
        fi
      done
    done
    echo "=== sweep done $(date -u) ===" >> "$L"
    last=""
  fi
  if [ -z "$ids" ]; then last=""; fi
  sleep 30
done
