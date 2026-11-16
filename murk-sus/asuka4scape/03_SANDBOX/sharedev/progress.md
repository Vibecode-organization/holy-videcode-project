# progress — UAF/гонки в IOSurfaceSharedEvent и IOFence (27.2 24B115)

Статус: готово, `REPORT.md`.

- [x] Собрал `kc.py` (короткая форма адреса `0x9c…` = `0xfffffff009c…`, `__TEXT_EXEC` offset = VA−`0xfffffff007004000`, PAC = `0xfffffff007004000+(q&0x0FFFFFFF)`), `x.py` (поиск вызывающих по `bl`/`b`), `fn.py` (карта функций по `bti c`).
- [x] Нашёл таблицу селекторов: `externalMethod 0x9c3ee10`, A `0x8068b90`, B `0x80694f0`, запись 0x28, 60 шт, гейт `uc+0x127` bit0; в B подменены 4-8,16-19,21,22,24-26,28-30,33,43,46-49 на `0x9c3a1dc` (`0xe00002e2`).
- [x] Регистрация классов `0x9c18b44`: Listener 0x50 (`0xaf48120`), NotificationPort 0x90 (`0xaf48148`), Reference 0x18 (`0xaf48170`), SharedEvent 0x68 (`0xaf48198`, инстанс-vtable `0x8066a10`), Notification 0x70 (`0xaf481c0`); `IOSurfaceSendRight` 0x28 (`0xaf484d0`).
- [x] SharedEvent: retain `vt+0x20`=`0x9c17f60` (`ldadd +1` по `+0xc`), release `vt+0x28`=`0x9c17f6c`, dtor `0x9c16c68`, free `0x9c16cdc` (panic `0x9c48e50` при `[+0x40]≠0`, живой вызов из `0x9c16dac`).
- [x] sel36 `0x9c3dad4`: `create 0x9c16a78` → `ref 0x9c165ec` (+1) → `0x9c41eec` (маппинг shared-страницы) → `ipc_port_copyout_send_right 0xa9a7b30` (всегда возвращает 0) → release ref+event на всех ветках. Двойного release нет.
- [x] sel37 `0x9c3d16c` / sel45 `0x9c3d038`: `ipc_object_copyin 0xa9a7bc0` даёт +1 на Reference, `safeMetaCast` `0xa894f30` по метаклассу `0xaf48170`, `[ref+0x10]` → signal `0x9c16db0` / wait `0x9c172ec`; release после. Событие живо весь вызов.
- [x] Listener: init `0x9c15480` (lock `+0x10`, очередь `+0x18/+0x20`, workloop `+0x30`, thread_call `+0x38`), add `0x9c158dc` под локом, drain `0x9c159b4`, free `0x9c157d4` — проверка `[+0x18]` **вне лока** → panic `0x9c48e20` (живой, вызов из `0x9c158d8`).
- [x] `Notification::~ 0x9c18420` отпускает `+0x40` (listener) → непустая очередь при rc=0 невозможна; UAF не подтверждён, инвариант на refcount.
- [x] sel34 `0x9c3b7b0`: `IOSurfaceSendRight` dtor `0x9c47788` отпускает `+0x18` ⇒ поверхность под +1, чтения `+0x3d2`/`+0x170` до `0x9c2b810` — не UAF (закрыт «не подтверждено #3» из `uaf_surf`).
- [x] IOFence: `IOFenceTransaction::free 0x9c19270` (panic при count≠0), dump `0x9c1933c` под `+0x20`; fence-счётчик `[surf+0x178]+0x18` — lock-free `cas` с сатурацией (`0x9c22ee0`/`0x9c2302c`), обход при `+0x3d2 bit5`.
- [x] Найдены два гейтед-дефекта: `allocAgentMaskSlot 0x9c18180` (check-then-act по `+0x58` без лока: потеря блока 0x70 + IOLock, дубль регистрации в `0x9c36be0`) и `free 0x9c16cdc` (agent-блок `+0x58` kfree без снятия регистрации). Оба за битом энтайтлментов `0x80000` (`0x9c31488`, `root+0x1a4`).
- [x] Поправка к зацепке: строки `IOSurfaceSharedEventAddEventListener` в кернеле нет; в sel34 читается бит 3, а не 5.
- [x] Записал `REPORT.md` (таблица объект|ref|лок|вердикт, топ-3 с дизасмом и двумя потоками, раздел «не подтверждено»).
- [x] Добавил запись `## SharedEvent/IOFence (subagent AC)` в `CHAT_дипсики.md`.
