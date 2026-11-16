# CoreGraphics PDF: две OOB-write уязвимости (patch-diff 27.0 → 27.2)

**Цель:** iPhone 14 (`iPhone14,7`, D27AP, A15/T8110), iOS 27.2 RC (`24B115`).
**Бинарь:** CoreGraphics из dyld shared cache 24B115 (RC IPSW) и 24B119 (release), а также 27.0 (24A5408d) и 26.6 (23G71) для сравнения.
**Класс:** heap out-of-bounds write, контролируемые 64-битные значения, достижимо из PDF, который рендерится любым приложением (CGPDFDocument / PDFKit / превью вложений).

---

## 0. Короткий вывод

Найдены две реальные OOB-write уязвимости в обработке PDF в CoreGraphics:

1. **`CGPDFShadingType5Init` / `_cg_shading_type5_draw`** — размерность `/Function` (`/Range`) не сверяется с числом компонент color space. Функция шадинга пишет `range_dim` doubles в запись вершины фиксированного размера **0x48 байт**. При `range_dim > 5` — переполнение heap-буфера записей треугольников.
2. **`_cmap_convert`** — несоответствие размерности code space в цепочке `/UseCMap` приводит к использованию неинициализированной длины кода; цикл декодирования не продвигается по входу и пишет 8-байтовые записи за пределы массива `malloc(len * 8)`.

Обе дыры **исправлены в 27.2** (и в RC `24B115`, и в release `24B119` — код CoreGraphics там идентичен). Проверка исправлений в RC:

* строки `CG-SEC-187882049` и `CG-SEC-187882136` присутствуют в `dyld_shared_cache_arm64e.01` из RC IPSW;
* функция `_CGPDFShadingType5Init` в 24B115 имеет тот же код, что в 24B119 (245 инструкций, с проверкой), а в 27.0 — 220 инструкций без проверки;
* побайтовый/пофункциональный diff CoreGraphics RC (24B115) vs release (24B119): 11 отличий, все — метаданные ObjC, кода нет.

**Следствие:** на iOS 27.2 RC (24B115) эти уязвимости не эксплуатируются. Они живут на **iOS ≤ 26.6.x и 27.0** (проверено: в 26.6 и 27.0 нет ни `CG-SEC` строк, ни соответствующих проверок). Это актуально для второго устройства в мастерской — iPhone 12 Pro Max на 26.5.2.

---

## 1. Как это найдено

1. Из IPSW `iPhone14,7_27.2_24B119_Restore.ipsw` и RC `iPhone14,7_27.2_24B115_Restore.ipsw` вырезаны SystemOS cryptex (`141-09773-227/223.dmg.aea`, ~2.4 ГБ) по HTTP Range, расшифрованы `ipsw fw aea`, распакованы 7-Zip, из split dyld cache вынут `CoreGraphics` (`dscparse.py`).
2. Локальная таблица символов `dyld_shared_cache_arm64e.symbols` сжата LZBITMAP (decmpfs type 14). Написан декомпрессор на Rust (`zbitmap`), извлечены 12 248 символов CoreGraphics для каждой сборки.
3. Функциональный diff 27.0 vs 27.2 (`capstone` + нормализация инструкций) показал ровно две «security-правки» с новыми строками `CG-SEC-*` в PDF-коде.
4. Обе правки разобраны декомпилятором Ghidra; восстановлен sink и primitives.

---

## 2. Уязвимость №1 — Type 5 shading, OOB write контролируемых doubles

### 2.1. Sink

`_cg_shading_type5_draw` (27.2: `0x183c5ce60`) строит массив записей треугольников с шагом **0x48 (72) байта**:

```c
// декомпиляция, 27.2, фрагмент LAB_183c5d584
lVar17 = colorspace_components;              // из color space
...
puVar14 = (undefined8 *)(triangle_array + index * 0x48);
puVar14[0] = x; puVar14[1] = y;
if (shading->function == 0) {
    for (i = 0; i < lVar17; i++)
        puVar14[i + 4] = vertex_colors[i];
} else {
    local_b8 = vertex_param;                 // 1 входной параметр на вершину
    FUN_183b7ffbc(shading->function, &local_b8, puVar14 + 4);
    // ^ пишет range_dim doubles в puVar14+0x20
}
puVar14[lVar17 + 4] = 1.0;                   // alpha
```

Запись вмещает 9 doubles (`0x48 / 8`):
`x, y, pad, pad, color[0..N-1], alpha`, где цвет начинается с индекса 4, alpha — с индекса `components+4`.
Максимально безопасно: `range_dim <= 5` (индексы 4..8).

При `/Function` с `/Range` на `2*N` чисел функция пишет `N` doubles по адресу `record + 0x20`. При `N >= 6` запись выходит за 72-байтовую запись в соседнюю; для последних вершин — за весь heap-буфер записей.

Переполнение на одну вершину: `(N - 5) * 8` байт. Для `N = 64` — **472 байта** за конец записи, 59 doubles подряд, значения полностью контролируются типом функции (Type 0 sampled или Type 4 PostScript calculator).

### 2.2. Root cause

`CGPDFShadingType5Init` (27.0 `0x183d77bfc`) читает `/Function` через `CGPDFShadingCreateShadingFunction()` и **не сверяет** `function->range_dim` (поле `+0x30`) с числом компонент color space (поле `+0x30` color space). Сравнение появилось только в 27.2:

```c
// 27.2, CGPDFShadingType5Init
uVar3 = colorspace->components;
uVar7 = function->range_dim;
if ((4 < uVar3) || (uVar7 != uVar3)) {
    _pdf_error("CG-SEC-187882049: invalid function for type 5 shading "
               "(range dimension does not match color space).");
    return 0;
}
```

Для сравнения: Type 4 (`CGPDFShadingType4Init`) такую проверку имел и раньше (`"invalid function for type 4 shading"`), Type 5 — нет. Это и есть регрессия, закрытая в 27.2 (CVE-2026-112611 / CVE-2026-112610 класс).

### 2.3. Достижимость

`/Sh1 sh` в content stream → `CGPDFContentStreamImpl::getShading` (0x183f3384c) → `CGPDFShadingCreateWithObject` (0x183eed21c) → таблица типов шадинга → `CGPDFShadingType5Init` → `type5_create_shading` → `CGShading` → `_rips_BltShade` → `_cg_shading_type5_draw`.

Достаточно открыть PDF в любом приложении, которое рендерит страницу (Files/QuickLook/превью вложения, Safari, сторонние вьюеры с `CGContextDrawPDFPage`).

### 2.4. PoC

Генератор: `poc/make_type5_shading.py`.
Готовые файлы: `poc/type5_8.pdf`, `poc/type5_32.pdf`, `poc/type5_64.pdf`.

PDF содержит:
- страницу с `/Shading << /Sh1 5 0 R >>` и content `/Sh1 sh`;
- ShadingType 5, `/ColorSpace /DeviceRGB`, `/BitsPerCoordinate 8`, `/BitsPerComponent 8`, `/VerticesPerRow 2`;
- `/Decode [0 1 0 1 0 1]`, поток из 4 вершин по 3 байта (2x2 lattice);
- `/Function` — Type 0 sampled function с `/Range` из `2*N` чисел и `N` выходов (`N = 64`).

Poppler на этом файле выдаёт ровно ожидаемое:
`GfxGouraudTriangleShading: function with wrong output size` — то есть парсер видит функцию с неверной размерностью выхода. CoreGraphics ≤27.0 эту проверку не делает.

**Ожидаемый эффект на уязвимой сборке:** heap OOB write ~0x1D8 байт за конец массива вершин на последней вершине, значения — 64 double (нули/произвольные). При повторном рендере (200 итераций в харнессе) — порча соседних объектов, падение или повреждение кучи.

### 2.5. Харнесс для проверки на устройстве

Theos-приложение: `app/` (исходники), собранный ad-hoc IPA: `app/PDFProbe.ipa`.
- рендерит `type5_8.pdf`, `type5_32.pdf`, `type5_64.pdf` через `CGPDFDocumentCreateWithURL` + `CGContextDrawPDFPage`;
- затем 200 итераций `type5_64.pdf`;
- пишет лог в UITextView и NSLog; при падении crash log уходит в Analytics Data.

Установка: подписать своим профилем (как KRW27 ранее) и запустить. На 27.2 RC рендер должен пройти без падений (исправлено); на 26.5.2/26.6/27.0 — падение/повреждение кучи.

---

## 3. Уязвимость №2 — CMap `/UseCMap`, OOB write длин кодов

### 3.1. Механизм

`_cmap_convert(cmap, in, len, out_codes, out_lengths)` (27.2: `0x183ed71a4`) декодирует строку PDF в коды/CID. При наличии `/UseCMap` (`cmap+0x20`) и отсутствии совпадения в собственном code space выполняется рекурсия:

```c
bVar10 = *pbVar5;                 // длина кода текущего cmap
if (3 < bVar10) bVar10 = 4;
lVar3 = _cmap_convert(used_cmap, param_2, bVar10, local_70, local_90);
uVar9 = local_90[0];              // <-- длина, «съеденная» рекурсией
if (lVar3 != 1) {                 // 27.2: проверка
    _pdf_log("CG-SEC-187882136: used-cmap codespace-dimension mismatch ...");
    goto identity_fallback;
}
...
*out_codes++   = code;
*out_lengths++ = uVar9;
param_2 += uVar9;  param_3 -= uVar9;
```

Если размерности code space не совпадают (например, внешний CMap с 1-байтовыми кодами и `/UseCMap` на CMap с 2-байтовыми), рекурсия не находит код и возвращает 0, **не записав** `local_90[0]`. В 27.0 и раньше значение `local_90[0]` — неинициализированный стек:

* `uVar9 == 0` → `param_2` не двигается, `param_3` не убывает → бесконечный цикл, каждая итерация пишет в `out_lengths` (8 байт) и `out_codes` (2 байта) со сдвигом → heap OOB write;
* `uVar9` большое → `param_3` underflow, выход за входной буфер, дальнейшие записи в output → OOB read + write.

Вызывающий код (`FUN_183fe61a0`) выделяет массив длин как `malloc(input_len * 8)` и передаёт его в `_cmap_convert`, поэтому выход за границы — это переполнение heap-буфера.

### 3.2. Root cause / фикс

В 27.2 добавлена проверка `lVar3 != 1` и fallback на identity (`CG-SEC-187882136`). В 27.0 (`_cmap_convert` @ `0x183d...`, 255 инструкций) проверки нет (в 27.2 — 268 инструкций).

### 3.3. PoC (схема)

PDF с Type0-шрифтом, у которого `/Encoding` — встроенный CMap-поток:

```
/CIDInit /ProcSet findresource begin
12 dict begin begincmap
/CMapName /A def
/CMapType 1 def
1 begincodespacerange
<00> <ff>
endcodespacerange
1 begincidrange
<00> <ff> 0
endcidrange
endcmap
```
плюс в словаре CMap `/UseCMap 7 0 R`, где объект 7 — CMap с code space `<0000> <ffff>` и своим `cidrange`. Строка в контенте — один байт (`<41> Tj`).
На уязвимой сборке декодирование уходит в рекурсию с 1 байтом против 2-байтового code space → mismatch → неинициализированная длина → OOB write.

Этот PoC пока не валидирован на устройстве (в отличие от Type 5); схема собрана по декомпиляции и требует динамической проверки на 26.x/27.0.

---

## 4. Что проверено в 27.2 (RC) и не дало новой OOB-write

* `Type 4` / `Type 1..3` shading: проверка `range == components` (или `components+1`) в `CGPDFShadingType4Init`, `FUN_183e18cc4`, `_CGShadingCreateAxialInternal`, `_CGShadingCreateRadialInternal`; `components+1 < 6` в draw.
* `Type 6/7` shading: `/Function` читается, но в draw при его наличии функция немедленно возвращает NULL-путь (ветка `cbnz x8, epilogue`), не вычисляется — безопасно.
* JBIG2: проверки `symbol number < numSyms`, overflow-проверки размеров (`0x7fffffff / size`), `JBIG2Bitmap::expand` с проверкой `height < 0x7ffffffe / stride`, `combine` с клиппингом.
* LZW: `code < 0x1000`, `oldCode < LZW_TABLE_SIZE`, sanity-check `freeCode == maxCode + 1`, bounds для chain.
* CCITT fax: запись run'ов ограничена `buf + width*2`; проверки `width/height` при инициализации.
* Predictor (PNG/TIFF), ASCII85/Hex, RunLength, Flate: фиксированные буферы 0x3000/0xF00 с assertion'ами на вход/выход.
* XRef stream: `/W[i] <= 8`, проверка чётности `/Index`, `count < 0x155555555555556`, запись строго `count` записей.
* CMap: длины code space валидируются `_csr_create` (1..4, 0 запрещён), `_check_dimension`.

Type1Scaler (libType1Scaler.dylib) между 27.0 и 27.2 изменился: найдены правки индексации (`uxtw` → `lsl`) и rounding в сканере — вероятно, часть фикса font OOB write (CVE-2026-113950). В 27.2 они уже есть; аудит соседних 22 индексированных записей продолжается как отдельное направление (embedded Type1 fonts в PDF).

---

## 5. Артефакты

| Путь | Что |
|---|---|
| `poc/make_type5_shading.py` | генератор Type 5 PoC PDF (N выходов функции) |
| `poc/type5_8.pdf`, `poc/type5_32.pdf`, `poc/type5_64.pdf` | готовые PoC |
| `app/` | Theos-харнесс PDFProbe |
| `app/PDFProbe.ipa` | собранный ad-hoc IPA (13.5 КБ) |
| `CoreGraphics.26.6`, `CoreGraphics.27.0`, `CoreGraphics.RC115`, `CoreGraphics.27.2` | извлечённые бинари |
| `dump_shading.c`, `dump_filters.c`, `dump_xref.c`, `dump_pdfimage.c` | декомпиляция ключевых подсистем |
| `/tmp/opencode/cg266.syms`, `cg270.syms`, `cgRC.syms`, `cg272.syms` | таблицы символов |

## 6. Рекомендация

* Для **27.2 RC / 24B119** эти две дыры мертвы — нужен новый баг; ближайшие зоны риска: Type1Scaler (embedded Type1 в PDF), PDF-образы с мягкими масками, CFF/Type1 charstring-парсер CoreGraphics.
* Для **26.5.2 / 26.6 / 27.0** (второе устройство) Type 5 PoC применим сразу: собрать `PDFProbe.ipa`, подписать, установить, запустить; ожидается падение/повреждение кучи. Type 5 — самый чистый primitive: контролируемые doubles, фиксированный сдвиг, куча CoreGraphics в процессе-рендерере.
