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
      tableTitle: 'TOP ALTERNATIVE WINDING PAIRS (CLICK TO PREVIEW)',
      thN1: 'N₁ (INPUT)',
      thN2: 'N₂ (OUTPUT)',
      thSum: 'TOTAL',
      thOut: 'ACTUAL OUTPUT',
      thErr: 'ERROR',
      svgTop: (n1, vIn) => `INPUT TERMINALS (N₁ = ${n1}) — APPLY ${vIn} V`,
      svgBot: (n2, vOut) => `OUTPUT TERMINALS (N₂ = ${n2}) — READ ${vOut} V`
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
      tableTitle: 'АЛЬТЕРНАТИВНЫЕ КОМБИНАЦИИ (КЛИК ДЛЯ ПРЕДПРОСМОТРА)',
      thN1: 'N₁ (ВХОД)',
      thN2: 'N₂ (ВЫХОД)',
      thSum: 'СУММА',
      thOut: 'ВЫХОД (ФАКТ)',
      thErr: 'ПОГРЕШНОСТЬ',
      svgTop: (n1, vIn) => `КЛЕММЫ ВХОДА (N₁ = ${n1}) — ПОДАТЬ ${vIn} V`,
      svgBot: (n2, vOut) => `КЛЕММЫ ВЫХОДА (N₂ = ${n2}) — СНЯТЬ ${vOut} V`
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
    altBody: document.getElementById('altBody'),
    swapBtn: document.getElementById('swapBtn'),
    copyBtn: document.getElementById('copyBtn'),
    langBtn: document.getElementById('langBtn')
  };

  function clamp(val, min, max) {
    return Math.min(max, Math.max(min, val));
  }

  function findBestPairs(vIn, vOut, maxTotal) {
    const candidates = [];

    for (let n1 = 1; n1 < maxTotal; n1++) {
      for (let n2 = 1; n1 + n2 <= maxTotal; n2++) {
        const actualOut = vIn * (n2 / n1);
        const diff = actualOut - vOut;
        const absDiff = Math.abs(diff);
        const relError = (absDiff / vOut) * 100;

        candidates.push({
          n1,
          n2,
          sum: n1 + n2,
          actualOut,
          diff,
          absDiff,
          relError
        });
      }
    }

    candidates.sort((a, b) => {
      if (Math.abs(a.absDiff - b.absDiff) > 1e-6) {
        return a.absDiff - b.absDiff;
      }
      return b.sum - a.sum;
    });

    return candidates;
  }

  function applyTranslations() {
    const t = I18N[lang];
    document.documentElement.lang = lang;
    el.langBtn.textContent = lang === 'en' ? 'RU' : 'EN';
    document.querySelectorAll('[data-i18n]').forEach((node) => {
      const key = node.dataset.i18n;
      if (t[key]) node.textContent = t[key];
    });
  }

  function syncUrlState(vIn, vOut, maxTotal) {
    const url = new URL(window.location.href);
    url.searchParams.set('in', vIn);
    url.searchParams.set('out', vOut);
    url.searchParams.set('max', maxTotal);
    url.searchParams.set('lang', lang);
    window.history.replaceState(null, '', url.toString());
  }

  function loadUrlState() {
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
  }

  function render(selectedPair = null) {
    const t = I18N[lang];
    const vIn = clamp(parseFloat(el.vInInput.value) || 0.01, 0.01, 1000000);
    const vOut = clamp(parseFloat(el.vOutInput.value) || 0.01, 0.01, 1000000);
    const maxTotal = clamp(parseInt(el.maxTurnsInput.value, 10) || 60, 2, 500);

    const pairs = findBestPairs(vIn, vOut, maxTotal);
    const active = selectedPair || pairs[0];

    el.modeBadge.textContent = vIn >= vOut ? t.stepDown : t.stepUp;
    el.n1Val.textContent = active.n1;
    el.n2Val.textContent = active.n2;
    el.inPreview.textContent = `${vIn.toFixed(2)} V`;
    el.outActual.textContent = `${active.actualOut.toFixed(2)} V`;
    el.ratioVal.textContent = `${(active.n1 / active.n2).toFixed(2)} : 1`;

    const sign = active.diff >= 0 ? '+' : '';
    el.errorVal.textContent = `${sign}${active.diff.toFixed(2)} V (${active.relError.toFixed(2)}%)`;
    el.sumVal.textContent = `${active.sum} / ${maxTotal}`;
    el.budgetUsed.textContent = `${active.sum} / ${maxTotal}`;

    el.svgTopLabel.textContent = t.svgTop(active.n1, vIn.toFixed(2));
    el.svgBotLabel.textContent = t.svgBot(active.n2, active.actualOut.toFixed(2));

    el.altBody.innerHTML = '';
    pairs.slice(0, 6).forEach((pair) => {
      const tr = document.createElement('tr');
      if (pair.n1 === active.n1 && pair.n2 === active.n2) {
        tr.classList.add('best');
      }
      const pSign = pair.diff >= 0 ? '+' : '';
      tr.innerHTML = `
        <td>${pair.n1}</td>
        <td>${pair.n2}</td>
        <td>${pair.sum} / ${maxTotal}</td>
        <td>${pair.actualOut.toFixed(2)} V</td>
        <td>${pSign}${pair.diff.toFixed(2)} V (${pair.relError.toFixed(2)}%)</td>
      `;
      tr.addEventListener('click', () => render(pair));
      el.altBody.appendChild(tr);
    });

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
