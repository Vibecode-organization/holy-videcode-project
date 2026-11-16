# IOSurfaceRootUserClient — точный формат вызовов селекторов (27.2, 24B115)

Файл: `kexts/iosurface/27.2/com.apple.iokit.IOSurface` (Mach-O, фрагмент kernelcache,
VM-адреса сохранены, kernel base для chained fixup = `0xfffffff007004000`).

---

## 0. Как читать chained-указатели в этом файле

В файле нет LC_DYLD_CHAINED_FIXUPS; указатели лежат в «kernelcache» кодировке:

```
resolved = 0xfffffff007004000 + (raw & 0xffffffff)
```

Проверка: `0x8030705d02c361ec` → `0xfffffff009c3a1ec` (это `bti c` в `__TEXT_EXEC`).
Сегменты файла:

| Сегмент | vmaddr | размер | file off |
|---|---|---|---|
| `__TEXT` | `0xfffffff00789a030` | `0x8000` | 0 |
| `__TEXT_EXEC` | `0xfffffff009c14f20` | `0x38000` | `0x8000` |
| `__DATA` | `0xfffffff00af47f98` | `0x4000` | `0x40000` |
| `__DATA_CONST` | `0xfffffff008066558` | `0x8000` | `0x44000` |
| `__LINKEDIT` | `0xfffffff00afb8000` | `0x4000` | `0x4c000` |

---

## 1. Главное: реальная таблица — 60 записей IOExternalMethodDispatch2022

`FUN_fffffff009c3ee10` (адрес в `__TEXT_EXEC`, 48 байт) — это, судя по коду,
`IOSurfaceRootUserClient::externalMethod` в стиле **IOUserClient2022**:

```asm
fffffff009c3ee10  bti
fffffff009c3ee14  adrp     x8, 0xfffffff008068000
fffffff009c3ee18  add      x8, x8, #0xb90          ; sMethods (обычная)
fffffff009c3ee1c  ldrb     w9, [x0, #0x127]        ; client+0x127 = gpu-restricted
fffffff009c3ee20  adrp     x10, 0xfffffff008069000
fffffff009c3ee24  add      x10, x10, #0x4f0        ; sMethodsGPU
fffffff009c3ee28  tst      w9, #0x1
fffffff009c3ee2c  csel     x3, x10, x8, ne         ; x3 = таблица методов
fffffff009c3ee30  mov      w4, #0x3c               ; 60 методов
fffffff009c3ee34  mov      x5, x0                  ; target = this
fffffff009c3ee38  mov      x6, #0x0                ; reference = NULL
fffffff009c3ee3c  b        fffffff009c498f4        ; IOUserClient2022::dispatchExternalMethod
```

Сигнатура `dispatchExternalMethod(selector, args, dispatch, count, target, reference)`:
x0=this, x1=selector, x2=args, x3=dispatch, x4=count, x5=target, x6=reference.

Структура записи (`IOExternalMethodDispatch2022`, 0x28 байт):

| off | поле |
|---|---|
| 0x00 | `IOExternalMethodAction function` |
| 0x08 | `uint32 checkScalarInputCount` |
| 0x0c | `uint32 checkStructureInputSize` |
| 0x10 | `uint32 checkScalarOutputCount` |
| 0x14 | `uint32 checkStructureOutputSize` |
| 0x18 | `uint8 allowAsync` |
| 0x20 | `const char *checkEntitlement` |

`0xffffffff` в полях размера = `kIOExternalMethodArgumentsUnspecified`
(размер не проверяется, структура переменной длины).

Во **всех 60 записях обеих таблиц** поле `checkEntitlement` (0x20) = NULL —
по-селекторных проверок entitlement нет; единственное отличие gpu-таблицы —
подмена обработчиков 4–8 на `0x9c3a1dc` (возврат `0xe00002e2`).

### Таблица A: `sMethods` @ `0xfffffff008068b90` (60 записей)

| sel | handler | scalIn | structIn | scalOut | structOut | async |
|---|---|---|---|---|---|---|
| 0 | `0x9c3888c` | 1 | var | 0 | 0xc68 | 0 |
| 1 | `0x9c38a5c` | 1 | 0 | 0 | 0 | 0 |
| 2 | `0x9c38a6c` | 0 | 0xc | 0 | 0xc68 | 0 |
| 3 | `0x9c38a88` | 0 | 0xc | 0 | 4 | 0 |
| 4 | `0x9c38aa4` | 1 | 0 | 0 | 0xc68 | 0 |
| 5 | `0x9c38ab8` | 2 | 0 | 0 | 0 | 0 |
| 6 | `0x9c38acc` | 0 | 0x20 | 0 | 0xc68 | 0 |
| 7 | `0x9c38adc` | 2 | 0 | 0 | 0xc68 | 0 |
| 8 | `0x9c38af4` | 1 | 0 | 1 | 0 | 0 |
| 9 | `0x9c38b2c` | 0 | var | 0 | 4 | 0 |
| 10 | `0x9c38c44` | 0 | var | 0 | var | 0 |
| 11 | `0x9c38e54` | 0 | var | 0 | 4 | 0 |
| 12 | `0x9c38f6c` | 3 | 0 | 0 | 0 | 0 |
| 13 | `0x9c38f84` | 0 | 0 | 0 | 0x28 | 0 |
| 14 | `0x9c38fcc` | 2 | 0 | 0 | 0 | 0 |
| 15 | `0x9c38fe0` | 2 | 0 | 0 | 0 | 0 |
| 16 | `0x9c38ff4` | 1 | 0 | 1 | 0 | 0 |
| 17 | `0x9c3906c` | 0 | 0x18 | 0 | 0 | 1 |
| 18 | `0x9c39094` | 0 | 0x18 | 0 | 0 | 0 |
| 19 | `0x9c390ac` | 0 | var | 0 | 0 | 0 |
| 20 | `0x9c39128` | 2 | 0 | 1 | 0 | 0 |
| 21 | `0x9c391a4` | 4 | 0 | 0 | 0 | 0 |
| 22 | `0x9c3922c` | 2 | 0 | 0 | 0 | 0 |
| 23 | `0x9c39248` | 1 | 0 | 1 | 0 | 0 |
| 24 | `0x9c392c0` | 0 | var | 0 | 0 | 0 |
| 25 | `0x9c393d0` | 1 | 0 | 1 | 0 | 0 |
| 26 | `0x9c39448` | 0 | var | 0 | var | 0 |
| 27 | `0x9c39654` | 0 | 0xa0 | 0 | 0 | 0 |
| 28 | `0x9c39660` | 1 | 0 | 0 | 0xa0 | 0 |
| 29 | `0x9c3967c` | 2 | 0 | 0 | 0 | 0 |
| 30 | `0x9c3968c` | 1 | 0 | 0 | var | 0 |
| 31 | `0x9c39748` | 3 | 0 | 0 | 0 | 0 |
| 32 | `0x9c39760` | 0 | 0 | 1 | 0 | 0 |
| 33 | `0x9c397c4` | 3 | 0 | 0 | 0 | 0 |
| 34 | `0x9c397d8` | 1 | 0 | 0 | 0xc68 | 0 |
| 35 | `0x9c397ec` | 2 | 0 | 1 | 0 | 0 |
| 36 | `0x9c39868` | 1 | 0 | 2 | 0 | 0 |
| 37 | `0x9c398f0` | 2 | 0 | 0 | 0 | 0 |
| 38 | `0x9c39904` | 1 | 0 | 4 | 0 | 0 |
| 39 | `0x9c39924` | 5 | 0 | 0 | 0 | 0 |
| 40 | `0x9c3993c` | 0 | 0 | 0 | 0 | 1 |
| 41 | `0x9c39958` | 1 | 0 | 0 | 0 | 0 |
| 42 | `0x9c39968` | 4 | 0 | 0 | 0 | 0 |
| 43 | `0x9c39984` | 4 | 0 | 0 | 0 | 0 |
| 44 | `0x9c3999c` | 4 | 0 | 0 | 0 | 0 |
| 45 | `0x9c39a64` | 3 | 0 | 0 | 0 | 0 |
| 46 | `0x9c39a78` | 0 | var | 2 | 0 | 0 |
| 47 | `0x9c39bdc` | 1 | var | 0 | 0 | 0 |
| 48 | `0x9c39cf4` | 1 | var | 0 | 0 | 0 |
| 49 | `0x9c39e0c` | 1 | 0 | 0 | var | 0 |
| 50 | `0x9c39eb8` | 2 | var | 0 | 0 | 0 |
| 51 | `0x9c39eec` | 2 | 0 | 2 | var | 0 |
| 52 | `0x9c39f28` | 1 | 0 | 0 | 0 | 0 |
| 53 | `0x9c39f4c` | 1 | 0 | 0 | 0 | 0 |
| 54 | `0x9c39f5c` | 0 | var | 0 | 0 | 0 |
| 55 | `0x9c3a06c` | 1 | 0 | 1 | 0 | 0 |
| 56 | `0x9c3a0f4` | 2 | 0 | 0 | 0 | 0 |
| 57 | `0x9c3a108` | 4 | 0 | 0 | 0 | 0 |
| 58 | `0x9c3a128` | 5 | 0 | 3 | 0 | 0 |
| 59 | `0x9c3a1cc` | 1 | 0 | 0 | 0 | 0 |

`var` = `0xffffffff` (`kIOExternalMethodArgumentsUnspecified`).

### Таблица B: `sMethodsGPU` @ `0xfffffff0080694f0` (60 записей)

Отличается от A только тем, что селекторы
**4,5,6,7,8,16,17,18,19,21,22,24,25,26,28,29,30,33,43,46,47,48,49**
указывают на `0x9c3a1dc` вместо реального обработчика. Все прочие поля (counts/sizes)
совпадают с A. Это и есть «com.apple.private.gpu-restricted»-ветка
(`client+0x127 & 1`, см. `FUN_fffffff009c3ee10`).

---

## 2. Почему скан из отчёта 27.2 давал 0xe00002c2 на всём

`probe/KRWProbe/main.m::scan_selectors` всегда передавал
`scalarInputCount = 1` и `scalarOutputCount = 8` (стр. 343–349).
Для селекторов, где таблица требует `si=0` (2,3,6,9,10,11,13,17,18,19,24,26,27,32,40,46,54),
это несовпадение → `kIOReturnBadArgument` (0xe00002c2) ещё до вызова обработчика.
То же для `so` (например, sel 8 требует ровно 1 скаляр на выход, а не 8).

---

## 3. Цепочка вызова подтверждена по коду

`0x9c3ee10` (ветка `b 0xfffffff009c498f4`) → thunk `0x9c498f4`:

```asm
fffffff009c498f4  adrp x17, 0xfffffff00806c000
fffffff009c498f8  add  x17, x17, #0x6e0
fffffff009c498fc  ldr  x16, [x17]          ; GOT[0xfffffff00806c6e0]
fffffff009c49900  braa x16, x17
```

GOT[`0xfffffff00806c6e0`] = `0x8011_0000_039ac888` → **`0xfffffff00a9b0888`**.
Это `IOUserClient2022::dispatchExternalMethod` в `kcore/272/com.apple.kernel`
(дизассемблировано capstone, `__TEXT_EXEC,__text`):

```asm
a9b08a8  cbz  x3, bad                     ; if (!dispatchArray) return kIOReturnError
a9b08b0  cmp  x4, w1                      ; if (count <= selector) return kIOReturnBadArgument
a9b08b4  b.ls bad
a9b08b8  add  x8, x8, x8, lsl #2
a9b08bc  add  x20, x3, x8, lsl #3         ; entry = &array[selector]  (stride 0x28)
a9b08d0  ldr  w8, [x20, #8]               ; checkScalarInputCount
a9b08dc  ldr  w9, [x2, #0x28]             ; args->scalarInputCount
a9b08e0  cmp  w8, w9
a9b08e8  ldr  w19,[x20, #0xc]             ; checkStructureInputSize
a9b0964  ldr  w8, [x2, #0x38]             ; args->structureInputSize
a9b0970  ldr  w8, [x20, #0x10]            ; checkScalarOutputCount
a9b097c  ldr  w9, [x2, #0x50]             ; args->scalarOutputCount
a9b0988  ldr  w19,[x20, #0x14]            ; checkStructureOutputSize
a9b09ec  ldr  w8, [x2, #0x60]             ; args->structureOutputSize
a9b09f8  ldr  x8, [x2, #8]                ; args->asyncWakePort
a9b0a00  ldrb w8, [x20, #0x18]            ; allowAsync
a9b0a08  ldr  x19,[x20, #0x20]            ; checkEntitlement
a9b0a78  ldr  x16,[x20]                   ; dispatch->function
a9b0a80  mov  x0, x5                      ; target
a9b0a84  mov  x1, x6                      ; reference
a9b0aa0  braa x16, x17                    ; (*function)(target, reference, args)
```

Смещения `IOExternalMethodArguments` (из `xnu/iokit/IOKit/IOUserClient.h`, LP64):

| off | поле |
|---|---|
| 0x20 | `scalarInput` (`const uint64_t*`) |
| 0x28 | `scalarInputCount` (u32) |
| 0x30 | `structureInput` |
| 0x38 | `structureInputSize` (u32) |
| 0x40 | `structureInputDescriptor` |
| 0x48 | `scalarOutput` |
| 0x50 | `scalarOutputCount` (u32) |
| 0x58 | `structureOutput` |
| 0x60 | `structureOutputSize` (u32) |
| 0x68 | `structureOutputDescriptor` |

Отсюда точное правило для userspace: **число скаляров и размер struct-буферов
должны точно совпадать с полями таблицы** (кроме `0xffffffff` = любой размер).
`IOConnectCallMethod` с несовпадающим `scalarInputCount`/`scalarOutputCount`
или размером struct-буфера возвращает `kIOReturnBadArgument` (0xe00002c2)
до вызова обработчика.

Обработчики вызываются как `function(target=this, reference=NULL, args)`,
то есть `args` — в x2. Это подтверждено декомпиляцией sel 0 (`0x9c3888c`):
`param_3 + 0x20` → `args->scalarInput`, `+0x30` → `structureInput`,
`+0x38` → `structureInputSize`, `+0x40` → `structureInputDescriptor`,
`+0x58` → `structureOutput`.

---

## 4. Селекторы 0..12 — точный формат вызова

Все обработчики вызываются как `function(target=this, reference=NULL, args)`;
`args` — `IOExternalMethodArguments*` (см. §3).

Ограничения таблицы (`ss`/`sso` = `0xffffffff` → размер не проверяется):

| sel | handler | scalIn | structIn | scalOut | structOut | gpu-restricted |
|---|---|---|---|---|---|---|
| 0 | `0x9c3888c` | **1** | var | 0 | **0xc68** | разрешён |
| 1 | `0x9c38a5c` | **1** | 0 | 0 | 0 | разрешён |
| 2 | `0x9c38a6c` | **0** | **0xc** | 0 | 0xc68 | разрешён |
| 3 | `0x9c38a88` | **0** | **0xc** | 0 | **4** | разрешён |
| 4 | `0x9c38aa4` | **1** | 0 | 0 | 0xc68 | **DENIED** (`0x9c3a1dc` → 0xe00002e2) |
| 5 | `0x9c38ab8` | **2** | 0 | 0 | 0 | **DENIED** |
| 6 | `0x9c38acc` | **0** | **0x20** | 0 | 0xc68 | **DENIED** |
| 7 | `0x9c38adc` | **2** | 0 | 0 | 0xc68 | **DENIED** |
| 8 | `0x9c38af4` | **1** | 0 | **1** | 0 | **DENIED** |
| 9 | `0x9c38b2c` | **0** | var (>0xc) | 0 | **4** | разрешён |
| 10 | `0x9c38c44` | **0** | var (≥0xd) | 0 | var (≥0xd) | разрешён |
| 11 | `0x9c38e54` | **0** | var (>0xc) | 0 | **4** | разрешён |
| 12 | `0x9c38f6c` | **3** | 0 | 0 | 0 | разрешён |

«DENIED» = в `sMethodsGPU` на этом месте `0x9c3a1dc`, единственная инструкция
`mov w0, #0xe00002e2; ret` (`kIOReturnNotPermitted`). Т.е. клиент с
`com.apple.private.gpu-restricted` / `com.apple.developer.gpu-restricted`
(`client+0x127 & 1`) получает **не** больше прав, а **меньше**: селекторы
4–8 ему запрещены.

### sel 0 — СОЗДАНИЕ IOSurface (главный ответ)

Обработчик `0x9c3888c` (asm, `__TEXT_EXEC`):

```asm
fffffff009c388ac  ldr   x8, [x2, #0x20]     ; args->scalarInput
fffffff009c388b0  ldr   x20, [x8]           ; scalarInput[0]
fffffff009c388b4  lsr   x8, x20, #0x20
fffffff009c388b8  cbz   x8, ...             ; старшие 32 бита обязаны быть 0
...
fffffff009c389c8  ldr   x3, [x22, #0x58]    ; args->structureOutput
fffffff009c389cc  mov   x0, x21             ; this
fffffff009c389d0  mov   x1, x23             ; structureInput
fffffff009c389d4  mov   x2, x20             ; parentID
fffffff009c389d8  ...                       ; x4 = structureInputSize
```

`0x9c3888c` → `0x9c3ab8c(this, data, parentID, structOut, size)`:

- `thunk_...38d4754(data, size, 0)` = `OSUnserialize` (см. ниже) → `OSDictionary`;
- `(int)parentID == 0` → поверхности без родителя, иначе `FUN_0x9c3f1d0(this, parentID)`
  (поиск родителя в таблице клиента; не найден → `0xe00002c2`);
- из словаря читается ключ **`IOSurfaceAllocateFromSuperbuffer`**
  (строка по адресу `0xfffffff00789b44e`);
- `FUN_0x9c33c34(root, task, dict, parent)` создаёт поверхность;
- `FUN_0x9c2c18c(surface, structOut)` заполняет выходной `IOSurfaceInfo`.

Формат вызова из userspace (совпадает с `IOSurfaceClient` framework,
см. проверку в конце §4):

```c
uint64_t scalars[1] = { parent_id };      // u32, 0 = нет родителя
uint8_t  props[]    = /* сериализованный plist свойств */;
uint8_t  info[0xc68];
size_t   infoSize   = 0xc68;
kr = IOConnectCallMethod(conn, 0,
                         scalars, 1,          // scalarInputCount = 1
                         props, props_len,    // structureInputSize любой > 0
                         NULL, NULL,          // scalarOutputCount = 0
                         info, &infoSize);    // structureOutputSize = 0xc68
```

`structureInput` парсится `OSUnserialize` (таргет thunk `0xa8d8754`).
Функция проверяет 32-байтовую сигнатуру бинарного формата libkern
(`d3 00 00 00 00 00 00 00 80 00 00 00 00 00 00 00 01 ...`, лежит по
`0xfffffff007043a08`) и иначе уходит в текстовый XML-парсер. То есть
принимается и бинарный plist-формат ядра, и текстовый XML.

### sel 1 — release по глобальному ID

`0x9c38a5c` → `FUN_0x9c3b0bc(this, id)`:

- `scalarInput[0]` = u32 surface ID (берётся `**(u32**)(args+0x20)`);
- под локом `client+0xd8` перебирает массив `client+0x140`, ищет запись,
  у которой `*(u32*)(entry+0x38) == id`; снимает её из массива (virtual `+0x108`),
  уменьшает счётчики `client+0x128` / `client+0x12c`, отпускает ссылку;
- struct-вход/выход не нужны (0/0).

### sel 2 — use-count/состояние + полный IOSurfaceInfo

`0x9c38a6c` → `FUN_0x9c3b3ac(this, structIn, structOut, inSize, &outSize)`;
структура входа ровно **0xc** байт:

```c
struct { uint32_t surface_id; uint32_t flags; } in;   // flags: bit0, bit2
```

Проверки: `inSize == 0xc`, `outSize == 0xc68`.
Логика: `FUN_0x9c3f130(this, in.surface_id)` (поиск поверхности),
если `flags & 4` — `FUN_0x9c26fcc(clientbuf, 2 - (flags & 1), -1)` +
`FUN_0x9c41314(...,0)`; затем `FUN_0x9c2af10(clientbuf, flags & 1)` и
`FUN_0x9c209b8(clientbuf, flags, &old)` (инкремент use-count:
`param_2&1` — категория, `param_2&2` — запрет use-count,
`param_2&4` — дополнительная ветка). Выход — `IOSurfaceInfo` (0xc68),
поле `+0x68` перезаписывается значением `old`.

### sel 3 — decrement use-count, ответ 4 байта

`0x9c38a88` → `FUN_0x9c3b58c(this, structIn, structOut, inSize, &outSize)`;
вход **0xc** байт `{ u32 surface_id; u32 arg; }`, выход **4** байта.
Требует `inSize == 0xc`, `outSize == 4`. Поиск поверхности
`FUN_0x9c3f1d0(this, id)`, затем `FUN_0x9c20f04(surface, arg, out)` —
декремент счётчика (`arg&1`: категория 0/1, декремент `+0x23c` или `+0x238`),
в `out` пишется `*(u32*)(*(surface+0x178)+0xc)` (текущий use count).

### sel 4 — lookup по глобальному ID (нужен gpu-restricted)

`0x9c38aa4` → `FUN_0x9c3b628(this, id, structOut)`; `scalarInput[0]` = u32 ID;
выход ровно **0xc68**. `FUN_0x9c3f044(this, id, ...)` ищет поверхность в
глобальной таблице рута, `FUN_0x9c33a4c(root, id, task, this)` создаёт
клиентский буфер, `FUN_0x9c2b810(shared, surface, 0)` маппит,
`FUN_0x9c2c18c` заполняет `IOSurfaceInfo`.

### sel 5 — два скаляра, флаг поверхности (gpu-restricted)

`0x9c38ab8` → `FUN_0x9c3bab4(this, a, b)`:
`scalarInput[0]` = u32 surface ID (поиск `FUN_0x9c3f1d0`),
`scalarInput[1]` = байт, записывается в `*(u8*)(*(surface+0x178)+0x6e)`
(`FUN_0x9c24720`). Это то же поле, что попадает в `IOSurfaceInfo+0x5c`
(см. `FUN_0x9c2c18c`, строка `uVar7 = *(u32*)(*(long*)(lVar15+0x178)+0xc)` /
`bVar4 = *(u8*)(*(long*)(lVar15+0x178)+0x6e)`), т.е. булев флаг клиента.

### sel 6 — создание поверхности из готовой памяти (gpu-restricted)

`0x9c38acc` → `FUN_0x9c3bb20(this, structIn, structOut)`; вход ровно **0x20**,
выход **0xc68**. Раскладка (по коду `0x9c3bb20`):

```c
struct {
    uint64_t address;          // +0x00  IOSurfaceAddress
    uint32_t width;            // +0x08  IOSurfaceWidth
    uint32_t height;           // +0x0c  IOSurfaceHeight
    uint32_t pixel_format;     // +0x10  IOSurfacePixelFormat
    uint32_t bytes_per_element;// +0x14  IOSurfaceBytesPerElement
    uint32_t bytes_per_row;    // +0x18  IOSurfaceBytesPerRow
    uint32_t alloc_size;       // +0x1c  IOSurfaceAllocSize
} in;
```

Каждое ненулевое поле превращается в `OSNumber` и кладётся в словарь;
затем `FUN_0x9c33c34` создаёт поверхность, `FUN_0x9c2c18c` заполняет info.

### sel 7 — создание поверхности из диапазона память (gpu-restricted)

`0x9c38adc` → `FUN_0x9c3bf44(this, addr, size, structOut)`;
`scalarInput[0]` = u64 address, `scalarInput[1]` = u64 size (оба обязаны быть
ненулевыми). В словарь кладутся `IOSurfaceAddress` и `IOSurfaceAllocSize`,
дальше создание как в sel 6; выход 0xc68.

### sel 8 — чтение флага (gpu-restricted)

`0x9c38af4` → `FUN_0x9c3c354(this, id)`:
`scalarInput[0]` = u32 surface ID (`ldr w1,[args->scalarInput]`),
`FUN_0x9c3f1d0(this,id)` + `FUN_0x9c24754(surface)` читает
`*(u8*)(*(surface+0x178)+0x6e)`; `scalarOutput[0]` всегда пишется `0`
(`str xzr,[args->scalarOutput]`), а прочитанный байт остаётся в `x0`
(возврат метода). Требует `scalarOutputCount == 1`.

### sel 9 — set value (property), вход — plist

`0x9c38b2c` → `FUN_0x9c3c3b8(this, structIn, inSize, structOut)`;
`inSize > 0xc`, выход ровно 4 байта.

```c
struct {
    uint32_t surface_id;   // +0x00
    uint32_t unused0;      // +0x04
    uint32_t unused1;      // +0x08
    uint8_t  plist[];      // +0x0c, длина inSize-0xc
} in;
```

Байты с `+0xc` парсятся `OSUnserialize` в **массив из двух элементов**:
`[0]` = value, `[1]` = key (OSString). Затем
`FUN_0x9c28220(surface, key, value, &out4)` (`FUN_0x9c255c8`).

### sel 10 — get value / словарь свойств, вход ≥0xd, выход переменный

`0x9c38c44` → `FUN_0x9c3c538(this, structIn, structOut, inSize, &outSize)`;
проверки: `inSize >= 0xd`, `outSize >= 0xd`.

```c
struct {
    uint32_t surface_id;   // +0x00
    uint32_t unused0;      // +0x04
    uint32_t flags;        // +0x08  (если != 0 — фильтр по ключу)
    char     key[];        // +0x0c, C-строка, длина inSize-0xc
} in;
```

`FUN_0x9c28380(surface, key, out+4)`; если `flags != 0`, результат кастуется
к `OSDictionary` и берётся объект по ключу `CreationProperties`
(`0xfffffff00789b3c1`). Сериализованный результат копируется в `out+0xc`,
`outSize = len + 0xc`. Формат выхода — та же сериализация libkern.

### sel 11 — remove value

`0x9c38e54` → `FUN_0x9c3c9c0(this, structIn, inSize, structOut)`;
`inSize > 0xc`, выход 4 байта; та же шапка 0xc и C-строка ключа с `+0xc`.
`FUN_0x9c284c8(surface, key, &out4)`; пустая строка (`*key == 0`) → key=NULL.

### sel 12 — три скаляра

`0x9c38f6c` → `FUN_0x9c3caa8(this, *u32(scalars+0), u32(scalars+1), u32(scalars+2))`
(читаются младшие 32 бита трёх 64-битных скаляров — `puVar1[0]`, `[2]`, `[4]`
при `u32*`). `scalarInput[0]` = surface ID (поиск `FUN_0x9c3f1d0`),
затем `FUN_0x9c2af10(surface, 0)` и `FUN_0x9c21128(surface, s1, s2)` →
`FUN_0x9c20b58(surface, s1, s2 & 7, 0)` — работа со счётчиками/категориями
use-count. Выходов нет.

### Что такое `IOSurfaceInfo` (0xc68)

`FUN_0x9c2c18c(surface, out)`:

```c
memset(out, 0, 0xc68);
out->id            = *(u32*)(surface+0x38);   // +0x18
out->use_count     = *(u32*)([surface+0x178]+0xc); // +0x68 (и +0x58?)
out->flag_5c       = *(u8*)([surface+0x178]+0x6e); // +0x5c
out->pixel_format  = *(u32*)(surface+0x9c);   // +0x64
...
planes = min(*(u32*)(*(long*)(surface+0x40)+0x98), 0x14); // +0x58
for (i = 0; i < planes; i++)
    out->planes[i] = ...;                     // +0x88 + i*0x98
```

Итого: **0x88 байт заголовка + 20 записей по 0x98 = 0xc68**. Именно поэтому
проверка `structureOutputSize == 0xc68`.

### Проверка по userspace-фреймворку

`dsc/272/IOSurface` (тот же файл есть в `work/ios272/IOSurface`) вызывает
`IOConnectCallMethod` (внешняя функция `0x1c8128670`) в 42 местах. Все
селекторы и счётчики совпадают с таблицей:

- sel 0: site `0x1c3090ba4`, `w3=1`, `x4`=serialized data, `x5`=len,
  `structureOutput=0xc68` (`mov w8,#0xc68`);
- sel 4: site `0x1c3090160`, `w3=1`, `structureOutput=0xc68`;
- sel 7: site `0x1c309c304`, `w3=2`, `structureOutput=0xc68`;
- sel 6: site `0x1c309c1bc`, `w3=0`, `x4`=stack struct, `w5=0x20`;
- sel 9: site `0x1c309189c`, `w3=0`, struct in `x4/x5`, struct out 4;
- sel 10: site `0x1c3092310`, `w3=0`, `w5=0xd` (вход 0xd);
- sel 27: site `0x1c3091d28`, `w3=0`, `w5=0xa0`;
- sel 34: site `0x1c30947a0`, `w3=1`, out 0xc68;
- и т.д. — ни одного расхождения с таблицей нет.

Это независимое подтверждение: таблица `0xfffffff008068b90` — реальный ABI,
которым пользуется системный `IOSurface.framework`.

---

## 5. Что такое «13 записей по 0x18» из прошлого отчёта

Это **не** таблица селекторов `IOConnectCallMethod`. Запись ровно 24 байта:

```asm
fffffff009c3ee58  add x9, x9, x9, lsl #1     ; index*3
fffffff009c3ee5c  lsl x9, x9, #3             ; index*0x18
fffffff009c3ee60  adrp x10, 0xfffffff008069000
fffffff009c3ee64  add  x10, x10, #0xe50
fffffff009c3ee68  cmp  x9, w9, SXTW
fffffff009c3ee6c  add  x11, x10, w9, SXTW
fffffff009c3ee70  add  x16, x10, x9
fffffff009c3ee74  movk x16, #0x2bad, lsl #48
fffffff009c3ee78  csel x11, x11, x16, eq
```

и в памяти каждая запись = `{ uint64 object = 0; IOMethod func (16 байт:
указатель на stub + adjustment = 0); }`.

По размеру и ABI это совпадает с `IOExternalTrap { IOService *object;
IOTrap func; }` (24 байта, `IOTrap` — 16-байтовый указатель на функцию-член):
`object = 0` (значит, берётся target из `*targetP = this`), `func` = 16-байтовый
member pointer (stub + adjustment 0). Обработчики этой таблицы (`0x9c3cb74` и др.)
принимают **сырые аргументы в x1..x6**, а не `IOExternalMethodArguments*`
(например `0x9c3cb74`: `cmp w2,#1`, x2 — второй сырой аргумент) — это ABI
`IOConnectTrap0..6`, а не `IOConnectCallMethod`.

Сверено с xnu (`iokit/Kernel/IOUserClient.cpp`, `iokit_user_client_trap`):

```c
trap = userClient->getTargetAndTrapForIndex(&target, args->index);
if (trap && target) {
    IOTrap func = trap->func;
    if (func)
        result = (target->*func)(args->p1, args->p2, args->p3,
                                 args->p4, args->p5, args->p6);
}
```

и `getTargetAndTrapForIndex` вызывает `getExternalTrapForIndex(index)` +
`*targetP = trap->object`. Переопределение `0x9c3ee40` вместо этого пишет
`*targetP = this` (object в таблице = 0).

Что `IOConnectCallMethod` в эту таблицу не ходит — доказано кодом: у класса
переопределён `externalMethod` (`0x9c3ee10`), и он сразу вызывает
`dispatchExternalMethod` с таблицей из 60 записей; путь
`getTargetAndMethodForIndex` в `IOUserClient::externalMethod` выполняется только
если `externalMethod` не переопределён.

Таблица `0xfffffff008069e50` (и её gpu-вариант `0xfffffff008069f88`) —
trap-таблица. Селекторы 0..12 из `IOConnectCallMethod` — это первые 13 записей
таблицы `IOExternalMethodDispatch2022` из §1.

## 6. Открытые вопросы (проверяю дальше)

- Динамически подтвердить trap-таблицу через `IOConnectTrapN` (статически
  структура и ABI совпадают с `IOExternalTrap`, но вызов на устройстве не
  проверялся).
- Точный формат сериализации свойств, который кладёт framework (XML vs
  бинарный libkern) — ядро принимает оба.
- Полная раскладка `IOSurfaceInfo` (сейчас подтверждены заголовок 0x88 и
  массив 20×0x98).
