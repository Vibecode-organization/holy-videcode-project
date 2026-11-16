#!/usr/bin/env bash
# language: bash, file: pull_267.sh
# 26.7.2 (23H128) is OTA-only for iPhone14,7: no Restore IPSW in the public
# asset set, so the kernelcache comes out of the AEA-sealed OTA payload.
set -euo pipefail
cd "$(dirname "$0")"

DEV=iPhone14,7
VER=26.7.2
OUT=ota

mkdir -p "$OUT"

# 1. AEA key for the OTA asset (Apple publishes it in the Pallas metadata)
ipsw download ota --platform ios --device "$DEV" --version "$VER" \
    --fcs-keys -o "$OUT"

# 2. The payload itself. ipsw's own multipart downloader stalls on this CDN
#    path; aria2 with 16 connections pulls the same object clean.
URL=$(python3 - <<'PY'
import json
k = json.load(open("ota/ota_fcs_keys.json"))
print(k[0]["url"])
PY
)
NAME=$(basename "$URL")

aria2c -x16 -s16 -k1M -c --file-allocation=none --console-log-level=error \
    -d "$OUT" -o "$NAME" "$URL"

# 3. Kernelcache out of the OTA
ipsw ota extract "$OUT/$NAME" --kernel --flat --output ./kc \
    --key-db "$OUT/ota_fcs_keys.json" --confirm

ls -la ./kc
