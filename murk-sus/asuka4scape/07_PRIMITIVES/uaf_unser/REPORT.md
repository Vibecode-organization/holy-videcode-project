# UAF / double-release в десериализаторе и в применении словаря к IOSurface

iOS 27.2 (24B115), `27.2_24B115_kernelcache`. Вход: `IOSurfaceRootUserClient` sel 0,
`structureInput`/OOL-дескриптор произвольной длины → `OSUnserializeXML(buf,size,NULL)`
(`0xfffffff00a8d8754`) → XML (`0xa8d846c`/`0xa8d5ea4`) **или** бинарный
(`0xa8d96f4`, цикл `0xa8d97a0`…`0xa8da46c`) → `create_surface` (`0x9c3ab8c`).

Нотация: `__TEXT_EXEC` off = `va - 0xfffffff007004000`; слоты vtable ниже проверены по
двум независимым сайтам каждый (см. §1.4).

---

## 0. Вердикт

| гипотеза | статус |
|---|---|
| двойной release при частичном разборе (бинарный цикл, `0xa8da31c`/`0xa8da32c`) | **опровергнуто** |
| висячая ссылка в родительском контейнере после неудачи | **опровергнуто** |
| UAF при росте массива объектов (`0xa8d9cd4`) / стека (`0xa8da2ac`) | **опровергнуто** |
| результат `OSUnserializeXML` в `create_surface` освобождается дважды или не освобождается | **опровергнуто** (ровно один release на всех 6 выходах) |
| сеттер IOSurface сохраняет значение без retain | **опровергнуто** для всех найденных путей (`+0x268` и `+0x98` — retain; `setObject` — retain) |
| **утечка ссылки на разобранный словарь** (`0x9c3e388`) | **подтверждено** (не UAF) |
| **утечка retain** в `create_surface` на 2 ветках (`0x9c3acec`) | **подтверждено** (недостижимо из plist) |
| **нет проверки типа ключа** в бинарном словаре (ключ = любой объект) | **подтверждено** (latent type confusion) |
| UAF / чтение освобождённого | **не подтверждено** |

Т.е. в разобранном коде **нет** UAF/double-release, который я мог бы доказать статически;
есть три дефекта владения, из которых один (утечка словаря) достижим по входу, если
`0x9c3e388` вообще вызывается из user client (xref'ов нет — виртуальная диспетчеризация).

---

## 1. Таблица владения

### 1.1 Бинарный парсер `OSUnserializeBinary` (`0xa8d96f4`, цикл `0xa8d97a0`…`0xa8da46c`)

Состояние (декомпилятор + исходник `libkern/c++/OSSerializeBinary.cpp`, сходится
по инструкциям: `+0x200` на рост = `ncap = capacity + 64`):

| слот | смысл | инициализация |
|---|---|---|
| `[sp+0x70]` | `objsArray` (`OSObject**`) | `0xa8d9814` (0) |
| `[x29-0x64]` | `objsIdx` (u32) | `0xa8d97b0` |
| `[x29-0x60]` | `objsCapacity` (u32, entries) | `0xa8d97ac` |
| `[sp+0x10]` | `stackArray` (контейнеры) | `0xa8d97d8` |
| `[sp+0xc]` | `stackIdx` | `0xa8d97b8` |
| `[sp+0x20]` | `stackCapacity` (max 64) | `0xa8d97b4` |
| `local_80`/`local_b0`/`local_c0` | dict / array / set | `0xa8da078` |
| `local_100` | parent | `0xa8da304` |
| `plVar15` | sym (отложенный ключ словаря) | `0xa8da078` |

| объект | откуда +1 | где −1 | вердикт |
|---|---|---|---|
| `OSDictionary/OSArray/OSSet` (`+0x68` alloc, `+0xd0` init) `0xa8d98f0`,`0xa8d9a00`,`0xa8d9b4c`,`0xa8d9bc0`,`0xa8da0dc` | создание | `0xa8d9900`,`0xa8d9ad0`,`0xa8d9b64`,`0xa8d9bf8`,`0xa8da110` при провале init | баланс |
| `OSNumber` (`0xa8da0bc`, metaClass `0xad95dc8` + `0x78`) / `OSString` (`0xa8d42e4`) / `OSData` (`0xa8d2050`) | создание | `0xa8d9c0c` при провале init | баланс |
| ключ словаря (`sym`) | создан как обычный объект → **в `objsArray`** | вставка `dict+0xf0(key,value)` **retain'ит ключ**; сам парсер ключ не отпускает, его отпустит cleanup | баланс (2 → 1 у словаря) |
| значение | создан → в `objsArray` | `setObject` retain'ит; cleanup отпускает | баланс |
| `kOSBooleanTrue/False` (`0xa8d9b94`) | **без retain** (синглтон) | cleanup `release` | refcount уходит в `0xffff` (pegged). `OSBoolean::free()` в release-ядре — no-op, память статична; в debug ядре (`MACH_ASSERT`) был бы panic. Не UAF |
| `0xa8da32c` (release только что созданного `o`) | — | **до** `objsIdx++` (`0xa8da30c`/`0xa8d9d34`) | объект не в таблице → двойного release нет |
| cleanup `0xa8da358`…`0xa8da3d8` | — | `for (i = (result!=0); i < objsIdx; i++) release(objsArray[i])`, затем `kfree_type(objsArray,cap*8)` и `kfree_type(stackArray,cap*8)` | каждый объект ровно один раз; корень (`objsArray[0]`) пропускается и возвращается с +1 |

Инвариант «`result == objsArray[0]`»: `result` пишется только в ветке, где `dict==array==set==0`
и `result==0` (`0xa8da320`-блок), а `kOSSerializeObject` (ref) требует `len < objsIdx`, т.е.
первым объектом быть не может → первый объект всегда попадает в таблицу под индекс 0.

### 1.2 Рост массивов (`0xa8d9cd4` объекты, `0xa8da2ac` стек)

Вызов `kreallocp_type_container`-подобного `0xa2217b4(type, old, oldsz, newsz, 0x41244, 0)`:

```
0xa8d9cd4  lsl  w2, w26, #3          ; oldsz = cap*8
0xa8d9cd8  add  w3, w2, #0x200       ; newsz = cap*8 + 64*8
0xa8d9cf8  bl   0xa2217b4
0xa8d9cfc  lsr  x8, x1, #3           ; новая ёмкость = факт. размер >> 3
0xa8d9d0c  cbz  x0, 0xa8da32c        ; провал → release(o) → cleanup
0xa8d9d28  str  x0, [sp, #0x70]      ; единственная копия указателя
```

`0xa2217b4` при провале выделения возвращает `{0,0}` **не освобождая старый блок**:
ветка возврата `LAB_fffffff00a221bb4` → `if (((uint)param_5 >> 3 & 1) == 0) return {0,0}`
(флаг `0x41244 & 8 == 0`), освобождение старого (`0xa2213e4`) — только в ветках
`uVar20 == 0` и успешного переноса. Значит cleanup вправе освободить **старый** указатель
из `[sp+0x70]`. Двойного free нет.

Других копий указателя на `objsArray`/`stackArray` в кадре нет: все использования
перезагружают слот (`0xa8d98b0`, `0xa8da37c`, `0xa8da16c`, `0xa8da300`, `0xa8da3c0`).
Стека: `stackCapacityMax = 64` (`0xa8da29c cmp w23,#0x3f`), запись идёт по
`stackIdx` после инкремента, чтение — по тому же индексу (`0xa8da17c`).

### 1.3 XML-путь (`0xa8d8754` → core `0xa8d846c` → `0xa8d5ea4`)

Это bison-реализация из `OSUnserializeXMLSharedImplementation.h` (строки
`buildArray`/`buildBoolean`/`maximum object count`, `MAX_OBJECTS=131071`,
`objcount 0xa8d6a74`, `livecount 0xa8d6b30` — совпадает).

| объект | +1 | −1 |
|---|---|---|
| `object_t` 0x40 B (`kalloc_type` `0x7c7c2d0`) | `newObject` | `cleanupObjects` → `free_type` |
| `o->object` | `build*` (`withCapacity`/`withCString`/…) | `cleanupObjects`; принятый корень обнуляется в case 3 (`0xa8d…`, `parsedObject = $1->object; $1->object = 0`) |
| `o->key` (OSSymbol) | `buildSymbol` | `buildDictionary`: `setObject` (retain) затем `o->key->release()`, `o->key=0` |
| `o->string` | `getString` | `buildString`/`buildSymbol`: `safe_free`, `=0` |
| `o->data` | hex/base64 декодер | `buildData`: `free`, `=0` |
| `state->tags` (`OSDictionary`) | `withCapacity(128)` | `state->tags->release()` |
| IDREF | `retrieveObject` — **заимствование** | case 12: `$$->object->retain()`, дальше владеет pair/build* |

Дубликат ключа отсекается в правиле `pairs` сравнением указателей интернированных
`OSSymbol` — до `buildDictionary` дубликат не доходит, поэтому сценарий
«replacement освободил старое значение, а новое — тот же указатель» недостижим.

### 1.4 Потребитель: IOSurface

Слоты vtable (проверены по сайтам в двух разных функциях):

| слот | метод | доказательство |
|---|---|---|
| `+0x20` | `retain()` | `buildBoolean` в XML-парсере: `o->object = kOSBooleanTrue; o->object->retain()` → `ldr x8,[x+0x20]` (`0xa8d5ea4`, case 0xb) |
| `+0x28` | `release()` | все teardown-ы, `0xa9…`; в `create_surface` финал `0x9c3b078` отпускает результат парсинга |
| `+0x38` | `getMetaClass()` | обход цепочки классов `[meta+0x10]` |
| `+0xe8` | `OSArray::setObject(OSObject*)` | `buildArray` `0xa8d8238` |
| `+0xf0` | `OSDictionary::setObject(OSSymbol*, OSObject*)` | `0x9c24b28` (`setValue`) |
| `+0x100` | `OSDictionary::setObject(const char*, OSObject*)` | `buildArray` (`tags` + строка `%u`) |
| `+0x118` | `OSArray::getObject(u32)` | `0x9c3c3bc`, `0x9c3d564` |
| `+0x138` | `OSDictionary::getObject(const char*)` | `create_surface` `0x9c3acc4` с `"IOSurfaceAllocateFromSuperbuffer"`; `tags->getObject(char[16])` |

| объект | владение | вердикт |
|---|---|---|
| результат `OSUnserializeXML` (`x20` в `0x9c3ab8c`) | +1 от парсера | `release` в общем эпилоге `0x9c3b078`; на все 6 выходов ровно один раз (в т.ч. «`id != 0`, родитель не найден» `0x9c3ac58`→`0x9c3ac84`→`0x9c3b078`) |
| родительская поверхность (`parentID != 0`) | `+1` от `0x9c3f1d0` | `release` `0x9c3b040` |
| словарь свойств на поверхности | `FUN_0x9c16670(surface+0x268, dict)` = `{old=*slot; *slot=new; retain(new); release(old)}` — **retain** | висячей ссылки нет |
| словарь в объекте из `0x9c43898` | `[+0x98] <- dict` c retain (`0x9c43a1c`) | retain |
| значения `setValue` | `[dict+0xf0](dict,key,value)` = `setObject` → retain ключа и значения (`0x9c24b28`) | retain |
| `0x9c3c800` | `OSArray::withObjects(parsed,NULL)` (+1) → `[root+0x130]`, старый release | баланс |

Вывод: сеттеры IOSurface **сохраняют ссылку**, а не только читают; UAF «сеттер сохранил
без retain» в этом дереве нет.

---

## 2. Топ-3 с дизасмом

### 2.1 (подтверждено) Утечка разобранного словаря в `0x9c3e388`

```
0x9c3e3c4  bl   0x9c49764          ; OSUnserializeXML(buf=x3, len=w4, NULL) -> x21  (+1)
0x9c3e3d8  bl   0x9c498d4          ; OSDynamicCast(x21, gOSDictionary)
0x9c3e3dc  mov  x19, x0
0x9c3e3e0  cbz  x0, 0x9c3e448      ; не словарь -> отдельная ветка
0x9c3e3e4  ldr  x0, [x23, #0xe8]   ; pool
0x9c3e3ec  cbz  x0, 0x9c3e484      ; pool==0 -> x22=x19; b 0x9c3e534 (release словаря)
0x9c3e3f0  mov  x21, x0            ; <-- x21 (результат парсинга) ПЕРЕЗАПИСАН пулом
0x9c3e410  blraa x8, x16           ; [x19+0x20] => retain(dict)
0x9c3e498  bl   0x9c43898          ; create obj(pool, dict, ref); внутри retain/release словаря
0x9c3e508  blraa ...               ; release(new obj)
0x9c3e510  blraa [x21+0x28]        ; release(pool)
0x9c3e534  blraa [x19+0x28]        ; release(dict) — снимает ТОЛЬКО retain из 0x9c3e410
0x9c3e554  retab                  ; +1 от OSUnserializeXML не снят никогда
```

Симметрия доказывает, что это именно утечка, а не «владение передано»:

```
0x9c3e448  cbz  x21, 0x9c3e46c     ; ветка "не словарь"
0x9c3e464  blraa [x21+0x28]        ; release(результата парсинга)  <-- здесь он есть
```
Плюс `0x9c43898` сам берёт временный retain словаря и снимает его
(`if (param_2) [param_2+0x20]; … [param_2+0x28]`), а `0x9c43a1c` кладёт словарь в
`[obj+0x98]` **с retain**. Значит лишний retain в `0x9c3e388` не нужен, а ссылка
парсера теряется: словарь и всё его дерево (строки/данные/массивы, до 131071 объекта)
живут вечно. На каждый вызов — своя копия.

Достижимость: прямых `bl` на `0x9c3e388` в кеше нет (виртуальный вызов из таблицы
методов user client'а не найдена — как и для `s_create_surface`, см. отчёт subagent E).
**Не подтверждено**, что sel доступен из песочницы; если доступен — это утечка ядерной
памяти управляемого размера (DoS/истощение зон), не UAF.

### 2.2 (подтверждено, недостижимо) Утечка retain в `create_surface` `0x9c3ab8c`

```
0x9c3acbc  ldr  x8, [x16]              ; dict->getObject("IOSurfaceAllocateFromSuperbuffer")
0x9c3acc8  blraa x8, x16
0x9c3acd8  bl   0x9c498d4              ; cast к классу 0x806c9f8
0x9c3acec  blraa [x22+0x20]            ; retain(obj)
0x9c3ad1c  blraa [x22+0xb0]            ; value = obj->...()
0x9c3ad2c  cbz  x0, 0x9c3ade4          ; value==0  -> утечка retain (нет release)
0x9c3ad80  cbz  x26, 0x9c3ade4         ; pool obj ==0 -> утечка retain
0x9c3b004  blraa [x22+0x28]            ; release только на успешной ветке
```
Ветки `0x9c3ad2c`/`0x9c3ad80` уходят в `0x9c3ade4`, минуя `0x9c3b004`. Чтобы попасть
в блок, значение по ключу должно быть объектом класса `0x806c9f8` — из plist такой
объект не собрать (только OSDictionary/OSArray/OSSet/OSNumber/OSString/OSData/boolean).
**Из песочницы не достижимо**, поэтому в топ только как дефект владения.

### 2.3 (подтверждено) Нет проверки типа ключа в бинарном словаре

```
0xa8d9eb8  ldur x0, [x29, #-0x70]             ; контейнер-словарь
0xa8d9ecc  ldr  x8, [x16, #0xf0]!             ; OSDictionary::setObject(OSSymbol*, OSObject*)
0xa8d9ed0  mov  x1, x22                       ; ключ  = ЛЮБОЙ объект из потока
0xa8d9ed4  mov  x2, x21                       ; значение
0xa8d9edc  blraa x8, x16
```
(рядом, `0xa8d9f00`…`0xa8d9f44`, тот же слот `+0xf0`, но с `func`: ключ подменяется
результатом callback'а — только при `flags & 1` и `func != 0`, чего в пути IOSurface нет)
В бинарном формате роль ключа играет первый объект пары, и он **не приводится**
к `OSSymbol`: `ODynamicCast`/`OSSymbol::withString` есть только в ветке с callback
(`0xa8d9e4c`), а при `func==0`, `flags==0` (путь IOSurface, `0xa8d8754`) вставка идёт
напрямую. `OSDictionary` хранит ключ как `OSSymbol*` и сравнивает указатели, поэтому
`kOSSerializeString`/`Number`/`Data`/`Dictionary` в роли ключа даёт словарь с
«ключом» чужого класса.

Для IOSurface последствий нет: все обращения к словарю идут через
`getObject(const char*)` (`+0x138`) / `setObject(key, …)`, т.е. по интернированным
символам, без разыменования поддельного ключа. Но любой потребитель, который
сериализует словарь или итерирует ключи (`getCStringNoCopy`), получит type confusion.
**Latent, не подтверждено как эксплуатируемое.**

---

## 3. Точная последовательность для UAF — не подтверждено

Единственный сценарий, который я мог бы довести до «освободили — читаем», и который
в этом коде **не срабатывает**, привожу, чтобы закрыть вопрос:

```
1. sel 0, buf[0]=0xd3  -> бинарный парсер 0xa8d96f4
2. { (kOSSerializeDictionary, len=N)
     kOSSerializeString "A"        ; ключ  -> objs[1], +1
     kOSSerializeNumber ...        ; значение -> objs[2], +1
     (kOSSerializeEndCollecton) }
3. вставка: dict[+0xf0]("A", value) -> OSDictionary retain'ит ключ и значение
4. cleanup 0xa8da358: release(objs[1..2]) -> у каждого остаётся ровно 1 ссылка (словарь)
5. возврат: словарь (+1) -> create_surface 0x9c3ab8c
6. динамический cast в OSDictionary, ctor 0x9c1a914 -> FUN_0x9c16670(surface+0x268, dict):
   retain(dict); release(старый)
7. 0x9c3b078: release(dict) -> остаётся 1 (поверхность)
```
На шаге 4 нечего освобождать дважды: `objsIdx` инкрементируется только после записи
в таблицу (`0xa8d9d30`/`0xa8d9d34`), а ранний `release(o)` (`0xa8da32c`) стоит **до**
этого места. На шаге 7 поверхности принадлежит своя ссылка, и она её отпускает в
`free`. Висячего указателя не возникает.

Что *могло бы* дать UAF и чего в коде нет:
* release значения без retain в сеттере (`+0x268`/`+0x98`/`setObject` — все retain);
* повторная вставка того же объекта под тем же ключом при refcount 1 (в XML дубликат
  отсекается, в бинарном у значения всегда ≥2 ссылки из-за `objsArray`);
* двойной release при провале `krealloc` (старый буфер не освобождается, см. §1.2).

---

## 4. Что проверено и отброшено (с адресами)

1. `0xa8da31c` (общий error), `0xa8da32c` (release `o` + cleanup), `0xa8da46c` (retab),
   `0xa8da34c`, `0xa8da3dc` — все сходятся в `0xa8da358`; release-цикл отпускает
   `[result!=0 .. objsIdx)`; `release(o)` в `0xa8da32c` — до попадания в таблицу.
2. `0xa8d9cd4` (рост `objsArray`) и `0xa8da2ac` (рост стека): `0xa2217b4` при провале
   не освобождает старый блок; указатель один — `[sp+0x70]` / `[sp+0x10]`.
3. `0xa8d9d44`…`0xa8d9fb8` (attach/pop, `setAtIndex(stack,…)`, `stackCapacityMax=64`,
   `0xa8da29c`): индекс валидируется, при провале — cleanup.
4. OOM в `buildDictionary` (инлайн в `0xa8d5ea4`): проверка `dict == 0` есть **только**
   для пустого словаря (`plVar22[2] == 0` → `"buildDictionary"`); для непустого сразу
   `[dict+0xf0](dict, key, value)` → вызов через NULL. То же в `buildArray` (`0xa8d8238`,
   `[array+0xe8]` без проверки). **NULL-deref при OOM**, DoS, не UAF. Порядок release
   в словаре: `key->release()`, затем `object->release()`, оба обнуляются; для `key==object`
   (IDREF) это парные отпускания двух retain'ов `setObject` — UAF нет.
5. `0x9c3c3bc` / `0x9c3c800` / `0x9c3d564` / `0x9c3e388` (`OSUnserializeXML` в
   IOSurface): результат отпускается один раз везде, кроме `0x9c3e388` (§2.1).
6. `0x9c24b28` (`setValue`): `[dict+0xf0](dict,key,value)` — retain; специальный ключ
   `"CreationProperties"` (строка `0x789b3c1`) вообще не кладётся в словарь значений.

---

## 5. Метод и артефакты

* Исходники XNU найдены локально (`/tmp/opencode/xnu-main`, tar'ы 12377.61.12/81.4/121.6):
  `libkern/c++/OSSerializeBinary.cpp` — это ровно алгоритм `0xa8d97a0`;
  `OSUnserializeXMLSharedImplementation.h` + `OSUnserializeXML.y` — XML-путь.
  Дизасм сверялся с исходником: `+0x200` = `capacity+64`, `0x3f` = `stackCapacityMax`,
  финальный цикл = `for (len = (result != NULL); len < objsIdx; len++) release`.
* Ghidra 12.1.4: проект `/tmp/opencode/ghproj272` (`com.apple.kernel`, байты по
  `0xa8d…` совпадают с кешем побайтово) + сырой срез `__TEXT_EXEC` `0x9c00000`…`0x9c50000`
  (`/tmp/opencode/ghios`, `ios_slice.bin`).
* Декомпиляция: `decomp/` (ядро), `decomp_ios/` (IOSurface), `decomp_k/` (хелперы
  `kalloc`/`OSObject`), дизасм: `mainloop.txt`, `create_surface.txt`, `create_from_dict.txt`.
* GOT-трамплины: `got.py` (`0x9c49764`→`0xa8d8754` OSUnserializeXML,
  `0x9c49ae4`→`0xa8d4088` приведение ключа, `0x9c49a84`→`0xa8cae24` OSNumber).
* Поиск вызывающих: `blscan.py` (по всем exec-сегментам; на `0x9c3e388`,
  `0x9c38890`, `0x9c3ab8c` — 0 прямых `bl`, только виртуальная диспетчеризация).
