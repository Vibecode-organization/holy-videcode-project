
---

## 2. Топ-8 непаханых

Отбор: не аудировано + доступно безусловно (`container.sb:13159..13631`) + принимает на вход данные/пути/URL и разбирает их. Все 8 — целые бинари из 27.2, энтайтлменты сняты, протоколы и селекторы вытащены строками (`svc_map/profile_*.txt`).

### 1. `com.apple.passd.library` / `.in-app-payment` / `.assertions` — passd
- Бинарь: `System/Library/PrivateFrameworks/PassKitCore.framework/passd`, 10.3 МБ, `container.sb:13542`, плист `com.apple.passd.plist`.
- Энтайтлменты: 197. `private.tcc.manager.access.read = kTCCServiceAll`, `private.tcc.allow = {Calendar, Willow, Liverpool, AddressBook, FaceID, Photos}`, `tcc.manager.check-by-audit-token` для `PKPassLibraryBackgroundAddPasses`, `mach+4` (`amsondevicestoraged`, `photos.service`, `visual-action-prediction`, `generativeexperiences.availabilityService`), `idcredentials.storage`.
- Что делает: библиотека Wallet. Протоколы `PDPaymentWebServiceCoordinatorProtocol`, `PDNetworkTaskManagerProtocol`; строки — `addPassesWithData:handler:`, `anyInDatabase:withURL:`, `cborWithData:`, `createWithData:`, `cachedDataForURL:`.
- Ценность: принимает **данные .pkpass** (ZIP + JSON + detached PKCS#7) и сам разбирает архив, манифест и подпись. Плюс CBOR-транзакции и сетевые ответы веб-сервиса. Классическая поверхность «архив + парсер + крипто-проверка» в одном сервисе, доступном приложению.
- Не подтверждено: гейт по аудиотокену/энтайтлментам на входе в listener (дизасм не делался).

### 2. `com.apple.managedappdistributiond.xpc` — managedappdistributiond
- Бинарь: `System/Library/Frameworks/ManagedAppDistribution.framework/Support/managedappdistributiond`, 8.6 МБ, `container.sb:13497`.
- Энтайтлменты: 89, в т.ч. `private.mobileinstall.allowedSPI = CheckCapabilitiesMatch`, `mach+10`, `storage.os_eligibility.readonly`.
- Что делает: управляемая дистрибуция приложений (MDM/App Store-каталог). Протоколы `IngesterProtocol`, `InstantiatorProtocol`, `DecrypterProtocol`, `VariantProtocol`, `ErasedInstantiatorProtocol`; строки — `metadataFromPlistData:error:`, `updateSINFForAppWithIdentity:sinfData:options:error:`, `importKeybagWithData:error:`, `initWithDatabasePath:`, `setSinfData:`.
- Ценность: разбор plist-манифестов, SINF, установка/варианты бандла из сети — прямой аналог installd, но новее и без разбора. `DecrypterProtocol` + `importKeybagWithData:` — отдельный интерес (работа с keybag).
- Не подтверждено: что именно клиент может задать в манифесте; гейты по энтайтлментам не смотрелись.

### 3. `com.apple.mediaanalysisd.*` (3 имени) — mediaanalysisd
- Бинарь: `System/Library/PrivateFrameworks/MediaAnalysis.framework/mediaanalysisd`, 3.7 МБ, `container.sb:13501`.
- Энтайтлменты: 79. `private.security.storage.{Photos, PhotosLibraries, MessagesMetaData, HomeAI}`, `tcc.allow = {Photos, Willow, Liverpool, AddressBook}`, `mach+11`, `aned.private.allow`, `modelmanager.inference`.
- Что делает: фото/видео-анализ (VCP + MAD). Протоколы `VCPMADServicePublicServerProtocol`, `MADVideoSessionServerProtocol`, `MADComputeServiceServerProtocol`, `MADVideoSessionClientProtocol`; строки — `assetWithImageData:uniformTypeIdentifier:identifier:clientBundleID:clientTeamID:`, `assetWithPHAsset:downloadedData:`, `decompressData:`, `faceObservationFromFaceprintData:`.
- Ценность: **принимает произвольные байты изображения + UTI** и гонит их через декодеры (ImageIO/AVFoundation) и ML-модели. Ошибки парсинга в декодере достигаются из песочницы приложения. Плюс запись в Photos/Messages-хранилища.
- Не подтверждено: нужен ли PHAsset или достаточно data-входа для public-сервиса; кто фильтрует clientBundleID.

### 4. `com.apple.mobilemail.services.xpc` — maild
- Бинарь: `System/Library/PrivateFrameworks/EmailDaemon.framework/maild`, 2.3 МБ, `container.sb:13522`.
- Энтайтлменты: 127. `storage.Mail`, `tcc.allow = {Liverpool, Calendar, Reminders}`, `tcc.allow.overridable = AddressBook`, `mach+10`.
- Что делает: демон Почты. Протоколы `MSDSearchProtocol`, `MSDAutosaveProtocol`, `MSDMessageBodyLoaderProtocol`, `MSDResetListUnsubscribeProtocol`, `MFNanoServerMessageContentURLProtocol`; строки — `addAttachmentData:mimeType:fileName:contentID:`, `attachmentForURL:error:`, `attachmentsForURLs:error:`, `autosaveMessageData:replacingIdentifier:completion:`.
- Ценность: MIME/EML-парсер, который **пишет вложения в контейнер** по имени/URL и отдаёт тело письма по ID. Разбор писем — исторически щедрая на баги поверхность (multipart, вложенные message/rfc822, кодировки).
- Не подтверждено: какой из MSD-протоколов экспортируется наружу (все они в одном бинаре).

### 5. `com.apple.nsurlsessiond` — nsurlsessiond
- Бинарь: `usr/libexec/nsurlsessiond`, 1021 КБ, `container.sb:13536`.
- Энтайтлменты: 54. `rootless.storage.nsurlsessiond`, `tcc.manager.check-by-audit-token = UserTracking`, `mach+4`.
- Что делает: фоновые загрузки/докачки за приложение. Протокол `NDBackgroundSessionProtocol`; строки — `avAssetDownloadTaskWithDownloadToken:URL:destinationURL:temporaryDestinationURL:assetTitle:assetArtworkData:options:assetOptions:...`, `downloadTaskWithResumeData:`, `cancelByProducingResumeData:`, `infoWithResumeData:`.
- Ценность: клиент задаёт **destinationURL** — путь, по которому демон пишет файл; сервис живёт вне контейнера приложения. Плюс `resumeData` — сериализованный блоб, который парсится.
- Не подтверждено: проверяется ли destinationURL на принадлежность контейнеру клиента (в строках следов валидации не видно, дизасм не делался).

### 6. `com.apple.cache_delete.public` — deleted
- Бинарь: `System/Library/PrivateFrameworks/CacheDelete.framework/deleted`, 830 КБ, `container.sb:13313`.
- Энтайтлменты: 22. `private.security.storage.AppDataContainers`, `private.mobileinstall.allowedSPI = InstallForLaunchServices`, `tcc.allow = {SystemPolicyRemovableVolumes, SystemPolicyNetworkVolumes}`, `private.apfs.space-attribution`, `private.CacheDelete`.
- Что делает: purge/удаление кэшей. Протоколы `CacheDeleteServiceProtocol`, `CacheDeletePublicClientProtocol`, `CacheDeletePrivateClientProtocol`; строки — `cdVolumeForPath:`, `mountPointForPath:`, `purgeableResult`, `cancelExtensionRequestWithIdentifier:`.
- Ценность: единственный сервис в списке, который по входу-пути **удаляет файлы** и считает занимаемое место; живёт с доступом к AppDataContainers. Ошибка в резолве пути = удаление чужого.
- Не подтверждено: принимает ли public-клиент произвольные пути или только свои том/каталог.

### 7. `com.apple.spotlight.IndexAgent` / `SearchAgent` / `IndexDelegateAgent` — searchd
- Бинарь: `System/Library/PrivateFrameworks/Search.framework/searchd`, 807 КБ, `container.sb:13573`.
- Энтайтлменты: 101. `fileprovider.enumerate`, `fileprovider.extension-host`, `storage.Spotlight`, `tcc.manager.access.read = kTCCServiceAll`, `mach+10`, `tcc.allow = {AddressBook, Calendar, Reminders}`.
- Что делает: индексатор Spotlight. Строки — `addDefaultBundleInformationForURL:attrSet:altNames:namesOnly:withApp:enName:`, `CS_INDEX_PATH`, `fileProviderDomainFilterQueries`, `com.apple.spotlight.index.firstUnlock`, `sendFeedbackType:feedbackData:queryId:clientID:`.
- Ценность: принимает URL/атрибуты на индексацию, тянет fileprovider-домены, отдаёт результаты поиска по всем доменам. Метаданные + импортеры = разбор произвольных типов.
- Не подтверждено: какой из трёх агентов экспортирует наружу и что фильтруется по клиенту.

### 8. `com.apple.quicklook.ThumbnailsAgent` — ThumbnailsAgent
- Бинарь: `System/Library/Frameworks/QuickLookThumbnailing.framework/Support/com.apple.quicklook.ThumbnailsAgent`, 91 КБ, `container.sb:13553`.
- Энтайтлменты: 16. `fileprovider.enumerate`, `fileprovider.fetch-url`, `private.security.storage.FileProvider`, `rootless.storage.QLThumbnailCache`, `mach+1` (`CoreGraphics.CGPDFService`), `seatbelt-profiles = com.apple.quicklook.QLThumbnailsService`.
- Что делает: превью файлов. Строки — `hasThumbnailForURLWrapper:updateLastHitDate:andSize:completion:`, `thumbnailsStoreURLForURL:completionBlock:`.
- Ценность: самый маленький и самый «входной» из восьми — URL на входе, дальше QL-генератор по типу файла (PDF/изображения/офис). PDF отдаётся в `CGPDFService` того же процесса.
- Не подтверждено: какие именно генераторы грузятся в этом процессе на 27.2 (в бандле их нет, только фреймворк).

---

## 3. XPC-сервисы из того же правила (48 имён, `xpc-service-name`)

Это не глобальные порты launchd, а XPC-сервисы внутри чужих процессов; приложение может их поднять по имени. Хост в root FS не искался (сервис живёт в бандле), поэтому «бинарь» тут — не путь.

| сервис | что даёт | ценность |
|---|---|---|
| `com.apple.ImageIOXPCService` | декодирование изображений произвольного формата вне процесса | 9 |
| `com.apple.iWorkFileFormat` | разбор iWork-документов (zip + protobuf) | 9 |
| `com.apple.textkit.nsattributedstringagent` | разбор RTF/HTML/DOCX в attributed string | 8 |
| `com.apple.PrintKit.PrinterTool` | подготовка документа к печати (PDF/PS/PCL) | 8 |
| `com.apple.BarcodeSupport.ParsingService` | разбор QR/PDF417/Aztec | 7 |
| `com.apple.DocumentManagerCore.Rename` | переименование файлов (работа с путями) | 7 |
| `com.apple.coremedia.compressionsession.xpc` / `decompressionsession.xpc` | медиа-кодеки | 7 |
| `com.apple.ModelIO.AssetLoader` | загрузка 3D-ассетов (USD/OBJ) | 6 |
| `com.apple.WebKit.{WebContent,Networking,GPU,Model,WebAuthn}` | веб-контент | 6 |
| `com.apple.mscamerad-xpc` | камера | 5 |
| `.viewservice`, `com.apple.uifoundation-bundle-helper`, `com.apple.iconservices`, `com.apple.avkit.SharedPreferences`, `com.apple.audio.AudioConverterService*`, `com.apple.datadetectors.AddToRecentsService`, `com.apple.MapKit.SnapshotService`, `com.apple.MediaPlayer.RemotePlayerService`, `com.apple.OSLogService`, `com.apple.backgroundassets.managed.helper.service`, `com.apple.externalaccessory.WACEAService`, `com.apple.imfoundation.IMRemoteURLConnectionAgent`, `com.apple.intents.intents-helper`, `com.apple.siri.*`, `com.apple.StocksKitService`, `com.apple.WorkoutKitXPCService`, `com.apple.accessibility.*`, `com.apple.tonelibraryd`, `com.apple.AGXCompilerService*`, `com.apple.MTLCompilerService`, `com.apple.CompassCalibration`, `com.apple.EnergyKitService`, `com.apple.SafariFoundation.*`, `com.apple.SafariServices.ContentBlockerLoader`, `com.apple.CallKit.CallDirectory`, `com.apple.ContactsUI.ContactsButtonXPCService`, `com.apple.audio.analytics.service` | служебное/UI | 2–4 |

Верхние пять — самый короткий путь к «парсим чужие байты в чужом процессе»: ImageIO и iWork отдельно интересны тем, что принимают контейнерные форматы.

---

## 4. Мёртвые правила (42)

Разрешены профилем, но хоста нет ни в одном launchd-плисте, ни в root FS (по имени и по строке в 103 кандидатах), ни в dyld shared cache (сплошной grep 9.1 ГБ). Аналог истории с `IOAccelContext2`.

Оговорка: `System/Cryptexes/{OS,App,Supplemental}` — симлинки (35–45 байт), содержимое криптекса в этот образ не входит. Сервис, чей хост живёт **только** в криптексе, тут выглядит мёртвым. Для перечисленных ниже это маловероятно (легаси-имена, часть из них — старые имена живых сервисов), но формально это «не найдено», а не «доказано мертво».

| сервис | комментарий |
|---|---|
| `ScripterServer` | легаси-порт Automator/скриптов, бинаря нет |
| `com.apple.AdSheetPad.server`, `com.apple.AdSheetPhone.server` | iAd, выпилен |
| `com.apple.AuthenticationServices.AuthenticationServicesAgent.PhoneNumberVerification` | хоста нет; живой аналог — `AuthenticationServicesUI.app` |
| `com.apple.IncomingCallNotifications.ICNotificationManagerHost` | хоста нет |
| `com.apple.KeyboardServices.TextReplacementService` | хоста нет |
| `com.apple.MediaControl.daemon` | живой аналог — `MediaControlMessageService.xpc` (в xpc-списке его нет) |
| `com.apple.PersistentURLTranslator.Gatekeeper` | хоста нет |
| `com.apple.SystemConfiguration.SCNetworkReachability` | остался только `configd` |
| `com.apple.UIKit.pasteboardd` | старое имя; живой — `com.apple.pasteboard.pasted` |
| `com.apple.USDKit.FormatLoader` | живой — `USDLib_FormatLoader.xpc` (в списке есть `com.apple.USDLib.FormatLoader`) |
| `com.apple.airplaydiagnostics.server` | хоста нет |
| `com.apple.ait.client` | хоста нет |
| `com.apple.appleprofilepolicyd` | хоста нет |
| `com.apple.audio.AudioConverterServer` | живой — `com.apple.audio.AudioConverterService` (xpc-список) |
| `com.apple.backboard.animation-fence-arbiter`, `com.apple.backboard.workspaceserverconnection` | оба имени отсутствуют в `backboardd` строками |
| `com.apple.bypassBasebandAutoBooter.msgport` | хоста нет |
| `com.apple.coremedia.bytestream.xpc`, `.externalsyncdevicemanager.xpc`, `.wirelessdisplay`, `.wirelessdisplayserver` | в `mediaplaybackd`/`videocodecd` таких имён нет |
| `com.apple.cvmsCompAgent_armv7`, `com.apple.cvmsServ` | старый OpenGL-компилятор, выпилен |
| `com.apple.datamigrator.dz` | хоста нет (есть `com.apple.datamigrator`) |
| `com.apple.dictationd.recognition` | хоста нет |
| `com.apple.dt.testmanagerd.runner`, `com.apple.dt.testmanagerd.uiprocess` | dev-образ, на стоке нет |
| `com.apple.gputools.producer` | dev-инструмент, бинаря нет |
| `com.apple.instruments.server.mig` | dev-инструмент, бинаря нет |
| `com.apple.itdbprep.server` | хоста нет |
| `com.apple.librariand` | хоста нет (архивы ушли в fileproviderd) |
| `com.apple.livecommunicationkit.conversationhistory`, `.telephonymanager` | хоста нет |
| `com.apple.mobileipod.MPMusicPlayerControllerInternal` | старое имя, бинаря нет |
| `com.apple.prdaily` | хоста нет |
| `com.apple.telephonyutilities.remotelogdaemon` | хоста нет |
| `com.apple.twitterd`, `com.apple.twitterd.server`, `com.apple.weibod.server` | соцсети, выпилены |
| `com.apple.vibrationmanagerd` | хоста нет (вибрация в `backboardd`) |
| `com.apple.vsassetd` | хоста нет (ассеты в `mobileassetd`) |
| `com.apple.webfilterd` | хоста нет (фильтр в `nesessionmanager`) |
| `com.apple.widget.pushkit` | хоста нет |

Отдельно, «хост есть, имя не подтверждено» (15): `com.apple.assetsd.changehub` (assetsd), `com.apple.accountsd.accessmanager`/`.authmanager` (accountsd), `com.apple.iTunesStore.daemon-notifications`/`.deatchwatch` (itunesstored), `com.apple.springboard.icongeneration`/`.watchdogserver` (SpringBoard), `com.apple.Music.MPMusicPlayerMigServerExists` и `com.apple.mobileipod.MPMusicPlayerMigServerExists` (Music), `com.apple.commcenter.dm-helper` (CommCenter), `com.apple.healthd.restriction` (healthd), `com.apple.gamed.note` (gamed), `com.apple.ap.adprivacyd.trackingtransparency` (adprivacyd), `com.apple.iap2d`/`com.apple.iaptransportd` (iapd/accessoryd), `com.apple.coremedia.videocodecd.compressionsession.xpc` (videocodecd), `com.apple.mediastream.sharing-nowake` (sharingd). Строкой имени в бинаре нет — либо собирается в рантайме, либо правило устарело.

---

## 5. Гейтованные правила (не для обычного приложения)

- **60 правил с энтайтлментом.** Примеры: `com.apple.fairplayd*` (нужен `private.applemediaservices`), `com.apple.contactsd.support` (`private.contacts`), `com.apple.coreduetd.people`, `com.apple.mobile.keybagd*`, `com.apple.ak.auth.xpc`, `com.apple.FileCoordination`, `com.apple.lskdd*`, `com.apple.iphone.axserver` (local-name).
- **13 правил по profile-flag.** Важнейшее — `common-mach-lookups`: `lsd`, `lsd.open`, `lsd.mapdb`, `lsd.icons`, `runningboard`, `logd`, `logd.events`, `diagnosticd`, `analyticsd`, `aggregated`, `distributed_notifications@1v3`, `CoreAuthentication.daemon`, `system.libinfo.muser`, `ctkd.token-client`, `duetknowledged.activity`, `coreservices.lsuseractivitymanager.xpc`, `appsupport.cplogd`. Второе — `common-containermanagerd-rules`: `com.apple.containermanagerd`, `.system`. Третье — `common-preferences-rules` (`cfprefsd.*`), `common-mobilegestalt-rules`, `common-system-logging-rules` (`com.apple.system.logger`).
- Приложение эти флаги получает от sandbox в зависимости от типа процесса, а не от своих энтайтлментов; фактическое состояние на устройстве не проверялось — **не подтверждено**. Именно поэтому `containermanagerd` не попал в основной список, хотя приложение до него достаёт (аудит это подтверждал).
- `com.apple.StreamingUnzipService` — не глобальное имя, а `xpc-service-name` в отдельном правиле (`container.sb:12685`) под `require-all` с sandbox-extension; обычному приложению без extension-class не даётся.
- `com.apple.installcoordinationd` в `container`/`baseline` отсутствует вовсе — он есть только в профилях `appconduitd` и `appstored`. Для обычного приложения путь к нему закрыт (аудит installd это подтверждал: установка идёт через `allowedSPI`).

---

## 6. Что осталось непроверенным

- Гейты на входе в listener у топ-8 (аудиотокен, энтайтлменты, allowedSPI) — дизасм не делался ни для одного.
- Проверка путей у `nsurlsessiond` (`destinationURL`) и `deleted` (`cdVolumeForPath:`) — по строкам не видно валидации, но это не доказательство.
- Хост 42 «мёртвых» имён в криптексе не исключён (криптекс в образе — симлинк).
- 132 имени без launchd-плиста: 75 привязаны к бинарю через строки FS/DSC, 57 разобраны выше; для 15 из них («хост есть») сервис не подтверждён.
- Санкционированность `xpc-service-name` из списка 48: сервис существует в бандле, но фильтрация клиента внутри сервиса не смотрелась.
