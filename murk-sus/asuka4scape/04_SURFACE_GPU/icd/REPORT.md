# installcoordinationd / app replacement — 27.2 (24B115)

Цель: проверить, может ли обычное приложение (без приватных/developer-энтайтлментов)
дойти до app replacement, до чужих data-контейнеров и что именно проверяет
`installcoordinationd` по `com.apple.developer.superseded-application-identifiers`.

Артефакты:

- `installcoordinationd` — `System/Library/PrivateFrameworks/InstallCoordination.framework/Support/installcoordinationd`
  (root FS 27.2, `141-10327-211.dmg`), 1 283 440 Б, arm64e.
- `InstallCoordination` (клиент/резолвер) — из DSC 27.2, `/System/Library/PrivateFrameworks/InstallCoordination.framework/InstallCoordination`.
- `ContainerManagerCommon`, `MobileContainerManager` — из DSC 27.2.
- Sandbox-профили — `/home/femboychik/work/sb272/all.json` (293 профиля).
- Дизасм: `capstone` + локальные символы (`ipsw macho info -n`, `-f`, `-u`).

Обозначения: «подтверждено» = есть дизасм/декларация в бинаре; «не подтверждено» =
не доказано ни в одну сторону.

---

## 1. Таблица точек входа

| точка входа | гейт | вердикт |
|---|---|---|
| mach-lookup `com.apple.installcoordinationd` (+ `.CacheDelete`, `.PersonaLifecycle`, `com.apple.InstallProgress.xpc`) | sandbox `container`: имени нет ни в одном `allow mach-lookup`; в `baseline`/`common-mach-lookups` тоже нет. Имя есть ровно в 11 профилях — все демоны (`appstored`, `appconduitd`, `mobile_storage_mounter`, `passd`, `sharingd`, `streaming_zip_conduit`, `AirTraffic`, `mobileassetd`, `nsurlsessiond`, `homed`, `temporary-sandbox`), и там это явный `global-name` | обычное приложение не подключается. Подтверждено |
| mach-lookup `com.apple.containermanagerd` / `.system` | `baseline`: `(allow mach-lookup (require-all (profile-flag "common-containermanagerd-rules") (require-any (global-name "com.apple.containermanagerd") (global-name "com.apple.containermanagerd.system"))))`; `container` включает этот flag | подключиться может любое приложение; фильтрация — на стороне демона по энтайтлментам. Подтверждено |
| mach-lookup `com.apple.mobile.installd` | `container`: входит в общий безусловный `allow mach-lookup (require-any ...)` | lookup открыт; каждый SPI отдельно гейтится в installd (`allowedSPI`, см. отчёт AI). Подтверждено |
| XPC `_remote_performAppReplacementFromAppIdentity:toAppIdentity:options:completion:` | `_IXHasTrueValueForEntitlement(xpcConnection, "com.apple.private.InstallCoordination.ReplaceApp")` | только приватный клиент. Подтверждено |
| XPC `_remote_getAppReplacementSource:forAppIdentity:options:completion:` | `com.apple.private.InstallCoordination.GetAppReplacementSource` | только приватный клиент. Подтверждено |
| XPC `_remote_appReplacementRefusedForAppIdentity:options:completion:` | `com.apple.private.InstallCoordination.AppReplacementRefused` | только приватный клиент. Подтверждено |
| XPC `_remote_resetAppReplacementStateForAppIdentity:options:completion:` | `com.apple.private.InstallCoordination.ResetAppReplacementState` | только приватный клиент. Подтверждено |
| `com.apple.developer.superseded-application-identifiers` (в подписи устанавливаемого app) | developer-энтайтлмент; installd проверяет только «непустой массив строк» (`MIAppReplacementOperation prepareWithError:` `0x100018ef0`); координатор читает его как ключ/список (Swift `0x10008dd54`) | без спец. подписи/профиля replacement не инициировать. Подтверждено (гейт); что именно сверяется с source — не подтверждено |
| MCM lookup контейнера по чужому identifier | `-[MCMEntitlements isAllowedToPerformOperationType:containerIdentity:part:partDomain:access:]` `0x207e10d90`: `[self allowed]` → allow; иначе `containerRequiredIdentifier` → `isAllowedWithContainerConfig:...`; для чужого id — `otherIDLookup` (`com.apple.private.MobileContainerManager.otherIdLookup`) | обычному приложению чужой контейнер не отдаётся. Подтверждено |
| MCM supersede (`replaceContainer:withContainer:`) | `-[MCMClientIdentity isAllowedToSupersedeContainer]` `0x207e35a14` = `[self allowed]` ИЛИ `[self canSupersedeContainer]` = `com.apple.private.MobileContainerManager.supersede` | только приватные клиенты (installd / installcoordinationd / сам containermanagerd). Подтверждено |

---

## 2. installcoordinationd: кто инициирует replacement

Демон запускается как `mobile`, MachServices: `com.apple.installcoordinationd`,
`com.apple.installcoordinationd.CacheDelete`, `.PersonaLifecycle`,
`com.apple.InstallProgress.xpc`. Свои энтайтлменты (ldid):

```
com.apple.private.installcoordinationd.daemon            = true
com.apple.private.mobileinstall.allowedSPI               = { GetAppMetadata, UpdatePlaceholderMetadata,
    InstallLocalProvisioned, UninstallForInstallCoordination, RevertForInstallCoordination,
    InstallForInstallCoordination, UpdateSinfForInstallCoordination,
    UpdateiTunesMetadataForInstallCoordination, SetAppReplacementStatus,
    RemoveAppReplacementState, PrepareAppReplacement, SetAppLaunchProhibited }
com.apple.private.MobileContainerManager.allowed         = true
com.apple.private.installcoordination.app-data-migration.host = true
```

т.е. координатор — единственный клиент installd, которому разрешены
`PrepareAppReplacement`/`SetAppReplacementStatus`/`RemoveAppReplacementState`
(подтверждает вывод AI по installd).

### 2.1 Гейт XPC-метода replacement

`-[IXSClientConnection _remote_performAppReplacementFromAppIdentity:toAppIdentity:options:completion:]`
(`0x100069c3c`):

```
100069c84: mov  x0, x24                 ; self (IXSClientConnection)
100069c88: bl   0x1000a7f20             ; objc_msgSend stub -> [self clientName]   (слот 0x1001182c0 -> "clientName")
100069c98: bl   0x1000aee60             ; objc_msgSend stub -> [self xpcConnection] (слот 0x100119e90 -> "xpcConnection")
100069ca4: adrp x24, #0x1000fd000
100069ca8: add  x24, x24, #0x68         ; CFString "com.apple.private.InstallCoordination.ReplaceApp"
100069cac: mov  x1, x24
100069cb0: bl   0x1000a3470             ; _IXHasTrueValueForEntitlement (GOT bind: InstallCoordination/_IXHasTrueValueForEntitlement)
100069cb4: mov  x26, x0
100069cbc: tbz  w26, #0, 0x100069d18    ; нет true -> ветка отказа (os_log + error)
```

Проверка идёт по энтайтлментам **XPC-соединения клиента**, не по подписи
приложения-инициатора. `[self clientName]` сохраняется только для текста ошибки
(`Client %@ is missing %@ entitlement, ...`).

Все гейты `_remote_*` replacement-семейства (сканирование вызовов
`_IXHasTrueValueForEntitlement` + ближайшая CFString):

| адрес вызова | метод | энтайтлмент |
|---|---|---|
| `0x100069540` | `getAppReplacementSource...` | `com.apple.private.InstallCoordination.GetAppReplacementSource` |
| `0x1000697b8` | `appReplacementRefused...` | `com.apple.private.InstallCoordination.AppReplacementRefused` |
| `0x100069a30` | `resetAppReplacementState...` | `com.apple.private.InstallCoordination.ResetAppReplacementState` |
| `0x100069cb0` | `performAppReplacementFrom...` | `com.apple.private.InstallCoordination.ReplaceApp` |
| `0x100069fb4` | `performAppReplacement...` (2-я точка) | `com.apple.private.InstallCoordination.ReplaceApp` |

Ошибки/логи: `IXAppReplacementErrorDomain`, `IXAppReplacementErrorCode`
(`Client %@ is missing %@ entitlement, rejecting ...`).

Кто держит `com.apple.private.InstallCoordination.ReplaceApp` — **не подтверждено**:
проверены `installd`, `containermanagerd`, `appstored`, `appconduitd`,
`managedappdistributiond`, `installcoordination_proxy` — ни у кого нет. Обычные
installer-демоны держат только `InstallCoordination.allowed` (`appstored`, `appconduitd`,
`managedappdistributiond`, `installcoordination_proxy`). Прямой XPC-путь replacement,
похоже, зарезервирован под отдельный/internal клиент (в исключениях координатора есть
`com.apple.installcoordinationd_test_daemon`); ставится ли он на релизе — открытый вопрос.

### 2.2 Где координатор читает superseded-identifiers

Swift-функция `0x10008da00` (единственный вызывающий — `0x10008b460`):

```
10008dd54: adrp x8, #0x1000ca000
10008dd58: add  x8, x8, #0xd30        ; "com.apple.developer.superseded-application-identifiers"
10008dd5c: sub  x8, x8, #0x20         ; Swift String-literal (large form: |0x8000..., length 0x36)
...
10008de30: bl   0x100095698           ; Dictionary.subscript / iterator
10008de40: bl   0x100083e78           ; сравнение ключа
10008de58: bl   0x1000a4310
10008de5c: tbz  w0, #0, 0x10008dddc   ; ключ не совпал -> следующий элемент
...
10008e49c: add  x3, x3, #0x580        ; "%s and %s both supersede %s"
```

Наблюдения:

- ключ читается из словаря энтайтлментов (итерация `Dictionary`/`Set` + сравнение строк);
- при совпадении двух кандидатов на один source — ошибка `%s and %s both supersede %s`;
- функция ниже по стеку (`0x10008b460`) вызывает резолвер из
  `InstallCoordination.framework`.

Резолвер (символы фреймворка, `ic/InstallCoordination`):

```
-[IXAppReplacementSourceResolver initWithIdentity:managedAppBundleIdentifiers:]
-[IXAppReplacementSourceResolver resolveAppReplacementSource:replacementRuledOut:replacementCandidate:error:]  @0x1c2fe5844
-[IXAppReplacementSourceResolver _appIsHidden:]      @0x1c2fe56c8
-[IXAppReplacementSourceResolver _appIsRestricted:]  @0x1c2fe5734
-[IXAppReplacementSourceResolver _personaForIdentity:record:error:] @0x1c2fe54fc
```

`resolveAppReplacementSource:` строит `LSApplicationRecord` по идентичностям,
отбрасывает hidden/restricted, сверяет персону и возвращает source identity либо
«replacement ruled out»/кандидата.

**Не подтверждено:** сверка team id / application-identifier destination-приложения с
source-приложением внутри этого пути. В бинаре координатора строка
`Unable to retrieve team identifier for bundle ID %@` есть, но её единственная ссылка —
`0x100014fac`, функция `remote`-класса removability (`askToOverrideUnremovabilityOfApplication:teamIdentifier:...`),
к резолверу отношения не имеет. Ни `teamIdentifier`, ни `application-identifier` в
резолвере не найдены; отрицательный результат статикой не доказывается.

Практический вывод по 2.2: единственная «авторизация» source — developer-энтайтлмент
`com.apple.developer.superseded-application-identifiers` в подписи устанавливаемого
приложения (выдаётся Apple через профиль). Рантайм-сверки «source принадлежит тому же
разработчику» в координаторе не видно; резолв идёт по bundle id через LaunchServices.

---

## 3. Контейнеры: supersede / чужой data-контейнер

Клиентский API 27.2 (вместо `libcontainer`; отдельного `libcontainer.dylib` в root FS и DSC
27.2 нет — код переехал в `libsystem_containermanager.dylib` внутри libSystem):

```
-[MCMContainerManager replaceContainer:withContainer:error:withCompletion:]  @0x297a6cf8c  (MobileContainerManager)
    -> _container_replace  (импорт libSystem.B.dylib; символ в libsystem_containermanager.dylib @0x207f6474c)
```

`_container_replace` строит XPC-сообщение (`xpc_connection_create_mach_service` + словарь
с идентичностями контейнеров); своего entitlement-гейта в клиенте нет — только транспорт.

Гейт демона (`ContainerManagerCommon`):

```
-[MCMEntitlements isAllowedToSupersedeContainer] @0x207ea3b3c
207ea3b64: bl   0x2080b5350             ; [self allowed]  (com.apple.private.MobileContainerManager.allowed)
207ea3b68: tbz  w0, 0x207ea3b98         ; allowed == YES -> return 1
207ea3bd0: b    0x2080b55c0             ; иначе tail-call [self canSupersedeContainer]

-[MCMClientIdentity isAllowedToSupersedeContainer] @0x207e35a14
207e35a3c: bl   0x2080b5800             ; [self codeSignInfo]
207e35a48: bl   0x20800f430             ; ... -> entitlements
207e35a54: bl   0x2080b7550             ; -[MCMEntitlements isAllowedToSupersedeContainer]
```

`-[MCMEntitlements canSupersedeContainer]` @0x207ea322c читает CFString
`0x26a1fc620` → cstr `0x207f1d252` = `com.apple.private.MobileContainerManager.supersede`
и вызывает `boolValue` (`0x207ea32b0`).

План supersede (`MCMCommandSupersedePlan`, Swift, `0x207f05568`) проверяет только:

```
207f0569c: cmp x27, x22
207f056a0: b.ne 0x207f0575c             ; -> "Refusing to supersede across container classes; successor=%llu, predecessor=%llu"
207f05738: cmp x22, x28
207f0573c: b.ne 0x207f05afc             ; -> "Refusing to supersede across users; successor=%s, predecessor=%s"
```

Плюс защита от повторного захвата identity (`0x207f04f64`, `0x207f05c18`):

```
"Refusing to supersede: [%s] already took this identity over from a different container called [%s], recorded = %s"
"Refusing to supersede a container with one that already has its identifier; identifier = [%s]"
```

Проверки «клиент владеет predecessor/successor» в плане нет — она выше, на входе
XPC, и сводится к entitlement-гейту `allowed || supersede`. Клиент с `.allowed`
(installd, installcoordinationd) проходит без привязки к bundle id контейнера.

Получение чужого контейнера по identifier — отдельный гейт
`-[MCMEntitlements isAllowedToPerformOperationType:containerIdentity:part:partDomain:access:]`
(`0x207e10d90`):

```
207e10e20: bl 0x2080b5350     ; [self allowed]
207e10e24: tbnz w0, ...       ; true -> разрешено
207e10e30: bl 0x2080b3360     ; [self containerRequiredIdentifier]
207e10e6c: bl 0x2080b7580     ; [self isAllowedWithContainerConfig:identifier:part:partDomain:access:]
...
207e10eb0..: switch(operationType)
207e10f9c: bl 0x2080b7eb0     ; [self otherIDLookup]  -> com.apple.private.MobileContainerManager.otherIdLookup
207e11160: mov w23, #3        ; allow
207e111b0: mov w23, #0        ; deny
```

(селекторы стабов сверены по DSC: `allowed`, `containerRequiredIdentifier`,
`isAllowedWithContainerConfig:...`, `otherIDLookup`, `canDelete`, `canDeleteContainerContent`.)

### 3.1 `supersedeExistingContainer:error:` в 27.2

Селектор не в libcontainer, а в `InstalledContentLibrary` (его и зовёт installd,
`0x100019794`):

```
-[MIMCMContainer supersedeExistingContainer:error:]  @0x1ab4c9910
-[MIDataContainer supersedeExistingContainer:error:] @0x1ab50e44c
_MICopySupersededApplicationIdentifiersEntitlement
```

`MIMCMContainer`: берёт `MCMContainer` из self и из аргумента и зовёт
`bl 0x1b0148160` — это thunk в `libsystem_containermanager.dylib`
(`_container_operation_copy_superseded`, @0x207f55494). Никаких проверок
identity/владельца по пути нет.

`_container_operation_copy_superseded` (клиентская часть) сама проверяет только
аргументы и шлёт XPC в сервис `container_operation_copy_superseded`:

```
207f557d8: add x8, #0xaa2        ; имя XPC-сервиса "container_operation_copy_superseded"
207f5581c: add x3, #0xb7         ; "%s: SPI MISUSE: predecessor required but not valid"
207f557f0: add x3, #0xea         ; "%s: SPI MISUSE: successor provided but not valid"
...
207f558b0/58c4/58d8:            ; словарь: "Command", "Container", "Flags", "SuccessorContainer"
207f55c98: add x3, #0x20d        ; "No usable container in reply during %s"
```

`MIDataContainer`: `dataContainer` обоих → `bl 0x1b00b1040` — та же передача в MCM.

Т.е. в 27.2 «libcontainer-путь» = `InstalledContentLibrary` → `libsystem_containermanager`
(XPC `container_operation_copy_superseded`) → `containermanagerd`, а решение о
допустимости принимает демон (`allowed || supersede`), не клиент.

---

## 4. Вердикт

1. **Без спец-энтайтлментов приложение не может инициировать replacement.**
   - к `installcoordinationd` нет mach-lookup в профиле `container` (и в `baseline`);
   - все XPC-методы replacement закрыты приватными `com.apple.private.InstallCoordination.*`;
   - сам триггер (`com.apple.developer.superseded-application-identifiers`) — developer-
     энтайтлмент, который должен быть в подписи/профиле устанавливаемого приложения.

2. **Чужой data-контейнер без спец-энтайтлментов не получить.**
   - lookup чужого identifier требует `allowed` / `otherIDLookup`;
   - supersede требует `allowed` или `supersede`;
   - оба — приватные `com.apple.private.MobileContainerManager.*`.

3. **Кто инициирует replacement в легальном пути:** клиент с
   `com.apple.private.InstallCoordination.ReplaceApp` дёргает координатор
   (в проверенных демонах такого клиента нет — см. 2.1); координатор — единственный
   держатель ключа `PrepareAppReplacement` — зовёт соответствующий SPI installd и
   двигает data-контейнеры через MCM supersede (у координатора есть
   `MobileContainerManager.allowed`). Триггер для самого replacement —
   `com.apple.developer.superseded-application-identifiers` в подписи
   устанавливаемого приложения (проверка installd: непустой массив строк).

4. **Дыра/недосмотр, который остаётся:** в координаторе не найдено сверки, что
   source-приложение принадлежит тому же разработчику/team id, что и destination.
   Если подпись с `com.apple.developer.superseded-application-identifiers` можно
   получить/подделать (jailbreak/AMFI bypass/enterprise-профиль), список в этой
   подписи — единственное, что отделяет destination от data-контейнера чужого
   приложения. Это **гипотеза**, требующая проверки на устройстве.

---

## 5. Что осталось не подтверждено

- Точная семантика Swift-функции `0x10008da00` (что делает с найденным массивом
  `superseded-application-identifiers`: сравнение с identity, фильтрация, передача в
  резолвер). Дизасм есть, полная декомпиляция — нет.
- Сверка team id / application-identifier при резолве source (см. 2.2).
- Проверка владельца контейнера внутри `MCMCommandSupersedeExecutor` (план проверяет
  только класс и пользователя; entitlements-гейт — выше).
- Кто именно из клиентов (кроме installd/installcoordinationd) держит
  `com.apple.private.MobileContainerManager.allowed` / `.supersede` — по root FS
  выборочно: installd, containermanagerd, installcoordinationd.
- Домен/system-app контейнеры и гонка install vs prepare (наследие отчёта AI).

## 6. Файлы

- `installcoordinationd`, `appstored`, `ic/InstallCoordination`, `icl/InstalledContentLibrary`,
  `lib/ContainerManagerCommon`, `lib/MobileContainerManager`, `lib2/libsystem_containermanager.dylib`.
- `f_69c3c.txt` — дизасм `_remote_performAppReplacement...` (гейт).
- `f_8da00.txt` — дизасм Swift-функции чтения superseded-identifiers.
- `cm_f2.txt`, `cm_supersede.txt` — дизасм плана supersede.
- `allowedop.txt` — дизасм `isAllowedToPerformOperationType:`.
- `ic_resolve.txt` — дизасм `resolveAppReplacementSource:...`.
- `icl_mimcm.txt` — дизасм `-[MIMCMContainer supersedeExistingContainer:error:]`.
- `dsc_images.txt`, `cm_starts.txt`, `starts.txt` — карты образов/функций.
