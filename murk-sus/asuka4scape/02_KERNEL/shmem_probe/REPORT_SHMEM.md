# ShmemProbe — итог по «адресу shmem» (iOS 27.2, iPhone14,7)

Дата: 10.11.2026. Цель: выяснить, даёт ли адрес command-shmem из IOGPU
прямой путь к kernel R/W, и подготовить решающий тест.

## 1. Что возвращает sel46

`IOGPUDeviceUserClient sel46` (create IO command buffer) возвращает два
скаляра:

```
out[0] = cbId (namespace id командного буфера)
out[1] = *(u64 *)(cb + 0x38)
```

Наблюдения (каждый запуск — новое значение):

```
IOGPU: f = 0xb019284, 0xb01a15a, 0xe01d503, 0xe01d558, 0x900a803, 0xade33cac
AGX  : f = 0xb0115bc, 0xe01d558
```

**`f` — это вообще не адрес.** Разбор кода показал:

```
IOGPUIOCommandBuffer::init (0x99958fd8):
  adrp x1, #0xaf22000 ; add x1,x1,#0xc0   ; &global_counter
  mov  w0, #1
  bl   0x99843dc                           ; ldadd x0,x0,[x1] -> old value
  stur x0, [x21,#-8]                       ; cb+0x38 = old counter

sel46 tail (0x9995ba4c):
  ldr x8, [x19,#0x38]                      ; cb+0x38
  str x8, [x20]                            ; out[1] = counter
```

`0x99843dc` — это атомарный `ldadd` по адресу `0xfffffff00af220c0`
(в образе ядра там лежит 1). То есть `out[1]` — **серийный номер**
(глобальный счётчик уведомлений/объектов), а не PA, не DVA и не VA.

Это объясняет всё:

- значение меняется от запуска к запуску и растёт между вызовами
  (0xb019284 → 0xb0192a3 → 0xb01a15a ...);
- `mach_vm_read_overwrite` по нему всегда `KERN_FAILURE`;
- «совпадение диапазонов» `f` и `resource+0x70` (0xb019xxx) — совпадение
  двух счётчиков, а не общая арена.

Настоящий command-list shmem находится в namespace `device+0x78` и
наружу не отдаётся; sel46 его адрес не возвращает.

## 2. `replace_backing_*` — полная цепочка гейтов

`sel38` (`replace_backing_bytes`):

```
FUN_999968054(device, structIn)
  → FUN_999957630(resource, task=device+0x50, addr, len)
      → FUN_999957448(resource)      // gate
      → sysmem->vtable[0xb0](sysmem, task, addr, len)
          = FUN_999982368 (replace_backing_bytes_locked)
              if (!(sysmem+0x30 & 0x10)) return 0xe00002c2  // Not detached
              if (len != old_descriptor_len) return 0xe00002c2 // Size mismatch
              FUN_9999805d0(task, addr, len)
                 mach_vm_region(task, &addr, &size, 9, ...)
                 IOMemoryDescriptor::withAddressRange(addr, len, opt, task)
```

`FUN_999957448` (gate) требует одновременно:

1. `OSDynamicCast(resource+0x28, IOGPUSysMemory)` — т.е. ресурс должен быть
   создан как sysmemory, а не из IOSurface (resType 0x82);
2. `(resource->flags & 0x2000ff) == 0x80` — **resType ровно 0x80**;
3. `resource+0x30 == 0`.

Поэтому:

- resType 0x82 (IOSurface-backed) → `0xe00002e2` (NotPermitted) сразу;
- нужен ресурс `sel8` с `w[0]=0x80`, затем `sel37` (detach) — он выставляет
  бит `0x10` в `sysmem+0x30`;
- `sel38` требует **точного совпадения длины** с исходным дескриптором;
- `sel39` (`replace_backing_ranges`) принимает `{u32 rid, u32 flags,
  u64 ptr_to_ranges, u64 count}`; `ptr_to_ranges` — массив
  `IOAddressRange {u64 addr; u64 len}` в user-памяти; каждый range
  валидируется через `mach_vm_region(task)`; исполняемые страницы
  запрещены (`VM_PROT_EXECUTE`); при `flags bit1` создаётся mapping в
  `task` и его адрес возвращается в `scalarOutput[0]`.

Ключевой вопрос — чей `task` лежит в `device+0x50`. Устройство создаётся
на каждый `IOServiceOpen`:

```
deviceUserClientStart:
  device = createDevice(gpu, userclient+0xd8 /* IOGPUTask */, userclient+0x128)
```

`IOGPUTask` создаётся в `initWithTask` (0x99946e14) из аргумента `x2` и
содержит task_t. Если это task нашего процесса — любой kernel VA/DVA
отвергается на `mach_vm_region`. Если это `kernel_task` — открывается
доступ к kernel VA (но mapping, созданный sel39, будет в kernel task, а не
в нашем).

## 3. IOSurfaceAddress (sel6/sel7)

`IOSurfaceRoot sel6/sel7` создают поверхность из клиентского адреса
(`IOSurfaceAddress` + `IOSurfaceAllocSize`). Проверка адреса реальная:

```
kernel{IOSurface} <ERROR>: allocate error - invalid address range
  (0xe01d59d - 0xe02159d) : (0xe01c000 - 0xe024000)
```

DVA `f` не прошёл. Значит `IOSurfaceAddress` тоже валидируется в task
клиента (mach_vm_region), а не трактуется как PA/kernel VA.

## 4. Сборка для решающего теста (SP6)

Исходник: `02_KERNEL/shmem_probe/main.m`.
Подписанный IPA: `/tmp/SP6-signed.ipa` (может быть очищен /tmp).

Что делает:

1. `service_sweep()` — IOServiceOpen типов 0..3 для AVE2/ANE/JPEG/
   IOMobileFramebuffer/DCP/SMC/SEP/Display/Scaler/IOGPU/AGX.
2. `make_cb()` — sel14 (shared page), sel42 (queue), sel44, sel46;
   сканирует shared-страницы sel14 и sel8-out+0x10 на qword с топ-байтами
   `0xffffff..` (потенциальная KASLR-утечка).
3. VM-снапшот до/после sel46 и sel45: печатает новые регионы и проверяет,
   попадает ли `f` в какой-либо mapped-регион.
4. `sysmem_test()`:
   - sel8 `resType=0x80`: `+0x38 = end`, `+0x40 = start`, `+0x48 = size`
     (наш page-aligned буфер 0x4000);
   - sel37 detach;
   - sel38 replace с нашим VA (контроль) и с kernel VA
     `0xfffffff007004000` (решающий тест);
   - sel39 ranges с нашим VA и с kernel VA.
5. `surface_addr_test()` — IOSurfaceAddress = наш VA (контроль),
   kernel text VA, kernel data VA.

## 5. Что означает результат

- `[SYSM] create type80 -> 0x0 rid=N` — ресурс создан; идём дальше.
- `detach -> 0x0` — sysmemory валиден и гейт пройден.
- `replace-bytes own -> 0x0` — task = наш процесс (addr трактуется как
  user VA). Тогда kernel VA даст `0xe00002bd`/`0xe00002c2`, и направление
  закрыто.
- `replace-bytes kva -> 0x0` — task = kernel_task. Тогда ресурс получает
  backing из kernel VA; нужен способ вернуть его в user (GPU/scaler) —
  следующий этап.
- Любой новый VM-регион после sel46, содержащий `f`, означает, что
  command-shmem замаплен в наш task: появляется контроль над GPU-командами.

## 6. Следующие шаги

1. Дождаться устройства, установить SP6 (bundle id
   `app.lake9674.aquila8809`), забрать `Documents/shmem.log`.
2. По результату `replace-bytes kva` выбрать ветку:
   - task=наш → искать memory-safety баг в reachable kext (scaler HCU,
     IOGPU sel25 stride OOB, IOSurface compressed);
   - task=kernel → строить GPU/scaler-цепочку для возврата kernel-памяти
     в user.
3. Параллельно: если VM-скан найдёт маппинг `f`, проверить запись в
   command-shmem и формат `sIOGPUIOKernelCommand` (типы 0/1/2/3,
   `processKernelCommands` 0x999598f8).
