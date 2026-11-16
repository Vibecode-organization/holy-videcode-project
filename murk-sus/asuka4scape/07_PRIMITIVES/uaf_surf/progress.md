# progress — UAF/двойное освобождение IOSurface, 27.2 24B115

- [x] Смаппил kernelcache: `__TEXT_EXEC` fileoff = va-0x7004000, `__DATA_CONST` = 0xbb4000+(va-0x7bb8000). Проверил на `0x9c3ab8c` (bti/pacibsp) — совпало.
- [x] Разобрал таблицу селекторов `0x8068b90`: 60 записей stride 0x28, запись = `{pac(handler), u32 scalarIn, u32 structInSize, u32 scalarOut, u32 structOutSize, ...}`. Выписал handler→impl для всех 60 (sel0 create 0x9c3888c→0x9c3ab8c, sel1→0x9c3b0bc, sel53→0x9c3b240, sel34→0x9c3b7b0, sel28→0x9c3d838 …).
- [x] Нашёл vtable IOSurface `0x8067138`: `+0x20` retain `0x9c1f3f0` (atomic ++ по `[surface+0xc]`), `+0x28` release `0x9c1f484`, free `0x9c1f830`. Слоты в вводной (`+0x28/+0x30`) сдвинуты на 8 — в этом билде retain/release = `+0x20/+0x28`.
- [x] Подтвердил контракт `lookupSurface 0x9c3f1d0`: `[uc+0xd8]` lock → `0x9c3f044` по `[uc+0x108]/[0x110]` → сверка `entry[+0x10]==uc[0x118]` → retain `entry[+0x40]` → unlock → возврат +1.
- [x] Подтвердил владение: entry `0x9c2b8c8` retain'ит поверхность в `+0x40`; `set_surface_handle 0x9c3f2b0` retain'ит entry и паникует на занятом слоте (`0x9c492f0`); root map `0x9c33dc4/0x9c33548/0x9c33a4c (+tryRetain 0x9c1f34c)/0x9c35dcc`, сверка id/surface при release (`0x789c83f`).
- [x] Прогнал CFG-аудит 33 сайтов `bl 0x9c3f1d0` (`audit.py`, `cfg.py`): нет `ret`-пути без release, нет двойного release одного регистра. Все error-ветки create/`sel2/4/9/10/26/28/34/53/57` сходятся в общий эпилог.
- [x] Проверил sel28 (0x9c3d838) и sel34 (0x9c3b7b0) на structureOutput: sel28 держит +1 на всё копирование `0x9c26438`; sel34 работает по entry из `0x9c3f044` под локом. Окна «release → копирование» нет.
- [x] Нашёл `IOSurfaceRootUserClient::free 0x9c3a678`: освобождает entry/таблицу/`OSArray[0x140]`/лок `[0xd8]` без лока и без isInactive — подозрение #1 (гонка с in-flight externalMethod, не подтверждено).
- [x] Нашёл асимметрию release: `sel1 0x9c3b0bc` (release после unlock, не чистит `[uc+0x108][id]`) vs `sel53 0x9c3b240` (чистит под локом, кладёт entry в `[uc+0x140]` через `+0xe8`=setObject) — подозрение #2 (не подтверждено).
- [x] Сверил 27.0/27.2: `free`, `lookupSurface`, `sel1`, `sel53`, `create_surface`, `rootRel` — поток инструкций идентичен (сдвиг 0x3bfa8), не регрессия 27.2.
- [x] Написал `REPORT.md` (таблица «функция|retain/release|лок|вердикт», топ-3 с дизасмом и последовательностями, раздел «не подтверждено»).
- [x] Добавил запись `## UAF IOSurface (subagent L)` в `CHAT_дипсики.md`.
