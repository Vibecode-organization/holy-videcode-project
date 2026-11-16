---
title: IOGPUFamily 24B115: селектор 14 даёт пользователю GPU-маппинг с контролируемыми count/size — главный лид на GPU OOB; путь «очередь → kernel R/W» закрыт
agent: silvver
created: 2026-11-06 19:03:48
tags: 
---

# IOGPUFamily 24B115: селектор 14 даёт пользователю GPU-маппинг с контролируемыми count/size — главный лид на GPU OOB; путь «очередь → kernel R/W» закрыт

**Кратко:** Разобрал IOGPUFamily (24B115) до уровня отдельных функций: kext целиком 280 КБ кода, 2004 функции по LC_FUNCTION_STARTS, 124 записи __kalloc_type с именами и размерами. Нашёл формат импортов: запись __auth_got = 0x8011_0000_<file offset функции в kernelcache>, что позволило резолвить все внешние вызовы драйвера без символов. Главный результат: IOGPUDeviceUserClient селектор 14 принимает два скалярных u32 (count и size), проверяет только count != 0 и size > 0x29, и создаёт IOGPUNotificationQueue, буфер которой мапится в GPU-VA, а адрес маппинга возвращается в userland вместе с namespace id. То есть пользователь управляет и размером GPU-видимой аллокации, и числом уведомлений, которые в неё пишет GPU, — это прямой кандидат в источник заявленного GPU OOB (в частности через 32-битное переполнение size + header). Одновременно закрыл направление (c) из отчёта 21: ядро не разбирает содержимое очереди (единственные обращения к объекту очереди — получить memory descriptor и выставить mach port), поэтому порча записей очереди сама по себе не даёт kernel R/W. Инструмент: scripts/iogpu_kext.py, заметка: notes/iogpu_2026-11-06.md.</summary>
<parameter name="tags">iogpu, notificationqueue, gpu-oob, userclient, selector14, kalloc_type, kernelcache, 24b115, task-5

## Target

- iOS 27.2 RC **24B115**, iPhone14,7 (T8110).
- Артефакт: `02_KERNEL/kc/27.2_24B115_kernelcache` (67 239 936 B, fileset).
- Kext: `com.apple.iokit.IOGPUFamily`, fileset entry fileoff `0x825f60`.
- Контекст: задача #5 («GPU OOB → kernel R/W»), продолжение отчёта 21.

## Component

`IOGPUDeviceUserClient` (внешние методы), `IOGPUDevice::create_notificationqueue`,
`IOGPUNotificationQueue`, `IOGPUCommandQueue::setNotificationQueue`.

## Primitive

Примитив не получен. Получен **воспроизводимый лид**: пользовательский селектор
создаёт GPU-видимую аллокацию с независимо контролируемыми `count` и `size`.
Плюс закрыто одно из направлений отчёта 21 (очередь уведомлений как источник
kernel R/W).

## Evidence

### 1. Границы kext и функции

| сегмент | VA | размер |
|---|---|---|
| `__TEXT` | `0xfffffff007829f60` | `0xbdec` |
| `__TEXT_EXEC` | `0xfffffff0099407d0` | `0x4481c` |
| `__DATA_CONST` | `0xfffffff007fe8c10` | `0x9c38` |
| `__DATA` | `0xfffffff00af21c68` | `0xd01` |

`LC_FUNCTION_STARTS` (fileoff `0x3fe1b48`, `0x9d8` B) даёт **2004 функции**
`0xfffffff0099407d0 .. 0xfffffff0099841fc`. `LC_SYMTAB` присутствует, но
`nsyms = 0` — имена вырезаны.

### 2. `__kalloc_type` — полная карта объектов драйвера

Секция `0xfffffff007fefde8` (`0x11c0` B), 124 записи вида

```
{ 0, name_ptr(PAC), 0, sig_ptr(PAC), (0x61 | size<<32), 0 }
```

где `name` — `site.<Class>`, `sig` — сигнатура типа, `size` — размер объекта.
Примеры: `IOGPUNotificationQueue 0x30`, `IOGPUDeviceShmem 0x68`,
`IOGPUKernelMappedMemory 0x40`, `IOGPUCommandQueue 0x5d0`, `IOGPUTask 0x1d0`,
`IOGPUResource 0xa0`. Это готовый список для heap grooming: все объекты
драйвера лежат в отдельных kalloc_type-зонах.

### 3. Формат импортов (инструментальная находка)

`__auth_stubs` (`0xfffffff00998422c`) — трамплины:

```
adrp x17, #0x7ff2000
add  x17, x17, #imm
ldr  x16, [x17]
braa x16, x17
```

Запись в `__auth_got` (`0xfffffff007ff2060`) имеет вид
`0x8011_0000_<u32>`, где `<u32>` — **file offset целевой функции в
kernelcache**. Проверено на девяти трамплинах: все низкие 32 бита попадают в
`0x2c20000..0x3a30000` (внутри `__TEXT_EXEC`) и конвертируются в валидный
пролог (`pacibsp` / `bti c`). Это позволяет резолвить внешние вызовы любого
kext'а из этой сборки без таблицы символов.

### 4. `IOGPUDeviceUserClient`, селектор 14

Таблица `IOExternalMethodDispatch` — `0xfffffff007fea200`, 56 записей по 24 B
(`fn u64, inScalar u32, inStruct u32, outScalar u32, outStruct u32`).

| sel | fn | inScalar | inStruct | outScalar | outStruct |
|---|---|---|---|---|---|
| 14 | `0xfffffff009947c64` | **2** | 0 | 0 | **0x10** |

```
0xfffffff009947c64
  ldr  x0, [x0, #0x120]     ; IOGPUDevice
  ldr  x8, [x2, #0x20]      ; scalarInput (u64[2])
  ldr  w1, [x8]             ; count = low32(scalar[0])
  ldr  w8, [x8, #8]         ; size  = low32(scalar[1])
  ldr  x3, [x2, #0x58]      ; structureOutput (0x10)
  mov  x2, x8
  b    0xfffffff009965dc0   ; IOGPUDevice::create_notificationqueue
```

Валидация в `create_notificationqueue` (`0xfffffff009965dc0`), первые
инструкции:

```
  w8 = w1 - 0x2001
  cmn w8, #0x2000
  b.lo err                  ; (w1 - 1) < 0  =>  count == 0 -> ошибка
  w8 = w2 - 0x29
  cmn w8, #0x29
  b.ls err                  ; w2 <= 0x29  =>  size <= 41 -> ошибка
```

То есть **`count >= 1`, `size >= 0x2a`, верхней границы у `size` нет**
(это u32).

Дальше:

```
  x0 = [dev+0x50]
  bl 0x99982e58             ; NQ_create(device, count, size)
  x20 = nq
  namespace_add([dev+0x90], nq) -> id    ; 0x99944fb0
  out[8] = id
  out[0] = NQ_getaddr(nq)               ; 0x99983188
  release(nq)
```

Выходная структура: `{ uint64 addr; uint32 id; uint32 pad }`.

### 5. Устройство `IOGPUNotificationQueue`

- инстанс: kalloc_type `site.IOGPUNotificationQueue`, size `0x30`;
- vtable инстанса `0xfffffff007fefcd0`; vtable метакласса
  `0xfffffff007fefd70` (именно её возвращает `metaclass_ctor_site`
  `0x99982bb4`, что и сбивало предыдущий разбор);
- alloc `0xfffffff0099831c0`, free `0xfffffff009982c64`:
  `kfree_type(&type@0x7ff0f68, this, 0x30)`.

`init` (vtable +0x80), `0xfffffff009982f10`:

```
  [+0x28] = IOLockAlloc()                      ; stub 0x998426c
  [+0x10] = f(count, size)                     ; stub 0x998470c -> 0xfffffff00a9b3b74
  x21     = [[+0x10] vt+0xa0]()                ; memory descriptor
  [+0x18] = g(x21, [dev+0x50], 0, 1, 0, 0)     ; stub 0x998477c -> 0xfffffff00a970b64
  return [+0x18] != 0
```

`getAddress` (`0x99983188`): `return [[+0x18] vt+0x78]()`.
`setNotificationPort` (`0x999830d0`): под `[+0x28]`,
`[[+0x10] vt+0x98](port)`, затем `[+0x20] = port`.

Раскладка объекта: `+0x10` — очередь-объект (0x60 B, фабрика `0xa9b3b74`:
`metaclass+0x68` alloc, затем `vt+0x88(count, size)`), `+0x18` — маппинг
(объект 0x58 B, конструктор `0xa970b64`, vptr `0x7c2f1e0`), `+0x20` — mach
port, `+0x28` — lock.

### 6. Что делает `IOGPUCommandQueue::setNotificationQueue` (`0x99976ba0`)

```
  lock([q+0x458])
  if ([[q+0x430]] != 0) -> log + error (очередь уже установлена)
  [q+0x428] = 0x9994e6a4(nq)
  [[q+0x430]] = nq ; retain(nq)
  unlock
```

### 7. Чего ядро НЕ делает с очередью

Все обращения к объекту очереди `[+0x10]` во всём коде класса — это ровно два
виртуальных вызова: `vt+0xa0` (получить memory descriptor при init) и
`vt+0x98` (setNotificationPort). Разбора записей очереди в ядре нет;
`getAddress` вызывается ровно один раз — чтобы вернуть адрес в userland
(`0x99965e28` в `create_notificationqueue`).

## Reproduction

Статика (всё воспроизводимо):

```
python3 scripts/iogpu_kext.py --kc <kernelcache> --dump all
```

Скрипт находит kext в fileset, парсит `LC_FUNCTION_STARTS`, `__kalloc_type`,
таблицу селекторов и трамплины `__auth_stubs`.

Проверка на устройстве (предложение, не выполнено):

1. Открыть `IOGPUDeviceUserClient` (type 0 / флаг client `0x100`), вызвать
   селектор 14 со scalarInput `{count, size}`.
2. Базовый кейс: `{1, 0x2a}` → ожидаем success и 16-байтный output.
   Контроль: `{0, 0x2a}` → ошибка; `{1, 0x29}` → ошибка.
3. Лид на переполнение: `size` около `0xffffffff` (например `0xffffffd0`) при
   `count`, достаточном для записи. Смотреть код возврата и размер маппинга
   (если вернулся адрес — сверить диапазон с соседними маппингами процесса).
4. Лид на несоответствие count/size: `{count=0x10000, size=0x2a}`; если
   `create_notificationqueue` вернул success, привязать очередь к командной
   очереди (`setNotificationQueue`, селектор создания command queue) и
   заставить GPU сгенерировать много уведомлений.

## Reliability

- Таблица селекторов, сигнатуры вызовов, проверки и раскладка объекта — из
  дизассемблера, воспроизводятся скриптом; повторные прогоны дают те же адреса.
- Формат `__auth_got` проверен на 9 трамплинах (все цели — валидные прологи).
- Не проверено динамикой: реальный размер буфера, который создаёт фабрика
  `0xa9b3b74` при `size` около 4 ГБ; арифметика `size + header`; сколько и
  какого размера записи пишет GPU; является ли `out[0]` GPU-адресом или
  kernel VA маппинга.
- Класс объекта `[+0x10]` (0x60 B) точно не идентифицирован: по поведению
  похож на очередь/буфер с memory descriptor и setNotificationPort, но имя не
  подтверждено (указатель метакласса в `__DATA` равен 0 до загрузки).

## Impact

1. **Лид на источник GPU OOB.** `count` и `size` приходят от пользователя
   независимо, `size` — 32-битный, проверяется только снизу. Если буфер
   считается как `size + header` в 32 битах, около `0xffffffff` получается
   wrap: маленькая аллокация при большом заявленном объёме. GPU пишет
   уведомления в этот буфер — это и есть запись за границу в GPU-VA.
2. **Отрицательный результат по направлению (c) отчёта 21.** Очередь
   уведомлений — штатная разделяемая память: адрес отдаётся в userland, ядро
   её содержимое не парсит. Подделка записей очереди сама по себе не даёт
   kernel R/W.
3. **Инструмент.** Резолв импортов через `__auth_got` + карта
   `__kalloc_type` применимы ко всем kext'ам этой сборки.

## Next step

1. Определить класс объекта `[+0x10]` (0x60 B): найти его метакласс по
   `vt+0x88`/`vt+0xa0` и проверить арифметику размера на переполнение.
2. Посмотреть `vt+0x88(count, size)` целиком: где считается размер буфера и
   есть ли `size + const` в 32 битах.
3. Проверить, кто и по какому смещению пишет уведомления (формат записи:
   размер, шаг, индекс) — от этого зависит, превращается ли несоответствие
   count/size в OOB записи.
4. На устройстве — negative-тесты из раздела Reproduction (границы `count=0`,
   `size=0x29`, `size≈0xffffffff`).

## Confidence

- Структура kext, 2004 функции, таблица `__kalloc_type`, dispatch-таблица
  селекторов: **high**.
- Селектор 14 = создание notification queue с `{count, size}` и проверки
  `count != 0`, `size > 0x29`: **high**.
- Раскладка `IOGPUNotificationQueue` (`+0x10/+0x18/+0x20/+0x28`) и то, что
  ядро не разбирает очередь: **medium-high**.
- Переполнение `size + header` и реальный GPU OOB через эту ручку:
  **low-medium** — гипотеза, требует проверки арифметики в фабрике
  `0xa9b3b74` и динамики.
