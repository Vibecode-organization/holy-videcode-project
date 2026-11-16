# GPU / IOMobileFramebuffer — внешние методы, 27.2 (24B115)

Цель: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`, 67 239 936 B, Mach-O filetype 12.
Скрипты и промежуточные данные: `/home/femboychik/work/parse_gpu/` (`kc.py`, `kmap.py`, `xrefs4.py`,
`tabs2.py`, `metaclass.py`, `dump_tables.py`; `tables_ref.json`, `tables_target.json`, `metaclass.json`,
`handlers_probe.json`, `xreffull.pkl`, `selectors_*.tsv`).

---

## 0. Метод (что именно доказано, а что — вывод)

1. `__PRELINK_INFO` — plist с 267 kext'ами. Раскладка в этом кеше **не** fileset: `LC_FILESET_ENTRY` = 0,
   `LC_SYMTAB` = 0 (nsyms 0). Символов нет вообще, все имена — производные.
2. Каждый kext в `__PRELINK_TEXT` — самостоятельный Mach-O. Парсинг его заголовка даёт **точные границы
   всех его сегментов** (`__TEXT`, `__TEXT_EXEC`, `__DATA_CONST`, `__DATA`) → `kmap.json`. Это опора для
   привязки адресов к kext'ам без символов.
3. Индекс перекрёстных ссылок: полный проход по `__TEXT_EXEC` (10 784 768 слов), `adrp` (614 395 шт.) с
   эмуляцией цепочек `add #imm` / `add #imm, lsl #12` (до 8 инструкций) → 1 107 881 пара `(цель, pc)`,
   207 332 уникальных цели (`xreffull.pkl`). **Грабля подтверждена: imm у `adrp` знаковый, маскировать.**
4. Таблицы искались не «по паттерну в данных», а **по факту ссылки из кода**: кандидат = цель `adrp/add`,
   которая сама выглядит как начало `IOExternalMethodDispatch`. Иначе в кеше ловятся десятки мёртвых
   копий (см. §6).
5. Привязка класс → таблица сделана через **конструкторы `OSMetaClass`**: в коде ищется
   `adrp/add x1,<строка имени>; ldr x2,[<слот суперкласса>]; mov w3,#<размер>; bl <OSMetaClass ctor>`.
   Это даёт имя класса **и размер экземпляра**. Далее размер экземпляра сверяется с максимальным смещением,
   которое диспетчер/обработчики читают от `x0`. Совпадение = привязка доказана, а не угадана.

### Формат записей таблиц (проверено по коду обработчиков)

Два вида, оба встречаются в этом кеше:

```
stride 0x18  IOExternalMethodDispatch:      fn(8) sIn(4) strIn(4) sOut(4) strOut(4)
stride 0x28  IOExternalMethodDispatch2022:  fn(8) sIn(4) strIn(4) sOut(4) strOut(4) [0x18..0x27 = 0]
```

* `strIn/strOut == 0xFFFFFFFF` — **sentinel «размер не проверяется»**. `IOUserClient::externalMethod`
  пропускает сравнение, и единственный контроль остаётся внутри обработчика.
* Хвост 0x18..0x27 во всех найденных 2022-таблицах нулевой (поле options/entitlement не используется).

### `IOExternalMethodArguments` — раскладка, восстановлена из кода (не из документации)

| off | поле | чем подтверждено |
|---|---|---|
| +0x10 | `asyncReference[0]` | диспетчер IOGPU 0x994a1f8: `ldr x9,[x2,#0x10]; cbnz -> kIOReturnMessageTooLarge` |
| +0x20 | `scalarInput` (u64*) | IOSurface 0x9c388ac, IOGPU 0x9948094 |
| +0x28 | `scalarInputCount` | — |
| +0x30 | `structureInput` | IOSurface 0x9c38a70, IOGPU 0x994809c |
| +0x38 | `structureInputSize` (u32) | `ldr w3,[x2,#0x38]` в обоих |
| +0x40 | `structureInputDescriptor` | IOSurface 0x9c38b5c (`cbz` → inline-ветка) |
| +0x48 | `scalarOutput` | IOSurface 0x9c38af8 `str xzr,[x8]` |
| +0x58 | `structureOutput` | IOSurface 0x9c38f88, IOGPU 0x994734c |
| +0x60 | `structureOutputSize` (u32, in/out) | IOSurface sel13 пишет туда 0x28 |
| +0x68 | `structureOutputDescriptor` | IOSurface 0x9c38d20 |
| +0x70 | `structureOutputDescriptorSize` | IOSurface 0x9c38d70 |

---

## 1. Таблица классов: адрес таблицы, число селекторов

| kext | класс | sizeof | ctor `OSMetaClass` | таблица | stride | sel | диспетчер |
|---|---|---|---|---|---|---|---|
| `com.apple.iokit.IOSurface` | **IOSurfaceRootUserClient** | 0x148 | 0x9c38400 | **0xfffffff008068b90** | 0x28 | **17** | 0x9c3ee10 |
| | то же, restricted-вариант | | | 0xfffffff0080694f0 | 0x28 | 17 | 0x9c3ee10 |
| `com.apple.iokit.IOGPUFamily` | **IOGPUDeviceUserClient** | 0x130 | 0x9946b6c | **0xfffffff007fea200** | 0x18 | **56** | 0x994a1e0 |
| | то же, restricted-вариант | | | 0xfffffff007fea740 | 0x18 | 56 | 0x994a1e0 |
| `com.apple.iokit.IOGPUFamily` | IOGPUMemoryInfoUserClient | 0xe8 | 0x997e404 | 0xfffffff007fef7c0 | 0x18 | 3 | 0x997e894 |
| `com.apple.driver.AppleH11ANEInterface` | H11ANEInDirectPathClient † | 0x1a0 | 0x89c02f0 | 0xfffffff007dc4130 | 0x28 | 11 | 0x89c1888 |
| `com.apple.driver.AppleH11ANEInterface` | H11ANEInDirectPathClient † | 0x1a0 | 0x89c02f0 | 0xfffffff007dc43b0 | 0x28 | 2 | 0x89c1a8c |
| `com.apple.driver.AppleH11ANEInterface` | ANEPrivilegedVMAccessUserClient † | 0xd8 | 0x8a7a938 | 0xfffffff007dc8a90 | 0x28 | 4 | 0x8a03f48 |
| `com.apple.driver.AppleJPEGDriver` | AppleJPEGWrapperControlV14 † | 0x30 | 0x8c7b8c4 | 0xfffffff007e293c0 | 0x28 | 6 | 0x8c8fc34 |
| `com.apple.driver.AppleM2ScalerCSCDriver` | **IOSurfaceAcceleratorClient** | — | (имя в коде 0x8d13554) | 0xfffffff007e56470 | 0x28 | **3** | — |

† класс по kext'у и размеру экземпляра; точная привязка таблицы к конкретному из четырёх
`*Client`-классов ANE (все 0x1a0) и к `AppleJPEGWrapperControlV14` — **не подтверждено**
у них нет своего `getTargetAndMethodForIndex` в открытом виде.

Диспетчеры (для справки):

```
; IOSurfaceRootUserClient, 0x9c3ee10
 adrp x8, 0x8068000 ; add x8,x8,#0xb90        ; базовая таблица
 adrp x10,0x8069000 ; add x10,x10,#0x4f0      ; restricted-таблица
 ldrb w9,[x0,#0x127] ; tst w9,#1              ; == entitlement gpu-restricted
 csel x3, x10, x8, ne                         ; есть entitlement -> restricted
 mov  w4,#0x3c ; mov x5,x0 ; mov x6,#0 ; b IOUserClient::externalMethod

; IOGPUDeviceUserClient, 0x994a1e0
 ldrb w9,[x0,#0x100] ; tbz w9,#0 -> 0xe00002c2 ; клиент должен быть started
 cmp  w1,#0x37 ; b.hi -> 0xe00002d8            ; 56 селекторов
 ldr  x9,[x2,#0x10] ; cbnz -> 0xe00002d8       ; asyncReference должен быть 0
 ldrb w8,[x0,#0x103] ; tst w8,#1               ; == entitlement gpu-restricted
 csel x3, tab_0x7fea740, tab_0x7fea200, ne
```

---

## 2. Классы из списка, у которых таблиц `IOExternalMethodDispatch` НЕТ

Это не «не нашли» — это проверено: в кеше 120 реально используемых таблиц, и ни одна не лежит в
`__DATA_CONST`/`__DATA` этих kext'ов.

| класс | sizeof | ctor | вердикт |
|---|---|---|---|
| `IOMobileFramebufferUserClient` (`com.apple.iokit.IOMobileGraphicsFamily`) | **0x958** | 0x9aa0f48 | диспетчеризация ручная (`switch` по селектору). Не разобрана — **не подтверждено** |
| `AppleKeyStoreUserClient` (`com.apple.driver.AppleSEPKeyStore`) | 0x118 | 0x914cbbc | ручная. Не разобрана — **не подтверждено** |
| `AGXDeviceUserClient` (`com.apple.AGXG14P`) | 0x138 | 0x819ef04 | ни таблицы, ни `cmp w?,#N / b.hi` в 0xb1e70 байтах текста AGX. Поверхность AGX идёт через `IOGPUDeviceUserClient` (см. §5) |
| `IOSurfaceSendRight` / `IOSurfaceWiredSendRight` | 0x28 | 0x9c470c8 / 0x9c476e0 | не user client, методов нет |
| `IOSurfaceAcceleratorClient` (`AppleM2ScalerCSCDriver`) | — | 0x8d13554 | таблица есть, 3 селектора, **только скаляры** |

Классов **`AGXSharedUserClient`, `IOAccelContext`, `IOAccelContext2`,
`AppleVirtIONeuralEngineDeviceUserClient` в этом кернелкаше не существует**. Их имена встречаются
ровно в одном месте — в скомпилированном профиле sandbox (`com.apple.security.sandbox`, `__TEXT`
0x79656d3 / 0x79e1a67 / 0x79de03b), и ни одна не имеет xref из кода. То есть строки в `require-any`
списке профиля есть, а открывать нечего.

---

## 3. IOSurfaceRootUserClient — 17 селекторов (таблица 0xfffffff008068b90)

Гейты (из `initWithTask`, 0x9c3a2f0):

```
[+0x122] = hasEntitlement("com.apple.private.iosurfaceinfo")
[+0x127] = hasEntitlement("com.apple.private.gpu-restricted")
        || hasEntitlement("com.apple.developer.gpu-restricted")   -> выбор таблицы
[+0x123] = 0
[+0x126] = ([+0x122] | hasEntitlement("com.apple.private.IOSurface.protected-access")) & 1
```

| sel | fn | sIn | strIn | sOut | strOut | что делает (по коду) | вердикт |
|---|---|---|---|---|---|---|---|
| 0 | 0x9c3888c | 1 | **UNCHECKED** | 0 | 0xc68 | `s_create_surface`: scalarInput[0] (hi32==0) = id; `OSUnserializeXML(ptr,len)`; лимит 0x4000 поверхностей на клиент | **подозрительно** |
| 1 | 0x9c38a5c | 1 | 0 | 0 | 0 | скаляр только | безопасно |
| 2 | 0x9c38a6c | 0 | 0xc | 0 | 0xc68 | (in,out,sizeof(out),&outsz) → 0x9c3b3ac | безопасно (точный 0xc) |
| 3 | 0x9c38a88 | 0 | 0xc | 0 | 4 | → 0x9c3b58c | безопасно |
| 4 | 0x9c38aa4 | 1 | 0 | 0 | 0xc68 | по id | безопасно |
| 5 | 0x9c38ab8 | 2 | 0 | 0 | 0 | по id | безопасно |
| 6 | 0x9c38acc | 0 | 0x20 | 0 | 0xc68 | → 0x9c3bb20 | безопасно |
| 7 | 0x9c38adc | 2 | 0 | 0 | 0xc68 | → 0x9c3bf44 | безопасно |
| 8 | 0x9c38af4 | 1 | 0 | 1 | 0 | по id, out=0 | безопасно |
| 9 | 0x9c38b2c | 0 | **UNCHECKED** | 0 | 4 | 12-байтный заголовок (id) + `OSUnserializeXML(ptr+0xc, len-0xc)`; **min len 0xd**; принимает descriptor | **подозрительно** |
| 10 | 0x9c38c44 | 0 | **UNCHECKED** | 0 | **UNCHECKED** | in+out, оба могут быть descriptor'ами; **min 0xd в обе стороны** | **подозрительно** |
| 11 | 0x9c38e54 | 0 | **UNCHECKED** | 0 | 4 | descriptor + min 0xd → 0x9c3c9c0: id из `*(u32*)ptr`, затем строка с `ptr+0xc`, требует `ptr[0xc]!=0` и `ptr[len-1]==0` | подозрительно (по поверхности) |
| 12 | 0x9c38f6c | 3 | 0 | 0 | 0 | скаляры | безопасно |
| 13 | 0x9c38f84 | 0 | 0 | 0 | 0x28 | копирует 0x28 байт свойств в structureOutput, пишет 0x28 в +0x60 | безопасно |
| 14 | 0x9c38fcc | 2 | 0 | 0 | 0 | | безопасно |
| 15 | 0x9c38fe0 | 2 | 0 | 0 | 0 | | безопасно |
| 16 | 0x9c38ff4 | 1 | 0 | 1 | 0 | | безопасно |

**restricted-вариант (0x80694f0)**: селекторы **4,5,6,7,8,16** подменены на 0x9c3a1dc =
`mov w0,#0x2e2; movk w0,#0xe000,lsl#16; ret` = `kIOReturnNotPermitted`.
То есть процесс с `com.apple.developer.gpu-restricted` теряет эти шесть методов.

---

## 4. IOGPUDeviceUserClient — 56 селекторов (таблица 0xfffffff007fea200)

Гейты: `[+0x100]` (started) обязателен; `[+0x103]` = `hasEntitlement("com.apple.private.gpu-restricted")`
(проверка 0x99658e8) → restricted-таблица.

В таблице 56 записей; ниже — все, у которых есть structure-вход или непустой structure-выход
(остальные чисто скалярные, `strIn=0/strOut=0`).

| sel | fn | sIn | strIn | sOut | strOut | что делает | вердикт |
|---|---|---|---|---|---|---|---|
| 0 | 0x9947330 | 0 | 0 | 0 | 0x40 | отдаёт 0x40 байт info, затем виртуальный вызов через `g+0x550` | безопасно |
| 1 | 0x9947444 | 0 | 0 | 0 | 0x40 | то же | безопасно |
| 2 | 0x9947478 | 0 | 0 | 0 | 0x218 | дамп 0x218 байт | безопасно |
| 6 | 0x99476bc | 0 | **UNCHECKED** | 0 | 0x10 | | подозрительно (см. §5.5) |
| 8 | 0x9947a54 | 0 | **UNCHECKED** | 0 | **UNCHECKED** | **`len >= 0x58`** на входе; выход отдаётся в 0x99669e0 без видимой проверки | вход безопасно, выход — **не подтверждено** |
| 21 | 0x9947cf8 | 0 | 0 | 0 | 0x30 | | безопасно |
| 22 | 0x9947d08 | 0 | 0 | 0 | **UNCHECKED** | | подозрительно |
| 25 | 0x9947de4 | 4 | **UNCHECKED** | 1 | 0 | | подозрительно |
| 26 | 0x9948074 | 1 | 0xc | 1 | 0 | `IOGPUResource` по id, размер в out | безопасно |
| 27 | 0x994811c | 1 | 4 | 0 | 0 | | безопасно |
| 38 | 0x994857c | 0 | 0x18 | 0 | 0 | | безопасно |
| 39 | 0x994858c | 0 | 0x18 | 1 | 0 | | безопасно |
| 45 | 0x9948af4 | 1 | **UNCHECKED** | 0 | 0 | **(len-8) % 0x18 == 0** и `input[0] == (len-8)/0x18` | безопасно |
| 52 | 0x99491a0 | 2 | **UNCHECKED** | 0 | 0 | | подозрительно |
| 53 | 0x9949330 | 2 | **UNCHECKED** | 0 | 0 | | подозрительно |

**restricted-вариант (0x7fea740)**: 28 селекторов → 0x9949520 = `kIOReturnNotPermitted`:
**21, 27, 28, 29, 30, 31, 32, 33, 34, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
52, 53, 54**. Свободно остаются 0-20 (кроме 21), 22-26, 35, 55.

`IOGPUMemoryInfoUserClient` (0x7fef7c0): sel 0 — `strOut=UNCHECKED`, sel 1 — `strIn=UNCHECKED, strOut=0x70`.

---

## 5. Топ-5 подозрительных — полный дизасм

### 5.1 IOSurface sel 0 — `s_create_surface`, `strIn = UNCHECKED` (0x9c3888c)

Единственный контроль перед разбором: указатель не NULL и длина не 0. Минимума нет, максимум не ограничен
(при descriptor-пути длина = `getLength()` дескриптора).

```asm
0x9c388ac  ldr  x8,[x2,#0x20]        ; args->scalarInput
0x9c388b0  ldr  x20,[x8]             ; 64-бит id
0x9c388b4  lsr  x8,x20,#0x20
0x9c388b8  cbz  x8,0x9c388f4         ; требуем hi32 == 0  (id < 2^32)
0x9c388bc  mov  w21,#0x2c2 ; movk w21,#0xe000,lsl#16    ; kIOReturnBadArgument
0x9c388c4  adrp x8,0x789c000 ; add x8,x8,#0xf60         ; "s_create_surface"
0x9c388cc  stp  x8,x20,[sp]          ; kprintf-тег + id
0x9c388ec  bl   0x9c49b74            ; log
0x9c388f0  b    0x9c38a40
0x9c388f4  mov  x22,x2 ; mov x21,x0
0x9c388fc  ldr  x0,[x2,#0x40]        ; args->structureInputDescriptor
0x9c38900  cbz  x0,0x9c38974         ; нет -> inline
0x9c38904  ldr  x16,[x0] ; ... autda
0x9c38914  ldr  x8,[x16,#0xe8]!      ; IOMemoryDescriptor vtbl+0xe8  (map)
0x9c38918  mov  w1,#0x1000           ; options = 0x1000
0x9c38920  blraa x8,x16
0x9c38924  cbz  x0,0x9c38a08         ; не смапилось -> error
0x9c38928  mov  x19,x0               ; map
0x9c3893c  ldr  x8,[x16,#0x78]!      ; IOMemoryMap vtbl+0x78 (getAddress)
0x9c38944  blraa x8,x16
0x9c38948  mov  x23,x0               ; x23 = адрес данных
0x9c3894c  ldr  x0,[x22,#0x40]
0x9c38960  ldr  x8,[x16,#0xb0]!      ; descriptor vtbl+0xb0 (getLength)
0x9c38968  blraa x8,x16
0x9c3896c  mov  x4,x0                ; x4 = длина  <- ИЗ ДЕСКРИПТОРА
0x9c38970  b    0x9c38980
0x9c38974  mov  x19,#0               ; inline-ветка
0x9c38978  ldr  w4,[x22,#0x38]       ; x4 = args->structureInputSize
0x9c3897c  ldr  x23,[x22,#0x30]      ; x23 = args->structureInput
0x9c38980  cmp  x23,#0
0x9c38984  ccmp w4,#0,#4,ne
0x9c38988  b.ne 0x9c389c8            ; нужен ptr != 0 && len != 0   <-- ВСЁ
0x9c3898c  mov  w21,#0x2c2 ; movk w21,#0xe000,lsl#16
0x9c38994  adrp x8,0x789c000 ; add x8,x8,#0xf60
0x9c3899c  str  x8,[sp]
0x9c389bc  bl   0x9c49b74           ; log
0x9c389c0  cbnz x19,0x9c389e4
0x9c389c4  b    0x9c38a40
0x9c389c8  ldr  x3,[x22,#0x58]       ; args->structureOutput
0x9c389cc  mov  x0,x21 ; mov x1,x23 ; mov x2,x20
0x9c389d8  bl   0x9c3ab8c           ; create_surface_impl(self, ptr, id, out)
0x9c389dc  mov  x21,x0
0x9c389e0  cbz  x19,0x9c38a40
0x9c389e4  ldr  x16,[x19]            ; release map
0x9c389f4  ldr  x8,[x16,#0x28]!
0x9c38a00  blraa x8,x16
```

Что контролирует пользователь: **всё содержимое и длина блоба**. Что делает ядро (`0x9c3ab8c`):

```asm
0x9c3abbc  ldr  w8,[x0,#0x128]        ; счётчик поверхностей клиента
0x9c3abc0  cmp  w8,#4,lsl#12          ; 0x4000
0x9c3abc4  b.lo 0x9c3abfc
0x9c3abc8  adrp x9,0x789d000 ; add x9,x9,#0x4a   ; "Too many surfaces"
0x9c3abf0  bl   0x9c49b74
0x9c3abf4  sub  w19,w19,#4             ; kIOReturnNoResources
0x9c3abfc  cbz  x1,0x9c3b098           ; ptr == 0 -> error
0x9c3ac10  mov  x0,x1                  ; buffer
0x9c3ac14  mov  x1,x8                  ; size  <- длина от пользователя
0x9c3ac18  mov  x2,#0
0x9c3ac1c  bl   0x9c49764             ; OSUnserializeXML(buf,len,NULL)
0x9c3ac20  cbz  x0,0x9c3b098           ; parse fail
0x9c3ac28  adrp x8,0x806c000 ; ldr x8,[x8,#0x9c8]
0x9c3ac30  ldr  x1,[x8]               ; OSDictionary::metaClass
0x9c3ac34  bl   0x9c498d4             ; OSDynamicCast(dict, obj)
0x9c3ac38  cbz  x0,0x9c3ac88           ; не словарь -> error
```

`0x9c49764`/`0x9c498d4` — GOT-трамплины (`adrp x17;add;ldr x16,[x17];braa x16,x17`), т.е. реальные
`OSUnserializeXML` и `OSDynamicCast` из Libkern.

Вывод: OOB здесь нет — парсер получает ровно `(ptr, len)`. Но это **точка входа произвольного
plist/XML в ядро с полностью контролируемой длиной**, включая путь «дескриптор любой длины»
(`io_connect_method` #2865, argc=17 — рутина, которая и заполняет `structureInputDescriptor`).
Остаточный риск целиком в `OSUnserializeXML`, а не в IOSurface.

### 5.2 IOSurface sel 10 — `strIn = UNCHECKED`, `strOut = UNCHECKED` (0x9c38c44)

Самый «грязный» по декларации селектор: и вход, и выход не проверяются таблицей.

```asm
0x9c38c8c  ldr  x23,[x2,#0x30]       ; structureInput
0x9c38c90  ldr  x24,[x2,#0x58]       ; structureOutput
0x9c38c94  ldr  w25,[x2,#0x38]       ; structureInputSize
0x9c38c98  ldr  w27,[x2,#0x60]       ; structureOutputSize (in)
0x9c38c9c  str  w27,[sp,#4]          ; сохранили
0x9c38ca0  ldr  x0,[x2,#0x40]        ; structureInputDescriptor
0x9c38ca4  cbz  x0,0x9c38d1c
0x9c38cb8  ldr  x8,[x16,#0xe8]!      ; map(0x1000)
0x9c38cbc  mov  w1,#0x1000
0x9c38cc4  blraa x8,x16
0x9c38cc8  mov  x21,x0               ; map
0x9c38ccc  cbz  x0,0x9c38dec
0x9c38ce0  ldr  x8,[x16,#0x78]!      ; getAddress
0x9c38cec  blraa x8,x16
0x9c38cf0  mov  x23,x0               ; x23 = in ptr  <- из дескриптора
0x9c38d08  ldr  x8,[x16,#0xb0]!      ; getLength
0x9c38d10  blraa x8,x16
0x9c38d14  mov  x25,x0               ; x25 = in len  <- из дескриптора
0x9c38d18  b    0x9c38d20
0x9c38d1c  mov  x21,#0               ; inline
0x9c38d20  ldr  x0,[x20,#0x68]       ; structureOutputDescriptor
0x9c38d24  cbz  x0,0x9c38d7c
0x9c38d38  ldr  x8,[x16,#0xe8]!      ; map(0)
0x9c38d3c  mov  w1,#0
0x9c38d44  blraa x8,x16
0x9c38d48  cbz  x0,0x9c38dec
0x9c38d4c  mov  x26,x0               ; out map
0x9c38d60  ldr  x8,[x16,#0x78]!      ; getAddress
0x9c38d68  blraa x8,x16
0x9c38d6c  mov  x24,x0               ; x24 = out ptr  <- из дескриптора
0x9c38d70  ldr  w27,[x20,#0x70]      ; structureOutputDescriptorSize
0x9c38d74  str  w27,[sp,#4]
0x9c38d7c  mov  x26,#0
0x9c38d80  cmp  x23,#0
0x9c38d84  ccmp w25,#0xd,#0,ne       ; in ptr && in len >= 0xd
0x9c38d88  ccmp x24,#0,#4,hs         ; && out ptr
0x9c38d8c  ccmp w27,#0xd,#0,ne       ; && out len >= 0xd
0x9c38d90  b.hs 0x9c38dc8            ; все четыре -> работаем
0x9c38d94  sub  w19,w19,#6           ; kIOReturnBadArgument
0x9c38d9c  str  w27,[x20,#0x70]      ; вернуть размер
0x9c38dc8  add  x4,sp,#4
0x9c38dcc  mov  x0,x22 ; mov x1,x23 ; mov x2,x24 ; mov x3,x25
0x9c38ddc  bl   0x9c3c538            ; impl(self, in, out, inlen, &outlen)
0x9c38de4  ldr  w27,[sp,#4]
0x9c38dec  str  w27,[x20,#0x60]
```

Проверка есть, но **только снизу, 13 байт**, и она применяется к длине дескриптора, а не к длине
структуры. Всё, что больше 0xd, уходит в `0x9c3c538`. Это ровно тот класс, который Кай просил помечать:
«пользовательский размер идёт в арифметику/длину без сравнения с размером объекта».

### 5.3 IOSurface sel 9 — заголовок 12 байт + XML (0x9c38b2c)

```asm
0x9c38b50  mov  w19,#0x2c2 ; movk w19,#0xe000,lsl#16
0x9c38b58  ldr  x20,[x2,#0x58]       ; structureOutput
0x9c38b5c  ldr  x0,[x2,#0x40]        ; structureInputDescriptor
0x9c38b60  cbz  x0,0x9c38bd4
0x9c38b74  ldr  x8,[x16,#0xe8]!      ; map(0x1000)
0x9c38b78  mov  w1,#0x1000
0x9c38b80  blraa x8,x16
0x9c38b84  cbz  x0,0x9c38c28
0x9c38b88  mov  x21,x0
0x9c38b9c  ldr  x8,[x16,#0x78]!      ; getAddress
0x9c38ba4  blraa x8,x16
0x9c38ba8  mov  x23,x0               ; in ptr
0x9c38bac  ldr  x0,[x24,#0x40]
0x9c38bc0  ldr  x8,[x16,#0xb0]!      ; getLength
0x9c38bc8  blraa x8,x16
0x9c38bcc  mov  x2,x0                ; in len
0x9c38bd0  b    0x9c38be0
0x9c38bd4  mov  x21,#0
0x9c38bd8  ldr  x23,[x24,#0x30]      ; inline ptr
0x9c38bdc  ldr  w2,[x24,#0x38]       ; inline len
0x9c38be0  cmp  x23,#0
0x9c38be4  ccmp w2,#0xd,#0,ne        ; ptr && len >= 0xd
0x9c38be8  b.lo 0x9c38c00
0x9c38bec  mov  x0,x22 ; mov x1,x23 ; mov x3,x20
0x9c38bf8  bl   0x9c3c3b8            ; impl(self, ptr, len, out)
0x9c38c28  add  w19,w19,#6            ; kIOReturnNoResources
```

`0x9c3c3b8`:

```asm
0x9c3c3e8  ldr  w1,[x1]              ; *(u32*)ptr  = id объекта
0x9c3c3ec  bl   0x9c3f1d0            ; lookup by id
0x9c3c3f0  cbz  x0,0x9c3c520
0x9c3c3f8  add  x8,x22,w23,uxtw      ; end = ptr + (u32)len   (нулевое расширение!)
0x9c3c3fc  add  x0,x22,#0xc          ; data = ptr + 0xc
0x9c3c400  sub  x1,x8,x0             ; size = len - 0xc
0x9c3c408  bl   0x9c49764            ; OSUnserializeXML(ptr+0xc, len-0xc, 0)
0x9c3c40c  cbz  x0,0x9c3c500
0x9c3c41c  ldr  x1,[x8]              ; OSDictionary::metaClass
0x9c3c420  bl   0x9c498d4            ; OSDynamicCast
```

Границы корректны (`uxtw`, вычитание из конца буфера). Схема: 12-байтный заголовок с id + XML.
Именно поэтому `strIn` в таблице = UNCHECKED — длина действительно переменная. **Подозрительно по
поверхности, не по арифметике.**

### 5.4 IOGPU sel 8 — `strIn = UNCHECKED / strOut = UNCHECKED` (0x9947a54)

```asm
0x9947a84  ldr  x23,[x2,#0x58]       ; structureOutput
0x9947a88  ldr  x0,[x2,#0x40]        ; structureInputDescriptor
0x9947a8c  cbz  x0,0x9947b04
0x9947aa0  ldr  x8,[x16,#0xe8]!      ; map(0x1000)
0x9947aa4  mov  w1,#0x1000
0x9947aac  blraa x8,x16
0x9947ab0  cbz  x0,0x9947b90
0x9947ac8  ldr  x8,[x16,#0x78]!      ; getAddress
0x9947ad0  blraa x8,x16
0x9947ad4  mov  x24,x0               ; in ptr
0x9947aec  ldr  x8,[x16,#0xb0]!      ; getLength
0x9947af4  blraa x8,x16
0x9947af8  mov  x3,x0                ; in len
0x9947b04  mov  x20,#0
0x9947b08  ldr  w3,[x22,#0x38]       ; inline len
0x9947b0c  ldr  x24,[x22,#0x30]      ; inline ptr
0x9947b10  cbz  x24,0x9947b38        ; ptr == 0 -> пропуск
0x9947b14  cmp  x3,#0x58             ; ТОЧНЫЙ минимум 88 байт
0x9947b18  ccmp x23,#0,#4,hs         ; && out != 0
0x9947b1c  b.eq 0x9947b38
0x9947b20  add  x4,x22,#0x60
0x9947b24  mov  x0,x21 ; mov x1,x24 ; mov x2,x23
0x9947b30  bl   0x994a30c            ; impl(self, in, out, &outsize)
```

`0x58` — фиксированный размер структуры, длина проверена точно. Ветка map(0x1000) берёт длину у
дескриптора, но обработчик всё равно требует `>= 0x58`. **Безопасно**, несмотря на UNCHECKED в таблице.

### 5.5 IOGPU sel 45 — `strIn = UNCHECKED`, переменный массив (0x9948af4)

```asm
0x9948b1c  ldr  x0,[x2,#0x40]        ; descriptor?
0x9948b20  cbz  x0,0x9948b90
0x9948b34  ldr  x8,[x16,#0xe8]!      ; map(0x1000)
0x9948b38  mov  w1,#0x1000
0x9948b40  blraa x8,x16
0x9948b44  cbz  x0,0x9948c1c
0x9948b5c  ldr  x8,[x16,#0x78]!      ; getAddress
0x9948b64  blraa x8,x16
0x9948b68  mov  x22,x0               ; in ptr
0x9948b80  ldr  x8,[x16,#0xb0]!      ; getLength
0x9948b88  blraa x8,x16              ; x0 = len
0x9948b8c  b    0x9948b9c
0x9948b90  mov  x19,#0
0x9948b94  ldr  x22,[x21,#0x30]      ; inline ptr
0x9948b98  ldr  w0,[x21,#0x38]       ; inline len
0x9948b9c  subs x9,x0,#8             ; len - 8
0x9948ba0  b.lo 0x9948bc0            ; len < 8 -> kIOReturnBadArgument
0x9948ba4  mov  x8,#-0x5555555555555556
0x9948ba8  movk x8,#0xaaab            ; 0xAAAAAAAAAAAAAAAB == 1/3 mod 2^64
0x9948bac  umulh x8,x9,x8
0x9948bb0  lsr  x8,x8,#4              ; x8 = (len-8)/3/16 = (len-8)/24 = count
0x9948bb4  mov  w10,#0x18
0x9948bb8  msub x9,x8,x10,x9          ; x9 = (len-8) - count*0x18
0x9948bbc  cbz  x9,0x9948c70          ; остаток 0 -> ок, иначе отказ
...
0x9948c70  ldr  w9,[x22]              ; input[0]
0x9948c74  cmp  x8,x9                 ; input[0] == count ?
0x9948c78  b.ne 0x9948ce4             ; не совпало -> отказ
0x9948c7c  ldr  x8,[x21,#0x20]        ; scalarInput
0x9948c80  ldr  w23,[x8]              ; obj id
0x9948c84  ldr  x0,[x20,#0x120]       ; device
0x9948c88  mov  x1,x23
0x9948c8c  bl   0x9967bb4            ; lookup resource by id
0x9948c90  cbz  x0,0x9948d24
0x9948c94  mov  x21,x0
0x9948c98  mov  x1,x22
0x9948c9c  bl   0x995b364            ; apply array
```

Три независимых условия согласованности: `len >= 8`, `(len-8) % 0x18 == 0`, `input[0] == count`.
Это образцовый разбор переменного массива. **Безопасно.**

### 5.6 (бонус) IOSurface sel 0 — путь через дескриптор

Отдельно стоит держать в голове: `map(0x1000)` + `getLength()` — если `IOMemoryMap` короче, чем
`getLength()`, то `OSUnserializeXML` получит длину больше отображённого. Проверить это без живой
отладки нельзя — `IOMemoryDescriptor::map` в IOS 27 может возвращать map с полной длиной либо
единственную страницу. **Не подтверждено**, помечено как единственная неочевидная арифметика
в самой IOSurface.

---

## 6. Мёртвые копии таблиц (важно для повторного парсинга)

В кеше лежат **вторые, идентичные копии** таблиц, на которые нет ни одной ссылки:

* IOSurface 0x8068d70/0x8068eb0/0x8068fc8/0x8069068/0x80691f8/0x8069428 — сдвиг +0x960 от основной
  группы, `fn` те же, ссылок 0.
* IOGPU 0x7fea818/0x7fea9b0/0x7feaab90 — то же.

Если сканировать «по паттерну в данных», они попадут в отчёт как отдельные классы. Отсекаются только
проверкой `adrp/add` из кода. Это же объясняет, почему наивный скан давал 165 таблиц вместо 120.

---

## 7. Что реально открывается из песочницы `container`

Список `require-any` из профиля подтверждён: скомпилированный пул строк лежит в
`com.apple.security.sandbox` `__DATA_CONST` / `__TEXT` около `0xfffffff0079ddfa8` —
`…IOSurfaceAcceleratorParavirtClient`, `RootDomainUserClient`, `AppleKeyStoreUserClient`,
`AppleJPEGDriverUserClient`, `IOAccelContext2`, `IOAccel`, `…SharedUserClient`, `AGXCommandQueue`,
`IOSurfaceAcceleratorClient`, `IOSurfaceRootUserClient`, `IOGPUDeviceUserClient`, `AGXDevice`,
`IOMobileFramebufferUserClient`, `IOPMrootDomain`, `AppleKeyStore`, `AGXAcceleratorG…`, `Paravirt`,
`Display`. Привязка именно к профилю `container` — **по списку, который дал Кай**, декомпиляции
sandbox-байткода я не делал.

| класс из списка | есть в кеше | методов | открывается | ограничения |
|---|---|---|---|---|
| `IOSurfaceRootUserClient` | да, 0x148 | **17** | **да** | 6 селекторов (4,5,6,7,8,16) отваливаются при `com.apple.developer.gpu-restricted`; `[+0x127]` выбирает вариант таблицы |
| `IOGPUDeviceUserClient` | да, 0x130 | **56** | **да** | нужен started-клиент (`[+0x100]`); 28 селекторов в restricted-варианте → `kIOReturnNotPermitted`; `asyncReference` должен быть 0 |
| `IOMobileFramebufferUserClient` | да, **0x958** | нет таблицы | **вероятно да** | ручной `switch`, не разобран — **не подтверждено** |
| `AppleKeyStoreUserClient` | да, 0x118 | нет таблицы | **вероятно да** | ручной `switch`, не разобран — **не подтверждено** |
| `IOSurfaceAcceleratorClient` | да (AppleM2ScalerCSCDriver) | 3 | **да** | только скаляры, structure-входа нет |
| `AppleJPEGDriverUserClient` | таблица есть (6), класс в kext'е — `AppleJPEGWrapperControlV14` † | 6 | вероятно | фиксированные 0x58 / 0x1000 |
| `H11ANEInDirectPathClient` | да, 0x1a0 | 11 + 2 | **вероятно да** | глобальный флаг `[0xfffffff00ae430b1] bit2` в каждом обработчике |
| `H1xANELoadBalancerDirectPathClient` | да, 0x1a0 | † | вероятно | тот же гейт |
| `AGXAccelerator*`, `AGXDevice`, `AGXCommandQueue` | классы есть, таблиц нет | 0 | **нет своей поверхности** | всё идёт через `IOGPUDeviceUserClient` (виртуальный вызов `g+0x550`) |
| `AGXSharedUserClient` | **нет в кеше** | — | **нет** | только строка в профиле |
| `IOAccelContext` / `IOAccelContext2` | **нет в кеше** | — | **нет** | только строка в профиле |
| `AppleVirtIONeuralEngineDeviceUserClient` | **нет в кеше** | — | **нет** | только строка в профиле |

Итог: реально достижимая поверхность из `container` — **17 + 56 + 3 + (11+2) + 6 = 95 селекторов**,
из них с непустым `structureInput`/`structureOutput` либо с descriptor-веткой — **13**
(IOSurface 0/2/3/6/9/10/11/13, IOGPU 8/26/38/39/45); ещё пять (IOGPU 6/22/25/52/53) объявлены
с `0xFFFFFFFF`, но разбирают только скаляры.

---

## 8. Явно «не подтверждено»

1. Привязка трёх ANE-таблиц и JPEG-таблицы к **конкретному** классу внутри kext'а (у ANE четыре
   `*Client`-класса одинакового размера 0x1a0, у JPEG имя `AppleJPEGDriverUserClient` в кеше есть,
   но без xref).
2. `IOMobileFramebufferUserClient` и `AppleKeyStoreUserClient` — разбор их ручных `switch` не делался.
3. Точное имя виртуального метода `IOMemoryDescriptor` на `vt+0xe8` (по поведению — `map`/`createMappingInTask`,
   аргумент 0x1000) и `vt+0xb0` (`getLength`) — идентификация по семантике вызовов, не по символам.
4. Совпадение длины `IOMemoryMap` и `getLength()` в descriptor-пути — единственное место, где
   возможна арифметика за границей отображения. Проверяется только динамически.
5. Порог, при котором libIOKit переключается с inline на `io_connect_method` (#2865) с дескриптором.
   Сама MIG-рутина с 17 аргументами существует и именно она заполняет `structureInputDescriptor`.
6. Привязка пула строк sandbox к профилю именно `container`.

## 9. Ответ на «есть ли OOB»

В разобранных 5 путях — **нет**. Все либо проверяют точный размер структуры таблицей (`0x58`, `0x18`,
`0xc`, `0x20`, `0x10`, `0x88`), либо ставят нижнюю границу и считают длину от конца буфера
(`ptr + (u32)len - (ptr + 0xc)` в sel 9), либо проверяют самосогласованность массива
(`(len-8) % 0x18 == 0 && input[0] == count` в IOGPU sel 45).

Настоящая поверхность здесь другая: **произвольный `OSUnserializeXML` в ядре с полностью
контролируемой длиной** (IOSurface sel 0 — без минимума вообще, sel 9 — 12-байтный заголовок + XML)
и **путь через `structureInputDescriptor` с длиной из `getLength()`** — то есть длина не ограничена
ни 4 КБ MIG-сообщения, ни чем-либо ещё, кроме самого дескриптора. Если копать дальше — это
`OSUnserializeXML`, а не IOSurface. Для сравнения: sel 11 того же класса обрабатывает строку
корректно (`ptr[0xc]!=0`, `ptr[len-1]==0`), то есть в IOSurface умеют считать границы — просто
в sel 0/9 этого не требуется по смыслу.
