#!/usr/bin/env bash
# Enable a gated stage in IOGPUChain27:
#   ./enable_stage.sh submit   -> Documents/run_submit
#   ./enable_stage.sh paddr    -> Documents/run_paddr
set -eu
BUNDLE="${BUNDLE:-app.lake9674.aquila8809}"
case "${1:-}" in
  submit) NAME=run_submit ;;
  paddr)  NAME=run_paddr ;;
  *) echo "usage: $0 {submit|paddr}"; exit 2 ;;
esac
TMP="$(mktemp)"
: > "$TMP"
pymobiledevice3 apps push "$BUNDLE" "$TMP" "$NAME" --documents
rm -f "$TMP"
echo "[+] pushed Documents/$NAME"
echo "[*] relaunch the app:"
echo "    pymobiledevice3 developer core-device launch-application --kill-existing $BUNDLE"
