# KRWProbe 1.8 — UI layout

## Design source
The UI follows the supplied dark-slate reference: near-black blue-grey canvas
(`#1E2229`), grouped cards (`#262A33`) with 22 pt continuous corners and a hairline
border, muted grey section headers, a bright white display title, and a floating
frosted bottom dock. A faint violet radial glow and a vertical gradient add depth
without changing the reference's mostly monochrome character. Violet
(`#A78BFA`) is the accent; mint, pink, amber, blue and red are used only as
small mode/icon tints.

## Structure
- **Header (fixed):** `IOSURFACE · KERNEL PROBE` eyebrow, `KRWProbe` title,
  `v1.8` pill, circular info/credits button.
- **Middle scroll view:** grouped sections in this order:
  1. **SESSION** — animated phase label, DOCS/TMP run-folder paths, folder
     verification/error line.
  2. **SAFE** — `RUN SAFE` (full width), `CREATE`, `SCAN SEL`.
  3. **FUZZ** — `FUZZ 50k`, `MUTATE 100k`, `MUTATE 200k`, `FUZZ UC`.
  4. **KERNEL** — `AGGR`, `RACE 30s`, `HARD` (full width), `LEAK`, `F1`.
  5. **INFO** — credits tile, direct GitHub and Telegram links, version
     `1.8 (18)`, build `18`, run folder name.
- **Log (fixed above dock):** `SESSION LOG` header with live dot and COPY
  button, and a scrollable monospaced terminal card. Its height is
  `clamp(30% of safe height, 150, 300)`, so the probe output is always visible
  while the control sections scroll.
- **Dock (fixed):** frosted pill with `STOP` and `CREDITS` (GitHub + Telegram
  glyphs, `murk-sus`).

All buttons from 1.7 are present and wired to the same selectors. `STOP` lives
in the always-visible dock; the other modes are grouped as above and are
reachable by scrolling, never hidden behind a tab or menu.

## Responsive measurements
Auto Layout only: margins 16 pt, card padding 10 pt, 8 pt grid gaps, two equal
columns; no fixed x/y frames. Key computed values:

| Device width | Content | 2-col tile | Tile text | Dock segment | Log height (SE/standard) |
|---:|---:|---:|---:|---:|---:|
| 320 pt | 288 | 130 | 76 | 134 | 164 (568 pt tall) |
| 375 pt | 343 | 157.5 | 103.5 | 161.5 | 218 (812 pt tall) |
| 390 pt | 358 | 165 | 111 | 169 | 229 (844 pt tall) |
| 430 pt | 398 | 185 | 131 | 189 | 252 (932 pt tall) |
| 440 pt | 408 | 190 | 136 | 194 | 258 (956 pt tall) |

Title/button labels use `UIFontMetrics` with maximum point sizes and
`adjustsFontSizeToFitWidth`; the header title has 190 pt of width available even
at 320 pt, while the 31 pt wordmark needs about 137 pt (168 pt at the 38 pt cap).
The vertical chain is:
`header 72 + gap 8 + scroll + gap 10 + log [150…300] + gap 10 + dock 62 + safe bottom`.
The 320×568 worst case leaves 210 pt for the scroll view (positive at every
checked size), and the Pro Max case leaves 428 pt.

## Motion and effects
- Launch fade/spring-in for header, scroll content, log and dock.
- `KRWActionButton` press feedback: 0.96 scale + shadow fade + spring return,
  with Reduce Motion fallback.
- Phase label cross-fades via `CATransition` and springs up 4 pt; live dots pulse.
- Log follows the tail smoothly only when already at the bottom; scrolling up
  is not fought by the updater.
- Subtle background gradient + violet glow, frosted dock via `UIVisualEffectView`.

## Credits
- `CREDITS` dock tile and the INFO credits tile open a custom sheet with two
  large links.
- INFO also exposes direct tappable GitHub/Telegram rows.
- GitHub: `murk-sus` — https://github.com/murk-sus
- Telegram: `murk-sus` — https://t.me/@asuka4scape_developer
- Icons: GitHub drawn with Core Graphics (parsed 24×24 mark path); Telegram is
  an SF Symbol paper-plane in Telegram blue.

## Preserved behaviour
Run setup (Documents + tmp folder, five files, per-run `run.log`), phase
markers / `last_phase.txt`, `last_config.json`, `last_config.xml`,
`last_action.json`, `leak.txt`, crash-resume files, logging and every probe
entry point are unchanged. Only the presentation layer, log follower and phase
label animation were touched.

## Version and verification
- Version **1.8**, build **18**; `Info.plist` inside the IPA reports
  `CFBundleDisplayName=KRWProbe 1.8`, `CFBundleShortVersionString=1.8`,
  `CFBundleVersion=18`.
- Built with Theos for arm64; binary is a signed Mach-O arm64 PIE.
- **Layout verification: constraint math only.** This host is Linux and has no
  macOS/Xcode iOS Simulator, so no simulator run was possible. The table above
  is the computed constraint pass across 320–440 pt widths and the 4.7″–6.9″
  height range; no fixed-width or negative-space cases remain. Compile-time
  validation succeeded; runtime simulator screenshots were not produced.
