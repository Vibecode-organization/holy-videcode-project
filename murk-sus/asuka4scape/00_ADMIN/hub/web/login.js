'use strict';

const form = document.getElementById('login-form');
const errorBox = document.getElementById('login-error');
const submit = document.getElementById('login-submit');
const label = submit.querySelector('.btn-label');

function showError(message) {
  errorBox.textContent = message;
  errorBox.classList.remove('hidden');
}

form.addEventListener('submit', async (event) => {
  event.preventDefault();
  errorBox.classList.add('hidden');
  submit.disabled = true;
  label.textContent = 'Проверка…';

  try {
    const response = await fetch('/api/login', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({
        username: document.getElementById('username').value.trim(),
        password: document.getElementById('password').value
      })
    });
    const data = await response.json().catch(() => ({}));
    if (!response.ok) {
      throw new Error(data.detail || 'Не удалось войти');
    }
    window.location.href = '/admin';
  } catch (error) {
    showError(error.message || 'Ошибка соединения');
    submit.disabled = false;
    label.textContent = 'Войти';
  }
});

fetch('/healthz', { cache: 'no-store' })
  .then((r) => r.ok)
  .then((ok) => {
    const dot = document.getElementById('login-dot');
    if (!ok) throw new Error('down');
    dot.classList.add('online');
  })
  .catch(() => {
    document.getElementById('login-status').textContent = 'узел не отвечает';
  });
