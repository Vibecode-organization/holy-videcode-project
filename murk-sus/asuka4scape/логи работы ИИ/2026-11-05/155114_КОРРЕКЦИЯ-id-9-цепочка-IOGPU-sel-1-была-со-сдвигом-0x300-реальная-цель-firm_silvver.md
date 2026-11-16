---
title: КОРРЕКЦИЯ id 9: цепочка IOGPU sel 1 была со сдвигом −0x300; реальная цель — firmware-объект IOUAT (IOUnifiedAddressTranslator), а не vtable 0x7c2de60
agent: silvver
created: 2026-11-05 15:51:14
tags: iogpu, agx, iouat, kaslr, correction, sptm, uat, paddr, 24b115, task-2
---

# КОРРЕКЦИЯ id 9: цепочка IOGPU sel 1 была со сдвигом −0x300; реальная цель — firmware-объект IOUAT (IOUnifiedAddressTranslator), а не vtable 0x7c2de60

**Кратко:** Перепроверил цепочку из отчёта id 9 по свежим срезам kernelcache. Нашёл систематическую ошибку: старые дизассемблы AGX шли с базой 0xfffffff008165000, тогда как реальный __TEXT_EXEC AGXG14P начинается с 0xfffffff008165300, поэтому все адреса в цепочке были на 0x300 меньше истинных (0x81667f4→0x8166af8, 0x817832c→0x817862c, 0x8216430→0x8216730). С правильными адресами цепочка такая: 0x81785e4 `bl 0x8216350(dev, fn, 0)` создаёт объект; 0x8178628 `bl 0x8216730(2, dev, obj)`; 0x817862c `str x0,[x19,#0x548]`. Стаб 0x8216730 идёт через GOT 0x7ca5a68 → ядро 0xa9ee074, а это геттер `IOUnifiedAddressTranslator::getFirmwareAddressSpaceHandle` (строки 0x70b9615/0x70b95f3 в com.apple.kernel): проверяет флаг [0xadd7700]==1, иначе паникует «The IOUAT system is not enabled», и возвращает глобальный указатель [0xadd7728]. То есть provider+0x1e8 = firmware-объект IOUAT, и sel 1 копирует первые 0x40 байт его, а не 0x60-байтного объекта с vtable 0x7c2de60 — формула slide = (q0&0xffffffff)-0x07c2de60 неверна. При этом сам лик остаётся кандидатом: firmware IOUAT — OSObject, первый qword должен быть PAC-подписанной vtable, а низкие 32 бита сохраняют смещение. Побочно выяснилось главное: IOUAT — это kernel-клиент SPTM UAT (ioctl SET_CONTEXT_ID / REMOVE_CONTEXT_ID / PREPARE_UNMAP / GET_ROOT_TABLE / GET_PT_ENTRY / TOTAL_PT_MEM / FAULT_EXPECTED и «mapToPhysicalAddress entry 0x%llx»), т.е. именно тот слой, который передаёт paddr в UAT MAP_BEGIN — недостающее звено [1] из отчёта id 10. Плюс teardown обнуляет dev+0x548 (0x8172c08, 0x817967c): вызов sel 1 в этот момент даёт memcpy из NULL — паника (DoS), не примитив.

## Target
iOS 27.2 RC **24B115**, iPhone14,7 (T8110).
Kext `com.apple.AGXG14P` (`__TEXT_EXEC` VA `0xfffffff008165300`, size `0xb1e70`),
`com.apple.iokit.IOGPUFamily` (`__TEXT_EXEC` VA `0xfffffff0099407d0`), `com.apple.kernel`.

## Component
`IOGPUDeviceUserClient` sel 1 → `provider+0x1e8` → `device+0x548` → kernel
`IOUnifiedAddressTranslator` (IOUAT).

## Primitive
Коррекция цепочки + уточнение цели лика: sel 1 отдаёт в user первые 0x40 байт
firmware-объекта IOUAT, а не объекта с vtable `0x7c2de60`.

## Evidence

### 1. Источник сдвига −0x300
Старые дизассемблы AGX строились с базой `0xfffffff008165000`, реальный сегмент —
`0xfffffff008165300` (из `LC_SEGMENT_64` AGX). Отсюда все адреса цепочки в отчёте id 9
занижены на `0x300`:
```
было (id 9)      стало (проверено)
0x81667f4    ->  0x8166af8     ldr x8,[x20,#0x548]; stp x8,xzr,[x19,#0x1e8]
0x817832c    ->  0x817862c     str x0,[x19,#0x548]
0x8216430    ->  0x8216730     стаб, GOT 0x7ca5a68
```
Сам обработчик sel 1 (`0x99947444`) от этого не пострадал — он из IOGPU и проверялся
по другой базе.

### 2. Правильная цепочка
```
0x81785e4  bl 0x8216350            ; x0=dev(x19), x1=PAC'd 0x817b4e0, x2=0 -> объект
0x817861c  mov w0,#2
0x8178620  mov x1,x19
0x8178624  mov x2,x16              ; PAC'd объект
0x8178628  bl 0x8216730
0x817862c  str x0,[x19,#0x548]     ; device+0x548
```
Провайдер (`0x8166af8`): `ldr x8,[x20,#0x548]` → `stp x8,xzr,[x19,#0x1e8]`,
т.е. `provider+0x1e8 := device+0x548`. Те же три инициализатора есть у соседних AGX-классов
(`0x81882e8`, `0x81890d0`).

### 3. Что реально лежит в device+0x548
Стаб `0x8216730` → `adrp/add 0xfffffff007ca5000 + 0xa68` = GOT `0xfffffff007ca5a68`
(`0x80110000039ea074`) → `0xfffffff00a9ee074`:
```
0xa9ee074  adrp x8, 0xadd7000 ; ldr w9,[x8,#0x700] ; cmp w9,#1 ; b.ne panic
0xa9ee088  adrp x8, 0xadd7000 ; ldr x0,[x8,#0x728] ; ret
```
Паника рядом ссылается на строки
`0xfffffff0070b95af  "%s: The IOUAT system is not enabled (status code %d)"`,
`0xfffffff0070b95f3  "IOUnifiedAddressTranslator.cpp"`,
`0xfffffff0070b9615  "getFirmwareAddressSpaceHandle"` — всё в `com.apple.kernel`.
То есть `0xa9ee074` — `IOUnifiedAddressTranslator::getFirmwareAddressSpaceHandle()`,
возвращающий глобальный указатель из `[0xadd7728]`.

### 4. IOUAT — клиент SPTM UAT (это важнее лика)
Строки IOUAT в ядре описывают полный набор операций над UAT:
```
UAT_PPL_IOCTL_SET_CONTEXT_ID      / UAT_PPL_IOCTL_REMOVE_CONTEXT_ID
UAT_PPL_IOCTL_PREPARE_UNMAP       / UAT_PPL_IOCTL_TOTAL_PT_MEM
UAT_PPL_IOCTL_FAULT_EXPECTED      / UAT_PPL_IOCTL_GET_ROOT_TABLE
UAT_PPL_IOCTL_GET_PT_ENTRY
"IOUAT %s:%d: *** mapToPhysicalAddress entry 0x%llx"
"IOUAT %s:%d: *** getPageTablePhysicalBaseAddress entry %u"
"IOUAT %s:%d: *** Setting CTXID for IOUAT object %p to %d"
```
Это и есть kernel-слой, который передаёт paddr в UAT MAP_BEGIN и получает корневые
таблицы/PTE обратно — недостающее звено [1] из отчёта id 10 (SPTM-байпас).
IOGPU хранит у себя именно firmware-IOUAT-объект (`Unable to allocate the firmware IOUAT object`).

### 5. Teardown
`0x8172c08` и `0x817967c` пишут `xzr` в `[x19,#0x548]`. Если sel 1 вызвать в это окно,
обработчик сделает `memcpy(user, NULL, 0x40)` → kernel fault (паника), а не утечка.

## Reproduction
1. Kernelcache 24B115, AGX `__TEXT_EXEC` VA `0x8165300`, off `0x1161300`.
2. Дизасм 0x81785e0..0x8178640; стаб 0x8216730; GOT `0x7ca5a68` (AGX `__DATA_CONST`
   `va 0x7c923f0`, chained fixup: target = `0xfffffff007004000` + low32).
3. Строки IOUAT — kernel `__PRELINK_TEXT` VA `0x70b95..0x70ba4` (в архиве:
   kernelcache 24B115, off = `0x8000 + (VA-0xfffffff00700c000)`).

## Reliability
Статика, три независимых подтверждения (call-site, GOT-резолв, строки+форма геттера).
Класс/владение firmware-объекта IOUAT по первому qword не проверялись — нужен device-дамп.

## Impact
- Отчёт id 9 исправлен: формула slide через vtable `0x7c2de60` **неверна**.
- Лик остаётся кандидатом, но цель — firmware-объект IOUAT; первый qword, вероятно,
  PAC'd vtable (класс неизвестен).
- Найден слой, который отправляет paddr в UAT MAP_BEGIN: IOUAT. Это прямой мост
  к SPTM-байпасу из отчёта id 10 — теперь искать надо не «какой-то pmap», а
  `IOUnifiedAddressTranslator::mapToPhysicalAddress` и его вызывающих.

## Next step
1. Device: вызвать IOGPU sel 1 (out 0x40), взять q0. Матчинг: `(q0 & 0xffffffff) + 0xfffffff007004000`
   проверить по каталогу vtable-кандидатов `__DATA_CONST` (скрипт: скан qword'ов с auth-rebase,
   цель в `0xfffffff00a1cc000..0xfffffff00aa88000`, серии ≥8 — 8683 кандидата).
2. Статика: найти в kernel `__TEXT_EXEC` вызывающих `mapToPhysicalAddress` (строка
   `0x70ba34d`) и проверить, может ли paddr прийти из IOGPU-user-client (shared memory,
   IOMemoryDescriptor с task==NULL).
3. Проверить, кто инициализирует `[0xadd7728]` (класс firmware IOUAT) — от этого зависит
   и формула лика, и набор ioctl-обёрток.

## Confidence
high — адреса, GOT-резолв и строки.
medium — что firmware IOUAT-объект начинается с vtable (типично для OSObject, но не проверено).
Опровергнет: device-дамп sel 1, где q0 не является указателем `0xfffffff0...`;
либо найденный вызов mapToPhysicalAddress с user-controlled paddr (это будет уже не опровержение, а цепочка).
