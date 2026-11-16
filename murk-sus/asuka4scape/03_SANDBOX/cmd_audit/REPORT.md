# containermanagerd — XPC-поверхность для обычного приложения

**Цель:** iOS 27.2 (24B119), `containermanagerd`, `MobileContainerManager-833.40.18.0.1`.
**Бинарь:** `/home/femboychik/work/root272/containermanagerd`, 54 400 Б, arm64e, sha256 `df9a1dbe…5fc5060c`.
27.0: `/home/femboychik/work/root270/containermanagerd`, sha256 `a74adea3…e151f27e75`.
**Код:** весь в `ContainerManagerCommon` из dsc 27.2 (`rc115/dsc272`), sha256 `400738ae…2794a26f`; клиент — `libsystem_containermanager.dylib`, sha256 `2b4f043e…c5401a4d`.
`ContainerManagerSystem`/`ContainerManagerUser` — пустые __TEXT (0 байт кода), алиасы Common.
**Метод:** `ipsw dyld` (extract/symaddr/disass/stubs/objc), capstone, символы dsc, ручной дизасм; динамики на устройстве нет — всё статически.

---

## 1. Приём и диспетчеризация

* Два mach-сервиса: `com.apple.containermanagerd` (user) и `com.apple.containermanagerd.system`. В профиле `container` оба открыты всем приложениям через `common-containermanagerd-rules` (дано).
* Слушатель: `____containermanagerd_connection_handler_block_invoke` @ `0x207e4697c` создаёт `MCMCommandDispatcher` и регистрирует **39 классов команд** (`registerCommandClass:` @ `0x207e469ec`–`0x207e46d84`). Набор — см. таблицу.
* Выбор команды: `-[MCMCommandDispatcher _commandClassFromXPCMessage:context:error:]` @ `0x207e18b54`:
  ```
  207e18b84  adrp x1, #0x207f1c000
  207e18b88  add  x1, x1, #0xbc3      ; "Command"
  207e18b90  bl   _xpc_dictionary_get_uint64
  207e18bac  ldr  x0, [x8, #0x808]    ; NSNumber
  207e18bc8  bl   objc_msgSend$objectForKeyedSubscript:
  ```
  Ключ — `"Command"` (uint64). Карта `messageToCommandClassMap` — `NSDictionary` в `MCMCommandDispatcher`; наполняется в block invoke выше.
* Общий конвейер `-[MCMCommandDispatcher dispatchMessage:context:reply:]` @ `0x207e14328`:
  ```
  207e144e4  bl  _commandFromCommandClass:message:context:reply:error:
  207e14504  bl  objc_msgSend$preflightClientAllowed
  207e1450c  tbz w0, #0, 0x207e14548        ; false -> notEntitled
  207e14514  bl  objc_msgSend$execute
  207e14548  ... 0x2760ad8f8                 ; +[MCMError notEntitled]
  207e1457c  bl  objc_msgSend$completeWithResult:
  ```
  `notEntitled` = `MCMError` type **0x37 (55)**, category 3 (`0x207e5e50c`).
  Никакой проверки «свой/чужой» на уровне диспетчера нет — только per-command preflight и проверки внутри `execute`.
* Личность клиента:
  * `-[MCMClientMessageContext initForCurrentThreadContextWithXPCMessage:]` @ `0x207e07d40`: audit token — `xpc_dictionary_get_audit_token` (`0x207e07dc0`), персона — `personaUniqueStringForCurrentContext` (`0x207e07dd4`) и voucher (`0x207e07dec`). **Из словаря сообщения не берутся.**
  * `-[MCMClientFactory(XPC) clientIdentityWithClientMessageContext:xpcMessage:error:]` @ `0x207e0b170`: `clientIdentityWithAuditToken:proximateAuditToken:personaUniqueString:error:generator:` (`0x207e0b274`).
  * `ProxyForClient` (подмена личности) — только при `com.apple.private.MobileContainerManager.proxy`:
    ```
    207e0b334  bl  objc_msgSend$proxyAllowed
    207e0b340  tbz w0, #0, 0x207e0b350   ; нет -> notEntitled
    ```
* Relay: `-[MCMCommandDispatcher _ifNeededRelayMessage:context:]` @ `0x207e002c4` по `message.disposition` (2 → `relayToPrivilegedDaemonMessage:context:` в system-демон; 1 → локально, в system-режиме ошибка 0x64). Сквозная проверка identity на стороне system-демона не аудировалась.

---

## 2. Модель гейтов

### 2.1 Preflight
У каждой команды свой `-preflightClientAllowed`. Основные предикаты (`MCMClientIdentity` → `MCMEntitlements`), строки энтайтлментов:

| Предикат | Энтайтлмент |
|---|---|
| `allowed` | `com.apple.private.MobileContainerManager.allowed` |
| `otherIDLookup` | `com.apple.private.MobileContainerManager.otherIdLookup` |
| `lookup` (словарь) | `com.apple.private.MobileContainerManager.lookup` |
| `access` (словарь) | `com.apple.private.container.access` |
| `proxyAllowed` | `…MobileContainerManager.proxy` |
| `canRepair` | `…MobileContainerManager.repair` |
| `canDebug` | `com.apple.private.container.debug` |
| `canDelete` | `…MobileContainerManager.delete` |
| `canDeleteContainerContent` | `…MobileContainerManager.deleteContainerContent` |
| `canManageUserManagedAssets` | `…MobileContainerManager.userManagedAssets` |
| `canControlCaches` | `…MobileContainerManager.cacheControl` |
| `canStageSharedContent` | `…MobileContainerManager.stageSharedContent` |
| `canSupersedeContainer` | `…MobileContainerManager.supersede` |
| `canCheckAuthorization` | `…MobileContainerManager.checkAuthorization` |
| `canReadReferences` / `canReadWriteReferences` | `…references.read-only` / `…references.read-write` |
| `canPerformDataMigration` | `…MobileContainerManager.dataMigration` |
| `canAccessAllPersonas` | `com.apple.private.container.all-personas` |
| `hasDaemonContainer` | `com.apple.private.security.daemon-container` |
| `hasSystemContainer` | `com.apple.security.system-container` |
| `hasProtectedSystemContainer` | `com.apple.private.security.protected-system-container` |
| `requestsNoContainer` | `com.apple.private.security.no-container` |
| `isAllowedToTest` | `…MobileContainerManager.testability` (+ internal image) |

### 2.2 Per-container проверка
`-[MCMEntitlements isAllowedToPerformOperationType:containerIdentity:part:partDomain:access:]` @ `0x207e10d90` — вторая (главная) линия. Возвращает код: 0 — запрет, 1 — владелец, 2 — public app group, 3 — entitled, 4 — app migration, 5 — system bypass list.

```
207e10e20  bl  objc_msgSend$allowed              ; allowed -> 3
207e10e6c  bl  objc_msgSend$isAllowedWithContainerConfig:identifier:part:partDomain:operation:access:
207e10f20  bl  objc_msgSend$identifier           ; entitlements.identifier (code-sign)
207e10f30  mov x0, x22
207e10f38  bl  objc_msgSend$isEqualToString:     ; == containerIdentity.identifier ?
207e10f44  cbz w27, 0x207e1109c                ; не совпало -> группы/bypass/запрет
```
Совпадение идентификатора даёт доступ только к «своему» контейнеру; для классов 0xa/0xc/0xf дополнительно требуются daemon/system/protected-энтайтлменты (`0x207e11090`, `0x207e11080`, `0x207e10f60`). Групповые классы (7/13) проверяются по app-group энтайтлментам (`0x207e10fa8`–`0x207e1107c`).

В `MCMCommandQuery` запрет по конкретному identifier — не «пропустить», а **аварийный `notEntitled` на весь запрос**:
```
207e24240  bl  isAllowedToPerformOperationType:containerIdentity:part:partDomain:access:
207e2424c  cbz x20, 0x207e24368
207e24368  ... bl objc_msgSend$notEntitled
207e243c4  b   0x207e245a8                ; выход из _queryPlanWithIdentifiers
```

---

## 3. Таблица методов (Command ID | класс | гейт | аргументы | что возвращает | вердикт)

| ID | Метод | Гейт preflight | Аргументы (из XPC) | Возврат | Вердикт |
|---|---|---|---|---|---|
| 2 | `MCMCommandReplaceContainer` | `isAllowedToReplaceContainers` | old/new concrete identity, staging paths, flags | metadata/path | закрыт |
| 3 | `MCMCommandOperationDelete` | per-container `isAllowed…` (в preflight, `0x207e312d4`) | container identities/manifests | результат | закрыт |
| 4 | `MCMCommandOperationReclaimDiskSpace` | `allowed` \|\| `canDelete` \|\| `canManageUserManagedAssets` | пути/флаги | результат | закрыт |
| 5 | `MCMCommandSetInfoValue` | `isAllowedToAccessInfoMetadata` | concrete identity, key, value | metadata | закрыт |
| 6 | `MCMCommandInfoValueForKey` | `isAllowedToAccessInfoMetadata` | concrete identity, key | значение | закрыт |
| 8 | `MCMCommandRecreateContainerStructure` | `isAllowedToRecreateContainerStructure` | identity | metadata | закрыт |
| 9 | `MCMCommandRegenerateDirectoryUUID` | `isAllowedToRegenerateDirectoryUUIDs` | identity | metadata | закрыт |
| 10 | `MCMCommandDeleteWithUIDClassAndIdentifier` | делегирует `deleteCommand.preflight` | uid, class, identifier | удаление | закрыт |
| 11 | `MCMCommandDeletePluginDataContainerContent` | per-container | identity | — | закрыт |
| 12 | `MCMCommandDeleteContainerContent` | per-container | identities | — | закрыт |
| 18 | `MCMCommandSetCodeSignMapping` | `isAllowedToAccessCodesignMapping` | identifier, info | — | закрыт |
| 19 | `MCMCommandGetCodeSignMapping` | `isAllowedToAccessCodesignMapping` | identifier | cs-info | закрыт |
| 20 | `MCMCommandInvalidateCodeSigningCache` | `isAllowedToAccessCodesignMapping` | — | — | закрыт |
| 21 | `MCMCommandSetDataProtection` | `isAllowedToSetDataProtection` | identity | — | закрыт |
| 22 | `MCMCommandProcessRestoredContainer` | `isAllowedToRestoreContainer` | identity | — | закрыт |
| 23 | `MCMCommandDiskUsageForContainer` | per-container | identity | байты | закрыт |
| 25 | `MCMCommandCrashTest` | internal image + `isAllowedToTest` | identity, count | краш | закрыт |
| 26 | `MCMCommandStageSharedContent` | `isAllowedToStageSharedContent` | identity, src/dst rel paths | — | закрыт |
| 28 | `MCMCommandUserManagedAssetsPath` | **own id** (`0x207e3f234`: `containerIdentity.identifier` == client id) + `isAllowedToAccessUserAssets` | identity, relative, create | путь | только свой |
| 29 | `MCMCommandDeleteUserManagedAsset` | `isAllowedToAccessUserAssets` | identity, relative path | удаление | закрыт энтайтлментом `userManagedAssets` |
| 30 | `MCMCommandUserDataMigration` | `isAllowedToStartUserDataMigration` | — | — | закрыт |
| 31 | `MCMCommandSetTestLock` | `isAllowedToTest` | lock, enable | — | закрыт |
| **32** | **`MCMCommandFetchPersonaUniqueStrings`** | **нет** (`0x207e34eac: mov w0,#1`) | — | persona unique strings | **свой persona; см. §4.4** |
| 33 | `MCMCommandFlushContainerCache` | `isAllowedToControlCaches` | identity, class | — | закрыт |
| 34 | `MCMCommandFlushPersonaCache` | `isAllowedToControlCaches` | — | — | закрыт |
| 35 | `MCMCommandAcquireSandboxExtensionWithUUID` | per-container (в preflight) | NSUUID, флаги | sandbox token + path | закрыт |
| **36** | **`MCMCommandCreateOrLookupWithBundle`** | **нет** (`0x207ea612c: mov w0,#1`) | `BundlePath`, `ExecutablePath`, `SandboxToken`, `Flags` | путь + token | **только свой id; см. §4.2** |
| **38** | **`MCMCommandCreateOrLookupAppGroupByAppGroupIdentifier`** | **нет** (`0x207e1b360`) | `Identifier`, `PersonaKernelID`, flags | путь + token | **только entitled группы** |
| **39** | **`MCMCommandQuery`** | только user-assets флаги (`0x207e0e6b0`) | `Identifiers`, `GroupIdentifiers`, `InternalUUID`, `Uid`, `Part`, `Persona`, `Explicit`/`PrivateFlags` | контейнеры: path/url/info/uuid/token | **только свои; чужой id → notEntitled** |
| 44 | `MCMCommandContainerFromPath` | `allowed` \|\| `otherIDLookup` (`0x207e95c1c`) | URL + relative path | identity/path | закрыт |
| **45** | **`MCMCommandOpenPrimordialDataContainer`** | **нет** (`0x207e8f58c`) | `containerRequiredIdentifier` из энтайтлмента клиента | ошибка 0x12 | **непригоден без `container-required`** |
| 46 | `MCMCommandCompleteBackgroundTasks` | `allowed` \|\| `testabilityAllowed` | — | — | закрыт |
| 47 | `MCMCommandReferencesQuery` | `isAllowedToReadReferences` | owners/groups | refs | закрыт |
| 48 | `MCMCommandReferencesAdd` | `isAllowedToChangeReferences` | owners/groups | — | закрыт |
| 49 | `MCMCommandReferencesRemove` | `isAllowedToChangeReferences` | owners/groups | — | закрыт |
| 50 | `MCMCommandAuthorize` | `onBehalfOfSelf` \|\| `isAllowedToCheckAuthorization`; в execute — `forAllContainers` access=2 (`0x207ee8728`) | auditToken, identifiers, groups | auth-результат | только свои/entitled |
| 51 | `MCMCommandUpdateInfo` | `isAllowedToAccessInfoMetadata` | identity, info dict | metadata | закрыт |
| 53 | `MCMCommandDumpState` | `canDebug` (`0x207efa3c4`) | — | дамп состояния | закрыт |
| 54 | `MCMCommandSupersedeContainer` | `isAllowedToSupersedeContainer` | identity | — | закрыт |

Не зарегистрированы в 27.2: ID 1, 7, 13–17, 24, 27, 37, 40–43, 52 (легаси/удалённые).

---

## 4. Ответы по пунктам

### 4.1. Методы и гейты
См. таблицу. Гейты — энтайтлменты `com.apple.private.MobileContainerManager.*` / `com.apple.private.container.*` / `com.apple.security.*`; `auditToken` берётся из ядра, `persona` — из voucher; `ProxyForClient` — только с `.proxy`.

### 4.2. Методы без гейта, принимающие identifier/bundle id/persona/uid/class/путь/NSUUID
Пять команд проходят preflight безусловно: **32, 36, 38, 39, 45**.

* **39 Query** — принимает `Identifiers` (bundle id), `GroupIdentifiers`, `InternalUUID` (NSUUID), `Uid` (uint64), класс контейнера (`Part`), персону (строка), флаги. Проверка: идентификатор каждого кандидата сравнивается с code-sign identifier клиента; чужой → `notEntitled`, запрос целиком падает. `Uid` **разбирается, но нигде не используется** (нет вызовов `objc_msgSend$uid` в методах Query).
* **36 CreateOrLookupWithBundle** — принимает `BundlePath`, `ExecutablePath`, `SandboxToken`, `Flags`. Класс контейнера выбирается по суффиксу `BundlePath` (`.appex` → 4, иначе 2; `0x207ea65cc`–`0x207ea6610`), а идентификатор берётся из **подписи исполняемого файла по `ExecutablePath`**: `MCMCodeSignInfo initWithURL:error:` (`0x207ea6684`, аргумент — `executableURL` из `0x207ea666c`), затем `identifier` (`0x207ea67c0`) → `legacyUserIdentityForIdentifier:…` (`0x207ea6844`). Далее `execute` проверяет **code-sign identifier клиента** против этого идентификатора:
  ```
  207ea6238  bl  _containerIdentityWithError:
  207ea6294  bl  isAllowedToPerformOperationType:containerIdentity:part:partDomain:access:
  207ea62a4  cbz x22, 0x207ea63d0   ; notEntitled
  ```
  Подсунуть чужой bundle id нельзя: подпись чужого executable даст чужой identifier, а он не равен identifier клиента из audit token.
* **38 CreateOrLookupAppGroup** — принимает `Identifier` (app group) и `PersonaKernelID`. `PersonaKernelID` только сверяется с `context.kernelPersonaID` (`0x207e00830`–`0x207e0083c`, ошибка 0x97 при флаге `errorOnPersonaPropagationFailure`), как селектор персоны **не используется**. Доступ — по app-group энтайтлментам клиента; иначе `notEntitled` (`0x207e1c194`).
* **32 FetchPersonaUniqueStrings** — аргументов нет. Для обычного приложения (`personaType != 2`, `isNoSpecificPersona` == false, `0x207e15eb8`) возвращает **только свой** persona unique string; полный перебор `allAccessibleUserIdentities` — лишь для клиентов без конкретной персоны.
* **45 OpenPrimordialDataContainer** — при отсутствии `com.apple.private.security.container-required` (и при `requestsNoContainer`) завершается ошибкой 0x12 ещё в `initWithMessage:`; пути/контейнера не отдаёт.

**Чужой контейнер запросить нельзя**: и Query, и CreateOrLookup* упираются в `isAllowedToPerformOperationType:`, где сравнение идёт с code-sign identifier вызывающего. Ответ на чужой id — `MCMError notEntitled` (55/3), без пути, URL и содержимого.

### 4.3. Query-путь (`container_query`, `container_copy_*`)
* Перед разбором: `execute` требует **подписанного** клиента (`codeSignInfo.isSigned`), иначе ошибка 0x62 (98):
  ```
  207e0f9e0  bl  objc_msgSend$isSigned
  207e0f9e4  tbz w0, #0, 0x207e0fa3c
  207e0fa48  mov w2, #0x62
  ```
* Без `Identifiers`/`GroupIdentifiers` запрос по умолчанию превращается в `setWithObject:self.clientIdentifier` (`0x207e2e3f8`–`0x207e2e46c`) — то есть «свой контейнер», не перебор всех.
* `includeUnowned` (`container_query_set_include_other_owners`): при `canAccessAllContainers == NO` возвращается не «все», а `entitlements.contributingIdentifiersForContainerConfig:` + групповые/системные спец-случаи (`0x207ea0474`–`0x207ea049c`). `canAccessAllContainers` = `allowed` \|\| `otherIDLookup` \|\| `isAllowedToPerformOperationType:forAllContainers…` (`0x207e0d154`).
* `requestAllPersonas`: расширение до `allAccessibleUserIdentities` только после `isAllowedToAccessAllPersonas` (`0x207e9fb14`–`0x207e9fbf4`); иначе — одна своя identity или ошибка.
* Фильтры по class/part/persona/uid не отменяют per-container проверку; `internalUUID` лишь выбирает инстанс, но не отменяет сравнение identifier.
* Клиентские обёртки `container_query_*` / `container_copy_path` / `container_copy_info` / `container_copy_sandbox_token` / `container_copy_persona_unique_strings` (экспорты `libsystem_containermanager.dylib`) упираются в те же команды 39 (Query) и 32 (FetchPersona) — отдельного XPC-пути у них нет; побитовая привязка каждой обёртки к ID статически не проверялась.
* Что возвращается для разрешённых контейнеров: path (fileSystemRepresentation), URL, info-словарь, UUID, class, identifier, user-managed assets rel path, creator, sandbox token (`MCMResultWithContainerBase encodeResultOntoReply:` @ `0x207e229cc`, ключи `Path`, `SandboxToken`, `Identifier`, `UUID`, `ContainerClass`, `PersonaUniqueString`, `Containers`).

### 4.4. Persona/uid
`-[MCMXPCMessageBase userIdentityFromClientPersonaUniqueString:clientIdentity:error:]` @ `0x207e069c0`:
```
207e06a90  bl  userIdentityForCurrentUserWithPersonaUniqueString:   ; резолв в кэше
207e06ad0  bl  objc_msgSend$isNoSpecificPersona                     ; клиент без персоны?
207e06ae0  bl  objc_msgSend$isEqual:                                ; == identity клиента?
207e06aec  bl  objc_msgSend$isAllowedToAccessAllPersonas
207e06af0  tbnz w26, #0, 0x207e06bc0   ; no-specific -> принять
207e06af4  tbnz w25, #0, 0x207e06bc0   ; своя персона -> принять
207e06af8  cbnz w0,  0x207e06bc0      ; all-personas -> принять
207e06b1c  ... initWithErrorType:0x4c  ; иначе отказ (76/3)
```
Итог: подставить чужую персону нельзя — она либо не резолвится для текущего пользователя, либо не равна identity клиента; исключение — клиент с `com.apple.private.container.all-personas` (или без конкретной персоны, т.е. системный). `uid` в Query не используется. Мультиюзерная ветка `legacySetOfUserIdentitiesForIdentifiers:` при нескольких владельцах одного identifier даёт ошибку 0x73 (ambiguous), а `_userIdentityDisambiguatedFromUserIdentities:` выбирает единственную personal-identity (`0x207e2ec0c`); путь «взять контейнер другого uid» не подтверждён.

### 4.5. Вердикт
Обычное подписанное приложение **может** подключиться к обоим сервисам и вызвать 36/38/39 (и 32), но:
* чужой bundle id/группа/персона/uid отсекаются сравнением с code-sign identity из audit token → `notEntitled` (55/3);
* пути, URL, info и sandbox-token выдаются только для контейнеров, где identifier совпал с собственным (или клиент имеет соответствующий энтайтлмент);
* создать контейнер с чужим id нельзя: идентификатор в 36 берётся из подписи бандла по пути, а доступ проверяется по подписи **клиента**;
* всё, что даёт чужой контейнер/путь/массовые операции (Query с `includeUnowned`, ContainerFromPath, AcquireSandboxExtensionWithUUID, Delete*, Replace/Supersede, DumpState), закрыто preflight-энтайтлментами.

Пути к чужим данным или созданию контейнера с чужим id **не найдено**.

---

## 5. Ключевой дизасм (адреса)

```
; dispatch: preflight -> notEntitled
207e14504  bl  objc_msgSend$preflightClientAllowed
207e1450c  tbz w0, #0, 0x207e14548
207e14548  adrp x8, #0x2760ad000 ; +[MCMError notEntitled]
207e14580  bl  objc_msgSend$completeWithResult:

; Query: обязательная подпись
207e0f9e0  bl  objc_msgSend$isSigned
207e0f9e4  tbz w0, #0, 0x207e0fa3c
207e0fa48  mov w2, #0x62

; Query: отказ по чужому identifier (весь запрос)
207e24240  bl  isAllowedToPerformOperationType:containerIdentity:part:partDomain:access:
207e2424c  cbz x20, 0x207e24368
207e24368  bl  objc_msgSend$notEntitled
207e243c4  b   0x207e245a8

; per-container: свой identifier
207e10f20  bl  objc_msgSend$identifier
207e10f38  bl  objc_msgSend$isEqualToString:
207e10f44  cbz w27, 0x207e1109c

; canAccessAllContainers
207e0d188  bl  objc_msgSend$allowed
207e0d194  bl  objc_msgSend$otherIDLookup
207e0d1e8  bl  isAllowedToPerformOperationType:forAllContainersOfContainerConfig:…

; persona
207e06a90  bl  userIdentityForCurrentUserWithPersonaUniqueString:
207e06af0  tbnz w26, #0, 0x207e06bc0
207e06b1c  mov w2, #0x4c

; proxy
207e0b334  bl  objc_msgSend$proxyAllowed
207e0b340  tbz w0, #0, 0x207e0b350

; CreateOrLookupWithBundle: гейт только per-container
207ea612c  mov w0, #1                 ; preflight = YES
207ea6684  bl  MCMCodeSignInfo initWithURL:error:
207ea67c0  bl  objc_msgSend$identifier
207ea6294  bl  isAllowedToPerformOperationType:…
207ea62a4  cbz x22, 0x207ea63d0

; PersonaKernelID (app group)
207e00830  bl  objc_msgSend$kernelPersonaID
207e00838  cmp w0, w8
207e0083c  b.eq 0x207e00874
```

---

## 6. Не подтверждено

* Сквозной relay user-демон → `containermanagerd.system`: проверка identity на принимающей стороне не аудирована.
* `MCMCommandDeleteUserManagedAsset`: идентификатор берётся из concrete identity сообщения, preflight проверяет только `userManagedAssets`; ограничение — тем же энтайтлментом, для обычного приложения недостижимо. Проверка владения внутри `execute` до конца не прослежена.
* Мультиюзер (Shared iPad): `legacySetOfUserIdentitiesForIdentifiers:` сканирует владельцев identifier по всем пользователям (`0x207dffb3c`), затем требует единственную personal-identity; сценарий «приложение установлено только у другого uid, но процесс запущен у вызывающего» не проверялся.
* Точные XPC-ключи concrete-container сообщений (часть читается helper'ами через NSConstantString, не все видны статически).
* Динамика: ни один вывод не проверен запуском на устройстве.
* 27.0 vs 27.2 дифф не делался (27.2 — целевая).

---

## 7. Итог

Поверхность для обычного приложения — ровно четыре команды: `Query` (39), `CreateOrLookupWithBundle` (36), `CreateOrLookupAppGroup` (38), `FetchPersonaUniqueStrings` (32). Все они упираются в сравнение code-sign identifier клиента (audit token, ядро) с идентификатором контейнера; persona/uid/proxy подменить нельзя. Чужой контейнер не выдаётся, контейнер с чужим id не создаётся. Единственный остаточный класс — DoS/ambiguity на мультиюзере и релей в system-демон (не подтверждено).
