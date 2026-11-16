# 27.2 / 24B115 — sandbox escape: MCM token scope and the race lead

Дата: 2026-11-09. Устройство: iPhone14,7 (D27AP), iOS 27.2, build 24B115.

## 0. Вердикт

KAMUI-примитив (class 7 part-directory symlink) на 27.2 **работает только до
MCM-контейнеров**: `container_copy_sandbox_token` выдаёт токен, когда symlink
резолвится в **валидный контейнер** (SystemGroup/AppGroup/App data). На цели
вне MCM — `/`, `/private/var`, `/var/mobile/Library/Preferences`,
`/var/mobile/Containers/Data`, `/System/Library` — токена нет:

```
query target=/ ... path=<group>/Library/Caches token=NO consume=-5
post opendir=/var/mobile/Library/Preferences -> EPERM
```

То есть это **частичный** escape (все MCM-контейнеры, включая SystemGroup и
MobileGestalt/PosterBoard), а не полный `/`/root. Полный escape требует
TOCTOU/symlink race в MCM или другого бага в демоне.

## 1. Что подтверждено на устройстве

`ctlab/sbprobe` (profile-signed, app group entitlement, без приватных
entitlements) выполняет class 7 и class 12 запросы:

| target | class 7 token | class 12 token | post opendir |
|---|---|---|---|
| `/` | NO | NO | ok (sandbox и так даёт `/`) |
| `/private/var` | NO | NO | EPERM |
| `/var/mobile/Library/Preferences` | NO | NO | EPERM |
| `/var/mobile/Containers/Data` | NO | NO | EPERM |
| `/System/Library` | NO | NO | ok (read-only) |

Для сравнения, лог KAMUI 2.4.3 на той же сборке:

```
strategy class7-symlink/group.8e0bc870a21520b9.1:
  cls=7 ident=group... part=3 result=0x... path=(null) token=YES consume=2
probe[class7]: target=/private/var/containers/Shared/SystemGroup/
  systemgroup.com.apple.mobilegestaltcache/Library/Caches
probe[class7]: token=YES consume=3
probe[class7]: marker=OK
```

Разница — **target**: SystemGroup-контейнер даёт токен, `/` — нет. MCM
резолвит part-directory symlink и валидирует конечный путь; вне MCM-контейнера
токен не выдаётся.

## 2. Следующий тест: symlink race

Гипотеза: `realPathForURL:ifChildOfURL:` (проверка) и
`container_copy_sandbox_token` (выдача) резолвят part-directory symlink в
разные моменты. Если между ними подменить symlink с валидного контейнера на
`/`, токен может быть выдан для `/`.

Собран `ctlab/sbracer`:
- два потока атомарно (`symlink` + `rename`) меняют
  `<app group>/Library/Caches` между
  `…/systemgroup.com.apple.mobilegestaltcache/Library/Caches` и `/`;
- третий поток в цикле делает class 7 / part 3 запрос, `consume` токена и
  проверяет `opendir("/var/mobile/Library/Preferences")` + запись маркера;
- `WIN` в логе = токен на `/` = полный sandbox escape для mobile-owned путей.

Проба собрана в `artifacts/sbracer.ipa`, исходник `ctlab/sbracer/main.m`.
Запуск не доведён до конца: соседняя сессия на этом же хосте убивает
`usbmuxd`/`pymobiledevice3` процессы и ставит/удаляет тот же единственный
bundle id (`app.lake9674.aquila8809`), поэтому install/launch рвётся
(`Client requested uninstall`). Нужен чистый USB-доступ и свободный app id.

## 3. Что это значит

- Частичный escape (MCM containers) — реален и воспроизводится.
- Полный `/` escape через class 7/12 symlink **напрямую** закрыт проверкой
  target; остаётся race или другой баг MCM.
- AMFI user client из sandbox не открывается (`0xe00002e2`), trust-cache путь
  закрыт.
- Для race-теста нужен стабильный девайс: без него нельзя отличить «токен не
  выдан» от «процесс убит соседней сессией».

## 4. Артефакты

- `ctlab/sbprobe/main.m`, `artifacts/sbprobe.ipa` — class 7/12 target sweep.
- `ctlab/sbracer/main.m`, `artifacts/sbracer.ipa` — symlink race.
- `artifacts/kamui243_selftest.log` — эталон class 7 token YES на SystemGroup.

## 5. Финальная проверка (2026-11-09, вечер)

Устройство снова на связи: iPhone14,7 / 27.2 / 24B115. systemd-usbmuxd
залипал; рабочий путь — приватный `usbmuxd` в user namespace
(`/proc/<pid>/root/run/usbmuxd`), после `USBDEVFS_DISCONNECT`/свежего демона.
Все пробы ниже выполнены на живой 27.2.

### 5.1 MobileHouseArrest

PoC `0xjohnnydev/MobileHouseArrest-PoC` (iOS 27 beta 4) проверен:

| Вариант подписи | Установка | Результат |
|---|---|---|
| bundle id `com.apple.mobile.MobileHouseArrest`, app-id профиля `8F9U9JSYJ9.app.lake9674.aquila8809` | OK | class 2 Safari/Notes — `res` есть, `token=NO`; class 7 Notes — `token=NO`; class 13 `0x8100000000` — `token=NO` |
| bundle id `app.lake9674…`, CD identifier `com.apple.mobile.MobileHouseArrest` | отказ `MismatchedBundleIDSigningIdentifier` | — |
| bundle id `com.apple.mobile.MobileHouseArrest`, app-id `8F9U9JSYJ9.com.apple.mobile.MobileHouseArrest` | отказ `ApplicationVerificationFailed 0xe8008015` | — |

Вывод: MCM проверяет **application-identifier из audit token**, а не только
CD identifier. Профиль ipa_dark фиксирует app-id, поэтому identity
`MobileHouseArrest` без профиля этого app-id недоступна. Wildcard/dev-профиля
на устройстве нет (проверены все установленные провижены: у команды
`8F9U9JSYJ9` только explicit app-id).

### 5.2 Legacy API (`container_*`)

`ctlab/sblegacy` и `ctlab/sboldclass` вызывают старые символы
`container_create_or_lookup_path`, `container_create_or_lookup`,
`container_copy_from_path`, `container_acquire_sandbox_extension`,
`container_system_path_for_identifier`, `container_system_group_path_for_identifier`.

- `create_or_lookup_path` / `copy_from_path` для `/`, `/private/var`, корней
  AppGroup/SystemGroup/geod, `/var/mobile/Library/Preferences` — `obj=0`
  (и `create=false`, и `create=true`).
- `container_create_or_lookup` для классов 0,1,2,7,12,13 и идентификаторов
  bundle/group/geod/systemgroup — `obj=0`.
- `container_system_path_for_identifier("com.apple.geod")` возвращает
  `/private/var/containers/Data/System/com.apple.geod`, но объект по этому
  пути не создаётся; traversal-идентификатор возвращает NULL/errno 55.
- `container_acquire_sandbox_extension` на живом объекте не вызывается.

Старый API на 27.2 фактически cut: путь отдаётся, объект/токен — нет.

### 5.3 Class sweep 0..24

`ctlab/sbclass1` (in-process, один класс на запуск) — target `/`, part 3,
flags `0x8000000000`, идентификаторы: bundle, group, `com.apple.geod`,
`systemgroup.com.apple.mobilegestaltcache`, `com.apple.Preferences`,
`com.apple.mobilesafari`; для класса 13 дополнительно `0x8100000000`.

- Все классы 0..24: `tok=NO` на `/`.
- Контроль class 7 / group id на валидном SystemGroup Caches: `token=YES`,
  consume=2, запись маркера OK. Значит sweep валиден, а `/` закрыт.
- Class 13 `0x8100000000` — `token=NO` (на 27.2 PoC beta-4 уже не работает).

### 5.4 CFPreferences

`ctlab/sbprefs`: абсолютный domain
`/var/mobile/Containers/Shared/AppGroup/<UUID>/Documents/...` пишет реальный
plist (`sync=1`, файл есть). Абсолютные domain
`/var/mobile/Library/Preferences/...` и `/private/var/db/...` — `sync=0`,
cross-read `com.apple.Preferences` — null. То есть cfprefsd не выходит за
пределы песочницы приложения; это не escape.

### 5.5 Backup2 / restore

Крафт минимального backup с `relativePath =
../../../../../../private/var/tmp/com.apple.CoreDevice/sbbackup_trav`
и `MBFile`-архивом. Restore отклонён устройством:

```
Find My iPhone must be disabled before restoring (MBErrorDomain/211)
```

До записи файла дело не дошло. Path traversal в backup2 на 27.2 не
проверяем без отключения Find My (Apple ID).

### 5.6 Developer services

- `debugserver vAttach` → `E96` для своего же приложения: профиль
  `get-task-allow=false`, attach запрещён.
- `DYLD_INSERT_LIBRARIES` в системное `Preferences` → маркер не создан;
  library validation/переменная не срабатывает.
- `dvt` `launchSuspendedProcessWithDevicePath` с `/bin/sh` и валидным
  bundle id запускает **установленное приложение по bundle id**, `device_path`
  игнорируется.
- CoreDevice file service: `temporary` = `/var/tmp/com.apple.CoreDevice`;
  symlink/traversal/запись вне домена блокируются.

### 5.7 Проект newjail (из `Загрузки`)

`ios_jailbreak 3.zip` / `build/newjail.ipa` — заготовка jailbreak:

- `stage2.c`: `nj_stage2_build_krw_from_64788` — заглушка
  (`*tfp0_out = 0xdeadbeef`, `kslide=0`), `build_krw_from_leaks` — `-1`.
- `stage3.c`: `sandbox_extension_issue_file` из песочницы (EPERM, проверено
  отдельно `ctlab/sbtok`), затем symlink; полного доступа не даёт.
- `stage4.c`: пишет `/var/jb` только если `/var` доступен на запись.
- `IOGPUChain27/latest.log` (тот же 27.2, xnu-13432.42.3~28): AGX user client
  и IOSurface queue найдены, но `KASLR slide: NO`, `paddr surface: NO`,
  `SPTM bypass: NOT ATTEMPTED — нужен kernel context/kext`.
- `F1Probe` — только shape/primitive, без KRW.

То есть проект не содержит рабочего kernel R/W и не является full escape.
Он подтверждает, что AGX/IOGPU и IOSurface — единственный оставшийся
интересный вход, но его ещё нужно превратить в tfp0.

### 5.8 Вердикт

**Полного sandbox escape на 27.2 не найдено.** Подтверждён только частичный
escape в MCM-контейнеры (class 7). Закрыты: CoreTrust, class 7/12/13 на `/`,
legacy container API, MobileHouseArrest (профиль), cfprefs за пределы
контейнера, backup2 (Find My), debugserver/DYLD_INSERT (get-task-allow),
CoreDevice file domains.

Оставшийся путь — настоящий kernel R/W (IOGPUFamily UAF 64788 / AGX) либо
новый баг парсера в CoreTrust/MCM. Артефакты и исходники всех проверок
сохранены в `ctlab/`; IPA/дампы — в `ctlab/artifacts/`.
