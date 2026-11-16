# SMITH — rootkey journal

Target: iPhone14,7 / iOS 27.2 RC 24B115, sandboxed app -> uid 0.

Working hypothesis (simple, no memory corruption):
1. CoreTrust/AMFI accepts a self-signed "Apple-like" CMS chain for a Mach-O.
2. Install a fake-Apple-signed app carrying platform-application + task_for_pid-allow.
3. That app gets launchd's task port and injects a tiny arm64 payload that writes a
   root LaunchDaemon plist and spawns /bin/sh as root.

Artifacts:
- build/rootkey/        app source + payload.S
- tools/sign_app.py     CoreTrust CMS signer for an app executable
- tools/build_rootkey.sh

Status: building. Device not attached at 05:35Z.
