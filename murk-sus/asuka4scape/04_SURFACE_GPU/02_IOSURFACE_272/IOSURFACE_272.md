# IOSurfaceRoot 27.2 (24B115) — таблица внешних методов, статика

Источник: `дипсик 1/kc/27.2_24B115_kernelcache` (Mach-O kext collection, filetype 12).
VA→offset: `off = va - 0xfffffff007004000` для `__TEXT_EXEC`.
Указатели в `__DATA_CONST` PAC-кодированы: реальный VA = `0xfffffff007004000 + (q & 0x0FFFFFFF)`,
верхние 32 бита `0x8050bcad` — подпись.

## 1. Диспетчер

```
fffffff009c3ee14  adrp x8, 0xfffffff008068000
fffffff009c3ee18  add  x8, x8, #0xb90        ; table A
fffffff009c3ee1c  ldrb w9, [x0, #0x127]      ; флаг клиента
fffffff009c3ee20  adrp x10, 0xfffffff008069000
fffffff009c3ee24  add  x10, x10, #0x4f0      ; table B
fffffff009c3ee28  tst  w9, #1
fffffff009c3ee2c  csel x3, x10, x8, ne       ; бит=1 -> B, иначе A
fffffff009c3ee30  mov  w4, #0x3c             ; 60 методов
fffffff009c3ee34  mov  x5, x0
fffffff009c3ee38  mov  x6, #0
fffffff009c3ee3c  b    0xfffffff009c498f4   ; общий диспетчер
```

- **table A** `0xfffffff008068b90`, **table B** `0xfffffff0080694f0`, stride **0x28**, используется **60** записей.
- Формат записи: `fn(8) | sIn(4) | strIn(4) | sOut(4) | strOut(4) | flags(4)`, где `strIn/strOut = 0xffffffff` — «не проверять».
- Заглушка «не поддерживается» `0x9c3a1dc` возвращает **0xe00002e2**.

Следствие из живого лога: наш клиент получал `0xe00002c2` на sel 26, а не `0xe00002e2`,
значит использовалась **table A** и `[self+0x127] & 1 == 0`.

## 2. Селектор 30 — единственный путь к var-output

```
fffffff009c3968c  ldrb w8, [x0, #0x122]      ; флаг
fffffff009c396b0  tbz  w8, #0, +0x6c         ; 0 -> 0xe00002c1 (not privileged)
fffffff009c396b8  ldr  x8, [x2, #0x78]       ; args->structureVariableOutputData
fffffff009c396bc  cbz  x8, +0x68             ; NULL -> 0xe00002c2
fffffff009c396c4  mov  w0, #0x100000
fffffff009c396d0  bl   GOT[0x806c650]        ; OSData::withCapacity(0x100000)
fffffff009c396dc  ldr  x8, [x20, #0x20]      ; args->scalarInput
fffffff009c396e0  ldr  x1, [x8]              ; scalarInput[0]
fffffff009c396ec  bl   0x9c40430             ; сериализация в OSData
fffffff009c396f0  cbz  w0, +...              ; 0 => успех
fffffff009c3972c  ldr  x8, [x20, #0x78]
fffffff009c39730  str  x21, [x8]             ; *structureVariableOutputData = OSData*
```

`0x9c40430(self, scalarInput[0], osdata)`:
создаёт вспомогательный объект (`GOT[?](1)`), берёт `self->0xe8` (коллекция),
зовёт `0x9c34d4c(self->0xe8, obj, scalarInput[0] != 0)`, затем `[obj vtable+0x30](obj, osdata)`,
проверяет `w0`, освобождает объект. То есть это **сериализация состояния root-объекта**
(список поверхностей/свойств) в `OSData` ёмкостью 1 МБ.

Ядро (`is_io_connect_method_var_output`) делает `OSDynamicCast(OSData, ...)` →
`copyoutkdata(data->getBytesNoCopy(), len, var_output)` → в userspace приходит
**содержимое OSData** (до 1 МБ), а не указатель.

Значит: sel 30 = «выгрузить сериализованное состояние», а не прямой leak указателя.
Ценность — содержимое: сериализованные свойства поверхностей, в которых бывают
бинарьные блобы (`IOSurfaceMemoryPoolInfo`, `IOSurfaceSharedEvent`, порты/идентификаторы).
Требует `[self+0x122] & 1 == 1`; кто и когда его ставит — сеттер `0x8fd1088`
(`strb w8,[x0,#0x122]`), вызывается косвенно (таблица свойств), не прямым BL.

## 3. Селектор 26 — это не то, что мы звали раньше

```
fffffff009c39448  ... ldr x23,[x2,#0x30]   ; structureInput
                       ldr w25,[x2,#0x38]   ; structureInputSize
                       ldr x0, [x2,#0x40]   ; structureInputDescriptor
                       cbz  x0, ...         ; -> IOMemoryDescriptor::createMapping(0x1000)
                       ldr x0, [x2,#0x68]   ; structureOutputDescriptor
                       ...                  ; +0x58 structureOutput, +0x60 size
```
Дефолтный код возврата `0xe00002c8` (kIOReturnVMError). Это метод работы с
дескрипторами памяти (map/unmap), а не «дай указатель».

## 4. Полная карта селекторов

`selectors_27.2.txt` рядом — обе таблицы, 60 записей каждая:
`sel | fn | sIn | strIn | sOut | strOut | flags`.

Ориентиры по table A:

| sel | fn | sIn | strIn | sOut | strOut | что похоже |
|---|---|---|---|---|---|---|
| 0 | 0x9c3888c | 1 | -1 | 0 | 3176 | create surface (dict in, props out) |
| 2 | 0x9c38a6c | 0 | 12 | 0 | 3176 | lookup by id |
| 9/11 | 0x9c38b2c / 0x9c38e54 | 0 | -1 | 0 | 4 | scalar getters |
| 10 | 0x9c38c44 | 0 | -1 | 0 | -1 | «любой размер» |
| 19/24 | 0x9c390ac / 0x9c392c0 | 0 | -1 | 0 | 0 | side-effect методы |
| 26 | 0x9c39448 | 0 | -1 | 0 | -1 | map/unmap дескрипторов |
| 27/28 | 0x9c39654 / 0x9c39660 | 0/1 | 160 | 0 | 160/0 | структура 160 B |
| **30** | **0x9c3968c** | **1** | **0** | **0** | **-1** | **serialize + var-output** |
| 34 | 0x9c397d8 | 1 | 0 | 0 | 3176 | свойства поверхности |
| 46 | 0x9c39a78 | 0 | -1 | 2 | 0 | два скаляра наружу |
| 58 | 0x9c3a128 | 5 | 0 | 3 | 0 | 5 скаляров внутрь, 3 наружу |

## 5. Что проверять на устройстве (когда появится подпись)

1. `IOConnectCallMethod(conn, 30, &v, 1, NULL, 0, so, &sc, &vp, (size_t[]){-3})`
   - `kr=0x0` → `[self+0x122]==1`, пришёл буфер, смотреть `cnt` и первые байты;
   - `kr=0xe00002c1` → флаг 0, нужен entitlement `com.apple.private.iosurfaceinfo`;
   - `kr=0xe00002c2` → var-output не доехал (не тот magic).
2. sel 26 с `structureInputDescriptor`/`structureOutputDescriptor` (MIG `io_connect_method`
   не умеет descriptor-аргументы — только var-output вариант умеет `args+0x78`;
   дескрипторы приходят из `io_connect_method_structureI_structureO`/`..._ool`).
3. sel 46/34 — быстрые скалярные/структурные чтения без var-output.

## 6. Файлы

```
02_IOSURFACE_272/selectors_27.2.txt   обе таблицы, 60 записей
02_IOSURFACE_272/IOSURFACE_272.md     этот разбор
08_SBX/main.m                          проба sel 30/26/46, magic -3
```

## 7. Проверка «кто ещё пишет в var-output»

Скан kext 27.2 (0x9bf0000–0x9c60000) на все чтения `args+0x78` (`ldr Xt,[Xn,#0x78]`, imm12=0x0F)
и записи по указателю оттуда. Найдено ровно **два** писателя:

| sel | fn | проверка флага | что кладёт |
|---|---|---|---|
| 30 | 0x9c3968c | `[self+0x122] & 1` (иначе 0xe00002c1) | `OSData::withCapacity(0x100000)` + сериализация `self->0xe8` |
| 49 | 0x9c39e0c | **нет** | `OSData::withCapacity(0x100000)`, но helper `0x9c3eb68` буфер **не заполняет** |

sel 49 (`0x9c39e0c`):
```
0x9c39e2c  ldr x8,[x2,#0x78] ; cbz -> 0xe00002c2      ; флага +0x122 нет
0x9c39e48  bl  GOT[0x806c650](0x100000)               ; OSData
0x9c39e64  bl  0x9c3eb68(self, scalarInput[0], osdata)
0x9c39ea0  str x21,[x8]                                ; *varData = OSData
```
`0x9c3eb68` берёт `self->0xf8`, зовёт `GOT[0x806c678](obj, scalarInput[0], &local)`,
логирует строку и возвращает статус. OSData (x20) в нём **не используется** →
`len = 0`, `copyoutkdata(..., 0, ...)`, в app приходит пустой буфер (cnt=0).
То есть селектор 49 — «сделай X и запиши в лог», без утечки.

Остальные `+0x78` в kext — поля объектов (`[x19,#0x3c0]`, `[x20,#0x380]` и т.п.),
не `IOExternalMethodArguments`.

**Вывод:** единственный канал ядро→app через var-output в IOSurface — селектор 30,
и он закрыт флагом `+0x122`. Дальше нужно понять, кто ставит `+0x122`
(сеттер `0x8fd1088`, вызывается косвенно — прямых BL к нему нет, значит таблица
указателей на свойства). Это следующий статический шаг.
