# Статус (05.11) — после остановки суб-агентов

Квота провайдера (`Go usage limit exceeded`) убила всех суб-агентов. Дальше — только руками.
`/home/femboychik/AGENTS.md` пустой (0 строк), новых правил не добавлено.

## Закрыто мной лично после отчётов

- **ICO `IIO_Reader_ICO::getImageCount` `0x187a0af68`** — кандидат AO **опровергнут**:
  читается ровно 6 байт (`w3=6`, `bl 0x18786af5c`, `cmp x8,#6`), count = `ldrb [sp,#0xc]`
  (один байт из этих шести, 0..255), за буфер не читается. OOB нет.
- **`-[NSHTMLReader _addTableCellForElement:]` `0x194be613c`** — дизасм начала: цикл по
  ячейкам, `x25` аккумулирует `getter()` + `getter()` (`0x1980b37f0`/`0x1980af650`),
  записи в кучу в этой части нет. Нужен проход по ветке с `colspan/rowspan`
  (`0x194be70a4`) — не закончен.
- **`nsurlsessiond`** — гейт `hasEntitlementToSpecifyDownloadDestinationURL` `0x10007e57c`
  объявлен, но **не вызывается** (0 call sites); `temporaryDestinationURL` не проверяется
  и приоритетнее в `_destinationURLToUse` `0x10007b120`. Ограничитель — профиль демона:
  `Caches/com.apple.nsurlsessiond`, `UserManagedAssets`, cookies, `Media/Downloads|Purchases`.
  Пересечение «разрешено демону И не принадлежит приложению» — не считано.

## Что осталось живым (по убыванию ценности)

1. `AVAssetDownloadTask` / `temporaryDestinationURL`: посчитать пересечение профиля
   `nsurlsessiond` с чужими путями; проверить, кто открывает файл и от чьего имени.
2. `NSHTMLReader` таблица: дойти до арифметики `colspan/rowspan` и сетки таблицы.
3. `passd` (ZIP+JSON+PKCS#7), `mediaanalysisd` (image data), `maild` (MIME+вложения),
   `quicklook.ThumbnailsAgent` — из карты сервисов, не аудированы.
4. `ImageIOXPCService`: остальные 26 ридеров, кроме ICO.
5. `PrintKit.PrinterTool` `ippReadIO` — глубина IPP-коллекций (stack exhaustion).

## Инструменты, которые работают

- dsc: `coretrust/ct272/dscparse.py` (`SharedCache`, `read_va`, `find_image`).
- Кеш: `__TEXT_EXEC` offset = `va-0xfffffff007004000`; PAC VA = `0xfffffff007004000+(q&0x0FFFFFFF)`.
- capstone: `adrp`/`bl`/`b` — ЗНАКОВЫЕ, маскировать `& 0xFFFFFFFFFFFFFFFF`.
- ObjC-методлисты: относительные IMP-оффсеты со сдвигом +8.

## HTML таблица — цепочка (05.11, руками)

```
0x194be629c  attr "colSpan"  0x1f641749c
0x194be62a8  проверка атрибута
0x194be62b0  значение (intValue)
0x194be62b8  cmp w0,#1
0x194be62bc  csinc w27,w0,wzr,gt      ; w27 = max(1, значение), верха НЕТ
0x194be62e8  bl 0x1980b0c80           ; это НЕ функция, а ObjC-транк селектора
             sel 0x1f681e96c = "initWithTable:startingRow:rowSpan:startingColumn:columnSpan:"
0x194be62dc  x4 = w26 (rowSpan), x5 = x25 (row), x6 = w27 (columnSpan)
```
Атрибут `rowSpan` = 0x1f64172e0, обрабатывается тем же `csinc`.
Значит неограниченные `rowSpan`/`columnSpan` из HTML попадают в `NSTextTableBlock`
и хранятся там; арифметика — позже, в раскладке `NSTextTable`/`NSLayoutManager`.

Селектор `columnSpan` в `__objc_methname` UIFoundation: `0x1f6417e3b`
(файл `dyld_shared_cache_arm64e.26.dyldreadonly`, off 0x48c7e3b).
Следующий шаг: selref-слоты закодированы chained-fixup (`DYLD_CHAINED_PTR_64`),
сырой скан по низу 32 бит пустой — декодировать фиксапы, взять слоты, от них
`adrp+ldr` → транки `objc_msgSend` → `bl`-потребители. Это даст код раскладки,
где проверяется `rowSpan × columnSpan`.
