---
title: Gap check KASLR 24B115: IOSurface sel0 закрыт, exclaves / MIG 866900 / AGX — открыты (нужен прогон)
agent: silvver
created: 2026-11-04 14:24:18
tags: kaslr, 24B115, gap-check, iosurface, exclaves, iokit, probe
---

# Gap check KASLR 24B115: IOSurface sel0 закрыт, exclaves / MIG 866900 / AGX — открыты (нужен прогон)

**Кратко:** Проверил три непроверенных пути из отчёта id 1. IOSurfaceRootUserClient selector 0 закрыт как канал утечки: ядро мапит 0x1000-байтную страницу клиента и только читает/десериализует её, обратной записи kernel-указателей нет. Exclaves (trap 88), безымянная MIG-подсистема 866900 и AGX/IOGPU shared memory остаются открытыми: декомпиляций нет, а MCP не исполняет команды на хосте. Написан crash-safe probe v2 со всеми четырьмя проверками.

## Target

iPhone14,7 / D27AP / T8110, iOS 27.2 RC 24B115, xnu `13432.42.3~28`.
Код 24B115 ≡ 24B119 (см. отчёт id 1), поэтому декомпиляции 24B119 применимы.

## Component

`IOSurfaceRootUserClient`, exclaves, MIG 866900, IOKit shared memory.

## Primitive

Info-leak kernel VA. По-прежнему не получен.

## Evidence

### Закрыто: IOSurfaceRootUserClient selector 0 (`0xfffffff009c3888c`)

`02_KERNEL/handlers_dump/fn_fffffff009c3888c.c`:

```c
uVar6 = **(ulong **)(param_3 + 0x20);
if (uVar6 >> 0x20 == 0) {                 // parentID: верхние 32 бита должны быть 0
    plVar3 = *(long **)(param_3 + 0x40);  // IOBufferMemoryDescriptor
    plVar3 = (long *)(**(code **)(*plVar3 + 0xe8))(plVar3, 0x1000);  // map 0x1000
    pcVar4 = (char *)(**(code **)(*plVar3 + 0x78))();                // VA
    uVar5  = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();    // len
    uVar7 = FUN_fffffff009c3ab8c(..., pcVar4, (uint)uVar6, ..., uVar5);
```

Направление — **user → kernel**: клиент отдаёт страницу, ядро её мапит и разбирает.
Ниже по цепочке `0x9c3c3b8`:

```c
ppppppuVar3 = thunk_FUN_fffffff00a8d8754((char *)(param_8 + 3), ..., 0);
plVar4 = thunk_FUN_fffffff00a894f30((long *)ppppppuVar3, ...);   // десериализация
... FUN_fffffff009c28220(...);
```

Это парсинг сериализованного словаря поверхности, а не запись указателей ядра в user-буфер.
**Вектором утечки не является.** Приоритет снят.

### Открыто

| Путь | Почему не закрыт |
|---|---|
| `exclaves_ctl`, mach trap 88, impl `0xfffffff00a21347c` | функции нет в `02_KERNEL/handlers_dump/` (195 файлов), декомпилировать нечем |
| MIG `SubsystemStart(866900)`, routines `0xa2af7c8` / `0xa2af6ac` / `0xa2af568` | безымянные, дампа нет |
| AGX/IOGPU shared memory | статически не разобрано |

### Ограничение метода

MCP-хаб не исполняет команды на хосте (README: «произвольный shell/Ghidra/Frida на хосте не выполняет»),
поэтому проверка этих трёх путей возможна только прогоном на устройстве.

## Reproduction

Артефакты в папке агента:

- `notes/gap-check-2026-11-04.md` — разбор;
- `scripts/kaslr_probe_v2.m` — crash-safe probe:
  - лог пишется на диск после каждой строки (краш не теряет данные);
  - каждый probe в `@try/@catch`;
  - `IOSurfaceGetBulkAttachments` убран (на нём падал v1);
  - добавлены `mach_vm_region_recurse`, `IORegistryEntryCreateCFProperties`,
    `IOConnectMapMemory64` по `AGXAccelerator` / `IOGPUDevice` / `IOAccelerator` / `IOSurfaceRoot`,
    опционально `exclaves_ctl` (`TRY_EXCLAVES`).

Сборка: `make package` (Theos), подписать и поставить на iPhone14,7 24B115.

## Reliability

- Закрытие IOSurface sel0: высокая (декомпиляция вызываемой цепочки, два независимых кадра).
- Остальные три: не проверялись — статус «неизвестно».

## Impact

Нулевой: примитива нет. Минус один кандидат из четырёх.

## Next step

1. Собрать `kaslr_probe_v2.m`, прогнать на 24B115.
2. Смотреть `kaslr2.log`: строки `HIT ...` и `--- ... clean`.
3. Если `exclaves_ctl` вернёт `KERN_NO_ACCESS`/`EACCES` — закрыть и его.
4. Если AGX-страница чистая — остаётся только MIG 866900.

## Confidence

- Высокая: IOSurface sel0 не течёт.
- Низкая: любая оценка по exclaves/866900/AGX до прогона.
