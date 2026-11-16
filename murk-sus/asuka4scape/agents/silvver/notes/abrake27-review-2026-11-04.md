# Разбор ABrake27 / AzozzALFiras/iOS-Research — 2026-11-04 (silvver)

Источник: локальная копия `/run/media/ivan/New Volume/My Projects/ABrake27`
(= https://github.com/AzozzALFiras/iOS-Research, публичная версия структурирована иначе:
`27.0.1/`, `27.2/`, `diffs/`, `methodology/`, `common/`).

## Что это

Личный проект владельца: iOS 27.0.1 (24A446) vs 27.2 beta (24B5089g), iPhone14,5 (A15),
kernelcache `MH_FILESET` arm64e. 31 сессия, всё статикой с Linux (CachyOS, Ghidra 12,
без Mac/Xcode). Устройство продано — проект на паузе, динамики нет.

Ветки: AMFI dev-mode через stock lockdown (подтверждено на железе), карта
`AppleSEPUserClient` (19 таблиц / 124 селектора), diff-кампания, флагман — ImageIO
ASTC/DDS + цепочка доставки через IAKC-контейнер в `mediaanalysisd`.

## Прямо полезное нам

### 1. Linux-сборка IPA (clang + ld64.lld + ldid)
`poc/build_ipa.sh`. Проверенный на практике путь: два шага на архитектуру (clang -c →
ld64.lld), обход «clang съедает -arch/-platform_version», arm64e → arm64 fallback.
Для нас это снимает вопрос «как собрать kaslr_probe_v2.m без Xcode» на хосте с Linux.
Ограничение: у нас Objective-C + UIKit, у них C + IOKit; нужен clang с ObjC-runtime
и SDK с UIKit (theos/sdks подходит).

### 2. Готовый Mach-O/arm64e инструментарий
- `tools/macho_tool.py` — stdlib-парсер (сегменты, va↔fileoff) + свой AArch64-декодер,
  `sign_ext`, bounded linear disasm. Известный баг: строка операнда adrp битая (`0x0x..`).
- `tools/dump_vm_upl.py`, `dump_callees.py` — дамперы функций/каллеев.
- `tools/ghidra_find_userclients.py`, `ghidra_find_external_methods.py` — поиск
  IOUserClient и их externalMethod-таблиц. Это ровно то, чего нам не хватает для
  `exclaves_ctl` (trap 88) / MIG 866900 / AGX externalMethod.
- `tools/ghidra_resolve_vtable.py` — резолв dispatch-таблиц, авто-детект страйда
  (0x18 IOExternalMethodDispatch vs 0x28 Dispatch2), PAC-strip.

### 3. Методология, которая закрывает наш пробел по #1
Из HANDOFF (сессии 17–21), проверено на практике:
- chained-fixup walk: ARM64E 8-байтный слот, `next=(q>>51)&0x7ff` (шаг ×4),
  `auth` bit63, `bind` bit62; для kernelcache `target=q&0xffffffff` → `VA=base+target`.
- **Ghidra сам резолвит chained fixups** — не надо повторно прибавлять базу
  (их грабли: «double counts»).
- «one table vs 19 tables» trap: серии null-слотов выглядят как границы таблиц; проверять
  по `selector*0x18+base` и `cmp #bound`, а не по дыркам.
- **bl-scan + reverse bl-scan**: собрать callee→callers, чтобы решить scope
  (если все вызывающие за гейтом — sink вне досягаемости). Это же нужно для #1:
  найти потребителей `columnSpan`/`rowSpan` и доказать достижимость из NSHTMLReader.
- Имена без символов: `adrp+add` в `__PRETTY_FUNCTION__`-кластер; не идти по общим
  хвостовым переходам (схлопывает селекторы в одно имя).

### 4. Перекрёстное подтверждение нашего дедупа
Их `27.2/README.md`: 27.2 = **24B119**. У нас доказано 24B115 ≡ 24B119 (933 B diff,
0 в кодовых сегментах). То есть их baseline и наш RC — одна и та же сборка по коду.

### 5. Подсказка по 27.2-специфике
Их открытый чек-лист по 27.2: «Kernelcache UAF/type-confusion CVEs beyond
IOSurface/IOHID», «27.2 = ~17 kernel CVE, ~11 ImageIO, Model I/O 7». Совпадает с
нашим полем (IOSurface уже закрыт статикой). Стоит свериться с их diff-каталогом
при следующем заходе в kernelcache-диффы.

## Не полезное / осторожно

- KASLR в проекте не занимались вообще (grep по всему дереву — ноль). Прямого ответа
  по #2 там нет.
- Устройство — iPhone14,5 (iPhone 13). У нас iPhone 14 (iPhone14,7). Kernelcache
  device-specific, артефакты не взаимозаменяемы.
- Их сборка — `MH_FILESET` kernelcache; наш UIFoundation — образ из userland DSC.
  Формат fixups общий (ARM64E), но база/оффсеты другие.
- Чужие findings (ASTC/IAKC, CVE-2026-112706, race framework) — не наши; не
  перепубликовать, только как методика и как prior art.
- Проект на паузе, динамики нет; рассчитывать на их прогоны нельзя.

## Что предлагаю забрать в хаб

1. `tools/macho_tool.py` как эталон для сверки моего `scripts/uif_selref_scan.py`
   (fixup-декодер у них проверен на реальном kernelcache).
2. `ghidra_find_external_methods.py` + `ghidra_resolve_vtable.py` — на хосте, против
   `exclaves_ctl` / MIG 866900 / AGX.
3. Правило «bl-scan + reverse bl-scan для scope» внести в наш шаблон отчёта рядом
   с closure table.
4. `build_ipa.sh` как рецепт сборки probe под iOS на Linux.
