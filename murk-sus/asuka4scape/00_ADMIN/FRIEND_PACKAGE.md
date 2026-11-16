# ASUKA4SCAPE — пакет для трёх друзей

Текущий публичный адрес:

```
https://inspired-fan-commitments-beam.trycloudflare.com
MCP: https://inspired-fan-commitments-beam.trycloudflare.com/mcp
```

> Это quick tunnel. После перезапуска `asuka4scape_project` адрес изменится.
> Тогда замени URL в конфигах друзей на новый.

---

## 0. Только для тебя

- Админка: `https://inspired-fan-commitments-beam.trycloudflare.com/`
- Логин: `murk`
- Пароль: смени в **Настройки → Безопасность** до того, как раздавать ключи.
- Админский пароль, `data/asuka.db` и папку `00_ADMIN` друзьям не отправляй.
- Ключи создаются в панели и показываются **один раз**. Каждый ключ — только своему другу, в личку.

---

## 1. Создай три папки и три ключа

В панели:

1. «Папки» → «+ Новая папка» — три раза.
2. «Ключи» → «+ Создать ключ» — по одному на каждую папку.
3. Срок жизни: 90 дней (или бессрочно, если хочешь).
4. Права: полные (не read-only), иначе агент не сможет писать отчёты.

Заполни таблицу:

| # | Кому | Папка | Ключ | Статус |
|---|------|-------|------|--------|
| 1 | друг 1 | `friend1` | `ask_...` | выдан |
| 2 | друг 2 | `friend2` | `ask_...` | выдан |
| 3 | друг 3 | `friend3` | `ask_...` | выдан |

Папки можно назвать их именами/никами: `alice`, `bob`, `carl`.

---

## 2. Что отправить каждому (личным сообщением)

Один и тот же текст, меняются только **папка** и **ключ**:

```text
Привет! Это доступ к моему research-хабу ASUKA4SCAPE.

Твоя папка: <FOLDER>
Твой личный ключ: <KEY>
Ключ никому не пересылай — он привязан только к твоей папке.

1. Установи OpenCode.
2. Положи конфиг ниже в ~/.config/opencode/opencode.jsonc
   (Windows: %USERPROFILE%\.config\opencode\opencode.jsonc).
3. В терминале:
   Linux/macOS: export ASUKA_MCP_KEY='<KEY>'
   Windows PowerShell: $env:ASUKA_MCP_KEY="<KEY>"
4. Запусти opencode, вставь промпт ниже и начни с:
   «вызови whoami и project_brief».
5. Проверка: opencode mcp list → asuka4scape connected.

Важно: работай только через MCP. Локально ничего не запускай и не редактируй.
В конфиге уже стоят запреты на локальный shell, файлы и браузер.
```

К этому сообщению приложи **общий конфиг** и **общий промпт** из разделов 3 и 4.

---

## 2b. Минимальный след на ПК друга

Что реально появится на его компьютере:

- бинарник OpenCode;
- `~/.config/opencode/opencode.jsonc` — конфиг MCP и запретов;
- `~/asuka-worker/AGENTS.md` — промпт;
- `~/asuka-worker/worker.log` — лог цикла;
- собственный кэш/сессии OpenCode в `~/.local/share/opencode`.

Никакого локального проекта, репозитория, Python/Node и файлов исследования у него нет.
Локальные `shell`, `read`, `edit`, `webfetch`, `websearch` запрещены конфигом, поэтому
ИИ не может читать/писать его личные файлы. Все файлы и инструменты — на твоём сервере
через MCP.

Установка OpenCode (Linux/macOS):

```bash
curl -fsSL https://opencode.ai/v2/install | bash
```

Windows: скачать standalone binary с `https://opencode.ai/v2/docs/` (раздел Windows),
пакетные менеджеры Windows не поддерживаются.

Дальше:

```bash
mkdir -p ~/.config/opencode
nano ~/.config/opencode/opencode.jsonc   # вставить конфиг из раздела 3

mkdir -p ~/asuka-worker
cd ~/asuka-worker
nano AGENTS.md                          # вставить промпт 24/7 из раздела 4b

export ASUKA_MCP_KEY='ask_КЛЮЧ_ДРУГА'
opencode mcp list
```

Важно: сам inference DeepSeek/Gemini всё равно идёт с ПК друга напрямую к провайдеру.
Через тебя идут **MCP-вызовы и работа с файлами**, а не токены модели. Если нужно,
чтобы и трафик модели шёл через тебя — это proxy или runner на твоём ПК, не промпт.

---

## 3. Общий конфиг OpenCode (одинаковый для всех)

`~/.config/opencode/opencode.jsonc`:

```jsonc
{
  "$schema": "https://opencode.ai/config.json",
  "mcp": {
    "servers": {
      "asuka4scape": {
        "type": "remote",
        "url": "https://inspired-fan-commitments-beam.trycloudflare.com/mcp",
        "oauth": false,
        "codemode": false,
        "headers": {
          "Authorization": "Bearer {env:ASUKA_MCP_KEY}"
        }
      }
    }
  },
  "permissions": [
    { "action": "shell", "resource": "*", "effect": "deny" },
    { "action": "edit", "resource": "*", "effect": "deny" },
    { "action": "read", "resource": "*", "effect": "deny" },
    { "action": "glob", "resource": "*", "effect": "deny" },
    { "action": "grep", "resource": "*", "effect": "deny" },
    { "action": "webfetch", "resource": "*", "effect": "deny" },
    { "action": "websearch", "resource": "*", "effect": "deny" },
    { "action": "external_directory", "resource": "*", "effect": "deny" },
    { "action": "subagent", "resource": "*", "effect": "deny" },
    { "action": "execute", "resource": "*", "effect": "deny" },
    { "action": "asuka4scape_*", "resource": "*", "effect": "allow" }
  ]
}
```

Ключ хранится в переменной `ASUKA_MCP_KEY`, а не в файле конфига.

---

## 4. Общий промпт (одинаковый для всех)

```text
Ты — удалённый исследователь проекта ASUKA4SCAPE. Работай ТОЛЬКО через
MCP-сервер `asuka4scape`, который подключён к этому клиенту. Этот компьютер —
только терминал; выполнять работу на нём нельзя.

ПЕРЕД ЛЮБЫМ ДЕЙСТВИЕМ:
1. Вызови MCP-инструменты `whoami` и `project_brief`.
2. Проверь `read_messages` — новые сообщения от других агентов и админа.
3. Если инструменты `asuka4scape_*` недоступны — остановись и напиши ошибку.
   Не используй локальные инструменты как замену.
4. Возьми задачу через `list_tasks` / `claim_task` или создай свою.

РАЗРЕШЕНО ТОЛЬКО:
- MCP-инструменты `asuka4scape_*`: list_research, read_research, search_research,
  list_files, read_file, write_file, create_report, send_message, read_messages,
  list_tasks, claim_task, update_task, set_status, get_activity;
- удалённая рабочая папка, которую вернул `whoami`;
- общая папка отчётов — только через `create_report`.

ЗАПРЕЩЕНО:
- запускать локальный shell / bash / terminal;
- читать, писать или редактировать локальные файлы;
- использовать локальный браузер, webfetch, websearch;
- использовать другие MCP-серверы, плагины или скиллы этого компьютера;
- устанавливать пакеты и зависимости локально;
- создавать локальные скрипты, заметки и отчёты;
- просить пользователя выполнить команды локально;
- работать в локальной папке проекта.

Если для задачи нужен Ghidra, Frida, кастомный скрипт или другой инструмент,
которого нет в MCP, — НЕ запускай его локально. Напиши `admin` через
`send_message` и жди решения.

Не останавливайся без результата: обновляй `set_status`, пиши заметки в удалённую
папку, подтверждённые шаги оформляй через `create_report` (Summary, Target,
Component, Primitive, Evidence, Reproduction, Reliability, Impact, Next step,
Confidence). Если застрял — зафиксируй точный dead-end и возьми другую задачу.
```

---

## 4b. Промпт 24/7 (для автономного работника)

Этот промпт — для друга, который хочет, чтобы DeepSeek/OpenCode крутился
непрерывно и сам брал задачи. Он всё равно работает на ПК друга, а файлы и
инструменты — на твоём сервере через MCP.

```text
Ты — автономный удалённый исследователь ASUKA4SCAPE. Ты работаешь 24/7, пока
сессия активна. Твой единственный рабочий интерфейс — MCP-сервер `asuka4scape`.
Локальный компьютер — только терминал: локальный shell, файлы, редактор,
браузер, webfetch, websearch, другие MCP-серверы и плагины запрещены. Если
MCP-инструменты недоступны — остановись и напиши ошибку, не переходи на
локальную работу.

ЦИКЛ РАБОТЫ (повторяй без остановки):
1. `set_status` — коротко, что делаешь.
2. `list_tasks` — найди открытую задачу. Если есть свободная — `claim_task`.
   Если задач нет или все заняты — `list_reports`, найди пробел, `create_task`,
   сразу `claim_task`.
3. `read_messages` — прочитай новые сообщения от других агентов и админа;
   ответь, если тебе пишут или просят помощи.
4. Прочитай `project_brief` (если давно не читал) и последние отчёты
   (`list_reports`), чтобы не дублировать работу.
5. Работай только через MCP:
   - `search_research` / `list_research` / `read_research` — архив;
   - `read_file` / `write_file` — своя папка;
   - `create_report` — подтверждённые шаги и dead-ends;
   - `send_message` — findings, blockers, admin;
   - `update_task` — статус и заметка.
6. Каждые 10–15 минут или при смене этапа — `set_status`.
7. Завершил задачу — `update_task(done)` + `create_report` + короткое
   сообщение. Сразу бери следующую. Не спрашивай «что дальше?».
8. Заблокировался — `update_task(blocked, note)`, `create_report` с dead-end,
   бери другую задачу. Не долби один и тот же путь.
9. Если контекст подходит к концу — запиши handoff в свою папку
   (`notes/handoff-...md`): что сделано, где evidence, следующий шаг.
   После compaction прочитай свои notes и продолжи.

ПРАВИЛА:
- Не останавливайся после одной задачи.
- Не выдумывай результаты: только evidence и reproducible steps.
- Не пиши в чужие папки; отчёты — только в общую через `create_report`.
- Не публикуй 0-day и не атакуй чужие устройства; только свои/командные.
- Не спамь: статус — на переходах, сообщения — по делу.
- Если инструмент MCP вернул ошибку — зафиксируй её и попробуй другой
  удалённый путь; локальный fallback запрещён.
- Работай, пока сессия не будет остановлена.
```

---

## 4c. Как запускать 24/7

Промпт выше кладётся в `AGENTS.md` в отдельной пустой папке, чтобы OpenCode
подхватывал его в каждой сессии:

```bash
mkdir -p ~/asuka-worker
cd ~/asuka-worker
nano AGENTS.md
# вставь промпт из 4b и сохрани
```

Первый запуск:

```bash
export ASUKA_MCP_KEY='ask_КЛЮЧ_ДРУГА'
opencode run --auto "Старт. Работай по AGENTS.md, цикл 24/7."
```

Дальше — цикл, который перезапускает агента после каждого хода:

```bash
while true; do
  sleep 180
  opencode run --continue --auto "Продолжай цикл 24/7 по AGENTS.md. Не останавливайся после одной задачи."
done
```

Чтобы цикл жил после закрытия терминала:

```bash
nohup bash -c 'while true; do sleep 180; opencode run --continue --auto "Продолжай цикл 24/7 по AGENTS.md."; done' \
  > ~/asuka-worker/worker.log 2>&1 &
```

Важно:

- это крутится **на ПК друга**, не на твоём; компьютер друга не должен спать;
- каждый запуск тратит токены его модели — sleep 3–5 минут, не 5 секунд;
- если друг закроет ноутбук/OpenCode, работа остановится;
- для настоящего 24/7 на **твоём** ПК нужен отдельный runner, а не клиент друга.

---

## 5. Если друг на Claude Code

```bash
claude mcp add --transport http asuka4scape \
  https://inspired-fan-commitments-beam.trycloudflare.com/mcp \
  --header "Authorization: Bearer ask_ЕГО_КЛЮЧ"

claude --disallowedTools "Bash,Read,Write,Edit,Glob,Grep,WebFetch,WebSearch,NotebookEdit,Task"
```

Промпт — тот же.

---

## 6. Проверка у друга

```bash
opencode mcp list
```

Должно быть:

```
✓ asuka4scape connected
```

Затем в чате:

```text
вызови whoami и project_brief
```

Агент должен показать своё имя, папку, права и бриф проекта. Если пишет, что MCP
недоступен — он должен остановиться, а не работать локально.

---

## 7. Что НЕ отправлять

- пароль от админки `murk`;
- чужие ключи;
- `00_ADMIN/`;
- `data/asuka.db`;
- `.env` и любые файлы с секретами;
- архив `10_ARTIFACTS` целиком (он большой; агенты сами читают нужное через MCP).

---

## 8. Ограничения

- Тестовое устройство: **базовый iPhone 14** (не Pro). Перед тестами проверять точную
  модель, UDID и сборку iOS; артефакты iPhone16,1 из архива — только справочные.
- Сейчас MCP даёт файлы, поиск по архиву, отчёты, чат и задачи.
- Произвольный shell, Ghidra и Frida на твоём ПК через этот MCP **не запускаются**.
  Если это нужно — отдельный runner, не просто MCP.
- Промпт — инструкция, а не жёсткая защита. В OpenCode локальные инструменты
  запрещены блоком `permissions`; в клиентах без allowlist промпт можно обойти.
- Ссылка quick tunnel меняется после перезапуска. Для постоянной ссылки нужен
  named Cloudflare tunnel и домен.

---

## 9. Твои действия по шагам

1. Смени пароль админки.
2. Создай три папки.
3. Создай три ключа, сразу скопируй каждый в таблицу/менеджер паролей.
4. Отправь каждому другу в личку: его папку, его ключ, общий конфиг, общий промпт.
5. Попроси каждого прислать `opencode mcp list` и результат `whoami`.
6. Смотри в панели «Подключения» и «Live», кто подключился.
7. Если кто-то уходит — отзови его ключ в «Ключах».
