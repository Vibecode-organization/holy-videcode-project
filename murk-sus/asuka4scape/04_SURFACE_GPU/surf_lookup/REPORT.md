# IOSurfaceAcceleratorClient — аудит 12 селекторов (27.2 / 24B115)

Target: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`
Класс: `IOSurfaceAcceleratorClient` (kext `AppleM2ScalerCSCDriver`), метакласс `0xfffffff00ae6eb98`,
sizeof `0x180`, instance-vtable `0xfffffff007e3b0d8`, мета-vtable `0xfffffff007e3b6c0`,
таблица методов `0xfffffff007e3b738`, 12 записей stride `0x30`.
Метод: статический RE, Capstone ARM64. Рантайма не было — всё недоказанное помечено **не подтверждено**.

---

## 0. Итог (главное)

1. **`0x8e00070` — не lookup.** Это GOT-трамплин (`adrp+add+ldr+braa`, GOT `0x7e60f08`) на
   `0xfffffff00a97ae84`, а тот — **конструктор `IOGeneralMemoryDescriptor`**:
   `withAddressRange(addr = user-u64, len, dir, task)`. Ключ-идентификатор превратился в
   **виртуальный адрес**, «таблицы» нет вообще.
2. **`0x8d56a18` — гейт селектора 6** на стороне провайдера (`AppleM2ScalerCSCDriver`),
   принимает `x0 = [uc+0x100]` (провайдер) и `x1 = structureInput` (0xfa8). Разобран в §3.
3. Из 12 селекторов **ни один** не превращает user-u64 в индекс/длину/указатель без проверки.
   Все «живые» — конфиг/буферы, проходящие через `IOCommandGate` или mdesc-конструктор.
4. Два реальных наблюдения (не подтверждены рантаймом): `sel11` копирует до `0x298` байт из
   `[[provider+0x150+slot*8]+0xb8]` без проверки длины источника; в `0x8d56a50` индекс
   `clz(rbit(bitmap))` при `bitmap==0` даёт 64 → чтение `[provider+0x350]` как указателя.
5. `[this+0x130]` — **task, без retain** (teardown просто зануляет `+0x130`). Пока он ненулевой,
   user-u64 трактуется как VA *этой* задачи (`kIOMemoryTypeVirtual64`); при нуле — как physical.
6. **Гейт `[+0x164]` («must called from user space!») отсутствует у sel 9, 10, 11** — ровно у тех,
   где sel9 строит два mdesc из двух user-u64. Для kernel-клиента (фабрика `0x8d13a70`) это дало бы
   physical-трактовку адресов; из песочницы такой клиент не открывается (см. §5.1).

---

## 1. Объект и диспетчер

`IOSurfaceAcceleratorClient::alloc` (`0x8d136dc`) — единственное место, где ставится vtable:

```
fffffff008d136dc: bti      c
fffffff008d136e0: pacibsp
fffffff008d136f0: adrp     x0, #0xfffffff007e5c000
fffffff008d136f4: add      x0, x0, #0x368          ; зона/тип
fffffff008d136f8: mov      w1, #0x180              ; sizeof = 0x180
fffffff008d136fc: bl       #0xfffffff008dffe80    ; kalloc
fffffff008d13700: mov      x19, x0
fffffff008d13704: adrp     x20, #0xfffffff00ae6e000
fffffff008d13708: add      x20, x20, #0xb98        ; &gMetaClass = 0xae6eb98
fffffff008d1370c: mov      x1, x20
fffffff008d13710: bl       #0xfffffff008dfff70    ; OSObject ctor
fffffff008d13714: adrp     x16, #0xfffffff007e3b000
fffffff008d13718: add      x16, x16, #0xc8
fffffff008d1371c: add      x16, x16, #0x10        ; = 0x7e3b0d8  ← vptr
fffffff008d13720: mov      x17, x0
fffffff008d13724: movk     x17, #0xcda1, lsl #48
fffffff008d13728: pacda    x16, x17
fffffff008d1372c: str      x16, [x0]
fffffff008d13730: stp      wzr, wzr, [x0, #0xdc]
```

Мета-vtable `0x7e3b6c0` лежит ровно на `vtable+0x5e8`; её `+0x68` (= `alloc`) прошит в
`0xfffffff007e3b728` → `0x8d136dc`. Таблица методов начинается сразу за мета-vtable:
`0x7e3b6c0 + 0x78 = 0x7e3b738`.

### 1.1 `getTargetAndMethodForIndex` (vtable+0x5b0 = `0x8d13c38`)

```
fffffff008d13c3c: cmp      w2, #0xb                     ; selector <= 11
fffffff008d13c40: b.hi     #0xfffffff008d13c70          ; -> NULL
fffffff008d13c44: mov      w8, #0x30
fffffff008d13c48: adrp     x9, #0xfffffff007e3b000
fffffff008d13c4c: add      x9, x9, #0x738               ; table = 0x7e3b738
fffffff008d13c50: umull    x8, w2, w8                   ; idx*0x30 (64-bit)
fffffff008d13c54: str      x0, [x1]                     ; *target = this
fffffff008d13c58: cmp      x8, w8, sxtw                 ; overflow check
fffffff008d13c5c: add      x0, x9, w8, sxtw
fffffff008d13c60: add      x16, x9, x8
fffffff008d13c64: movk     x16, #0x2bad, lsl #48
fffffff008d13c68: csel     x0, x0, x16, eq              ; PAC-битый указатель при overflow
fffffff008d13c6c: ret
```

Границы: индекс проверен (`<=0xb`), произведение проверено. Утечки индекса нет.

### 1.2 Формат записи (то, что реально читает ядро)

Ядро берёт запись, читает `+0x18` как **shape** (0..4) и разводит по хелперам
(`0xa9a33a4` shape 0, `0x9a3840` shape 2, `0xa9a3c2c` shape 3, `0xa9a1d04` shape 4).
Проверка размера — `0xa9a3c48`:

```
fffffff00a9a3c2c: pacibsp
fffffff00a9a3c44: mov      x21, x0
fffffff00a9a3c48: ldr      x8, [x0, #0x20]        ; entry.checkStructureInputSize
fffffff00a9a3c4c: mov      w9, #-1                ; 0xffffffff = «любой»
fffffff00a9a3c50: cmp      x8, x9
fffffff00a9a3c54: mov      w19, w3                ; w3 = фактический размер
fffffff00a9a3c58: ccmp     x8, x19, #4, ne
fffffff00a9a3c5c: b.ne     #0xfffffff00a9a3cb4    ; kIOReturnBadArgument
fffffff00a9a3c60: ldr      x10, [x21, #0x28]      ; entry.checkStructureOutputSize
fffffff00a9a3c68: cmp      x10, x9
fffffff00a9a3c6c: b.ne     #0xfffffff00a9a3c78
fffffff00a9a3c70: ldp      x17, x9, [x21, #8]     ; x17 = fn, x9 = discriminator
fffffff00a9a3c8c: asr      x10, x9, #1
fffffff00a9a3c90: add      x0, x1, x10            ; target += discr>>1
fffffff00a9a3c94: eor      x16, x1, x0
fffffff00a9a3c98: tst      x16, #-0x40000000000000
fffffff00a9a3ca0: movk     x0, #0xc8a2, lsl #48   ; резолв PAC при смене тега
```

Итог по записи:

| offset | поле | у наших 12 |
|---|---|---|
| `+0x00` | object (заполняется диспетчером, в таблице 0) | 0 |
| `+0x08` | fn (PAC) | 12 адресов |
| `+0x10` | discriminator (`>>1` прибавляется к target, бит0 = ключ PAC) | 0 |
| `+0x18` | shape (0..4) | 0,2,3 |
| `+0x1c` | 0 | 0 |
| `+0x20` | `checkStructureInputSize` (`0xffffffff` = любой) | 0 / 0x20 / 0x1b0 / 0x8 / 0x10 / 0x18 / 0xfa8 / `0xffffffff` |
| `+0x28` | `checkStructureOutputSize` (`0xffffffff` = любой) | 0 / 1 / `0xffffffff` |

Отсюда: размер structureInput проверяет **ядро** (до вызова) и повторно сам селектор.
`+0x10 = 0` ⇒ discriminator не используется, PAC-ключ постоянный.

---

## 2. `0x8e00070` — разбор

### 2.1 Это трамплин, а не функция

```
fffffff008e00070: adrp     x17, #0xfffffff007e60000
fffffff008e00074: add      x17, x17, #0xf08        ; GOT = 0x7e60f08
fffffff008e00078: ldr      x16, [x17]
fffffff008e0007c: braa     x16, x17
```
`[0x7e60f08] = 0x8011000003976e84` → `pac` → **`0xfffffff00a97ae84`**.

### 2.2 `0xa97ae84` — конструктор IOMemoryDescriptor

```
fffffff00a97ae84: pacibsp
fffffff00a97ae88: sub      sp, sp, #0x30
fffffff00a97ae98: mov      x19, x3               ; x3 = task/owner
fffffff00a97ae9c: mov      x20, x2               ; x2 = direction/options
fffffff00a97aea0: stp      x0, x1, [sp]          ; {addr, len}
fffffff00a97aea4: adrp     x0, #0xfffffff00ad97000
fffffff00a97aea8: add      x0, x0, #0x200         ; &IOGeneralMemoryDescriptor::gMetaClass
fffffff00a97aeac: ldr      x16, [x0]
fffffff00a97aeb8: autda    x16, x17
fffffff00a97aebc: ldr      x8, [x16, #0x68]!      ; meta-vtable+0x68 = alloc
fffffff00a97aec4: blraa    x8, x16                ; -> новый IOGeneralMemoryDescriptor
fffffff00a97aec8: cbz      x0, #0xfffffff00a97af44 ; NULL -> вернуть NULL
fffffff00a97aecc: cmp      x19, #0
fffffff00a97aed0: mov      w8, #0x10
fffffff00a97aed4: mov      w9, #0x20
fffffff00a97aed8: csel     w8, w9, w8, eq         ; task==0 ? 0x20 : 0x10
fffffff00a97aedc: ldr      x16, [x0]
fffffff00a97aee8: autda    x16, x17
fffffff00a97aeec: ldr      x9, [x16, #0x78]!      ; vtable+0x78 = initWithOptions
fffffff00a97aef0: mov      x1, sp                 ; &{addr,len}
fffffff00a97aef4: orr      w5, w8, w20            ; type | direction
fffffff00a97aefc: mov      w2, #1
fffffff00a97af00: mov      w3, #0
fffffff00a97af04: mov      x4, x19                ; task
fffffff00a97af08: mov      x6, #0
fffffff00a97af10: blraa    x9, x16
fffffff00a97af14: tbz      w0, #0, #0xfffffff00a97af20 ; bit0==0 -> провал
fffffff00a97af18: mov      x0, x20                     ; bit0==1 -> успех, вернуть объект
fffffff00a97af1c: b        #0xfffffff00a97af44
fffffff00a97af20: mov      x0, x20
fffffff00a97af2c: ldr      x16, [x20]
fffffff00a97af34: ldr      x8, [x16, #0x28]!            ; vtable+0x28 = release
fffffff00a97af3c: blraa    x8, x16
fffffff00a97af40: mov      x0, #0                      ; -> NULL
```

Семантика: `x0 = addr (u64)`, `w1 = len`, `w2 = direction`, `x3 = task`.
`csel` : `task == 0 → type 0x20`, `task != 0 → type 0x10`.

Тип разбирает `IOGeneralMemoryDescriptor::initWithOptions` (`vtable+0x78` = `0xa977cc8`),
`w26 = w5 & 0xf0`, `w25 = (w26-0x10)>>4`:

```
fffffff00a977cf8: and      w26, w5, #0xf0
fffffff00a977d04: ldr      x8, [x22]              ; ветка 0x40: дескриптор-источник
fffffff00a977d5c: sub      w8, w26, #0x10
fffffff00a977d60: lsr      w25, w8, #4
fffffff00a977d64: cmp      w25, #3
fffffff00a977d6c: sub      w8, w25, #1
fffffff00a977d74: b.lo     #0xfffffff00a977d94 ; 0x20/0x30 — общий путь
fffffff00a977d90: cbz      x4, #0xfffffff00a978384 ; 0x10: task обязателен, иначе ошибка
fffffff00a977e20: cbnz     x4, #0xfffffff00a978388 ; 0x60: task обязан быть NULL
```

Т.е. `0x10` требует **непустой task** (трансляция VA в адресном пространстве задачи) —
это `kIOMemoryTypeVirtual64`; `0x20` task не требует — physical. Проверка стоит **внутри
инициализатора дескриптора**, а не в клиенте.

### 2.3 Что реально передают вызывающие

| место | addr | len | dir (w2) | task (x3) |
|---|---|---|---|---|
| sel7 `0x8d14d2c` | `scalarInput[0]` | `[this+0x150]` = 12·`[provider+0x15c]` | 3 | `[this+0x130]` |
| sel8 `0x8d14fd0` | `structIn[0]` | `(N+0x40 \| 0x200)*0x7c + 0x20` (N из конфига) | 1 | `[this+0x130]` |
| sel9 `0x8d15098` | `structIn[0]` | 0x1b0 | 3 | `[this+0x130]` |
| sel9 `0x8d150b4` | `structIn[1]` | 0x18 | 3 | `[this+0x130]` |
| `0x8d13e34` | x1 (аргумент) | `x2*4` (`ubfiz`, 32-бит) | 2 | `[this+0x130]` |

`[this+0x150]` — из `init` (`0x8d138b0`): `w8=[obj+0x15c]`, `[+0x148]=w8`, `[+0x14c]=3w8`,
`[+0x150]=12w8`, `[+0x158]=alloc(12w8)`; `obj` = `0x8d5104c(provider, 8)` → `[provider+0x150+slot*8]`.
Значит длина — **производная от конфига провайдера**, не от пользователя.
`sel8` длина считается из глобала `[0xae6f218]` (`smull w8, 0x7c`, 32-бит, без переполнения
при разумном N).

`[this+0x130]` — task, ставится **только** в `0x8d13ffc` (`withProvider`):
`str x23,[x19,#0x130]` (`0x8d14068`), зануляется в teardown (`0x8d1396c`). **Retain'а нет.**

Вердикт: user-u64 → **виртуальный адрес в task'е клиента** (type `0x10`), длина фиксирована
конфигом. Путь «physical» (`type 0x20`) требует `task == 0`, т.е. `+0x130 == 0` **при**
`+0x164 == 0` — такой комбинации в бинаре не наблюдается: единственная запись `+0x130`
идёт из `withProvider`, который одновременно ставит `+0x164 = 0` и передаёт `x1`.
Если `x1 == 0`, physical-путь открыт — **не подтверждено** (вызывающего `0x8d13ffc` в
бинаре нет: ни `bl`, ни PAC-указателя; см. §6).

---

## 3. `0x8d56a18` — разбор

Вызывается только из **sel6** хвостом (`0x8d14ecc: b 0x8d56a18`) с
`x0 = [uc+0x100]` (провайдер `AppleM2ScalerCSCDriver`) и `x1 = structureInput` (0xfa8).

```
fffffff008d56a18: bti      c
fffffff008d56a1c: mov      x8, x0                     ; provider
fffffff008d56a20: mov      w0, #0x2c2
fffffff008d56a24: movk     w0, #0xe000, lsl #16       ; kIOReturnBadArgument
fffffff008d56a28: ldr      x9, [x8, #0x288]
fffffff008d56a2c: ldr      w9, [x9, #0x18]
fffffff008d56a30: cbz      w9, #0xfffffff008d56a40     ; подсистема не готова
fffffff008d56a34: ldrb     w9, [x1, #0xfa4]           ; user-байт ВНУТРИ 0xfa8-структуры
fffffff008d56a38: tbnz     w9, #0, #0xfffffff008d56a48 ; бит0 -> работаем
fffffff008d56a3c: ret                               ; 0xe00002c2
fffffff008d56a40: orr      w0, w0, #0x20              ; 0xe00002e2
fffffff008d56a44: ret
fffffff008d56a48: mov      x0, x8
fffffff008d56a4c: b        #0xfffffff008d56a50
```

Хвост (`0x8d56a50`), 4 итерации:

```
fffffff008d56a80: add      x22, x0, #0x150            ; массив указателей
fffffff008d56a84: mov      w23, #4
fffffff008d56a88: adrp     x24, #0xfffffff007e4a000
fffffff008d56a8c: add      x24, x24, #0xf60           ; таблица из 4 fn
fffffff008d56a90: ldr      x8, [x24, x21, lsl #3]     ; fn[k]
fffffff008d56a94: ldr      x9, [x20, #0x1c0]          ; битовая карта скалеров
fffffff008d56a98: rbit     x9, x9
fffffff008d56a9c: clz      x9, x9                     ; clz(rbit(0)) = 64
fffffff008d56aa0: ldr      x9, [x22, x9, lsl #3]      ; [provider+0x150+idx*8]
fffffff008d56aa4: ldr      x0, [x9, #0xb8]
fffffff008d56aa8: add      x2, sp, #0xc
fffffff008d56aac: mov      x1, x19                    ; structureInput 0xfa8
fffffff008d56ab0: mov      x17, #0x1810               ; PAC-ключ (ручной)
fffffff008d56ab4: blraa    x8, x17
fffffff008d56ab8: ldr      w0, [sp, #0xc]
```

Таблица `0x7e4af60` → `0x8d09188 / 0x8d09990 / 0x8d09b70 / 0x8d09d74` (по одному вызову на
каждый из 4 «слоёв», один и тот же объект).

Проверки: `[provider+0x288]->+0x18 != 0` (готовность), `user[0xfa4] & 1`, ненулевой указатель
слота. **Индекс не проверяется снизу/сверху**: `bitmap == 0` → `clz = 64` → чтение
`[provider+0x150+0x200] = [provider+0x350]` как указателя, затем `[[..]+0xb8]` → вызов.
Заполнение `+0x1c0` в бинаре не найдено (провайдер инициализирует его сам).
**Не подтверждено**: может ли `[provider+0x1c0]` быть 0 к моменту вызова (маловероятно —
это карта активных скалеров, но проверки нет).

---

## 4. Таблица: все 12 селекторов

Легенда: «user-value» — что из пользовательского ввода реально уходит дальше;
«x1/x2» — structureInput и его размер (сверяются ядром с `entry+0x20`).

| sel | fn | user-value | куда идёт | проверка | вердикт |
|---|---|---|---|---|---|
| 0 | `0x8d14ee0` | — | `return 0xe00002c7` | — | заглушка `kIOReturnUnsupported` |
| 1 | `0x8d1475c` | `structIn[0..0x1b0]`, `structIn[1]` (флаг/размер) | `+0xdc` atomic++, токен `0x8e00760/0x8e006b0`→`[+0xf8]`; `structIn[1]!=0` → `0x8d142e8` (commandGate `[+0x140]`, либо `0x8dfff50([+0x120], in+8, in+0x10, [+0x130])`); иначе `0x8d141d0` → `runAction(0x8d144c0)` → `0x8d56c60(provider, in, &st, this)` | `[+0x164]==0` (иначе panic «must called from user space»), `x2==0x1b0` | адресов/индексов из user нет; конфиг уходит в провайдер под commandGate. **OK** |
| 2 | `0x8d14ef0` | — | `0xe00002c7` | — | заглушка |
| 3 | `0x8d14f00` | — | `0xe00002c7` | — | заглушка |
| 4 | `0x8d14c7c` | `structIn[0..0x20]` | `0x8d14888(this, in, out)`: `0x8d5104c(provider,8)`→`[obj+0xc0]`, серия виртуальных вызовов порта/текстуры | `[+0x164]==0`, `x1!=0`, `x2!=0` (размер — ядром) | конфиг, без user-указателей. **OK** |
| 5 | `0x8d14c1c` | — | `provider->vt[0x548]()` → `*x1 = w0`, `return 0` | `[+0x164]==0` | пишет u32 по указателю диспетчера; проверки `x1!=0` нет. **не подтверждено** (может ли быть NULL при structIn=0) |
| 6 | `0x8d14e8c` | `structIn[0..0xfa8]` | `0x8d56a18(provider, in)` → 4 вызова `fn([[provider+0x150+idx*8]+0xb8], in, &st)` | `[+0x164]==0`, `x1!=0`, `x2==0xfa8`, `in[0] <= 0x3e8`, `user[0xfa4]&1`, готовность `[p+0x288]->+0x18` | OOB-индекс `clz(rbit(bitmap))` при `bitmap==0` → 64 (§3). **лид, не подтверждено** |
| 7 | `0x8d14ce0` | `scalarIn[0]` = адрес | `withAddressRange(addr, [uc+0x150], 3, [+0x130])` → `prepare(0)` → `0x8d5cfdc(provider, uc, md)` → `complete` → `release` | `[+0x164]==0`, `[+0x160] bit0 == 0` (иначе `0xe00002c1`), `addr != 0`, инициализатор требует `task != 0` для type 0x10 | VA в задаче клиента, длина фиксирована. **OK** (при `+0x130 != 0`) |
| 8 | `0x8d14f84` | `structIn[0]` = адрес (8 Б) | `withAddressRange(addr, (N+0x40\|0x200)*0x7c+0x20, 1, [+0x130])` → `0x8d5d094(provider, md)` → `release` | `[+0x164]==0`, `x1!=0`, `x2==8` | длина из конфига, direction=1. **OK** |
| 9 | `0x8d15064` | `structIn[0]`, `structIn[1]` = два адреса | 2× mdesc (0x1b0 / 0x18, dir 3) → `prepare` → `xpacd`-проверка vptr первого → `0x8d5d5cc(provider, A, B, uc)` → `complete` + `release` | `x2==0x10`; **гейта `[+0x164]` нет** (см. §5.1) | два VA задачи (при `+0x130!=0`). **OK для user client'а**, но ассерт отсутствует |
| 10 | `0x8d15230` | `structIn[0]` (u32), `structIn[8..0x18]` (16 Б) | `[this+0x168]=u32` (требует `<4`), `[this+0x170..0x180]=16 Б` | `x2==0x18`, `w8 < 4` (иначе `0xe00002c2`); **гейта нет** | состояние клиента; читает `[+0x168]` только лог в sel1, 16 Б — в `+0x170`. **OK** |
| 11 | `0x8d152d0` | `[x2]` = длина (in/out) | `n = min(*x2, 0x298)`; `src = 0x8d50ff0(provider, 8)` = `[[provider+0x150+slot*8]+0xb8]`; `memcpy(x1, src, n)`; `*x2 = n` | `n <= 0x298` (клэмп), длина **источника** не проверяется | дамп состояния провайдера; при буфере < 0x298 — over-read. **не подтверждено** |

`0x8d50ff0` (`slot`): `w1 >= 8` → `idx = clz(rbit([p+0x1c0]))`; иначе если бит `w1` установлен —
`idx = w1`, иначе тот же `clz`. Затем `ldr x8,[p+0x150+idx*8]; ldr x0,[x8+0xb8]`.

---

## 5. Гейты, `free`, `stop`

`init` (`0x8d13820`) — единственный писатель гейтов:

```
fffffff008d1383c: str      w2, [x0, #0x164]      ; 0 = user client, 1 = kModuleClient
fffffff008d13844: strb     wzr, [x0, #0x138]
fffffff008d1384c: mov      w8, #2
fffffff008d13850: str      w8, [x0, #0x168]       ; дефолт для sel10
fffffff008d13854: ldr      q0, [x8, #0xd00]
fffffff008d13858: str      q0, [x0, #0x170]       ; 16 Б дефолта
fffffff008d1385c: str      x1, [x0, #0x100]       ; provider (retain vt+0x20)
```

* `[+0x164]` — тип клиента. Все 12 селекторов начинают с `ldr w8,[x0,#0x164]; cbnz w8, <assert>`.
  Ассерт — `0x8de6604`: `w8 = 0x2e4` → `0x8d15408` → строки
  `"[%s] must called from user space!\n" @IOSurfaceAcceleratorClient.cpp`, `%s = "kModuleClient"`,
  далее `0x8e007b0` → `0xaa4d114` (panic/backtrace). Т.е. селекторы на kernel-клиенте = паника,
  и это **не** путь из песочницы (kernel-клиент не является user client'ом).
* `[+0x160]` — читается только в sel7 (`ldrb w8,[x0,#0x160]; tbz w8,#0`). **Писателей в
  бинаре нет** (скан 0x8d13000–0x8e00000 по `strb/str` с disp 0x160: только чужие классы,
  0x8d3ef24 / 0x8d3f29c / 0x8d40590 / 0x8d40afc / 0x8d5597c). Проверка фактически мёртвая —
  **не подтверждено**, что её ставит подкласс/другой kext.

### 5.1 Гейт `[+0x164]` стоит не на всех селекторах

Проверено по первым инструкциям каждой из 12 функций:

| есть `ldr w?,[x0,#0x164]` | селекторы |
|---|---|
| да | 1, 4, 5, 6, 7, 8 |
| **нет** | **0, 2, 3** (заглушки) и **9, 10, 11** |

`9`, `10`, `11` — ровно те, что работают с адресами/состоянием: sel9 строит **два**
`IOMemoryDescriptor` из `structIn[0]`/`structIn[1]`, sel11 отдаёт дамп провайдера.
Для `kModuleClient` (`+0x164 == 1`, `+0x130 == 0`) это означает: sel9 выполняет
`withAddressRange(user_u64, 0x1b0, 3, NULL)` → тип `0x20` → **user-u64 трактуется как
физический адрес**, без единой проверки и без ассерта. Комбинация `+0x164==1 && +0x130==0`
— это ровно то, что создаёт фабрика `0x8d13a70` (init с `w2=1`, `+0x130` не ставится).
Из песочницы такой клиент недостижим (это не user client), но инвариант «адрес всегда VA
задачи» держится на том, что kernel-клиент никто не нагружает пользовательскими данными.
**Не подтверждено**: есть ли у kernel-клиента вход из user-space через другую поверхность
(провайдер/AGX).

`stop` (vtable+0x560 = `0x8d13c78`):
```
fffffff008d13c90: mov      x19, x0
fffffff008d13c94: mov      w8, #1
fffffff008d13c98: strb     w8, [x0, #0x138]      ; «остановлен»
fffffff008d13c9c: ldr      x0, [x0, #0x100]      ; provider
fffffff008d13ca0: cbz      x0, #0xfffffff008d13ce4
fffffff008d13ca4: bl       #0xfffffff008e003e0
fffffff008d13cb8: ldr      x0, [x19, #0x100]
fffffff008d13ccc: mov      x17, #0x540
fffffff008d13cd0: add      x16, x16, x17
fffffff008d13cd4: ldr      x8, [x16]
fffffff008d13cd8: mov      x1, x19
fffffff008d13ce0: blraa    x8, x16            ; provider->vt[0x540](this)
fffffff008d13ce4: add      x20, x19, #0xe0
fffffff008d13ce8: ldar     w8, [x20]          ; [+0xe0] vs [+0xdc]
fffffff008d13cf4: cmp      w8, w9
fffffff008d13d0c: ldr      x8, [x19, #0x140]
fffffff008d13d28: bl       #0xfffffff008dca080 ; закрыть commandGate
fffffff008d13d3c: mov      x17, #0x2f0
fffffff008d13d54: blraa    x8, x16            ; this->vt[0x2f0](0)
```
`stop` не освобождает provider — только помечает `+0x138`, снимает регистрацию и закрывает
`[+0x140]`. Освобождает `free`.

`free` (vtable+0x70 = `0x8d13a1c`): `bl 0x8d1392c` (teardown) + `bl` через глобал `[0x7e613b0]->vt[0x80]`.

`teardown` (`0x8d1392c`):
```
fffffff008d13944: ldr x0,[x19,#0x120]; bl 0x8dfff60; [+0x120]=0
fffffff008d13954: ldr x0,[x19,#0x108]; bl 0x8dffd60; [+0x108]=0
fffffff008d13964: ldr x8,[x19,#0x130]; cbz; str xzr,[x19,#0x130]   ; ← без release!
fffffff008d13970: ldr x0,[x19,#0x118]; vt[0x28]; [+0x118]=0
fffffff008d13998: ldr x0,[x19,#0x140]; vt[0x28]; [+0x140]=0
fffffff008d139c0: ldr x0,[x19,#0x100]; vt[0x28]; [+0x100]=0        ; release provider
fffffff008d139e8: ldr x0,[x19,#0x158]; bl 0x8dffd20               ; free буфера 12N
```
`[+0x130]` (task) **не retain'ится и не release'ится** — слабая ссылка. Для user client'а
задача живёт дольше клиента, но инвариант держится на этом, а не на коде.

---

## 6. Что осталось недоказанным

1. **Кто вызывает `0x8d13ffc` (`withProvider`).** В бинаре нет ни `bl`, ни PAC-указателя
   на `0x8d13ffc` / `0x8d13a70` (скан всех `__DATA_CONST`/`__DATA` по low-28 и полному
   low32). Значит либо вызов идёт из другого kext через kmod-символ, либо ветка мёртвая.
   От этого зависит `x1` → `[+0x130]` → тип mdesc.
2. **`x1 == 0` в `withProvider`** ⇒ `type 0x20` (physical) при `+0x164 == 0` ⇒
   user-u64 становится **физическим адресом**. Комбинация в бинаре не наблюдается, но и
   не запрещена кодом. Это единственный путь к серьёзному impact'у; нужен рантайм-тест.
3. **sel11**: длина источника `[[provider+0x150+slot*8]+0xb8]` не проверяется, клэмп
   только на `0x298`; размер назначения задаёт диспетчер (`entry+0x28 = 0xffffffff` — без
   ограничения).
4. **sel6 / `0x8d56a50`**: `bitmap == 0` → `clz = 64` → OOB-чтение указателя.
5. `[+0x160]` bit0 — писателей нет.
6. У sel 9/10/11 нет гейта `[+0x164]`; для user client'а это безвредно (task != 0), но инвариант
   «адрес всегда VA» держится на том, что kernel-клиент не получает пользовательских данных —
   проверки этого в коде нет.
7. Точная семантика shape-хелперов ядра (`0xa9a33a4`, `0xa9a3840`, `0xa9a3c2c`, `0xa9a1d04`)
   для пар (ptr,size) на разных shape — восстановлена по дизассемблеру частично; для
   shape 2 (`sel11`) соответствие «x1 = выходной буфер, x2 = слот размера» **не подтверждено**.

### Рантайм-проверки, которые закроют вопросы

* Открыть сервис из `container`-приложения, вызвать sel7 с `scalarIn[0] = 0` и с заведомо
  невалидным VA → оба должны дать `0xe00002bd`/`0xe00002c2`, паники быть не должно.
* Вызвать sel11 с `*x2 = 0x298` и посмотреть, не приходит ли в буфер PAC-указатель
  (если да — утечка KASLR-энтропии).
* Проверить, создаётся ли клиент вообще: если `newUserClient` для
  `AppleM2ScalerCSCDriver` из песочницы возвращает `kIOReturnUnsupported`, весь класс
  недостижим и пункты 2–4 — теоретические.
