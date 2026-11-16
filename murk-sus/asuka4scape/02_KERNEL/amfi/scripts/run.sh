#!/bin/bash
# Run a Ghidra post-script against the analyzed 27.2 kernel project.
# usage: run.sh <logfile> <Script.java> [args...]
set -u
LOG="$1"; shift
SCRIPT="$1"; shift
export GHIDRA_HEADLESS_MAXMEM=4G
PROJ="/home/femboychik/Загрузки/AyuGram Desktop/Архив"
/home/femboychik/ghidra/support/analyzeHeadless "$PROJ" 123 \
  -process kernelcache.release.iphone14b.decompressed \
  -noanalysis -readOnly \
  -scriptPath /home/femboychik/work/amfi/scripts \
  -postScript "$SCRIPT" "$@" > "$LOG" 2>&1
echo "EXIT=$?" >> "$LOG"
