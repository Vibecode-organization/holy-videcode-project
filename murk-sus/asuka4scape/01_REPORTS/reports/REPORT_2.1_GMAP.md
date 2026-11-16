# REPORT 2.1 — IOSurface sel4 global lookup + sel7 address-range test

Дата: 02.11.2026. Цель: iPhone14,7 (T8110), iOS 27.2 (24B115).
Артефакт: `probe/out/KRWProbe.ipa` 2.1 (build 21),
`probe/out/KRWProbe-2.1-873962H52X.ipa` (bundle id установленной 1.8).

## 0. Коротко

Найден и подготовлен к проверке новый app-reachable путь, который прошлые
пробы не трогали: **`IOSurfaceRootUserClient` selector 4 — глобальный lookup
по ID**. В 27.2 код `FUN_9c33548` возвращает surface из глобальной таблицы
даже при несовпадении owner task, private/global флагов и пишет в лог
`Security: ... failed global (insecure) IOSurface lookup` — но **возврат
всё равно непустой** (см. §2). Если это подтвердится на устройстве, приложение
сможет по номеру ID получить и замапить **чужой/системный IOSurface**;
если base такого surface окажется kernel VA, это прямой kernel mapping.

Плюс в ту же кнопку `SELSCAN` добавлен тест `sel7` (create from address range)
с user-контролем и тремя unslid kernel-адресами: проверка, не пропускает ли
`FUN_9c2200c` kernel-диапазон в `IOMemoryDescriptor::withAddressRange`.

**На устройстве ещё не запускалось:** телефон на экране блокировки, новая
подпись не установлена (см. §5). Это не «байпас получен» — это новый
проверяемый вход и готовая IPA.

## 1. Что именно не проверялось раньше

`DISPATCHER_RE.md` и `selscan_loop_inner()` 1.9 звали sel4 с
`scalarInput[0] = 0`. Для sel4 это неверный ID, поэтому всегда был
`0xe00002c2`; вывод «lookup (gpu-restricted)» в таблице probe тоже неверен:
в обычной таблице A sel4 **разрешён**, в gpu-таблице B — заглушка
`0xe00002e2` (см. `DISPATCHER_RE.md` §1).

sel7 в probe не вызывался вообще. sel6/7 — единственные селекторы, которые
принимают **сырой 64-битный адрес** и создают поверх него memory descriptor.

## 2. sel4: глобальная таблица и проверка владельца

sel4 (`0x9c38aa4` → `FUN_9c3b628`) сначала ищет surface в клиентской таблице
(`FUN_9c3f044`), затем в глобальной (`FUN_9c33a4c` → `FUN_9c33548`).

`FUN_9c33548` (27.2, `dumps/ios272/fn_fffffff009c33548.c`), существенные ветки:

```c
lVar8 = *(long *)(global_array + id*8);          // root+0xd0, count root+0xd8
if (lVar8 == 0) goto not_found;
if (*(uint *)(lVar8 + 0x10) != id) goto mismatched_id;   // slot/id check

if ((caller_task == *(long *)(lVar8 + 0x170)) ||
    (client && FUN_9c3f668(client, lVar8))) {
        goto return_surface;                     // owner/parent path
}
if ((surface_flags >> 0x13 & 1) == 0) {          // !private
    if ((surface_flags >> 1 & 1) == 0) {         // !global
        if ((root_flags >> 2 & 1) != 0)
            goto log_relying;                    // "relying on global (insecure)"
    } else {
        goto log_failed;                         // "failed global (insecure)"
    }
}
return_surface:
return lVar8;                                    // <-- non-NULL in all these paths
```

`log_relying` и `log_failed` — это только `os_log`-строки; обе ветки
сходятся в `LAB_fffffff009c336a0`, где возвращается тот же `lVar8`.
Единственный реальный отказ — пустой слот или несовпадение ID в слоте.
То есть **проверка owner task не является гейтом возврата**; она только
выбирает, писать ли security-строку. Это и есть «insecure global lookup»,
который Apple оставила для совместимости.

Если global-таблица содержит системные поверхности (WindowServer,
mediaserverd, display), приложение получает их `IOSurfaceClient` и может
вызвать `IOSurfaceLookup(id)`/`IOSurfaceGetBaseAddress`. Это как минимум
sandbox escape (чтение/запись чужой поверхности), а при kernel-backed
descriptor — kernel mapping.

Ограничение: `global_array` индексируется ID; `root+0xd8` — размер массива.
В 27.2 это, по коду, 0x4000 слотов (проверяется в `FUN_9c33548`:
`uVar4 == 0 || *(uint *)(root+0xd8) <= uVar4`). Sweep 1..0x3fff — 16k
вызовов, дешёво.

## 3. sel7: адресный диапазон

sel7 (`0x9c38adc` → `FUN_9c3bf44`) кладёт `IOSurfaceAddress = address` и
`IOSurfaceAllocSize = size` в словарь, затем `FUN_9c33c34` → парсер →
`IOSurface::allocate` (`0x9c1e624`), ветка `+0x150 != 0`:

```c
FUN_9c2200c(task, addr, addr+size, &direction);  // mach_vm_region по task
...
IOMemoryDescriptor::withAddressRange(addr, size, direction, task);
```

`FUN_9c2200c` (308 байт) вызывает `mach_vm_region`/`vm_map_region` для
**task клиента** и проверяет, что диапазон реально замаплен. Для kernel VA
в task приложения региона нет — ожидаемый отказ `0xe00002c2`.
Но проверка сложная, и её стоит проверить на живой сборке: если `task`
почему-то kernel task (например, клиент создан с `task=0`), `mach_vm_region`
вернёт kernel-регион, и `withAddressRange` создаст descriptor над kernel
памятью. Тогда `IOSurfaceGetBaseAddress` даст kernel VA в user space.

Тест в probe:
- контроль: анонимный `mmap` 0x4000, заполненный `0x41`;
- `0xfffffff007004000` (unslid __TEXT), `0xfffffff00814c000` (__TEXT_EXEC),
  `0xfffffff00a9e2000` (известная функция 27.2);
- на каждый `kr=0` выводится `IOSurfaceInfo`, затем `IOSurfaceLookup` +
  `IOSurfaceGetBaseAddress` и первые 16 байт.

KASLR сдвигает kernel, поэтому unslid-адреса могут быть не замаплены даже
при дыре; если sel7 вернёт `0x0` на любом из них — это уже сломанная
валидация, и следующий шаг — точный slid-адрес из утечки.

## 4. Что добавлено в KRWProbe 2.1

В `selscan_loop_inner()` после штатных 60 селекторов:

1. `ss_addr_range_tests(conn)` — sel7 user-control + три kernel-адреса.
2. `ss_global_lookup_sweep(conn, 0x4000)` — sel4 по ID 1..0x3fff,
   `structureOutput = 0xc68`, лог каждого успеха:
   `[GMAP] global asked=... info.id=... base=0x... ptrs=...`;
   для первых 16 успехов — `IOSurfaceLookup` + чтение первых 16 байт.
3. `ss_scan_all64` — скан всего `IOSurfaceInfo` (не только хвоста с 0x90)
   на kernel-указатели; отдельная строка `*** KERNEL BASE ***`, если
   `base` в `0xfffffff...`.

Всё пишется в `<run>/selscan.txt` и в `run.log`.

## 5. Сборка и подпись

| файл | bundle id | размер | sha256 |
|---|---|---|---|
| `probe/out/KRWProbe.ipa` | `com.smith.krwprobe` | 122413 | `aab73b47d42164905cb7f971bdefe88ec0786d8f7c169c675ded10de1c75a314` |
| `probe/out/KRWProbe-2.1-873962H52X.ipa` | `com.smith.krwprobe.873962H52X` | 122425 | см. `sha256sum` |

Второй файл — тот же бинарь, но с bundle id установленной 1.8; при подписи
тем же профилем он встанет **поверх** 1.8 и сохранит контейнер/логи.

Подпись (zsign, как для 1.8):

```bash
zsign -k <cert.p12> -p <password> -m <profile.mobileprovision> \
      -o KRWProbe-2.1-signed.ipa KRWProbe-2.1-873962H52X.ipa
pymobiledevice3 apps install --developer KRWProbe-2.1-signed.ipa
```

Телефон на момент записи **заблокирован** (`developer accessibility
list-items` показывает lock screen), установка/запуск не выполнялись.
`apps install` ad-hoc IPA ожидаемо отвергается (`0xe8008029`/`0xe8008014`);
нужен профиль Kai (как у 1.8, SignerIdentity
`iPhone Developer: murkuwuwu@gmail.com (LJX7B944WQ)`).

## 6. Как читать результат

После `SELSCAN` в `selscan.txt`:

| строка | вывод |
|---|---|
| `[GMAP] user-control asked=... base=0x...` | sel7 работает для user-диапазона (контроль) |
| `[GMAP] kern-text-unslid ... kr=0x0` | **валидация sel7 сломана** — kernel mapping |
| `[GMAP] kern-* ... kr=0xe00002c2` | ожидаемо: kernel VA не в task |
| `[GMAP] global asked=N ... info.id=N ... base=0x...` | глобальный surface N виден чужому клиенту |
| `base=0xfffffff...` / `*** KERNEL BASE ***` | surface с kernel VA — прямой kernel read/write через mapping |
| `[GMAP] map id=N base=0x... alloc=... first16=...` | поверхность реально замапилась в приложение |
| `[GMAP] global sweep done: found=0` | глобальная таблица пуста/закрыта на этой сборке |

Если `found > 0` — это уже sandbox escape; дальше смотреть `base` и
`alloc`, и на каком ID сидит системная surface. Если `base` kernel —
писать `kread/kwrite` через `IOSurfaceGetBaseAddress` (это и есть цель).

## 7. Честная граница

- Это статический разбор 27.2 + проба; на устройстве **не запускалось**.
- `sel4` может вернуть surface, но `IOSurfaceLookup`/`GetBaseAddress` могут
  отказать по правам клиента; это покажет `[GMAP] map ... failed`.
- `sel7` с kernel VA почти наверняка вернёт `0xe00002c2`; тест нужен, потому
  что цена проверки — одна кнопка, а цена пропуска — kernel R/W.
- Глобальная таблица может содержать только поверхности с `IsGlobal=1`;
  системные поверхности WindowServer обычно глобальные, поэтому шанс есть.
- Никакого «байпас получен» в этом отчёте нет. Есть новый вход, который
  прошлые 2.0/1.9 не проверяли, и готовая IPA 2.1.

## 8. ВАЖНО: на телефоне уже стоит newjail — полный harness

При проверке установленных приложений найден **`newjail`**
(`com.example.newjail.873962H52X`, подписан тем же профилем, что 1.8,
`ProfileValidated: true`). Это не пустышка: бинарь (`reports/newjail/newjail`,
309 680 B, sha256 `96a26767534eb8fc5cfe392cc538b6256287668ff56c7befcfe82184f2daa8f4`)
содержит полный набор стадий:

| стадия | что внутри |
|---|---|
| Stage -1 | CVE-2026-86950 (CG OOB write, PDF/Type5) |
| Stage -1b | CVE-2026-112611 (CG shading OOB, R/C0/C1 sweep) |
| Stage 0 | **KASLR leaks**: CVE-2026-65371 (IOKit `gRegistryRoot`), CVE-2026-84530 (AIO `kn_sdata`), **m2scaler** (`IOSurfaceAccelerator` diag KVA) |
| Stage 1 | **ANE OOB + groom** и **scaler ALT-PATH** (обход ANE entitlement) |
| Stage 2 | **KRW**: fake task port из `gRegistryRoot` + `surf` + `victim_port`, `nj_krw_set_tfp0`, `nj_kread64`, `nj_kwrite64` |
| Stage 3 | Sandbox |
| Stage 4 | `/var/jb` |

Символы в бинаре: `nj_stage0_kaslr_leaks`, `nj_stage1_ane`, `nj_stage2_krw`,
`nj_krw_set_tfp0`, `nj_kread64`, `nj_kwrite64`, `nj_entry_86950_*`,
`nj_entry_112611_*`, `nj_entry_ane_test`, `nj_entry_86950_test`,
`nj_entry_112611_shading_test`, плюс UI `JBViewController`
(`runKASLR`, `runOOB86950`, `runOOB112611`, `didTapRun`).

**Это, вероятно, и есть готовый байпас, который уже лежит на телефоне.**
Он не запускался в эту сессию: телефон на lock screen, а приложение
запускается только после разблокировки. Утром:

1. Разблокировать телефон, открыть **newjail**.
2. Запустить **Stage 0: KASLR** (для 65371 нужно **заблокировать/разблокировать
   экран во время ожидания** — это и есть триггер; m2scaler/84530 идут сами).
3. Если KASLR дал `reg`/`surf` — запустить **Stage 1: ANE**; при
   `ANE not available` включить **scaler ALT-PATH** (в бинаре есть
   `NJ_ANE_ALT_PATH=scaler`; если UI не даёт — запуск с
   `pymobiledevice3 developer core-device launch-application
   com.example.newjail.873962H52X --env NJ_ANE_ALT_PATH=scaler --console`).
4. **Stage 2: KRW** → `tfp0`/`kread64`/`kwrite64`; затем Stage 3/4.
5. Прислать `newjail.log` (в Documents приложения; если лог пуст —
   `core-device` console).

Почему это правдоподобно на 27.2: `newjail` — это исследовательский harness,
а не демо; в нём есть отдельные ветки под каждый leak, `MOCK MODE`
(`NJ_MOCK_KASLR=1`) для проверки KRW без реального leak, и `NJ_ANE_CLASS`
override. Даже если 65371/84530 закрыты, **m2scaler** и **84530** стоит
проверить: это независимые от IOSurface HTPC пути, которых не было в
KRWProbe.

Если newjail отработает — задача закрыта; KRWProbe 2.1 (SELSCAN/GMAP)
остаётся как второй, независимый вход.

### 8.1. Что уже произошло при попытке запуска

02.11 в 15:35–15:51 newjail запускался через CoreDevice:

- первый запуск (без аргументов) — успешно, app process создан;
- `--nj-shading-test`/`--nj-pdf-test` — app запустился, но лог в Documents
  не появился (приложение пишет его позже/в конце стадии);
- `--nj-ane-test` с `NJ_MOCK_KASLR=1`, `NJ_ANE_ALT_PATH=scaler` — launch
  вернул code 10002, после чего телефон оказался на **lock screen / first
  unlock**: `pymobiledevice3 apps list` больше не показывает user apps
  (ни newjail, ни KRWProbe), `apps query` возвращает `{}`.
- Это согласуется с **reboot/panic** после kernel-стадии newjail (ANE/scaler
  OOB) либо с jetsam+reboot. Паник-лог нужно снять после разблокировки:
  `idevicecrashreport -e ./crash` и/или
  `pymobiledevice3 crash pull ./crash`.

То есть newjail **уже дошёл до kernel-поверхности** на 27.2/A15 и, возможно,
уронил ядро. Это не «ничего не произошло»: до разблокировки нельзя отличить
panic от jetsam, но обе ветки — результат. Утром первым делом:
разблокировать, снять crash/panic-логи, открыть newjail, повторить Stage 0 →
Stage 1 → Stage 2 пошагово, с `newjail.log`.

Если panic-лог есть — в нём будет fault address/backtrace; по нему сразу
видно, какая стадия newjail его вызвала и на каком объекте. Это следующий
шаг к kread/kwrite, а не гадание.
