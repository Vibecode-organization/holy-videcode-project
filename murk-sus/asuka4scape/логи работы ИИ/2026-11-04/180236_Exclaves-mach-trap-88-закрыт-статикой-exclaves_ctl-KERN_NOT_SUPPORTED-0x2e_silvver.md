---
title: Exclaves (mach trap 88) закрыт статикой: exclaves_ctl = KERN_NOT_SUPPORTED (0x2e) на 24B115 / iPhone14,7
agent: silvver
created: 2026-11-04 18:02:36
tags: kaslr, exclaves, mach-trap-88, 24B115, static, negative, mig-866900, task-2
---

# Exclaves (mach trap 88) закрыт статикой: exclaves_ctl = KERN_NOT_SUPPORTED (0x2e) на 24B115 / iPhone14,7

**Кратко:** Первый из трёх открытых входов KASLR (exclaves_ctl, mach trap 88) закрыт без устройства и без Ghidra: адрес входа 0xfffffff00a21347c в кернелкэше 24B115 указывает на 4-инструкционный стаб (bti c; mov w0,#0x2e; ret), т.е. trap возвращает KERN_NOT_SUPPORTED и никакой ядерной информации не отдаёт. Проверено по распакованному kernelcache.27.2RC.24B115.iphone14b из архива (VA→offset 0x320f47c), валидность маппинга подтверждена контрольным trap 89 (mach_timebase_info). Попутно разобраны три рутины MIG 866900: наружу kernel VA не отдают.

## Target
iOS 27.2 RC (24B115), iPhone14,7 (base iPhone 14), kernelcache `02_KERNEL/diff_267_272/kernelcache.27.2RC.24B115.iphone14b`
(67239936 B, `MH_MAGIC_64`, cputype arm64e, уже распакованный, не im4p).
Дедуп 24B115 ≡ 24B119 по кодовым сегментам (report id 1) — вывод переносится и на 24B119.

## Component
mach trap table, trap 88 `exclaves_ctl` (munge `0xfffffff00a3baa08`, nargs=8),
плюс для контекста MIG-подсистема 866900 (`SubsystemStart(866900) start=866900 end=866903`, 3 рутины).

## Primitive
Отрицательный результат: примитива нет. `exclaves_ctl` на этой сборке — заглушка, возвращающая
`KERN_NOT_SUPPORTED` (46 / 0x2e) до любого копирования в user-буфер.

## Evidence
Карта сегментов (из заголовка ядра):

```
__TEXT         va=0xfffffff007004000 off=0x0
__PRELINK_TEXT va=0xfffffff00700c000 off=0x8000
__DATA_CONST   va=0xfffffff007bb8000 off=0xbb4000
__TEXT_EXEC    va=0xfffffff00814c000 off=0x1148000  size=0x2924000
```

VA→file offset: `off = 0x1148000 + (VA - 0xfffffff00814c000)`.

Адрес входа trap 88 из `02_KERNEL/mach_27.2.txt`: `0xfffffff00a21347c` → off **0x320f47c**.

Дизассемблер на этом оффсете:

```
0xfffffff00a21347c  bti      c
0xfffffff00a213480  mov      w0, #0x2e
0xfffffff00a213484  ret
0xfffffff00a213488  bti      c
0xfffffff00a21348c  mov      w0, #0x2e
0xfffffff00a213490  ret
...
```

Далее до `0xfffffff00a213554` идёт та же плитка стабов с шагом 0xc байт (bti c / mov w0,#0x2e / ret),
местами `mov x0,#0 / ret`. Реальный код начинается только с `0xfffffff00a213558`.

Контроль маппинга (иначе адресам нельзя верить): trap 89 `mach_timebase_info` @ `0xfffffff00a2072f0`
тоже в `__TEXT_EXEC` (off 0x32032f0) и выглядит как настоящая реализация —
`ldr x8,[..]; ldr x8,[x8,#8]; str x8,[sp,#8]; bl 0xfffffff00a38a690; retab`.
Значит таблица трапов и файл — одна и та же сборка, смещение верное.

## Reproduction
1. Взять `02_KERNEL/diff_267_272/kernelcache.27.2RC.24B115.iphone14b`.
2. `off = 0x1148000 + (0xfffffff00a21347c - 0xfffffff00814c000) = 0x320f47c`.
3. `aarch64-linux-gnu-objdump -D -b binary -m aarch64 --adjust-vma=0xfffffff00a21347c --start-address=0 --stop-address=0x24 kc115.bin`
   (или capstone 5.x, 30 инструкций вперёд по этому оффсету).
4. Увидеть `mov w0,#0x2e; ret`.
5. Контроль: то же для `0xfffffff00a2072f0` (trap 89) — там настоящий код, а не стаб.

Скрипты: `agents/silvver/scripts/fetchwin.py` (тянет окно через MCP `read_research` по offset+length и дизассемблирует),
`agents/silvver/scripts/mparse.py` (резолв сегментов kernelcache).

## Reliability
Детерминированно: статический дизассемблер, один файл, один оффсет, прогонов не требуется.
Ограничение: вывод верен для 24B115 (iPhone14,7). Для другой сборки адрес пересчитать по `mach_27.x.txt`.

## Impact
Один из трёх «непроверенных входов» из report id 2 (exclaves trap 88) закрыт как канал KASLR:
ни copyout, ни возврата указателя, trap недоступен по существу.

Попутно по MIG 866900 (`mig_27.2.txt`: 866900 argc=4 reply=52, 866901 argc=2 reply=52, 866902 argc=3 reply=1072):
- 866900/866901 пишут в reply одинаковую 8-байтную константу из `0xfffffff00700db18` = `0x0000000000110000` (не указатель);
- 866900 дополнительно кладёт PAC-подписанный (`pacda`, ctx = адрес поля) указатель в reply+0x24 — это внутренний
  дескриптор сообщения, который `ipc_kmsg_copyout` превращает в имя порта, наружу как VA не уходит;
- 866902 пишет в reply `0x400` и размер — тоже без kernel VA.

## Next step
1. AGX/IOGPU shared page — externalMethod-таблицы (тем же оффсетным методом или `ghidra_find_external_methods.py`).
2. Для 866900 — дожать reply+0x24 до `ipc_kmsg_copyout`, чтобы формально закрыть и его.
3. Пересобрать `scripts/kaslr_probe_v2.m` без exclaves-проверки (бессмысленна) и без IOSurface sel0.

## Confidence
high — прямой дизассемблер входа trap 88 плюс контрольный trap 89 на том же файле.
Опровергнет: если на 24B115 trap 88 ведёт не в `0xa21347c` (тогда неверна `mach_27.2.txt`),
либо если в ядре есть рантайм-патч таблицы трапов (следов такого механизма не найдено).
