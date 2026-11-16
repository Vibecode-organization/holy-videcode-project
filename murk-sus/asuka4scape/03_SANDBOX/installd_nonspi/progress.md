# installd_nonspi — subagent AK (методы без allowedSPI)

## step 1 — вход и инструменты
- Каталог создан. Бинарь `work/root272/installd` (961 888 Б, 27.2, sha256 `408906e8…fdf06`), дифф-база `work/root270/installd` (928 032 Б).
- `ipsw 3.1.736`: `class-dump --re -V`, `macho disass` (с a2s-кэшем), `macho info --fixups`; LIEF 1.0.0 + capstone 5.0.7 для парсинга `__objc_methlist`/`protocol_t`; `ldid -e`.
- Из DSC `rc115/dsc272` извлечены `MobileInstallation` и `InstalledContentLibrary` для `MIAppReference`/`MIAppIdentity`/`ICLRegistrationOptions`.

## step 2 — вход
- `sb272/container.sb:13515` — `com.apple.mobile.installd` в безусловном `allow mach-lookup` (блок с 13159). Прошлый вывод «sandbox не пускает app» неверен.
- Listener `0x10001b280`: `setExportedInterface:` (`0x100004ae0`, протокол `MobileInstallerProtocol`), `setExportedObject:`, `resume`, `return 1`. Audit token/энтайтлменты не проверяются.
- `clientName` `0x10001b348` — только `pid/euid/egid` для логов.

## step 3 — перепись
- В протоколе 75 методов, все реализованы (в классе 97 методов с приватными).
- Прямой гейт `allowedSPI` — `0x10001c7c4` (строка или массив `containsObject:`); булев энтайтлмент — `0x10001e40c` (boolValue).
- Без гейта ровно 6: `triggerRegistrationForContainerizedContent…`, `…DiskImageContent…`, `registerPlaceholderForReference:`, `referencesForBundleWithIdentifier:inDomain:`, `checkCapabilities:withOptions:`, `getPidForTesting`.
- `installURL`/`stageInstallURL` не гейтятся в теле, но безусловно идут в `_validateInstallRequestForURL` (`0x10001dfd0` → `0x10001e06c`); `revertIdentity`/`uninstall*` — в gated-калькуляции.

## step 4 — ungated
- `triggerRegistration…` `0x10002c2a0` → `_triggerRegistrationForContent` `0x10002bcc0`: `ICLRegistrationOptions.targetUID` (`0x10002bd3c`) без валидации → `initWithOptions:forTargetUID:` `0x10002befc` → `LSOperationRequestContext.setTargetUserID:` `0x10002c154` → `registerApplicationForRebuild…` `0x10002c1a8`. Cross-uid LS-регистрация + полный gather без рейт-лимита.
- `registerPlaceholderForReference` `0x10001d394`: `validateAppReference:` не вызывается; контейнер по `identity.bundleID` `0x10001d4d4`; data-контейнеры `0x10001d5cc`; `setIsPlaceholder:1` `0x10001d7bc`; `registerInstalledInfo:` `0x10001df40` → `addReferenceForIdentity:` `0x100062374` (запись `AppReferences` в bundle-контейнер цели) + `_registerInstalledInfo` `0x100062488`.
- `referencesForBundleWithIdentifier` `0x1000286d4` → `referencesForIdentifier` `0x10006e3f8`: `allUsers` `0x10000a8b4`, домен 3 — только currentUser.uid `0x10006e4cc`; возврат `NSDictionary {uid: NSSet(personas)}`, без путей/UUID.
- `checkCapabilities` `0x10002592c` → ICL `0x1ab4e2670` (UIRequiredDeviceCapabilities); `getPid` `0x10002b4e4`.

## step 5 — негативный результат
- Клиентских путей в ungated-методах нет; `MIAppIdentity.location` для резолва контейнера не используется; bundle id — только ключ поиска.
- Path traversal, symlink escape, TOCTOU «проверка пути → использование» не найдены.
- Возврат наружу: только metadata (personas/uid), capability-словарь, pid, `LSRecordPromise`/ошибки; содержимого файлов нет.
- Установка/удаление/замена/revert остаются за `allowedSPI`/`installcoordinationd.daemon`/`lsd`.

## step 6 — вывод
- `REPORT.md` записан (таблицы 6 ungated + 69 gated, дизасм, вердикт, «не подтверждено»).
- Запись в `CHAT_дипсики.md` добавлена (<=15 строк).

## Открыто
- Рантайм-проверка на устройстве; состояние `MI_App_References`; перезапись существующей LS-записи при `isPlaceholder=1`; эффект `targetUID=0`/чужого uid; Shared iPad; содержимое `LSRecordPromise`; декодеры gated-методов до гейта.
