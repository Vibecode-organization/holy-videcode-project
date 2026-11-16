# IOSurface — сеттеры свойств, аудит (iOS 27.2, 24B115)

Объект: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache` (67 239 936 B)
Метод: статика, capstone/arm64e. Символов в кеше нет (LC_SYMTAB пуст), границы функций
взяты из `LC_FUNCTION_STARTS` самого кеста `com.apple.iokit.IOSurface`
(header `0xfffffff00789a030`, fo `0x896030`, 1330 функций, `__text`
`0xfffffff009c14f20..0xfffffff009c49554`).

Обозначение адресов: ниже — полные VA `0xfffffff0…`; в тексте сокращаю до `0x9c…`
(это те же значения, что в задании: `0x9c3ab8c` = `0xfffffff009c3ab8c`).

---

## 0. Поправки к исходной вводной

1. **Таблица диспетчера подтверждена**: `0xfffffff008068b90`, stride `0x28`, ровно 60 записей.
   Формат записи: `+0x00` PAC-указатель на обработчик, `+0x08` `{u32 scalarIn, u32 structIn}`,
   `+0x10` `{u32 scalarOut, u32 structOut}`, `+0x18/+0x20` нули.
2. Номера селекторов из вводной совпали, а вот адреса — нет: в таблице лежат **трамплины**,
   а не реализации. Реальные цепочки:
   - sel 27 → `0x9c39654` (`ldr x1,[args+0x30]`; `b 0x9c3d7c8`) → **`0x9c3d7c8`** ✔ совпало;
   - sel 28 → `0x9c39660` → **`0x9c3d838`** ✔;
   - sel 34 → `0x9c397d8` (`b 0x9c3b7b0`) → **`0x9c3b7b0`** ✔.
   То есть «27/28/34» в задании — это адреса *внутренних* функций, они верны.
3. `vtable+0x138` = **`getObject(key)`**. Подтверждено по сигнатуре вызова в
   `0x9c1fec4` (getBool): `dict->vtable[0x138](dict, key)` → объект, затем `obj->vtable[0x88]()`.
4. PAC-формула из вводной проверена: слот `0x806c618` → `0xfffffff00a8d8754`
   (это и есть `OSUnserializeXML`). Трамплин: `adrp x17; add x17,#imm; ldr x16,[x17]; braa x16,x17`.

---

## 1. Путь «словарь → IOSurface»

```
sel 0 (0x9c3888c)  IOSurfaceRootUserClient::create_surface
  args+0x20  scalar[0]                     — surface id/флаги (проверка: старшие 32 бита == 0)
  args+0x40  IOMemoryDescriptor*  -> map + length      ┐ один из двух путей
  args+0x30  buf, args+0x38 len                        ┘
  0x9c3ab8c  create_surface(this, buf, len, out, mapped_len)
      0x9c49764 -> 0xa8d8754   OSUnserializeXML(buf,len)      [слот 0x806c618]
      0x9c498d4 -> …           требует OSDictionary (иначе выход)
      0x9c498d4               getObject(gSymbol@0x8066fc0)
      0x9c33c34  create_surface_internal(iosurfaceRoot, port, dict, out)
          0x9c1a914  IOSurface::init(this, root, port, dict, extra)
              0x9c16670  склейка словарей (dict -> this+0x378, this+0x268)
              0x9c1af14  IOSurface::initWithProperties(this, dict)   <-- ЯДРО, 0x3710 байт
```

Побочный путь, важный ниже:

```
sel 7 (0x9c38adc)  create_surface_client_mem(this, addr, size, out)
  0x9c38ae0  ldr  x8,[x2,#0x20]      ; массив скаляров
  0x9c38ae4  ldp  x1,x8,[x8]         ; x1 = scalar[0] = АДРЕС, x8 = scalar[1] = РАЗМЕР
  0x9c38aec  mov  x2,x8
  0x9c38af0  b    0x9c3bf44
      0x9c3c044..0x9c3c058  dict->setObject("IOSurfaceAddress",  OSNumber(addr,64))
      0x9c3c0ac..0x9c3c0c0  dict->setObject("IOSurfaceAllocSize",OSNumber(size,64))
      -> 0x9c33c34 create_surface_internal(...)  (тот же init)
```

## 2. Семейство геттеров (все проверки ширины — здесь)

| адрес | что | поведение |
|---|---|---|
| `0x9c1fec4` | `getBoolProperty(dict,key,&b)` | `getObject` → `vt+0x88` → `strb` |
| `0x9c20038` | `getU64Property(dict,key,&u64)` | `getObject` → `vt+0x88` = число бит, `vt+0xb0` = значение; если бит<64 и знаковый бит выставлен — **знаковое расширение** |
| `0x9c1ff50` | `getU32Property` | `getU64`, затем `lsr x9,x8,#32; cbnz` → «IOSurface: %s exceeds maximum value» (`0x789a0321`), возврат 0 |
| `0x9c20114` | `getU8Property` | `cmp x8,#0xff; b.hi` → та же ошибка |
| `0x9c20288` | `getU32Property` (required) | отличие: при отсутствии ключа пишет «IOSurface: Required property %s missing» (`0x789a0413`) |
| `0x9c203b0` | специальный (AddressRanges) | отдельный разбор массива |

Вывод по геттерам: значение не может быть «шире», чем ждёт поле, но **само по себе ни с чем
не сверяется** — сверка целиком в `initWithProperties`.

## 3. Таблица ключей

`cmp`-адрес = место, где ключ материализуется (`adrp/add` строки) и сразу вызывается геттер.

| ключ | адрес сравнения | что делает | проверка размера | вердикт |
|---|---|---|---|---|
| `IOSurfaceWidth` | `0x9c1c810` | `str x8,[this+0x58]` (u64) | верхней границы нет; но `bytesPerRow >= widthInElements*bpe` (`0x9c1cf74`) и общий расчёт `offset+bpr*(h-1)+minBpr <= allocSize` (`0x9c1df10`) | **проверено косвенно** |
| `IOSurfaceHeight` | `0x9c1c8f0` | `str x8,[this+0x60]` (u64) | входит в `heightInElements=(h+elemH-1)/elemH` с детектом переноса (`0x9c1dcf0`), далее в общий размер | **проверено косвенно** |
| `IOSurfaceBytesPerRow` | `0x9c1c9d0` | `str x10,[this+0x68]` | `0x9c1cf74: cmp x10,x8; b.hs` — меньше `widthInElements*bpe` не пускает | **проверено** |
| `IOSurfaceBytesPerElement` | `0x9c1c7e8` | `strh w8,[this+0x70]`; `lsr #16; cbnz` → ошибка | значение обязано быть < 0x10000; `0x9c1c994: cbz` — 0 запрещён | **проверено (ширина)** |
| `IOSurfaceBitsPerBlock` | `0x9c1c7bc` | тот же `[this+0x70]`: `ubfx w8,w8,#3,#13` | пишет **тот же** u16, что и BytesPerElement → последний ключ побеждает; значение сдвигается на 3 и маскируется 13 битами | **алиасинг полей** |
| `IOSurfaceElementWidth` | `0x9c1c944` | `strb [this+0x72]` | `cmp x8,#0xff; b.hi` → ошибка | **проверено** |
| `IOSurfaceElementHeight` | `0x9c1c96c` | `strb [this+0x73]` | `cmp x8,#0xff` | **проверено** |
| `IOSurfacePixelFormat` | `0x9c1c79c` | `str w8,[this+0x80]` | нет; 64-битное значение молча усекается до 32 | **не влияет на размер** |
| `IOSurfaceOffset` | `0x9c1d028` | `str x8,[this+0x78]` | входит в `offset+size` с детектом переноса (`0x9c1de64`) | **проверено** |
| `IOSurfaceAllocSize` | `0x9c1d50c` | `str x8,[this+0x90]` | округление до страницы без переноса (`0x9c1d548`), `<=` размера родителя (`0x9c1d584`), `<=` лимита `[root+0x198]` (`0x9c1d650`) | **проверено** |
| `IOSurfaceAddress` | `0x9c1dfc8` | `str x8,[this+0x150]` — адрес поверхности | только: `[this+0x308]==0` (не сжатая), `[this+0x3a0]==0`, и выравнивание на страницу (`0x9c1e93c`). **Владение диапазоном не проверяется** | **НЕ проверено** — см. топ-1 |
| `IOSurfaceAddressOffset` | `0x9c1da90` | `str x8,[this+0x168]` | `cmp x8,pagesize; b.hs` → ошибка (`0x9c1dabc`) | **проверено** |
| `IOSurfaceAddressRanges` | `0x9c1dac4` | массив диапазонов через `0x9c203b0` | проверка количества (`cmp w0,#0x10; tst w0,#0xf`), дальше не разобрано | **не подтверждено** |
| `IOSurfaceDirection` | `0x9c1da64` | `str w8,[this+0x368]` | `and #~1; cmp #2` — только 0..3 | **проверено** |
| `IOSurfacePlaneInfo` | `0x9c1b1e4` | массив плоскостей; `getCount()->[this+0x98]`, аллокация `count*24` (`0x9c1b230`) и `count*32` (`0x9c1b258`) | `cmp w8,#3; b.hi` → «maximum plane count of %d exceeded» (`0x9c1b26c`) | **проверено (<=3)** |
| `IOSurfacePlaneWidth` | `0x9c1b464` | в структуру плоскости | участвует в `widthInElements` и в размере плоскости | **проверено косвенно** |
| `IOSurfacePlaneHeight` | `0x9c1b5c4` | то же | то же | **проверено косвенно** |
| `IOSurfacePlaneBytesPerRow` | `0x9c1b7e8` | `str x9,[plane+0x20]` | `0x9c1b890: cmp x9,x8; b.lo` → ошибка | **проверено** |
| `IOSurfacePlaneSize` | `0x9c1b8f4` | `str x8,[plane+0x28]` | `cbz x8` — 0 запрещён; верх — через `base+size <= allocSize` | **проверено** |
| `IOSurfacePlaneOffset` | `0x9c1b930` | `str x8,[plane+0x18]` | арифметика с переносами (`0x9c1b9b4`) | **проверено** |
| `IOSurfacePlaneBase` | `0x9c1ba28` | `stur x8,[plane+0x10]` — **без единой проверки на месте** | но `0x9c1da48: cmp x8,x17; b.lo` → «allocation size ... too small ... plane %d» (`0x789fa79`): `plane.base+plane.size <= fAllocSize` | **проверено позже** |
| `IOSurfacePlaneCompressedTileHeaderRegionOffset` | `0x9c1c370` | `str [plane+8]`, required | `0x9c1c3b8 cmp x10,x9; b.hi` — конец региона vs `plane.base+plane.size` | **проверено** |
| `IOSurfacePlaneCompressedTileDataRegionOffset` | `0x9c1c388` | `str [plane+0xc]`, required | `0x9c1c420 cmp x10,x9; b.hi` | **проверено** |
| `IOSurfacePlaneCompressedTileWidth/Height` | `0x9c1bf18`/`0x9c1bf74` | `umaddl`/`madd` в размере тайла | каждое произведение с проверкой `>>32` (`0x9c1c3e4`, `0x9c1c400`, `0x9c1c40c`) | **проверено** |
| `IOSurfaceSliceCount` | `0x9c1bda8` | `str [this+0x3b8]` | множитель в `madd` с проверкой переполнения (`0x9c1c41c`) | **проверено** |
| `IOSurfaceProtectionOptions` | `0x9c1c648` | `cmp #0x10; b.hs` → ошибка | **проверено** |
| `IOSurfaceMemoryPoolSize` | — | **ноль ссылок**: строка `0x789b484` не имеет ни одного `adrp/add` и ни одного указателя в `__DATA`/`__DATA_CONST`/`__PRELINK_INFO` | — | **мёртвый ключ в этом кесте** |
| `IOSurfaceMemoryPoolEntitlement/ZerofillEnabled/Class/Type/EDRFactor/Superbuffer` | — | то же: строка есть, потребителя нет | — | **не подтверждено** |

Ключи без числовой семантики (`IsGlobal`, `IsPrivate`, `NonPurgeable`, `CacheMode`,
`PurgeWhenNotInUse`, `Name`, `BufferTileMode`, …) идут через `bfi`/`strb` в слово флагов
`[this+0x3d0]` и на размеры не влияют.

## 4. Топ-5 подозрительных

### 1. `IOSurfaceAddress` — адрес поверхности из словаря, без проверки владения

Значение становится базой поверхности. Ограничения: не сжатая поверхность, `[this+0x3a0]==0`,
выравнивание на страницу. Ни проверки, что диапазон принадлежит вызывающей задаче или был
ею выделен, ни сверки с `allocSize` нет.

```
0x9c1dfc8  adrp x1,'IOSurfaceAddress'
0x9c1dfd4  bl   0x9c20038            ; getU64
0x9c1dfd8  cbz  w0,0x9c1e040
0x9c1dfdc  ldr  x8,[x19,#0x308]      ; сжатая?
0x9c1dfe0  cbz  x8,0x9c1e00c
0x9c1dfe4  ...  "Cannot use kIOSurfaceClientAddress with compressed iosurfaces."
0x9c1e00c  ldr  x16,[x19,#0x3a0]     ; уже занято?
0x9c1e034  cbnz x16,-> error
0x9c1e038  ldur x8,[x29,#-0x68]      ; значение из словаря
0x9c1e03c  str  x8,[x19,#0x150]      ; fAddress
...
0x9c1e918  ldr  x9,[x19,#0x370]      ; список диапазонов
0x9c1e930  ldr  x21,[x8]             ; адрес диапазона
0x9c1e934  ldr  x9,[x24]             ; pagesize
0x9c1e938  sub  x9,x9,#1
0x9c1e93c  tst  x9,x21
0x9c1e940  b.ne -> error             ; единственная проверка: выравнивание
```

Достижимость: (а) как ключ в XML-словаре `create_surface`, (б) напрямую селектором 7
`create_surface_client_mem(addr,size)` — два сырых скаляра, без проверки энтайтлмента
(в кесте всего 5 строк `com.apple.*`, все — `iosurfaceinfo`, `gpu-restricted` ×2,
`IOSurface.protected-access`, `IOUserClientEntitlements`, и ни одна не относится к sel 7).
**Вердикт: единственное место, где пользовательское число становится адресом без сверки
с реальным буфером.** Требует динамики: чем заканчивается `0x9c2200c` при маппинге
(не подтверждено статикой — дальше `IOBufferMemoryDescriptor`-подобный вызов
`0x9c49c64` со списком диапазонов).

### 2. `IOSurfacePlaneBase` — проверка запаздывает

`stur x8,[plane+0x10]` без валидации (`0x9c1ba40`); безопасность держится на единственной
поздней проверке в цикле по плоскостям:

```
0x9c1da38  ldr  x0,[x17,#0x10]       ; plane.base
0x9c1da3c  ldr  x17,[x17,#0x28]      ; plane.size
0x9c1da40  adds x17,x0,x17           ; перенос -> error 0x9c1dd84
0x9c1da48  cmp  x8,x17               ; x8 = fAllocSize
0x9c1da4c  b.lo 0x9c1ddac            ; "allocation size ... too small ... plane %d"
```
Если из этого цикла есть выход по `continue`/`break` для какого-то типа плоскости —
граница обходится. Цикл полный (`cmp w9,w12; b.ne` в конце), поэтому сейчас **проверено**.

### 3. `IOSurfaceBytesPerElement` и `IOSurfaceBitsPerBlock` — одно поле, два ключа

```
0x9c1c7bc  adrp x1,'IOSurfaceBitsPerBlock'
0x9c1c7d0  ldur x8,[x29,#-0x68]
0x9c1c7d4  lsr  x9,x8,#0x10
0x9c1c7d8  cbnz x9,error
0x9c1c7dc  ubfx w8,w8,#3,#13          ; bpb = (v>>3) & 0x1fff
0x9c1c7e0  strh w8,[x19,#0x70]
...
0x9c1c7e8  adrp x1,'IOSurfaceBytesPerElement'
0x9c1c800  lsr  x9,x8,#0x10
0x9c1c804  cbnz x9,error
0x9c1c808  strh w8,[x19,#0x70]        ; то же поле, без сдвига
```
На память не влияет (0 отсекается `0x9c1c994`), но `bpb` из `BitsPerBlock` — это не
«биты на блок», а `v>>3`: семантика ключа не соответствует записи. Для фаззера — хороший
маркер рассинхрона ядра и клиента.

### 4. `IOSurfaceAddressRanges` — единственный неразобранный до конца путь

`0x9c203b0` + проверки `cmp w0,#0x10; tst w0,#0xf` (`0x9c1daf4`). Ветка «количество >= 16
и кратно 16» уходит в `0x9c1df44`, дальше идёт работа со списком диапазонов и
`IOSurfaceAddressOffset`. Статикой до конца не прослежено.
**Вердикт: не подтверждено.** Если у ключа есть потребитель помимо paravirt-пути,
это второй кандидат на «число → адрес».

### 5. `IOSurfacePixelFormat` — усечение 64→32 без проверки

```
0x9c1c79c  adrp x1,'IOSurfacePixelFormat'
0x9c1c7a8  bl   0x9c20038            ; 64-битное число
0x9c1c7b0  ldur x8,[x29,#-0x68]
0x9c1c7b4  str  w8,[x19,#0x80]       ; старшие 32 бита отброшены
```
Размеров не касается. Но `pixelFormat` дальше участвует в выборе «сжатая/несжатая» логики
(`[this+0x308]`), а та, в свою очередь, гейтит `IOSurfaceAddress`. То есть усечение может
переключать режим поверхности относительно того, что ожидал клиент.

## 5. Что проверено и чем

Арифметика создания поверхности (все ветки — через явные проверки переноса):

| выражение | адрес | проверка |
|---|---|---|
| `widthInElements=(w+elemW-1)/elemW` | `0x9c1c9b0`..`0x9c1c9c8` | `adds`+`cset hs`+`eor` — детект переполнения, `udiv` |
| `bytesPerRow >= widthInElements*bpe` | `0x9c1c9f0`..`0x9c1cf7c` | `umulh` + `cmp/b.hs` |
| `bpr` по умолчанию: `round_up(...)` | `0x9c1cd9c`..`0x9c1cdd0` | `umulh` + `adds` + округление `bic` |
| `heightInElements=(h+elemH-1)/elemH` | `0x9c1dce0`..`0x9c1dd08` | `cinc`/`eor` + `tbnz #63` |
| `required = offset + minBpr + bpr*(hInElem-1)` | `0x9c1de30`..`0x9c1de68` | три `umulh`/`adds` с ветками на ошибку (`0x789f923`, `0x789fb4e`, `0x789fb78`) |
| `required <= allocated` | `0x9c1df10 cmp x8,x9; b.hs` | да, иначе «buffer allocation size is too small to cover valid image area: fAllocSize=%llu, requiredSizeInBytes=%llu» (`0x789fba7`) |
| `allocSize` → страницы | `0x9c1d540`..`0x9c1d548` | `add`+`bic`+`cmp/b.hs` |
| лимит `allocSize <= [root+0x198]` | `0x9c1d650` | «allocation size of %llu exceeds limit of %llu bytes» (`0x789fa0c`) |
| сжатые тайлы: `umaddl`, `madd`, `umull` | `0x9c1c3a4`..`0x9c1c424` | после каждого — `lsr #32/#0x23; cbnz` → ошибка |

## 6. Вывод

На этой сборке **классического «число из словаря → memcpy/индекс без проверки» в
`IOSurface::initWithProperties` нет**: геометрия (Width/Height/BytesPerRow/BytesPerElement/
ElementW/H/Offset/AllocSize/Plane*) вся проходит через явные проверки переполнения и
сверку с `fAllocSize`, включая сжатые тайлы. Вход в словарь безопасен (бинарный plist
с границами, XML — `OSUnserializeXML`).

Остаётся ровно один ключ, значение которого становится **адресом** без сверки с реальным
буфером — `IOSurfaceAddress`, достижимый двумя путями (ключ в словаре `create_surface`
и селектор 7 `create_surface_client_mem` с двумя сырыми скалярами и без проверки
энтайтлмента в кесте). Единственные ограничения — выравнивание на страницу и запрет для
сжатых поверхностей. Это и есть цель для динамической проверки: что делает ядро с
`[IOSurface+0x150]` при `lock`/`map` поверхности.

`IOSurfaceMemoryPoolSize` в этом кесте **не используется вообще** (строка без ссылок и без
указателей) — как вектор атаки через `create_surface` он мёртв.
