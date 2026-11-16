# Байт-флаг `[IOSurfaceRootUserClient + 0x122]`
**kernelcache iOS 27.2, build 24B115 (`27.2_24B115_kernelcache`, MH_FILESET, 67 239 936 байт)**

---

## TL;DR

`[self+0x122]` пишется **ровно в одном месте всего кеша** — `0xfffffff009c3a350`,
внутри `IOSurfaceRootUserClient::initWithTask` (`0xfffffff009c3a2d8`):

```
0x9c3a350  strb w0, [x19, #0x122]      ; w0 = результат гейта 0x9c3a60c
```

а гейт `0x9c3a60c` — это `copyClientEntitlement(task, key) == &gOSBooleanTrue`:

```
0x9c3a628  bl   0x9c49804              ; (task, key) -> OSObject*
0x9c3a664  cmp  x20, x19               ; x20 = gOSBooleanTrue
0x9c3a668  cset w0, eq
```

Ключ, подставленный перед вызовом (`adrp 0x789c000; add #0xe3e` @ `0x9c3a340`):

> **`com.apple.private.iosurfaceinfo`**

**Ответ:** процесс без entitlements получить `[self+0x122] == 1` не может.
Точное условие — у task'а, открывшего user client, есть entitlement
`com.apple.private.iosurfaceinfo` **со значением boolean true** (`<true/>`).
Строка `"1"`, число `1`, `false`, отсутствие ключа — всё даёт 0.
Других писателей поля нет ни в одном селекторе, ни в одной таблице методов.

---

## 0. Важная поправка к исходной гипотезе

Сеттеры `0x8fd1088` (`[x0+0x122]`) и `0x8fd1700` (`[x0+0x127]`) **не относятся к IOSurface**.
Это не отдельные функции и не «таблица указателей», а **case-тела jump-таблицы**
внутри функции `0xfffffff008fd0ee4`:

```
0x8fd0ee4  bti c
0x8fd0ee8  sub  w16, w1, #6
0x8fd0eec  cmp  w16, #0xf9
0x8fd0ef0  b.hi 0x8fd192c
0x8fd0ef8  csneg x16, x16, xzr, ls
0x8fd0efc  adrp x17, 0x8fd1000
0x8fd0f00  add  x17, x17, #0x964        ; таблица 32-битных relative-оффсетов @0x8fd1964
0x8fd0f04  ldrsw x16, [x17, x16, lsl #2]
0x8fd0f08  adr  x17, 0x8fd0f08
0x8fd0f0c  add  x16, x17, x16
0x8fd0f10  br   x16                     ; "сеттер": x0=obj, w1=selector(6..0xfe), w2=value
```

Единственный вызывающий — `0x8fcfae4`, внутри функции `0x8fcf904(this, OSDictionary*)`,
которая раскладывает словарь по 210-элементной таблице свойств
`__DATA_CONST 0x7e9cd98 = {u32 selector, u32 pad, char *key}`, ключи — power/thermal:
`FullOperationModePowerFraction`, `UseOverrideSystemCapability`, `OverrideBatteryInputMeasuredPu`, …
Совпадение смещений `0x122/0x127` — случайное: это другой класс (power/SMC-kext), другой объект.
Поэтому «условие вызова сеттера» искать там бессмысленно, и `bl` к `0x8fd1088` действительно нет.

Заодно: кодировка data-указателей в этом кеше не одна.
Кроме PAC-формы `(q>>32)==0x8050bcad` (VA = `0x7004000 + (q & 0x0FFFFFFF)`) есть
тегированные file-offset'ы: `1<<52 | fileoff` и `2<<52 | fileoff` (например `0x0010000000c664c0`).
Поиск только по `0x8050bcad` даёт ложные нули.

---

## 1. Кто пишет `+0x122` (полный скан)

Скан всех байтовых и широких записей, перекрывающих `0x122`, по `__TEXT_EXEC`,
`__TEXT_BOOT_EXEC`, `__TEXT`. В кластере кода IOSurface-клиента (`0x9c30000–0x9c40000`):

| адрес | инструкция | что это |
|---|---|---|
| `0x9c3a350` | `strb w0,[x19,#0x122]` | **единственная запись**, init |
| `0x9c396ac` | `ldrb w8,[x0,#0x122]` | чтение, селектор 30 |
| `0x9c3a398` | `ldrb w8,[x19,#0x122]` | чтение, init (→ `+0x126`) |

`str w?, [x?,#0x120]` (перекрывает `0x122`) встречается в `0x9c30d50`, `0x9c3131c`,
`0x9c32e88`, `0x9c35fec`, `0x9c361bc` — но это **другой класс**: те функции лежат в
`IOSurfaceRoot::init`/`map_surface_id` (ссылаются на `"IOSurfaceRootParavirtMapperInterface"`,
`"Entry for surface handle %d %p is not equal to %p"`) и зануляют область `0xd0…0x218+`,
т.е. объект-провайдер с `uint32` по `0x120`. У клиента `0x122` — именно байт (только `ldrb/strb`),
и `init` никогда не пишет `0x120` словом.

Остальные ~70 записей `strb ...#0x122` (`0x9202aac`, `0x92e2cac`, `0x93b92bc`, `0x9b8cb84`,
`0x9f3e1fc`, `0xa6bc350`, `0xa703b34`, …) — другие классы, другой layout.

---

## 2. Гейт `0xfffffff009c3a60c` — что именно сравнивается

```
0x9c3a60c  bti c
0x9c3a610  pacibsp
0x9c3a614  stp  x20,x19,[sp,#-0x20]!
0x9c3a618  stp  x29,x30,[sp,#0x10]
0x9c3a620  mov  x0, x1                  ; arg0 -> task
0x9c3a624  mov  x1, x2                  ; arg1 -> entitlement string
0x9c3a628  bl   0x9c49804              ; copyClientEntitlement(task, key) -> OSObject* (retained)
0x9c3a62c  mov  x19, x0
0x9c3a630  adrp x8, 0x806c000
0x9c3a634  ldr  x8, [x8,#0xa60]         ; GOT-слот -> 0x7c6a4c0 -> 0xadd6e58 (&gOSBooleanTrue)
0x9c3a638  ldr  x8, [x8]
0x9c3a63c  ldr  x20, [x8]               ; x20 = gOSBooleanTrue (объект)
0x9c3a640  cbz  x0, 0x9c3a664
0x9c3a644  .. 0x9c3a660                ; release(x19) через vtable+0x28
0x9c3a664  cmp  x20, x19
0x9c3a668  cset w0, eq                  ; 1 только если это ТОТ САМЫЙ объект kOSBooleanTrue
0x9c3a66c  ldp/ldp
0x9c3a674  retab
```

Следствия, важные на практике:

* сравнение **по идентичности объекта**, а не по значению → entitlement должен быть
  ровно `<true/>`; `<string>1</string>`, `<integer>1</integer>`, `<false/>` дадут **0**;
* гейт ничего не знает про sandbox/платформу — только про entitlement у переданного task;
* `x0` (self) в гейт не используется вообще.

Единственные четыре вызова гейта во всём `__TEXT_EXEC` — все внутри `init`:

```
0x9c3a34c  bl 0x9c3a60c     0x9c3a360  bl 0x9c3a60c
0x9c3a37c  bl 0x9c3a60c     0x9c3a390  bl 0x9c3a60c
```

---

## 3. Полная последовательность в `init` (`0xfffffff009c3a2d8`)

Идентификация: внутри функции есть ссылки на строки
`"provider not IOSurfaceRoot\n"` (`0x9c3a4f8`), `"Cannot allocate IOSurfaceShared\n"`,
`"Cannot map graphics comm page\n"`, `"Cannot allocate notification array\n"`,
`"Cannot allocate invalidated surface array\n"`, `"Cannot allocate IOLock/IORWLock"`.
Регистры на входе: `x0=self`, `x1=inSecurityToken`, `x2=task(x20)`, `x3=inProperties`.
Task сохраняется в `self+0xf8` (`pacda` @ `0x9c3a324..0x9c3a33c`, перед этим `bl 0x9c49df4` — retain).

```
0x9c3a340  adrp x2,0x789c000 ; add x2,#0xe3e   -> "com.apple.private.iosurfaceinfo"
0x9c3a348  mov  x1, x20                        ; task
0x9c3a34c  bl   0x9c3a60c
0x9c3a350  strb w0, [x19, #0x122]              ; +0x122 = iosurfaceinfo

0x9c3a354  add  x2, #0xe5e                      -> "com.apple.private.gpu-restricted"
0x9c3a360  bl   0x9c3a60c
0x9c3a364  tbz  w0, #0, 0x9c3a370
0x9c3a368  mov  w0, #1
0x9c3a36c  b    0x9c3a380
0x9c3a370  add  x2, #0xe7f                      -> "com.apple.developer.gpu-restricted"
0x9c3a37c  bl   0x9c3a60c
0x9c3a380  strb w0, [x19, #0x127]              ; +0x127 = gpu-restricted(private|developer)

0x9c3a384  add  x2, #0xea2                      -> "com.apple.private.IOSurface.protected-access"
0x9c3a390  bl   0x9c3a60c
0x9c3a394  strb wzr, [x19, #0x123]             ; +0x123 = 0
0x9c3a398  ldrb w8, [x19, #0x122]
0x9c3a39c  orr  w8, w8, w0
0x9c3a3a0  and  w8, w8, #1
0x9c3a3a4  strb w8, [x19, #0x126]              ; +0x126 = iosurfaceinfo | protected-access
```

Дальше `+0x126` уходит аргументом в `bl 0x9c418cc` (`0x9c3a3c4..0x9c3a3d4`) — то есть флаг
«поверхность можно создавать как protected»; на `+0x122` это не влияет.

Все пути отказа (`0x9c3a5fc` и ветки `0x9c3a4e8/0x9c3a510/0x9c3a538/0x9c3a5d8/0x9c3a5c0`)
возвращают `w0=0` → объект уничтожается. Живой объект всегда прошёл через `0x9c3a350`.

---

## 4. Что даёт `+0x127` (таблицы externalMethod)

`0xfffffff009c3ee14`:

```
0x9c3ee14  adrp x8, 0x8068000 ; add x8,#0xb90    ; таблица A
0x9c3ee1c  ldrb w9, [x0, #0x127]
0x9c3ee20  adrp x10, 0x8069000 ; add x10,#0x4f0  ; таблица B
0x9c3ee28  tst  w9, #1
0x9c3ee2c  csel x3, x10, x8, ne                  ; +0x127==1 -> B, иначе A
0x9c3ee30  mov  w4, #0x3c                        ; 60 методов
0x9c3ee3c  b    0x9c498f4
```

Обе таблицы — `60 × 0x28`, запись `{u64 action_pac(0x8050bcad…), u32 inScalar, u32 inStructSize,
u32 outScalar, u32 outStructSize, 8 байт нулей}`:

* table A `0xfffffff008068b90`
* table B `0xfffffff0080694f0`

Таблица B подменяет **20** селекторов заглушкой `0xfffffff009c3a1dc`
(`mov w0,#0x2e2; movk w0,#0xe000; ret` = `kIOReturnUnsupported 0xE00002E2`):
`4,5,6,7,8,16,17,18,19,21,22,24,25,26,28,29,30,33,43,46,47,48,49`.

### Селектор 30

| | table A | table B |
|---|---|---|
| запись | `0x8068b90 + 30*0x28 = 0x8069040` | `0x80694f0 + 30*0x28 = 0x80699a0` |
| action | `0x9c3968c` | `0x9c3a1dc` |
| тело | `0x9c39690` | `0xE00002E2` |

```
0x9c39690  pacibsp
0x9c396a4  mov  w19, #0x2bd ; 0x9c396a8 movk w19,#0xe000   ; 0xE00002BD (kIOReturnNoMemory)
0x9c396ac  ldrb w8, [x0, #0x122]
0x9c396b0  tbz  w8, #0, 0x9c3971c
...
0x9c3971c  add  w19, w19, #4        ; 0xE00002C1 = kIOReturnNotPrivileged
0x9c39720  b    0x9c39734           ; возврат ошибки
```

Ветка «есть права» (`0x9c396b4…`): требует `args->structureOutput != NULL` (иначе `+5` →
`0xE00002C2 kIOReturnBadArgument`), выделяет `0x100000` (1 МБ), зовёт
`0x9c40430(this, args->structureInput[0], buf)` и при успехе пишет указатель буфера в
`*(args->structureOutput)`. Это и есть тот самый канал «ядро → user» — 1 МБ shared-области.

Для gpu-restricted клиента (`+0x127==1`) селектор 30 вообще отсутствует в таблице → `0xE00002E2`.

---

## 5. Ответ на главный вопрос

**Может ли процесс без entitlements получить `[self+0x122] == 1`? — Нет.**

Доказательство (все адреса — инструкции, не догадки):

1. Единственная запись поля: `0x9c3a350 strb w0,[x19,#0x122]` (скан всех `strb/strh/str/str x/str q/stp`
   с перекрытием `0x122` по всем exec-сегментам; см. §1).
2. Значение `w0` в этой точке — исключительно результат `bl 0x9c3a60c` (`0x9c3a34c`), между ними
   нет ни одной инструкции, меняющей `w0`.
3. `0x9c3a60c` возвращает `cset w0, eq` (`0x9c3a668`) после `cmp x20, x19` (`0x9c3a664`), где
   `x19` = `copyClientEntitlement(task,"com.apple.private.iosurfaceinfo")`, `x20` = `gOSBooleanTrue`.
4. `task` — это `x2` из `init`, т.е. **task процесса, открывшего user client**
   (`IOSurfaceRoot::newUserClient` → `initWithTask(inOwningTask, …)`); он же кладётся в `self+0xf8`.
5. Ни один action ни из table A, ни из table B не содержит записи в `+0x122` — таблицы задают
   только чтение (`0x9c396ac`) и запись `+0x126/+0x127` в `init`.

**Точное условие `[self+0x122] == 1`:**
> у task'а, создавшего `IOSurfaceRootUserClient`, `copyClientEntitlement(task, "com.apple.private.iosurfaceinfo")`
> вернул объект `kOSBooleanTrue`, т.е. в entitlements процесса есть
> `com.apple.private.iosurfaceinfo = <true/>`.

Побочные следствия:

* флаг — свойство **открывающего** task'а, а не держателя mach-port'а user client'а.
  Если привилегированный демон создал клиент и передал порт другому процессу,
  у объекта `+0x122` останется 1, и получатель унаследует канал;
* `+0x122` нельзя выставить/сбросить через externalMethod — только пересозданием клиента;
* значение `+0x122` влияет ровно на один путь — селектор 30 (и через `+0x126` на
  `protected-access` при создании поверхности).

---

## 6. Таблица адресов

| что | адрес |
|---|---|
| `IOSurfaceRootUserClient::initWithTask` | `0xfffffff009c3a2d8` |
| гейт `entitlement == gOSBooleanTrue` | `0xfffffff009c3a60c` |
| `copyClientEntitlement` (вызов) | `0x9c3a628 → 0xfffffff009c49804` |
| запись `+0x122` | `0xfffffff009c3a350` |
| запись `+0x127` | `0xfffffff009c3a380` |
| запись `+0x126` | `0xfffffff009c3a3a4` |
| чтение `+0x122` (селектор 30) | `0xfffffff009c396ac` |
| externalMethod (выбор таблицы) | `0xfffffff009c3ee14` |
| table A / table B | `0xfffffff008068b90` / `0xfffffff0080694f0` |
| заглушка table B | `0xfffffff009c3a1dc` (`0xE00002E2`) |
| строка `com.apple.private.iosurfaceinfo` | `0xfffffff00789ce3e` |
| строка `com.apple.private.gpu-restricted` | `0xfffffff00789ce5e` |
| строка `com.apple.developer.gpu-restricted` | `0xfffffff00789ce7f` |
| строка `com.apple.private.IOSurface.protected-access` | `0xfffffff00789cea2` |
| **ложный след**: power-диспетчер свойств | `0xfffffff008fd0ee4`, jump table `0x8fd1964`, имена `0xfffffff007e9cd98` |

---

## 7. Что осталось непроверенным (честно)

* Символьных имён нет: `LC_SYMTAB` в кеше отсутствует, `__LINKEDIT` — это `bplist00`
  с `WeakRefFallbackSymbolsSets`, но файл обрезан (trailer нулевой), поэтому name→addr не строится.
  Имя `initWithTask` присвоено по строковым ссылкам внутри функции (см. §3), не по символам.
* Указателей на `0x9c3a2d8` / `0x9c3ee14` / `0x9c39690` в `__DATA_CONST`/`__DATA` не найдено
  ни в одной из трёх кодировок (`0x8050bcad`, `0x8011…`, tag `1/2<<52`). Как именно
  раскрывается vtable этого класса в 24B115 — не установлено; на вывод это не влияет,
  потому что вывод держится на достижимом коде `externalMethod` и на единственном писателе поля.
* `0x9c407ec` (цель тунка `0x9c3a2c0 cmp x4,#0; cset w4,ne; b 0x9c407ec`) гейт **не** вызывает;
  внутри ссылается на строку `append_transaction` — это отдельный именованный диспетчер методов,
  к `+0x122` отношения не имеет.

---

## 8. Как перепроверить

```bash
cd /home/femboychik/work/parse_flags2
python3 fieldscan.py     # все байтовые обращения к +0x122 / +0x127 по __TEXT_EXEC
python3 wide.py          # широкие записи, перекрывающие +0x122 (фильтр по 0x9c30000-0x9c40000)
python3 tables.py        # разбор table A / table B (60 x 0x28) -> action-адреса
python3 kcd.py 0xfffffff009c3a2d8 120   # init целиком
python3 kcd.py 0xfffffff009c39690 60    # тело селектора 30
python3 strrefs.py 0xfffffff009c3a2d8 0xfffffff009c3a610   # строки внутри init
```
