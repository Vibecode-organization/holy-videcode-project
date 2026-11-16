---
title: IOUAT API целиком: doMap принимает IOMemoryDescriptor и сам выводит paddr из его физических сегментов; наружу в AGX торчат doMap/doUnmap/setClientContextID
agent: silvver
created: 2026-11-05 16:01:46
tags: iouat, uat, sptm, paddr, iomemorydescriptor, agx, iogpu, api-map, 24b115, task-4
---

# IOUAT API целиком: doMap принимает IOMemoryDescriptor и сам выводит paddr из его физических сегментов; наружу в AGX торчат doMap/doUnmap/setClientContextID

**Кратко:** Разобрал класс IOUnifiedAddressTranslator (firmware IOUAT, vtable 0xfffffff007c67f18) по окну kernel __TEXT_EXEC 0xa9e4000..0xaa24000. Строки дают полную карту API: getMode 0xa9ee018, getFirmwareAddressSpaceHandle 0xa9ee074, setClientContextID 0xa9ee0d0, removeClientContextID 0xa9ee210, doMap 0xa9ee318, doUnmap 0xa9ee854, prepareFWUnmap, createMappingInAperture, queueUnmap, commitUnmaps, getTotalPageTableMemory, isPageFaultExpected, getPageTablePhysicalBaseAddress, getPageTableEntry, mapToPhysicalAddress. PPL-опкоды: 0xbee0 SET_CONTEXT_ID, 0xbee1 REMOVE_CONTEXT_ID, 0xbee4 (bool-запрос), 0xbee5 GET_PT_ENTRY, 0xbee7 GET_ROOT_TABLE; сам маппинг идёт не через эти опкоды, а через вызов 0xa382400 с массивом записей {va, pa, len, flags}. Ключевое для задачи о paddr: doMap(this, backingDescriptor, virt, length, options) проверяет только descriptor != NULL и 16K-выравнивание virt/length, а физические адреса берёт из самого дескриптора — вызывает его виртуальный метод [desc+0x90] с опциями 0x1000001/0x1000000, получает сегменты {offset, pa, len} и складывает их в массив для PPL. То есть paddr не приходит от вызывающего: его источник — физические сегменты IOMemoryDescriptor. Значит для SPTM-байпаса через UAT MAP_BEGIN нужен не «произвольный paddr из userland», а kernel-объект, отдающий атакующие физические сегменты (withPhysicalAddress / DART / IOSurface-подобный путь). В AGX через GOT 0x7ca5a60..0x7ca5a90 экспортированы make (0xa9ec60c), getFirmwareAddressSpaceHandle, doMap (0xa9ee318), doUnmap, set/remove CTXID, getMode — то есть AGX является полноценным клиентом IOUAT, и вопрос reachability сводится к тому, какой AGX-селектор дергает doMap и с каким дескриптором.

## Target
iOS 27.2 RC **24B115**, iPhone14,7 / T8110. `com.apple.kernel` (IOUAT),
`com.apple.AGXG14P`. Окно `__TEXT_EXEC` `0xfffffff00a9e4000..0xfffffff00aa24000`
(off `0x39e0000`, 256 KiB).

## Component
`IOUnifiedAddressTranslator` (firmware IOUAT): kernel-клиент SPTM UAT.
Vtable `0xfffffff007c67f18` (см. отчёт id 15), объект 0x570 байт,
глобал `[0xfffffff00add7728]`, state `[0xadd7700]/[0xadd7708]`.

## Primitive
Не примитив — карта API и разбор источника `paddr` в `doMap`.

## Evidence

### 1. Полная карта методов (строки -> функции)
```
getMode                          0xfffffff0070b95eb  0xfffffff00a9ee018  ret [0xadd7708]
getFirmwareAddressSpaceHandle    0xfffffff0070b9615  0xfffffff00a9ee074  ret [0xadd7728]
setClientContextID               0xfffffff0070b9bbb  0xfffffff00a9ee0d0  PPL op 0xbee0, in 4
removeClientContextID            0xfffffff0070b9c47  0xfffffff00a9ee210  PPL op 0xbee1
doMap                            0xfffffff0070b9d8d  0xfffffff00a9ee318
doUnmap                          0xfffffff0070b9ef5  0xfffffff00a9ee854
prepareFWUnmap                   0xfffffff0070b9f45  (рядом, 0xa9eef..)
getTotalPageTableMemory          0xfffffff0070ba10b  vtable +0x80 (0xa9ece5c)
isPageFaultExpected              0xfffffff0070ba196  vtable +0x88 (0xa9eccd4)
getPageTablePhysicalBaseAddress  0xfffffff0070ba225  vtable +0x90 (0xa9ecb48), op 0xbee7
getPageTableEntry                0xfffffff0070ba2d8  vtable +0x98 (0xa9ec9d0), op 0xbee5
mapToPhysicalAddress             0xfffffff0070ba35e  vtable +0xa0 (0xa9ec94c) = getPTE & ~0xfff
```
Сообщения PPL-ошибок подтверждают опкоды:
`UAT_PPL_IOCTL_SET_CONTEXT_ID`, `..._REMOVE_CONTEXT_ID`, `..._PREPARE_UNMAP`,
`..._TOTAL_PT_MEM`, `..._FAULT_EXPECTED`, `..._GET_ROOT_TABLE`, `..._GET_PT_ENTRY`.

### 2. doMap: источник paddr
Сигнатура по регистрам (`0xa9ee318`): `(this, backingDescriptor, virtAddr, length, options)`.
```
0xa9ee398  cbz  x22,<err "backingDescriptor != nullptr">
0xa9ee3a4  tst  x21,#0x3fff ; b.ne <err "isAligned(size)">
0xa9ee3ac  tst  x8(sp+0x48),#0x3fff ; b.ne <err "isAligned(virtAddr)">
```
Перечисление сегментов — через виртуальный метод дескриптора
`[desc vtable +0x90]`, вызывается с `(desc, 0x1000001, buf64, 0x40)` и затем
`(desc, 0x1000000, buf64, 0x40)` (offset/PA/len очередного сегмента):
```
0xa9ee3dc  ldr x8,[x16,#0x90]!
0xa9ee3e8  w1 = 0x1000001
0xa9ee3f0  w3 = 0x40
0xa9ee3f8  blraa
...
0xa9ee40c  ldp x8,x23,[sp,#0x58]   ; offset?, phys?
0xa9ee410  and x8,x8,#0x3fff
0xa9ee418  add x9,x23,#0x3fff
0xa9ee420  and x24,x8,x9 ...       ; page-aligned extent
```
Дальше строится массив записей (stride 0x20, поля +0 va, +8 pa, +0x10 len, +0x18 0):
```
0xa9ee574  x13 = 5*idx
0xa9ee578  x11 = array + 8*x13
0xa9ee594  stp x13(va+off), x12(pa page) ,[x11]
0xa9ee5a8  str x10(len),[x11,#0x10]
0xa9ee598  str wzr,[x11,#0x18]
```
И вызов PPL-маппинга:
```
0xa9ee618  ldr x0,[x19,#0x20]     ; PPL client/gate
0xa9ee61c  x1 = array
0xa9ee620  x2 = count
0xa9ee624  x3 = w20/flags
0xa9ee628  x4 = 0
0xa9ee62c  bl 0xfffffff00a382400
```
Итог: **paddr не передаётся вызывающим** — он вычисляется из физических
сегментов `backingDescriptor`. Вызывающий контролирует только VA/длину/опции.

### 3. Что экспортировано в AGX
GOT AGX `0xfffffff007ca5a60..0x7ca5a90`:
```
0x7ca5a60 -> 0xa9ec60c  IOUAT::make(object, handle)
0x7ca5a68 -> 0xa9ee074  getFirmwareAddressSpaceHandle
0x7ca5a70 -> 0xa9ee318  doMap
0x7ca5a78 -> 0xa9ee854  doUnmap
0x7ca5a80 -> 0xa9ee018  getMode
0x7ca5a40 -> 0xa9ed1e4  retain/ref
0x7ca5a48 -> 0xa9eec08
0x7ca5a50 -> 0xa9ee0d0  setClientContextID
0x7ca5a58 -> 0xa9ee210  removeClientContextID
```
Это сходится с IOUAT-логикой: AGX создаёт IOUAT-объект, ставит CTXID и маппит
GPU-регионы через doMap.

### 4. Прочие методы (read-only трансляции)
`getPageTablePhysicalBaseAddress(ttbrIdx<2)` -> PPL `0xbee7`, out 8 (PA корневой
таблицы). `getPageTableEntry(va)` -> PPL `0xbee5`, in 8/out 8. `mapToPhysicalAddress`
просто маскирует PTE до 4K. `isPageFaultExpected(addr)` -> `0xbee4`, in 16/out 1.

## Reproduction
1. Kernelcache 24B115, окно off `0x39e0000` (VA `0xa9e4000`), 256 KiB.
2. Дизасм `0xa9ee318` (doMap), `0xa9ee0d0`, `0xa9ee210`, `0xa9ee854`.
3. Строки — `__PRELINK_TEXT`, off = `0x8000 + (VA-0xfffffff00700c000)`.
4. GOT AGX — `__DATA_CONST` `0xfffffff007c923f0`+, chained fixup
   `target = 0xfffffff007004000 + (q & 0xffffffff)`.

## Reliability
Статика; сигнатура doMap и массив сегментов прочитаны по инструкциям.
Имена методов — по строкам, которые эти функции логируют (совпадение
xref -> начало функции проверено для doMap/CTXID/getPTE/getRootTable).

## Impact
- Звено [1] из отчёта id 10 существует: IOUAT действительно отправляет
  физические адреса в PPL/UAT.
- Но paddr берётся из `IOMemoryDescriptor` (его физических сегментов), а не из
  аргумента. Прямого «user передал paddr» нет.
- Следовательно, для байпаса нужен объект, отдающий атакующие сегменты
  (например, дескриптор над произвольным PA, DART-окно, shared region).
- Reachability: AGX импортирует doMap/doUnmap/CTXID — следующий шаг искать
  конкретный AGX/IOGPU-селектор, который создаёт дескриптор и вызывает doMap.

## Next step
1. По полному kernelcache найти всех вызывающих `0xa9ee318` (doMap) и
   `0xa9ec94c` (mapToPhysicalAddress); выделить пути, достижимые из user client.
2. Проверить, может ли AGX/IOGPU создать IOMemoryDescriptor с task==NULL или
   с внешним PA (gfx-shared-region-base / gpu-region-base из DT — см. строки
   `0x70b98d1`, `0x70b98e5`, `0x70b9949`).
3. Если нет — зафиксировать hard negative: UAT MAP_BEGIN недостижим по paddr
   из песочницы, и вернуться к другим компонентам.

## Confidence
high — карта методов, сигнатура doMap и источник paddr (дизасм + строки).
medium — точная семантика опций 0x1000000/0x1000001 и полей структуры сегмента
(выведена из арифметики, не из символов).
Опровергнет: найденный вызов doMap с дескриптором, чьи сегменты задаёт userland,
или иная функция, отправляющая paddr в PPL напрямую (не через дескриптор).
