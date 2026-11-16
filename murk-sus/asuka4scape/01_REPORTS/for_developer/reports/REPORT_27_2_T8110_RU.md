# 27.2 RC / T8110 — kernel R/W и SPTM bypass

**Дата:** 26.10.2026  
**Цель:** iPhone 14 (T8110, A15), iOS 27.2.0 RC  
**Статус:** статический анализ, без устройства. Все адреса — pre-slide, из Ghidra-базы.

---

## 0. Что реально на столе

| Артефакт | Что это | Билд |
|---|---|---|
| `kernelcache.release.iphone14b.decompressed.gzf` (294 MB) | полный fileset, 3 904 блока, 211 266 функций, 10.7 M инструкций | **Darwin 27.2.0**, `xnu-13432.42.3~28`, сборка **Tue Oct 13 21:26:30 PDT 2026**, `RELEASE_ARM64_T8110` |
| `sptm.t8110.release` | SPTM для t8110, Mach-O arm64e | **SPTM-820.0.22**, 08.08.2026 |
| `sptm.raw` / `sptm.raw.24A437` | SPTM для iPhone 16 | 820.0.16 / 820.0.22 |
| `26.1…iPhone16,1`, `26.7…iphone16,1KERNELN1` | 26.x, другая модель (T8122) | 25.x/26.x Darwin |

**Честно про версии:** 27.2.0-ядро найдено и подтверждено (`strings` → `@(#)VERSION: Darwin Kernel Version 27.2.0 … xnu-13432.42.3~28`).  
**SPTM 27.2 на диске нет.** Все три SPTM-блоба — 820.0.16/820.0.22 (июль–август). Всё ниже по SPTM — против 820.0.22; для 27.2 нужно вытащить `sptm.t8110.release` из IPSW 27.2 и прогнать те же скрипты (§5). Хэши кода в 27.2 могут отличаться, логика таблиц — нет.

Ядро 27.2 содержит `__DATA_SPTM` и `SPTM version: %.256s` — SPTM на A15 в 27.2 реально включён, это не заглушка.

---

## 1. Kernel R/W — что проверено и закрыто

### 1.1 ANE auto-prewire (вектор 26.5.2 из `main.m`) — **ЗАКРЫТ в 27.2**

Старая дыра: `memoryMapRequest` на фиксированные 128 записей, цикл писал запись на каждый IO-буфер без проверки количества.

В 27.2 перед созданием запроса стоит гейт:

```c
// FUN_fffffff0089d201c  (size=320)
if (param_8 == 0)                       return 0xe00002c2;   // "memoryMapRequest is nullptr"
else if (*(uint *)(param_8 + 0x810) < 0x81) return 0;       // <= 128 — OK
else                                    return 0xe00002c2;   // "Buffer count: %u exceeds max allowed number"
```

Копирование записей (FUN_fffffff0089d215c):

```c
memcpy(mapRequest + 0xa0, param_8, (u64)*(u32 *)(param_8 + 0x102) << 4);   // count*16
*(u64 *)(mapRequest + 0x10a0) = param_8[0x102];                            // count
```

`param_8 + 0x102` в `undefined8*` = байтовое `+0x810`. Счётчик проверен **до** memcpy и читается из того же объекта; длина `count*16` ≤ 0x800. Записи живут по `+0xa0`, счётчик — `+0x10a0`; потребитель (`FUN_fffffff0089cf69c`) и unwire (`FUN_fffffff0089d47a0`) итерируют ровно `+0x10a0`.

**Вывод:** OOB-запись 26.5.2 в 27.2 не воспроизводится. Остаётся только теоретический OOB-read на 4 байта в самом гейте, если `structureInput` короче 0x814 и вызывающий не проверил длину; записи нет, для R/W бесполезно.

### 1.2 Work-token TOCTOU (V5 из `exploit ios27.c`) — **в 27.2 есть, но описан неверно**

Реальные адреса 27.2:

| Функция | Адрес | Роль |
|---|---|---|
| `FUN_fffffff00a9e2db4` | `0xfffffff00a9e2db4` | dispatch токена: check capacity → callback → re-check → `entry[+0x10]=1` |
| `FUN_fffffff00a9e2a8c` | `0xfffffff00a9e2a8c` | альтернативный dispatch, `entry[+0x10]=0` |
| `FUN_fffffff00a9e2eb8` | `0xfffffff00a9e2eb8` | async-постановка токена |
| строка | `0xfffffff0070b9009` | `"Invalid work token (%llu): index out of bounds. @%s:%d"` |

Раскладка очереди (подтверждена по трём функциям):

```
queue+0x10  vtable (callback'и +0x20/+0x28/+0x30/+0x38)
queue+0x18  массив записей
queue+0x20  capacity (u64)
queue+0x28  last_done
queue+0x38  запись = 0x38 байт, статус на entry+0x10
```

Что реально делает код:

```c
if (token < *(u64*)(q+0x20)) {                       // [A]
    entry = *(u64*)(q+0x18) + token*0x38;
    ctx.backptr = entry + 0x11;  ctx.size = 0x20;    // контекст для callback
    callback(...);                                   // окно
    if (token < *(u64*)(q+0x20)) {                   // [B] re-check
        entry = *(u64*)(q+0x18) + token*0x38;
        *(u8*)(entry + 0x10) = 1;                    // запись — entry+0x10, НЕ +0x21
    } else panic("Invalid work token");
}
```

**Почему `exploit ios27.c` в текущем виде неверен:** он утверждает, что запись идёт в `+0x21` (второй байт capacity) и раздувает capacity 0x10→0x110. В 27.2 запись идёт в **entry+0x10**, value = 1; при уменьшении capacity срабатывает re-check и **паника**, а не OOB. `+0x11` в контексте — это back-pointer на inline-буфер записи, а не смещение записи. Адреса вида `0xa9a275c` в эксплойте — из другого ядра (14.5), к 27.2 отношения не имеют.

**Что остаётся реальным:** если во время callback очередь/массив освобождается (refcount→0), запись `entry+0x10 = 1` идёт в освобождённый и переиспользованный kalloc-блок. Это stale-write одного байта `0x01` по смещению +0x10. Слабый, но настоящий примитив; требует heap-shaping и объекта с управляемым полем на +0x10. Для «полного арбитрари» этого мало — нужен второй шаг.

### 1.3 IOSurface — поверхность проверена, новых дыр не видно

Таблицы методов (0x28-шаг, 2022-формат) кластером от `0xfffffff008068b90`; на базе есть ссылка из `0xfffffff009c3ee2c` (указатель в data). Кластер длинный (несколько клиентов подряд), в нём 24 селектора с `structIn=ANY` и 10 с `structOut=ANY`.

Проверены ANY-обработчики:

| Селектор | Функция | Проверка |
|---|---|---|
| 9 | `0xfffffff009c38b2c` | `12 < structInSize`, передаёт размер вглубь |
| 10 | `0xfffffff009c38c44` | `structInSize >= 0xd` и `structOutSize >= 0xd` |
| 19 | `0xfffffff009c390ac` | `size < 0x200`, требует `buf[size-1]==0`, печать `%.512s` |
| 26 | `0xfffffff009c39448` | (нет отдельной функции — слита с соседней) |
| 22 | `0xfffffff009c3968c` | выделяет 0x100000, пишет указатель в `args+0x78` |

Плюс в 26→27 в IOSurface внедрён `bounded_ptr<T>` (строки `OSBoundedPtr.h`), и исчезла целая AgentMask-подсистема. Грубых OOB на ANY-размерах нет.

**Единственный новый пользовательский ввод в 27.2 IOSurface** — три HTPC-свойства:

- `IOSurfacePlaneBytesPerRowOfCompressedTileHeaderGroups`
- `IOSurfacePlaneHorizontalPixelOffsetWithinCompressedTileArray`
- `IOSurfacePlaneVerticalPixelOffsetWithinCompressedTileArray`

Их валидатор — `FUN_fffffff009c1af14` (3 377 строк декомпила, ~0x23500 байт кода). В нём есть проверки переполнений (`Width + CompressedTileWidth`, `tilesToCoverHeight + headersInGroup`, точное покрытие ширины/высоты), но именно там сосредоточена вся новая арифметика plane-геометрии. Это **главный статический лид на запись** в IOSurface: аудит `0x9c1af14` на 32/64-битные переполнения в новых полях и на индексацию plane[] без проверки `planeCount`.

### 1.4 AppleJPEGDriver — размеры парные

Таблица `0xfffffff007e293c0` (10 селекторов, 0x28-шаг):

```
sel0/2: 0/0        sel1/3: 0x58/0x58
sel4/5: 0x1000 in/out   sel6/7: 0xda0 in/out   sel8: 4/0   sel9: 0/0
```

Обработчики 4/6 (`0xfffffff008c8fb08`, `0xfffffff008c8fb70`) — тонкие обёртки, передающие и указатель, и размер (`args+0x30`, `args+0x58`) в ядро кодека (`FUN_…8c86bd4`, `FUN_…8c876d8`). На уровне IOKit размеры фиксированы и парные; искать нужно внутри кодека, если понадобится.

**Итог по kernel R/W:** проверенного примитива произвольного чтения/записи в 27.2 пока нет. Закрыто: ANE. Ослаблено: work-token (однобайтовая stale-запись). Открыто: новая HTPC-геометрия IOSurface (`0x9c1af14`), кодек JPEG, и — главное — путь через SPTM/GPU ниже, который даёт запись в page tables без kernel R/W вообще.

---

## 2. SPTM 820.0.22 — карта и дыра в исключении TTBAT

### 2.1 Таблицы endpoint'ов

Формат записи — 0x18 байт: `{char *name; void (*handler)(void *args); u64 flags}`.

| Группа | База таблицы | Записей |
|---|---|---|
| UAT | `0xfffffff02701c0e0` | 14 |
| CPUTRACE | `0xfffffff02701c848` | 12 |
| NVME | `0xfffffff02701ce48` | 10 |
| HIB | `0xfffffff027023460` | 6 |

UAT:

| # | Endpoint | Handler |
|---|---|---|
| 0 | INIT_STATE | `0xfffffff0270aeb0c` |
| 1 | DESTROY_STATE | `0xfffffff0270ae830` |
| 2 | MAP_TABLE | `0xfffffff0270ae534` |
| 3 | UNMAP_TABLE | `0xfffffff0270ae210` |
| 4 | **MAP_BEGIN** | **`0xfffffff0270ada40`** |
| 5 | MAP_CONTINUE | `0xfffffff0270ad8a4` |
| 6 | PREPARE_FW_UNMAP_BEGIN | `0xfffffff0270ad5a4` |
| 7 | PREPARE_FW_UNMAP_CONTINUE | `0xfffffff0270ad28c` |
| 8 | UNMAP_BEGIN | `0xfffffff0270ac614` |
| 9 | UNMAP_CONTINUE | `0xfffffff0270ac298` |
| 10 | SET_CTX_ID | `0xfffffff0270abc74` |
| 11 | REMOVE_CTX_ID | `0xfffffff0270ab9e0` |
| 12 | GET_INFO | `0xfffffff0270f317c` (паника «SAPT Revocation is not supported») |
| 13 | REVOKE_SAPT_MULTIPAGE | **NULL** (не поддержан) |

### 2.2 Объект состояния UAT (из `FUN_fffffff0270be6dc` и обработчиков)

```
+0x00  flags/type (бит0 — state object, биты 2/3 — twin TTBR)
+0x08  TTBR0 PA
+0x10  TTBR1 PA (если type==4)
+0x18  context id (u16)
+0x1a  guard state: 1 — захвачен, далее 2/3/4...
+0x20  текущий output PA (курсор)
+0x28  число сегментов
+0x30  текущий сегмент
+0x38  смещение внутри сегмента (в страницах)
+0x40  атрибуты маппинга (u32)
+0x48  сегменты[]: {u64 pa; u64 pages} шаг 0x10
```

Гейт `FUN_fffffff0270be6dc(param_1, type, mask)` проверяет тип состояния, guard, границы PA (`(pa & 0x3fff)`, `pa+0x4000`), находит FTE и требует `(%pte_type & mask) != 0`.

### 2.3 Проверка прав — `FUN_fffffff0270e029c`

Ядро политики SPTM: для каждого выходного PA при MAP_BEGIN вызывается

```c
FUN_fffffff0270e029c(pa, perm);   // pa = output page, perm = 1 или 2
```

Внутри:

1. находит FTE (`DAT_fffffff0270914f0 + idx*0x10` для DRAM, иначе `FUN_…de884`);
2. читает тип страницы `fte[+2]` и текущий dispatch ID `*(u64*)(sysreg_base+0xb08)-1`; допустимо 0..8;
3. берёт `allowed_permissions = DAT_fffffff027092230[type*0x90]` и битмап `DAT_fffffff027092228[type*0x90]`;
4. **паника**, если бит для dispatch ID не выставлен или `allowed_permissions < perm`;
5. отдельно — IO-range restriction для типа 6.

То есть обычный путь «замапить kernel/SPTM-страницу как writable» отбивается типом FTE и таблицей разрешений.

### 2.4 Исключение TTBAT — **находка**

В MAP_BEGIN (`0xfffffff0270ada40`), строки 142–164 декомпила:

```c
bVar3 = (type - 5) < 3;      // 5..7
bVar5 = (type - 9) < 2;      // 9..10
bVar4 = (type & 0xe) == 2;   // 2,3,6,7,10,11
perm = (bVar3 || bVar5 || bVar4) ? 2 : 1;

if ((out_pa == *(u64*)(SK + 0x68)) && (bVar3 || bVar5 || bVar4))
        panic("...");                       // TTBAT + executable/device — запрещено

if (out_pa != *(u64*)(SK + 0x68))
        FUN_fffffff0270e029c(out_pa, perm);  // обычная проверка прав
// если out_pa == SK+0x68 и тип НЕ executable — проверка ПРОПУСКАЕТСЯ
```

`SK + 0x68` — это **gpu-region-base**, то есть TTBAT (Translation Table Base Address Table) GPU. Устанавливается на boot из device tree в `FUN_fffffff0270af4d4`:

```c
*(u64 *)(SK + 0x68) = devtree["gpu-region-base"];
*(u64 *)(SK + 0x70) = devtree["gpu-region-size"] >> 14;   // в страницах
FUN_fffffff0270df108(SK+0x68, pages, 2);                  // регистрация типа 2
```

Паника в том же файле прямо называет регион TTBAT: `"The TTBAT is smaller than a page in size or not a multiple of the SPTM_PAGE_SIZE"`.

**Смысл исключения:** TTBAT — особая страница; SPTM не гоняет её через FTE-проверку прав, потому что GPU-драйвер должен мапить её writable в UAT-контекст GPU (GPU сам обновляет свои page tables).

**Дыра:** исключение не проверяет, **какому UAT-контексту** и **под каким dispatch ID** мапится TTBAT. Достаточно, чтобы выходной PA сегмента совпал с `gpu-region-base`, а атрибуты были не executable (обычный writable data). Тогда:

1. любой вызывающий EL1 (XNU), умеющий дёрнуть `SPTM_UAT_ENDPOINT_MAP_BEGIN`, получает **writable-маппинг TTBAT** в выбранном UAT-контексте;
2. запись в этот маппинг = запись TTE в базовую таблицу GPU;
3. подмена TTE → GPU MMU транслирует произвольный VA на произвольный PA → GPU DMA читает/пишет любую физическую память, включая ядро и SPTM-страницы;
4. это и есть «полный анлок»: SPTM больше не последний рубеж, потому что его проверка для TTBAT обойдена, а GPU-трансляция контролируется атакующим.

Это не требует kernel R/W на первом шаге: нужен только вызов UAT MAP_BEGIN с корректным state-объектом. State создаётся через INIT_STATE с TTBR PA, который проходит проверку типа (page-table page). Дальше — сегмент с `pa = gpu-region-base`, обычные атрибуты.

**Что надо подтвердить на устройстве (без этого finding — гипотеза):**

1. `SK+0x68` в 27.2 всё ещё `gpu-region-base` (проверить строку `gpu-region-base` в 27.2 SPTM).
2. Что MAP_BEGIN вызывается из XNU без дополнительного фильтра по dispatch ID (в 820.0.22 в теле MAP_BEGIN фильтра нет — только в `FUN_…0e029c`, который для TTBAT пропускается).
3. Что UAT-контекст, куда замапили TTBAT, достижим из GPU/пользователя (иначе п.2–3 цепочки не собрать).
4. Что GPU действительно ходит в DRAM через этот TTBAT (а не через отдельный DART), и что подмена TTE даёт DMA в нужный PA.

### 2.5 Что в 820.0.22 уже закрыто

- `hib_validate_io_buffer_page` — hibernation IO-страница теперь валидируется постранично;
- `t8110dart_verify_sid_config` / `_shadow_config`, `t8110dart_read_dapf_reg`, `sptm_t8110dart_sk_tlbi_request` — DART SID/TTBR теперь зеркалятся в shadow, TLBI брокерится через SK;
- новые паники: `VIOLATION_T8110_DART_SID_TRANSLATION_DISABLED`, `..._RACE`, `..._INVALID_RETYPE_*`.

Старые IOMMU/hibernation-пути (820.0.16) в 27.x не работают. Осталась UAT-ветка — и в ней TTBAT-исключение.

---

## 3. Сводка

| Направление | Статус | Адреса |
|---|---|---|
| 27.2 RC kernel | подтверждён | Darwin 27.2.0, `xnu-13432.42.3~28`, T8110 |
| SPTM 27.2 blob | **отсутствует на диске** | есть 820.0.22 (t8110) |
| ANE OOB (26.5.2) | закрыт в 27.2 | гейт `0xfffffff0089d201c`, memcpy `0xfffffff0089d215c` |
| Work-token V5 | есть, но примитив слабее заявленного | `0xfffffff00a9e2db4`, `0xa9e2a8c`, `0xa9e2eb8` |
| IOSurface ANY | проверены, OOB не найден | кластер `0xfffffff008068b90`, валидатор `0xfffffff009c1af14` |
| JPEG | размеры парные, поверхность закрыта | таблица `0xfffffff007e293c0` |
| **SPTM TTBAT** | **исключение из проверки прав — подтверждено кодом** | MAP_BEGIN `0xfffffff0270ada40`, SK+0x68, setup `0xfffffff0270af4d4` |
| Kernel R/W arb | **не получен** | главный путь — через TTBAT/GPU DMA |

---

## 4. Что делать дальше (по приоритету)

1. **Вытащить SPTM 27.2** из IPSW `iPhone14,7_27.2_*_Restore.ipsw` (`pyimg4 im4p extract -i sptm.t8110.release -o sptm.27.2`), прогнать §5 — проверить, что `gpu-region-base` и MAP_BEGIN-исключение не изменились.
2. **Проверить TTBAT-гипотезу на живом устройстве**: вызвать `SPTM_UAT_ENDPOINT_MAP_BEGIN` с state, где сегмент = `gpu-region-base`, атрибуты — обычный writable; проверить, что маппинг создан (по возврату и по отсутствию паники `0x4000012`).
3. **Собрать GPU-часть**: какой UAT-контекст доступен (AGX user client), как его VA попадает в пользователя, и ходит ли AGX в DRAM через TTBAT. Это ответит, нужен ли промежуточный kernel R/W.
4. **Параллельно — аудит `FUN_fffffff009c1af14`** (новая HTPC-геометрия): искать переполнения `plane_width * bpp`, `tiles * headers`, индексацию `plane[planeIndex]` без проверки `planeCount`. Это самый вероятный путь к классической OOB-записи в IOSurface 27.2.
5. **Work-token UAF**: проверить, можно ли освободить массив во время callback (через completion), и подобрать объект с полем на `+0x10` (например, `ipc_port`/`kqueue`), чтобы однобайтовая запись `0x01` дала рост счётчика/длины.

---

## 5. Артефакты и воспроизведение

**Ghidra-проект (read-only):** `/home/femboychik/Загрузки/AyuGram Desktop/Архив/123`  
Программа: `kernelcache.release.iphone14b.decompressed`

**SPTM-проект:** `/home/femboychik/work/gh/sptm` (импорт `sptm.t8110.release`)

**Скрипты:** `/home/femboychik/work/scripts2/`

| Скрипт | Назначение |
|---|---|
| `ScanDispatch.java` | глобальный скан таблиц `IOExternalMethodDispatch` (0x18 и 0x28), фильтр ANY |
| `FindStrings.java` | поиск строк + xref + декомпил |
| `StringStart.java` | строка от середины, refs, декомпил |
| `DumpAt.java` | декомпил функций по адресам в `/home/femboychik/work/kdump` |
| `RefTo.java` | ссылки на данные + декомпил |
| `Insn.java` | дизасм вокруг адреса |
| `GlobScan.java` | поиск инструкций по подстроке |
| `Inventory.java` | блоки/секции/SPTM-строки |

Запуск:

```bash
GHIDRA_HEADLESS_MAXMEM=5G ~/ghidra/support/analyzeHeadless \
  "/home/femboychik/Загрузки/AyuGram Desktop/Архив" 123 \
  -process "kernelcache.release.iphone14b.decompressed" \
  -noanalysis -readOnly -scriptPath ~/work/scripts2 -postScript DumpAt.java 0xfffffff0270ada40
```

**Результаты сканов:** `/home/femboychik/work/dispatch_scan.txt` (787 найденных, 128 после дедупликации, 77 с ANY), `/home/femboychik/work/any_tables.txt`, `/home/femboychik/work/kexts.txt`, `/home/femboychik/work/kdump/`, `/home/femboychik/work/sptm_dump/`.

---

*Все выводы — из декомпила Ghidra 12.1.4. Совпадение адресов не доказывает идентичность функций между билдами; для 27.2 SPTM нужен отдельный blob. Ничего не проверялось запуском на устройстве.*

---

# ДОПОЛНЕНИЕ 26.10.2026 — публичный ландшафт и что реально закрыто в 27.2 RC

## 6. Публичное состояние на 26.10.2026

| Что | Версия | Статус |
|---|---|---|
| Calif @ Hexacon (Chollima) | iOS 27.0.1 | kernel R/W + SPTM bypass + sandbox escape, untethered; демо на 17e/18 Pro (MIE); релиза нет |
| iOS 27.2 | RC 24B6115 (RC 19.10) | по трекеру и по диффу — закрывает цепочку Calif; SPTM-байпас ≤27.0.1 закрыт в **27.2b3 (24B5099f)** |
| SPTM | 27.0.1 = **820.40.18**; 27.2b1 = 820.40.18; **27.2b3 = 820.40.23** | между b1 и b3 +3320 байт `__text`, +24 `dmb ish`, Dekker-гейт UAT против GPU GMMU TLBI |
| ClearSword / DarkSword (CVE-2025-43520) | ≤26.0.1 | закрыт в **26.1**: проверка UPL-флагов второго `vm_map_get_upl` |
| AIO kevent UAF | ≤26.2.x | закрыт в **26.3**: в 27.2 `aio_workq_entry` при freed-with-knotes уходит в **панику** (`FUN_fffffff00a6e2494`, строки `@0x…708bfbe`/`0x…708bff9`) |

**Наш SPTM-блоб (`sptm.t8110.release`) побайтово равен SPTM из IPSW 27.0.1 (24A446).**  
sha256: `92f1f932d0a5bc8b2c47c2b7764f319f9575a04ccb387cc70c3a4d28a2f196e8`.  
То есть весь §2 — это **27.0.1**, не 27.2. Для 27.2 нужен `Firmware/sptm.t8110.release.im4p` из 27.2 (RC/OTA).

## 7. Что проверено в самом 27.2 RC

1. **AIO** — `FUN_fffffff00a6e2494`: при `entry[0x18] != 0` (knotes attached) → `FUN_fffffff00aa4d114` = паника, не free. UAF не воспроизводится.
2. **cluster_write_contig** — `FUN_fffffff00a3d5d28`, после `vm_map_get_upl` стоит проверка `((uint)local_f8 >> 1 & 1) == 0` (IO_CONTIG) → ошибка. То же в `cluster_read_contig` (`FUN_fffffff00a3dc38c`, строка 168). Раса DarkSword закрыта.
3. **SPTM UAT** — в 27.0.1 нет `uat_dekker_*`; в 27.2b3 появились `uat_dekkerlock_lock`, `uat_sync_outer_tlb_sapt_flush`, `VIOLATION_T8110_DART_UNGANG_GAPF_RACE`. Исправление — протокол взаимного исключения SPTM↔GMMU, а не одна проверка.

## 8. Что осталось живым в 27.2 (по нашей статике)

- **Work-token stale write**: `0xfffffff00a9e2db4` / `0xa9e2a8c` / `0xa9e2eb8`; ASM `strb w8,[x9,#0x10]`; при UAF массива — запись `0x01` в `entry+0x10`. Слабый, но живой.
- **ANE**: гейт `0xfffffff0089d201c` (`count < 0x81`), memcpy `0xfffffff0089d215c`; OOB-записи нет. OOB-read на 4 байта в гейте при коротком `structureInput` — не R/W.
- **IOSurface HTPC**: новая геометрия, валидатор `FUN_fffffff009c1af14` (3 377 строк). Не аудирован до конца; главный кандидат на OOB-запись.
- **SPTM 27.2**: гейт покрывает 5 функций; `verify-gmmu-tlbis-at-sync` — **opt-in** (на прод-устройствах выключен, следует из `gmmu-tlbi-verification-reg`-строки). Значит, корректность TLBI на прод не проверяется — окно для варианта гонки остаётся теоретически.
- **TTBAT-исключение** (27.0.1): `SK+0x68 = gpu-region-base`, MAP_BEGIN пропускает `FUN_0e029c`, если PA == TTBAT и атрибуты не executable. В 27.2 не проверено (нужен блоб).

## 9. Артефакты, добавленные в этот заход

| Файл | Что |
|---|---|
| `~/work/kc_27.0.1_iphone14b.decompressed` | 27.0.1 kernelcache, iPhone14,7 (T8110), xnu-13432.2.10~2 |
| `~/work/sptm_27.0.1_t8110.macho` | SPTM 27.0.1 (== sptm.t8110.release) |
| `~/work/kc_27.0.1_iphone14b.im4p`, `sptm_27.0.1_t8110.im4p` | IM4P-контейнеры |
| `~/work/ClearSword/` | публичный kernel R/W (CVE-2025-43520), для сверки патча |
| `~/work/aio/` | публичный AIO UAF PoC, для сверки патча |
| `~/work/Coruna-SPTM/` | RE-разбор Rocket SPTM bypass (GFX/hibernation/self-ref PTE) |
| `~/work/ziprange.py` | range-извлечение файла из IPSW без полной загрузки |
| `~/work/kexts.txt`, `dispatch_scan.txt`, `any_tables.txt` | карта 27.2: 249 kext-диапазонов, 128 таблиц методов, 77 с ANY |

## 10. Вывод по цели

На 27.2 RC **нет ни одного публичного kernel R/W и ни одного публичного SPTM bypass**: ClearSword и AIO закрыты, UAT-гонка закрыта в b3, Rocket/hibernation закрыт ещё в 820.0.22 (`hib_validate_io_buffer_page`).  
Рабочая цепочка «27.2 RC» = **новый kernel-баг + новый SPTM-баг**. Это не собирается из публичных компонентов; это отдельная исследовательская работа.  
Ближайшие реальные заходы:

1. Достать SPTM 27.2 (820.40.23+) и проверить TTBAT-исключение и границы Dekker-гейта.
2. Добить аудит `FUN_fffffff009c1af14` (IOSurface HTPC) — единственный новый пользовательский ввод в 27.2.
3. Проверить, кто ещё, кроме 5 функций, меняет UAT (map_begin/map_continue/prepare_fw_unmap_begin) и не покрыт гейтом.
4. Проверить достижимость UAT-мутаций из IOGPU (не AGX sampling-клиента, а IOGPU sel8/sel45) — тогда UAT-гонка снова userland-reachable.
