# AppleJPEGDriver — внутренние границы четырёх парсеров

Объект: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (MH_FILESET, 24B115).
Инструменты: `an.py` (собственная va→file карта — `kc.py` на этом образе даёт `None` на части адресов из-за bisect по перекрытым сегментам), `kc.py`.
Слой user client в этом проходе не перепроверялся — взяты готовые факты прошлого прохода (таблица `0x7e293c0`, 10 записей, stride `0x28`, валидатор `0xa9b0888`).

## 1. Коротко

Четыре «парсера» — это не разбор JPEG-файла, а разбор **фиксированной IO-структуры** метода (`AppleJPEGDriverIOStructExt`, 0x1000 Б; `AppleJPEGDriverIOStruct2024`, 0xda0 Б). Разбирают они: 0x84-байтовая шапка параметров (0x00…0x83, fake header начинается с 0x84), две таблицы по 64 элемента (квантование; u8 в Ext, u16 в 2024) и «fake header» — массив 12-байтовых записей, который копируется в `std::vector<uint32_t>` сессии. Сканирования маркеров JPEG (`FFD8/FFC0/FFDA`) в драйвере нет вообще.

Внутренние границы, как они написаны, **сходятся**: длина структуры на входе фиксируется диспетчером ровно в 0x1000/0xda0, все чтения по смещениям лежат внутри, копия «fake header» ограничена дважды (0xf7f/0xc03 + кратность 12) и защищена `brk #0x800` по фактической ёмкости вектора. OOB/переполнения не найдено.

Остались три не-граничных риска: неограниченный размер аллокации из поля `+0x08` (u32), полностью невалидируемое содержимое 12-байтовых записей (уходит в железо/firmware) и «заимствующий» указатель `session+0x4c8` внутрь входной структуры (потребителя в образе нет — риск латентный).

## 2. Четыре парсера

Селекторы и переходники (из прошлого прохода), fn — обёртка таблицы `0x7e293c0`:

| sel | strIn | обёртка | парсер | символ (строка в `__PRELINK_TEXT`) |
|---|---|---|---|---|
| 5 | 0x1000 | `0x8c8fb3c` | **`0x8c86024`** | `AppleJPEGDriver::startDecoderExt(AppleJPEGDriverIOStructExt*, ...)` @ `0x751a459` |
| 4 | 0x1000 | `0x8c8fb08` | **`0x8c86bd4`** | `AppleJPEGDriver::startEncoderExt(...)` @ `0x751a566` |
| 7 | 0xda0, flags=1 | `0x8c8fba4` | **`0x8c87038`** | `AppleJPEGDriver::startDecoder2024(AppleJPEGDriverIOStruct2024*, ...)` @ `0x751a5f1` |
| 6 | 0xda0, flags=1 | `0x8c8fb70` | **`0x8c876d8`** | `AppleJPEGDriver::startEncoder2024(...)` @ `0x751a67f` |

Легаси-варианты для полноты (strIn 0x58): `0x8c85520` `startDecoder`, `0x8c867c0` `startEncoder`.

Общая инфраструктура, на которую опираются все четыре:

- `0x8c8505c` — alloc сессии (`0x8ca9278` → GOT `0x7e2cf00` → `0xa902074`, тип/зона `0x7e2c498`), затем `0x8c8509c` — конструктор: обнуление всего объекта (до `+0x550`), два встроенных вектора, `lck_mtx` по `+0xf8`.
- `0x8c85370` — `getMCUSize(AppleJPEGSubsampling, ...)`: таблица на 5 записей `0x7526a18`/`0x7526a2c`, вход — поле `+0x2c`, **bound-check `cmp w1,#5 / b.hs`**, при промахе лог и дефолт 8/0x20. Деления — только после `cbz` на делителе.
- `0x8c85834` — `convertToRequestSubSampleMode`: switch по тому же `+0x2c` (0…4), пишет `session+0x444`.
- `0x8c86644` — `vector<uint32_t>::reserve(count)`: рост в 2×, `brk #0x800` на переполнении `count*4`.
- `0x8c858fc` — лямбда, которая гоняется через `driver->[0xb8]->vt[+0xe8]` (command gate) уже после разбора; получает готовую сессию.

## 3. Откуда берётся вход

Цепочка (одинакова для всех четырёх):

1. `vptr+0x5d0` = `0x8c8fc30` → `b 0x8ca9458` (PLT) → GOT `0x7e2cff0` → **`0xa9b0888`** (диспетчер/валидатор).
2. `0xa9b0888` сверяет запись таблицы с аргументами: `entry+0x08` (sIn) == `args[+0x28]`; `entry+0x0c` (strIn) == `getLength()` дескриптора `args[+0x40]` (`vt+0xb0`), либо, если дескриптора нет, == `args[+0x38]`; то же для out (`entry+0x10`/`+0x14` против `args[+0x50]` и `args[+0x68]`/`args[+0x60]`). Сравнение **точное** (`b.ne` → `0xe00002bc`).
3. Обёртка (`0x8c8fb08/3c/70/a4`) вызывает парсер как
   `start(driver=[client+0xe0], in=args[+0x30], out=args[+0x58], wakePort=[client+0xf0], client, task=[client+0x100])`.

То есть `x1` внутри парсера — это kernel-VA структуры входа, `x2` — структуры выхода. Длина обеих зафиксирована валидатором: ровно `0x1000` (Ext) или `0xda0` (2024).

**Не подтверждено:** является ли `args[+0x30]` копией (`copyin`) или живым маппингом дескриптора (`createMapping`) — код заполнения `args` лежит в generic IOUserClient2022, в этом проходе не локализован. На границы это не влияет (длина фиксирована), влияет только на TOCTOU-семантику содержимого и на «заимствующий» указатель из §6.3.

## 4. Поля из файла → как используются → проверка

Общая шапка (одинакова для Ext и 2024; отличия отмечены):

| поле | роль по коду | куда | проверка |
|---|---|---|---|
| `+0x00` u32 | режим/оп | `session+0x2ac` | нет |
| `+0x04` u32 | inputSize | `session+0x420` | только у энкодеров: `> 0xff` (`cmp/b.hi`), иначе лог «i/o sizes illegal» + ошибка; у декодеров — нет |
| `+0x08` u32 | размер внутреннего буфера | `session+0x2b0` → `IOBufferMemoryDescriptor`-подобная аллокация в `0x8c84868` | **нет верхней границы** (u32 → до 4 ГиБ), ошибка аллокации обрабатывается (`0xe00002cc`) |
| `+0x0c` u32 | outputSize | `session+0x424` | у энкодеров `>= 7`; у декодеров — нет |
| `+0x14` u32 | width | `session+0x428` | у энкодеров `4..0xffff` (`b.lo` + `lsr #16/cbnz`); у декодеров — нет |
| `+0x18` u32 | height | `session+0x42c` | у энкодеров `2..0xffff` через `sub #0x10000; cmp #-0xffff; b.ls` (wrap-приём, границы верные); у декодеров — нет |
| `+0x1c` u32 | quality | (только энкодеры) | `(v & 0xfffe) < 0xa` → 0…9, иначе лог «unsupported encoding quality» + ошибка |
| `+0x20` u8 | флаги | `session+0x310/0x312/0x314` (биты 0/1/2) | нет (битовые) |
| `+0x24` 8 Б | параметры кадра | `session+0x450` | нет |
| `+0x2c` u32 | subsampling/codec | `getMCUSize`, `session+0x444`, `session+0x464` | `< 5` в `0x8c85370`; `0..4` в `0x8c85834`; иначе лог + дефолт |
| `+0x30` 16 Б | in-указатель/флаг + `+0x38` | `session+0x10/0x18` | **только `cbz`**; разыменований в образе не найдено |
| `+0x40` 8 Б | out-указатель | `session+0x20` | `cbz` (в конце решает, писать ли результат в out-структуру) |
| `+0x48` u32 | tag/cmdID | `session+0x538` | нет; идёт только в лог |
| `+0x4c` 8 Б | — | `session+0x47c` | нет |
| `+0x54` u32 | делитель слайс-арифметики (`udiv`) | `session+0x4ac` | `cbz` перед `udiv` (деления на 0 нет) |
| `+0x58` u32 | флаг/счётчик слайсов | `session+0x4b0` | `cbz` → блок слайсов пропускается |
| `+0x5c`/`+0x60`/`+0x64`/`+0x68`/`+0x6c` | у декодеров — 5×u32 | `session+0x4b4..0x4c4` | нет |
| `+0x70`/`+0x74`/`+0x78`/`+0x7c`/`+0x80` | 5×u32 | `session+0x498`/`0x49c`/`0x4a8`/**`0x4a0`**/`0x4a4` | нет; `+0x7c` — см. ниже |
| **`+0x7c` u32** | **newHeaderSize** | `session+0x4a0` → длина копии | **да, см. §5** |
| `+0x84..` | «fake header», 12-байтовые записи | `vector<u32>` `session+0x4d8` (или borrow, §5) | длина — см. §5; **содержимое не проверяется** |
| `+0xc84` u32 (2024) | — | `session+0x468` | нет |
| `+0xcac` u32 (2024) | — | `session+0xc4` | нет |
| `+0xdc` u8 (Ext enc) / `+0x15c` u8 (2024 enc) | флаг после таблиц | `session+0x500` (бит 0) | нет (бит) |

Таблицы энкодеров (цикл ровно `0x40` итераций, счётчик не из файла):

| вариант | источник 1 | источник 2 | флаг | приёмник |
|---|---|---|---|---|
| Ext | `+0x5c`, 64×u8 | `+0x9c`, 64×u8 | `+0xdc` | `session+0x31e` / `+0x39e` (u16) |
| 2024 | `+0x5c`, 64×u16 (`0x80` Б) | `+0xdc`, 64×u16 (`0x80` Б) | `+0x15c` | `session+0x31e` / `+0x39e` (u16) |

Границы таблиц: Ext `0x9c+0x40 = 0xdc`, `0xdc+0x40 = 0x11c ≤ 0x1000`; 2024 `0xdc+0x80 = 0x15c`, `0x15c+0x80 = 0x1dc ≤ 0xda0`. Внутри.

## 5. Ответы на четыре вопроса

**(1) Чтения по смещениям.** Внешняя длина задана диспетчером точно (0x1000/0xda0), поэтому фиксированные смещения `+0x00…+0x84` и `+0xc84/+0xcac` (2024) всегда внутри. Внутренняя длина `newHeaderSize` берётся из файла (`+0x7c`), но проверяется: `<= 0x1000` (MARKERRAM_MEM_SIZE), затем кратность 12, затем `<= 0xf7f` (Ext) / `<= 0xc03` (2024). Все чтения `+0x5c…+0x6c` также внутри. Ни одного чтения по индексу из файла нет.

**(2) Циклы по счётчикам из файла / умножения.** Единственный цикл с внешним счётчиком — копия fake header: `elementCount = newHeaderSize >> 2`, `vector::reserve(elementCount)`, затем `memcpy(len = newHeaderSize & 0xffc)`. Умножение `elementCount*4` — внутри reserve, с `brk #0x800` при переполнении; при `newHeaderSize <= 0xf7f` переполнение невозможно. Цикл таблиц — фиксированные 0x40. Слайс-арифметика — `udiv` после `cbz`. Кумулятивных смещений по данным файла нет.

**(3) Копирования в буферы 0x1000/0xda0.** Таких копий нет: 0x1000/0xda0 — это размеры *пользовательской* структуры, а не приёмники. Приёмник fake header — свежий `vector` ёмкостью `(newHeaderSize>>2)*4`, то есть ровно под данные; сверх того стоит явная проверка `cap-begin >= len` с `brk #0x800`. Данные длиннее лимита отвергаются до копии (лог + `0xe00002bc`). В таблицы энкодеров копируется фиксированных 128 Б.

**(4) Заполнение полей сессии.** Сессия аллоцируется заново и обнуляется конструктором; из файла в неё попадают только скаляры и два «указателя» (`+0x30/+0x38` → `session+0x10/0x18`, `+0x40` → `session+0x20`). `session+0x00/0x08` — это `IOUserClient*` и wakePort от вызывающего, не из файла. Указатель на драйвер (`[client+0xe0]`) только читается. Перезаписи полей устройства/класса данными файла нет.

Отдельно: `session+0x4c8/0x4d0` в ветке «без внешнего буфера» получают **сырой указатель внутрь входной структуры** (`struct+0x84`) и счётчик `0x3df`/`0x300`. Чтений `+0x4c8/+0x4d0/+0x4d8` в регионе драйвера нет ни одного (пословный скан `0x8c70000…0x8c93000` с учётом масштаба imm — только записи в парсерах и обнуление в конструкторе). То есть в этой сборке поле мёртвое; если появится потребитель при асинхронном старте — это UAF на маппинге входа.

## 6. Топ-3 с дизасмом

### 6.1 `startDecoderExt` — проверка `newHeaderSize` и копирование (0x8c8619c…0x8c86358)

```
0xfffffff008c8619c  cmp     w25, #1, lsl #12        ; w25 = [in+0x7c], 0x1000
0xfffffff008c861a0  b.ls    #0xfffffff008c8620c     ; <= MARKERRAM_MEM_SIZE -> дальше
0xfffffff008c861a4  mov     w8, #0x1000
0xfffffff008c861a8  stp     x25, x8, [sp, #8]       ; лог: newHeaderSize, лимит
0xfffffff008c861ac  str     x27, [sp]
0xfffffff008c861b0  adrp    x0, #0xfffffff007519000
0xfffffff008c861b4  add     x0, x0, #0x490
0xfffffff008c861b8  adrp    x1, #0xfffffff007e2d000
0xfffffff008c861bc  ldr     x1, [x1, #0x278]
0xfffffff008c861c0  adrp    x3, #0xfffffff00751f000
0xfffffff008c861c4  add     x3, x3, #0x1d7           ; "newHeaderSize %u exceeds MARKERRAM_MEM_SIZE %u"
0xfffffff008c861c8  mov     w2, #0
0xfffffff008c861cc  bl      #0xfffffff008ca9768     ; IOLog
0xfffffff008c861d0  b       #0xfffffff008c86290     ; -> ошибка 0xe00002bc
0xfffffff008c8620c  and     w9, w25, #0xffff
0xfffffff008c86210  mov     w10, #0xaaab
0xfffffff008c86214  movk    w10, #0xaaaa, lsl #16
0xfffffff008c86218  mul     w9, w9, w10
0xfffffff008c8621c  ror     w9, w9, #2
0xfffffff008c86220  mov     w10, #0x5556
0xfffffff008c86224  movk    w10, #0x1555, lsl #16
0xfffffff008c86228  cmp     w9, w10
0xfffffff008c8622c  b.lo    #0xfffffff008c86258     ; newHeaderSize % 12 == 0
0xfffffff008c86230  ...                             ; лог "not a multiple of 12 bytes"
0xfffffff008c86258  lsr     x1, x25, #2             ; elementCount = size/4
0xfffffff008c8625c  cmp     w25, #0xf7f
0xfffffff008c86260  b.ls    #0xfffffff008c86310     ; <= capacity(0x3df*4)
0xfffffff008c86264  mov     w8, #0x3df
0xfffffff008c86268  stp     x1, x8, [sp, #8]        ; лог "elementCount ... capacity"
0xfffffff008c8626c  ...  bl 0x8ca9768  -> ошибка
0xfffffff008c86290  mov     w26, #0x448
0xfffffff008c86294  movk    w26, #0x2bc7, lsl #16
0xfffffff008c86310  add     x23, x19, #0x84         ; src = in+0x84
0xfffffff008c86314  cbz     x8, #0xfffffff008c8634c ; [in+0x30]==0 -> borrow
0xfffffff008c86318  add     x0, x21, #0x4d8
0xfffffff008c8631c  bl      #0xfffffff008c86644    ; vector::reserve(elementCount)
0xfffffff008c86320  ldr     x24, [x21, #0x4d8]      ; begin
0xfffffff008c86324  ldr     x26, [x21, #0x4e8]      ; cap
0xfffffff008c86328  and     w25, w25, #0xffc
0xfffffff008c8632c  mov     x0, x24
0xfffffff008c86330  mov     x1, x23
0xfffffff008c86334  mov     x2, x25
0xfffffff008c86338  bl      #0xfffffff008ca97f8    ; memcpy(begin, in+0x84, len)
0xfffffff008c8633c  sub     x8, x26, x24            ; cap - begin
0xfffffff008c86340  cmp     x8, x25
0xfffffff008c86344  b.ge    #0xfffffff008c86358
0xfffffff008c86348  brk     #0x800                 ; ёмкость не сошлась -> BUG
0xfffffff008c8634c  str     x23, [x21, #0x4c8]      ; borrow: ptr = in+0x84
0xfffffff008c86350  mov     w8, #0x3df
0xfffffff008c86354  str     x8, [x21, #0x4d0]       ; count = 991
```

Проверка на `%12` формально работает по младшим 16 битам (`and w9,w25,#0xffff`), но она выполняется **после** отсечения `>0x1000`, поэтому обойти её значением с ненулевой старшей половиной нельзя. Численно проверено: для 0..0xffff предикат в точности равен `x % 12 == 0` (342 значения, максимум 0xffc).

### 6.2 `startDecoder2024` — та же цепочка, другой лимит (0x8c871b0…0x8c87374)

```
0xfffffff008c871b0  cmp     w26, #1, lsl #12
0xfffffff008c871b4  b.ls    #0xfffffff008c87220
0xfffffff008c871b8  mov     w8, #0x1000
0xfffffff008c871bc  stp     x26, x8, [sp, #8]
0xfffffff008c871c0  str     x28, [sp]
0xfffffff008c871c4  adrp    x0, #0xfffffff007519000
0xfffffff008c871c8  add     x0, x0, #0x490
0xfffffff008c871cc  adrp    x1, #0xfffffff007e2d000
0xfffffff008c871d0  ldr     x1, [x1, #0x278]
0xfffffff008c871d4  adrp    x3, #0xfffffff00751f000
0xfffffff008c871d8  add     x3, x3, #0x587           ; "exceeds MARKERRAM_MEM_SIZE"
0xfffffff008c871dc  mov     w2, #0
0xfffffff008c871e0  bl      #0xfffffff008ca9768
0xfffffff008c871e4  b       #0xfffffff008c872a4
0xfffffff008c87220  and     w9, w26, #0xffff
0xfffffff008c87224  mov     w10, #0xaaab
0xfffffff008c87228  movk    w10, #0xaaaa, lsl #16
0xfffffff008c8722c  mul     w9, w9, w10
0xfffffff008c87230  ror     w9, w9, #2
0xfffffff008c87234  mov     w10, #0x5556
0xfffffff008c87238  movk    w10, #0x1555, lsl #16
0xfffffff008c8723c  cmp     w9, w10
0xfffffff008c87240  b.lo    #0xfffffff008c8726c
0xfffffff008c87244  ...                             ; лог "% 12 != 0"
0xfffffff008c8726c  lsr     x1, x26, #2
0xfffffff008c87270  cmp     w26, #0xc03
0xfffffff008c87274  b.ls    #0xfffffff008c87324
0xfffffff008c87278  mov     w8, #0x300             ; capacity = 768 u32 = 0xc00
0xfffffff008c8727c  stp     x1, x8, [sp, #8]
0xfffffff008c87280  ...  bl 0x8ca9768  -> ошибка
0xfffffff008c87324  add     x23, x19, #0x84
0xfffffff008c87328  cbz     x8, #0xfffffff008c87368
0xfffffff008c8732c  add     x0, x21, #0x4d8
0xfffffff008c87330  bl      #0xfffffff008c86644
0xfffffff008c87334  ldr     x25, [x21, #0x4d8]
0xfffffff008c87338  ldr     x8, [x21, #0x4e8]
0xfffffff008c8733c  str     x8, [sp, #0x18]
0xfffffff008c87340  and     w26, w26, #0xffc
0xfffffff008c87344  mov     x0, x25
0xfffffff008c87348  mov     x1, x23
0xfffffff008c8734c  mov     x2, x26
0xfffffff008c87350  bl      #0xfffffff008ca97f8
0xfffffff008c87354  ldr     x8, [sp, #0x18]
0xfffffff008c87358  sub     x8, x8, x25
0xfffffff008c8735c  cmp     x8, x26
0xfffffff008c87360  b.ge    #0xfffffff008c87374
0xfffffff008c87364  brk     #0x800
0xfffffff008c87368  str     x23, [x21, #0x4c8]
0xfffffff008c8736c  mov     w8, #0x300
0xfffffff008c87370  str     x8, [x21, #0x4d0]
```

Арифметика сходится: `0x84 + 0xc00 = 0xc84 <= 0xda0`, при этом хвостовые поля `+0xc84` и `+0xcac` лежат уже за скопированной областью и читаются позже (0x8c873b0), не пересекаясь с копией.

### 6.3 `startEncoderExt` — параметрическая валидация и «дыра» в `+0x08` (0x8c86c5c…0x8c86db4, 0x8c86dec…0x8c86e84)

```
0xfffffff008c86c5c  ldr     w8, [x19, #0x1c]       ; quality
0xfffffff008c86c60  and     w9, w8, #0xfffe
0xfffffff008c86c64  cmp     w9, #0xa
0xfffffff008c86c68  b.lo    #0xfffffff008c86cc8    ; 0..9 -> дальше
0xfffffff008c86c6c  mov     w9, #9
0xfffffff008c86c70  stp     x8, x9, [sp, #8]
0xfffffff008c86c74  str     x27, [sp]
0xfffffff008c86c78  adrp    x0, #0xfffffff007519000
0xfffffff008c86c7c  add     x0, x0, #0x490
0xfffffff008c86c80  adrp    x1, #0xfffffff007e2d000
0xfffffff008c86c84  ldr     x1, [x1, #0x278]
0xfffffff008c86c88  adrp    x3, #0xfffffff00751f000
0xfffffff008c86c8c  add     x3, x3, #0x418           ; "unsupported encoding quality %d ... limit is %d"
0xfffffff008c86c90  mov     w2, #0
0xfffffff008c86c94  bl      #0xfffffff008ca9768
0xfffffff008c86c98  b       #0xfffffff008c86d0c
0xfffffff008c86cc8  ldr     w8, [x19, #4]          ; inputSize
0xfffffff008c86ccc  ldr     w9, [x19, #0xc]        ; outputSize
0xfffffff008c86cd0  cmp     w8, #0xff
0xfffffff008c86cd4  b.hi    #0xfffffff008c86d84
0xfffffff008c86d84  ldr     w10, [x19, #0x14]      ; width
0xfffffff008c86d88  cmp     w9, #7
0xfffffff008c86d8c  b.lo    #0xfffffff008c86cdc    ; outputSize < 7 -> лог/ошибка
0xfffffff008c86d90  cmp     w10, #4
0xfffffff008c86d94  b.lo    #0xfffffff008c86cdc    ; width < 4
0xfffffff008c86d98  lsr     w11, w10, #0x10
0xfffffff008c86d9c  cbnz    w11, #0xfffffff008c86cdc ; width > 0xffff
0xfffffff008c86da0  ldr     w11, [x19, #0x18]      ; height
0xfffffff008c86da4  sub     w11, w11, #0x10, lsl #12
0xfffffff008c86da8  mov     w12, #-0xffff
0xfffffff008c86dac  cmp     w11, w12
0xfffffff008c86db0  b.ls    #0xfffffff008c86cdc    ; height вне [2,0xffff]
0xfffffff008c86db4  bl      #0xfffffff008c8505c    ; alloc session
...
0xfffffff008c86dec  stp     x25, x24, [x23]        ; session+0: client, wakePort
0xfffffff008c86df0  ldr     q0, [x19, #0x30]       ; 16 Б из файла
0xfffffff008c86df4  str     q0, [x23, #0x10]       ; session+0x10/0x18
0xfffffff008c86df8  ldr     x8, [x19, #0x40]
0xfffffff008c86dfc  str     x8, [x23, #0x20]       ; session+0x20
0xfffffff008c86e00  mov     w8, #1
0xfffffff008c86e04  str     w8, [x23, #0x2a8]      ; isEncoder
0xfffffff008c86e08  ldp     w8, w9, [x19]          ; +0x00, +0x04
0xfffffff008c86e0c  str     w8, [x23, #0x2ac]
0xfffffff008c86e10  ldp     w8, w10, [x19, #8]     ; +0x08, +0x0c
0xfffffff008c86e14  str     w8, [x23, #0x2b0]      ; <-- размер аллокации, БЕЗ проверки
0xfffffff008c86e18  ldp     w11, w8, [x19, #0x1c]
0xfffffff008c86e1c  and     w12, w8, #1
0xfffffff008c86e20  strb    w12, [x23, #0x310]
0xfffffff008c86e24  ubfx    w12, w8, #3, #1
0xfffffff008c86e28  strb    w12, [x23, #0x8d]
0xfffffff008c86e2c  strb    w12, [x23, #0x31c]
0xfffffff008c86e30  ubfx    w8, w8, #4, #1
0xfffffff008c86e34  str     w8, [x23, #0x318]
0xfffffff008c86e38  str     w9, [x23, #0x420]      ; inputSize
0xfffffff008c86e3c  str     w10, [x23, #0x424]     ; outputSize
```

`session+0x2b0` позже уходит в `0x8c84868`:

```
0xfffffff008c848a8  ldr     x21, [x0, #0x148]
0xfffffff008c848ac  ldr     w23, [x1, #0x2b0]      ; размер из файла
0xfffffff008c848b0  bl      #0xfffffff008ca97b8    ; current_task()
0xfffffff008c848b4  mov     x22, x0
0xfffffff008c848b8  mov     x0, x21
0xfffffff008c848bc  mov     x1, x23
0xfffffff008c848c0  mov     x2, x22
0xfffffff008c848c4  bl      #0xfffffff008ca93d8    ; buffer/descriptor по размеру
0xfffffff008c848c8  str     x0, [x19, #0x2c0]
0xfffffff008c848cc  ...
0xfffffff008c848d4  cbz     x0, #0xfffffff008c848ec ; NULL -> 0xe00002cc
```

То есть `+0x08` — единственный размер, который доходит до аллокатора без верхней границы. Это не переполнение, а поверхность memory-pressure (u32 = до 4 ГиБ на вызов, при неудаче — корректная ошибка).

## 7. Чего нет (проверено отрицательно)

- Нет сравнений с `0xffd8/0xffc0/0xffda` в регионе драйвера: 11 вхождений `0xffd8` во всём `__TEXT`+`__TEXT_EXEC` — все вне `0x8c70000…0x8c93000`; пословный поиск констант маркеров (`SOI/SOF0/DHT/SOS/DQT/EOI/DRI`) в регионе драйвера — 0 совпадений. Драйвер не сканирует JPEG-маркеры.
- Нет копий «в буфер 0x1000/0xda0»: эти числа — только размер входа/выхода в таблице и лимит в логе.
- Нет циклов `for i < field` кроме fake header; таблицы — фиксированные 0x40.
- Нет разыменований `session+0x10/0x18/0x20` (значений `+0x30/+0x38/+0x40`) в этом образе: только `cbz`.
- Нет чтений `session+0x4c8/0x4d0/0x4d8` вне парсеров и конструктора в регионе драйвера `0x8c70000…0x8c93000`.

## 8. Не подтверждено

1. `args[+0x30]` — копия или живой маппинг дескриптора (код generic IOUserClient2022 не локализован). Влияет на TOCTOU и на латентность §6.3.
2. Семантика 12-байтовых записей fake header: драйвер их не интерпретирует, только копирует; что именно ждёт MARKERRAM (маркер/длина/смещение) — по коду не восстановимо.
3. Роль `+0x08` (размер внутреннего буфера) — по коду только «размер для аллокатора»; официальное имя поля неизвестно.
4. Что `+0x30/+0x38/+0x40` — именно user-VA буферов, а не хэндлы/флаги: в образе они только проверяются на 0.
5. Есть ли потребитель `session+0x4c8` в другом kext/прошивке (в этом образе — нет).

## 9. Вердикт

**Внутренние границы четырёх парсеров корректны.** Все чтения и копии ограничены либо точным размером входа (0x1000/0xda0, проверяется диспетчером), либо собственной проверкой `newHeaderSize` (0x1000 → %12 → 0xf7f/0xc03) с дополнительным `brk`-контролем ёмкости вектора. Переполнений, OOB-чтений и целочисленных переполнений в разборе не найдено.

Риск сместился из «границ» в три других места:
1. `+0x08` → размер аллокации без верхней границы (DoS по памяти, не corruption).
2. Содержимое 12-байтовых записей fake header не валидируется вообще — весь семантический разбор уходит в железу/прошивке; поверхность для атаки на firmware-парсер, не на kernel.
3. Ветка «borrow» кладёт в сессию указатель внутрь входной структуры (`session+0x4c8`) и живёт дольше вызова (сессия ретейнит user client); потребителя в 27.2 нет, но при его появлении это UAF на маппинге входа.

Приоритет для следующего прохода: (3) — искать потребителя `+0x4c8` в прошивке/другом kext; (1) — проверить, нет ли квоты на аллокацию в `0xa902074`/`0x9c33890`.
