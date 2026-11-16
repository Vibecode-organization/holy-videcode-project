# progress — verify_zero (subagent Z2)

## step 1 — инструменты
`macho.py`/`kdis.py`/`ldis.py` (из `leak_uninit`), новый `scan_ref.py` — ADRP+ADD/LDR по
`__PRELINK_TEXT` + `__TEXT_EXEC`, imm маскируется `& 0xFFFFFFFFFFFFFFFF`.
Грабля: в первом сканере `add x8,x8,#imm` принимался за `add xD,xB,#imm` — 0 попаданий; после
проверки `parts[0]==parts[1]==reg` якоря нашлись.

## step 2 — якоря
Символов в 27.2 нет (нет LC_SYMTAB), искал по panic-строкам:
`"ipc_kobject_server: strange destination rights"` → `0xa217ad4`, функция `0xa21722c`;
`"size too large for the fast kmsg zone"` → `0xa1e6e18`, функция `0xa1e6b4c` = `ipc_kmsg_alloc`.
`ipc_kobject_server_internal` инлайнен в `ipc_kobject_server` (hash-lookup + alloc + blraa + panic в одной функции).

## step 3 — вызов аллокации
`0xa2174f4 bl 0xa1e6b4c`, аргументы: `w0=kreply_size` (`[mig_bucket+0x10]`), `w1=0`, `x2=desc_cnt`,
`w3=0xB` = KERNEL(1)|ZERO(2)|NOFAIL(8). Крoutine — `0xa217908 blraa x8`. Выделение строго до вызова.

## step 4 — трансляция флага
`0xa1e6c70 lsr w8,w3,#1`; `0xa1e6c78 lsl w21,w25,#0xc` (NOFAIL→0x8000); `0xa1e6c7c bfi w21,w8,#2,#1`
(ZERO→0x4). Payload alloc `0xa1e6ca0`, kdata alloc `0xa1e6d10` — оба с `x2=w21`; kmsg zalloc `0xa1e6d30`
с `w2=0x8004`. Контроль: `ipc_kmsg_alloc_uext_reply` шлёт `0x1B` (`0xa1e6e48`) — совпало с исходником,
значит раскладка флагов декодирована верно.

## step 5 — OOL
`is_io_connect_method` (MIG 2865) `0xa34ed50` → prep `0xa9ae990`: `args+0x58 = inband_output`
(`0xa9aeb3c`), `args+0x60 = *inband_outputCnt`; OOL-дескриптор — отдельно `args+0x68` из
`IOMemoryDescriptor::withAddressRange(ool_output, ..., current_task())` (`0xa9aeb6c/0xa9aeb74`).
`dispatchExternalMethod` (`0xa9b0888`) для OOL только `getLength()` (`0xa9b09ac`).
sel 28 `0x9c39660` и sel 34 `0x9c397d8` забирают только `+0x58`; в телах `0x9c3d838..0x9c3d908` и
`0x9c3b7b0..0x9c3b9f8` обращений к `+0x68/+0x70` нет (grep по дизасму — пусто).

## step 6 — вердикт
Zeroing подтверждён инструкциями; дыры sel 28 (28 Б), sel 34 (3164 Б), sel 13 (5 Б) — нули.
OOL не обходит: обработчик пишет в inband reply (нулевой), user-буфер не трогает.
Не подтверждено: конкретный `memset` внутри generic-аллокатора (Z_ZERO→KMA_ZERO) — только флаг+контракт;
динамика не снималась. Отчёт: `REPORT.md`.
