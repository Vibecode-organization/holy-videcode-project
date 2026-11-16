---
title: Селекторы UIFoundation 27.2: формат rc272 DSC декодирован, 3362 selref резолвятся; найдены слоты table/rowSpan/columnSpan/startingRow/startingColumn и property-list NSTextTableBlock
agent: silvver
created: 2026-11-06 18:11:28
tags: uifoundation, dsc, selrefs, objc, 27.2, rc272, task-3, nstexttable, tool
---

# Селекторы UIFoundation 27.2: формат rc272 DSC декодирован, 3362 selref резолвятся; найдены слоты table/rowSpan/columnSpan/startingRow/startingColumn и property-list NSTextTableBlock

**Кратко:** Отчёт id 19 закрывал метод как заблокированный: образы UIFoundation из DSC 27.2 не имеют LC_DYLD_CHAINED_FIXUPS и у них пустой __objc_methname, поэтому старый selref-скрипт падал. Формат декодирован: 8-байтный selref = {u32 смещение от sharedRegionStart; u32 тег 0x00100000}, а не указатель. Резолвер по главному заголовку DSC (subCacheArray, 81 запись по 56 байт: uuid16 + vmOffset + suffix32) и таблице маппингов субкеша даёт имя селектора. Проверено на трёх независимых видах ссылок (selref -> строка, classlist -> class_t, in-image PAC-указатели -> низкие 32 бита + 0x180000000). Для UIFoundation: все 3362 selref резолвятся в одну 20-МБ строковую область 0x753F6A2F..0x76822308 (субкеш .26.dyldreadonly); найдены точные слоты table/rowSpan/columnSpan/startingRow/startingColumn; рядом лежит property_list_t (0x1e39324f0, entsize 0x10, count 5) класса NSTextTableBlock с теми же именами; в __cstring — кодировки "@IIII" и "II" и имена иваров NSTable/NSRowNum/NSColNum/NSRowSpan/NSColSpan. Инструмент: scripts/dsc_selref.py. Потребители rowSpan/columnSpan внутри UIFoundation пока не локализованы: method-list в этой сборке использует «direct selector» форму, которую ещё нужно декодировать.

## Target

- Сборка: iOS 27.2 RC, **24B115** (артефакты сняты с rc272), arm64e.
- Артефакты в архиве:
  - `04_SURFACE_GPU/html_table/uif/UIFoundation` — 42 466 872 B, Mach-O arm64e, извлечён из DSC;
  - `01_REPORTS/pdf/rc272/dsc/System/Library/Caches/com.apple.dyld/dyld_shared_cache_arm64e` — главный файл 802 816 B + 81 субкеш.
- Контекст: отчёт id 19 (blocked task #3). Цель этого блока — снять блокер метода, а не доказать уязвимость.

## Component

UIFoundation, objc-метаданные в dyld shared cache: `__objc_selrefs`, `__objc_classlist`, `__objc_const`, `__objc_methlist`, `__cstring`.
Классы по теме: `NSTextTable`, `NSTextTableBlock`, `NSHTMLReader`.

## Primitive

Не примитив. Результат — **декодер формата** и точные адреса, которые разблокируют статический анализ #3.

## Evidence

### 1. Формат указателей в rc272 DSC

8-байтное значение:

```
bits 63..32 = тег (0x00100000 = ссылка на objc-строку в shared region)
bits 31..0  = смещение от sharedRegionStart (0x180000000)
```

Проверки, на которых формат подтверждён:

| источник | значение | резолв |
|---|---|---|
| `__objc_selrefs[?]` | `0x00100000_76817789` | `0x1f6817789` → `"_appendTemporaryExclusionPathsForRects_iOS:"`, далее `"_appendTextContainer"`, `"applicationFrameworkContext"` |
| `__objc_classlist[0]` | `0x00100000_6f387e88` | `0x1ef387e88` → class_t: isa `0x1ef387e60`, superclass `0x1edf31610`, data → `0x1e39324f0` |
| in-image PAC-указатель | `0x801d87e0_639324f0` | низкие 32 бита + 0x180000000 = `0x1e39324f0` |

То есть тег в старшей половине — не PAC, а маркер таблицы; PAC-подпись встречается только у настоящих указателей внутри образа (class_t/isa), и там работает то же правило «низкие 32 бита + база».

### 2. Как резолвить (алгоритм)

1. Главный заголовок `dyld_cache_header`: `sharedRegionStart` (+0xE0) = `0x180000000`, `sharedRegionSize` (+0xE8) = `0x18fb2c000`.
2. `subCacheArrayOffset` (+0x188) = `0x5a428`, `subCacheArrayCount` (+0x18C) = 81.
   Запись субкеша — **56 байт**: `uuid[16]`, `cacheVMOffset u64`, `fileSuffix[32]` (`.01`, `.02`, …, `.26.dyldreadonly`, …).
   *(В отчёте id 19 предполагалось 24 байта; фактически 56 — это важно, иначе массив разъезжается.)*
3. Для нужного смещения находим субкеш, чей `[vmOffset, next)` его покрывает, читаем заголовок этого субкеша, берём его `mappingOffset/mappingCount` (32-байтные записи `{va, size, fileoff, maxprot, initprot, pad}`), переводим `va → fileoff`.
4. Читаем C-строку.

### 3. UIFoundation: статистика selrefs

```
section __objc_selrefs: addr=0x1e0b9daa0 size=0x6910 (3362 записи), fileoff=0x13d808
тег 0x00100000: 3360 записей, тег 0: 2 (нулевые слоты)
диапазон смещений: 0x753f6a2f .. 0x76822308  (≈20 МБ, все в .26.dyldreadonly)
```

Точные слоты (после резолва строк):

| селектор | slot VA | значение selref |
|---|---|---|
| `table` | `0x1e0ba2660` | `0x7551aca0` |
| `rowSpan` | `0x1e0ba17b8` | `0x764172e0` |
| `columnSpan` | `0x1e0b9f5e0` | `0x76417e3b` |
| `startingRow` | `0x1e0ba2478` | `0x768216f1` |
| `startingColumn` | `0x1e0ba2468` | `0x768216cf` |

Соседние варианты строк (тоже в области): `rowSpan:colSpan:` @ `0x76418c80`, `rowSpan:startingColumn:columnSpan:` @ `0x7681e986`, `columnSpan:` @ `0x7681e99d`, `setRowSpan:` @ `0x7641a9e8` / `0x7681b04e`, `setColumnSpan:` @ `0x7641a4a3` / `0x76816c70`.

### 4. Класс NSTextTableBlock: property-list найден по содержимому

В `__AUTH_CONST __objc_const` лежит `property_list_t`:

```
VA 0x1e39324f0
+0x00: entsize = 0x10, count = 5
+0x08: name "table"          attributes 0x78bea56c
+0x18: name "startingRow"    attributes 0x78942a64
+0x28: name "rowSpan"        attributes 0x78942a64
+0x38: name "startingColumn" attributes 0x78942a64
+0x48: name "columnSpan"     attributes 0x78942a64
```

Это ровно набор свойств `NSTextTableBlock` и одновременно подтверждение, что найденные селекторы относятся к нему.

### 5. Ивары и кодировки типов

В `__TEXT __cstring` непосредственно перед диагностикой NSTextTable идут строки:

```
"@IIII"  "NSTable" "NSRowNum" "NSColNum" "NSRowSpan" "NSColSpan" "NSTextTableBlock"
"II"     "NSNumCols" "NSTableFlags" "NSTextTable"
```

- `@IIII` — тип метода вида `initWithTable:startingRow:rowSpan:startingColumn:columnSpan:` (объект + 4 unsigned int);
- `II` — тип сеттера (`void setX:(unsigned int)`);
- `NSTable/NSRowNum/NSColNum/NSRowSpan/NSColSpan` — имена иваров блока;
- `NSNumCols/NSTableFlags` — ивары `NSTextTable`.

Плюс тривиальные геттеры в `__text` (шаблон `ldr w0,[x0,#imm]; ret`):

```
0x10 -> 0x194bf2d4c
0x14 -> 0x194bf2db0
0x18 -> 0x194ba47b8
```

Геттера `ldr w0,[x0,#0x1c]` в образе **нет** — то есть четвёртое u32-поле (ожидаемый `columnSpan`) не лежит простым полем по 0x1c; это отдельный вопрос (битовое поле/другая раскладка/иной геттер).

### 6. Что НЕ получилось (честно)

- Прямой скан `adrp+ldr` по `__text` находит 2382 `adrp` на страницы selrefs, но ни одного попадания именно в 5 найденных слотов. Это не доказательство отсутствия обращений: в этой сборке загрузка SEL идёт не тем шаблоном, который отслеживает сканер (возможны register-offset `ldr` или иная схема). Вывод «UIFoundation не шлёт себе rowSpan» делать нельзя.
- `__objc_methlist` (0x194c05f80, 0xbbd4) читается как relative method list: заголовок `entsizeAndFlags=0xe000000f` (entsize 12, flags 3), дальше пары «8-байтный заголовок + count + 12-байтные записи». **imp-смещения работают** (проверено: imp попадает в `__text` на `add/ldr/ret`-геттер), а name-смещения в этом образе не указывают на строки: значения вида `0x28fb4` ведут в код субкеша .05, а не в строковую таблицу. Похоже на новую «direct selector» форму, где name — индекс в отдельной таблице (в `dyld_cache_objc_opt` по смещению `0x753ccaa0`, size 0x88, версия 4). Это следующий шаг.

## Reproduction

```
# 1) выгрузить главный заголовок и subCacheArray (по 0x5a428)
# 2) найти субкеш для смещения, прочитать его mapping table
# 3) разобрать __objc_selrefs образа
python3 scripts/dsc_selref.py <dsc_dir> UIFoundation --find rowSpan
#   rowSpan   slot=0x1e0ba17b8   sel=0x764172e0
python3 scripts/dsc_selref.py <dsc_dir> UIFoundation --dump 10
```

Скрипт: `agents/silvver/scripts/dsc_selref.py` (stdlib, без capstone). Работает на любом образе из этого DSC, не только на UIFoundation.

## Reliability

- Формат подтверждён на трёх независимых типах ссылок (selref, classlist, PAC-указатель образа), плюс 8 вручную сверенных строк.
- Резолвер детерминирован; повторные прогоны дают те же 5 слотов.
- Не проверено: субкеши с суффиксами `:com.apple.ResourceFork`/`.dyldlinkedit` (там строк нет) и образы, собранные до 27.x (там старый формат chained fixups).

## Impact

Снимает блокер #3 в части «как вообще читать селекторы в 27.2»: теперь можно резолвить любые selref-слоты любого образа из rc272 DSC и получать имена. Дополнительно получены: property-list NSTextTableBlock (порядок и имена свойств), имена иваров и кодировки типов, три геттера u32-полей.

## Next step

1. Разобрать `dyld_cache_objc_opt` (0x753ccaa0, 0x88 байт) и найти таблицу, в которую индексируют name-поля method list (значение `0x28fb4`). После этого — получить список методов `NSTextTableBlock`/`NSTextTable` с именами и imp-адресами.
2. По imp-адресам сеттеров `setRowSpan:`/`setColumnSpan:` и по геттерам `0x194bf2d4c/0x194bf2db0/0x194ba47b8` найти потребителей в раскладке `NSTextTable` и проверить арифметику на переполнение/выход за границу (гипотеза #3: произвольные rowSpan/columnSpan из HTML).
3. Параллельно — вход со стороны парсера: `NSHTMLReader` и ключи `rowspan`/`colspan`; в `__cstring` уже видны `NSTable/NSRowNum/NSColNum/NSRowSpan/NSColSpan`.

## Confidence

- Формат selrefs и резолвер: **high**.
- Принадлежность property-list и слотов к NSTextTableBlock: **high**.
- Раскладка иваров (4 u32, columnSpan не по 0x1c): **medium** — тип `@IIII` это подтверждает, но конкретные смещения не доказаны.
- Потребители rowSpan/columnSpan и наличие OOB: **not established**.
