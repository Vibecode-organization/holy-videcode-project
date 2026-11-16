# progress — keytype (subagent AB2)

- 27.2_24B115: диспетчер `0xa8d8754` = `OSUnserialize(buf,len,err)`; `strncmp(buf,"<?xml",4)`
  (`0xaa7451c`), иначе `buf[0]==0xd4` -> tail `b 0xa8d96f4` (binary), XML -> `0xa8d846c`.
- GOT: 19 слотов в __DATA_CONST указывают на `0xa8d8754`; 43 `bl` через PLT-заглушки
  (`adrp/add/ldr/braa`) + 8 прямых `bl 0xa8d8754` = 51 сайт, достижимый бинарным путём.
  Ещё 15 сайтов зовут XML-входы (`0xa8d846c` x9, `0xa8d5c98` x5, `0xa8d5ea4` x1).
- ГЛАВНОЕ: проверка типа ключа ЕСТЬ. `0xa8d9d64..0xa8d9db8`: два inline OSDynamicCast
  (обход `[mc+0x10]`) — OSSymbol `0xad95eb8`, OSString `0xad95ee0` -> `OSSymbol::withString`
  `0xa8d4088`. `setObject` vtable+0xf0 на `0xa8d9ecc`; `sym==NULL` -> setObject(NULL,val)
  = false -> `0xa8d9fa8` -> `0xa8da320` cleanup, result=NULL.
  Проверка inline, не через `bl` — поэтому по `bl OSDynamicCast` не находится.
- `0xad95c70` = OSDictionary::gMetaClass (подтверждено по `0xa8c0a60` + "not a dictionary").
- Потребители: null-check -> safeMetaCast(`0xa894f30`) к OSDictionary -> getObject по имени
  (vtable+0x138 c-string / +0xa8 symbol). Итерации по ключам с C-cast не найдено.
- Итог: путь «непроверенный ключ -> вызов/чтение по подконтрольному объекту» не подтверждён;
  на 27.2 он закрыт в парсере. Отчёт: work/keytype/REPORT.md.
- Инструменты: find_slots.py, blxref.py, meta2.py, annot.py, summ.py (ксэш-хелперы в кэше).
