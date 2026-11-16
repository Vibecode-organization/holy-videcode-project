# XPC-парсеры: memory corruption triage (iOS 27.2 / 24B115)

Сервисы из `container.sb` (`require-any` → `xpc-service-name`), которые парсят чужие байты в чужом процессе:
`ImageIOXPCService`, `iWorkFileFormat`, `textkit.nsattributedstringagent`, `PrintKit.PrinterTool`,
`BarcodeSupport.ParsingService`.

Метод: статика. Бинари из `out272_clean/141-10327-211.dmg`, фреймворки — из `dsc272`
(`ipsw dyld extract`), дизасм — capstone поверх `LC_SEGMENT_64` + резолв `__auth_stubs`/`__objc_stubs`
и chained fixups. Динамики нет: ни один кандидат не подтверждён запуском.

---

## 1. Сводная таблица

| Сервис | Бинарь (размер) | XPC-вход | Что парсит | Лимиты | Вердикт |
|---|---|---|---|---|---|
| ImageIOXPCService | `.../ImageIO.framework/XPCServices/ImageIOXPCService.xpc/ImageIOXPCService` (56 288) | `_IIOProcessEvent` — 8 ID + словарь | любые image-байты через `iio_xpc_src_data`; все `IIO_Reader_*` | нет глобального лимита размера; лимиты внутри ридеров | **есть кандидат** (`IIO_Reader_ICO::getImageCount`, OOB-read) — не подтверждено |
| textkit.nsattributedstringagent | `.../UIFoundation.framework/XPCServices/nsattributedstringagent.xpc/nsattributedstringagent` (75 776) | 3 селектора `_NSAttributedStringAgentProtocol` | `readFromData:` → `initWithData:` (HTML/RTF в UIFoundation); `renderHTML:` → WebKit `loadData:MIMEType:` | RTF: `maximumNestedGroups`; HTML: без лимита размера | **есть кандидат** (`colspan/rowspan`, overflow/OOM) — не подтверждено |
| BarcodeSupport.ParsingService | `.../BarcodeSupport.framework/XPCServices/com.apple.BarcodeSupport.ParsingService.xpc/...` (74 640) | 4 селектора | строки QR, метаданные, `CIQRCodeFeature`, App Clip payload | длина дескриптора сверяется с ожидаемой | **чисто** на уровне XPC-обвязки; Quagga-декодер не подтверждён |
| PrintKit.PrinterTool | `.../PrintKit.framework/XPCServices/com.apple.PrintKit.PrinterTool.xpc/...` (912 384) | 757 селекторов, IPP/URF/HTTP | IPP-бинарь от принтера, URF, gzip/deflate | нет лимита на глубину IPP-коллекций (не проверено) | **есть кандидат** (`ippReadIO`, глубина коллекций) — не подтверждено |
| iWorkFileFormat | `.../iWorkXPC.framework/XPCServices/iWorkFileFormat.xpc/iWorkFileFormat` (2 542 352) | 1 селектор, путь к файлу | TSP/protobuf/snappy из файла по URL | не проверялось | **чисто** на уровне XPC-обвязки (байтов в сообщении нет) — парсер файла не подтверждён |

Все пять — отдельные процессы. Ценность RCE разная: у `nsattributedstringagent` в энтайтлментах
16 mach-lookup (securityd-смежные `ak.authorizationservices`, `securityd` нет, но есть
containermanagerd, frontboard.systemappservices, fontservicesd, backboard.*, analyticsd,
`lsd.open`, `iconservices`, `usymptomsd`), у `PrinterTool` — сетевые сокеты
(`network.socket-delegate`, `necp.match`), `frontboard.launchapplications`; у `iWorkFileFormat` —
свой seatbelt-профиль `iWorkXPC` (доступ к файлам по URL), у `ImageIOXPCService` — `autobox`,
у Barcode — `platform-application` + `associated-domains`.

---

## 2. ImageIOXPCService

### 2.1 Обвязка

Бинарь — шим: `_main` → `_xpc_main`, обработчик соединения ставит блок, который вызывает
`_IIOProcessEvent(connection, msg)` (импорт из `ImageIO`) и отправляет ответ
(`ImageIOXPCService+0xde8`, `+0xe38`). Никакого парсинга в шиме нет.

`_IIOProcessEvent` в `ImageIO` = **0x187a76190**:

```
0x187a761d0  mov  x0, x1
0x187a761d4  bl   0x187aaed30            ; xpc_dictionary_create_reply / copy
0x187a761dc  adrp x1, 0x187dcd000 ; "iio_xpc_message_id"
0x187a761e8  bl   0x18813c9c0           ; xpc_dictionary_get_string
0x187a761f0  adrp x1, 0x187e04000 ; "iio_xpc_transacion_id"
0x187a761fc  bl   0x18813c9c0
0x187a76204  bl   0x187a5f1e4           ; IIOXPCUpdatePermissions
0x187a76210  bl   0x187a5f3d0           ; IIOXPCUpdateAllowableTypes
0x187a762c0  cmp  x23, #3
0x187a762c4  b.le 0x187a7636c
```

Диспетчер по `atoi(iio_xpc_message_id)` (сравнения `cmp x23,#N`):

| id | имя (строка лога) | адрес ветки |
|---|---|---|
| 1 | `XPC_READPLUGIN_IDENTIFY` | 0x187a764f4 |
| 2 | `XPC_READPLUGIN_IMAGECOUNT` | 0x187a766b8 |
| 3 | `XPC_READPLUGIN_SOURCEPROPERTIES` | 0x187a76384 |
| 4 | `XPC_READPLUGIN_INITIMAGE` | 0x187a76598 |
| 5 | `XPC_READPLUGIN_DEBUG` | 0x187a762e0 |
| 6 | `XPC_READPLUGIN_DECODE_IMAGE` | 0x187a76628 |
| 8 | `XPC_READPLUGIN_WAKEUP` | 0x187a76414 |

Ключи словаря (все из `__cstring` ImageIO): `iio_xpc_src_data`, `iio_xpc_src_header_data`,
`iio_xpc_src_hint_string`, `iio_xpc_src_image_count`, `iio_xpc_src_utitype`,
`iio_xpc_plugin_data`, `iio_xpc_plugin_data_{atx,tga}`, `iio_xpc_msg_pid`, `iio_xpc_msg_name`.

Клиент шлёт **сами байты файла** (`iio_xpc_src_data`) → сервис прогоняет их через свой ридер.
То есть поверхность = все форматы ImageIO: 26 классов ридеров
(`IIO_Reader_{AI, AppleJPEG, ASTC, ATX, BC, BMP, CUR, ETC, GIF, HEIF, ICNS, ICO, JP, KTX, LibJPEG,
MPO, OpenEXR, PBM, PDF, PNG, PSD, PVR, RAD, TGA, TIFF, WebP}`), плюс встроенные libtiff,
libwebp/VP8L и libjpeg — это отдельные C-парсеры в том же процессе.

### 2.2 Кандидат: `IIO_Reader_ICO::getImageCount` — 0x187a0af68

```
0x187a0af80  mov  x0, x1                 ; IIOImageReadSession*
0x187a0af84  cbz  x4, ...
0x187a0af88  str  wzr, [x19]             ; *out_count = 0
0x187a0af8c  strh wzr, [sp, #0xc]        ; 6-байтный буфер, обнулён 2 байта
0x187a0af90  str  wzr, [sp, #8]
0x187a0af94  add  x1, sp, #8
0x187a0af98  mov  x2, #0
0x187a0af9c  mov  w3, #6
0x187a0afa0  bl   0x18786af5c            ; getBytes(session, buf, offset=0, len=6)
0x187a0afa4  mov  w8, w0
0x187a0afa8  cmp  x8, #6
0x187a0afac  mov  w9, #-0x32
0x187a0afb0  csel w0, w9, wzr, ne        ; kIIOError (-50), если прочитано != 6
0x187a0afb4  cbz  x19, 0x187a0afcc
0x187a0afb8  cmp  x8, #6
0x187a0afbc  b.ne 0x187a0afcc
0x187a0afc0  mov  w0, #0
0x187a0afc4  ldrb w8, [sp, #0xc]         ; count = buf[4]  (только младший байт!)
0x187a0afc8  str  w8, [x19]
```

Наблюдения:
- `count` берётся из файла (ICONDIR: reserved u16, type u16, count u16). Читается **один байт**
  (`ldrb`), старший байт 16-битного count отбрасывается — расхождение с форматом, но не порча памяти.
- **Нет сверки `count * 16` с длиной файла** в этой функции. Проверка `getBytes == 6` покрывает
  только заголовок. Если `IIO_Reader_ICO::createReadPlugin` читает `count` записей каталога
  (по 16 байт) без повторной валидации против `IIOImageReadSession::getLength`, то `count` до 255
  даёт чтение за EOF — но каждый `getBytes` сам по себе bounds-checked, поэтому это OOB-read только
  если каталог кэшируется в один буфер одним `getBytes(count*16)`.
- Тип: потенциальный **OOB-read / integer truncation**, не подтверждено (нужен дизасм
  `IIO_Reader_ICO::createReadPlugin` 0x187a0ae50 и 0x187a0aed0 — отдельного `parse` у ICO нет).

### 2.3 Что проверено и чисто

`_IIOXPCDecodeCGImageMetadataTag` — **0x187ab2d54**: разбирает один тег из XPC-словаря,
типы 0..4, для массива создаёт `CFMutableArray` и наполняет его; рекурсии в себя нет
(вызовы только `_CGImageMetadataTagCreate` 0x187869c00), глубина вложенности = 1.
`_CGImageMetadataCreateFromXPCObj` — **0x187ab1bdc**: плоский набор ключей, без рекурсии.
Классического «вложенные контейнеры без лимита глубины» здесь нет.

`TIFFReadDirEntryDataAndRealloc` — **0x1878cc568**: переаллокация кусками
(`x24 = x23 + x25`, рост `x26 = x26*5*2`), на каждой итерации `realloc` + проверка
возвращённого количества; переполнения `count*size` не видно (`subs x8, x21, x25` до выделения).
Apple-форк libtiff здесь выглядит прикрытым.

---

## 3. textkit.nsattributedstringagent

### 3.1 Протокол и whitelist

`_NSAttributedStringAgentProtocol` (адреса IMP из `__objc_methlist` 0x1000026c0):

| селектор | IMP |
|---|---|
| `startWithReply:` | 0x100001284 |
| `renderHTML:options:extensionTokens:withReply:` | 0x100001294 |
| `readFromData:orFileURL:options:extensionTokens:withReply:` | 0x100001834 |

`_NSAttributedStringAgentService listener:shouldAcceptNewConnection:` (0x100000d98) строит
`NSXPCInterface` для протокола и вызывает `setClasses:forSelector:argumentIndex:ofReply:`
(стаб 0x100002600) шесть раз:

```
renderHTML:   arg1 -> _allowedOptionClasses, arg2 -> _allowedTokensClasses, reply0 -> _allowedOptionClasses
readFromData: arg2 -> _allowedOptionClasses, arg3 -> _allowedTokensClasses, reply1 -> _allowedOptionClasses
```

Сами списки — в UIFoundation:
`+[NSAttributedString(NSAttributedStringAgent) _allowedOptionClasses]` **0x194b97cf4** —
`NSMutableSet` из 6 элементов: базовый класс (0x1e010b8e0) + 3 класс-рефа (0x1e010beb0,
0x1e00fe270, 0x1e00fe1a8) + 2 приватных класса по имени (0x1e3926a08, 0x1e3926948);
`_allowedTokensClasses` **0x194b97dcc** — 2 класса. Точные имена классов лежат в `__DATA_CONST`
DSC и не резолвились (в extracted-бинаре этой секции нет). То есть `options`/`extensionTokens`
— не «просто `NSAttributedString`», а расширяемый набор контейнеров/скаляров.

`readFromData:` (0x100001834) сначала перебирает `extensionTokens`, у каждого берёт `-bytes`
(0x100002400) и вызывает `sandbox_extension_consume` (0x10000232c), результат пакует в `NSNumber`.
Затем через `dlsym` из UIFoundation достаёт `_NSReadAttributedStringFromURLOrDataAgent`
(строка 0x100002ea8, `__sl_dlopen` 0x100001f08) и вызывает его с `(data, url, options, tokens, reply)`.

Бэкенды:
- `renderHTML:` (0x100001294) — единственный путь в WebKit: он tail-call'ом уходит в
  `WKWebView loadData:MIMEType:characterEncodingName:baseURL:` (стаб 0x1000024e0), т.е. HTML
  разбирает WebKit, а не сервис;
- `readFromData:` → dlsym `_NSReadAttributedStringFromURLOrDataAgent` → UIFoundation
  `__NSReadAttributedStringFromURLOrData` (**0x194b347fc**) → `-[NSAttributedString
  initWithData:options:documentAttributes:error:]` (**0x194b34700**). Внутри — свои ридеры:
  `-[NSHTMLReader initWithData:options:]` (**0x194be9588**, libxml2 + DOM-обход) и
  `NSRTFReader` (**0x194bdd460**). `+loadFromHTMLWithData:options:completionHandler:`
  (0x1000011b8) — обёртка над тем же `initWithData:` (виден вызов стаба 0x100002440),
  не WebKit.

### 3.2 Лимиты

- RTF: есть `+[NSRTFReader maximumNestedGroups]` **0x194bdc678** (плюс cold-путь
  0x194bfd4dc) — т.е. лимит глубины в коде заложен; что он реально применяется в цикле
  разбора `{\*\...}`, не проверял (не подтверждено).
- HTML: лимита на размер входа в `readFromData:` нет; ограничение только со стороны XPC
  (размер сообщения) и памяти.

### 3.3 Кандидат: `colspan`/`rowspan` — 0x194be613c, `-[NSHTMLReader _addTableCellForElement:]`

```
0x194be6260  cbz  x21, 0x194be628c
0x194be6264  adrp x8, 0x1f6417000
0x194be6268  add  x1, x8, #0x2e0        ; CFString @0x1f64172e0 (colspan?)
0x194be626c  mov  x0, x21
0x194be6270  bl   0x1980fd9f0          ; respondsToSelector:
0x194be6274  tbz  w0, #0, 0x194be6298
0x194be6278  mov  x0, x21
0x194be627c  bl   0x1980b2450          ; -integerValue
0x194be6280  cmp  w0, #1
0x194be6284  csinc w26, w0, wzr, gt     ; w26 = max(1, colspan)
0x194be6288  b    0x194be629c
0x194be628c  mov  w27, #1
0x194be6290  mov  w26, #1
0x194be6294  b    0x194be62c8
0x194be6298  mov  w26, #1
0x194be629c  adrp x8, 0x1f6417000
0x194be62a0  add  x1, x8, #0x49c        ; CFString @0x1f641749c (rowspan?)
0x194be62a4  mov  x0, x21
0x194be62a8  bl   0x1980fd9f0          ; respondsToSelector:
0x194be62ac  tbz  w0, #0, 0x194be62c4
0x194be62b0  mov  x0, x21
0x194be62b4  bl   0x1980af5d0          ; -integerValue
0x194be62b8  cmp  w0, #1
0x194be62bc  csinc w27, w0, wzr, gt     ; w27 = max(1, rowspan)
0x194be62c0  b    0x194be62c8
0x194be62c4  mov  w27, #1
0x194be62c8  ...
0x194be62dc  mov  x4, x26               ; colspan → аргумент
0x194be62e0  mov  x5, x25               ; row/col index
0x194be62e4  mov  x6, x27               ; rowspan → аргумент
0x194be62e8  bl   0x1980b0c80
```

Два атрибута ячейки (CFString-константы 0x1f64172e0 и 0x1f641749c; по семантике — `colspan`/`rowspan`)
полностью под контролем атакующего (`<td colspan=2147483647>`). Верхняя граница **не проверяется**: только `max(1, x)`. Дальше значения уходят в построение
табличной сетки (0x1980b0c80 и `-[NSHTMLReader _addTableForElement:]`/`_exitElement:...`).

Тип кандидата: **integer overflow / unbounded allocation** при расчёте сетки
(`rowspan * colspan`, индексы строк/столбцов). Если где-то по пути `colspan` умножается на
`sizeof(ptr)` или складывается с индексом в 32 битах — получим маленькое выделение и запись
по большому индексу. Не подтверждено: нужен дизасм `_exitElement:tag:display:depth:startIndex:`
(**0x194be70a4**) и `_addTableForElement:` (**0x194be5eac**) — проверка границ сетки там.

---

## 4. BarcodeSupport.ParsingService

`BarcodeParsingService` (0x100008550), протокол `BarcodeParsingServiceProtocol`:

| селектор | IMP | вход |
|---|---|---|
| `parseQRCodeString:withReply:` | 0x100000f98 | `NSString` |
| `parseQRCodeMetadata:withReply:` | 0x100001078 | `NSDictionary` |
| `parseQRCodeFeature:withReply:` | 0x1000011d4 | `CIQRCodeFeature` |
| `decodeAppClipCodeURLWithEncodedData:codingVersion:requiresAuthorization:withReply:` | 0x10000164c | `NSData` + версия |

App Clip путь: `decodeAppClipCodeURL...` → `_MRCDescriptorCreateWithAttributes` (Quagga
0x2a2de8660) → `_MRCDescriptorDecodePayload` (0x2a2de89cc → `MRCDescriptorDecodePayloadWithOptions`
0x2a2de89d8). В декодере есть сверка длины дескриптора:

```
0x2a2de8ad8  cbz  x21, 0x2a2de8b08
0x2a2de8adc  mov  x0, x21
0x2a2de8ae0  bl   0x2a80685c0           ; длина дескриптора (Quagga)
0x2a2de8ae4  mov  x23, x0
0x2a2de8af8  ldr  x8, [x8, #0x748]       ; ожидаемая длина payload (после dispatch_once)
0x2a2de8b00  cmp  x23, x8
0x2a2de8b04  b.ne 0x2a2de8bf4           ; несовпадение → ошибка, декод не запускается
```

Дальше `sub_2a2dd2584` (0x2a2dd2584) — сам битовый декодер, вызывается только при совпадении длины.
App Clip payload в BarcodeSupport (`-[BCSAppclipCodePayload initWithData:version:]` 0x259feb01c)
не парсится, а сохраняется (`objc_storeStrong` в +8, версия в +0x10); разбор — позже в
`+[BCSAction getActionWithData:codePayload:completionHandler:]` (0x259fc37f8).

Вердикт: **чисто** на уровне XPC-обвязки и пре-декодной проверки длины. Глубина `sub_2a2dd2584`
и `BCSAction` не аудирована — «не подтверждено».

---

## 5. PrintKit.PrinterTool

912 КБ, 757 методов. Внутри — полноценный IPP-стек: классы `ipp_t` (0x1000c0448),
`ipp_attribute_t` (0x1000c03f8), `ipp_collection_t` (0x1000c03a8), `ipp_request_t`,
`ipp_response_t`, `Real_IPP_Message`, `http_ipp_response_t`, `device_http_t`, плюс
`application/urf`, `DocumentCompressor` (zlib `deflate`, чанк 0x2000 — 0x100003504),
TLS (`PKSecTrustWrapper`, `PKNAN*`, Bonjour/NAN/Extension browse).

Точка входа разбора — `ippReadIO` **0x100001720** (C++ `_Z9ippReadIOPvPFlS_PhmEP5ipp_t`),
внутри — машина состояний `sub_100001860`:

```
0x100001720  pacibsp
0x100001754  add  x0, sp, #0x20
0x100001760  bl   0x100002ce0            ; ipp_t::init / reader ctx
0x100001764  mov  w8, #0x13
0x100001768  stp  wzr, w8, [sp, #0x18]   ; state=0, tag=0x13 (end-of-attributes)
0x100001770  add  x1, sp, #0x18
0x100001774  add  x2, sp, #0x1c
0x100001778  mov  w3, #0
0x10000177c  mov  x4, x19
0x100001780  bl   0x100001860            ; ippReadIO_state_machine
...
0x100001860  sub  sp, sp, #0x460         ; 0x460 байт стека на кадр
0x1000018ac  ldr  w8, [x19]              ; state
0x1000018b0  cmp  w8, #2
0x1000018b8  cmp  w8, #1
0x1000018e0  add  x1, sp, #0x50
0x1000018e8  mov  w2, #8
0x1000018ec  bl   0x100002d38            ; read 8 байт заголовка IPP
0x1000018f0  ldrh w8, [sp, #0x52]
0x1000018f4  rev  w8, w8                 ; big-endian
0x1000018f8  lsr  w2, w8, #0x10
0x100001900  bl   0x100064340            ; setOp_or_status:
0x100001904  ldr  w8, [sp, #0x54]
0x100001908  rev  w2, w8
0x100001910  bl   0x100064620            ; setRequest_id:
```

IPP — бинарный протокол с 16-битными длинами значений и **вложенными коллекциями**
(`ipp_collection_t` внутри `ipp_attribute_t`). Классический вектор: коллекция в коллекции без
лимита глубины → рекурсивный разбор → stack exhaustion, либо счётчик элементов, по которому
сразу выделяется массив.

Кандидат: **нет видимого лимита глубины коллекций** в `ippReadIO`/`sub_100001860`
(машина состояний, рекурсию в явном виде не показала, но глубина коллекций не ограничена
константой в прологе). Тип: **stack exhaustion / unbounded alloc**. Не подтверждено —
нужен разбор ветки `ipp_collection_t` (тег 0x34) и `ReadAttribute` внутри `0x100001860`.

Достижимость: `PrinterTool` ходит в сеть (`com.apple.private.network.socket-delegate`,
`necp.match`) и общается с принтером/extension'ом; IPP-ответ принтера — контролируемый
извне вход. Плюс `PrintKitExtension` грузит сторонние extension'ы
(`PrintKitExtension(%@): Exception caught processing dictionary`) — это уже другой процесс.

---

## 6. iWorkFileFormat

2.5 МБ, но наружу торчит **один** метод:

```
ServiceDelegate listener:shouldAcceptNewConnection:   0x100001638
iWorkFileFormat -prepareFileForUploadingAtURL:originalURLExtension:inDirectory:
                 destinationSandboxExtension:completionHandler:   0x100001724
```

В сообщении нет байтов документа — только `NSURL`, расширение, каталог и sandbox-extension.
`prepareFileForUploading…` (шим на 0x10000172c) читает файл **по URL** и гоняет его через
`TSPPackageWriter`/`TSPFileManager`/`TSPArchiveMessages` — это protobuf (`TSPArchiveMessages.proto`),
`snappy` (`SnappySource`), zip-контейнер iWork-пакета.

Вердикт: **чисто** на уровне XPC-обвязки — парсинга байтов из сообщения нет. Реальная поверхность
— парсер iWork-пакета (protobuf + snappy + zip) по пути, который клиент может указать;
энтайтлменты сервиса — только `seatbelt-profiles: [iWorkXPC]`. Аудит TSP-парсера не делался,
«не подтверждено». Отдельно стоит проверить, что `iWorkXPC`-профиль не даёт читать больше,
чем контейнер приложения (это уже не memory corruption).

---

## 7. Итог

| Сервис | Кандидат | Адрес | Тип | Статус |
|---|---|---|---|---|
| ImageIO | `IIO_Reader_ICO::getImageCount` — count из файла, без сверки с длиной | 0x187a0af68 | OOB-read / truncation | не подтверждено |
| textkit | `-[NSHTMLReader _addTableCellForElement:]` — `colspan`/`rowspan` только `max(1,·)` | 0x194be613c (0x194be6278, 0x194be62b0) | overflow / OOM | не подтверждено |
| PrinterTool | `ippReadIO` — глубина IPP-коллекций не ограничена | 0x100001720 / 0x100001860 | stack exhaustion / alloc | не подтверждено |
| Barcode | — (`MRCDescriptorDecodePayloadWithOptions` сверяет длину) | 0x2a2de89d8 | — | чисто (обвязка) |
| iWork | — (нет байтов в XPC-сообщении) | 0x100001724 | — | чисто (обвязка) |

Приоритет для следующего шага: (1) `_exitElement:tag:display:depth:startIndex:` 0x194be70a4 —
проверить арифметику сетки таблицы; (2) `IIO_Reader_ICO::createReadPlugin` 0x187a0ae50 / 0x187a0aed0 — проверить,
кэшируется ли каталог одним `getBytes(count*16)`; (3) ветка
`ipp_collection_t` в `0x100001860`.

Не делалось: динамика (fuzz/запуск), аудит TSP/protobuf/snappy в iWork, аудит WebKit-пути
textkit (`loadData:MIMEType:`), резолв имён классов в `_allowedOptionClasses`.
