# progress — JPEG / IOSurfaceAccelerator user client (27.2 24B115)

Статус: готово, `REPORT.md`, TSV рядом.

- [x] Инфраструктура: `kc.py` (flat-образ), `xm.py` (быстрый adrp/add-xref, disasm, PAC, bl-xref), `klass.py` (метаклассы + привязка vtable).
- [x] `AppleJPEGDriverUserClient` — в `com.apple.driver.AppleJPEGDriver`: gMetaClass `0xae4b740`, sizeof `0x110`, vptr `0x7e28d50`.
- [x] `IOSurfaceAcceleratorClient` — **не** в IOSurface.kext, а в `com.apple.driver.AppleM2ScalerCSCDriver`: gMetaClass `0xae6eb98`, sizeof `0x180`, vptr `0x7e3b0d8`. Рядом 241 метакласс (Iosa*/AppleM2ScalerCSCHal*).
- [x] Привязка vtable: слот `+0x48` (getMetaClass) возвращает свой gMetaClass — единственный надёжный способ на этом образе, т.к. gMetaClass в файле нулевой (заполняется в рантайме).
- [x] JPEG: легаси-слот `vptr+0x540` = panic (`wrong externalMethod for IOUserClient2022`, IOUserClient.cpp:0x19e4); рабочий вход `vptr+0x5d0` = `0x8c8fc30` → таблица `0x7e293c0`, 10 записей, stride 0x28.
- [x] Общий валидатор `0xa9b0888` (через трамплин `0x8ca9458`, GOT `0x7e2cff0`): точное сравнение sIn/strIn/sOut/strOut, для дескриптора берётся `getLength()` (`vtable+0xb0`). Поля таблицы: fn@0, sIn@8, strIn@0xc, sOut@0x10, strOut@0x14, flags@0x18, async_fn@0x20.
- [x] JPEG селекторы: 1/3 (0x58), 4/5 (0x1000), 6/7 (0xda0, flags=1), 8 (u32), 9 — тонкие переходники в AppleJPEGDriver (`0x8c85520`, `0x8c867c0`, `0x8c86bd4`, `0x8c86024`, `0x8c876d8`, `0x8c87038`).
- [x] JPEG sel 8: user u32 → `0x8c832d4` → `driver->vt[+0xe8]`, лямбда `0x8c83168` — адресация через `OSBoundedPtr` с проверкой переноса (`adds`/`cset hs`) и границ. Защищено.
- [x] JPEG clientClose `0x8c8f9e4` = `driver->clientClosedGated(this)`, члены не рвутся. Dtor `0x8c8f208` = OSObject + operator delete(0x110), без release членов.
- [x] SURF: `vptr+0x540` = общий `0xa9a18bc`; `vptr+0x5d0` = 0; `vptr+0x5b0` = `0x8d13c38` → таблица `0x7e3b738`, 12 записей, stride 0x30, fn по +0x08 (первый qword нулевой).
- [x] SURF обработчики: точные размеры 0x1b0/0xfa8/8/0x10/0x18, гейт `this+0x164`, sel 7 — гейт `this+0x160` и lookup `0x8e00070(type 3)` по user-u64, sel 10 idx<4, sel 11 clamp 0x298.
- [x] SURF clientClose `0x8d13c78`: флаг `+0x138=1`, callback `[this+0x100]->vt+0x540`, дренаж по `ldar` `+0xdc`/`+0xe0`. Хвост не дочитан.
- [x] `site.<Class>` рядом с именами — kasan type-site, НЕ sandbox-гейт (5062 таких строк). Энтайтлмент-строк для классов нет.
- [x] TSV: `jpeg_selectors.tsv`, `surfacc_selectors.tsv`.
- [x] `REPORT.md` + запись `## JPEG/Accelerator (subagent R)` в `CHAT_дипсики.md`.
- [ ] TODO: внутренние границы парсеров 0x1000/0xda0, семантика `0x8e00070` и `0x8d56a18`, достижимость panic-слота.
