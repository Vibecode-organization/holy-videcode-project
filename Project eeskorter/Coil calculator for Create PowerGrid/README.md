# Coil calculator for Create PowerGrid

Production web calculator for computing optimal primary ($N_1$) and secondary ($N_2$) transformer winding turns in the **Create: Power Grid** Minecraft mod within the shared core turns limit ($N_1 + N_2 \le 60$).

## Features
- Exact integer solver respecting the shared core turns budget ($N_1 + N_2 \le \text{Max Turns}$).
- Interactive terminal wiring diagram for copper connectors.
- Top-6 alternative winding combinations sorted by minimum voltage deviation.
- URL query state persistence (`?in=1406.59&out=258&max=60&lang=en`) with one-click shareable link copy.
- Bilingual UI (`EN` / `RU`), zero dependencies, ready for static hosting (GitHub Pages, Cloudflare Pages, Nginx).

## Deployment
Serve the directory with any static web server or open `index.html` directly.
