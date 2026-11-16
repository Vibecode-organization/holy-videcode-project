#!/bin/bash
# Wait for the 24B115 IPSW download, then extract the 27.2 root FS and key daemons.
set -u
cd /home/femboychik/work/rc115 || exit 1
LOG=/home/femboychik/work/rc115/extract_272.log
exec > "$LOG" 2>&1
echo "start $(date)"

# Wait for aria2c (match only the aria2c process, not this script)
while pgrep -f "aria2c .*iPhone14,7_27.2_24B115" >/dev/null; do sleep 20; done
sleep 5
echo "download done $(date)"
ls -la iPhone14,7_27.2_24B115_Restore.ipsw

# List IPSW contents; find the root FS AEA (largest .dmg.aea)
unzip -l iPhone14,7_27.2_24B115_Restore.ipsw > ipsw_list_272.txt
echo "--- dmg.aea ---"
grep -E '\.dmg\.aea$' ipsw_list_272.txt | sort -nr | head -10

ROOT=$(grep -E '\.dmg\.aea$' ipsw_list_272.txt | sort -nr | head -1 | awk '{print $NF}')
echo "ROOT=$ROOT"
[ -z "$ROOT" ] && { echo "no root dmg"; exit 2; }

if [ ! -f root272.dmg.aea ]; then
  echo "extracting $ROOT $(date)"
  unzip -p iPhone14,7_27.2_24B115_Restore.ipsw "$ROOT" > root272.dmg.aea
fi
ls -la root272.dmg.aea

mkdir -p out272
if [ ! -f out272/root272.dmg ]; then
  echo "decrypting aea $(date)"
  ipsw fw aea root272.dmg.aea -o out272
fi
ls -la out272

# Extract daemons/frameworks of interest
echo "--- root fs listing ---"
7z l out272/root272.dmg > root272_fs.txt
grep -E "usr/libexec/(installd|containermanagerd|amfid|sharingd|quicklookd|mediaparserd|streaming_zip_conduit)|InstalledContentLibrary.framework|MobileInstallation.framework|ContainerManager" root272_fs.txt | head -60

mkdir -p daemons
for f in \
  "usr/libexec/installd" \
  "usr/libexec/containermanagerd" \
  "usr/libexec/amfid" \
  "usr/libexec/sharingd" \
  "usr/libexec/quicklookd" \
  "usr/libexec/mediaparserd" \
  "usr/libexec/streaming_zip_conduit" ; do
  out="daemons/$(basename "$f")"
  if [ ! -s "$out" ]; then
    7z x -so out272/root272.dmg "$f" > "$out" 2>/dev/null
  fi
  printf "%-30s %s\n" "$(basename "$f")" "$(stat -c%s "$out" 2>/dev/null)"
done

echo "done $(date)"
