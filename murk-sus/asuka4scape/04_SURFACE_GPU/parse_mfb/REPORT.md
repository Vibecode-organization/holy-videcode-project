# IOMobileFramebufferUserClient / AppleKeyStoreUserClient / IOGPUDeviceUserClient (restricted)

target: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (67 239 936 B)
ветка: subagent G (после D). Всё ниже — только то, что прострелено по байтам этого файла.

---

## 0. Метод и общие опоры

### 0.1 Декодирование указателей

| вид | формула | проверено на |
|---|---|---|
| code/const ptr (PAC, key `0xbcad`) | `VA = 0xfffffff007004000 + (q & 0x0FFFFFFF)` | `0x8050bcad02a9fc14` → `0x9aa3c14` |
| class-name string | `adrp/add` в `__PRELINK_TEXT` | `0xfffffff00785cff5` = `"IOMobileFramebufferUserClient"` |
| `size` класса | аргумент `mov w3,#imm` перед `bl OSMetaClass::OSMetaClass` | MFB `#0x958`, KeyStore `#0x118` |

### 0.2 Слот `externalMethod` в vtable = **+0x550** (байтовое смещение, индекс 170)

Доказано тремя независимыми точками:

| класс | адрес слота | значение |
|---|---|---|
| `IOUserClient` (база) | `0xfffffff007c3aa58` | `0xa9a18bc` `IOUserClient::externalMethod` |
| `IOGPUDeviceUserClient` | `0xfffffff007fea0c8` | `0x994a1dc` (свой override) |
| `IOSurfaceRootUserClient` | `0xfffffff008068af0` | `0x9c3ee10` (свой override) |

`0xa9a18bc` читает `[x3+8]` (checkScalarInputCount) и `[x2+0x28]` (scalarInputCount) — это
и есть эталонная валидация IOKit, по ней сверена раскладка ниже.

### 0.3 `IOExternalMethodArguments` — подтверждено по коду, а не по памяти

| off | поле | где видели |
|---|---|---|
| +0x04 | selector | `IOGPU` берёт селектор из `w1`, `IOSurface`/MFB тоже |
| +0x10 | asyncReference | IOGPU: `ldr x9,[x2,#0x10]; cbnz → 0xe00002d8` |
| +0x20 | scalarInput (`u64*`) | MFB sel 0x44: `ldr x8,[x2,#0x20]; ldr w19,[x8]` |
| +0x28 | scalarInputCount | `0xa9a18bc`, MFB-валидатор |
| +0x30 | structureInput | MFB sel 0x4e: `ldr x19,[x2,#0x30]` |
| +0x38 | structureInputSize | MFB валидатор, KeyStore `0x9aa42dc` |
| +0x40 | structureInputDescriptor | `0xa9a18bc` + MFB валидатор |
| +0x48/+0x50 | scalarOutput / count | KeyStore свёрка `[x21,#0x50]` |
| +0x58/+0x60 | structureOutput / size | MFB sel 0x4f, IOGPU sel 8 |
| +0x68/+0x70 | structureOutputDescriptor / count | MFB валидатор, KeyStore sel 162 |

> **Поправка к отчёту D:** утверждение «у `IOMobileFramebufferUserClient` нет таблиц,
> ручной `switch`» — **неверно**. У класса есть таблица на 101 запись и свой валидатор
> (см. §1). Ручной `switch` есть у `AppleKeyStoreUserClient`, но это не `cmp`-цепочка,
> а относительная таблица переходов (см. §2).

---

## 1. `IOMobileFramebufferUserClient` (`com.apple.iokit.IOMobileGraphicsFamily`)

* `sizeof` = `0x958` (мета-конструктор `0x9aa0f2c`, `bl OSMetaClass::OSMetaClass` в `0x9aa0f48`)
* vtable класса = **`0xfffffff008023458`** (заканчивается на `0x80239d0`, дальше vtable метакласса)
* слот `0x550` = `0xfffffff0080239a8` → **`externalMethod = 0xfffffff009aa33b8`**

### 1.1 `externalMethod` — 12 инструкций, дальше всё в общий валидатор

```
0x9aa33b8  bti c ; pacibsp ; frame
0x9aa33d0  mov x20, x2            ; args
0x9aa33d4  mov x21, w1            ; selector
0x9aa33d8  mov x19, x0            ; this
0x9aa33dc  ldr x0, [x0, #0xd8]    ; this->framebuffer  (без cbz!)
0x9aa33e0  ldr x16, [x0]          ; vtable fb
0x9aa33ec  autda x16, x0|0xcda1
0x9aa33f0  mov x17, #0x5c0
0x9aa33f4  add x16, x16, x17      ; fb->vtable[0x5c0]
0x9aa33f8  ldr x8, [x16]
0x9aa3400  blraa x8, x16          ; w0 = fb->state_ok()
0x9aa3404  cbz  w0, 0x9aa3418     ; 0 -> диспетчеризация
0x9aa3408  ... retab              ; иначе вернуть w0 как есть
0x9aa3418  adrp x3, 0x8023000
0x9aa341c  add  x3, x3, #0xad0    ; x3 = &table[0]
0x9aa3420  mov  x0, x19           ; self
0x9aa3424  mov  x1, x21           ; selector
0x9aa3428  mov  x2, x20           ; args
0x9aa342c  mov  w4, #0x65         ; count = 101
0x9aa3430  mov  x5, x19           ; target
0x9aa3434  mov  x6, #0            ; reference
0x9aa3454  b    0x9abd40c         ; GOT-трамплин -> 0xa9b0888 (валидатор)
```

`0xd8` не проверяется на NULL — теоретический NULL-deref, но объект создаётся только
вместе с framebuffer'ом (`0x9aa1658`: `ldr x1,[GOT 0x8024ae8]; bl 0x9abd3dc; str x0,[x19,#0xd8]`),
поэтому ветка **недостижима**.

### 1.2 Валидатор `0xfffffff00a9b0888` — самописный `IOExternalMethodDispatch`

Сигнатура: `(this, selector, args, table, count, target, reference)`.

```
0xa9b08a0  w0 = 0xe00002c2                     ; kIOReturnBadArgument
0xa9b08a8  cbz x3, err(-6)                     ; нет таблицы -> 0xe00002bc
0xa9b08ac  mov w8, w1
0xa9b08b0  cmp x4, x8
0xa9b08b4  b.ls err                            ; selector >= count -> 0xe00002c2
0xa9b08b8  add x8, x8, x8, lsl #2              ; sel*5
0xa9b08bc  add x20, x3, x8, lsl #3             ; &table[sel*0x28]
0xa9b08d0  w8 = entry[+0x08]                   ; checkScalarInputCount
0xa9b08d4  cmn w8, #1 ; b.eq skip              ; 0xffffffff = не проверять
0xa9b08dc  w9 = args->scalarInputCount (+0x28)
0xa9b08e4  b.ne err                            ; не равно -> отказ
0xa9b08e8  w19 = entry[+0x0c]                  ; checkStructureInputSize
0xa9b08f0  b.eq 0xa9b0970                      ; -1 -> не проверять
0xa9b08f4  x8 = args->structureInputDescriptor (+0x40)
0xa9b08f8  cbz x8, use_size
0xa9b090c  x9 = [x8->vtable + 0xb0]            ; IOMemoryDescriptor::getLength()
0xa9b0924  blraa -> x0 = length
0xa9b0940  cmp x8, x19 ; b.ne err              ; длина дескриптора != объявленной
0xa9b0964  w8 = args->structureInputSize (+0x38)   ; дескриптора нет -> сверить size
0xa9b096c  b.ne err
0xa9b0970  ... то же для +0x10/+0x50 (scalarOut) и +0x14/+0x60..0x68 (structOut)
0xa9b09f8  x8 = args->asyncReference (+0x08) ; если не 0 -> entry[+0x18] должен быть !=0
0xa9b0a08  x19 = entry[+0x20]                  ; тегированное поле (см. §1.5)
0xa9b0a78  x16 = entry[+0x00]                  ; fn
0xa9b0a7c  cbz x16 -> 0xe00002ea               ; дырка в таблице
0xa9b0a80  x0 = target ; x1 = reference
0xa9b0aa0  braa x16, #0xbcad                   ; fn(target, reference, args)  [x2 не тронут]
```

Запись таблицы (stride `0x28`), восстановлена по коду валидатора:

```
+0x00  fn                          (PAC, key 0xbcad)
+0x08  u32 checkScalarInputCount   (0xffffffff = не проверять)
+0x0c  u32 checkStructureInputSize
+0x10  u32 checkScalarOutputCount
+0x14  u32 checkStructureOutputSize
+0x18  u8  разрешён asyncReference
+0x20  u64 тег (0 у всех, кроме sel 0x56/0x64)
```

**Вывод по валидатору:** размеры сверяются *точно* и в обе стороны; при наличии
дескриптора приоритет у `getLength()`, а не у объявленного `structureInputSize`.
Это сильнее, чем дефолтный `IOUserClient::externalMethod` (тот сверяет только
`structureInputSize`, не длину дескриптора).

### 1.3 Таблица: `0xfffffff008023ad0`, **101 запись** (sel 0x00..0x64), конец `0x8024a78`

Полный дамп: `mfb_selectors.tsv`. Сводка:

* 94 записи с точными размерами; `-1` (без проверки) — **7**: sel `0x44, 0x4e, 0x4f, 0x55, 0x56, 0x63, 0x64`.
* sel `0x01,0x02,0x09,0x15,0x20,0x24..0x28,0x2d,0x2e,0x3a` → заглушка `0x9aa53b8`
  (`mov w0,#1; ret` / `0xe00002c7` в зависимости от точки входа) — «принято, ничего не делаю».
* sel `0x3b..0x41, 0x46, 0x47` (9 записей) — `fn == NULL` → валидатор отдаёт `0xe00002ea`. **Недостижимо.**
* sel `0x05` требует `strInSize == 0x6e0` (1760 Б) — самый большой вход.
* sel `0x38` требует `strInSize == 0x9c`; sel `0x45` — `0x88`; sel `0x4b` — `0x8008`.

### 1.4 Разбор sel `0x44` (`0x9aa42dc`) — единственный вход, где пользователь задаёт «опкод»

```
0x9aa42fc  x8 = args->scalarInput        ; +0x20
0x9aa4300  w19 = *(u32*)x8               ; <- opcode от пользователя
0x9aa4304  w8  = args->structureInputSize; +0x38   (в таблице -1, те. не проверен)
0x9aa4308  w20 = w8 >> 3                 ; «сколько u64 пришло»
0x9aa430c  cmp w19, #0x11 ; b.ne ...
0x9aa4314  x0 = this->[0xe8]             ; task
0x9aa4318  x1 = "com.apple.<...>" @0x785d744
0x9aa4320  bl 0x9abd1cc                  ; IOTaskHasEntitlement
0x9aa4324  cbnz w0, ok
0x9aa4328  w0 = 0xe00002c1               ; kIOReturnNotPrivileged
0x9aa4340  cmp w19,#1 ; ccmp w20,#2,#0,eq
0x9aa4348  b.eq  case_1
0x9aa434c  cmp w19,#0xb ; b.ne default
0x9aa4354  x8 = *(u64*)args->structureInput   ; +0x30, без проверки указателя на NULL!
0x9aa435c  cbz x8, default
0x9aa4364  bl 0x9abd20c                  ; release/put
```

Что контролирует пользователь: `scalarInput[0]` (опкод 0x01/0x0b/0x11) и содержимое
`structureInput`. Ветка `0x11` закрыта энтайтлментом (`kIOReturnNotPrivileged`).
Ветки `0x01` (при `strInSize/8 == 2`) и `0x0b` — без энтайтлмента; `0x0b` разыменовывает
**первый u64 структуры как указатель и зовёт на нём release-метод**. Это ядро, поэтому
значение — не user-VA, а объект, который должен был положить сам драйвер; передача
произвольного числа приведёт к `autda`-провалу/панике, а не к записи по адресу.
**подозрительно (тип-путаница), но не memory-corruption.**

### 1.5 Разбор sel `0x4e` / `0x4f` (`0x9aa3d3c` / `0x9aa3e34`) — размер уходит вниз

```
sel 0x4e:
0x9aa3d60  x19 = args->structureInput          ; +0x30 (NULL-check есть)
0x9aa3d6c  w8  = args->scalarInputCount        ; требует >= 2
0x9aa3d7c  x8  = args->scalarInput ; w20 = *(u32*)x8
0x9aa3d84  x0 = this->[0xe8] (task)
0x9aa3d88  w2 = this->[0x104] ; w3 = this->[0x108]
0x9aa3d94  bl 0x9aa19f4                        ; валидация пары (task, id)
0x9aa3d9c  x8 = args->scalarInput ; w3 = *(u32*)(x8+8)
0x9aa3dac  x8 += 0x10 ; x4 = (count-2 ? x8 : NULL)
0x9aa3db4  x0 = this->[0xd8] (fb) ; x1 = this->[0xe8]
0x9aa3dbc  w7 = args->structureInputSize       ; +0x38, В ТАБЛИЦЕ -1
0x9aa3dd0  add x16, vtable, #0x720
0x9aa3e14  braa -> fb->vtable[0x720](fb, ref, op, val, ptr, count, structIn=x19, size=w7)
```

`structureInput` **и его размер передаются в метод framebuffer'а как есть**, локальной
сверки нет (в таблице `-1`), `NULL`-чек есть только на сам указатель. Кали — метод
`fb->vtable[0x720]`; его тело по цепочке `0x9aa33b8 → 0x80227e8+0x720` не подтверждено
(см. §5), поэтому «OOB есть/нет» — **не подтверждено**. Форма передачи (ptr+size вместе,
без обрезки) — правильная; опасность была бы, если кали игнорирует `w7`.

`sel 0x4f` симметричен: `strOut` (`+0x58`) и `structureOutputSize` (`+0x60`) уходят в
`fb->vtable[0x728]`, `strIn/strOut` в таблице `-1`.

### 1.6 Вердикт по MFB

| группа | селекторы | вердикт |
|---|---|---|
| точные размеры, фиксированные записи | 0x00..0x43, 0x45, 0x48..0x55, 0x57..0x62 | **безопасно** (валидатор + запись в `structureOutput` в пределах объявленного размера) |
| `NULL` в таблице | 0x3b..0x41, 0x46, 0x47 | **недостижимо** (`0xe00002ea`) |
| sel `0x44` | опкод+энтайтлмент | **подозрительно** (тип-путаница через `*(u64*)structIn`) |
| sel `0x4e/0x4f` | ptr+size вниз | **не подтверждено** (кали не разобран) |
| sel `0x55/0x56/0x63/0x64` | свои проверки в теле: `0x56` требует `strInSize==0x48`; `0x55/0x63/0x64` — `scalarInputCount>=2` + non-NULL `structOut` | **безопасно** по видимой части |

---

## 2. `AppleKeyStoreUserClient` (`com.apple.driver.AppleSEPKeyStore`)

* `sizeof` = `0x118` (мета-конструктор `0x914cbbc`)
* **`externalMethod = 0xfffffff009142e0c`** (свой vtable-слот `+0x550` не найден —
  см. §2.4, вызов идёт из `IOExternalMethodAction`-трамплина)

### 2.1 Пролог и гейт

```
0x9142e34  x22 = this
0x9142e3c  x8 = [GOT 0x7ec7788] ; x8 = *x8   ; stack canary
0x9142e50  x23 = this
0x9142e54  ldr x0, [x23, #0xd8]!  ; this->keystore
0x9142e58  cbz x0, err_0x2d9      ; 0xe00002d9
0x9142e5c  x19 = args
0x9142e60  x25 = selector
0x9142e64  x21 = this->[0xe0]
0x9142e68  subs w28, w1, #1
0x9142e6c  b.eq  dispatch         ; selector 1 -> без проверки
0x9142e74  bl 0x917349c           ; this->is_privileged()
0x9142e7c  tbz w0,#0 -> 0xe00002d9
0x9142ecc  cmp w28, #0xa8
0x9142ed0  b.hi 0x9148f14         ; selector-1 > 0xa8 -> default/unsupported
0x9142ef0  adrp x17, 0x914b000 ; add x17,#0x3c8
0x9142ef8  ldrsw x16,[x17, x16, lsl #2]   ; относительный офсет
0x9142efc  adr  x17, .            ; база = 0x9142efc
0x9142f04  br   x16
```

### 2.2 Таблица переходов: `0xfffffff00914b3c8`, 169 записей (sel 1..0xa9), база `0x9142efc`

`sel` → обработчик: `ks_selectors.tsv` (169 строк). 126 разных целей.

* `sel 0x00` — отдельная ветка до switch (`0x914300c`), не через таблицу.
* `0x19, 0x1c, 0x1d, 0x2f, 0x3b, 0x3c, 0x3d, 0x3e, 0x63, 0x66, 0x67, 0x86, 0x88, 0x9e, 0xa3..0xa8`
  и ещё 5 — **`0x9148f14`** (default, `kIOReturnUnsupported`).
* `sel 0x1a, 0x1b, 0x64, 0x65` → `0x9147e68` → `b 0x916958c` (под-диспетчер keybag).

### 2.3 Проверки числа аргументов — по каждому case

Считаются **только скаляры** (`args+0x20/+0x28` и `+0x48/+0x50`); `structureInput`
(`+0x30/+0x38`) в этой функции **не читается вообще** (проверено сплошным сканом тела
`0x9142e0c..0x914a7c8`: ни одного `ldr [x19,#0x30]` / `[x19,#0x38]`). Структурный ввод
здесь отсутствует как класс — поверхность только скалярная.

| sel | ожидает scalarIn | scalarOut | что делает |
|---|---|---|---|
| 0x01 | 1 | — | базовый запрос к keystore |
| 0x02 | 6 | 1 | |
| 0x03,0x04,0x06,0x0d,0x0f,0x11,0x13,0x17,0x1d,0x23,0x25,0x27,0x29 | 1 | — | одиночный id/keybag-запрос |
| 0x05 | 4 | — | |
| 0x07,0x08,0x0e,0x10,0x20 | 1 | 1 | |
| 0x09,0x0c,0x0f,0x12 | 3 | 1/— | |
| 0x0a,0x14,0x2b,0x2c | 2 | 1 | |
| 0x15 (`sel 21/22`) | 21 | — | самый широкий скалярный вход |
| 0x1a | 2 **или** 3, при 2 — `scalarOut==0` | 0 | keybag-операция |
| 0x1b / 0x64 | 1 (при 1: `scalarOut==0`), иначе 2 | 0 | keybag-операция |
| 0x65 | 1, `scalarOut==0` | 0 | keybag-операция |
| 0xa2 (162) | — | — | использует `structureOutputDescriptors` (+0x68/+0x70) |

Полная таблица — `ks_selectors.tsv`.

### 2.4 Под-диспетчер `0x916958c` (sel 0x1a/0x1b/0x64/0x65)

```
0x9169648  cmp w1,#0x65 ; b.eq 0x91696f0
0x9169654  cmp w1,#0x1b ; b.eq 0x916968c
0x916965c  cmp w23,#0x64 ; b.eq 0x916968c
0x9169664  cmp w23,#0x1a ; b.ne default
0x916966c  w8 = args->scalarInputCount
0x9169670  cmp w8,#3 ; b.eq ...
0x9169678  cmp w8,#2 ; b.ne default
0x9169680  w8 = args->scalarOutputCount ; cbz -> ok
...
0x916978c  x8 = args->scalarInput ; w23 = *(u32*)x8
0x9169798  cmp x26,#4 ; b.hi default      ; под-опкод 0..4
```

Внутри — свой разбор под-опкода (`x26 = scalarInput[0]`, допустимо 0..4), дальше
работа с keybag-структурой (`this->[0xf0]` флаги, `this->[0xf3]` тип, `this->[0x108]` счётчик).
Никаких копирований по пользовательскому размеру нет.

### 2.5 Вердикт по KeyStore

* Диапазон селекторов: `0x00..0xa9`, из них рабочих ~145, `0x19/0x1c/0x1d/...` — unsupported.
* Вход — исключительно скаляры; `structureInput` не используется → **класс не является
  вектором для size-trust багов**.
* Доступ к телу требует `this->[0xd8] != 0` и (кроме sel 1) прохождения `0x917349c`.
* **Вердикт: безопасно** в части размеров; единственный «интересный» момент —
  sel 0xa2 работает с `structureOutputDescriptors` (count `+0x70`), но count формирует
  сам IOKit по MIG-сообщению, не пользователь.

---

## 3. `IOGPUDeviceUserClient` — restricted-таблица

* `externalMethod = 0x994a1e0` (vtable-слот `0x7fea0c8`)
* гейт: `ldrb w9,[x0,#0x100]; tbz w9,#0` → иначе `w8 = 0xe00002c2 + 0x16 = 0xe00002d8`
* `ldrb w8,[x0,#0x103]` — **бит «restricted»**
* `sel > 0x37` → `0xe00002c2`
* `args->asyncReference (+0x10) != 0` → `0xe00002d8` (async запрещён)
* `x3 = sel*0x18`; таблица A = `0x7fea200`, таблица B = `0x7fea740`;
  `csel x3, B, A, ne` по биту `[0x103]&1`

### 3.1 Откуда берётся бит restricted

```
0x99658e8  this = [0x9949eb0] this->[0x120]
0x9965900  x1 = "com.apple.private.gpu-restricted"   @0x782debf
0x9965908  bl 0x9964e38    ; IOTaskHasEntitlement
0x996590c  tbz w0,#0 -> check2
0x9965910  w0 = 1 ; ret                      ; есть private -> restricted=1
0x9965920  x1 = "com.apple.developer.gpu-restricted" @0x782dee0
0x9965944  b 0x9964e38                       ; restricted = has(developer)
```

`strb w0,[x19,#0x103]` в `0x9949eb0`. То есть **B (restricted) включается, когда у задачи
НЕТ ни `com.apple.private.gpu-restricted`, ни `com.apple.developer.gpu-restricted`**.

### 3.2 Diff A/B (56 селекторов, stride `0x18`: fn, sIn, strIn, sOut, strOut)

Заглушка restricted = `0x9949520`: `mov w0,#0x2e2; movk w0,#0xe000,lsl#16; ret`
= **`kIOReturnNotPermitted` `0xe00002e2`**.

**Заблокировано 28:** `0x15, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x24, 0x25,
0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33,
0x34, 0x35, 0x36`.

**Остаются рабочими 28:** `0x00..0x14, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x23, 0x37`.

Полный дамп: `iogpu_tables.tsv`.

### 3.3 Три рабочих селектора в restricted-режиме

**sel `0x00` → `0x9947330`** (`sIn=0, strOut=0x40`)

```
0x994734c  x21 = args->structureOutput        ; +0x58
0x9947350  x0  = this->[0xf8]                 ; IOGPUDevice
0x9947354  w8  = [x0+0x1f0]
0x9947358  w9  = w8 & 0xffff
0x994735c  w8  = (w8 >> 9) & 0x1000
0x9947364  w8 |= w9
0x9947368  w9  = [x0+0x1f8]
0x994736c  stp  w8, w9, [x21]                 ; запись 8 байт в structureOutput
0x9947370  x8  = [x0+0x208]
0x9947374  str  x8, [x21, #0x10]              ; +0x10 .. +0x18
0x994739c  blraa [x0->vtable + 0x540]
```
Пишет фиксированные 0x18 байт в буфер, размер которого валидатор уже сверил с `0x40`.
Пользователь не контролирует ни смещение, ни длину. **безопасно.**

**sel `0x08` → `0x9947a54`** (`strIn = -1, strOut = -1`)

```
0x9947a84  x23 = args->structureOutput        ; +0x58
0x9947a88  x0  = args->structureInputDescriptor ; +0x40
0x9947a8c  cbz x0 -> 0x9947b90                ; без дескриптора — другой путь
0x9947aa0  x8  = [x0->vtable + 0xe8]          ; IOMemoryDescriptor::map?
0x9947aa4  w1  = 0x1000
0x9947aac  blraa                              ; x0 = map(0x1000)
0x9947ab0  cbz x0 -> 0x9947b90
0x9947ac8  x8  = [x0->vtable + 0x78]          ; getAddress()
0x9947ad0  blraa
```
Оба размера в таблице `-1`, но вход берётся **дескриптором** и мапится с фиксированной
длиной `0x1000`; сырой `structureInput`/`structureInputSize` не используется.
**безопасно** (единственное — `0x1000` не сверяется с реальной длиной дескриптора;
`map()` вернёт ошибку/укороченный маппинг, но это не OOB-запись).

**sel `0x37` → `0x9949514`** — `ldr x0,[x0,#0x120]; b 0x99683c4`. Тривиальный форвардер,
входов нет. **безопасно.**

### 3.4 Вердикт по IOGPU

* Без энтайтлмента доступны 28 селекторов: `0x00..0x14, 0x16..0x1a, 0x23, 0x37`.
* Все 28 имеют либо точные размеры в таблице, либо работают через дескриптор.
* **Вердикт: безопасно** для restricted-набора; остальные 28 — `kIOReturnNotPermitted`,
  то есть не «тихо», а явным отказом.

---

## 4. Что реально открывается из песочницы `container`

Строковый пул sandbox-профиля (сериализованный `require-any`, кодировка `0x0f`+символ)
в `__DATA_CONST` около `0xfffffff0079ddc00..0xfffffff0079de200` содержит:

`IOMobileFramebufferUserClient`, `IOGPUDeviceUserClient`, `AppleKeyStoreUserClient`,
`AppleKeyStore`, `IOSurfaceRootUserClient`, `IOAccelContext2`, `IOAccel…Device`,
`AGXDevice`, `AGXSharedUserClient`, `AGXCommandQueue`, `AGXAcceleratorG`,
`IOSurfaceAcceleratorClient`, `IOSurfaceAcceleratorParavirtClient`, `AppleJPEGDriverUserClient`,
`RootDomainUserClient`.

| класс | доступен из container | что это значит |
|---|---|---|
| `IOMobileFramebufferUserClient` | да | 101 селектор после гейта `[0x100]`; реальных «дыр» не найдено |
| `IOGPUDeviceUserClient` | да | 28 селекторов, sizes проверены таблицей |
| `AppleKeyStoreUserClient` | да | только скаляры, ~145 селекторов |
| `IOSurfaceRootUserClient` (для сравнения) | да | разобран subagent D отдельно |

---

## 5. Чего НЕ доказано (честный список)

1. **Кали `fb->vtable[0x720]` / `[0x728]` для MFB sel `0x4e`/`0x4f`.** Передача
   `(ptr,size)` прослежена до `braa`, но тело метода framebuffer'а не отождествлено:
   предполагаемая база `0x80227e8` даёт на `+0x720` геттер `0x9a9dafc`, который к
   структуре не относится → база не та. Нужен отдельный проход по vtable
   `IOMobileFramebuffer`/`…Service`.
2. **Поле `entry+0x20` в таблице MFB.** Ненулевое только у sel `0x56` и `0x64`
   (`0x0001000000859744` / `0x0003000000859744`), валидатор гоняет его через
   `mrs tpidr_el1` + вызов `[GOT+0x1c8]`. Семантика (thread/task token либо
   owner-проверка) — не подтверждена; младшие 28 бит указывают в padding
   `__PRELINK_TEXT` (`0xaa`/`0xff`), т.е. это не обычный указатель на строку.
3. **Ветка sel `0x0b` в MFB.** `*(u64*)structureInput` используется как `OSObject*`
   (вызов release через vtable). Что именно драйвер кладёт в первый u64 — не
   прослежено; трактовка «тип-путаница, не запись по адресу» — вывод из наличия
   `autda`/PAC перед вызовом, а не из наблюдения.
4. **`AppleKeyStoreUserClient` vtable-слот `externalMethod`.** Функция `0x9142e0c`
   не найдена ни в одной `__DATA_CONST`-вставке (в т.ч. по data-key PAC), вызов идёт
   из трамплина `0x9147ebc` внутри неё же. Возможно, слот указывает на трамплин
   `IOExternalMethodAction`, а не на саму функцию; точная привязка «слот ↔ функция»
   не подтверждена.
5. **Гейт `[x0+0x100]` bit0 у IOGPU** — где именно ставится (open vs initWithTask)
   не разобрано; известно только, что при нуле `externalMethod` отдаёт `0xe00002d8`.

---

## 6. Файлы

| файл | что внутри |
|---|---|
| `mfb_selectors.tsv` | 101 селектор: fn, sIn, strIn, sOut, strOut, flag, token |
| `ks_selectors.tsv` | 169 селекторов KeyStore: обработчик, поля args, ожидаемые скаляры |
| `iogpu_tables.tsv` | 2×56 селекторов IOGPU: A (полная) и B (restricted) |
| `kc.py`, `kd.py`, `qref.py`, `bxref.py`, `adrp_scan.py`, `dxref2.py` | инструменты (декод PAC, дизасм, поиск xref) |
| `progress.md` | журнал шагов |
