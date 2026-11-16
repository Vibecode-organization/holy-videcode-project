# agx_iogpu — subagent X2 (AGXCommandQueue + остаток селекторов IOGPU)

## step 1 — вход
- work/agx_iogpu/ не существовал; использованы готовые тулы `work/agx_queue/tools` (kc.py/vm.py, capstone 5.0.7).
- Прочитаны отчёты соседей: `parse_iogpu` (sel 52/53, ABI args), `uaf_gpu` (refcount/namespace, TOCTOU лимита).

## step 2 — AGXCommandQueue: класс
- `metaclass.json` (parse_gpu) даёт site 0x819bba8, size 0x948.
- Дизасм конструктора метакласса: name "AGXCommandQueue" 0x711964d, meta 0xae20f50, super через GOT 0x7ca6038.
- `bl 0x8215ad0` — GOT-трамплин. `0x819a850` аллоцирует 0x948 и ставит vtable **0x7c93bb8** (44 слота).
- Слот 0/1 — dtor → `0x99763d8` (IOGPUCommandQueue::~) + kfree(0x948). База — vtable `0x7feee38` (41 слот; символ `__ZTV` = 0x7feee28, +0x10 prefix). AGX добавляет слоты 41..43.

## step 3 — достижимость
- sel 6 `0x99476bc`: stInSize == `[uc+0xf8]+0x278` = 0x408 (константа записана в `0x99714c8`); фабрика `[uc+0xf8]->vt+0x698`; затем `queue->vt[27]` = `0x818f8e8` AGXCommandQueue::init.
- Init зовёт базу `IOGPUCommandQueue::init` `0x99765dc` (через `__ZTV+0xe8` = function table +0xd8 = слот 27).
- База: `memcpy(q+0x10, stIn, 0x400)`, `[q+0x450]=stIn[0x400]` (<5), `[q+0x439]/[q+0x527]` = bool(stIn[0x404/0x405]), `[q+0x490]=stIn[0x60]`, `[q+0x480]=dev[0x58]`+retain.
- AGX init: count `[q+0x848]` = `[accel+0x11140]`/`[accel+0x610]`; массивы `[q+0x8e0]`=count*0x40, `0x8f0`=count*8, `0x8f8`=count*8, `0x900`=count*4; маска `0x830`=(n-1)%n; индексы `0x83c/0x840`=0; `0x7ec`=-1; `0x7f4`=0x100/0x100.

## step 4 — submit/ring/complete
- vt35 `0x818eb40`: lazy start (vt43), `[q+0x610]->vt+0x98`, сброс `0x7e8/0x7ea`, хвост в базовый submit.
- sel 25 worker `0x9976cf8` под `[q+0x458]`; запись = `buf + i*stride`, читает `+0x20` (id) → ns `[dev+0x78]` retain → `vt+0x80`; затем `0x997700c` (читает `+0x10/+0x18`) → vt35.
- vt36 `0x818e0f0` signal, vt37 `0x818df38` wait (таймаут мс→мкс, cap 0xfa0). Отдельного complete-слота нет — firmware-кольцо.

## step 5 — free/stop
- sel 7 → `removeLocked` → `0x997684c` terminate: `[q+0x458]` lock → vt17 stop → unlock → release.
- stop `0x819a1f4`: база stop `0x997690c`, `[accel+0x4b0]->vt[0x230]`, разбор пулов `[q+0x610]`.
- free (vt14) `0x819a4c0`: release `0x610/0x918/0x910`, затем IOFree четырёх массивов по `[q+0x848]`.
- Submit-worker и terminate под одним мьютексом `[q+0x458]`; free — по refcount 0. UAF нет.

## step 6 — селекторы IOGPU
- Собрана сводная таблица 56 селекторов (args-офсеты, проверки, callee).
- structureInput читают только 6,8,25,26,27,38,39,45 (+52/53).
- stIn=0xffffffff: 6 (==0x408), 8 (>=0x58 + output floor), 25 (==count*stride + umulh), 45 ((size-8)%24==0, header==count).
- Найден дефект sel 25: stride не ограничен снизу → OOB read до 0x1F–0x2F за structureInput, значение → id в `[dev+0x78]`.
- sel 45: count перечитывается из буфера — TOCTOU только в descriptor-пути (не подтверждён для песочницы).
- callee `0x9967e24`/`0x9967bc0` — только sel 52; `0x9945040` — retain под ns-локом; `0x9945214` — 12/17 под локом (5 thunk'ов не подтверждены).

## step 7 — результат
- REPORT.md записан, CHAT-строка добавлена. Не трогал sbx_build/IPA.
