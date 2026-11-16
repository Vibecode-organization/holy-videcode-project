# IOSurface UAF / double-free audit — kernelcache iOS 27.2 (24B115)

Target: `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`
Class: `IOSurfaceRootUserClient` (open from sandbox, no entitlement — only the misc
`com.apple.private.iosurfaceinfo` changes behaviour, see `0x9c3a2d4`).
Method: static RE, Capstone ARM64, Mach-O segment mapping. No device run — every
unproven statement is marked **не подтверждено**.

## 0. Итог

**Подтверждённого UAF/double-free не найдено.** Все прямые пути «id → объект»
(`lookupSurface 0x9c3f1d0`, `0x9c3f130`, root-lookup `0x9c33a4c`) отпускают
ссылку на каждой возвращающей ветке, включая error-ветки. Дисциплина локов
`[uc+0xd8]` (per-client `lck_mtx`) и `[root+0x140]` (root `lck_mtx`) выдержана.

Три места остаются подозрительными; они требуют нарушения времени жизни
user-client'а или обёртки `IOSurfaceSendRight`, поэтому статус — **не подтверждено**:

1. `IOSurfaceRootUserClient::free 0x9c3a678` — не берёт `[uc+0xd8]`, не проверяет
   `isInactive`, освобождает таблицу `[uc+0x108]` и сам лок `[uc+0xd8]`.
2. `sel1 0x9c3b0bc` vs `sel53 0x9c3b240` — две несимметричные реализации release:
   sel1 отпускает entry **после** unlock и не чистит `[uc+0x108][id]`; sel53
   чистит под локом, но кладёт entry в `[uc+0x140]` (`OSArray::setObject`).
3. `sel34 0x9c3b7b0` — берёт `IOSurface*` из обёртки (`[wrapper+0x18]`) и читает
   поля поверхности до `retain` в `0x9c2b810`; защищён только per-client локом,
   который не защищает саму поверхность.

## 1. Подтверждённая модель объектов

| Что | Адрес / слот | Комментарий |
|---|---|---|
| IOSurface instance vtable | `0x8067138` | ставится в ctor `0x9c1a2b0` (`0x9c1a2c4`), dtor `0x9c1a53c` |
| IOSurface `retain` | vtable `+0x20` → `0x9c1f3f0` | атомарный `+1` по `[IOSurface+0xc]` (`ldadd` в `0x9c46fb8`), overflow-check |
| IOSurface `release` | vtable `+0x28` → `0x9c1f484` | атомарный `-1` по `+0xc`; при 0 — `vtable+0x78` (`0x9c1f610`) → free `0x9c1f830` |
| IOSurface free | `0x9c1f830` | проверяет `[+0x3b0]` (client retain count), паника-строка `0x789badd` |
| IOSurface release-before-free | `0x9c1f1b4` | `0x9c1f2d4` (root notify-list) → `root->release_surface 0x9c35dcc` → `[+0x10]=0` → `vtable+0x70` |
| `lookupSurface(uc,id)` | `0x9c3f1d0` | `lck_mtx_lock([uc+0xd8])`; raw `0x9c3f044`; проверка `entry[+0x10]==uc[0x118]`; `retain(entry[+0x40])`; unlock; **возвращает +1** |
| raw lookup | `0x9c3f044` | `[uc+0x108]` — массив `IOSurfaceClient*`, `[uc+0x110]` — count, PAC `0xf69b` |
| `IOSurfaceClient` (entry) | ctor `0x9c2b8c8` | `[+0x10]`=owner (`IOSurfaceClient` объекта-владельца из `uc[0x118]`), `[+0x38]`=surface id, `[+0x40]`=IOSurface*, `retain(+0x20)` в `0x9c2b958` |
| `set_surface_handle` | `0x9c3f2b0` | пишет entry в `[uc+0x108][id]`, `retain(+0x20)` в `0x9c3f3d0`; занятый слот → panic `0x9c492f0` |
| `IOSurfaceRoot::set_surface_handle` | `0x9c33dc4` | root lock `[root+0x140]`; таблица `[root+0xd0]`, count `[root+0xd8]`, bitmap `[root+0xe8]` |
| `IOSurfaceRoot::lookup` | `0x9c33a4c` → `0x9c33548` | root lock; проверки id/owner; `tryRetain` `0x9c1f34c` (CAS `+1` если `[+0xc]!=0`) |
| `IOSurfaceRoot::release_surface` | `0x9c35dcc` | root lock; сверка `table[id]==surface`, иначе log `0x789c83f` и выход **без очистки**; чистит слот+бит |
| user-client table | `[uc+0x108]/[uc+0x110]`, lock `[uc+0xd8]` | lock/unlock = `0x9c495b4/0x9c495d4` |
| «Client Surfaces» | `[uc+0x140]` | `OSArray`, создаётся в `0x9c3a2d4` (`0x9c49a54(cap=1)`); `+0xe8`=`setObject`, `+0x118(i)`=`getObject`, `+0x108(i)`=`removeObjectAtIndex`, `+0x90`=`getCount` |
| user-client free | `0x9c3a678` | без лока: release всех entry из `[0x108]`, `IOFree([0x108])`, release `[0x140]`, `IOFree([0xd8])`, `IOFree([0xe0])` |

Замечание к вводной: слоты retain/release в этом билде — **`+0x20` / `+0x28`**, а не
`+0x28` / `+0x30` (проверено по vtable `0x8067138` и по парным вызовам
`0x9c16670`: retain new `+0x20`, release old `+0x28`). `+0x30` — другой виртуальный
метод (`0xa897ba0`), в teardown не участвует.

## 2. Таблица аудита

«lookup» — `0x9c3f1d0` (+1). «R» — release через vtable `+0x28`. «лок» — что
удерживается на время работы с entry/поверхностью.

| функция (sel) | retain/release | лок | вердикт |
|---|---|---|---|
| `create_surface 0x9c3ab8c` (0) | lookup `+1` (`0x9c3ac4c`), R на всех выходах (`0x9c3afdc`, `0x9c3b020`) | `[uc+0xd8]` на `set_surface_handle`/копирование | OK |
| `create_fast 0x9c3bb20` (6) | lookup `+1`, R в эпилоге `0x9c3bf24` | `[uc+0xd8]` | OK |
| `create_client_mem 0x9c3bf44` (7) | lookup `+1`, R `0x9c3c340/0x9c3c348` | `[uc+0xd8]` | OK |
| `sel1 0x9c3b0bc` | entry из `[0x140]`; `0x9c16670` (+1), `removeObjectAtIndex`, R `0x9c3b1f4` **после unlock** | `[uc+0xd8]` только на scan/remove | **подозрение #2** |
| `sel2 0x9c3b3ac` | `0x9c3f130` (+1 entry), surface `+0x20`; R surface `0x9c3b510`, R entry `0x9c3b530` | внутри `0x9c3f130` | OK |
| `sel3 0x9c3b58c` | lookup `+1`, R `0x9c3b618` | — | OK |
| `sel4 0x9c3b628` | root lookup `0x9c33a4c` (tryRetain `+1`), entry `0x9c2b810`; R surface `0x9c3b724`, R entry `0x9c3b748` | `[uc+0xd8]` | OK |
| `sel5 0x9c3bab4`, `sel8 0x9c3c354`, `sel9 0x9c3c3b8`, `0x9c3c538`, `0x9c3c8d4` (55), `0x9c3c9c0`, `0x9c3caa8` (12) | lookup `+1`; R по одной на каждой ветке (см. `0x9c3bb18`, `0x9c3c3b0`, `0x9c3c7e0…`, `0x9c3c9b0`, `0x9c3ca98`, `0x9c3cb24`) | — | OK |
| `sel14 0x9c3cb74`, `sel15 0x9c3cc88`, `0x9c3cd9c` | entry через `0x9c3f130` (+1), surface `+0x20`; R surface+entry (`0x9c3cc7c`, `0x9c3cd90`, `0x9c3cf30…`) | — | OK |
| `sel25 0x9c3d760`, `sel27 0x9c3d7c8`, `sel28 0x9c3d838`, `sel29 0x9c3d908` | lookup `+1`, R после работы (`0x9c3d7a8`, `0x9c3d81c`, `0x9c3d8c4`, `0x9c3d958`) | — | OK |
| `sel16 0x9c3d2d0`, `sel20 0x9c3d38c`, `sel21 0x9c3d408`, `sel22 0x9c3d48c`, `sel23 0x9c3d4f8`, `sel31 0x9c3d978`, `sel33 0x9c3da58`, `sel35 0x9c3b9f8`, `sel36 0x9c3dad4` | lookup `+1`, R ровно один (`0x9c3d334`, `0x9c3d404`, `0x9c3d488`, `0x9c3d4f4`, `0x9c3d55c`, `0x9c3d9f0`, `0x9c3dad0`, `0x9c3baa8`, `0x9c3db18`) | — | OK |
| `sel34 0x9c3b7b0` | IOCast обёртки → `[+0x18]` surface; entry `0x9c2b810` (retain `+0x20`); R только entry `0x9c3b9e4`; surface явно не retain'ится | `[uc+0xd8]` | **подозрение #3** |
| `sel42 0x9c3e22c` | lookup `+1`; R surface `0x9c3e2f8`, R wrapper `0x9c3e320`, R entry/port по веткам | — | OK |
| `sel53 0x9c3b240` | entry из `0x9c3f044`; `[0x140].setObject(entry)` (+1), R entry `0x9c3b2dc`, очистка `[0x108][id]` `0x9c3b350` | `[uc+0xd8]` | OK, but ordering |
| `sel55 0x9c3c8d4`, `sel56 0x9c3d268`, `sel57 0x9c407ec`, `sel59 0x9c409ec` | lookup `+1`, R на всех путях (`0x9c3c9b0`, `0x9c3d2cc`, `0x9c4095c`, `0x9c40a48`) | — | OK |
| root lookup `0x9c33a4c`, set `0x9c33dc4`, release `0x9c35dcc` | tryRetain/`table`/clear; R не требуется | `[root+0x140]` | OK, сверки id/owner на месте |
| `uc free 0x9c3a678` | R всех entry `0x9c3a758`, R массива `0x9c3a7fc` | **лок не берётся** | **подозрение #1** |

Все 33 сайта `bl 0x9c3f1d0` проверены на CFG: пути `ret` без release не найдено;
двойного release одного регистра в одной функции не найдено (скрипт `audit.py`,
`cfg.py` в `work/uaf_surf/`).

## 3. Топ-3 подозрительных

### 3.1 `IOSurfaceRootUserClient::free 0x9c3a678` — teardown без лока

```
9c3a69c  ldr  w8,[x0,#0x110]        ; count
9c3a6a0  ldr  x1,[x0,#0x108]        ; table
...
9c3a71c  ldr  x16,[x17]             ; entry = table[i]
9c3a748  ... blraa [entry+0x28]     ; release(entry)     <-- БЕЗ лока
9c3a7d8  bl   0x9c49584             ; IOFree(table)
9c3a7e4  ldr  x0,[x19,#0x140]
9c3a7fc  blraa [x0+0x28]            ; release(OSArray "Client Surfaces")
9c3a810  str  xzr,[x19,#0x48]
9c3a848  bl   0x9c495a4             ; IOFree(lock [uc+0xd8])  <-- БЕЗ лока
9c3a858  bl   0x9c49654             ; IOFree([uc+0xe0])
9c3a89c  braa  super::free
```

Нет ни `lck_mtx_lock([uc+0xd8])`, ни проверки `isInactive`/`[uc+0x127]`.
Последовательность для гонки (если время жизни uc позволяет):

1. Поток A: `io_connect_method(uc, sel=15/27/…, id…)` → `externalMethod 0x9c3ee10`
   → impl → `lookupSurface 0x9c3f1d0`, внутри держит `[uc+0xd8]`
   (`0x9c3f204 lock … 0x9c3f27c unlock`).
2. Поток B: `IOServiceClose(uc_port)` → terminate → `free 0x9c3a678`:
   `0x9c3a7d8` освобождает таблицу, `0x9c3a848` — сам мьютекс.
3. A продолжает `0x9c3f220` (entry уже из освобождённой таблицы) или
   `0x9c3f27c unlock` по освобождённому мьютексу → UAF.

Почему, скорее всего, **не срабатывает**: mach-trap держит ссылку на порт
(`ipc_object_reference`) на время вызова, а `ip_kobject` (uc) не даёт
`free()` выполниться, пока вызов в полёте. Статически это не доказано —
**не подтверждено**. Проверять динамически (2 потока + close) или сверить
`iokit_user_client_trap`/`ipc_kobject` refcount.

### 3.2 Две реализации release: `sel1 0x9c3b0bc` и `sel53 0x9c3b240`

`sel53` (под локом):
```
lookup 0x9c3f044 -> entry
[uc+0x140].setObject(entry)     ; +1 (OSArray)
release(entry)                  ; -1 (ссылка таблицы)
str xzr,[uc+0x108][id]          ; очистка слота, всё ещё под локом
unlock
```
`sel1` (вне лока на release):
```
lock
scan [uc+0x140]: getObject(i) -> entry, entry->0x38 == id
0x9c16670(&tmp, entry)          ; retain (+1)
removeObjectAtIndex(i)          ; -1 (ссылка массива)
dec [uc+0x128]/[uc+0x12c]
unlock
release(entry)                  ; -1 (tmp)
```
`sel1` **не чистит `[uc+0x108][id]`**. Если entry одновременно лежит и в таблице,
и в массиве, ссылки сбалансированы (таблица +1, массив +1) — двойного free нет.
Если бы `set_surface_handle` не делал retain (`0x9c3f3d0`) или `OSArray::setObject`
не удерживал объект, `sel1`+`free()` дали бы двойной release entry → release
поверхности дважды. По дизассему retain'ы есть, поэтому вердикт: **не
подтверждено**, асимметрия реальна (release вне лока + отсутствие очистки id-слота).

Последовательность-кандидат: T1 `sel1(id)` — снял entry с массива, unlock;
T2 `sel53(id)` — под локом нашёл entry в таблице, `setObject`, release,
`[0x108][id]=0`, unlock; T1 делает release(entry) — если T2 уже уронил счётчик
в 0 (возможно только при отсутствии retain'а таблицы), это double free.
С retain'ом таблицы счётчик не доходит до 0 — **не подтверждено**.

### 3.3 `sel34 0x9c3b7b0` — поверхность из обёртки без retain

```
9c3b7f0  ldr  x16,[uc+0xf8]        ; task
9c3b834  bl   0x9c49824            ; task -> wrapper (send right?), out в [sp+8]
9c3b850  ldr  x0,[sp+8]
9c3b85c  bl   0x9c498d4            ; OSDynamicCast(x0, meta 0xaf484d0)
9c3b868  ldr  x23,[x0+0x18]        ; x23 = IOSurface*
9c3b86c  ldr  x0,[uc+0xd8]; lock   ; защищает только таблицу клиента
9c3b874  bl   0x9c3f044            ; lookup в [uc+0x108] по [x23+0x10]
9c3b8b4  ... [x23+0x3d2] bit3, [x23+0x170] == task
9c3b928  ldr  x0,[uc+0x118]
9c3b934  bl   0x9c2b810            ; создаёт entry -> retain surface (+0x20)
```
Между `0x9c3b868` и `0x9c3b934` поверхность `x23` не удерживается; per-client
лок `[uc+0xd8]` не мешает другому потоку освободить поверхность через
`sel53`/`IOSurface::release`. Спасает только то, что обёртка `[sp+8]`
(send right) сама держит `IOSurface` — если `[wrapper+0x18]` это слабая ссылка,
окно реально. `[sp+8]` отпускается в эпилоге `0x9c3b980`. **Не подтверждено**;
нужно проверить ctor обёртки (`IOSurfaceSendRight`, строка `0x789d9b9`).

## 4. Что проверено и отвергнуто

- **Handle reuse.** `IOSurface::release-before-free 0x9c1f1b4` освобождает
  root-слот `id` до последнего release объекта; новый `create_surface` может
  получить тот же id. `root->release_surface 0x9c35dcc` сверяет
  `table[id]==surface` (`0x9c35e7c`, log `0x789c83f`) и при несовпадении
  **не очищает** слот; `set_surface_handle 0x9c33dc4` при занятом слоте
  логирует bogus-handle (`0x789c7b7`). Двойного освобождения слота нет.
- **`set_surface_handle`** (`0x9c3f2b0`) при занятом слоте уходит в panic
  (`0x9c3f418` → `0x9c492f0`), а не перезаписывает entry — double-insert
  невозможен.
- **sel28 `0x9c3d838` и sel34 `0x9c3b7b0` (structureOutput).** sel28 держит
  `lookup`+`1` на всё время `0x9c26438` (копирование 0x84/0xa0) и отпускает
  после; sel34 lookup не использует (работает с entry из `0x9c3f044` под локом).
  Окна «скопировали после release» нет.
- **error-ветки create**: парсинг свойств, `OSDynamicCast`, `0x9c33c34`,
  `0x9c2b810`, `0x9c3f2b0` — все выходы сходятся в `0x9c3b068/0x9c3b078` и
  отпускают `x20/x21/x22/x25/x26` ровно по одному разу.
- **27.0 vs 27.2**: `free 0x9c3a678`, `lookupSurface 0x9c3f1d0`, `sel1`,
  `sel53`, `create_surface`, `rootRel 0x9c35dcc` — поток инструкций идентичен
  (сдвиг `0x3bfa8`), т.е. это не регрессия 27.2 и не свежий фикс.

## 5. Как доказать/опровергнуть

1. Динамика на устройстве: два потока — один в `IOConnectCallMethod(sel 15/27)`,
   второй закрывает connection; смотреть panic `data_abort` на `[uc+0xd8]`.
   Либо `sel1`/`sel53` в два потока с одним id.
2. Проверить, удерживает ли `IOSurfaceSendRight` поверхность в `[+0x18]`
   (ctor по строке `0x789d9b9`): если да — подозрение #3 снимается.
3. Проверить `OSArray::setObject` retain (слот `+0xe8`): если retain есть —
   подозрение #2 остаётся только логической асимметрией.

Артефакты: `kc.py` (mapping/disasm), `an.py`, `cfg.py`, `audit.py`,
`uaf2.py`, дамп `0x9c10000–0x9c50000` в `/tmp/opencode/uaf_surf.txt`.
