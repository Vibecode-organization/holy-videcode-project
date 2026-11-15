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

## Try to use

**Live Demo:** [Coil calculator for Create PowerGrid](https://murk-sus.github.io/holy-videcode-project/Project%20eeskorter/Coil%20calculator%20for%20Create%20PowerGrid)

### User Guide

#### 1. Transformer Mechanics in Create: Power Grid
1. **Shared Core Turns Budget:** The maximum turn limit (**60**) applies to the **entire transformer core combined** ($N_1 + N_2 \le 60$), not per individual coil. Setting the primary winding to 60 exhausts the core budget and locks the secondary winding at `1` with the error `Cannot put any more turns on this transformer`.
2. **Voltage Transformation Formula:** Output voltage is determined by the winding ratio:
   $$V_{\text{out}} = V_{\text{in}} \times \frac{N_2}{N_1}$$
3. **Measuring Voltages Above 2000 V:** The **Voltage Gauge** dial caps at **2000 V**. To read exact high-voltage values:
   - Equip **Engineer's Goggles** and look directly at a terminal, or attach a **Display Link** to a Display Board.
   - Alternatively, connect an auxiliary **10 : 1** step-down measurement transformer (e.g., **50 turns** primary, **5 turns** secondary) in parallel and multiply the gauge reading by 10.
   - If the gauge displays a **negative value** (e.g., `-207.69 V`), swap the two wires connected to its terminals.

#### 2. Calculating Winding Turns
1. **Enter Input Voltage (`INPUT VOLTAGE`):** Type or slide to your measured line voltage (e.g., `2076.9` or `1406.59`).
2. **Enter Target Voltage (`TARGET OUTPUT VOLTAGE`):** Set the desired output voltage (e.g., `258`).
3. **Verify Core Budget (`MAX CORE TURNS BUDGET`):** Keep at `60` for standard Create: Power Grid transformers.
4. **Read the Result:**
   - **PRIMARY COIL ($N_1$)** shows the turn count for the input winding.
   - **SECONDARY COIL ($N_2$)** shows the turn count for the output winding along with the actual resulting voltage.
   - Click any row in **TOP ALTERNATIVE WINDING PAIRS** to preview alternative ratios and update the wiring diagram.
5. **Share Configuration:** Click **COPY LINK** to copy a direct URL containing your exact parameters (`?in=...&out=...&max=60&lang=en`).

#### 3. Wiring the Transformer In-Game
1. **Disconnect All Wires First:** Create: Power Grid blocks turn adjustments while wires are attached or current is flowing through the coils. Remove all copper wires from the top terminals before configuring.
2. **Set $N_1$ and $N_2$ Values:** Look at the **Turns (`N`)** slot on the first coil, hold **Right-Click**, drag the mouse right to set **$N_1$** (e.g., `48`), and release. Repeat on the second coil to set **$N_2$** (e.g., `6`).
3. **Connect Input & Output Terminals:** The transformer has 4 copper terminals on top—one pair above each coil. Connect your input line to the pair of terminals on the **$N_1$** side, and your output load to the pair on the **$N_2$** side. Never bridge the two terminals of the same pair together.
