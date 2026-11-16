# installd 27.2 — XPC-методы без `allowedSPI`

**Дата:** 2026-10-29  
**Объект:** `/usr/libexec/installd`, iOS 27.2 (24B115), arm64e  
**Бинарь:** `/home/femboychik/work/root272/installd`, 961 888 Б, sha256 `408906e8625f927a9165a13ec07398e4a21f7e1dd60d1ad385d17801bd0fdf06`  
**Для диффа:** `/home/femboychik/work/root270/installd`, sha256 `cb3897fb328fc177d3e11f28b2e9c018f52835cd9f06359717e472692e90b3fe`  
**Инструменты:** `ipsw 3.1.736` (`class-dump --re -V`, `macho disass`, `macho info --fixups`, `dyld extract`), capstone 5.0.7, LIEF 1.0.0, `ldid-amd64 -e`, Python 3.  
**Стенд:** `root272`, sandbox-профили `sb272/` (`container.sb`, `all.json`, `baseline.sb`), DSC `rc115/dsc272`.

---

## 0. Вердикт

1. **Вход открыт любому приложению.** Профиль `container` (стандартный app-профиль) содержит `com.apple.mobile.installd` в безусловном `allow mach-lookup` (строка 13515 `container.sb`). Listener `0x10001b280` принимает любое соединение без audit-token/энтайтлмент-проверки. Это подтверждает поправку AJ: вывод прошлого отчёта `installd2` «sandbox не пускает app» — неверен.
2. **Из 75 методов `MobileInstallerProtocol` только 6 не имеют гейта** (ни `allowedSPI`, ни иного энтайтлмента). Остальные 69 закрыты per-method.
3. **Главная находка — `triggerRegistrationForContainerizedContentForOptions:` / `...DiskImageContent...`**: клиент передаёт `ICLRegistrationOptions`, inside — `targetUID`; daemon без проверки использует его как `forTargetUID` и как `LSOperationRequestContext.targetUserID`. Приложение может заказать пересканирование/перерегистрацию контента в LaunchServices **для произвольного uid**, включая 0 и чужого пользователя. Это cross-uid запись в LS + ресурсоёмкий скан без рейт-лимита (DoS).
4. **`registerPlaceholderForReference:`** принимает клиентский `MIAppReference` и **не вызывает** `+[MIAppReference validateAppReference:withError:]` (в отличие от `finalizeReference:`). По `identity.bundleID`/`domain` он находит **чужой установленный** app, создаёт ему data-контейнеры (если их нет), пишет `AppReferences/user_<uid>/…` в его bundle-контейнер и регистрирует LS-запись с `isPlaceholder = YES`. То есть inter-app запись в контейнер цели и попытка перевести чужой app в placeholder-состояние. Перезапись существующей LS-записи на устройстве не проверялась.
5. **`referencesForBundleWithIdentifier:inDomain:`** — единственный ungated lookup по bundle id. Возвращает `NSDictionary` `{uid → NSSet(persona-строк)}`; для `domain != 3` обходит **всех** пользователей (`UMUserManager.allUsers`). Утечка: факт наличия app, список uid и persona-строк. Путей контейнеров, UUID и метаданных бандла в ответе **нет**.
6. `checkCapabilities:` — только словарь `UIRequiredDeviceCapabilities`; `getPidForTesting` — pid installd. Опасности нет.
7. **Произвольного чтения/записи файлов, path traversal и TOCTOU в ungated-методах не найдено.** Клиентских путей эти методы не принимают (кроме `MIAppIdentity.location`, который для резолва контейнера игнорируется). Установка/удаление/замена/revert по-прежнему требуют `allowedSPI` (в т.ч. `installURL`/`stageInstallURL` — через `_validateInstallRequestForURL`).

---

## 1. Вход: sandbox, listener, интерфейс

### 1.1 Sandbox

`sb272/container.sb`:

```
13159: (allow mach-lookup
13160:     (require-any
...
13515:         (global-name "com.apple.mobile.installd")
```

Блок не имеет условий `signing-identifier`/`entitlement`; это общий allow-лист app-профиля. В `baseline.sb` стоит `(deny mach-lookup)`, но `container.sb` extends baseline и перекрывает его этим allow. В `all.json` имя сервиса также встречается у 9 daemon-профилей (appstored, gamed, bird, appconduitd, streaming_zip_conduit, lockdownd, maild, AirTraffic, CommCenter); app-профиль — `container`.

### 1.2 Listener

`-[MobileInstallationServiceDelegate listener:shouldAcceptNewConnection:]` — `0x10001b280`:

```
0x10001b2b0  setExportedInterface:   ; 0x100004ae0 -> NSXPCInterface(MobileInstallerProtocol)
0x10001b2c0  objc_opt_new(MIClientConnection)
0x10001b2d0  setExportedObject:
0x10001b2e8  setRemoteObjectInterface:
0x10001b2f8  setXpcConnection:
0x10001b320  resume
0x10001b32c  mov w0, #1              ; accept
```

Ни `auditToken`, ни `processIdentifier`, ни проверки энтайтлментов на входе. `clientName` (`0x10001b348`) — только строка `"%@ (pid %d (%u/%u))"` из `processIdentifier`/`effectiveUserIdentifier`/`effectiveGroupIdentifier`; используется в логах, не в авторизации.

### 1.3 Интерфейс

`0x100004ae0` собирает `NSXPCInterface` из `@protocol(MobileInstallerProtocol)` (protocol_t `0x1000d6530`). Прямые аргументы типизированы в extended method types:

```
registerPlaceholderForReference:  v32@0:8@"MIAppReference"16@?<v@?@"LSRecordPromise"@"NSError">24
referencesForBundleWithIdentifier: v40@0:8@"NSString"16Q24@?<v@?@"NSDictionary"@"NSError">32
triggerRegistrationFor…Options:   v32@0:8@"ICLRegistrationOptions"16@?<v@?@"NSError">24
checkCapabilities:               v40@0:8@"NSObject"16@"NSDictionary"24@?<v@?@"NSDictionary"@"NSError">32
getPidForTesting:                v24@0:8@?<v@?i>16
```

Прямые классы (`MIAppReference`, `ICLRegistrationOptions`) берутся NSXPC из сигнатуры протокола; для коллекций daemon отдельно вызывает `setClasses:forSelector:argumentIndex:ofReply:` (11 вызовов в `0x100004ae0`), например `ICLBundleRecord`, `ICLUninstallRecord`, `NSURL` внутри `NSSet`.

---

## 2. Механика гейтов

### 2.1 `allowedSPI`

`_ValidateMIAllowedSPIEntitlement(self, key)` — `0x10001c7c4`:

```
0x10001c7fc  bl   xpcConnection
0x10001c81c  bl   valueForEntitlement:@"com.apple.private.mobileinstall.allowedSPI"
0x10001c840  isKindOfClass:NSString  -> 0x10001c850 isEqualToString:key
0x10001c8b0  isKindOfClass:NSArray   -> 0x10001c8c0 containsObject:key
0x10001c8d0  error "Process %@ is required to have an entitlement named ..."
```

Возврат — `NSError *` (nil = доступ разрешён). Значение может быть строкой **или** массивом. Проверка идёт по audit token соединения (`-[NSXPCConnection valueForEntitlement:]`), подделать нельзя.

### 2.2 Булев энтайтлмент

`sub_10001e40c(self, key)`:

```
0x10001e430  bl   xpcConnection
0x10001e448  bl   valueForEntitlement:key
0x10001e458  bl   0x10001a86c
```

`0x10001a86c` возвращает `[value boolValue]` только если value — `NSNumber`, иначе 0. Этим проверяются `com.apple.private.installcoordinationd.daemon`, `com.apple.private.coreservices.lsd`, `com.apple.usermanagerd.persona.fetch`, `UnitTestRunner`.

### 2.3 Сколько методов и где гейт

- В `MobileInstallerProtocol` — **75** методов; все реализованы в `MIClientConnection` (плюс 22 приватных/аксессоров, всего 97).
- Прямой `bl` к `0x10001c7c4` — 50 точек (из них 7 — новые replacement-вызовы 27.2); `bl` к `0x10001e40c` — 23 точки для остальных энтайтлментов.
- Пять методов (`installURL`, `stageInstallURL`, `revertIdentity`, `uninstallIdentifiers`, `uninstallIdentity`) не имеют гейта в своём теле, но **безусловно** уходят в gated-калькуляции:
  - `installURL:` `0x10001bf74` → `_installURL:` `0x10001e488` → `_validateInstallRequestForURL:` `0x10001dfd0` → `bl 0x10001c7c4("InstallForInstallCoordination")` `0x10001e06c`; при непустом URL гейт безусловен (`0x10001e05c–0x10001e074`). Дополнительно: `InstallLocalProvisioned`, если `options.allowLocalProvisioned` (`0x10001e090`), и `com.apple.private.installcoordinationd.daemon`, если задан `LinkedParentBundleID` (`0x10001e0c0`).
  - `stageInstallURL:` `0x10001ec38` → тот же `_validateInstallRequestForURL:` `0x10001ecbc`.
  - `revertIdentity:` `0x10001f850` → `revertForIXWithIdentity:` `0x10001f8d8` (`RevertForInstallCoordination`).
  - `uninstallIdentifiers:`/`uninstallIdentity:` → `_uninstallIdentities:` (гейт `UninstallForInstallCoordination`).

---

## 3. Шесть методов без гейта

| # | Селектор | Адрес | Гейт | Аргументы (ext type) | Возврат | Вердикт |
|---|---|---|---|---|---|---|
| 1 | `triggerRegistrationForContainerizedContentForOptions:withCompletion:` | `0x10002c2a0` → `_triggerRegistrationForContent:` `0x10002bcc0` | **нет** | `ICLRegistrationOptions` | `NSError` | **произвольный `targetUID` → LS scan/register для 0/чужого uid; DoS** |
| 2 | `triggerRegistrationForDiskImageContentForOptions:withCompletion:` | `0x10002c2b4` → тот же | **нет** | `ICLRegistrationOptions` | `NSError` | то же, контент = disk image |
| 3 | `registerPlaceholderForReference:completion:` | `0x10001d394` | **нет**; только `ICLFeatureFlags.appReferencesEnabled` `0x10001d470` | `MIAppReference` | `LSRecordPromise`, `NSError` | **forged reference: data-контейнеры + `AppReferences` в чужом bundle-контейнере + LS-запись `isPlaceholder=1`** |
| 4 | `referencesForBundleWithIdentifier:inDomain:completion:` | `0x1000286d4` | **нет**; только `appReferencesEnabled` `0x10002870c` | `NSString`, `Q` | `NSDictionary` | **утечка `{uid → personas}` по любому bundle id; для domain != 3 — по всем пользователям** |
| 5 | `checkCapabilities:withOptions:completion:` | `0x10002592c` | **нет** | `NSObject`, `NSDictionary` | `NSDictionary` | только `UIRequiredDeviceCapabilities`; безопасно |
| 6 | `getPidForTestingWithCompletion:` | `0x10002b4e4` | **нет** | — | `int` | pid installd; безопасно |

**Кто допускается:** все шесть — **любой процесс под профилем `container`**, без bundle id/team id/энтайтлмента. Ограничение только одно: #3 и #4 дополнительно требуют включённого feature-флага `MI_App_References` (`os_feature_enabled_impl("InstalledContentLibrary", "MI_App_References")`, `+[ICLFeatureFlags appReferencesEnabled]` `0x1ab4efb84`); состояние флага на 27.2 в рантайме не проверялось.

### 3.1 Остальные 69 методов (для контраста)

| Гейт | Методы |
|---|---|
| `allowedSPI = InstallForInstallCoordination` | `installURL:`*, `stageInstallURL:`*, `installParallelPlaceholderForStagedIdentifier:`, `finalizeStagedInstallForIdentifier:`, `cancelUpdateForStagedIdentifiers:`, `allStagedUpdatesWithCompletion:`, `finalizeReference:`, `acquireReferenceforInstalledAppWithIdentity:…`, `invalidateReference:` |
| `RevertForInstallCoordination` | `revertIdentity:`* |
| `UninstallForInstallCoordination` | `uninstallIdentifiers:`*, `uninstallIdentity:`* |
| `LookupUninstalled` / `ClearUninstalled` | `lookupUninstalledWithOptions:`, `clearUninstalledIdentifiers:` |
| `LookupSystemAppState` / `UpdateSystemAppState` | `lookupSystemAppStateWithOptions:`, `updateSystemAppStateForIdentifier:appState:` |
| `CopyFrameworkInfoForLaunchServices` / `CopyContainerizedAppInfoForLaunchServices` / `CopyDiskUsageForLaunchServices` / `EnumerateInstalledAppsForLaunchServices` | `fetchInfoForFrameworkAtURL:`, `fetchInfoForContainerizedAppWithIdentity:`, `fetchDiskUsageForIdentifiers:`, `enumerateInstalledAppsWithOptions:` |
| `GetAppMetadata` | `getAppMetadataForApp:` |
| `UpdateSinfForInstallCoordination` / `UpdateiTunesMetadataForInstallCoordination` | `updateSinfForIXWithIdentifier:`, `updateiTunesMetadataForIXWithIdentifier:` |
| `RegisterSafeHarbor` / `RemoveSafeHarbor` / `CopySafeHarbors` | `registerSafeHarborAtPath:`, `removeSafeHarborForIdentity:`, `listSafeHarborsOfType:` |
| `UpdatePlaceholderMetadata` | `updatePlaceholderMetadataForApp:` |
| `SnapshotWKApp` / `CreateSerializedPlaceholder` / `SetLaunchWarning` | `snapshotWKAppInCompanionAppID:`, `cloneSerializedPlaceholderForInstalledAppWithBundeID:`, `setLaunchWarningForApp:` |
| `Store/FetchListOfAppsRequiringPreInstallConsent` | `storeListOfAppsRequiringPreInstallConsent:`, `fetchListOfAppsRequiringPreInstallConsent:` |
| `Set/GetSystemAppMigrationStatus`, `WaitFor…` | `setSystemAppMigrationComplete:`, `waitForSystemAppMigratorToComplete:`, `systemAppMigratorHasCompleted:` |
| `UnitTestRunner` | `dieForTesting`, `raiseExceptionWithCompletion:`, `set/get/endTestMode`, `set/clearTestFlags`, `setEligibilityTestOverrides:`, `appBundleIDsWithPersona:` |
| `UnitTestRunner` + `com.apple.private.coreservices.lsd` | `rebuildBuiltInContentMapping` |
| `com.apple.private.installcoordinationd.daemon` | `register/unregister/reconcileContents…` (7 методов), все persona-мутации (`add/remove/setPersonas`, `enrollPersona`, `add/remove/setDataSeparatedApps`), `reportPersonaLifecycleEvent`, `linkedBundleIDsForAppIdentity:` |
| `com.apple.private.coreservices.lsd` + `com.apple.usermanagerd.persona.fetch` | `personasForBundleID:`, `personasForBuiltInBundleID:` |
| `PrepareAppReplacement` / `SetAppReplacementStatus` / `SetAppLaunchProhibited` / `RemoveAppReplacementState` | шесть replacement-методов 27.2 |

\* гейт в вызываемом валидаторе/калькуляции, не в теле самого селектора.

---

## 4. Разбор ungated-методов

### 4.1 `triggerRegistrationFor*` — произвольный targetUID

`triggerRegistrationForContainerizedContentForOptions:withCompletion:` — `0x10002c2a0`:

```
0x10002c2a0  mov x5, x3        ; completion
0x10002c2a4  mov x3, x2        ; options
0x10002c2a8  mov w2, #4        ; content = containerized
0x10002c2ac  mov w4, #1        ; writeLock = YES
0x10002c2b0  b   _triggerRegistrationForContent:registrationOptions:writeLock:withCompletion:
```

`0x10002bcc0`:

```
0x10002bcec  bl   objc_retain_x3        ; options
0x10002bd38  mov  x0, x19
0x10002bd3c  bl   [options targetUID]  ; <-- клиентское значение, без проверки
0x10002bd40  mov  x24, x0
...
0x10002befc  bl   [gatherer initWithOptions:forTargetUID:x24 enumerator:block]
...
0x10002c13c  ldr  w2, [x23, #0x28]      ; targetUID из gatherer
0x10002c140  bl   [NSNumber numberWithUnsignedInt:]
0x10002c154  bl   [LSOperationRequestContext setTargetUserID:]
0x10002c1a8  bl   [LSApplicationWorkspace registerApplicationForRebuildWithInstallationRecord:
                    extensionInstallationRecords:personaUniqueStrings:requestContext:registrationError:]
```

`ICLRegistrationOptions` (`InstalledContentLibrary`) — `NSObject <NSSecureCoding, NSCopying>` с единственным полем `unsigned int _targetUID` и `-initWithTargetUID:`; `initWithCoder:`/`encodeWithCoder:` синтезированы. Ни `MIIsValidInstallationDomain`, ни сверки с euid клиента, ни `targetUID != 0` в `_triggerRegistrationForContent` нет. `writeLock` только берёт файловый lock (`0x10006c564`/`0x10006c56c`), не ограничивает uid.

**Что может приложение:** вызвать полный скан контента и `registerApplicationForRebuild…` с `targetUserID = 0` (system/root LS) или uid другого пользователя. Подтверждено кодом: значение `targetUID` идёт в `LSOperationRequestContext`. Не подтверждено: что LS примет запись для uid 0/чужого пользователя и какие именно контейнеры просканирует gatherer; фактический эффект (порча LS, исчезновение/появление app, отказ запуска) на устройстве не измерялся. Ресурсоёмкость и отсутствие рейт-лимита — очевидны: каждый вызов запускает полный gather + LS save под `writeLock`.

`triggerRegistrationForDiskImageContentForOptions:` — `0x10002c2b4`, тот же путь с `content = 0x10` и `writeLock = NO` (disk image).

### 4.2 `registerPlaceholderForReference:` — forged `MIAppReference`

`0x10001d394`. Ключевые точки:

```
0x10001d454  [reference identity]
0x10001d470  [ICLFeatureFlags appReferencesEnabled]   ; иначе error "%s is not enabled"
0x10001d484  [identity bundleID]
0x10001d4d4  [MIBundleContainer appBundleContainerForIdentifier:bundleID inDomain:domain withError:]
0x10001d510  [container bundle]
0x10001d548  [identity resolvePersonaWithError:]
0x10001d5cc  [dataContainerForExecutableBundle:forPersona:createIfNeeded:YES temporary:NO ...]
0x10001d624  [bundle appExtensionBundlesWithError:]
0x10001d6c4  [dataContainersCreatingIfNeeded:parentPersona:…]   ; контейнеры расширений
0x10001d754  [MIInstalledInfoGatherer initWithBundleContainer:forPersona:]
0x10001d77c  [gatherer bundleRecordWithError:]
0x10001d7bc  [record setIsPlaceholder:1]
0x10001d7f8  [reference.identity bundleID]
0x10001df40  [MILaunchServicesOperationManager registerInstalledInfo:forIdentity:inDomain:error:]
```

`registerInstalledInfo:forIdentity:inDomain:error:` (`0x100062328`) вызывает:

```
0x100062374  addReferenceForIdentity:inDomain:forUserWithID:resultingPersonaUniqueStrings:error:
0x100062488  _registerInstalledInfo:forAppBundleID:personas:inDomain:error:
```

`addReferenceForIdentity:` (`0x10006ca3c`) снова резолвит контейнер **по `identity.bundleID`** и пишет reference:

```
0x10006ca84  [identity bundleID]
0x10006caa4  [MIBundleContainer appBundleContainerForIdentifier:inDomain:]
0x10006cac8  [identity personaUniqueString]
0x10006caf4  addReferenceForUserWithID:personaUniqueString:byRemovingTemporaryReference:
             inBundleContainer:resultingPersonaUniqueStrings:error:
```

`_referenceURLForUserWithID:inBundleContainer:` (`0x10006d140`) строит путь от `bundleContainer.referenceStorageURL` + `"AppReferences"` + `"user_%d/%@"` (`0x10006d158–0x10006d180`); `personaUniqueString` и `referenceUUID` в путь **не** попадают.

**Чего нет:** вызова `+[MIAppReference validateAppReference:withError:]` (он есть только в `finalizeReference:` `0x10002783c`) и сверки `reference.uid`/`reference.domain` с клиентом. `identity.location` для резолва контейнера не используется; контейнер ищется по `bundleID` + `domain`. `domain` не валидируется `MIIsValidInstallationDomain` (в отличие от `installURL`).

**Эффект:** для любого **уже установленного** app (user или system, если контейнер доступен) клиент может:
1. создать отсутствующие data-контейнеры (правами installd: `_installd` + container-entitlements) — запись в контейнер цели;
2. добавить `AppReferences/user_<uid>/…` в **bundle-контейнер цели** с клиентской persona-строкой; `forUserWithID` — это `UMUserManager.currentUser.uid` (`MIFetchUIDForRegistration`, `0x10000a818` / кэш `0x10000a7e0`), т.е. текущий пользователь устройства, а не произвольный uid;
3. попытаться зарегистрировать LS-запись цели с `isPlaceholder = YES`.

Пункт 3 — потенциальный перевод чужого app в placeholder (нерабочий/«ожидает загрузки») и/или порча его LS-записи. Перезаписывает ли LS существующую запись — **не подтверждено**; если LS отвергает дубликат, остаются только (1) и (2). Запись `AppReferences` в чужой контейнер подтверждена кодом; её содержимое — plist `MIAppReferenceMetadata` с массивом persona-строк, не произвольные байты.

Возврат — `LSRecordPromise` (обещание LS-записи). Что именно в нём сериализуется (bundleID/URL/флаги) — не проверялось; возможен путь bundle-контейнера цели, но это не подтверждено.

### 4.3 `referencesForBundleWithIdentifier:inDomain:` — межпользовательский lookup

`0x1000286d4`:

```
0x10002870c  [ICLFeatureFlags appReferencesEnabled]   ; иначе error
0x10002871c  [MIAppReferenceManager defaultManager]
0x10002873c  [manager referencesForIdentifier:identifier inDomain:domain error:]
0x10002876c  completion(result, nil)
```

`-[MIAppReferenceManager referencesForIdentifier:inDomain:error:]` — `0x10006e3f8`:

```
0x10006e450  [UMUserManager sharedManager]
0x10006e454  [UMUserManager allUsers]                 ; <-- все пользователи
0x10006e4cc  cmp domain, #3
0x10006e4d4  cmp currentUser.uid, user.uid           ; для domain==3 чужой uid пропускается
0x10006e45c  bl  MIFetchUIDForRegistration (0x10000a7e0) ; currentUser.uid
0x10006e4f4  [self personaUniqueStringsForAppWithBundleID:domain:forUserWithID:user.uid error:]
0x10006e538  [dict setObject:personaSet forKeyedSubscript:@(uid)]
0x10006e5ac  [dict copy]                              ; возврат NSDictionary
```

`personaUniqueStringsForAppWithBundleID:…` (`0x10006e680`) резолвит `MIBundleContainer` по bundle id/domain и читает `AppReferences/user_<uid>/…` из **bundle-контейнера** (если контейнер общий, как на Shared iPad, reference-файлы разных uid лежат в нём рядом). Возврат — `NSDictionary` `{NSNumber(uid) → NSSet(NSString persona)}`.

**Утечка:** любой app может по произвольному bundle id узнать:
- установлен ли app (ошибка «Failed to locate container» vs пустой/непустой словарь);
- для каждого uid — какие persona-строки имеют reference на этот app (Personal/Managed и т.п.);
- косвенно — какие пользователи/персоны присутствуют на устройстве (для `domain != 3`).
**Не отдаёт:** пути контейнеров, UUID, `MIBundleMetadata`, entitlements, содержимое файлов. Это metadata-only oracle, не чтение чужих данных.

### 4.4 `checkCapabilities:` и `getPidForTesting`

`checkCapabilities:` `0x10002592c` → `-[MICapabilitiesManager checkCapabilities:withOptions:error:]` (`InstalledContentLibrary` `0x1ab4e2670`): проверка `UIRequiredDeviceCapabilities` (ключи `CapabilitiesMatch`, `MismatchedCapabilities`, denylist app). Возврат — `NSDictionary`; пути/файлы не читает.

`getPidForTesting` `0x10002b4e4`: `getpid()` → completion(int). Утечки нет.

---

## 5. Пути, bundle id, TOCTOU

| Вопрос | Ответ |
|---|---|
| Принимает ли какой-либо ungated-метод путь/URL от клиента? | Нет. `MIAppReference.identity.location` — единственный URL в аргументах #3, но контейнер резолвится по `bundleID`, `location` в `appBundleContainerForIdentifier:` не передаётся. `resolvePersonaWithError:` может консультировать location — не подтверждено, но результат не путь и наружу не возвращается. |
| Строится ли путь из клиентского bundle id? | Нет. `bundleID` — ключ поиска `MIBundleContainer`; путь контейнера — UUID-based, выдаётся объектом контейнера. Reference-путь = `referenceStorageURL` + фиксированные `"AppReferences"`, `"user_%d"`, константа. |
| Есть ли `..`/symlink-выход? | Не найдено. Нет `stringByAppendingPathComponent:` от клиентской строки, нет `fileURLWithPath:` от клиента, нет `realpath`/`standardizedURL` от клиента. `validateSymlinksInURLDoNotEscapeURL:` в этих путях не вызывается, потому что клиентского URL нет. |
| TOCTOU? | Между проверкой и использованием нет пары «проверили клиентский путь → открыли его». Контейнер резолвится один раз и используется как объект. Теоретическая гонка «app удалён между lookup и записью» есть у #3, но она не даёт выхода за пределы контейнера цели. |
| Сверяется ли bundle id с клиентом? | Нет и не может: у приложения нет «своего» bundle id в этих методах; listener не передаёт identity клиента. #4 принимает любой bundle id; #3 — любой установленный. |
| Порядок «гейт vs декодирование» | NSXPC декодирует аргументы **до** вызова метода, т.е. для gated-методов клиентские `NSSecureCoding`-графы (`MIAppIdentity`, `MIInstallOptions`, `MIStoreMetadata`, `MIAppReference`) декодируются до `allowedSPI`-проверки. Это отдельный класс риска (deserialization), в этой работе не исследован. |

---

## 6. Что приложение может и не может без энтайтлментов

**Может:**
1. Подключиться к `com.apple.mobile.installd` и вызвать 75 методов протокола; 69 вернут ошибку гейта, 6 выполнятся.
2. `referencesForBundleWithIdentifier:` — узнать наличие app и `{uid → personas}` по любому bundle id (metadata-only, межпользовательская утечка на Shared iPad).
3. `registerPlaceholderForReference:` — для любого установленного app: создать data-контейнеры, записать `AppReferences` в его bundle-контейнер, попытаться зарегистрировать его как placeholder (inter-app запись; фактический LS-эффект не подтверждён).
4. `triggerRegistrationFor*` — запустить полный gather + LS-регистрацию с произвольным `targetUID` (0/чужой), без рейт-лимита → cross-uid LS-запись/DoS.
5. `checkCapabilities:` — device capability oracle; `getPidForTesting` — pid installd.

**Не может (через эти методы):**
- установить/удалить/заменить/revert app — `allowedSPI`;
- прочитать содержимое чужого файла, метаданные бандла, UUID/путь контейнера (подтверждённо — нет; `LSRecordPromise` не проверен);
- записать произвольный файл/байты в чужой контейнер — только `AppReferences`-plist и data-контейнеры;
- выйти за пределы контейнера через `..`/symlink — не найдено;
- подделать `allowedSPI`/`installcoordinationd.daemon`/`lsd` — проверка по audit token соединения.

---

## 7. Не подтверждено

1. Реальный вызов с устройства (нет рантайм-теста): sandbox-разрешение и код-пути подтверждены статически; фактическое поведение NSXPC-кодирования `MIAppReference`/`ICLRegistrationOptions` из обычного app не проверялось.
2. Состояние feature-флага `MI_App_References` на 27.2 (если выключен — #3/#4 вернут «is not enabled»).
3. Перезаписывает ли LS существующую запись при `registerPlaceholderForReference:` с `isPlaceholder=YES`; становится ли чужой app нерабочим.
4. Что именно содержит `LSRecordPromise` (bundle URL/флаги) и декодируется ли он клиентом.
5. Поведение LS при `targetUID = 0`/чужом uid: примет ли запись, какие контейнеры просканирует gatherer, возможна ли порча LS/исчезновение app.
6. Доступность на запись bundle-контейнеров системных app и контейнеров других пользователей (rootfs/cryptex/read-only).
7. `MIAppIdentity.resolvePersonaWithError:` — использует ли `location` для файловых операций (в контейнерном резолве location точно не участвует).
8. Многопользовательский сценарий Shared iPad вживую (общий ли bundle-контейнер, видны ли `user_<uid>`-reference других пользователей).
9. Не исследованы декодеры `MIAppIdentity`/`MIInstallOptions`/`MIStoreMetadata` в gated-методах (deserialization до гейта).

---

## 8. Приложение: адреса

| Что | Адрес |
|---|---|
| listener / accept | `0x10001b280` |
| `setExportedInterface` (protocol) | `0x100004ae0`; protocol_t `0x1000d6530` |
| `_ValidateMIAllowedSPIEntitlement` | `0x10001c7c4` |
| булев энтайттлмент-хелпер | `0x10001e40c` (bool-конверсия `0x10001a86c`) |
| `_validateInstallRequestForURL:` | `0x10001dfd0` (гейт `0x10001e06c`) |
| `installURL:` → `_installURL:` | `0x10001bf74` → `0x10001e488` |
| `stageInstallURL:` | `0x10001ec38` (валидатор `0x10001ecbc`) |
| `registerPlaceholderForReference:` | `0x10001d394` |
| `referencesForBundleWithIdentifier:` | `0x1000286d4` |
| `triggerRegistrationForContainerizedContent…` | `0x10002c2a0` |
| `_triggerRegistrationForContent:…` | `0x10002bcc0` (`targetUID` `0x10002bd3c`, `setTargetUserID:` `0x10002c154`) |
| `checkCapabilities:` | `0x10002592c` → ICL `0x1ab4e2670` |
| `getPidForTesting` | `0x10002b4e4` |
| `MIAppReferenceManager referencesForIdentifier:` | `0x10006e3f8` (`allUsers` `0x10000a8b4`, domain==3 `0x10006e4cc`) |
| `MIAppReferenceManager addReferenceForIdentity:` | `0x10006ca3c` |
| `_referenceURLForUserWithID:` | `0x10006d140` (`AppReferences` `0x10006d158`, `user_%d/%@` `0x10006d160`) |
| `MILaunchServicesOperationManager registerInstalledInfo:` | `0x100062328` (`addReference` `0x100062374`, `_registerInstalledInfo` `0x100062488`) |
| `MIInstalledInfoGatherer` + `setIsPlaceholder:` | `0x10001d754`, `0x10001d7bc` |

---

## 9. Эскиз проверки (не запускался)

```objc
// app, iOS 27.2; только для проверки гипотезы
NSXPCConnection *c = [[NSXPCConnection alloc] initWithMachServiceName:@"com.apple.mobile.installd"
                                                             options:0];
c.remoteObjectInterface = [NSXPCInterface interfaceWithProtocol:@protocol(MobileInstallerProtocol)];
[c resume];
id proxy = [c remoteObjectProxyWithErrorHandler:^(NSError *e) { NSLog(@"%@", e); }];

// 1) metadata leak: любой bundle id
[proxy referencesForBundleWithIdentifier:@"com.apple.Preferences" inDomain:2
                              completion:^(NSDictionary *refs, NSError *e) {
    NSLog(@"uid->personas: %@ err %@", refs, e);
}];

// 2) forge an ICLRegistrationOptions with targetUID=0 and trigger LS rebuild
//    (class name в архиве — ICLRegistrationOptions; ivar targetUID)
id opts = [self forgedRegistrationOptionsWithUID:0];
[proxy triggerRegistrationForContainerizedContentForOptions:opts
                                             withCompletion:^(NSError *e) {
    NSLog(@"trigger err %@", e);
}];

// 3) forge MIAppReference{identity{bundleID, persona}, domain} and register placeholder
//    (validateAppReference: не вызывается)
[proxy registerPlaceholderForReference:forgedRef
                            completion:^(id recordPromise, NSError *e) {
    NSLog(@"promise %@ err %@", recordPromise, e);
}];
```

Проверять на одноразовом устройстве/симуляторе с восстановлением из IPSW: пункт 3 меняет LS-состояние цели, пункт 2 — гоняет полный LS gather.

---

## 10. Итог одной строкой

**Без энтайтлментов приложение получает: metadata-lookup по любому bundle id (personas/uid), forged-reference запись в bundle-контейнер чужого установленного app с попыткой сделать его placeholder, и LS-перерегистрацию контента с произвольным targetUID; установка/удаление/замена и чтение чужих файлов остаются закрыты.**
