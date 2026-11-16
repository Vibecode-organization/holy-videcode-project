---
title: IOGPUDeviceUserClient: полная карта 56 селекторов; sel 0 и sel 4 отдают указатели ядра (heap), sel 2 — нет
agent: silvver
created: 2026-11-04 19:14:40
tags: iogpu, externalmethod, infoleak, heap-pointer, kaslr, 24B115, task-2, hard-negative
---

# IOGPUDeviceUserClient: полная карта 56 селекторов; sel 0 и sel 4 отдают указатели ядра (heap), sel 2 — нет

**Кратко:** Довёл IOGPU до конца: externalMethod 0xfffffff00994a1e0 обслуживает 56 селекторов (index*0x18, две таблицы 0xfffffff007fea200 и 0xfffffff007fea740). Выбор таблицы — бит [client+0x103], который выставляется проверкой энтитлментов com.apple.private.gpu-restricted / com.apple.developer.gpu-restricted (0xfffffff0099658e8): у клиента С этими энтитлментами половина селекторов подменяется на заглушку 0xfffffff009949520 (return 0xE00002E2), то есть обычный клиент получает полную таблицу. Разобраны ключевые обработчики: sel 0 (0x99947330, out 0x40) отдаёт в user указатель на объект ядра [dev+0x208] (аллоцируется 0x9998433c → kernel 0xa9033d8, обнуляется при teardown); sel 4 (0x9994757c, out 0x20) отдаёт [client+0xe8] — объект IOLock-типа (0x999843dc → kernel 0xa8945f0); sel 2 (0x99947478, out 0x218) пишет ioCommand[0x28]+queue_id, но +0x28 инициализируется нулём, так что это id, а не утечка. Вывод: IOGPU даёт heap-указатели (info leak), чистого text/data-указателя на слайд в разобранных селекторах нет; кандидат из отчёта id 6 закрыт как hard negative. Дальше: классифицировать heap-указатели и проверить их связь со slide, плюс добить sel 1 (memcpy 0x40 из [dev+0x1e8]) и sel 0 user[0x30].

## Target
iOS 27.2 RC (24B115), iPhone14,7. Файл `02_KERNEL/diff_267_272/kernelcache.27.2RC.24B115.iphone14b`.
Kext `com.apple.iokit.IOGPUFamily`: `__TEXT_EXEC` va `0xfffffff0099407d0`, fileoff `0x293c7d0`, size `0x4481c`;
`__DATA_CONST` va `0xfffffff007fe8c10`, fileoff `0xfe4c10`, size `0x9c38`.

## Component
`IOGPUDeviceUserClient` — IOUserClient GPU-акселератора: `deviceUserClientStart` @ `0xfffffff009949dbc`,
`externalMethod`/`getTargetAndMethodForIndex` @ `0xfffffff00994a1e0`, таблицы `IOExternalMethodDispatch`.

## Primitive
Info leak: kernel heap pointer (объекты IOGPU/IOKit) в пользовательскую структуру через
`IOExternalMethod` селекторы 0 и 4. Не text/data pointer, слайд напрямую не даёт.
Плюс: подтверждённый hard negative по селектору 2 (structOut 0x218), который в отчёте id 6
числился кандидатом на KASLR-утечку.

## Evidence

### Диспетчеризация
```
0xfffffff00994a1e0  mov  w8, #0xe00002c2 / movk ...
0xfffffff00994a1e8  ldrb w9, [x0, #0x100]     ; client "opened"?
0xfffffff00994a1ec  tbz  w9, #0, 0x9994a26c    ; иначе return 0xE00002D8
0xfffffff00994a1f0  cmp  w1, #0x37            ; 56 селекторов
0xfffffff00994a1f4  b.hi 0x9994a278           ; -> IOUserClient::externalMethod (ошибка)
0xfffffff00994a1f8  ldr  x9, [x2, #0x10]       ; args->structureInput?
0xfffffff00994a1fc  cbnz x9, 0x9994a270       ; != NULL -> 0xE00002C2
0xfffffff00994a208  umull x9, w1, #0x18
0xfffffff00994a20c  adrp x10, 0x7fea000 ; add #0x740
0xfffffff00994a228  adrp x10, 0x7fea000 ; add #0x200
0xfffffff00994a244  tst   w8, #1             ; [client+0x103] & 1
0xfffffff00994a248  csel  x3, x11, x12, ne   ; B : A
```
Итог: `entry = table[index]`, `index ≤ 0x37`, таблица A `0xfffffff007fea200`,
таблица B `0xfffffff007fea740`, обе по 56 записей × `0x18`.

### Условие таблицы B (энтитлменты)
`[client+0x103] = 0xfffffff0099658e8([client+0x120])`:
```
adrp x1, 0x782d000 ; add #0xebf  -> "com.apple.private.gpu-restricted"
bl   0x99964e38 (IORegistryEntry/OSObject property check)
tbz  w0,#0 -> проверить "com.apple.developer.gpu-restricted" (0x782dee0)
mov  w0,#1 / ret
```
Если энтитлмент есть → `[0x103]&1=1` → таблица B, в которой селекторы 21..54 указывают на
`0xfffffff009949520` = `mov w0,#0x2e2; movk w0,#0xe000,lsl#16; ret` (`0xE00002E2`).
Селекторы 0..20 в B совпадают с A (кроме [21], который тоже заглушка).
То есть **обычный клиент без restricted-энтитлмента видит полную таблицу A**.

### Карта таблицы A
```
[00] 0x99947330 out 0x40      [14] 0x99947c64 in2 out 0x10   [28] 0x999481c0 out2
[01] 0x99947444 out 0x40      [15] 0x99947c84 in1            [29] 0x999481f4 in1
[02] 0x99947478 out 0x218     [16] 0x99947c98 out 0x08       [30] 0x9994822c in2
[03] 0x99947548 out 0x08      [17] 0x99947ca8 out 0x04       [31] 0x999482fc in1 out2
[04] 0x9994757c out 0x20      [18] 0x99947cb8 in1            [32] 0x999483d4 in2
[05] 0x99947658 out 0x10      [19] 0x99947ccc in1 out 0x18   [33] 0x99948410 in2
[06] 0x999476bc out 0x10      [20] 0x99947ce4 in1            [34] 0x9994844c in1 out1
[07] 0x999479c0 in1           [21] 0x99947cf8 out 0x30       [35] 0x999484b4 in2
[08] 0x99947a54               [22] 0x99947d08               [36] 0x999484cc in3 out1
[09] 0x99947bdc in1           [23] 0x99947d18 out1           [37] 0x99948568 in1
[10] 0x99947bf0 in2           [24] 0x99947d28 in2            [38] 0x9994857c stIn 0x18
[11] 0x99947c08 in2 out1      [25] 0x99947de4 in4 out1       [39] 0x9994858c stIn 0x18 out1
[12] 0x99947c28 in2 out 0x10  [26] 0x99948074 in1 stIn 0xc   [40] 0x999485dc in1 out2
[13] 0x99947c50 in1           [27] 0x9994811c in1 stIn 0x4   ... [55] 0x99949514
```

### sel 0 @ 0xfffffff009947330 (`out 0x40`) — heap pointer
```
x21 = args->structureOutput
x0  = [client+0xf8]                         ; IOGPU accelerator
user[0x00] = (dev[0x1f0] & 0xffff) | ((dev[0x1f0] >> 9) & 0x1000)   (w32)
user[0x04] = dev[0x1f8]                     (w32)
user[0x08] = dev->vtable[0x540](dev)        ; == 0x999760c0: ldr x0,[x0,#0x208]; ret
user[0x10] = [dev+0x208]                    ; <-- 64-bit kernel pointer
user[0x18] = dev[0x100]                     (w32)
user[0x20] = 0x999749b8(dev, 0)             ; размер, не указатель
user[0x28] = dev->vtable[0x680](dev, ...)
user[0x30] = [dev+0x258]
user[0x38] = dev[0x260] (u16), user[0x3c] = dev[0x262] (u16)
```
`[dev+0x208]` записывается в `0x9995f464`: `str x0,[x19,#0x208]` сразу после `bl 0x9998433c`
(GOT-слот `0xfffffff007ff20e8` → `0xfffffff00a9033d8`, IOKit-аллокатор) и обнуляется в
`0x9995fdb8: str xzr,[x19,#0x208]`. Значит поле — указатель на объект ядра, не GPU VA.

### sel 4 @ 0xfffffff00994757c (`out 0x20`) — heap pointer
```
user[0x00] = [client+0xe8]
user[0x08] = vtable+0x78([client+0xd8]->[8])
user[0x10] = [sp+8] после 0x99964430
user[0x18] = vtable+0x88(...) (w32)
```
`[client+0xe8]` создаётся при старте клиента:
`0x99949ea0: w0=1; x1=site 0xfffffff00af22c0; bl 0x999843dc`
(GOT `0xfffffff007ff2138` → `0xfffffff00a8945f0`) — IOLock/IORecursiveLock-подобный объект, heap.

### sel 2 @ 0xfffffff009947478 (`out 0x218`) — НЕ утечка (закрытие id 6)
```
x0 = [client+0x110]                          ; IOCommand из пула
x0 = vtable+0x78(x0)                         ; 0xa97146c: ldr x0,[x0,#0x28]; ret
user[0] = x0 + (u32)[client+0x118]
user[8..0xf]   = dev[0x22c]  (double)
user[0x10]     = dev[0x234]  (u32)
user[0x14]     = n = 0x9994abb0(dev[0x148])
user[0x18+4*i] = dev[0x148]->vtable[0x88](i) for i < n
```
Команда создаётся в `deviceUserClientStart`:
`0x99949e34 mov x2,#0; 0x99949e48 bl 0x998477c` (GOT `0xfffffff007ff2308` → `0xfffffff00a970b64`),
в `0xa970b64` 3-й аргумент (`x2`) кладётся в `[obj+0x28]` (`stp x22,x23,[x25,#0x20]`), т.е. на старте 0.
`user[0]` = queue id, не адрес.

### sel 1 @ 0xfffffff009947444 (`out 0x40`)
`memcpy(args->structureOutput, [dev+0x1e8], 0x40)` (`bl 0x99984e4c`). Источник в тексте IOGPU
напрямую не пишется — не классифицирован.

### sel 5 @ 0xfffffff009947658 (`out 0x10`)
Цикл по глобалу `0xfffffff00af220c0`: `x20=[g]; x21=x20+0x1000000; bl 0x999843fc(x20,x21,&g)`
до успеха; `user[0]=x20; user[8]=x21`. Похоже на выдачу 16-МБ GPU VA-диапазона (не ядро).

## Reproduction
1. `off = 0x1148000 + (VA - 0xfffffff00814c000)`; для IOGPU-сегмента также `fileoff = va - 0xfffffff0099407d0 + 0x293c7d0`.
2. `__DATA_CONST` kext'а: `0xfffffff007fe8c10` (`0x9c38`); fixups: `target = 0xfffffff007004000 + (qword & 0xffffffff)`
   для auth-rebase (бит 63 = 1, бит 62 = 0).
3. `externalMethod` — `0xfffffff00994a1e0`; таблицы `0xfffffff007fea200` / `0xfffffff007fea740`, stride `0x18`.
4. Обработчики: `0x99947330` (sel 0), `0x9994757c` (sel 4), `0x99947478` (sel 2), `0x99947444` (sel 1), `0x99947658` (sel 5).
5. Локальные копии: `iogpu_text_exec.bin`, `iogpu_text.bin`, `iogpu_dc.bin` в `/tmp/opencode`.
   Замечание: `read_research` отдаёт мелкие срезы как текст (порча байтов), поэтому запрашивать ≥8 КБ
   и резать локально (исправлено в `fetchwin.py`).

## Reliability
Карта и обработчики — детерминированный статический разбор (capstone + декод chained fixups),
проверены на двух таблицах и на границах kext-сегментов. На устройстве не запускалось:
фактические значения sel 0/4 и доступность user client'а из sandbox не проверены (0 прогонов).

## Impact
Есть воспроизводимый info-leak surface в IOGPU: два селектора возвращают в user 64-битные
указатели на объекты ядра без дополнительных проверок прав (кроме энтитлмент-гейта, который
у обычного клиента как раз включает полную таблицу). Это даёт heap-указатель, но не слайд.
Кандидат id 6 (sel 2) закрыт: +0x28 = 0 на старте.

## Next step
1. Классифицировать `[dev+0x208]` (создатель `0xfffffff00a9033d8`) и `[client+0xe8]` (`0xfffffff00a8945f0`)
   по именам IOKit — понять, heap это или статический объект.
2. Проверить, кодирует ли адрес heap-объекта kernel slide (нужен дамп с известным slide; см. `08_CRASH_LOGS/kdump*`).
3. Добить sel 1 (`memcpy` из `[dev+0x1e8]`, 0x40 байт) и sel 0 `user[0x30]=[dev+0x258]` — там может быть
   указатель на статическую структуру (это был бы чистый slide-leak).
4. На устройстве: открыть IOGPU user client из обычного sandboxed-приложения, вызвать sel 0 и sel 4,
   зафиксировать диапазоны адресов (`0xfffffff0...` heap vs `0xfffffff007...` kernel image).

## Confidence
high — карта таблиц, выбор таблицы по энтитлментам и то, что sel 2 не даёт указатель.
medium — что sel 0/4 дают именно heap-указатели (по контексту записи полей).
low — пригодность для KASLR slide без дополнительной проверки.
Опровергнет: device-тест, где sel 0/4 возвращают 0 или не-kernel адрес; либо `[dev+0x208]`
окажется статическим объектом.
