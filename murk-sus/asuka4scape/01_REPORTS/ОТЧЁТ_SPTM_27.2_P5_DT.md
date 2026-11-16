# SPTM 27.2 — новый заход: sgx DT-свойства и paddr-цель

Дата: 2026-11-03. Телефон: iPhone14,7 / 27.2 (24B115) / T8110.

## 0. Главное

- P4 (map-memory/properties) закрыт: 2191 `IOConnectMapMemory64/IOConnectMapMemory`
  вызовов, все `0xe00002c2`; в IOService-свойствах AGX нет `gpu-region-base`/`ttbat`.
- P5 нашёл путь к sgx-узлу:
  `IODeviceTree:/arm-io@10F00000/sgx@4000000` (через
  `IORegistryEntryGetParentEntry(AppleARMIODevice, kIODeviceTreePlane)`).
  **Важно:** полный словарь свойств sgx-узла
  (`PARENT depth=1`, `dt props`) содержит только
  `device_type`, `metal-standard`, `name`, `opengl-standard`,
  `procedural-antialiasing`, `compatible`, `iommu-present`,
  `soc-generation`. Ключей `gpu-region-base`, `ttbat-phys-addr-base`,
  `gfx-shared-*`, `uat-*` там **нет**. Строки `dt key=... v=¿èïˆ`
  в P5 — артефакт логирования не-CFType значения, а не реальные
  свойства. P6 для этих ключей не нужен.
- Единственный источник paddr GPU-региона — **статический**
  `sgx.reg[1] = {0x04D00000, 0x20000}`.
- Телефон подключён по USB (`REDACTED-UDID`), но сейчас
  заблокирован: `lockdownd` не отвечает (`Mux error -8`), поэтому
  новые IPA может поставить только Kai.

## 1. Статический DeviceTree 24B115

`ipsw dtree iPhone14,7_27.2_24B115_Restore.clean.ipsw --json` ->
`/tmp/dt272.json` (200 KB). Узел:

```
/device-tree/children[7]/arm-io/children[71]/sgx
  compatible = "gpu,t8110"
  device_type = "sgx"
  agx-address-space-mgmt-mode = 1
  reg = { addr=0x04000000, size=0x04000000 },
        { addr=0x04D00000, size=0x00020000 }
  metal-standard = 256; opengl-standard = 768
  gpu-* power/perf properties (gpu-num-perf-states, gpu-pwr-*, gpu-perf-*)
  interrupts = {597,598,599,600,613}
```

В **статическом** DT нет `gpu-region-base`/`ttbat-phys-addr-base` и нет
`/chosen/gpu-region-base`. Полный дамп IORegistry (P5) показывает, что
этих ключей нет и в живых узлах `sgx`, `/arm-io`, `AGXAcceleratorG14P`:
в словарях только `device_type`, `metal-standard`, `name`,
`opengl-standard`, `procedural-antialiasing`, `compatible`,
`iommu-present`, `soc-generation`. Строки `dt key=... v=¿èïˆ` — баг
логирования, а не свойства. Единственный источник paddr — статический
`sgx.reg[1] = 0x04D00000/0x20000` (кандидат).

## 2. Scaler sel 0x01 (0x1b0) — физический путь мёртв (статика)

Проверено по декомпиляции `AppleM2ScalerCSCDriver` 27.2:

- `sel 0x01` (`0x8d1475c`):
  - если `[client+0x164] != 0` -> `setCustomFilter` (`FUN_8d1b504`/`FUN_8d14888`),
    не 0x1b0-команда;
  - если `[client+0x164] == 0` и `structIn == 0x1b0` -> `FUN_8d14158`.
- `FUN_8d14158` -> `FUN_8d142e8`; в `FUN_8d142e8` ветка
  `if (*(client+0x164) == 0)` -> user-путь `IOMemoryDescriptor` с
  `task=owningTask` (virtual64); kernel-ветка (`input+0x50/+0x58` как
  physical) доступна только при `+0x164 != 0`.
- Но при `+0x164 != 0` `sel 0x01` уходит в `setCustomFilter`, а не в
  0x1b0. Значит **одним user-клиентом физическую ветку 0x1b0 не достать**.
  Это закрывает старую гипотезу о paddr через Scaler.

## 3. Что осталось

1. P6/P5: полный sgx-словарь **не содержит** `gpu-region-base`/`ttbat`;
   остаётся статический кандидат `0x04D00000` из `sgx.reg[1]`.
2. Если paddr подтвердится — нужен **write** на этот paddr. Кандидаты:
   - SPTM `GET_INFO`/`MAP_CONTINUE`/`PREPARE_FW_UNMAP`/`REVOKE_SAPT_MULTIPAGE`
     (dispatch-таблица `0x2701c148`, 9 записей: MAP_CONTINUE,
     PREPARE_FW_UNMAP_BEGIN/CONTINUE, UNMAP_BEGIN/CONTINUE, SET_CTX_ID,
     REMOVE_CTX_ID, GET_INFO, REVOKE_SAPT_MULTIPAGE). В прошлых отчётах
     эти endpoint'ы не разбирались; `GET_INFO` может отдавать TTBAT/TTBR
     в kernel, а `REVOKE_SAPT` — новый класс.
   - AGX/IOGPU 27.2 ABI: `sel 6` new queue (0x408), `sel 8` new resource;
     paddr в типе 0/0x40/0x80/0x82 не пользовательский (owningTask).
3. IOSurface/JPEG/DART/MFB — по P2/P3/P5 закрыты (методы 2c2, map 2c2).

## 4. Артефакты

| Путь | Что |
|---|---|
| `SPTMProbe6.ipa` | устарел: полный словарь sgx уже снят P5, ключей там нет |
| `/home/femboychik/Загрузки/AyuGram Desktop/SPTMProbe5.log` | P5: DT path, map 2c2 |
| `/tmp/dt272.json` | статический DeviceTree 24B115 |
| `sptm_272_bypass/dumps/sptm_core_raw.log` | SPTM MAP_BEGIN/check |
| `work/sptm_27.2_24B119.macho` | SPTM 27.2 |

---

## 5. gpu-region-base: кандидат из статического DT

В статическом `DeviceTree.d27ap.im4p` узел `sgx`:

```
reg = { addr = 0x04000000, size = 0x04000000 },   // GPU MMIO
      { addr = 0x04D00000, size = 0x00020000 }    // 128 KiB = 8 x 16 KiB
```

Второй `reg` — `0x04D00000`, размер `0x20000`. В SPTM
`gpu-region-base` = `uat_instance[0x68]`, а `gpu-region-size` считается
в страницах 16 KiB: `0x20000 >> 14 = 8`. То есть второй `reg` по размеру
ровно совпадает с `gpu-region`/TTBAT (8 page-table pages), а `gpu-region-base`
= **0x04D00000** — кандидат на paddr, с которым сравнивает `UAT MAP_BEGIN`.
Первый `0x04000000/0x4000000` — обычный GPU MMIO-блок.

Это **кандидат**, не подтверждённый runtime-свойством: полный словарь
sgx-узла таких ключей не содержит (см. §0/§1). Но размер и положение
сходятся слишком точно, чтобы это было случайно. P10 проверяет
`0x04D00000` прямым GPU-чтением (identity) и через окна `0x100000000`,
`0x800000000`, `0x400000000`.

## 6. Новый путь после пата Coruna: GPU firmware -> TTBAT

Coruna закрыт в 27.2 на **hibernation/TTBR1** (`sanitize_integer(
ttbr1_root_table_paddr_U.UNSAFE_VALUE)`, HMAC, `resume_uat`). Но TTBAT —
это **page table самого GPU**, уже замапленная SPTM в GPU UAT для
firmware. Проверки `VIOLATION_UAT_ILLEGAL_TTBAT_MAPPING/LOCK` стоят в
**MAP_BEGIN**, то есть на CPU/kernel-пути создания маппинга. Запись в
уже замапленный TTBAT со стороны **GPU firmware** (DMA/stamp) — это не
MAP_BEGIN и не hibernation; SPTM её не видит.

Цепочка:

```
GPU firmware job (stamp / op-0x0f arbitrary write)
  -> 32-bit write в TTBAT paddr 0x04D00000 (или его GPU GVA)
  -> подменить PTE контекста GMMU на свою physical page
  -> GPU DMA read/write произвольной физики
  -> kernel R/W, unsigned code
```

Это не Coruna-порт: target — TTBAT, а не `power_thread+0x48`/hibernation.
Доставка job'а — та же, что в Coruna custom path (Metal queue + ring
injection), но 27.2 ABI/offset'ы AGX/IOGPU надо вывести заново; P2/P3
показали, что IOGPU type 1 методы 0..0x40 с нулевыми аргументами дают
`0xe00002c2`, а Coruna-ABI (sel 7/0xF/0x19/0xD/0x1A) не проверялся.

Следующий код: P10 — GPU-чтение `0x04D00000` / окон
`0x100000000`, `0x800000000`, `0x400000000` и Metal unified-VA тест;
P9 — IOGPU sel6 queue. Если P10 видит TTBAT, дальше — запись PTE через
GPU OOB; если нет — raw GPU job path (P11).

---

## 7. Crash-логи 2026-11-03: AGX info-query -> KASLR leak

В `новая папка (3).zip` — 52 `.ips`, все **userspace** (bug_type 309/298),
ни одного kernel panic (210)/panicString. Разбор:

- `KRWProbe-2026-11-02-203356` — `EXC_BAD_ACCESS`, `0x9a9e582fa3e1f040`
  -> strip `0xffffffafa3e1f040` (kernel);
- `KRWProbe-2026-11-02-210333` — `0xb3f4ff17eded3ae0` -> strip
  `0xffffff97eded3ae0` (kernel);
- `KRWProbe-2026-11-02-203333` — `0xb02e8d40078646e0` -> strip
  `0x00000540078646e0` (packed config, не указатель);
- `KRWProbe-2026-11-02-215036` — SIGBUS `0x800000008` = packed
  `{u32 8, u32 8}`, 3.10 прочитал его как VA; в 3.11 добавлен guard
  `(v & 0x3fff) != 0` и ограничение региона.

Стек: `agx_probe_user_va` <- `agx_map_probe` <- `gates_loop_inner`:
это AGX `sel2/4/5` info-запросы. Значит **AGX sel2/4/5 отдают
PAC-подписанные kernel-указатели**. 3.10 падал, потому что
дереференсил их; сами значения — **KASLR leak** без VM-race.

`newjail-2026-11-01-183404` SIGBUS `0x400000010`, `SPTM272Probe`
`EXC_GUARD INVALID_OPTIONS mach port 0`, `AllProbe` SIGABRT/watchdog —
userspace, не kernel. «Паники newjail» в логах нет: был jetsam/watchdog.

## 8. P7 — безопасный повтор AGX info

`SPTMProbe7.ipa` (на столе) повторяет `sel0..8` с **точными**
structureOutput (0x40/0x40/0x218/8/0x20/0x10) и
`scalarOutput=NULL` — той формой, которая в 3.10 сработала. Дамп всех
qword + флаг kernel/PAC, **без дереференса**. Это даст полный конфиг
`sel2` (0x218) с kernel-указателями и, возможно, paddr/TTBAT-полями.

---

## 9. P7 результат + P8/P9

`SPTMProbe7.log` (27.2, 24B115): type 1 открывается, `sel0..5` успешны,
`sel6/7/8` — `0xe00002c2` (метод есть, но аргументы не той формы):

```
sel0  (0x40)  +0x00 = 0x4340, +0x18 = 2, +0x20 = 0x100004000, +0x28 = 0xc0000000
sel1  (0x40)  "AGXG14P"
sel2  (0x218) +0x00 = 0x1030ec000, +0x08 = 0x0000000800000008,
              +0x10 = 0x0000008000000000, +0x18 = 0x0000000400000000,
              дальше таблица пар (offset, offset+4) с шагом 8
sel3  (0x08)  0
sel4  (0x20)  +0x00 = 0x4133cd48d, +0x08 = 0x103100000,
              +0x10 = 0x1030f4000, +0x18 = 0x4000
sel5  (0x10)  +0x00 = 0x4133cd48e, +0x08 = 0x4143cd48e
```

То есть AGX отдаёт **user VAs** своих shared-страниц (`0x1030ec000`,
`0x1030f4000/0x103100000`, size `0x4000`) и top-byte tagged handles
(`0x41...`). Это не kernel leak, но это структуры AGX, которые можно
читать из процесса.

- `SPTMProbe8.ipa` — читает эти user VAs через `mach_vm_region`
  (маска low 4 бит и top-byte 0x41..0x43), дампит 0x100 байт и ищет
  kernel/PAC qword. Без дереференса невалидных указателей.
- `SPTMProbe9.ipa` — то же + **создание IOGPU command queue**:
  `sel6`, `structureInput` ровно 0x408 Б (priority +0x400 < 5,
  bool +0x404/+0x405), `structureOutput` 0x10 Б. При успехе сразу
  `sel7` (scalarInput = queue id) — уничтожение. Проба на обоих
  сервисах, priority 0 и 1.

`sel6` — это ворота ко всему GPU job path: `sel25` (submit command
buffers) и `sel45` (submit IO commands) требуют queue id. Если P9
вернёт `kr=0`, следующий шаг — NOP-job и stamp.

## 10. IOUAT: как kernel строит segment list для SPTM

По strings kernelcache найдены и разобраны функции IOUAT
(`com.apple.kernel`, `__TEXT_EXEC`):

- `IOUAT::map(self, IOMemoryDescriptor*, ...)` @ `0xfffffff00a9ee318`.
  Лог: `IOUAT object %p map virt: %010llX length: 0x%llX options: 0x%llX`.
  Функция:
  1. требует `virt`/`length` кратными 0x4000;
  2. вызывает у descriptor'а `vt+0x90` с селекторами `0x01000001` и
     `0x01000000`, обходя physical segments;
  3. строит массив записей **0x20 байт**:
     `{ +0x00 = offset_в_маппинге, +0x08 = paddr, +0x10 = size,
        +0x18 = 0 }`
  4. кладёт его в kernel-буфер и вызывает PPL ioctl `MAP_BEGIN`.

  Ключевое: **paddr берётся из IOMemoryDescriptor**, то есть из
  физических страниц, которые kernel разрешил для этого descriptor'а.
  Пользователь задаёт только VA/len/options, не paddr.

- `IOUAT::unmap` @ `0xfffffff00a9ee8a4` — тот же формат segment list,
  `UNMAP_BEGIN` + `UNMAP_CONTINUE`.

- `IOUAT::mapToPhysicalAddress(self, va)` @ `0xfffffff00a9ec94c` —
  вызывает `vt+0x98`, возвращает `ret & 0xfffffffff000` (paddr).

- `IOUAT::getPageTableEntry(self, va)` @ `0xfffffff00a9ec9d0` —
  PPL ioctl `0xbee5`, input 8 Б (VA), output 8 Б (PTE).

PPL ioctl IDs, найденные в IOUAT-коде:

| ID | функция |
|---|---|
| 0xbee0 | init/allocate state |
| 0xbee1 | SET_CONTEXT_ID |
| 0xbee2 | REMOVE_CONTEXT_ID / TASK_DIED |
| 0xbee3 | PREPARE_UNMAP |
| 0xbee4 | GET_ROOT_TABLE |
| 0xbee5 | GET_PT_ENTRY |
| 0xbee6 | TOTAL_PT_MEM |
| 0xbee7 | FAULT_EXPECTED |

SPTM-сторона (`sptm.macho`, база `0xfffffff027004000`; в таблице
`0x2701c148` хранятся **смещения от базы**, не готовые VA):

| endpoint | реальный VA |
|---|---|
| MAP_CONTINUE | `0xfffffff0270adf30` |
| PREPARE_FW_UNMAP_BEGIN | `0xfffffff0270add94` |
| PREPARE_FW_UNMAP_CONTINUE | `0xfffffff0270ad8f0` |
| UNMAP_BEGIN | `0xfffffff0270ad5d8` |
| UNMAP_CONTINUE | `0xfffffff0270ac7b8` |
| SET_CTX_ID | `0xfffffff0270ac43c` |
| REMOVE_CTX_ID | `0xfffffff0270abc74` |
| GET_INFO | `0xfffffff0270ab9e0` |
| REVOKE_SAPT_MULTIPAGE | таблица/данные `0xfffffff02710334` |

`MAP_BEGIN` @ `0xfffffff0270ae700` и `UNMAP_BEGIN` @
`0xfffffff0270ad5d8` принимают **paddr массива сегментов** и count,
копируют `count*0x10` байт в state-страницу SPTM, затем вызывают
CONTINUE. `SET_CTX_ID` пишет root-table paddr в глобальную таблицу
контекстов `[ctxid<=0x3f]`, только если слот свободен.

## 11. Проверка gpu-region-base в MAP_CONTINUE

В `FUN_fffffff0270adf30` (MAP_CONTINUE), на каждой 16K-странице:

```
uVar19 = paddr & 0xfffffffff000;
type   = table[ (flags>>8 & 3) | ((flags & 3) << 2) ];   // 3-битный индекс
special = (type & 0xf) in {2,3,5,6,7,9,10};

if (uVar19 == gpu_region_base && special)
        VIOLATION_UAT_ILLEGAL_TTBAT_MAPPING/LOCK;
if (uVar19 != gpu_region_base)
        FUN_fffffff0270e1168(paddr, type);   // обычная проверка FTE
*pte = ... | uVar19 | ...;                   // PTE пишется в любом случае
```

То есть при `paddr == gpu-region-base` и **не-special** типе маппинга
SPTM **пропускает и violation, и FTE-проверку**, но всё равно пишет
PTE. Это реальный skip, но он срабатывает только на точное равенство
`paddr == 0x04D00000` (кандидат из `sgx.reg[1]`), а paddr в segment
list приходит из IOMemoryDescriptor. Пользовательские страницы никогда
не имеют paddr `0x04D00000` (это device/GPU carveout ниже DRAM).
Значит путь требует **descriptor с физическим адресом**, а не обычного
user-буфера. Это и есть недостающее звено; sel8/AGX resource descriptor
сейчас проверяется статически.

## 12. Честный статус

- Полного SPTM bypass на 27.2 **пока нет**.
- Закрыто: Coruna/TTBR1/hibernation (патч `sanitize_integer` + HMAC),
  P4 map-memory, Scaler 0x1b0 physical, IOUAT paddr из user VA.
- Открыто: (а) IOGPU sel6 queue -> sel25/45 raw GPU job -> stamp в
  GPU VA, если TTBAT/GPU-region замаплен в GPU address space;
  (б) sel8 resource descriptor с полем paddr; (в) SPTM skip
  `gpu-region-base` при не-special типе, если найдётся путь подать
  device paddr в segment list.
- Следующие IPA: P8 (чтение AGX shared-страниц) и P9 (sel6 queue).

## 13. P10 — Metal unified-VA / GPU OOB (новый заход)

SPTM UAT — это **Unified Address Translation**: MAP_CONTINUE копирует
PTE из user page table в GPU page table. Если GPU VA совпадает с user
VA, то Metal-буфер доступен GPU по тому же адресу, что и CPU.

Тогда можно проверить GPU MMU без IOGPU-селекторов: compute-шейдер
берёт `device uint *a`, считает `(device char*)a + delta` и пишет
туда. Если `delta = B.contents - A.contents` и GPU VA == CPU VA,
запись попадёт в буфер B, хотя формально это OOB за пределы A.

`SPTMProbe10.ipa` делает три теста:
1. `a[0]` (delta 0) — sanity;
2. `delta = B-A` — главный тест;
3. `delta = 0x4000` — диагностика (mapped / GPU fault).

Если тест 2 даёт hit `0xdeadbeef` в B:
- user VA == GPU VA для Metal-буферов;
- GPU MMU не режет OOB-указатель;
- можно прицелиться шейдером в **любой известный user VA**, включая
  AGX shared-страницы из P8 и, если TTBAT замаплен в GPU address
  space, в его GPU VA.

Это не требует kernel r/w и не требует sel6/25/45. Если же тест 2
не даёт hit, значит GPU VA отдельный, и остаётся путь P9 (IOGPU
queue + raw job) либо поиск GPU VA через sel2-таблицу.

Риск: тест 3 может вызвать GPU fault (command buffer error) или
повесить приложение; ядро/ОС при этом не затрагиваются, запись идёт
только в GPU VA-пространство нашего контекста.

## 14. Артефакты на столе

| Файл | Что |
|---|---|
| `SPTMProbe8.ipa` | чтение AGX shared user VAs |
| `SPTMProbe9.ipa` | P8 + IOGPU sel6 queue create/destroy |
| `SPTMProbe10.ipa` | Metal unified-VA / GPU OOB тест |
| `SPTMProbe8_10_README.txt` | инструкция и что означают логи |

## 15. IOSurfaceAddress (GMAP) — кандидат, в P10 не включён

Проверка legacy-пути IOSurfaceRoot (`IOSurfaceAddress` +
`IOSurfaceAllocSize`) — потенциальный kernel r/w, **но в P10 не
включена**. Причина: если ключ трактуется как physical address, а мы
передаём user VA (0x10... ниже 6 ГБ DRAM), surface может получить
чужую физическую страницу, а release — освободить её. Это риск
повреждения kernel memory, а не просто GPU fault. Нужен отдельный
прогон с явного согласия Kai и сначала read-only kernel text.

Исторически тест выглядел так:
`IOSurfaceAddress` + `IOSurfaceAllocSize` в XML (публичный
`IOSurfaceCreate` и приватный `sel7`). Передаётся **только user-буфер**;
в лог пишется, вернулся ли `base == requested`. Если `honored=1`,
значит на 27.2 ключ адреса ещё работает, и следующий шаг — тот же
sel7 с paddr/kernel VA (сначала read-only kernel text
`0xfffffff007004000`, потом запись). Это не SPTM-путь, но он даёт
kernel r/w, без которого SPTM-таргеты (`gpu-region-base`,
`SET_CTX_ID`, `MAP_BEGIN root paddr`) недостижимы из песочницы.

Если `honored=0` — путь закрыт, остаётся GPU job path (P9/P11).
Если `honored=1` — sel7 с kernel VA (сначала `0xfffffff007004000`,
read-only) и проверка Mach-O magic. Это отдельный IPA, не P10.

## 16. Откуда SPTM берёт gpu-region-base (подтверждено кодом)

`FUN_fffffff0270afb68` (UAT global init) ищет в **SecureDT** узел
`/arm-io/sgx` и читает оттуда:

| свойство | проверка | куда пишется |
|---|---|---|
| `agx-address-space-mgmt-mode` | 4 Б | `uat+0x10` |
| `gfx-shared-region-base/size` | 8 Б, size кратен 0x4000 | `uat+0x108/0x110` |
| `gfx-shared-l2-region-*` | 8 Б | `uat+0x118/0x120` |
| **`gpu-region-base`** | **8 Б** | **`uat+0x68`** |
| **`gpu-region-size`** | **8 Б, >=0x4000 и кратен 0x4000** | **`uat+0x70` (>>14)** |
| `uat-vaddr-size` | 4 Б, 0x28..0x30 | `uat+0x1b1` |
| `uat-segment-limit` | 4 Б, default 0x40 | `uat+0x1c0` |
| `uat-mapping-limit` | 4 Б | `uat+0x1c8` |

`/defaults/uat-enforce-gpu-carveout` (4 Б, default 1) -> `uat+0x1b0`.

После чтения SPTM делает `phystokv(gpu-region-base)` -> `uat+0x78` и
вызывает `FUN_fffffff0270dffd4(base, size>>14, 2)` — это подготовка
TTBAT-региона (8 страниц по 16 КБ при `size=0x20000`).

**Вывод:** `gpu-region-base` — это SecureDT-свойство, которого нет в
публичном IORegistry и в статическом `DeviceTree.d27ap.im4p`.
Единственный кандидат — `sgx.reg[1] = {0x04D00000, 0x20000}`; его
размер ровно 8 x SPTM_PAGE_SIZE, что совпадает с проверкой
`gpu-region-size`. P10 проверяет `0x04D00000` GPU-чтением.
