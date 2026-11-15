(() => {
  'use strict';

  const I18N = {
    en: {
      subtitle: 'TRANSFORMER WINDING & CORE TURNS BUDGET SOLVER',
      stepDown: 'STEP-DOWN',
      stepUp: 'STEP-UP',
      vInLabel: 'INPUT VOLTAGE (V_IN)',
      vOutLabel: 'TARGET OUTPUT VOLTAGE (V_OUT)',
      maxTurnsLabel: 'MAX CORE TURNS BUDGET (N₁ + N₂)',
      swapBtn: '⇄ SWAP',
      copyBtn: 'COPY LINK',
      copiedBtn: 'COPIED ✓',
      primaryTitle: 'PRIMARY COIL (N₁)',
      secondaryTitle: 'SECONDARY COIL (N₂)',
      inPrefix: 'IN:',
      outPrefix: 'OUT:',
      ratioLabel: 'RATIO',
      deviationLabel: 'DEVIATION',
      turnsSumLabel: 'TURNS USED',
      guideToggle: 'USER GUIDE & IN-GAME WIRING INSTRUCTIONS',
      svgTop: (n1, vIn) => `INPUT TERMINALS (N₁ = ${n1}) — APPLY ${vIn} V`,
      svgBot: (n2, vOut) => `OUTPUT TERMINALS (N₂ = ${n2}) — READ ${vOut} V`,
      guideHtml: `
        <div class="guide-block">
          <h3>1. CORE BUDGET &amp; FORMULA</h3>
          <ul>
            <li><b>Shared Limit (60):</b> Max turns apply to the entire transformer combined (<code>N₁ + N₂ ≤ 60</code>). Setting 60 on one coil locks the other at <code>1</code>.</li>
            <li><b>Voltage Ratio:</b> <code>V_out = V_in × (N₂ / N₁)</code>.</li>
            <li><b>Above 2000 V:</b> Voltage Gauge caps at 2000 V. Use <b>Engineer's Goggles</b>, a <b>Display Link</b>, or a <b>10:1</b> step-down test transformer (50 &amp; 5 turns) and multiply by 10.</li>
          </ul>
        </div>
        <div class="guide-block">
          <h3>2. SETTING COIL TURNS</h3>
          <ol>
            <li><b>Disconnect all wires:</b> Turn counts cannot be changed while wires are attached or current is flowing.</li>
            <li><b>Set N₁:</b> Aim at the <code>Turns (N)</code> slot on the primary coil, hold <b>Right-Click</b>, drag right to <b>N₁</b>, and release.</li>
            <li><b>Set N₂:</b> Repeat on the second coil to set <b>N₂</b>.</li>
          </ol>
        </div>
        <div class="guide-block">
          <h3>3. WIRING TERMINALS</h3>
          <ol>
            <li><b>Top Terminals:</b> The 4 copper terminals on top are grouped in pairs — one pair directly above each coil.</li>
            <li><b>Connect Lines:</b> Wire your input source to the pair on the <b>N₁</b> side and your output load to the pair on the <b>N₂</b> side.</li>
            <li><b>Polarity:</b> Never bridge two terminals of the same pair. If a gauge shows a minus sign, swap its two wires.</li>
          </ol>
        </div>
      `
    },
    ru: {
      subtitle: 'РАСЧЁТ ВИТКОВ И БЮДЖЕТА СЕРДЕЧНИКА ТРАНСФОРМАТОРА',
      stepDown: 'ПОНИЖАЮЩИЙ',
      stepUp: 'ПОВЫШАЮЩИЙ',
      vInLabel: 'ВХОДНОЕ НАПРЯЖЕНИЕ (V_IN)',
      vOutLabel: 'ЦЕЛЕВОЕ НАПРЯЖЕНИЕ (V_OUT)',
      maxTurnsLabel: 'ЛИМИТ ВИТКОВ СЕРДЕЧНИКА (N₁ + N₂)',
      swapBtn: '⇄ ИНВЕРТ',
      copyBtn: 'ССЫЛКА',
      copiedBtn: 'СКОПИРОВАНО ✓',
      primaryTitle: 'ПЕРВИЧНАЯ (N₁)',
      secondaryTitle: 'ВТОРИЧНАЯ (N₂)',
      inPrefix: 'ВХОД:',
      outPrefix: 'ВЫХОД:',
      ratioLabel: 'КОЭФФ.',
      deviationLabel: 'ОТКЛОНЕНИЕ',
      turnsSumLabel: 'СУММА ВИТКОВ',
      guideToggle: 'ГАЙД ПО НАСТРОЙКЕ И ПОДКЛЮЧЕНИЮ В MINECRAFT',
      svgTop: (n1, vIn) => `КЛЕММЫ ВХОДА (N₁ = ${n1}) — ПОДАТЬ ${vIn} V`,
      svgBot: (n2, vOut) => `КЛЕММЫ ВЫХОДА (N₂ = ${n2}) — СНЯТЬ ${vOut} V`,
      guideHtml: `
        <div class="guide-block">
          <h3>1. ЛИМИТ СЕРДЕЧНИКА И ЗАМЕРЫ</h3>
          <ul>
            <li><b>Общий бюджет (60):</b> Лимит витков делится на обе катушки (<code>N₁ + N₂ ≤ 60</code>). Если поставить 60 на первой, вторая заблокируется на <code>1</code>.</li>
            <li><b>Формула:</b> <code>V_out = V_in × (N₂ / N₁)</code>.</li>
            <li><b>Выше 2000 V:</b> Шкала Voltage Gauge ограничена 2000 V. Используйте <b>Очки инженера</b>, <b>Display Link</b> или делитель <b>10:1</b> (50 и 5 витков) и умножьте показание на 10.</li>
          </ul>
        </div>
        <div class="guide-block">
          <h3>2. НАСТРОЙКА ВИТКОВ</h3>
          <ol>
            <li><b>Снимите провода:</b> Мод блокирует изменение витков, если к клеммам подключены провода или идёт ток.</li>
            <li><b>Выставьте N₁:</b> Наведите прицел на слот <code>Turns (N)</code> первой катушки, зажмите <b>ПКМ</b>, потяните мышь вправо до <b>N₁</b> и отпустите.</li>
            <li><b>Выставьте N₂:</b> Повторите то же самое на второй катушке для значения <b>N₂</b>.</li>
          </ol>
        </div>
        <div class="guide-block">
          <h3>3. ПОДКЛЮЧЕНИЕ КЛЕММ</h3>
          <ol>
            <li><b>4 клеммы сверху:</b> Разделены на две пары — по одной паре строго над каждой катушкой.</li>
            <li><b>Вход и выход:</b> Подайте входную линию на пару клемм со стороны <b>N₁</b>, а выходную цепь снимите с пары со стороны <b>N₂</b>.</li>
            <li><b>Полярность:</b> Не замыкайте клеммы одной пары между собой. Если прибор показывает минус — поменяйте его два провода местами.</li>
          </ol>
        </div>
      `
    }
  };

  let lang = 'en';

  const el = {
    vInInput: document.getElementById('vInInput'),
    vInRange: document.getElementById('vInRange'),
    vOutInput: document.getElementById('vOutInput'),
    vOutRange: document.getElementById('vOutRange'),
    maxTurnsInput: document.getElementById('maxTurnsInput'),
    maxTurnsRange: document.getElementById('maxTurnsRange'),
    modeBadge: document.getElementById('modeBadge'),
    budgetUsed: document.getElementById('budgetUsed'),
    n1Val: document.getElementById('n1Val'),
    n2Val: document.getElementById('n2Val'),
    inPreview: document.getElementById('inPreview'),
    outActual: document.getElementById('outActual'),
    ratioVal: document.getElementById('ratioVal'),
    errorVal: document.getElementById('errorVal'),
    sumVal: document.getElementById('sumVal'),
    svgTopLabel: document.getElementById('svgTopLabel'),
    svgBotLabel: document.getElementById('svgBotLabel'),
    guideContent: document.getElementById('guideContent'),
    swapBtn: document.getElementById('swapBtn'),
    copyBtn: document.getElementById('copyBtn'),
    langBtn: document.getElementById('langBtn')
  };

  function clamp(val, min, max) {
    return Math.min(max, Math.max(min, val));
  }

  function findBestPair(vIn, vOut, maxTotal) {
    let best = null;

    for (let n1 = 1; n1 < maxTotal; n1++) {
      for (let n2 = 1; n1 + n2 <= maxTotal; n2++) {
        const actualOut = vIn * (n2 / n1);
        const diff = actualOut - vOut;
        const absDiff = Math.abs(diff);
        const relError = (absDiff / vOut) * 100;
        const sum = n1 + n2;

        if (
          !best ||
          absDiff < best.absDiff - 1e-6 ||
          (Math.abs(absDiff - best.absDiff) <= 1e-6 && sum > best.sum)
        ) {
          best = { n1, n2, sum, actualOut, diff, absDiff, relError };
        }
      }
    }

    return best;
  }

  function applyTranslations() {
    const t = I18N[lang];
    document.documentElement.lang = lang;
    el.langBtn.textContent = lang === 'en' ? 'RU' : 'EN';
    document.querySelectorAll('[data-i18n]').forEach((node) => {
      const key = node.dataset.i18n;
      if (t[key]) node.textContent = t[key];
    });
    el.guideContent.innerHTML = t.guideHtml;
  }

  function syncUrlState(vIn, vOut, maxTotal) {
    try {
      const url = new URL(window.location.href);
      url.searchParams.set('in', vIn);
      url.searchParams.set('out', vOut);
      url.searchParams.set('max', maxTotal);
      url.searchParams.set('lang', lang);
      window.history.replaceState(null, '', url.toString());
    } catch (_) {}
  }

  function loadUrlState() {
    try {
      const params = new URLSearchParams(window.location.search);
      if (params.has('in')) {
        const v = clamp(parseFloat(params.get('in')) || 1406.59, 0.01, 1000000);
        el.vInInput.value = v;
        el.vInRange.value = clamp(Math.round(v), 10, 5000);
      }
      if (params.has('out')) {
        const v = clamp(parseFloat(params.get('out')) || 258, 0.01, 1000000);
        el.vOutInput.value = v;
        el.vOutRange.value = clamp(Math.round(v), 1, 5000);
      }
      if (params.has('max')) {
        const m = clamp(parseInt(params.get('max'), 10) || 60, 2, 500);
        el.maxTurnsInput.value = m;
        el.maxTurnsRange.value = clamp(m, 2, 120);
      }
      if (params.get('lang') === 'ru' || params.get('lang') === 'en') {
        lang = params.get('lang');
      }
    } catch (_) {}
  }

  function render() {
    const t = I18N[lang];
    const vIn = clamp(parseFloat(el.vInInput.value) || 0.01, 0.01, 1000000);
    const vOut = clamp(parseFloat(el.vOutInput.value) || 0.01, 0.01, 1000000);
    const maxTotal = clamp(parseInt(el.maxTurnsInput.value, 10) || 60, 2, 500);

    const best = findBestPair(vIn, vOut, maxTotal);

    el.modeBadge.textContent = vIn >= vOut ? t.stepDown : t.stepUp;
    el.n1Val.textContent = best.n1;
    el.n2Val.textContent = best.n2;
    el.inPreview.textContent = `${vIn.toFixed(2)} V`;
    el.outActual.textContent = `${best.actualOut.toFixed(2)} V`;
    el.ratioVal.textContent = `${(best.n1 / best.n2).toFixed(2)} : 1`;

    const sign = best.diff >= 0 ? '+' : '';
    el.errorVal.textContent = `${sign}${best.diff.toFixed(2)} V (${best.relError.toFixed(2)}%)`;
    el.sumVal.textContent = `${best.sum} / ${maxTotal}`;
    el.budgetUsed.textContent = `${best.sum} / ${maxTotal}`;

    el.svgTopLabel.textContent = t.svgTop(best.n1, vIn.toFixed(2));
    el.svgBotLabel.textContent = t.svgBot(best.n2, best.actualOut.toFixed(2));

    syncUrlState(vIn, vOut, maxTotal);
  }

  function bindPair(numEl, rangeEl) {
    numEl.addEventListener('input', () => {
      const val = parseFloat(numEl.value);
      if (!Number.isNaN(val)) {
        rangeEl.value = clamp(val, parseFloat(rangeEl.min), parseFloat(rangeEl.max));
      }
      render();
    });
    rangeEl.addEventListener('input', () => {
      numEl.value = rangeEl.value;
      render();
    });
  }

  bindPair(el.vInInput, el.vInRange);
  bindPair(el.vOutInput, el.vOutRange);
  bindPair(el.maxTurnsInput, el.maxTurnsRange);

  document.querySelectorAll('.presets button[data-in]').forEach((btn) => {
    btn.addEventListener('click', () => {
      el.vInInput.value = btn.dataset.in;
      el.vOutInput.value = btn.dataset.out;
      el.vInRange.value = clamp(Math.round(parseFloat(btn.dataset.in)), 10, 5000);
      el.vOutRange.value = clamp(Math.round(parseFloat(btn.dataset.out)), 1, 5000);
      render();
    });
  });

  el.swapBtn.addEventListener('click', () => {
    const tmp = el.vInInput.value;
    el.vInInput.value = el.vOutInput.value;
    el.vOutInput.value = tmp;
    el.vInRange.value = clamp(Math.round(parseFloat(el.vInInput.value)), 10, 5000);
    el.vOutRange.value = clamp(Math.round(parseFloat(el.vOutInput.value)), 1, 5000);
    render();
  });

  el.copyBtn.addEventListener('click', async () => {
    try {
      await navigator.clipboard.writeText(window.location.href);
      el.copyBtn.textContent = I18N[lang].copiedBtn;
      setTimeout(() => {
        el.copyBtn.textContent = I18N[lang].copyBtn;
      }, 1500);
    } catch (_) {
      window.prompt('URL:', window.location.href);
    }
  });

  el.langBtn.addEventListener('click', () => {
    lang = lang === 'en' ? 'ru' : 'en';
    applyTranslations();
    render();
  });

  loadUrlState();
  applyTranslations();
  render();
})();
