# UAF/гонки IOMobileFramebufferUserClient — 27.2 (24B115)

Статус: анализ завершён, отчёт `REPORT.md`.

## Шаги
- [x] 1. offsets/адреса подтверждены; хелпер `macho.py` (capstone 5.0.7)
- [x] 2. externalMethod 0x9aa33b8: pre-gate fb->vt[0x5c0]=0x9a778d8, таблица 0x8023ad0 (0x65), validator 0xa9b0888
- [x] 3. sel 0x44 0x9aa42dc: count=size>>3, op 0xb inc/dec +0xfc, fb->vt[0x780]
- [x] 4. close/дренаж 0x9aa17b8/0x9aa17d0: dec-loop, tear-down 12×0xb0, vt[0x620]
- [x] 5. sel 0x4e/0x4f: 0x9aa3d3c/0x9aa3e34 -> vt[0x720]/[0x728]; IOMemoryDescriptor::withAddress
- [x] 6. free 0x9aa156c: 0x3b8/0x3c0, +0xd8 не чистит; retain fb нет
- [x] 7. REPORT.md + CHAT_дипсики.md

## Ключевые факты
- Записи таблицы: 0x44 scalar_in=1,struct_in=-1; 0x4e/0x4f все -1 (нет проверок).
- +0xfc: только ldadd (0xa8945fc/0xa89460c), лока нет; stop drain: dec -> while(old>0) vt[0x780](fb,0xb,&zero,1).
- Handler'ы не читают uc+0xe0; stop освобождает uc+0x110 и снимает клиента без сериализации.
- fb = safeMetaCast(provider) в +0xd8 без retain; free/stop не освобождают и не обнуляют.
- sel 0x4f без entitlement-check; vt[0x890] -> [fb+0x5e90]->vt[0x670] = 0x8e6a644 (unsupported) — retention не подтверждён.
- Diff 27.0 vs 27.2: внешние методы и sel 0x44/4e/4f идентичны (не фикс 27.2).

## Вердикт
Гонка close/stop vs externalMethod подтверждена структурно; конкретный UAF не подтверждён.
Дальше: динамика с KASAN, два потока 0x44/{1}/8 vs IOServiceClose.
