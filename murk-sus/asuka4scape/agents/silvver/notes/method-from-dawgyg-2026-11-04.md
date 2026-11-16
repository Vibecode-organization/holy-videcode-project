# Что взял из github.com/dawgyg/AppleResearch (agent_guidance) — 2026-11-04

Просмотрел все 8 файлов в `agent_guidance/`. Ниже — что реально применимо к нашим задачам
(#1 NSHTMLReader, #2 KASLR 27.2), а что мимо.

## Применимо

### 1. RULE ZERO + closure table (CODEX_DEEP_RE_RULES.md, AGENTS.md)
Формулировка, которой не хватало в наших отчётах: наличие одной проверки **не значит**, что
sink безопасен. Для каждого sink (`arr[i]=`, `memcpy`, `free`, `blraa`) нужно перечислить
**все** операнды, попадающие в индекс/длину/указатель, и для каждого назвать конкретную
инструкцию `cmp/b.hs` с адресом.

Проверка на операнде A не ограничивает операнд B того же sink. Классы дыр:
- (a) проверен один операнд, соседний — нет;
- (b) глобальный лимит в проверке vs span записи в sink (разрыв между двумя границами);
- (c) проверка есть на N-1 селекторах/сайтах, на последнем отсутствует;
- (d) underflow в `A - B` (так же эксплуатируемо, как overflow);
- (e) смена ширины/знака между проверкой и использованием (u64→u32, sxtw/uxtw);
- (f) агрегатная проверка суммирует N-1 из N вкладчиков в общий буфер.

Прямо ложится на #1: `rowSpan`/`columnSpan` из HTML проходят `csinc` без верхней границы и
уходят в `NSTextTableBlock` — нам нужно найти sink в раскладке и построить closure table
(какие `cmp` ограничивают row, column, span, stride), а не писать «выглядит ограниченным».

### 2. Physical-host hard lock (AGENTS.md)
Перед любым динамическим запуском на целевом железе требуется явное `go` от владельца и
заранее заявленные: точная команда/бинарь, явно названный таргет, ожидаемый результат и
время, риск (panic/reboot/потеря данных), условие остановки и план восстановления.
Это ровно наш случай с `kaslr_probe_v2.m` на iPhone 14 — полезно оформить запрос на прогон
именно так, а не «запустите плиз».

### 3. Broker-UC sweep (broker_kernel_uc_candidates.md)
Техника: искать root-демон, который сам открывает kernel IOKit user client, недоступный
приложению напрямую (`IOServiceOpen` + `IOConnectCall*` в одном бинаре), и имеет ungated
XPC/MIG-метод, пробрасывающий клиентские селектор/скаляры/структуру в kernel UC.
Метод: launchd-плисты → фильтр по импортам → эвристика гейта (наличие импортов
`audit_token`/`SecTask`/`entitlement`/`euid` = гейт есть) → dataflow клиент→IOConnectCall.

Переносится на iOS, потому что это структурный паттерн, а не macOS-факт. У нас уже есть
половина данных: `03_SANDBOX/svc_map/` (plists, `exe_ents.json` 716 KB, `machlookup_best.json`,
`rows.json`, `table.md`). Не хватает только импортов бинарей — то есть снова нужен прогон
`nm`/`otool` на хосте.

### 4. Escalation template (escalation_results_template.md)
Формат «PRIMITIVE → BOUNDED or FULL-POINTER → STILL PRESENT? (LC_UUID) → ESCALATABLE?
→ WHAT WOULD PROVE IT?». Для #2 это буквально наш критерий: примитив утечки обязан быть
FULL-POINTER (не base+index), а «жив ли» подтверждается сравнением сборок — у нас это уже
сделано (24B115 ≡ 24B119, 0 байт в кодовых сегментах).

## Мимо

- **gemini.md** — macOS 26.5.1, сам автор пишет «несколько месяцев, данные устарели».
  Таргеты (cvmsServ, syspolicyd, fskitd) — macOS, к iOS 27.2 не переносятся.
- **helper_sweep_results.md**, **clocksyncd_effect.md**, **webgpu_audit.md** — конкретные
  macOS-находки (hdiejectd, systemstats, IOTimeSync, WebGPU). Чужие результаты, к нашим
  таргетам не применимы; как образец оформления closure table — полезны, как факты — нет.
- Правило «never touch Braze» и вся инфраструктура tart/VM — личное у автора.

## Что делать с этим (предложение)

1. Взять closure table как обязательный формат для отчётов по #1 и по любому будущему
   memory-sink (в шаблон `create_report` добавить раздел «Closure table»).
2. Оформить запрос на прогон `kaslr_probe_v2.m` по пунктам Physical-host hard lock
   (команда, таргет, риск, стоп-условие).
3. Отдельная задача: broker-UC sweep по iOS 27.2 на базе `03_SANDBOX/svc_map` + прогон
   `nm` по root-демонам (нужен shell на хосте).

Источник: https://github.com/dawgyg/AppleResearch/tree/main/agent_guidance (8 файлов, ~48 KB).
