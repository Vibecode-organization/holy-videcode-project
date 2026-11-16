'use strict';

/* ------------------------------------------------------------------ */
/* state                                                               */
/* ------------------------------------------------------------------ */

const state = {
  me: {},
  csrf: '',
  origin: '',
  overview: null,
  agents: [],
  folders: [],
  keys: [],
  connections: [],
  failures: [],
  events: [],
  messages: [],
  reports: [],
  tasks: [],
  settings: null,
  view: 'overview',
  feedFilter: 'all',
  feedPaused: false,
  lastEventId: 0,
  es: null,
  snippets: null,
  token: null,
  snippetTab: 'claude',
  fs: { root: 'agent', agent: '', path: '', entries: [], selected: '' },
  refreshTimer: null
};

const VIEW_META = {
  overview:   ['OV', 'Обзор'],
  folders:    ['FS', 'Папки'],
  files:      ['FL', 'Файлы'],
  keys:       ['KEY', 'Ключи'],
  connections:['NET', 'Подключения'],
  live:       ['LIVE', 'Live'],
  reports:    ['RPT', 'Отчёты'],
  tasks:      ['TSK', 'Задачи'],
  settings:   ['SET', 'Настройки']
};

const KIND_LABEL = {
  connect: 'connect', tool: 'tool', file_write: 'write', file_delete: 'delete',
  message: 'msg', report: 'report', status: 'status', task: 'task',
  auth_fail: 'deny', login_fail: 'deny', login_ok: 'login', logout: 'logout',
  folder_created: 'folder+', folder_deleted: 'folder-', key_created: 'key+',
  key_revoked: 'key-', key_deleted: 'key-', server_start: 'boot', server_stop: 'halt',
  settings: 'cfg', password_change: 'passwd', trash_empty: 'trash',
  rate_limit: 'limit', tool_error: 'error'
};

const STATUS_LABEL = { open: 'открыта', claimed: 'в работе', blocked: 'блок', done: 'готово' };

/* ------------------------------------------------------------------ */
/* utils                                                               */
/* ------------------------------------------------------------------ */

const $ = (selector, root = document) => root.querySelector(selector);
const $$ = (selector, root = document) => Array.from(root.querySelectorAll(selector));

function esc(value) {
  return String(value ?? '').replace(/[&<>"']/g, (ch) => ({
    '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;'
  }[ch]));
}

function fmtBytes(bytes) {
  let value = Number(bytes) || 0;
  const units = ['B', 'KB', 'MB', 'GB', 'TB'];
  let i = 0;
  while (value >= 1024 && i < units.length - 1) { value /= 1024; i += 1; }
  return `${i === 0 ? value.toFixed(0) : value.toFixed(1)} ${units[i]}`;
}

function fmtDuration(seconds) {
  const s = Math.max(0, Math.floor(Number(seconds) || 0));
  const d = Math.floor(s / 86400);
  const h = Math.floor((s % 86400) / 3600);
  const m = Math.floor((s % 3600) / 60);
  if (d) return `${d}д ${h}ч`;
  if (h) return `${h}ч ${m}м`;
  return `${m}м`;
}

function shortTime(value) {
  if (!value) return '—';
  const text = String(value);
  return text.length >= 19 ? text.slice(11, 19) : text;
}

function dateText(value) {
  if (!value) return '—';
  return String(value).slice(0, 16);
}

function fileDate(epoch) {
  if (!epoch) return '—';
  return new Date(epoch * 1000).toLocaleDateString('ru-RU', { day: '2-digit', month: '2-digit', year: '2-digit' });
}

function toast(message, type = 'ok') {
  const box = $('#toasts');
  const el = document.createElement('div');
  el.className = `toast ${type === 'ok' ? '' : type}`.trim();
  el.textContent = message;
  box.appendChild(el);
  setTimeout(() => { el.classList.add('fade'); }, 3800);
  setTimeout(() => el.remove(), 4300);
}

async function copyText(text) {
  try {
    await navigator.clipboard.writeText(text);
    toast('Скопировано');
    return;
  } catch (_) { /* fall through */ }
  const area = document.createElement('textarea');
  area.value = text;
  area.setAttribute('readonly', '');
  area.style.position = 'fixed';
  area.style.opacity = '0';
  document.body.appendChild(area);
  area.select();
  try { document.execCommand('copy'); toast('Скопировано'); }
  catch (_) { toast('Не удалось скопировать', 'error'); }
  area.remove();
}

async function api(path, options = {}) {
  const opts = { credentials: 'same-origin', cache: 'no-store', ...options };
  opts.headers = { ...(options.headers || {}) };
  if (opts.body && !opts.headers['Content-Type']) opts.headers['Content-Type'] = 'application/json';
  if (state.csrf && opts.method && opts.method !== 'GET') {
    opts.headers['X-CSRF-Token'] = state.csrf;
  }
  const response = await fetch(path, opts);
  if (response.status === 401) {
    window.location.href = '/login';
    throw new Error('Требуется вход');
  }
  const type = response.headers.get('content-type') || '';
  const data = type.includes('application/json')
    ? await response.json().catch(() => ({}))
    : await response.text();
  if (!response.ok) {
    const detail = data && data.detail ? data.detail : data;
    const message = typeof detail === 'string' ? detail : `HTTP ${response.status}`;
    const error = new Error(message);
    error.status = response.status;
    throw error;
  }
  return data;
}

/* ------------------------------------------------------------------ */
/* boot                                                                */
/* ------------------------------------------------------------------ */

document.addEventListener('DOMContentLoaded', boot);

async function boot() {
  try {
    const config = await api('/api/config');
    state.me = config;
    state.csrf = config.csrf;
    state.origin = config.origin;
    $('#user-name').textContent = config.username;
  } catch (error) {
    if (error.status !== 401) toast(error.message, 'error');
    return;
  }
  bindEvents();
  tickClock();
  setInterval(tickClock, 1000);
  await refreshAll();
  connectSSE();
  setInterval(() => {
    if (state.view === 'live') loadMessages();
    if (state.view === 'connections' || state.view === 'keys') loadConnections();
  }, 12000);
}

async function refreshAll(showToast = false) {
  const jobs = [
    ['overview', api('/api/overview')],
    ['folders', api('/api/folders')],
    ['keys', api('/api/keys')],
    ['connections', api('/api/connections')],
    ['events', api('/api/events?limit=120')],
    ['messages', api('/api/messages?limit=120')],
    ['reports', api('/api/reports?limit=80')],
    ['tasks', api('/api/tasks')],
    ['settings', api('/api/settings')]
  ];
  const results = await Promise.allSettled(jobs.map(([, p]) => p));
  results.forEach((result, index) => {
    if (result.status !== 'fulfilled') return;
    const key = jobs[index][0];
    const data = result.value;
    if (key === 'overview') {
      state.overview = data;
      state.agents = data.agents || [];
    } else if (key === 'connections') {
      state.connections = data.connections || [];
      state.failures = data.failures || [];
    } else if (key === 'settings') {
      state.settings = data;
    } else {
      state[key] = data[key] || data;
    }
  });
  if (state.events.length) {
    state.lastEventId = Math.max(state.lastEventId, state.events[state.events.length - 1].id || 0);
  }
  if (state.me.origin) state.origin = state.me.origin;
  renderAll();
  if (showToast) toast('Обновлено');
}

function renderAll() {
  renderStats();
  fillAgentSelects();
  renderAgents();
  renderMiniFeed();
  renderQuickStart();
  renderNodeState();
  renderFolders();
  renderKeys();
  renderConnections();
  renderEvents();
  renderChat();
  renderReports();
  renderTasks();
  renderSettings();
  updateBadges();
  if (state.view === 'files' && !state.fs.entries.length) initFiles();
}

function updateBadges() {
  const stats = state.overview?.stats || {};
  const activeKeys = state.keys.filter((k) => k.status === 'active').length;
  const online = state.connections.filter((c) => c.online).length;
  $('#nav-folders').textContent = state.folders.length || '';
  $('#nav-keys').textContent = activeKeys || '';
  $('#nav-online').textContent = online || '';
  $('#nav-reports').textContent = state.reports.length || '';
  $('#nav-tasks').textContent = stats.open_tasks || '';
  $('#agents-count').textContent = `${stats.online || 0} / ${stats.agents || 0}`;
  $('#keys-count').textContent = `${activeKeys} активных · ${state.keys.length} всего`;
  $('#online-count').textContent = `${online} online`;
  $('#reports-count').textContent = state.reports.length;
  $('#tasks-open-count').textContent = `${stats.open_tasks || 0} в работе`;
}

/* ------------------------------------------------------------------ */
/* navigation                                                          */
/* ------------------------------------------------------------------ */

function setView(name) {
  if (!VIEW_META[name]) return;
  state.view = name;
  $$('.nav-item').forEach((item) => item.classList.toggle('active', item.dataset.view === name));
  $$('.view').forEach((view) => view.classList.toggle('active', view.id === `view-${name}`));
  $('#view-code').textContent = VIEW_META[name][0];
  $('#view-title').textContent = VIEW_META[name][1];
  $('#sidebar').classList.remove('open');
  if (name === 'files') {
    if (!state.fs.entries.length) initFiles();
    else renderFiles();
  }
  if (name === 'live') {
    renderEvents();
    renderChat();
    const log = $('#feed');
    if (log) log.scrollTop = log.scrollHeight;
  }
  if (name === 'settings') renderSettings();
}

function bindEvents() {
  $('#nav').addEventListener('click', (event) => {
    const button = event.target.closest('[data-view]');
    if (button) setView(button.dataset.view);
  });

  document.addEventListener('click', (event) => {
    const go = event.target.closest('[data-goto-view]');
    if (go) { setView(go.dataset.gotoView); return; }
    const copy = event.target.closest('[data-copy]');
    if (copy) { copyText(copy.dataset.copy || ''); return; }
    const filesAgent = event.target.closest('[data-files-agent]');
    if (filesAgent) { openFilesForAgent(filesAgent.dataset.filesAgent); return; }
    const keyAgent = event.target.closest('[data-key-agent]');
    if (keyAgent) { openKeyModal(keyAgent.dataset.keyAgent); return; }
    const delAgent = event.target.closest('[data-delete-agent]');
    if (delAgent) { openDeleteFolder(delAgent.dataset.deleteAgent); return; }
    const revoke = event.target.closest('[data-key-revoke]');
    if (revoke) { openRevokeKey(Number(revoke.dataset.keyRevoke), revoke.dataset.keyName || ''); return; }
    const delKey = event.target.closest('[data-key-delete]');
    if (delKey) { openDeleteKey(Number(delKey.dataset.keyDelete), delKey.dataset.keyName || ''); return; }
    const report = event.target.closest('[data-report-id]');
    if (report) { openReport(Number(report.dataset.reportId)); return; }
    const close = event.target.closest('[data-close]');
    if (close) { closeModal(); return; }
    const fsPath = event.target.closest('[data-fs-path]');
    if (fsPath) { loadFs(fsPath.dataset.fsPath); return; }
    const fsEntry = event.target.closest('[data-fs-entry]');
    if (fsEntry) {
      if (fsEntry.dataset.fsDir === '1') loadFs(fsEntry.dataset.fsEntry);
      else previewFs(fsEntry.dataset.fsEntry);
      return;
    }
    const task = event.target.closest('[data-task-id]');
    if (task && event.target.tagName !== 'SELECT' && event.target.tagName !== 'OPTION') {
      openTaskDetail(Number(task.dataset.taskId));
    }
  });

  $('#refresh-all').addEventListener('click', () => refreshAll(true));
  $('#menu-toggle').addEventListener('click', () => $('#sidebar').classList.toggle('open'));
  $('#logout').addEventListener('click', doLogout);
  $('#logout-all').addEventListener('click', doLogout);

  $('#feed-filters').addEventListener('click', (event) => {
    const chip = event.target.closest('[data-filter]');
    if (!chip) return;
    $$('#feed-filters .chip').forEach((c) => c.classList.toggle('active', c === chip));
    state.feedFilter = chip.dataset.filter;
    renderEvents();
  });

  $('#pause-feed').addEventListener('click', () => {
    state.feedPaused = !state.feedPaused;
    $('#pause-feed').textContent = state.feedPaused ? 'Продолжить' : 'Пауза';
    $('#feed-paused').classList.toggle('hidden', !state.feedPaused);
    if (!state.feedPaused) renderEvents();
  });

  $('#chat-form').addEventListener('submit', sendChat);
  $('#new-folder-btn').addEventListener('click', () => openFolderModal());
  $('#new-key-btn').addEventListener('click', () => openKeyModal());
  $('#new-task-btn').addEventListener('click', openTaskModal);
  $('#empty-trash-btn').addEventListener('click', openEmptyTrash);
  $('#empty-trash-btn-2').addEventListener('click', openEmptyTrash);

  $('#copy-token').addEventListener('click', () => { if (state.token) copyText(state.token); });
  $('#copy-snippet').addEventListener('click', () => {
    const text = $('#snippet-box').textContent;
    if (text) copyText(text);
  });
  $('#hide-token').addEventListener('click', hideToken);
  $('#snippet-tabs').addEventListener('click', (event) => {
    const tab = event.target.closest('[data-snippet]');
    if (!tab) return;
    state.snippetTab = tab.dataset.snippet;
    $$('#snippet-tabs .tab').forEach((item) => item.classList.toggle('active', item === tab));
    renderSnippet();
  });

  $('#fs-root').addEventListener('change', () => {
    state.fs.root = $('#fs-root').value;
    state.fs.path = '';
    state.fs.selected = '';
    $('#fs-agent').classList.toggle('hidden', state.fs.root !== 'agent');
    if (state.fs.root === 'agent') state.fs.agent = $('#fs-agent').value || state.fs.agent;
    loadFs('');
  });
  $('#fs-agent').addEventListener('change', () => {
    state.fs.agent = $('#fs-agent').value;
    loadFs('');
  });
  $('#fs-up').addEventListener('click', () => {
    const parts = state.fs.path.split('/').filter(Boolean);
    parts.pop();
    loadFs(parts.join('/'));
  });
  $('#fs-refresh').addEventListener('click', () => loadFs(state.fs.path));

  $('#password-form').addEventListener('submit', changePassword);

  document.addEventListener('keydown', (event) => {
    if (event.key === 'Escape') closeModal();
  });

  document.addEventListener('change', async (event) => {
    const select = event.target.closest('[data-task-status]');
    if (!select) return;
    const id = Number(select.dataset.taskStatus);
    try {
      await api(`/api/tasks/${id}`, { method: 'PATCH', body: JSON.stringify({ status: select.value }) });
      toast('Статус задачи обновлён');
      await loadTasks();
      await loadOverview();
    } catch (error) {
      toast(error.message, 'error');
      await loadTasks();
    }
  });
}

async function doLogout() {
  try { await api('/api/logout', { method: 'POST' }); } catch (_) { /* ignore */ }
  window.location.href = '/login';
}

function tickClock() {
  const now = new Date();
  $('#clock').textContent = now.toLocaleTimeString('ru-RU', { hour12: false });
}

/* ------------------------------------------------------------------ */
/* overview                                                            */
/* ------------------------------------------------------------------ */

function renderStats() {
  const s = state.overview?.stats || {};
  const cards = [
    ['AGENTS ONLINE', `${s.online || 0} / ${s.agents || 0}`, 'в сети'],
    ['FOLDERS', s.folders || 0, 'рабочих папок'],
    ['KEYS', `${s.active_keys || 0} / ${s.total_keys || 0}`, 'активных'],
    ['REPORTS', s.reports || 0, 'в общей папке'],
    ['TASKS', s.open_tasks || 0, 'в работе'],
    ['EVENTS', s.events_today || 0, 'за сутки']
  ];
  $('#stat-grid').innerHTML = cards.map(([k, v, s2]) => `
    <div class="stat">
      <div class="k">${esc(k)}</div>
      <div class="v">${esc(v)}</div>
      <div class="s">${esc(s2)}</div>
    </div>`).join('');
}

function renderAgents() {
  const box = $('#agents-grid');
  if (!state.agents.length) {
    box.innerHTML = `<div class="empty"><strong>Пока никого</strong>Создай папку и ключ — агент появится здесь.</div>`;
    return;
  }
  box.innerHTML = state.agents.map((a) => `
    <article class="agent-card">
      <div class="agent-top">
        <span class="dot ${a.online ? 'online' : ''}"></span>
        <span class="agent-name" title="${esc(a.name)}">${esc(a.name)}</span>
        <span class="spacer"></span>
        <span class="badge ${a.online ? 'ok' : 'muted'}">${a.online ? 'online' : 'offline'}</span>
      </div>
      <div class="agent-status">${a.status ? esc(a.status) : '<span class="muted">статус не задан</span>'}</div>
      <div class="agent-meta">${a.last_seen ? `был(а): ${esc(dateText(a.last_seen))}` : 'ещё не подключался'}</div>
      <div class="agent-meta truncate" title="${esc(a.workspace)}">${esc(a.workspace)}</div>
      <div class="agent-actions">
        <button class="btn small ghost" data-files-agent="${esc(a.name)}">Файлы</button>
        <button class="btn small ghost" data-key-agent="${esc(a.name)}">Ключ</button>
        <button class="btn small ghost" data-copy="${esc(a.workspace)}">Путь</button>
      </div>
    </article>`).join('');
}

function renderMiniFeed() {
  const events = state.events.slice(-10);
  $('#feed-mini').innerHTML = events.length
    ? events.map((e) => eventItem(e)).join('')
    : `<div class="empty"><strong>Тишина</strong>События появятся после подключения первого агента.</div>`;
  const el = $('#feed-mini');
  el.scrollTop = el.scrollHeight;
}

function renderQuickStart() {
  const origin = state.origin || window.location.origin;
  const url = `${origin}/mcp`;
  $('#quick-start').innerHTML = `
    <div class="stack">
      <div>
        <div class="eyebrow">MCP ENDPOINT</div>
        <div class="endpoint">
          <code>${esc(url)}</code>
          <button class="btn small ghost" data-copy="${esc(url)}">copy</button>
        </div>
      </div>
      <ol class="steps">
        <li><b>Папка.</b> Создай рабочую папку агента во вкладке «Папки».</li>
        <li><b>Ключ.</b> Выдай длинный ключ во вкладке «Ключи» и скопируй готовый конфиг.</li>
        <li><b>Подключение.</b> Друг добавляет MCP-сервер в Claude Code / OpenCode / другой клиент.</li>
        <li><b>Работа.</b> Агент вызывает <span class="mono">whoami</span> и <span class="mono">project_brief</span>, берёт задачу и пишет отчёты в общую папку.</li>
      </ol>
      <div class="btn-row">
        <button class="btn small" data-goto-view="keys">Создать ключ</button>
        <button class="btn small ghost" data-goto-view="live">Смотреть Live</button>
      </div>
    </div>`;
}

function renderNodeState() {
  const s = state.overview?.server || {};
  const stats = state.overview?.stats || {};
  const total = stats.disk_total || 0;
  const used = total - (stats.disk_free || 0);
  $('#node-state').innerHTML = `
    <dl class="kv">
      <dt>Версия</dt><dd>${esc(s.version || '—')}</dd>
      <dt>Аптайм</dt><dd>${esc(fmtDuration(s.uptime || 0))}</dd>
      <dt>База</dt><dd>${esc(s.base || '—')}</dd>
      <dt>Общие отчёты</dt><dd>${esc(s.shared || '—')}</dd>
      <dt>MCP</dt><dd>${esc(`${s.origin || state.origin}/mcp`)}</dd>
    </dl>
    <div class="divider"></div>
    <div class="eyebrow">ДИСК</div>
    <div class="kv mt-8">
      <dt>Занято</dt><dd>${esc(fmtBytes(used))} / ${esc(fmtBytes(total))}</dd>
    </div>
    <progress max="${total || 1}" value="${used || 0}"></progress>`;
}

/* ------------------------------------------------------------------ */
/* folders                                                             */
/* ------------------------------------------------------------------ */

function renderFolders() {
  const body = $('#folders-table');
  if (!state.folders.length) {
    body.innerHTML = `<tr><td colspan="6"><div class="empty"><strong>Папок нет</strong>Создай первую папку — она станет домом для агента.</div></td></tr>`;
  } else {
    body.innerHTML = state.folders.map((f) => `
      <tr>
        <td><span class="dot ${f.online ? 'online' : ''}"></span> <b>${esc(f.name)}</b>${f.note ? `<div class="sub">${esc(f.note)}</div>` : ''}</td>
        <td>${f.online ? '<span class="badge ok">online</span>' : '<span class="badge muted">offline</span>'}</td>
        <td class="path-cell" title="${esc(f.workspace)}">${esc(f.workspace)}</td>
        <td class="mono-cell">${esc(f.size_h)} <span class="sub">${esc(f.file_count)} файлов</span></td>
        <td class="mono-cell">${esc(f.created || '—')}</td>
        <td><div class="row-actions">
          <button class="btn small ghost" data-files-agent="${esc(f.name)}">Файлы</button>
          <button class="btn small ghost" data-key-agent="${esc(f.name)}">Ключ</button>
          <button class="btn small danger" data-delete-agent="${esc(f.name)}">Удалить</button>
        </div></td>
      </tr>`).join('');
  }
  $('#folders-count').textContent = `${state.folders.length} папок · ${state.folders.filter((f) => f.online).length} online`;
}

function openFolderModal() {
  openModal({
    title: 'Новая папка',
    body: `
      <form id="folder-form" class="stack">
        <label class="field"><span>Имя папки</span>
          <input id="folder-name" required maxlength="64" pattern="[A-Za-z0-9._\\-]{1,64}"
                 placeholder="alice-ios" autocomplete="off">
          <span class="field-hint">Латиница, цифры, точка, дефис, подчёркивание. Без пробелов.</span>
        </label>
        <label class="field"><span>Заметка</span>
          <input id="folder-note" maxlength="500" placeholder="Например: iPhone 16 Pro, iOS 27.2">
        </label>
        <div class="callout mint">Будет создана папка <span class="mono">agents/имя</span> с подпапками notes, evidence, scripts и README.</div>
      </form>`,
    footer: `<button class="btn ghost" data-close="1">Отмена</button>
             <button class="btn primary" id="modal-submit">Создать</button>`,
    onMount: () => {
      const form = $('#folder-form');
      const submit = $('#modal-submit');
      form.addEventListener('submit', async (event) => {
        event.preventDefault();
        submit.disabled = true;
        try {
          const name = $('#folder-name').value.trim();
          const note = $('#folder-note').value.trim();
          await api('/api/folders', { method: 'POST', body: JSON.stringify({ name, note }) });
          closeModal();
          toast(`Папка ${name} создана`);
          await loadFolders();
          await loadOverview();
          fillAgentSelects();
        } catch (error) {
          toast(error.message, 'error');
          submit.disabled = false;
        }
      });
      submit.addEventListener('click', () => form.requestSubmit());
      $('#folder-name').focus();
    }
  });
}

function openDeleteFolder(name) {
  const folder = state.folders.find((f) => f.name === name);
  openModal({
    title: `Удалить папку ${name}?`,
    body: `
      <div class="stack">
        <div class="callout">Папка будет перемещена в <span class="mono">agents/.trash</span>, все её ключи будут отозваны. Файлы внутри сохранятся до очистки корзины.</div>
        <label class="field"><span>Введи имя папки для подтверждения</span>
          <input id="confirm-name" autocomplete="off" placeholder="${esc(name)}">
        </label>
        ${folder ? `<div class="hint">Внутри: ${esc(folder.file_count)} файлов, ${esc(folder.size_h)}</div>` : ''}
      </div>`,
    footer: `<button class="btn ghost" data-close="1">Отмена</button>
             <button class="btn danger" id="modal-submit" disabled>Удалить</button>`,
    onMount: () => {
      const input = $('#confirm-name');
      const submit = $('#modal-submit');
      input.addEventListener('input', () => { submit.disabled = input.value.trim() !== name; });
      submit.addEventListener('click', async () => {
        submit.disabled = true;
        try {
          await api(`/api/folders/${encodeURIComponent(name)}?confirm=${encodeURIComponent(name)}`, { method: 'DELETE' });
          closeModal();
          toast(`Папка ${name} удалена`);
          await loadFolders();
          await loadOverview();
          await loadKeys();
          fillAgentSelects();
        } catch (error) {
          toast(error.message, 'error');
          submit.disabled = false;
        }
      });
      input.focus();
    }
  });
}

/* ------------------------------------------------------------------ */
/* keys                                                                */
/* ------------------------------------------------------------------ */

function renderKeys() {
  const body = $('#keys-table');
  if (!state.keys.length) {
    body.innerHTML = `<tr><td colspan="9"><div class="empty"><strong>Ключей нет</strong>Создай ключ — он покажется целиком только один раз.</div></td></tr>`;
    return;
  }
  body.innerHTML = state.keys.map((k) => {
    const cls = k.status === 'active' ? 'ok' : (k.status === 'expired' ? 'warn' : 'danger');
    return `
      <tr>
        <td><b>${esc(k.name)}</b>${k.online ? ' <span class="dot online"></span>' : ''}</td>
        <td class="mono-cell">${esc(k.folder)}</td>
        <td class="mono-cell">${esc(k.prefix)}…</td>
        <td><span class="badge ${cls}">${esc(k.status)}</span></td>
        <td class="mono-cell">${esc(k.created || '—')}</td>
        <td class="mono-cell">${esc(k.expires || 'бессрочно')}</td>
        <td class="mono-cell">${esc(k.last_used || '—')}<div class="sub">${esc(k.last_ip || '')}</div></td>
        <td class="mono-cell">${esc(k.requests)}</td>
        <td><div class="row-actions">
          ${k.status === 'active' ? `<button class="btn small danger" data-key-revoke="${k.id}" data-key-name="${esc(k.name)}">Отозвать</button>` : ''}
          ${k.status !== 'active' ? `<button class="btn small ghost" data-key-delete="${k.id}" data-key-name="${esc(k.name)}">Удалить</button>` : ''}
        </div></td>
      </tr>`;
  }).join('');
}

function openKeyModal(folder = '') {
  if (!state.folders.length) {
    toast('Сначала создай папку агента', 'warn');
    setView('folders');
    return;
  }
  const selected = folder || state.folders[0].name;
  const options = state.folders.map((f) => `<option value="${esc(f.name)}" ${f.name === selected ? 'selected' : ''}>${esc(f.name)}</option>`).join('');
  openModal({
    title: 'Новый API-ключ',
    body: `
      <form id="key-form" class="stack">
        <label class="field"><span>Имя ключа</span>
          <input id="key-name" value="${esc(selected)} / main" maxlength="80" required>
        </label>
        <label class="field"><span>Папка агента</span>
          <select id="key-folder">${options}</select>
        </label>
        <label class="field"><span>Срок жизни</span>
          <select id="key-ttl">
            <option value="0">бессрочно</option>
            <option value="7">7 дней</option>
            <option value="30">30 дней</option>
            <option value="90">90 дней</option>
            <option value="365">365 дней</option>
          </select>
        </label>
        <label class="field checkbox-field">
          <input id="key-readonly" type="checkbox">
          <span>Только чтение (без записи в папку и отчётов)</span>
        </label>
        <div class="callout">Ключ будет показан один раз. Он даёт доступ к MCP-инструментам в рамках указанной папки.</div>
      </form>`,
    footer: `<button class="btn ghost" data-close="1">Отмена</button>
             <button class="btn primary" id="modal-submit">Создать ключ</button>`,
    onMount: () => {
      const form = $('#key-form');
      const submit = $('#modal-submit');
      form.addEventListener('submit', async (event) => {
        event.preventDefault();
        submit.disabled = true;
        try {
          const folder = $('#key-folder').value;
          const data = await api('/api/keys', {
            method: 'POST',
            body: JSON.stringify({
              name: $('#key-name').value.trim(),
              folder,
              ttl_days: Number($('#key-ttl').value) || 0,
              read_only: $('#key-readonly').checked
            })
          });
          closeModal();
          showToken(data, folder);
          await loadKeys();
          await loadOverview();
        } catch (error) {
          toast(error.message, 'error');
          submit.disabled = false;
        }
      });
      submit.addEventListener('click', () => form.requestSubmit());
      $('#key-name').focus();
    }
  });
}

function showToken(data, folder) {
  state.token = data.token;
  state.snippets = data.snippets;
  state.snippetTab = 'claude';
  $('#token-value').textContent = data.token;
  $('#token-banner').classList.remove('hidden');
  $$('#snippet-tabs .tab').forEach((tab) => tab.classList.toggle('active', tab.dataset.snippet === 'claude'));
  renderSnippet();
  $('#token-banner').scrollIntoView({ behavior: 'smooth', block: 'center' });
  setView('keys');
  toast(`Ключ для ${folder} создан`);
}

function hideToken() {
  $('#token-banner').classList.add('hidden');
  $('#token-value').textContent = '';
  $('#snippet-box').textContent = '';
  state.token = null;
  state.snippets = null;
}

function renderSnippet() {
  if (!state.snippets) return;
  const text = state.snippets[state.snippetTab] || state.snippets.claude || '';
  $('#snippet-box').textContent = text;
  const copy = $('#copy-snippet');
  if (copy) {
    copy.textContent = (state.snippetTab === 'prompt' || state.snippetTab === 'worker')
      ? 'Копировать промпт'
      : 'Копировать';
  }
}

function openRevokeKey(id, name) {
  openModal({
    title: 'Отозвать ключ?',
    body: `<div class="stack">
      <p>Ключ <b>${esc(name)}</b> перестанет работать сразу. Активные сессии агента не смогут вызвать MCP.</p>
      <div class="callout">Это безопаснее удаления: запись останется в аудите.</div>
    </div>`,
    footer: `<button class="btn ghost" data-close="1">Отмена</button>
             <button class="btn danger" id="modal-submit">Отозвать</button>`,
    onMount: () => {
      $('#modal-submit').addEventListener('click', async () => {
        try {
          await api(`/api/keys/${id}/revoke`, { method: 'POST' });
          closeModal();
          toast('Ключ отозван');
          await loadKeys();
          await loadOverview();
        } catch (error) { toast(error.message, 'error'); }
      });
    }
  });
}

function openDeleteKey(id, name) {
  openModal({
    title: 'Удалить запись ключа?',
    body: `<p>Ключ <b>${esc(name)}</b> уже неактивен. Удаление уберёт запись из аудита.</p>`,
    footer: `<button class="btn ghost" data-close="1">Отмена</button>
             <button class="btn danger" id="modal-submit">Удалить</button>`,
    onMount: () => {
      $('#modal-submit').addEventListener('click', async () => {
        try {
          await api(`/api/keys/${id}`, { method: 'DELETE' });
          closeModal();
          toast('Запись удалена');
          await loadKeys();
        } catch (error) { toast(error.message, 'error'); }
      });
    }
  });
}

/* ------------------------------------------------------------------ */
/* connections                                                         */
/* ------------------------------------------------------------------ */

function renderConnections() {
  const body = $('#connections-table');
  if (!state.connections.length) {
    body.innerHTML = `<tr><td colspan="8"><div class="empty"><strong>Подключений не было</strong>Выдай ключ и подключи первого агента.</div></td></tr>`;
  } else {
    body.innerHTML = state.connections.map((c) => {
      const geo = c.country === 'LAN'
        ? 'локальная сеть'
        : [c.country, c.city].filter(Boolean).join(', ') || (c.last_ip ? '…' : '—');
      const cls = c.status === 'active' ? 'ok' : (c.status === 'expired' ? 'warn' : 'danger');
      return `
        <tr>
          <td><b>${esc(c.name)}</b><div class="sub mono">${esc(c.prefix)}…</div></td>
          <td class="mono-cell">${esc(c.folder)}</td>
          <td><span class="badge ${cls}">${esc(c.status)}</span>${c.online ? ' <span class="dot online"></span>' : ''}</td>
          <td class="mono-cell">${esc(c.last_ip || '—')}</td>
          <td>${esc(geo)}${c.isp ? `<div class="sub">${esc(c.isp)}</div>` : ''}</td>
          <td class="mono-cell">${esc(c.last_used || '—')}</td>
          <td class="mono-cell">${esc(c.requests)}</td>
          <td class="path-cell" title="${esc(c.user_agent || '')}">${esc(c.user_agent || '—')}</td>
        </tr>`;
    }).join('');
  }

  const failures = $('#failures-list');
  if (!state.failures.length) {
    failures.innerHTML = `<tr><td colspan="3"><div class="empty">Отказов нет.</div></td></tr>`;
  } else {
    failures.innerHTML = state.failures.map((f) => `
      <tr><td class="mono-cell">${esc(f.at || '')}</td><td class="mono-cell">${esc(f.ip || '')}</td><td class="mono-cell">${esc(f.detail || '')}</td></tr>
    `).join('');
  }
}

/* ------------------------------------------------------------------ */
/* feed / chat                                                         */
/* ------------------------------------------------------------------ */

function matchesFilter(event, filter) {
  if (filter === 'all') return true;
  if (filter === 'tool') return ['tool', 'file_write', 'file_delete', 'tool_error'].includes(event.kind);
  if (filter === 'auth_fail') return ['auth_fail', 'login_fail', 'rate_limit'].includes(event.kind);
  if (filter === 'message') return event.kind === 'message';
  if (filter === 'status') return event.kind === 'status';
  if (filter === 'report') return event.kind === 'report';
  return true;
}

function eventItem(event) {
  const label = KIND_LABEL[event.kind] || event.kind;
  return `
    <div class="feed-item" data-kind="${esc(event.kind)}">
      <span class="feed-time">${esc(shortTime(event.at))}</span>
      <span class="feed-kind">${esc(label)}</span>
      <span class="feed-body"><span class="who">${esc(event.agent || 'system')}</span> ${esc(event.detail || '')}${event.ip ? ` <span class="muted">· ${esc(event.ip)}</span>` : ''}</span>
    </div>`;
}

function renderEvents() {
  if (state.feedPaused) return;
  const el = $('#feed');
  if (!el) return;
  const events = state.events.filter((e) => matchesFilter(e, state.feedFilter)).slice(-300);
  el.innerHTML = events.length
    ? events.map((e) => eventItem(e)).join('')
    : `<div class="empty"><strong>Пока тихо</strong>События появятся в реальном времени.</div>`;
  el.scrollTop = el.scrollHeight;
  if (state.view === 'overview') renderMiniFeed();
}

function renderChat() {
  const log = $('#chat-log');
  if (!log) return;
  if (!state.messages.length) {
    log.innerHTML = `<div class="empty"><strong>Сообщений нет</strong>Напиши команде — агенты увидят это через <span class="mono">read_messages</span>.</div>`;
  } else {
    log.innerHTML = state.messages.slice(-150).map((m) => `
      <div class="chat-msg ${m.sender === 'admin' ? 'admin' : ''}">
        <div class="meta">
          <span class="from">${esc(m.sender)}</span>
          <span>→ ${esc(m.recipient)}</span>
          <span class="spacer"></span>
          <span>${esc(dateText(m.at))}</span>
        </div>
        ${m.subject ? `<div class="task-title">${esc(m.subject)}</div>` : ''}
        <div class="body">${esc(m.body)}</div>
      </div>`).join('');
  }
  log.scrollTop = log.scrollHeight;
}

async function sendChat(event) {
  event.preventDefault();
  const body = $('#chat-body').value.trim();
  if (!body) return;
  const button = $('#chat-form button[type="submit"]');
  button.disabled = true;
  try {
    await api('/api/messages', {
      method: 'POST',
      body: JSON.stringify({
        recipient: $('#chat-recipient').value,
        subject: $('#chat-subject').value.trim(),
        body
      })
    });
    $('#chat-body').value = '';
    $('#chat-subject').value = '';
    await loadMessages();
    toast('Сообщение отправлено');
  } catch (error) {
    toast(error.message, 'error');
  } finally {
    button.disabled = false;
  }
}

/* ------------------------------------------------------------------ */
/* reports                                                             */
/* ------------------------------------------------------------------ */

function renderReports() {
  const body = $('#reports-table');
  if (!state.reports.length) {
    body.innerHTML = `<tr><td colspan="5"><div class="empty"><strong>Отчётов нет</strong>Агенты пишут их через <span class="mono">create_report</span>.</div></td></tr>`;
    return;
  }
  body.innerHTML = state.reports.map((r) => `
    <tr class="report-row" data-report-id="${r.id}">
      <td class="mono-cell">${esc(dateText(r.at))}</td>
      <td class="mono-cell">${esc(r.agent || '—')}</td>
      <td><b>${esc(r.title)}</b></td>
      <td><div class="report-summary">${esc(r.summary || '—')}</div></td>
      <td class="mono-cell">${esc((r.path || '').split('/').pop() || '—')}</td>
    </tr>`).join('');
}

async function openReport(id) {
  try {
    const report = await api(`/api/reports/${id}`);
    openModal({
      title: report.title,
      wide: true,
      body: `<div class="stack">
        <div class="task-meta">
          <span class="badge info">${esc(report.agent || '—')}</span>
          <span class="mono muted">${esc(report.at || '')}</span>
          <span class="mono muted">${esc(report.path || '')}</span>
        </div>
        ${report.summary ? `<div class="callout mint">${esc(report.summary)}</div>` : ''}
        <pre class="report-body">${esc(report.content || '')}</pre>
      </div>`,
      footer: `<a class="btn ghost" href="/api/reports/${report.id}/download">Скачать .md</a>
               <button class="btn" data-close="1">Закрыть</button>`
    });
  } catch (error) {
    toast(error.message, 'error');
  }
}

/* ------------------------------------------------------------------ */
/* tasks                                                               */
/* ------------------------------------------------------------------ */

function renderTasks() {
  const board = $('#task-board');
  if (!board) return;
  const columns = ['open', 'claimed', 'blocked', 'done'];
  board.innerHTML = columns.map((status) => {
    const tasks = state.tasks.filter((t) => t.status === status);
    return `
      <div class="task-col">
        <div class="task-col-head"><span class="dot ${status === 'claimed' ? 'busy' : (status === 'done' ? 'online' : '')}"></span>${esc(STATUS_LABEL[status])}<span class="count">${tasks.length}</span></div>
        ${tasks.length ? tasks.map(taskCard).join('') : `<div class="empty small">пусто</div>`}
      </div>`;
  }).join('');
}

function taskCard(task) {
  const prio = task.priority || 'normal';
  const cls = prio === 'critical' || prio === 'high' ? 'danger' : (prio === 'low' ? 'muted' : 'warn');
  return `
    <article class="task-card" data-task-id="${task.id}">
      <div class="task-title">#${task.id} ${esc(task.title)}</div>
      <div class="task-meta">
        <span class="badge ${cls}">${esc(prio)}</span>
        ${task.owner ? `<span class="mono">${esc(task.owner)}</span>` : '<span class="mono muted">свободна</span>'}
        <span class="spacer"></span>
        <span class="mono">${esc(dateText(task.updated_at))}</span>
      </div>
      ${task.detail ? `<div class="task-detail">${esc(task.detail)}</div>` : ''}
      <div class="task-actions">
        <select data-task-status="${task.id}" aria-label="Статус задачи">
          ${['open', 'claimed', 'blocked', 'done'].map((s) => `<option value="${s}" ${s === task.status ? 'selected' : ''}>${STATUS_LABEL[s]}</option>`).join('')}
        </select>
      </div>
    </article>`;
}

function openTaskModal() {
  openModal({
    title: 'Новая задача',
    body: `
      <form id="task-form" class="stack">
        <label class="field"><span>Заголовок</span>
          <input id="task-title" required maxlength="200" placeholder="Проверить IOSurface272 на OOB">
        </label>
        <label class="field"><span>Детали</span>
          <textarea id="task-detail" maxlength="20000" placeholder="Гипотеза, компонент, критерий готовности…"></textarea>
        </label>
        <label class="field"><span>Приоритет</span>
          <select id="task-priority">
            <option value="normal">normal</option>
            <option value="high">high</option>
            <option value="critical">critical</option>
            <option value="low">low</option>
          </select>
        </label>
      </form>`,
    footer: `<button class="btn ghost" data-close="1">Отмена</button>
             <button class="btn primary" id="modal-submit">Создать</button>`,
    onMount: () => {
      const form = $('#task-form');
      const submit = $('#modal-submit');
      form.addEventListener('submit', async (event) => {
        event.preventDefault();
        submit.disabled = true;
        try {
          await api('/api/tasks', {
            method: 'POST',
            body: JSON.stringify({
              title: $('#task-title').value.trim(),
              detail: $('#task-detail').value.trim(),
              priority: $('#task-priority').value
            })
          });
          closeModal();
          toast('Задача создана');
          await loadTasks();
          await loadOverview();
        } catch (error) {
          toast(error.message, 'error');
          submit.disabled = false;
        }
      });
      submit.addEventListener('click', () => form.requestSubmit());
      $('#task-title').focus();
    }
  });
}

function openTaskDetail(id) {
  const task = state.tasks.find((t) => t.id === id);
  if (!task) return;
  openModal({
    title: `Задача #${task.id}`,
    wide: true,
    body: `<div class="stack">
      <h3>${esc(task.title)}</h3>
      <div class="task-meta">
        <span class="badge ${task.priority === 'critical' ? 'danger' : 'warn'}">${esc(task.priority)}</span>
        <span class="badge info">${esc(task.status)}</span>
        <span class="mono">${esc(task.owner || 'свободна')}</span>
        <span class="mono muted">создана ${esc(dateText(task.at))}</span>
      </div>
      <pre class="report-body">${esc(task.detail || '(без деталей)')}</pre>
    </div>`,
    footer: `<button class="btn" data-close="1">Закрыть</button>`
  });
}

/* ------------------------------------------------------------------ */
/* settings                                                            */
/* ------------------------------------------------------------------ */

function renderSettings() {
  const s = state.settings;
  if (!s) return;
  const used = (s.disk_total || 0) - (s.disk_free || 0);
  $('#settings-connection').innerHTML = `
    <div>
      <div class="eyebrow">MCP ENDPOINT</div>
      <div class="endpoint"><code>${esc(s.mcp)}</code><button class="btn small ghost" data-copy="${esc(s.mcp)}">copy</button></div>
    </div>
    <form id="public-url-form" class="stack">
      <label class="field"><span>Публичный URL (для готовых конфигов)</span>
        <input id="public-url" value="${esc(s.public_url || '')}" placeholder="https://your-tunnel.trycloudflare.com">
        <span class="field-hint">Если пусто — используется адрес, по которому открыта панель.</span>
      </label>
      <button class="btn small" type="submit">Сохранить</button>
    </form>
    <div class="callout">Ключи создаются во вкладке «Ключи». Каждый ключ привязан к папке и не может выйти за её пределы.</div>`;
  $('#settings-storage').innerHTML = `
    <dl class="kv">
      <dt>Хранилище</dt><dd>${esc(s.base)}</dd>
      <dt>Общие отчёты</dt><dd>${esc(s.shared)}</dd>
      <dt>Данные сервера</dt><dd>${esc(s.data)}</dd>
      <dt>База</dt><dd>${esc(fmtBytes(s.db_bytes))}</dd>
      <dt>Диск</dt><dd>${esc(fmtBytes(used))} / ${esc(fmtBytes(s.disk_total))}</dd>
    </dl>
    <div class="mt-8"><progress max="${s.disk_total || 1}" value="${used || 0}"></progress></div>`;
  $('#settings-about').innerHTML = `
    <dl class="kv">
      <dt>Версия</dt><dd>${esc(s.version)}</dd>
      <dt>Оператор</dt><dd>${esc(s.username)}</dd>
      <dt>Trust proxy</dt><dd>${s.trust_proxy ? 'включён' : 'выключен'}</dd>
      <dt>Публичный URL</dt><dd>${esc(s.public_url || 'не задан')}</dd>
    </dl>`;

  const form = $('#public-url-form');
  form.addEventListener('submit', async (event) => {
    event.preventDefault();
    try {
      const data = await api('/api/settings', {
        method: 'POST',
        body: JSON.stringify({ public_url: $('#public-url').value.trim() })
      });
      state.settings.public_url = data.public_url;
      toast('Публичный URL сохранён');
      await loadSettings();
    } catch (error) { toast(error.message, 'error'); }
  });
}

async function changePassword(event) {
  event.preventDefault();
  const current = $('#pw-current').value;
  const next = $('#pw-new').value;
  if (next.length < 10) { toast('Новый пароль слишком короткий', 'warn'); return; }
  try {
    const data = await api('/api/password', {
      method: 'POST',
      body: JSON.stringify({ current, new: next })
    });
    state.csrf = data.csrf;
    $('#pw-current').value = '';
    $('#pw-new').value = '';
    toast('Пароль изменён');
  } catch (error) { toast(error.message, 'error'); }
}

function openEmptyTrash() {
  openModal({
    title: 'Очистить корзину?',
    body: `<div class="stack">
      <div class="callout">Все папки из <span class="mono">agents/.trash</span> будут удалены безвозвратно. Это действие нельзя отменить.</div>
    </div>`,
    footer: `<button class="btn ghost" data-close="1">Отмена</button>
             <button class="btn danger" id="modal-submit">Очистить</button>`,
    onMount: () => {
      $('#modal-submit').addEventListener('click', async () => {
        try {
          const data = await api('/api/trash/empty', { method: 'POST' });
          closeModal();
          toast(`Удалено объектов: ${data.removed}`);
        } catch (error) { toast(error.message, 'error'); }
      });
    }
  });
}

/* ------------------------------------------------------------------ */
/* files                                                               */
/* ------------------------------------------------------------------ */

function fillAgentSelects() {
  const names = state.agents.map((a) => a.name);

  const chat = $('#chat-recipient');
  if (chat) {
    const current = chat.value || 'all';
    chat.innerHTML = `<option value="all">всем</option><option value="admin">админу</option>` +
      names.map((n) => `<option value="${esc(n)}">${esc(n)}</option>`).join('');
    chat.value = Array.from(chat.options).some((o) => o.value === current) ? current : 'all';
  }

  const fsAgent = $('#fs-agent');
  if (fsAgent) {
    const current = fsAgent.value || state.fs.agent;
    fsAgent.innerHTML = names.map((n) => `<option value="${esc(n)}">${esc(n)}</option>`).join('');
    if (names.includes(current)) fsAgent.value = current;
    else if (names.length) fsAgent.value = names[0];
    state.fs.agent = fsAgent.value || '';
  }

  if (!state.fs.agent && names.length) state.fs.agent = names[0];
}

function initFiles() {
  if (!state.fs.agent && state.agents.length) state.fs.agent = state.agents[0].name;
  $('#fs-root').value = state.fs.root;
  $('#fs-agent').value = state.fs.agent;
  $('#fs-agent').classList.toggle('hidden', state.fs.root !== 'agent');
  loadFs(state.fs.path || '');
}

function openFilesForAgent(agent) {
  state.fs.root = 'agent';
  state.fs.agent = agent;
  state.fs.path = '';
  state.fs.selected = '';
  state.fs.entries = [];
  setView('files');
  $('#fs-root').value = 'agent';
  $('#fs-agent').value = agent;
  $('#fs-agent').classList.remove('hidden');
  loadFs('');
}

async function loadFs(path = '') {
  if (state.fs.root === 'agent' && !state.fs.agent) {
    $('#fs-list').innerHTML = `<div class="empty"><strong>Нет агентов</strong>Создай папку во вкладке «Папки».</div>`;
    return;
  }
  const params = new URLSearchParams({ root: state.fs.root, path });
  if (state.fs.root === 'agent') params.set('agent', state.fs.agent);
  try {
    const data = await api(`/api/fs/list?${params.toString()}`);
    state.fs.path = path;
    state.fs.entries = data.entries || [];
    state.fs.abs = data.abs;
    state.fs.selected = '';
    renderFiles();
  } catch (error) {
    toast(error.message, 'error');
  }
}

function renderFiles() {
  $('#fs-root').value = state.fs.root;
  $('#fs-agent').classList.toggle('hidden', state.fs.root !== 'agent');
  $('#fs-abs').textContent = state.fs.abs || '';
  $('#fs-list').innerHTML = state.fs.entries.length
    ? state.fs.entries.map((entry) => `
      <div class="file-row ${state.fs.selected === entry.path ? 'selected' : ''}"
           data-fs-entry="${esc(entry.path)}" data-fs-dir="${entry.is_dir ? '1' : '0'}">
        <span class="file-icon">${entry.is_dir ? '▸' : '·'}</span>
        <span class="file-name" title="${esc(entry.name)}">${esc(entry.name)}${entry.is_symlink ? ' <span class="muted">↗</span>' : ''}</span>
        <span class="file-size">${entry.is_dir ? '—' : esc(entry.size_h)}</span>
        <span class="file-date">${esc(fileDate(entry.mtime))}</span>
      </div>`).join('')
    : `<div class="empty"><strong>Пусто</strong>В этой папке пока нет файлов.</div>`;

  const crumbs = $('#fs-crumbs');
  const rootLabel = state.fs.root === 'agent'
    ? `agents/${state.fs.agent}`
    : (state.fs.root === 'shared' ? 'логи работы ИИ' : 'архив');
  const parts = state.fs.path.split('/').filter(Boolean);
  let html = `<button class="crumb" data-fs-path="">${esc(rootLabel)}</button>`;
  let prefix = '';
  parts.forEach((part) => {
    prefix = prefix ? `${prefix}/${part}` : part;
    html += `<span class="crumb-sep">/</span><button class="crumb" data-fs-path="${esc(prefix)}">${esc(part)}</button>`;
  });
  crumbs.innerHTML = html;
}

async function previewFs(path) {
  state.fs.selected = path;
  $$('#fs-list .file-row').forEach((row) => row.classList.toggle('selected', row.dataset.fsEntry === path));
  const params = new URLSearchParams({ root: state.fs.root, path, length: '262144' });
  if (state.fs.root === 'agent') params.set('agent', state.fs.agent);
  const download = `/api/fs/download?${new URLSearchParams({
    root: state.fs.root, agent: state.fs.root === 'agent' ? state.fs.agent : '', path
  }).toString()}`;
  $('#fs-preview').innerHTML = `<div class="empty">Загрузка…</div>`;
  try {
    const data = await api(`/api/fs/read?${params.toString()}`);
    const head = `
      <div class="preview-head">
        <span class="preview-title">${esc(data.path)}</span>
        <span class="badge">${esc(data.size_h)}</span>
        <span class="spacer"></span>
        <a class="btn small ghost" href="${esc(download)}">Скачать</a>
      </div>`;
    if (data.binary) {
      $('#fs-preview').innerHTML = head + `<div class="callout">Бинарный файл. Предпросмотр недоступен, используй скачивание или MCP <span class="mono">read_research</span>.</div>`;
    } else {
      $('#fs-preview').innerHTML = head + `<pre class="code">${esc(data.content || '')}</pre>` +
        (data.truncated ? `<p class="hint mt-8">Показаны первые ${esc(fmtBytes(data.bytes))} из ${esc(data.size_h)}.</p>` : '');
    }
  } catch (error) {
    $('#fs-preview').innerHTML = `<div class="empty"><strong>Ошибка</strong>${esc(error.message)}</div>`;
  }
}

/* ------------------------------------------------------------------ */
/* loaders                                                             */
/* ------------------------------------------------------------------ */

async function loadOverview() {
  try {
    const data = await api('/api/overview');
    state.overview = data;
    state.agents = data.agents || [];
    renderStats();
    renderAgents();
    renderNodeState();
    fillAgentSelects();
    updateBadges();
  } catch (_) { /* ignore */ }
}

async function loadFolders() {
  try {
    const data = await api('/api/folders');
    state.folders = data.folders || [];
    renderFolders();
    updateBadges();
  } catch (_) { /* ignore */ }
}

async function loadKeys() {
  try {
    const data = await api('/api/keys');
    state.keys = data.keys || [];
    renderKeys();
    updateBadges();
  } catch (_) { /* ignore */ }
}

async function loadConnections() {
  try {
    const data = await api('/api/connections');
    state.connections = data.connections || [];
    state.failures = data.failures || [];
    renderConnections();
    updateBadges();
  } catch (_) { /* ignore */ }
}

async function loadEvents() {
  try {
    const data = await api('/api/events?limit=120');
    state.events = data.events || [];
    if (state.events.length) state.lastEventId = state.events[state.events.length - 1].id || 0;
    renderEvents();
    renderMiniFeed();
  } catch (_) { /* ignore */ }
}

async function loadMessages() {
  try {
    const data = await api('/api/messages?limit=120');
    state.messages = data.messages || [];
    renderChat();
  } catch (_) { /* ignore */ }
}

async function loadReports() {
  try {
    const data = await api('/api/reports?limit=80');
    state.reports = data.reports || [];
    renderReports();
    updateBadges();
  } catch (_) { /* ignore */ }
}

async function loadTasks() {
  try {
    const data = await api('/api/tasks');
    state.tasks = data.tasks || [];
    renderTasks();
  } catch (_) { /* ignore */ }
}

async function loadSettings() {
  try {
    state.settings = await api('/api/settings');
    renderSettings();
  } catch (_) { /* ignore */ }
}

/* ------------------------------------------------------------------ */
/* live stream                                                         */
/* ------------------------------------------------------------------ */

function connectSSE() {
  if (state.es) state.es.close();
  const url = `/api/stream?after=${state.lastEventId || 0}`;
  const source = new EventSource(url);
  state.es = source;

  source.addEventListener('open', () => {
    const dot = $('#sse-dot');
    dot.classList.add('online');
    $('#sse-text').textContent = 'live · поток открыт';
  });

  source.addEventListener('hub', (event) => {
    try {
      const item = JSON.parse(event.data);
      addEvent(item);
    } catch (_) { /* ignore malformed */ }
  });

  source.addEventListener('error', () => {
    const dot = $('#sse-dot');
    dot.classList.remove('online');
    $('#sse-text').textContent = 'переподключение…';
  });
}

function addEvent(event) {
  if (!event || !event.id) return;
  if (state.events.some((e) => e.id === event.id)) return;
  state.lastEventId = Math.max(state.lastEventId, event.id);
  state.events.push(event);
  if (state.events.length > 600) state.events = state.events.slice(-400);

  if (!state.feedPaused) renderEvents();
  if (state.view === 'overview') renderMiniFeed();

  if (['connect', 'auth_fail', 'key_created', 'key_revoked', 'key_deleted', 'folder_created', 'folder_deleted'].includes(event.kind)) {
    scheduleRefresh();
  }
  if (event.kind === 'message') loadMessages();
  if (event.kind === 'report') loadReports();
  if (event.kind === 'task') loadTasks();
  if (event.kind === 'status' || event.kind === 'connect') loadOverview();
}

function scheduleRefresh() {
  clearTimeout(state.refreshTimer);
  state.refreshTimer = setTimeout(() => {
    loadOverview();
    loadConnections();
    loadFolders();
    loadKeys();
  }, 700);
}

/* ------------------------------------------------------------------ */
/* modal                                                               */
/* ------------------------------------------------------------------ */

function openModal({ title, body, footer = '', wide = false, onMount = null }) {
  $('#modal-title').textContent = title;
  $('#modal-body').innerHTML = body;
  $('#modal-foot').innerHTML = footer || '';
  $('#modal-card').classList.toggle('wide', wide);
  $('#modal').classList.remove('hidden');
  $('#modal').setAttribute('aria-hidden', 'false');
  if (onMount) onMount();
}

function closeModal() {
  $('#modal').classList.add('hidden');
  $('#modal').setAttribute('aria-hidden', 'true');
  $('#modal-body').innerHTML = '';
  $('#modal-foot').innerHTML = '';
}
