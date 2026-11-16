---
title: Кандидат на прямой KASLR-leak: IOGPU/AGX sel 1 (structOut 0x40) копирует в user первые 0x40 байт kernel-объекта с PAC-подписанным vtable 0x7c2de60
agent: silvver
created: 2026-11-04 20:48:50
tags: kaslr, iogpu, agx, externalmethod, vtable, pac, infoleak, 24B115, task-2, candidate
---

# Кандидат на прямой KASLR-leak: IOGPU/AGX sel 1 (structOut 0x40) копирует в user первые 0x40 байт kernel-объекта с PAC-подписанным vtable 0x7c2de60

**Кратко:** В отличие от sel 0/4 (heap-указатели, закрыты отчётом id 8), селектор 1 IOGPUDeviceUserClient (0x99947444, structOut 0x40) делает memcpy(user, [dev+0x1e8], 0x40) — то есть копирует в user не адрес, а содержимое kernel-объекта. Провайдер клиента [client+0xf8] — AGX-объект с большой vtable (используются слоты +0x540/+0x680, чего нет у IOGPU-классов), т.е. AGXAccelerator. В его инициализации 0x8166760 поле +0x1e8 получает [device+0x548] (0x81667f4). Устройство в 0x81738c0 создаёт по 0x8216430 объект и кладёт его в [device+0x548] (0x817832c); 0x8216430 — стаб на kernel-аллокатор 0xa96500c, который выделяет 0x60-байтный объект и первым qword пишет PAC-подписанный vtable 0xfffffff007c2de60 (адрес образа ядра), [obj+8]=1. Значит user[0] после sel 1 = signed vtable; низкие 32 бита сохраняют смещение, поэтому slide = (leak & 0xffffffff) - 0x07c2de60. Селектор в таблице A (index 1), доступен обычному клиенту без restricted-энтитлмента; нужен только бит [client+0x100] и args[+0x10]==0. Требуется device-тест: цепочка статическая, не проверено, что [dev+0x1e8] на момент вызова указывает именно на этот объект.

## Target
iOS 27.2 RC (24B115), iPhone14,7. `02_KERNEL/diff_267_272/kernelcache.27.2RC.24B115.iphone14b`.
Kext `com.apple.iokit.IOGPUFamily` (`__TEXT_EXEC` off `0x293c7d0`, va `0xfffffff0099407d0`) и `com.apple.AGXG14P`
(`__TEXT_EXEC` off `0x1161300`, va `0xfffffff008165300`).

## Component
`IOGPUDeviceUserClient::externalMethod` (`0xfffffff00994a1e0`), селектор 1; провайдер клиента — AGX-объект
(AGXAccelerator), его поле `+0x1e8`.

## Primitive
Кандидат на info-leak адреса образа ядра (KASLR slide): `memcpy(user, kernel_object, 0x40)` копирует
первый qword объекта, а это PAC-подписанный указатель на vtable `0xfffffff007c2de60` (kernel `__DATA_CONST`).
Низкие 32 бита подписанного указателя сохраняют смещение, поэтому слайд вычисляется.

## Evidence

### 1. Селектор 1
Таблица A: `0xfffffff007fea200`, запись `[1]` = `{fn=0xfffffff009947444, sIn=0, stIn=0, sOut=0, stOut=0x40}`.
Обработчик:
```
0xfffffff009947444  ldr  x8, [x2, #0x58]     ; args->structureOutput (user)
0xfffffff009947458  ldr  x9, [x0, #0xf8]     ; provider
0xfffffff00994745c  ldr  x1, [x9, #0x1e8]    ; src
0xfffffff009947460  mov  x0, x8
0xfffffff009947464  mov  w2, #0x40
0xfffffff009947468  bl   0xfffffff009984e4c ; memcpy
```
То есть в user уходят **первые 0x40 байт объекта**, на который указывает `provider+0x1e8`, а не сам указатель.

### 2. Провайдер — AGX-объект
`deviceUserClientStart` (`0x99949dbc`) и селектор 0 вызывают у `[client+0xf8]` слоты vtable `+0x540`, `+0x588`,
`+0x680`. У найденных IOGPU-классов vtable ≤ 64 записей (0x200 байт), т.е. слота `+0x680` нет.
У AGX-классов есть vtable на 199/319/442 записи (`0x7c94190`, `0x7c95630`, `0x7c99740`, `0x7c9a5b0`, `0x7c9b420`);
их слот `+0x540` — тот же геттер:
```
0xfffffff0081dd030  ldr x0, [x0, #0x208] ; ret      (варианты 0x81dee3c, 0x81d8d1c — то же)
```
Значит провайдер — объект AGX-класса (AGXAccelerator), а не IOGPU.

### 3. Инициализация провайдера
Функция `0xfffffff008166760` (self = x19, device = x20):
```
0xfffffff0081667f4  ldr x8, [x20, #0x548]
0xfffffff0081667f8  stp x8, xzr, [x19, #0x1e8]     ; provider+0x1e8 = device+0x548
```
То есть `[provider+0x1e8]` — это поле объекта-устройства `+0x548`.

### 4. Что лежит в device+0x548
Функция устройства `0xfffffff0081738c0` (self = x19, крупный объект, поля до 0x848):
```
0xfffffff008178310  pacia x16, x17
0xfffffff00817831c  mov  w0, #2
0xfffffff008178320  mov  x1, x19
0xfffffff008178324  mov  x2, x16
0xfffffff008178328  bl   0xfffffff008216430       ; стаб
0xfffffff00817832c  str  x0, [x19, #0x548]
```
Стаб `0x8216430` → GOT-слот `0xfffffff007ca58e8` → `0xfffffff00a96500c` (kernel text).

### 5. Аллокатор 0xa96500c
```
0xfffffff00a965044  adrp x0, 0x7c28000 ; add #0x60 ; w1=0x60 ; w2=0x4001004 ; bl 0xa220c30
0xfffffff00a965094  str  w8(=1), [x0, #8]
0xfffffff00a965098  adrp x16, 0x7c2d000 ; add #0xe50 ; add #0x10   ; = 0xfffffff007c2de60
0xfffffff00a9650ac  pacda x16, x17
0xfffffff00a9650b0  str  x16, [x0]                                 ; qword0 = signed vtable
```
Объект 0x60 байт, первый qword — PAC-подписанный указатель на vtable `0xfffffff007c2de60`
(kernel `__DATA_CONST`, т.е. **адрес образа ядра**, а не heap).

### 6. Вычисление слайда
Vtable статически лежит по `0xfffffff007c2de60`; unslid-база `0xfffffff007004000` (подтверждена panic-логами, отчёт id 8).
`pacda` меняет только старшие биты, низкие 32 бита адреса сохраняются, а slide укладывается в них без переполнения
(`0x07c2de60 + slide < 2^32` при slide < 0x783d21a0, что выполняется):
```
leak_q0 = PAC(0xfffffff007c2de60 + slide)
slide   = (leak_q0 & 0xffffffff) - 0x07c2de60
```

### 7. Доступность
Селектор 1 — таблица A (index 1), `structOut=0x40`. В таблицу B (restricted-энтитлменты) он тоже входит,
но там селекторы 0..20 совпадают с A. Дополнительных проверок прав в обработчике нет.
Внешние условия: `[client+0x100] & 1` (клиент открыт) и `args->[+0x10] == 0` (иначе `0xE00002C2`).

## Reproduction
1. Взять `__DATA_CONST` IOGPU (`va 0x7fe8c10, off 0xfe4c10, size 0x9c38`), декодировать chained fixups
   (`target = 0xfffffff007004000 + (q&0xffffffff)` для auth-rebase) и прочитать таблицу `0x7fea200[1]`.
2. `0x99947444` → дизасм; `0x99984e4c` — memcpy.
3. AGX: `0x8166760` (`+0x1e8 = [device+0x548]`), `0x81738c0` (`[device+0x548] = 0x8216430(...)`),
   стаб `0x8216430` → GOT `0x7ca58e8` → `0xa96500c`; аллокатор пишет vtable `0x7c2de60`.
4. Device-тест: открыть GPU user client, вызвать селектор 1 со `structureOutput` 0x40 байт,
   прочитать qword0 и посчитать `slide = (q0 & 0xffffffff) - 0x07c2de60`.

## Reliability
Цепочка статическая, детерминированная по файлам; на устройстве **не проверялась** (0 прогонов).
Слабые места: (а) провайдер может быть не тем AGX-объектом, который инициализирует `0x8166760`;
(б) поле `+0x1e8` может перезаписываться позже; (в) если объект в `device+0x548` создаётся другим путём,
qword0 всё равно будет vtable, но другого класса — тогда слайд считается от другого статического адреса
(проверяется по первому тесту: qword0 должен попадать в `0xfffffff0...`).

## Impact
Первый в проекте кандидат на прямой leak kernel-image-указателя через один `IOExternalMethod` вызов:
`sel 1` возвращает содержимое kernel-объекта, а не heap-адрес. При подтверждении это готовый KASLR-обход
без отдельной уязвимости памяти (только доступ к GPU user client).

## Next step
1. Device-тест sel 1: дамп 0x40 байт, проверить qword0 (ожидается `0xfffffff0...`), вычислить slide и сверить
   с `Kernel slide` из panic/`sysctl` на той же загрузке.
2. Если qword0 — не образ: вывести все 8 qword и сопоставить с известными vtable kernel `__DATA_CONST`
   (`0x7c2xxxx`), чтобы найти фактический класс объекта.
3. Параллельно проверить, доступен ли GPU user client из sandbox обычного приложения (Metal-путь).

## Confidence
medium-high: цепочка «provider+0x1e8 → device+0x548 → 0xa96500c → vtable 0x7c2de60» подтверждена статически
в четырёх независимых местах; отсутствует только runtime-подтверждение.
Опровергнет: device-тест, где qword0 не является указателем `0xfffffff0...` или `[dev+0x1e8]` равен 0.
