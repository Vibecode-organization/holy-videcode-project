## step 1 — карта владения из исходников XNU (найдены в /tmp/opencode)

- В `/tmp/opencode` лежат исходники XNU: `xnu-main` (12377.x) и tar'ы 12377.61.12/81.4/121.6.
  Ключевой файл: `libkern/c++/OSSerializeBinary.cpp` — это ровно тот алгоритм, что в кеше
  по `0xa8d97a0`: `setAtIndex` (рост массива на +64 записи), `objsIdx/objsCapacity`,
  `stackIdx/stackCapacity`, финальный цикл
  `for (len = (result != NULL); len < objsIdx; len++) objsArray[len]->release();`
  и `kfree_type(OSObject*, objsCapacity, objsArray)`.
- Сверка с дизасмом: `0xa8d9cd4 lsl w2,w26,#3; add w3,w2,#0x200` = `ncap = capacity + 64`
  (64*8 = 0x200) — совпадает с макросом `setAtIndex`; `0xa8da29c cmp w23,#0x3f`
  = `stackCapacityMax = 64`; финальный блок `0xa8da358..0xa8da3d8` = тот самый цикл.
- Значит владение можно читать по исходнику, а по кешу проверять только расхождения.
  Ниже — карта refcount и места, где она рвётся.
- Инструмент: Ghidra-проект `/tmp/opencode/ghproj272` (`com.apple.kernel`) — байты по
  адресам 0xa8d... совпадают с кешем побайтово (проверено на 0xa8d96f4), запущен
  декомпилятор в `/home/femboychik/work/uaf_unser/decomp/`.

## step 2 — бинарный парсер: дизасм цикла + декомпиляция
- Снял весь цикл `0xa8d97a0`…`0xa8da46c` (`mainloop.txt`, 820 инстр.) и декомпилировал
  `0xa8d96f4` в Ghidra (`decomp/fn_fffffff00a8d96f4.c`, 3336 B кода). Структура совпала
  с `OSSerializeBinary.cpp` построчно (setAtIndex/cleanup/stack).
- Состояние: `[sp+0x70]`=objsArray, `[x29-0x64]`=objsIdx, `[x29-0x60]`=objsCapacity,
  `[sp+0x10]`=stackArray, `[sp+0xc]`=stackIdx, `[sp+0x20]`=stackCapacity(max 64).
- Все release-сайты: 0xa8d9900/0xa8d9ad0/0xa8d9b64/0xa8d9bf8/0xa8da110 (провал init),
  0xa8da04c и 0xa8d9f78 (ключ после callback-вставки), 0xa8da32c (объект до инкремента
  индекса), 0xa8da358 (cleanup). Двойного release нет.

## step 3 — рост массивов
- 0xa8d9cd4 (objs): `kreallocp`-подобный 0xa2217b4, newsz = cap*8+0x200 (== +64 записи),
  новый указатель единственный, пишется в [sp+0x70].
- Декомпилировал 0xa2217b4: при провале возвращает {0,0} и НЕ освобождает старый блок
  (ветка `param_5>>3 & 1 == 0`, у нас 0x41244). Значит cleanup вправе свободный старый
  указатель — double free нет.
- Стек: max 64 (0xa8da29c), индекс валидируется, стек-кадр не переполняется.

## step 4 — XML-путь
- 0xa8d5ea4 = bison-парсер из OSUnserializeXMLSharedImplementation.h (нашёл исходники
  XNU в /tmp/opencode/xnu-main). Проверено: buildArray 0xa8d8238, buildBoolean (retain
  через +0x20), cleanupObjects, MAX_OBJECTS=131071 (0xa8d6a74), livecount 0x10000.
- buildDictionary: setObject → key->release() → object->release(), оба обнуляются;
  дубликат ключа ловится в правиле `pairs` по указателю интернированного OSSymbol.
  Принятый корень обнуляется (case 3) → cleanup его не трогает.
- Слоты vtable подтверждены: +0x20 retain, +0x28 release, +0x38 getMetaClass,
  +0xe8 OSArray::setObject, +0xf0 OSDictionary::setObject(OSSymbol*,OSObject*),
  +0x100 setObject(const char*,...), +0x118 OSArray::getObject(i),
  +0x138 OSDictionary::getObject(const char*).

## step 5 — IOSurface: create_surface и применение словаря
- Декомпилировал срез __TEXT_EXEC 0x9c00000-0x9c50000 в Ghidra (`decomp_ios/`):
  0x9c3ab8c (create_surface), 0x9c33c34, 0x9c1a914 (ctor), 0x9c1af14 (применение
  свойств, 14 KB), 0x9c24b28 (setValue), 0x9c3c3bc/0x9c3c800/0x9c3d564/0x9c3e388
  (потребители OSUnserializeXML), 0x9c43898/0x9c43a1c.
- Результат парсинга в create_surface отпускается ровно один раз (общий эпилог
  0x9c3b078) на всех 6 выходах; родитель — 0x9c3b040.
- Владение словарём: `FUN_0x9c16670(surface+0x268, dict)` = retain; `0x9c43a1c`
  кладёт словарь в [obj+0x98] с retain; setValue → `[dict+0xf0](dict,key,value)`.
  Сеттеров «сохранил без retain» не найдено.

## step 6 — найденные дефекты
- 0x9c3e388: dict-ветка теряет +1 результата OSUnserializeXML (x21 перезаписывается
  пулом на 0x9c3e3f0; release словаря 0x9c3e534 снимает только retain 0x9c3e410).
  В non-dict ветке release есть (0x9c3e464) — асимметрия доказывает утечку.
  Прямых bl-xref нет (blscan.py по всем exec-сегментам) → достижимость не подтверждена.
- 0x9c3ab8c: retain объекта по ключу "IOSurfaceAllocateFromSuperbuffer" (0x8066fc0)
  не снимается на ветках 0x9c3ad2c и 0x9c3ad80; нужен класс 0x806c9f8 → из plist
  не собрать.
- Бинарный словарь: ключ не приводится к OSSymbol (вставка 0xa8d9ecc), приведение есть
  только в callback-ветке 0xa8d9f00. Latent type confusion.
- OOM: buildDictionary/buildArray не проверяют NULL от withCapacity → NULL-deref (DoS).

## step 7 — отчёт и запись в чат
- REPORT.md (таблица владения, топ-3 с дизасмом, последовательность-кандидат, список
  отброшенного, артефакты). Вердикт: UAF/double-release не подтверждён.
- Запись `## UAF десериализатора (subagent N)` в CHAT_дипсики.md.
