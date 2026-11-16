# AGXCommandQueue + IOGPUDeviceUserClient — остаток (27.2 / 24B115)

**Бинарь:** `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (67 239 936 Б, Mach-O arm64e fileset).
**Профиль:** `container`, без `com.apple.developer.gpu-restricted` → полная таблица `0x7fea200` (56 селекторов).
**Адресация:** `__TEXT_EXEC` = `va - 0xfffffff007004000`; `__DATA_CONST` = `0xbb4000 + (va - 0xfffffff007bb8000)`; PAC-резолв `BASE + (q & 0x0FFFFFFF)`, `BASE = 0xfffffff007004000`.
**Грабля capstone:** `adrp`/`b`/`bl` — знаковые, во всех скриптах маска `& 0xFFFFFFFFFFFFFFFF`.
**Автор:** subagent X2. Статика (capstone 5.0.7), скрипты в `work/agx_queue/tools`.

---

## 0. Короткий ответ

| Цель | Результат |
|---|---|
| **AGXCommandQueue** (0x948) | Класс найден и разобран: метакласс `0x819bba8`, alloc/ctor `0x819a850`, vtable `0x7c93bb8` (44 слота = 41 база `IOGPUCommandQueue` + 3 AGX-слота). Достижим из песочницы через `IOGPUDeviceUserClient` **sel 6** → `[uc+0xf8]->vt+0x698` (фабрика) → `queue->vt+0xd8` = `AGXCommandQueue::init` `0x818f8e8`. Init принимает пользовательскую структуру **ровно 0x408 Б** (`[accel+0x278]=0x408`), копирует 0x400 Б в объект, валидирует `priority<5` и два bool. Кольцо: 4 массива на `[q+0x8e0..0x900]`, ёмкость `[q+0x848]`, маска `[q+0x830]`, индексы `[q+0x83c/0x840]`. Submit — слот 35 `0x818eb40` → база `IOGPUCommandQueue::submitCommandBuffer` под мьютексом `[q+0x458]`. `free` (слот 14 `0x819a4c0`) освобождает все 4 массива по refcount 0; `stop` (слот 17 `0x819a1f4`) сериализован с submit тем же мьютексом. **UAF/гонки не найдено.** |
| **IOGPUDeviceUserClient** | Проверены все 56 селекторов, кроме 9/52/53. Только **8** читают `structureInput` (`+0x30`): 6, 8, 25, 26, 27, 38, 39, 45 (52/53 — разобраны ранее). Переменный размер (`stIn=0xffffffff`) у 6, 8, 25, 45 — у всех четырёх проверка размера **в теле есть** (у 6 — точное равенство 0x408; у 8 — пол 0x58 + пол по output; у 25 — точное `count*stride` с `umulh`; у 45 — `(size-8)%24==0` и `[buf]==count`). **Найден реальный дефект: sel 25 не проверяет минимальный `stride`, из-за чего читает до 0x1F Б за концом `structureInput`** (значение уходит id-ом в namespace `[dev+0x78]`). Остальное — корректно либо не подтверждено. |

---

## 1. AGXCommandQueue: идентификация

### 1.1 Метакласс и vtable

Конструктор метакласса (единственный xref на строку `"AGXCommandQueue"` `0x711964d`):

```
0x819bb8c  adrp x0, 0xae20000 ; add x0, x0, #0xf50     ; &meta (__DATA 0xae20f50)
0x819bb94  adrp x1, 0x7119000 ; add x1, x1, #0x64d     ; "AGXCommandQueue"
0x819bb9c  adrp x2, 0x7ca6000 ; ldr  x2, [x2, #0x38]   ; super meta (GOT)
0x819bba4  mov  w3, #0x948                             ; sizeof
0x819bba8  bl   0x8215ad0                              ; GOT-трамплин OSMetaClass ctor
```

Аллокатор/конструктор (`bti c; …; kalloc(0x948); vtable`):

```
0x819a850  bti  c ; pacibsp
0x819a864  adrp x0, 0x7ca0000 ; add x0, x0, #0xdc8    ; type descriptor
0x819a86c  mov  w1, #0x948
0x819a870  bl   0x8215970                              ; IOMalloc/kalloc
0x819a874  mov  x19, x0
0x819a878  adrp x20, 0xae21000 ; add x20, x20, #0xf50  ; &meta
0x819a880  mov  x1, x20
0x819a884  bl   0x8216200                              ; OSObject ctor(meta)
0x819a888  adrp x16, 0x7c93000 ; add x16, x16, #0xba8 ; +0x10 → 0x7c93bb8
0x819a894  mov  x17, x0 ; movk x17, #0xcda1, lsl #48
0x819a89c  pacda x16, x17
0x819a8a0  str  x16, [x0]                              ; vptr = 0x7c93bb8
```

* **vtable (function table) = `0xfffffff007c93bb8`**, 44 слота.
* Слоты 0/1: `0x819a848` (dtor → GOT → `0x99763d8`, `IOGPUCommandQueue::~`) и `0x819a800` (deleting dtor → `kfree(obj, 0x948)`).
* Слоты 2..40 совпадают по смыслу с vtable базы `IOGPUCommandQueue` (`0x7feee38`, 41 слот); AGX перекрывает 14,16,17,20,22,23,24,26..29,31,33,35..40.
* Слоты **41..43** — собственные виртуальные AGX (в базе их нет):
  * `41 = 0x819bdf4` — process-exit/teardown-проверка (capability `[accel+0x1ac44] bit3`, 1-секундный таймаут `0x3b9ac9ff`);
  * `42 = 0x819bd5c` — «idle ≥ 1 c?» (сравнение `mach_absolute_time` с `0x3b9ac9ff`);
  * `43 = 0x818b114` — ленивый `start`: если `[q+0x610]` уже есть → true, иначе создаёт firmware-объект через сервис `0xae20f78` и кладёт в `[q+0x610]`.

### 1.2 Достижимость из песочницы (главное)

`IOGPUDeviceUserClient::s_new_command_queue` (**sel 6**, `0x99476bc`, `stIn=0xffffffff`, `stOut=0x10`):

```
0x99476e4  ldr  x20, [x2, #0x30]        ; structureInput
0x99476e8  ldr  x22, [x2, #0x58]        ; structureOutput (16 Б)
0x99476ec  ldr  x8, [x0, #0x120]        ; IOGPUDevice
0x99476f0  ldr  x8, [x8, #0x88]         ; namespace очередей
0x99476f4  ldr  w8, [x8, #0x30]         ; ns->count  (без лока — TOCTOU, см. отчёт O)
0x99476f8  ldr  x0, [x0, #0xf8]         ; AGXAccelerator (провайдер)
0x99476fc  ldr  w9, [x0, #0x248]        ; лимит очередей
0x9947700  cmp  w8, w9 ; b.ls …
…
0x99477b8  ldr  w8, [x21, #0x38]        ; structureInputSize (u32)
0x99477bc  ldr  w9, [x0, #0x278]        ; 0x408 (записано в 0x99714c8)
0x99477c0  cmp  w8, #0x408
0x99477c4  ccmp w8, w9, #0, hs
0x99477c8  b.eq 0x994780c               ; требуется size == 0x408
…
0x994780c  ldr  x16, [x0] ; … ldr x8, [x16, #0x698]
0x994782c  blraa x8, x16                ; accelerator->vt[0xd3] = фабрика очереди
0x9947830  cbz  x0, err
0x9947838  ldr  x1, [x19, #0xf8]        ; accelerator
0x994783c  ldr  x2, [x19, #0x120]       ; device
0x9947840  ldr  x16, [x0] ; ldr x8, [x16, #0xd8]!
0x994785c  mov  x3, x20                 ; structureInput
0x9947864  blraa x8, x16                ; queue->vt[27] = AGXCommandQueue::init
0x9947830…  при успехе: add() в ns `[dev+0x88]`, `0x997a23c(queue,id)`,
            `0x9947080(uc,1)`, затем `stp {id, [queue+0x550]}, [structureOutput]`
```

Ключевое: `queue->vt+0xd8` = `0xfffffff00818f8e8` — **это и есть AGXCommandQueue::init**, а не IOGPU-стаб. Значит sel 6 создаёт именно AGXCommandQueue (0x948) и передаёт ему пользовательские 0x408 Б.

### 1.3 `AGXCommandQueue::init` (`0x818f8e8`, слот 27)

```
0x818f900  mov  x20, x3                 ; stIn (0x408)
0x818f904  mov  x21, x2                 ; IOGPUDevice
0x818f908  mov  x22, x1                 ; AGXAccelerator
0x818f90c  mov  x19, x0                 ; queue
0x818f910  str  xzr, [x0, #0x610]       ; сброс firmware-объекта
0x818f914  ldr  x16, [x1] ; … #0xd58    ; accelerator->vt[0x1ab](accel, device, 0, q)
0x818f944  blraa x8, x16
0x818f948  adrp x8, 0x7ca6000 ; ldr x8, [x8, #0x130]  ; &__ZTV15IOGPUCommandQueue
0x818f950  ldr  x9, [x8, #0xe8]!        ; +0xe8 символа = function table +0xd8 = слот 27
0x818f964  mov  x0, x19 ; x1, x22 ; x2, x21 ; x3, x20
0x818f96c  blraa x9, x17                ; IOGPUCommandQueue::init(q, accel, dev, stIn)
0x818f970  tbz  w0, #0, fail
0x818f974  ldr  x9, [x19, #0x530]       ; accel
0x818f978  add  x8, x9, #0x11, lsl #12 ; +0x11140 (или [accel+0x610])
0x818f980  ldr  w8, [x8]
0x818f98c  str  w8, [x19, #0x848]       ; ёмкость кольца
0x818f990  ldr  x9, [x19, #0x488]
0x818f994  ldr  x0, [x9, #0x1f0] ; str x0, [x19, #0x850] ; retain vt+0x20
0x818f9c0… четыре IOMalloc:
            [q+0x8f0] = count*8
            [q+0x8f8] = count*8
            [q+0x900] = count*4
            [q+0x8e0] = count*64  (зануляется по 0x40)
0x818fb34  str  w21(#-1), [q+0x7ec]
0x818fb38  movi v0.2s, #1, lsl #8 ; str s0, [q+0x7f4]  ; 0x100,0x100
0x818fb40  str  wzr, [q+0x83c]        ; write/read index = 0
0x818fb48  str  d0(0), [q+0x840]      ; второй индекс = 0
0x818fb4c  ldr  w8, [q+0x834] ; (w8-1) % w8 ; str w8, [q+0x830]  ; маска = n-1
0x818fba4  … создаёт workloop "AGXCommandQueueProcessExitWorkLoop" → [q+0x930], таймер → [q+0x938]
```

**База `IOGPUCommandQueue::init` (`0x99765dc`) читает структуру:**

```
0x9976628  cbz x23 (accel), cbz x21 (dev), cbz w0
0x9976630  str x23, [q, #0x530]        ; accel
0x99766a8  add x0, q, #0x10 ; mov x1, x22 (stIn) ; mov w2, #0x400
0x99766b4  bl  0x9984e4c               ; memcpy(q+0x10, stIn, 0x400)
0x99766b8  ldrb w8, [stIn, #0x404] ; cset → strb [q+0x439]
0x99766c8  ldr  w8, [stIn, #0x400] ; str w8, [q+0x450]   ; priority, ниже проверка <5
0x99766f8  ldr  w8, [stIn, #0x60]  ; str w8, [q+0x490]
0x9976700  mov  x0, x21(dev) ; bl 0x99676a8 → dev->[0x58] ; str [q+0x480] + retain vt+0x20
0x99766e4  ldrb w8, [stIn, #0x405] ; cset → strb [q+0x527]
```

Проверка priority — в `0x99766d0`: `ldr w8,[stIn+0x400]; cmp w8,#5; cset w23,lo`; при `>=5` init возвращает false.

**Итог по структуре 0x408:**

| offset | использование | проверка |
|---|---|---|
| +0x000..0x3FF | `memcpy` в `[q+0x10]` (снимок; в init не парсится, см. §6) | нет |
| +0x400 (u32) | `[q+0x450]` — priority | `< 5`, иначе отказ |
| +0x404 (u8) | `[q+0x439]` bool | приводится к 0/1 |
| +0x405 (u8) | `[q+0x527]` bool | приводится к 0/1 |
| +0x060 (u32) | `[q+0x490]`, позже пишется в `[accel+0x2e8]` | нет |

### 1.4 Кольцо

| поле | смысл | откуда |
|---|---|---|
| `[q+0x8e0]` | массив записей по **0x40 Б**, `count` штук | `IOMalloc(count*0x40)`, зануляется |
| `[q+0x8f0]` | массив u64, `count` | `IOMalloc(count*8)` |
| `[q+0x8f8]` | массив u64, `count` | `IOMalloc(count*8)` |
| `[q+0x900]` | массив u32, `count` | `IOMalloc(count*4)` |
| `[q+0x848]` | `count` (ёмкость) | `[accel+0x11140]`, иначе `[accel+0x610]` |
| `[q+0x830]` | `count-1` (маска) | `0x818fb4c` |
| `[q+0x834]`,`[q+0x838]` | гранулярность/шаг из конфига accel | `[accel+0x11158/0x1115c]` |
| `[q+0x83c]` | u32-индекс (write) | init = 0 |
| `[q+0x840]` | второй индекс (read) | init = 0 |
| `[q+0x7ec]` | `-1` (нет последнего слота) | init |
| `[q+0x7f4]` | две u16 = `0x100,0x100` | init |
| `[q+0x7e8]`/`[q+0x7ea]` | u16/u8, сбрасываются в submit | `0x818ebb8/bbc` |

### 1.5 Submit

`AGXCommandQueue::submitCommandBuffer` = слот 35 = `0x818eb40`. Это обёртка:

```
0x818eb60  ldr x16,[q] ; #0x158 ; ldr x8,[x16]
0x818eb7c  mov w1,#1
0x818eb84  blraa x8, x16           ; [q vt+0x158] = слот 43 (ленивый start)
0x818eb88  tbz w0,#0 → fail
0x818eb8c  ldr x8,[q,#0x610]       ; firmware-объект
0x818eb90  ldr x0,[x8,#0xa8]
0x818eb94  ldr w1,[cb_args,#0x30]      ; cb_args = x20 = sIOGPUCommandQueueCommandBufferArgs*
0x818eb98  ldr x2,[cb_args,#0x38]
0x818eb9c  ldr x16,[x0] ; #0x98 ; blraa   ; x0->vt[0x13](w1, x2)
0x818ebb8  strh wzr,[q,#0x7e8] ; strb wzr,[q,#0x7ea]
0x818ebc0  ldr x21,[q,#0x518]
0x818ebc4  ldr x8,[x21,#0x130] ; cbz → создать
0x818ebcc  strb 1,[q,#0x618]
0x818ebd4  ldr x8,[__ZTV_IOGPUCommandQueue] ; add x2,x8,#0x128 ; ldr x16,[x8,#0x128]
0x818ec10  braa x16, x17           ; хвост в базовый submitCommandBuffer
```

Вызывается из `IOGPUCommandQueue::submitCommandBuffers` (**worker `0x9976cf8`**), который держит мьютекс `[q+0x458]`; на каждую запись зовёт `[q vt+0x80]` и `0x997700c(q, record)`, а `0x997700c` в свою очередь `[q vt+0x118]` = слот 35 (AGX submit).

### 1.6 Signal / wait / complete

* `signalSharedEvent` — слот 36 `0x818e0f0`: проверяет capability `[accel+0x10a71] bit0`; если включено — `[accel+0x148]->…` и лог `"Event ID %u signal value (%llu) will use fallback path since queue is idle"` (`0x7118e4b`); иначе — tail-call в базу.
* `waitSharedEvent` — слот 37 `0x818df38`: `timeout_ms` (или `-1`) → мкс, `min(…, 0xfa0)` (4 мс), затем ожидание; ничего пользовательского, кроме таймаута, не принимает.
* Явного «complete»-виртуального слота в AGX-таблице нет: завершение приходит из firmware-кольца через `AGXEventMachine`/`AGXFirmware` (вне пользовательского пути sel 6).

### 1.7 free / stop / terminate под in-flight

```
sel 7 (0x99479c0):
  removeLocked(ns очередей, id)  → obj  (слот обнулён под [ns+0x20])
  0x997684c(q)                   → terminateAndRelease, ВНЕ ns-лока
```

`terminateAndRelease` `0x997684c`:

```
0x9976860  ldr x8,[q,#0x530] ; ldrb w8,[x8,#0x1fd]
0x9976870  add x8,q,#0x5c8 ; stlrb 1,[x8]      ; «terminating»
0x997687c  str wzr,[q,#0x420]
0x9976880  ldr x0,[q,#0x458] ; bl lock          ; <<< мьютекс очереди
0x9976898  ldr x8,[q] ; #0x88 ; blraa           ; q->vt[17] = stop
0x99768a8  ldr x0,[q,#0x458] ; bl unlock
0x99768b0  ldr x8,[q] ; #0x28 ; braa             ; q->release()
```

`stop` AGX `0x819a1f4`:
1. зовёт базу `stop` (`__ZTV+0x98` → function table +0x88 → слот 17 = `0x997690c`);
2. `[accel+0x4b0]->vt[0x230]` — firmware-менеджер;
3. если `[q+0x610]` есть — уничтожает оба пула (`[fw+0x98]`/`[fw+0x9c]`, записи `[fw+0x28+i*8]`/`[fw+0x48+i*8]`, `vt+0x100`) и отпускает `[fw+0x68/0x70/0x78/0x80/0x88/0x90]` через `vt+0x28`.

`free` AGX `0x819a4c0` (слот 14):
```
0x819a4e0  ldr x0,[q,#0x610] ; release vt+0x28 ; str xzr
0x819a510  ldr x0,[q,#0x918] ; release vt+0x28 ; str xzr
0x819a538  ldr x0,[q,#0x910] ; release vt+0x28 ; str xzr
0x819a560  ldrsw x8,[q,#0x848] ; lsl x9,x8,#3 ; csel x2 = size
0x819a574  ldr  x1,[q,#0x8f0] ; str xzr ; IOFree(x1, size)
… то же для 0x8f8 (×8), 0x900 (×4), 0x8e0 (×64)
```

**Дисциплина:** submit-worker и `terminate` берут **один и тот же** мьютекс `[q+0x458]`, поэтому `stop` не может разорвать массив/пул под работающим submit. `free` вызывается только при `gpu_refcnt==0`; namespace `remove` отдаёт свою ссылку вызывающему, а submit берёт `+1` через `retainById` (`0x9945040`) до входа в worker. **UAF не найден.** Отдельно: `free` сам мьютекс не берёт и полагается только на refcount — это корректно при текущей модели ссылок.

---

## 2. IOGPUDeviceUserClient: все селекторы

### 2.1 Карта (56 записей, `0x7fea200`)

`fn` — PAC-резолв; `scIn/stIn/scOut/stOut` — из `IOExternalMethodDispatch` (stride 0x18). «args» — какие офсеты `IOExternalMethodArguments` читает тело (эмпирически). «size» — проверка размера **в теле** (не в диспетчере).

| sel | scIn | stIn | stOut | args | size в теле | callee / примечание |
|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0x40 | +0x58 | — | `0x99749b8`, `0x99676a8`; пишет 0x00..0x40 |
| 1 | 0 | 0 | 0x40 | +0x58 | — | `0x9984e4c` (memcpy в out) |
| 2 | 0 | 0 | 0x218 | +0x58 | — | `0x994abb0`; пишет фикс. структуру |
| 3 | 0 | 0 | 0x8 | +0x58 | — | `0x997554c`; 8 Б |
| 4 | 0 | 0 | 0x20 | +0x58 | — | `0x9975520`, `0x9964430`; 0x20 Б |
| 5 | 0 | 0 | 0x10 | +0x58 | — | `0x99843fc` |
| **6** | 0 | **0xffffffff** | 0x10 | **+0x30, +0x38, +0x58** | **`size == [accel+0x278]` (=0x408)** | `[uc+0xf8]->vt+0x698` → `queue->vt[27]`; лимит очередей читается без лока |
| 7 | 1 | 0 | 0 | +0x20 | — | `removeLocked` → `0x997684c` (terminate+release) |
| 8 | 0 | **0xffffffff** | **0xffffffff** | +0x38, +0x40, +0x58, +0x60 | **`stIn >= 0x58` и `*outSize >= [dev+0x234]+0x58`** | `0x994a30c` → `0x99669e0` (ресурс из 0x58-Б дескриптора) |
| 9 | 1 | 0 | 0 | +0x20 | — | удаление ресурса (разобрано ранее) |
| 10 | 2 | 0 | 0 | +0x20 | — | `0x99664e4` |
| 11 | 2 | 0 | 0 | +0x20,+0x48 | — | `0x9966668` |
| 12 | 2 | 0 | 0x10 | +0x20,+0x58 | — | `0x99659b4` |
| 13 | 1 | 0 | 0 | +0x20,+0x58 | — | `0x9965b04` (remove+release из `[dev+0x78]`) |
| 14 | 2 | 0 | 0x10 | +0x20,+0x58 | — | `0x9965dc0` |
| 15 | 1 | 0 | 0 | +0x20,+0x58 | — | `0x9965edc` |
| 16 | 0 | 0 | 0x8 | +0x20,+0x58 | — | `0x99673a0` |
| 17 | 0 | 0 | 0x4 | +0x20,+0x58 | — | `0x9965cd0` |
| 18 | 1 | 0 | 0 | +0x20,+0x58 | — | `0x9965d78` |
| 19 | 1 | 0 | 0x18 | +0x20,+0x58 | — | `0x9965b64` |
| 20 | 1 | 0 | 0 | +0x20,+0x58 | — | `0x9965c20` |
| 21 | 0 | 0 | 0x30 | +0x48,+0x58 | — | `0x9966328` |
| 22 | 0 | 0 | **0xffffffff** | +0x48 | — | `kIOReturnUnsupported` (0xE00002C7) |
| 23 | 0 | 0 | 0 | +0x48 | — | ветка в общий эпилог |
| 24 | 2 | 0 | 0 | +0x20 | — | `0x9965da8`, `0x9965db4`, `0x9976ba0` |
| **25** | 4 | **0xffffffff** | 0 | **+0x38, +0x40** | **`size == scalar[3]*scalar[2]`** (+`umulh`); `scalar[3]==0x30` | `0x9965da8` (retain) → `0x9976cf8`; **stride не проверен — см. §3.1** |
| 26 | 1 | 0xc | 0 | +0x20, +0x30 | — (фикс. 0xc в таблице) | `0x9977304`; читает 2×u32 из `+0x30` |
| 27 | 1 | 0x4 | 0 | +0x20, +0x30 | — (фикс. 4) | `0x99767f8`; читает u32 |
| 28 | 0 | 0 | 0 | +0x20 | — | `0x99481fc` читает scalar[0] без null-чека |
| 29 | 1 | 0 | 0 | +0x20 | — | — |
| 30 | 2 | 0 | 0 | +0x20 | — | `s_async_signal_mtlLateEvalevent` |
| 31 | 1 | 0 | 0 | +0x20 | — | `s_query_mtlLateEvalevent` |
| 32 | 2 | 0 | 0 | +0x20 | — | — |
| 33 | 2 | 0 | 0 | +0x20 | — | — |
| 34 | 1 | 0 | 0 | +0x20 | — | — |
| 35 | 2 | 0 | 0 | +0x20 | — | — |
| 36 | 3 | 0 | 0 | +0x20 | — | `0x9984f2c`, `0x99676d4` |
| 37 | 1 | 0 | 0 | +0x20 | — | tail `0x9967fb8` |
| 38 | 0 | 0x18 | 0 | +0x30 | — (фикс. 0x18) | tail `0x9968054` |
| 39 | 0 | 0x18 | 0 | +0x30 | — (фикс. 0x18) | `0x996810c` |
| 40 | 1 | 0 | 0 | +0x20 | — | `s_create_vniodesc` → `0x99647b0` |
| 41 | 1 | 0 | 0 | +0x20 | — | `0x99451a0` (remove+release) |
| 42 | 2 | 0 | 0 | +0x20 | — | `s_create_io_command_queue` → `0x995b2e0` |
| 43 | 1 | 0 | 0 | +0x20 | — | `s_destroy_io_command_queue` → `0x995b020` |
| 44 | 2 | 0 | 0 | +0x20 | — | `s_set_io_notification_queue`: `0x9967bb4` + `0x9965db4`, release обоих |
| **45** | 1 | **0xffffffff** | 0 | **+0x38, +0x40** | **`size>=8`, `(size-8)%24==0`, `[buf]==count`** | `0x9967bb4` → `0x995b364` |
| 46 | 1 | 0 | 0 | +0x20 | — | `0x9967bb4` → `0x995b9a4` |
| 47 | 2 | 0 | 0 | +0x20 | — | `0x9967bb4` → `0x995bb6c` |
| 48 | 2 | 0 | 0 | +0x20 | — | `0x9967bb4` → `0x995bbe4` |
| 49 | 1 | 0 | 0 | +0x20 | — | `0x9967bb4` → `0x995b654` |
| 50 | 1 | 0 | 0 | +0x20 | — | `0x9967bb4` → `0x995bc50` |
| 51 | 3 | 0 | 0 | +0x20 | — | `0x9967bb4` → `0x995bc90` |
| 52 | 2 | 0xffffffff | 0 | +0x20,+0x40 | `size>=count*4` | `s_group_add_resources` (разобрано) |
| 53 | 2 | 0xffffffff | 0 | +0x20,+0x40 | `size>=count*8` | `s_group_remove_resources` (разобрано) |
| 54 | 2 | 0 | 0 | +0x20 | — | `0x99681d8` |
| 55 | 0 | 0 | 0 | — | — | пустой |

**Вывод по args:** только sel **6, 8, 25, 26, 27, 38, 39, 45** (и 52/53) читают `structureInput` (+0x30). Все остальные работают только со `scalarInput` (+0x20) и `structureOutput` (+0x58). `structureInputDescriptor` (+0x40) читают только 6/8/25/45/52/53. `structureOutputDescriptor` (+0x68) в этом билде не читает **никто** из 56 — вывод: либо поле не используется, либо за него отвечает `+0x58` (в 27.2 `+0x58` — именно буфер `structureOutput`, запись в него идёт напрямую `stp/str`, см. sel 0).

### 2.2 ABI `IOExternalMethodArguments` (эмпирически)

| offset | поле | доказательство |
|---|---|---|
| +0x10 | должен быть 0 | `0x994a1f8` в `externalMethod` |
| +0x20 | `scalarInput` (u64*) | sel 28 (`scIn=0`) читает без null-чека |
| +0x28 | `scalarInputCount` | sel 25 `cmp w8,#4` |
| +0x30 | `structureInput` | sel 26 `ldr x21,[x2,#0x30]` |
| +0x38 | `structureInputSize` | sel 6/25/45 |
| +0x40 | `structureInputDescriptor` | sel 6/25/45 (map через `vt+0xe8`, bytes `vt+0x78`, len `vt+0xb0`) |
| +0x48 | `scalarOutput` | sel 26/39/54 |
| +0x50 | `scalarOutputCount` | — (по симметрии) |
| +0x58 | **`structureOutput` (буфер)** | sel 0: `ldr x21,[x2,#0x58]; stp w8,w9,[x21]` |
| +0x60 | `structureOutputSize` | sel 8: `ldr w8,[x4]`, `x4=args+0x60` |

`+0x68`/`+0x70` не встречаются ни в одном из 56 тел. В 27.2 `+0x58` — именно буфер `structureOutput` (sel 0 пишет в него напрямую `stp/str`), поэтому «дескриптор вывода» в этом ABI либо отсутствует, либо не используется; в любом случае из пользовательского пути он не читается.

---

## 3. Топ-5 подозрительных (дизасм + вердикт)

### 3.1 №1 — sel 25: `stride` не ограничен → OOB-чтение за `structureInput` (**подтверждено**)

`0x9947de4`, проверка размера:

```
0x9947e18  ldr  x0, [x2, #0x40]        ; structureInputDescriptor (может быть NULL)
0x9947e1c  cbz  x0, 0x9947eac
…          map + getBytes + getLength → x0=len, x23=bytes, x20=map
0x9947eac  ldr  w8, [x21, #0x28]       ; scalarInputCount
0x9947eb0  cmp  w8, #4 ; b.ne err
0x9947ec4  ldr  x8, [x21, #0x20]       ; scalarInput
0x9947ec8  ldp  x25, x24, [x8, #0x10]  ; x25=scalar[2] (stride), x24=scalar[3] (count)
0x9947ecc  umulh x9, x24, x25          ; переполнение?
0x9947ed0  cbz  x9, 0x9947f10
0x9947f10  mul  x9, x24, x25
0x9947f14  cmp  x0, x9
0x9947f18  b.ne err                    ; size == count*stride (ровно)
0x9947f1c  ldr  w1, [x8]               ; queue id = scalar[0]
0x9947f20  ldr  x0, [x22, #0x120]      ; device
0x9947f24  bl   0x9965da8              ; ns [dev+0x88] retainById
0x9947f28  cbz  x0, err
0x9947f30  ldr  x8, [x0, #0x530]       ; accel
0x9947f34  ldr  w8, [x8, #0x268]       ; = 0x30 (записано в 0x9971498)
0x9947f38  cmp  x24, x8
0x9947f3c  b.ne err                    ; scalar[3] == 48
0x9947f48  mov  x0, x22 ; x1=x23 ; x2=x25 ; x3=x24 ; x4=&out
0x9947f58  bl   0x9976cf8              ; worker
```

Worker `0x9976cf8` (на каждую из 48 записей):

```
0x9976d54  ldr  x0, [q, #0x528] ; bl lock
0x9976da4  mov  x25, #0
0x9976e00  mul  x8, x25, x21           ; i * stride
0x9976e04  cmp  x8, w8, sxtw           ; w8 = [q+0x540]
0x9976e08  add  x24, x23, w8, sxtw
0x9976e0c  add  x16, x23, x8
0x9976e10  movk x16, #0x2bad, lsl #48
0x9976e14  csel x24, x24, x16, eq      ; обе ветви дают buf + i*stride
0x9976e18  ldr  w1, [x24, #0x20]       ; <<< id из записи
0x9976e1c  cbz  w1, 0x9976e4c
0x9976e20  ldr  x0, [q, #0x488]
0x9976e24  bl   0x9965b58              ; ldr x0,[x0,#0x78]; b retainById → ns [dev+0x78]
0x9976e28  mov  x1, x0
0x9976e2c  ldr  x16, [q] ; ldr x8, [x16, #0x80]!
0x9976e48  blraa x8, x16               ; obj->vt[16](…)
0x9976e4c  mov  x0, q ; mov x1, x24
0x9976e54  bl   0x997700c              ; разбор записи (читает +0x10, +0x18)
0x9976ebc  add  x25, x25, #1
0x9976ec0  subs x22, x22, #1
0x9976ec4  b.ne 0x9976da8
```

**Дефект.** `stride` (= `scalar[2]`) не проверяется на минимум `sizeof(record)`. При `stride < 0x20` последняя запись начинается по `buf + 47*stride`, а `ldr w1,[rec+0x20]` читает за концом буфера: при `stride=1` — до `buf+0x4F`, т.е. **до 0x1F Б за `structureInput`** (в in-band пути это kernel-буфер, выделенный диспетчером; при descriptor-пути — отображённые страницы). `0x997700c` дополнительно читает `[rec+0x10]` и `[rec+0x18]` — оба меньше 0x20, границу не расширяют.

**Impact.** Прочитанный u32 используется как **id в namespace `[dev+0x78]`** (retain + `vt[16]`). Если в куче за буфером окажется валидный id (namespace общий на устройство, id маленькие), вызов пойдёт по чужому объекту того же класса. Прямой утечки в user нет; запись в user — только `scalarOutput[0]` (код возврата). Оценка: OOB read / потенциальный type-confusion внутри класса, не граница привилегий. **Не подтверждено динамикой.**

### 3.2 №2 — sel 6: пользовательские 0x408 Б в init очереди (**частично подтверждено**)

См. §1.3. Всё, что реально читается: `+0x60`, `+0x400..+0x405`; `+0x400` проверяется `<5`. Остальные 0x3FC Б копируются в `[q+0x10]`. В `IOGPUCommandQueue::init` они не парсятся; потребителя `q+0x10` как потока kernel-команд в `IOGPUFamily` не нашлось (нет ни одного `add …, #0x410` или передачи диапазона `[q+0x10, q+0x410]` в `processKernelCommands 0x997987c`). Вердикт: **вредного использования не найдено, «снимок»**. Отдельно подтверждён TOCTOU лимита очередей (ns->count читается вне лока, `0x99476f4` vs add под локом `0x9947878`) — это ресурсный DoS, не память (см. отчёт subagent O).

### 3.3 №3 — sel 8: дескриптор ресурса 0x58 Б (**не подтверждено**)

```
0x9947a84  ldr  x23, [x2, #0x58]       ; structureOutput
0x9947a88  ldr  x0,  [x2, #0x40]       ; descriptor?
0x9947a8c  cbz  x0, 0x9947b04
…          map/getBytes/getLength → x24=bytes, x3=len
0x9947b04  mov  x20, #0
0x9947b08  ldr  w3, [x22, #0x38]       ; stInSize
0x9947b0c  ldr  x24, [x22, #0x30]      ; stIn
0x9947b10  cbz  x24, err
0x9947b14  cmp  x3, #0x58
0x9947b18  ccmp x23, #0, #4, hs        ; size>=0x58 && out!=NULL
0x9947b1c  b.eq err
0x9947b20  add  x4, x22, #0x60         ; &structureOutputSize
0x9947b28  mov  x1, x24
0x9947b2c  mov  x2, x23
0x9947b30  bl   0x994a30c
```

`0x994a30c` → `0x99669e0`: `cmp x3,#0x58`; `w8=*outSize`; `x9=[dev+0x234]+0x58`; `cmp x9,x8; b.hi err`. Далее — разбор `u32 type = [in]` и ветки 0/3/0x40/0x80/0x82; поля `+0x18,+0x20,+0x28,+0x30,+0x38,+0x3c,+0x40,+0x48,+0x50` уходят аргументами в типовые конструкторы (`0x99544e0`, `0x9966d5c`, …). Проверки, которые видны: тип 0 — `[in+0x48] <= f(dev+0x118, dev+0x2ec, page)`; тип 0x82 — `[in+0x3c] >= 0x9975b40(...)`. **Семантика адресных полей (+0x18/+0x38/+0x40/+0x48) и их валидация не прослежены** — это главный кандидат на «число из входа → адрес/длина».

### 3.4 №4 — sel 45: перечитывание count из user-буфера (**не подтверждено для песочницы**)

```
0x9948b90  mov  x19, #0
0x9948b94  ldr  x22, [x21, #0x30]      ; structureInput
0x9948b98  ldr  w0,  [x21, #0x38]      ; size (u32)
0x9948b9c  subs x9, x0, #8
0x9948ba0  b.lo err                    ; size >= 8
0x9948ba4  mov  x8, #-0x5555555555555556 ; /24 magic
0x9948ba8  movk x8, #0xaaab
0x9948bac  umulh x8, x9, x8
0x9948bb0  lsr  x8, x8, #4
0x9948bb4  mov  w10, #0x18
0x9948bb8  msub x9, x8, x10, x9
0x9948bbc  cbz  x9, 0x9948c70         ; (size-8)%24 == 0
0x9948c70  ldr  w9, [x22]              ; header = count
0x9948c74  cmp  x8, x9 ; b.ne err      ; count == (size-8)/24
0x9948c7c  ldr  x8, [x21, #0x20] ; ldr w23, [x8]  ; queue id
0x9948c84  ldr  x0, [x20, #0x120]
0x9948c8c  bl   0x9967bb4              ; retainById из [dev+0x110]
0x9948c98  mov  x1, x22
0x9948c9c  bl   0x995b364              ; worker
```

Worker `0x995b364`:

```
0x995b3b0  ldr  w8, [x20]              ; count
0x995b3bc  mov  w25, #0x171 ; movk …   ; trace id
0x995b3c4  add  x26, x20, #8           ; записи по 24 Б
0x995b3d0  add  x9, x24, x24, lsl #1
0x995b3d4  add  x8, x26, x9, lsl #3    ; rec = buf+8+i*24
0x995b3e8  ldr  w1, [x8]               ; id
0x995b3ec  cbz  w1, 0x995b4a4
0x995b3f0  ldr  w22, [x8, #4]          ; offset
0x995b3f4  ldr  x23, [x8, #8]          ; 64-битное значение/адрес
0x995b3f8  ldrb w28, [x8, #0x10]       ; флаг
0x995b3fc  ldr  x0, [x19, #0x38]
0x995b400  bl   0x9945040              ; retainById (под локом ns)
0x995b408  mov  x21, x0 ; cbz err
0x995b41c  bl   0x9959248              ; io-команда(obj, offset, value, flag)
0x995b4d4  ldr  w8, [x20]              ; <<< count перечитывается из user-буфера
0x995b4d8  cmp  x24, x8 ; b.lo loop
```

`0x9959248` кладёт `x2` (=[rec+8]) в `[io_queue+0x20]`, флаг — в `+0x5e`, и зовёт `0x9959368(io, offset)`. То есть 64-битное поле записи сохраняется как «адрес/значение» io-команды.

**Вердикт.** В in-band пути `structureInput` — kernel-копия, перечитывание безопасно. В descriptor-пути (`args+0x40`) это отображение user-страниц: пользователь может поднять `[buf]` между итерациями → цикл выйдет за длину маппинга (OOB read, вплоть до паники). **Достижимость descriptor-пути из песочницы не подтверждена** (публичный `IOConnectCall*` передаёт структуры in-band; дескриптор — для kernel-клиентов). Поэтому пункт помечен «не подтверждено».

### 3.5 №5 — AGX lifecycle: `free`/`stop` vs in-flight (**проверено, дыры нет**)

См. §1.7. `terminateAndRelease` берёт `[q+0x458]`, `stop` — под ним; submit-worker — под ним же; `free` — только по refcount 0. Единственное наблюдение: `free` не берёт `[q+0x458]` и освобождает массивы по `[q+0x848]`; при частично успешном init (аллокация упала) `IOFree(NULL, size)` безопасен, но `count` уже записан. **UAF/двойного free не найдено.**

---

## 4. Спец-callee (0x9967e24, 0x9945040, 0x9944fb8, 0x9945214, 0x9967bc0)

| адрес | что | кто зовёт (вне 52/53) |
|---|---|---|
| `0x9967e24` | group_add_resources (создаёт массив count*8, worker 0x9967bc0) | **только sel 52** |
| `0x9967bc0` | worker add: raw lookup `0x9945214` под локом `[dev+0x10]`, retain `vt+0x20` | только `0x9967e24` |
| `0x9945040` | `lock(ns+0x20); 0x9944fb8; unlock` | thunk'и `0x9965da8` (+0x88), `0x9965db4` (+0x90), `0x9967bb4` (+0x110); sel 6/24/25/26/27/40/42/43/44/46..51/52/53 |
| `0x9944fb8` | `retainById`: bounds `id!=0 && id<[ns+0x28]`, `ldr [base+id*8]`, `ldadd +1` на `[obj+0xc]` | только из `0x9945040` и `0x9967c20` |
| `0x9945214` | `lookupRaw`: bounds, без ref/лока | 17 сайтов; 12 доказанно под локом, 5 — виртуальные thunk'и (`0x9965624/0x9965b54/0x9965c90/0x9965cc0/0x9965f2c`) — не подтверждены (отчёт O) |

Все вызовы `0x9945040` в проверенных селекторах идут **до** использования объекта и с последующим `release` (`vt+0x28`) — утечек/висячих ссылок не видно. `0x9945214` в пользовательских путях встречается только внутри `0x9967bc0` (sel 52), под локом namespace `[dev+0x10]`.

---

## 5. Вердикт

1. **AGXCommandQueue разобран** и достижим из `container` через `IOGPUDeviceUserClient` sel 6. Пользовательский вклад: 0x408-Б структура (0x400 — снимок, 4 поля реально читаются), id/лимит очереди. Кольцо и индексы инициализируются из конфига акселератора, не из входа.
2. **Критической дыры (запись за буфер, UAF, произвольный адрес) не найдено.**
3. **Реальный дефект — sel 25:** отсутствие минимального `stride` даёт OOB-чтение до 0x1F Б за `structureInput`; прочитанное уходит id-ом в namespace `[dev+0x78]`. Классифицируется как OOB read / потенциальный type-confusion, не leak.
4. `stIn=0xffffffff` у 6/8/25/45 **не означает «без проверки»**: у всех четырёх проверка в теле есть; у 6 — точное равенство 0x408, у 8 — пол 0x58 + пол по output, у 25 — точное произведение с `umulh`, у 45 — `%24` и header==count.
5. `free`/`stop` под in-flight **сериализованы** мьютексом `[q+0x458]`; `free` освобождает 4 массива только при `gpu_refcnt==0`.

---

## 6. Не подтверждено

| Утверждение | Почему |
|---|---|
| Потребитель `[q+0x10..0x40F]` (0x400-Б снимок) | в `IOGPUFamily` нет ни `#0x410`, ни передачи диапазона в `processKernelCommands`; возможно, используется только для диагностики/crash-логов |
| Семантика адресных полей sel 8 (`+0x18/+0x38/+0x40/+0x48`) и их валидация | типовые конструкторы `0x99544e0`/`0x9966d5c` не прослежены до конца |
| Достижимость `structureInputDescriptor` (+0x40) из app-песочницы | публичный `IOConnectCall*` копирует in-band; дескрипторный путь, вероятно, только для kernel-клиентов |
| Impact OOB-чтения sel 25 | требует динамики/груминга кучи; статически — только «id из-за буфера» |
| Точная семантика `[rec+8]` в sel 45 (адрес или значение) | `0x9959248` кладёт его в `[io+0x20]`; дальнейшее использование в `0x9959368` не разобрано |
| 5 виртуальных thunk'ов `lookupRaw` без лока | см. отчёт subagent O |
| `flag`/`priority` в sel 6 сверх `<5` | `[q+0x490]` пишется в `[accel+0x2e8]`; ограничения не найдены |

---

## 7. Рецепт проверки (negative-тест)

* **sel 25 (OOB):** `scalarInput = {queue_id, 0, stride, 48}`, `structureInput` = `stride*48` байт. Взять `stride = 1` (48 Б) → последняя запись `buf+47`, чтение `+0x20` = `buf+0x4F` (за буфером). Ожидаемо: либо `0` (id не найден) → `kIOReturnSuccess`, либо паника/иной код при попадании в валидный id. Для сравнения — `stride = 0x24` (без OOB).
* **sel 6:** `structureInputSize` ровно `0x408`; `+0x400 = 5` → `kIOReturnBadArgument` (проверка priority), `+0x400 = 0` → успех. `+0x404/+0x405` — любые bool.
* **sel 8:** `structureInputSize = 0x57` → отказ; `0x58` c `structureOutput = NULL` → отказ; `0x58` + output ≥ `[dev+0x234]+0x58` → успех/иной код.
* **sel 45:** `size = 8 + 24n`, `[buf] = n`; `size = 8 + 24n + 4` → отказ; `[buf] = n+1` → отказ.

---

## 8. Артефакты

* `work/agx_iogpu/REPORT.md` — этот отчёт.
* `work/agx_iogpu/progress.md` — журнал шагов.
* Скрипты: `work/agx_queue/tools/{kc,vm}.py`, `work/parse_gpu/metaclass.json` (карта классов AGX), `work/iogpu_all/selmap.json` + `disasm_all.txt` (56 селекторов).
