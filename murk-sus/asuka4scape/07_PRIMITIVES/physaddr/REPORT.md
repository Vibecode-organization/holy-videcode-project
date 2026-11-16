# physical vs virtual: `IOMemoryDescriptor::withAddressRange` в AppleM2ScalerCSCDriver

Kernelcache: `27.2_24B115_kernelcache` (MH_FILESET, 250 kext, flat-карта `fo = va - 0xfffffff007004000`, но у kext-сегментов свой сдвиг: `fo = va - 0x700000`).
Все адреса ниже — полные VA. Инструмент: capstone, ручной парсер fileset/segments, декодер chained-fixup (`auth` = бит 63, `bind` = 62, `next` = 51..61, target 32 бита = смещение от `0xfffffff007004000`).

## 0. Вердикт (коротко)

**Примитива «маппинг произвольной физической памяти из песочницы» в `AppleM2ScalerCSCDriver` нет.**
Все 7 вызовов `withAddressRange` в kext берут `task` из одного поля — `[obj+0x130]`. У user client это `owningTask` из `newUserClient` (всегда непустой) → в `0xa97ae84` уходит тип **0x10 (virtual64)**. `task == 0` достижим только у **kernel client**, который создаётся фабрикой **без** task (`0x8d13a6c`) и наружу не отдаётся.
Кросс-kext: 120 точек вызова, из них **4** с явным `task = NULL` (IOPCIFamily ×2, IOMobileGraphicsFamily-DCP, IOSurface) — там адрес/длина приходят из kernel-полей (BAR, прошивка, бэкенг поверхности), user-u64 в них не уходит.

## 1. Целевая функция `0xfffffff00a97ae84`

Символ из `__LINKINFO`: `__ZN18IOMemoryDescriptor16withAddressRangeEyyjP4task`
(`unsigned long long, unsigned long long, unsigned int, task*`).

```
fffffff00a97ae84: pacibsp
fffffff00a97ae88: sub      sp, sp, #0x30
fffffff00a97ae8c: stp      x20, x19, [sp, #0x10]
fffffff00a97ae90: stp      x29, x30, [sp, #0x20]
fffffff00a97ae94: add      x29, sp, #0x20
fffffff00a97ae98: mov      x19, x3          ; x19 = task
fffffff00a97ae9c: mov      x20, x2          ; x20 = options/direction
fffffff00a97aea0: stp      x0, x1, [sp]     ; addr, len
fffffff00a97aea4: adrp     x0, #0xfffffff00ad97000
fffffff00a97aea8: add      x0, x0, #0x200   ; метакласс IOGeneralMemoryDescriptor
fffffff00a97aeac: ldr      x16, [x0]
fffffff00a97aeb0: mov      x17, x0
fffffff00a97aeb4: movk     x17, #0xcda1, lsl #48
fffffff00a97aeb8: autda    x16, x17
fffffff00a97aebc: ldr      x8, [x16, #0x68]!
fffffff00a97aec0: movk     x16, #0x1601, lsl #48
fffffff00a97aec4: blraa    x8, x16         ; alloc()
fffffff00a97aec8: cbz      x0, #0xfffffff00a97af44
fffffff00a97aecc: cmp      x19, #0          ; <<< task == 0 ?
fffffff00a97aed0: mov      w8, #0x10
fffffff00a97aed4: mov      w9, #0x20
fffffff00a97aed8: csel     w8, w9, w8, eq   ; task==0 -> 0x20 (physical64), иначе 0x10 (virtual64)
fffffff00a97aedc: ldr      x16, [x0]
fffffff00a97aee0: mov      x17, x0
fffffff00a97aee4: movk     x17, #0xcda1, lsl #48
fffffff00a97aee8: autda    x16, x17
fffffff00a97aeec: ldr      x9, [x16, #0x78]!   ; initWithAddressRange
fffffff00a97aef0: mov      x1, sp
fffffff00a97aef4: orr      w5, w8, w20        ; flags = type | options
fffffff00a97aef8: mov      x20, x0
fffffff00a97aefc: mov      w2, #1
fffffff00a97af00: mov      w3, #0
fffffff00a97af04: mov      x4, x19            ; task
fffffff00a97af08: mov      x6, #0
fffffff00a97af0c: movk     x16, #0xfe46, lsl #48
fffffff00a97af10: blraa    x9, x16
fffffff00a97af14: tbz      w0, #0, #0xfffffff00a97af20
fffffff00a97af18: mov      x0, x20
fffffff00a97af1c: b        #0xfffffff00a97af44
```

Т.е. `withAddressRange(addr, len, dir, task)`:
* `task != 0` → тип **0x10** — адрес трактуется как **virtual64 адрес этого task**;
* `task == 0` → тип **0x20** — адрес трактуется как **physical64**.

Трамплин: GOT-слот `0xfffffff007e60f08` (`__DATA_CONST` kext) = auth-rebase на `0xfffffff00a97ae84` (raw `0x8011000003976e84`), `next=2`.
Вход — `0xfffffff008e00070` (`adrp x17,#0x7e60000; add x17,x17,#0xf08; ldr x16,[x17]; braa x16,x17`). Соседние слоты `+0xf10/+0xf18/+0xf20/+0xf28/+0xf30` — соседние фабрики IOMemoryDescriptor.

## 2. Все вызовы в AppleM2ScalerCSCDriver (7 точек)

`self` = объект `IOSurfaceAcceleratorClient`. `task` во всех — `[self+0x130]`.

| # | точка вызова | функция | адрес (x0) | длина (x1) | dir | task | вердикт |
|---|---|---|---|---|---|---|---|
| 1 | `0x8d13e44` | helper `0x8d13dec` (из sel4) | `[in+0x18]` | `2*(w24*w25+w21*w22)*4` | 2 | `[self+0x130]` | virtual64 |
| 2 | `0x8d14d3c` | **sel7** `0x8d14ce0` | `[structIn]` | `[self+0x150]` | 3 | `[self+0x130]` | virtual64 |
| 3 | `0x8d14fec` | **sel8** `0x8d14f84` | `[structIn]` | `0x7c*(cfg+0x40/0x200)+0x20` | 1 | `[self+0x130]` | virtual64 |
| 4 | `0x8d150a8` | **sel9** `0x8d15064` | `[structIn+0]` | `0x1b0` | 3 | `[self+0x130]` | virtual64 |
| 5 | `0x8d150c4` | **sel9** | `[structIn+8]` | `0x18` | 3 | `[self+0x130]` | virtual64 |
| 6 | `0x8dbbebc` | helper `0x8dbbd78` (из `0x8dbc6d0`, init/DT-путь) | `[tab+8]` (tab=`self+0xdf0`, stride 0x28) | `[tab+0x10]` | 3 | `[[self+0x50]+0x130]` | physical **если** kernel client |
| 7 | `0x8dbbfac` | helper `0x8dbbd78` | `[tab+0x18]` | `[tab+0x20]` | 3 | `[[self+0x50]+0x130]` | то же |

`dir`: 1 = In (ядро читает user-память), 2 = Out, 3 = InOut.

### Таблица селекторов — `0xfffffff007e3b738`, 12 × 0x30

Читается через `getExternalMethodDispatch 0x8d13c38` (`cmp w2,#0xb` → 0..11, `umull` стрид 0x30). Поля: `+0x00` = 0, `+0x08` = fn (auth-указатель), `+0x10` = 0, `+0x18` = shape (3 = есть structIn), `+0x20` = structInSize (`0xffffffff` = любой), `+0x28` = прочее.

| selector | fn | structInSize | что делает | withAddressRange | вердикт |
|---|---|---|---|---|---|
| 0 | `0x8d14ee0` | 0xffffffff | `ret 0xe00002c7` (unsupported) | — | — |
| 1 | `0x8d1475c` | 0x1b0 | commandGate, `0x8d56c60` | — | — |
| 2 | `0x8d14ef0` | 0 | заглушка | — | — |
| 3 | `0x8d14f00` | 0 | заглушка | — | — |
| 4 | `0x8d14c7c` | 0x20 | → `0x8d14888` (custom filter) → helper | да, `[in+0x18]`, len из полей | virtual64 |
| 5 | `0x8d14c1c` | 0 (flags=1) | u32 провайдера | — | — |
| 6 | `0x8d14e8c` | 0xfa8 | гейт `[in]<=0x3e8` | — | — |
| **7** | `0x8d14ce0` | 8 | user-u64 → mdesc len `[self+0x150]` dir 3 → `0x8d5cfdc(scaler, self, desc)` | да | **virtual64** (task=owningTask) |
| **8** | `0x8d14f84` | 8 | user-u64 → mdesc len из конфига dir 1 → `0x8d5d094` | да | **virtual64** |
| **9** | `0x8d15064` | 0x10 | два user-u64 → 2 mdesc (0x1b0 / 0x18) dir 3 | да | **virtual64** |
| 10 | `0x8d15230` | 0x18 | u32<4 → `+0x168`, 16 Б → `+0x170` | — | — |
| 11 | `0x8d152d0` | 0 (`0xffffffff`) | memcpy из `[[p+0x150+slot*8]+0xb8]` | — | — |

sel7 (`0x8d14d3c`) целиком:

```
0x8d14cf8: ldr   w8, [x0, #0x164]      ; busy/assert-флаг
0x8d14cfc: cbnz  w8, 0x8d14df4
0x8d14d0c: ldrb  w8, [x0, #0x160]
0x8d14d10: tbz   w8, #0, 0x8d14d2c    ; (писателей бита в бинаре нет)
0x8d14d2c: ldr   x0, [x1]              ; <<< user-u64 -> адрес
0x8d14d30: ldr   w1, [x21, #0x150]     ; длина из клиента
0x8d14d34: ldr   x3, [x21, #0x130]     ; <<< task
0x8d14d38: mov   w2, #3                ; InOut
0x8d14d3c: bl    0x8e00070             ; withAddressRange
0x8d14d40: cbz   x0, 0x8d14d90
0x8d14d60: ldr   x8, [x16, #0xd8]!     ; prepare()
0x8d14d98: ldr   x0, [x21, #0x100]     ; scaler
0x8d14da4: bl    0x8d5cfdc             ; привязка дескриптора
```

sel9 (`0x8d15064`):

```
0x8d15088: cmp   x2, #0x10
0x8d15098: ldr   x0, [x1]              ; user-u64 #1
0x8d1509c: ldr   x3, [x22, #0x130]     ; task
0x8d150a0: mov   w1, #0x1b0
0x8d150a4: mov   w2, #3
0x8d150a8: bl    0x8e00070
0x8d150b4: ldr   x0, [x21, #8]         ; user-u64 #2
0x8d150b8: ldr   x3, [x22, #0x130]     ; task
0x8d150bc: mov   w1, #0x18
0x8d150c0: mov   w2, #3
0x8d150c4: bl    0x8e00070
```

## 3. Откуда берётся `task` = `[client+0x130]`

Записей в `+0x130` во всём kext **две**:

* `0x8d14068` `str x23, [x19, #0x130]` — фабрика **с** task;
* `0x8d1396c` `str xzr, [x19, #0x130]` — деструктор (обнуление, без release — task не retain'ится).

Значит любой объект, созданный **не** через первую фабрику, имеет `+0x130 == 0` → physical.

### Фабрика с task: `0x8d13ff8`

```
0x8d14028..0x8d14048: alloc() через метакласс
0x8d14054: mov x0, x19 ; mov x1, x24 ; mov w2, #0
0x8d14060: bl  0x8d13820              ; ctor(obj, provider, 0)
0x8d14068: str x23, [x19, #0x130]     ; <<< task = x1 фабрики
0x8d14090: mov x2, x22 ; mov x3, x21 ; mov x4, x20
0x8d140a0: blraa [vtable+0x550]       ; initWithTask(task, secid, type, props)
```

**Вызывающий найден** (в прошлом отчёте `surf_lookup` он значился «не подтверждён»): единственный указатель на `0x8d13ff8` — не `bl`, а элемент таблицы указателей
`0xfffffff007e4adb0` → `0xfffffff008d55e4c` (raw `0x801182cd01d51e4c`). Это слот **+0x460** vtable'а `0xfffffff007e4a950` (kext-класс; рядом в таблице — только kernel-методы IOService).

```
0x8d55e4c: bti c / pacibsp
0x8d55e6c: ldrb  w8, [x0, #0x88]      ; self->started
0x8d55e70: tbz   w8, #0, err
0x8d55e74: mov   x22, x5              ; &handler
0x8d55e78: mov   x21, x0              ; self
0x8d55e7c: bl    0x8d13ff8            ; withTask(self=provider, x1=task, x2=secid, x3=type, x4=props)
```

ABI совпадает с `IOService::newUserClient(owningTask, securityID, type, properties, &handler)` (`self` в x0, task в x1, handler в x5), а `initWithTask` получает тот же x1 первым аргументом. **Следствие: у user client'а `+0x130` = `owningTask` вызывающего процесса, т.е. никогда не 0 → тип 0x10 (virtual64).**

### Фабрика без task: `0x8d13a6c`

```
0x8d13a84: str  xzr, [sp, #8]
0x8d13ad0: tbz  w0, #0, err
0x8d13ad4: add  x0, sp, #8
0x8d13ad8: bl   0x8d13b7c            ; waitForService("AppleM2ScalerCSCDriver") + copyProperty
0x8d13ae0: ldr  x1, [sp, #8]
0x8d13af0: bl   0x8d13820            ; ctor(obj, prop, 1)
0x8d13af4: tbz  w0, #0, ...
...
0x8d13b60: mov  x0, x19              ; return obj   (+0x130 НЕ пишется => 0)
```

Вызывается 5 раз из инициализации драйвера: `0x8d092cc`, `0x8d09ad4`, `0x8d09c44`, `0x8d09ea4`, `0x8d0a1c0` (создание пула kernel-клиентов на скалеры). Это единственный источник `+0x130 == 0`.

Побочный факт: `0x8dbbd78` (точки 6/7) берёт `task` из `[[driver+0x50]+0x130]` — то есть из kernel-клиента, и таблица `driver+0xdf0` (4 × 0x28: `{u32 type, u64 addr, u32 len, u32 ?, u64 ptr, u32 size}`) — это firmware/MSR-блоки драйвера, не user-данные. Путь исполняется из `0x8dbc6d0` (инициализация/DT-property), не из селекторов.

## 4. Кросс-kext: тот же паттерн у соседей

Всего `withAddressRange` импортируют **33 kext'а** (GOT-слот с auth-rebase на `0xa97ae84`), найдено **120** точек `bl` на их трамплины.

Явный `mov x3, #0` (physical) — **4 точки**:

| kext | точка | что маппит | адрес откуда | вердикт |
|---|---|---|---|---|
| `com.apple.iokit.IOPCIFamily` | `0x9b4747c` | PCI BAR (`_CopyDeviceMemoryWithIndex`) | `[dev+0x98]` BAR base + offset, kernel | physical, kernel-controlled |
| `com.apple.iokit.IOPCIFamily` | `0x9b47fc8` | то же | то же | physical, kernel-controlled |
| `com.apple.iokit.IOMobileGraphicsFamily-DCP` | `0x9a7c090` | DCP firmware/поверхность | поля объекта | physical, kernel-controlled |
| `com.apple.iokit.IOSurface` | `0x9c1ebf8` | бэкенг поверхности | `ldp x0,x1,[surf+0x158]` (addr,len) | physical, если `[surf+0x170]==0` |

IOSurface, ключевой фрагмент (`0x9c1ea68`):

```
0x9c1ea68: ldp   x0, x1, [x19, #0x158]   ; addr, len поверхности
0x9c1ea74: ldr   x16, [x19, #0x170]      ; task-ссылка поверхности
0x9c1ea78: cbz   x16, 0x9c1ebf0
0x9c1ebf0: mov   x3, #0                  ; <<< task = NULL -> physical64
0x9c1ebf4: orr   w2, w8, w9
0x9c1ebf8: bl    0x9c49964               ; withAddressRange
```

Остальные 116 точек передают task из поля объекта (`ldr x3,[xN,#0xd8/#0xe0/#0x30/...]`) либо регистр, пришедший аргументом; ни одна не передаёт `xzr`. Массив `[+0x158/+0x160/+0x170]` заполняется при создании поверхности — из userland адрес туда не приходит; **не подтверждено**, что существует путь, где `+0x170 == 0` и `+0x158` задан пользователем (кандидат на отдельный разбор IOSurface).

Семейства `AppleM2ScalerCSCHal*` отдельными kext'ами не существуют: все 30+ классов (`AppleM2ScalerCSCHalMSR2..30`, `M2ScalerSrcDestCfgControl*`, `M2ScalerCSCColorConversionControl*`, `IOSurfaceAcceleratorClient`, `IOSurfaceAcceleratorKernelClient`) лежат **внутри** `com.apple.driver.AppleM2ScalerCSCDriver`; других импортёров `withAddressRange` из этого семейства нет.

## 5. Итог

* `task == 0` в этом kext достижим — да, но только у kernel-клиентов, созданных фабрикой `0x8d13a6c` (5 точек в `start`-пути драйвера).
* Пользовательский адрес в такой вызов не попадает: селекторы 4/7/8/9 работают на объекте, у которого `+0x130 = owningTask != 0`.
* Значит **чтения/записи ядра через physical-маппинг из песочницы здесь нет**.
* Косвенно подтверждено, что physical-ветка рабочая: драйвер сам ей пользуется для firmware-блоков (`0x8dbbd78`, task из kernel-клиента).

## 6. Не подтверждено / следующий шаг

1. `[driver+0x50]` — что это за объект (kernel client или промежуточный); проверяется по единственной записи `str xN,[xM,#0x50]` в `start`-пути. На вердикт не влияет (адреса таблицы kernel-controlled).
2. IOSurface `0x9c1ebf8`: кто и из каких аргументов пишет `[surf+0x158]/+0x160/+0x170`. Если найдётся user-API, задающий physical-адрес при `+0x170 == 0` — это готовый примитив (kext `com.apple.iokit.IOSurface`, доступен из песочницы).
3. Лимит `[self+0x150]` (длина в sel7) — где ставится; интересует только для полноты (на тип адреса не влияет).

Файлы: `kc.py` (парсер/карта), `kdis.py`, `xref.py`, `tramp.py`, `callsites.json`, `x3.json`.
