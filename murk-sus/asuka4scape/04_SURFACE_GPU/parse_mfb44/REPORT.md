# `IOMobileFramebufferUserClient`, селектор `0x44` — разбор и вердикт

target: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (67 239 936 B)
ветка: subagent I (после G). Всё ниже — только то, что прострелено по байтам этого файла.
Устройство: kext `com.apple.driver.AppleMobileDispH14P-DCP` (H14P), iOS 27.2 (24B115).

---

## 0. Итог одной строкой

**Type confusion с вызовом `release` на пользовательском указателе — НЕ подтверждён и опровергнут.**
Ветка `0x0b` селектора `0x44` не разыменовывает первый u64 как `OSObject*`, а только сравнивает его
с нулём и превращает в `bool`. Виртуального `release` в этом пути нет вообще. Реально найденный
дефект в этом же обработчике — **чтение `*(u64*)args->structureInput` без NULL-чека**
(`0xfffffff009aa4358`), то есть потенциальный NULL-deref → panic (DoS). Достижимость — см. §7,
помечена как «не подтверждено на устройстве».

---

## 1. Точки опоры

| что | адрес |
|---|---|
| `IOMobileFramebufferUserClient::externalMethod` | `0xfffffff009aa33b8` |
| таблица диспетчеризации (101 запись, stride `0x28`) | `0xfffffff008023ad0` |
| запись `0x44` | `0xfffffff008024570` → fn `0xfffffff009aa42dc` |
| обработчик селектора `0x44` | **`0xfffffff009aa42dc`** |
| `this->[0xd8]` (framebuffer) | `OSDynamicCast(IOMobileFramebuffer*, provider)`, `0xfffffff009aa1668` → `0xfffffff00a894f30` |
| метакласс `IOMobileFramebuffer` | `0xfffffff00af28460` (getMetaClass `0xfffffff009aa5638`) |
| реальный класс провайдера | `AppleCLCD2`, meta `0xfffffff00aec9b78`, size `0x61b8`, ctor `0xfffffff008e9fbc0` |
| **instance vtable `AppleCLCD2`** | **`0xfffffff007e71088`** (пишется в ctor `0xfffffff008e9fc24`) |
| **`vtable[0x780]`** | **`0xfffffff009a754cc`** ← настоящий обработчик опкодов |
| `vtable[0x5c0]` (гейт перед диспетчеризацией) | `0xfffffff009a778d8` |
| `vtable[0x720]` (sel `0x4e`) | `0xfffffff009a742f4` |
| `vtable[0x728]` (sel `0x4f`) | `0xfffffff009a74528` |
| `vtable[0xa28]` (default-ветка опкодов) | `0xfffffff009a884a8` |
| `vtable[0x8b0]` (DCP-прокси) | `0xfffffff008ea0a6c` |
| `vtable[0x890]` | `0xfffffff008ea4f58` |

Цепочка вызова:
`externalMethod` → валидатор `0xfffffff00a9b0888` → `0x9aa42dc(sel=0x44)` →
`fb = *(this+0xd8)` → `fb->vtable[0x780](fb, opcode, structureInput, count)`.

`this->[0xd8]` — это не «какой-то объект», а результат `OSDynamicCast` провайдера к
`IOMobileFramebuffer`; на этом устройстве провайдер — `AppleCLCD2`, поэтому слот `+0x780`
разрешается в код AppleCLCD2, а не в базовый (в базовой vtable `0x8024b08` слот `+0x780` —
`0xfffffff00aa61974`, stub `panic()`, т.е. непереопределённый pure virtual).

---

## 2. Полный дизасм обработчика `0xfffffff009aa42dc`

```
; x0 = this (IOMobileFramebufferUserClient), x1 = selector, x2 = IOExternalMethodArguments*
fffffff009aa42dc  bti      c
fffffff009aa42e0  pacibsp
fffffff009aa42e4  stp      x22, x21, [sp, #-0x30]!
fffffff009aa42e8  stp      x20, x19, [sp, #0x10]
fffffff009aa42ec  stp      x29, x30, [sp, #0x20]
fffffff009aa42f0  add      x29, sp, #0x20
fffffff009aa42f4  mov      x21, x2                  ; x21 = args
fffffff009aa42f8  mov      x22, x0                  ; x22 = this
fffffff009aa42fc  ldr      x8, [x2, #0x20]          ; args->scalarInput
fffffff009aa4300  ldr      w19, [x8]                ; w19 = scalarInput[0]  <-- ОПКОД ОТ ПОЛЬЗОВАТЕЛЯ
fffffff009aa4304  ldr      w8, [x2, #0x38]          ; w8  = (u32)args->structureInputSize
fffffff009aa4308  lsr      w20, w8, #3              ; w20 = size/8 = "сколько u64"
fffffff009aa430c  cmp      w19, #0x11
fffffff009aa4310  b.ne     #0xfffffff009aa4340
; --- case 0x11: требуется энтайтлмент ---
fffffff009aa4314  ldr      x0, [x22, #0xe8]         ; x0 = this->task
fffffff009aa4318  adrp     x1, #0xfffffff00785d000
fffffff009aa431c  add      x1, x1, #0x744           ; "com.apple.private.gain-map-access"
fffffff009aa4320  bl       #0xfffffff009abd1cc      ; GOT 0x8029e50 -> 0xa9dee48 (has-entitlement)
fffffff009aa4324  cbnz     w0, #0xfffffff009aa4370  ; есть энтайтлмент -> общая диспетчеризация
fffffff009aa4328  mov      w0, #0x2c1
fffffff009aa432c  movk     w0, #0xe000, lsl #16     ; kIOReturnNotPrivileged (0xe00002c1)
fffffff009aa4330  ldp/l... ; epilogue
fffffff009aa433c  retab
; --- прочие опкоды ---
fffffff009aa4340  cmp      w19, #1
fffffff009aa4344  ccmp     w20, #2, #0, eq          ; opcode==1 && size/8==2 ?
fffffff009aa4348  b.eq     #0xfffffff009aa436c      ; -> w20 = 1 (count форсится в 1)
fffffff009aa434c  cmp      w19, #0xb
fffffff009aa4350  b.ne     #0xfffffff009aa4370      ; не 0x0b -> общая диспетчеризация
; --- case 0x0b ---
fffffff009aa4354  ldr      x8, [x21, #0x30]         ; x8 = args->structureInput
fffffff009aa4358  ldr      x8, [x8]                 ; <-- ЧТЕНИЕ *structureInput БЕЗ NULL-ЧЕКА
fffffff009aa435c  cbz      x8, #0xfffffff009aa43cc
fffffff009aa4360  add      x0, x22, #0xfc
fffffff009aa4364  bl       #0xfffffff009abd20c      ; GOT 0x8029e70 -> 0xa8945fc: atomic +1 на this+0xfc
fffffff009aa4368  b        #0xfffffff009aa4370
fffffff009aa436c  mov      w20, #1
fffffff009aa4370  ldr      x0, [x22, #0xd8]         ; x0 = framebuffer
fffffff009aa4374  ldr      x2, [x21, #0x30]         ; x2 = args->structureInput
fffffff009aa4378  ldr      x16, [x0]                ; x16 = fb->vtable (PAC, key D)
fffffff009aa437c  mov      x17, x0
fffffff009aa4380  movk     x17, #0xcda1, lsl #48
fffffff009aa4384  autda    x16, x17                 ; модификатор = fb | 0xcda1<<48
fffffff009aa4388  mov      x17, #0x780
fffffff009aa438c  add      x16, x16, x17
fffffff009aa4390  ldr      x8, [x16]                ; x8 = vtable[0x780] (PAC, key A)
fffffff009aa4394  mov      x4, x16
fffffff009aa4398  mov      x16, x8
fffffff009aa439c  mov      x1, x19                  ; arg1 = opcode
fffffff009aa43a0  mov      x3, x20                  ; arg3 = count
fffffff009aa43a4  ... epilogue ...
fffffff009aa43c0  mov      x17, x4
fffffff009aa43c4  movk     x17, #0x4ee4, lsl #48
fffffff009aa43c8  braa     x16, x17                 ; tail-call vtable[0x780](fb, op, struct, count)
fffffff009aa43cc  add      x0, x22, #0xfc
fffffff009aa43d0  bl       #0xfffffff009abd1fc      ; GOT 0x8029e68 -> 0xa89460c: atomic -1 на this+0xfc
fffffff009aa43d4  b        #0xfffffff009aa4370
```

Ключи:
* опкод — `*(u32*)args->scalarInput` (`+0x20`), полностью пользовательский;
* `count` — `(u32)args->structureInputSize >> 3` (`+0x38`); в таблице у записи `0x44`
  `checkStructureInputSize = -1`, т.е. **размер не проверяется**;
* `structureInput` читается из `args+0x30` (не из дескриптора `args+0x40`);
* `0x9abd20c/0x9abd1fc` — это GOT-трамплины в `0xa8945fc` (`mov w8,#1; ldadd w8,w0,[x0]`) и
  `0xa89460c` (`mov w8,#-1; ldadd w8,w0,[x0]`) — атомарный инкремент/декремент u32 по `this+0xfc`.

---

## 3. Что на самом деле делает «ветка 0x0b»

```
x8 = *(u64*)structureInput;
if (x8 != 0)  atomic_add(this+0xfc, +1);
else          atomic_add(this+0xfc, -1);
goto dispatch(opcode=0xb, structureInput, count);
```

Ни `OSDynamicCast`, ни `getMetaClass()`, ни `isOSObject`, ни `release` — **ничего этого нет**.
Значение используется только как логическое. `this+0xfc` — счётчик «сколько раз gain-map включён»:
инициализируется нулём в `0xfffffff009aa14ac`, а в пути закрытия клиента
(`0xfffffff009aa17d0`) крутится цикл

```
w0 = atomic_dec_return(this+0xfc);
while (w0 > 0)
    fb->vtable[0x780](fb, 0xb, &zero_u64, 1);   ; сброс состояния
    w0 = atomic_dec_return(this+0xfc);
```

то есть это парный «set/reset» флага, а не управление жизнью объекта.

**Вывод по §3: исходное подозрение (type confusion + виртуальный `release` по пользовательскому
указателю) — ложное. Никакого разыменования пользовательского значения как объекта нет.**

---

## 4. Настоящий получатель: `AppleCLCD2::vtable[0x780]` = `0xfffffff009a754cc`

```
; x0 = fb (AppleCLCD2*), w1 = opcode, x2 = structureInput, x3 = count
fffffff009a754cc  bti      c
fffffff009a754d0  pacibsp
...
fffffff009a754ec  mov      x22, x3                 ; x22 = count
fffffff009a754f0  mov      x21, x2                 ; x21 = struct
fffffff009a754f4  mov      x23, x1                 ; x23 = opcode (сохраняется)
fffffff009a754f8  mov      x20, x0                 ; x20 = this
fffffff009a754fc  mov      w24, #0x1c9
fffffff009a75500  movk     w24, #0x3180, lsl #16   ; trace-id 0x318001c9
fffffff009a75508  ...
fffffff009a75524  bl       #0xfffffff009a9a8a0     ; лог входа (id, opcode, 0,0,0,0)
fffffff009a75528  cmp      w23, #0xa
fffffff009a7552c  b.le     #0xfffffff009a7557c
fffffff009a75530  cmp      w23, #0xb
fffffff009a75534  b.eq     #0xfffffff009a75590    ; case 0xb
fffffff009a75538  cmp      w23, #0x14
fffffff009a7553c  b.eq     #0xfffffff009a755d8    ; case 0x14
fffffff009a75540  cmp      w23, #0x1c
fffffff009a75544  b.ne     #0xfffffff009a75650    ; default
; ---- case 0x1c ----
fffffff009a75548  cmp      w22, #1
fffffff009a7554c  b.ne     #0xfffffff009a7561c    ; count != 1 -> 0xe00002c2
fffffff009a75550  ldr      x8, [x21]               ; in[0]
fffffff009a75554  cmp      x8, #0
fffffff009a75558  cset     w2, ne                  ; w2 = (in[0] != 0)
fffffff009a7555c  ldr      x0, [x20, #0x148]       ; IOCommandGate*
fffffff009a75560  adrp     x16, #0xfffffff009a83000
fffffff009a75564  add      x16, x16, #0xd6c         ; action = 0x9a83d6c: w1=(x1!=0); b 0x9a756f8
fffffff009a75568  mov      x17, #0xbd41
fffffff009a7556c  pacia    x16, x17
fffffff009a75570  mov      x1, x16
fffffff009a75574  mov      x3, #0
fffffff009a75578  b        #0xfffffff009a756a8    ; runAction(gate, action, struct, count, 0,0)
; ---- opcode <= 0xa ----
fffffff009a7557c  cbz      w23, #0xfffffff009a75628 ; case 0
fffffff009a75580  cmp      w23, #9
fffffff009a75584  b.ne     #0xfffffff009a75650    ; default
fffffff009a75588  mov      w23, #0                 ; case 9: return 0
fffffff009a7558c  b        #0xfffffff009a756b8
; ---- case 0xb ----
fffffff009a75590  mov      w23, #0x2c2
fffffff009a75594  movk     w23, #0xe000, lsl #16   ; ret = 0xe00002c2
fffffff009a75598  cmp      w22, #1
fffffff009a7559c  b.ne     #0xfffffff009a756b8    ; count != 1 -> error
fffffff009a755a0  ldr      x21, [x21]              ; x21 = in[0]
fffffff009a755a4  cmp      x21, #0
fffffff009a755a8  cset     w8, ne
fffffff009a755ac  str      x8, [sp]                 ; в лог: (in[0] != 0)
fffffff009a755b0  adrp     x0, #0xfffffff007854000
fffffff009a755b4  add      x0, x0, #0x94e
fffffff009a755b8  bl       #0xfffffff009a99bc0
fffffff009a755bc  ldr      x0, [x20, #0x438]        ; объект-получатель свойства
fffffff009a755c0  cbz      x0, #0xfffffff009a756f0  ; NULL -> kIOReturnNotFound-ish (ret-6)
fffffff009a755c4  cmp      x21, #0
fffffff009a755c8  cset     w1, ne                  ; w1 = bool
fffffff009a755cc  mov      w2, #0
fffffff009a755d0  bl       #0xfffffff009a932e4      ; set(bool) на подобъекте
fffffff009a755d4  b        #0xfffffff009a756b4
; ---- case 0x14 ----
fffffff009a755d8  cmp      w22, #1
fffffff009a755dc  b.ne     #0xfffffff009a7561c
fffffff009a755e0  ldr      x8, [x21]
fffffff009a755e4  cmp      x8, #0
fffffff009a755e8  cset     w1, eq                  ; w1 = (in[0] == 0)
fffffff009a755ec  ldr      x16, [x20]
fffffff009a755f0  mov      x17, x20
fffffff009a755f4  movk     x17, #0xcda1, lsl #48
fffffff009a755f8  autda    x16, x17
fffffff009a755fc  mov      x17, #0x788
fffffff009a75600  add      x16, x16, x17
fffffff009a75604  ldr      x8, [x16]
fffffff009a75608  mov      x0, x20
fffffff009a7560c  mov      x2, x20
fffffff009a75610  movk     x16, #0x9852, lsl #48
fffffff009a75614  blraa    x8, x16                 ; vtable[0x788](this, bool, this)
fffffff009a75618  b        #0xfffffff009a756b4
fffffff009a7561c  mov      w23, #0x2c2
fffffff009a75620  movk     w23, #0xe000, lsl #16
fffffff009a75624  b        #0xfffffff009a756b8
; ---- case 0 ----
fffffff009a75628  ldr      x0, [x20, #0x438]
fffffff009a7562c  cbz      x0, #0xfffffff009a75688
fffffff009a75630  ldr      x16, [x0]
fffffff009a75634  mov      x17, x0
fffffff009a75638  movk     x17, #0xcda1, lsl #48
fffffff009a7563c  autda    x16, x17
fffffff009a75640  ldr      x8, [x16, #0xb0]!       ; getLength()/isReady()
fffffff009a75644  movk     x16, #0x3a5, lsl #48
fffffff009a75648  blraa    x8, x16
fffffff009a7564c  tbz      w0, #0, #0xfffffff009a75688
; ---- default / fallthrough ----
fffffff009a75650  ldr      x16, [x20]              ; this->vtable[0xa28]
fffffff009a75654  ...
fffffff009a75668  ldr      x8, [x16]
fffffff009a7566c  mov      x0, x20
fffffff009a75670  mov      x1, x23                 ; opcode
fffffff009a75674  mov      x2, x21                 ; struct
fffffff009a75678  mov      x3, x22                 ; count
fffffff009a75680  blraa    x8, x16                 ; -> 0x9a884a8
fffffff009a75684  b        #0xfffffff009a756b4
fffffff009a75688  ... runAction(gate, action=0x9a83d20, struct, count, 0, 0)
fffffff009a756b4  mov      x23, x0
fffffff009a756b8  ... лог выхода (id 0x318001ca) ...
fffffff009a756d4  mov      x0, x23
fffffff009a756ec  retab
```

`0x9a884a8` (default, `vtable[0xa28]`):

```
fffffff009a884bc  cmp      w3, #5
fffffff009a884c0  b.lo     #0xfffffff009a884f4   ; count >= 5 -> лог + 0xe00002c2
fffffff009a884f4  ...
fffffff009a88500  str      w1, [sp, #0x28]       ; [buf+0] = opcode
fffffff009a88518  ldr      x11, [x2, x8, lsl #3]  ; копия ровно count qwords (<=4) в buf+4..
fffffff009a8852c  str      w8, [sp, #0x24]       ; out = 0xAAAAAAAA
fffffff009a88534  str      w3, [sp, #0x4c]       ; [buf+0x24] = count
fffffff009a88550  ldr      x8, [x16]             ; vtable[0x8b0]
fffffff009a88554  add      x2, sp, #0x28         ; фиксированный буфер 0x28
fffffff009a8855c  mov      w1, #0x3030
fffffff009a88560  movk     w1, #0x4135, lsl #16  ; 0x41353030
fffffff009a88564  mov      w3, #0x28
fffffff009a88568  mov      w5, #4
fffffff009a88570  blraa    x8, x16               ; DCP-прокси
```

`vtable[0x8b0] = 0x8ea0a6c`: `x0 = this->[0x5e30]; if (!x0) return 0xe00002d8; tail-call 0x8eb91e0`.
Никаких пользовательских указателей.

---

## 5. PAC: что именно аутентифицируется

Два независимых уровня:

1. **Указатель на vtable** (`fb->[0]`): `autda x16, (fb | 0xcda1<<48)` — ключ **D**, модификатор —
   адрес самого объекта с классовой константой `0xcda1` в старших 16 битах.
2. **Элемент vtable** (`vtable+0x780`): `braa x16, (slot_addr | 0x4ee4<<48)` — ключ **A**,
   модификатор — адрес слота с константой `0x4ee4`.

Практический смысл: запись произвольного значения в слот `+0x780` (или в `[fb]`) не даёт вызова —
`braa`/`autda` не аутентифицируют подделку и уводят в `brk #0xc471` / data-abort, то есть в **panic**,
а не в control-flow hijack. Именно поэтому даже гипотетическая запись в vtable здесь не даёт
произвольного вызова. (То же самое для `vtable[0x788]`, `[0xa28]`, `[0x8b0]` — все вызовы идут через
`autda`+`braa` с модификатором-адресом слота.)

Отдельно: `bl 0x9abd1cc/0x9abd1fc/0x9abd20c` — это GOT-трамплины (`adrp x17,page; add x17,#imm;
ldr x16,[x17]; braa x16,x17`), слоты `0x8029e50/0x8029e68/0x8029e70` → `0xa9dee48` (entitlement),
`0xa89460c` (atomic -1), `0xa8945fc` (atomic +1).

---

## 6. Таблица веток опкодов селектора `0x44`

Опкод — `scalarInput[0]` (u32). `count = structureInputSize>>3`.

| опкод | что делает клиент (`0x9aa42dc`) | что делает fb (`0x9a754cc`) | работа с пользовательскими указателями/длинами | вердикт |
|---|---|---|---|---|
| `0x00` | проброс | `[this+0x438]` → `vtable[0xb0]`; если «ready» — `IOCommandGate::runAction(action=0x9a83d20, struct, count, 0,0)`; action: `if (count==4) copy 4 qwords → this+0x6b8` иначе `0xe00002c2` | struct читается только при `count==4`; запись в поля объекта фиксированного размера | чисто |
| `0x01` | если `count==2`, форсит `count=1` | default → `vtable[0xa28]` | `count<5` → копия ≤4 qword в буфер 0x28 | чисто |
| `0x09` | проброс | `return 0` | нет | чисто |
| **`0x0b`** | `x8 = *(u64*)structureInput` **без NULL-чека**; `x8!=0` → `atomic +1 [this+0xfc]`, иначе `atomic -1`; затем вызов | требует `count==1`; `in[0]` только сравнивается с 0 → `bool` → `0x9a932e4(this->[0x438], bool, 0)` | значение **не** разыменовывается; но само чтение `*(u64*)structureInput` может упасть на NULL | **ложное подозрение**; остаётся NULL-deref (см. §7) |
| `0x11` | требует энтайтлмент `com.apple.private.gain-map-access`, иначе `0xe00002c1` | default → `vtable[0xa28]` | `count<5` | чисто (закрыт энтайтлментом) |
| `0x14` | проброс | требует `count==1`; `bool = (in[0]==0)`; `vtable[0x788](this, bool, this)` | только bool | чисто |
| `0x1c` | проброс | требует `count==1`; `bool=(in[0]!=0)`; `runAction(action=0x9a83d6c, struct, count, 0,0)`; action: `w1=(x1!=0)` → `0x9a756f8` | указатель превращается в bool | чисто |
| прочие | проброс | default → `0x9a884a8` | `count>=5` → `0xe00002c2`; иначе копия ≤4 qword в фикс. буфер 0x28 и DCP-прокси | чисто |

Итог по таблице: **ни одна ветка не трактует пользовательские данные как указатель**. Единственное
место, где пользовательское значение используется как адрес, — `0x9aa4354/0x9aa4358`, и это чтение
*самого буфера* `structureInput`, а не «объекта по указателю из буфера».

---

## 7. Единственный реальный дефект: NULL-deref в `0x9aa4358`

```
0x9aa4354  ldr x8, [x21, #0x30]   ; args->structureInput
0x9aa4358  ldr x8, [x8]           ; <-- нет cbz
```

Для сравнения, соседний обработчик `0x4e` (`0x9aa3d3c`) этот указатель проверяет:
`ldr x19,[x2,#0x30]; cbz x19, error`. Здесь проверки нет.

Условия:
* `scalarInputCount == 1` (таблица: `checkScalarInputCount = 1`) — выполняется тривиально;
* `scalarInput[0] == 0x0b`;
* `structureInput == NULL` — то есть вызов без inband-структуры (`IOConnectCallMethod`,
  `structureInputSize = 0`) либо с одним только `structureInputDescriptor`.

Тогда ядро читает адрес 0 → translation fault → panic. Это **DoS, не RCE**: управляемого значения
ядро не получает, только падает.

Статус: **не подтверждено на устройстве**. Код-путь однозначен; вопрос только в том, кладёт ли
MIG/IOKit `args->structureInput = NULL` при нулевой длине (повсеместные `cbz` на этот указатель в
IOKit-драйверах и в самом MFBUC говорят, что да). Проверка — одним вызовом
`IOConnectCallMethod(conn, 0x44, &op, 1, NULL, 0, NULL, NULL, NULL, NULL)` с `op = 0x0b`;
на устройстве с включённым debug-kext это даст панику в `0x9aa4358`.

Остальные опкоды (`0x14`, `0x1c`, `0x00`, default) в клиенте не читают `structureInput` до
диспетчеризации, поэтому NULL для них безопасен: fb-слой проверяет `count` до любого чтения
(`cmp w22,#1; b.ne`), а `count` при `structureInputSize == 0` равен 0.

---

## 8. `0x4e` / `0x4f` — туда, куда уходит «сырой» `structureInput` с непроверенным размером

Записи таблицы:
`0x4e` — `fn=0x9aa3d3c`, `sci=-1, sis=-1, soc=-1, sos=-1`;
`0x4f` — `fn=0x9aa3e34`, то же.

### 8.1 клиент `0x4e` (`0x9aa3d3c`)

```
ldr  x19,[x2,#0x30]        ; structureInput
cbz  x19, 0xe00002c2       ; NULL-чек ЕСТЬ
ldr  w8,[x2,#0x28]         ; scalarInputCount
cmp  w8,#2 ; b.lo error
w20 = scalarInput[0]       ; op
bl   0x9aa19f4(task, op, this->[0x104], this->[0x108])   ; проверка пары (task,id)
w3  = scalarInput[1]       ; val
w5  = scalarInputCount-2   ; count
x4  = (count ? &scalarInput[2] : NULL)
w7  = (u32)args->structureInputSize     ; <-- без проверки (sis = -1)
fb->vtable[0x720](fb, task, op, val, x4, count, structureInput, w7)
```

### 8.2 `fb->vtable[0x720]` = `0x9a742f4`

Это сеттер свойства AppleCLCD2. Он:
* читает флаг `this+0x5870` (bit0); если флаг **установлен** — лог и сразу `0xe00002d8`;
* иначе собирает на стеке структуру и вызывает `0x9a73db8(this, &msg, op, val, size, task, 1)`.

`0x9a73db8` — ключевое место. Структура разбирается **не как сырой блоб**, а по описателю:

```
0x9a73e3c  ldr  w10,[x27]        ; x27 = structureInput; w10 = *(u32*)struct  <-- id свойства
0x9a73e48  ldr  w13,[x12,x13]    ; цикл по таблице: ищем запись с entry->id == w10
0x9a73e74  ldrh w8,[x11,#4]      ; desc->off0  (u16)
0x9a73e78  ldrh w9,[x11,#6]      ; desc->off1  (u16)
0x9a73e7c  add  x10, x8, #8
0x9a73e80  add  x11, x9, #4
0x9a73e84  csel x10, x10, x11, hi
0x9a73e8c  cmp  x26, x10
0x9a73e90  b.hs ok               ; ТРЕБУЕТСЯ size >= max(off0+8, off1+4)
0x9a73e28  cmp  x26, #4          ; и минимум 4 байта (id)
0x9a73eb0  ldr  x26,[x8]         ; value64 = *(u64*)(struct + off0)
0x9a73eb8  ldr  w8, [x8+off1]    ; value32 = *(u32*)(struct + off1)
0x9a73f3c  mov  x0, x26
0x9a73f48  bl   0x9a9a350        ; -> 0x9a9da24: value64 кладётся НА СТЕК (stp x0,x1,[sp]),
                                 ;    затем 0xa97ae84 (setProperty) с указателем на стек
```

То есть:
* id свойства берётся из первых 4 байт структуры и ищется во внутренней таблице описателя,
  который вернул `0x9a9a360(op)` (`0x9a9fd1c`: таблица `0xfffffff008027050`, stride 0x10,
  жёсткий предел `op < 0xbd` — `cmp w0,#0xbd; b.lo`);
* смещения полей (`off0`/`off1`) берутся из **статической** таблицы, а не из пользовательских данных;
* перед чтением полей стоит проверка `structureInputSize >= max(off0+8, off1+4)`;
* 8-байтное значение из структуры **не разыменовывается**: `0xa97ae84` кладёт его на стек
  (`stp x0,x1,[sp]`) и передаёт дальше как данные (`mov x1,sp`).

Для неизвестного id `0x9a9a360` вернёт 0 → `0x9a73e24 cbz w0, 0x9a73e6c` → `ret = 0xe00002c2`,
т.е. whitelist по id.

**Вывод: `vtable[0x720]` размер сверяет (по описателю), а пользовательские значения использует как
данные. Произвольного разыменования здесь нет.**

### 8.3 `fb->vtable[0x728]` = `0x9a74528` (sel `0x4f`)

```
x20 = arg6 = args->structureOutput
x21 = arg7 = (u32)args->structureOutputSize
cmp w2,#0xbc ; b.eq  0x9a745d8
mov x24,x3            ; x24 = scalarInput[1]
cmp w2,#0x87 ; b.ne  0xe00002c2
0x9a74570  mov  w2, w24                 ; w2 = (u32)scalarInput[1]
0x9a74598  mov  x0, x19                 ; this
0x9a7459c  mov  x1, x20                 ; structureOutput
0x9a745a0  mov  x3, x21                 ; structureOutputSize
0x9a745a4  braa vtable[0x890]           ; -> 0x8ea4f58
```

`vtable[0x890] = 0xfffffff008ea4f58` → `this->[0x5e90]->vtable[0x670](...)`, т.е. снова DCP-прокси,
куда `structureOutput` и его размер уходят как (ptr,len). Локальной сверки `structureOutputSize`
с чем-либо в `0x9a74528` нет — есть только выбор по `op == 0x87 || op == 0xbc`.

Вывод по `0x4e/0x4f`: клиент передаёт `structureInput/Output` и **непроверенный** размер вниз;
`+0x720` разбирает структуру по статическому описателю с проверкой `size >= desc->min` и
использует значения как данные; `+0x728` только выбирает метод по op и уводит пару (ptr,len)
в DCP. Глубина копирования в DCP-прокси (`0x8eb91e0`, `0x8ea4f58` → `[0x5e90]->vtable[0x670]`)
в этом отчёте **не подтверждена**.

---

## 9. Прочие селекторы без проверки размера (для полноты)

`0x55 (0x9aa3f10)`, `0x56 (0x9aa415c)`, `0x63 (0x9aa424c)`, `0x64 (0x9aa41ec)` — по G:
`scalarInputCount` фиксирован (0 или 1), `structureInputSize = -1`. В `0x55` есть NULL-чек
`structureInput`, в `0x56/0x63/0x64` работают со `structureOutput`. Детальный разбор — вне
скоупа этого отчёта (задача была про `0x44` и `0x4e/0x4f`).

---

## 10. Явный вывод

1. **Произвольный вызов/запись через `0x44` — не достижимы.** Опкод `0x0b` не превращает
   пользовательский u64 в `OSObject*`; `release` не вызывается; все целевые адреса вызовов берутся
   из PAC-подписанных vtables (`autda` ключ D по адресу объекта, `braa` ключ A по адресу слота).
2. **Паника (DoS) — да, но другая:** `0xfffffff009aa4358` читает `*(u64*)args->structureInput`
   без NULL-чека. При `opcode = 0x0b` и отсутствии inband-структуры — NULL-deref.
   Помечено как **не подтверждённое на устройстве**.
3. **Указатель «валидируется» не валидацией, а отсутствием использования:** значение только
   сравнивается с нулём (`0x9a755a0..0x9a755c8`), поэтому говорить о проверке типа не приходится —
   типа там нет.
4. Побочно: `this+0xfc` — счётчик «gain map enabled», инкремент/декремент парный, дренаж в
   close-пути `0x9aa17d0`; подкрутить его вверх можно, но это не даёт ни OOB, ни UAF.
5. `0x4e/0x4f` — единственное место, где непроверенный размер уходит вниз; в `+0x720` есть
   табличная проверка `size >= desc->min`, в `+0x728` — нет. Требуется отдельный разбор DCP-прокси,
   чтобы сказать, есть ли там OOB. **Не подтверждено.**

---

### Приложение: как проверялось

* дизасм — capstone 5.0.7, `CS_MODE_ARM`, VA→offset: `off = va - 0xfffffff007004000`;
* PAC-декод: `VA = 0xfffffff007004000 + (q & 0x0FFFFFFF)`;
* GOT-трамплины: `adrp x17,page; add x17,x17,#imm; ldr x16,[x17]; braa x16,x17` → слот `page+imm`;
* `adrp` immediates и цели `b/bl` — знаковые, маскированы `& 0xFFFFFFFFFFFFFFFF`;
* vtable AppleCLCD2 найдена по конструктору `0x8e9fc24` (`str pacda(0x7e71088)`), класс — по
  строке `AppleCLCD2` (`0x762d26a`) и `getMetaClass` `0x8e9ff0c` (`0xaec9b78`);
* дизасм-скан по всему `__TEXT_EXEC` (10 792 960 инструкций) — с `skipdata`, иначе capstone
  останавливается на первом байте данных.
