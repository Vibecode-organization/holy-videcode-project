---
title: SPTM 24B115 (T8110) = post-b3: фикс UAT/TLB-гонки в сборке есть; живой остаётся только путь через контроль paddr
agent: silvver
created: 2026-11-05 15:40:25
tags: sptm, ios-27.2, 24b115, t8110, uat, ttbat, tlbi, hard-negative, task-4
---

# SPTM 24B115 (T8110) = post-b3: фикс UAT/TLB-гонки в сборке есть; живой остаётся только путь через контроль paddr

**Кратко:** Проверил наш SPTM 27.2 (02_KERNEL/sptm/27.2/sptm.macho, 1 212 448 B, T8110) на наличие фикса, который Apple добавил в 27.2b3 и который публично разобран для T8150 (github IvanIVGrozny/iOS27.0.1-SPTM-Research): 27.0.1 и 27.2b1 имеют один SPTM-820.40.18, а b3 (820.40.23) добавляет uat_dekker-гейт, uat_sync_outer_tlb_sapt_flush, verify-gmmu-tlbis-at-sync / gmmu-tlbi-verification-reg/bit и 24 новых dmb ish. В нашем бинаре эти ключи не просто присутствуют — они разбираются в UAT Global init (FUN_fffffff0270afb68): instance+0x81 = verify-gmmu-tlbis-at-sync, +0x88 = VA регистра верификации, +0x90 = бит, и рядом инициализируется gate-байт +0x91 = 0 (ровно тот, что в публичном разборе b3). Плюс размер Mach-O 27.2 больше 27.0.1 T8110 на 16 384 B. Вывод: 24B115 — post-b3, UAT/TLB-race класс на нашей сборке закрыт, и это согласуется с предупреждением opa334 не обновляться на 27.2. Из SPTM-поверхности остаётся только путь «произвольный paddr в UAT MAP_BEGIN» (скип проверки для paddr == gpu-region-base), а он упирается в kernel-примитив, которого у нас нет: device-тест показал, что AGX/IOGPU-селекторы из песочницы отдают 0xe00002c2, IOSurfaceAddress трактуется как virtual64, DART — not privileged.

## Target
iOS 27.2 RC, build **24B115**, iPhone14,7 (**T8110**), `xnu-13432.42.328/RELEASE_ARM64_T8110`.
SPTM: `02_KERNEL/sptm/27.2/sptm.macho` (1 212 448 B; sha256 `a29fbc4f54c10888e25372a47410669b9857787adbee4feac3af37f15701d083` по `02_KERNEL/sptm_272_bypass/ОТЧЁТ.md`), версия **SPTM-820.40.24**.
Для сравнения: `02_KERNEL/sptm/27.0.1/sptm_27.0.1_t8110.macho` = 1 196 064 B.

## Component
SPTM, UAT Global init `FUN_fffffff0270afb68` (разбор — `02_KERNEL/sptm_gpu.log`, Ghidra-проект `/home/femboychik/work/gh/sptm`, файл `sptm_27.2_24B119.macho`, MD5 `f6b53887fb7ad9ed4dea23475b64e0fa`).

## Primitive
Hard negative: **фикс UAT/TLB-гонки, добавленный Apple в 27.2b3, в нашей 24B115 присутствует**. Значит класс «гонка PTE-write ↔ GMMU TLBI» на нашем устройстве закрыт, и SPTM-поверхность сводится к единственному пути — контроль `paddr` на входе UAT MAP_BEGIN.

## Evidence

### 1. Какие ключи читает наш SPTM (декомпиляция init)
```
"issue-gmmu-tlbis-at-retype"      -> instance+0x80   (bool)
"verify-gmmu-tlbis-at-sync"       -> instance+0x81   (bool)
"gmmu-tlbi-verification-reg"      -> instance+0x88   (VA: (reg & 0x3ff8) + map(reg & ~0x3fff))
"gmmu-tlbi-verification-bit"      -> instance+0x90   (byte, 0..63)
...
*(instance + 0x91) = 0            ; gate-байт
```
Ровно эти строки публичный разбор b3 перечисляет как **новые** (в 27.2b1/27.0.1 их нет):
`verify-gmmu-tlbis-at-sync`, `gmmu-tlbis-at-retype`, `gmmu-tlbi-verification-reg`, `gmmu-tlbi-verification-bit`,
`uat_sync_outer_tlb_sapt_flush`, `uat_dekker_lock/gate_lock`, `VIOLATION_T8110_DART_UNGANG_GAPF_RACE`,
`Failed to verify TLBI`, отказ `relaxed_rw_protections` + `allow_pte_remap`.

Gate-байт `+0x91` — тот самый, что в b3 ставится/снимается вокруг критической секции; в нашей сборке он
инициализируется в `UAT Global`, т.е. код-путь присутствует целиком, а не только строка.

### 2. Размеры подтверждают реальное изменение между релизами
| Сборка | Файл | Размер |
|---|---|---|
| 27.0.1 / T8110 | `sptm_27.0.1_t8110.macho` | 1 196 064 B |
| 27.2 RC 24B115 / T8110 | `sptm/27.2/sptm.macho` | 1 212 448 B (+16 384 B) |

Публично: 27.0.1 (24A446) и 27.2b1 (24B5084k) — **байт-идентичный** SPTM (820.40.18);
весь дельта-период — b1 → b3 (820.40.23). Наш 24B115 — 820.40.24, т.е. не раньше b3.

### 3. Что это закрывает
В b1 окно было: `write PTE` → (GMMU TLBI успевает) → `issue TLBI`. В b3 добавлены
`dmb ish` (3→27), per-CPU dekker-гейт и опциональная верификация TLBI. В нашей сборке
присутствует и гейт-байт, и верификация, значит окно закрыто тем же протоколом.

## Reproduction
1. Открыть Ghidra-проект `work/gh/sptm` → `sptm_27.2_24B119.macho` → `FUN_fffffff0270afb68`.
2. Либо строковый срез бинаря:
```python
d=open('02_KERNEL/sptm/27.2/sptm.macho','rb').read()
for s in (b'verify-gmmu-tlbis-at-sync', b'gmmu-tlbi-verification-reg',
          b'gmmu-tlbi-verification-bit', b'issue-gmmu-tlbis-at-retype'):
    print(s, d.find(s))
```
3. Сверить с публичным списком новых строк b3 (репозиторий IvanIVGrozny, §3).

## Reliability
Статика по единственному артефакту сборки; вывод «фикс есть» держится сразу на четырёх
независимых признаках (ключи devtree, gate-байт +0x91, поле +0x88/0x90, рост размера).
Ограничение: прямого бинарного диффа b3-сборки T8150 с нашей T8110 нет — сравнение по
структуре, а не по байтам.

## Impact
- TLBI-гонка как класс снимается с рассмотрения на 24B115: искать её на нашем устройстве бессмысленно.
- Согласуется с публичным предупреждением opa334 (27.2b3 закрыл SPTM-байпас) — наш RC уже после фикса.
- Единственный оставшийся SPTM-путь — `paddr == gpu-region-base` в UAT MAP_BEGIN (скип проверки прав,
  `FUN_fffffff0270adf30`, `instance+0x68`). Для него нужен произвольный paddr, т.е. kernel/IOGPU-примитив.
- Device-тест 24B115 закрывает песочные входы: AGX/IOGPU селекторы → `0xe00002c2`,
  `IOSurfaceAddress` → virtual64, `AppleT8110DART` → not privileged.

## Next step
1. Не тратить время на TLB/SPTM-гонку; переключиться на источники **paddr**:
   `AppleM2ScalerCSCDriver` (единственный user-reachable kext, который открывается из песочницы),
   DMA-пути IOGPU/AGX, `IOMemoryDescriptor` с `task == NULL`.
2. Отдельно проверить расхождение по GPU: мой кандидат на KASLR (IOGPU sel 1, отчёт id 9)
   относится к `IOGPUDeviceUserClient` (`com.apple.iokit.IOGPUFamily`), а device-тест
   работал с `AGXAcceleratorG14P`; `IOGPUDevice` в пробе вообще «absent». Доступность
   IOGPUDevice-клиента из песочницы до сих пор не проверена — это следующий device-шаг.
3. Зафиксировать в отчёте по KASLR, что путь через AGX-селекторы закрыт энтитлментом
   (иначе отчёт id 9 переоценивает доступность).

## Confidence
high — присутствие b3-протокола в бинаре (строки + gate-байт + поля + размер).
medium — что в SPTM не осталось других пользовательски достижимых классов, кроме paddr-пути.
Опровергнет: дифф нашего SPTM с 27.0.1 T8110, где этих полей нет; либо device-тест,
показывающий, что AGX/IOGPU-селекторы всё-таки доступны без энтитлмента.
