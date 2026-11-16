# CoreGraphics — полноценный reverse 27.2 (PDF / image / font / color)

Дата: 2026-11-11  
Target: iOS 27.2 (24B115), iPhone14,7 (D27AP, A15/T8110)  
Framework: `/System/Library/Frameworks/CoreGraphics.framework/CoreGraphics`  
Бинарь: `01_REPORTS/pdf/CoreGraphics.27.2.fixed` (Mach-O arm64e, 8.57 МБ, `__TEXT` 0x7bd9f8)

---

## 1. Что уже сделано

Построен Ghidra-проект `01_REPORTS/pdf/gh/cg272` (94 МБ) и снят полный инвентарь:

| Артефакт | Что внутри | Размер |
|---|---|---|
| `gh/cg272_functions.tsv` | **14 294** функции: адрес, размер, имя | 700 КБ |
| `gh/cg272_strings.tsv` | **12 924** строки: адрес, значение | 424 КБ |
| `gh/cg272_symbols.tsv` | **156 870** символов (14 328 Function + 142 542 Label) | 5.1 МБ |
| `gh/cg272_function_strings.tsv` | 2 438 функций, у которых есть строковые ссылки (адрес, размер, имя, строки) | 990 КБ |
| `gh/cg272_top_decomp.txt` | декомпиляция 16 ключевых PDF-функций | 703 КБ |
| `gh/cg272_all_decomp.txt` | **полная декомпиляция всех 14 294 функций** (44.1 МБ, 6 DECOMP FAIL) | 44 МБ |
| `gh/cg272_risk_scan.tsv` | top-500 функций по risk-score (loops/shifts/memcpy) | 41 КБ |
| `gh/cg272_pdf_risk_scan.tsv` | top-300 PDF/font/security функций по risk-score | 42 КБ |

Имена функций — настоящие: Ghidra подтянула C++/ObjC-символы, так что это не безымянный `FUN_*`.

---

## 2. Карта парсеров

По именам и строкам:

| Категория | Функций | Крупнейшие |
|---|---:|---|
| **PDF** | **1 860** | `PDFLinearizer::endDocument` 17 464; `JBIG2Stream::readSegments` 15 468; `_cg_shading_type6_draw` 14 284; `JBIG2Stream::readGenericBitmap` 12 668; `JBIG2Stream::readGenericRefinementRegion` 11 492; `_pdf_xref_create` 9 116 |
| Font | 439 | `PageLayoutFactory::ScannerContext::appendTextLayout` 7 596; `CGGlyphBuilder::create_missing_bitmaps` 4 748; `_PDFContentStreamDrawGlyphs` 4 440 |
| Color | 947 | `RGBAf16_mark_inner` 20 072; `_img_data_lock` 10 104; `CG::DisplayListXMLDeserializer::parseResources` 9 620; `_ripc_DrawShading` 6 744 |
| Image | 696 | `RGBAf16_mark_inner` 20 072; `_CMYK64_image_mark` 18 260; `CIF10_image_mark` 15 940; `_cmyk64_image_mark` 13 956 |
| PS/DisplayList | 1 025 | `DisplayListXMLDeserializer::parseResources` 9 620; `_ripc_GetClipState` 9 192; `_ripc_DrawShading` 6 744 |
| Security | 615 | `_CMYK64_mark_pixelshape` 20 096; `_cg_shading_type6_draw` 14 284; `_PDFDocumentFinalize` 10 164; `_pdf_xref_create` 9 116 |

---

## 3. Топ-16 функций, уже декомпилированных

`gh/cg272_top_decomp.txt`:

| 27.2 VA | Функция | Размер |
|---|---|---:|
| `0x183cf8178` | `JBIG2Stream::readSegments` | 15 468 |
| `0x183cffd34` | `JBIG2Stream::readGenericBitmap` | 12 668 |
| `0x183cfc9f8` | `JBIG2Stream::readGenericRefinementRegion` | 11 492 |
| `0x183f7e4a0` | `_cg_shading_type6_draw` | 14 284 |
| `0x183c5ce60` | `_cg_shading_type5_draw` | 3 004 |
| `0x183bf52cc` | CMap loader (`FUN_183bf52cc`) | 7 540 |
| `0x183caee70` | `_PDFSecurityHandlerCreate` | 3 764 |
| `0x183bcdbf8` | `_pdf_lexer_scan` | 4 908 |
| `0x183bd21f4` | `_pdf_xref_create` | 9 116 |
| `0x183c6b984` | `_CGPDFImageCreate` | 2 220 |
| `0x183c6c4a4` | `_CGPDFImageCreateInline` | 1 988 |
| `0x183bde09c` | `op_gs` (PDF graphics state) | 3 264 |
| `0x183f32e4c` | `CGPDFContentStreamImpl::getPattern` | 2 392 |
| `0x183f323e8` | `CGPDFContentStreamImpl::getXObject` | 2 448 |
| `0x183fe3290` | `_pdf_scanner_read_compound_object` | 1 288 |
| `0x183c4e5d8` | `CGPDFPageCreateWithImage` helper | 1 220 |

---

### 3.1. PDF risk scan (2 178 кандидатов, top-300 в `cg272_pdf_risk_scan.tsv`)

Скоринг: `memcpy/malloc/calloc` + сдвиги + циклы + «risky» строки (invalid/overflow/too large/...).

| score | size | 27.2 VA | функция | mem/mal/cal | shl | loops | risky |
|---:|---:|---|---|---:|---:|---:|---:|
| 457 | 17 464 | `0x183f3ec30` | `PDFLinearizer::endDocument` | 0/0/0 | 59 | 78 | 0 |
| 379 | 14 284 | `0x183f7e4a0` | `_cg_shading_type6_draw` | 0/0/0 | 74 | 102 | 1 |
| 233 | 9 116 | `0x183bd21f4` | `_pdf_xref_create` | 0/0/0 | 25 | 37 | 39 |
| 216 | 12 668 | `0x183cffd34` | `JBIG2Stream::readGenericBitmap` | 0/0/0 | 67 | 35 | 6 |
| 172 | 7 980 | `0x183ca41cc` | `_ccitt_fax_filter_refill` | 0/0/0 | 40 | 34 | 1 |
| 159 | 15 468 | `0x183cf8178` | `JBIG2Stream::readSegments` | 0/0/0 | 14 | 27 | 12 |
| 129 | 9 036 | `0x183e29868` | `PageLayout` ctor | 0/0/0 | 8 | 21 | 11 |
| 128 | 10 164 | `0x183d6f530` | `_PDFDocumentFinalize` | 0/0/0 | 20 | 27 | 6 |
| 116 | 11 492 | `0x183cfc9f8` | `JBIG2Stream::readGenericRefinementRegion` | 0/0/0 | 41 | 3 | 0 |
| 99 | 4 440 | `0x183f739f0` | `_PDFContentStreamDrawGlyphs` | 0/0/0 | 4 | 12 | 0 |
| 78 | 6 744 | `0x183b8165c` | `_ripc_DrawShading` | 0/0/0 | 11 | 4 | 2 |
| 70 | 7 540 | `0x183bf52cc` | CMap loader | 0/0/0 | 5 | 17 | 4 |
| 66 | 3 764 | `0x183caee70` | `_PDFSecurityHandlerCreate` | 0/0/0 | 8 | 10 | 4 |
| 62 | 2 220 | `0x183c6b984` | `_CGPDFImageCreate` | 0/0/0 | 6 | 0 | 27 |
| 62 | 3 004 | `0x183c5ce60` | `_cg_shading_type5_draw` | 0/0/0 | 10 | 14 | 1 |
| 38 | 1 988 | `0x183c6c4a4` | `_CGPDFImageCreateInline` | 0/0/0 | 1 | 0 | 18 |

Полные списки:
- `cg272_pdf_risk_scan.tsv` — 300 PDF/font/security-функций;
- `cg272_risk_scan.tsv` — 500 функций по всему фреймворку.

---

## 4. Что уже известно по 27.2

В 27.2 **исправлены** две PDF OOB-записи, найденные ранее (см. `REPORT_PDF_OOB_27.2_RC.md`):

1. `CGPDFShadingType5Init` / `_cg_shading_type5_draw` — `/Range` функции не сверялся с числом компонент color space; `range_dim > 5` переполнял запись вершины 0x48 байт.
2. `_cmap_convert` — несоответствие размерности code space в `/UseCMap` давало OOB-запись 8-байтовых записей.

На 27.2 эти конкретные баги **не работают**. Но соседние пути (type 4/6 shading, JBIG2, image create, security handler, CMap loader) — не проверены до конца.

---

## 5. Приоритетный план аудита 27.2

1. **JBIG2** — `readSegments`, `readGenericBitmap`, `readGenericRefinementRegion`. Огромные битстрим-парсеры, много сдвигов и арифметики; классический источник OOB.
2. **Shading type 6/4** — `_cg_shading_type6_draw` (14 284) и `_cg_shading_type4_draw` (1 760). Type 5 уже был битым; type 6 — следующий кандидат на такую же ошибку range/comps.
3. **CMap loader** `FUN_183bf52cc` (7 540) — `UseCMap`, вложенные CMap, `invalid CMap: not a name or stream`; рядом с уже исправленным `_cmap_convert`.
4. **PDFSecurityHandlerCreate** (3 764) — парсинг `/Encrypt`, длины ключей, RC4/AES; строки `Invalid combination of encryption options`, `invalid encryption key length`.
5. **PDF image create** — `_CGPDFImageCreate` / inline: `Width`, `Height`, `BitsPerComponent`, `ImageMask`; проверить `width*height*bits` и размеры буферов.
6. **xref/lexer/compound object** — `_pdf_xref_create`, `_pdf_lexer_scan`, `_pdf_scanner_read_compound_object`: рекурсия, `startxref`, `xref` count/offset.
7. **Fonts** — `_load_font`, Type1/CFF (`Length1/Length2`), `CGGlyphBuilder::create_missing_bitmaps`.

---

## 6. Ограничение по 27.3

27.3 beta 1 CoreGraphics пока **не извлечён**: `ipsw extract --dyld --remote` для IPSW 27.3 завис на скачивании dyld cache (нет прогресса, соединение установлено, но данные не идут). 27.2.1 kernel/kext код идентичен 27.2, но userland CoreGraphics в 27.2.1 может отличаться — это отдельная задача.

Когда 27.3 CoreGraphics будет извлечён, делаем function-shape diff 27.2 vs 27.3 по той же схеме, что для кекстов: ищем новые проверки в PDF/JBIG2/shading/image. Это лучший способ найти 1-day на 27.2.

---

## 7. Файлы

```
01_REPORTS/pdf/gh/cg272_functions.tsv
01_REPORTS/pdf/gh/cg272_strings.tsv
01_REPORTS/pdf/gh/cg272_symbols.tsv
01_REPORTS/pdf/gh/cg272_function_strings.tsv
01_REPORTS/pdf/gh/cg272_top_decomp.txt
01_REPORTS/pdf/gh/cg272_all_decomp.txt   (14 294 функции, 44 МБ)
01_REPORTS/pdf/gh/cg272_risk_scan.tsv
01_REPORTS/pdf/gh/cg272_pdf_risk_scan.tsv
01_REPORTS/pdf/gh/cg272.rep              (Ghidra project)
```

Дальше: полная декомпиляция уже идёт; после неё — греп по `memcpy/malloc/шифтам/циклам` и ручной аудит JBIG2 + shading type 6 + CMap.
