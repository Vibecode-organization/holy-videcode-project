# Kernel OOB candidates — 2026-11-11 (IOGPU / IOSurface)

## 0. Коротко

- **F1 GPU cross-object OOB write — подтверждён** на живом устройстве
  (`02_KERNEL/f1poc_desktop/REPORT_F1_GPU.md`). Но это OOB **в GPU VA-контексте
  приложения**, не в kernel: в контексте только свои Metal-буферы, kernel/TTBAT
  маппингов не найдено.
- **IOGPUNotificationQueue** — hard negative: `IODataQueue::withEntries`
  считает `(numEntries+1)*(entrySize+4)+12` с проверками, wrap нет.
- **IOGPUMemoryMap::update_pte** — найден batch-вызов `FUN_99943ea0`
  (массив дескрипторов + count, цикл `update_pte`). Кандидат на OOB/PTE-маппинг,
  если count/array приходят из userland. Нужна reachability до селектора.
- **sel25 submit_command_buffers** (`0x99947de8`) — кандидат на user-controlled
  completion address / DVA write. Нужен реальный формат command buffer.

## 1. F1 OOB (подтверждено)

Лог:

```
[METAL] F1 MTLBuffer len=65536 gpuAddress=0x1500000000
[METAL] victim MTLBuffer len=65536 gpuAddress=0x15000a8000
[METAL] *** CROSS-OBJECT GPU OOB WRITE CONFIRMED ***
```

- Алиас F1 даёт write/read за пределами своего буфера в **чужой GPU-ресурс**
  того же процесса.
- Скан GPU VA (f1ga ±, 0x13400000000..+16MB) нашёл только свои буферы и
  fence/stamp-страницы; kernel-указателей/TTBAT нет.
- Вывод: для kernel r/w нужен **kernel-owned объект, замапленный в GPU VA
  контекст** (device shmem / fence / firmware), либо отдельный kernel bug.

## 2. IOGPUNotificationQueue — hard negative

`IODataQueue` init `0xfffffff00a9b20e0`:

```
cmn w1,#1 ; b.eq reject
cmn w2,#5 ; b.hi reject
entrySize+4, numEntries+1
udiv -> 0xffffffff/(numEntries+1)
cmp ; b.ls alloc
buffer = round_page((numEntries+1)*(entrySize+4)+12)
```

Проверки исключают wrap при `size ≈ 0xffffffff`. Селектор 14 не даёт
undersized GPU-аллокацию.

## 3. IOGPUMemoryMap::update_pte batch

`update_pte` = `0xfffffff00997f744`. Прямой вызывающий:
`FUN_fffffff009943ea0` (`0x99943ea0`):

```c
if (*(int *)(obj+0x50) == 2) array = obj+0x60;
else                          array = *(long **)(obj+0x58);
count = *(int *)(obj+0x54);
for (i=0; i<count; i++)
    update_pte(array[i], p2, p3, p4);
```

- Если `count`/`array` контролируются userland — OOB read массива
  дескрипторов или PTE-маппинг произвольных дескрипторов.
- Reachability: `FUN_99943ea0` имеет только data-ref
  (`0xfffffff00afb8072`), вероятно vtable-метод; нужно найти vtable/класс
  и селектор. Следующий шаг: скан `__DATA_CONST`/`__auth_got` по
  PAC/relative-указателю на `0x99943ea0`, затем callers.

## 4. sel25 submit_command_buffers

- Handler `0xfffffff009947de8`; `si=4`, `szi=0xffffffff`, `so=1`.
- Input: `*puVar10` = queue id; `uVar1 = *(u64*)(in+0x10)`,
  `uVar2 = *(u64*)(in+0x18)`; проверка `uVar7 == uVar2*uVar1`
  (structureInputSize) и overflow-check.
- Submit `FUN_99976cf8`: цикл `count` раз, `lVar4 = i * cmdSize`,
  `uVar1 = param_2 + (int)lVar4` — **32-битное усечение смещения**.
  Если `lVar4 != (int)lVar4`, указатель заменяется на poison
  `0x2bad...`, и `FUN_9997700c` его разбирает.
- Кандидат: OOB read / panic при `count`/`cmdSize`, дающих смещение
  >2^31 (например, count=2, cmdSize=0x40000000). Product 2^31
  проходит 32-битный structureInputSize, но второй итерации указатель
  усечён/poisoned. Практический PoC требует 2 ГБ input — не тривиально;
  это DoS/panic, не r/w.

## 5. Следующие действия

1. Найти vtable/selector для `FUN_99943ea0`; проверить, откуда берутся
   `obj+0x50/0x54/0x58/0x60` (user или kernel).
2. Decompile `0x99947de8` (sel25) и AGX command buffer submit; искать
   completion address/DVA write.
3. Для F1: попытаться создать/найти kernel-owned GPU-маппинг
   (`IOGPUDeviceShmem`, fence page) и проверить, попадает ли он в GPU VA
   контекст приложения.
