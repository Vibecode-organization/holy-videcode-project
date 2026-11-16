# asuka4scape — upload manifest
Generated: 2026-11-16T14:33:48.977193+00:00
## Source
- Source path on the author's PC: `/home/femboychik/asuka4scape`
- Full source size: **226 GB** (106,379 files)
- Uploaded to GitHub: **23,257 files, 0.27 GB**
- UDID occurrences in text files: **12** (replaced with `REDACTED-UDID`)
- Binary files skipped because they contained the UDID: **0**
- Sensitive files skipped (keys, certificates, profiles, signed IPAs, binaries): **1104**
- Files over 20 MB skipped: **11**

## Why the full tree is not here
GitHub blocks individual files over 100 MB and the repository becomes impractical at hundreds of gigabytes.
The full `asuka4scape` tree contains ~245 GB of firmware images (IPSW/DMG/AEA), OTA files, kernelcaches,
Ghidra databases, build products and tool binaries. They are research artifacts, not project source.
This folder contains the project's source code, reports, notes, scripts and small artifacts.

Excluded directories: `09_TOOLS` (209 MB), `99_QUARANTINE` (150 MB), `ghidra` (119 MB) — tool binaries, Ghidra databases and quarantined artifacts.

## Excluded files over 20 MB (top 400 by size)
| Size | Path |
|---:|---|
| 0.28 GB | `06_CORETRUST/syslog_bqtool.log` |
| 0.27 GB | `06_CORETRUST/syslog_after_reboot.log` |
| 0.08 GB | `06_CORETRUST/ctcanary/syslog_plat.log` |
| 0.08 GB | `06_CORETRUST/rc115/root272_clean_fs.txt` |
| 0.07 GB | `05_ROOTFS_IPSW/aea26_os/os_listing.txt` |
| 0.04 GB | `01_REPORTS/pdf/gh/cg272_all_decomp.txt` |
| 0.04 GB | `02_KERNEL/amfi_syslog.log` |
| 0.04 GB | `04_SURFACE_GPU/html_table/stubs.txt` |
| 0.03 GB | `03_SANDBOX/svc_map/fs_sizes.json` |
| 0.03 GB | `06_CORETRUST/syslog_research_amfid.log` |
| 0.03 GB | `06_CORETRUST/ctlab/bypass/artifacts/syslog_prof2.log` |

## Notes
- No other participant folder in the Holy Vibecode repository was modified.
- Signing credentials, provisioning profiles, private keys, signed IPAs and the device UDID are not included.
- Large artifacts can be regenerated/downloaded from Apple or stored externally.
