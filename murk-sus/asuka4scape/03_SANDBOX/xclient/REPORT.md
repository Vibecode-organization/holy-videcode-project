# IOGPU: «чужой» ресурс по id (27.2 / 24B115) — зацепка закрыта отрицательно

Ядро: `27.2_24B115_kernelcache`, `__TEXT_EXEC` → `va = 0xfffffff000000000 + off`.
Инструменты: `work/xclient/an.py` (индекс `bl/b`), `selmap2.py` (селектор → id-операция),
дизасм через `work/iogpu_all/kc.py` (capstone; знаковые imm замаскированы).
Импорты (GOT в `__DATA_CONST`) в дампе **нулевые** — имена внешних функций не резолвятся,
поэтому выводы держатся на структуре кода, а не на именах.

---

## 0. Вердикт

| | |
|---|---|
| DoS чужого процесса по id | **нет** |
| cross-process data access | **нет** |
| kernel UAF | нет |
| что на самом деле | «отсутствие проверки владельца» — не дефект: **namespace ресурсов создаётся на подключение** (`IOGPUDevice` создаётся в `deviceUserClientStart` с task'ом и securityID клиента), поэтому в таблице лежат только свои id |

Зацепка предыдущего прохода («`+0x10/+0x18/+0x20/+0x28/+0x30`, lookup `0x9965b58` → `0x9945040` →
`0x9944fb8`, владелец не проверяется, namespace висит на устройстве») **подтверждена в части
кода и опровергнута в части вывода**: namespace действительно висит на объекте `IOGPUDevice`
и действительно не проверяет владельца — потому что этот объект **свой у каждого
пользовательского клиента**, а не общий на GPU.

Ниже — доказательная цепочка (§1), полная карта id-операций (§2), дизасм (§3),
что это значит для атаки (§4), перебор id (§5) и что осталось непроверенным (§6).

---

## 1. Почему id не кросс-клиентские: цепочка из четырёх мест

### 1.1 Клиент запоминает task и securityID

Функция инициализации user client'а — `0xfffffff0099446e50` (имя не подтверждено:
`__func__`-строки для неё в образе нет; набор аргументов и полей — ровно
`initWithTask(owningTask, securityID, type, props)`):

```
0xfffffff0099446e50  adrp     x0, #0xfffffff007ff0000
0xfffffff0099446e54  add      x0, x0, #0x28
0xfffffff0099446e58  bl       #0xfffffff00998430c        ; alloc (импорт)
0xfffffff0099446e5c  str      x0, [x19, #0xd8]           ; uc+0xd8 = {task,...}
0xfffffff0099446e60  cbz      x0, #0xfffffff009946ea4
0xfffffff0099446e64  bl       #0xfffffff00998426c        ; alloc
0xfffffff0099446e68  str      x0, [x19, #0xf0]
0xfffffff0099446e6c  cbz      x0, #0xfffffff009946ea4
0xfffffff0099446e70  mov      x0, x20                   ; x20 = owningTask
0xfffffff0099446e74  bl       #0xfffffff009984ebc        ; task_reference(task)
0xfffffff0099446e78  ldr      x8, [x19, #0xd8]
0xfffffff0099446e7c  str      x20, [x8]                  ; *uc+0xd8 = task
0xfffffff0099446e80  str      x21, [x19, #0x128]         ; uc+0x128 = securityID (x21)
0xfffffff0099446e84  mov      x0, x20
0xfffffff0099446e88  bl       #0xfffffff009984cdc
```
`x20`/`x21` — это `task_t owningTask` и `void *securityID` из
`IOUserClient::initWithTask(task_t, void*, UInt32, OSDictionary*)`. `0x9984ebc` —
импорт, вызывается на task'е ровно так же, как `task_reference`; ниже тот же импорт
зовётся на task-аргументе при инициализации устройства (1.3).

### 1.2 Клиент **создаёт** устройство, а не получает общее

`IOGPUDeviceUserClient::deviceUserClientStart` — `0xfffffff009949e54`:

```
0xfffffff009949e54  ldr      x0, [x19, #0xf8]        ; провайдер (IOGPU, IOService)
0xfffffff009949e58  ldr      x8, [x19, #0xd8]
0xfffffff009949e5c  ldr      x1, [x8]                ; x1 = task клиента
0xfffffff009949e60  ldr      x2, [x19, #0x128]       ; x2 = securityID клиента
0xfffffff009949e64  ldr      x16, [x0]
0xfffffff009949e74  mov      x17, #0x588
0xfffffff009949e78  add      x16, x16, x17
0xfffffff009949e7c  ldr      x8, [x16]
0xfffffff009949e84  blraa    x8, x16                 ; provider->vt[0x588](provider, task, secid)
0xfffffff009949e88  str      x0, [x19, #0x120]       ; uc+0x120
0xfffffff009949e8c  cbz      x0, #0xfffffff009949f90
```
Аргументы — **task и securityID клиента**. Фабрика с такой сигнатурой не может быть
геттером общего объекта: общему устройству незачем знать токен безопасности
конкретного подключения. Дальше `uc+0x120` используется как «device» во всех
селекторах (§2).

### 1.3 Устройство хранит task клиента (одна запись, только в init)

`IOGPUDevice::init` (имя по классу-владельцу vtable; `__func__`-строки нет) — `0xfffffff0099964c38`:

```
0xfffffff009964c38  pacibsp
0xfffffff009964c3c  stp      x22, x21, [sp, #-0x30]!
0xfffffff009964c40  stp      x20, x19, [sp, #0x10]
0xfffffff009964c44  stp      x29, x30, [sp, #0x20]
0xfffffff009964c48  add      x29, sp, #0x20
0xfffffff009964c4c  mov      x20, x2                 ; arg2 = task
0xfffffff009964c50  mov      x21, x1                 ; arg1 = IOGPU*
0xfffffff009964c54  mov      x19, x0                 ; self
0xfffffff009964c58  adrp     x8, #0xfffffff007feb000
0xfffffff009964c5c  add      x8, x8, #0x1e8
0xfffffff009964c60  ldr      x9, [x8, #0x78]!
0xfffffff009964c64  mov      x17, x8
0xfffffff009964c68  movk     x17, #0x4a6a, lsl #48
0xfffffff009964c6c  blraa    x9, x17                 ; super::init()
0xfffffff009964c70  str      x21, [x19, #0x48]       ; device+0x48 = IOGPU*  (общий)
0xfffffff009964c74  mov      x0, x20
0xfffffff009964c78  bl       #0xfffffff009984ebc     ; task_reference(task)
0xfffffff009964c7c  str      x20, [x19, #0x50]       ; device+0x50 = task   (клиента)
0xfffffff009964c80  ldr      x16, [x19]
...
0xfffffff009964c94  mov      x0, x19
0xfffffff009964c98  mov      x1, x20
0xfffffff009964c9c  movk     x16, #0x771e, lsl #48
0xfffffff009964ca0  blraa    x8, x16                 ; далее init c task'ом
```
`+0x48` — общий `IOGPU*` (он же лимиты/лок: `[+0x24c]`, `[+0x250]`, `[+0x2e0]`,
`[+0x234]`), `+0x50` — task. Сплошной скан `str/stur` по `0x9960000..0x9970000`
даёт для этого объекта **единственную** запись `+0x50` — здесь; остальные попадания
относятся к другим классам (обнуление `[x+0x50]` в их teardown) либо к `sp`/return-структуре.
То есть поле не переставляется на каждый вызов — объект рождается с task'ом одного клиента.

### 1.4 Namespace'ы живут внутри этого объекта

`new_resource` кладёт ресурс в `[uc+0x120]+0x10`:

```
0xfffffff0099671a0  ldr      x0, [x22, #0x10]        ; device->ns_resources
0xfffffff0099671a4  mov      x1, x24                 ; новый IOGPUResource*
0xfffffff0099671a8  bl       #0xfffffff009944fb0     ; insert -> id (низший свободный)
0xfffffff0099671ac  str      w0, [x24, #0x88]        ; res->id
0xfffffff0099671b0  cbz      w0, #0xfffffff009967298
0xfffffff0099671b4  str      w0, [x21, #0x24]        ; returnData->id
```
а `delete_resource` берёт `[uc+0x120]+0x10` же (§3.1). Другого пути «достать id из
чужого namespace» в коде нет: все точки резолва принимают **тот же** `device`,
который пришёл из своего `uc+0x120`.

**Вывод.** `id` — локальный номер в таблице подключения. Числа у разных процессов
совпадают (у каждого свой счёт с 1), но это разные таблицы. `delete_resource(5)`
удаляет *свой* пятый ресурс либо возвращает `kIOReturnBadArgument`, если своего
пятого нет.

---

## 2. Карта id-операций (что вообще можно сделать по номеру)

Диспетчер `externalMethod` — `0xfffffff00994a1e0`: `uc->[0x100]&1`, `selector <= 0x37`,
таблица `0xfffffff007fea200` (или `0x7fea740` при `uc->[0x103]&1`). Per-selector
проверок прав нет — они и не нужны, если таблица своя у каждого клиента.

| операция | sel | резолв (в своём device) | проверка владельца | следствие |
|---|---|---|---|---|
| `delete_resource(id)` | 9 | ns `+0x10` detach → `vt[0xb0]` | нет (не требуется) | удаляет свой ресурс, id освобождается, GPU VA снимается |
| `delete_command_queue(id)` | 7 | ns `+0x88` detach → `0x997684c` | нет | удаляет свою очередь |
| `destroy_io_command_queue(id)` | 43 | ns `+0x110` detach → `0x995b020` | нет | удаляет свою IO-очередь |
| `destroy/try_cancel/perform/complete io cb` | 47/48/49/50 | ns `+0x110` get → `0x995b654`/`0x995bc50` | нет | работа со своими IO-буферами |
| `submit_command_buffers` | 25 | ns `+0x88` get(queue); id из записи `+0x20` → ns `+0x78` get | нет | сабмит в свою очередь; чужой номер просто не найдётся |
| `set_io_notification_queue` | 44 | ns `+0x110` get → ns `+0x90` get | нет | привязка своей очереди уведомлений |
| `res_detach_backing(id)` | 38 | ns `+0x10` get → `IOGPUResource::detach_backing()` | нет | снос backing своего ресурса |
| `res_replace_backing_ranges(id)` | 39 | ns `+0x10` get → `replace_backing_ranges` | нет | подмена backing своего ресурса |
| `set_resource_purgeable(id,state)` | 11 | ns `+0x10` get → type dispatch | нет | purgeable своего ресурса |
| `res_rec(id, idx)` | 10 | ns `+0x10` get → запись 0x40 Б в `res+0x18+idx*0x40` | нет | правка своей записи ресурса |
| `res_iter(id)` | 19 | ns `+0x10` get → `{id2,[res+0x288],[res+0x38]}` | нет | метаданные своего ресурса |
| `GROUP_ADD(group,id[])` | 52 | ns `+0x10` get(group) + `peek` каждого id | нет (только `type != 3`) | вложить свои ресурсы в свою группу |
| `GROUP_REMOVE(group,id[])` | 53 | то же | нет | вынуть свои ресурсы |
| `ns+0x78/0x80/0x90/0x18 remove(id)` | 13/18/15/20 | detach+release | нет | снос своего канального объекта |

Формы аргументов (для полноты): `sel 9/13/15/18/20` — `scalar[0]=id`;
`sel 10/11/12` — `scalar[0]=id, scalar[1]=параметр`; `sel 38/39` — `structIn{id,...}`
(≥0x18); `sel 52` — `scalar[0]=group, scalar[1]=count`, `structIn = uint32_t ids[count]`
(проверка `structInSize >= count*4` @`0x949268`); `sel 53` — то же, `>= count*8`.

---

## 3. Дизасм ключевых мест (как оно устроено внутри)

### 3.1 `delete_resource` — sel 9 (`0x947bdc`) → `0x9965954`

```
0xfffffff009947bdc  bti      c
0xfffffff009947be0  ldr      x0, [x0, #0x120]        ; СВОЙ device
0xfffffff009947be4  ldr      x8, [x2, #0x20]
0xfffffff009947be8  ldr      w1, [x8]                ; id = scalarInput[0]
0xfffffff009947bec  b        #0xfffffff009965954
```
```
0xfffffff009965954  bti      c
0xfffffff009965958  pacibsp
0xfffffff00996595c  stp      x20, x19, [sp, #-0x20]!
0xfffffff009965960  stp      x29, x30, [sp, #0x10]
0xfffffff009965964  add      x29, sp, #0x10
0xfffffff009965968  mov      x19, x0
0xfffffff00996596c  ldr      x0, [x0, #0x10]         ; ns ресурсов (своего device)
0xfffffff009965970  bl       #0xfffffff009945154    ; lock + detach(id) + unlock
0xfffffff009965974  cbz      x0, #0xfffffff0099659a0 ; нет id -> 0xe00002c2
0xfffffff009965978  ldr      x16, [x0]
0xfffffff00996597c  mov      x17, x0
0xfffffff009965980  movk     x17, #0xcda1, lsl #48  ; дискриминатор = объект
0xfffffff009965984  autda    x16, x17
0xfffffff009965988  ldr      x8, [x16, #0xb0]!      ; vt[0xb0] = teardown
0xfffffff00996598c  mov      x1, x19                ; device
0xfffffff009965990  movk     x16, #0xb33d, lsl #48
0xfffffff009965994  blraa    x8, x16
0xfffffff009965998  mov      w0, #0
0xfffffff00996599c  b        #0xfffffff0099659a8
0xfffffff0099659a0  mov      w0, #0x2c2
0xfffffff0099659a4  movk     w0, #0xe000, lsl #16   ; kIOReturnBadArgument
0xfffffff0099659a8  ldp      x29, x30, [sp, #0x10]
0xfffffff0099659ac  ldp      x20, x19, [sp], #0x20
0xfffffff0099659b0  retab
```
`vt[0xb0]` — тот же слот, которым `new_resource` уничтожает недоинициализированный
ресурс (`0x9966e98`, `0x9967104`: вызов и `ret` без `release`), т.е. teardown
съедает ссылку, которую держал namespace. Имя слота не достаётся: vtable'ы в
`__DATA_CONST`, она в дампе нулевая.

### 3.2 Резолв `id → объект` — `0x9944fb8` (границы + refcount, ничего больше)

```
0xfffffff009944fcc  cbz      w1, #0xfffffff009945028   ; id == 0 -> отказ
0xfffffff009944fd0  ldr      w8, [x0, #0x28]           ; cap
0xfffffff009944fd4  cmp      w1, w8
0xfffffff009944fd8  b.hs     #0xfffffff009945028      ; id >= cap -> отказ
0xfffffff009944fdc  ldr      x8, [x0, #0x10]           ; array
0xfffffff009944fe0  ubfiz    x9, x1, #3, #0x20
...                                                   ; (PAC-проверка слота, опущено)
0xfffffff009944ff8  ldr      x0, [x10]                 ; slot
0xfffffff009944ffc  cbz      x0, #0xfffffff009945034  ; NULL -> отказ
0xfffffff009945000  add      x8, x0, #0xc             ; refcount @ obj+0xc
0xfffffff009945008  ldadd    w9, x8, [x8]             ; ++
0xfffffff00994500c  mov      w9, #0xfffffff
0xfffffff009945010  cmp      w8, w9
0xfffffff009945014  b.lo     #0xfffffff009945034
```
Раскладка namespace (подтверждена по всем точкам):
`+0x10` array, `+0x18` bitmap, `+0x20` IOLock, `+0x28` cap, `+0x2c` hint, `+0x30` count.
Поля владельца в структуре нет — и это логично для таблицы, у которой один владелец
по построению.

Detach (`0x994508c`) обнуляет слот, бит и `count--`, откатывая `hint` на этот id:
следующий `new_resource` (в этом же процессе) получит этот номер.

### 3.3 `submit_command_buffers` — sel 25: id из записи резолвится, но не ресурс

`0x9976cf8` идёт по записям (stride = `[accelerator+0x268]`), и на каждой:

```
0xfffffff009976e18  ldr      w1, [x24, #0x20]         ; id из записи клиента
0xfffffff009976e1c  cbz      w1, #0xfffffff009976e4c
0xfffffff009976e20  ldr      x0, [x19, #0x488]        ; свой device
0xfffffff009976e24  bl       #0xfffffff009965b58     ; ns[+0x78].get(id)
0xfffffff009976e28  mov      x1, x0
0xfffffff009976e3c  ldr      x8, [x16, #0x80]!        ; queue->vt[0x80]
0xfffffff009976e48  blraa    x8, x16
0xfffffff009976e58  ldr      x0, [x19, #0x580]       ; удержанный объект
0xfffffff009976e70  ldr      x8, [x16, #0x28]!        ; release
0xfffffff009976e7c  str      xzr, [x19, #0x580]
```
Базовая реализация `0x997a410` — `str x1,[x0,#0x580]`, т.е. объект просто удерживается
на время записи. id ресурсов из тела command buffer'а **не** резолвятся (там GPU VA,
а не id), поэтому «подставить чужой ресурс в свой submit» нечем: чужая страница в
мою page table не попадёт.

### 3.4 `group_add_resources` — sel 52 (`0x9491a0` → `0x9967e24` → `0x9967bc0`)

```
0xfffffff0099491d8  ldr      w23, [x8]               ; scalar[0] = group id
0xfffffff0099491dc  ldr      w21, [x8, #8]           ; scalar[1] = count
0xfffffff009949268  cmp      x0, x21, lsl #2         ; structInSize >= count*4
0xfffffff009949270  ldr      x0, [x22, #0x120]       ; свой device
0xfffffff009949280  bl       #0xfffffff009967e24
```
```
0xfffffff009967bfc  cbz      x21, #0xfffffff009967c58
0xfffffff009967c00  ldr      w1, [x23, x24, lsl #2]  ; ids[i]
0xfffffff009967c08  bl       #0xfffffff009945214    ; peek в СВОЁМ ns[+0x10]
0xfffffff009967c10  cbz      x0, #0xfffffff009967c58 ; нет -> abort
0xfffffff009967c14  ldrb     w8, [x0, #0x10]         ; res->type
0xfffffff009967c18  cmp      w8, #3
0xfffffff009967c1c  b.eq     #0xfffffff009967c58     ; нельзя группу в группу
0xfffffff009967c30  ldr      x8, [x16, #0x20]!       ; vt[0x20] = retain
0xfffffff009967c7c  bl       #0xfffffff009956c5c    ; addMemoryFromResources
```
Проверок владельца нет — но и чужих id тут быть не может: `peek` смотрит в тот же
`[device+0x10]`, куда пишет только `new_resource` этого же клиента.

---

## 4. Что это значит для атаки

1. **Чужой id не резолвится.** Пространство id — часть объекта, созданного на
   подключение (`uc+0x120`), с task'ом и securityID клиента. Второго пути в чужой
   namespace нет: все селекторы и `new_resource`/`delete_resource` берут `device`
   из своего `uc`.
2. **`delete_resource` чужого номера** либо удалит *свой* ресурс с этим номером
   (номера у процессов совпадают: у каждого счёт с 1), либо вернёт `0xe00002c2`.
   Для жертвы — ничего.
3. **`group_add`** может вложить только свои ресурсы; максимум — самоDOS
   (вложить группу в группу нельзя, а свои ресурсы можно испортить и так).
4. **`submit`** в чужую очередь не отправить: id очереди резолвится в своей таблице.
5. Единственная общая сущность в поле зрения — `IOGPU*` в `device+0x48`
   (лимиты `+0x234/+0x24c/+0x250`, лок `+0x2e0`); он не содержит id-таблиц,
   через него id не адресуются.

То есть «нет проверки владельца» здесь — не missing check, а следствие того, что
проверять нечего: таблица пер-клиентская. Это же объясняет, почему Apple не
ставит в lookup ни `task_t`, ни securityID, хотя securityID у клиента под рукой
(`uc+0x128`).

---

## 5. Перебор id (внутри своего пространства)

* Диапазон `1 .. cap-1`, `cap` растёт (`0x9944424`), выдача — низший свободный бит,
  `hint` откатывается при удалении.
* Выданный id возвращается в `returnData+0x24` (`0x99671b4`), GPU VA — в `+0x28`.
* Оракул «id жив» внутри своего пространства: `sel 11` (`0`) / `0xe00002c2`;
  `sel 9` — разрушающий, но самосообщающий.
* Наблюдаемость чужих процессов: **нулевая** — их таблицы не видны и не влияют
  на мои номера (счёт у каждого свой).

---

## 6. Что осталось непроверенным / чем это можно опрокинуть

1. **Имя слота `IOGPU::vt[0x588]`** — не резолвится: vtable'ы в `__DATA_CONST`,
   а в дампе она нулевая (`0xbb4000` — не указатели, проверено). Вывод «создание,
   а не getter» держится на трёх косвенных признаках: аргументы `(task, securityID)`,
   `task_reference` в `IOGPUDevice::init` с записью в `+0x50`, и то, что `+0x50`
   больше нигде не перезаписывается (сплошной скан `str/stur` по `0x9960000..0x9970000`).
2. Если бы `vt[0x588]` возвращал **кэшированный общий** объект, картина перевернулась
   бы: тогда `delete_resource`/`group_add` стали бы кросс-клиентскими. Проверить это
   статикой нельзя — нужен либо рантайм (создать ресурсы в двух процессах и сравнить
   выданные id), либо распакованный `__DATA_CONST` с vtable'ами.
   Быстрый рантайм-тест: в приложении и в SpringBoard-подобном процессе создать по
   ресурсу; если оба получат `id=1` — таблицы пер-клиентские (ожидаемый исход);
   если второй получит `id=2` — таблица общая, и тогда отчёт надо читать как
   «кросс-клиентский доступ есть».
3. `cap` (стартовое значение `[ns+0x28]`) и инициализация namespace не найдены;
   рост по `0x9944424` есть.
4. `sel 47/48/49/50` (IO command buffer) на гонки с teardown не разбирались —
   в рамках своей таблицы это self-DoS.

---

## 7. Поправка к предыдущему проходу

`uc+0x120` — действительно `IOGPUDevice`, и его namespace действительно не проверяет
владельца. Ошибка была в том, что объект сочли общим на GPU. Он создаётся в
`deviceUserClientStart` фабрикой провайдера с аргументами `(task, securityID)`
(`0x9949e54..0x9949e88`) и хранит task клиента в `+0x50`
(`IOGPUDevice::init` `0x9964c38`: `task_reference` → `str x20,[x19,#0x50]`).
Поэтому id-пространство — пер-клиентское, и «отсутствие проверки владельца» —
не дефект.
