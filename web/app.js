/* Holy VibeCode — статический сайт для GitHub Pages.
   Данные берутся из GitHub API; реквизиты хранятся в папке support/<login>.json. */
(function () {
  'use strict';

  const OWNER = 'murk-sus';
  const REPO = 'holy-videcode-project';
  const API = 'https://api.github.com';
  const SITE_DIRS = new Set(['web', 'support', '.github']);
  const CACHE_KEY = 'hv-cache-v1';
  const TOKEN_KEY = 'hv-token';
  const LIMITS = { name: 50, message: 300, label: 40, value: 200, methods: 15 };

  const TRON_RE = /^T[1-9A-HJ-NP-Za-km-z]{33}$/;
  const CARD_RE = /^\d[\d ]{14,21}\d$/;
  const METHODS = {
    trc20:   { label: 'USDT TRC-20', short: 'USDT', color: '#26a17b', re: TRON_RE, hint: 'Адрес в сети TRON, начинается с T', ph: 'T...' },
    tron:    { label: 'TRX (Tron)', short: 'TRX', color: '#eb0029', re: TRON_RE, hint: 'Адрес TRON, начинается с T', ph: 'T...' },
    monobank:{ label: 'Monobank', short: 'mono', color: '#1c1c1c', re: /^(\d[\d ]{14,21}\d|https:\/\/send\.monobank\.ua\/\S+)$/, hint: 'Номер карты или ссылка на банку send.monobank.ua', ph: '4441 1111 ... или https://send.monobank.ua/jar/...' },
    tbank:   { label: 'Т-Банк', short: 'Т', color: '#ffdd2d', fg: '#222', re: /^(\d[\d ]{14,21}\d|\+?\d[\d ()-]{9,17}\d|https:\/\/\S+)$/, hint: 'Номер карты, телефон (СБП) или ссылка', ph: '2200 ... или +7 ...' },
    ton:     { label: 'TON', short: 'TON', color: '#0098ea', re: /^[A-Za-z0-9_-]{48}$/, hint: 'Адрес TON (48 символов)', ph: 'UQ...' },
    btc:     { label: 'Bitcoin', short: 'BTC', color: '#f7931a', re: /^(bc1[a-z0-9]{25,62}|[13][a-km-zA-HJ-NP-Z1-9]{25,34})$/, hint: 'Адрес Bitcoin', ph: 'bc1...' },
    eth:     { label: 'ETH / ERC-20', short: 'ETH', color: '#627eea', re: /^0x[a-fA-F0-9]{40}$/, hint: 'Адрес Ethereum, начинается с 0x', ph: '0x...' },
    paypal:  { label: 'PayPal', short: 'PP', color: '#003087', re: /^(https:\/\/(www\.)?paypal\.(me|com)\/\S+|[^@\s]+@[^@\s]+\.[^@\s]+)$/, hint: 'Ссылка paypal.me или e-mail', ph: 'https://paypal.me/...' },
    boosty:  { label: 'Boosty', short: 'Boosty', color: '#f15f2c', re: /^https:\/\/boosty\.to\/\S+$/, hint: 'Ссылка https://boosty.to/...', ph: 'https://boosty.to/...' },
    kofi:    { label: 'Ko-fi', short: 'Ko-fi', color: '#29abe0', re: /^https:\/\/ko-fi\.com\/\S+$/, hint: 'Ссылка https://ko-fi.com/...', ph: 'https://ko-fi.com/...' },
    custom:  { label: 'Свой способ', short: '★', color: '#b06cff', re: null, hint: 'Любые реквизиты: название и значение', ph: 'Реквизиты или ссылка' }
  };

  const $ = (s, r = document) => r.querySelector(s);
  const $$ = (s, r = document) => Array.from(r.querySelectorAll(s));
  const reduceMotion = matchMedia('(prefers-reduced-motion: reduce)').matches;

  /* Безопасное создание DOM: весь пользовательский текст идёт через textContent */
  function el(tag, attrs = {}, ...kids) {
    const n = document.createElement(tag);
    for (const [k, v] of Object.entries(attrs)) {
      if (v == null || v === false) continue;
      if (k === 'class') n.className = v;
      else if (k === 'text') n.textContent = v;
      else if (k.startsWith('on')) n.addEventListener(k.slice(2), v);
      else n.setAttribute(k, v);
    }
    for (const kid of kids.flat()) if (kid != null) n.append(kid);
    return n;
  }
  const safeUrl = (v) => { try { const u = new URL(v); return /^https?:$/.test(u.protocol) ? u.href : null; } catch { return null; } };
  const clean = (v, max) => String(v ?? '').replace(/[\u0000-\u001f\u007f]/g, ' ').trim().slice(0, max);

  /* ---------- Тосты и искры ---------- */
  let toastTimer;
  function toast(text) {
    const t = $('#toast');
    t.textContent = text;
    t.classList.add('show');
    clearTimeout(toastTimer);
    toastTimer = setTimeout(() => t.classList.remove('show'), 2600);
  }
  function burst(x, y, n = 12) {
    if (reduceMotion) return;
    for (let i = 0; i < n; i++) {
      const a = (Math.PI * 2 * i) / n + Math.random() * .4;
      const d = 50 + Math.random() * 60;
      const s = el('span', { class: 'burst' });
      s.style.left = x + 'px'; s.style.top = y + 'px';
      s.style.setProperty('--dx', Math.cos(a) * d + 'px');
      s.style.setProperty('--dy', Math.sin(a) * d + 'px');
      s.style.background = ['#ffd34d', '#ff5fa8', '#b9a8ff', '#7fe3c8'][i % 4];
      document.body.append(s);
      setTimeout(() => s.remove(), 950);
    }
  }
  async function copy(text, e) {
    try { await navigator.clipboard.writeText(text); toast('Скопировано!'); }
    catch { toast('Не удалось скопировать'); }
    if (e) burst(e.clientX, e.clientY, 8);
  }

  /* ---------- Фон: звёздочки и сакура ---------- */
  function decorate() {
    if (reduceMotion) return;
    const sp = $('#sparkles');
    for (let i = 0; i < 28; i++) {
      const s = el('span', { class: 'sparkle' });
      s.style.left = Math.random() * 100 + '%';
      s.style.top = Math.random() * 100 + '%';
      s.style.animationDelay = (Math.random() * 4).toFixed(2) + 's';
      const size = 8 + Math.random() * 14;
      s.style.width = s.style.height = size + 'px';
      sp.append(s);
    }
    const pe = $('#petals');
    for (let i = 0; i < 16; i++) {
      const p = el('span', { class: 'petal' });
      p.style.left = Math.random() * 110 + '%';
      p.style.animationDuration = (9 + Math.random() * 10).toFixed(1) + 's';
      p.style.animationDelay = (-Math.random() * 18).toFixed(1) + 's';
      const sc = .6 + Math.random() * .9;
      p.style.width = 14 * sc + 'px'; p.style.height = 10 * sc + 'px';
      pe.append(p);
    }
    // заголовок волной
    const t = $('#heroTitle');
    const text = t.textContent;
    t.textContent = '';
    t.setAttribute('aria-label', text);
    let i = 0;
    text.split(' ').forEach((word, wi) => {
      if (wi) t.append(' ');
      const w = el('span', { class: 'word', 'aria-hidden': 'true' });
      [...word].forEach((ch) => {
        const s = el('span', { class: 'ch', text: ch });
        s.style.animationDelay = (i++) * 0.08 + 's';
        w.append(s);
      });
      t.append(w);
    });
  }

  /* ---------- Девочки ---------- */
  const PHRASES = [
    'Добро пожаловать, вайбкодер!',
    'Покажи свой проект миру ★',
    'Любая платформа подходит!',
    'Не бойся начать с Hello, World!',
    'Поддержи авторов во вкладке «Поддержка» ♥',
    'Вайбкодинг — это магия ✧',
    'Кто-то сейчас пишет промпт мечты…'
  ];
  function setupGirls() {
    const hero = $('#heroGirl');
    hero.innerHTML = window.girl();
    $('#supportGirl').innerHTML = window.girl({ hair: '#8ee8d0', hairDark: '#3fb59a', eye: '#ff5fa8', eyeLight: '#ffd1ea', jacket: '#ffb36b', jacketDark: '#e88a3c', phones: '#b9a8ff' });
    $('#footGirl').innerHTML = window.girl({ hair: '#c3b2ff', hairDark: '#7d63e0', eye: '#1fa58a', eyeLight: '#c8fff0', jacket: '#ff7ab8', jacketDark: '#d6508f' });

    let pi = 0;
    hero.addEventListener('click', (e) => {
      pi = (pi + 1) % PHRASES.length;
      const b = $('#bubble');
      b.textContent = PHRASES[pi];
      b.style.animation = 'none'; void b.offsetWidth; b.style.animation = '';
      hero.classList.remove('happy'); void hero.offsetWidth; hero.classList.add('happy');
      burst(e.clientX, e.clientY, 14);
    });

    // зрачки следят за курсором
    if (!reduceMotion) {
      let raf = 0;
      window.addEventListener('pointermove', (e) => {
        if (raf) return;
        raf = requestAnimationFrame(() => {
          raf = 0;
          $$('.girl').forEach((svg) => {
            const r = svg.getBoundingClientRect();
            if (!r.width) return;
            const cx = r.left + r.width / 2, cy = r.top + r.height * .42;
            const dx = e.clientX - cx, dy = e.clientY - cy;
            const len = Math.hypot(dx, dy) || 1;
            const k = Math.min(1, len / 300);
            const tx = (dx / len) * 5 * k, ty = (dy / len) * 4 * k;
            svg.querySelectorAll('.g-iris').forEach((g) => { g.style.transform = `translate(${tx}px, ${ty}px)`; });
          });
        });
      });
    }
  }

  /* ---------- Роутинг по вкладкам ---------- */
  const ROUTES = ['home', 'projects', 'support', 'join'];
  function movePill() {
    const a = $('#nav a.active');
    const pill = $('#navPill');
    if (!a) return;
    pill.style.width = a.offsetWidth + 'px';
    pill.style.transform = `translateX(${a.offsetLeft}px)`;
  }
  function route() {
    const r = ROUTES.includes(location.hash.slice(1)) ? location.hash.slice(1) : 'home';
    $$('.page').forEach((p) => p.classList.toggle('active', p.dataset.page === r));
    $$('#nav a').forEach((a) => a.classList.toggle('active', a.dataset.route === r));
    movePill();
    window.scrollTo({ top: 0, behavior: reduceMotion ? 'auto' : 'smooth' });
    observeReveal();
  }
  let io;
  function observeReveal() {
    if (!('IntersectionObserver' in window)) { $$('.reveal').forEach((n) => n.classList.add('in')); return; }
    io = io || new IntersectionObserver((entries) => {
      entries.forEach((en) => {
        if (en.isIntersecting) {
          const idx = Number(en.target.dataset.i || 0);
          en.target.style.transitionDelay = Math.min(idx, 8) * 70 + 'ms';
          en.target.classList.add('in');
          io.unobserve(en.target);
        }
      });
    }, { threshold: .12 });
    $$('.page.active .reveal:not(.in)').forEach((n, i) => { n.dataset.i = i; io.observe(n); });
  }

  /* ---------- GitHub API ---------- */
  async function api(path, { token, method = 'GET', body } = {}) {
    const headers = { Accept: 'application/vnd.github+json', 'X-GitHub-Api-Version': '2022-11-28' };
    if (token) headers.Authorization = 'Bearer ' + token;
    if (body) headers['Content-Type'] = 'application/json';
    const res = await fetch(API + path, { method, headers, body: body ? JSON.stringify(body) : undefined, cache: 'no-store' });
    if (!res.ok) {
      let msg = '';
      try { msg = (await res.json()).message || ''; } catch { /* ignore */ }
      const err = new Error(msg || res.statusText);
      err.status = res.status;
      err.rateLimited = res.status === 403 && res.headers.get('x-ratelimit-remaining') === '0';
      throw err;
    }
    return res.status === 204 ? null : res.json();
  }
  const b64encode = (str) => { const bytes = new TextEncoder().encode(str); let bin = ''; bytes.forEach((b) => { bin += String.fromCharCode(b); }); return btoa(bin); };
  const b64decode = (b64) => new TextDecoder().decode(Uint8Array.from(atob(b64.replace(/\s/g, '')), (c) => c.charCodeAt(0)));

  async function loadRepo(force) {
    if (!force) {
      try {
        const c = JSON.parse(sessionStorage.getItem(CACHE_KEY) || 'null');
        if (c && Date.now() - c.t < 5 * 60 * 1000) return c;
      } catch { /* ignore */ }
    }
    const token = getToken();
    const repo = await api(`/repos/${OWNER}/${REPO}`, { token });
    const branch = repo.default_branch;
    const tree = await api(`/repos/${OWNER}/${REPO}/git/trees/${encodeURIComponent(branch)}?recursive=1`, { token });
    const data = { t: Date.now(), branch, paths: tree.tree.map((x) => ({ p: x.path, d: x.type === 'tree' })) };
    try { sessionStorage.setItem(CACHE_KEY, JSON.stringify(data)); } catch { /* ignore */ }
    return data;
  }

  /* ---------- Проекты ---------- */
  function buildProjects(data) {
    const dirs = new Set(data.paths.filter((x) => x.d).map((x) => x.p));
    const files = new Set(data.paths.filter((x) => !x.d).map((x) => x.p));
    const authors = [...dirs].filter((p) => !p.includes('/') && !SITE_DIRS.has(p) && !p.startsWith('.'));
    return authors.sort((a, b) => a.localeCompare(b)).map((a) => {
      const subs = [...dirs].filter((p) => p.startsWith(a + '/') && p.split('/').length === 2);
      const list = (subs.length ? subs : [a]).map((p) => ({
        name: p.split('/').pop(),
        path: p,
        demo: files.has(p + '/index.html')
      }));
      return { author: a, projects: list };
    });
  }
  function avatarFor(name) {
    const fallback = el('div', { class: 'avatar', text: (name[0] || '?').toUpperCase() });
    if (!/^[A-Za-z0-9-]{1,39}$/.test(name)) return fallback;
    const img = el('img', { class: 'avatar', src: `https://github.com/${name}.png?size=104`, alt: '', loading: 'lazy' });
    img.addEventListener('error', () => img.replaceWith(fallback));
    return img;
  }
  const encPath = (p) => p.split('/').map(encodeURIComponent).join('/');

  function renderProjects(data) {
    const grid = $('#projectsGrid');
    grid.textContent = '';
    const authors = buildProjects(data);
    $('#statAuthors').textContent = authors.length;
    $('#statProjects').textContent = authors.reduce((n, a) => n + a.projects.length, 0);
    if (!authors.length) { grid.append(el('div', { class: 'card empty', text: 'Проектов пока нет — стань первым!' })); return; }
    authors.forEach((a) => {
      const card = el('article', { class: 'card reveal' },
        el('div', { class: 'author' }, avatarFor(a.author),
          el('div', {}, el('b', { text: a.author }), el('span', { class: 'muted', text: a.projects.length + ' ' + plural(a.projects.length, ['проект', 'проекта', 'проектов']) })))
      );
      a.projects.forEach((p) => {
        const gh = `https://github.com/${OWNER}/${REPO}/tree/${encPath(data.branch)}/${encPath(p.path)}`;
        card.append(el('div', { class: 'proj' },
          el('span', { class: 'proj-name', text: p.name }),
          el('span', { class: 'proj-actions' },
            p.demo ? el('a', { class: 'btn btn-small btn-pink', href: encPath(p.path) + '/', target: '_blank', rel: 'noopener', text: 'Демо' }) : null,
            el('a', { class: 'btn btn-small btn-ghost', href: gh, target: '_blank', rel: 'noopener', text: 'Код' }))
        ));
      });
      grid.append(card);
    });
    observeReveal();
  }
  function plural(n, f) { const m10 = n % 10, m100 = n % 100; return f[m10 === 1 && m100 !== 11 ? 0 : m10 >= 2 && m10 <= 4 && (m100 < 10 || m100 >= 20) ? 1 : 2]; }

  /* ---------- Поддержка: чтение ---------- */
  let supporters = new Map();

  function sanitizeEntry(raw, login) {
    if (!raw || typeof raw !== 'object') return null;
    if (String(raw.login || '').toLowerCase() !== login.toLowerCase()) return null;
    const methods = (Array.isArray(raw.methods) ? raw.methods : []).slice(0, LIMITS.methods).map((m) => {
      const type = METHODS[m?.type] ? m.type : 'custom';
      const label = type === 'custom' ? clean(m.label, LIMITS.label) || 'Другое' : METHODS[type].label;
      const value = clean(m?.value, LIMITS.value);
      return value ? { type, label, value } : null;
    }).filter(Boolean);
    return { login, name: clean(raw.name, LIMITS.name), message: clean(raw.message, LIMITS.message), methods, updated: clean(raw.updated, 40) };
  }

  async function fetchSupportFile(file, branch) {
    const urls = [`support/${file}`, `https://raw.githubusercontent.com/${OWNER}/${REPO}/${encPath(branch)}/support/${file}`];
    for (const u of urls) {
      try {
        const r = await fetch(u, { cache: 'no-cache' });
        if (r.ok) return await r.json();
      } catch { /* try next */ }
    }
    return null;
  }

  async function loadSupporters(data) {
    const files = data.paths.filter((x) => !x.d && /^support\/[A-Za-z0-9-]{1,39}\.json$/.test(x.p)).map((x) => x.p.slice(8));
    const entries = await Promise.all(files.map(async (f) => sanitizeEntry(await fetchSupportFile(f, data.branch), f.slice(0, -5))));
    supporters = new Map(entries.filter(Boolean).map((e) => [e.login.toLowerCase(), e]));
    renderSupport();
  }

  function renderSupport() {
    const grid = $('#supportGrid');
    grid.textContent = '';
    const list = [...supporters.values()].filter((e) => e.methods.length).sort((a, b) => a.login.localeCompare(b.login));
    $('#statSupport').textContent = list.length;
    if (!list.length) {
      grid.append(el('div', { class: 'card empty' },
        el('h3', { text: 'Пока никто не добавил реквизиты' }),
        el('p', { class: 'muted', text: 'Участники репозитория могут добавить свои — кнопка выше.' })));
      return;
    }
    list.forEach((e) => {
      const card = el('article', { class: 'card reveal' },
        el('div', { class: 'author' }, avatarFor(e.login),
          el('div', {}, el('b', { text: e.name || e.login }),
            el('a', { class: 'muted', href: `https://github.com/${e.login}`, target: '_blank', rel: 'noopener', text: '@' + e.login }))),
        e.message ? el('p', { class: 'quote', text: '«' + e.message + '»' }) : null
      );
      e.methods.forEach((m) => {
        const meta = METHODS[m.type];
        const tag = el('span', { class: 'mtag', text: meta.short });
        tag.style.background = meta.color; if (meta.fg) tag.style.color = meta.fg;
        const url = safeUrl(m.value);
        card.append(el('div', { class: 'method' }, tag,
          el('div', { class: 'mbody' },
            el('div', { class: 'mlabel', text: m.label }),
            url ? el('a', { class: 'mvalue', href: url, target: '_blank', rel: 'noopener nofollow', text: m.value })
                : el('div', { class: 'mvalue', text: m.value })),
          el('button', { class: 'copy', type: 'button', text: 'Копировать', onclick: (ev) => copy(m.value, ev) })));
      });
      grid.append(card);
    });
    observeReveal();
  }

  /* ---------- Поддержка: вход и редактирование ---------- */
  const state = { token: null, user: null, branch: null, sha: null };
  function getToken() { try { return sessionStorage.getItem(TOKEN_KEY); } catch { return null; } }
  function setToken(t) { try { t ? sessionStorage.setItem(TOKEN_KEY, t) : sessionStorage.removeItem(TOKEN_KEY); } catch { /* ignore */ } }
  function setMsg(node, text, kind) { node.textContent = text || ''; node.className = 'msg' + (kind ? ' ' + kind : ''); }

  function openEditor() {
    $('#editor').hidden = false;
    $('#editor').scrollIntoView({ behavior: reduceMotion ? 'auto' : 'smooth', block: 'start' });
    const t = getToken();
    if (t && !state.user) login(t, true);
  }
  function closeEditor() { $('#editor').hidden = true; }

  async function login(token, silent) {
    const msg = $('#loginMsg');
    setMsg(msg, 'Проверяю…');
    try {
      const user = await api('/user', { token });
      const repo = await api(`/repos/${OWNER}/${REPO}`, { token });
      if (!repo.permissions || !repo.permissions.push) {
        setToken(null);
        setMsg(msg, `@${user.login}, у вас нет прав на изменение репозитория. Добавлять реквизиты могут только участники — напишите владельцу.`, 'err');
        return;
      }
      Object.assign(state, { token, user, branch: repo.default_branch, sha: null });
      setToken(token);
      setMsg(msg, '');
      await showForm();
    } catch (e) {
      if (!silent || e.status !== 401) setMsg(msg, e.status === 401 ? 'Токен не подошёл. Проверьте, что скопировали его полностью.' : 'Ошибка: ' + e.message, 'err');
      else setMsg(msg, '');
      if (e.status === 401) setToken(null);
    }
  }

  function logout() {
    setToken(null);
    Object.assign(state, { token: null, user: null, sha: null });
    $('#stepForm').hidden = true;
    $('#stepLogin').hidden = false;
    $('#tokenInput').value = '';
  }

  async function showForm() {
    const u = state.user;
    $('#stepLogin').hidden = true;
    $('#stepForm').hidden = false;
    $('#whoAvatar').src = u.avatar_url;
    $('#whoLogin').textContent = '@' + u.login;
    $('#methodRows').textContent = '';
    setMsg($('#formMsg'), 'Загружаю ваши реквизиты…');

    let existing = null, loadError = false;
    try {
      const f = await api(`/repos/${OWNER}/${REPO}/contents/support/${u.login}.json?ref=${encodeURIComponent(state.branch)}`, { token: state.token });
      state.sha = f.sha;
      existing = sanitizeEntry(JSON.parse(b64decode(f.content)), u.login);
    } catch (e) {
      if (e.status !== 404) { loadError = true; setMsg($('#formMsg'), 'Не удалось загрузить: ' + e.message, 'err'); }
      state.sha = null;
    }
    $('#fName').value = existing ? existing.name : clean(u.name || '', LIMITS.name);
    $('#fMessage').value = existing ? existing.message : '';
    (existing ? existing.methods : []).forEach((m) => addRow(m.type, m));
    $('#deleteBtn').hidden = !state.sha;
    if (!loadError) setMsg($('#formMsg'), '');
  }

  function renderChips() {
    const box = $('#methodChips');
    Object.entries(METHODS).forEach(([type, m]) => {
      box.append(el('button', { class: 'chip', type: 'button', text: '+ ' + m.label, onclick: (e) => { addRow(type); burst(e.clientX, e.clientY, 6); } }));
    });
  }

  function addRow(type, data = {}) {
    const rows = $('#methodRows');
    if (rows.children.length >= LIMITS.methods) { toast(`Максимум ${LIMITS.methods} способов`); return; }
    const meta = METHODS[type];
    const tag = el('span', { class: 'mtag', text: meta.short });
    tag.style.background = meta.color; if (meta.fg) tag.style.color = meta.fg;
    const labelInput = type === 'custom' ? el('input', { class: 'f-label', maxlength: LIMITS.label, placeholder: 'Название (например: Сбер, QIWI, DonationAlerts)' }) : null;
    if (labelInput) labelInput.value = data.label || '';
    const valueInput = el('input', { class: 'f-value', maxlength: LIMITS.value, placeholder: meta.ph, spellcheck: 'false', autocomplete: 'off' });
    valueInput.value = data.value || '';
    const hint = el('div', { class: 'hint', text: meta.hint });
    const row = el('div', { class: 'mrow', 'data-type': type },
      tag,
      el('div', { class: 'fields' }, type === 'custom' ? null : el('b', { text: meta.label }), labelInput, valueInput, hint),
      el('button', { class: 'remove', type: 'button', 'aria-label': 'Удалить', text: '×', onclick: () => { row.classList.add('out'); setTimeout(() => row.remove(), 280); } })
    );
    valueInput.addEventListener('input', () => validateRow(row));
    rows.append(row);
    if (!data.value) valueInput.focus();
  }

  function validateRow(row) {
    const type = row.dataset.type;
    const meta = METHODS[type];
    const value = clean($('.f-value', row).value, LIMITS.value);
    const label = type === 'custom' ? clean($('.f-label', row).value, LIMITS.label) : meta.label;
    const hint = $('.hint', row);
    let error = '';
    if (!value) error = '';
    else if (type === 'custom' && !label) error = 'Укажите название способа';
    else if (meta.re && !meta.re.test(value)) error = 'Похоже на ошибку: ' + meta.hint;
    hint.textContent = error || meta.hint;
    hint.classList.toggle('bad', !!error);
    return { ok: !error, entry: value ? { type, label, value } : null };
  }

  async function save(e) {
    e.preventDefault();
    const msg = $('#formMsg');
    const results = $$('#methodRows .mrow:not(.out)').map(validateRow);
    if (results.some((r) => !r.ok)) { setMsg(msg, 'Исправьте поля, отмеченные красным.', 'err'); return; }
    const methods = results.map((r) => r.entry).filter(Boolean);
    if (!methods.length) { setMsg(msg, 'Добавьте хотя бы один способ оплаты.', 'err'); return; }
    const entry = {
      version: 1,
      login: state.user.login,
      name: clean($('#fName').value, LIMITS.name),
      message: clean($('#fMessage').value, LIMITS.message),
      methods,
      updated: new Date().toISOString()
    };
    const btn = e.submitter || $('#supportForm button[type=submit]');
    btn.disabled = true;
    setMsg(msg, 'Сохраняю…');
    try {
      const res = await api(`/repos/${OWNER}/${REPO}/contents/support/${state.user.login}.json`, {
        token: state.token, method: 'PUT',
        body: {
          message: `support: реквизиты @${state.user.login}`,
          content: b64encode(JSON.stringify(entry, null, 2) + '\n'),
          branch: state.branch,
          ...(state.sha ? { sha: state.sha } : {})
        }
      });
      state.sha = res.content.sha;
      $('#deleteBtn').hidden = false;
      supporters.set(entry.login.toLowerCase(), sanitizeEntry(entry, entry.login));
      sessionStorage.removeItem(CACHE_KEY);
      renderSupport();
      setMsg(msg, 'Сохранено! На сайте для всех обновится примерно через минуту.', 'ok');
      const r = btn.getBoundingClientRect(); burst(r.left + r.width / 2, r.top, 18);
    } catch (err) {
      setMsg(msg, err.status === 409 ? 'Файл изменился, обновите страницу и попробуйте снова.' : 'Ошибка сохранения: ' + err.message, 'err');
    } finally { btn.disabled = false; }
  }

  async function remove() {
    if (!state.sha || !confirm('Удалить ваши реквизиты с сайта?')) return;
    const msg = $('#formMsg');
    setMsg(msg, 'Удаляю…');
    try {
      await api(`/repos/${OWNER}/${REPO}/contents/support/${state.user.login}.json`, {
        token: state.token, method: 'DELETE',
        body: { message: `support: удалил реквизиты @${state.user.login}`, sha: state.sha, branch: state.branch }
      });
      state.sha = null;
      supporters.delete(state.user.login.toLowerCase());
      sessionStorage.removeItem(CACHE_KEY);
      renderSupport();
      $('#methodRows').textContent = '';
      $('#deleteBtn').hidden = true;
      setMsg(msg, 'Реквизиты удалены.', 'ok');
    } catch (err) { setMsg(msg, 'Ошибка удаления: ' + err.message, 'err'); }
  }

  /* ---------- Старт ---------- */
  async function init() {
    decorate();
    setupGirls();
    renderChips();
    route();
    window.addEventListener('hashchange', route);
    window.addEventListener('resize', movePill);
    document.fonts && document.fonts.ready.then(movePill);

    $('#openEditor').addEventListener('click', openEditor);
    $('#closeEditor').addEventListener('click', closeEditor);
    $('#loginForm').addEventListener('submit', (e) => { e.preventDefault(); const t = $('#tokenInput').value.trim(); if (t) login(t); });
    $('#logout').addEventListener('click', logout);
    $('#supportForm').addEventListener('submit', save);
    $('#deleteBtn').addEventListener('click', remove);

    try {
      const data = await loadRepo();
      renderProjects(data);
      await loadSupporters(data);
    } catch (e) {
      const text = e.rateLimited ? 'GitHub временно ограничил запросы. Попробуйте через несколько минут.' : 'Не удалось загрузить данные с GitHub.';
      ['#projectsGrid', '#supportGrid'].forEach((s) => { const g = $(s); g.textContent = ''; g.append(el('div', { class: 'card empty', text })); });
    }
  }

  document.addEventListener('DOMContentLoaded', init);
})();
