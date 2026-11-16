# KRWProbe 1.0 — прямой вызов IOSurfaceRootUserClient

Статус: собрано, IPA проверен. Изменения — только в `probe/KRWProbe/main.m`
и `probe/KRWProbe/Info.plist`; `reports/DISPATCHER_RE.md` не менялся.

## Что добавлено

Кнопка **CREATE  IOSurface sel0 -> 2,3,9,10,11,1** (зелёная, нижний ряд).
Она открывает `IOSurfaceRoot` (`IOServiceOpen`, тип 0), затем:

1. sel 0 — создаёт поверхность 64x64 BGRA из XML-plist;
2. sel 2, 3, 9, 10, 11, 1 — с точными формами из `reports/DISPATCHER_RE.md`.

Все прежние кнопки (RUN SAFE / AGGR / FUZZ 50k / STOP / RACE 30s / FUZZ UC /
SCAN SEL) работают как раньше; layout сдвинут, чтобы освободить пятый ряд.

## Смещение surface ID в IOSurfaceInfo (0xc68)

Источник: `dumps/ios272/fn_fffffff009c2c18c.c` (заполнение info) и
`dumps/ios272/fn_fffffff009c3b3ac.c` (sel 2).

```c
*(undefined4 *)(param_2 + 3) = *(undefined4 *)(param_1 + 0x38);
```

`param_2` — `undefined8 *`, значит `3 * 8 = 0x18`. **ID читается по смещению
`0x18`** (u32 little-endian), значение берётся из `*(u32 *)(surface + 0x38)`.

Полная раскладка заголовка, использованная в логе:

| смещение | поле | подтверждение в дампе |
|---|---|---|
| +0x18 | **surface ID (u32)** | `*(undefined4 *)(param_2 + 3)` |
| +0x58 | plane count (u32) | `*(uint *)(param_2 + 0xb) = uVar2` |
| +0x5c | флаг клиента (u8) | `*(uint *)((long)param_2 + 0x5c)` |
| +0x64 | pixel format (u32) | `*(undefined4 *)((long)param_2 + 100)` |
| +0x68 | use count (u32) | `*(undefined4 *)(param_2 + 0xd)`; sel 2 перезаписывает `local_5c` |
| +0x88 | planes[0], шаг 0x98, максимум 20 | `puVar14 = param_2 + 0x11` (0x88); `puVar14 + i*0x13` (0x13*8 = 0x98) |

0x88 + 20×0x98 = 0xc68 — совпадает с проверкой `checkStructureOutputSize`.

## Точные аргументы вызовов

| sel | scalarIn | structureInput | scalarOut | structureOutput | код |
|---|---|---|---|---|---|
| 0 | 1 × u64 `{0}` (parent id; hi32 = 0) | XML-plist свойств + завершающий NUL (0x18a = 394 байта) | 0 (`NULL,NULL`) | 0xc68 | `out+0x18` → id |
| 2 | 0 | 0xc: `{u32 id; u32 flags=0; u32 pad=0}` | 0 | 0xc68 | info + use count `+0x68` |
| 3 | 0 | 0xc: `{u32 id; u32 arg=0; u32 pad=0}` | 0 | 4 | счётчик в ответе |
| 9 | 0 | 0xc + XML-plist `[value, key]` (0x6b), key = `OSString` | 0 | 4 | `KRWProbeValue = 1` |
| 10 | 0 | 0xc + C-строка ключа с NUL (`0x1a` байт) | 0 | 0x800 (var, ≥0xd) | сериализованное значение в `out+0xc` |
| 11 | 0 | 0xc + C-строка ключа с NUL | 0 | 4 | remove `KRWProbeValue` |
| 1 | 1 × u64 `{id}` | — | 0 | — | release |

Важные детали, без которых возвращался бы `0xe00002c2`:

- **sel 2 и sel 3 требуют ровно `0xc` байт structIn**, хотя логическая структура
  — 8 байт; в коде добавлен явный `uint32_t pad`. В `fn_fffffff009c3b3ac.c` /
  `fn_fffffff009c3b58c.c` стоит жёсткая проверка `param_4 != 0xc`.
- **XML для sel 0 обязан заканчиваться NUL**: в `dumps/fn_fffffff00a8d8754.c`
  XML-ветка выбирается только при `param_1[param_2 - 1] == '\0'` (иначе
  `OSUnserialize` возвращает NULL → `0xe00002c2`). Поэтому передаётся
  `strlen(xml) + 1` байт.
- sel 0: `scalarInput[0] >> 32` обязан быть 0 (проверка в
  `fn_fffffff009c3888c.c`), поэтому parent id = 0.
- sel 9/11: structIn строго `> 0xc`; ключ/plist начинаются с `+0xc`.
- sel 10: structIn `>= 0xd`, последний байт — NUL; structOut `>= 0xd`,
  размер выхода = `0xc + len(serialized)`.
- sel 4..8 не вызываются (gpu-таблица отдаёт `0xe00002e2`).

Создаваемая поверхность (XML, ровно 4 ключа, как в задании):

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN"
 "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0"><dict>
  <key>IOSurfaceWidth</key><integer>64</integer>
  <key>IOSurfaceHeight</key><integer>64</integer>
  <key>IOSurfaceBytesPerElement</key><integer>4</integer>
  <key>IOSurfacePixelFormat</key><integer>1111970369</integer>
</dict></plist>
```

`1111970369 = 0x42475241` (`'BGRA'`).

Что логирует кнопка: `kr` каждого селектора, `structOut` после sel 0,
id по `+0x18`, planes/pixfmt/flag/usecnt, hex-дамп первых 0x90 байт info,
а для sel 10 — hex сериализованного значения из `out+0xc`.

## Версия

- `Info.plist`: `CFBundleShortVersionString` = **1.0**, `CFBundleVersion` = **10**,
  `CFBundleDisplayName` = **KRWProbe 1.0**.
- `main.m`: заголовок файла и баннер CREATE — `KRWProbe 1.0`; стартовый текст
  text view — `KRWProbe 1.0 — idle`.

## Сборка и проверка

Theos не принимает путь с пробелами, поэтому проект скопирован в
`/tmp/opencode/krwprobe` и собран оттуда:

```
make ipa          # Theos 2.x, iphone:clang:latest:14.0, arm64
cp KRWProbe.ipa /home/.../probe/out/KRWProbe.ipa
```

Результат: `probe/out/KRWProbe.ipa`, 24724 байта. Содержимое:

```
Payload/
Payload/KRWProbe.app/
Payload/KRWProbe.app/KRWProbe        (Mach-O 64-bit arm64, 119360 байт)
Payload/KRWProbe.app/Info.plist      (CFBundleShortVersionString = 1.0)
```

Проверено: в бинарнике присутствуют строки `CREATE  IOSurface sel0 -> 2,3,9,10,11,1`
и `=== KRWProbe 1.0 CREATE (IOSurfaceRootUserClient) ===`; подпись ad-hoc
(`ldid`) с пустым `entitlements.plist` на месте; `LC_BUILD_VERSION`
platform=ios, minos=14.0.

Запуск на устройстве не выполнялся (нет доступа к телефону из этой сессии) —
все строки лога являются реальными кодами возврата, получаемыми на девайсе.
