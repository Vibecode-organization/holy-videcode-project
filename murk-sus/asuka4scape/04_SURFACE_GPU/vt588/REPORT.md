# IOGPU vt+0x588 — общий кэш или пер-клиентский объект

Kernelcache 27.2 (24B115), база `0xfffffff007004000`.
Все адреса — VA, файловое смещение = `va - 0xfffffff007004000` (образ линеен, проверено по всем LC_SEGMENT_64).

## Вердикт

**Пер-клиентский. Кэша нет.** Слот `+0x588` (`0x9974304`) на каждом вызове
аллоцирует новый объект через метакласс (`kalloc` + ctor) и инициализирует его
парой `(task, securityID)` вызывающего. Ни глобальной переменной, ни
`OSDictionary`, ни сравнения `task`/`securityID` между вызовами в этом пути нет.
Вердикт предыдущего прохода (AE, `work/xclient/REPORT.md`) не переворачивается —
он теперь доказан на уровне слота, а не выведен из полей `+0x48/+0x50`.

Единственная nuance: у конкретного провайдера (AGX-акселератор) возвращается не
голый `IOGPUDevice`, а его подкласс `AGXShared` (0x218 Б, `+0xd8` = securityID).
Объект всё равно новый на каждое открытие user client'а.

## Цепочка адресов

```
0x9949e54  deviceUserClientStart: provider->vt[0x588](provider, task, secid)
   provider  = [uc+0xf8]  (OSDynamicCast(IOGPU, getProvider()), 0x9946f00)
   task      = [[uc+0xd8]]
   secid     = [uc+0x128]
   результат -> [uc+0x120]

0x9974304  реализация слота +0x588  (4 vtable-слота, см. ниже)
0x9973d18  IOGPU::vt[0x630]  -> [0x7fed260] = 0xaf225d8 (метакласс IOGPUDevice)
0x9964ad0  IOGPUDevice::alloc  (kalloc 0x120 + ctor 0x994d73c + vptr 0x7fed280)
0x9964c08  IOGPUDevice::vt[0x88] -> thunk на 0x9964c34 (init: +0x48=IOGPU*, +0x50=task)
0x816ecbc  AGXAccelerator::vt[0x630] -> [0xae23c90] = метакласс AGXShared
0x8200c0c  AGXShared::alloc  (kalloc 0x218 + ctor 0x8215a20 + vptr 0x7c9edc0)
0x8200704  AGXShared::vt[0x88] = init(shared, accel, task, secid)
```

Слот `+0x588` = `0x9974304` ровно в четырёх vtable'ах этого ядра:

| vtable (stored vptr) | класс | ctor |
|---|---|---|
| `0x7fee6c0` | `IOGPU` (база, size 0x2f0) | `0x997137c` |
| `0x7c99740` | `AGXAcceleratorG14P_A0` (size 0x1ad08) | `0x81dd0ec` |
| `0x7c9a5b0` | AGX-вариант B | `0x81df33c` |
| `0x7c9b420` | AGX-вариант C | `0x81d9240` |

Т.е. ответ не зависит от того, кто именно подставлен в `provider`: база `IOGPU`
и все AGX-наследники делят одну реализацию. (В базовой vtable `+0x550` =
`__cxa_pure_virtual` `0xaa61974`, поэтому живой провайдер — AGX-подкласс;
`OSDynamicCast(IOGPU)` в `0x9946f00` проходит, метакласс `0xaf22790`, имя
`"IOGPU"` @ `0x782ec42`, size `0x2f0`.)

## Дизасм: место вызова (0x9949e54..0x9949e88)

```
fffffff009949e54: ldr      x0, [x19, #0xf8]        ; provider
fffffff009949e58: ldr      x8, [x19, #0xd8]
fffffff009949e5c: ldr      x1, [x8]                ; task
fffffff009949e60: ldr      x2, [x19, #0x128]       ; securityID
fffffff009949e64: ldr      x16, [x0]
fffffff009949e68: mov      x17, x0
fffffff009949e6c: movk     x17, #0xcda1, lsl #48
fffffff009949e70: autda    x16, x17
fffffff009949e74: mov      x17, #0x588
fffffff009949e78: add      x16, x16, x17
fffffff009949e7c: ldr      x8, [x16]
fffffff009949e80: movk     x16, #0xc856, lsl #48
fffffff009949e84: blraa    x8, x16
fffffff009949e88: str      x0, [x19, #0x120]
```

## Дизасм: реализация слота (0x9974304, 30 инструкций)

```
fffffff009974304: bti      c
fffffff009974308: pacibsp
fffffff00997430c: stp      x22, x21, [sp, #-0x30]!
fffffff009974310: stp      x20, x19, [sp, #0x10]
fffffff009974314: stp      x29, x30, [sp, #0x20]
fffffff009974318: add      x29, sp, #0x20
fffffff00997431c: mov      x20, x2            ; secid
fffffff009974320: mov      x21, x1            ; task
fffffff009974324: mov      x22, x0            ; provider
fffffff009974328: ldr      x16, [x0]
fffffff00997432c: mov      x17, x0
fffffff009974330: movk     x17, #0xcda1, lsl #48
fffffff009974334: autda    x16, x17
fffffff009974338: mov      x17, #0x630
fffffff00997433c: add      x16, x16, x17
fffffff009974340: ldr      x8, [x16]
fffffff009974344: movk     x16, #0xb80e, lsl #48
fffffff009974348: blraa    x8, x16       ; x19 = provider->vt[0x630]()  == НОВЫЙ объект
fffffff00997434c: mov      x19, x0
fffffff009974350: cbz      x0, #0xfffffff009974384
fffffff009974354: ldr      x16, [x19]
fffffff009974358: mov      x17, x19
fffffff00997435c: movk     x17, #0xcda1, lsl #48
fffffff009974360: autda    x16, x17
fffffff009974364: ldr      x8, [x16, #0x88]!
fffffff009974368: mov      x0, x19
fffffff00997436c: mov      x1, x22       ; accel
fffffff009974370: mov      x2, x21       ; task
fffffff009974374: mov      x3, x20       ; secid
fffffff009974378: movk     x16, #0xa21, lsl #48
fffffff00997437c: blraa    x8, x16       ; obj->vt[0x88](obj, accel, task, secid)
fffffff009974380: cbz      w0, #0xfffffff009974390     ; init fail -> release
fffffff009974384: mov      x0, x19
fffffff009974388: bl       #0xfffffff009964f18       ; регистрация/учёт в accel
fffffff00997438c: b        #0xfffffff0099743b4
fffffff009974390: ...      vt[0x28] (release) -> x19 = 0
```

Ни одного `cmp` по `task`/`secid`, ни одной загрузки из глобала-словаря.
Единственная «память» функции — `x19` в стековом кадре.

## Откуда берётся объект (vt[0x630])

**База IOGPU** — `0x9973d18`:

```
adrp x8, 0x7fed000 ; add x8,x8,#0x260 ; ldr x0,[x8]   ; [0x7fed260] = 0xaf225d8
ldr  x16,[x0]                                          ; vptr метакласса IOGPUDevice
ldr  x8,[x16,#0x68]! ; braa
```
`0xaf225d8` — тот самый метакласс, что передаётся в ctor внутри
`IOGPUDevice::alloc 0x9964ad0` (`adrp 0xaf22000 + #0x5d8`). Слот `+0x68`
метакласс-vtable = `alloc` (у метакласса IOGPUDevice `0x7fed380`:
`PTR[0x7fed3e8] = 0x9964ad0`). `IOGPUDevice::alloc`:

```
mov w1, #0x120 ; bl kalloc_type -> x19
x1 = 0xaf225d8 ; bl 0x994d73c (ctor)
pacda vptr 0x7fed280 ; str x16,[x0]
bl 0x9984adc (instanceCreated)
ret x19
```
Никакого поиска по task перед `kalloc` нет.

**AGX-акселератор** — `0x816ecbc`:

```
adrp x0, 0xae23000 ; add x0,x0,#0xc90 ; ldr x16,[x0]    ; метакласс AGXShared
ldr  x8,[x16,#0x68]! ; braa                              ; = alloc 0x8200c0c
```

`AGXShared::alloc 0x8200c0c`: `kalloc_type(0x7ca2608, 0x218)` -> ctor `0x8215a20` ->
vptr `0x7c9edc0` -> `instanceCreated`. Класс зарегистрирован в `0x8200d50`
(`"AGXShared"` @ `0x71229a3`, size `0x218`).

## Что делает init и куда девается securityID

`AGXShared::vt[0x88] = 0x8200704` (20+ инструкций):

```
mov  x22, x3              ; secid
mov  x20, x2              ; task
mov  x21, x1              ; accelerator
mov  x19, x0              ; новый объект
str  xzr, [x0, #0xd8]
bl   kalloc_type x3       ; +0x198, +0x1b0, +0x168
...
str  x22, [x19, #0xd8]    ; <-- securityID кладётся В ОБЪЕКТ
ldr  x8, [0x7ca60d0]      ; vtable базового класса (level-2 указатель)
ldr  x9, [x8, #0x90]!     ; базовый init
x0=x19; x1=x21; x2=x20    ; (shared, accel, task)
blraa x9
cbz  w0, fail
ldr  x9, [x19, #0x48]     ; = IOGPU* после базового init
ldr  w8, [x9, #0x618] ... ; конфиг акселератора
```

То есть `securityID` — это **поле объекта** (`+0xd8`), а не ключ поиска.
Для чистой базы `IOGPUDevice::vt[0x88]` — thunk `0x9964c08`, который
переадресует на `0x9964c34` (`IOGPUDevice::init`: `str x1,[x19,#0x48]` —
общий `IOGPU*`, `str x2,[x19,#0x50]` — task клиента; `x3` там затирается
адресом слота, т.е. secid в базовом варианте не сохраняется).

## Отрицательные доказательства (что кэша нет)

1. В `0x9974304` нет ни одной ссылки на глобал: тело — только `self->vt[0x630]`,
   `obj->vt[0x88]`, `obj->vt[0x28]` и вызов `0x9964f18`.
2. `vt[0x630]` в обеих ветках — это `metaclass[+0x68]`, а `+0x68` у метаклассов
   `IOGPUDevice` (`0x7fed380`) и `AGXShared` (`0x7c9eec8`) — это `alloc`
   (`0x9964ad0` / `0x8200c0c`), т.е. `kalloc` + конструктор.
3. Ни в `0x9974304`, ни в `0x9973d18`/`0x816ecbc`, ни в обоих `alloc` нет
   загрузки `OSDictionary`/`OSArray`, нет `OSSymbol::withCString`, нет
   `getObject`, нет `strcmp`/`cmp` по `task_t`, нет `proc_*`/`task_*` вызовов.
4. Результат никуда не публикуется: `str x0,[uc+0x120]` — единственная запись;
   ссылок на `0x120` из других процессов не существует по построению (поле
   живёт в объекте user client'а, `IOGPUDeviceUserClient` size `0x130`).

## Следствие для namespace'ов

Namespace-таблицы (`+0x10` ресурсы, `+0x88` очереди, `+0x110` IO-очереди,
`+0x78/0x80/0x90/0x18` каналы) лежат внутри объекта, полученного из `+0x588`.
Объект новый на каждое открытие → **таблица своя у каждого user client'а**,
в том числе у двух клиентов одного процесса. Номера id начинаются с 1 у
каждого; отсутствие проверки владельца в lookup `0x9944fb8` — не дефект.

## Не подтверждено

- Точная цель вызова базового init внутри `AGXShared::init`: `[0x7ca60d0]` —
  chained-указатель `0x0010000000fe9270`, резолвится в `0x7feb270`, но эта
  область в файле нулевая (vtable-патчинг / level-2). Что это именно
  `IOGPUDevice::init 0x9964c34` — вывод по сигнатуре (`x0=shared, x1=accel,
  x2=task`, далее чтение `[obj+0x48]`), не по прямому указателю.
- Не проверял, переопределяет ли `+0x588` какой-либо класс вне этих четырёх
  vtable'ов (в данном kernelcache слотов ровно 4).
- Рантайм-проверка (два процесса, по ресурсу, id) не выполнялась — только
  статика.

## Инструменты

`kc.py` (парсер chained fixups + дизасм), `ctors.pkl` (карта vptr→ctor),
`ref.pkl` (карта указателей `__DATA_CONST`/`__DATA`).
Ключевой момент парсера: в `DYLD_CHAINED_PTR_64_KERNEL_CACHE` (format 8)
`page_start[]` — в 8-байтовых единицах, а `next` — в 4-байтовых; при ошибке
в единицах `page_start` теряется часть vtable'ов.
