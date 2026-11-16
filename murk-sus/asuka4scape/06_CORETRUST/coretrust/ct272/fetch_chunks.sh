#!/bin/bash
# Resume-safe chunked fetch of the stored SystemOS AEA entry via HTTP ranges.
set -u
URL="https://updates.cdn-apple.com/2026FallFCS/9e4d9a90-76a7-4d2f-b8ff-f762f4d056d8/iPhone14,7_27.2_24B119_Restore.ipsw"
OFF=198733876
SIZE=2415919104
OUT=/home/femboychik/work/coretrust/ct272/141-09773-227.dmg.aea
CHUNK=$((256*1024*1024))
END=$((OFF+SIZE-1))
have=$(stat -c %s "$OUT" 2>/dev/null || echo 0)
echo "start have=$have target=$SIZE $(date -Is)"
while [ "$have" -lt "$SIZE" ]; do
  a=$((OFF+have)); b=$((a+CHUNK-1)); [ "$b" -gt "$END" ] && b=$END
  want=$((b-a+1))
  curl -sS --fail --connect-timeout 30 --max-time 900 --retry 8 --retry-delay 3 \
       --retry-all-errors --speed-time 60 --speed-limit 100000 \
       -r "$a-$b" "$URL" >> "$OUT" || { echo "chunk fail at $have $(date -Is)"; sleep 2; }
  now=$(stat -c %s "$OUT"); got=$((now-have))
  echo "chunk [$have..$now] got=$got want=$want $(date -Is)"
  if [ "$got" -eq 0 ]; then sleep 3; fi
  if [ "$got" -ne "$want" ] && [ "$got" -gt 0 ] && [ "$got" -lt "$want" ]; then
    echo "short read, continuing from $now"
  fi
  have=$now
done
echo "done $have $(sha256sum "$OUT") $(date -Is)"
