# UAF / double-release в работе с `IOMemoryDescriptor` / `IOMemoryMap`
## `IOSurfaceRootUserClient`, iOS 27.2 (24B115)

Цель: найти UAF или двойной `release` дескриптора/маппинга, достижимый из песочницы без энтайтлментов.

Адреса — короткая форма (`0x9c38b2c`), полный VA = `0xfffffff000000000 | addr`.
`__TEXT_EXEC` fileoff = `va - 0xfffffff007004000`; `__DATA_CONST` fileoff = `0xbb4000 + (va - 0xfffffff007bb8000)`.
Всё ниже — из самого kernelcache, без символьной таблицы (её в 24B115 нет: `nsyms = 0`).

---

## 0. Короткий вывод

| Вопрос задания | Ответ |
|---|---|
| 1. Двойной `release` / утечка | **Двойного release нет.** Ни в одном из 9 дескрипторных селекторов, ни в error-путях. Утечки маппинга тоже нет |
| 2. Порядок `release` → использование данных | **Нарушений нет.** `getAddress`/`getLength` берутся до вызова реализации, `release` — после, данные после `release` не читаются |
| 3. Error-пути после частичной инициализации | **Корректны.** При отказе второго `createMapping` первый маппинг отпускается (sel10/sel26, ветки ниже) |
| 4. `0x28` vs `0x30` | **Не путается.** `0x28` = `release` всегда; `0x30` — другой метод, в teardown не используется |

Остаточные (не подтверждённые) риски — в разделе 5. Все они — OOB, а не UAF.

---

## 1. Таблица слотов vtable (выведена из call-site + discriminator)

| Слот | Disc | Метод | Класс объекта |
|---|---|---|---|
| `+0xe8` | `0x3ed6` | `map(IOOptionBits)` | `IOMemoryDescriptor` (`args+0x40` / `args+0x68`) |
| `+0x78` | `0x34f6` | `getAddress()` — **kernel VA** | `IOMemoryMap` (результат `map`) |
| `+0xb0` | `0xb392` | `getLength()` | **дескриптор**, не маппинг |
| `+0x28` | `0x3a87` | `release()` | любой `OSObject` |
| `+0x30` | `0x89a9` | инициализация/установка (1 аргумент) | — в teardown не встречается ни разу |

Опции: вход — `map(0x1000)` (`kIOMapReadOnly|kIOMapAnywhere`), выход — `map(0)` (rw).

Полный скан `blraa` по `0x9c30000..0x9c46000` — `out/vcall_scan.txt`.
Сайтов `map` (`0xe8/disc 0x3ed6`) в kext ровно **11**: sel0, sel9, sel10, sel11, sel24, sel26, sel46, sel47, sel48, sel54 и внутренний `0x9c3692c`. Скрытых маппингов нет.

---

## 2. Диспетчер и таблица

`getTargetAndMethodForIndex` @ `0x9c3ee10`:

```
0xfffffff009c3ee10: adrp x8, 0xfffffff008068000
0xfffffff009c3ee18: add  x8, x8, #0xb90        ; table = 0xfffffff008068b90
0xfffffff009c3ee1c: ldrb w9, [x0, #0x127]
0xfffffff009c3ee24: add  x10, x10, #0x4f0      ; restricted twin = 0xfffffff0080694f0
0xfffffff009c3ee2c: csel x3, x10, x8, ne
0xfffffff009c3ee30: mov  w4, #0x3c             ; 60 селекторов
```

Запись таблицы — **stride 0x28**: `{u64 action; u32 sIn; u32 strIn; u32 sOut; u32 strOut; 0x10 pad}`.
PAC-снятие: `VA = 0xfffffff007004000 + (action & 0x0FFFFFFF)`.
`strIn/strOut == 0xffffffff` = «MIG размер не проверяет» → это и есть дескрипторные селекторы.
Полная таблица 60/60 — `out/table_base.txt`; все «точки» из задания совпали с ней.

---

## 3. Таблица «взял → замапил → отпустил»

`args`: `0x30` structureInput, `0x38` structureInputSize, `0x40` structureInputDescriptor,
`0x48` scalarOutput, `0x58` structureOutput, `0x60` structureOutputSize, `0x68` structureOutputDescriptor,
`0x70` structureOutputDescriptorSize, `0x78` — поле вне известных, см. 5.3.

| sel | стаб | strIn/strOut | карта входа | addr | len | карта выхода | release (адреса) | вердикт |
|---|---|---|---|---|---|---|---|---|
| 0 | `0x9c3888c` | `-1` / `0xc68` | `@0x9c38920` opt `0x1000` | `@0x9c38944` | `@0x9c38968` (desc) | — | `0x9c38a00` (x19) | 1:1 ✔ |
| 9 | `0x9c38b2c` | `-1` / `4` | `@0x9c38b80` | `@0x9c38ba4` | `@0x9c38bc8` | — | `0x9c38c20` (x21) | 1:1 ✔ |
| 10 | `0x9c38c44` | `-1` / `-1` | `@0x9c38cc4` | `@0x9c38cec` | `@0x9c38d10` | `@0x9c38d44` opt `0` | out `0x9c38dbc` (x26), in `0x9c38e10` (x21) | 2:2 ✔ |
| 11 | `0x9c38e54` | `-1` / `4` | `@0x9c38ea8` | `@0x9c38ecc` | `@0x9c38ef0` | — | `0x9c38f48` (x21) | 1:1 ✔ |
| 19 | `0x9c390ac` | `-1` / `0` | **отказ**: `args+0x40 != 0 → 0xe00002bd` | | | | — | дескриптор запрещён |
| 24 | `0x9c392c0` | `-1` / `0` | `@0x9c39310` | `@0x9c39334` | `@0x9c39358` | — | `0x9c393ac` (x20) | 1:1 ✔ |
| 26 | `0x9c39448` | `-1` / `-1` | `@0x9c394c8` | `@0x9c394f0` | `@0x9c39514` | `@0x9c39548` opt `0` | out `0x9c395bc` (x26), in `0x9c39610` (x21) | 2:2 ✔ |
| 46 | `0x9c39a78` | `-1` / `0` | `@0x9c39aec` | `@0x9c39b10` | `@0x9c39b34` | — | `0x9c39b98` (x22) | 1:1 ✔ |
| 47 | `0x9c39bdc` | `-1` / `0` | `@0x9c39c2c` | `@0x9c39c50` | `@0x9c39c74` | — | `0x9c39cd0` (x20) | 1:1 ✔ |
| 48 | `0x9c39cf4` | `-1` / `0` | `@0x9c39d44` | `@0x9c39d68` | `@0x9c39d8c` | — | `0x9c39de8` (x20) | 1:1 ✔ |
| 50 | `0x9c39eb8` | `-1` / `0` | **отказ**: `args+0x40 != 0 → 0xe00002c2` | | | | — | дескриптор запрещён |
| 51 | `0x9c39eec` | `0` / `-1` | **отказ**: `args+0x68 != 0 → 0xe00002c2` | | | | — | out-дескриптор запрещён |
| 54 | `0x9c39f5c` | `-1` / `0` | `@0x9c39fac` | `@0x9c39fd0` | `@0x9c39ff4` | — | `0x9c3a048` (x20) | 1:1 ✔ |

Реализации: sel0 → `0x9c3ab8c`; sel9 → `0x9c3c3b8`; sel10 → `0x9c3c538`; sel11 → `0x9c3c9c0`;
sel24 → `0x9c3d560`; sel26 → `0x9c3f77c`; sel46 → `0x9c3e384`; sel47 → `0x9c3e570`; sel48 → `0x9c3e86c`;
sel54 → `0x9c3c7fc`.

### Канон (sel9, полный жизненный цикл)

```
0x9c38b58: ldr  x20, [x2, #0x58]        ; structureOutput
0x9c38b5c: ldr  x0,  [x2, #0x40]        ; <<< structureInputDescriptor
0x9c38b60: cbz  x0, 0x9c38bd4           ; нет дескриптора -> args+0x30/0x38
0x9c38b74: ldr  x8,  [x16, #0xe8]!      ; map()
0x9c38b78: mov  w1,  #0x1000
0x9c38b80: blraa x8, x16                ; -> x21 (IOMemoryMap)
0x9c38b84: cbz  x0,  0x9c38c28          ; map == NULL -> 0xe00002c8
0x9c38b9c: ldr  x8,  [x16, #0x78]!      ; getAddress()
0x9c38ba4: blraa x8, x16                ; -> x23 = bytes (kernel VA)
0x9c38bc0: ldr  x8,  [x16, #0xb0]!      ; getLength()  (на дескрипторе!)
0x9c38bc8: blraa x8, x16                ; -> w2  = length
0x9c38be0: cmp  x23, #0
0x9c38be4: ccmp w2,  #0xd, #0, ne
0x9c38be8: b.lo 0x9c38c00               ; короткий вход -> пропуск вызова
0x9c38bf8: bl   0x9c3c3b8               ; impl(self, bytes, len, args+0x58)
0x9c38c14: ldr  x8,  [x16, #0x28]!      ; release()  -- ровно один раз
0x9c38c20: blraa x8, x16
0x9c38c40: retab
```

### sel10 / sel26 — два дескриптора, LIFO

```
0x9c38cec: blraa  ...                   ; in : map(0x1000) -> x21
0x9c38d10: blraa  ...                   ; in : getLength -> w25
0x9c38d44: blraa  ...                   ; out: map(0) -> x26
0x9c38d68: blraa  ...                   ; out: getAddress -> x24
0x9c38d70: ldr    w27, [x20, #0x70]     ; out capacity = structureOutputDescriptorSize
0x9c38ddc: bl     0x9c3c538             ; impl(self, in, out, inlen, &outcap)
0x9c38de8: cbnz   x26, 0x9c38d9c
0x9c38d9c: str    w27, [x20, #0x70]     ; writeback (уже после работы с данными)
0x9c38dbc: blraa  ...                   ; release out (x26)
0x9c38e10: blraa  ...                   ; release in  (x21)
```

Error-ветки, проверенные поштучно:
* `0x9c38ccc` (`in::map == NULL`) → `0x9c38dec` → `cbz x21` (x21 == 0) → выход, отпускать нечего ✔
* `0x9c38d48` (`out::map == NULL`) → `0x9c38dec` → `cbz x21` не срабатывает → `0x9c38df4` → **release in** ✔
* `0x9c38d90` (не прошла проверка длин) → `0x9c38d94..0x9c38dbc` (**release out**) → `0x9c38df4` (**release in**) ✔

То же зеркально в sel26: `0x9c3954c` → `0x9c395ec` → `0x9c39610`; `0x9c39598` → `0x9c3959c`/`0x9c395bc` → `0x9c39610`.

---

## 4. Почему это не UAF (по пунктам задания)

**4.1. Один объект — один `release`.** В каждом стабе ровно столько `blraa`-`0x28`, сколько объектов создано
(`map`), и каждый — на своём регистре (`x19/x20/x21/x22/x26`). Повторных `release` одного регистра нет;
`str xzr`/перезапись слота после `release` есть только в `initWithTask` и `free`, где это парная замена.

**4.2. Дескриптор не отпускается вообще.** `0x28` вызывается только на результате `map` (маппинге).
`args->structureInputDescriptor` / `structureOutputDescriptor` принадлежат `IOExternalMethodArguments`;
клиент их не `retain`-ит и не `release`-ит → double-release на них структурно невозможен.

**4.3. Порядок.** `getAddress` (`0x78`) и `getLength` (`0xb0`) вызываются до реализации; `release` — после
её возврата. Ни одна ветка не читает `bytes` после `release`. Writeback размеров (`str w27,[x20,#0x70]`,
`str w27,[x20,#0x60]`) пишет в `args`, а не в маппинг, и происходит уже после `release` — это безопасно.

**4.4. `0x28` vs `0x30`.** `0x30` встречается в `0x9c3c688` (implA), `0x9c3ebdc`, `0x9c3ffec`, `0x9c404c4`
с disc `0x89a9` и одним аргументом — это не teardown. Ни одной пары «`free` вместо `release`» в kext нет.

**4.5. Не регрессия 27.2.** Те же стабы в 27.0 (24A437): таблица `0xfffffff00805b530`, диспетчер `0x9c02e68`,
постоянный сдвиг кластера `0x3bfa8`. Все 9 стабов **инструкция-в-инструкцию идентичны** (отличаются только
цели `cbz/cbnz` и один GOT-слот), ограничения `strIn/strOut` в таблицах совпадают. См. `out/diff_stubs.txt`.

---

## 5. Топ-3 остаточных кандидата (не подтверждено)

### 5.1. Ёмкость выходного дескриптора берётся из `args+0x70` без сверки с длиной маппинга

sel10 (`0x9c38d70`) и sel26 (`0x9c39574`):

```
0x9c38d68: blraa  x8, x16        ; getAddress()  выходного маппинга
0x9c38d6c: mov    x24, x0
0x9c38d70: ldr    w27, [x20, #0x70]   ; capacity := structureOutputDescriptorSize
0x9c38d74: str    w27, [sp, #4]
0x9c38ddc: bl     0x9c3c538           ; impl пишет не более *(&sp+4) байт по x24
```

`getLength()` выходного дескриптора не запрашивается ни разу. Если `IOUserClient` не клампит
`structureOutputDescriptorSize` к длине дескриптора — запись за пределы маппинга (OOB write в страницы
OOL-буфера). Если клампит — безопасно. Проверка требует кода `IOUserClient::externalMethod` (в этом же
kernelcache, вне `__TEXT_EXEC` IOSurface) — **не подтверждено**.

### 5.2. Длина берётся у дескриптора, адрес — у маппинга, сверки нет

Во всех стабах:

```
0x9c38cec: blraa  ...   ; x23 = map->getAddress()
0x9c38d10: blraa  ...   ; w25 = descriptor->getLength()   <<< другой объект
```

Слот `0xb0` **ни разу** не вызывается на маппинге — длина маппинга не проверяется. Для штатного
`IOMemoryDescriptor::map()` длина маппинга = длина дескриптора, поэтому дыры нет; но при любом дескрипторе,
чей маппинг короче `getLength()` (усечённый диапазон, subrange, отказ на последней странице), реализации
`0x9c3c538` / `0x9c3f77c` / `0x9c3c3b8` читают `len` байт из короткого маппинга — OOB read.
Достижимость такого дескриптора из песочницы через MIG OOL — **не подтверждено**.

### 5.3. sel49: указатель объекта пишется в `*(args+0x78)`, владение передаётся

Стаб `0x9c39e0c`, реализация `0x9c3eb68`:

```
0x9c39e64: bl     0x9c3eb68        ; создаёт объект (x21 = alloc(0x100000))
0x9c39e6c: cbz    w0, 0x9c39e9c
0x9c39e70: ...                     ; ошибка: release x21
0x9c39e9c: ldr    x8, [x20, #0x78]
0x9c39ea0: str    x21, [x8]        ; успех: объект отдан наружу, release НЕ вызывается
```

Поле `0x78` `IOExternalMethodArguments` не удалось отождествить с известными (`0x30/0x38/0x40/0x48/0x58/0x60/0x68/0x70`).
Если это пользовательский указатель — запись ядерного указателя в user-память; если поле структуры — утечка
живого `OSObject` (освободить его из userspace нельзя). UAF здесь нет: владение передаётся, а не теряется.
**Не подтверждено** (нужен реальный `IOExternalMethodArguments` 27.x).

---

## 6. Что проверено и отброшено

* sel19 `0x9c390ac`, sel50 `0x9c39eb8`, sel51 `0x9c39eec` — дескриптор **отвергают** явно (`0xe00002bd` / `0xe00002c2`).
* `IOSurfaceRootUserClient::initWithTask` `0x9c3a2d4` — `release`-then-store для слотов `0x118/0x138/0x100/0x140`,
  `createMappingInTask(desc, owningTask, 0, 0x1001, 0, 0)` → маппинг в задаче вызывающего (user VA), не в `kernel_task`.
* `free()` `0x9c384d0` — освобождает `0x140/0x138/0x130/0x118/0x100`, каждый слот обнуляется; `0xe8` (провайдер)
  не отпускается. Двойного освобождения нет.
* sel32 `0x9c39760` / `0x9c3d9f4` — отдают `[client+0x138]->getAddress()`. Это **user VA** (см. выше), не KASLR-слив;
  как инфолик отброшено.
* `OSUnserializeBinary` (GOT `0x806c618` → `0xfffffff00a8d8754`) и `OSString::withCString` (GOT `0x806c7d0`)
  **копируют** данные; указатель на маппинг в долгоживущие объекты не сохраняется.

---

## 7. Артефакты

| файл | что |
|---|---|
| `kd.py`, `fn.py` | обёртка capstone над `parse_gpu/kc.py`, аннотация `adrp`/GOT/`bl`/vcall-слотов |
| `diff270.py` | скелетное сравнение функций 27.0 ↔ 27.2 |
| `dis/*.txt` | дизасм 9 стабов + 8 реализаций + диспетчера |
| `out/table_base.txt` | полная таблица 60 селекторов (27.2) |
| `out/table_270.txt` | та же таблица для 27.0 (24A437) |
| `out/vcall_scan.txt` | все `blraa` + слоты в `0x9c30000..0x9c46000` |
| `out/diff_stubs.txt` | diff стабов 27.0/27.2 |
