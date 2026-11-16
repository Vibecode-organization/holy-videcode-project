# SPTM / UAT chain theory — 27.2 RC 24B115, iPhone14,7 (T8110)

> Статус: **теория + проверяемые адреса**, не рабочий exploit.
> Всё, что ниже, снято с `kernelcache.27.2RC.24B115.iphone14b`
> (MD5 `b6ccbea022fada0fd7fc399212110e0c`) и `sptm/27.2/sptm.macho`
> (SPTM-820.40.24). Где вывод сделан по коду, это помечено; где не проверено
> на устройстве — тоже.

---

## 0. Карта доменов

```
app / sandbox
   │  kernel bug (UAF/OOB) или узкий paddr-примитив
   ▼
XNU kernel
   │  IOUAT::doMap / PPL ioctl
   ▼
SPTM / PPL (UAT)
   │  paddr == uat_instance[0x68] -> skip FTE, PTE write
   ▼
GPU page tables (TTBAT)
   │  GPU DMA
   ▼
физическая память / kernel memory
```

SPTM-байпас — **не** sandbox escape. Это PPL-баг, который срабатывает только
после того, как kernel-код отправил в UAT сегмент с `paddr == 0x04D00000`.

---

## 1. SPTM UAT: точные адреса

База SPTM: `0xfffffff027004000`. `__text` VA `0xfffffff027098000`
(file offset `0x94000` в `sptm.macho`).

| endpoint | VA | Примечание |
|---|---|---|
| `sptm_uat_map_begin` | `0xfffffff0270ae700` | копирует сегменты, вызывает continue |
| `sptm_uat_map_continue` | `0xfffffff0270adf30` | per-page цикл, **TTBAT skip** |
| `sptm_uat_unmap_begin` | `0xfffffff0270ad5d8` | |
| `sptm_uat_unmap_continue` | `0xfffffff0270ac7b8` | |
| `sptm_uat_set_ctx_id` | `0xfffffff0270ac43c` | PPL `SET_CONTEXT_ID` |
| `sptm_uat_remove_ctx_id` | `0xfffffff0270abc74` | PPL `REMOVE_CONTEXT_ID` |
| `sptm_uat_get_info` | `0xfffffff0270ab9e0` | GET_INFO, 10 типов |
| `sptm_uat_revoke_sapt_multipage` | `0xfffffff0270f4334` | |
| `sptm_uat_map_table` | `0xfffffff0270aeec4` | |
| `sptm_uat_unmap_table` | `0xfffffff0270aea24` | |
| `sptm_uat_init_state` | `0xfffffff0270af568` | |
| `sptm_uat_destroy_state` | `0xfffffff0270af1a0` | |
| `uat_walk_tables` | `0xfffffff0270ad14c` | |
| `sptm_validate_fte` | `0xfffffff0270e1168` | проверка FTE, которую skip-ают |
| `uat_bootstrap_parse_dt` | `0xfffffff0270afb68` | SecureDT → instance |
| `uat_instance` pointer | `0xfffffff0270921b8` | `*(u64*)` → instance |

### 1.1. `uat_instance` layout (из `uat_bootstrap_parse_dt` и `map_continue`)

| offset | поле |
|---|---|
| `+0x10` | mode (0/1) |
| `+0x18` | shared/private root table |
| `+0x20` | PPL state object? |
| `+0x28` | state lock |
| `+0x30` | flags (bit 0 = fCodeRange) |
| `+0x38` | fCodeRangeAllocator |
| `+0x68` | **gpu-region-base (TTBAT)** |
| `+0x70` | gpu-region-size, в страницах 16K |
| `+0x80` | `issue-gmmu-tlbis-at-retype` |
| `+0x81` | `verify-gmmu-tlbis-at-sync` |
| `+0x88` | `gmmu-tlbi-verification-reg` |
| `+0x90` | `gmmu-tlbi-verification-bit` |
| `+0x91` | Dekker gate byte |
| `+0x108/+0x110` | `gfx-shared-region-base/size` |
| `+0x118/+0x120` | `gfx-shared-l2-region-base/size` |
| `+0x1b0` | `uat-enforce-gpu-carveout` |
| `+0x1b1` | `uat-vaddr-size` |
| `+0x1b8` | GET_INFO 4 |
| `+0x1c0` | `uat-segment-limit` (default 0x40) |
| `+0x1c8` | `uat-mapping-limit` |
| `+0x1d0` | GET_INFO 8 |

`gpu-region-base` = кандидат **`0x04D00000`**, `gpu-region-size` = **`0x20000`**
(8 × 16K). В публичном DeviceTree этих ключей нет; они в SecureDT.
Кандидат подтверждается `sgx.reg[1] = {0x04D00000, 0x20000}`.

### 1.2. Код skip-а (24B115, `map_continue`)

```asm
270ae174  ldr  x11, [x11, #0x68]   ; instance->gpu_region_base
270ae178  cmp  x23, x11            ; x23 = paddr & ~0x3fff
270ae17c  b.ne 270ae184
270ae180  cbnz w10, 270ae33c      ; special type -> panic 0x4000012
270ae184  cmp  x23, x11
270ae188  b.eq 270ae064           ; <<< skip sptm_validate_fte
270ae18c  and  w1, w9, #0xff
270ae190  mov  x0, x23
270ae194  bl   270e1168           ; sptm_validate_fte
270ae198  b    270ae064
270ae064  ...  PTE write
270ae0a8  str  x24, [x22], #8
```

`w10` = special type (`{2,3,5,6,7,9,10}`). Если `paddr == gpu_region_base`
и тип не special:

- `VIOLATION_UAT_ILLEGAL_TTBAT_MAPPING` не срабатывает;
- `sptm_validate_fte` не вызывается;
- PTE пишется с правами из `w9` (read/write).

Это и есть SPTM-байпас.

### 1.3. `GET_INFO` (для проверки)

`0xfffffff0270ab9e0`:

| param | возвращает |
|---|---|
| 0 | `instance+0x10` (mode) |
| 1/2 | root table paddr через `0x270d3dec(instance+0x18)` |
| 3 | `instance+0x1b1` (uat-vaddr-size) |
| 4 | `instance+0x1b8` |
| 5 | `instance+0x1c0` |
| 6 | `0x1000000000` |
| 7 | `0x7000000000` |
| 8 | `instance+0x1d0` |
| 9 | `instance+0x118` + трансляция |

`GET_INFO` полезен для проверки TTBAT/root table после маппинга.

---

## 2. IOUAT: kernel-клиент UAT

База kernel `__TEXT`: `0xfffffff007004000`. IOUAT-код: `0xfffffff00a9e4000..0xfffffff00aa24000`.

### 2.1. API

| метод | VA | vtable | примечание |
|---|---|---|---|
| `make` | `0xfffffff00a9ec60c` | | создаёт IOUAT |
| `getMode` | `0xfffffff00a9ee018` | | `[0xadd7708]` |
| `getFirmwareAddressSpaceHandle` | `0xfffffff00a9ee074` | | `[0xadd7728]` |
| `setClientContextID` | `0xfffffff00a9ee0d0` | | PPL `0xbee0` |
| `removeClientContextID` | `0xfffffff00a9ee210` | | PPL `0xbee1` |
| `doMap` | `0xfffffff00a9ee318` | | paddr из `IOMemoryDescriptor` |
| `doUnmap` | `0xfffffff00a9ee854` | | |
| `getTotalPageTableMemory` | `0xfffffff00a9ece5c` | `+0x80` | |
| `isPageFaultExpected` | `0xfffffff00a9ed01c` | `+0x88` | PPL `0xbee4` |
| `getPageTablePhysicalBaseAddress` | `0xfffffff00a9ecb48` | `+0x90` | PPL `0xbee7` |
| `getPageTableEntry` | `0xfffffff00a9ec9d0` | `+0x98` | PPL `0xbee5` |
| `mapToPhysicalAddress` | `0xfffffff00a9ec94c` | `+0xa0` | `getPTE & ~0xfff` |
| `prepareFWUnmap` | `0xfffffff00a9ed644` | | PPL `0xbee3` |

Глобалы:

- `[0xfffffff00add7700]` — IOUAT enabled (должно быть 1);
- `[0xfffffff00add7708]` — mode (0/1);
- `[0xfffffff00add7728]` — firmware IOUAT object;
- `vtable = 0xfffffff007c67f18`.

### 2.2. Объект IOUAT (0x570 байт)

| offset | поле |
|---|---|
| `+0x10` | param |
| `+0x18` | param |
| `+0x20` | PPL state object |
| `+0x28` | lock |
| `+0x30` | flags (bit 0 = fCodeRange) |
| `+0x38` | fCodeRangeAllocator |
| `+0x540` | state |
| `+0x548` | unmap list lock |
| `+0x550` | release array |
| `+0x558` | release thread lock |
| `+0x560` | thread |

### 2.3. `doMap`

`0xfffffff00a9ee318`:

1. `backingDescriptor != NULL`, `virt`/`length` кратны 0x4000.
2. Перечисляет физические сегменты через `[desc vtable+0x90]`:
   - `(desc, 0x1000001, &seg, 0x40)` — первый сегмент;
   - `(desc, 0x1000000, &seg, 0x40)` — следующий.
3. Строит массив записей stride 0x20:
   `{ +0x00 = va, +0x08 = paddr & ~0x3fff, +0x10 = length, +0x18 = 0 }`.
4. Вызывает `FUN_fffffff00a382400(*(this+0x20), array, count)`.

`FUN_fffffff00a382400` — обёртка PPL map:

```c
if (array != NULL && count * 0x28 overflows) panic;
return (*(state_vtable + 0x30))(state, array, count);
```

### 2.4. PPL ioctl

`FUN_fffffff00a3825a8(state, opcode, in, inSize, out, outSize)`.

| opcode | смысл |
|---|---|
| `0xbee0` | SET_CONTEXT_ID |
| `0xbee1` | REMOVE_CONTEXT_ID |
| `0xbee3` | PREPARE_UNMAP |
| `0xbee4` | FAULT_EXPECTED |
| `0xbee5` | GET_PT_ENTRY |
| `0xbee6` | TOTAL_PT_MEM |
| `0xbee7` | GET_ROOT_TABLE |

`getPageTableEntry(va)`:

```c
FUN_0xa3825a8(state, 0xbee5, &va, 8, &pte, 8);
```

`getPageTablePhysicalBaseAddress(idx)`:

```c
FUN_0xa3825a8(state, 0xbee7, &idx, 4, &paddr, 8);
```

### 2.5. `withPhysicalAddress` / `withAddressRange`

`IOMemoryDescriptor::withAddressRange` — `0xfffffff00a97ae84`:

```c
task != 0 -> type 0x10 (virtual64)
task == 0 -> type 0x20 (physical64)
```

`IOMemoryDescriptor::withPhysicalAddress` — `0xfffffff00a97af54`:

```c
alloc IOGeneralMemoryDescriptor
vtable+0x78(&addr, 1, 0, 0, options | 0x20, 0)
```

`options | 0x20` — physical64. Это ровно то, что нужно для дескриптора
над `0x04D00000`.

---

## 3. AGX / TTBAT

| объект | VA | примечание |
|---|---|---|
| AGX `__TEXT_EXEC` | `0xfffffff008165300` | G14P |
| `AGXUAT` TTBAT init | `0xfffffff0081ff0d0` | читает `gptbat-ready`, `ttbat-phys-addr-base` |
| `AGXUAT::allocPageTables` | `0xfffffff0082105b8` | |
| `AGXUAT::mapToPhysicalAddress` | `0xfffffff00821569c` | unimplemented/panic |
| `AGXSecureGart::mapInThisGart` | `0xfffffff0081fc968` | вызывает `IOUAT::doMap` |
| AGXSecureGart call sites | `0x81fcb78/0x81fccb4/0x81fcdb0/0x81fce60` | |
| AGXSecureGart unmap | `0x81fdc28` | |
| AGXDeviceUserClient ctor | `0xfffffff00819ee2c` | vtable `0x7c947e0` |
| AGX `ttbat-phys-addr-base` string | `0xfffffff0071228e8` | |

`FUN_fffffff0081ff0d0`:

```c
if (provider->getProperty("gptbat-ready")) {
    prop = provider->getProperty("ttbat-phys-addr-base");
    paddr = *(u32*)prop->bytes << 14;
    desc = IOMemoryDescriptor::withPhysicalAddress(paddr, page_size, 3);
} else {
    desc = IOBufferMemoryDescriptor::withOptions(...);
}
```

То есть AGX сам создаёт дескриптор над TTBAT, но paddr берётся из SecureDT,
а не из userland. Это kernel-owned дескриптор.

---

## 4. IOGPU: таблица селекторов

`IOGPUDeviceUserClient` dispatch table:

- table A: `0xfffffff007fea200`, 56 entries, stride 0x18;
- table B (privileged): `0xfffffff007fea740`.

`externalMethod` — `0xfffffff00994a1dc`:

```c
if (client+0x100 == 0) return 0xe00002d8;
if (selector > 0x37) return 0xe00002c2;
if (structureInput == NULL) return 0xe00002c2;
```

`newUserClient` — `0xfffffff00994a38c`, принимает **только type 0**.

Ключевые селекторы:

| sel | handler | in | out | что |
|---|---|---|---|---|
| 0 | `0x99947330` | — | 0x40 | info |
| 1 | `0x99947444` | — | 0x40 | **IOUAT leak** |
| 6 | `0x999476c0` | size == `dev+0x4f`, ≥0x408 | 0x10 | `s_new_command_queue` |
| 8 | `0x99947a58` | >0x57, variable | variable | `s_new_resource` |
| 25 | `0x99947de8` | 4 scalar + variable | 1 scalar | `s_submit_command_buffers` |
| 45 | `0x99948af4` | 1 scalar + variable | — | `s_submit_io_commands` |

`sel 1`:

```c
memcpy(user_out, *(provider+0x1e8), 0x40);
```

`provider+0x1e8 = device+0x548 = [0xfffffff00add7728]` — firmware IOUAT.
Первый qword — PAC-подписанная vtable `0xfffffff007c67f18`, второй — 1.

Формула:

```c
slide = ((q0 & 0xffffffff) - 0x07c67f18) & 0xffffffff;
kernel_text = 0xfffffff007004000 + slide;
```

---

## 5. Возможные утечки

| источник | что даёт | статус |
|---|---|---|
| IOGPU sel 1 | KASLR slide + поля IOUAT | не проверено на устройстве |
| AGX sel 2/4/5 | user VA AGX shared-страниц | не kernel leak |
| IOSurfaceRoot sel 4 | чужая/системная surface | не проверено; потенциальный sandbox escape |
| IOSurfaceRoot sel 7 | surface из address range | kernel VA должен падать, но проверяется |
| `gRegistryRoot` | kernel base (newjail CVE) | не проверено на 24B115 |
| AIO `kn_sdata` | kernel heap | не проверено |
| m2scaler diag | KVA | не проверено |
| AGX telemetry strings | `kern.sptm.event_counters.*` | не leak |

---

## 6. paddr: что уже закрыто

| путь | почему не paddr |
|---|---|
| `AppleM2ScalerCSCDriver` sel7/8/9 | `[client+0x130]` = owningTask → virtual64 |
| `IOSurfaceAddress` / sel7 | `FUN_9c2200c` проверяет `mach_vm_region` в task клиента |
| `IOGPU` sel8 type 0/0x80 | `owningTask`; physical branch требует `dev+0x1fc & 0x80 == 0` (UAT disabled) |
| `AGXSecureGart` | secure descriptor, не user paddr |
| `IOUAT::doMap` | paddr из дескриптора, не аргумент |
| `withAddressRange` task=0 | только kernel clients / UAT-disabled |
| `IOSurface` task=NULL sites | kernel-owned (IOPCIFamily, DCP, backend) |

Вывод: user-reachable paddr-примитива в 27.2 RC **не найдено**. Нужен
kernel-баг или dev-kext.

---

## 7. Полная цепочка (теория)

### Вариант A — userland

```
[app]
  0. leak: IOGPU sel 1 -> slide
  1. kernel bug -> kernel R/W
  2. fake IOMemoryDescriptor {pa=0x04D00000, len=0x20000}
  3. call IOUAT::doMap(fwIOUAT, desc, va, len, opts)
  4. PPL MAP_BEGIN -> MAP_CONTINUE -> skip FTE -> PTE
  5. TTBAT writable
  6. write PTE: GPU VA -> arbitrary PA
  7. GPU job -> DMA read/write
```

### Вариант B — kext PoC

```
[kext]
  1. find IOUAT object [0xadd7728 + slide]
  2. IOMemoryDescriptor::withPhysicalAddress(0x04D00000, 0x20000, 3)
  3. IOUAT::doMap(obj, desc, va, len, opts)
  4. getPageTableEntry(va) -> PTE
  5. verify no panic 0x4000012 and PTE has paddr 0x04D00000
```

Вариант B не является sandbox escape, но это честный PoC SPTM-бага.

---

## 8. Что именно нужно для Apple

1. **SPTM PoC** (kext): показать, что `MAP_CONTINUE` пишет PTE на TTBAT
   без `validate_fte`, и что это даёт writable-маппинг.
2. **Kernel bug** (app): показать, как из песочницы получить paddr-дескриптор
   или kernel R/W.
3. **Full chain**: app → kernel → SPTM → GPU DMA.

Без (2) отчёт будет неполным. Публичные PE/SPTM bypass на 27.2 мертвы.

---

## 9. Ограничения

- Все адреса — unslid VA; на устройстве нужен slide.
- `gpu-region-base = 0x04D00000` — кандидат, не runtime-подтверждён.
- `ttbat-phys-addr-base` в публичном DT отсутствует.
- IOGPU sel 1, sel 6, sel 8, IOSurface sel 4/7 на устройстве не проверены.
- Kext PoC требует dev/jailbroken устройство и может паниковать.
- Это теория, а не готовый exploit.
