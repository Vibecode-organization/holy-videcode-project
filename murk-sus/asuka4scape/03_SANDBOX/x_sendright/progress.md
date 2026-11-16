# progress — x_sendright (subagent T)

## step 1 — инструменты
Собран `kc2.py`: карта сегментов 27.2, парсер kext-слайсов (LC_FILESET_ENTRY 0x80000035), `scan_adrp_to`
(adrp+add/ldr, включая двух-add), `stub_target` (GOT adrp+add+ldr+braa → PAC-слот), `stubs_of`.
Грабля подтверждена: capstone `adrp` отдаёт 32-битный imm — нормализация `0xfffffff000000000 | imm`.

## step 2 — IOSurfaceSendRight
Метаклассы: `IOSurfaceSendRight` 0xaf484d0 (sizeof 0x28, vtable 0x806a870), `IOSurfaceWiredSendRight`
0xaf484f8 (0x806a9a8). Это OSObject, не IOUserClient; `externalMethod` у класса нет.
Раскладка: `+0x10 id`, `+0x18 IOSurface*` (retain в init 0x9c4755c, release в dtor 0x9c47174),
`+0x20 wired`, `+0x21 lock/held`. Фабрика `create 0x9c47474` (+ wired 0x9c47a80).
Выдача: `0x9c33ad8` → create → `0xa9a7b30` → `0xa34c248` (MOVE_SEND). **0 ссылок** на 0x9c33ad8/0x9c47474/
0x9c4746c во всём образе (bl/b скан + data + литералы) → surface-путь мёртв; `0xa9a7b30` жив через sel36.
Живой импорт: sel34 `0x9c397d8` → `0x9c3b7b0`: имя порта из scalarInput[0], lookup в task+0x310
(0xa9a7bc0→0xa34be34, тип 0x26, retain), safeMetaCast(meta 0xaf484d0), surface=+0x18, id=surface+0x10,
поиск в [uc+0x108]. Владелец проверяется только при `surface+0x3d2 bit3` (свойство `IOSurfaceIsPrivate`,
ставится 0x9c1e120): `surface+0x170` (PAC task, key 0xf19c) == `uc+0xf8`, иначе 0xe00002c2.
Release kobject один — 0x9c3b980 (vt+0x28). `ipc_port_release_send` не зовётся; double-free нет.
sel36 `0x9c39868` → `0x9c3dad4` — это выдача порта для IOSurfaceSharedEvent, не для поверхности.

## step 3 — IOGPUDeviceUserClient
meta 0xaf22218, sizeof 0x130, live vtable 0x7fe9b88 (ctor 0x9946d00/0x9946d70/0x9946dcc).
Слоты: +0x70 free 0x9946f44, +0x540 externalMethod 0x994a1dc, +0x560 clientClose 0x994a164,
+0x5d0 start 0x9949db8, +0x5d8 stop 0x9949ff0, dtor 0x9946c14/+0x08 0x9946c1c.
externalMethod: gate uc+0x100 bit0 → 0xe00002d8, sel 0..0x37, asyncRef != 0 → 0xe00002c2,
таблицы 0x7fea200 (56) / 0x7fea740 (restricted) stride 0x18, tail → 0xa9a18bc.
free: release [0x120],[0x110],[0x108]; free пары [0xd8], [0xf0]; super::free; без лока/ref/isInactive,
[0x120] не обнуляется, uc+0x100 не чистится.
stop: "AppUsage", provider->drain 0x9965338, release/zero [0x110]/[0x108], clears uc+0x100; ref провайдера
не снимает (это free). clientClose: provider vt+0xa0, self vt+0x2f0(this,0); флаг не чистит.
dtor: kfree_type(0x7feffe8, 0x130) — только память, члены не трогает.
Синхронизация: класс ничего не делает; IOKit — trap retain 0xa34bbcc (vt+0x20) / release 0xa34eef4,
ldadd +1 в uc+0x9c под локом uc+0xb0 (0xa9ae888, close 0xa9ad368), free только по rc=0.
«ldadd в uc+0x9c» — общий IOUserClient-счётчик, не код IOSurface (в 27.2 в IOSurface его нет).

## step 4 — результат
REPORT.md записан; запись в CHAT_дипсики.md; sbx_build/IPA не трогал.
