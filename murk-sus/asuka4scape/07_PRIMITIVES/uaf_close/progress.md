# progress — free() против in-flight externalMethod (27.2 24B115)

Статус: готово, `REPORT.md`.

- [x] Собрал `kc.py`: flat-образ (`fileoff = va - 0x7004000`), capstone 5.0.7, маска знаковых imm у adrp/b/bl.
- [x] Взял MIG-таблицу `mig_27.2.txt`: `_Xio_connect_method 0xa34ed50`, `_Xio_connect_method_var_output 0xa34dff8`, `_Xio_connect_async_method 0xa34ea58`, `_Xio_service_close 0xa352d64`.
- [x] `iokit_lookup_connect_ref 0xa34bbcc`: kobject из `[port+0x50]` (autda 0x7d), виртуальный retain по vtable`+0x20` → возврат **+1**.
- [x] Все четыре входа делают lookup → воркер → release по vtable`+0x28` **после** возврата воркера (`0xa34eef4`, `0xa34e19c`, `0xa34ecb8`, `0xa352dc4`). Async снимает ref сразу после `bl 0xa9aed20`.
- [x] `is_io_connect_method` обёртка `0xa9ae888`: лок `uc+0xb0` по флагам `uc+0x9b` биты 2/3, **безусловный** `ldadd +1` в `uc+0x9c`, вызов `externalMethod` через vtable `+0x540`/`+0x5d0`, выход через `0xa9a5808`.
- [x] `0xa9a5808`: `--uc+0x9c`; при old==1 и истинном `vt+0x298` → `scheduleFinalize 0xa9172f8` (строка `%s[0x%qx]::scheduleFinalize`). Финализация откладывается до последнего выходящего вызова.
- [x] `is_io_service_close 0xa9ad368`: CAS `uc+0x99` 0→1 (двойной close → лог `ignored is_io_service_close`), `lck_mtx_lock(uc+0xb0)`, `++uc+0x9c`, `vt+0x560` (clientClose), unlock+gate mode 2. Объект не освобождает.
- [x] SURF: `externalMethod 0x9c3ee10` — только выбор таблицы по `uc+0x127`, isInactive нет; `free 0x9c3a678` = vtable`+0x70`, прямых `bl`/`b` нет (скан всего `__TEXT_EXEC`); `clientClose 0x9c3ab48` — 3 инструкции, членов не рвёт. Вердикт: **безопасно**.
- [x] MFB: `externalMethod 0x9aa33b8` — только `fb->vt[0x5c0]` pre-gate; `stop 0x9aa17b8` (vtable`+0x390`, прямых `bl`/`b` нет) рвёт члены: дренаж `+0xfc`, `removeUserClient`, release 12 записей `uc+0x110`. Вердикт: объект жив, **гонка по членам**, нужен порядок двух потоков.
- [x] GPU: `externalMethod 0x994a1e0` проверяет `uc+0x100` bit0 (иначе `0xe00002d8`), selector<0x38, таблицы `0x7fea740`/`0x7fea200`. free/stop не разобраны → member-гонка **не подтверждена**.
- [x] Общий диспетчер `0xa9b0888` (через GOT-трамплин `0x9abd40c`, слот `0x8029f70`): валидация `IOExternalMethodDispatch` (stride 0x28, `-1` = не проверять), isInactive не проверяет.
- [x] Записал `REPORT.md` (таблица вердиктов, дизасм 10–20 инструкций на ключ, раздел «не подтверждено»).
- [x] Добавил запись `## free() против in-flight (subagent Q)` в `CHAT_дипсики.md`.
