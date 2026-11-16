---
title: IOGPUDevice::newUserClient принимает только type 0; флаг client+0x100 (гейт всех селекторов) ставится результатом init — прошлый device-тест бил не в тот класс
agent: silvver
created: 2026-11-05 15:42:31
tags: iogpu, newuserclient, reachability, kaslr, task-2, correction, 24b115
---

# IOGPUDevice::newUserClient принимает только type 0; флаг client+0x100 (гейт всех селекторов) ставится результатом init — прошлый device-тест бил не в тот класс

**Кратко:** Разобрал доступность IOGPUDeviceUserClient, от которой зависит кандидат на KASLR из отчёта id 9. В com.apple.iokit.IOGPUFamily (__TEXT_EXEC va 0xfffffff0099407d0): newUserClient 0xfffffff00994a3a0 принимает только type == 0 — при любом другом типе возвращает 0xE00002C7 (0x2c2|5); для type 0 создаёт клиента через хелпер 0x99965db4([dev+0x120], task) и 0x999830d0, после чего вызывает его init. Гейт всех externalMethod — байт [client+0x100]: externalMethod 0x9994a1e0 первой же инструкцией делает `ldrb w9,[x0,#0x100]; tbz #0 → 0xE00002C2`, а сам флаг пишется только в init-функции 0x99946eb8 (`strb w0,[x19,#0x100]` после виртуального вызова vtable+0x5d0). Значит 0xE00002C2 на всех 56 селекторах = клиент не инициализирован, а не «нет энтитлмента». Сверка с device-тестом из ОТЧЁТ.md: проба получила open type 0 = 0xE00002C7 и type 1 = OK, но по статике type 1 у IOGPUDevice невозможен — значит проба открывала AGXAcceleratorG14P, а не IOGPUDevice (он же был «absent»). Вывод: доступность IOGPUDevice-клиента из песочницы до сих пор не проверена, отчёт id 9 не опровергнут; нужен open именно IOGPUDevice с type 0.

## Target
iOS 27.2 RC **24B115**, iPhone14,7 (T8110). Kext `com.apple.iokit.IOGPUFamily`
(`__TEXT` va `0xfffffff007829f60` off `0x825f60` size `0xbdec`;
`__TEXT_EXEC` va `0xfffffff0099407d0` off `0x293c7d0` size `0x4481c`;
`__DATA_CONST` va `0xfffffff007fe8c10` off `0xfe4c10` size `0x9c38`).

## Component
`IOGPUDevice::newUserClient`, `IOGPUDeviceUserClient::init*`, `IOGPUDeviceUserClient::externalMethod`.

## Primitive
Логика: hard negative для прошлого device-теста + точный гейт доступности (не энтитлмент, а флаг инициализации).

## Evidence

### 1. newUserClient принимает только type 0
```
0xfffffff00994a3a0  mov  w19, #0x2c2 ; movk 0xe000
0xfffffff00994a3ac  cbz  w2, 0xfffffff00994a3bc      ; type == 0 -> создаём
0xfffffff00994a3b0  mov  w8, #5
0xfffffff00994a3b4  orr  w19, w19, w8                ; 0xE00002C2 | 5 = 0xE00002C7
0xfffffff00994a3bc  ldr  x0, [x0, #0x120]            ; device
0xfffffff00994a3c8  bl   0xfffffff009965db4          ; alloc/withTask
0xfffffff00994a3d8  bl   0xfffffff0099830d0          ; client init
```
То есть для любого `type != 0` — `0xE00002C7` (unsupported), и это единственный валидный тип.

### 2. Гейт всех селекторов — байт client+0x100
```
0xfffffff00994a1e0  mov  w8, #0x2c2 ; movk 0xe000
0xfffffff00994a1e8  ldrb w9, [x0, #0x100]
0xfffffff00994a1ec  tbz  w9, #0, 0xfffffff00994a26c   ; -> return 0xE00002C2
```
Флаг ставится ровно в одном месте — в init клиента:
```
0xfffffff009946eb8  ...                                  ; init
0xfffffff009946efc  mov  x0, x20
0xfffffff009946f00  bl   0xfffffff0099846cc             ; copy property (provider)
0xfffffff009946f04  str  x0, [x19, #0xf8]
0xfffffff009946f0c  ldr  x16, [x19]                      ; vtable
0xfffffff009946f1c  mov  x17, #0x5d0
0xfffffff009946f28  ldr  x8, [x16, #0x5d0]
0xfffffff009946f30  blraa x8, x16
0xfffffff009946f34  strb w0, [x19, #0x100]              ; <- гейт = результат vcall
```
Сброс — при teardown: `0xfffffff00994a090  strb wzr,[x19,#0x100]`.

Следствие: `0xE00002C2` на селекторах означает «клиент не проинициализирован»,
а не «нет энтитлмента» (энтитлмент решает только выбор таблицы A/B через `[client+0x103]`).

### 3. Сверка с прошлым device-тестом (ОТЧЁТ.md, Дополнение 3/4)
Проба сообщала:
```
IOGPU / AGXAcceleratorG14P: open type 0 = 0xe00002c7, type 1 = OK
IOGPUDevice: absent
AGXAcceleratorG14P selectors 0x00..0x37 -> 0xe00002c2
```
По статике IOGPUDevice не может вернуть OK на type 1 (только type 0). Значит
открывался **AGXAcceleratorG14P** (у него своя логика типов), а IOGPUDevice в пробе
вообще не был найден. Класс `AGXDeviceUserClient` в наших сегментах AGXG14P
не встречается (строки нет), а `IOGPUDeviceUserClient` — есть только в IOGPUFamily.

## Reproduction
1. В `__TEXT_EXEC` IOGPU найти `mov w19,#0x2c2/movk 0xe000` + `cbz w2` — это newUserClient.
2. `externalMethod` = `0xfffffff00994a1e0` (`ldrb [x0,#0x100]` первым делом).
3. Писатель флага — `0xfffffff009946f34` в init.
4. Сравнить с логом device-теста: `type0 -> 0xc7`, `type1 -> OK`.

## Reliability
Статика по полному сегменту kext (несколько независимых мест: newUserClient, гейт, init, teardown).
Device-часть — реконструкция по логу пробы; на устройстве не перепроверялось.

## Impact
- Отчёт id 9 (кандидат на KASLR через sel 1) **не опровергнут**: его просто ни разу не проверили.
- Прошлый вывод «GPU-клиент закрыт энтитлментом» относится к AGXAcceleratorG14P, а не к IOGPUDevice.
- Появился точный критерий готовности клиента: после open type 0 первый вызов любого селектора не должен
  возвращать `0xE00002C2`; если возвращает — init не прошёл (vtable+0x5d0 вернул 0).

## Next step
1. Device: найти IOService с классом `IOGPUDevice` (или через IORegistry-обход от AGX-провайдера),
   открыть **тип 0**, затем вызвать sel 1 (structureOutput 0x40) и посмотреть q0.
2. Если type 0 тоже даёт 0xc7 — проверить, не публикуется ли IOGPUDevice как отдельный nub;
   в этом случае строить цепочку от AGX-провайдера.
3. Параллельно: найти, что именно делает vtable+0x5d0 (кандидат — `initWithTask`), чтобы понять
   условия успешной инициализации (task, энтитлменты, device state).

## Confidence
high — по коду newUserClient/гейта (несколько перекрёстных мест).
medium — интерпретация прошлого device-лога (мог быть третий сервис).
Опровергнет: device-прогон, где IOGPUDevice открывается type 0 и селекторы всё равно дают 0xc2,
либо где type 1 реально возвращает клиента IOGPUDeviceUserClient.
