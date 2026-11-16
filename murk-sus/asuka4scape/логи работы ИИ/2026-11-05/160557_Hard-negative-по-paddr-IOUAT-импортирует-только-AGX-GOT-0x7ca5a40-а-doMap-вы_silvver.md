---
title: Hard-negative по paddr: IOUAT импортирует только AGX (GOT 0x7ca5a40), а doMap вызывает только AGXSecureGart; у IOGPU ссылок на IOUAT нет
agent: silvver
created: 2026-11-05 16:05:57
tags: iouat, sptm, uat, paddr, agx, iogpu, secure-gart, hard-negative, 24b115, task-4
---

# Hard-negative по paddr: IOUAT импортирует только AGX (GOT 0x7ca5a40), а doMap вызывает только AGXSecureGart; у IOGPU ссылок на IOUAT нет

**Кратко:** Проверил, кто вообще может дотянуться до IOUAT в 24B115. Скан полного __DATA_CONST кернелкеша (0xfffffff007bb8000, 0x548000 байт, все kext-секции внутри) по chained fixup'ам на функции IOUAT даёт ровно один импортёр — AGX: 0x7ca5a40 retain, 0x7ca5a48, 0x7ca5a50 setClientContextID, 0x7ca5a58 removeClientContextID, 0x7ca5a60 make, 0x7ca5a68 getFirmwareAddressSpaceHandle, 0x7ca5a70 doMap, 0x7ca5a78 doUnmap, 0x7ca5a80 getMode. У com.apple.iokit.IOGPUFamily (__DATA_CONST 0x7fe8c10..0x7ff2850) — ноль ссылок. Внутри AGX все вызовы doMap/doUnmap идут из AGXSecureGart: call sites 0x81fcb78/0x81fccb4/0x81fcdb0/0x81fce60 в функции 0x81fc968 = AGXSecureGart::mapInThisGart(AGXSecureMemoryMap*, AGXPageTableEntryFlags) (строка 0x712260b) и 0x81fde40 в 0x81fdc28 (unmap), плюс 0x81fd5b8/0x81fd620 set/remove CTXID и 0x81fdf54 (init класса, там же make и getFirmwareAddressSpaceHandle). Secure GART — это secure/protected-content MMU (AGXSecureMonitorG14, secure unmap timeout), а doMap сам paddr не принимает: он берёт физические сегменты из IOMemoryDescriptor (отчёт id 16). Отсюда вывод: путь «userland -> произвольный paddr -> SPTM UAT MAP_BEGIN» через IOUAT в этой сборке не просматривается; IOUAT — не универсальный мост, а приватный API AGX secure GART. Осталось проверить только kernel-internal прямые bl на doMap/mapToPhysicalAddress (нужен полный скан kernel __TEXT_EXEC, качаю; локальная копия была обрезана на 0x980000).

## Target
iOS 27.2 RC **24B115**, iPhone14,7 / T8110. `com.apple.kernel` (IOUAT),
`com.apple.AGXG14P`, `com.apple.iokit.IOGPUFamily`.

## Component
Импортёры/вызывающие `IOUnifiedAddressTranslator` (IOUAT):
`make`, `getFirmwareAddressSpaceHandle`, `set/removeClientContextID`, `doMap`,
`doUnmap`, `getMode`.

## Primitive
Hard negative: user->kernel путь к UAT MAP_BEGIN через IOUAT не найден;
IOUAT — приватный API AGX secure GART с дескрипторным paddr.

## Evidence

### 1. Полный скан импортов (chained fixups)
`__DATA_CONST` кернелкеша: `0xfffffff007bb8000`, size `0x548000` (внутри лежат
`__DATA_CONST` всех kext'ов). Fixup'ы на IOUAT есть только в диапазоне AGX
(`0x7c923f0..0x7ca61f0`):
```
0xfffffff007ca5a40 -> 0xfffffff00a9ed1e4  retain
0xfffffff007ca5a48 -> 0xfffffff00a9eec08
0xfffffff007ca5a50 -> 0xfffffff00a9ee0d0  setClientContextID
0xfffffff007ca5a58 -> 0xfffffff00a9ee210  removeClientContextID
0xfffffff007ca5a60 -> 0xfffffff00a9ec60c  make
0xfffffff007ca5a68 -> 0xfffffff00a9ee074  getFirmwareAddressSpaceHandle
0xfffffff007ca5a70 -> 0xfffffff00a9ee318  doMap
0xfffffff007ca5a78 -> 0xfffffff00a9ee854  doUnmap
0xfffffff007ca5a80 -> 0xfffffff00a9ee018  getMode
```
`IOGPUFamily.__DATA_CONST` = `0x7fe8c10..0x7ff2850` — **0** ссылок на IOUAT.
Других импортёров нет.

### 2. Вызывающие doMap внутри AGX
GOT-стаб `0xfffffff008216740` (`adrp 0x7ca5000; add #0xa70; ldr; braa`).
```
call sites: 0x81fcb78 0x81fccb4 0x81fcdb0 0x81fce60   -> функция 0x81fc968
            0x81fde40                                  -> функция 0x81fdc28
```
`0x81fc968` = `AGXSecureGart::mapInThisGart(AGXSecureMemoryMap *, AGXPageTableEntryFlags)`
— строка `0xfffffff00712260b`; `0x81fdc28` — unmap-аналог
(`unmapFromThisGart`, строка `0x712269a`).
`0x81fdf54` содержит `make` (0x81fe2a4) и `getFirmwareAddressSpaceHandle`
(0x81fe1a0) — инициализация класса; CTXID — 0x81fd5b8/0x81fd620.
Vtable класса: `0x7c98ec0 -> 0x81fc6d0` (map), `0x7c98df8 -> 0x81fdc28` (unmap),
`0x7c98e50 -> 0x81fd548` (init).

### 3. Почему это не даёт произвольный paddr
- `doMap(this, backingDescriptor, virt, length, options)` проверяет только
  `descriptor != NULL` и 16K-выравнивание; физические адреса берёт из
  сегментов дескриптора (`[desc vtable+0x90]`, опции 0x1000001/0x1000000),
  затем отдаёт массив {va,pa,len,0} в PPL (отчёт id 16).
- AGXSecureGart — secure/protected-content MMU: строки
  `AGXSecureGart::unmap Timed out waiting for FW to process secure unmap`,
  `AGXSecureMonitorG14`, `SecureGart` в secure-логике; secure-память
  выделяется ядром, PA не выбирается пользователем.

## Reproduction
1. Kernelcache 24B115, разобрать `LC_FILESET_ENTRY` (cmd `0x80000035`):
   entry_id_offset — поле +0x18, строка по `off+eidoff`.
   AGX: `__TEXT_EXEC` 0x8165300, `__DATA_CONST` 0x7c923f0 (0x13e00).
   IOGPU: `__TEXT_EXEC` 0x99407d0, `__DATA_CONST` 0x7fe8c10 (0x9c38).
2. Скан `__DATA_CONST` `0x7bb8000+0x548000` по qword'ам с auth-rebase:
   `target = 0xfffffff007004000 + (q & 0xffffffff)`.
3. AGX: стаб `0x8216740`, call sites — обратный скан `bl` по `__TEXT_EXEC`.

## Reliability
Импорты — точный байтовый скан полного сегмента (не выборка). Call sites —
полный скан AGX `__TEXT_EXEC` (0xb1e70). Семантика secure GART — по строкам
и расположению (vtable), не по символам.

## Impact
- Закрывает направление «IOUAT как универсальный мост userland -> SPTM UAT MAP_BEGIN»:
  у IOUAT один клиент — AGX secure GART, paddr дескрипторный.
- Экономит время: искать дыру в UAT через IOGPU/обычный AGX-клиент бессмысленно.
- Остаётся теоретический вектор: подменить не paddr, а firmware VA в doMap
  (маппинг своей памяти поверх прошивочных адресов) — но это требует
  контроля VA в AGXSecureMemoryMap (secure mode), отдельная задача.

## Next step
1. Досканировать kernel `__TEXT_EXEC` на прямые `bl` к `0xa9ee318` / `0xa9ec94c`
   (полный файл качается; локальная копия была обрезана нулями после 0x980000).
2. Если kernel-internal вызовов нет — зафиксировать hard negative окончательно.
3. Проверить AGXSecureMemoryMap: кто создаёт (secure surface / IOSurface) и
   контролирует ли пользователь firmware VA.

## Confidence
high — импортёры и call sites (полные байтовые сканы).
medium — что AGXSecureGart недостижим без secure-режима/entitlement (по строкам
и архитектуре, device-проверки нет).
Опровергнет: найденный kext/framework с fixup'ом на IOUAT вне AGX, либо
kernel-путь, вызывающий doMap с дескриптором над пользовательским PA.
