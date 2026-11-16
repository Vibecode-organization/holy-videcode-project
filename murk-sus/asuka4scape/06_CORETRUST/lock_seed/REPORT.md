# IOSurface: lock / seed / mapping / purgeable — аудит 27.2 (24B115)

Цель: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`.
Классы (ipsw kernel cpp, точные размеры): `IOSurface` sizeof **0x3e0**, vtab `0x8067138`;
`IOSurfaceClient` sizeof **0x98**, vtab `0x8067358`; `IOSurfaceRoot` sizeof **0x4a0**, vtab `0x8067db0`.
Таблица селекторов `IOSurfaceRootUserClient`: `0x8068b90`, 60 записей stride 0x28
(`{pac(fn), u32 sIn, u32 strIn, u32 sOut, u32 strOut}`). Полный список собран скриптом
`sel.py`; lock = sel2 (`0x9c3b3ac`), unlock = sel3 (`0x9c3b58c`), setPurgeable = sel20
(`0x9c3d38c`), useCount++/-- = sel14/15, isInUse = sel23, `IOSurfaceClient::mapSurface`
вызывается не селектором, а из ctor'а клиента. Вторая (restricted) таблица `0x80694f0`
(`uc+0x127`) для sel1/2/3/14/15/20/23 содержит те же обработчики; отличается только замена
части селекторов (4/5/6/7/8/16/22/25/… ) на deny-заглушку `0x9c3a1dc` (`0xe00002e2`), поэтому
выводы по lock/seed/purgeable верны для обеих.

Метод: статический RE (Capstone, kernelcache + отдельный бинарь
`work/ios272/com.apple.iokit.IOSurface`, сверка строк/смещений), без запуска на устройстве.
Всё, что не доказано инструкциями, помечено **не подтверждено**.

## 0. Итог

Память под замапленным диапазоном **не освобождается** ни lock/unlock, ни purgeable:
`setPurgeable` только транслирует состояние в `IOMemoryDescriptor::setPurgeable` и не трогает
`surface->[0x30]`; `IOSurface::free` — единственное место, где MD обнуляется. UAF через
purgeable+маппинг **не подтверждён**.

Реальные находки — не memory corruption, а логические:

1. **Нет владельца у lock/unlock и purgeable.** Счётчики `+0x238/+0x23c` — просто числа;
   unlock проверяет только «счётчик != 0». Для **global** поверхности (флаг `+0x3d0 bit1`)
   root-lookup умеет пускать чужой task с логом `"Security: Process %s (%d) relying on
   global (insecure) IOSurface"` (`0x78a074b`), **но только если `iosurface_debug & 4`**
   (root `+0x1a4`; по коду дефолт `0x10` → в лог идёт `"IOSurface disallowing global
   lookups"`). На стоке, судя по дефолту, global-lookup выключен → finding условный.
2. **Маска options отсутствует.** lock проверяет только биты 0 (`ReadOnly`) и 1 (`AvoidSync`);
   user-client дополнительно бит 2 (`0x4`, недокументированный) — он создаёт IOFence /
   device-cache transition (`0x9c26fcc` → `0x9c27118`), ошибка commit'а (`0x9c41314`)
   игнорируется. Биты ≥3 молча игнорируются, `0xFFFFFFFF` = обычный write-lock.
3. **Маппинг всегда полный, без offset/size.** `mapSurface` зовёт
   `IOMemoryDescriptor::createMappingInTask(desc, task, opts, 0, 0)` — offset=0, length=0,
   т.е. весь descriptor (`fAllocSize`). Пользовательских offset/size в этом пути нет,
   `offset+size > alloc` недостижимо. IOMemoryMap кэшируется в `client+0x48`; повторный
   маппинг возвращает 1 без создания новой мапы. Unmap-ветка чистит только `client+0x50`
   (base VA), саму мапу не отпускает → после unmap повторный map отдаёт success с base=0
   (функциональный баг, не memory safety).

## 1. Модель полей (проверено дизасмом)

| Поле | Смысл | Доказательство |
|---|---|---|
| `IOSurface+0x30` | `IOMemoryDescriptor*` буфера | `0x9c22264` = `ldr x0,[x0,#0x30]`; обнуляется только в free `0x9c1fbdc`/dtor |
| `IOSurface+0x38` | указатель на сжатый/device-бэкенд; AvoidSync-гейт | `0x9c209fc` (`ldr x8`) |
| `IOSurface+0x50` | IOLock поверхости | lock/unlock `0x9c495b4/d4` по `[x0+0x50]` |
| `IOSurface+0x168` | `fClientAlignedOffset` | пишется `0x9c1daa8`; проверка `< page_size` `0x9c1dabc`→`0x9c1dee8` |
| `IOSurface+0x178` | PAC-указатель на client-shared блок | `autda` key `0xa39b`, `0x9c2a6b4` |
| shared `+0x0c` | **seed (u32)** | `IOSurface::getSeed 0x9c2a6b0` = `ldr w0,[x16,#0xc]` |
| shared `+0x10` | счётчик unlock/begin-access | `0x9c20f7c`, `0x9c257f4` |
| shared `+0x18` | 64-bit значение, `low+high` отдаёт sel16 | `0x9c233a0`; в kext не пишется (пишет внешний клиент/драйвер) |
| shared `+0x20` | второй счётчик, `orr 1; add 2` | `0x9c250a8`, `0x9c24b28` |
| `IOSurface+0x228` | текущее purgeable-состояние | `0x9c2164c/694/6a0` |
| `IOSurface+0x238` | счётчик read-lock | `0x9c20a40-5c` |
| `IOSurface+0x23c` | счётчик write-lock | `0x9c20a1c-38` |
| `IOSurface+0x270` / `+0x2b0` | lck_mtx-объекты (0x40) read/write sync | init/zero `0x9c49d44` в `0x9c20a24/48`; lock/unlock `0x9c495b4/d4` |
| `IOSurface+0x3d0` | 32-bit flags (последнее поле объекта) | см. таблицу флагов |
| `IOSurfaceClient+0x48` | закэшированный `IOMemoryMap*` | `0x9c2bcec`, `0x9c2bd3c` |
| `IOSurfaceClient+0x50` | base VA (userspace) | `0x9c2bdd4` |

Флаги `+0x3d0` (u32; `+0x3d1/+0x3d2/+0x3d3` — его байты):

| Бит | Значение | Где |
|---|---|---|
| 1 (0x2) | `IOSurfaceIsGlobal` | set `0x9c1e0f4` (`bfi #1`); root lookup `0x9c33660` |
| 2/3 (0xc) | «в использовании» (write access) | set `0x9c20ad8`, `0x9c257fc`; clear `0x9c23418` |
| 4/5 (0x10/0x20) | pending processor cache flush | set `0x9c20fd0`; clear `0x9c20a88-9c` |
| 9 (0x200, = `+0x3d1 bit1`) | isInUse (вероятно; пара sel22/23) | set `0x9c247d0`; getter `0x9c2a750` (sel23) |
| 15 (0x8000, `+0x3d1 bit7`) | purgeable-capable | гейт `setPurgeable` `0x9c21608` |
| 19 (0x80000) | `IOSurfaceIsPrivate` | set `0x9c1e120` (`bfi #0x13`); root lookup `0x9c33658` |
| 21 (0x200000) | отдаётся клиенту в data `+0x6d` | `0x9c2c2b0` |
| 22 (0x400000) | «не мапить в клиента» | `0x9c2bb4c` → mapSurface flag=1 |
| 24 (0x1000000, `+0x3d3 bit0`) | тоже skip client mapping | `0x9c2bb48` (`ubfx #0x18`) |
| 25 (0x2000000) | отдаётся в data `+0x6e` | `0x9c2c2c8` |
| 27 (0x8000000, `+0x3d3 bit3`) | гейт в `prepare` | `0x9c1eaa8` |

Примечание к вводной: `+0x3d8/+0x3e0/+0x3e8/+0x3f0` — это **IOSurfaceRoot** (sizeof 0x4a0),
а не IOSurface; у IOSurface объект кончается на `+0x3df`. Байт `+0x3d2` — это биты 16..23
того же слова: `bit5` (=u32 bit21) читается в IOFence/device-cache путях (`0x9c271c0`),
`bit7` (=u32 bit23) — в teardown `0x9c1fb90`; отдельного счётчика в `+0x3d2` нет.

## 2. Таблица аудита

| функция | проверки | вердикт |
|---|---|---|
| `lockWithOptions 0x9c209b8` (sel2 `0x9c3b3ac`) | size struct==0xc, outSize==0xc68; `AvoidSync` при `[surf+0x38]!=0` → `0xe00002cc`; счётчики `+0x238/+0x23c`; seed++ только при write; **маски options нет**; владелец не проверяется | OK по памяти; логика неполная |
| `unlockWithOptions 0x9c20f04` (sel3 `0x9c3b58c`) | outSize==4; счётчик==0 → `0xe00002c2`; decrement; seed отдаётся **без** ++ | OK, underflow закрыт |
| `getSeed 0x9c2a6b0` | `[shared+0xc]`, без блокировки | OK |
| seed в `IOSurfaceData` | `0x9c2c268`: `[out+0x68]=[shared+0xc]` | OK |
| `setPurgeable 0x9c215c4` (sel20) | state = arg&0xf, >3 → `0xe00002c2`; гейт `+0x3d1 bit7`; вызов `MD->setPurgeable(state\|arg&0x760, &old)`; пишет `+0x228`, флаги; **MD не освобождает** | OK по памяти |
| `isInUse 0x9c2a750` (sel23) | `+0x3d1 bit1`; соответствие публичному `IOSurfaceIsInUse` не подтверждено | OK |
| `setInUse 0x9c247d0` (sel22) | при arg!=0 и `flags&0xc` ставит bit9 | OK |
| `mapSurface 0x9c2bc3c` | `createMappingInTask(desc, task, opts, 0, 0)`; кэш `client+0x48`; on fail — log `createMappingInTask() failed`; base = mapAddr + `surf+0x168` | offset/size не контролируются юзером |
| `map_client_shared 0x9c41c14 → 0x9c41d4c` | две мапы (`0xd0` и `0x40`): `0x1001` (RO) / `1` (RW) по `[obj+0x40] bit0`; это shared-блок **владельца** (`uc+0x118`), не `[surf+0x178]` | seed-блок не мапится |
| `prepare/allocate 0x9c1e624` | client address ranges: VM-region lookup `0x9c2200c` (тип/границы/`kIOReturnVMError`), покрытие allocation `0x9c1ee1c`; `fAllocSize < requiredSize` → fail `0x9c1df10`; planeLimit `0x9c1ddc8` | границы валидируются |
| root lookup `0x9c33548` | id/owner; private → только owner; global → только при `root+0x1a4 bit2` (`iosurface_debug & 4`), иначе fail + лог `0x9c33840` | по умолчанию (0x10) global-lookup выключен |
| `IOSurface::free 0x9c1f830` / teardown `0x9c1fb48` | обнуляет `+0x30`, `+0x3c0`, `+0x28` | единственное место освобождения MD |

## 3. Топ-3

### #1. Cross-client unlock / purgeable на global-поверхности (условно: `iosurface_debug & 4`)

Условие включения (root init, `0x9c31e64-0x9c31eb8`):
```
0x9c31e64  add   x23, x19, #0x1a4          ; root->fDebugFlags
0x9c31e68  adrp/add x0, "iosurface_debug"
0x9c31e78  bl    getProperty
0x9c31e7c  cbz   w0, 0x9c31ea8             ; нет свойства -> ...
0x9c31e80  ldr   w8, [x23]
0x9c31e84  tbz   w8, #1, 0x9c31e98         ; bit1 -> pixel-size-casting log
0x9c31e98  tbz   w8, #2, 0x9c31eb0         ; bit2 = allow global lookups
0x9c31e9c  adrp/add x0, "IOSurface allowing global lookups (with warnings)\n"
0x9c31eb0  adrp/add x0, "IOSurface disallowing global lookups\n"
0x9c31ea8  mov   w8, #0x10                 ; дефолт, если свойства нет
0x9c31eac  str   w8, [x23]                 ; -> bit2 = 0, lookup запрещён
```
Дизасм (lock, счётчики и seed):
```
0x9c209f8  tbz   w20, #1, 0x9c20a18      ; AvoidSync — единственный «дорогой» флаг
0x9c209fc  ldr   x8, [x19, #0x38]        ; compressed/device?
0x9c20a00  cbz   x8, 0x9c20a18
0x9c20a08  bl    lck_mtx_unlock
0x9c20a0c  mov   w0, #0x2cc ; movk #0xe000  -> kIOReturnCannotLock
0x9c20a1c  ldr   w8, [x19, #0x23c]       ; writer count
0x9c20a34  add   w8, w8, #1
0x9c20a38  str   w8, [x19, #0x23c]
0x9c20a60  tst   w20, #1
0x9c20a64  cset  w3, eq                  ; is_write
0x9c20ac4  tbnz  w20, #0, 0x9c20ae0      ; read-only -> seed не трогаем
0x9c20ac8  ldr   w8, [x16, #0xc]         ; x16 = [surf+0x178] shared
0x9c20ad0  str   w8, [x16, #0xc]         ; seed++
0x9c20ae0  ldr   w22, [x16, #0xc]
0x9c20ae8  str   w22, [x21]              ; *seed_out
```
Дизасм (unlock): `0x9c20f48 ldr w8,[x19,#0x23c]; cbz -> 0x9c21084 (0xe00002c2)`,
`0x9c20f54 sub/str`, `0x9c21018 ldr w8,[shared+0xc]; str w8,[x21]` — только чтение seed.

Root-lookup:
```
0x9c33654  ldr   w8, [x19, #0x3d0]
0x9c33658  tbnz  w8, #0x13, 0x9c33750    ; private -> только owner
0x9c33660  tbnz  w8, #1, 0x9c336d4       ; global
0x9c336d4  tbnz  w9, #2, 0x9c3377c       ; w9 = root->fDebugFlags; bit2?
0x9c33840  adrp/add x3, "... relying on global (insecure) IOSurface"
0x9c33854  b     0x9c336a0               ; success
```
Последовательность (только при `iosurface_debug & 4`):
1. A: `IOSurfaceCreate({IOSurfaceIsGlobal:true, ...})` → ID.
2. B: `IOSurfaceLookup(ID)` (sel4) → global-ветка, лог «relying on global (insecure)».
3. B: `IOSurfaceUnlock(surf, A_options, &seed)` (sel3) — декремент **чужого** счётчика
   (write при `options=0`, read при `options=1`), возврат актуального seed.
4. B: `IOSurfaceSetPurgeable(surf, Volatile=1, &old)` (sel20) — только если у поверхности
   поднят bit15 (purgeable-capable); дальше `MD->setPurgeable`.
Эффект: межпроцессная порча данных/DoS — **если** отладочный флаг включён; иначе чужой task
до поверхности не допускается (owner/private/port). Memory corruption нет ни в каком случае.

### #2. Options без маски; бит 2 создаёт IOFence

sel2 wrapper (`0x9c3b3ac`):
```
0x9c3b488  and  w23, w21, #1
0x9c3b48c  tbz  w21, #2, 0x9c3b4d4
0x9c3b490  mov  w8, #2
0x9c3b494  sub  w1, w8, w23              ; 2 (write) или 1 (read)
0x9c3b498  mov  x0, x22
0x9c3b49c  mov  w2, #-1                  ; planeIndex = -1
0x9c3b4a0  bl   0x9c26fcc                ; IOFence create (0x9c27118)
0x9c3b4ac  mov  w1, #0
0x9c3b4b0  bl   0x9c41314                ; commit; return игнорируется
```
`0x9c27118` берёт глобальный IOFence-класс `0x806a150`, создаёт объект IOFence
(класс `0x9c414d0`), привязывает surface/direction/planeIndex; deadlock-детектор умеет
`SIGKILL`'ить процесс (`0x9c1a044-0x9c1a0d4`, строки `process %s (%d) caught causing IOFence
deadlock!` / `Killed process ...`). Что именно проверяет AvoidSync и что делает бит 2 —
не документировано; ошибка commit'а не проверяется.
Последовательность: `IOSurfaceLock(s, 0x4|opts, &seed)` в цикле → создание/commit IOFence на
каждый вызов; `opts=0xFFFFFFFE` = write-lock + AvoidSync + бит2, остальные биты игнор.
Эффект: недокументированный kernel-объект на каждый lock (рост памяти), потенциальный
IOFence-deadlock/убийство процесса — **не подтверждено** (нужен рантайм).

### #3. Маппинг: полный descriptor, кэш, «unmap» без release

```
0x9c2bcec  ldr   x8, [x19, #0x48]        ; IOMemoryMap уже есть?
0x9c2bcf0  cbnz  x8, 0x9c2bdd8           ; -> mov w0,#1; return
0x9c2bcf4  bl    0x9c22264               ; desc = surface->[0x30]
0x9c2bcfc  mov   x1, x22                 ; task
0x9c2bd00  mov   x2, #0                  ; atAddress = anywhere
0x9c2bd04  mov   x3, x21                 ; options (cache mode)
0x9c2bd08  mov   x4, #0                  ; offset = 0
0x9c2bd0c  mov   x5, #0                  ; length = 0 -> весь MD
0x9c2bd10  bl    IOMemoryDescriptor::createMappingInTask
0x9c2bd3c  str   x21, [x19, #0x48]
0x9c2bd54  ldr   x8, [x16, #0x78]!       ; IOMemoryMap::getAddress
0x9c2bdcc  bl    0x9c22410               ; [surface+0x168] (fClientAlignedOffset)
0x9c2bdd0  add   x8, x0, x21
0x9c2bdd4  str   x8, [x19, #0x50]        ; base VA
```
Unmap-ветка (флаг `w3!=0`, `0x9c2bc98`): `str xzr,[x19,#0x50]` и return 1 — `[x19+0x48]`
не отпускается и не обнуляется. Значит повторный вызов после unmap уходит в early-return
(`w0=1`), а base остаётся 0. Все 4 сайта `createMappingInTask` в kext (`0x9c2bd10`,
`0x9c3a424`, `0x9c41dd4`, `0x9c433a8`) передают offset=x4=0, length=x5=0.
`fClientAlignedOffset` валидируется `< page_size` (`0x9c1dabc`), plane coverage —
`fAllocSize >= planeLimit` (`0x9c1ddc8`), `fAllocSize >= requiredSize` (`0x9c1df10`).
Итог: замапить `offset+size > fAllocSize` через этот интерфейс нельзя.

## 4. Ответы по пунктам задания

1. **lock/unlock.** Реализации: `0x9c209b8` / `0x9c20f04` (обёртки sel2/sel3 —
   `0x9c3b3ac`/`0x9c3b58c`). «Чужой» не проверяется вообще: ни task, ни thread, ни id
   владельца; **но** чужой клиент получает entry только через root lookup, а тот для
   не-owner task требует `iosurface_debug & 4` (дефолт 0x10), либо mach-порт поверхности
   (легитимный шаринг). Неизвестные биты options игнорируются (проверяются 0/1, в обёртке ещё
   2). Двойной lock: счётчик +2, seed +2 (для write), ошибки нет. Unlock без lock:
   `0xe00002c2` (kIOReturnBadArgument), счётчик не уходит в минус. `planeIndex` из struct
   (12 байт: id, options, planeIndex) **не читается** — plane-lock'а нет, лок всегда на всю
   поверхность. `+0x3d0` — не счётчик, а 32-bit flags (см. таблицу); счётчики — `+0x238`/`+0x23c`,
   `+0x3d2` — только `bit7` в teardown `0x9c1fb48`.
2. **seed.** `u32` в client-shared блоке `[surface+0x178]+0xc`; `getSeed 0x9c2a6b0` и копия в
   `IOSurfaceData+0x68` (`0x9c2c268`) читают его напрямую. Меняется на **write-lock**
   (`options bit0 == 0`), `0x9c20ac8-ad0`; unlock отдаёт текущее значение без инкремента
   (вопреки комментарию в заголовке Apple). Никаких индексов/ключей на seed нет: все чтения —
   возврат пользователю/ktrace. Мапится ли `[surface+0x178]` в task — статикой не подтверждено;
   даже при записи ядро от этого значения ничего не решает.
3. **Маппинг.** `IOSurfaceMap` как отдельного селектора в 27.2 нет; поверхность мапится в task
   при создании `IOSurfaceClient` (`0x9c2b8c8` → `0x9c2bc3c`), всегда весь
   `IOMemoryDescriptor` (`fAllocSize`), offset=0/length=0. Сверка с `fAllocSize` происходит
   при создании (planeLimit/requiredSize) и при client-address-ranges (VM-region + coverage).
   Повторный маппинг: early-return по `client+0x48`; отдельного «того же диапазона» нет.
   Слоты vtable `+0x78/+0xb0/+0xe8` на IOSurface в этом билде — **не маппинг**:
   `+0x78` = release/notify→free (`0x9c1f1b4`), `+0xb0` = `mov w0,#0; ret` (`0xa894b08`),
   `+0xe8` = пустой `ret` (`0xa894ad8`). Маппинг живёт в `IOSurfaceClient`.
4. **Purgeable.** `setPurgeable 0x9c215c4` (sel20): states 0..3, old state возвращается
   (`out+0x3c`), при невалидном — `0xe00002c2`; вызывает `MD->setPurgeable`
   (`[surface+0x30] vt+0x80`), пишет `[surface+0x228]` и флаги. Память не освобождается:
   `[surface+0x30]` обнуляется только в `free`/teardown. Пользовательский маппинг держит
   IOMemoryMap/object, поэтому purge страниц не даёт UAF — только потерю данных.
   Отдельного `IOSurfaceGetPurgeable` нет: старое состояние отдаёт сам sel20.

## 5. Не подтверждено

- **`iosurface_debug` в рантайме**: статически виден только дефолт `0x10` (global-lookup
  выключен); если device tree/бут-арг ставит bit2 (`0x4`), cross-client сценарий #1 оживает.
  Значение на конкретном устройстве не проверялось.
- **volatile + device memory**: `IOSurfaceDeviceMemoryRegion`/`IOSurfaceDeviceCache`
  (`0x9c2ddc8`, `0x9c30478`) при volatile могут пересоздавать device-регион; статически
  доказать/опровергнуть UAF в GPU-маппингах не удалось (нужен рантайм с IOGPU/AGX).
- **RW client-shared**: `map_client_shared` мапит блоки владельца (`uc+0x118`) в task; вторая мапа
  идёт с `kIOMapAnywhere` (1) вместо `0x1001` при `[obj+0x40] bit0 == 0`. Что именно лежит в
  этом блоке и пересекается ли он с `[surface+0x178]+0xc` (seed) — не подтверждено. Если да,
  клиент может писать seed/useCount, но ядро это только перечитывает; control flow не зависит.
- **IOFence kill**: может ли клиент через `lock(options|4)` на чужой global-поверхности
  спровоцировать kill **другого** процесса — не подтверждено (нужен трейс `0x9c1a000`).
- **client-address-ranges**: `0x9c2200c` валидирует VM-регионы и покрытие, но точная семантика
  флагов `tbnz #2`/`#1` и поведение при ranges **больше** allocation статически не доказаны;
  путь доступен только при создании (не при маппинге).
- Точный смысл shared `+0x18`/`+0x20` (в kext не пишутся; вероятно, поля для внешних
  драйверов) — не подтверждено.

## 6. Файлы

- `kc2.py` — сегменты/VA↔file/capstone; `kext.py` — xref строк по отдельному kext;
  `sel.py` — обе таблицы селекторов (`selectors.tsv`); `lock_unlock_map.txt` — листинги
  lock/unlock/mapSurface/setPurgeable/getSeed/rootLookup.
- Сверка 27.0/27.2: vtable `+0x78/+0xb0/+0xe8` в 27.0 тоже ведут на стабы, не на маппинг.
