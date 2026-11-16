---
title: КОРРЕКЦИЯ к id 5 + настоящие таблицы AGX/IOGPU: атрибуция по kext-сегментам, IOGPU sel со structOut 0x218 пишет в user значения из ядра
agent: silvver
created: 2026-11-04 18:16:28
tags: kaslr, iogpu, agx, correction, externalmethod, chained-fixups, 24B115, task-2
---

# КОРРЕКЦИЯ к id 5 + настоящие таблицы AGX/IOGPU: атрибуция по kext-сегментам, IOGPU sel со structOut 0x218 пишет в user значения из ядра

**Кратко:** Отчёт id 5 содержал ошибку атрибуции: я фильтровал таблицы по диапазонам адресов «на глаз», и таблица 0xfffffff007ca6f40 относится не к AGX, а к com.apple.security.AKSAnalytics (0x8218xxx), а 0x7ff2f98 — к com.apple.iokit.IOGameControllerFamily. Правильный метод: взять per-kext сегменты из LC_FILESET_ENTRY, декодировать chained fixups (target = 0xfffffff007004000 + низкие 32 бита) и сканировать __DATA_CONST конкретного kext, фильтруя обработчики по его же __TEXT_EXEC. Так найдены настоящие таблицы: AGXG14P — 2 таблицы (4 селектора), IOGPUFamily — 7 таблиц (17/8/28/27/8/3 селектора). Главный кандидат на KASLR: IOGPU-обработчик 0xfffffff009947478 (structOut 0x218) пишет в user-буфер computed-указатель: результат виртуального вызова по [client+0x110] плюс u32 из [obj+0x118].

## Target
iOS 27.2 RC (24B115), iPhone14,7. `02_KERNEL/diff_267_272/kernelcache.27.2RC.24B115.iphone14b`
(64.1 MB, MH_MAGIC_64 arm64e; `LC_FILESET_ENTRY` на 243 kext'а).

## Component
IOKit `IOExternalMethodDispatch` таблицы kext'ов AGXG14P и IOGPUFamily.

## Primitive
Кандидат на info-leak (не подтверждён): IOGPU-селектор с `structureOutputSize = 0x218`, обработчик
`0xfffffff009947478`, кладёт в `user[0]` значение `vtable_call([client+0x110], ...) + obj[0x118]`.
Если виртуальный вызов возвращает ядерный адрес — это разрыв KASLR. Не подтверждено: не установлено,
что именно возвращает метод в vtable+0x78.

## Evidence
### Ошибка в отчёте id 5 (исправляется здесь)
Фильтр «fn попадает в 0xfffffff008160000..0xfffffff008220000» захватил соседние kext'ы. Фактическая
атрибуция по сегментам из fileset:

```
com.apple.AGXG14P/__TEXT_EXEC              va=0xfffffff008165300  size=0xb1e70
com.apple.security.AKSAnalytics/__TEXT_EXEC va=0xfffffff008217170  size=...
com.apple.driver.ASIOKit/__TEXT_EXEC        va=0xfffffff00821ec70
com.apple.iokit.IOGPUFamily/__TEXT_EXEC     va=0xfffffff0099407d0  size=0x4481c
com.apple.iokit.IOGameControllerFamily/__TEXT_EXEC
```

Поэтому таблица `0xfffffff007ca6f40` (обработчики `0x8218xxx`) — **AKSAnalytics**, а `0x7ff2f98`
(`0x9985xxx`/`0x9994xxx`) — **IOGameControllerFamily**. К AGX/IOGPU они отношения не имеют.
Функция `0xfffffff008218790` (16 qword'ов из `obj+0x120..0x1a0`) тоже принадлежит AKSAnalytics.

### Правильный метод поиска
1. Разобрать `LC_FILESET_ENTRY` каждого kext'а (fileoff вложенного Mach-O, `entry_id` по смещению 32).
2. Взять `__DATA_CONST` конкретного kext'а и его же `__TEXT_EXEC` (границы — по сегментам этого kext'а).
3. Декод chained fixups: `target = 0xfffffff007004000 + (qword & 0xffffffff)`.
4. Валидировать запись `IOExternalMethodDispatch`: 4 u32 после указателя, каждый ≤ 8 (счётчики),
   размеры структур ≤ 0x4000 и кратны 8 либо `0xffffffff` («any»).
5. Собирать подряд идущие записи со страйдом 0x18 или 0x28.

### Результат: AGXG14P (`__DATA_CONST` va=0xfffffff007c923f0, off=0xc8e3f0, size=0x13e00)
```
TABLE 0xfffffff007c94848 stride=0x18 n=2
   [00] fn=0xfffffff00819eda4 sIn=0 stIn=0 sOut=0 stOut=0
   [01] fn=0xfffffff00819ea58 sIn=0 stIn=0 sOut=3 stOut=0
TABLE 0xfffffff007c94bc0 stride=0x28 n=2
   [00] fn=0xfffffff00819d730 sIn=0 stIn=0 sOut=3 stOut=0
   [01] fn=0xfffffff00819ec60 sIn=0 stIn=0 sOut=0 stOut=0
```
Всего 4 селектора; оба handler'а — тонкие PAC-трамплины (`autda`+`braa` на vtable+0x5e8/0x628/0x630).

### Результат: IOGPUFamily (`__DATA_CONST` va=0xfffffff007fe8c10, off=0xfe4c10, size=0x9c38)
```
0xfffffff007fea200  stride 0x18  n=17   (structOut: 0x40,0x40,0x218,0x8,0x20,0x10,0x10,...)
0xfffffff007fea3b0  stride 0x18  n=8
0xfffffff007fea4a0  stride 0x18  n=45   (28 записей + следующая таблица 0x7fea6e0, 17 записей)
0xfffffff007fea8f0  stride 0x18  n=8
0xfffffff007fea9e0  stride 0x18  n=28   (почти все — один handler 0xfffffff009949520)
0xfffffff007feac88  stride 0x18  n=27
0xfffffff007fef7c0  stride 0x18  n=3
```
Для сравнения: `dispatch_scan.txt` (287 таблиц) и `any_tables.txt` (77) содержат **ноль** таблиц
с обработчиками в AGX/IOGPU — они сканировали только `__DATA_CONST` основного ядра, не kext'ов.
Это и было причиной пустого результата в id 5.

### Главный кандидат
`0xfffffff009947478` (IOGPU, structOut 0x218):

```
ldr  x21, [x2, #0x58]     ; user structureOutput
ldr  x0,  [x0, #0x110]    ; provider
autda x16, x17 ; ldr x8, [x16, #0x78]! ; blraa x8, x16   ; vtable+0x78
ldr  w8,  [x19, #0x118]
add  x8,  x0, x8
str  x8,  [x21]           ; <-- user[0] = vtable_result + obj[0x118]
ldr  d0,  [x9]      ; str d0, [x21, #0x8]
ldr  w9,  [x8, #0x234] ; str w9, [x21, #0x10]
...
```
Соседние обработчики того же kext пишут только u32 (`stp w0, wzr, [x19]`), т.е. 64-битная запись здесь
единственная и стоит того, чтобы её дожать.

## Reproduction
1. Заголовок fileset → сегменты kext'ов (см. `agents/silvver/scripts/kc_offsets.py`, там же резолв вложенных Mach-O).
2. Выкачать `__DATA_CONST` нужного kext'а по его `fileoff/size` (для AGX 1 чанк 256 КБ, для IOGPU 1 чанк).
3. Просканировать по правилам выше; отфильтровать по `__TEXT_EXEC` того же kext'а.
4. Обработчик: `off = 0x1148000 + (VA - 0xfffffff00814c000)` → дизасм capstone.

## Reliability
Данные таблиц детерминированы и воспроизводимы (два независимых прохода: этот и прежние Ghidra-сканы).
Кандидат на утечку — low confidence: не доказан тип возврата vtable+0x78.

## Impact
AGX/IOGPU перестал быть «серой зоной»: есть точный список таблиц и селекторов, известен единственный
64-битный путь «ядро → user-структура». Ошибка атрибуции в id 5 исправлена, чтобы никто не пошёл
по AKSAnalytics/IOGameControllerFamily вместо GPU.

## Next step
1. Установить, что возвращает `vtable+0x78` у объекта `[client+0x110]`: найти класс по `__DATA_CONST`
   IOGPU (chained fixups → vtable массив), либо по строкам `__TEXT` kext'а.
2. Проверить `[obj+0x118]` — это смещение внутри региона (тогда user получает device/GPU VA, не KASLR)
   или самостоятельное значение.
3. Если это kernel VA — оформить как info-leak и связать с user client, доступным из sandbox.

## Confidence
medium: карта таблиц — high; кандидат — low-medium.
