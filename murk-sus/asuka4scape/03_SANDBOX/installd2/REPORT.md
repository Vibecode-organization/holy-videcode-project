# installd 27.2 — app replacement: побег из песочницы через userland

**Дата:** 2026-10-29  
**Объект:** `/usr/libexec/installd`, iOS 27.2 (24B115), arm64e  
**Бинарники:**
- 27.2 — `/home/femboychik/work/root272/installd`, 961 888 Б, sha256 `408906e8625f927a9165a13ec07398e4a21f7e1dd60d1ad385d17801bd0fdf06`, UUID `384C904B-F540-3E5E-9F23-F16A7C0059C5`, source `1680.40.14.0.0`
- 27.0 — `/home/femboychik/work/root270/installd`, 928 032 Б, sha256 `cb3897fb328fc177d3e11f28b2e9c018f52835cd9f06359717e472692e90b3fe`

**Инструменты:** `ipsw 3.1.736` (macho disass/class-dump/dyld extract/str), `capstone 5.0.7`, `llvm-objdump`, `ldid-amd64 -e`, `7z 26.03` (APFS), Python 3.  
**Стенд:** `root272` / `root270`, root FS `rc115/out272_clean/141-10327-211.dmg`, sandbox-профили `sb272/` (`all.json`, `baseline.sb`, `installd.sb`), DSC `rc115/dsc272`.

---

## 0. Вердикт в одну строку

**Нового достижимого из обычного приложения входа нет.** Весь app replacement в 27.2 закрыт теми же `com.apple.private.mobileinstall.allowedSPI`, что и установка; четыре ключа replacement-а (`PrepareAppReplacement`, `SetAppReplacementStatus`, `SetAppLaunchProhibited`, `RemoveAppReplacementState`) из проверенных бинарников есть только у `installcoordinationd`. Песочница приложения вообще не выпускает mach-lookup к `com.apple.mobile.installd`: в `baseline.sb` стоит `(deny mach-lookup)`, allow-листа с этим именем нет. Внутри `prepareWithError` нет проверки, что замещаемое приложение действительно названо в `com.apple.developer.superseded-application-identifiers` — проверка только «массив непустой»; авторитет пары целиком вынесен в `installcoordinationd`/подпись Apple.

---

## 1. XPC-поверхность installd

### 1.1 Listener

`-[MobileInstallationServiceDelegate listener:shouldAcceptNewConnection:]` — `0x10001b280`:

```
0x10001b2c0  objc_opt_new(class_MIClientConnection)
0x10001b2d0  setExportedObject:
0x10001b2f8  setXpcConnection:
0x10001b320  resume
0x10001b32c  mov w0, #1          ; accept
```

Ни audit-token, ни проверки энтайтлментов на входе. **Любой процесс, которому песочница разрешила lookup, получает соединение**; весь контроль — per-method внутри `MIClientConnection`.

Launchd-плист (`System/Library/LaunchDaemons/com.apple.mobile.installd.plist`) регистрирует ровно один Mach-сервис `com.apple.mobile.installd`, пользователь `_installd`. Строка `com.apple.mobile.installd0` в бинаре встречается, но launchd её не публикует.

### 1.2 Центральный гейт allowedSPI

`sub_10001c7c4` (`_ValidateMIAllowedSPIEntitlement(self, selectorName)`) — `0x10001c7c4`:

```
0x10001c7fc  bl   j__objc_msgSend(self, "xpcConnection")
0x10001c81c  valueForEntitlement:@"com.apple.private.mobileinstall.allowedSPI"
0x10001c840  isKindOfClass:NSString   -> 0x10001c850 isEqualToString:<key>
0x10001c8b0  isKindOfClass:NSArray    -> 0x10001c8c0 containsObject:<key>
0x10001c8d0  иначе error:
0x10001c908  "Process %@ is required to have an entitlement named \"%@\" with an array
              containing \"%@\" to call the MobileInstallation SPI."
```

То есть значение `allowedSPI` может быть **строкой** (равной ключу) или **массивом** (содержащим ключ). Ошибка возвращается как `MIInstallerErrorDomain`; вызывающий метод сразу уходит в completion с ошибкой.

### 1.3 Новые replacement-методы и их гейты

В 27.2 в `MIClientConnection` 97 методов (в 27.0 — 91). Шесть новых, все gated:

| XPC-селектор | адрес | гейт (ключ allowedSPI) | адрес `bl` гейта |
|---|---|---|---|
| `prepareReplacementOfApp:byApp:extensionBundleIDs:withCompletion:` | `0x10002d158` | `PrepareAppReplacement` | `0x10002d1d4` |
| `setLaunchProhibited:forApp:withCompletion:` | `0x10002d9e0` | `SetAppLaunchProhibited` | `0x10002da88` |
| `pushReplacementInfoForApp:replacingApp:withCompletion:` | `0x10002e040` | `SetAppLaunchProhibited` | `0x10002e0e4` |
| `setAppReplacementStatus:forApp:replacingApp:completion:` | `0x10002e55c` | `SetAppReplacementStatus` | `0x10002e5c0` |
| `endAppReplacementWithStatus:forApp:completion:` | `0x10002ea70` | `SetAppReplacementStatus` **и** `SetAppLaunchProhibited` | `0x10002eb18`, `0x10002eb50` |
| `removeAppReplacementStateForApp:completion:` | `0x10002f1f0` | `RemoveAppReplacementState` | `0x10002f240` |

Пример (prepare):

```
0x10002d1c8  adrp x1, ...
0x10002d1cc  add  x1, x1, #0x3b0 ; "PrepareAppReplacement"
0x10002d1d4  bl   0x10001c7c4
0x10002d1d8  bl   j__objc_claimAutoreleasedReturnValue
0x10002d1dc  cbz  x0, ...          ; non-nil -> сразу error в completion
```

`endAppReplacement` требует **оба** ключа: сначала `SetAppReplacementStatus`, затем `SetAppLaunchProhibited`.

### 1.4 Остальные точки входа

Полный автомат по `bl 0x10001c7c4`: 50 вызовов в 27.2 (43 в 27.0), ровно +7 — новые replacement-методы (`end` даёт два вызова). Ключи общих методов не изменились; новых имён ключей только четыре — replacement. Список общих ключей: `InstallForInstallCoordination`, `RevertForInstallCoordination`, `UninstallForInstallCoordination`, `LookupUninstalled`, `ClearUninstalled`, `LookupSystemAppState`, `UpdateSystemAppState`, `EnumerateInstalledAppsForLaunchServices`, `CopyFrameworkInfoForLaunchServices`, `CopyContainerizedAppInfoForLaunchServices`, `UpdateSinfForInstallCoordination`, `UpdateiTunesMetadataForInstallCoordination`, `CopyDiskUsageForLaunchServices`, `RegisterSafeHarbor`, `RemoveSafeHarbor`, `CopySafeHarbors`, `UpdatePlaceholderMetadata`, `GetAppMetadata`, `SnapshotWKApp`, `Set/GetSystemAppMigration*`, `Store/FetchListOfAppsRequiringPreInstallConsent`, `CreateSerializedPlaceholder`, `SetLaunchWarning`, `InstallLocalProvisioned`, `UnitTestRunner`, `com.apple.private.coreservices.lsd`.

Методы **без** `allowedSPI` и без иного энтайтлмента в теле (проверено сканом диапазона):

| метод | адрес | что делает | достижимость |
|---|---|---|---|
| `getPidForTesting` | `0x10002b4e4` | отдаёт pid installd | sandbox: lookup запрещён |
| `referencesForBundleWithIdentifier:inDomain:` | `0x1000286d4` | список `MIAppReference` по bundle id | sandbox |
| `checkCapabilities:withOptions:` | `0x10002592c` | `checkCapabilities:withOptions:error:` | sandbox |
| `registerPlaceholderForReference:` | `0x10001d394` | регистрирует LS-placeholder по `MIAppReference`; пути из клиента не берет (`appBundleContainerForIdentifier:`, `dataContainerForExecutableBundle:`) | sandbox |
| `_triggerRegistrationForContent:...` / `triggerRegistrationForContainerizedContent…` / `...DiskImageContent…` | `0x10002bcc0` | LS-database gatherer (`initWithOptions:forTargetUID:enumerator:`) | sandbox |

Отдельные гейты вне `allowedSPI`:

- `com.apple.private.installcoordinationd.daemon` — `installURL` при `linkedParentBundleID`, все persona-операции, `register/unregister/reconcileContents*`, `add/remove/setDataSeparatedApps`, `linkedBundleIDs`.
- `com.apple.private.coreservices.lsd` — `personasForBundleID:`, `personasForBuiltInBundleID:`, `rebuildBuiltInContentMapping`.
- `com.apple.private.MobileInstallationHelperService.allowed` — accept-гейт отдельного XPC-сервиса `com.apple.MobileInstallationHelperService` (см. 1.6).

### 1.5 Песочница: почему из app не достучаться

`sb272/baseline.sb` (общая база; app-профиль её включает):

```
строка 8:     (deny default)
строка 7600:  (deny mach*)
строка 7779:  (deny mach-lookup)
```

Allow-листы `mach-lookup` в baseline перечисляют `com.apple.mobile.usermanagerd.xpc`, `com.apple.pluginkit.pkd`, `com.apple.system.logger` и т.п. **`com.apple.mobile.installd` там отсутствует.** В `sb272/all.json` (293 профиля) имя `com.apple.mobile.installd` встречается только в 10 daemon-профилях: `AirTraffic`, `CommCenter`, `appconduitd`, `appstored`, `com.apple.bird`, `container`, `gamed`, `lockdownd`, `maild`, `streaming_zip_conduit`. Ни одного app-профиля.

Итог: обычное приложение не может даже открыть соединение с installd; `allowedSPI`-гейт — вторая стена, а не первая.

### 1.6 Кто реально держит replacement-SPI

`ldid -e` по бинарникам из того же root FS (проверены все daemon-клиенты installd из `all.json`, кроме `container`/`AirTraffic`/`CommCenter` — их бинарники не извлекались):

- `installcoordinationd` — единственный **из проверенных** с полным набором:
  ```
  PrepareAppReplacement
  SetAppReplacementStatus
  SetAppLaunchProhibited
  RemoveAppReplacementState
  ```
  плюс `com.apple.private.installcoordinationd.daemon`, `MobileInstallationHelperService.allowed`, `InstallCoordinationDaemonOpsEnabled`.
- `appstored` — `InstallForLaunchServices`, `UninstallForLaunchServices`, `CheckCapabilitiesMatch`.
- `gamed` — `UninstallForLaunchServices`, `Lookup`, `Uninstall`.
- `streaming_zip_conduit` — `InstallForLaunchServices`, `InstallLocalProvisioned`.
- `bird` — `InstallForLaunchServices`, `UninstallForLaunchServices`.
- `appconduitd` — `SnapshotWKApp`, `GetAppMetadata`, `WaitForSystemAppMigrationToComplete`.
- `lockdownd` — `CopyDiskUsageForLaunchServices`.
- `maild` — `allowedSPI` нет вовсе.

Ни один из проверенных daemon-клиентов не может вызвать replacement-методы: у всех нет четырёх ключей. Даже компрометация `appstored`/`gamed` не даёт replacement. Для `container`, `AirTraffic`, `CommCenter` бинарники не извлекались — не подтверждено.

### 1.7 Helper service

`com.apple.MobileInstallationHelperService` (`MobileInstallation.framework/XPCServices/...`) — отдельный демон с опасными path-операциями (`makeSymlinkFromAppDataContainerToBundleForIdentifier:`, `moveItemInStagingLocation:atRelativePath:toDestinationURL:onBehalfOf:`, `stageItemAtURL:...`). Но accept-гейт в `-[MobileInstallationHelperServiceDelegate listener:shouldAcceptNewConnection:]` (`0x10000f158`):

```
0x10000f180  add  x22, x22, #0xeb0 ; "com.apple.private.MobileInstallationHelperService.allowed"
0x10000f188  bl   valueForEntitlement:
0x10000f254  ; "connection attempt from %@ (pid %d) missing entitlement: %@"
```

`allowed` есть у installd и installcoordinationd; у appstored/appconduitd/streaming_zip_conduit его нет. В песочнице app имени сервиса тоже нет. Из app недостижим.

---

## 2. `MIAppReplacementOperation`

### 2.1 Карта объекта

`initWithAppIdentity:replacingAppWithIdentity:extensionBundleIDs:` (`0x1000189c0`):

```
+0x08  appIdentity            = arg2  (byApp, НОВОЕ приложение)
+0x10  sourceAppIdentity      = arg3  (app, СТАРОЕ, чьи данные забирают)
+0x18  extensionBundleIDsBySourceExtensionBundleID (copy)
+0x20  pendingInstallationHoldsByBundleID
```

Маппинг подтверждён вызовом из `MIClientConnection` (`0x10002d6f4`): `x2 = byApp` (arg3 метода), `x3 = app` (arg2). То есть `appIdentity` — замещающее приложение, `sourceAppIdentity` — замещаемое.

### 2.2 `prepareWithError:` — `0x100018ef0`

Последовательность (адреса — 27.2):

1. **Личности.** `sourceAppIdentity` → `[sp+0x68]`, `appIdentity` → `x21`, персона берётся из `appIdentity.personaUniqueString` → `[sp+0x48]`.
2. **Контейнер нового приложения.**
   ```
   0x100018f74  _bundleContainerForIdentity: appIdentity
   0x100018f90  bundle
   0x100018fc4  codeSigningInfoByValidatingResources:0 performingOnlineAuthorization:0
                ignoringCachedSigningInfo:0 checkingTrustCacheIfApplicable:0
                skippingProfileIDValidation:0 error:
   0x100018fe8  entitlements
   0x100018ff4  bl 0x1000617d8       ; достаёт NSArray строк по ключу
   0x100019008  count
   0x10001900c  cbz -> 0x100019438   ; пусто/не массив -> error
   ```
   `sub_1000617d8` (`0x1000617d8`) — это ровно `objectForKeyedSubscript:@"com.apple.developer.superseded-application-identifiers"` + `isKindOfClass:NSArray` + проверка «только строки». **Ничего больше.**
3. **Ошибка при отсутствии entitlements** (`0x100019438`):
   ```
   0x100019448  "com.apple.developer.superseded-application-identifiers"
   0x10001945c  "%@ cannot replace another app because it does not have a valid \"%@\" entitlement"
   ```
4. **Контейнер старого приложения** (`0x100019020`), проверка, что bundle существует (nil → `"Could not find an app bundle in the bundle container for %@"`).
5. **Запрет запуска старого приложения** (`0x1000190a8`):
   ```
   0x1000190a8  ldr x0, [sp,#0x80]    ; source bundle container
   0x1000190b0  saveAppLaunchProhibition:withError:
   ```
6. **Состояние на контейнере нового** (`0x100019120`):
   ```
   0x10001912c  w2 = 3
   0x100019134  initWithStatus:sourceAppIdentity:osBuildVersion:
   0x10001914c  saveAppReplacementState:withError:   ; x0 = dest bundle container
   ```
7. **Data-контейнеры** (`0x100019168`–`0x1000191dc`): `sourceBundle.dataContainerForPersona:` и `destBundle.dataContainerForPersona:`. Dest обязателен. Source может отсутствовать только при `MIContainerManagerErrorDomain` code `0x15`: тогда лог `"%@ has no data container left to hand over to %@, so its replacement is being resumed"` (`0x100019690`) и операция продолжается.
8. **Handover** (`0x10001978c`):
   ```
   0x10001978c  mov x0, x27     ; dest data container
   0x100019790  mov x2, x28     ; source data container
   0x100019794  supersedeExistingContainer:error:
   ```
9. **Расширения** (`0x100019894` block): для каждой пары `sourceExtBundleID -> destExtBundleID`:
   ```
   0x1000198d4  _extensionBundleWithBundleID:<key> fromExtensionBundles:<source app extensions>
   0x1000198f0  _extensionBundleWithBundleID:<value> fromExtensionBundles:<dest app extensions>
   0x100019928  _getDataContainer:... allowingAbsentContainer:1   ; source ext
   0x10001996c  _getDataContainer:... allowingAbsentContainer:0   ; dest ext
   ```
   затем тот же `supersedeExistingContainer:` на контейнерах расширений. `_getDataContainer` (`0x100018ca8`) требует ровно один контейнер на персону:
   ```
   "Expected to find only one container in persona %@ for %@; app replacement doesn't support SYSTEM/ANY persona extensions"
   ```

### 2.3 Что проверяется у «замещающего» приложения

| Проверка | Где | Есть? |
|---|---|---|
| `MIAppIdentity`, не nil | `0x10002d1f0`–`0x10002d258` | да |
| bundle id нового ≠ старого | `0x10002d2a8`; error `0x10002d2c0` | да |
| персона нового = персона старого | `0x10002d41c`; error `0x10002d780` | да |
| `extensionBundleIDs` — словарь непустых строк | `0x10002d4dc`–`0x10002d594` | да |
| расширение не заменяет само себя | `0x10002d598`–`0x10002d818` | да |
| bundle-контейнер нового существует (`createIfNeeded:0`) | `0x100018ad4`, `0x100018f78` | да |
| подпись нового: offline, **без online-auth, без resource-validation, без trust-cache** | `0x100018fc4` (все флаги 0) | да, слабая |
| `com.apple.developer.superseded-application-identifiers` — непустой массив строк | `0x100018fe4`–`0x10001900c` | да |
| **старое приложение названо в этом массиве** | — | **нет** |
| **team id / application-identifier старого = новому** | — | **нет** |
| подпись старого приложения | — | **нет** |
| `MIAppIdentity.location` / domain | — | **игнорируется** (контейнер ищется только по bundle id) |
| дубликаты значений в extension-маппинге (два source → один dest) | — | **нет** |

Валидация того же entitlement на этапе установки (`MIInstallableBundle._performAppExtensionValidationForAppBundleSigningInfo:...`, `0x100056c64`) тоже только синтаксическая: массив непустой и не содержит **собственный** application-identifier (строки `"...names the app's own application identifier..."`, `"...is set to an empty list..."`). Сверки с реально установленным замещаемым приложением в installd нет.

### 2.4 Кто и как двигает операцию

`MIClientConnection`:

- `prepare...` — типы, self-check, персона, extension-словарь, затем `init` + `prepareWithError:` + `applyInstallationHoldsWithError:` (`0x10002d700`–`0x10002d744`).
- `pushReplacementInfoForApp:replacingApp:` — пишет в LaunchServices:
  ```
  0x10002e4ec  setAppReplacementSourceBundleID:<source> forBundleID:<dest> inDomain:... error:
  ```
  Идентификаторы — из клиента, повторной проверки подписи/контейнера нет.
- `setAppReplacementStatus:forApp:replacingApp:` — резолвит bundle-контейнер по bundle id, пишет `MIAppReplacementState(status, sourceAppIdentity, osBuildVersion)`.
- `endAppReplacementWithStatus:forApp:` — резолвит контейнер по bundle id **и персоне**, снимает launch prohibition, сохраняет state.
- `removeAppReplacementStateForApp:` — удаляет state + чистит LS-записи.

Ни один из них не перепроверяет пару «кто кого замещает»; они доверяют клиенту с SPI.

Отдельно, на этапе установки (`MIInstallableBundle._setAppLaunchProhibitionWithReplacementRuledOut:`, `0x10005d378`) installd сам ставит launch prohibition приложению, у которого `sub_1000617d8(entitlements)` вернул непустой superseded-массив (`0x10005d468`–`0x10005d480`); для restore/старых сборок `_setAppReplacementStateRulingOutReplacement:` (`0x10005cf8c`) пишет state «not applicable» по `_MIAppReplacementMinimumBuildVersion`. Это тоже часть install-пути, а не отдельный вход.

### 2.5 TOCTOU

- Внутри `prepareWithError` контейнеры резолвятся один раз (`0x100018f74`, `0x100019020`) и handover идёт по этим объектам (`0x100019794`); между проверкой подписи (`0x100018fc4`) и `supersede` нет IPC/повторного lookup. Окна «подменить bundle между проверкой и handover» в одном вызове нет.
- Состояние и prohibition лежат в **bundle-контейнере** (`AppReplacementState.plist`, `AppLaunchProhibition.plist`; строки в `InstalledContentLibrary`: `getAppReplacementState:forBundleContainerURL:`, `getAppLaunchProhibition:forBundleContainerURL:`). Bundle-контейнер принадлежит root/_installd и не writable для app — symlink-подмены state-файла из песочницы не видно.
- Межвызовное окно (`prepare` → `push`/`setStatus`/`end`) существует, но `end`/`setStatus` резолвят контейнер заново по bundle id: если между вызовами приложение переустановить, у нового контейнера не будет state/prohibition, и операция завершится ошибкой. Эксплуатация требует SPI и контроля над установкой — то есть того же доверенного клиента.

**Не подтверждено:** сериализация параллельного `installURL` и `prepare` внутри installd (общая очередь установок не проверялась); поведение `supersedeExistingContainer:` в libcontainer при разных team id.

---

## 3. Пути, симлинки, wrapper bundle, App Clips

### 3.1 Новый код путей не берёт

Полный список селекторов в диапазоне `MIAppReplacementOperation` (`0x1000189c0`–`0x10001a400`): `appBundleContainerWithIdentifier:createIfNeeded:created:error:`, `dataContainerForPersona:`, `dataContainersCreatingIfNeeded:parentPersona:makeLive:created:didUseProvidedPersona:`, `saveAppReplacementState:`, `saveAppLaunchProhibition:`, `supersedeExistingContainer:`, `appExtensionBundlesWithError:`, `setInstallationHold:forBundleID:inDomain:error:`, `appReplacementStateURL`, `appLaunchProhibitionURL`, `path`, `removeAppReplacementStateWithError:`, `removeAppLaunchProhibitionWithError:`.

Нет `URLWithString:`, `fileURLWithPath:`, `URLByAppendingPathComponent:`, `copyItemAtURL:`, `createDirectoryAtURL:`, `_symlink`, `writeToFile:`. Пути из IPA в новый код не попадают вообще: handover — это операция над объектами контейнеров (`supersedeExistingContainer:`), а state-файлы — фиксированные имена в bundle-контейнере.

### 3.2 Симлинки в установке — без изменений

`MIInstaller _installInstallable:containingSymlink:error:`:

- 27.2 — `0x100034da0`, вызов `MIFileManager validateSymlinksInURLDoNotEscapeURL:error:` на `bundle.bundleURL` — `0x1000351c8`;
- 27.0 — `0x100030fc4`, тот же вызов — `0x1000313ec`, тот же контекст (`MIFileManager defaultManager`, `bundleURL`).

Проверка `containingSymlink` (флаг «в бандле был симлинк») та же. Новый replacement-код её не обходит, потому что не распаковывает IPA.

### 3.3 Wrapper bundle / App Clips

`MIInstallableBundle _validateAppManagementDomainForSigningInfo:` (`0x100054e2c`) в 27.2 **добавил** проверки (в 27.0 этих строк нет):

- `"com.apple.AppClips"` domain → приложение обязано быть App Clip (`com.apple.developer.parent-application-identifiers` и т.п.);
- domain App Clips → обязателен `com.apple.developer.wrapper-bundle = TRUE`:
  `"\"%@\" does not have the wrapper bundle entitlement (\"%@\" = TRUE) which is required for apps within the App Clips management domain..."`.

`_performAppClipSpecificValidationForEntitlements:isAppClip:withError:` (`0x100055184`) проверяет: ровно один parent identifier, префикс application-identifier родителя, префикс bundle id + отсутствие точек после префикса, запрещённые extension points (WidgetKit, background-asset-downloader, Home), `keychain-access-groups`, embedded watch app, DriverKit. Всё это — чтение entitlements/Info.plist и возврат ошибки; **никаких записей по путям из IPA**.

Вердикт: wrapper/App Clips — только ужесточение проверок в 27.2, не путь побега. Новый replacement-код вообще не расширяет path-поверхность installd: если побег через installd и существует, он должен быть в старом install/extract-пути (распаковка IPA), а не в app replacement.

---

## 4. Diff 27.0 → 27.2

| Что | 27.0 | 27.2 |
|---|---|---|
| размер | 928 032 | 961 888 (+33 856) |
| `__TEXT.__text` | `0x70f48` | `0x77db8` (+28 272) |
| `__cstring` | `0x18723` | `0x1a6b3` (+8 080) |
| строки `replacement` | **0** | **79** |
| классы | — | `MIAppReplacementOperation`, `MILaunchServicesSetAppReplacementSourceOperation`, `MILaunchServicesSetInstallationHoldOperation` |
| методы `MIClientConnection` | 91 | 97 (+6) |
| вызовы allowedSPI-гейта | 43 | 50 (+7) |
| `MIInstallableBundle` | — | `+_performAppExtensionValidationForAppBundleSigningInfo:...`, `+_setAppLaunchProhibitionWithReplacementRuledOut:...`, `+_setAppReplacementStateRulingOutReplacement:...` |
| App Clips | нет domain-проверок | `com.apple.AppClips` + wrapper-bundle enforcement |
| симлинки | `validateSymlinks...` `0x1000313ec` | `0x1000351c8` (тот же код) |
| гейт | `0x10001adc8` | `0x10001c7c4` |

Проверки у общих методов не убирались: все имена ключей 27.0 присутствуют в 27.2; новых имён — только четыре replacement-ключа (+7 вызовов на 6 новых методов). Единственное ослабление, которое видно в новом коде, — `codeSigningInfoByValidatingResources:0 performingOnlineAuthorization:0 checkingTrustCacheIfApplicable:0` в `prepareWithError` (но это чтение уже установленного приложения, не установка из IPA).

---

## 5. Цепочка app → IX → installd

`installcoordinationd` — единственный известный держатель replacement-SPI. App-facing вход в него тоже закрыт:

- `-[IXSClientConnection _remote_performAppReplacementFromAppIdentity:toAppIdentity:options:completion:]` (`0x100069c3c`):
  ```
  0x100069ca8  "com.apple.private.InstallCoordination.ReplaceApp"
  0x100069d5c  "Client %@ is missing the \"%@\" = TRUE (boolean) entitlement."
  ```
- `_remote_recordAppReplacementNotApplicable...` → `com.apple.private.InstallCoordination.GetAppReplacementSource`
- `_remote_appReplacementRefused...` → `com.apple.private.InstallCoordination.AppReplacementRefused`
- `_remote_resetAppReplacementState...` → `com.apple.private.InstallCoordination.ResetAppReplacementState`

Все — `com.apple.private.*`, в стороннем профиле недостижимы (AMFI сверяет энтайтлменты с профилем). Сами data-replacement extensions, которые дергает `IXSDataReplacementHost`, — системные (`/System/Library/ExtensionKit/Extensions/AppReplacement.appex`, `SpringBoardAppReplacement.appex`, `NEAppReplacement.appex` и т.д.), не третьесторонние.

Единственный не-`com.apple.private` элемент цепочки — `com.apple.developer.superseded-application-identifiers`: он может быть выдан профилем стороннему app (Apple-controlled), но лишь разрешает бандлу **быть** замещающим. Инициировать операцию всё равно может только клиент с `com.apple.private.InstallCoordination.ReplaceApp`, а исполнить — только с `PrepareAppReplacement`; ни то, ни другое стороннему профилю не выдаётся.

---

## 6. Итоговая таблица

| Точка входа | Гейт | Что можно | Вердикт |
|---|---|---|---|
| `prepareReplacementOfApp:byApp:extensionBundleIDs:` | `allowedSPI = PrepareAppReplacement` | подменить data-контейнер любого резолвимого app любому установленному app с непустым superseded-массивом; запретить запуск source; записать state | **нужен allowedSPI** (из проверенных — только installcoordinationd) |
| `setLaunchProhibited:forApp:` | `SetAppLaunchProhibited` | запретить запуск произвольного app по bundle id | **нужен allowedSPI** |
| `pushReplacementInfoForApp:replacingApp:` | `SetAppLaunchProhibited` | записать в LS произвольную пару source→dest | **нужен allowedSPI** |
| `setAppReplacementStatus:forApp:replacingApp:` | `SetAppReplacementStatus` | перезаписать replacement state в bundle-контейнере | **нужен allowedSPI** |
| `endAppReplacementWithStatus:forApp:` | `SetAppReplacementStatus` + `SetAppLaunchProhibited` | снять prohibition, финализировать state | **нужен allowedSPI** |
| `removeAppReplacementStateForApp:` | `RemoveAppReplacementState` | удалить state + LS-записи | **нужен allowedSPI** |
| `installURL` / stage / finalize / revert / uninstall / lookup / enumerate / safe harbor / metadata | `allowedSPI` (см. 1.4) | установка/удаление/метаданные | **нужен allowedSPI** |
| persona / content registration / data-separated | `com.apple.private.installcoordinationd.daemon` | управление персонами и регистрацией контента | **нужна подпись Apple** |
| `personasForBundleID`, `rebuildBuiltInContentMapping` | `com.apple.private.coreservices.lsd` | чтение персон / rebuild | **нужна подпись Apple** |
| `getPidForTesting`, `referencesForBundleWithIdentifier`, `checkCapabilities`, `registerPlaceholderForReference`, `triggerRegistrationForContent` | гейта нет | pid, список references, capability-запрос, LS-placeholder, LS-gather | **недостижимо из app (sandbox: deny mach-lookup)** |
| `MobileInstallationHelperService` (`makeSymlink...`, `stageItemAtURL...`, `moveItem...`) | `com.apple.private.MobileInstallationHelperService.allowed` на accept | файловые операции от `_installd` | **нужна подпись Apple** |
| `IXSClientConnection _remote_performAppReplacement...` | `com.apple.private.InstallCoordination.ReplaceApp` | запуск replacement через installcoordinationd | **нужна подпись Apple** |
| App Clips / wrapper bundle | entitlements + management domain | только установка App Clip/wrapper | **нужна подпись Apple** |
| симлинки IPA | `validateSymlinksInURLDoNotEscapeURL:` (без изменений) | запись только внутри bundle | **не новый вектор** |

---

## 7. Не подтверждено

1. **Сверка superseded-массива с source app в installcoordinationd.** В installd её нет; есть ли она в `IXSDataReplacementHost` / `IXAppReplacementSourceResolver` — не разобрано (отдельный бинарник, вне задачи). Если её нет и там, любой клиент с `ReplaceApp` может забрать контейнер чужого приложения.
2. **Проверки внутри `supersedeExistingContainer:`** (`MIMCMContainer` → libcontainer, строка `_container_operation_copy_superseded`). DSC на 27.2 использует ObjC optimization v4, `ipsw class-dump` его не парсит; identity/team-проверки примитива не верифицированы.
3. **Домены контейнеров.** `_bundleContainerForIdentity:` не передаёт domain/persona в `appBundleContainerWithIdentifier:createIfNeeded:created:error:`; можно ли так достать контейнер системного приложения — не проверено (нужен список установленных app с superseded-entitlement).
4. **Параллельная установка.** Сериализация `installURL` и `prepare` внутри installd не проверялась; межвызовное окно существует, но требует SPI.
5. **`MIAppIdentity.location`.** Поле есть (`_doInitWithBundleID:personaUniqueString:location:`), `prepareWithError` его игнорирует; использует ли `resolvePersonaWithError:` location как путь для чтения — не проверено.
6. **Runtime.** Ничего не запускалось на устройстве; все выводы — статика по 27.2/27.0.
7. **`registerPlaceholderForReference:` + `MIAppReference`.** Метод без гейта, а `MIAppReference`/`MIAppIdentity` входят в типы XPC-протокола (строки `@"MIAppReference"`, `@"MIAppIdentity"`); NSXPC-whitelist настраивается в `0x100004ae0` (`setClasses:forSelector:...`), конкретные пары селектор→класс не разобраны. Если крафтнутый `MIAppReference` с `location` проходит декодирование, это может дать чтение/регистрацию по чужому пути от `_installd` — но только клиенту, которому песочница разрешила lookup (daemon), не app.
