# IOGPUDeviceUserClient, селекторы 52/53 (`0x99491a0` / `0x9949330`), 27.2 (24B115)

**Вердикт: дыры нет.** Ни info leak, ни OOB read, ни OOB write, ни DoS в разобранном пути.
Заявленные «`u32 [structureInput]` и `u32 [structureInput+8]` без проверки размера» — это
`scalarInput[0]` и `scalarInput[1]` (args+0x20), а не structureInput (args+0x30); сам structureInput
проверяется ровно на `count * sizeof(element)` байт перед каждым чтением, и ни один
пользовательский индекс не выходит за границу таблицы объектов.

Разбор — по бинарю `27.2_24B115_kernelcache` (67 239 936 байт). Все адреса — VA,
`__TEXT_EXEC` (offset = `va - 0xfffffff007004000`), `__DATA_CONST` (offset = `0xbb4000 + (va - 0xfffffff007bb8000)`).

---

## 1. Идентификация методов

По `__func__`-строкам, которые методы кладут в лог при ошибке:

| sel | VA | `__func__` | строка лога |
|---|---|---|---|
| 52 | `0xfffffff0099491a0` | `0xfffffff00782b0bb3` → `static IOReturn IOGPUDeviceUserClient::s_group_add_resources(IOGPUDeviceUserClient *, void *, IOExternalMethodArguments *)` | `0x78315d1` `"%s failed to add resources to group\n"` |
| 53 | `0xfffffff009949330` | `0xfffffff00782b0c2e` → `...::s_group_remove_resources(...)` | `0x7831612` — та же строка `"failed to add resources to group"` (copy-paste у Apple) |

Обе — `IOExternalMethodAction`: `(x0=target=юзер-клиент, x1=reference, x2=IOExternalMethodArguments*)`.

## 2. Таблицы и достижимость

`IOGPUDeviceUserClient::externalMethod` = `0xfffffff00994a1e0` (единственный код, который ссылается
на обе таблицы; сигнатура `(x0=uc, w1=selector, x2=args)`; рядом метакласс-конструкторы
`0x9946b70`/`0x9946cb4` со строкой `"IOGPUDeviceUserClient"`):

```
0x994a1e0  mov  w8, #0x2c2 ; movk w8,#0xe000     ; kIOReturnBadArgument
0x994a1e8  ldrb w9,[x0,#0x100]
0x994a1ec  tbz  w9,#0, 0x994a26c                 ; [uc+0x100]&1 == 0 -> return 0xe00002d8
0x994a1f0  cmp  w1,#0x37 ; b.hi 0x994a278        ; selector <= 55
0x994a1f8  ldr  x9,[x2,#0x10] ; cbnz x9, 0x994a270   ; args+0x10 должен быть 0, иначе BadArgument
0x994a200  ldrb w8,[x0,#0x103]
0x994a208  umull x9,w1,#0x18                     ; entry = table + sel*24
0x994a20c  adrp x10,0x7fea000 ; add x10,#0x740    ; restricted table
0x994a228  adrp x10,0x7fea000 ; add x10,#0x200    ; full table
0x994a244  tst  w8,#1
0x994a248  csel x3, x11(restricted-entry), x12(full-entry), ne
0x994a268  braa x16  -> generic dispatch (x0=uc, x1=sel, x2=args, x3=entry, x4=uc)
```

Таблицы (stride 24, `IOExternalMethodDispatch`):

* полная `0xfffffff007fea200`, 56 записей, `0x7fea200..0x7fea740`;
* «урезанная» `0xfffffff007fea740`, **тоже 56 записей**, `0x7fea740..0x7feac80`;
  в ней 21, 27..34, 36..54 подменены заглушкой `0xfffffff009945520`
  (`mov w0,#0x2e2; movk w0,#0xe000; ret` = `kIOReturnNotPermitted`), живые — 0..20, 22..26, 35, 55.

Записи 52/53 **идентичны в обеих таблицах по метаданным**, но в урезанной `fn` = заглушка:

```
full[52] = { fn 0xfffffff0099491a0, scIn=2, stIn=0xffffffff, scOut=0, stOut=0 }
full[53] = { fn 0xfffffff009949330, scIn=2, stIn=0xffffffff, scOut=0, stOut=0 }
restr[52]= { fn 0xfffffff009945520, scIn=2, stIn=0xffffffff, ... }   ; NotPermitted
restr[53]= { fn 0xfffffff009945520, scIn=2, stIn=0xffffffff, ... }   ; NotPermitted
```

`stIn = 0xffffffff` = `kIOUCVariableStructureSize` — «фиксированного размера нет, метод проверяет сам»,
а не «проверки нет».

**Кто получает полную таблицу.** `[uc+0x103]` пишется в `deviceUserClientStart`:

```
0x9949ea8  ldr  x0,[x19,#0x120]        ; IOGPUDevice
0x9949eac  bl   0x99658e8
0x9949eb0  strb w0,[x19,#0x103]
```

`0x99658e8`: `if (entitled("com.apple.private.graphics-restart-no-kill")) return 1;`
иначе tail-call `0x9964e38(device, "com.apple.developer.gpu-restricted")`.
`0x9964e38` — лоченный запрос через лениво создаваемый объект `[device+0x68]`
(создаётся `0x9965780` по имени сервиса `"AppleMobileFileIntegrity"`, строка `0x782de7b`):
`vt+0x138(name)` → объект (нет объекта → 0) → `0x99846cc(obj, g)` → `vt+0x88()` → u32.
Обе строки — entitlement-домены (`com.apple.private.*` / `com.apple.developer.*`), поэтому по смыслу
это проверка энтайтлмента задачи через AMFI-объект; точная семантика слота `0x138`
(`copyProperty` vs `hasEntitlement`) не подтверждена — для вердикта это не важно.

Итог: **задача без этих энтайтлментов получает полную таблицу 56 селекторов** → sel 52/53 ей
доступны; задача с энтайтлментом получает урезанную, где 52/53 = `0xe00002e2`.
Полярность совпадает с отчётом subagent J.

## 3. ABI `IOExternalMethodArguments` в 27.2 (эмпирически, по коду методов)

| offset | поле | доказательство |
|---|---|---|
| +0x20 | `const uint64_t *scalarInput` | sel 7 (`scIn=1`) `0x99479dc: ldr x8,[x2,#0x20]; ldr w20,[x8]`; sel 28 (`scIn=0`) `0x99481fc` делает то же **без** null-чека |
| +0x28 | `uint32_t scalarInputCount` | напрямую не видно; вывод по симметрии с +0x48/+0x50 и по тому, что +0x20 — указатель на массив скаляров |
| +0x30 | `const void *structureInput` | sel 26 (`stIn=0xc`) `0x994809c: ldr x21,[x2,#0x30]` |
| +0x38 | `IOByteCount structureInputSize` | sel 52/53, §4 |
| +0x40 | `IOMemoryDescriptor *structureInputDescriptor` | sel 8, sel 52/53 |
| +0x48 | `uint64_t *scalarOutput` | sel 26 `0x99480d0: ldr x9,[x19,#0x48]; str x8,[x9]` |
| +0x50 | `uint32_t scalarOutputCount` | — |
| +0x58 | `IOMemoryDescriptor *structureOutputDescriptor` | sel 8 `0x9947a84: ldr x23,[x2,#0x58]` |

Ключевое: **`args+0x20` и `args+0x30` — разные указатели**. `[si]`/`[si+8]` из отчёта J — это
`scalarInput[0]`/`scalarInput[1]`, а не structureInput. Что `scalarInput` всегда валиден даже при
`scalarInputCount==0`, видно по sel 28 (`scIn=0`), который дергает `[x2,#0x20]` без проверки на NULL:
иных вариантов, кроме «ядро всегда даёт валидный буфер скаляров (стандартные 16×u64)», быть не может —
иначе каждый вызов sel 28 падал бы.

## 4. Полный дизасм sel 52 (`0xfffffff0099491a0`)

```
0x99491a0  bti c ; pacibsp
0x99491a8  sub sp,sp,#0x60 ; ... пролог, x25=args, x22=self(uc)
0x99491cc  w19 = 0xe00002c2                    ; kIOReturnBadArgument (дефолт)
0x99491d4  ldr  x8,[x2,#0x20]                  ; x8 = args->scalarInput
0x99491d8  ldr  w23,[x8]                       ; w23 = scalar[0]  (group id)
0x99491dc  ldr  w21,[x8,#8]                    ; w21 = scalar[1]  (count)
0x99491e0  ldr  x0,[x2,#0x40]                  ; structureInputDescriptor?
0x99491e4  cbz  x0, 0x9949258                  ; нет -> прямой путь

; --- путь через дескриптор ---
0x99491e8  ldr  x16,[x0] ; autda ...
0x99491f8  ldr  x8,[x16,#0xe8]!
0x99491fc  mov  w1,#0x1000
0x9949204  blraa x8,x16                        ; obj = desc->vt[0xe8](desc, 0x1000)
0x9949208  cbz  x0, 0x99492e0                  ; fail -> log "map arguments", ret 0xe00002c8
0x9949210  ldr  x16,[x0] ; autda ...
0x9949220  ldr  x8,[x16,#0x78]!
0x9949228  blraa x8,x16                        ; x24 = obj->vt[0x78]()  (указатель на байты)
0x9949230  ldr  x0,[x25,#0x40]
0x9949244  ldr  x8,[x16,#0xb0]!
0x994924c  blraa x8,x16                        ; x0 = desc->vt[0xb0]()  (длина)
0x9949250  cbnz x24, 0x9949268
0x9949254  b    0x9949288

; --- прямой путь (in-band structureInput) ---
0x9949258  mov  x20,#0                        ; (нет mapping-объекта)
0x994925c  ldr  w0,[x25,#0x38]                ; w0 = (u32)structureInputSize
0x9949260  ldr  x24,[x25,#0x30]               ; x24 = structureInput
0x9949264  cbz  x24, 0x9949288                ; NULL -> BadArgument

; --- единственная проверка размера ---
0x9949268  cmp  x0, x21, lsl #2               ; size >= count*4 ?
0x994926c  b.lo 0x9949288                     ; нет -> BadArgument

0x9949270  ldr  x0,[x22,#0x120]               ; x0 = uc->device
0x9949274  mov  x1, x23                       ; x1 = scalar[0] (group id)
0x9949278  mov  x2, x24                       ; x2 = structureInput
0x994927c  mov  x3, x21                       ; x3 = count
0x9949280  bl   0xfffffff009967e24            ; group_add_resources(device, gid, ids, n)
0x9949284  mov  x19, x0

0x9949288  cbz  x20, 0x99492ac                ; release mapping-объекта, если был
0x994928c..0x99492a8  [x20 vt+0x28]
0x99492ac  cbz  w19, 0x9949310                ; успех -> return 0
0x99492b0..0x99492dc  log "failed to add resources to group"
0x9949310  mov  x0,x19 ; epilogue ; retab
```

Замечания:

* `cmp x0, x21, lsl #2` — 64-битное беззнаковое сравнение; `w21` при `ldr w21` расширен нулями,
  `lsl #2` в x-регистре не переполняется (max `0x3_FFFF_FFFC`).
* `ldr w0,[x25,#0x38]` берёт только младшие 32 бита `structureInputSize`. Усечение безопасно:
  при реальном размере > 4 ГиБ младшие 32 бита могут только «недобрать» — но тогда буфер всё равно
  не меньше `count*4`, а чтений ровно `count*4`.
* Ветка дескриптора проверяет длину *дескриптора* (`vt+0xb0`) тем же `cmp`, а на вход worker'а
  отдаёт указатель из `vt+0x78`.
* Никаких `[structureInput+8]`-чтений помимо элементов массива нет.

## 5. Полный дизасм sel 53 (`0xfffffff009949330`) и дифф с 52

Байт-в-байт совпадает с sel 52 — из 0x18c байт различаются 8 слов, и все они ожидаемые:

```
0x9949268  cmp x0, x21, lsl #2   ->  lsl #3        ; size >= count*8 вместо count*4
0x9949280  bl  0x9967e24         ->  0x9967f2c     ; remove-путь вместо add
0x99492b4 / 0x99492e4  __func__: s_group_add_resources -> s_group_remove_resources
0x99492d0 / 0x9949300  строка лога 0x78315d1 -> 0x7831612 (тот же текст "failed to add ...")
0x99492d8 / 0x9949308  PC-relative bl на общий 0x9984c2c (сдвиг из-за адреса функции)
```

`0x9967f2c` (remove-путь):

```
0x9967f2c  mov x21,x3 (count) ; mov x22,x2 (buf)
0x9967f54  ldr x0,[x0,#0x10] ; bl 0x9945040     ; obj = таблица->lookup_ref(scalar[0])  (см. §6.2)
0x9967f5c  cbz x0 -> BadArgument
0x9967f64  ldrb w8,[x0,#0x10] ; cmp #3 ; b.ne -> BadArgument   ; state группы
0x9967f70  bl 0xfffffff0099569fc               ; remove(obj, ids, count)
0x9967f84  [obj vt+0x28]                        ; release
```

`0x9569fc` — хэш-поиск по u64-ключам: `0x956a94: ldr x9,[x26,x25,lsl #3]` (ровно 8 байт на элемент),
далее `mul` на константу `0x9e3779b97f4a7c15`-класса, `lsr` на `[tab+0x2c]`, маска `[tab+0x20]-1`,
обход цепочки, сравнение ключа `cmp x15,x9`, декремент счётчика ссылок и удаление при нуле.
Индекс бакета всегда `& (nbuckets-1)` → в границах; произвольный id просто не находится.

Итого 53 — это remove по 64-битным id, 52 — add по 32-битным id. Проверки размера совпадают
с шириной элемента в обоих случаях (4 и 8 байт).

## 6. Callee sel 52: `0xfffffff009967e24`

```
0x9967e24  mov x21,x3 (count) ; mov x22,x2 (ids) ; mov x23,x0 (device)
0x9967e50  w20 = 0xe00002c2
0x9967e58  ldr x0,[x0,#0x10] ; bl 0x9945040     ; group = lookup_ref(device->table, scalar[0])
0x9967e60  cbz x0 -> return BadArgument
0x9967e68  cmp x21,#0x80, lsl #12 ; b.hi        ; count <= 0x80000 (4 МиБ под массив)
0x9967e70  ldrb w8,[x19,#0x10] ; cmp #3 ; b.ne  ; group->state == 3
0x9967e7c  lsl x24,x21,#3                       ; alloc = count*8
0x9967e80  adrp x0,0x7ff1000 ; add #0x6d8 ; mov x1,x24 ; bl 0x998431c   ; IOMalloc
0x9967e90  cbz x0 -> 0xe00002bd (NoMemory)
0x9967e98  [x19 vt+0x20]                        ; lock/retain группы
0x9967eb8..0x9967ecc  bl 0xfffffff009967bc0     ; worker(device, group, arr, ids, count)
0x9967ed4  bl 0x998425c(0x7ff1028, x25, count*8) ; free(arr)
0x9967ef0  [x19 vt+0x28]                        ; unlock/release
0x9967f10  return x20
```

### 6.1 worker `0xfffffff009967bc0`

```
0x9967bf0  bl 0x994463c                    ; lock(device->[0x10])
0x9967bfc  cbz x21, done                   ; count==0
loop:
0x9967c00  ldr  w1,[x23,x24,lsl #2]        ; id = ((u32*)structureInput)[i]   <-- ровно 4 байта
0x9967c08  bl   0x9945214                  ; r = table[id]  (bounds-checked, §6.2)
0x9967c0c  str  x0,[x20,x24,lsl #3]        ; arr[i] = r   (arr = count*8, i<count)
0x9967c10  cbz  x0 -> cleanup(BadArgument)
0x9967c14  ldrb w8,[x0,#0x10] ; cmp #3 ; b.eq cleanup   ; state
0x9967c20..0x9967c38  [r vt+0x20]          ; retain
0x9967c3c  add x24,x24,#1 ; cmp x21,x24 ; b.ne loop
done/cleanup:
0x9967c48  bl 0x9944648                    ; unlock
0x9967c68..0x9967c7c  cmp x21,#0x100
0x9967c7c  bl 0x9956c5c                    ; group_add_resources(group, arr, n)   (n<=0x100)
0x9967c94  bl 0x99561c4                    ; то же для n>0x100
0x9967ca4  on cleanup: [arr[i] vt+0x28] (release) по уже добавленным
```

В `0x9956c5c` по каждому объекту: `ldr x23,[obj,#0x70]` (ключ), хэш-вставка, `[bucket]+=1`,
`[obj vt+0x20]` (retain), и на замещении/ошибке `[old vt+0x28]` (release). Классово-специфичных
виртуальных вызовов по объекту из таблицы нет — только `retain`/`release` (`vt+0x20`/`vt+0x28`).

### 6.2 lookup `0x9945214` / `0x9944fb8` — границы

```
0x9945214  cbz  w1, miss              ; id == 0 запрещён
0x994521c  ldr  w8,[x0,#0x28]         ; count = table->count
0x9945220  cmp  w1,w8
0x9945224  b.hs miss                  ; id >= count -> miss
0x9945228  ldr  x8,[x0,#0x10]         ; base = table->base
0x994522c  ubfiz x9,x1,#3,#0x20       ; off = id*8  (32-битный id, без переполнения)
0x9945244  ldr  x0,[x8 + id*8]        ; element
0x9945248  ret
```

`0x9944fb8` — то же самое + `ldadd w9,[p+0xc]` (atomic ++ ссылок, порог `0xffffff`).
Обе функции возвращают 0 на `id==0`, `id>=count`, `element==NULL`.

**Арифметика:** `element = *(u64*)(table->base + (u64)id * 8)`, `id ∈ [1, table->count)`,
`table->count = *(u32*)(table+0x28)`, `table->base = *(u64*)(table+0x10)`.
Никакого «индекса из `[si]`» тут нет: `scalar[0]` — это id группы, он идёт в тот же
bounds-checked lookup (`0x9945040`→`0x9944fb8`); id ресурсов берутся из structureInput и тоже
проверяются.

## 7. Что контролирует пользователь → что происходит

| вход | где | обработка | эффект |
|---|---|---|---|
| selector | `0x994a1f0` | `<= 0x37` | иначе ветка на generic dispatch |
| `args+0x10` | `0x994a1f8` | должен быть 0 | иначе `0xe00002c2` |
| `[uc+0x103]` (энтайтлмент) | `0x994a244` | выбор таблицы | с энтайтлментом 52/53 → `0xe00002e2` |
| `scalar[0]` | `0x99491d8` → `0x9967e58` | lookup_ref по id | `0`/`>=count`/`NULL` → `0xe00002c2` |
| `scalar[1] = count` | `0x99491dc` | `size >= count*4` (52) / `*8` (53); в 52 ещё `count <= 0x80000` | иначе `0xe00002c2` |
| `structureInput` | `0x9949260` | `cbz` | NULL → `0xe00002c2` |
| `structureInputSize` | `0x994925c` | сравнение с `count*4`/`*8` | меньше → `0xe00002c2` |
| `structureInputDescriptor` | `0x99491e0..0x9949250` | vtable: bytes+len, тот же `cmp` | — |
| элементы массива (id) | `0x9967c00` / `0x956a94` | lookup, `id!=0 && id<count` | miss → `0xe00002c2` |
| state группы/ресурса | `0x9967e70` / `0x9967c14` | `== 3` | иначе `0xe00002c2` |
| — | — | — | наружу только `kIOReturn`, `stOut=0`, `scOut=0` |

## 8. Разбор гипотез

**(а) «чтение 4 байт за буфером».** Нет. 52 читает `ldr w1,[buf + i*4]` для `i = 0..count-1`,
последнее чтение — байты `[4count-4, 4count)`, а перед вызовом стоит `size >= 4*count`
(`0x9949268`). 53 — `ldr x9,[buf + i*8]`, проверка `size >= 8*count` (`0x99493f8`).
Дескрипторная ветка проверяет длину дескриптора тем же сравнением.

**(б) «OOB-индекс → чтение произвольного поля/запись».** Нет. `0x9945214`/`0x9944fb8` проверяют
`id != 0 && id < count` до `ldr x0,[base + id*8]`; выходного буфера у методов нет (`stOut=0`),
поэтому и «утечки через индекс» нет — значение наружу не возвращается.

**(в) «без последствий».** Да, для 52/53 это корректная оценка. Единственное, что стоит держать
в голове (не memory-safety): id из structureInput не проверяется на *тип* объекта — в таблицу
`[device+0x10]` свалены и группы, и ресурсы, поэтому в `group_add_resources` можно подсунуть id
объекта другого класса. Диспетчеризация при этом остаётся `retain`/`release` (`vt+0x20`/`vt+0x28`),
классовых вызовов по этому объекту нет; реального impact не подтверждено.

## 9. Поправки к отчёту subagent J

1. `ldr w23,[si]` / `ldr w21,[si+8]` — это `args+0x20` = **scalarInput**, не structureInput
   (`args+0x30`). Доказательство: sel 28 (`scIn=0`) читает `args+0x20` без null-чека (`0x99481fc`),
   sel 26 (`stIn=0xc`) читает `args+0x30` как 12-байтную структуру (`0x994809c`).
2. «обработчики structureInputSize не читают вообще» — неверно: `0x994925c`/`0x99493ec` читают
   и сравнивают с `count*4`/`count*8`.
3. «`[si]` уходит индексом в `0x9967e24`» — `scalar[0]` идёт не индексом массива, а id группы
   в bounds-checked lookup (`0x9945040` → `0x9944fb8`); индексы элементов — id из structureInput,
   тоже bounds-checked (`0x9945214`).
4. Про таблицу: она не «28 селекторов», а 56 записей, где 21, 27..34, 36..54 — заглушки
   `0x9949520`; живые 0..20, 22..26, 35, 55. На вывод о достижимости это не влияет.

## 10. Что не подтверждено

* Локализовать в бинаре сам generic dispatch (проверку `scIn`/`scOut` из записи таблицы) не удалось:
  tail-call из `0x994a1e0` идёт через vtable-слот (`[0x7ff27d0]+0x550`), цепочка PAC-указателей
  в `__DATA_CONST` для этого слота не разрешилась в начало функции. Поэтому «`scIn==2` проверяется
  диспетчером» — вывод по стандартному контракту `IOExternalMethodDispatch` + по тому, что методы
  с `scIn=0` (sel 28) свободно дереференсят `args+0x20` (значит буфер скаляров всегда валиден и
  фиксированного размера). На вердикт это не влияет: даже при отсутствии проверки читаются только
  `scalar[0..1]` из этого валидного буфера, а значения идут в bounds-checked lookup и в проверку размера.
* Точные имена слотов `vt+0xe8`/`vt+0x78`/`vt+0xb0` в дескрипторной ветке (`IOMemoryDescriptor`-семейство)
  — по смыслу (bytes + length), не по символам.
* Судьба ссылок при частичном отказе `group_add_resources` (утечка ref'ов на error-пути) — не аудирована.

## 11. Рецепт вызова (для negative-теста на устройстве)

Юзер-клиент `IOGPUDeviceUserClient` (реальный класс в 27.2, объект 0x130 байт; гейт `open`/`newUserClient`
самого `IOGPUDevice` в этой задаче не разбирался — считаем, что клиент доступен app-процессу, как обычно
у GPU-клиентов), `IOConnectCallMethod(sc, sel, ...)`:

* sel 52: `scalarInput = { group_id, n }` (обязательно 2 скаляра), `structureInput` = `n` × u32
  (id ресурсов), `structureInputSize = 4n`.
  * `size < 4n` → `0xe00002c2` (до чтения буфера);
  * `group_id == 0` или `>= table->count` → `0xe00002c2`;
  * `n > 0x80000` → `0xe00002c2`;
  * id `0` или отсутствующий в таблице → `0xe00002c2`;
  * корректный набор → `0` (ресурсы добавлены в группу), наружу ничего не отдаётся.
* sel 53: то же с `structureInput` = `n` × u64 и `size = 8n`.

Ожидаемо: ни паники, ни утечки, ни записи за буфер; отказы — только кодами возврата.

## 12. Артефакты

* `work/parse_iogpu/kc.py` — маппинг VA↔offset, дизасм (capstone 5.0.7), PAC-декод `BASE + (q & 0x0FFFFFFF)`.
* `work/parse_iogpu/progress.md` — журнал шагов.
