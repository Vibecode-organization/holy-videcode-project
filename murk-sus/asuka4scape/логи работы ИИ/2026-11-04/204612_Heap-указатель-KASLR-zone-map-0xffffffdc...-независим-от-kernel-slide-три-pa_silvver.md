---
title: Heap-указатель ≠ KASLR: zone map 0xffffffdc... независим от kernel slide (три panic-лога, iPhone14,7/15,4/17,1)
agent: silvver
created: 2026-11-04 20:46:12
tags: kaslr, heap, zone-map, panic-log, iogpu, 24B115, 27.0, hard-negative, task-2
---

# Heap-указатель ≠ KASLR: zone map 0xffffffdc... независим от kernel slide (три panic-лога, iPhone14,7/15,4/17,1)

**Кратко:** Проверил по реальным panic-логам, кодирует ли адрес heap-объекта kernel slide. Нет: во всех трёх логах (iPhone14,7 / 27.0 24A5430a, iPhone15,4 / 27.0.1 24A446, iPhone17,1 / 18.6.2 22G100) kernel text base = 0xfffffff007004000 + Kernel slide (арифметика сходится точно), а zone map всегда лежит в регионе 0xffffffdc........ (0xffffffdc02398000 / 0xffffffdc006b4000 / 0xffffffdc040bc000) и с slide не коррелирует: слайды 0x36380000 / 0x47f08000 / 0x43474000 дают зоны 0x02398000 / 0x006b4000 / 0x040bc000. Heap-указатели в паниках — 0xffffffdd.../0xffffffe0..., никогда не 0xfffffff0.... Значит утечки IOGPU sel 0 ([dev+0x208]) и sel 4 ([client+0xe8]) — это heap-указатели, и KASLR они не ломают; для slide нужен указатель в образ ядра (0xfffffff0...), например PAC-подписанный vtable-указатель объекта. Это закрывает IOGPU sel 0/4 как путь к KASLR и объясняет, какой тип утечки искать дальше.

## Target
Panic-логи из архива:
- `08_CRASH_LOGS/panic/panic-full-2026-09-05-230934.0002.txt` — iPhone14,7, iOS 27.0 (24A5430a), xnu-13432.2.10~5, T8110.
- `08_CRASH_LOGS/panic/panic-full-2026-11-02-231652.0002.ips` — iPhone15,4, iOS 27.0.1 (24A446), T8120.
- `08_CRASH_LOGS/panic/panic-full-2026-09-08-175625.0002.ips` — iPhone17,1, iOS 18.6.2 (22G100), T8140.
Целевая сборка 27.2 RC 24B115 (iPhone14,7) своих panic-логов в архиве не имеет, но механизм раскладки одинаковый на 27.0/27.0.1.

## Component
Раскладка kernel VA: kernel image (text/data) vs kalloc zone map; оценка пригодности heap-утечек для KASLR.

## Primitive
Hard negative: kernel heap pointer (IOGPU sel 0 `[dev+0x208]`, sel 4 `[client+0xe8]`) не содержит kernel slide и не является KASLR-утечкой.

## Evidence
| Устройство | ОС | Kernel slide | Kernel text base | Zone map base |
|---|---|---|---|---|
| iPhone14,7 | 27.0 (24A5430a) | `0x36380000` | `0xfffffff03d384000` | `0xffffffdc02398000` |
| iPhone15,4 | 27.0.1 (24A446) | `0x47f08000` | `0xfffffff04ef0c000` | `0xffffffdc006b4000` |
| iPhone17,1 | 18.6.2 (22G100) | `0x43474000` | `0xfffffff04a478000` | `0xffffffdc040bc000` |

Проверка арифметики (все три сходятся):
```
0xfffffff03d384000 - 0x36380000 = 0xfffffff007004000
0xfffffff04ef0c000 - 0x47f08000 = 0xfffffff007004000
0xfffffff04a478000 - 0x43474000 = 0xfffffff007004000
```
То есть **text base = 0xfffffff007004000 + slide** — наша unslid-база подтверждена на реальных загрузках.

Зоны и слайд независимы:
```
slide 0x36380000 -> zone 0xffffffdc02398000
slide 0x47f08000 -> zone 0xffffffdc006b4000
slide 0x43474000 -> zone 0xffffffdc040bc000
```
Корреляции нет; zone map всегда в `0xffffffdc........`, kernel image — в `0xfffffff0........`.
Примеры heap-указателей из тех же паник: `0xffffffdd36e91d80`, `0xffffffde1d4b9a30`, `0xffffffdf005b3300`, `0xffffffe0cee6fec4` — ни один не попадает в диапазон образа ядра.

## Reproduction
1. Открыть panic-файл (это первые ~8 КБ: header + `panicString`).
2. Взять строки `Kernel slide:`, `Kernel text base:`, `Zone info:` → `Zone map:`.
3. Вычесть slide из text base — получается `0xfffffff007004000`.

## Reliability
Три независимые загрузки на трёх разных SoC/ОС; арифметика детерминирована. Ограничение: для 27.2/24B115 прямого лога нет, но 27.0 и 27.0.1 дают одинаковую картину.

## Impact
- IOGPU sel 0/4 (heap-указатели) окончательно закрыты как путь к KASLR — device-тест для них больше не нужен.
- Зафиксировано, какой именно указатель нужен: в диапазон `0xfffffff0...` (kernel image). Для PAC-подписанного vtable-указателя низкие 32 бита сохраняют смещение, поэтому такой слив тоже годится.
- Сэкономлено время: не надо пытаться выводить slide из kalloc-адресов.

## Next step
1. Искать утечку указателя **образа ядра**, а не heap: содержимое объекта (первый qword = PAC'd vtable) или статическая структура.
2. Дожать IOGPU sel 1 (`memcpy` 0x40 байт из `[dev+0x1e8]`, `0x99947444` → `0x99984e4c`): если источник — OSObject, первые 8 байт дадут PAC-подписанный vtable → text leak. Класс объекта пока не установлен.
3. Проверить AGX-копии `0x819d254` (из `[x0+0x120]→[+0x48]+0x18000`) и `0x819d57c` (из `[x0+0xf8]+0x3b0..0x440`) — если в копируемых полях есть указатели образа, это готовый лик.

## Confidence
high — арифметика и независимость zone map от slide.
medium — что среди остальных селекторов IOGPU нет утечки образа (проверены только struct-output обработчики; скалярные выходы не аудированы полностью).
