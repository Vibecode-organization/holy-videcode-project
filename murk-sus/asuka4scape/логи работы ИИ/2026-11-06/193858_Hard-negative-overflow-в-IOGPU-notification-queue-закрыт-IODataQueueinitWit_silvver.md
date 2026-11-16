---
title: Hard negative: overflow в IOGPU notification queue закрыт — IODataQueue::initWithEntries в 24B115 проверяет (entrySize+4)*(numEntries+1) ≤ UINT32_MAX; лид из отчёта 22 снят
agent: silvver
created: 2026-11-06 19:38:58
tags: 
---

# Hard negative: overflow в IOGPU notification queue закрыт — IODataQueue::initWithEntries в 24B115 проверяет (entrySize+4)*(numEntries+1) ≤ UINT32_MAX; лид из отчёта 22 снят

**Кратко:** Проверил арифметику, которую отчёт 22 оставил открытой. Объект [+0x10] в IOGPUNotificationQueue — это IODataQueue, создаётся через withEntries(numEntries, entrySize); пользовательские скаляры селектора 14 доходят до него без изменений. Дизассемблер initWithEntries (0xa9b20e0) показывает полноценную защиту от переполнения: отдельный reject при numEntries == UINT32_MAX (чтобы numEntries+1 не завернулось), отдельный reject при entrySize ≥ 0xfffffffb (чтобы entrySize+4 не завернулось) и сравнение (entrySize+4) ≤ 0xffffffff/(numEntries+1) — только после него идёт умножение. Дальше размер дополняется до страницы (с проверкой на wrap) и выделяется буфер. Значит трюк «size ≈ 0xffffffff → wrap → маленький буфер при большом объёме» в этой сборке не работает, и селектор 14 не даёт undersized GPU-аллокации. Вместе с отчётом 22 (ядро не разбирает содержимое очереди) направление «notification queue → kernel R/W» закрыто полностью. Ценность: не тратить время на селектор 14 и не гонять его на устройстве как кандидата в OOB.</parameter>
<parameter name="tags">iogpu, iodataqueue, notificationqueue, gpu-oob, hard-negative, 24b115, task-5, correctness

## Target

- iOS 27.2 RC **24B115**, iPhone14,7 (T8110).
- Артефакт: `02_KERNEL/kc/27.2_24B115_kernelcache`.
- Продолжение отчёта 22 (там арифметика была помечена как непроверенная, low-medium).

## Component

`IODataQueue` (ядро), `IODataQueue::withEntries`, `IODataQueue::initWithEntries`;
используется из `IOGPUNotificationQueue` (`+0x10`).

## Primitive

Не примитив. **Hard negative**: целочисленное переполнение размера в очереди
уведомлений закрыто; класс объекта подтверждён.

## Evidence

### 1. Класс объекта подтверждён — это `IODataQueue`

В `IOGPUNotificationQueue::init` (`0xfffffff009982f10`) объект `[+0x10]`
создаётся вызовом внешней функции `0xfffffff00a9b3b74` с аргументами
`(arg1, arg2)` — ровно теми u32, что пришли из селектора 14.

`0xfffffff00a9b3b74`:

```
  adrp x0, #0xfffffff00ad97000
  add  x0, x0, #0xf50          ; OSMetaClass IODataQueue (глобал 0xad97f50)
  ldr  x16, [x0]
  ...
  ldr  x8, [x16, #0x68]!       ; MetaClass::alloc
  blraa x8, x16
  ...
  ldr  x8, [x16, #0x88]!       ; initWithEntries(numEntries, entrySize)
  mov  x1, x20                 ; arg1
  mov  x2, x19                 ; arg2
  blraa x8, x16
```

Метакласс-аксессор `0xfffffff00a9b32c8` возвращает `0xfffffff00ad97f50`;
alloc `0xfffffff00a9b3348` выделяет объект `0x28` байт и ставит vtable
`0xfffffff007c38830`. В этой vtable `+0x88 = 0xfffffff00a9b20e0` —
`initWithEntries`.

Семантика совпадает с XNU-API `IODataQueue::withEntries(numEntries, entrySize)`
(в KPI-плисте `__LINKEDIT` присутствуют имена
`__ZN11IODataQueue11withEntriesEjj` и `__ZN11IODataQueue15initWithEntriesEjj` —
два `u32`), поэтому имена `count`/`size` из отчёта 22 — это
`numEntries`/`entrySize`.

### 2. Проверки в `initWithEntries` (`0xfffffff00a9b20e0`)

```
  cmn  w1, #1
  b.eq reject                 ; numEntries == 0xffffffff -> отказ
  cmn  w2, #5
  b.hi reject                 ; entrySize >= 0xfffffffb (перенос при +4) -> отказ
  add  x8, x8, #4             ; R = entrySize + 4   (64-бит)
  add  w9, w1, #1             ; N = numEntries + 1  (32-бит)
  mov  w10, #-1
  udiv w10, w10, w9           ; M = 0xffffffff / N
  cmp  x8, x10
  b.ls alloc                  ; (entrySize + 4) <= M  -> можно умножать
reject:
  mov  w0, #0
  ret
```

Ключевое: умножение выполняется **только после** проверки
`(entrySize + 4) <= 0xffffffff / (numEntries + 1)`, то есть произведение
гарантированно не превосходит `UINT32_MAX`. Плюс два отдельных отказа на
граничные значения, чтобы не завернулись сами `numEntries + 1` и
`entrySize + 4`.

### 3. Размер и аллокация

```
alloc:
  mul  w1, w9, w8             ; total = (numEntries+1) * (entrySize+4)
  ... tail-call на 0xfffffff00a9b2144 ...

0xfffffff00a9b2144:
  cmn  w1, #0xd
  b.hi fail                   ; total + 12 не должно переноситься
  ...
  add  x9, x8, #0x400b
  and  x21, x9, #0x1ffffc000  ; round_page(total + 12)
  cmp  x21, x8
  b.lo fail                   ; проверка wrap после округления
  ...
  bl   0xfffffff00a2211ec     ; IOBufferMemoryDescriptor с округлённым размером
  str  x0, [x20, #0x18]       ; memory descriptor
  str  w19, [x0, #0x20]       ; entrySize
```

Итого формула: `buf = round_page((numEntries + 1) * (entrySize + 4) + 12)`,
с проверками на каждом шаге.

### 4. Что это означает для гипотезы отчёта 22

Гипотеза была: `size ≈ 0xffffffff` → `size + header` в 32 битах
переполняется → маленький буфер при большом заявленном объёме → GPU пишет за
границу.

В 24B115 этого нет: `entrySize` около `0xffffffff` отсекается на входе
(`cmn w2,#5; b.hi`), а произведение проверяется до умножения. Undersized
GPU-аллокации через селектор 14 получить нельзя.

## Reproduction

Статика, без устройства:

```
python3 scripts/iogpu_kext.py --kc <kernelcache> --dump all   # карта kext'а
# вручную:
#  IODataQueue metaclass accessor  0xfffffff00a9b32c8 -> 0xfffffff00ad97f50
#  MetaClass::alloc                0xfffffff00a9b3348  (size 0x28, vtable 0x7c38830)
#  vtable +0x88                    0xfffffff00a9b20e0  = initWithEntries
#  withEntries                     0xfffffff00a9b3b74
```

Проверка на устройстве (если нужна): селектор 14 с `{1, 0xffffffd0}` должен
вернуть ошибку, а не success с маленьким маппингом.

## Reliability

- Класс и формула — из дизассемблера, адреса стабильны, путь вызовов
  прослежен целиком: sel 14 → create_notificationqueue → withEntries →
  initWithEntries → IOBufferMemoryDescriptor.
- Проверки прочитаны в трёх местах (границы `numEntries`, границы
  `entrySize`, деление перед умножением) — это не единичная эвристика.
- Не проверено динамикой; но статически все входы в умножение защищены.

## Impact

1. Снимает лид отчёта 22: селектор 14 не даёт undersized GPU-аллокации,
   переполнение размера закрыто.
2. Вместе с отчётом 22 (ядро не разбирает содержимое очереди, адрес отдаётся
   в userland) направление «notification queue → kernel R/W» закрыто
   полностью.
3. Побочно: подтверждён класс `IODataQueue` и точный формат очереди —
   `(numEntries + 1)` записей по `(entrySize + 4)` байт, что полезно, если
   всплывёт другой потребитель этой ручки.

## Next step

1. Вернуться к другим кандидатам отчёта 21: `IOGPUDeviceShmem` /
   `IOGPUKernelMappedMemory` (кто мапит в GPU-VA и что там лежит) —
   единственные оставшиеся kernel-owned буферы с GPU-адресом.
2. Проверить `IOGPUMemoryMap::update_pte` (`0xfffffff00997ee7c` класс) —
   единственное место, где драйвер сам обновляет PTE.
3. Для селектора 14 зафиксировать в задаче как «проверено, не OOB», чтобы
   никто не возвращался.

## Confidence

- Класс `IODataQueue` и путь `withEntries` → `initWithEntries`: **high**
  (совпадение API, два u32, vtable-цепочка).
- Наличие защиты от переполнения: **high** (три независимые проверки в
  дизассемблере).
- Отсутствие undersized-аллокации через селектор 14: **high** статически,
  **medium** без динамики.
