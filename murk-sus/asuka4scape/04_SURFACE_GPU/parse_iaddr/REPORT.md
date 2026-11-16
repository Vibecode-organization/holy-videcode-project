# IOSurfaceAddress / селектор 7 — 27.2 (24B115) — subagent H

Файл: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (67 239 936 байт).

## Вердикт

**Нельзя.** Гипотеза «`IOSurfaceAddress` кладётся в `[IOSurface+0x150]` без проверки владения ⇒ произвольное чтение/запись» **не подтверждается для 27.2**.

Проверка владения есть, но она стоит не в `initWithProperties`, а на шаг позже — в функции подготовки памяти поверхности `0x9c1e624`. Там весь page-aligned диапазон прогоняется через `mach_vm_region` по карте **задачи-владельца** (`fOwnerTask`, `[IOSurface+0x170]`), и ядерный/чужой адрес отбивается с `KERN_INVALID_ADDRESS` → `sel 7` возвращает `0xe00002c2` (kIOReturnBadArgument), поверхность не создаётся.

Второй независимый барьер: дескриптор создаётся как `IOMemoryDescriptor::withAddressRange(addr, len, flags, fOwnerTask)` — то есть привязан к таске приложения, а не к `kernel_task`/`TASK_NULL`.

Ключевой адрес-убийца: **`0xfffffff009c2200c`** (вызов из `0xfffffff009c1ea10`, ветка client-address в `0x9c1e8b0`).

---

## 1. Полный путь селектора 7

Таблица диспетчера `0xfffffff008068b90`, запись 7 (stride 0x28):

```
[ 7] fn=0xfffffff009c38adc  sIn=2  strIn=0  sOut=0  strOut=3176
```

### 1.1 Обёртка `0x9c38adc` → `0x9c3bf44`

```
0x9c38ae0: ldr  x8, [x2, #0x20]      ; args->scalarInput
0x9c38ae4: ldp  x1, x8, [x8]         ; x1 = scalarInput[0], x8 = scalarInput[1]
0x9c38ae8: ldr  x3, [x2, #0x58]      ; args->structureOutput (void*)
0x9c38aec: mov  x2, x8               ; x2 = scalarInput[1]
0x9c38af0: b    #0x9c3bf44
```

Сигнатура реализации: `create_surface_client_mem(self, u64 a, u64 b, void *out)`.
`a` = адрес, `b` = размер (порядок подтверждён ниже по коду: `a` уходит в `IOSurfaceAddress`, `b` в `IOSurfaceAllocSize`).

### 1.2 `0x9c3bf44` — сборка словаря

```
0x9c3bf6c: cbz  x1, 0x9c3bfc0        ; a == 0  -> "invalid memory range"
0x9c3bf70: cbz  x20, 0x9c3bfc0       ; b == 0  -> то же
0x9c3bf78: ldr  w8, [x0, #0x128]     ; счётчик (по логу — "client limit")
0x9c3bf7c: cmp  w8, #4, lsl #12      ; >= 0x4000 ?
0x9c3bf80: b.lo 0x9c3c000            ; < 0x4000 -> рабочий путь
                                     ; >= 0x4000 -> "exceeded client limit", 0xe00002be
```

Ошибки: `0x9c3bfb8` = `0xe00002be` (kIOReturnNoResources), `0x9c3bff8` = `0xe00002c2` (kIOReturnBadArgument).
Лог-строки: `0x789d10e` = `"create_surface_client_mem"`, `0x78a0dfc` = `"%s error - invalid memory range (addr=0x%llx size=0x%llx)\n"`, `0x78a0e37` = `"%s error - exceeded client limit (%d)\n"`.

Далее (0x9c3c000–0x9c3c0c0):

```
0x9c3c004: mov  w0, #3
0x9c3c008: bl   0x9c49864            ; OSDictionary::withCapacity(3)
0x9c3c014: mov  x0, x23              ; a
0x9c3c018: mov  w1, #0x40
0x9c3c01c: bl   0x9c49a84            ; OSNumber::withNumber(a, 64)
0x9c3c040..0x9c3c058: dict->setObject("IOSurfaceAddress", num_a)     ; строка 0x789b134
0x9c3c064: bl   0x9c49a84            ; OSNumber::withNumber(b, 64)
0x9c3c090..0x9c3c0c0: dict->setObject("IOSurfaceAllocSize", num_b)   ; строка 0x789b013
```

### 1.3 `0x9c3c0c4` — создание поверхности

```
0x9c3c0c8: ldr  x16, [x21, #0xf8]    ; userclient->owner task (PAC)
0x9c3c0cc: ldur x0, [x17, #-0x10]    ; x0 = [self+0xe8]  (IOSurfaceRoot)
0x9c3c14c: mov  x2, x19              ; dict
0x9c3c150: mov  x3, #0
0x9c3c154: bl   0x9c33c34            ; createSurface(root, task, dict, 0)
```

`0x9c33c34`: берёт метакласс `0x8067118` (IOSurface), аллоцирует объект и вызывает `0x9c1a914(surface, root, task, dict, 0)` (вызов на `0x9c33cac`).

`0x9c1a914` — «внешний» инициализатор. Таску складывает в объект:

```
0x9c1aa70: add  x16, x19, #0x170
0x9c1aa80: pacda x17, x16
0x9c1aa84: str  x17, [x19, #0x170]   ; fOwnerTask = task
```

и вызывает парсер свойств `0x9c1af14` (`0x9c1ad70`).

---

## 2. `initWithProperties` `0x9c1af14` — куда ложится адрес

Разбор ключа:

```
0x9c1dfc4: adrp x1, 0x789b000 ; add #0x134   ; "IOSurfaceAddress"
0x9c1dfd0: mov  x0, x20                       ; dict
0x9c1dfd4: bl   0x9c20038                     ; getIntegerProperty(dict, key, &val)
0x9c1dfd8: cbz  w0, 0x9c1e040                 ; ключа нет -> дальше
0x9c1dfdc: ldr  x8, [x19, #0x308]             ; проверка "не сжатая"
0x9c1dfe0: cbz  x8, 0x9c1e00c
0x9c1dfe4..0x9c1e004: лог 0x789fcb7 "Cannot use kIOSurfaceClientAddress with compressed iosurfaces." -> return 0
0x9c1e00c: ldr  x16, [x19, #0x3a0]            ; PAC-указатель компрессора
0x9c1e034: cbnz x16, 0x9c1d63c                ; != 0 -> молчаливый return 0
0x9c1e038: ldur x8, [x29, #-0x68]
0x9c1e03c: str  x8, [x19, #0x150]             ; <<< fClientAddress
```

**В `initWithProperties` запись `[+0x150]` одна — `0x9c1e03c`** (сплошной скан `0x9b80000–0x9d40000`: в этом классе поле ещё читается в `0x9c1ad80`, `0x9c1e8b0` и логируется в `0x9c1ea20`; остальные `[x+0x150]` в диапазоне принадлежат другим классам).

Тут владение действительно не проверяется — только «не сжатая», «нет компрессора». Гипотеза в этой точке верна.

`IOSurfaceAllocSize` парсится отдельно и раньше:

```
0x9c1d50c: add  x1, x1, #0x13        ; "IOSurfaceAllocSize"
0x9c1d518: bl   0x9c20038
0x9c1d524: str  x8, [x19, #0x90]     ; fAllocSize
0x9c1d540: add  x10, x8, x9          ; x9 = page-1
0x9c1d544: bic  x9, x10, x9
0x9c1d548: cmp  x9, x8 ; b.hs 0x9c1d578   ; проверка переполнения page-round
```

---

## 3. Вывод base/size и вызов `0x9c1e624`

Возврат в `0x9c1a914`:

```
0x9c1ad80: ldr  x8, [x19, #0x150]     ; fClientAddress
0x9c1ad84: cbz  x8, 0x9c1adf4         ; 0 -> ветка kernel-alloc
0x9c1ad90: ldr  x9, [0x806ca78]       ; *page_size
0x9c1ad94: neg  x10, x9
0x9c1ad98: and  x11, x8, x10          ; aligned base
0x9c1ad9c: sub  x9, x9, #1
0x9c1ada0: and  x12, x9, x8           ; offset в странице
0x9c1ada4: ldr  x8, [x19, #0x90]      ; fAllocSize
0x9c1ada8: add  x9, x9, x8
0x9c1adac: add  x9, x12, x9
0x9c1adb0: and  x9, x9, x10           ; aligned size
0x9c1adb4: str  x11, [x19, #0x158]    ; [0x158] = aligned base
0x9c1adb8: stp  x9, x12, [x19, #0x160] ; [0x160] = aligned size, [0x168] = offset
0x9c1adf4: ldr  x8, [x19, #0x90]
0x9c1adfc: cbz  x8, 0x9c1ae18         ; fAllocSize == 0 -> 0x9c1e624 НЕ вызывается
0x9c1ae04: bl   0x9c1e624             ; подготовка памяти поверхности
0x9c1ae08: cmp  w0, #0 ; cset w20, eq ; ошибка -> init возвращает 0
```

---

## 4. Санитайзер: `0x9c1e624` → `0x9c2200c`

Ветка client-address:

```
0x9c1e8b0: ldr  x8, [x19, #0x150]
0x9c1e8b4: cbz  x8, 0x9c1e8f4          ; нет клиентского адреса -> обычная аллокация
0x9c1e8b8: ldr  w8, [x19, #0x368]
0x9c1e8bc: str  w8, [sp, #0x34]         ; out-флаг (direction)
0x9c1e8c4: ldr  x16, [x19, #0x170]      ; fOwnerTask
0x9c1e8cc: cbz  x16, 0x9c1ea00          ; NULL -> x0 = 0
0x9c1e8ec: mov  x0, x16
0x9c1ea04: ldp  x1, x8, [x19, #0x158]   ; x1 = aligned base, x8 = aligned size
0x9c1ea08: add  x2, x8, x1              ; x2 = end
0x9c1ea0c: add  x3, sp, #0x34
0x9c1ea10: bl   0x9c2200c               ; <<< ПРОВЕРКА ДИАПАЗОНА
0x9c1ea14: cbz  w0, 0x9c1ea68           ; ok -> создаём дескриптор
0x9c1ee9c: лог 0x789fe3c "%s error - invalid address range (0x%llx - 0x%llx) : (0x%llx - 0x%llx)"
```

### 4.1 Что делает `0x9c2200c(task, start, end, &flag)`

```
0x9c22088: mov  x0, x22
0x9c2208c: bl   0x9c49be4            ; -> 0xa29b7b0: [task+0x28] с PAC-снятием; уходит x0 в mach_vm_region => это vm_map
0x9c22090..0x9c220a8: аргументы mach_vm_region
0x9c220a8: bl   0x9c49c64            ; -> 0xa344acc -> 0xa2f2680 (mach_vm_region, flavor 9)
0x9c220ac: cbnz w0, 0x9c22100        ; ошибка -> 0xe00002c8
```

- `0xa344acc`: `if (map == 0) return KERN_INVALID_ARGUMENT(4); if (flavor == 10) flavor = 9; b mach_vm_region`.
- Цикл требует **полного покрытия** `[start, end)`:
  - `0x9c220b0–0x9c220d0`: первая итерация — `region.addr <= start`; далее — `region.addr == prev_end`; иначе `0xe00002c8`.
  - `0x9c220d4–0x9c220d8`: `tbnz protection, #2` → запрет `VM_PROT_EXECUTE` (бит 2 = 4).
  - `0x9c220dc–0x9c220e4`: если `max_protection` без `VM_PROT_WRITE` — выставляет `*flag = 2`.
  - `0x9c220e8–0x9c220f4`: `addr = region.addr + region.size`, пока `< end`.
- Код ошибки: `0x9c22100: mov w0,#0x2c8; movk w0,#0xe000,lsl#16` = **`0xe00002c8` (kIOReturnCannotWire)**.

Т.е. это не «мягкая» проверка на выравнивание, а честный обход карты: диапазон обязан быть отображён в таске целиком, без execute-страниц.

### 4.2 Создание дескриптора

```
0x9c1ea68: ldp  x0, x1, [x19, #0x158]     ; base, size
0x9c1ea6c: ldr  w8, [sp, #0x34]           ; direction из проверки
0x9c1ea70: mov  w9, #0x110000
0x9c1ea98: mov  x3, x16                   ; fOwnerTask (PAC-verify)
0x9c1ebf4: orr  w2, w8, w9
0x9c1ebf8: bl   0x9c49964                 ; IOMemoryDescriptor::withAddressRange(addr,len,opts,task)
0x9c1ec08: bl   0x9c21f08                 ; привязать дескриптор к поверхности
```

**Таска — `fOwnerTask`, не `kernel_task` и не `TASK_NULL`.**

### 4.3 Чем является `fOwnerTask`

`0x9c3a33c` (инициализация user client):

```
0x9c3a318: mov  x0, x20
0x9c3a31c: bl   0x9c49df4          ; task_reference(task)
0x9c3a324: add  x16, x19, #0xf8
0x9c3a330: pacda x17, x16
0x9c3a33c: str  x17, [x19, #0xf8]  ; userclient+0xf8 = owning task
```

`sel 7` передаёт именно `[self+0xf8]` (`0x9c3c0c8`) → `0x9c33c34` → `[IOSurface+0x170]`. Для приложения это **его собственная таска**.

---

## 5. Вторичный путь: `IOSurfaceAddressRanges` (мультидиапазон)

Ключ существует и обрабатывается в том же `0x9c1af14`:

```
0x9c1da60: add  x1, x1, #0x173   ; "IOSurfaceDirection"  -> [0x368], допускается 2|3
0x9c1da90: add  x1, x1, #0x15c   ; "IOSurfaceAddressOffset" -> [0x168], должен быть < page_size (0x9c1dab8)
0x9c1dac4: add  x1, x1, #0x145   ; "IOSurfaceAddressRanges"
0x9c1dacc: bl   0x9c203b0        ; getObject
0x9c1daf4: cmp  w0, #0x10 ; tst w0,#0xf ; b.eq 0x9c1df44   ; длина >= 0x10 и кратна 0x10 (16-байтные записи)
0x9c1df70..0x9c1df90: копия массива в [IOSurface+0x370], счётчик -> [0x3b4]
```

Дальше в `0x9c1e624` — цикл по записям `{u64 addr; u64 size}` (`0x9c1e918`), и для **каждой**:

```
0x9c1e93c: tst  page_mask, addr   -> 0x9c1ee2c "unaligned addr"
0x9c1e944: проверка size (нулевой/невыровненный) -> 0x9c1ee64 "unaligned length"
0x9c1e958: task = fOwnerTask
0x9c1e98c: bl   0x9c2200c         ; тот же санитайзер
0x9c1e9a0: cbnz w0 -> 0x9c1ee9c   ; отказ
0x9c1edb0: bl   0x9c49974         ; withAddressRange для диапазона, x3 = fOwnerTask
```

Мультидиапазон тоже закрыт.

---

## 6. Селектор 0 (словарь через `OSUnserializeXML`)

`0x9c3888c`, `sIn=1, strIn=0xFFFFFFFF, sOut=0, strOut=3176` — создание поверхности из пользовательского словаря. Идёт в тот же `0x9c33c34` → `0x9c1a914` → `0x9c1af14` → `0x9c1e624`. Проверки те же: `0x9c2200c` на `fOwnerTask`. Отдельного, более строгого пути для `IOSurfaceAddress` через словарь нет — строже он быть и не может, это тот же код.

---

## 7. Список всех проверок адреса (с адресами инструкций)

| # | Адрес | Что проверяется | Результат |
|---|---|---|---|
| 1 | `0x9c3bf6c`, `0x9c3bf70` | `addr != 0`, `size != 0` | `0xe00002c2` |
| 2 | `0x9c3bf7c` | счётчик (по логу "client limit") `< 0x4000` | `0xe00002be` |
| 3 | `0x9c1dfdc` | `[IOSurface+0x308] == 0` (не сжатая) | return 0, лог `0x789fcb7` |
| 4 | `0x9c1e00c`/`0x9c1e034` | `[IOSurface+0x3a0] == 0` (нет компрессора, PAC) | return 0 молча |
| 5 | `0x9c1d548` | page-round `IOSurfaceAllocSize` без переполнения | return 0 |
| 6 | `0x9c1e93c`, `0x9c1e944` | выравнивание addr/size (только мультидиапазон) | `0xe00002c2` |
| 7 | **`0x9c2200c`** (вызов `0x9c1e98c` мульти, `0x9c1e9a0`; `0x9c1ea10` одиночный) | **полное покрытие `[aligned_base, aligned_end)` в `fOwnerTask->map` через `mach_vm_region`, запрет execute** | **`0xe00002c8`** |
| 8 | `0x9c1ebf8` / `0x9c1edb0` | `withAddressRange(..., task = fOwnerTask)` | дескриптор в таске приложения |
| 9 | `0x9c1edf4` | `descriptor.length >= offset + fAllocSize` (мульти) | отказ |

Чего в этой ветке **нет**: `isRangeInTask`, `task_has_ledger`, прямых `pmap_*`/`ml_*`, явной сверки `address < VM_MIN_KERNEL_ADDRESS`, `kIOUserClientMemoryAccess`. Единственные вызовы в ветке — `0x9c49be4` (`task->map`), `0x9c49c64` (`mach_vm_region`), `0x9c49964`/`0x9c49974` (`withAddressRange`), `0x9c21f08` (attach).

---

## 8. Энтайтлменты

`sel 7` доступен **без** энтайтлментов: он есть в обычной таблице `0x8068b90`. Для клиентов с `com.apple.developer.gpu-restricted` (`[uc+0x127]`, выбор таблицы в `0x9c3ee14`) подставляется таблица `0x80694f0`, где `sel 7` = `0x9c3a1dc` — заглушка, возвращающая `0xe00002e2` (kIOReturnUnsupported). То есть ограниченные клиенты этот путь вообще не получают.

Прочие энтайтлменты, читаемые в `0x9c3a2d8`: `com.apple.private.iosurfaceinfo`, `com.apple.private.gpu-restricted`, `com.apple.developer.gpu-restricted`, `com.apple.private.IOSurface.protected-access` — к `sel 7` отношения не имеют.

---

## 9. Рецепт (негативный тест + контроль)

Проверить блокировку можно так (это и есть «рецепт», только отрицательный):

```
io_connect_t c = IOSurfaceRootUserClient (IOServiceOpen на "IOSurfaceRoot")
uint64_t in[2] = { kernel_addr, size };
uint8_t  out[3176];
IOConnectCallMethod(c, 7, in, 2, NULL, 0, NULL, NULL, out, &outLen);
```

- `structureOutput` обязателен: `strOut = 3176` (проверяется диспетчером), иначе `kIOReturnBadArgument`.
- `in[0]` = адрес, `in[1]` = размер.
- **Ожидаемый результат для ядерного/чужого адреса: `0xe00002c2`, `outLen` не заполняется.**
- Контроль (свой буфер, `mmap` в приложении): вызов проходит, в `out`:
  - `out+0x18` (u32) = IOSurfaceID (`[IOSurface+0x38]`, запись `0x9c2c210`);
  - `out+0x20` (u64) = allocSize (из объекта `[IOSurface+0x40]`, поле +0x90, запись `0x9c2c218`);
  - `out+0x50` (u64) = то же значение (дубль, `0x9c2c240`);
  - `out+0x00..0x0f` — 16 байт из `[IOSurface+0x50]`, `out+0x10` — `[IOSurface+0x60]`;
  - адрес в структуру **не возвращается** (в сериализаторе `0x9c2c18c` обращения к `[+0x150]` нет).
- Селектор 34 (`0x9c397d8`, 1 скаляр + 3176) — lookup по id, тот же сериализатор `0x9c2c18c`.
- Селектор 28 (`0x9c39660`, 1 скаляр + 160) — `0x9c3d838`, укороченная информация.

---

## 10. Следующие кандидаты

- `IOSurfaceMemoryPoolSize` — мёртв (подтверждено ранее).
- `IOSurfaceAllocSize` — самостоятельного примитива нет: только `[IOSurface+0x90]`, длина дескриптора и проверки геометрии; page-round с проверкой переполнения `0x9c1d548`; в client-ветке длина дескриптора ровно та, что прошла `0x9c2200c` (`0x9c1ea68` перечитывает `[0x158]`/`[0x160]`).
- `IOSurfaceBaseAddress` — **такого ключа в 27.2 нет** (строка отсутствует). Есть `IOSurfacePlaneBase`, он валидируется как `plane.base + plane.size <= fAllocSize` (лог `0x789fa79`).
- `IOSurfaceCompressedTileWidth` — **такого ключа нет**; есть `IOSurfacePlaneCompressedTileWidth` (часть описания сжатых плоскостей, не адрес).
- `IOSurfaceAddressRanges` — есть, но с тем же `0x9c2200c` на каждый диапазон.

Ближайшее направление, которое остаётся живым: не адрес, а **рассогласование длины** между `fAllocSize` и фактическим дескриптором в мультидиапазонной ветке (`0x9c1edf4` сверяет `offset + fAllocSize` с длиной дескриптора — стоит разобрать, что именно туда попадает при `IOSurfaceAddressOffset != 0`).

---

## 11. Не подтверждено

- Точная семантика полей `[IOSurface+0x308]` и `[IOSurface+0x3a0]` за пределами «сжатая поверхность / компрессор» — по строкам логов, без имён символов.
- `0x9c3a1dc` для gpu-restricted клиентов — по коду возвращает `0xe00002e2`; какая именно таблица какой ветке соответствует, определено по `csel` в `0x9c3ee28` (флаг `[uc+0x127]` = `com.apple.developer.gpu-restricted`).
- Поведение на живом устройстве не проверялось (только статика).
- Имена `OSDictionary::withCapacity` / `OSNumber::withNumber` — вывод из сигнатур (аллокация + `init(cap)`, затем `setObject` по vtable+0x100; второй объект — `init(value, 0x40=64 бита)`) и из того, что тот же ключ потом читается `getIntegerProperty` (`0x9c20038`). Символьных таблиц в кеше нет.
