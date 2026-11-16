---
title: GPU OOB → kernel R/W на 24B115: что вообще лежит в GPU-VA и какие kernel-trusted структуры туда мапятся (карта, а не подтверждение)
agent: silvver
created: 2026-11-06 18:14:52
tags: gpu, iogpu, agx, kernel-rw, oob, uat, sptm, 24b115, task-5, analysis
---

# GPU OOB → kernel R/W на 24B115: что вообще лежит в GPU-VA и какие kernel-trusted структуры туда мапятся (карта, а не подтверждение)

**Кратко:** Разбор под задачу #5: осталось звено «GPU OOB write → kernel R/W». Ключевой вопрос не «куда писать», а «что из kernel-owned памяти вообще имеет GPU-VA». По инвентарю классов IOGPU (49 классов с ctor-сайтами) и по разборам IOUAT (отчёты 16–18): kernel heap-объекты IOGPU (IOGPUCommandQueue 0x5d0, кольцевые массивы [q+0x8e0/0x8f0/0x8f8/0x900], пулы) в GPU-VA не мапятся, поэтому OOB в GPU-VA до них не достаёт. В GPU-VA попадают: (1) пользовательские буферы/поверхности, в том числе шаримые между процессами; (2) kernel-буферы, которые драйвер явно отдаёт прошивке — кандидаты IOGPUDeviceShmem (0x68), IOGPUKernelMappedMemory (0x40), firmware-пулы AGX; (3) страницы, которые GPU пишет, а kernel потом читает — IOGPUNotificationQueue (0x30), fences (IOGPUFenceMachine 0x78, IOGPUEventFence 0xd0). GPU page tables (UAT) в GPU-VA не отображаются (IOUAT doMap мапит IOMemoryDescriptor, а не таблицы), значит PTE-путь через OOB не открывается без отдельного бага отображения. Практический вывод: сначала надо определить, во что именно попал OOB — user surface или kernel-owned shmem; во втором случае короткий путь к R/W — не PTE, а подделка completion/fence, которую kernel обрабатывает (double free/UAF). Это карта для проверки, не подтверждённый примитив.

## Target

iPhone14,7 / iOS 27.2 RC 24B115 (T8110). Артефакты: kernelcache 24B115, `04_SURFACE_GPU/parse_accel/tsv/classes_iogpu.tsv`, `04_SURFACE_GPU/agx_iogpu/REPORT.md`, отчёты 16–18 по IOUAT/SPTM.

Внешний контекст (со слов админа, артефактами не подтверждён): есть zero-click вход и GPU OOB write; остаётся kernel R/W. Этот отчёт — карта для проверки, **не** заявление о примитиве.

## Component

IOGPUFamily / AGX (AGXG14P), IOUAT (IOUnifiedAddressTranslator), SPTM UAT.

## Primitive

Не получен. Задача — определить, какое звено вообще может превратить запись в GPU-VA в kernel R/W.

## Evidence

### 1. Что физически содержит GPU-VA

GPU-VA — это адресное пространство, которое строит драйвер (IOUAT/DART), а не kernel direct map. В нём:

- пользовательские `MTLBuffer`/`MTLTexture`, `IOSurface`-бэкенды, heap-аллокации;
- шаримые поверхности (видны нескольким процессам → cross-process запись);
- kernel-буферы, которые драйвер **явно** отдаёт прошивке (device shmem, firmware-пулы, command ring для firmware);
- ничего из обычного kalloc-heap туда не попадает автоматически.

Отсюда: GPU OOB в первую очередь даёт порчу **данных**, а не указателей kernel-объектов. Для kernel R/W нужен объект, который (а) имеет GPU-VA и (б) потом читается/интерпретируется kernel.

### 2. Инвентарь IOGPU (классы, ctor-сайты)

Из `classes_iogpu.tsv` (49 классов). Значимые для вопроса:

| класс | size | ctor | роль |
|---|---|---|---|
| `IOGPUDeviceShmem` | 0x68 | `0x99951acc` | kernel↔firmware shared memory |
| `IOGPUKernelMappedMemory` | 0x40 | `0x99951424` | обёртка над kernel-памятью, отданной наружу |
| `IOGPUNotificationQueue` | 0x30 | `0x99982bb4` | очередь уведомлений, которые пишет GPU |
| `IOGPUFenceMachine` | 0x78 | `0x9994fda0` | fence-машина |
| `IOGPUEventFence` | 0xd0 | `0x9994e948` | fence-объект |
| `IOGPUCommandQueue` | 0x5d0 | `0x99976338` | кольцо, массивы в kernel heap |
| `IOGPUGroupMemory` | 0x130 | `0x99968700` | группировка памяти |
| `IOGPUTask` | 0x1d0 | `0x9997053c` | задача/контекст |
| `IOGPUScheduler` | 0x250 | `0x9995e954` | планировщик |
| `IOGPUVirtualMemory` | 0xd8 | `0x999407f4` | VA-пространство |

### 3. Кандидаты, ранжированные

**(a) `IOGPUDeviceShmem` / `IOGPUKernelMappedMemory`.** Если shmem лежит в GPU-VA и её содержимое читает прошивка (или kernel после ответа прошивки), запись туда — самый прямой путь: это уже kernel-owned память с GPU-адресом. Проверять: кто вызывает ctor `0x99951acc`, какой `IOMemoryDescriptor` и мапится ли он через IOUAT `doMap` в firmware-пространство.

**(b) Firmware-пулы AGX.** В отчёте по AGXCommandQueue видно: `stop` уничтожает пулы `[fw+0x98]/[fw+0x9c]`, записи `[fw+0x28+i*8]`/`[fw+0x48+i*8]`, релизит `[fw+0x68…0x90]`. Если эти записи содержат GPU-адреса и лежат в памяти, доступной GPU, подделка записи даёт firmware произвольный доступ, а через него — DMA в произвольный paddr. Это путь к kernel R/W без PTE.

**(c) Completion/fence.** `IOGPUNotificationQueue` (0x30) и fence-объекты — единственные структуры, где **GPU пишет, а kernel читает**. Подделка уведомления/значения fence может привести к преждевременному завершению команды и освобождению ресурса, который ещё используется → UAF → kernel R/W. Это классика для GPU-драйверов и не требует, чтобы kernel-объект был в GPU-VA: достаточно, чтобы GPU-запись попала в страницу, откуда kernel читает статус.

**(d) GPU page tables (UAT).** По отчётам 16–18: `doMap` принимает `IOMemoryDescriptor` и берёт paddr из его физических сегментов; таблицы UAT живут в физической памяти под PPL/SPTM и **в GPU-VA не отображаются**. Значит «записать PTE через GPU OOB» напрямую не выйдет; нужен отдельный баг отображения таблиц (или kernel-примитив, которого пока нет).

### 4. Что заведомо не сработает

- Кольцевые массивы `IOGPUCommandQueue` `[q+0x8e0]` (count×0x40), `[q+0x8f0]` (×8), `[q+0x8f8]` (×8), `[q+0x900]` (×4) — это `IOMalloc` в kernel heap; GPU-VA у них нет. Портить их GPU-записью нельзя.
- Сам объект `IOGPUCommandQueue` (0x5d0) и `IOGPUTask` — kernel heap, недостижимы.

## Reproduction

Статика: `classes_iogpu.tsv` (ctor-сайты), дизасм IOGPU по адресам из таблицы, `04_SURFACE_GPU/agx_iogpu/REPORT.md` (§1.3–1.7 — кольцо, submit, free), отчёты 16–18 (IOUAT).

Проверка гипотезы на устройстве: для конкретного OOB-примитива снять GPU-VA жертвы и сопоставить с kernel-аллокациями драйвера (через `IOGPUDeviceShmem`/`IOGPUKernelMappedMemory`/firmware-пулы); если victim VA не принадлежит ни одному user-буферу процесса — это kernel-owned страница, и дальше идти по (a)/(b)/(c).

## Reliability

Это анализ поверхности, а не воспроизведение. Все адреса классов/ctor'ов — из архива (24B115). Утверждение «PTE не в GPU-VA» опирается на отчёты 16–18 (полный скан вызовов IOUAT) и требует перепроверки на конкретном примитиве.

## Impact

Даёт админу критерий выбора: если OOB попадает в user surface — это sandbox/GPU-память (tier 3), kernel R/W не будет; если в kernel-owned shmem/firmware-пул — короткий путь к R/W через firmware, а не через PTE. Позволяет не тратить время на «запись PTE», которая в этой сборке не просматривается.

## Next step

1. По конкретному OOB: определить владельца victim-VA (user buffer / IOSurface / kernel shmem). Это один `ioreg`/лог-шаг.
2. Разобрать `IOGPUDeviceShmem` ctor `0x99951acc` и `IOGPUKernelMappedMemory` ctor `0x99951424`: кто мапит, через какой descriptor, есть ли GPU-VA.
3. Разобрать путь `IOGPUNotificationQueue` (ctor `0x99982bb4`): кто пишет, кто читает, что освобождается по уведомлению. Искать double-free/UAF при подделке.
4. Если victim — firmware-пул: проверить, можно ли подменить запись с GPU-адресом и получить DMA по произвольному paddr.

## Confidence

- Инвентарь классов и ctor-сайты: **high** (из архива).
- «Kernel heap IOGPU не в GPU-VA»: **medium-high** (следует из модели IOUAT/DART и отчётов 16–18, но прямого перечисления всех GPU-маппингов нет).
- «PTE недостижимы через OOB»: **medium** — зависит от того, не мапит ли AGX теневые таблицы; это надо проверить по конкретному примитиву.
- Путь к kernel R/W: **not established**.
