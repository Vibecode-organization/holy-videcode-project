## step 1 — карта таблицы A и имена хендлеров
- Разобрал Mach-O (9 сегментов), исправил знаковое расширение adrp/b/bl, собрал индексы bl/b и adrp+add.
- Таблица A 0x7fea200: 56 записей, PAC fn = BASE+(q&0x0FFFFFFF) — сходится с 0x99491a0/0x9949330.
- Все 56 fn резолвнуты в VA 0x9947330..0x9949530.
- 19 `__func__`-строк IOGPUDeviceUserClient найдены и сопоставлены по xref с телами функций.
  sel 0-5 = геттеры аргументов, sel 6 = s_new_command_queue (0x99476bc, 0x304),
  sel 7 = s_delete_command_queue (0x99479c0, 0x94), sel 8 = s_new_resource (0x9947a54),
  sel 9-24 = мелкие тайл-колы в 0x9965xxx/0x9966xxx, sel 25 = s_submit_command_buffers (0x9947de4),
  sel 40/42/43/44/45/46..51, 52/53, 54, 55.

## step 2 — примитивы таблицы объектов (namespace)
Класс таблицы: [ns+0x10]=массив ptr, [ns+0x18]=bitmap, [ns+0x20]=mutex, [ns+0x28]=capacity,
[ns+0x2c]=low-water, [ns+0x30]=count.
- 0x9944798 = add (lock 0x994463c → 0x9944654 insert → unlock 0x9944648), возвращает id, 0 = ошибка.
- 0x9944654 = insert: поиск свободного бита от [ns+0x2c]>>6, слот пишется ЧЕРЕЗ vtable+0x78,
  потом ставится бит, count++; при нехватке — grow 0x9944424.
- 0x9944fb8 = retain by id: bounds-check, `ldr x0,[tab+id*8]`, `ldadd w9=1, w8, [x0+0xc]`,
  при old>=0xFFFFFFF → 0x9983678 (panic os_refcnt overflow).
- 0x9945040 = retain by id ПОД локом [ns+0x20].
- 0x9945214 = lookup БЕЗ ref и БЕЗ лока (17 вызовов, все внутри локов у вызывающих).
- 0x994508c = remove: bounds-check, ldr слота, `str xzr` в слот, сброс бита, count--, возврат указателя.
  Слот обнуляется ДО возврата; вызывается только под локом (6 мест).
- 0x9945154 = remove под локом, возвращает объект БЕЗ release.
- 0x99451a0 = remove под локом + release (vt+0x28) ПОСЛЕ unlock.
Итог: id→объект защищён мьютексом; retain всегда берётся под тем же мьютексом, что и remove.

## step 3 — namespace-офсеты IOGPUDevice
+0x10 ресурсы/группы, +0x18, +0x78, +0x80, +0x88 command queues, +0x90 io queues,
+0x108 vniodesc, +0x110 IOCommandQueue. add/remove+release парны для каждого.

## step 4 — подтверждение модели рефкаунта
- Найдено `0x994d928` = `IOGPUObject::retain()`: `add x8,x0,#0xc; mov w9,#1; ldadd w9,w8,[x8]`
  + проверка `old >= 0xFFFFFFF` → `0x9983678`.
- `0x994d95c` = `IOGPUObject::release()`: `add x0,x0,#0xc; mov w8,#-1; ldaddl w8,w8,[x0]`.
- Строка `'"gpu_refcnt: overflow (rc=%p)\n" @%s:%d'` = 0x782ae35, файл `IOGPUObject.cpp` = 0x782c0fc.
- Строка `'"IOGPUObject does not support release with when != 1"'` = 0x782c10c → vt+0x28 = release(when).
- Значит +0xc — настоящий счётчик жизни, и 0x9944fb8 (retainById) — настоящий retain. Модель корректна.

## step 5 — пространства имён устройства
+0x10 ресурсы/группы, +0x18 resource-set, +0x78, +0x80, +0x88 очереди, +0x90 io-очереди,
+0x108 vniodesc, +0x110 IOCommandQueue. Для каждого add/remove адресуют один офсет — рассинхрона нет.

## step 6 — результат
- UAF в пути id→объект НЕ найден: lookup/retain/remove сериализованы мьютексом [ns+0x20],
  слот обнуляется до возврата, release всегда вне лока, retain держится всё время операции.
- Подтверждённые дефекты: (1) TOCTOU лимита очередей (чтение ns->count вне лока, 0x99476f4 vs add 0x9947878),
  (2) счётчик [uc+0x11c] не откатывается на error-ветках sel 6,
  (3) sel 9 (0x9965954) удаляет ресурс и вызывает только vt+0xb0 без release — утечка gpu_refcnt (не подтверждено).
- Не подтверждено: что делает vt+0xb0; достижимость AGXCommandQueue из таблицы 0x7fea200 (её там нет).
- REPORT.md записан.

## step 7 — уточнение по 17 сайтам lookupRaw
Скриптовая проверка (bl-индекс + поиск 0x994463c в теле до сайта):
12 сайтов доказанно под локом, 5 — thunk-и без лока в теле:
0x9965624 ([x0+0x10] ресурсы), 0x9965b54 (+0x78), 0x9965c90 (+0x18), 0x9965cc0 (+0x100), 0x9965f2c (+0x80).
Это виртуальные getObjectNoRetain; в образе нет ни bl-цели, ни data-слота с резолвом BASE+(q&0x0FFFFFFF).
В REPORT.md они вынесены в «не подтверждено» как единственное непокрытое место модели.
