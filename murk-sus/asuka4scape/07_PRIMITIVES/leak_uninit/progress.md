# progress — leak_uninit (subagent U)

## step 1 — инструменты
`macho.py` (сегменты 27.2/27.0, плоский `va-base`), `kdis.py` (recursive-descent, аннотация adrp/add → строки),
`ldis.py` (линейный дамп), `refs.py`/`stubs.py` (ADRP+ADD/ADD-база и `__auth_stubs` → PAC-слот),
`table.py` (разбор `IOExternalMethodDispatch2022`), `diffkc.py` (27.0 vs 27.2).
Грабли подтверждены: capstone `adrp` — 32-битный imm, нужен `& 0xFFFFFFFFFFFFFFFF`; `add xD, xB, #imm`
надо матчить по **базе** (`xB`), а не по приёмнику.

## step 2 — таблица и диспетчер
A `0xfffffff008068b90` (60 × 0x28), B `0xfffffff0080694f0`; выбор в `0x9c3ee10` по `ldrb [uc+0x127] & 1`.
`checkEntitlement` (entry+0x20) = 0 у всех 60 в обеих таблицах; `allowAsync` = 1 только sel 17 и 40.
`IOExternalMethodArguments`: scalarInput +0x20, structureInput +0x30/+0x38, inDesc +0x40,
scalarOutput +0x48, structureOutput +0x58, structureOutputSize +0x60, outDesc +0x68, varOut +0x78.
Целевой вызов — `IOUserClient2022::dispatchExternalMethod` (стаб `0x9c498f4`).

## step 3 — 3176-байтные выходы
`0x9c2c18c` — единственная fill-функция `IOSurfaceData`; первым делом `bzero(out, 0xC68)` (`0x9c2c1f8..0x9c2c1fc`,
bzero = `0xaa65cc0`). Call-site'ы: `0x9c3ae9c` (sel0), `0x9c3b500` (sel2), `0x9c3b714` (sel4), `0x9c3b968` (sel34),
`0x9c3bd84` (sel6), `0x9c3c1bc` (sel7). Все успешные пути проходят через неё → дыр нет.

## step 4 — sel 28 (`0x9c39660`)
`0x9c3d838` ставит локальный размер `0x84`, зовёт `0x9c26438`; тот копирует stack-структуру `0x84` целиком
(`memcpy` @`0x9c265a0`, стаб на `0xaa65b10`; `sp+0x67` закрыт `str wzr,[sp,#0x64]` @`0x9c264b8`),
затем `0x9c3d8a4` пишет `*structureOutputSize = 0xA0`. Дыра `out+0x84..0x9F` (28 Б) — reply-буфер, нули.

## step 5 — sel 34 (`0x9c397d8`)
Ветка «уже импортирован» `0x9c3b884..0x9c3b8a4`: `w19=0`, `out[0]=-1`, `out[0x18]=[client+0x38]`,
остальные 3164 Б не тронуты. Reply-буфер нулевой → не утечка.

## step 6 — sel 13 (`0x9c38f84`) и скаляры
0x28 объявлено, не пишутся `0x21` + `0x24..0x27` (5 Б). Скалярные селекторы: `is_io_connect_method` сам
`bzero(scalar_output, cnt*8)`, обработчики обнуляют `[sp+4]/[sp+8]/[sp+0x10..0x20]` (`stp xzr`/`str wzr`);
все sOut пишутся, утечки нет.

## step 7 — 27.0 vs 27.2
Таблицы идентичны по counts; «разные» первые 32 Б у sel 16/17/18/20/23/25/35/36/55/58 — только сдвиг
глобала stack-canary (adrp target). Код не менялся.

## вердикт
Подтверждённой утечки нет: дыры закрывает `IPC_KMSG_ALLOC_ZERO` в `ipc_kobject_server_internal`
(проверено по xnu-4903 и main; в бинаре 27.2 символов нет — предпосылка). Остаточный риск: sel 28 (28 Б)
и sel 34 (3164 Б) при необнуляемом приёмнике. Отчёт: `REPORT.md`.
