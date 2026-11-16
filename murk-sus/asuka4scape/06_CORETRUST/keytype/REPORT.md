# Type confusion ключей OSUnserialize — 27.2 (24B115)

Бинарник: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`
База: `__TEXT_EXEC` VA = `0xfffffff00814c000`, файловое смещение `0x1148000`;
PAC-декод констант: `0xfffffff007004000 + (q & 0x0FFFFFFF)`.
Все адреса ниже — VA. Дизасм — capstone, знаковые imm замаскированы `& 0xFFFFFFFFFFFFFFFF`.

## 0. Итог

**Предпосылка задания не подтверждается на 27.2: проверка типа ключа в бинарном
десериализаторе ЕСТЬ.** Она стоит не рядом с `setObject`, а на ~0x170 байт раньше —
`0xa8d9d64..0xa8d9db8` — и сделана **inline** (обход цепочки метаклассов), без вызова
`bl OSDynamicCast`. Поиск по `bl` её не видит; отсюда, вероятно, и вывод предыдущего
прохода про «нет проверки на `0xa8d9ecc`».

Цепочка: ключ, не являющийся `OSSymbol` и не являющийся `OSString`, даёт `sym = NULL` →
`OSDictionary::setObject(NULL, value)` возвращает `false` → `ok = false` → парсер
разрушает результат и возвращает `NULL` (cleanup `0xa8da320`/`0xa8da354`).
`OSString`-ключ конвертируется в интернированный `OSSymbol` через
`OSSymbol::withString` (`0xa8d4088`) — это ровно то, что делает `OSSerializeBinary.cpp`
из open-source XNU.

Потребителей тоже отсмотрел: 51 сайт `OSUnserialize` (43 через 19 GOT-стабов + 8 прямых)
плюс 15 сайтов, зовущих только XML-обёртки. В проверенных сайтах корень кастуется к
`OSDictionary` (`0xad95c70`), ключи читаются **по имени** (`getObject` c c-string /
`OSSymbol`), итерации по ключам с C-cast не найдено.

**Пути, где непроверенный тип ключа даёт вызов/чтение по подконтрольному объекту,
не найдено.** Что именно проверено, а что нет — раздел 5.

## 1. Карта семейства OSUnserialize

| VA | роль | признаки |
|---|---|---|
| `0xfffffff00a8d8754` | `OSUnserialize(const char*, size_t, OSString**)` — диспетчер | `cbz x0`; `cmp x1,#4`; `strncmp(buf,"<?xml",4)` (`0xaa7451c`); `ldrb w8,[buf]; cmp #0xd4` |
| `0xfffffff00a8d96f4` | `OSUnserializeBinary(const char*, size_t, ..., OSString**)`, 6 арг. | `cmp x1,#4`; `ldrb #0xd4`; `setAtIndex`-макрос `str x21,[x0,w8,uxtw #3]` на `0xa8d9d30` |
| `0xfffffff00a8d846c` | XML-обёртка с опциями, 5 арг. | `bl 0xa292e20` (kalloc 0x40), дальше `0xa8d8568` |
| `0xfffffff00a8d8568` | вход в bison-парсер | `bl 0xa8d5ea4` |
| `0xfffffff00a8d5ea4` | сам bison-парсер XML | большой кадр `0x1040` |
| `0xfffffff00a8d5c98` | XML-вход 2-арг. (на входе — ленивая инициализация глобала + `casa`) | `tpidr_el1`, `casa` на `0xadd7150` |

Ветвление диспетчера (дизасм):

```
0xa8d8768  cbz  x0, fail            ; buf == NULL
0xa8d876c  cmp  x1, #4
0xa8d8770  b.lo fail                ; len < 4
0xa8d878c  bl   0xaa7451c           ; strncmp(buf, "<?xml", 4)
0xa8d8790  cbz  w0, xml_path
0xa8d8794  ldrb w8, [x20]
0xa8d8798  cmp  w8, #0xd4
0xa8d879c  b.ne fail                ; не XML и не 0xd4 -> ошибка
0xa8d87a0  ... mov x5, x19 ; b 0xa8d96f4     ; OSUnserializeBinary(buf,len,0,0,0,err)
0xa8d87cc  ... (проверка последнего байта == 0) ; b 0xa8d846c  ; XML
```

Практический вывод: **любой** вызов `OSUnserialize` с байтами, начинающимися с `0xd4`,
уходит в бинарный парсер. Отдельный `OSUnserializeBinary` вызывать не нужно.

## 2. GOT-слоты и сайты вызовов

19 слотов в `__DATA_CONST`, все указывают на `0xa8d8754` (PAC-константа вида
`0x8011xxxx0xxxxxxx`, низкие 32 бита = `0x038d4754`):

```
0xfffffff007d7c130  0xfffffff007db41d8  0xfffffff007dfd1e0  0xfffffff007e0e6b0
0xfffffff007e26350  0xfffffff007e741d8  0xfffffff007f0a140  0xfffffff007f1f018
0xfffffff007f57550  0xfffffff007f99338  0xfffffff007ff8c28  0xfffffff007ffd8d0
0xfffffff008016ec0  0xfffffff008021bd8  0xfffffff00806c618  0xfffffff0080b65d8
0xfffffff0080c5eb8  0xfffffff0080d7e00  0xfffffff0080dcf70
```

Каждому слоту соответствует PLT-заглушка `adrp x17; add x17; ldr x16,[x17]; braa x16,x17`
(16 байт). Заглушки и число `bl` на них:

| заглушка | сайтов | заглушка | сайтов |
|---|---|---|---|
| `0x880c148` | 1 | `0x99a046c` | 3 |
| `0x8908934` | 6 | `0x99b8ba8` | 1 |
| `0x8b74944` | 2 | `0x9a4815c` | 4 |
| `0x8c1ffcc` | 3 | `0x9a99d40` | 5 |
| `0x8c78924` | 1 | `0x9c49764` | 7 |
| `0x8eb8980` | 1 | `0x9e9896c` | 1 |
| `0x92ba10c` | 1 | `0x9f0942c` | 1 |
| `0x9363c20` | 1 | `0x9f6f1c8` | 1 |
| `0x94be7ac` | 1 | `0x9fa975c` | 1 |
| `0x97ba7c4` | 2 | | |

Итого **43** вызова через заглушки + **8** прямых `bl 0xa8d8754` (внутри ядра:
`0xa9a8630, 0xa9a87e0, 0xa9a8a38, 0xa9a8b58, 0xa9a8d8c, 0xa9abac8, 0xa9b01b4, 0xa9e06fc`)
= **51** сайт, достижимый бинарным путём.

Плюс 15 сайтов зовут только XML-входы напрямую (`0xa8d846c` — 9, `0xa8d5c98` — 5,
`0xa8d5ea4` — 1); к бинарному парсеру они отношения не имеют.

Отдельно проверено по заданию: **у `0xa8d846c` и `0xa8d5c98` GOT-слотов нет вообще**
(скан `__DATA_CONST`+`__DATA` по низким 32 битам PAC-констант не дал ни одного попадания
на эти VA). Это внутренние входы ядра: их зовут только прямые `bl`/`b` из
`libkern`/`IOKit`-кода, ни один kext их не импортирует. Импортируется только
`0xa8d8754` — 19 слотов, по одному на kext.

## 3. Проверка типа ключа — главное

### 3.1. Код

```
0xa8d9d3c  ldur x8, [x29, #-0x70]        ; x8 = dict
0xa8d9d40  stur x26, [x29, #-0x60]
0xa8d9d44  cbz  x8, 0xa8d9dc0            ; dict == NULL -> array/set/result
0xa8d9d48  cbz  x19, 0xa8d9df8           ; sym == NULL -> sym = o (C-cast, без проверки)
--- проверка №1: sym это OSSymbol? ---
0xa8d9d4c  ldr  x16, [x19]
0xa8d9d64  ldr  x8, [x16, #0x38]!        ; getMetaClass()
0xa8d9d70  blraa x8, x16
0xa8d9d74  cmp  x0, x23                  ; x23 = 0xfffffff00ad95eb8 (OSSymbol::gMetaClass)
0xa8d9d78  b.eq 0xa8d9e04                ; да -> x22 = x19 (ключ принят как есть)
0xa8d9d7c  ldr  x0, [x0, #0x10]          ; superClass
0xa8d9d80  cbnz x0, 0xa8d9d74
--- проверка №2: sym это OSString? ---
0xa8d9d8c  ldr  x8, [x16, #0x38]!
0xa8d9d98  blraa x8, x16
0xa8d9da0  add  x8, x8, #0xee0           ; 0xfffffff00ad95ee0 (OSString::gMetaClass)
0xa8d9da4  cmp  x0, x8
0xa8d9da8  b.eq 0xa8d9e94                ; да -> OSSymbol::withString(str)
0xa8d9dac  ldr  x0, [x0, #0x10]
0xa8d9db0  cbnz x0, 0xa8d9da4
0xa8d9db4  mov  x19, #0                 ; ни то, ни другое:
0xa8d9db8  mov  x22, #0                 ;   sym = NULL
0xa8d9dbc  b    0xa8d9ea4
--- setObject ---
0xa8d9e94  mov  x0, x19
0xa8d9e98  bl   0xa8d4088              ; OSSymbol::withString(OSString*)
0xa8d9e9c  mov  x22, x0
0xa8d9ea0  cbz  x0, fail
...                                      ; (0xa8d9ea4..0xa8d9eb4: сравнение value с dict)
0xa8d9eb8  ldur x0, [x29, #-0x70]        ; dict
0xa8d9ecc  ldr  x8, [x16, #0xf0]!        ; setObject(key, value)
0xa8d9ed0  mov  x1, x22                  ; key
0xa8d9ed4  mov  x2, x21                  ; value
0xa8d9edc  blraa x8, x16
0xa8d9ee0  mov  x23, x0                  ; ok = результат
...
0xa8d9fa8  mov  x19, #0
0xa8d9fb0  cbnz w23, loop                ; ok != 0 -> следующая пара
0xa8d9fb4  b    0xa8da320               ; ok == 0 -> cleanup
...
0xa8da320  ...  b 0xa8da354
0xa8da3bc  cbz  w23, 0xa8d977c
0xa8d977c  mov  x0, x19                 ; x19 == 0 -> парсер вернул NULL
0xa8d979c  retab
```

`setObject(NULL, ...)` возвращает `false`, `x19` (result) обнуляется на `0xa8d9fa8`,
и на выходе `0xa8d977c` парсер отдаёт `NULL`.

### 3.2. Соответствие исходнику

Это дословно `OSSerializeBinary.cpp` (open-source XNU, `OSUnserializeBinary`):

```c
if (dict) {
    if (!sym) {
        sym = (OSSymbol *) o;                        // 0xa8d9df8: mov x19, x21
    } else {
        str = sym;
        sym = OSDynamicCast(OSSymbol, sym);          // 0xa8d9d74 -> 0xad95eb8
        if (!sym && (str = OSDynamicCast(OSString, str))) {   // 0xa8d9da0 -> 0xad95ee0
            sym = const_cast<OSSymbol *>(OSSymbol::withString(str));  // 0xa8d4088
            ok = (sym != NULL);
            if (!ok) break;
        }
        if (o != dict) {
            ok = dict->setObject(sym, o);            // 0xa8d9ecc, vtable+0xf0
        }
        if (sym && (sym != str)) sym->release();     // 0xa8d9f78, vtable+0x28
        sym = NULL;
    }
}
```

`0xa8d4088` = `OSSymbol::withString(const OSString*)`: сначала быстрый путь
`getMetaClass() == OSSymbol::gMetaClass` (`0xa8d40cc`, `0xad95eb8`), иначе
`getCStringNoCopy()` (vtable+0xa8) + `getLength()` (`[obj+0xc]`) и интернирование
(`0xa8d42e4` = `withCString(len+1)`, `0xa8d4164` — вторая ветка по знаку длины).

`OSDictionary::setObject(const OSSymbol*, const OSMetaClassBase*)` первым же сравнением
отбрасывает `aKey == NULL` → `false`. Поэтому «плохой» ключ не доходит до словаря.

### 3.3. Угол, который проверен отдельно

Если значение — сам словарь (`o == dict`, self-reference через `kOSSerializeObject`),
`setObject` пропускается (`0xa8d9eac: b.eq 0xa8d9eec`). Но и там при `sym == NULL`
управление уходит на `0xa8d9fb8` → `x19 = 0` → следующая итерация. Записи в словарь не
происходит, `sym` обнуляется — обойти проверку этим нельзя.

## 4. Потребители

### 4.1. Что делают с результатом

Типовой каркас (пример — IOSurface `create_surface`, сайт `0x9c3ac1c`):

```
0x9c3ac14  mov  x1, x8
0x9c3ac18  mov  x2, #0
0x9c3ac1c  bl   stub 0x9c49764        -> 0xa8d8754        ; OSUnserialize(buf,len,NULL)
0x9c3ac20  cbz  x0, fail
0x9c3ac24  mov  x20, x0
0x9c3ac28  adrp x8, 0x806c000
0x9c3ac2c  ldr  x8, [x8, #0x9c8]      ; слот -> глобал -> 0xfffffff00ad95c70
0x9c3ac30  ldr  x1, [x8]              ; OSDictionary::gMetaClass
0x9c3ac34  bl   0xa894f30             ; OSMetaClassBase::safeMetaCast(root, OSDictionary)
0x9c3ac38  cbz  x0, fail              ; корень не словарь -> отказ
...
0x9c3acb4  vtable+0x138(dict, "IOSurfaceAllocateFromSuperbuffer")   ; getObject по имени
```

`0xfffffff00a894f30` — это `OSMetaClassBase::safeMetaCast` (движок `OSDynamicCast`):
`getMetaClass()` (vtable+0x38), сравнение с целевым метаклассом, обход `[mc+0x10]`
(superClass), возврат `inst` или `NULL`. Вызывается с c-string/symbol-ключом и
метаклассом из GOT-глобала.

`0xfffffff00ad95c70` = `OSDictionary::gMetaClass` — подтверждено независимо по
ядерному потребителю `0xa8c0a60`: сравнение `getMetaClass()` с `0xad95c70`, при
несовпадении печатается `"not a dictionary"` (`0x70aa61f`), затем
`"Error unserializing request from user space: %s."` (`0x70acc37`).

`0xfffffff00ad95eb8` = `OSSymbol::gMetaClass`, `0xfffffff00ad95ee0` = `OSString::gMetaClass`
(из разбора `OSSymbol::withString`, п. 3.2).

### 4.2. Как читаются ключи

В проверенных сайтах — только по имени:

* `IOSurface` (`0x9c3ac1c`, `0x9c3c408`, `0x9c3c830`, `0x9c3d5b0`, `0x9c3e3c4`,
  `0x9c3e5b0`, `0x9c3e8ac`): `OSDynamicCast(OSDictionary, root)` + `vtable+0x138` с
  c-string (`"IOSurfaceAllocateFromSuperbuffer"` и т.п.), значения кастуются
  (`0xad95dc8`, `0xad95bd0`, `0xad95ee0`).
* Ядерные парсеры пользовательских запросов `0xa8b6798` (info-dict kext из booter DT) и
  `0xa8c0a28` (запрос из user space): inline-проверка корня на `0xad95c70`, при провале —
  `"not a dictionary"`.
* `OSDictionary`-setter `0xa9a8630`: `safeMetaCast` первого аргумента к классу
  `0xad98838`, затем корня к `OSDictionary` (`0xad95c70`), затем `vtable+0xf0`
  (`setObject`) с двумя глобальными символами. Имя класса `0xad98838` не проверял —
  в отчёте он без имени.
* `IOMFB` (`0x9a78de0`, `0x9a94db0`, `0x9a95204`, `0x9a95ebc`, `0x9a962b8`),
  `AppleH11ANE` (`0x9995c80`, `0x999b21c`, `0x999f124`), `IOSurface`-соседи,
  `0x9f83320` (`"Protobox"`, `"Exclude from data collection"`), `0x9ee3080`
  (`"UTCOffset"`), `0x8c6fc90` (`"AIDNextLoadOptions"`), `0x8ea46c4`
  (`"OSUnserializeXML failed"`, `"IOPMPowerSource"`) — тот же каркас: null-check →
  `safeMetaCast` к `OSDictionary` → `getObject` по имени/символу → `release` (vtable+0x28).

Итерации по ключам (`OSCollectionIterator`/`getNextObject`/`iterateObjects`) с
C-cast `(OSSymbol*)key` в просмотренных функциях нет: во всех сайтах видны только
`vtable+0x138` (getObject по c-string), `vtable+0xa8` (getObject по символу) и
`vtable+0xf0` (setObject).

### 4.3. Сводка по 43 стаб-сайтам

| сайт | корневой каст | заметное |
|---|---|---|
| `0x87cd104` | `0xad95c70` | `_processFirmwareDataGated`, `AncFirmware` |
| `0x88bbc04` | `0xad95c70` | 3 каста, `0xad95bd0` |
| `0x88c3e5c` | `0xad95c70` | `IOUserClientClass/IOClass/IOProviderClass` |
| `0x88c54d8` | `0xad95c70` | то же |
| `0x88c5878` | `0xad95c70` | то же |
| `0x88d9e84` | `0xad95c70` | 3 каста |
| `0x88e26ac` | — | `AFKIOServiceClient` |
| `0x8b06298` | `0xad95c48` | `mergeFromHeader`, `Property Header` |
| `0x8b19dfc` | `0xad95c70` | 12 кастов |
| `0x8c1c260` | `0xad95c70` | `Symbols`, `AccessOptions` |
| `0x8c1c5f8` | `0xad95c70` | `Values`, `AccessOptions` |
| `0x8c1c7dc` | `0xad95c70` | — |
| `0x8c6fc90` | `0xad95c70` | `AIDNextLoadOptions` |
| `0x8ea46c4` | — | `IOPMPowerSource`, `OSUnserializeXML failed` |
| `0x92b47a8` | `0xad95c70` | — |
| `0x932b768` | `0xad95c70` | — |
| `0x94bb28c` | `0xad95c70` | `_channel`, `_value` |
| `0x97a8afc` | `0xad96808` | `level`, `masks` |
| `0x97b6f00` | `0xad95c70` | `_setHDRStaticMetadata` |
| `0x9995c80` | `0xad95c70` | `Create control queue` |
| `0x999b21c` | `0xad95c70` | `ReportInterval` |
| `0x999f124` | `0xad95c70` | `Failed to open provider` |
| `0x99b379c` | `0xad95c70` | `createImageInfoDict` |
| `0x99d0974` | `0xad95dc8` | — |
| `0x9a2ab90` | `0xad95c70` | — |
| `0x9a459fc` | `0xad95c70` | — |
| `0x9a46ef8` | `0xad95c70` | `Privileged`, `RegisterService` |
| `0x9a78de0` | `0xad95c70` | IOMFB `InstanceTracker` |
| `0x9a94db0` | `0xad95c70` | IOMFB |
| `0x9a95204` | `0xad95c70` | IOMFB |
| `0x9a95ebc` | `0xad95c70` | IOMFB |
| `0x9a962b8` | `0xad95c70` | IOMFB |
| `0x9c3ac1c` | `0xad95c70` | IOSurface `create_surface` |
| `0x9c3c408` | `0xad95c70` | IOSurface |
| `0x9c3c830` | `0xad95bd0` | IOSurface |
| `0x9c3d5b0` | `0xad95bd0` | IOSurface |
| `0x9c3e3c4` | `0xad95c70` | IOSurface (утечка +1, см. отчёт N) |
| `0x9c3e5b0` | `0xad95c70` | IOSurface `ensure_memory_pool_memory` |
| `0x9c3e8ac` | `0xad95c70` | IOSurface `flush_memory_pool` |
| `0x9e93bcc` | `0xad95c70` | — |
| `0x9ee3080` | `0xad95bd0` | `UTCOffset` |
| `0x9f397ac` | `0xad95bd0` | — |
| `0x9f83320` | `0xad95bd0` | `Protobox`, `Exclude from data collection` |

`—` = метакласс не резолвился статически (вызов ушёл в локальную обёртку kext’а);
строка — по строкам в функции.

Прямые 8 сайтов (`0xa9a8630`, `0xa9a87e0`, `0xa9a8a38`, `0xa9a8b58`, `0xa9a8d8c`,
`0xa9abac8`, `0xa9b01b4`, `0xa9e06fc`) используют **inline**-проверку
`cmp getMetaClass(), 0xad95c70` + обход `[mc+0x10]`, без вызова `safeMetaCast`.

## 5. Что проверено, а что нет

Проверено по инструкциям:
* диспетчер `0xa8d8754` целиком (ветки XML/бинарный/ошибка);
* проверка типа ключа `0xa8d9d64..0xa8d9db8`, `OSSymbol::withString` `0xa8d4088`,
  `setObject` `0xa8d9ecc`, путь отказа `0xa8d9fa8 → 0xa8da320`;
* каркас потребителя на IOSurface `0x9c3ac1c` (safeMetaCast + getObject по имени);
* ядерные парсеры `0xa8b6798`, `0xa8c0a28` (inline-каст к `OSDictionary`, сообщения);
* `setProperties`-подобный `0xa9a8630` (касты к `OSString`/`OSDictionary`, `setObject`).

Не проверено (помечаю как «не подтверждено»):
* полный dataflow по всем 66 сайтам; таблица 4.3 — это резолв метаклассов и строк, а не
  доказательство отсутствия итерации в каждой функции. «Нет итерации по ключам» —
  выборочная проверка (12 функций вручную + сигнатуры вызовов), не исчерпывающая;
* XML-путь: тип ключа по грамматике (`<key>` → интернированный `OSSymbol`) — по
  исходникам XNU, по инструкциям bison-парсера `0xa8d5ea4` не сверял;
* поведение при `o == dict` (self-reference) с валидным, но чужим ключом — запись
  пропускается, но и вреда не найдено; отдельно не тестировал.

## 6. Вывод для цепочки

Тип-конфьюжн ключей на 27.2 закрыт в парсере: не-`OSSymbol`/`OSString` ключ ломает
парсинг, а `OSString` нормализуется в интернированный `OSSymbol`. Даже если бы проверки
не было, все просмотренные потребители ищут по имени (`getObject(const char*)` /
`getObject(const OSSymbol*)`) — это сравнение указателей с интернированным символом,
посторонний объект-ключ совпасть не может. Для эксплуатации нужен потребитель, который
*итерирует* ключи и делает C-cast — такого не найдено.

`sbx_build` и IPA не трогал.
