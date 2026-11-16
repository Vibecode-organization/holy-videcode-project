# Ночь 28.10.2026 — iOS 27.2 (24B115) / iPhone14,7 (T8110): что проверено

Цель ночи: произвольный kernel R/W на 27.2. Итог: **примитива нет**, но закрыт ряд
направлений и найдены точные места фиксов. Ниже — что именно проверено, чем и что осталось.

---

## 1. Сборка

| Что | Значение |
|---|---|
| Устройство | iPhone14,7 (T8110), iOS 27.2, build 24B115, на связи (`REDACTED-UDID`) |
| Наш kernelcache | `kc/27.2_24B115_kernelcache` — Mach-O, `xnu-13432.42.3~28`, собран 13.10.2026 |
| IPSW 24B115 | kernel внутри имеет штамп `24B113`; диff с нашим файлом — **933 байта, все build-строки** |
| Вывод | код 27.2 RC и финальной сборки идентичен; анализировали правильное ядро |

---

## 2. SPTM TTBAT — закрыто

Таблица эндпоинтов UAT (`0xfffffff02701c0e0`, шаг 0x18) хранит **смещения от базы образа**
`0xfffffff027004000` + PAC-тег `0x8020…`, а не указатели. Прошлый декод (`handler=0x80200000000a9f30`)
указывал в SHA-256.

Настоящий MAP_BEGIN 27.2: **`0xfffffff0270adf30`** (найден по сигнатуре пролога, сходится
с таблицей: `0xfffffff027004000 + 0xa9f30`).

Код 27.2 (и такой же в 27.0):

```c
if (out_pa == SK+0x68 && memtype in {2,3,5,6,7,9,10})   // gpu-region-base
        violation 0x4000012;                            // hard panic
if (out_pa != SK+0x68)
        FUN_0xe1168(out_pa, perms);                     // проверка FTE/IOMMU
```

Скип проверки — **только для одного фиксированного PA** (gpu-region-base, из DeviceTree),
это штатный маппинг GPU MMIO. Произвольный PA так не замапить. Плюс 27.2 валит в violation
именно тот класс атрибутов, который раньше проходил.
**Как primitive снято.**

---

## 3. IOSurface: фикс найден, гонка закрыта

`com.apple.iokit.IOSurface` 27.0 (24A437) ↔ 27.2 (24B115), секция `__text`
(53 639 ↔ 53 645 инструкций).

**Весь фикс — 6 инструкций в 3 функциях** (подробно: `FINDING_IOSurface_27.2.md`):

| 27.0 | 27.2 | изменение |
|---|---|---|
| `FUN_fffffff009bf9900` | `FUN_fffffff009c35890` | проверка `child+0xf1` + ветка отказа |
| `FUN_fffffff009bf9b60` | `FUN_fffffff009c35ae0` | `mov #1; strb` |
| `FUN_fffffff009bfead4` | `FUN_fffffff009c3aa7c` | `strb` + `bl` |

`addChild` (27.2 `FUN_0x9c35850`) под локом `surface+0x150` отказывает, если у ребёнка
взведён `child+0xf1`. `removeChild` (27.2 `FUN_0x9c35ad4`) **в 27.2 взводит этот флаг**.
В 27.0 флаг проверялся, но никем не выставлялся — это и есть CVE-2026-112477.
Других мест, трогающих `+0xf1`, во всём кексте нет. **Примитива нет.**

> Методическая заметка: сравнивать надо **секцию `__text`**, а не первый сегмент
> (`__TEXT`). Первый прогон по первому сегменту дал ложное «кекс не менялся».

---

## 4. AppleAVE2: блок новых проверок (27.2)

В 27.2 в `com.apple.driver.AppleAVE2` (913.43.1 → 913.64.1) появился большой набор
проверок границ — это фиксы CVE-2026-112470/112469/112468/112689/112466:

- HEVC VPS: `vps_max_sub_layers_minus1 < 7`, `vps_num_layer_sets_minus1 < 16`,
  `vps_num_hrd_parameters <= 16`, `vps_max_layer_id < 63`, `num_add_layer_sets <= 64`,
  сумма layer-sets/OLS <= 64, `layer_id_in_nuh`, `highest_layer_idx_plus1`.
- HEVC SPS: `sps_max_sub_layers_minus1 < 7`, `num_long_term_ref_pics_sps <= 16`,
  `log2_max_poc_lsb_minus4 <= 12`.
- HEVC PPS: `num_tile_columns/rows_minus1 <= 256`, `chroma_qp_offset_list_len_minus1 <= 5`,
  `num_extra_slice_header_bits == 0`.
- HEVC RPS: `num_short_term_ref_pic_sets < 65`, long-term <= 16.
- AVC: `4 <= iLog2MaxFrameNum <= 16`, `4 <= iLog2MaxPOCLsb <= 17`, `iNumSliceGroups == 1`,
  ref idx 1..16.
- Временные слои <= 7, MCTF strength, `userDPBnumFrames` 2..17, `num_ref_frame <= 16`.

Строки-ассерты с точными условиями лежат в кексте — по ним можно восстановить структуры
(`pInfo->saHEVC_VPS[]`, `sSyntaxCfgAVC`, `uPropCfg.sHEVC`, …).

**Не проверено до конца:** используется ли какое-то из этих полей как индекс массива
*без* проверки в соседнем пути (энкодер/транскодер). Это следующий шаг, если идти в AVE.

---

## 5. Ядро (com.apple.kernel): карта изменений

- 20 876 → 20 901 функций; shape-diff (инструкции без иммедиатов): **20 393 идентичны
  (97.6%)**, 392 региона изменены, из них ~150 функций с малым приростом кода.
- Крупные кластеры изменений: task/port/exception, VM и компрессор
  (`vm_object_paging_*`, `c_decompress_page`, `vm_map_freeze`, JIT-downgrade).
- В `task_set_special_port` (27.0 `0xfffffff00a1d9100` → 27.2 `0xfffffff00a2153dc`)
  добавлена проверка refcount порта перед заменой special port (порт- UAF-класс).
  Границы массива (`which <= 0x24`) в обеих версиях одинаковые.

Полный список изменённых функций — `reports/kcore_shape_diff.txt`; опознание по строкам —
`scripts/ident_changed.py`.

---

## 6. Артефакты

| Путь | Что |
|---|---|
| `probe/out/KRWProbe.ipa` | probe-приложение (15 КБ), подписать своим Apple ID |
| `probe/KRWProbe/` | исходники probe |
| `reports/FINDING_IOSurface_27.2.md` | разбор фикса IOSurface |
| `reports/kcore_shape_diff.txt` | изменённые функции ядра 27.0→27.2 |
| `scripts/compare_text.py` | сравнение секции `__text` двух Mach-O |
| `scripts/diff_func.py` | дифф одной функции между двумя сборками |
| `scripts/ident_changed.py` | опознание функции по строкам, на которые она ссылается |
| `scripts/fdiff_kernel_shape.py` | shape-diff ядра по всем сегментам |

### Что делает KRWProbe

Кнопка **RUN SAFE** (ничего не ломает):

- `kern.version`, `kern.osversion`, `hw.model`, `hw.memsize`, uid/euid, наличие контейнера;
- создание IOSurface (1/2/4/8 планов) и вывод реальных `alloc/bytesPerRow/planeCount`;
- `IOServiceOpen` для `IOSurfaceRoot`, `AppleAVE2Driver`, `AppleAVE2Interface`,
  `AppleH11ANEInterface`, `AGXAcceleratorG14P` — **это и есть ответ на вопрос, что
  песочница реально пускает** (для IOSurface/AVE мы это только предполагали).

Кнопка **AGGR** (может уронить ядро — это тест, а не демо): создаёт interchange-поверхности
с `(dataPerSlice + headerPerSlice) * sliceCount`, переполняющим 32 бита (`0xffffffff`,
`0x80000000`, `0x40000000`).

Кнопка **RACE 30s** — 5 потоков на одной поверхности: `IOSurfaceSetValue`/`RemoveValue`
со случайными ключами, три потока `Lock/Unlock` + чтение plane info, и поток, который
подменяет `IOSurfacePlaneInfo` целиком (в том числе на другое число планов). Это стресс
ровно того списка клиентов (`surface+0x188`), который Apple правила в 27.2.

Кнопка **FUZZ UC** — если `IOServiceOpen` для `IOSurfaceRoot`/`AppleAVE2Interface`
разрешён, гоняет 200 000 вызовов `IOConnectCallMethod` со случайными селекторами (0..63),
скалярными входами и struct-входом (0..256 байт). Селектор и аргументы пишутся в
`last_config.json` перед каждым вызовом.

Кнопка **FUZZ 50k** — структурный фаззер: 50 000 случайных `IOSurfaceCreate` по пространству
compressed-plane свойств (тип компрессии, sliceCount, региональные размеры, tile-геометрия,
bits per block, HTPC-селектор). Значения берутся из набора граничных (0,1,2,3,4,7,8,15,16,31,
32,63,64,127,128,255,256,511,512,1023,4096,65535,65536) и «взрывных» (0x20000000…0xffffffff).
**Перед каждой попыткой полный конфиг пишется в `last_config.json`** в контейнере приложения.
Если ядро упадёт — после перезагрузки вверху экрана будет ровно тот ввод, который это сделал.

---

## 7. Честный статус

**Произвольного kernel R/W нет.** За ночь:
- закрыто SPTM TTBAT (ложный лид из прошлого отчёта);
- найден и разобран точный фикс IOSurface (гонка закрыта);
- собран полный список проверок AVE, добавленных в 27.2;
- построена карта изменений ядра 27.0 → 27.2 (392 функции);
- собран probe, который на устройстве отвечает на вопросы достижимости.

Всё, что было найдено как «живое» ранее, в 27.2 закрыто. Новый баг за ночь не найден.
Дальше без динамики (запуск своего кода на устройстве) поиск упирается в слепой перебор
по 392 изменённым функциям ядра.

---

## 8. Явная проверка на устройстве (KRWProbe 0.3–0.9)

Устройство: iPhone14,7, 27.2 (24B115), uid=501, песочница приложения.

### Подтверждено

| Проверка | Результат |
|---|---|
| `IOServiceOpen("IOSurfaceRoot")` | **kr=0x0** — прямой user client доступен |
| `IOServiceOpen("AppleAVE2Driver")` | 0xe00002bd (NoMemory) |
| `IOServiceOpen("AGXAcceleratorG14P")` | 0xe00002c7 (Unsupported) |
| `AppleAVE2Interface`, `AppleH11ANEInterface` | `no service` |
| Контроль: `NoSuchService_SMITH_0` | `no service` |
| Контроль: `AppleMobileFileIntegrity` | 0xe00002e2 (NotPermitted) |

Контроли доказывают, что лог отражает реальные ответы ядра: одна и та же функция даёт
четыре разных `kern_return_t`, включая «сервис не найден» и «не разрешено».

### Диспетчер user client'а

`IOSurfaceRootUserClient::getTargetAndMethodForIndex` = `FUN_0x9c3ee40`.
Две таблицы по 13 записей (`0x18` байт), вторая — для `com.apple.private.gpu-restricted`,
ведёт на **те же** обработчики:

| sel | handler | | sel | handler |
|---|---|---|---|---|
| 0 | 0xfffffff009c3cb74 | | 7 | 0xfffffff009c3d16c |
| 1 | 0xfffffff009c3cc88 | | 8 | 0xfffffff009c3a230 |
| 2 | 0xfffffff009c3cd9c | | 9 | 0xfffffff009c3a2ac |
| 3 | 0xfffffff009c3cf68 | | 10 | 0xfffffff009c3e22c |
| 4 | 0xfffffff009c3b240 | | 11 | 0xfffffff009c3a2c0 |
| 5 | 0xfffffff009c3b0bc | | 12 | 0xfffffff009c409ec |
| 6 | 0xfffffff009c3d038 | | | |

Таблица лежит на `0xfffffff008069e50`; в файле она в виде chained fixups, читать только
из Ghidra (скрипт `scripts/ghidra/ReadTable.java`).

### Отрицательный результат

Все 13 селекторов вернули `kIOReturnBadArgument` (0xe00002c2) при:

- `scalarInputCnt` 0..8, `structureInputSize` 0..2048 (шаг 8);
- `scalar0` = 0, 1 и реальный ID поверхности, созданной через `IOSurfaceCreate`;
- `IOServiceOpen` type 1..3 — не открываются (0xe00002c7).

Значит конвенция аргументов не угадывается перебором. Следующий шаг — статика:
`IOUserClient::externalMethod` + переопределение в клиенте, и разбор одного обработчика
по ассемблеру. После этого — один точный вызов, а не 10 тысяч слепых.

### Фаззер

- 50 000 случайных compressed-plane конфигов: 170 созданных поверхностей, паники нет.
- RACE 30s (5 потоков SetValue/Lock/Unlock): паники нет.
- AGGR (4 конфига с 32-битным переполнением `(data+hdr)*sliceCount`): все `rejected`.
- FUZZ UC (200 000 случайных селекторов/аргументов): паники нет.
