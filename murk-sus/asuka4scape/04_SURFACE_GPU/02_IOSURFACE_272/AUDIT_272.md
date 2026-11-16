# IOSurfaceRoot 27.2 — аудит 60 внешних методов (table A)

Источник — `kc/27.2_24B115_kernelcache`, статика. Артефакты-генераторы:
`work/parse_handlers/dump_handlers.py`, `work/parse_handlers/annotate.py`
(перезапускаются на любом kernelcache: `python3 annotate.py <kc> <outdir>`).

## 0. Как устроен диспетчер

`IOSurfaceRootUserClient::externalMethod` @ `0xfffffff009c3ee14`:

```
ldrb w9,[x0,#0x127]        ; флаг клиента
tst  w9,#1
csel x3, tableB(0x80694f0), tableA(0x8068b90), ne
mov  w4,#0x3c              ; 60 методов
b    0xfffffff009c498f4    ; общий диспетчер
```

- запись таблицы: `fn(8) | sIn(4) | strIn(4) | sOut(4) | strOut(4) | flags(4)`, stride 0x28;
- `strIn/strOut == 0xffffffff` — размер не проверяется;
- заглушка `0x9c3a1dc` возвращает `0xe00002e2`;
- наш не-entitled клиент попадает в **table A** (`[self+0x127]&1 == 0`).

Почти все записи table A — **тонкие шимы** на 3–8 инструкций: проверить наличие
нужного аргумента (`ldr x8,[x2,#0x..]` + `cbz` -> `0xe00002c2`), вытащить скаляры
и `b <реальная реализация>` в диапазоне `0x9c3xxxx…0x9c4xxxx`. Реальный код
начинается с `bti c; pacibsp; …`.

## 1. Классификация по аргументам

Сгенерировано из `args_matrix.txt`:

| профиль аргументов | селекторы |
|---|---|
| только `scalarIn` | 0 1 5 8 12 14 15 16 20 21 22 23 25 29 31 33 35 36 37 39 41 42 43 44 45 53 55 56 57 58 59 |
| `structInDesc` (OOL-дескриптор на вход) | 24 47 48 50 54 |
| `scalarIn + structOut` | 4 7 28 34 |
| `structIn` (inline) | 17 18 27 |
| `structIn + structInSize + structOut` | 2 3 |
| `structInDesc + structOut` | 9 11 |
| `structOutDesc` | 51 52 |
| `structIn + structOut` | 6 |
| `structInSize` (только размер!) | 19 |
| `self0x126 + structOut + structOutSize` | 13 |
| `self0x138 + scalarOut` | 32 |
| `varOut (+ self0x122)` | 30 |
| `varOut` (без флага) | 49 |
| без аргументов вообще | 10 26 40 46 (у 10/26 аргументы читаются через x20 после `mov x20,x2`) |

## 2. Что важно по конкретным

- **sel 30** — единственный реальный канал ядро→app: `OSData::withCapacity(0x100000)`
  + сериализация `self->0xe8`, результат кладётся в `args+0x78`. Закрыт `[self+0x122]`.
- **sel 49** — var-output без флага, но helper `0x9c3eb68` буфер не заполняет (`cnt=0`).
- **sel 10 / 26** — «взять данные по ключу»: `mov x20,x2`, мапят
  `structureInputDescriptor` (`vt[0xe8]`) и `structureOutputDescriptor`, берут длину
  (`vt[0x78]`/`vt[0xb0]`), копируют `memcpy(out, src, len)` при `*structureOutputSize >= len`.
  Проверка размера на месте.
- **sel 19** — единственный, кто читает только `structureInputSize`:
  `cmp w9,#0x1ff; b.ls …` иначе `0xe00002c2`; дальше тело по `0x9c390c8`
  (в дампе обрезано первым `ret` — диззассемблировать отдельно от `0x9c390c8`).
- **sel 27/28/29** — шимы в `0x9c3d7c8` (структура 160 B), `0x9c3d838` (id + 160 B out),
  `0x9c3d908` (2 скаляра).
- **sel 51/52** — требуют **отсутствия** `structureOutputDescriptor`
  (`ldr x8,[x2,#0x68]; cbz` -> иначе `0xe00002c2`), т.е. только inline.
- **sel 50** — наоборот, требует **наличия** `structureInputDescriptor`.
- **sel 47/48** — 1 скаляр + дескриптор входа, реализации `0x9c3e570` и `0x9c3e86c`.
- **sel 31/32** — читают флаг `self+0x138` (ещё один гейт, отдельный от 0x122).
- **sel 12/13** — читают флаг `self+0x126`.

## 3. Состояние проверки на памяти

Реальные реализации (`0x9c35850 … 0x9c40a4c`) не проверялись на память глубоко:
это следующий проход — для каждого из ~30 «толстых» обработчиков смотреть
`memcpy`/`memmove`/`copyout` и сравнивать длину с размером целевого объекта.

## 4. Открытые вопросы

1. Кто ставит `[self+0x122]` (и `+0x127`, `+0x138`, `+0x126`) — сеттеры
   `0x8fd1088/0x8fd1700` вызываются косвенно, таблица указателей. Без этого
   нельзя сказать, доступен ли sel 30 из песочницы.
2. `sel 19` — тело после `0x9c390c8`: что делает с размером.
3. Глубокий проход по реализациям на memory-safety (длины vs размеры объектов).

## 5. Гейт `+0x122` — закрыт (проверено по инструкциям)

`IOSurfaceRootUserClient::initWithTask` @ `0x9c3a2d8`:

```
0x9c3a340  adrp x2, 0x789c000 ; add x2,#0xe3e          ; "com.apple.private.iosurfaceinfo"
0x9c3a34c  bl   0x9c3a60c                              ; copyClientEntitlement
0x9c3a350  strb w0, [x19, #0x122]                      ; <-- флаг
0x9c3a354  ... "com.apple.private.gpu-restricted" + "com.apple.developer.gpu-restricted"
0x9c3a380  strb w0, [x19, #0x127]
0x9c3a384  ... "…protected-access"
0x9c3a394  strb wzr,[x19,#0x123]
0x9c3a398  ldrb w8,[x19,#0x122] ; orr w8,w8,w0 ; and w8,w8,#1
0x9c3a3a4  strb w8, [x19, #0x126]
```

Гейт `0x9c3a60c` в конце:
```
0x9c3a63c  ldr x20, [x8]        ; объект-значение энтайтлмента
0x9c3a664  cmp x20, x19         ; == &gOSBooleanTrue (сравнение по идентичности)
0x9c3a668  cset w0, eq
```
То есть нужен именно `<true/>` в `com.apple.private.iosurfaceinfo`. Флаг принадлежит
**task'у**, открывшему клиент; переданный порт несёт его с собой.

Следствия:
- sel 30 из непривилегированного приложения недостижим: `0xe00002c1` (not privileged);
- `+0x127` = `private.gpu-restricted | developer.gpu-restricted` → выбор table B;
- `+0x126` = `+0x122 | private.IOSurface.protected-access`;
- сеттеры `0x8fd1088/0x8fd1700` — **ложный след** (это case-тела jump-таблицы power-kext'а
  `0x8fd0ee4`, таблица `0x8fd1964`), к IOSurface не относятся.

## 6. Memory-safety проход: memcpy-цепочки

Собрано 138 функций (60 обработчиков + все прямые `bl` внутри kext, 2 уровня).
Единственные два вызова `memcpy` (`slot 0x806c8a8 -> 0xfffffff00aa65b10`):

1. `0x9c3f77c @ 0x9c3f8c4` — `memcpy(dst=outBuf, src=data->bytes, n=len)` под проверкой
   `*structureOutputSize >= len` (см. §2 sel 10/26). **Корректно.**
2. `0x9c3c538 @ 0x9c3c72c` — «сериализовать свойство в буфер с 12-байтовым заголовком»:
   ```
   ld r w8,[x23]        ; *outSize (ёмкость буфера)
   sub w0,w8,#0xc       ; ёмкость - 12
   bl  OSData::withCapacity
   ...  serialize
   [data vtable+0xb8]   ; len
   add x26, len, #0xc
   cmp x26, *outSize ; b.ls  -> иначе 0xe00002db (buffer too small)
   [data vtable+0x78]   ; src
   memcpy(outBuf+0xc, src, len)
   ```
   Ёмкость берётся из `structureOutputDescriptorSize`/`structureOutputSize`, проверка
   `len+12 <= capacity` стоит **до** копирования. **Корректно.**

Других `memcpy` в достижимых реализациях нет; копирования через `blraa` (виртуальные
методы `IOMemoryDescriptor`/`OSData`) идут в стандартные пути с собственными проверками.

## 7. Итог

- Внешняя поверхность `IOSurfaceRoot` размечена полностью (60 селекторов, аргументы, гейты).
- Канал ядро→app (var-output) закрыт энтайтлментом; в IOSurface обойти нельзя.
- В достижимых обработчиках явных переполнений по длине не найдено; остаются
  нетривиальные пути (виртуальные методы, конкурентный доступ, property-парсеры).
