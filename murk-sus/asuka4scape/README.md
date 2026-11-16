# ASUKA4SCAPE — хаб для совместной iOS-безопасности

Локальный сервер на этом ПК: браузерная админ-панель, MCP-сервер для ИИ-агентов,
изолированные папки исследователей, общий чат, доска задач и отчёты в реальном времени.

## Тестовое устройство

К хосту подключён **базовый iPhone 14** (не Pro) для тестов. Перед любым запуском
агент обязан проверить точную модель, UDID и сборку iOS. Артефакты iPhone16,1 / iOS 27.2
из архива — справочные; они не заменяют kernelcache/DeviceTree от подключённого iPhone 14.

## Запуск

```bash
asuka4scape_project                 # панель + MCP на 0.0.0.0:8080
asuka4scape_project --tunnel        # + публичная ссылка Cloudflare (quick tunnel)
asuka4scape_project --daemon        # в фоне
asuka4scape_project --daemon --tunnel
asuka4scape_project --status
asuka4scape_project --stop
```

После запуска:

- локально: `http://127.0.0.1:8080`
- по сети: `http://10.1.30.48:8080` (адрес может меняться)
- с `--tunnel`: ссылка `https://....trycloudflare.com` (меняется при перезапуске)
- MCP: `<адрес>/mcp`

Логин: `murk`. Пароль — тот, который задан при установке (по умолчанию из первого
запуска). **Смени пароль в «Настройках» перед публичным доступом.**

## Подключение агента

1. В панели открой «Папки» → «+ Новая папка». Это рабочее пространство агента.
2. «Ключи» → «+ Создать ключ» → выбери папку. Ключ показывается один раз.
3. Скопируй готовый конфиг из баннера (Claude Code / JSON / OpenCode).
4. На вкладке **«Промпт для ИИ»** в том же баннере — готовый текст, который надо
   дать агенту. Он запрещает работать локально и требует работать только через MCP.
5. Агент вызывает `whoami`, затем `project_brief` — и получает правила, пути и протокол
   работы. Дальше он сам берёт задачу через `list_tasks` / `claim_task`.

Пример для Claude Code:

```bash
claude mcp add --transport http asuka4scape https://ВАШ-АДРЕС/mcp \
  --header "Authorization: Bearer ask_ВАШ_КЛЮЧ"
```

Пример для OpenCode V2 (`~/.config/opencode/opencode.jsonc`):

```jsonc
{
  "$schema": "https://opencode.ai/config.json",
  "mcp": {
    "servers": {
      "asuka4scape": {
        "type": "remote",
        "url": "https://ВАШ-АДРЕС/mcp",
        "oauth": false,
        "codemode": false,
        "headers": { "Authorization": "Bearer {env:ASUKA_MCP_KEY}" }
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

```bash
export ASUKA_MCP_KEY='ask_ВАШ_КЛЮЧ'
opencode mcp list
```

Важно: один промпт — это инструкция, а не жёсткая защита. Чтобы агент **не мог**
работать локально, нужны именно `permissions` в клиенте (или контейнер/песочница
без локальных файлов). Если клиент не умеет запрещать инструменты, промпт можно
обойти.

Права: агент пишет только в свою папку и в общие отчёты; читать может папки других
агентов и исследовательский архив (кроме `00_ADMIN` и `99_QUARANTINE`). Сейчас MCP
даёт файлы, поиск, отчёты, чат и задачи; произвольный shell/Ghidra/Frida на хосте
не выполняет. Если это нужно — это отдельный runner, а не просто MCP.

## Что внутри

| Папка | Содержимое |
|---|---|
| `00_ADMIN/` | сервер, лаунчер, база, логи, manifest переезда и undo-скрипт |
| `01_REPORTS/` | отчёты, статусы, PDF, заметки для разработчика |
| `02_KERNEL/` | kernelcache, SPTM, KASLR, AMFI, CoreTrust-ядро, kexts, syscall/mach таблицы |
| `03_SANDBOX/` | sandbox, SBX, XPC, сервисы, entitlements, launchd |
| `04_SURFACE_GPU/` | IOSurface, IOGPU, AGX, ANE, медиа/графические парсеры |
| `05_ROOTFS_IPSW/` | rootfs, IPSW-метаданные, AEA, OTA |
| `06_CORETRUST/` | CoreTrust, подписи, Coruna, choma, ClearSword, keychain |
| `07_PRIMITIVES/` | UAF, KRW, leak, physaddr, probe, smith |
| `08_CRASH_LOGS/` | `.ips`, crash-дампы, kdump, memscan |
| `09_TOOLS/` | Ghidra-проекты (`ghidra_projects`), REA, скрипты, venv, opencode-studio, supervisor, `.tools` |
| `10_ARTIFACTS/` | `.gzf`, `.im4p`, `.macho`, `.tar.gz`, `.ipa`, kernelcache |
| `11_MISC/` | разрозненные логи и мелочи |
| `99_QUARANTINE/` | дубликаты и пустые файлы (не удалены безвозвратно) |
| `agents/` | рабочие папки агентов (создаются из панели) |
| `логи работы ИИ/` | общие отчёты агентов |

Установка Ghidra осталась в `./ghidra` (её могут ждать старые скрипты), проекты — в
`09_TOOLS/ghidra_projects`. Исходный `AGENTS.md` перемещён в `00_ADMIN/prompts/`
(в исследовательский архив он не попадает).

Переезд можно откатить: `00_ADMIN/moves_20261103_211355.tsv` и
`00_ADMIN/undo_moves_20261103_211355.sh` (плюс второй манифест для файлов, появившихся
во время уборки).

## REA (reverse engineering agents)

Исходники REA 6.8.0: `09_TOOLS/rea/rea-rea-agents-6.8.0/`.
REA установлена в `~/.local` (`rea --version` → 6.8.0). Локальный MCP REA (stdio)
регистрируется в клиенте на машине исследователя:

```bash
npx -y rea-agents@6.8.0 mcp
```

> Node 26.10 ниже требуемого REA 26.12; `rea --version` работает. Если понадобится
> Frida-часть, переустанови с разрешённым postinstall:
> `npm install -g --prefix ~/.local --allow-scripts=frida rea-agents@6.8.0`.

REA не выставлена наружу как общий сервер: она анализирует локальные бинарники и
требует локальный Ghidra/IDA/Hopper. Артефакты для анализа агент забирает из хаба
через `list_research` / `read_research`.

## Безопасность

- Пароль хранится как scrypt-хеш; API-ключи — как SHA-256, в открытом виде не хранятся.
- Ключ привязан к папке, срок жизни задаётся, отзыв мгновенный.
- Вход ограничен по попыткам; сессии HttpOnly/SameSite, CSRF на изменяющих запросах.
- Публичный доступ — только через `--tunnel` или проброс порта. Если туннель не нужен,
  не запускай с `--tunnel`; сервер всё равно слушает LAN на `0.0.0.0:8080`.
- Перед доступом из интернета смени пароль и не передавай ключи в открытых чатах.
- Резервная копия: `00_ADMIN/hub/data/asuka.db` (ключи/сессии/история). Файлы — в
  `agents/` и `логи работы ИИ/`.

## Остановка / диагностика

```bash
asuka4scape_project --status
asuka4scape_project --stop
tail -f 00_ADMIN/hub/logs/server.log
tail -f 00_ADMIN/hub/logs/tunnel.log
```
