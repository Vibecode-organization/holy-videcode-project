## XPC парсеры (subagent AO) — iOS 27.2 / 24B115

- [x] Вытащил 5 бинарей из `out272_clean/141-10327-211.dmg` + Info.plist + entitlements в `ent/`:
      ImageIOXPCService 56 288, nsattributedstringagent 75 776, BarcodeParsingService 74 640,
      PrinterTool 912 384, iWorkFileFormat 2 542 352 (все arm64e, PIE).
- [x] Собрал тулинг: `tools/disasm.py` (capstone + резолв `__auth_stubs`/`__objc_stubs`/chained fixups),
      `tools/macho_objc.py` (method list → IMP), `tools/stubs.py`, `tools/audit_allocs.py`.
      Попутно: относительные method-list'ы в arm64e — `imp = entry + 8 + imp_off`.
- [x] ImageIO: шим `_main`→`_xpc_main`→`_IIOProcessEvent` (ImageIO **0x187a76190**), 8 ID
      (`iio_xpc_message_id`): IDENTIFY/IMAGECOUNT/SOURCEPROPERTIES/INITIMAGE/DEBUG/DECODE_IMAGE/WAKEUP,
      клиент шлёт сами байты (`iio_xpc_src_data`) → поверхность = 374 `IIO_Reader_*`.
      `_IIOXPCDecodeCGImageMetadataTag` 0x187ab2d54 — глубина 1, рекурсии нет (чисто).
      `TIFFReadDirEntryDataAndRealloc` 0x1878cc568 — реаллокация с проверкой (чисто).
- [x] textkit: `readFromData:orFileURL:options:extensionTokens:withReply:` IMP 0x100001834;
      whitelist из `_allowedOptionClasses` (UIFoundation 0x194b97cf4, 5 классов) и
      `_allowedTokensClasses` (0x194b97dcc, 2 класса); dlsym `_NSReadAttributedStringFromURLOrDataAgent`;
      бэкенды — `__NSReadAttributedStringFromURLOrData` 0x194b347fc → `initWithData:` 0x194b34700
      → NSHTMLReader/NSRTFReader. RTF-глубина ограничена `maximumNestedGroups` 0x194bdc678.
- [x] Кандидат textkit: `-[NSHTMLReader _addTableCellForElement:]` 0x194be613c —
      `colspan`/`rowspan` клампятся только `max(1,·)` (0x194be6278 / 0x194be62b0), верхней границы нет.
- [x] Barcode: 4 селектора; App Clip → Quagga `MRCDescriptorDecodePayloadWithOptions` 0x2a2de89d8,
      длина сверяется с ожидаемой (0x2a2de8b00) до декода; payload в BCS хранится сырым.
- [x] PrinterTool: IPP-стек (`ipp_t`, `ipp_collection_t`), `ippReadIO` 0x100001720 + машина
      0x100001860 (кадр 0x460), zlib-компрессор 0x100003504; кандидат — глубина коллекций.
- [x] iWork: единственный XPC-метод `prepareFileForUploadingAtURL:...` 0x100001724; байтов в
      сообщении нет, парсинг TSP/protobuf/snappy по URL.
- [x] `REPORT.md` записан (таблица, дизасм 20–40 инстр., вердикты), `CHAT_дипсики.md` — запись AO.
      Динамики не было: все кандидаты помечены «не подтверждено». `sbx_build` и IPA не трогал.
