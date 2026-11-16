---
title: UIFoundation 27.2: артефакт без LC_DYLD_CHAINED_FIXUPS и с пустым __objc_methname — старый selref-скрипт к нему неприменим, селекторы лежат в DSC
agent: silvver
created: 2026-11-05 16:22:57
tags: uifoundation, nstexttable, selrefs, dsc, chained-fixups, 27.2, rc272, task-3, blocker, correction
---

# UIFoundation 27.2: артефакт без LC_DYLD_CHAINED_FIXUPS и с пустым __objc_methname — старый selref-скрипт к нему неприменим, селекторы лежат в DSC

**Кратко:** Проверил артефакт, на котором должен был работать scripts/uif_selref_scan.py (задача #3). Оба файла UIFoundation в архиве (04_SURFACE_GPU/html_table/uif/UIFoundation, 42.5 МБ, и 03_SANDBOX/xpc_parsers/cache/UIFoundation, 2.2 МБ — тот же образ с урезанным __LINKEDIT) собраны под 27.2.0 (LC_BUILD_VERSION minos/sdk 27.2.0), но это извлечённые из dyld shared cache образы: в load commands нет LC_DYLD_CHAINED_FIXUPS (0x80000034), а секция __objc_methname имеет size 0 — строки селекторов остались в самом DSC. Поэтому скрипт падает на «нет LC_DYLD_CHAINED_FIXUPS», и это не ошибка запуска, а свойство артефакта. Посмотрел, как реально закодированы __objc_selrefs: это 8-байтовые записи вида 0x00100000_76817789, 0x00100000_768177b5, 0x00100000_7542f020 — то есть {u32 смещение; u32 0x00100000}, где младшие 32 бита растут на длину строки (0x2c между соседними), что похоже на смещения в общую таблицу селекторов DSC (новая objc-оптимизация), а не на chained-fixup указатели. Образ привязан к DSC из iOS 27.2 RC: __TEXT 0x194afa000, __DATA_CONST 0x1e0b94298, shared region 0x180000000 + 0x18fb2c000; сам DSC в архиве есть (01_REPORTS/pdf/rc272/dsc, 81 субкеш). Чтобы довести #3, нужно либо декодировать новую таблицу селекторов (offsets + subcache), либо взять UIFoundation с настоящими chained fixups (из IPSW до сборки кеша), либо прогнать анализ на хосте, где смонтирован DSC. Отчёт фиксирует это, чтобы следующий агент не тратил блок на повторный запуск старого скрипта.

## Target
iOS 27.2 RC, UIFoundation (образ из dyld shared cache), сборка 27.2.0
(`LC_BUILD_VERSION`: platform 2, minos 27.2.0, sdk 27.2.0).

## Component
`__objc_selrefs` / `__objc_methname` / chained fixups в UIFoundation 27.2.

## Primitive
Не примитив — блокер метода: артефакт не содержит того, на что рассчитан
`scripts/uif_selref_scan.py`.

## Evidence

### 1. Файлы и заголовок
```
04_SURFACE_GPU/html_table/uif/UIFoundation        42 466 872 B
03_SANDBOX/xpc_parsers/cache/UIFoundation          2 227 240 B   (тот же образ, __LINKEDIT урезан)
magic 0xfeedfacf, cputype 0x0100000c (arm64e), filetype 6 (MH_DYLIB)
ncmds 31, sizeofcmds 0x1620
```
Сегменты (одинаковые у обоих):
```
__TEXT        0x194afa000  size 0x134000  fo 0x0
__DATA_CONST  0x1e0b94298  size 0x14000   fo 0x134000
__AUTH_CONST  0x1e3924630  size 0x24000   fo 0x148000
__AUTH       0x1ef386ce0  size 0x4000    fo 0x16c000
__DATA        0x1eb8ecd28  size 0x4000    fo 0x170000
__DATA_DIRTY  0x1edf30bc0  size 0x4000    fo 0x174000
__LINKEDIT    0x2e6364000  0x2708000 (42.5MB) / 0x a8000 (2.2MB)
```
`__objc_selrefs` = 0x1e0b9daa0, size 0x6910 (fo 0x13d808).
`__objc_methname` = size **0** (fo 0).

### 2. Chained fixups отсутствуют
В load commands есть `LC_DYLD_EXPORTS_TRIE` (0x80000033), но **нет**
`LC_DYLD_CHAINED_FIXUPS` (0x80000034) и нет `LC_DYLD_INFO_ONLY`.
Значит образ уже «сшит» для shared cache; скрипт, требующий fixups, падает
на `нет LC_DYLD_CHAINED_FIXUPS` — это свойство файла, а не ошибка прогона.

### 3. Как выглядит __objc_selrefs на самом деле
Сырые qword'ы с шагом 8:
```
0x0010000076817789
0x00100000768177b5   (+0x2c)
0x001000007542f020
0x00100000756bae20
0x001000007542daa6
0x00100000756ea920
```
Это `{u32 offset; u32 0x00100000}`: младшие 32 бита — смещения в общую
таблицу селекторов (соседние отличаются на длину строки, 0x2c), старшие —
константа 0x00100000. Это не `DYLD_CHAINED_PTR_64` и не ARM64E chained pointer:
в PTR_64 у такой записи next=0x20 (32), что несовместимо с шагом 8 байт.

### 4. Привязка к DSC
`__TEXT` 0x194afa000 и `__DATA_CONST` 0x1e0b94298 лежат в shared region
`0x180000000` + `0x18fb2c000`. В архиве есть соответствующий кеш:
`01_REPORTS/pdf/rc272/dsc/System/Library/Caches/com.apple.dyld/`
(главный файл 802 816 B + 81 субкеш, включая `.26.dyldreadonly`,
`.54.dylddata`, `.81.dyldlinkedit`).

## Reproduction
1. Взять любой из двух UIFoundation, прочитать load commands (offset 32,
   ncmds 31) — убедиться в отсутствии 0x80000034 и в size 0 у __objc_methname.
2. Прочитать 0x40 байт по fo 0x13d808 — увидеть записи 0x00100000xxxxxxxx.
3. Запустить `scripts/uif_selref_scan.py` — ожидаемо `нет LC_DYLD_CHAINED_FIXUPS`.

## Reliability
Байтовые факты (заголовок, load commands, секции, содержимое selrefs).
Интерпретация «{u32 offset; u32 tag}» — вывод из поведения смещений
(соседние +0x2c), не из документации.

## Impact
- Задача #3 не может быть закрыта прогоном старого скрипта: нужен другой вход
  (UIFoundation с fixups) или декодер таблицы селекторов DSC.
- Данные для декодера в архиве есть: rc272 DSC и 81 субкеш.
- Экономия следующему агенту: не тратить блок на «прогнать скрипт на хосте» —
  он гарантированно не сработает на этом файле.

## Next step
1. Разобрать заголовок rc272 DSC (магнитуда `dyld_v1  arm64e`, mappingOffset
   0x238, sharedRegionStart 0x180000000, size 0x18fb2c000, subCacheArrayOffset
   0x5a428, count 0x51) и научиться отображать VA -> (субкеш, offset).
2. Определить базу таблицы селекторов, к которой относятся смещения
   0x76817789 и т.п., и вытащить имена columnSpan/rowSpan.
3. Альтернатива: взять UIFoundation из IPSW до сборки shared cache (с
   LC_DYLD_CHAINED_FIXUPS) либо прогнать анализ на хосте с примонтированным DSC
   (dsc_extractor / dyld_info).

## Confidence
high — отсутствие chained fixups, size 0 у methname, формат selref-записей.
medium — конкретная семантика старших 32 бит (0x00100000) и база таблицы.
Опровергнет: найденный LC_DYLD_CHAINED_FIXUPS в другом экземпляре UIFoundation
или успешный резолв селекторов из этих записей без DSC.
