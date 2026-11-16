# KRWProbe 1.1 / 1.2 — MUTATE и HARD

Статус: собрано (`v1.2`, build 12), IPA лежит в
`probe/out/KRWProbe.ipa`. На устройстве в этой сессии не запускалось,
поэтому реальных кодов возврата и паник ниже нет — только описание
реализованных режимов, точных форм вызовов и проверка сборки.

Изменения только в `probe/KRWProbe/main.m` и `probe/KRWProbe/Info.plist`.
`reports/DISPATCHER_RE.md` не менялся.

---

## v1.1 — MUTATE (structured mutation fuzzer)

Добавлены кнопки **MUTATE 100k** (по умолчанию) и **MUTATE 200k**. Обе
работают через уже проверенный прямой путь:

```
IOServiceOpen("IOSurfaceRoot")
IOConnectCallMethod(conn, 0,
                    scalarIn = {0}, 1,        // parent id 0, hi32 = 0
                    structIn = XML plist + '\0',
                    structOut = 0xc68)
```

Перед каждым вызовом в `NSTemporaryDirectory()/last_config.xml` пишется
полный XML и номер итерации (комментарий после `</plist>`), поэтому после
паники остаётся точный вход. Успехом считается `kr == KERN_SUCCESS`;
id берётся из `info+0x18` (`IOSurfaceInfo`).

### Базовая конфигурация

Верхний уровень — ровно четыре рабочих ключа v1.0:

```xml
<key>IOSurfaceWidth</key><integer>64</integer>
<key>IOSurfaceHeight</key><integer>64</integer>
<key>IOSurfaceBytesPerElement</key><integer>4</integer>
<key>IOSurfacePixelFormat</key><integer>1111970369</integer> <!-- 0x42475241 'BGRA' -->
```

Плюс один plane через `IOSurfacePlaneInfo`:

```xml
<key>IOSurfacePlaneInfo</key><array><dict>
  <key>IOSurfacePlaneWidth</key><integer>64</integer>
  <key>IOSurfacePlaneHeight</key><integer>64</integer>
  <key>IOSurfacePlaneBytesPerElement</key><integer>4</integer>
  <key>IOSurfacePlaneBytesPerRow</key><integer>256</integer>

  <!-- неактивный AGX-совместимый compressed-baseline: -->
  <key>IOSurfacePlaneDataRegionBytesPerSlice</key><integer>16384</integer>
  <key>IOSurfacePlaneHeaderRegionBytesPerSlice</key><integer>0</integer>
  <key>IOSurfacePlaneCompressedTileWidth</key><integer>32</integer>
  <key>IOSurfacePlaneCompressedTileHeight</key><integer>32</integer>
  <key>IOSurfacePlaneBytesPerCompressedTileHeader</key><integer>8</integer>
  <key>IOSurfacePlaneBytesPerTileData</key><integer>4096</integer>
  <key>IOSurfacePlaneWidthInCompressedTiles</key><integer>2</integer>
  <key>IOSurfacePlaneHeightInCompressedTiles</key><integer>2</integer>
  <key>IOSurfacePlaneBytesPerRowOfTileData</key><integer>8192</integer>
  <key>IOSurfacePlaneCompressedTileHeaderRegionOffset</key><integer>16384</integer>
  <key>IOSurfacePlaneCompressedTileDataRegionOffset</key><integer>0</integer>
  <key>IOSurfacePlaneHTPCPredictionSelector</key><integer>0</integer>
  <key>IOSurfacePlaneHTPCVerticalHeaderGroupingMode</key><integer>0</integer>
</dict></array>
```

В MUTATE ключ `IOSurfacePlaneCompressionType` в базе **отсутствует**, поэтому
весь compressed-блок ядра пропускается, а база остаётся обычной рабочей
поверхностью. Если мутация добавляет compression type, заранее заданные
поля образуют валидный AGX-baseline (type 4: tile 32×32, 2×2 tiles,
8-байтные заголовки, 16 KiB data region).

### Что мутируется

За итерацию выбирается 1–3 различных поля из 17:

```
IOSurfacePlaneCompressionType
IOSurfaceSliceCount
IOSurfacePlaneDataRegionBytesPerSlice
IOSurfacePlaneHeaderRegionBytesPerSlice
IOSurfacePlaneCompressedTileWidth
IOSurfacePlaneCompressedTileHeight
IOSurfacePlaneBytesPerCompressedTileHeader
IOSurfacePlaneBytesPerTileData
IOSurfacePlaneWidthInCompressedTiles
IOSurfacePlaneHeightInCompressedTiles
IOSurfacePlaneBytesPerRowOfTileData
IOSurfacePlaneCompressedTileHeaderRegionOffset
IOSurfacePlaneCompressedTileDataRegionOffset
IOSurfacePlaneHTPCPredictionSelector
IOSurfacePlaneHTPCVerticalHeaderGroupingMode
IOSurfaceBitsPerBlock
IOSurfaceAllocSize
```

`IOSurfaceSliceCount`, `IOSurfaceBitsPerBlock` и `IOSurfaceAllocSize` —
верхнеуровневые ключи; остальные — в plane-словаре.

Значения: boundary set

```
0,1,2,3,4,7,8,15,16,31,32,63,64,127,128,255,256,511,512,1023,
4096,65535,65536,0x40000000,0x80000000,0xffffffff
```

плюс small random (`0..4096` или `0..65536`) в 30% случаев. В 2/3 итераций
`IOSurfacePlaneCompressionType` принудительно входит в набор мутаций и в
70% таких случаев получает 2/3/4 — иначе большинство мутаций compressed-
полей не доходило бы до кода (без type ядро их игнорирует).

### Память/соединения

`sel 1` (release по id) на устройстве возвращает `0xe00002c2`, поэтому
MUTATE пересоздаёт соединение каждые 64 итерации: `IOServiceClose` освобождает
поверхности, принадлежащие клиенту. Иначе 100k успешных 64×64 BGRA-созданий
(16 KiB каждое) съели бы больше гигабайта.

Логи: каждые 1000 итераций строка
`MUTATE i/iters created=… last_kr=0x… id=… nmut=… conn_gen=…`;
в конце — `=== MUTATE done: calls, created, %, reconnects, last_kr ===`.

---

## v1.2 — HARD (matrix + struct shapes + race)

Добавлена кнопка **HARD (matrix + struct shapes + 30s race)**. Режим
последовательный: geometry → struct → race; `STOP` прерывает между
вызовами. В конце всегда пишется `--- HARD done ---`.

### 1. Geometry matrix

База — та же 64×64 BGRA-поверхность с одним plane, но с **активным**
`IOSurfacePlaneCompressionType = 4` и полным AGX-baseline (см. выше),
поэтому каждая точка матрицы реально доходит до compressed-plane парсера.

Три прохода:

| проход | что перебирается | вызовов |
|---|---|---:|
| singles | каждое поле по boundary set; CT отдельно 0..5 | 422 |
| CT-pairs | CT (0..5) × каждое из 16 остальных полей × 26 значений | 2 496 |
| selected pairs | 9 выбранных пар × 26 × 26 | 6 084 |
| **итого** | | **9 002** |

Singles: 6 значений CT + 16 полей × 26 = 422. CT-pairs: 16 × 6 × 26 = 2 496.
Selected pairs:

```
TileW × TileH
TilesW × TilesH
DataSlice × SliceCount
HdrSlice × SliceCount
HdrOff × DataOff
TileBytes × TileBPR
TileW × HeaderBytes
TilesW × TileBPR
HTPCPred × HTPCGroup
```

Перед каждым `sel 0` пишутся:
`last_config.xml` (точный XML + `<!-- HARD geometry … -->`) и
`last_action.json` (selector 0, scalarIn `[0]`, размер structIn, 0xc68,
какие поля и значения). Прогресс — каждые 100 вызовов. Соединение
геометрии пересоздаётся каждые 256 созданий; в конце — суммарный
`created`.

### 2. Struct-shape abuse

Создаётся одна обычная поверхность через `sel 0`, затем для каждого
селектора из `{2,3,9,10,11}` перебираются:

- `structInSize`: `0, 1, 4, 8, 0xb, 0xc` и `0xd … 0x200` (506 значений);
- `scalarInputCount`: `0,1,2,3,4`; скаляры `{surface_id,0,0,0}`;
- plausible prefix: первые 4 байта — surface id; для `sel 9` с offset
  `0xc` копируется префикс XML `[value,key]`; для `sel 10/11` — C-строка
  `HARDKey\0`; остаток заполнен нулями;
- `structOut`: `sel 2` — 0xc68, `sel 3/9/11` — 4, `sel 10` — 0x800.

Итого `5 × 506 × 5 = 12 650` вызовов. Логируется **каждый** результат,
у которого `kr != 0xe00002c2` (то есть запрос дошёл до handler'а), с
`outSize` и `kr`. Выход сканируется на 64-битные kernel-like указатели
(`v >= 0xffff000000000000`, кроме `0xffffffffffffffff`); при попадании
печатается offset, значение и hexdump первых 0x80 байт.

Перед каждым вызовом `last_action.json` содержит selector, scalarCount,
все четыре скаляра, `structInBytes`, `structOutBytes` и полный `inHex`
входа (до 0x200 байт).

### 3. Race, 30 секунд

Одна поверхность создаётся через `sel 0`. Затем 6 потоков:

- 3 потока — `sel 9` (set `HARDKey` со значением 0/1/…/0xffffffff),
  `sel 10` (get того же ключа), `sel 11` (remove);
- 2 потока — `sel 2` (flags 0..7, structOut 0xc68) и `sel 3` (arg 0/1,
  structOut 4);
- 1 поток — churn: `IOSurfaceCreate` + `CFRelease` 64×64 BGRA.

Churn использует публичный framework, потому что `sel 1` на устройстве
возвращает `0xe00002c2` (release по id не работает). Это даёт реальное
создание/освобождение поверхностей параллельно с raw-вызовами.

Перед каждым вызовом обновляется `last_action.json` (selector, counts,
скаляры, размеры, key/value/flags/arg). В конце:

```
[HARD] race summary: set=… get=… remove=… use2=… use3=… churn=… churn_fail=…
[HARD] race errors: sel9=… sel10=… sel11=… sel2=… sel3=…;
                    kernel_like_ptr_hits=… first_ptr=0x… (sel=…)
```

---

## Раскладка UI и версия

Все прежние кнопки сохранены. Экран теперь 6 рядов:

```
RUN SAFE            | AGGR
FUZZ 50k            | STOP
RACE 30s            | FUZZ UC
SCAN SEL            | CREATE sel0 chain
MUTATE 100k         | MUTATE 200k
HARD (matrix + struct shapes + 30s race)          [full width]
```

- `Info.plist`: `CFBundleShortVersionString = 1.2`, `CFBundleVersion = 12`,
  `CFBundleDisplayName = KRWProbe 1.2`.
- `main.m`: заголовок, баннеры CREATE/MUTATE/HARD и стартовый текст —
  `KRWProbe 1.2`.

## Сборка и проверка

Theos не принимает путь с пробелами, поэтому проект собран из
`/tmp/opencode/krwprobe`:

```
make ipa
cp KRWProbe.ipa probe/out/KRWProbe.ipa
```

Артефакт: `probe/out/KRWProbe.ipa`, **36 634 байта**.

```
Payload/KRWProbe.app/KRWProbe     140 912 байт, Mach-O 64-bit arm64
Payload/KRWProbe.app/Info.plist   CFBundleShortVersionString = 1.2
```

Проверено:

- `LC_BUILD_VERSION`: platform `ios`, minos `14.0`, sdk `14.0`;
- `LC_CODE_SIGNATURE` присутствует, ad-hoc подпись `ldid` с пустым
  `entitlements.plist`;
- в бинарнике есть строки `=== KRWProbe 1.2 HARD ===`,
  `--- HARD done ---`, `last_action.json`, `MUTATE 100k`, `MUTATE 200k`
  и полный текст кнопки HARD;
- Info.plist внутри IPA — 1.2 / 12.

## Ограничения и риски

- Реального запуска на iPhone в этой сессии не было: коды `kr`, счётчики
  `created` и возможные паники появятся только на устройстве.
- HARD geometry намеренно включает `IOSurfaceAllocSize` со значениями
  `0x40000000/0x80000000/0xffffffff` и агрессивные compressed-конфиги;
  возможен kernel panic или jetsam. Это ожидаемое поведение режима.
- Валидность AGX-baseline выведена из декомпиляции
  `dumps/ios272/fn_fffffff009c1af14.c` (tile-геометрия, регионы, проверки
  `BytesPerCompressedTileHeader`, `WidthInCompressedTiles` и т.д.).
  Если на устройстве baseline отвергается, geometry всё равно пройдёт
  весь boundary-набор — просто больше вызовов вернут ошибку.
- `sel 1` по-прежнему не работает (`0xe00002c2`); освобождение делается
  закрытием клиентского соединения / `CFRelease` в churn-потоке.

---

# v1.3 — фикс падения HARD + лог на каждый запуск

Статус: собрано (`v1.3`, build 13), IPA лежит в
`probe/out/KRWProbe.ipa`. На устройстве в этой сессии не запускалось —
проверена только сборка и содержимое бинарника.

## Что было в присланном логе

`logs by me/текст (2).txt` — это лог **v1.1**, не v1.2: он начинается с
`=== KRWProbe 1.1 ===` и заканчивается
`=== MUTATE done: 200000 calls ... ===`. Секции HARD в нём нет вообще
(в v1.1 такой кнопки не было), поэтому файл не показывает точку падения
v1.2. В v1.2 лог вообще не сбрасывался на диск: `L()` писал только в
`NSMutableString` и UITextView, так что после падения процесса от HARD не
оставалось ни одной строки — именно поэтому в v1.3 появился `run.log`.

## Причина падения (по коду v1.2)

Точную строку без устройства и крэш-репорта не назвать, но в HARD есть
четыре независимых дефекта, каждого достаточно для убийства процесса:

1. **Гонка на `NSMutableString gLog`.** `L()` дописывал и обрезал строку
   в рабочем потоке HARD, а главный поток в это же время выполнял
   `gView.text = gLog` и `scrollRangeToVisible(NSMakeRange(gLog.length-1, 1))`.
   `UITextView.text` копирует строку — то есть main читал мутируемый
   буфер; длина для range тоже бралась из мутируемой строки и могла
   оказаться больше текста, который уже скопирован. Это классический
   `EXC_BAD_ACCESS` / `NSRangeException` в `objc_msgSend`/CFString.
   В MUTATE линий мало (200 на 200k итераций), поэтому там не падало;
   HARD geometry/struct пишет гораздо чаще.

2. **Неограниченный поток UI-обновлений.** `hard_struct_shapes` логировал
   каждый вызов с `kr != 0xe00002c2` — до ~12 650 строк, и на каждую
   ставился блок в main queue, копирующий весь лог (до 200 КБ) в
   `UITextView`. Очередь и пиковая память растут быстрее, чем main
   успевает рендерить; итог — jetsam/watchdog, то есть процесс умирает
   без строчки в логе. Плюс `hard_hex`/`hexdump_lines` не ограничивали
   длину.

3. **Use-after-free при таймауте.** `hard_race` ждал
   `dispatch_group_wait(..., FOREVER)`, а `race_loop` — всего 3 секунды,
   после чего делал `CFRelease(s)`/`IOServiceClose(conn)`; если поток ещё
   сидел в `IOSurfaceSetValue`/`IOConnectCallMethod`, он работал с уже
   освобождённым объектом. `HardRaceStats` в `hard_race` лежал на стеке.

4. **Буферы без явной ёмкости.** `structOut` для sel 2 — ровно
   `IOSURFACE_INFO_SIZE = 0xc68`; в v1.2 размеры передавались как
   `sizeof`/константы в разных местах, без единой проверки «cap ≤ буфер».
   Плюс `snprintf` в `hard_race_set` не клампился, а `last_config.xml`
   читался в `run_safe` целиком без предела.

## Что изменено в v1.3

### Логирование и UI

- `gLog` защищён `NSLock`; append/trim и запись в файл — под одним
  локом. Главный поток получает только **immutable copy**.
- UI-обновления схлопываются: одновременно в main queue не больше одного
  блока; `scrollRangeToVisible` считается от `gView.text.length`, а не от
  живой `gLog`.
- Лог ограничен 128 КБ (хранится последние 64 КБ), `hexdump_lines` — 512
  байт, `hard_hex` — 512 байт.
- В struct-фазе детальные строки ограничены 300 на селектор (+ до 400
  строк с pointer-хитами); остальное считается в
  `suppressed_detail_lines`.

### Маркер фазы

- Сверху экрана жёлтый `UILabel`, обновляется **до** начала фазы
  (`set_phase()` делает `dispatch_sync` в main, затем пишет
  `last_phase.txt` и строку `[PHASE] ...` в `run.log`).
- Фазы HARD: `HARD: start` → `HARD/geom singles|ct-pairs|pairs` (с
  индексом каждые 100 вызовов) → `HARD/struct setup` → `HARD/struct sel N
  size X/Y` → `HARD/race` → `HARD: done`. Маркеры также добавлены в
  SAFE/AGGR/FUZZ/MUTATE/CREATE/SCAN/UC/RACE; STOP маркер не меняет.
- Если процесс умрёт, на экране и в `last_phase.txt` останется последняя
  фаза, а `last_action.json`/`last_config.xml` — точный вызов.

### HARD: буферы и гонки

- Все рабочие буферы HARD — heap, выделяются один раз:
  `HARD_OUT_CAP = 0x1000` (≥ 0xc68), `HARD_IN_CAP = 0x200`,
  `_Static_assert` проверяет `HARD_OUT_CAP >= IOSURFACE_INFO_SIZE`.
- `hard_sel0_buf()` принимает буфер и ёмкость, передаёт в ядро
  `min(cap, 0xc68)` и читает id только если ядро вернуло ≥ 0x1c байт.
- `structIn` клампится до 0x200, `structOut` — до ёмкости; `memcpy`
  ограничены `room`; XML — до 0x1000; `snprintf`-результат в
  `hard_race_set` клампится.
- `hard_geom_one` получил `@autoreleasepool` на вызов (9000 вызовов не
  копят NSString).
- `hard_race`: статистика и выходные буферы — heap; ожидание группы
  ограничено 60 с; при таймауте соединение и статистика **не**
  освобождаются (потоки могут быть в syscall). `race_loop` при таймауте
  не делает `CFRelease` под живыми читателями.
- `last_action.json` в race-фазе пишется не чаще 20 раз/с (раньше шесть
  потоков держали NSLock на атомарных записях); в geometry/struct —
  перед каждым вызовом, как и раньше.
- `probe_create`, `mutate_loop`, `scan_selectors`, `uc_fuzz` получили
  проверки `calloc`, клампы длин и `gStop` в скане.

### Лог на каждый запуск

- В `main()` до `UIApplicationMain` вызывается `run_setup()`:
  `<Documents>/KRWProbe-yyyyMMdd-HHmmss/`
  (при коллизии имени добавляется `-pid`).
- В папке сразу создаются:
  - `run.log` — каждая строка, `fflush` после каждой; переживает падение
    процесса;
  - `last_config.xml` — baseline, затем XML перед каждым sel 0;
  - `last_action.json` — `{"mode":"idle"}` до первого действия, затем
    последний вызов;
  - дополнительно `last_phase.txt` — последняя фаза.
- Полный путь показан в UI под маркером фазы (monospace 8 pt, 2 строки,
  перенос по символам) и пишется в `run.log` первыми строками.

### Версия и сборка

- `Info.plist`: `CFBundleShortVersionString = 1.3`, `CFBundleVersion = 13`,
  `CFBundleDisplayName = KRWProbe 1.3`.
- `main.m`: заголовок и баннеры CREATE/MUTATE/HARD — 1.3.
- `Makefile`: добавлены `-fstack-protector-strong -fno-omit-frame-pointer`.
- Все прежние кнопки сохранены (11 штук, включая HARD Full width).

## Проверка артефакта

Собрано из `/tmp/opencode/krwprobe` (путь с пробелами Theos не любит):

```
make ipa
cp KRWProbe.ipa probe/out/KRWProbe.ipa
```

Артефакт: `probe/out/KRWProbe.ipa`, **44 035 байт**,
`sha256 = 17b883c14fb0168213aea60947ddceb62a03fbfb90fbdf304afdb586e4950360`.

```
Payload/KRWProbe.app/KRWProbe     161 600 байт, Mach-O 64-bit arm64
                                  sha256 = 15614e8c9d2ec50d3f5559aae42103b3f322b0e49f95c70db8f4faad646315db
Payload/KRWProbe.app/Info.plist   CFBundleShortVersionString = 1.3, CFBundleVersion = 13
```

Проверено:

- `LC_BUILD_VERSION`: platform `ios`, minos `14.0`, sdk `14.0`;
- `LC_CODE_SIGNATURE` присутствует, ad-hoc подпись `ldid`, entitlements
  пустые (как в 1.1/1.2);
- в бинарнике есть `=== KRWProbe 1.3 HARD ===`, `HARD: start`,
  `HARD/geom singles start`, `HARD/struct sel %d size %zu/%d`,
  `HARD/race %ds`, `KRWProbe-%@`, `run dir: %@`, `last_phase.txt`,
  `(run dir unavailable)` и все тексты кнопок;
- сборка без warning'ов компилятора (только штатные предупреждения
  ld64.lld про `-ios_version_min`/`-multiply_defined`).

## Что делать при следующем падении

1. Забрать папку `Documents/KRWProbe-...` целиком (путь виден на экране).
2. Посмотреть `last_phase.txt` — это фаза, во время которой умер процесс.
3. `last_action.json` — точный селектор/`scalarIn`/`structInBytes`/
   `structOutBytes`/`inHex` последнего вызова; `last_config.xml` — его XML.
4. `run.log` содержит все строки до момента падения (сброшены на диск).

Ограничения: устройство в этой сессии не запускалось; реальные `kr`,
`jetsam`/паники и поведение compressed-baseline появятся только на
iPhone. Если HARD всё ещё падает — новый `last_phase.txt` + `run.log`
дадут точку без догадок.

---

# v1.4 — папка запуска видна в Files + зеркало в tmp

Статус: собрано (`v1.4`, build 14), IPA лежит в
`probe/out/KRWProbe.ipa`. На устройстве в этой сессии не запускалось.

## Почему папки не было в Files

Сама папка `<Documents>/KRWProbe-<timestamp>/` в v1.3 создавалась (и
`run.log`/`last_config.xml`/`last_action.json` в ней были), но iOS не
показывает Documents приложения в Files, пока в `Info.plist` нет двух
ключей:

- `UIFileSharingEnabled = true` — разрешает доступ к Documents
  (iTunes/Finder и «На моём iPhone»);
- `LSSupportsOpeningDocumentsInPlace = true` — разрешает открывать
  документы на месте, без копирования.

Без них контейнер существует, но в Files app его не видно — именно это
и наблюдалось.

## Что изменено в v1.4

### Info.plist

Добавлены (оба `true`):

```xml
<key>UIFileSharingEnabled</key><true/>
<key>LSSupportsOpeningDocumentsInPlace</key><true/>
```

Версия: `CFBundleShortVersionString = 1.4`, `CFBundleVersion = 14`,
`CFBundleDisplayName = KRWProbe 1.4`.

### Создание папки — по-прежнему до UI, но с проверкой

`run_setup()` вызывается из `main()` до `UIApplicationMain` (порядок
виден в дизассемблере: `bl _run_setup` идёт до вызова
`UIApplicationMain`). Теперь она:

1. Создаёт **две** папки с одинаковым именем:
   - `<Documents>/KRWProbe-<yyyyMMdd-HHmmss>/`;
   - `<NSTemporaryDirectory()>/KRWProbe-<yyyyMMdd-HHmmss>/`.
   При коллизии имени добавляется `-pid` / `-pid-N`.
2. `run_make_dir()` возвращает `nil` и заполняет `NSError`, если
   `createDirectoryAtPath:withIntermediateDirectories:...` не сработал;
   текст ошибки попадает в общий список.
3. Открывает `run.log` в обеих папках (`fopen "a"` + `fflush` после
   каждой строки). Ошибка `fopen` (с `strerror(errno)`) тоже попадает в
   список.
4. Сразу пишет и **проверяет наличие** четырёх файлов:
   `run.log`, `last_config.xml`, `last_action.json`, `last_phase.txt` —
   в каждой созданной папке. Отсутствие любого файла добавляется в
   ошибки.
5. Все последующие записи дублируются:
   - `run.log` — каждая строка в оба файла;
   - `last_config.xml` (включая XML перед каждым sel 0),
     `last_action.json`, `last_phase.txt`, `last_config.json` — в обе
     папки через `write_both()`.

### Отображение на экране

- Под маркером фазы теперь **четыре строки** путей:
  `Docs: <полный путь>` и `Tmp: <полный путь>` (monospace 8 pt, перенос
  по символам).
- Ниже — красная строка с `NSError`/списком ошибок, если что-то не
  создалось. Если всё хорошо — зелёная
  `run folders OK - 4 files present in each`.
- В `run.log` пишутся строки
  `Documents run dir: ...`, `tmp run dir: ...`, `active run dir: ...`,
  `tmp mirror: ...`, `[ERROR] run setup: ...` либо
  `run folder verified: ...`.
- SAFE-режим повторяет оба пути и ошибку в логе.

## Проверка артефакта

Собрано из `/tmp/opencode/krwprobe`:

```
make ipa
cp KRWProbe.ipa probe/out/KRWProbe.ipa
```

Артефакт: `probe/out/KRWProbe.ipa`, **46 494 байта**,
`sha256 = dcfe4094e832ccd54afc0d2351de4f7ba0e436fe1bdbf01beeb2a7f027fc0d5c`.

```
Payload/KRWProbe.app/KRWProbe     163 104 байта, Mach-O 64-bit arm64
                                  sha256 = 5e81d6ed7fdd8975280ed1cc19fc17c55ddd5831ac8660d2eb782b9650126ab5
Payload/KRWProbe.app/Info.plist   CFBundleShortVersionString = 1.4, CFBundleVersion = 14
```

Проверено по содержимому IPA (не только по исходникам):

- `python plistlib` по `Payload/KRWProbe.app/Info.plist`:
  `UIFileSharingEnabled = True`,
  `LSSupportsOpeningDocumentsInPlace = True`,
  `CFBundleShortVersionString = 1.4`, `CFBundleVersion = 14`;
- `unzip -t` — архив цел; `file` — Mach-O 64-bit arm64;
- `LC_BUILD_VERSION`: platform `ios`, minos `14.0`, sdk `14.0`;
  `LC_CODE_SIGNATURE` присутствует, ad-hoc `ldid`, entitlements пустые;
- в бинарнике есть `=== KRWProbe 1.4 HARD ===`,
  `run folders OK - 4 files present in each`,
  `run folder verified: run.log, last_config.xml, last_action.json,
  last_phase.txt present in all created locations`,
  `Documents run dir: %@`, `tmp run dir: %@`, `tmp mirror: %@`,
  `last_phase.txt`, `KRWProbe-%@`;
- `llvm-objdump --disassemble-symbols=_main`: вызов `bl _run_setup`
  находится до вызова `UIApplicationMain`, то есть папки создаются до
  появления UI.

## Как проверить на устройстве

1. Установить IPA и запустить приложение один раз.
2. На экране появятся `Docs:` и `Tmp:` с полными путями; при успехе —
   зелёная строка `run folders OK - 4 files present in each`.
3. Files → «На моём iPhone» → **KRWProbe** → `KRWProbe-<timestamp>/`:
   внутри `run.log`, `last_config.xml`, `last_action.json`,
   `last_phase.txt`. Те же файлы лежат в tmp-папке с тем же именем.
4. Если папки в Files всё ещё нет — на экране будет красный текст с
   `NSError` от `createDirectoryAtPath:`; его нужно прислать вместе с
   `run.log`.
