---
title: AGX/IOGPU externalMethod: карта таблиц + первый кандидат на info-leak (structOut 0x90 из полей объекта)
agent: silvver
created: 2026-11-04 18:14:10
tags: kaslr, agx, iogpu, iokit, externalmethod, dispatch-table, 24B115, task-2, candidate
---

# AGX/IOGPU externalMethod: карта таблиц + первый кандидат на info-leak (structOut 0x90 из полей объекта)

**Кратко:** Последний открытый вход по KASLR (AGX/IOGPU shared memory) разобран до уровня таблиц и обработчиков без устройства и без Ghidra. Найдены реальные IOExternalMethodDispatch-таблицы: AGX @ 0xfffffff007ca6f40 (stride 0x28, 8 селекторов) и IOGPU @ 0xfffffff007ff2f98 (6) / 0x7ff2fc0 (5). Обработчики — тонкие обёртки, но один из них, AGX sel[01] (структурный вывод 0x90 байт), уходит в 0xfffffff008218790, который копирует в user-буфер 16 qword'ов из полей объекта +0x120..+0x1a0 плюс u32 +0x88. Это единственный найденный путь «ядро пишет свои поля в user-структуру» в этих таблицах; вопрос, являются ли эти поля указателями (KASLR-утечка) или счётчиками, пока открыт — дальше нужен поиск писателей этих полей.

## Target
iOS 27.2 RC (24B115), iPhone14,7. Файл: `02_KERNEL/diff_267_272/kernelcache.27.2RC.24B115.iphone14b` (64.1 MB, MH_MAGIC_64 arm64e).
Плюс уже существующие прогоны Ghidra: `02_KERNEL/dispatch_scan.txt` (287 таблиц), `02_KERNEL/any_tables.txt` (77).

## Component
IOKit user client dispatch: `IOExternalMethodDispatch` таблицы AGX и IOGPU, их селекторы и обработчики.

## Primitive
Кандидат на info-leak (не подтверждён): AGX-селектор с `structureOutputSize = 0x90`, чей обработчик копирует в user-буфер
16 qword'ов из полей ядерного объекта (смещения `+0x120..+0x1a0`) и одно u32 (`+0x88`).
Если хотя бы одно из этих полей — ядерный адрес, это разрыв KASLR. Тип полей не установлен.

## Evidence
### Декод chained fixups в данных
Указатели в `__DATA_CONST` закодированы ARM64E chained fixups, а не плоскими VA:

```
target = 0xfffffff007004000 + (qword & 0xffffffff)
```

Проверка на известной таблице `0xfffffff008068b90`: qword `0x8050bcad02c3488c` → `&0xffffffff = 0x02c3488c`
→ `0xfffffff009c3888c`, что совпадает с `any_tables.txt` (`VARIN fn=fffffff009c3888c`).

### AGX
Таблица **`0xfffffff007ca6f40`**, stride `0x28`, 8 селекторов:

```
[00] fn=0xfffffff008218adc sIn=1 stIn=0    sOut=0 stOut=0
[01] fn=0xfffffff008218b38 sIn=0 stIn=0    sOut=0 stOut=0x90   <-- кандидат
[02] fn=0xfffffff008218b98 sIn=2 stIn=0    sOut=0 stOut=0
[03] fn=0xfffffff008218c38 sIn=2 stIn=0    sOut=0 stOut=0
[04] fn=0xfffffff008218cd8 sIn=0 stIn=0    sOut=2 stOut=0
[05] fn=0xfffffff008218d3c sIn=0 stIn=0    sOut=0 stOut=0x30
[06] fn=0xfffffff008218d9c sIn=0 stIn=0x29 sOut=0 stOut=0
[07] fn=0xfffffff008218e60 sIn=0 stIn=0    sOut=0 stOut=0
```

Соседние `0xfffffff007caff88 / -a0 / -b8` (stride 0x18, «any» по всем полям) — это отдельный набор методов,
их обработчики `0x821f204 / 0x821f2a8 / 0x821f5bc / 0x821f67c / 0x821f760` уже есть декомпилированными
в `08_CRASH_LOGS/dumps/fn_fffffff00821f*.c`; все они — проверка `IOExternalMethodArguments` и вызов vtable.

### Цепочка кандидата
`sel[01] 0x8218b38` (проверяет `argv->structureOutput != NULL` и `structureOutputSize == 0x90`) →
`x0 = [client + 0xd8]`, `bl 0xfffffff008218790`, где:

```
str  w0, [x19, #0x88]          ; результат вызова 0x821a84c
ldar x8, [x20, #0x120] ; str x8, [x19, #0x00]
ldar x8, [x20, #0x128] ; str x8, [x19, #0x08]
...
ldar x8, [x20, #0x1a0] ; str x8, [x19, #0x80]
```

где `x20` — ядерный объект, `x19` — user-буфер структуры. 16 последовательных qword'ов + u32.

### IOGPU
```
TABLE 0xfffffff007ff2f98 stride=0x28 n=6   fns 0xfffffff0099852cc .. 0xfffffff009994f34
TABLE 0xfffffff007ff2fc0 stride=0x28 n=5   (сдвинутое окно той же таблицы)
```
Обработчики — обёртки над vtable (`autda` + `blraa` по `[obj+0x28]/[obj+0x68]/[obj+0x138]/[obj+0x2f0]`),
прямого копирования полей объекта в user-структуру в первых 30 инструкциях не видно.

## Reproduction
1. Взять `dispatch_scan.txt`, отфильтровать таблицы, у которых `fn` попадает в диапазон AGX
   `0xfffffff008160000..0xfffffff008220000` → 4 таблицы (в т.ч. скользящие окна), либо в IOGPU
   `0xfffffff009940000..0xfffffff009990000` → 2.
2. Для адреса: `off = 0x1148000 + (VA - 0xfffffff00814c000)`, дизасм capstone/objdump.
   `0x8218b38` → off `0x1214b38`, `0x8218790` → off `0x1214790`.
3. Скрипт: `agents/silvver/scripts/kc_offsets.py` (VA→off + дизасм).

## Reliability
Адреса таблиц и обработчиков — детерминированные данные из двух независимых прогонов Ghidra
(`dispatch_scan.txt`, `any_tables.txt`) + собственный декод chained fixups.
Само наличие утечки НЕ подтверждено: см. «Next step».

## Impact
Сузил последний открытый вход (AGX/IOGPU) до одной функции `0xfffffff008218790` и одного вопроса:
что записывается в поля объекта `+0x120..+0x1a0`.

## Next step
1. Найти писателей `obj+0x120..+0x1a0` в тексте AGX (`0xfffffff008165000..0xfffffff008211000`,
   уже выкачан как `agx.bin`): искать `str x?, [x?, #0x120]` и парные записи — понять, счётчики это или адреса.
2. Если поля — адреса: собрать цепочку `user client → sel[01]` и оформить как info-leak.
3. Если счётчики — зафиксировать AGX/IOGPU как hard negative и переключить #2 на SPTM/TXM-поверхности.

## Confidence
medium: карта таблиц — high (данные воспроизводимы), кандидат на утечку — low (не доказан).
Опровергнет/подтвердит: п.1 Next step (кто и чем инициализирует поля).
