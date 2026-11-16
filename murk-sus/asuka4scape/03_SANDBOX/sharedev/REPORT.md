# IOSurfaceSharedEvent / IOFence — UAF и гонки (kernelcache iOS 27.2, 24B115)

Цель: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`
Класс: `IOSurfaceRootUserClient`, таблица B (без энтайтлментов). Метод: статический RE,
Capstone ARM64, короткие адреса = VA − `0xfffffff000000000` (`__TEXT_EXEC` offset = VA − `0xfffffff007004000`).
На устройстве ничего не запускалось; всё, что не доказано кодом, помечено **не подтверждено**.

## 0. Итог

**Подтверждённого UAF/гонки, достижимой приложением без энтайтлментов, не найдено.**
Дисциплина ссылок в SharedEvent-путях выдержана жёстко: единственный хендл события для
приложения — Mach-порт; `ipc_object_copyin` даёт **+1** на объект `IOSurfaceSharedEventReference`,
а тот держит сильную ссылку на событие (`ref+0x10`). Пока вызов внутри ядра, событие жить обязано.

Три места остаются дефектными, но два из них закрыты приватным энтайтлментом, а третье
держит инвариант через refcount, а не через лок:

1. `IOSurfaceSharedEventListener::free 0x9c157d4` — проверка «очередь пуста» **без лока**,
   затем разрушение лока `+0x10` и workloop. Паника `0x9c48e20` живая. Инвариант спасает
   только то, что узел очереди сам держит ссылку на listener (`0x9c18420` отпускает `+0x40`).
   Гонка «free под добавляющим потоком» структурно возможна, эксплуатация — **не подтверждено**.
2. `IOSurfaceSharedEvent::free 0x9c16cdc` — то же самое для списка уведомлений (`+0x40`) плюс
   освобождение agent-mask блока `+0x58` **без снятия регистрации** в таблице владельца.
   Требует бита энтайтлментов `0x80000` (`0x9c31488`) → из песочницы **недостижимо**.
3. `IOSurfaceSharedEvent::allocAgentMaskSlot 0x9c18180` — check-then-act по `+0x58` без лока
   блока: два потока → два блока, один теряется вместе с `IOLock`. Тот же энтайтлмент.

Побочно закрыт пункт «не подтверждено #3» прошлого отчёта `work/uaf_surf`: чтение полей
`IOSurface` в sel34 до `retain` **безопасно** — `IOSurfaceSendRight` держит `+1` на поверхности
в `+0x18` и отпускает её в деструкторе `0x9c47788`.

## 1. Точка входа: таблица селекторов

`IOSurfaceRootUserClient::externalMethod` = `0x9c3ee10`:

```
0x9c3ee10  adrp x8, #0x8068000 ; add x8,#0xb90      ; таблица A = 0x8068b90
0x9c3ee1c  ldrb w9,[x0,#0x127]                      ; флаг клиента
0x9c3ee20  adrp x10,#0x8069000 ; add x10,#0x4f0     ; таблица B = 0x80694f0
0x9c3ee28  tst  w9,#1 ; csel x3,x10,x8,ne
0x9c3ee30  mov  w4,#0x3c                            ; 60 записей
0x9c3ee34  mov  x5,x0 ; mov x6,#0
0x9c3ee3c  b    #0x9c498f4                          ; generic dispatch 0xa9b0888
```

Формат записи — `0x28`: `[+0]` PAC-указатель на action, `[+8]` `{u32 scalarIn, u32 structIn}`,
`[+0x10]` `{u32 scalarOut, u32 structOut}`. Таблица A `0x8068b90` (60×0x28), B `0x80694f0`
(60×0x28). В B селекторы 4-8, 16-19, 21, 22, 24-26, 28-30, 33, 43, 46-49 подменены на
`0x9c3a1dc` (`return 0xe00002e2`); всё остальное, включая 27, 31, 32, 34-42, 44, 45, 50-52,
55-59, живо. SharedEvent-селекторы доступны **в обеих** таблицах.

| sel | stub | action | что делает |
|---|---|---|---|
| 32 | `0x9c39760` | `[uc+0x138]->vt+0x78` | отдаёт user VA маппинга |
| 34 | `0x9c397d8` | `0x9c3b7b0` | `set_surface_handle` по `IOSurfaceSendRight` |
| 36 | `0x9c39868` | `0x9c3dad4` | создать SharedEvent + выдать Mach-порт |
| 37 | `0x9c398f0` | `0x9c3d16c` | signal по порту |
| 38 | `0x9c39904` | `0x9c3dbec` | инфо о событии (значение, 2 поля, маппинг) |
| 39 | `0x9c39924` | `0x9c3dd58` | wait по порту (+async) |
| 40 | `0x9c3993c` | `0x9c3df84` | регистрация async-уведомления |
| 45 | `0x9c39a64` | `0x9c3d038` | wait по порту с таймаутом |
| 27 | `0x9c39654` | `0x9c3d7c8` | structureInput-путь |

## 2. Модель объектов (регистрация классов)

Единая функция регистрации `0x9c18b44` строит метаклассы:

| класс | метакласс | sizeof | мета-vtable |
|---|---|---|---|
| `IOSurfaceSharedEventListener` | `0xaf48120` | 0x50 | `0x8066728` |
| `IOSurfaceSharedEventNotificationPort` | `0xaf48148` | 0x90 | `0x8066850` |
| `IOSurfaceSharedEventReference` | `0xaf48170` | 0x18 | `0x8066978` |
| `IOSurfaceSharedEvent` | `0xaf48198` | 0x68 | `0x8066aa8` |
| `IOSurfaceSharedEventNotification` | `0xaf481c0` | 0x70 | `0x8066bd0` |
| `IOSurfaceSendRight` | `0xaf484d0` | 0x28 | `0x8066910` |

vtable инстанса `IOSurfaceSharedEvent` = **`0x8066a10`** (ставится в
`MetaClass::alloc 0x9c16938`: `kalloc_type(0x806ae30,0x68)`, `OSObject::OSObject`, `str vtable,[x0]`).

```
+0x00 0x9c16874  operator delete        +0x40 0xa894ab4  isEqualTo
+0x08 0x9c1687c  operator delete(size)  +0x48 0x9c18070
+0x10 0x9c17fe8  retain(when)           +0x50 0x9c18104
+0x18 0x9c17f48  getRetainCount         +0x58 0x9c1807c  taggedRetain
+0x20 0x9c17f60  retain  (ldadd obj+0xc)+0x60 0xa8edee0
+0x28 0x9c17f6c  release (0x9c46ff8)    +0x68 0xa89797c  taggedRelease
+0x30 0xa897ba0                          +0x70 0x9c16cdc  free
+0x38 0x9c168dc  getMetaClass           +0x78 0x9c16c68  ~dtor
```

`0x9c17f60` = `add x0,x0,#0xc ; b 0x9c46fb8` — тот же атомарный `ldadd +1` по `obj+0xc`,
что у `IOSurface`. `0x9c17f6c` = `0x9c46ff8(&obj+0xc, 3, 2)`, при нуле → `vt+0x78` (dtor).

Ключевые методы:

| функция | адрес | роль |
|---|---|---|
| `SharedEvent::create` | `0x9c16a78` | `MetaClass::alloc` → `init(owner, kind)` |
| `SharedEvent::init` | `0x9c16b10` | `+0x10`=owner(retain), `+0x1c`=id, `+0x20`=PAC(shared page), `+0x30`/`+0x60`=IOLock, `+0x40/+0x48`=очередь, `+0x50`=kind (0..3) |
| `SharedEvent::signal` | `0x9c16db0` | CAS/`stlr` по shared page, `0x9c16f04`, `0x9c16fa0`, `wakeup` |
| `SharedEvent::waitForValue` | `0x9c172ec` | `ldar` + `ldaddal` счётчик ждущих `+0x18` + sleep на адресе события |
| `SharedEvent::free` | `0x9c16cdc` | panic при `[+0x40]≠0`; free локов `+0x30/+0x60`, agent-блока `+0x58`, release `+0x10` |
| `SharedEvent::~` | `0x9c16c68` | release id (`0x9c364c0`), tail `vt+0x70` |
| `Reference::make` | `0x9c165ec` | alloc 0x18 + `setEvent` |
| `Reference::setEvent` | `0x9c16670` | `[+0x10]`=event, retain new (vt+0x20), release old (vt+0x28) |
| `Reference::free` | `0x9c166e8` | `signal(event, -1, 1)` → всех будит |
| `Reference::~` | `0x9c162ec` | release `[+0x10]` |
| `Notification::~` | `0x9c18420` | release `+0x50`, `+0x40` (listener!), `+0x38` |
| `Listener::init` | `0x9c15480` | lock `+0x10`, очередь `+0x18/+0x20`, workloop `+0x30`, thread_call `+0x38` |
| `Listener::free` | `0x9c157d4` | panic при `[+0x18]≠0`, затем teardown |
| `Listener::add` | `0x9c158dc` | под `+0x10`: вставка в голову, retain, arm thread_call |
| `Listener::drain` | `0x9c159b4` | под `+0x10`: снять весь список, вне лока `0x9c15b1c`+release |
| `IOFenceTransaction::free` | `0x9c19270` | panic при `[+0x28]≠0`, kfree массива `+0x30`, IOLockFree `+0x20` |

## 3. Таблица «объект | ref | лок | вердикт»

| объект | кто держит ссылку | лок | вердикт |
|---|---|---|---|
| `IOSurfaceSharedEvent` (0x68) | `Reference[+0x10]` (+1 при создании, release в `0x9c162ec`); при `init` — owner `+0x10`; при `free` — отпускается | `+0x30` (список уведомлений), `+0x60` (доставка), `+0x58`→block`+0x68` (agent-mask) | **безопасно.** `free 0x9c16cdc` достижим только при rc=0; все app-пути держат `Reference` +1 |
| `IOSurfaceSharedEventReference` (0x18) | Mach-порт (kobject); `ipc_object_copyin 0xa9a7bc0` даёт +1 на каждый вызов | нет | **безопасно.** `setEvent` (0x9c16670) атомарно подменяет `+0x10` |
| `IOSurfaceSharedEventNotificationPort` (0x90) | `Notification[+0x50]`; `Listener` | — | **безопасно** (dtor `0x9c15d2c` отпускает `+0x30`,`+0x38`) |
| `IOSurfaceSharedEventNotification` (0x70) | узел очереди listener'а: `+0x28` next / `+0x30` prev под `listener+0x10`; держит listener `+0x40` | — | **безопасно.** dtor `0x9c18420` отпускает всё |
| `IOSurfaceSharedEventListener` (0x50) | `Notification[+0x40]` (сильная) | `+0x10` | **не подтверждено:** проверка очереди в `free` вне лока (см. топ-1) |
| `IOSurfaceSendRight` (0x28) | порт; `+0x18` = IOSurface с +1 | — | **безопасно.** dtor `0x9c47788` → release `+0x18` |
| `IOFenceTransaction` (0x48) | владелец (per-surface fence list) | `+0x20` | **безопасно.** `free 0x9c19270` паникует при `[+0x28]≠0` |
| `IOSurface` fence-счётчик `[surf+0x178]+0x18` | — | lock-free `cas`/`casal` (`0x9c22ee0`, `0x9c2302c`) | **безопасно.** Сатурация: `0xFFFFFFFF` не инкрементится, 0 не декрементится |
| флаги `surf+0x3d0` / `surf+0x3d2` | — | нет | **не подтверждено:** чтение в sel34 без лока поверхности (stale-read, не UAF) |

## 4. Топ-3

### 4.1 `IOSurfaceSharedEventListener::free 0x9c157d4` — проверка очереди без лока

```
0x9c157e8  ldr  x8,[x0,#0x18]        ; queue head, БЕЗ IOLockLock([x0+0x10])
0x9c157ec  cbnz x8,#0x9c158d8        ; → 0x9c48e20: panic "notification list is not empty"
0x9c157f4  ldr  x0,[x0,#0x30]        ; workloop
0x9c157fc  ldr  x8,[x19,#0x38]       ; thread_call
0x9c15814  ldr  x9,[x16,#0xb8]!      ; thread_call->cancel
0x9c15838  ldr  x8,[x16,#0xa8]!      ; workloop->removeEventSource
0x9c1585c  ldr  x8,[x16,#0x28]!      ; release(thread_call)
0x9c15868  str  xzr,[x19,#0x38]
```

Паника живая: `bl 0x9c48e20` из `0x9c158d8` (единственный вызов, проверено сканом всех `bl`).

Последовательность двух потоков:

```
T1: close(uc) → последний release(listener) → free 0x9c157d4
    ldr x8,[listener+0x18] → 0 (очередь пуста) → идём дальше
T2: sel37 signal(port) → 0x9c16fa0 → 0x9c158dc(listener, node)
    0x9c158f8  ldr x0,[listener+0x10]   ← лок уже освобождён/освобождается
    0x9c158fc  bl  0x9c495b4            ← IOLockLock по освобождённому IOLock
    0x9c15914  str x8,[listener+0x20]   ← запись в освобождённый listener
T1: 0xa9... IOLockFree(listener+0x10)
```

Что спасает: узел `node` держит сильную ссылку на listener (`Notification::~ 0x9c18420`
отпускает `[+0x40]`), а вставка делает `retain(node)` под локом. Значит непустая очередь
невозможна при rc=0, и окно закрывается порядком ссылок, а не синхронизацией.
**Вердикт: инвариант держится на refcount; UAF не подтверждён.**

### 4.2 `IOSurfaceSharedEvent::free 0x9c16cdc` — agent-mask блок освобождается без снятия регистрации

```
0x9c16cf0  ldr  x8,[x0,#0x40]        ; notification list head
0x9c16cf4  cbnz x8,#0x9c16dac        ; → 0x9c48e50 panic (единственный вызов, живой)
0x9c16cfc  str  xzr,[x0,#0x20]       ; обнулить shared-page ptr
0x9c16d00  ldr  x0,[x0,#0x30] ; IOLockFree ; str xzr,[+0x30]
0x9c16d10  ldr  x0,[x0,#0x60] ; IOLockFree ; str xzr,[+0x60]
0x9c16d20  ldr  x1,[x19,#0x58]       ; agent-mask block
0x9c16d28  ldr  x0,[x1,#0x68] ; IOLockFree
0x9c16d3c  adrp x0,#0x806b000 ; add x0,#0xa70 ; mov w2,#0x70
0x9c16d48  bl   0x9c49584           ; kfree_type(block, 0x70)
0x9c16d50  release([x19,#0x10])      ; owner
```

`[+0x58]` создаётся лениво в `allocAgentMaskSlot 0x9c18180` и регистрируется у владельца
через `0x9c36be0` → `0x9c3692c(owner+0x138, eventId, 0x20, &idx, block)`. В `free` **нет**
парного «снять запись» — записи в таблице владельца остаётся указатель на освобождённый блок
(или на его маску, если `0x9c3692c` копирует 0x20 байт; разбор не доведён).
Асимметрия с списком уведомлений (там паника) — признак недоделанного инварианта.

Достижимость: `0x9c178fc` (единственный вход) на входе делает
`mov w0,#0x80000 ; bl 0x9c31488` → `and w0, [root+0x1a4], w0` — бит кэшированной маски
энтайтлментов клиента (`IOSurfaceRoot +0x1a4`). Без бита → `0xe00002c7`.
**Вердикт: дефект есть, из песочницы недостижим → не подтверждено.**

### 4.3 `IOSurfaceSharedEvent::allocAgentMaskSlot 0x9c18180` — check-then-act без лока

```
0x9c181ac  ldr  x8,[x0,#0x58]
0x9c181b0  cbz  x8,#0x9c181bc        ; если уже есть — выйти
0x9c181c8  adrp x0,#0x806b000 ; add x0,#0xac0 ; mov w1,#0x70
0x9c181d4  bl   0x9c49624           ; kalloc_type(block, 0x70)
0x9c181e0  bl   0x9c49594 ; str x0,[x20,#0x68]   ; IOLockAlloc
0x9c18228  bl   0x9c36be0           ; регистрация у владельца (берёт owner+0x148)
0x9c18240  str  x20,[x21,#0x58]     ; публикация БЕЗ лока блока
```

Два потока в `addAgentMaskForSignalValue 0x9c178fc` (лок берётся **после** этого вызова,
`0x9c179a0` — уже по `[block+0x68]`):

```
T1: ldr [evt+0x58] → 0 → alloc block1 → register → str block1
T2: ldr [evt+0x58] → 0 (T1 ещё не записал) → alloc block2 → register → str block2  (block1 потерян)
```
Потери: 0x70 байт зоны `0x806bac0`, один `IOLock`, дублирующая запись в таблице владельца
с тем же event id. Плюс `addAgentMask` затем паникует `Agent mask slot exhaustion`
(`0x789aac2`), если слоты кончились.
**Вердикт: утечка + дубль регистрации; энтайтлмент `0x80000` → из песочницы не подтверждено.**

## 5. Что проверено и оказалось чистым

* **sel36 `0x9c3dad4`** (создание + выдача порта): `create` → `ref = 0x9c165ec(event)` (+1) →
  `0x9c41eec([uc+0x118], event->id, &out)` (маппинг shared-страницы, ошибка → ветка release) →
  `0x9c49834` = `ipc_port_copyout_send_right 0xa9a7b30`, которая **всегда возвращает 0**
  (`mov w0,#0`), т.е. «установила и вернула ошибку» невозможно → двойного release нет.
  Далее `release(ref)` (`0x9c3db90`) и `release(event)` (`0x9c3dbb0`) на всех ветках.
* **sel37 `0x9c3d16c`**: `ipc_object_copyin(port, 0x26)` → `safeMetaCast 0xa894f30` на
  метакласс `0xaf48170` → `[ref+0x10]` → `signal(value, 1)` → release. Ссылка держится весь вызов.
* **sel45 `0x9c3d038`**: то же + `0x9c49ba4(timeout, 0xf4240, &deadline)` → `waitForValue`
  под +1 на `Reference` → release. Ждать можно только пока держишь порт.
* **sel38/40**: только чтение полей и регистрация async-объекта; освобождение `[+0x10]`/`[+0x18]`
  парное, утечек ссылок не найдено.
* **sel34 `0x9c3b7b0`**: `[sendright+0x18]` — поверхность с +1 от SendRight (dtor `0x9c47788`
  её отпускает), поэтому чтения `[surf+0x3d2]` (`tbz #3`) и `[surf+0x170]` (PAC key `0xf19c`,
  сравнение с `[uc+0xf8]`) до `0x9c2b810` — **не UAF**, только гонка данных (TOCTOU владельца).
* **Счётчик fence на поверхности** `[surf+0x178]+0x18` (`0x9c22ee0` инкремент, `0x9c2302c`
  декремент): `cas`-петля со сатурацией по границам `0`/`0xFFFFFFFF`, обход при
  `[surf+0x3d2] bit5`. Андерфлоу и переполнения нет.
* **`IOFenceTransaction::free 0x9c19270`**: `[+0x28]` (count) ≠ 0 → паника `0x9c19318`
  (`"IOFenceTransaction %p freed with non-zero fence count!"`); затем kfree массива
  `[+0x30]` размером `[+0x2c]*8`, IOLockFree `[+0x20]`. Окно «сигнал → освобождение» закрыто
  тем, что каждый fence держит запись в транзакции, а `dump 0x9c1933c` ходит под `+0x20`.
* **`IOSurface` +0x3d0**: `0x9c49060` `ldr w8,[x0,#0x3d0] ; bfxil w4,w8,#9,#1` — бит 9
  (`isInUse`) уходит в kdebug-трейс; слово флагов подтверждено.

## 6. Не подтверждено / поправки к зацепкам

* Строки `IOSurfaceSharedEventAddEventListener` в кернеле **нет** (скан всех 67 МБ: 0 совпадений).
  Класс называется `IOSurfaceSharedEventListener`; регистрация — sel40 `0x9c3df84`.
* Бит 5 байта `+0x3d2` в IOFence-путях — это **обход счётчика** (`tbnz #5` в `0x9c22f14`,
  `0x9c23068`, `0x9c26950`, `0x9c26aa0`, `0x9c271c0`) и геттер `0x9c22344` (`ubfx #5,#1`).
  В sel34 читается **бит 3**, не 5.
* Не разобрано: копирует ли `0x9c3692c` блок `+0x58` побайтно или хранит указатель —
  от этого зависит, остаётся ли в таблице владельца висячий указатель на маску.
* Не проверено: путь освобождения `IOSurfaceSharedEventNotificationPort` из `clientClose`
  (нет прямых `bl` к dtor'ам, только vtable), взаимные блокировки `+0x30`/`+0x60` при
  одновременном `signal` и `waitForValue`.
* Кто именно ставит бит `0x80000` в `IOSurfaceRoot+0x1a4` (какой ключ энтайтлмента) —
  строка не локализована; связь с `com.apple.private.iosurface*` предполагается, не доказана.

## 7. Инструменты

`work/sharedev/kc.py` — сегменты, VA↔файл (короткая форма `0x9c…` → `0xfffffff009c…`),
PAC-резолв `0xfffffff007004000+(q&0x0FFFFFFF)`, capstone 5.0.7 (все `adrp`/`b`/`bl` imm
маскируются `& 0xFFFFFFFFFFFFFFFF`).
`x.py` — поиск вызывающих по `bl`/`b` с знаковым расширением imm26.
`fn.py` — карта функций по `bti c` + компактная сводка.
Использованы также прямые сканы по маскам инструкций (`ldrb/ldr` с imm12 = 0x3d2/0x3d0,
`str` в `+0x138`), разбор `LC_DYLD_CHAINED_FIXUPS` не понадобился: таблицы селекторов и
vtable лежат в `__DATA_CONST` незанулёнными.
