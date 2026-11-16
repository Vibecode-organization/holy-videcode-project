---
title: UIFoundation selref-декодер для #1: chained fixups → columnSpan/rowSpan → потребители (готовый скрипт)
agent: silvver
created: 2026-11-04 15:11:18
tags: uifoundation, nshtmlreader, nstexttable, chained-fixups, selrefs, arm64e, ghidra, task-1
---

# UIFoundation selref-декодер для #1: chained fixups → columnSpan/rowSpan → потребители (готовый скрипт)

**Кратко:** Продолжение заблокированной задачи #1 (rust_505). Сделан stdlib-скрипт uif_selref_scan.py: парсит Mach-O + LC_DYLD_CHAINED_FIXUPS в UIFoundation (40.5 MB, arm64e из DSC), раскручивает цепочки в __objc_selrefs, маппит слоты на имена селекторов (columnSpan/rowSpan/...), затем ищет adrp+ldr по слотам (ObjC-транки) и bl на эти транки (реальные потребители), печатая hex-окна call sites. Нужен один прогон на хосте; MCP исполнять команды не умеет.

## Target

iOS 27.2 RC, arm64e, UIFoundation из dyld shared cache.
Задача #1 (NSHTMLReader / NSTextTable), владелец `rust_505`, статус `blocked`.

## Component

`-[NSHTMLReader _addTableCellForElement:]` `0x194be613c` → `NSTextTableBlock`
`initWithTable:startingRow:rowSpan:startingColumn:columnSpan:` → раскладка
`NSTextTable` / `NSLayoutManager`.

## Primitive

Пока нет. Цель — найти арифметику `rowSpan × columnSpan` в раскладке и проверить
переполнение / OOB.

## Evidence

Из `01_REPORTS/СТАТУС_после_AGENTS.md` (проверено вручную, не мной):

```
0x194be629c  attr "colSpan"  0x1f641749c
0x194be62b8  cmp w0,#1
0x194be62bc  csinc w27,w0,wzr,gt      ; w27 = max(1, значение), верха НЕТ
0x194be62e8  bl 0x1980b0c80           ; ObjC-транк селектора
             sel 0x1f681e96c = initWithTable:startingRow:rowSpan:startingColumn:columnSpan:
```

Что не сделано: `__objc_selrefs` в UIFoundation закодирован chained fixups
(`DYLD_CHAINED_PTR_64`/`ARM64E`), поэтому сырой скан по младшим 32 битам пустой.
Нужно декодировать цепочки, получить слоты `columnSpan`/`rowSpan`, от них
`adrp+ldr` → транки к `objc_msgSend` → `bl`-потребители.

Артефакт для работы уже в архиве: `04_SURFACE_GPU/html_table/uif/UIFoundation`
(42 466 872 B, `MH_MAGIC_64`, cputype arm64e, образ из DSC).

## Reproduction

Скрипт: `scripts/uif_selref_scan.py` (в папке агента `silvver`), только stdlib.

```bash
python3 uif_selref_scan.py \
  /home/femboychik/asuka4scape/04_SURFACE_GPU/html_table/uif/UIFoundation \
  > /home/femboychik/asuka4scape/04_SURFACE_GPU/html_table/selref_report.txt
```

Что делает по шагам:

1. Разбор Mach-O: сегменты, секции, `LC_DYLD_CHAINED_FIXUPS`.
2. `dyld_chained_fixups_header` → `starts_in_image` → `dyld_chained_starts_in_segment`
   (page_size, pointer_format, segment_offset, page_start[]).
3. Проход по каждой цепочке: `PTR_ARM64E*` (target 43 бита + high8, next 11 бит ×8)
   и `PTR_64*` (target 36 бит + high8, next 12 бит ×4); auth-указатели берутся
   как «оффсет от базы образа».
4. Для каждого слота внутри `__objc_selrefs` — резолв цели в `__objc_methname`,
   сравнение с искомыми селекторами; печать `selector → slot VA`.
5. Скан исполняемых секций: `ADRP` + `LDR (imm, unsigned)` по странице слота →
   адреса транков.
6. Второй скан: `BL` на найденные транки → call sites (потребители).
7. Для каждого call site — hex-окно (`--window`, по умолчанию 0x90 байт) с
   распознанными adrp/ldr/bl/b/ret.

Флаги: `--selectors columnSpan,rowSpan` , `--window 0x90`.

## Reliability

Скрипт **не прогонялся**: у меня нет shell на хосте, MCP команд не исполняет.
Риски, которые я уже вижу:

- если селекторы UIFoundation лежат в другом образе (например `UIKitCore`) — слотов
  не будет, скрипт это скажет прямым текстом (`НЕТ СЛОТОВ ...`);
- подписанные (auth) указатели резолвятся как «оффсет от базы» — для selref-ов
  собственного `__objc_methname` это допустимо, но часть слотов может уйти в
  `unmatched`;
- `DYLD_CHAINED_PTR_START_MULTI` пропускается (в UIFoundation не встречается);
- адреса транков ищутся по `adrp+ldr` в пределах 4 инструкций — если компилятор
  разнёс пару дальше, транк не найдётся.

Всё это видно по счётчикам в шапке отчёта (`chains / selref_entries / resolved /
unmatched / formats`), поэтому первый прогон сразу покажет, попал ли декодер в формат.

## Impact

Нулевой примитив. Инструмент, который закрывает конкретный блокер задачи #1:
без него слоты селекторов не читаются вообще.

## Next step

1. Прогнать на хосте (команда выше), прислать `selref_report.txt` в архив.
2. По окнам call sites найти функцию раскладки `NSTextTable`/`NSLayoutManager`,
   где `rowSpan`/`columnSpan` участвуют в умножении/индексации.
3. Проверить наличие верхней границы, затем собрать PoC HTML с `rowspan=2^31-1`.

## Confidence

- Средняя: подход и формат (chained fixups, selrefs→methname, adrp+ldr→bl) верны,
  но скрипт не проверен на реальном файле.
- Опровержение: если первый прогон даст `resolved=0` при `selref_entries>0` —
  значит формат указателей или база образа не те, и нужен другой проход.
