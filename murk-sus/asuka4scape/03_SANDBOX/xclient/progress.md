# xclient — кросс-клиентские id IOGPU (27.2 24B115)

## 2026-10-29 — subagent AE

Задача: что приложение может сделать с чужим ресурсом по id. Зацепка прошлого прохода:
ns ресурсов у `IOGPUDevice` (`+0x10` array, `+0x18` bitmap, `+0x20` lock, `+0x28` cap,
`+0x2c` hint, `+0x30` count), lookup `0x9944fb8` проверяет только `0<id<cap`, non-NULL и
refcount → «владелец не проверяется».

Разобрано:
- `0x9944fb8`/`0x9945040`/`0x9945214`/`0x9945154`/`0x99451a0` — get/get-locked/peek/detach/
  detach+release; `0x994508c` — обнуление слота+бита+count--, откат hint.
- `new_resource` `0x99669e0` → `ns[+0x10] add` `0x9944fb0`; id в `returnData+0x24`, GPU VA `+0x28`.
- Селекторы, берущие id: 7 (delete_cmd_queue, ns+0x88), 9 (delete_resource, ns+0x10 +
  `vt[0xb0]`), 10/11/12/13/14/15/18/19/20 (ns+0x10/+0x18/+0x78/+0x80/+0x90), 25 (submit,
  ns+0x88 + id из записи → ns+0x78), 38/39 (detach_backing / replace_backing_ranges),
  43/44/47/48/49/50 (ns+0x110), 52/53 (group add/remove, массив чужих id → `addMemoryFromResources`).
- `externalMethod` `0x994a1e0`: per-selector энтайтлментов нет, только `uc->[0x100]&1`,
  `selector<=0x37`, таблица `0x7fea200`/`0x7fea740`.

**Итог (опровержение зацепки):** `uc+0x120` — не общий `IOGPUDevice` на GPU, а объект,
созданный на подключение: `deviceUserClientStart` `0x9949e54..0x9949e88` зовёт
`provider->vt[0x588](provider, task, securityID)` и кладёт результат в `uc+0x120` без retain;
`IOGPUDevice::init` `0x9964c38` делает `task_reference(task)` и `str x20,[x19,#0x50]`
(+0x48 = общий `IOGPU*`, +0x50 = task клиента; других записей в +0x50 нет).
Все namespace'ы живут внутри этого объекта ⇒ id-пространство пер-клиентское,
кросс-клиентских id нет: чужой номер = либо свой ресурс с тем же номером, либо
отказ `kIOReturnBadArgument` (`0xe00002c2`).

Вердикт: **ничего** (ни DoS, ни data access). Не подтверждено: имя/поведение
`IOGPU::vt[0x588]` (vtable'ы в нулевой `__DATA_CONST`); рантайм-тест — в двух процессах
создать по ресурсу и сравнить id (оба `1` = пер-клиентские, `1`/`2` = общая таблица).

Файлы: `REPORT.md` (доказательная цепочка + дизасм + карта селекторов),
`an.py` (индекс bl/b, `callers()`, `fn_start`, `fn_end`), `selmap2.py` (селектор → id-операция),
`callidx.pkl` (кэш индекса, 247k целей).
