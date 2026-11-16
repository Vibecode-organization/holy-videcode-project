# var-output scan — kernelcache iOS 27.2 (24B115)

Файл: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (67 239 936 B)
Инструменты: `kc.py` (layout/PAC), `tools.py` (таблицы, GOT-трамплины), `flow.py` (абстрактный
интерпретатор), скрипты `s1..s6`. Всё в `/home/femboychik/work/parse_varout3`.

---

## 1. Что такое канал и как он устроен

`IOExternalMethodArguments::structureVariableOutputData` — `OSObject **` по смещению **+0x78**
(xnu `iokit/IOKit/IOUserClient.h`). Раскладка, которой пользовался скан:

```
+0x20 scalarInput            +0x48 scalarOutput
+0x28 scalarInputCount       +0x50 scalarOutputCount
+0x30 structureInput         +0x58 structureOutput
+0x38 structureInputSize     +0x60 structureOutputSize
+0x40 structureInputDescriptor  +0x68 structureOutputDescriptor
                             +0x70 structureOutputDescriptorSize
                             +0x78 structureVariableOutputData   <-- OSObject **
```

Механика (xnu `iokit/Kernel/IOUserClient.cpp`, `is_io_connect_method_var_output`, строки 5049–5125):

```c
OSObject *structureVariableOutputData = NULL;
args.structureVariableOutputData = &structureVariableOutputData;
...
ret = client->callExternalMethod(selector, &args);
...
if ((serialize = OSDynamicCast(OSSerialize, structureVariableOutputData))) {
        len = serialize->getLength();  copyoutkdata(serialize->text(), len, var_output);
} else if ((data = OSDynamicCast(OSData, structureVariableOutputData))) {
        len = data->getLength();       copyoutkdata(data->getBytesNoCopy(), len, var_output);
} else ret = kIOReturnUnderrun;
if (structureVariableOutputData) structureVariableOutputData->release();
```

Три следствия, важных для эксплуатации:

1. Драйвер пишет в `*args->structureVariableOutputData` **указатель на OSObject**, а ядро само
   копирует содержимое в userland: `OSSerialize` — как текст (XML-пlist), `OSData` — как сырые
   байты. Любой другой класс → `kIOReturnUnderrun`, данных нет.
2. Поле инициализируется **только** в `is_io_connect_method_var_output`. В обычном
   `is_io_connect_method` оно `NULL` (строка 5283), поэтому все найденные обработчики первым
   делом делают `cbz` и отдают `kIOReturnBadArgument` (`0xe00002c2`), если поле пустое.
   То есть канал живой только через var-output вариант трапа.
3. Размер отдаёт само ядро из объекта, драйвер размер не контролирует.

---

## 2. Метод

* `__TEXT_EXEC` = `0xfffffff00814c000`, файловое смещение `0x1148000`, размер `0x2924000`.
* 110 778 границ функций (пролог `bti c` + `pacibsp`), атрибуция к 249 kext'ам по
  `__PRELINK_INFO` + per-kext Mach-O заголовкам.
* **Грабли (подтверждены):** capstone отдаёт `adrp` `operands[1].imm` как знаковое 64-битное
  (например `-68584816640`), поэтому страница считается только после
  `page = i.operands[1].imm & 0xFFFFFFFFFFFFFFFF`. Без маски все GOT-слоты получаются
  отрицательными, `q()` возвращает `None`, и список писателей пустой.
* Таблицы диспетчеров: перебор `__DATA_CONST` / `__DATA` / `__DATA_SPTM` с шагом 8 на две
  раскладки:
  * **0x18** — классический `IOExternalMethodDispatch`
    (`fn | sIn | strIn | sOut | strOut`), 151 таблица;
  * **0x28** — `IOExternalMethodDispatch2022` (+0x18 `allowAsync`/u8, +0x20 `const char
    *checkEntitlement`), 38 таблиц.
  Валидация: qword0 — PAC-указатель в `__TEXT_EXEC`, четыре 32-битных счётчика ≤ 4 МБ либо
  `0xffffffff` (`kIOUCVariableStructureSize`), серия ≥ 3 подряд.
  Итог: **189 таблиц, 2090 записей, 67 именованных kext'ов** + 39 таблиц в неатрибутированном
  `__DATA_CONST`.
* Цель записи разрешается через GOT-трамплин
  (`adrp x17,page; add x17,x17,#imm; ldr x16,[x17]; braa x16,x17`) и tail-тюн `b`.
* Dataflow: `x2` = `IOExternalMethodArguments *` (`IOExternalMethodAction(target, reference,
  args)`); отслеживаются копии (`mov`), спиллы на стек, `ldr Xt,[args,#0x78]` → регистр
  помечается как varout-указатель, затем ищется запись через него (`str/stp [Xt]`). Вызовы
  `bl`/`b` с помеченными аргументами прослеживаются на глубину 2.
* Независимая проверка: сплошной проход по **1523** функциям, которые вообще читают
  `[x?,#0x78]` (3333 инструкции `ldr/ldur/ldp`). Ровно **14** функций пишут через полученный
  указатель — те же, что дали таблицы, плюс три вызова через vtable.

---

## 3. Результат: кто пишет в var-output

`f = [sIn, strIn, sOut, strOut]` из записи таблицы; `0xffffffff` = переменный размер.
При `*varout == NULL` все обработчики, кроме DriverKit-прокси, сразу возвращают
`kIOReturnBadArgument` (`0xe00002c2`); прокси в этом случае уходит на обычный путь через
`structureOutputDescriptor`.

| # | функция | kext / класс | таблица + селектор | гейт | что кладётся | адрес записи |
|---|---------|--------------|--------------------|------|--------------|--------------|
| 1 | `0xfffffff00932c994` | AppleT8110CLPC / `AppleCLPCUserClient` | `0xfffffff007f19d48` stride 0x18, **sel 6**, f=[0,0,0,-1] | **нет** | 64-битное значение из out-параметра `AppleCLPC::…(&slot)`; далее `str x8,[varout]` | `0xfffffff00932c9ec` |
| 2 | `0xfffffff00932ca04` | AppleT8110CLPC / `AppleCLPCUserClient` | `0xfffffff007f19d48`, **sel 7**, f=[0,0,0,-1] | **нет** | то же (вторая ветка/ключ) | `0xfffffff00932ca5c` |
| 3 | `0xfffffff0097b6cf0` | IOAVFamily / `IOAVServiceUserClient` (кандидат) | `0xfffffff007f94da0` 0x18, **sel 26**, f=[0,0,0,-1] | **нет** | объект из виртуального метода, строка `"_copyEDID"` | `0xfffffff0097b6d54` |
| 4 | `0xfffffff0097b7154` | IOAVFamily / тот же | `0xfffffff007f94da0`, **sel 31**, f=[0,0,0,-1] | **нет** | то же | `0xfffffff0097b71b8` |
| 5 | `0xfffffff009994f34` | IOGameControllerFamily / `IOGCDynamicDeviceProbeUserClient` | `0xfffffff007ff2f98` stride **0x28**, **sel 5**, f=[1,-1,0,-1] | **нет** | объект-сериализация в буфере 0x1000, ключи `QueueID`, `QueueGuard`, `QueueMemorySize`, `QueueEntrySize` | `0xfffffff009995370` |
| 6 | `0xfffffff00999a0d0` | IOGameControllerFamily | таблица не найдена: вызов через vtable/указатель (не подтверждено) | **нет** | объект `x23` после виртуального `serialize` | `0xfffffff00999ac58` |
| 7 | `0xfffffff00999acf0` | IOGameControllerFamily | там же | **нет** | то же | `0xfffffff00999aea8` |
| 8 | `0xfffffff009a459b0` | IOHIDFamily | `0xfffffff008012058` 0x28, **sel 4**, f=[0,-1,0,-1] | **нет** | объект, созданный из `structureInput` (0x9a4815c + конструктор 0x9a483bc), затем виртуальный метод с `&slot` | `0xfffffff009a45a6c` |
| 9 | `0xfffffff009c3968c` | IOSurface / `IOSurfaceRootUserClient` | `0xfffffff008068b90` 0x28, **sel 30**, f=[1,0,0,-1] | **ДА** — `ldrb w8,[x0,#0x122]; tbz` → `kIOReturnNotPrivileged`; флаг ставит `0xfffffff009c3a2d4` по `"com.apple.private.iosurfaceinfo"` | объект surface info (1 МБ под сериализацию) | `0xfffffff009c39730` |
| 10 | `0xfffffff009c39e0c` | IOSurface / `IOSurfaceRootUserClient` | `0xfffffff008068b90` 0x28, **sel 49**, f=[1,0,0,-1] | **нет** | объект (по данным Kai буфер пустой) | `0xfffffff009c39ea0` |
| 11 | `0xfffffff009d241cc` | IOUSBHostFamily (`AppleUSBHostDeviceUserClient` / `IOUSBDeviceUserClientV2` — не подтверждено) | `0xfffffff00808f0a0` 0x18 **sel 4** и `0xfffffff0080927b8` 0x18 **sel 4**, f=[5,0,1,-1] | **нет** | `OSData` дескриптора USB из `0x9dabeb0(value)`; дополнительно пишет 16-бит в scalarOutput (`args+0x48`) | `0xfffffff009d24288` |
| 12 | `0xfffffff009ffa1d4` | apfs / `AppleAPFSUserClient` | `0xfffffff0080e1730` 0x18, **sel 2**, f=[0,4,0,0] | **нет** (только `index <= 0x63`) | буфер 0x1000, заполняется виртуальным методом; сначала `str xzr` | `0xfffffff009ffa414` (+ обнуление `0xfffffff009ffa234`) |
| 13 | `0xfffffff009fff338` | apfs / `AppleAPFSUserClient` | `0xfffffff0080e1148` 0x18, **sel 8**, f=[0,0,0,0] | **нет** | объект, возвращённый вызовом (`mov x21,x0` после `blraa`); сначала `str xzr` | `0xfffffff009fff490` (+ обнуление `0xfffffff009fff374`) |
| 14 | `0xfffffff00a9c4778` | **com.apple.kernel** — DriverKit-прокси `IOUserUserClient` (externalMethod override; рядом `OSAction_IOUserClient_KernelCompletion`, `IOUserServer.cpp`) — класс не подтверждён | таблицы нет, vtable-слот `0xfffffff007c63a50` | **нет** per-selector | объект, полученный от dext в completion-пути | `0xfffffff00a9c49b8` |

Итого: **14 функций, 12 пар (таблица, селектор)**. `0x9d241cc` (USB) прописан в двух разных
таблицах IOUSBHost с одним и тем же селектором 4; остальные пары — в разных kext'ах.

**IOSurface — две таблицы, а не одна.** Непрерывный прогон из 120 записей по 0x28 — это на самом
деле два массива по 60:

* `0xfffffff008068b90` (UC №1): sel 30 → `0xfffffff009c3968c`, sel 49 → `0xfffffff009c39e0c`;
* `0xfffffff0080694f0` (UC №2): те же 60 селекторов, но 23 из них (`4,5,6,7,8,16,17,18,19,21,22,
  24,25,26,28,29,30,33,43,46,47,48,49`) заменены заглушкой `0xfffffff009c3a1dc`
  (`mov w0,#0xe00002e2; ret` = `kIOReturnUnsupported`). То есть **sel 30 и 49 у второго
  user client'а закрыты полностью** — канал живёт только на одном из двух.

### Тип объекта

Везде в var-output кладётся **указатель на OSObject**. Ядро принимает только `OSSerialize`
(копируется `text()`) либо `OSData` (копируются байты); иначе `kIOReturnUnderrun`.
Конкретный класс по статике не подтверждён (в бинаре нет символов, `LC_SYMTAB` пуст,
`nsyms=0`); по объёму буфера (1 МБ в IOSurface sel 30, 0x1000 в apfs/IOGame) похоже на
`OSSerialize` с capacity. Для строк 1–4, 8, 13 значение — объект/значение, возвращённое
вызовом через out-параметр, поэтому тип определяется тем, что вернул сервис.

---

## 4. Диспетчерские таблицы

Полный список — `tables_full.txt` (189 строк: адрес, stride, число записей, kext, сегмент,
индексы с `strOut == 0xffffffff`).

Сводка:

| параметр | значение |
|---|---|
| всего таблиц | 189 (`__DATA_CONST` 178, `__DATA` 11) |
| классических 0x18 (`IOExternalMethodDispatch`) | 151, записей 1657 |
| 0x28 (`IOExternalMethodDispatch2022`) | 38, записей 433 |
| записей с `strOut == 0xffffffff` (переменный вывод) | 147 |
| записей с непустым `checkEntitlement` | **0** |
| записей с `allowAsync == 1` | 110 |
| kext'ов с таблицами | 67 именованных + неатрибутированные |

Таблицы, в которых сидят найденные писатели:

```
0xfffffff007f19d48  0x18  11  AppleT8110CLPC            sel 6, 7
0xfffffff007f94da0  0x18  33  IOAVFamily                sel 26, 31
0xfffffff007ff2f98  0x28   6  IOGameControllerFamily    sel 5
0xfffffff008012058  0x28   5  IOHIDFamily               sel 4
0xfffffff008068b90  0x28  60  IOSurface                 sel 30, 49 (первый UC)
0xfffffff0080694f0  0x28  60  IOSurface                 те же селекторы, 23 -> kIOReturnUnsupported (второй UC)
0xfffffff008069e58  0x18  26  IOSurface                 мелкие thunk-методы, counts = 0
0xfffffff00808f0a0  0x18  29  IOUSBHostFamily           sel 4
0xfffffff0080927b8  0x18  15  IOUSBHostFamily           sel 4
0xfffffff0080e1148  0x18  11  apfs                      sel 8
0xfffffff0080e1730  0x18  18  apfs                      sel 2
```

### Главная находка по гейтам

`IOExternalMethodDispatch2022::checkEntitlement` (поле +0x20 записи) — **не заполнено ни в одной
из 433 записей** во всём kernelcache. То есть декларативного per-selector энтайтлмента
(`dispatchExternalMethod` → `kIOReturnNotPrivileged`) в этой сборке не использует никто;
все проверки, которые есть, спрятаны в телах обработчиков или на открытии user client.

Из **139** уникальных обработчиков, объявленных с переменным structure-output
(`strOut == 0xffffffff`), поле `+0x78` вообще читают только **11**, и **9** из них пишут через
него (ещё два — `0xfffffff0097b8ff8` и `0xfffffff0097b91cc` — читают/пишут, но args приходит
в `x21`, см. §6). Остальные отдают данные через `structureOutputDescriptor` (`+0x68`) и к каналу
`var-output` отношения не имеют.

Отдельно стоит отметить: `strOut == 0xffffffff` — **не** обязательный признак. Два писателя
(apfs sel 2 с f=[0,4,0,0] и apfs sel 8 с f=[0,0,0,0]) объявлены с обычным structure-output,
но всё равно пишут в `+0x78`.

---

## 5. Вывод: где канал ядро→app без энтайтлментов

Без какой-либо проверки прав (кроме `*varout != NULL` и валидации размеров/индексов входа):

* **com.apple.kernel, `0xfffffff00a9c4778`** — код в DriverKit-регионе (`IOUserServer.cpp`,
  `OSAction_IOUserClient_KernelCompletion`), форма `externalMethod(self, selector, args)`.
  Пишет в varout объект, полученный в completion-пути от dext'а. Если это действительно
  `IOUserUserClient` (не подтверждено), то это общий канал для всех DriverKit-сервисов;
  per-selector гейтов в нём нет, ограничение — энтайтлменты dext'а на загрузку.
* **apfs**, `AppleAPFSUserClient`: sel 2 (`0xfffffff009ffa1d4`) и sel 8 (`0xfffffff009fff338`).
* **AppleT8110CLPC**, `AppleCLPCUserClient`: sel 6 и sel 7 — отдают значение/объект CLPC-сервиса.
  (энтайтлменты `com.apple.private.clpc.*` в kext'е есть, но в теле этих методов не проверяются).
* **IOUSBHostFamily**: sel 4 в двух таблицах — отдаёт `OSData` USB-дескриптора наружу.
* **IOAVFamily**: sel 26 и 31 — `_copyEDID`.
* **IOGameControllerFamily**: sel 5 (строка 5 таблицы) + два метода, вызываемых через vtable
  (строки 6 и 7) — дамп очередей (`QueueID`/`QueueGuard`/`QueueMemorySize`/`QueueEntrySize`).
* **IOHIDFamily**: sel 4 — объект, собранный из `structureInput`.

С проверкой:

* **IOSurface sel 30** — единственный найденный обработчик, который перед записью смотрит
  закешированный флаг `IOSurface+0x122`; флаг выставляет `0xfffffff009c3a2dc`
  (`strb w0,[x19,#0x122]`) по результату проверки `"com.apple.private.iosurfaceinfo"`
  (функция `0xfffffff009c3a60c`, рядом также `"com.apple.private.IOSurface.protected-access"`).
  При снятом флаге — `kIOReturnNotPrivileged`.
* **IOSurface sel 49** — гейта нет; по данным Kai буфер пустой, то есть данные не отдаются
  по другой причине (проверять на живой системе). Плюс: у второго IOSurface user client'а
  (таблица `0xfffffff0080694f0`) и sel 30, и sel 49 заменены заглушкой `kIOReturnUnsupported`.

### Отдельно: два IOAVFamily-метода, не включённые в таблицу

`0xfffffff0097b8ff8` и `0xfffffff0097b91cc` (таблица `0xfffffff007f95f48` stride 0x18,
**sel 5 и 6**) делают ровно то же:

```
ldr x8,[sp,#0x28] ; значение из out-параметра
ldr x9,[x21,#0x78] ; varout
str x8,[x9]
```

но `x21` в этих функциях **нигде не инициализируется**: чтение и запись идут только через `x21`
(`ldr x9,[x21,#0x78]`), значит указатель на args должен прийти от вызывающего. Прямых `bl/b`
на эти адреса нет вообще — только непрямые ветвления, поэтому статически провенанс `x21` не
восстанавливается. Если на живой системе `x21` действительно равен `args`, это ещё два
незакрытых канала в IOAVFamily (sel 5/6), но это **не подтверждено**.

---

## 6. Что не подтверждено

* Имена классов: в kernelcache нет символов (`LC_SYMTAB` с `nsyms = 0`), привязка
  «таблица → класс» сделана по kext'у, строкам `*UserClient*` и `IOUserClientClass`
  из `__PRELINK_INFO`. Для IOSurface / apfs / CLPC / IOGameController класс следует из
  единственного user client'а в kext'е; для IOUSBHost / IOAV / IOHID — кандидаты, не доказано.
* Точный класс объекта в var-output (`OSSerialize` vs `OSData`) — не доказан, кроме общего
  требования ядра.
* Проверки на **открытии** user client (`initWithTask`, `kIOUserClientEntitlementsKey`) не
  анализировались: канал может быть недоступен непривилегированному процессу ещё до вызова
  метода. Это следующий логичный шаг, если нужен полный путь от app до данных.
* Виртуальные вызовы (`blraa`, `braa`) не девиртуализированы: если метод передаёт varout
  в виртуальный helper, а тот пишет, такой случай мог не попасть в список. Проверка «передать
  указатель в вызов» дала 7 кандидатов, все разобраны вручную — ложные (x2 там не args).
* `0xfffffff0097b8ff8` / `0xfffffff0097b91cc` (IOAV, sel 5/6) — args в `x21`, см. выше.
* 39 таблиц лежат в `__DATA_CONST` без атрибуции к kext'у (нет per-kext сегмента в заголовках);
  на список писателей это не влияет — сканировался весь сегмент.
* Sandbox-профили приложений не учитывались: `io_connect_method_var_output` может быть закрыт
  песочницей независимо от энтайтлментов.

---

## 7. Файлы

```
progress.md            журнал шагов
tools.py               загрузчик, PAC, поиск таблиц, GOT-трамплины
flow.py                абстрактный интерпретатор args/varout
s1_strings.py          строки + xrefs (энтайтлменты)
s2_tables.py           поиск таблиц -> tables.json
s3_walk.py             обход записей таблиц -> s3_hits.json
s4_global.py           сплошной скан функций с [x?,#0x78] -> s4_global.json
s5_dump.py             дампы писателей -> dump/*.txt
s6_final.py            сводка -> final_writers.json
tables.json            189 таблиц с записями
tables_full.txt        человекочитаемый список таблиц
final_writers.json     14 писателей + гейты
dump/                  дизассемблер каждого писателя
```
