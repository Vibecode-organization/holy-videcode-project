# SMITH — bench status (iOS 27.2 RC / iPhone14,7 / 24B115)

## Objective
Sandboxed app -> uid 0, no memory-corruption chain. All artifacts are in this folder.

## The three live hypotheses

1. **CoreTrust / signature bypass** (RootKey)
   - Fake Apple-like self-signed CMS (`RootKey-iphone*.ipa`, `RootKey-applesign.ipa`, `RootKey-wwdr.ipa`).
   - TrollStore-style real Apple CMS + modified CodeDirectory (`RootKey-modcd*.ipa`,
     `RootKey-ts*.ipa`, built from ctprobe payloads `p_modcd_reuse` / `p_trollstore`).
   - App entitlements: `platform-application`, `task_for_pid-allow`, `get-task-allow`,
     `com.apple.private.security.no-sandbox`, `com.apple.private.skip-library-validation`.
   - On launch: `task_for_pid(1)` (launchd) then root daemons; injects raw arm64
     payload that writes `/Library/LaunchDaemons/com.smith.root.plist` and runs
     `/bin/sh` as root.
   - Build source `build/rootkey`, signer `tools/sign_app.py` / `tools/sign_app_blob.py`.

2. **cfprefsd AnyUser container / final-symlink** (CFProbe)
   - Public zero-file primitive creates a root-owned empty file at an arbitrary
     missing path. CFProbe tests the canary + tries to make the daemon write a
     launchd plist (`Label`, `ProgramArguments`, `RunAtLoad`) through the same
     symlink. If content is written, reboot loads it as root.
   - Bundle id reuses the installed `com.smith.krwprobe.873962H52X` so an update
     preserves the container.

3. **MCM class-13 system-group sweep** (MCMProbe)
   - Sweeps `systemgroup.com.apple.*` (mobilegestaltcache, installcoordinationd,
     configurationprofiles, pisco.suinfo, osanalytics, codecoveragedata,
     nsurlstoragedresources, ondemandresources, lsd.iconscache) over parts 0..6,
     flags 0x8000000000 / 0x8100000000. Read-only. If `configurationprofiles` /
     `pisco.suinfo` is reachable, the next step is the managed-settings /
     trusted-code-signing-identities path.

## Install order (watcher)
`tools/watch_all.sh` polls `idevice_id`; when the device appears it tries, in order:
RootKey-modcd, RootKey-modcdours, RootKey-ts, RootKey-tsrev, RootKey-iphone,
RootKey-applesign, RootKey-wwdr, then CFProbe-*, then MCMProbe-*.
Each variant is tried with and without `--developer`. On install success it
launches the bundle via `developer core-device launch-application` and pulls
`Documents/rootkey.log` / `cfprobe.log` / `mcmprobe.log` into `logs/`.

## State at 08:00Z
Device offline (last USB 04:19Z). All IPAs built. Watcher running.
No positive root yet; nothing claimed.
