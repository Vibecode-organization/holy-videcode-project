# IOSurfaceSendRight + IOGPUDeviceUserClient free/stop/clientClose — iOS 27.2 (24B115)

**Target:** `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (67 239 936 B, Mach-O fileset, 250 kext-слайсов).
**Метод:** статический разбор, Capstone 5.0.7. Адреса — короткая форма: полный VA = `0xfffffff000000000 | addr`
(`0x9c4755c` → `0xfffffff009c4755c`). `__TEXT_EXEC` = `va - 0xfffffff007004000`;
`__DATA_CONST` = `0xbb4000 + (va - 0xfffffff007bb8000)`; PAC-резолв `BASE + (q & 0x0FFFFFFF)`, `BASE = 0xfffffff007004000`.
Скрипты: `kc2.py` (маппинг/дизасм/стабы/GOT), `cg.py`, `bscan.py` (глобальный скан `bl/b`), `allcalls.pkl`.

Всё, что не доказано инструкцией/ссылкой, помечено **не подтверждено**.

---

## 0. Вердикты

| # | Вопрос | Ответ |
|---|---|---|
| 1.1 | `IOSurfaceSendRight` — user client с `externalMethod`? | **Нет.** OSObject-обёртка (`sizeof 0x28`), экземпляр = kobject Mach-порта типа `0x26`; таблицы `IOExternalMethodDispatch` у класса нет |
| 1.2 | Как выдаётся send right на поверхность | `IOSurfaceRoot::makeSendRight 0x9c33ad8` → `IOSurfaceSendRight::create 0x9c47474` → `ipc_kobject`-copyout `0xa9a7b30` → `0xa34c248` (`MACH_MSG_TYPE_MOVE_SEND`). **В 27.2 недостижимо: у `0x9c33ad8`/`0x9c47474` 0 статических ссылок** |
| 1.3 | Проверяется ли владелец при импорте | Только для private-поверхностей: флаг `surface+0x3d2 bit3` (свойство `IOSurfaceIsPrivate`), тогда `surface+0x170 == uc+0xf8`. Для остальных — **нет проверки**, достаточно держать порт |
| 1.4 | Можно ли получить право на чужую поверхность по id | **По id — нет.** Только по имени Mach-порта, уже лежащему в IPC-space вызывающего (`task+0x310`); id берётся из самой поверхности |
| 1.5 | `ipc_port_release_send` / двойное освобождение | В путях send right не зовётся ни разу; ref на kobject снимается ровно один раз (`0x9c3b980`, vt`+0x28`). Double-free не найден |
| 2.1 | `IOGPUDeviceUserClient::free` | `0x9946f44` (vtable `+0x70`) — рвёт `[0x120]`,`[0x110]`,`[0x108]`, пару `[0xd8]`, `[0xf0]`; супер-`free` |
| 2.2 | `stop` | `0x9949ff0` (vtable `+0x5d8`) — drain провайдера `0x9965338`, release `[0x110]/[0x108]`, **clears `uc+0x100`** |
| 2.3 | `clientClose` | `0x994a164` (vtable `+0x560`) — provider vt`+0xa0`, затем self vt`+0x2f0(this,0)` |
| 2.4 | Берётся ли ref на время вызова / синхронизация с `externalMethod` | В самом классе — **нет** (ни `ldadd`, ни лока, ни isInactive). Защита — в IOKit: trap-retain `0xa34bbcc` (vt`+0x20`) / release `0xa34eef4`; `ldadd +1` в `uc+0x9c` под локом `uc+0xb0` (`0xa9ae888`, `0xa9ad368`); `free` — только из release при rc=0 |
| 2.5 | Что освобождает деструктор | Только саму память: `kfree_type(type=0x7feffe8, size=0x130)` (`0x9946c1c`). Члены не трогает |

---

## 1. IOSurfaceSendRight

### 1.1 Класс, метакласс, vtable

Метакласс-конструкторы (init-функция `0x9c47cb0`, вызывается из `__mod_init_func`):

```
9c47cb0  adrp x19,#0xaf48000 ; add x19,#0x4d0        ; gMetaClass IOSurfaceSendRight
9c47cb8  adrp x1,#0x789d000  ; add x1,#0x9b9         ; "IOSurfaceSendRight"
9c47cc4  ldr  x2,[0x806ca00]                          ; meta суперкласса (0xad98798)
9c47cc8  mov  w3,#0x28                                ; sizeof
9c47ccc  bl   0x9c497a4                               ; OSMetaClass::OSMetaClass
9c47cd0  ...
9c47cfc  str  x16,[x19]                               ; vtable метакласса 0x806a910
9c47d00  adrp x0,#0xaf48000 ; add x0,#0x4f8           ; gMetaClass IOSurfaceWiredSendRight
9c47d08  adrp x1,#0x789d000 ; add x1,#0x9ea           ; "IOSurfaceWiredSendRight"
9c47d10  mov  x2,x19                                  ; super = IOSurfaceSendRight
9c47d14  mov  w3,#0x28
9c47d18  bl   0x9c497a4
```

| | адрес | значение |
|---|---|---|
| meta `IOSurfaceSendRight` | `0xaf484d0` | в файле нули (`__DATA.__common`, заполняется при загрузке) |
| meta `IOSurfaceWiredSendRight` | `0xaf484f8` | подкласс, тот же размер |
| vtable `IOSurfaceSendRight` | `0x806a870` | `+0x00` dtor `0x9c47174`, `+0x08` deleting dtor `0x9c47268`, `+0x20` retain, `+0x28` release, `+0x38` getMetaClass `0x9c472cc`, `+0x70` `0x9c47644`, `+0x78` `0x9c4752c`, `+0x80` `0x9c4755c`, `+0xa0` `0x9c470f0` |
| vtable `IOSurfaceWiredSendRight` | `0x806a9a8` | `+0x70` `0x9c47bf0`, `+0x80` `0x9c47b38` (wired-init) |
| kalloc_type | `0x806b970` | тип для `kfree_type(...,0x28)` в `0x9c47268` |

`externalMethod` и `IOExternalMethodDispatch`-таблицы у класса **нет**: в vtable только OSObject-слоты, `getMetaClass`, `init`/`initWithSurface` и wired-вариант. Это не `IOUserClient`, а объект-«содержимое» Mach-порта.

### 1.2 Раскладка и время жизни

`init` (`0x9c4755c`, слот vt`+0x80`; args `x1=id, x2=IOSurface*, x3=flags`):

```
9c47588  ldr  x8,[0x806ca30]        ; meta
9c47590  ldr  x9,[x8,#0x78]         ; метакласс-метод
9c4759c  blraa x9,x17
9c475a4  str  x23,[x20,#0x10]       ; +0x10 = id (w)
9c475a8  tbnz w22,#1,0x9c475c0      ; flags bit1 -> не wired
9c475ac  mov  x0,x21
9c475b0  bl   0x9c22340             ; IOSurface::isWired? (bit)
9c475b4  tbnz w0,#1,0x9c475c0
9c475b8  mov  w8,#1
9c475bc  strb w8,[x20,#0x20]        ; +0x20 = wired
9c475c0  ldr  x22,[x20,#0x18]       ; old surface
9c475c4  str  x21,[x20,#0x18]       ; +0x18 = IOSurface*
9c475d8  ldr  x8,[x21] ; ... ldr x8,[x16,#0x20]!
9c475e8  blraa x8                   ; retain(surface)  (+0x20)
9c475f0  ... ldr x8,[x22] ; ldr x8,[x16,#0x28]! ; blraa  ; release(old)
9c47610  bl   0x9c233d8             ; wire/pin
9c47618  ldrb w8,[x20,#0x20]
9c47620  ldr  x0,[x20,#0x18] ; mov w1,#0 ; bl 0x9c22ee0   ; conditional unpin
```

Деструктор `0x9c47174` (vt`+0x00`) снимает **ровно одну** ссылку с `+0x18`:

```
9c471a0  str  x16,[x0]              ; vtable
9c471a4  ldr  x0,[x0,#0x18]
9c471a8  cbz  x0,0x9c471c8
9c471b8  ldr  x8,[x16,#0x28]!       ; release
9c471c4  blraa x8,x16
9c471c8  str  xzr,[x19,#0x18]
9c471e8  b    0x9c49aa4            ; ~OSObject
```

`deleting dtor` `0x9c47268`: `bl 0x9c471ec` (dtor wired-варианта) → `kfree_type(0x806b970, this, 0x28)` (`0x9c496d4`).
Фабрика `IOSurfaceSendRight::create` `0x9c47474`:

```
9c47498  adrp x0,#0xaf48000 ; add x0,#0x4d0   ; meta
9c474a0  ldr  x16,[x0]
9c474b0  ldr  x8,[x16,#0x68]!                 ; OSMetaClass::alloc
9c474b8  blraa x8
9c474c4  ldr  x16,[x19]
9c474d4  ldr  x8,[x16,#0x80]!                 ; init(id,surface,flags)
9c474ec  blraa x8
```

Итог: обёртка `{+0x10 id, +0x18 IOSurface* (retained), +0x20 wired, +0x21 lock/held}`; поверхность живёт, пока живёт обёртка, — окно «surface без retain» в sel34 (подозрение #3 из `uaf_surf`) **снимается**: обёртка держит `+1` на `+0x18`.

### 1.3 Выдача send right на поверхность — мертва в 27.2

`IOSurfaceRoot`-хелпер `0x9c33ad8` (args `x0=id, x1=task/space, x2=surface, x3=flags, x4=&name`):

```
9c33afc  tbnz w3,#0,0x9c33b08       ; flags bit0 -> wired
9c33b00  bl   0x9c47474             ; IOSurfaceSendRight::create
9c33b04  b    0x9c33b0c
9c33b08  bl   0x9c47a80             ; IOSurfaceWiredSendRight::create
9c33b14  mov  x0,x20                ; space
9c33b18  mov  x1,x21                ; wrapper (kobject)
9c33b1c  mov  x2,x19                ; &name
9c33b20  bl   0x9c49834             ; GOT -> 0xa9a7b30
9c33b38  ldr  x8,[x16,#0x28]! ; blraa ; release wrapper
```

`0xa9a7b30` — kernel-хелпер «создать порт с kobject»:

```
a9a7b30  pacibsp ...
a9a7b44  mov  w2,#0x26              ; kobject type
a9a7b48  bl   0xa34c248             ; (space, kobject, type) -> name
a9a7b4c  str  w0,[x19]              ; out: mach_port_name
```

`0xa34c248`: `ipc_kobject`-порт, затем `0xa1ee0f0(space, port, 0x11 /*MOVE_SEND*/, ...)` → имя send right в пространстве задачи.

**Достижимость:** ни `0x9c33ad8`, ни `0x9c33ac8`, ни `0x9c47474`, ни `0x9c4746c` не имеют **ни одного**
`bl/b` во всех exec-сегментах (`bscan` по 809 883 ветвям) и **ни одного** 8/4-байтного указателя/литерала
в файле. Проверены и «двух-add» adrp-цепочки, и литеральные пулы. Код мёртв.
Сам port-copyout `0xa9a7b30` живой (GOT-слот `0x806c680`, стаб `0x9c49834`), но вызывается только из
`sel36` (shared event, `0x9c3db88`) и из мёртвого `0x9c33b20`; поэтому выдача send right **на поверхность**
недостижима, а на shared event — достижима.
Проверка на 27.0 не делалась (**не подтверждено**, регрессия это или нет).

### 1.4 Живой импорт: `IOSurfaceRootUserClient` sel34

Таблица `IOSurfaceRootUserClient` — `0x8068b90`, **60 записей**, stride `0x28` (`IOExternalMethodDispatch2022`:
fn`+0x00`, sIn`+0x08`, strIn`+0x0c`, sOut`+0x10`, strOut`+0x14`); restricted-вариант `0x80694f0`
(записи 4–8 → отказ `0x9c3a1dc`). Вход — `externalMethod 0x9c3ee10` (`mov w4,#0x3c`), таблица выбирается по
`uc+0x127` bit0.

sel34: запись 34 (`fn 0x9c397d8`, `sIn=1`, `strOut=0xc68`):

```
9c397d8  ldr  x8,[x2,#0x20]     ; args->scalarInput
9c397dc  ldr  w1,[x8]           ; name = scalarInput[0]
9c397e0  ldr  x2,[x2,#0x58]     ; structureOutput
9c397e4  b    0x9c3b7b0
```

`0x9c3b7b0` (ключевые инструкции):

```
9c3b7f0  ldr  x16,[x24,#0xf8]!        ; task = uc->task
9c3b81c  mov  x0,x16
9c3b828  mov  x8,#-0x5555555555555556
9c3b82c  str  x8,[sp,#0x10]           ; sentinel в out
9c3b830  add  x2,sp,#8
9c3b834  bl   0xa9a7bc0               ; (task, name, &kobject)
9c3b838  cbz  w0,0x9c3b848            ; 0 = ok
...
9c3b850  ldr  x0,[sp,#8]
9c3b85c  bl   0xa894f30               ; safeMetaCast(x0, meta 0xaf484d0)
9c3b864  cbz  x0,0x9c3b8a8            ; не IOSurfaceSendRight -> +5 (0xe00002c2)
9c3b868  ldr  x23,[x0,#0x18]          ; surface = wrapper+0x18
9c3b86c  ldr  x0,[x20,#0xd8] ; bl 0x9c495b4   ; lock [uc+0xd8]
9c3b874  ldr  w1,[x23,#0x10]          ; surface->id
9c3b878  add  x2,sp,#0x10
9c3b87c  mov  x0,x20
9c3b880  bl   0x9c3f044               ; lookup в [uc+0x108] (raw, без ref)
9c3b884  cbz  w0,0x9c3b8b4            ; не найден -> импорт
9c3b888  ...                           ; найден: out = {id, ...}, rc=0
...
9c3b8b4  ldrb w8,[x23,#0x3d2]         ; флаги поверхности
9c3b8b8  tbz  w8,#3,0x9c3b928         ; bit3 == 0 -> БЕЗ проверки владельца
9c3b8bc  ldr  x16,[x23,#0x170]        ; owner task (PAC, key 0xf19c)
9c3b8cc  autda x16,x17
9c3b914  cmp  x8,x16
9c3b918  b.eq 0x9c3b928               ; owner == uc->task(u+0xf8) -> можно
9c3b91c  mov  x22,#0 ; add w19,w19,#5 ; b 0x9c3b970   ; 0xe00002c2
9c3b928  ldr  x0,[x20,#0x118]         ; IOSurfaceRoot*
9c3b92c  mov  x1,x23 ; mov w2,#0
9c3b934  bl   0x9c2b810               ; создать IOSurfaceClient (retain surface +0x20)
9c3b940  ldr  w2,[x23,#0x10]
9c3b94c  bl   0x9c3f2b0               ; set_surface_handle(uc, entry, id)
9c3b960  mov  x0,x22 ; mov x1,x21
9c3b968  bl   0x9c2c18c               ; заполнить structOut (0xc68)
9c3b970  ldr  x0,[x20,#0xd8] ; bl 0x9c495d4   ; unlock
9c3b978  ldr  x0,[sp,#8]
9c3b97c  cbz  x0,0x9c3b99c
9c3b980  ldr  x16,[x0] ; ... ldr x8,[x16,#0x28]! ; blraa x8,x16   ; release kobject ровно 1 раз
```

Флаг `+0x3d2 bit3` — это свойство **`IOSurfaceIsPrivate`** (init поверхности `0x9c1e0f8`–`0x9c1e124`:
`bl 0x9c1fec4` с ключом `0x789bd3e` = `"IOSurfaceIsPrivate"`, затем `bfi w8,w9,#0x13,#1`).
Т.е. private-поверхность нельзя импортировать чужой задаче даже с портом; non-private — можно.

`0xa9a7bc0` → `0xa34be34`: `ipc_entry_lookup(space=task+0x310, name)`, проверка типа kobject `0x26`,
`retain` kobject (vt`+0x20`), возврат **+1**. Пространство — **задачи вызывающего** (`uc+0xf8`), не отправителя.

### 1.5 Право на «чужую» поверхность и повторная выдача

* По **id** — нельзя: id ищется только в таблице своего user client (`[uc+0x108]`), а импорт требует порт.
* По **имени порта** — можно, если имя уже есть в IPC-space задачи (т.е. право реально передано). Имена
  per-task, угадать чужое имя нельзя: его надо получить.
* Ветка «surface уже в таблице» возвращает успех без повторного `set_surface_handle`; повторный sel34 с тем же
  именем безопасен: каждый вызов берёт +1 на kobject и снимает его в `0x9c3b980`; имя не потребляется.
* `ipc_port_release_send` в `IOSurface.kext` на этих путях **не вызывается ни разу** (скан всех `bl` —
  4 177 ветвей). Освобождение Mach-права делает только смерть имени/задачи.
* Двойного release нет: единственный release kobject — `0x9c3b980`, под `cbz`; ошибки идут туда же.

### 1.6 Второй живой путь (для полноты): sel36 — это SharedEvent, не поверхность

sel36 (`0x9c39868`, `sIn=1,sOut=2`) → `0x9c3dad4`: по id из `[uc+0xe8]` (IOSurfaceRoot) создаётся/ищется
`IOSurfaceSharedEvent` (`0x9c16a78`, meta `0xaf48198`), обёртка `IOSurfaceSharedEventReference`
(meta `0xaf48170`, `sizeof 0x18`) и `0xa9a7b30(task, ref, &name)` — тот же port-copyout, тип `0x26`.
Возвращает `{u32 name, u64}`.
Т.е. в 27.2 живая выдача send right есть только для **shared event**, а не для поверхности.

---

## 2. IOGPUDeviceUserClient: free / stop / clientClose

### 2.1 Класс

* meta `0xaf22218` (`__DATA.__common`, нули в файле), `sizeof 0x130`, имя `"IOGPUDeviceUserClient"`
  (`0x782b0d0`), конструктор метакласса `0x994a43c` (init-функция `0x994a42c` из `__mod_init_func[5]`).
* live-vtable `0x7fe9b88`; ставится конструкторами `0x9946d00`, `0x9946d70`, `0x9946dcc`:

```
9946cec  adrp x0,#0x7fef000 ; add x0,#0xfe8     ; kalloc_type (sizeof 0x130)
9946cf8  bl   0x998444c
9946d00  adrp x20,#0xaf22000 ; add x20,#0x218   ; gMetaClass
9946d0c  bl   0x998458c                          ; OSObject::OSObject(meta)
9946d10  adrp x16,#0x7fe9000 ; add #0xb78 ; add #0x10   ; 0x7fe9b88
9946d24  pacda x16,x17
9946d28  str  x16,[x0]
```

Слоты live-vtable `0x7fe9b88` (проверены по коду и по общим вызовам IOKit):

| слот | адрес | роль |
|---|---|---|
| `+0x00` | `0x9946c14` | dtor → `0x998459c` |
| `+0x08` | `0x9946c1c` | deleting dtor: dtor + `kfree_type(0x7feffe8,0x130)` |
| `+0x20` | `0xa897d58` | retain (общий) |
| `+0x28` | `0xa897d28` | release (общий) |
| `+0x38` | `0x9946c7c` | getMetaClass → `0xaf22218` |
| `+0x70` | **`0x9946f44`** | **free** |
| `+0x540` | **`0x994a1dc`** | **externalMethod (classic)** |
| `+0x560` | **`0x994a164`** | **clientClose** |
| `+0x5d0` | `0x9949db8` | start (возвращает bool; `init` пишет его в `uc+0x100`) |
| `+0x5d8` | **`0x9949ff0`** | **stop** |

`uc+0x100` ставится в `initWithTask` (`0x9946e14`):

```
9946f18  ldr  x16,[x19] ; add x16,#0x5d0
9946f20  ldr  x8,[x16]
9946f2c  movk x16,#0x31cf
9946f30  blraa x8
9946f34  strb w0,[x19,#0x100]        ; started = start()
```

### 2.2 externalMethod `0x994a1dc` (vtable `+0x540`)

```
994a1dc  bti c
994a1e0  mov  w8,#0x2c2 ; movk w8,#0xe000
994a1e8  ldrb w9,[x0,#0x100]
994a1ec  tbz  w9,#0,0x994a26c        ; !started -> +0x16 => 0xe00002d8
994a1f0  cmp  w1,#0x37
994a1f4  b.hi 0x994a278              ; sel > 55 -> общий stub (0xe00002c2)
994a1f8  ldr  x9,[x2,#0x10]          ; args->asyncReference
994a1fc  cbnz x9,0x994a270           ; !=0 -> 0xe00002c2
994a200  ldrb w8,[x0,#0x103]         ; entitlement gpu-restricted
994a204  mov  w9,#0x18               ; stride 0x18 (classic IOExternalMethodDispatch)
994a208  umull x9,w1,w9
994a20c  adrp x10,#0x7fea000 ; add x10,#0x740   ; restricted (24 записи)
994a228  adrp x10,#0x7fea000 ; add x10,#0x200   ; полная (56 записей)
994a244  tst  w8,#1
994a248  csel x3,x11,x12,ne          ; dispatch = table[selector]
994a24c  adrp x8,#0x7ff2000 ; ldr x8,[x8,#0x7d0]
994a254  add  x6,x8,#0x550
994a258  ldr  x16,[x8,#0x550]        ; IOUserClient::externalMethod (0xa9a18bc)
994a25c  mov  x4,x0
994a268  braa x16,x17
```

**Ref/лок в самом методе отсутствует** (нет `ldadd`, нет `lck_mtx_*`, нет повторной проверки `uc+0x100`).
`uc+0x100` — единственный гейт; `0xe00002d8` при незапущенном клиенте (подтверждает вводную).

### 2.3 free `0x9946f44` (vtable `+0x70`)

```
9946f44  bti c ; pacibsp ...
9946f5c  ldr  x0,[x0,#0x120]           ; provider
9946f60  cbz  x0,0x9946f80
9946f78  ldr  x8,[x16,#0x28]! ; blraa  ; release(provider)
9946f80  str  xzr,[x19,#0x120]
9946f84  ldr  x0,[x19,#0x110]
9946f88  cbz  x0,0x9946fa8
9946f9c  ldr  x8,[x16,#0x28]! ; blraa  ; release
9946fac  ldr  x0,[x19,#0x108]
9946fc4  ldr  x8,[x16,#0x28]! ; blraa  ; release
9946fd4  ldr  x1,[x19,#0xd8]           ; пара {ptr0, ptr8}
9947004  str  xzr,[x1,#8]
9947008  ldr  x0,[x1] ; bl 0x9984e9c  ; IOFree(ptr0)
9947014  ldr  x1,[x19,#0xd8] ; str xzr,[x1] ; str xzr,[x19,#0xd8]
9947020  adrp x0,#0x7ff0000 ; add #0x68 ; bl 0x998424c
994702c  ldr  x0,[x19,#0xf0] ; bl 0x998427c ; str xzr,[x19,#0xf0]
9947044  ldr  x16,[x1,#0x80]! ; braa     ; super::free
```

Замечания (все — факты по дизасму):
* ни лока, ни проверки `isInactive`, ни refcount, ни `ldadd` — «голый» teardown;
* каждое поле обнуляется сразу после release (`0x9946f80` — `[0x120]`, `0x9946fa8` — `[0x110]`,
  `0x9946fd0` — `[0x108]`, `0x994701c` — `[0xd8]`, `0x9947038` — `[0xf0]`), поэтому повторный `free()`
  по членам идемпотентен; опасен только повторный `super::free` — достижимость двойного вызова
  **не подтверждена**;
* `uc+0x100` не очищается (это делает `stop`).

### 2.4 stop `0x9949ff0` (vtable `+0x5d8`)

```
9949ff0  bti c ; pacibsp ...
994a008  ldr  x16,[x0] ; add x16,#0x100
994a01c  ldr  x8,[x16]
994a024  adrp x1,#0x782b000 ; add #0x1b8   ; "AppUsage"
994a030  blraa x8,x16                       ; remove property
994a034  ldr  x0,[x19,#0x120]               ; provider
994a038  cbz  x0,0x994a040
994a03c  bl   0x9965338                     ; IOGPUDevice::<drain user client>(provider)
994a040  ldr  x0,[x19,#0x110] ; ... release (vt+0x28)
994a064  str  xzr,[x19,#0x110]
994a068  ldr  x0,[x19,#0x108] ; ... release (vt+0x28)
994a08c  str  xzr,[x19,#0x108]
994a090  strb wzr,[x19,#0x100]              ; started = 0
```

`0x9965338` — метод провайдера: под `[provider+0x110]` берёт лок `0x994463c`, обходит namespace
(`0x9945214` lookup / `0x994508c` remove) — вычищает клиента из устройства. Ref на провайдера здесь
**не снимается** (это делает `free`), поэтому double-release между stop и free нет.

### 2.5 clientClose `0x994a164` (vtable `+0x560`)

```
994a164  bti c ; pacibsp ...
994a17c  ldr  x0,[x0,#0x120]             ; provider
994a180  cbz  x0,0x994a1a0
994a194  ldr  x8,[x16,#0xa0]!            ; provider vt+0xa0 (без аргументов)
994a19c  blraa x8,x16
994a1a0  ldr  x16,[x19] ; add x16,#0x2f0 ; self vt+0x2f0
994a1b8  ldr  x8,[x16]
994a1c0  mov  w1,#0
994a1c8  blraa x8,x16                    ; terminate/close(0)
994a1cc  mov  w0,#0
```

Ни лока, ни refcount, `uc+0x100` **не** очищает; члены `[0x108]/[0x110]` не рвёт (это stop).

### 2.6 Деструктор

```
9946c14  bti c ; b 0x998459c                    ; ~OSObject
9946c1c  bti c ; pacibsp
9946c34  bl 0x998459c                            ; ~OSObject
9946c38  adrp x0,#0x7fef000 ; add #0xfe8         ; kalloc_type descriptor
9946c40  mov  x1,x19 ; mov w2,#0x130
9946c60  b  0x998443c                            ; kfree_type(type,ptr,0x130)
```

Освобождается **только блок 0x130**: ни `[0x120]`, ни `[0x110]/[0x108]/[0xd8]/[0xf0]` деструктор не трогает.
Если объект уничтожается без `free()` (например, ошибка инициализации до `free`), члены утекают — это
наблюдение, не UAF.

### 2.7 Синхронизация с in-flight `externalMethod`

Класс сам не синхронизируется. Слои IOKit (проверено в этом образе):

1. **Trap-retain.** `_Xio_connect_method` → `0xa34bbcc` (`lookup_connect_ref`): lookup порта, проверка
   kobject-типа `0x27`, `retain` kobject (`0xa34bc34`: vt`+0x20`), возвращает +1; release — `0xa34eef4`
   (vt`+0x28`) после воркера. Пока вызов в полёте, объект не может уйти в `free` по rc=0.
2. **Счётчик вызовов.** Обёртка `0xa9ae888` (режимы `uc+0x9b` 2/3): лок `uc+0xb0`
   (`0xa228180`/`0xa227a00`), затем `ldadd w20=1 → [uc+0x9c]`, диспетчеризация; выход `0xa9a5808`
   при old==1 и `vt+0x298` планирует finalize. Close `0xa9ad368`: CAS `uc+0x99`, лок `uc+0xb0`,
   `ldadd +1` в `uc+0x9c`, затем `clientClose` через `vt+0x560`.
3. **free** — только из release при rc=0 (+0x70 vtable), прямых `bl/b` на `0x9946f44` нет.

Вывод: «free под работающим externalMethod» заблокирован слоем IOKit, а не классом. Классовый дефект —
отсутствие собственного ref/lock — сам по себе **не** даёт UAF; member-гонка **не подтверждена**.
Единственное, что стоит отметить: `free` не чистит `uc+0x100`; `clientClose` тоже
не чистит флаг. Штатный порядок `clientClose → stop → free` (stop гасит флаг) это закрывает.

### 2.8 Расхождение с вводной

Фраза «как у IOSurface через `ldadd` в `uc+0x9c`»: в 27.2 `uc+0x9c` — это **общий** счётчик in-flight
вызовов `IOUserClient`, его крутят kernel-обёртки `0xa9ae888`/`0xa9ad368`, а не код `IOSurface.kext`.
В самом `IOSurfaceRootUserClient` (init `0x9c3a2d4`, free `0x9c3a678`) `ldadd` по `+0x9c` нет вовсе
(скан всех `ldadd` в kext: 10 сайтов, ни один не `+0x9c`). То же и у IOGPU: в `externalMethod`/`free`/`stop`/
`clientClose` `ldadd` нет.

---

## 3. «Не подтверждено»

1. Достижимость выдачи surface-send-right в других сборках (27.0/27.1): в 27.2 `0x9c33ad8`/`0x9c47474`
   не имеют ни одной статической ссылки; `0xa9a7b30` живёт только за счёт shared-event пути. Возможно,
   surface-путь удалён или создаётся иначе — **не подтверждено**.
2. Повторный вызов `free`/`super::free` — механизма повторного вызова не найдено, поля обнуляются.
3. Реальная member-гонка `externalMethod` vs `stop/free` — слой IOKit (trap-ref + `uc+0x9c`) её закрывает
   статически; динамикой не проверялось.
4. Точная семантика `IOSurface+0x170` (owner task?) — сравнение с `uc+0xf8` и PAC-ключ `0xf19c` доказаны,
   имя поля — нет.
5. Тип kobject `0x26` (send-right) и `0x27` (connect) — числовые константы проверены, символические имена
   (`IKOT_*`) не подтверждены по заголовкам.
6. `0x9949db8` (start) и `0x9949ff0` (stop) привязаны к слотам `+0x5d0/+0x5d8` по вызову из `initWithTask`
   и по очистке `uc+0x100`; точное имя слота в ABI `IOUserClient2022` — не подтверждено.
7. `[uc+0x120]` — объект, который start получает через `task vt+0x588` (`0x9949e54`–`0x9949e88`);
   назван «провайдером» условно, его класс не подтверждён.

---

## 4. Артефакты

`/home/femboychik/work/x_sendright/`:
`kc2.py` (сегменты/VA, kext-слайсы, `scan_adrp_to`, `stub_target`, `stubs_of`), `cg.py` (call/xref граф
IOSurface/IOGPU), `bscan.py` (глобальный `bl/b` скан), `allcalls.pkl`, `IOSurface_cg.pkl`, `IOGPUFamily_cg.pkl`.
