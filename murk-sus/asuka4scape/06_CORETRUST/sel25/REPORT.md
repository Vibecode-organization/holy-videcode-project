# IOGPUDeviceUserClient sel 25 — «OOB по stride»: проверка и вердикт

**Бинарь:** `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (67 239 936 Б, fileset).
**Устройство:** iPhone14,7 (A15) — в кэше ровно один GPU-kext: `com.apple.AGXG14P` (+ `com.apple.iokit.IOGPUFamily`).
**Адресация:** `__TEXT_EXEC` = `va - 0xfffffff007004000`; PAC-резолв `BASE + (q & 0x0FFFFFFF)`, `BASE = 0xfffffff007004000` (в тексте — младшие 32 бита VA).
**Метод:** статика (capstone 5.0.7) + ручной decode всех ключевых слов (`ldp/mul/umulh/cmp/mov/ldr/str/csel`), сверка с `vt.py`/`pat.py`. Скрипты: `work/sel25/tools`.
**Автор:** subagent AD.

---

## 0. Вердикт

| Вопрос | Ответ |
|---|---|
| OOB-чтение за `structureInput` в sel 25 | **Нет.** `stride` не «без нижней границы» — он сверяется на **точное равенство** с `[accel+0x268]`, а размер — на точное `count*stride`. Все чтения записи лежат внутри 0x40-байтной записи. |
| Примитив | **Никакого**: ни oracle, ни OOB read, ни aliasing. Отчёт `work/agx_iogpu/REPORT.md` §3.1 **опровергнут**. |
| Причина ошибки X2 | Перепутаны роли `scalar[2]` и `scalar[3]`; плюс взято значение `[accel+0x268]=0x30` из **базового** `IOGPUAccelerator::init`, которое AGXG14P **перезаписывает на 0x40** (`0x8174ec8`). |
| Соседние селекторы 6/8/26/27/38/39/45 | Чисто: у всех чтения ≤ объявленного размера (таблица §5). |

Короткая формула sel 25:

```
scalar[0] = queue id        (lookup в ns [dev+0x88], bounds+refcount)
scalar[1] = не используется
scalar[2] = count  (N)      — счётчик цикла
scalar[3] = stride (S)      — ДОЛЖЕН быть равен [accel+0x268] == 0x40
structureInputSize == N*S   (ровно, с umulh-проверкой переполнения)
запись 0x40 Б: +0x10, +0x18 (лог), +0x20 (id ресурса), +0x30, +0x38 (submit)
```

---

## 1. Точный дизасм sel 25 (`0x9947de4`)

### 1.1 Запись диспетчера

`0x7fea200 + 25*0x18`: `fn=0x9947de4`, `scIn=4`, `stIn=0xffffffff`, `scOut=1`, `stOut=0`.

`scOut=1` важно: `scalarOutput[0]` — валидный 8-байтовый буфер, `str x8,[args+0x48]` в конце не паникует.

### 1.2 Два пути входа

```
0x9947e18  ldr  x0, [x2, #0x40]      ; structureInputDescriptor
0x9947e1c  cbz  x0, 0x9947eac        ; → in-band путь
; --- descriptor путь (из userland недостижим, см. §6) ---
0x9947e20..0x9947e3c  map(vt+0xe8, 0x1000)
0x9947e40  cbz  x0, -> err (w19 += 6)
0x9947e44  mov  x20, x0              ; map-объект (release в эпилоге)
0x9947e48..0x9947e60  x23 = getBytes(vt+0x78)
0x9947e68..0x9947e84  x0  = getLength(vt+0xb0)
0x9947e88  b    0x9947ec4
; --- in-band путь ---
0x9947eac  ldr  w8, [x21, #0x28]     ; scalarInputCount
0x9947eb0  cmp  w8, #4
0x9947eb4  b.ne -> 0xE00002C2
0x9947eb8  mov  x20, #0              ; map = NULL
0x9947ebc  ldr  w0, [x21, #0x38]     ; structureInputSize (u32, zero-extend)
0x9947ec0  ldr  x23, [x21, #0x30]    ; structureInput
```

Общий хвост:

```
0x9947ec4  ldr  x8, [x21, #0x20]     ; scalarInput
0x9947ec8  ldp  x25, x24, [x8, #0x10]
             ; raw a9416119: Rt=x25=[x8+0x10]=scalar[2]
             ;              Rt2=x24=[x8+0x18]=scalar[3]
0x9947ecc  umulh x9, x24, x25        ; x9 = hi64(scalar[3]*scalar[2])
0x9947ed0  cbz  x9, 0x9947f10        ; переполнения нет
0x9947f10  mul  x9, x24, x25         ; x9 = count*stride (64-бит)
0x9947f14  cmp  x0, x9
0x9947f18  b.ne -> err               ; size == count*stride РОВНО
0x9947f1c  ldr  w1, [x8]             ; id очереди = scalar[0]
0x9947f20  ldr  x0, [x22, #0x120]    ; IOGPUDevice
0x9947f24  bl   0x9965da8            ; retainById(ns [dev+0x88], id)
0x9947f28  cbz  x0, -> err
0x9947f2c  mov  x22, x0              ; queue
0x9947f30  ldr  x8, [x0, #0x530]     ; queue->accel
0x9947f34  ldr  w8, [x8, #0x268]     ; <<< record size / stride
0x9947f38  cmp  x24, x8              ; scalar[3] == record size
0x9947f3c  b.ne -> err               ; ТОЧНОЕ равенство, не «>=»
0x9947f40  str  wzr, [sp, #0x1c]
0x9947f44  add  x4, sp, #0x1c
0x9947f48  mov  x0, x22 ; x1 = x23 ; x2 = x25 ; x3 = x24
0x9947f58  bl   0x9976cf8            ; worker(q, buf, count, stride, &out)
0x9947f5c  mov  x19, x0
0x9947f60  ldr  w8, [sp, #0x1c]
0x9947f64  ldr  x9, [x21, #0x48]     ; scalarOutput
0x9947f68  str  x8, [x9]             ; <<< наблюдаемый выход
0x9947f6c..0x9947f88  release(queue)
```

Ключевые слова проверены ручным decode (не только capstone):

| адрес | word | смысл |
|---|---|---|
| `0x9947ec8` | `a9416119` | LDP: `imm7=2 (0x10)`, `Rt=x25`, `Rt2=x24`, `Rn=x8` |
| `0x9947ecc` | `9bd97f09` | UMULH: `Rm=x25`, `Rn=x24`, `Rd=x9` |
| `0x9947f10` | `9b197f09` | MADD: `x9 = x25*x24 + xzr` |
| `0x9947f38` | `eb08031f` | SUBS xzr: `Rn=x24`, `Rm=x8` → `cmp x24,x8` |
| `0x9947f50/f54` | `aa1903e2` / `aa1803e3` | `mov x2,x25` / `mov x3,x24` |

### 1.3 Worker `0x9976cf8` — роли и цикл

```
0x9976d18  mov x20, x4        ; &out
0x9976d1c  mov x21, x3        ; >>> x21 = stride = scalar[3]
0x9976d20  mov x22, x2        ; >>> x22 = count  = scalar[2]
0x9976d24  mov x23, x1        ; buf
0x9976d28  mov x19, x0        ; q
...
0x9976d84  cbnz x22, loop     ; count != 0
loop:
0x9976e00  mul  x8, x25, x21  ; i * stride
0x9976e04  cmp  x8, w8, sxtw  ; overflow-check 32-битного смещения
0x9976e08  add  x24, x23, w8, sxtw
0x9976e0c  add  x16, x23, x8
0x9976e10  movk x16, #0x2bad, lsl #48   ; fail-stop poison при переполнении
0x9976e14  csel x24, x24, x16, eq
0x9976e18  ldr  w1, [x24, #0x20]        ; id ресурса
0x9976e1c  cbz  w1, 0x9976e4c
0x9976e20  ldr  x0, [q, #0x488]         ; device
0x9976e24  bl   0x9965b58               ; retainById(ns [dev+0x78], id)
0x9976e28  mov  x1, x0
0x9976e2c..0x9976e48  q->vt[16](q, obj) ; см. §2.2
0x9976e4c  bl   0x997700c               ; обработка записи (submit + лог)
0x9976e58  ldr  x0, [q, #0x580]         ; release obj, если был
0x9976e7c  str  xzr, [q, #0x580]
0x9976ebc  add  x25, x25, #1
0x9976ec0  subs x22, x22, #1
0x9976ec4  b.ne loop
```

Ручной decode: `aa0303f5` = `mov x21,x3`; `aa0203f6` = `mov x22,x2`; `9b157f28` = `x8 = x25*x21`; `f10006d6` = `subs x22,x22,#1`; `b9402301` = `ldr w1,[x24,#0x20]`.

**Итого:** цикл `count` раз, `rec = buf + i*stride`, `stride == [accel+0x268]`, `size == count*stride`.
Максимальный байт, который вообще читается из записи: `(count-1)*stride + 0x38 + 8 = count*stride`. Ровно конец буфера, ни байтом больше.

> Замечание про `0x2bad`: это не bounds-чек, а fail-stop на переполнении 32-битного смещения (сравнение `x8` с его sign-extended low32). При `count*stride < 2^31` ветка всегда «eq».

### 1.4 Откуда X2 взял `0x30` и почему это неверно

`[accel+0x268]` пишут три места во всём кэше:

| адрес | значение | кто |
|---|---|---|
| `0x997149c` | `0x30` | базовый `IOGPUAccelerator::init` (IOGPUFamily), рядом `[+0x278]=0x408` (`0x99714cc`) |
| `0x8174ec8` | **`0x40`** | `AGXG14P`, init/start акселератора; рядом `[+0x278]=0x410` (`0x8174ed0`), `[+0x270]=0x1e` |
| `0x8187bd8` | `[x20+0x534]` | AGX, копия конфига «источник → акселератор» (firmware-поле record size) |

```
0x8174ec0  str  x0, [x26, #0x368]
0x8174ec4  mov  w8, #0x40
0x8174ec8  str  w8, [x19, #0x268]     ; <<< stride/record size
0x8174ecc  mov  w8, #0x410
0x8174ed0  str  w8, [x19, #0x278]     ; <<< sizeof(queue init struct)
0x8174ed4  mov  w8, #0x1e
0x8174ed8  str  w8, [x19, #0x270]
```

AGX-оверрайд `submitCommandBuffer` (`0x818eb40`, слот 35) читает ровно те поля 0x40-записи, которые определены в воркере:

```
0x818eb94  ldr  w1, [x20, #0x30]      ; cb_args+0x30
0x818eb98  ldr  x2, [x20, #0x38]      ; cb_args+0x38
0x818eb9c..0x818ebb4  [fw+0xa8]->vt[0x90](x0, w1, x2)
```

Это и есть доказательство, что record size на AGX = **0x40**, а не 0x30: базовый `submit` для «0x30-акселераторов» — другой код; AGX-оверрайд обязан укладываться в `[accel+0x268]`, иначе драйвер читал бы за записью в штатном сценарии. Проверка sel 25 (`stride == [accel+0x268]`) — сильнейшая из возможных, она пинит ABI.

---

## 2. Что происходит с id

### 2.1 Lookup

```
0x9965b58  ldr x0, [x0, #0x78]      ; ns ресурсов устройства
0x9965b60  b   0x9945040            ; retainById
0x9945040  lock(ns+0x20); 0x9944fb8; unlock
0x9944fb8  cbz w1 -> NULL           ; id == 0 невалиден
0x9944fd0  ldr w8, [ns+0x28]        ; capacity
0x9944fd4  cmp w1, w8 ; b.hs NULL   ; id < capacity
0x9944fdc  ldr x8, [ns+0x10]        ; base
0x9944fe0  ubfiz x9, x1, #3, #32
0x9944ff8  ldr x0, [x8 + id*8]
0x9944ffc  cbz x0 -> NULL
0x9945000  add x8, x0, #0xc         ; refcount++
```

id — это **индекс в массиве** (0-based; 0 трактуется как «нет объекта»). Аллокатор `0x9944654` (`addObject`, под локом `0x9944798`) выдаёт первый свободный бит из bitset `[ns+0x18]` → id маленькие и последовательные.

### 2.2 Слот 16 (`vt+0x80`) — что делает с объектом

AGX vtable `0x7c93bb8`, слот 16 = `0x819a468`:

```
0x819a47c  mov  x19, x1                       ; obj
0x819a480  adrp x8, &__ZTV15IOGPUCommandQueue
0x819a488  ldr  x9, [x8, #0x90]!              ; __ZTV+0x90 = fn table+0x80 = слот 16 базы
0x819a494  blraa x9, x17                      ; база: 0x997a40c
0x819a498  cbz  x19, ret
0x819a49c  adrp x1, &meta(0xae22130 = AGXDebugBufferShmem)
0x819a4a8  bl   0x8216040                     ; OSDynamicCast/isKindOf
0x819a4ac  cbz  x0, ret
0x819a4b0  str  wzr, [x19, #0x68]
```

База (`0x997a40c`): `str x1, [x0, #0x580]` — «текущий ресурс» очереди.

То есть: `q->[0x580] = obj`; если объект — `AGXDebugBufferShmem` (класс `0xae22130`, размер 0x70, ctor `0x819d040`, vtable `0x7c94040`), то `obj->[0x68] = 0`. Запись в чужой объект защищена `isKindOf`, type-confusion нет.

`q->[0x580]` больше **нигде не читается** кроме release в конце итерации (проверено сканом `ldr [x,+0x580]` и `add x,+0x580` по IOGPUFamily и AGXG14P). То есть объект держится только как lifetime-пин на время обработки записи.

### 2.3 `0x997700c` — остальные аргументы записи

| поле | куда |
|---|---|
| `+0x10` (u64) | `0x994f180` → трейс-лог (`[0x7ff27d8]->vt[0xa0]`), не firmware |
| `+0x18` (u64) | туда же + `[q+0x518]->vt[0x90]` |
| `+0x38` (u64), `+0x30` (u32) | `q->vt[35]` = AGX submit `0x818eb40` → `[fw+0xa8]->vt[0x90]` |
| `+0x20` (u32) | id (см. выше) |

Больше ничего из записи не читается (полный список `[x21,…]` в `0x997700c`: `+0x10`, `+0x18`).

### 2.4 Невалидный id

`id == 0` → `cbz w1` → lookup и слот 16 **пропускаются**, ошибки нет, submit всё равно выполняется. Несуществующий/чужевой id → `retainById` вернул NULL → слот 16 получает `x1 = NULL` → база пишет NULL в `q->[0x580]` → в конце итерации `cbz` → тишина. **Валидность id не влияет ни на код возврата, ни на `[q+0x520]`.**

### 2.5 Aliasing

Поскольку OOB нет, id — это просто пользовательский u32 из записи, и он **и так полностью контролируем**. Значит:

* «OOB-значение попало на чужой объект» — сценария не существует.
* Вопрос «можно ли назвать чужой id» от дефекта не зависит: `retainById` проверяет только `0 < id < capacity` и non-NULL, **проверки владельца/task в этом пути нет**; ns висит на `IOGPUDevice` (`+0x78`), а не на user client'е. Статически это значит, что клиент одного и того же GPU-сервиса может назвать любой живой id. Эксплуатируемость (чья это память на стороне firmware/IOMMU) **не подтверждена** — нужна динамика; к sel 25 как к дефекту это отношения не имеет.

---

## 3. Управляемость OOB

Предмета нет: буфер всегда ровно `count*stride`, чтения ≤ `+0x38..0x3f`.

Для справки (если бы stride был меньше): в in-band пути `structureInput` — kernel-копия трепа `IOConnectCallMethod` длиной ровно `structureInputSize`; `structureInputDescriptor` (+0x40) из userland не выставляется (§6), поэтому «страничный» вариант с user-маппингом тоже не применим.

---

## 4. Наблюдаемый выход

`scalarOutput[0] = [q+0x520]` (u32, zero-extended) — статус воркера. Значения:

| код | откуда |
|---|---|
| 0 | успех (`0x9976ec8`, либо `0x9976f1c`) |
| 4 | `0x9976d7c` — `[q+0x43a] bit0`, «resubmit»-состояние |
| 6 | `0x9976fec` — очередь не смогла обработать запись |
| 8 | `0x9977234` — `[q+0x518]` не создан |
| `0xE00002C2` | ошибка sel 25 (size/stride/count/lookup очереди) |

Код возврата самого селектора = тот же статус воркера. **Оракула на содержимое id нет**: ни валидность id, ни класс объекта, ни прочитанные поля в выход не попадают.

---

## 5. Соседние селекторы — та же проверка

| sel | stIn | проверка в теле | максимум чтения | OOB |
|---|---|---|---|---|
| 6 | var | `size >= 0x408 && size == [accel+0x278]` (=0x410) | `+0x405` (+ memcpy 0x400) | нет |
| 8 | var | `size >= 0x58` + `outSize >= [dev+0x234]+0x58` | `+0x50` (u32) → 0x54 | нет |
| 25 | var | `size == count*stride` + `umulh` + `stride == recsize` | `+0x38`+8 = recsize | нет |
| 26 | 0xc | точный (диспетчер) | `+0x30`+8 = 0x38 | нет |
| 27 | 0x4 | точный (диспетчер) | `+0x30`+4 | нет |
| 38 | 0x18 | точный (диспетчер) | `+0x10`+8 = 0x18 | нет |
| 39 | 0x18 | точный (диспетчер) | `+0x10`+8 = 0x18 | нет |
| 45 | var | `size>=8`, `(size-8)%24==0`, `[buf]==(size-8)/24` | `+0x10` (в 24-Б записи) | нет |

sel 45: повторное чтение `[buf]` в цикле (`0x995b4d4`) безопасно для in-band (kernel-копия неизменяема). Для descriptor-пути — TOCTOU, но путь из userland недостижим (§6).

sel 8: полный список чтений входа `x23`: `+0x00,+0x04,+0x14,+0x15,+0x18,+0x20,+0x28,+0x30,+0x38,+0x3c,+0x40(16Б),+0x48,+0x50` → максимум `+0x53`, при `size>=0x58`.

---

## 6. Не подтверждено

| Утверждение | Почему |
|---|---|
| Достижимость `structureInputDescriptor` (+0x40) из app-песочницы | `IOConnectCall*` кладёт структуру in-band; дескриптор — для kernel-клиентов (совпадает с выводом X2/Z2) |
| Кросс-клиентский доступ к id в ns `[dev+0x78]` | статически проверки владельца нет; ns на device; нужна динамика (два клиента, чужой id) |
| Точная семантика `[fw+0xa8]->vt[0x90](w1=rec+0x30, x2=rec+0x38)` | firmware-объект, дальше не разбирался |
| `[accel+0x534] → +0x268` в copy-пути `0x81878ec` | значение приходит из firmware-конфига; на G14P должен быть 0x40 (иначе AGX submit читал бы за записью) — динамикой не снято |
| `q+0x580` не инициализируется в init (только пишется слотом 16 и зануляется в конце итерации) | остаточный риск только если объект пришёл из чужого типа; на практике предыдущая очередь всегда оставляет 0 |

---

## 7. Рецепт проверки (falsifiable, negative-тест)

1. `IOServiceOpen` на IOGPU-сервис (профиль `container`), sel 6 → queue id.
2. sel 25: `scalarInput = { qid, 0, N=1, S=0x30 }`, `structureInput` = 0x30 Б нулей.
   **Ожидание:** `kIOReturnBadArgument (0xE00002C2)` — потому что `[accel+0x268] == 0x40`, а не потому что «stride слишком мал».
3. sel 25: `scalarInput = { qid, 0, 1, 0x40 }`, `structureInput` = 0x40 Б нулей.
   **Ожидание:** `0` и `scalarOutput[0] == 0`; запись с `id=0` ничего не делает.
4. sel 25: та же запись, но `+0x20 = валидный id` своего ресурса.
   **Ожидание:** тот же `0`; на стороне очереди — `q->[0x580]` на время итерации (наблюдаемо только косвенно).
5. sel 25: `scalarInput = { qid, 0, 2, 0x40 }`, size = 0x80, но `structureInputSize` объявить 0x7F.
   **Ожидание:** `0xE00002C2` (точное произведение).
6. Контроль «0x30 vs 0x40»: если шаг 2 вернул `0` (а не ошибку), значит на этом образе `[accel+0x268] == 0x30`, и тогда AGX submit `0x818eb94` читает за записью — это был бы **другой** дефект; на 24B115/AGXG14P ожидается ошибка.

---

## 8. Артефакты

* `work/sel25/REPORT.md` — этот отчёт.
* `work/sel25/progress.md` — журнал.
* `work/sel25/tools/{kc.py,vm.py,d.py,tbl.py,vt.py,pat.py,x78.py,adrp.py,adrp2.py,callers.py,base.py,f.py,s.py}`.
* Опровергаемый отчёт: `work/agx_iogpu/REPORT.md` §3.1 (и строка про sel 25 в §5/§7).
