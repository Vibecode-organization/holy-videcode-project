# AppleJPEGDriverUserClient / IOSurfaceAcceleratorClient — разметка externalMethod (27.2 24B115)

Образ: `27.2_24B115_kernelcache` (MH_FILESET). База `0xfffffff007004000`.
PAC: `VA = 0xfffffff007004000 + (q & 0x0FFFFFFF)`. Трамплины: `adrp x17,page; add x17,x17,#imm; ldr x16,[x17]; braa x16,x17` → цель = `[page+imm]`.
Все смещения vtable ниже — от **vptr** (указателя, который конструктор пишет в `[x0]`); `VT = vptr - 0x10`.

| класс | kext | gMetaClass | sizeof | vptr | vtable |
|---|---|---|---|---|---|
| AppleJPEGDriverUserClient | com.apple.driver.AppleJPEGDriver | `0xfffffff00ae4b740` | `0x110` | `0xfffffff007e28d50` | `0xfffffff007e28d40` |
| IOSurfaceAcceleratorClient | com.apple.driver.AppleM2ScalerCSCDriver | `0xfffffff00ae6eb98` | `0x180` | `0xfffffff007e3b0d8` | `0xfffffff007e3b0c8` |

Классы найдены по строкам `__PRELINK_TEXT` (`0xfffffff00751b791`, `0xfffffff0075fceac`) → OSMetaClass-конструктор (`adrp/add x1,<имя>; ldr x2,[got]; mov w3,#size; bl`) → `gMetaClass`; vtable определена как единственная в `__DATA_CONST`, у которой слот `+0x48` (getMetaClass) возвращает этот `gMetaClass`. Это же подтверждает размеры (0x110 / 0x180) и принадлежность vtable классу.

Внимание: `IOSurfaceAcceleratorClient` живёт **не** в IOSurface.kext, а в `AppleM2ScalerCSCDriver` — рядом с ним 241 метакласс (AppleM2ScalerCSCHal*, Iosa*). Это отдельная поверхность, ранее не смотрели.

Строки `site.AppleJPEGDriverUserClient` / `site.IOSurfaceAcceleratorClient` рядом с именами классов — **не** sandbox-гейт. Это kasan type-site метаданные (`site.<type>` + цифровая строка, 5062 таких строк в образе, ср. `site.struct ipc_port_request` + `92`). Энтайтлмент-строк для обоих классов в образе нет.

---

## 1. AppleJPEGDriverUserClient

### 1.1 Точки входа

| слот | значение | что это |
|---|---|---|
| vptr+0x540 | `0xfffffff00aa62438` | **panic-заглушка**: `panic("wrong externalMethod for IOUserClient2022 @%s:%d", "IOUserClient.cpp", 0x19e4)` |
| vptr+0x560 | `0xfffffff008c8f9e4` | clientClose (переопределён) |
| vptr+0x5b0 | `0xfffffff00a9a1568` | getTargetAndMethodForIndex (базовый) |
| vptr+0x5d0 | `0xfffffff008c8fc30` | **externalMethod2022** — рабочий вход |

`0x8c8fc30`:

```
0x8c8fc34  adrp x3, 0x7e29000
0x8c8fc38  add  x3, x3, #0x3c0        ; таблица 0xfffffff007e293c0
0x8c8fc3c  mov  w4, #0xa              ; 10 селекторов
0x8c8fc40  mov  x5, x0                ; target = this
0x8c8fc44  mov  x6, #0                ; reference = NULL
0x8c8fc48  b    0x8ca9458             ; GOT-трамплин, слот 0x7e2cff0
```

Трамплин ведёт в общий валидатор `0xfffffff00a9b0888` (`(uc, sel, args, table, count, target, ref)`). Он же используется MFB — там это уже разбирали, здесь важно, что **JPEG ходит именно через него**.

Легаси-слот `vptr+0x540` — паника. Класс объявлен «2022»; `is_io_connect_method` (`0xa9ae888`) выбирает ветку по биту 1 в `uc+0x9b`:

```
0xa9ae914  tbnz w8, #1, 0xa9ae940      ; бит1 = 2022
0xa9ae918  add  x8, x16, #0x540        ; легаси externalMethod
0xa9ae940  add  x8, x16, #0x5d0        ; 2022-вход
```

Достижимость паники из песочницы **не подтверждена** (нужно доказать, что бит 0x2 в `uc+0x9b` не выставлен на этом классе; статически флаг ставится в рантайме).

### 1.2 Таблица `0xfffffff007e293c0`, stride 0x28, 10 записей

Поля (сверены по валидатору `0xa9b0888`): `+0x00 fn`, `+0x08 sIn(u32)`, `+0x0c strIn(u32)`, `+0x10 sOut(u32)`, `+0x14 strOut(u32)`, `+0x18 flags(u32)`, `+0x20 async_fn`.

| sel | fn | sIn | strIn | sOut | strOut | flags | куда уходит |
|---|---|---|---|---|---|---|---|
| 0 | `0x8c8fa88` | 0 | 0 | 0 | 0 | 0 | `0x8c83e6c` → return 0 |
| 1 | `0x8c8fa94` | 0 | 0x58 | 0 | 0x58 | 0 | `0x8c85520` |
| 2 | `0x8c8fac8` | 0 | 0 | 0 | 0 | 0 | `0x8c83e78` → return 0 |
| 3 | `0x8c8fad4` | 0 | 0x58 | 0 | 0x58 | 0 | `0x8c867c0` |
| 4 | `0x8c8fb08` | 0 | 0x1000 | 0 | 0x1000 | 0 | `0x8c86bd4` |
| 5 | `0x8c8fb3c` | 0 | 0x1000 | 0 | 0x1000 | 0 | `0x8c86024` |
| 6 | `0x8c8fb70` | 0 | 0xda0 | 0 | 0xda0 | **1** | `0x8c876d8` |
| 7 | `0x8c8fba4` | 0 | 0xda0 | 0 | 0xda0 | **1** | `0x8c87038` |
| 8 | `0x8c8fbd8` | 0 | 4 | 0 | 0 | 0 | `0x8c832d4` |
| 9 | `0x8c8fc08` | 0 | 0 | 0 | 0 | 0 | `0x8c8336c` |

TSV: `jpeg_selectors.tsv`.

### 1.3 Что проверяет валидатор (важно для вердикта)

```
0xa9b08d0  ldr  w8, [x20, #8]          ; table.sIn
0xa9b08d4  cmn  w8, #1                 ; -1 = не проверять
0xa9b08dc  ldr  w9, [x2, #0x28]        ; args->scalarInputCount
0xa9b08e0  cmp  w8, w9
0xa9b08e4  b.ne <err 0xe00002c2>
0xa9b08e8  ldr  w19, [x20, #0xc]       ; table.strIn
0xa9b08f4  ldr  x8, [x2, #0x40]        ; args->structureInputDescriptor
0xa9b08f8  cbz  x8, 0xa9b0964          ; дескриптора нет → сравнение с размером
0xa9b090c  ldr  x9, [x16, #0xb0]!      ; IOMemoryDescriptor::getLength()
...
0xa9b0964  ldr  w8, [x2, #0x38]        ; args->structureInputSize
0xa9b0968  cmp  x8, x19
0xa9b096c  b.ne <err>
```

То же для `sOut` (`args+0x50`) и `strOut` (`args+0x60`). Затем `ldr x19,[x20,#0x20]` — вызов действия. Вывод: **размеры сверяются на точное равенство**, включая ветку с memory-дескриптором (длина берётся у дескриптора). Это ключевое отличие от классов, где в таблице стоят `0`.

### 1.4 Реализации селекторов

Все они — тонкие переходники: берут `driver = this->[0xe0]` (без retain, просто указатель), при `NULL` возвращают `0xe00002bc`, и передают `structureInput`/`structureOutput` прямо в метод драйвера.

```
sel 1 (0x8c8fa94)
0x8c8fa98  mov  x4, x0
0x8c8fa9c  ldr  x0, [x0, #0xe0]        ; driver
0x8c8faa0  cbz  x0, err_0xe00002bc
0x8c8faa4  ldr  x8, [x2, #0x58]        ; args->structureOutput
0x8c8faa8  ldr  x1, [x2, #0x30]        ; args->structureInput
0x8c8faac  ldr  x3, [x4, #0xf0]
0x8c8fab0  ldr  x5, [x4, #0x100]
0x8c8fab4  mov  x2, x8
0x8c8fab8  b    0x8c85520
```

```
sel 8 (0x8c8fbd8)
0x8c8fbe0  ldr  x0, [x0, #0xe0]
0x8c8fbe8  ldrb w8, [x1, #0x108]       ; гейт: бит 0
0x8c8fbec  tbz  w8, #0, err
0x8c8fbf0  ldr  x8, [x2, #0x30]        ; structureInput (4 байта по таблице)
0x8c8fbf4  ldr  w2, [x8]               ; пользовательский u32
0x8c8fbf8  b    0x8c832d4
```

```
0x8c832d4  stur w2, [x29, #-4]         ; число на стек
0x8c832f0  ldr  x0, [x0, #0xb8]
0x8c83304  ldr  x10, [x16, #0xe8]!     ; driver->vt[+0xe8]
0x8c83320  sub  x3, x29, #4            ; &значение
0x8c83328  blraa x10, ...
```

Приёмник — лямбда `0x8c83168`, и она считает адрес через `OSBoundedPtr`:

```
0x8c83190  add  x26, x0, #0xe0
0x8c83194  add  x8, x0, #0xf0
0x8c83198  subs x8, x8, x26
0x8c8319c  b.lo <fail>
0x8c831a0  lsr  x8, x8, #0x20          ; (end-begin) должно влезать в 32 бита
0x8c831a4  cbnz x8, <fail>
0x8c831d4  lsl  w8, w23, #3
0x8c831d8  adds x22, x26, x8
0x8c831dc  cset w9, hs                 ; перенос → ошибка
```

Пользовательский u32 идёт в индекс, но с проверкой переноса и границ — по коду это защищено (совпадает со строкой `OSBoundedPtr.h`, которая лежит в этом же кеше).

### 1.5 clientClose / dtor

clientClose `0x8c8f9e4` (vptr+0x560):

```
0x8c8f9fc  ldr  x0, [x0, #0xe0]
0x8c8fa00  cbz  x0, <return 0>
0x8c8fa04  bl   0x8ca95d8             ; isInactive-подобная проверка (driver)
0x8c8fa08  tbnz w0, #0, <return 0>
0x8c8fa0c  mov  x0, x19
0x8c8fa10  bl   0x8ca95d8             ; то же для самого UC
0x8c8fa18  ldr  x0, [x19, #0xe0]
0x8c8fa2c  ... vptr+0x540 -> blraa
0x8c8fa38  mov  x1, x19
0x8c8fa44  mov  w0, #0
```

vptr+0x540 у драйвера — это `AppleJPEGDriver::clientClosedGated(AppleJPEGDriverUserClient *)` (строка символа есть в образе). Ни один член UC здесь не освобождается: только снимается регистрация на стороне драйвера.

Деструктор `0x8c8f208`: `OSObject::~OSObject` + `operator delete(this, 0x110)`. Указатель `this->[0xe0]` не release-ится (сырой). Гонки «free против in-flight» на самом UC нет: объекта не освобождают до последнего вызова (общая схема `is_io_connect_method` с `uc+0x9c` уже разобрана ранее), а члены в close/dtor не рвутся.

---

## 2. IOSurfaceAcceleratorClient

### 2.1 Точки входа

| слот | значение | что это |
|---|---|---|
| vptr+0x540 | `0xfffffff00a9a18bc` | общий `IOUserClient::externalMethod` (класс **не** переопределяет) |
| vptr+0x560 | `0xfffffff008d13c78` | clientClose (переопределён) |
| vptr+0x5b0 | `0xfffffff008d13c38` | getTargetAndMethodForIndex (переопределён) |
| vptr+0x5d0 | `0` | 2022-входа нет |

Геттер:

```
0x8d13c3c  cmp  w2, #0xb               ; 12 селекторов (0..11)
0x8d13c40  b.hi <NULL/err>
0x8d13c44  mov  w8, #0x30              ; stride 0x30
0x8d13c48  adrp x9, 0x7e3b000
0x8d13c4c  add  x9, x9, #0x738         ; таблица 0xfffffff007e3b738
0x8d13c50  umull x8, w2, w8
0x8d13c54  str  x0, [x1]               ; *target = this
0x8d13c58  cmp  x8, w8, sxtw           ; контроль переполнения
0x8d13c5c  add  x0, x9, w8, sxtw
0x8d13c60  add  x16, x9, x8
0x8d13c68  csel x0, x0, x16, eq
```

### 2.2 Таблица `0xfffffff007e3b738`, stride 0x30, 12 записей, fn по `+0x08`

| sel | fn | +0x10 | +0x18 | +0x20 | +0x28 | обработчик |
|---|---|---|---|---|---|---|
| 0 | `0x8d14ee0` | 0 | 3 | -1 | 0 | возврат `0xe00002c7` |
| 1 | `0x8d1475c` | 0 | 3 | 0x1b0 | 0 | размер==0x1b0 |
| 2 | `0x8d14ef0` | 0 | 0 | 0 | 0 | заглушка |
| 3 | `0x8d14f00` | 0 | 0 | 0 | 0 | заглушка |
| 4 | `0x8d14c7c` | 0 | 3 | 0x20 | 0 | non-NULL in/out |
| 5 | `0x8d14c1c` | 0 | 0 | 0 | 1 | гейт `0x160` |
| 6 | `0x8d14e8c` | 0 | 3 | 0xfa8 | 0 | размер==0xfa8, count<=1000 |
| 7 | `0x8d14ce0` | 0 | 3 | 8 | 0 | u64 → lookup(type 3) |
| 8 | `0x8d14f84` | 0 | 3 | 8 | 0 | размер==8, u64 handle |
| 9 | `0x8d15064` | 0 | 3 | 0x10 | 0 | два u64 handle |
| 10 | `0x8d15230` | 0 | 3 | 0x18 | 0 | idx<4, 16 байт в члены |
| 11 | `0x8d152d0` | 0 | 2 | 0 | -1 | clamp >=0x299 |

TSV: `surfacc_selectors.tsv`.

**Не подтверждено**: точное соответствие полей `+0x10/+0x18/+0x20/+0x28` (по наблюдениям `+0x20` = ожидаемый размер структуры: 0x1b0/0xfa8/8/0x10/0x18 ровно совпадают с проверками в обработчиках; `+0x18` = 2 или 3 и похоже на число скаляров, `+0x28` = размер выхода). Формат не совпадает с легаси `IOExternalMethodDispatch` (stride 0x18, 32-битные поля), поэтому какому диспетчеру он соответствует — открытый вопрос; `+0x5d0` (2022) равен нулю.

### 2.3 Обработчики

Гейт почти везде один и тот же: `ldr w8,[x0,#0x164]; cbnz w8, out` — «сессия занята/в процессе», при ненулевом значении вызов отбивается.

```
sel 1 (0x8d1475c)
0x8d14774  ldr  w8, [x0, #0x164]
0x8d14778  cbnz w8, 0x8d1480c         ; занято → отбой
0x8d14780  cmp  x2, #0x1b0            ; x2 = размер входа
0x8d14784  b.ne 0x8d147d8             ; лог + 0xe00002c2
0x8d14790  ldr  w1, [x0, #0x168]
0x8d147d4  b    0x8d14158             ; разбор 0x1b0 байт
```

```
sel 6 (0x8d14e8c)
0x8d14e90  ldr  w8, [x0, #0x164]
0x8d14e94  cbnz w8, 0x8d14ed0
0x8d14e98  cbz  x1, err
0x8d14e9c  cmp  x2, #0xfa8
0x8d14ea0  b.ne err
0x8d14ea4  ldr  w8, [x1]              ; count из входа
0x8d14ea8  cmp  w8, #0x3e8            ; <= 1000
0x8d14eac  b.ls 0x8d14ebc
0x8d14ebc  ldr  x0, [x0, #0x100]
0x8d14ecc  b    0x8d56a18
```

0xfa8 = 4008 = 8 + 1000*4 — границы сходятся, count ограничен 1000.

```
sel 10 (0x8d15230)
0x8d15248  cmp  x2, #0x18
0x8d1524c  b.ne err
0x8d15254  ldr  w8, [x1]
0x8d15258  cmp  w8, #4                ; индекс < 4
0x8d1525c  b.lo 0x8d152ac
0x8d152ac  mov  w19, #0
0x8d152b0  str  w8, [x0, #0x168]
0x8d152b4  ldur q0, [x20, #8]         ; 16 байт
0x8d152b8  str  q0, [x0, #0x170]
0x8d152bc  mov  x0, x19
```

```
sel 11 (0x8d152d0)
0x8d152f0  ldr  x20, [x2]             ; x2 — указатель на выход
0x8d152f4  cmp  x20, #0x299
0x8d152f8  b.lo 0x8d15304
0x8d152fc  mov  w20, #0x298           ; clamp
0x8d15300  str  x20, [x19]
0x8d15304  ldr  x0, [x0, #0x100]
0x8d15308  mov  w1, #8
0x8d1530c  bl   0x8d50ff0
0x8d1531c  bl   0x8e007a0            ; (obj, count)
0x8d15320  str  x20, [x19]
```

```
sel 9 (0x8d15064)
0x8d15088  cmp  x2, #0x10
0x8d15098  ldr  x0, [x1]              ; user u64 #1
0x8d150a0  mov  w1, #0x1b0
0x8d150a4  mov  w2, #3                ; тип 3
0x8d150a8  bl   0x8e00070            ; lookup
0x8d150b4  ldr  x0, [x21, #8]         ; user u64 #2
0x8d150bc  mov  w1, #0x18
0x8d150c4  bl   0x8e00070
0x8d150d8  xpacd x17
0x8d150e0  cmp  x16, x17
0x8d150e8  brk  #0xc472               ; проверка подписи vtable
```

### 2.4 clientClose / dtor

```
0x8d13c94  mov  w8, #1
0x8d13c98  strb w8, [x0, #0x138]      ; флаг «закрывается»
0x8d13c9c  ldr  x0, [x0, #0x100]
0x8d13ca0  cbz  x0, 0x8d13ce4
0x8d13cac  mov  x0, x19
0x8d13cb0  bl   0x8e003e0
0x8d13cb8  ldr  x0, [x19, #0x100]
0x8d13ccc  ... vptr+0x540 -> blraa    ; callback в объект
0x8d13ce4  add  x20, x19, #0xe0
0x8d13ce8  ldar w8, [x20]             ; атомарный счётчик
0x8d13cf0  ldar w9, [x21]             ; +0xdc
0x8d13cf4  cmp  w8, w9
0x8d13cf8  b.hs 0x8d13d0c
```

Дальше идёт дренаж/ожидание по счётчикам `+0xdc`/`+0xe0`. Освобождения членов в прочитанном фрагменте нет; полностью хвост функции не дочитан — **не подтверждено**, что члены не рвутся дальше по коду.

Деструктор `0x8d13620`: `OSObject::~OSObject` + `operator delete(this, 0x180)`, члены не release-ятся.

---

## 3. Топ-5 подозрительных мест

### 3.1 JPEG sel 6/7 — `flags=1`, 3488 байт, дескрипторная ветка

Единственные два селектора JPEG с ненулевым флагом. В валидаторе флаг `+0x18` связан с полем `args+8`, а ветка дескриптора берёт **длину у IOMemoryDescriptor**:

```
0xa9b08f4  ldr  x8, [x2, #0x40]      ; structureInputDescriptor
0xa9b08fc  ldr  x16, [x8]
0xa9b090c  ldr  x9, [x16, #0xb0]!    ; getLength()
0xa9b0924  blraa x9, x16
0xa9b0940  cmp  x8, x19              ; длина == 0xda0 ?
0xa9b0944  b.ne  err
```

Смысл: пользователь может передать не буфер, а memory descriptor на свои страницы, и драйвер будет разбирать 3488 байт из отображённой пользовательской памяти. Само по себе это не дыра (длина проверяется), но это единственный путь, где вход не копируется в `struct input` ядра, а парсится из user-страниц — гонка «поменял содержимое после проверки» архитектурно возможна, если парсер читает буфер дважды. Проверить, читает ли `0x8c876d8` вход повторно после валидации, **не подтверждено**.

### 3.2 JPEG sel 1/3 — указатель из пользовательской структуры

```
0x8c85570  ldr  w2, [x1, #0x48]
0x8c85574  ldr  x8, [x1, #0x30]      ; ВНУТРИ структуры лежит адрес
0x8c85578  cmp  x8, #0
0x8c8557c  cset w3, ne               ; проверяется только «не NULL»
0x8c85580  ldr  w8, [x1, #0x14]
0x8c85584  ldrh w9, [x1, #0x18]
0x8c85588  orr  w4, w9, w8, lsl #16
```

`structureInput` — обычная копия в ядре, но по смещению `+0x30` в ней лежит **адрес**, и он передаётся дальше (`w3` = «есть указатель»). Если этот указатель где-то используется как kernel-адрес — это пробой; если как user-адрес и потом копируется через `copyin` — норма. Что именно делает `0x8c85520` с `w3`, в разобранном фрагменте не видно — **не подтверждено**.

### 3.3 JPEG sel 8 — пользовательский u32 в индекс (защищено)

Единственное место, где число пользователя становится индексом. Защита — `OSBoundedPtr` с проверкой переноса (`adds`/`cset hs`) и границ (`subs`, `lsr #0x20`). Оценка: **закрыто**; вынес в топ, потому что это ровно тот шаблон, который в подобных драйверах обычно и течёт.

### 3.4 SURF sel 7/9 — пользовательский u64 как handle объекта

```
0x8d14d2c  ldr  x0, [x1]             ; u64 из входа
0x8d14d30  ldr  w1, [x21, #0x150]
0x8d14d34  ldr  x3, [x21, #0x130]
0x8d14d38  mov  w2, #3
0x8d14d3c  bl   0x8e00070           ; lookup по таблице объектов
0x8d14d40  cbz  x0, err_0xe00002bd
```

Число уходит в поиск объекта (тип 3), затем результат используется как `target` для `[obj->vt+0xd8]` и `0x8d5cfdc`. Границы/тип проверяет сама `0x8e00070` — её семантика не разобрана, **не подтверждено**, что нельзя достать объект чужого типа/класса. Это самый вероятный кандидат на «type confusion через handle» в этом классе.

### 3.5 SURF sel 11 — запись по пользовательскому указателю + clamp

`x2` здесь — указатель на выход, значение из него клампится к `0x298` и **пишется обратно** (`str x20,[x19]`) до и после вызова `0x8e007a0`. Клампинг корректный (`b.lo` = меньше 0x299 пропускаем), но запись в пользовательский указатель идёт дважды и без проверки, что буфер валиден на момент второй записи; в 2022-ABI это отдаётся на откуп диспетчеру. OOB не видно; **не подтверждено**, что `0x8e007a0` не использует count как индекс во внутреннем массиве (кламп сверху есть, снизу — нет, но значение беззнаковое).

---

## 4. Вердикты

**AppleJPEGDriverUserClient** — слой user client сам по себе тонкий и корректный: 10 селекторов, размеры входа/выхода сверяются общим валидатором на точное равенство (включая длину memory-дескриптора), гейты минимальные (`this+0xe0 != NULL`, `this+0x108` бит 0 для sel 8/9). Вся логика — в `AppleJPEGDriver` (`0x8c85520`, `0x8c867c0`, `0x8c86bd4`, `0x8c86024`, `0x8c876d8`, `0x8c87038`), и именно там надо искать дальше: два парсера принимают по 4096 байт, два — по 3488, и их внутренние границы не проверялись. Отдельно: легаси-слот `externalMethod` — panic-заглушка (`wrong externalMethod for IOUserClient2022`); если флаг режима на объекте окажется снят, любой вызов через старый MIG-путь валит ядро (DoS). Достижимость не доказана.

**IOSurfaceAcceleratorClient** — 12 селекторов, каждый либо точный размер (0x1b0 / 0xfa8 / 8 / 0x10 / 0x18), либо явный `NULL`-чек; пользовательские числа проходят через lookup (`0x8e00070`) с фиксированным типом, индекс в sel 10 ограничен `< 4`, в sel 11 есть clamp. Явных OOB/underflow в обработчиках не найдено. Риск смещается в `0x8e00070` (что можно достать по u64-хендлу) и в `0x8d56a18` (разбор 1000 записей). Гейт `this+0x164` означает, что параллельные вызовы во время активной сессии отбиваются — это снижает ценность гонок, но `this+0x160`-ветка в sel 7 делает ожидание внутри обработчика, что стоит проверить на блокировки.

**Общее**: ни для одного класса не подтверждено освобождение членов под in-flight вызовом — `clientClose` обоих только снимает регистрацию/ставит флаг, деструкторы членов не release-ят. То есть класс член-гонки, который искали в MFB, здесь **не подтверждён**.

## 5. Что осталось непроверенным

- Внутренние границы парсеров `AppleJPEGDriver` для структур 0x1000/0xda0 (`0x8c86bd4`, `0x8c86024`, `0x8c876d8`, `0x8c87038`).
- Семантика `+0x30`-указателя внутри структуры sel 1/3.
- Достижимость panic-заглушки (`uc+0x9b` бит 1 на этом классе).
- Семантика `0x8e00070` (lookup по пользовательскому u64, тип 3) и `0x8d56a18` (1000 записей).
- Точное соответствие полей таблицы SURF (stride 0x30) и то, какой диспетчер её использует.
- Хвост `clientClose` SURF после `0x8d13d14`.
