# UIFoundation 27.2 / selref'ы: что на самом деле в артефакте (2026-11-05)

## Файлы
- `04_SURFACE_GPU/html_table/uif/UIFoundation` — 42 466 872 B, полный __LINKEDIT.
- `03_SANDBOX/xpc_parsers/cache/UIFoundation` — 2 227 240 B, тот же образ,
  __LINKEDIT урезан до 0xa8000 (годится для кода/данных, не для символов).

## Заголовок
arm64e (cputype 0x0100000c), MH_DYLIB, 27 LC_SEGMENT_64 + 31 команда,
LC_BUILD_VERSION minos/sdk 27.2.0.
```
__TEXT        0x194afa000  0x134000  fo 0
__DATA_CONST  0x1e0b94298  0x14000   fo 0x134000
__AUTH_CONST  0x1e3924630  0x24000   fo 0x148000
__AUTH       0x1ef386ce0  0x4000    fo 0x16c000
__DATA        0x1eb8ecd28  0x4000    fo 0x170000
__DATA_DIRTY  0x1edf30bc0  0x4000    fo 0x174000
__LINKEDIT    0x2e6364000  0x2708000 (полный)
```
`__objc_selrefs` 0x1e0b9daa0 size 0x6910 fo 0x13d808.
`__objc_methname` size 0 — строки селекторов в DSC.

## Главное
1. **Нет LC_DYLD_CHAINED_FIXUPS** (0x80000034). Есть LC_DYLD_EXPORTS_TRIE
   (0x80000033). Скрипт `uif_selref_scan.py` на этом файле падает по определению.
2. `__objc_selrefs` — 8-байтовые записи `0x00100000_XXXXXXXX`, где
   младшие 32 бита растут на длину строки (0x2c между соседними), старшие —
   константа 0x00100000. Похоже на смещения в общую таблицу селекторов DSC
   (новая objc-оптимизация), а не на chained pointers.
3. Образ привязан к rc272 DSC: shared region 0x180000000 + 0x18fb2c000.
   Кеш в архиве: `01_REPORTS/pdf/rc272/dsc/System/Library/Caches/com.apple.dyld/`
   (главный файл 802 816 B, 81 субкеш, у главного mappingOffset 0x238,
   subCacheArrayOffset 0x5a428, count 0x51).

## Следующий шаг для #3
1. По заголовку главного кеша и заголовкам субкешей построить VA -> (файл, offset).
2. Найти базу таблицы, к которой относятся смещения 0x76817789 и т.п.,
   вытащить имена columnSpan/rowSpan.
3. Либо взять UIFoundation из IPSW до сборки shared cache (с chained fixups)
   или прогнать dsc_extractor/dyld_info на хосте с DSC.
