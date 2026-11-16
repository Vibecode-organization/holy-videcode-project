# OSUnserializeXML / OSUnserializeBinary, iOS 27.2 (24B115) — memory-safety review

Cache: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (67 239 936 B),
diff cache: `27.0_24A437_kernelcache` (66 977 792 B).
`LC_SYMTAB` пуст — все имена ниже восстановлены по строкам логирования и по таблице
kext-symbol plist в `__LINKEDIT` (имена есть, адресов нет), поэтому имена функций помечены
как *выведенные*. Адреса — VA кеша `27.2`; для `27.0` даётся дельта.

Нотация: `0xfffffff007004000 + off` для `__TEXT_EXEC` (off = `va - 0xfffffff007004000`,
проверено: `va2off` даёт одинаковый результат для обоих кешей, т.к. у всех сегментов
`va - fileoff == 0xfffffff007004000`).

---

## 1. Точки входа и ключевые функции (27.2)

| VA | что это | доказательство |
|---|---|---|
| `0xfffffff00a8d5c98` | `OSUnserializeXML(const char *buf, OSString **err)` — 2-арг, **без размера**, уходит в старый парсер | строка `0xfffffff0070ae996` и вызов `0xa8d4630` по `0xa8d5d88` |
| `0xfffffff00a8d8660` | `OSUnserializeXML(buf, err)` через новый core (stub, 7 инструкций) | `b 0xa8d846c` по `0xa8d8674` |
| `0xfffffff00a8d846c` | **core**: `OSUnserializeXML(buf, func, ref, flags, err)`; аллоцирует `parser_state_t` (0x40 B) и вызывает новый парсер | `kalloc_type`-дескриптор `0xfffffff007c7c2d0`, `bl 0xa8d5ea4` по `0xa8d8568` |
| `0xfffffff00a8d8678` | `OSUnserializeXML(buf, size, func, ref, flags, err)` — 6-арг | `cmp x1,#4`, `strcmp("\xd3",buf)`, `buf[0]==0xd4` |
| **`0xfffffff00a8d8754`** | `OSUnserializeXML(buf, size, err)` — 3-арг, **используется IOSurface** | полный дизасм ниже |
| `0xfffffff00a8da3fc` | `OSUnserializeXML(..., OSSharedPtr<OSString>&)` | обёртка вокруг `0xa8d846c` + release старого |
| `0xfffffff00a8da470` | `OSUnserializeXML(buf, OSSharedPtr<OSString>&)` | то же, аргументы 0 |
| `0xfffffff00a8d4630` | **старый XML-парсер** (0x1668 B, 1434 инстр.), глобальное состояние, без размера | строки `OSUnserialize: %s near line %d`, `unexpected end of buffer`, `syntax error` |
| `0xfffffff00a8d5ea4` | **новый XML-парсер** (0x1bb4 B, 1773 инстр.), `parser_state_t`, итеративный | `OSUnserializeXML: %s near line %d`, `buildArray…buildBoolean`, `maximum object count` |
| `0xfffffff00a8d75d4` | блок внутри нового парсера: разбор `<tag attr="v">` в 32-байтные записи | вызывается 5× из `0xa8d5ea4` |
| `0xfffffff00a8d7a58` | `<data format="hex">` → байты (hex-decode, рост буфера x2) | `lsl #4`, `orr`, realloc `0xa2217b4` |
| `0xfffffff00a8d7c28` | `<data>` → байты (base64: `add w25,w8,w25,lsl #6`) | `and x8,#0x7f`, таблица `0xfffffff007028fc9` |
| `0xfffffff00a8d7df8` | `<integer>` → `OSNumber` (0x…, dec/hex, знак) | `cmp w8,#0x30 / 0x78 / 0x2d` |
| `0xfffffff00a8d7f28` | `<string>` + раскрытие `&lt; &gt; &amp;` | сравнения `0x26 0x67 0x74 0x3b` и т.д. |
| `0xfffffff00a8d812c` | установщик `*errorString` (snprintf 0x80 + `OSString::initWithCString`) | `ldr x8,[x0,#0x28]`, строка `...XML: %s near line %d` |
| `0xfffffff00a8d8238` | финализация контейнера / привязка детей (`OSDictionary::setObject` vtable+0xf0/0x100) | `ldr w8,[x19,#0x50]`, `"%u"` |
| `0xfffffff00a8d96f4` | **бинарный десериализатор** (0xd08 B, 834 инстр.) | `word & 0x7F000000` тип, `& 0xFFFFFF` данные, `kOSSerialize*` семантика |
| `0xfffffff00aa7451c` | `strcmp` (используется и для сигнатуры `"\xd3"`) | вызовы с (`buf`, `"plist"`) |
| `0xfffffff00a76d3ec` | `snprintf` (buf, 0x80, fmt, …) | все места формирования ошибок |

`__DATA`-глобалы старого парсера: буфер `0xfffffff00add71d8`, смещение `u32` `0xfffffff00add71e0`,
текст ошибки `0xfffffff00add7158` (128 B), корень `0xfffffff00add7140`, счётчик строк
`0xfffffff00ad95f14/0xad95f18`, состояние кавычки `0xfffffff00ad95f08`.

### Дизасм: 3-арг точка входа (то, что зовёт IOSurface)

```
0xfffffff00a8d8754  pacibsp
0xfffffff00a8d8768  cbz  x0, 0xa8d87d8            ; if (!buf) return 0
0xfffffff00a8d876c  cmp  x1, #4
0xfffffff00a8d8770  b.lo 0xa8d87d8                 ; if (size < 4) return 0
0xfffffff00a8d8780  adrp x0, 0x7043000
0xfffffff00a8d8784  add  x0, x0, #0xa08            ; x0 = "\xd3"  (0xfffffff007043a08: d3 00 00 00 …)
0xfffffff00a8d8788  mov  x1, x20                    ; x1 = buf
0xfffffff00a8d878c  bl   0xaa7451c                 ; strcmp("\xd3", buf)
0xfffffff00a8d8790  cbz  w0, 0xa8d87a0               ; == 0  -> binary
0xfffffff00a8d8794  ldrb w8, [x20]
0xfffffff00a8d8798  cmp  w8, #0xd4
0xfffffff00a8d879c  b.ne 0xa8d87cc                  ; != 0xd4 -> XML
0xfffffff00a8d87a0  … mov w4,#0 ; mov x5,x19
0xfffffff00a8d87c8  b    0xa8d96f4                 ; binary parser(buf,size,...,err), требует 4-байт. выравнивания (tst x22,#3)
0xfffffff00a8d87cc  sub  x8, x21, #1
0xfffffff00a8d87d0  ldrb w8, [x20, x8]
0xfffffff00a8d87d4  cbz  w8, 0xa8d87ec                ; require buf[size-1] == 0
0xfffffff00a8d87d8  mov  x0, #0                      ; иначе return 0
0xfffffff00a8d87e8  retab
0xfffffff00a8d87ec  mov  x0, x20                    ; buf
0xfffffff00a8d87f0  mov  x1, #0
0xfffffff00a8d87f4  mov  x2, #0
0xfffffff00a8d87f8  mov  w3, #0
0xfffffff00a8d87fc  mov  x4, x19                     ; err
0xfffffff00a8d8810  b    0xa8d846c                 ; XML core — РАЗМЕР ОТБРОШЕН
```

Ключевой факт: **`size` используется ровно дважды** — проверка `size >= 4` и проверка
`buf[size-1] == 0`. Дальше размер не передаётся никуда; в `parser_state_t` поля размера нет
(см. §2). Т.е. вся защита XML-ветки — «последний байт объявленного буфера равен нулю».

Про бинарную ветку: `0xaa7451c` — это `strcmp` (побайтовое сравнение до `NUL` первого
аргумента), поэтому `strcmp("\xd3", buf)` вырождается в проверку `buf[0] == 0xd3`; второй
вариант — `buf[0] == 0xd4` (флаг сохраняется в `[sp+0x4c]` в `0xa8d97a0` и меняет разбор).
Семантику различия `0xd3`/`0xd4` установить не удалось (см. §6).

---

## 2. Ограничения парсеров

### 2.1 `parser_state_t` (0x40 байт, `kalloc_type` var `0xfffffff007c7c2d0`)

Создаётся в `0xfffffff00a8d846c`:

```
0xfffffff00a8d84c0  str  x24, [x19]        ; +0x00 = buffer
0xfffffff00a8d84c4  ldr  d0, [0x700db98]   ; = 0x0000000100000000
0xfffffff00a8d84cc  str  d0, [x19, #8]     ; +0x08 = offset (u32) = 1, +0x0c = line = 0
0xfffffff00a8d84d0  stp  xzr, xzr, [x19,#0x10]
0xfffffff00a8d8550  stp  x24, x23, [x19,#0x20]   ; +0x20 error OSString, +0x28 errorString**
0xfffffff00a8d8558  str  q0, [x19, #0x30]       ; +0x30 ptr, +0x38 objcount, +0x3c livecount
0xfffffff00a8d855c  stp  x22, x21, [x19,#0x48]   ; +0x48 func, +0x50 ref
0xfffffff00a8d8560  str  w20, [x19, #0x40]      ; +0x40 flags
```

Полей: `buffer`, `offset u32`, `line u32`, список объектов `+0x18`, `error obj`,
`errorString**`, `+0x30`, `objcount u32`, `livecount u32`, `flags`, `func`, `ref`.
**Поля «длина буфера» нет** — это структурный факт, а не вывод из отдельных проверок.

### 2.2 Таблица проверок

| проверка | есть? | значение / где | адрес |
|---|---|---|---|
| длина входного буфера в XML-парсере | **нет** | парсер читает до `NUL`/`'<'`; поле размера отсутствует | — |
| `size` в 3/6-арг входе | только `size>=4` и `buf[size-1]==0` | — | `0xa8d876c`, `0xa8d87cc` |
| переполнение `size_t`→`u32` в парсере | да, **смещение 32-битное** | `ldr w8,[x19,#8]` + `sxtw x9,w8` | `0xa8d5f8c-0xa8d5fb0`, `0xa8d7a9c-0xa8d7aa4` и др. |
| max число объектов | **есть** | `0x1FFFF` (131071), счётчик `state+0x38` | `0xa8d6a74`…`0xa8d6a98`, `0xa8d6b78`, `0xa8d6c3c` |
| max «живых» объектов | **есть** | `0x10000` (65536), счётчик `state+0x3c` | `0xa8d6b30-0xa8d6b64`, `0xa8d6c3c-0xa8d6c5c` |
| глубина рекурсии | **нет счётчика** | парсер итеративный; вложенность в связном списке `state+0x18`, ограничена только 131071 объектом | `0xa8d650c-0xa8d65d0` (attach/pop) |
| стек парсера | фикс. | кадр `0x1080`: `0x640` состояние-стек, `0x400`+`0x400` буферы записей, `0xc00`… | `0xa8d5ed8-0xa8d5ff8` |
| имя тега | **31 симв.** | `cmp x8,#0x1f` → ошибка | `0xa8d7718` |
| имя атрибута | **≤30** | `cmp x8,#0x1e` → ошибка | `0xa8d77ec` |
| значение атрибута | **≤30** | `cmp x10,#0x1e` → ошибка | `0xa8d78cc` |
| число атрибутов | **≤32 записи** | `cmp w11,#0x1e; b.le` | `0xa8d7928-0xa8d7938` |
| запись атрибутов | 32×32 B | `add x12,x3,x11,lsl #5` (x3 = sp+0xc00) | `0xa8d77d4`, `0xa8d78b4` |
| строка без NUL | обрабатывается | `<string>`: длина = до `'<'` или `NUL` (`cbz w11`), аллокация `len+1` | `0xa8d7f40-0xa8d7f90`, `0xa8d7fb4-0xa8d7fd4` |
| сущности `&lt; &gt; &amp;` | проверяются | сравнения `#0x26/#0x67/#0x6c/#0x61/#0x74/#0x70/#0x3b` | `0xa8d8028-0xa8d80f8` |
| индекс ссылки (`IDREF`) | **есть** | «forward reference detected» / «maximum object reference count» | `0xa8d7514`, `0xa8d7554` |
| «duplicate dictionary key» | **есть** | `OSDictionary` set + проверка | `0xa8d73b4` |
| бинарный: границы на каждом слове | **есть** | `cmp x26,x10; b.hi` (x10 = size) | `0xa8d983c`, `0xa8d9978`, `0xa8d99d8`, `0xa8d9b98`, `0xa8d9c4c` |
| бинарный: NUL-терминация строки внутри буфера | **есть** | `sub w8,w23,#1; ldrb [x27,w8]; cbnz → fail` | `0xa8d9c54-0xa8d9c5c` |
| бинарный: индекс объекта | **есть** | `cmp w22,w23; b.hs → fail` | `0xa8da2a4-0xa8da2a8`, `0xa8da2f4-0xa8da2fc` |
| бинарный: выравнивание | **есть** | `tst x22,#3` | `0xa8d9770` |
| бинарный: предел тега | **есть** | `cmp w23,#0x3f; b.hi → fail` | `0xa8da29c` |

### 2.3 Дизасм: новые проверки количества объектов

```
0xfffffff00a8d6a74  ldr  w8, [x19, #0x38]      ; objcount
0xfffffff00a8d6a78  add  w9, w8, #1
0xfffffff00a8d6a7c  str  w9, [x19, #0x38]
0xfffffff00a8d6a80  mov  w9, #0x1ffff
0xfffffff00a8d6a84  cmp  w8, w9
0xfffffff00a8d6a88  …
0xfffffff00a8d6a94  b.lt …                       ; else -> 0xa8d7454 "maximum object count"
```
```
0xfffffff00a8d6b30  ldr  w8, [x19, #0x3c]       ; live objects
0xfffffff00a8d6b34  add  w8, w8, #1
0xfffffff00a8d6b38  str  w8, [x19, #0x3c]
0xfffffff00a8d6b3c  … (retain объекта) …
0xfffffff00a8d6b5c  ldr  w8, [x19, #0x3c]
0xfffffff00a8d6b60  cmp  w8, #0x10, lsl #12    ; 0x10000
0xfffffff00a8d6b64  b.ge 0xa8d7550             ; -> ошибка
```

### 2.4 Дизасм: чтение буфера по 32-битному смещению

```
0xfffffff00a8d5f88  adrp x10, 0x7028000
0xfffffff00a8d5f8c  add  x10, x10, #0xfba       ; таблица классов символов
0xfffffff00a8d5f90  ldrsb w8, [x10, x8]
0xfffffff00a8d5f94  mov  x21, x9
0xfffffff00a8d5f98  cmp  x24, #0x18b            ; накопление символов тега (шаг 2 байта)
0xfffffff00a8d5fa0  strh w8, [x28, x24]
0xfffffff00a8d6048  … 
0xfffffff00a8d6004  ldr  x9, [x19]              ; buffer
0xfffffff00a8d6008  ldr  w8, [x19, #8]          ; offset (u32)
0xfffffff00a8d600c  sxtw x10, w8                ; <-- знаковое расширение
0xfffffff00a8d6010  add  x11, x9, x10
0xfffffff00a8d6014  ldrb w27, [x11]             ; чтение без сравнения с длиной
```
То же в старом парсере (глобальное состояние):
```
0xfffffff00a8d4788  adrp x8, 0xadd7000
0xfffffff00a8d478c  ldr  x8, [x8, #0x1d8]       ; global buffer
0xfffffff00a8d4790  sxtw x9, w11                ; global offset (u32)
0xfffffff00a8d4794  add  x12, x8, x9
0xfffffff00a8d4798  ldrb w12, [x12]
0xfffffff00a8d479c  cmp  w12, #0x20
...
0xfffffff00a8d47b8  ldrb w12, [x8, x9]          ; цикл до NUL
```
Ни в одном месте нет сравнения с длиной — её просто нет в состоянии.

---

## 3. Цепочка IOSurface → парсер

Код `IOSurfaceRootUserClient`/`IOSurfaceTransaction` лежит в `__TEXT_EXEC` около
`0xfffffff009c3xxxx` (строки — `0xfffffff00789cxxx`, `0xfffffff0078axxx`).

```
io_connect_method (MIG, OOL descriptor)
   -> IOUserClient::externalMethod            (в кеше не разбирался, см. §6)
      -> s_create_surface         0xfffffff009c38890   (action, лог-префикс "s_create_surface")
         -> create_surface        0xfffffff009c3ab8c   (0x534 B)
            -> OSUnserializeXML(buf,size,NULL)  0xfffffff00a8d8754   через PLT-стаб 0xfffffff009c49764
               (GOT-слот 0xfffffff00806c618 = 0x80110000038d4754 -> 0xfffffff00a8d8754)
            -> OSUnserializeXML core 0xfffffff00a8d846c -> парсер 0xfffffff00a8d5ea4
            -> dynamic_cast к OSDictionary (metaClass 0xfffffff00806c9c8)
            -> IOSurfaceRoot::createSurface(dict) / применение свойств
```

### 3.1 `s_create_surface` — откуда берутся buf и size

```
0xfffffff009c388ac  ldr  x8, [x2, #0x20]        ; args->scalarInput
0xfffffff009c388b0  ldr  x20, [x8]              ; parentID (u64)
0xfffffff009c388b4  lsr  x8, x20, #0x20
0xfffffff009c388b8  cbz  x8, 0x9c388f4          ; parentID должен влезать в 32 бита
0xfffffff009c388f4  mov  x22, x2                ; args
0xfffffff009c388fc  ldr  x0, [x2, #0x40]        ; args->structureInputDescriptor
0xfffffff009c38900  cbz  x0, 0x9c38974          ; нет дескриптора -> inline-ветка
0xfffffff009c38914  ldr  x8, [x16, #0xe8]!      ; vtable+0xe8: createMappingInTask(...)
0xfffffff009c38918  mov  w1, #0x1000
0xfffffff009c38920  blraa x8, x16
0xfffffff009c38924  cbz  x0, 0x9c38a08          ; "failed to map shmem"
0xfffffff009c3893c  ldr  x8, [x16, #0x78]!      ; vtable+0x78 = getAddress()
0xfffffff009c38944  blraa x8, x16               ;  -> x23 = buf
0xfffffff009c38960  ldr  x8, [x16, #0xb0]!      ; vtable+0xb0 = getLength()
0xfffffff009c38968  blraa x8, x16               ;  -> x0 = u64 length
0xfffffff009c3896c  mov  x4, x0                  ; size (64-bit!)
0xfffffff009c389d4  mov  x2, x20                 ; parentID
0xfffffff009c389d8  bl   0x9c3ab8c              ; create_surface(this, buf, parentID, args+0x58, size)
…
0xfffffff009c38974  mov  x19, #0                  ; inline-ветка
0xfffffff009c38978  ldr  w4, [x22, #0x38]        ; args->structureInputSize (u32)
0xfffffff009c3897c  ldr  x23, [x22, #0x30]       ; args->structureInput
0xfffffff009c38980  cmp  x23, #0
0xfffffff009c38984  ccmp w4, #0, #4, ne
0xfffffff009c38988  b.ne 0x9c389c8              ; buf && size, иначе "no args"
```

### 3.2 `create_surface` — 64-битная длина усекается до 32 бит

```
0xfffffff009c3abbc  ldr  w8, [x0, #0x128]
0xfffffff009c3abc0  cmp  w8, #4, lsl #12       ; лимит клиентов 0x4000
0xfffffff009c3abc4  b.lo 0x9c3abfc              ; иначе "exceeded client limit"
0xfffffff009c3abfc  cbz  x1, 0x9c3b098          ; if (!buf) return
0xfffffff009c3ac00  mov  x24, x3
0xfffffff009c3ac04  mov  x22, x2                 ; parentID
0xfffffff009c3ac08  mov  x23, x0                 ; this
0xfffffff009c3ac0c  mov  w8, w4                  ; <-- size = (uint32_t) size
0xfffffff009c3ac10  mov  x0, x1                  ; buf
0xfffffff009c3ac14  mov  x1, x8                  ; size (zero-extended u32)
0xfffffff009c3ac18  mov  x2, #0                  ; errorString = NULL
0xfffffff009c3ac1c  bl   0x9c49764               ; OSUnserializeXML(buf, size, NULL)
0xfffffff009c3ac20  cbz  x0, 0x9c3b098           ; NULL -> выход
0xfffffff009c3ac24  mov  x20, x0
0xfffffff009c3ac28  adrp x8, 0x806c000
0xfffffff009c3ac2c  ldr  x8, [x8, #0x9c8]          ; указатель на OSMetaClass OSDictionary
0xfffffff009c3ac30  ldr  x1, [x8]
0xfffffff009c3ac34  bl   0x9c498d4                ; dynamic_cast
0xfffffff009c3ac38  cbz  x0, 0x9c3ac88           ; нет -> ошибка
```

Итог: **обработчик сам никакого верхнего предела на размер не накладывает** — только
`size != 0`, `size >= 4` и `buf[size-1] == 0` (внутри `0xa8d8754`). Для дескриптора длина
`getLength()` (u64) усекается до 32 бит по `0x9c3ac0c`.

Дополнительно найдены ещё 4 места в IOSurface, где в парсер уходит буфер со смещением
(похоже на разбор значений `set_value`/транзакций; точный селектор не подтверждён):

| функция | что парсит |
|---|---|
| `0xfffffff009c3c3bc` | `OSUnserializeXML(buf+0xc, len-0xc, NULL)` (`0x9c3c3f8-0x9c3c408`) |
| `0xfffffff009c3c800` | тонкая обёртка (0xd8 B) |
| `0xfffffff009c3d564` | `OSUnserializeXML(buf+0x10, len-0x10, NULL)` (`0x9c3d5a0-0x9c3d5b0`) |
| `0xfffffff009c3e388` | вариант с другим заголовком |

---

## 4. Самое подозрительное (с дизасмом)

### 4.1 Размер во входной точке — только проверка последнего байта, дальше size отбрасывается

`0xfffffff00a8d8754` (§1). Практический смысл: корректность всей границы чтения держится
на одном байте `buf[size-1] == 0` и на том, что парсер действительно останавливается на
`NUL`. Любой вызов, где `size` больше реально отображённого буфера, даёт OOB-чтение
длиной до первого нуля. Обратная ситуация (size меньше) безопасна. Это не «баг в парсере»,
а **контракт API, который легко нарушить**: в самом парсере нет ни одного сравнения с длиной.

### 4.2 Старый 2-арг путь всё ещё экспортируется и вообще не имеет размера

`0xfffffff00a8d5c98` → `0xfffffff00a8d4630`. В старом парсере нет ни размера, ни
проверки границ — только `NUL` и `'<'`:

```
0xfffffff00a8d4788  adrp x8, 0xadd7000
0xfffffff00a8d478c  ldr  x8, [x8, #0x1d8]     ; global buffer
0xfffffff00a8d4790  sxtw x9, w11               ; global offset u32
0xfffffff00a8d4798  ldrb w12, [x12]            ; чтение
0xfffffff00a8d47d4  cmp  w12, #0x23            ; '#' комментарий
0xfffffff00a8d47f8  ...                        ; и т.д., без сравнений с длиной
```

Кто вызывает (27.2): `0xfffffff00a907efc`, `0xfffffff00a907f88`, `0xfffffff00a951d64`,
`0xfffffff00a9dd4f0` (IOFindBSDRoot — статические plist-строки). Пользовательских буферов
среди них не найдено, но сама функция остаётся достижимой для любого kext'а ядра.

### 4.3 Смещение 32-битное и знаковое — граница 2 ГиБ

`ldr w8,[x19,#8]` + `sxtw` (`0xa8d6008-0xa8d6010`, `0xa8d7a9c-0xa8d7aa4`,
`0xa8d7f44-0xa8d7f48`). Для входа > 2 ГиБ смещение становится отрицательным и чтение
уходит *перед* буфером. Через `structureInputSize` (u32) это требует ≥ 2 ГиБ inline — на
практике недостижимо; через дескриптор длина усекается до 32 бит, т.е. теоретически
возможно при `getLength()` ~4 ГиБ + отображении. Помечено как **теоретическое**, не
подтверждено как достижимое.

### 4.4 IOSurface: парсинг до какой-либо валидации содержимого + усечение длины

`create_surface` (`0x9c3ab90`) сначала парсит произвольный plist из `structureInput`
(до 4 ГиБ по контракту), затем проверяет только класс результата (OSDictionary) и уже
потом применяет свойства. Лимит клиентов (`[this+0x128] < 0x4000`) проверяется до парсинга,
лимита на размер входа нет. Усечение `(uint32_t)getLength()` — `0x9c3ac0c`.

Что это даёт атакующему: до `0x1FFFF` объектов на один вызов, каждый — `object_t` (0x40 B) +
`OSArray/OSDictionary/OSString`; это десятки МБ ядерной памяти на один вызов и до 0x4000
клиентов. Амплификация по памяти, не переполнение.

### 4.5 «Тихие» ветки: `create_surface` зовёт парсер с `errorString = NULL`

`0x9c3ac18: mov x2,#0`. Ошибки разбора не логируются и не возвращаются вызывающему —
единственный признак отказа это `NULL` (→ `kIOReturn` из `0x9c3b098`). Для аудита это
означает, что эксплуатация не оставляет следов в логе (`s_create_surface` логирует только
случаи `no args`/`failed to map shmem`/`invalid parentID`).

---

## 5. Дифф 27.0 ↔ 27.2

Метод: нормализованный дизасм (capstone), маскируются `adrp`/`add`-page/`ldr`-page/`b`/`bl`/
`b.cond`/`cbz`/`tbz` (цели и page-смещения), затем sha256 по последовательности
`mnemonic op_str`. Это ловит любые изменения кода кроме перестановки адресов.

| функция | 27.2 | 27.0 | insns | sha256 (norm) | итог |
|---|---|---|---|---|---|
| `OSUnserializeXML(buf,err)` 2-арг | `0xa8d5c98` | `0xa895eac` | 131 | `d3fd6183c68c5406…` | **идентично** |
| core `(buf,func,ref,flags,err)` | `0xa8d846c` | `0xa898680` | 131 | `563f0d0ed03b887f…` | **идентично** |
| stub 2-арг → core | `0xa8d8660` | `0xa898874` | 7 | `f1e48839676feab2…` | **идентично** |
| sized 6-арг | `0xa8d8678` | `0xa89888c` | 55 | `079e5ea444fff9cd…` | **идентично** |
| sized 3-арг | `0xa8d8754` | `0xa898968` | 50 | `1cca973dda652cba…` | **идентично** |
| `OSSharedPtr` вариант 1 | `0xa8da3fc` | `0xa89a610` | 29 | `7c19e227011fdd44…` | **идентично** |
| `OSSharedPtr` вариант 2 | `0xa8da470` | `0xa89a684` | 32 | `b429a8e1f7bda811…` | **идентично** |
| бинарный парсер | `0xa8d96f4` | `0xa899908` | 834 | `320e87e6f9b524c8…` | **идентично** |
| старый XML-парсер | `0xa8d4630` | `0xa894844` | 1434 | `726195cad42f9a5e…` | **идентично** |
| новый XML-парсер | `0xa8d5ea4` | `0xa8960b8` | 1773 | `65f5da4ebe6edf51…` | **идентично** |
| error setter | `0xa8d812c` | `0xa898340` | 67 | `f229a2116714869d…` | **идентично** |
| финализация/attach | `0xa8d8238` | `0xa89844c` | 141 | `ea07d557b0a09424…` | **идентично** |
| hex→data | `0xa8d7a58` | `0xa897c6c` | 116 | `38320f97ef744e5a…` | **идентично** |
| base64→data | `0xa8d7c28` | `0xa897e3c` | 192 | `fda2bdd8b2328663…` | **идентично** |
| number | `0xa8d7df8` | `0xa89800c` | 76 | `d077cfed6c873a8c…` | **идентично** |
| string+entities | `0xa8d7f28` | `0xa89813c` | 129 | `06767a3832309c8c…` | **идентично** |
| `s_create_surface` | `0x9c38890` | `0x9bfc8e8` | 154 | — | **идентично** |
| `create_surface` | `0x9c3ab8c` | `0x9bfebe4` | 333 | `64c8fa844df3c08c…` | **идентично** |

Дополнительно:
* Блоб строк ошибок libkern (`OSUnserialize:`, `OSUnserializeXML:`, `buildArray…buildBoolean`,
  `maximum object count`, `forward reference detected`, `duplicate dictionary key`,
  `memory exhausted`) **побайтово совпадает** в 27.0 и 27.2 (`ba == bb` на 0x400 байтах вокруг
  `OSUnserialize: %s`), и новый парсер в обоих билдах ссылается на одни и те же строки
  (41 ссылка, отсортированные списки совпадают).
* GOT-слот в 27.0 `0xfffffff00805efb8` = `0x8011000003894968` → `0xfffffff00a898968`
  (= sized-3), в 27.2 `0xfffffff00806c618` = `0x80110000038d4754` → `0xfffffff00a8d8754`.
  То есть **IOSurface в обоих билдах вызывает один и тот же вариант с размером**.

**Вывод по диффу: код десериализатора (XML старый + новый, бинарный, все обёртки) и весь
путь `create_surface` в 27.2 не менялись относительно 27.0.** Смещения: libkern-кластер
`27.0 = 27.2 − 0x3FDEC`, IOSurface `27.0 = 27.2 − 0x3AFA8`.

---

## 6. Что не подтверждено

1. **Таблица диспетчеризации `IOSurfaceRootUserClient`** (соответствие «селектор 0 →
   `s_create_surface`», селекторы 27/28 → `set_value`) в кеше не найдена: на
   `0xfffffff009c38890` и `0xfffffff009c3ab8c` нет ни одного xref'а — ни в `__DATA_CONST`,
   ни в `__DATA`, ни в тексте, ни как 36-битный chained-fixup, ни как 32-битная дельта,
   ни как PAC-подписанный указатель. Привязка сделана по лог-префиксам `"s_create_surface"` /
   `"create_surface"` и по сигнатуре `(this, buf, parentID, x3, u32 size)`. Поэтому
   `strIn = -1` из таблицы методов проверить не удалось.
2. Лимит `structureInput` в `IOUserClient::externalMethod` / MIG `io_connect_method` не
   разбирался (вне фокуса), поэтому утверждение «до размера OOL-дескриптора» взято из
   постановки задачи и не проверено по коду.
3. Точные имена функций — выведены из строк (`s_create_surface`, `create_surface`,
   `buildArray`…); табличных символов в кеше нет.
4. Достижимость 2-ГиБ сценария (§4.3) не проверялась.
