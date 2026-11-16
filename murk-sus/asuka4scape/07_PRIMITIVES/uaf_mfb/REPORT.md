# UAF / гонки в IOMobileFramebufferUserClient — iOS 27.2 (24B115)

Файл: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`
(мини-fileset Mach-O, `cffaedfe`; VA = `0xfffffff000000000 | lo`, file off = `va - 0xfffffff007004000`).

Инструмент: `macho.py` (capstone 5.0.7, ручной разбор adrp/add/ldr/braa, PAC-резолв по
`0xfffffff007004000 + (q & 0x0FFFFFFF)`). Для контроля собран второй загрузчик 27.0_24A437
и сделан побайтовый diff нормализованного дизасма (`diff27.py`).

## 0. Карта объекта

* vtable `IOMobileFramebufferUserClient` = `0x8023300` (externalMethod по `+0x6a8`).
* `start` (`+0x388`) = `0x9aa161c`; `stop` (`+0x390`) = `0x9aa17b8`; `free` (`+0x148`) = `0x9aa156c`.
* `initWithTask` = `0x9aa145c`: `[uc+0xe8]=task`, `[uc+0xf0]=type`, `[uc+0xfc]=0`, `[uc+0x104/0x108]` из task.
* `start`:
  ```
  9aa1658  adrp x8, 0x8024000
  9aa165c  add  x8, x8, #0xae8
  9aa1660  ldr  x1, [x8]              ; OSMetaClass IOMobileFramebuffer
  9aa1664  mov  x0, x20               ; provider
  9aa1668  bl   0x9abd3dc            ; safeMetaCast(provider, meta)
  9aa166c  str  x0, [x19, #0xd8]      ; uc->fb — БЕЗ retain
  ...
  9aa17a4  mov  w0, #1
  9aa17a8  strb w0, [x19, #0xe0]      ; "started/drain armed"
  ```
* `stop 0x9aa17b8` (дренаж с `0x9aa17d0`):
  ```
  9aa17e4  ldrb w8, [x20, #0xe0]
  9aa17e8  tbz  w8, #0, 0x9aa19b8     ; не стартовали — мимо
  9aa17ec  add  x0, x20, #0xfc
  9aa17f0  bl   0x9abd1fc            ; OSDecrementAtomic(&uc->fc), возвращает СТАРОЕ
  9aa17f4  cmp  w0, #1
  9aa17f8  b.lt 0x9aa1844            ; old < 1 -> дренаж пропущен
  9aa17fc  str  xzr, [sp, #0x18]
  9aa1800  ldr  x0, [x20, #0xd8]      ; fb
  ...                                 ; fb->vtable[0x780]
  9aa1824  mov  w1, #0xb
  9aa1828  mov  w3, #1
  9aa182c  blraa x8                  ; fb->vt[0x780](fb, 0xb, &zero, 1)
  9aa1834  add  x0, x20, #0xfc
  9aa1838  bl   0x9abd1fc            ; ещё dec
  9aa183c  cmp  w0, #0
  9aa1840  b.gt 0x9aa17fc            ; пока old > 0
  9aa1844  ldr  w8, [x20, #0xf4]     ; затем tear-down
  ...
  9aa187c  fb->vt[0x620](fb, uc)     ; removeUserClient (0x9a7e5c8)
  9aa18d0  цикл i=0..11:
  9aa18f8    fb->vt[0x6a0](fb, i, uc+0x110+i*0xb0+8)
  9aa1908    release(entry[0]); entry[0]=0
  9aa1920    if i==3: release(entry[0x98]); release(entry[0xa0])
  9aa197c  strb wzr, [x20, #0xe0]
  9aa1980  if [uc+0xf0]==2: fb->vt[0x560](fb, uc)
  9aa19b8  tail-call super::stop
  ```
* `free 0x9aa156c`: освобождает только `[uc+0x3b8]` и `[uc+0x3c0]`, `uc->fb` (`+0xd8`) **не трогает**.

## 1. Диспетчеризация и таблица

`externalMethod 0x9aa33b8`:
```
ldr x0,[x0,#0xd8]                  ; fb
ldr x16,[x0]; autda
add x16,x16,#0x5c0
ldr x8,[x16]; blraa                ; fb->vt[0x5c0](fb, sel, args, dispatch)
cbz w0 -> 0x9aa3418
...                                ; иначе early ret
0x9aa3418: adrp x3,0x8023000; add x3,#0xad0   ; таблица, 101 запись (w4=0x65)
b 0x9abd40c -> validator 0xa9b0888
```
`fb->vt[0x5c0]` = `0x9a778d8`: ждёт флаг `fb+0x5860` под локом `fb+0x4d38`
(«сервис готов»), **состояние uc не проверяет**.

`validator 0xa9b0888` читает запись `table + sel*0x28`:
`+0: fn`, `+8: scalar_in(u32)`, `+0xc: struct_in(u32)`, `+0x10: scalar_out`, `+0x14: struct_out`,
`+0x18: flags`. Значение `-1` = «не проверять». Для структуры с descriptor'ом (`args+0x40`)
делает `descriptor->vt[0xb0]()` (getLength) и сравнивает; иначе сравнивает `args+0x38`.

Фактические записи (27.2 и 27.0 идентичны):

| sel | fn | scalar_in | struct_in | scalar_out | struct_out |
|---|---|---|---|---|---|
| 0x44 | `0x9aa42dc` | 1 | **-1** | 0 | 0 |
| 0x4e | `0x9aa3d3c` | **-1** | **-1** | **-1** | **-1** |
| 0x4f | `0x9aa3e34` | **-1** | **-1** | **-1** | **-1** |

То есть у 0x44 не проверяется размер structure input, у 0x4e/0x4f — вообще ничего.

## 2. Таблица «операция | что защищено | вердикт»

| # | Операция | Что защищено | Вердикт |
|---|---|---|---|
| 1 | `externalMethod` pre-gate `fb->vt[0x5c0]` | ждёт `fb+0x5860`; uc не проверяет | ⚠️ от close не защищает |
| 2 | validator `0xa9b0888` | scalar counts; `struct_in` только если != -1 | ✅ для 0x44/0x4e/0x4f проверок нет |
| 3 | sel 0x44 `0x9aa42dc` data path | `count = structureInputSize>>3`; `vt[0x780]` сам режет count: generic `vt[0xa28]` требует `count<=4`, op 0xb/0x14/0x1c — `count==1` | ✅ OOB по count нет |
| 4 | sel 0x44 op 0xb: `+0xfc` | `OSIncrementAtomic/OSDecrementAtomic` (`ldadd`), **лок отсутствует** | ⚠️ гонка с drain |
| 5 | `stop` drain `0x9aa17d0` | dec-loop по `+0xfc`, вызов `vt[0x780](fb,0xb,&stack,1)` | ⚠️ нет лока, нет re-check `+0xe0` |
| 6 | `stop` tear-down `0x9aa1844..0x9aa1978` | 12 записей `uc+0x110` + `vt[0x620]` removeUserClient | ⚠️ освобождает без синхронизации с handler'ами |
| 7 | `free 0x9aa156c` | освобождает `0x3b8/0x3c0`; `+0xd8` не чистит | ⚠️ висячий fb, если провайдер умер |
| 8 | sel 0x4e `0x9aa3d3c` → `vt[0x720]` | entitlement-check по task (`0x9aa19f4`); `structureInput` читается синхронно | ✅ буфер не сохраняется |
| 9 | sel 0x4e → `0x9a73db8` → `IOMemoryDescriptor::withAddress` | адрес/длина берутся из user-структуры, но оборачиваются в descriptor с task | ✅ по дизайну (проверка диапазона — в withAddress) |
| 10 | sel 0x4f `0x9aa3e34` → `vt[0x728]` | **нет entitlement-check**; id 0xbc: len>=0x104, count=[fb+0x370]<=0x40; id 0x87: `vt[0x890]`; прочее: len<=0x1000 | ⚠️ доступ без проверки; UAF не подтверждён |
| 11 | `vt[0x890]` → `[fb+0x5e90]->vt[0x670]` | в этой сборке терминал = `0x8e6a644`, возвращает `0xe0002c7` (unsupported) | ❓ async-retention указателя не подтверждён |
| 12 | два потока: sel 0x44/0x4e/0x4f + `IOServiceClose` | сериализации нет; handler'ы не читают `+0xe0` | ⚠️ окно гонки есть, конкретный freed-object не доказан |
| 13 | sel 0x44 op 0xb без structureInput | `0x9aa4354: ldr x8,[args+0x30]; ldr x8,[x8]` — **NULL-чек отсутствует** (у 0x4e он есть) | ❌ NULL-deref → panic (DoS); на устройстве не подтверждено |

## 3. Top-3

### Top-1. `IOServiceClose`/`stop` против `externalMethod` — гонка без сериализации

Что подтверждено дизасмом:

1. `stop` — единственное место, читающее `uc+0xe0` (`0x9aa17e4`); handler'ы `0x9aa42dc`,
   `0x9aa3d3c`, `0x9aa3e34` этот флаг не проверяют вообще.
2. `stop` релизит объекты в 12 записях `uc+0x110` и снимает клиента с fb (`vt[0x620]`), не беря
   никакого лока, который берут handler'ы (в них локов нет вовсе).
3. `externalMethod` после pre-gate сразу читает `[uc+0xd8]`; `+0xd8` не обнуляется ни в
   `stop`, ни в `free`.
4. `+0xfc` меняется только атомарно; вокруг проверки и вызова `vt[0x780]` лока нет.

Два потока:

```
T1: IOConnectCallMethod(conn, 0x44, in={u64 1}, 8)
    externalMethod 0x9aa33b8
    handler 0x9aa42dc: w19=0xb, w20=1
      x8=[args+0x30]; x8=[x8] (=1)
      inc(uc+0xfc)                       ; 0xa8945fc, ldadd
      fb=[uc+0xd8]
      fb->vt[0x780](fb,0xb,args+0x30,1)  ; 0x9a75590 -> 0x9a932e4(fb+0x438,1,0)

T2: IOServiceClose(conn)
    stop 0x9aa17b8
      [uc+0xe0]&1
      x = dec(uc+0xfc); if (x<1) skip drain
      while (x>0) { fb->vt[0x780](fb,0xb,&zero,1); x=dec(uc+0xfc); }
      fb->vt[0x6d8](fb,0)               ; если uc+0xf4
      fb->vt[0x620](fb,uc)              ; removeUserClient 0x9a7e5c8
      for i in 0..11: vt[0x6a0](fb,i,uc+0x110+i*0xb0+8); release(entry[0])
      [uc+0xe0]=0
      fb->vt[0x560](fb,uc)              ; если type==2
```

Окна:
* T2 сделал первый `dec`, увидел `<1` и ушёл из дренажа; T1 в этот момент делает `inc` и
  включает gain-map уже после tear-down. Состояние «включено» остаётся у умирающего клиента.
* T1 и T2 одновременно дергают `vt[0x780]` op 0xb — счётчик уходит в произвольное значение
  (в т.ч. `-1`), количество disable-вызовов не соответствует числу enable.
* T2 релизит объекты в записях `uc+0x110`, но ни один из трёх handler'ов их не использует,
  поэтому **UAF именно этих объектов не подтверждён**.

Вердикт: **гонка подтверждена структурно; memory-safety последствие — не подтверждено**
(нужен рантайм: KASAN/paniclog, либо подтверждение, что `0x9a932e4`/`0x9a9311c` держат
указатели на ресурсы, освобождаемые в `stop`).

### Top-2. `uc->fb` (`+0xd8`): заимствованный указатель, который нигде не retain/release

* `start` кладёт результат `safeMetaCast(provider, meta)` в `+0xd8` (`0x9aa166c`) — без retain.
* `stop` и `free` `+0xd8` не освобождают и не обнуляют; `free` чистит только `0x3b8/0x3c0`.
* Все handler'ы и pre-gate безусловно разыменовывают `[uc+0xd8]` (`0x9aa33dc`, `0x9aa4370`,
  `0x9aa3db4`, `0x9aa3e70`).

Если провайдер (`IOMobileFramebuffer`) умирает/переинициализируется, а user client ещё жив,
любой селектор идёт в освобождённую память. Штатный IOKit-порядок (terminate провайдера →
stop клиента → free клиента) это, вероятно, закрывает, но в самом классе никакой страховки
нет: `+0xd8` не проверяется на `NULL`/`isInactive`, а `stop` не выставляет состояние,
которое увидел бы `externalMethod`.
Вердикт: **висячий путь есть; достижимость — не подтверждено** (нужен сценарий отключения
дисплея/провайдера одновременно с открытым клиентом).

### Top-3. sel 0x4f: `(structureOutput, size)` уходит в DCP без проверки прав и без проверки размера

* Запись таблицы 0x4f: все четыре поля `-1` → validator не проверяет ни scalar, ни structure.
* Handler `0x9aa3e34` требует только `[args+0x58]!=0` и `scalarInputCount>=2`; entitlement-check
  (`0x9aa19f4`), который есть в 0x4e, здесь **отсутствует**.
* Далее `fb->vt[0x728](fb, [uc+0xe8], scalar0, scalar1, extra, n, args+0x58, args+0x60)`:
  ```
  cmp w2,#0xbc -> 0x9a7460c: len>=0x104; memset 0x100; [ptr]=count; copy count*4
                              (count=[fb+0x370]<=0x40, добавление в массив: проверка count<=0x3f в 0x9a763b0)
  cmp w2,#0x87 -> fb->vt[0x890](fb, ptr, scalar1, len)
                  0x8ea4f58 -> [fb+0x5e90]->vt[0x670]
                  в 27.2 терминал = 0x8e6a644 (mov w0,#0xe0002c7; ret) — unsupported
  иначе        -> fb->vt[0x9f0](fb,...,ptr,len), len<=0x1000 (0x9a87e18)
  ```
* `structureOutput` — это буфер MIG/OOL, живущий только до возврата из syscall. Если
  терминальный метод `vt[0x670]` на реальном железе не заглушка и сохраняет указатель для
  асинхронного DCP-ответа — это UAF. В данной сборке заглушка, поэтому **retention не
  подтверждён**.
* Отдельно: отсутствие entitlement-check в 0x4f — это дыра доступа (sandboxed app может
  звать output/DCP-путь), но не UAF.

## 4. Что ещё проверено

* `sel 0x44` op 0xb (gain-map): `vt[0x780]` `0x9a75590` читает только `[ptr]` (8 байт) при
  `count==1`; внутри `0x9a932e4` → `0x9a9311c` берётся мьютекс `[obj+0x80]`. Утечки указателя нет.
  Но до этого `0x9aa4354` делает `ldr x8,[args+0x30]; ldr x8,[x8]` без проверки на NULL:
  `opcode=0xb` + вызов без structureInput → ядро читает адрес 0 (DoS; подтверждается только
  тем, что MIG при size=0 может отдать NULL — на устройстве не проверено).
* `sel 0x44` generic: `0x9a884a8` копирует `min(count,4)` u64 на стек и зовёт `vt[0x8b0]`;
  `count>=5` → `kIOReturnBadArgument`. OOB нет.
* `sel 0x4e`: `0x9a73db8` ищет id в таблице `0x8027050` (id<0xbd, 16-байтные записи), проверяет
  `len >= max(hdr+8,hdr2+4)`, затем `0x9a9a350` → `0x9a9da24` → `0x9a97ae84`
  (`IOMemoryDescriptor::withAddress(addr,len,opts,task)`); исходный `structureInput` после
  возврата не нужен. `len` берётся из `args+0x38`, буфер MIG имеет ровно этот размер.
* `sel 0x4f` id 0xbc: запись в output ограничена `4+4*[fb+0x370]`, а `[fb+0x370]` не может
  превысить 0x40 (проверка при добавлении в `0x9a763b0`: `count<=0x3f`), т.е. запись ровно 0x104 —
  совпадает с проверенным минимумом.
* Diff 27.0 → 27.2: `externalMethod`, `sel 0x44`, `sel 0x4e`, `sel 0x4f` **идентичны** с точностью
  до адресов строк/таблицы. Это не «фикс 27.2», поведение есть и в 27.0.

## 5. Итог

* Подтверждённых UAF с конкретным освобождённым объектом в этой сборке нет.
* Есть три структурных дефекта: (1) отсутствие сериализации close/stop с `externalMethod`
  и отсутствие проверки состояния uc в handler'ах; (2) заимствованный `+0xd8` без
  retain/clear; (3) полное отсутствие валидации и entitlement-check у sel 0x4f.
* Для превращения (1) в UAF нужно доказать, что `stop` освобождает объект, который
  handler трогает после `0x9aa17d0`; статически такого объекта не видно — handler'ы работают
  только с `fb` и `task`, а `fb` остаётся жив.
* Приоритет для динамики: два потока `IOConnectCallMethod(0x44,{1},8)` vs `IOServiceClose`
  в цикле, KASAN, смотреть `0x9a932e4/0x9a9311c` и `0x9aa17d0`; параллельно — `0x4f`
  с `structureOutputSize` 0x104/0x1000 и id 0x87/0xbc.
