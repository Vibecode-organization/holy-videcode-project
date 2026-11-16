# IOSurfaceRootUserClient — аудит неинициализированных выходных буферов

**Бинарь:** `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`
**База:** `0xfffffff007004000`, offset = `va - base` (единая плоская раскладка для `__TEXT_EXEC` и `__DATA_CONST` в этом образе)
**Дата:** 2026-10-29
**Метод:** статический, capstone; все `adrp`/`b`/`bl` — со снятием знака (`& 0xFFFFFFFFFFFFFFFF`), ранние `ret` в error-ветках учтены.

---

## Вердикт (коротко)

**Подтверждённой утечки неинициализированной памяти в выходах IOSurfaceRootUserClient нет.**

Все «дыры», которые удаётся найти в объявленных размерах (`sel 28`: 28 байт, `sel 34`: 3164 байта, `sel 13`: 5 байт),
попадают в **reply-буфер MIG**, который ядро обнуляет при аллокации
(`ipc_kobject_server_internal()` → `ipc_kmsg_alloc(..., IPC_KMSG_ALLOC_ZERO | ...)`;
в xnu это есть с 4903/iOS 12 и по текущий main). Поэтому пользователь читает нули, а не остатки кучи/стека.

3176-байтные выходы (`sel 0/2/4/6/7`) защищены явно: `bzero(out, 0xC68)` в `0x9c2c18c`
(единственная функция заполнения `IOSurfaceData`), вызывается на всех успешных путях.
Скалярные выходы обнуляются дважды: `is_io_connect_method()` делает `bzero(scalar_output, count*8)`,
плюс сами обработчики обнуляют свои stack-локали; все объявленные `sOut` записываются.

Остаточный риск (не эксплуатируется сейчас): `sel 28` и `sel 34` держатся только на zeroing reply-буфера.
Если выход когда-нибудь пойдёт в необнуляемый буфер (OOL-дескриптор, снятие `IPC_KMSG_ALLOC_ZERO`,
переиспользование kmsg), это готовые infoleak'и на 28 и 3164 байта соответственно.

---

## 1. Диспетчеризация и достижимость

Таблица `IOExternalMethodDispatch2022`, stride `0x28`, 60 записей:

| | VA | назначение |
|---|---|---|
| A (полная) | `0xfffffff008068b90` | обычный клиент |
| B (урезанная) | `0xfffffff0080694f0` | `[uc+0x127] & 1 != 0` (GPU-restricted, WebContent) |

Выбор таблицы — `0x9c3ee10`:

```
0x9c3ee14  adrp x8, 0x8068000
0x9c3ee18  add  x8, x8, #0xb90        ; table A
0x9c3ee1c  ldrb w9, [x0, #0x127]      ; gpu-restricted flag
0x9c3ee20  adrp x10, 0x8069000
0x9c3ee24  add  x10, x10, #0x4f0      ; table B
0x9c3ee28  tst  w9, #1
0x9c3ee2c  csel x3, x10, x8, ne
0x9c3ee30  mov  w4, #0x3c             ; 60
0x9c3ee3c  b    0x9c498f4            ; dispatchExternalMethod
```

`checkEntitlement` (`entry+0x20`) в таблице A — NULL у всех 60 записей; per-method энтайтлментов нет.
`allowAsync` (`+0x18`) = 1 только у sel 17 и 40.

`IOExternalMethodArguments` (подтверждено по коду обработчиков):

| off | поле |
|---|---|
| `+0x20` | `scalarInput` |
| `+0x30` | `structureInput` |
| `+0x38` | `structureInputSize` |
| `+0x40` | `structureInputDescriptor` |
| `+0x48` | `scalarOutput` |
| `+0x58` | `structureOutput` |
| `+0x60` | `structureOutputSize` |
| `+0x68` | `structureOutputDescriptor` |
| `+0x78` | `structureVariableOutputData` |

### Ключевой факт про «дыры»

`args->structureOutput` в этой модели — **не** user-VA, а буфер reply-сообщения
(`is_io_connect_method()`: `args.structureOutput = inband_output`, где `inband_output` — поле reply-структуры MIG).
Reply выделяется в `ipc_kobject_server_internal()` c `IPC_KMSG_ALLOC_ZERO` и обнуляется целиком
(`bzero`/`Z_ZERO`), обработчик пишет поверх. Всё, что он не записал, пользователь получит **нулями**.

> Проверено по исходникам xnu (`osfmk/kern/ipc_kobject.c`, `osfmk/ipc/ipc_kmsg.c`):
> `xnu-4903` (iOS 12) и текущий main. В самом бинаре 27.2 символы отсутствуют, поэтому
> это **предпосылка**, а не дизасм-факт; §6 даёт способ проверить её динамически.

Скаляры: `is_io_connect_method()` делает `bzero(&scalar_output[0], *scalar_outputCnt * 8)` до вызова;
legacy `io_connect_method_scalarI_scalarO()` дополнительно обнуляет свой `_output[16]`.
Поэтому недописанный `scalarOutput[i]` — тоже нули, не утечка.

---

## 2. Сводная таблица выходов

| sel | функция | sOut | stOut | что инициализируется | дыра / статус |
|---|---|---|---|---|---|
| 0 | `0x9c3888c` → `0x9c3ab8c` | 0 | `0xC68` | `bzero(0xC68)` @`0x9c2c1fc`, затем поля из IOSurfaceClient/IOSurface | нет; **чисто** |
| 2 | `0x9c38a6c` → `0x9c3b3ac` | 0 | `0xC68` | то же (`0x9c2c18c` @`0x9c3b500`) | нет; **чисто** |
| 3 | `0x9c38a88` → `0x9c3b58c` | 0 | 4 | `IOSurface::unlock`, 4-байтный seed | нет |
| 4 | `0x9c38aa4` → `0x9c3b628` | 0 | `0xC68` | `0x9c2c18c` @`0x9c3b714` | нет; **чисто** |
| 6 | `0x9c38acc` → `0x9c3bb20` | 0 | `0xC68` | `0x9c2c18c` @`0x9c3bd84` | нет; **чисто** |
| 7 | `0x9c38adc` → `0x9c3bf44` | 0 | `0xC68` | `0x9c2c18c` @`0x9c3c1bc` | нет; **чисто** |
| 9 | `0x9c38b2c` | 0 | 4 | `0x9c3c3b8`→callee, 4 байта; слот обнулён MIG | нет |
| 10 | `0x9c38c44` | 0 | var | сериализация значения, длина точная | нет |
| 11 | `0x9c38e54` | 0 | 4 | `0x9c3c9c0`→callee, 4 байта; слот обнулён MIG | нет |
| 13 | `0x9c38f84` | 0 | `0x28` | поля `IOSurfaceRoot+0xac..0xc8`, `uc+0x126` | **5 байт** `0x21, 0x24..0x27` → нули; не подтв. |
| 26 | `0x9c39448` | 0 | var | `OSSerialize` + memcpy точной длины | нет |
| 28 | `0x9c39660` → `0x9c3d838` | 0 | `0xA0` | `memcpy(out, stack, 0x84)`; stack заполнен целиком | **28 байт** `0x84..0x9F` → нули; не подтв. |
| 30 | `0x9c3968c` | 0 | var | OSData в `structureVariableOutputData` | нет |
| 34 | `0x9c397d8` → `0x9c3b7b0` | 0 | `0xC68` | успех: `0x9c2c18c`; ветка «already imported»: 12 байт | **3164 байта** → нули; не подтв. |
| 49 | `0x9c39e0c` | 0 | var | OSData в `structureVariableOutputData` | нет |
| 51 | `0x9c39eec` | 2 | var | `0x9c4060c`, длина из фактического чтения | нет |
| 8 | `0x9c38af4` | 1 | 0 | пишет 0 | нет |
| 16 | `0x9c38ff4` | 1 | 0 | `[sp+4]` (обнулён) | нет |
| 20 | `0x9c39128` | 1 | 0 | `[sp+4]` (обнулён) | нет |
| 23 | `0x9c39248` | 1 | 0 | `[sp+4]` (обнулён) | нет |
| 25 | `0x9c393d0` | 1 | 0 | `[sp+4]` (обнулён) | нет |
| 32 | `0x9c39760` | 1 | 0 | результат виртуального вызова `[uc+0x138]` | нет |
| 35 | `0x9c397ec` | 1 | 0 | `[sp+4]` (обнулён) | нет |
| 36 | `0x9c39868` | 2 | 0 | `[sp+0x14]`, `[sp+8]` (обнулены) | нет |
| 38 | `0x9c39904` | 4 | 0 | указатели на 4 слота `scalarOutput` | нет (слоты обнулены MIG) |
| 46 | `0x9c39a78` | 2 | 0 | `[sp+0x14]`, `[sp+8]` (обнулены) | нет |
| 55 | `0x9c3a06c` | 1 | 0 | `[sp+4]` (обнулён) | нет |
| 58 | `0x9c3a128` | 3 | 0 | `[sp+0x10/0x18/0x20]` (обнулены `stp xzr,xzr`+`str xzr`) | нет |

`var` = `checkStructureOutputSize == 0xffffffff` (sel 10, 26, 30, 49, 51).

Семантика (по коду; 0/1/2/3/4/5/6 совпадают с публичными KDK-символами macOS 13):
0 `create_surface`, 1 `release_surface`, 2 `lock_surface`, 3 `unlock_surface`, 4 `lookup_surface`,
5 `set_ycbcrmatrix`, 6 `create_surface_fast_path`, 13 — getter limits/params (`IOSurfaceRoot+0xac..0xc8`),
28 — get bulk attachments (`0x84` из IOSurface expansion), 34 — import send right (`IOSurfaceLookupFromMachPort`).

---

## 3. Топ-3 (с дизасмом и точными смещениями)

### 3.1. sel 28 — `0x9c39660`: объявлено `0xA0`, записано `0x84`

> Уточнение к заданию: в этой сборке у sel 28 `checkStructureOutputSize = 0xA0` (entry `0x8068ff0`),
> а `0xC68` — у sel 0, 2, 4, 6, 7 и 34.

```
0x9c39660  ldr x8, [x2, #0x20]      ; scalarInput
0x9c39664  ldr w1, [x8]             ; surface_id
0x9c39668  ldr x8, [x2, #0x58]      ; structureOutput
0x9c3966c  add x3, x2, #0x60        ; &structureOutputSize
0x9c39670  mov x2, x8
0x9c39674  b   0x9c3d838
...
0x9c3d880  mov w8, #0x84
0x9c3d884  str x8, [sp]             ; локальный размер = 0x84
0x9c3d890  bl  0x9c26438           ; memcpy(out, stack, min(size,0x84))
0x9c3d894  ldr x8, [sp]
0x9c3d898  cmp x8, #0x84
0x9c3d89c  csel w19, wzr, w19, eq
0x9c3d8a0  mov w8, #0xa0
0x9c3d8a4  str w8, [x20]            ; *structureOutputSize = 0xA0
```

Копирование внутрях `0x9c26438`:

```
0x9c264b8  str wzr, [sp, #0x64]     ; заранее закрывает байт 0x67
0x9c264ac..0x9c26580  поля -> sp+0x00..0x83   (все 0x84 байта)
0x9c26584  ldr x23, [x19]           ; 0x84
0x9c26590  csel x22, x23, x8, lo    ; min(0x84,0x84)
0x9c26594  mov x1, sp
0x9c2659c  mov x2, x22
0x9c265a0  bl  0x9c49c74            ; memcpy -> 0xaa65b10
0x9c265c0  str x22, [x19]           ; *size = 0x84
```

**Неинициализированные байты выхода: `out+0x84 .. out+0x9F` (28 байт).**
Источник — не стек: все `0x84` байта stack-временного буфера записаны явно
(в частности `sp+0x67` закрыт `str wzr,[sp,#0x64]`). Источник — reply-буфер MIG,
который обнулён. **Статус: не подтверждено.**

Замечание: обработчик перезаписывает `args->structureOutputSize` в `0xA0` **и на error-ветке**
(поверх-лукап не удался, `0x9c3d8cc`), но там возврат `0xE00002C2` и MIG отдаёт error-reply без данных.

### 3.2. sel 34 — `0x9c397d8`: успех с 12 из 3176 байт

```
0x9c3b674  mov x2, sp
0x9c3b678  mov x0, x20               ; self
0x9c3b67c  mov x1, x22               ; surface_id
0x9c3b680  bl  0x9c3f044             ; findClient(id,&client) -> 1 = найден
0x9c3b684  tbnz w0, #0, 0x9c3b76c    ; [sel 4] найден = ошибка
...
0x9c3b874  ldr w1, [x23, #0x10]      ; id из send-right обёртки
0x9c3b87c  mov x0, x20
0x9c3b880  bl  0x9c3f044
0x9c3b884  cbz  w0, 0x9c3b8b4        ; не найден -> полное заполнение
0x9c3b888  mov  x22, #0
0x9c3b88c  mov  w19, #0              ; kIOReturnSuccess
0x9c3b890  mov  x8, #-1
0x9c3b894  str  x8, [x21]            ; out+0x00..0x07 = 0xFFFFFFFFFFFFFFFF
0x9c3b898  ldr  x8, [sp, #0x10]
0x9c3b89c  ldr  w8, [x8, #0x38]      ; IOSurfaceID
0x9c3b8a0  str  w8, [x21, #0x18]     ; out+0x18..0x1B = ID
0x9c3b8a4  b    0x9c3b970           ; unlock -> return 0
```

**Неинициализированные байты: `out+0x08..0x17` (16) и `out+0x1C..0xC67` (3148) = 3164 байта.**
Это ветка «объект уже импортирован» (`IOSurfaceLookupFromMachPort` по send-right):
`out[0] = -1` (адрес не картирован), `out[0x18] = surfaceID`, остальное не заполняется.
Reply-буфер обнулён → нули. **Статус: не подтверждено.**

### 3.3. sel 13 — `0x9c38f84`: 5 байт из 0x28

```
0x9c38f88  ldr x8, [x2, #0x58]       ; out
0x9c38f8c  ldr x9, [x0, #0xe8]       ; IOSurfaceRoot*
0x9c38f90  ldur d0, [x9, #0xac]
0x9c38f94  str  d0, [x8]             ; 0x00..0x07
0x9c38f98  ldur q0, [x9, #0xb8]
0x9c38f9c  stur q0, [x8, #8]         ; 0x08..0x17
0x9c38fa0  ldr  x9, [x9, #0xc8]
0x9c38fa4  str  x9, [x8, #0x18]      ; 0x18..0x1F
0x9c38fa8  ldrb w9, [x0, #0x126]
0x9c38fac  and  w9, w9, #1
0x9c38fb0  strb w9, [x8, #0x20]      ; 0x20
0x9c38fb4  mov  w9, #1
0x9c38fb8  strh w9, [x8, #0x22]      ; 0x22..0x23
0x9c38fbc  mov  w8, #0x28
0x9c38fc0  str  w8, [x2, #0x60]      ; *structureOutputSize = 0x28
```

**Не записано: `out+0x21` (1) и `out+0x24..0x27` (4) = 5 байт** (вероятно padding структуры).
Reply-буфер обнулён → нули. **Статус: не подтверждено.**

---

## 4. Чистые пути (для полноты)

- `sel 0/2/4/6/7`: единственная функция заполнения `IOSurfaceData` — `0x9c2c18c`.
  Первое, что она делает: `mov x0,x19; mov w1,#0xC68; bl bzero (0xaa65cc0)` (`0x9c2c1f8..0x9c2c1fc`).
  Все 6 call-site'ов (`0x9c3ae9c, 0x9c3b500, 0x9c3b714, 0x9c3b968, 0x9c3bd84, 0x9c3c1bc`) — успешные пути.
  Поля после bzero: `IOSurfaceClient+0x38/0x50/0x60`, `IOSurface+0x58/0x68/0x78/0x80/0x90/0x9c/0x378/0x380/0x3ac/0x3d0`,
  плюс до 20 plane-записей по 0x98 (копирование 0x38 байт + bzero остального).
- `sel 28`: stack-структура 0x84 заполняется полностью (все поля + `str wzr` на `0x64`, закрывающий `0x67`);
  memcpy-источник инициализирован. Дыра только в приёмнике.
- `sel 34` основная ветка: `0x9c2c18c` → `bzero(0xC68)`.
- Скаляры: обработчики обнуляют `[sp+4]` / `[sp+8]` / `[sp+0x10..0x20]` до вызова callee
  (`0x9c39020`, `0x9c39274`, `0x9c393fc`, `0x9c39818`, `0x9c39894`, `0x9c39ac0`, `0x9c39ac4`,
  `0x9c3a09c`, `0x9c3a170..0x9c3a174`), поэтому даже если callee ничего не записал — уйдёт 0.

---

## 5. Что утекало бы, если бы не zeroing reply-буфера

| sel | объём | что это было бы |
|---|---|---|
| 34 (ветка «уже импортирован») | 3164 Б | остаток reply-kmsg: заголовок/хвост предыдущих сообщений, возможные kernel pointers |
| 28 | 28 Б | хвост reply-kmsg за `inband_output[0x84]` |
| 13 | 5 Б | padding reply-структуры |

Для `sel 28` и `sel 13` это **не стек**, а kmsg-куча.
Стековых утечек в audited-путях нет: единственный `memcpy` из стека (`0x9c265a0`) копирует
полностью инициализированный буфер.

---

## 6. Чем подтверждать (если понадобится динамика)

1. `sel 28` (`IOConnectCallMethod`, sIn=1 — ID существующей поверхности, stOut=`0xA0`):
   проверить, что байты `0x84..0x9F` ответа — нули. Если там ненулевые хвосты — zeroing в этой сборке не работает.
2. `sel 34` по send-right на уже импортированную поверхность: байты `0x08..0x17` и `0x1C..0xC67` должны быть нулями.
3. `sel 13`: байты `0x21`, `0x24..0x27` — нули.
4. Контроль zeroing: любой селектор с заведомо неполным заполнением (например, `sel 13`) — если padding не нулевой,
   гипотеза о `IPC_KMSG_ALLOC_ZERO` в 27.2 неверна и топ-3 становится реальными утечками.

---

## 7. Приложение: адреса

| что | VA |
|---|---|
| таблица A | `0xfffffff008068b90` |
| таблица B | `0xfffffff0080694f0` |
| выбор таблицы | `0x9c3ee10` (флаг `uc+0x127`) |
| `bzero` | `0xaa65cc0` (стаб `0x9c49b94`) |
| `memcpy` | `0xaa65b10` (стаб `0x9c49c74`/`0x9c49c84`) |
| заполнение IOSurfaceData | `0x9c2c18c` |
| sel 0 | `0x9c3888c` → `0x9c3ab8c` |
| sel 2 | `0x9c38a6c` → `0x9c3b3ac` |
| sel 4 | `0x9c38aa4` → `0x9c3b628` |
| sel 6 | `0x9c38acc` → `0x9c3bb20` |
| sel 7 | `0x9c38adc` → `0x9c3bf44` |
| sel 13 | `0x9c38f84` |
| sel 28 | `0x9c39660` → `0x9c3d838` → `0x9c26438` |
| sel 34 | `0x9c397d8` → `0x9c3b7b0` |
| sel 58 | `0x9c3a128` |

Скрипты аудита: `macho.py`, `kdis.py`, `ldis.py`, `refs.py`, `stubs.py`, `table.py`, `diffkc.py`.
