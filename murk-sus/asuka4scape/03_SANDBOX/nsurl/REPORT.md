# nsurlsessiond / CacheDelete — запись и удаление вне контейнера приложения (iOS 27.2)

Артефакты: root FS `rc115/out272_clean/141-10327-211.dmg` (24B115, iOS 27.2),
DSC `rc115/dsc272`, sandbox-профили `work/sb272/all.json`.
Бинарь: `usr/libexec/nsurlsessiond`, 1 045 648 Б, arm64e, база `0x100000000`.
Энтайтлменты сняты `ipsw macho info --ent` (54 шт.); `ldid -e` на 27.2 пуст.

Обозначения: **подтверждено** — есть дизасм/декларация в бинаре; **не подтверждено** —
не доказано ни в одну сторону.

---

## 1. Достижимость сервиса из обычного app

В профиле `container` есть безусловный `allow mach-lookup` со списком global-name,
в который входит `com.apple.nsurlsessiond` (проверено по `sb272/all.json`).
То же для `com.apple.cache_delete.public`; `com.apple.cache_delete` требует
`com.apple.mobile.deleted.AllowFreeSpace` или `com.apple.private.CacheDelete`.

Итог: обычное приложение может подключиться к `com.apple.nsurlsessiond`
(это и нужно для штатного background NSURLSession) и к публичному listener
CacheDelete. **Подтверждено.**

Селектор класса сессии выбирается по клиентскому флагу конфигурации
`-_supportsAVAssetDownloads` (`0x1000046dc`): true → `NDAVBackgroundSession`
(класс-объект `0x1000d8580`), иначе `NDBackgroundSession`/`NDNWSession`
(`0x1000046e4`–`0x1000047c8`). Флаг приходит от клиента и в
`copyAndSanitizeClientConfiguration:` не вычищается. **Подтверждено.**

---

## 2. Обычная фоновая загрузка (`downloadFilePath`)

Точка входа XPC (протокол `NDBackgroundSessionProtocol`):

```
-[NDBackgroundSession downloadTaskWithRequest:originalRequest:
    downloadFilePath:identifier:uniqueIdentifier:reply:]      @0x10001fb94
```

Порядок (дизасм `0x10001fca0`–`0x10001fe78`):

| адрес | что происходит |
|---|---|
| `0x10001fca4` | `__CFN_isSafeRequestForBackgroundDownload(request)` — отсев небезопасных request |
| `0x10001fcd8` | `[[Daemon sharedDaemon] isPrivileged]` |
| `0x10001fce0` | `csel x8, x28, xzr, ne`: клиентский `downloadFilePath` передаётся дальше **только если демон privileged**, иначе `nil` |
| `0x10001fd14` | `[session _downloadTaskWithRequest:request downloadFilePath:path]` (private CFNetwork) |
| `0x10001fd58` | `[[task downloadFile] path]` — фактический путь, который выбрал CFNetwork |
| `0x10001fdb4` | `[[NSXPCConnection currentConnection] auditToken]` — токен **клиента** |
| `0x10001fe50` | `+[NDFileUtilities safeURLForDownload:path auditToken:token]` |
| `0x10001fe6c` | `[taskInfo setDownloadFileURL:safeURL]` (nil, если проверка не прошла) |

Ключевая проверка — `+[NDFileUtilities safeURLForDownload:auditToken:]` `0x10005a8d4`:

```
0x10005a908  [url URLByDeletingLastPathComponent]
0x10005a928  +[NDFileUtilities safeDirectoryForDownloads:parent auditToken:token]
0x10005a93c  [url lastPathComponent]
0x10005a958  [safeDir URLByAppendingPathComponent:lastComponent isDirectory:0]
```

`safeDirectoryForDownloads:auditToken:` `0x10005a720`:

```
0x10005a75c  NSString *p = [dir path]
0x10005a774  [p hasPrefix:@"/.nofollow"]
   да  -> 0x10005a790  strdup([p fileSystemRepresentation] + 10)   // срезать префикс
   нет -> 0x10005a7a8  realpath([p fileSystemRepresentation], NULL)
0x10005a7bc  flags = SANDBOX_CHECK_NO_REPORT | SANDBOX_CHECK_CANONICAL
                    | SANDBOX_CHECK_POSIX_WRITEABLE
0x10005a7f4  op = "file-write-data"
0x10005a804  sandbox_check_by_audit_token(token, "file-write-data", flags|1, realpath)
0x10005a808  if (rc != 0) { free; return nil; }
0x10005a860  snprintf(buf, 0x40b, "/.nofollow%s", realpath)
0x10005a894  return [NSURL fileURLWithFileSystemRepresentation:buf isDirectory:1 ...]
```

Значения флагов подтверждены по `libsystem_sandbox.dylib`:
`NO_REPORT=0x40000000`, `CANONICAL=0x20000000`, `POSIX_WRITEABLE=0x02000000`
(`__TEXT.__const` `0x2ca7fa694`–`0x2ca7fa6ac`). В `_sandbox_check_common`
`0x2ca7f6968` бит 30 → attr 1 (no report), бит 29 → attr 2 (canonical),
бит 25 → attr 0x40 (POSIX writeable). То есть проверяется sandbox-операция
`file-write-data` **от имени клиента**, с канонизацией пути и проверкой
POSIX-прав. Это не «демон проверяет себя», а проверка прав **приложения**.

Дополнительно: для клиентского `_directoryForDownloadedFiles` в конфигурации
сессии (`copyAndSanitizeClientConfiguration:` `0x10000398c`) при
`!isPrivileged` вызывается тот же `safeDirectoryForDownloads:auditToken:`
`0x100003d14`. При `isPrivileged` каталог принимается как есть
(`0x100003ccc` → `0x100003d64`). **Подтверждено.**

### Кто реально открывает файл

`-[NDBackgroundSession _URLSession:openFileAtPath:mode:completionHandler:]`
`0x100041dd8` не открывает файл сам: он собирает callback типа 6 с аргументами
`{path, mode}` (`0x100041f3c`–`0x100041f94`) и отдаёт его клиенту.
`-[NDBackgroundSession performCallback:]` `0x100017bfc` вызывает на клиентском
прокси `-openFileAtPath:mode:withReply:` (`0x1000183f4`). Клиент (app) открывает
файл у себя, возвращает `NSFileHandle`; демон делает `dup(fd)` (`0x100042188`)
и отдаёт fd в CFNetwork. То есть open/write идёт **под sandbox приложения**.

`requiresClientToOpenFiles` включается в
`configurationWithClientConfiguration:discretionary:` `0x100007568` только при
`isPrivileged` (`0x100007a74` → `0x100007a8c`).

### `isPrivileged`

Ивар `Daemon._privileged` — смещение `0x30`. Единственный писатель —
`-[Daemon setPrivileged:]` `0x100073448` (`strb w2,[x0,#0x30]`). В бинаре
**нет** ни `bl 0x100073448`, ни селекторного стаба `setPrivileged:`.
`-[Daemon start]` `0x100073220` privileged не выставляет. На iOS демон
запущен как `mobile` (`UserName=mobile` в launchd-плисте), т.е. `isPrivileged`
с высокой вероятностью `NO`; **не подтверждено** (внешнего сеттера не нашли,
но стартовое значение из launchd не доказано).

Практический вывод: на обычном iOS `downloadFilePath` от app **игнорируется**
(`nil`), а каталог загрузки берётся из клиентской конфигурации и проходит
`sandbox_check_by_audit_token`. Запись идёт в
`.../Library/Caches/com.apple.nsurlsessiond` внутри контейнера app.
**Подтверждено для ветки `!isPrivileged`.**

---

## 3. AVAssetDownloadTask: `destinationURL` и `temporaryDestinationURL`

XPC-метод:

```
-[NDAVBackgroundSession avAssetDownloadTaskWithDownloadToken:URL:
    destinationURL:temporaryDestinationURL:assetTitle:assetArtworkData:
    options:assetOptions:identifier:uniqueIdentifier:taskKind:
    enableSPIDelegateCallbacks:reply:]                        @0x10007e800
```

Что делает:

1. `downloadDirectoryToUse:destinationURL` = `[destinationURL URLByDeletingLastPathComponent]`
   (`0x10007e94c` → `0x10007d3f8`).
2. `+[NDFileUtilities safeDirectoryForDownloads:parent auditToken:clientToken]`
   (`0x10007e990`). Если nil — ошибка
   `"Task <...> for client %@ does not have write access to destination directory %@"`
   (`0x10007f048`) и задача не создаётся.
3. `temporaryDestinationURL` сохраняется **без проверки**:
   `[taskInfo setTemporaryDestinationURL:]` `0x10007ec88`.
4. `destinationURL` кладётся в taskInfo через
   `initWithAVAssetDownloadURL:destinationURL:...` `0x10007eb3c`.
5. `_destinationURLToUse` (категория `NDAVAdditions`) `0x10007b120`:
   ```
   if (taskInfo.temporaryDestinationURL) return temporaryDestinationURL;
   return taskInfo.destinationURL;
   ```
6. `newAVAssetDownloadSessionWrapperForTaskInfo:` `0x1000821e0` берёт
   `[taskInfo _destinationURLToUse]` (`0x10008225c`) и передаёт его в
   `-[AVAssetDownloadSession initWithURLAsset:destinationURL:options:delegate:queue:]`
   (`0x1000822cc`) либо `initWithURL:destinationURL:...` (`0x100082458`).

Таким образом:

- проверяется только **родитель `destinationURL`**, и результат проверки
  (safe URL с `/.nofollow`) **выбрасывается**: `x24` кладётся в `[sp,#0x38]`
  (`0x10007e9a0`) и используется только как boolean/для release
  (`0x10007ef8c`). В AVFoundation уходит **сырой** URL клиента.
- `temporaryDestinationURL` не проверяется вообще и имеет приоритет над
  `destinationURL`.

### Мёртвый entitlement-гейт

В бинаре есть:

```
-[NDAVBackgroundSession hasEntitlementToSpecifyDownloadDestinationURL]  @0x10007e57c
  [[NSXPCConnection currentConnection]
      hasEntitlement:@"com.apple.private.nsurlsession.media-asset-download.can-specify-destination-url"]
```

строка entitlement — `0x1000aaa8e`, CFString — `0x1000d7298`.
Но у метода **нет ни одного call site**: нет селекторного стаба
`hasEntitlementToSpecifyDownloadDestinationURL`, нет `bl 0x10007e57c`.
Т.е. в 27.2 гейт объявлен, но в разобранном пути не применяется.
**Подтверждено статически.**

### Ограничение ущерба

Даже если AVFoundation откроет сырой путь, sandbox-профиль самого
`nsurlsessiond` (`com.apple.private.sandbox.profile:embedded` = `nsurlsessiond`)
разрешает `file-write*` только:

- `.../Containers/Data/<app>/Library/Caches/com.apple.nsurlsessiond*`
- `.../Containers/Data/<app>/Library/com.apple.UserManagedAssets*`
- `.../Library/Cookies/*.binarycookies*`
- `.../Containers/Shared/AppGroup/<group>/Library/Caches/com.apple.nsurlsessiond*`
- `.../Containers/Shared/AppGroup/<group>/Library/com.apple.UserManagedAssets*`
- `.../Media/[<domain>/]Downloads`, `.../Media/[<domain>/]Purchases`,
  `.../Media/[<domain>/]MotionAssets`

Это не произвольная ФС: запись в `/private/var/mobile/Library/SMS/...`,
`/var/mobile/Library/Preferences/...`, чужие `Documents` и т.п. sandbox демона
не разрешает. Но запись в **общие Media Downloads/Purchases** или в
`Caches/com.apple.nsurlsessiond` другого контейнера — вне контейнера app.

---

## 4. `/.nofollow` и TOCTOU

В корне FS 27.2 есть пустой каталог `/.nofollow` (строка 61 `root272_clean_fs.txt`).
Префикс `/.nofollow` используют CoreFoundation (`0x180ac47dc`), FileProvider,
PhotoLibraryServicesCore, MobileAsset. Логика `safeDirectoryForDownloads:`
(realpath → `/.nofollow` + канонический путь) соответствует приёму
«открыть тот же vnode, не разыменовывая symlink»: клиент может подменить
компонент пути после проверки, но повторное открытие через `/.nofollow`
не должно пойти по symlink.

Что **не подтверждено**:

- что `/.nofollow` — именно mount с `MNT_NOSYMLINKS` (в dmg это пустой
  каталог; таблицы монтирования и kernelcache в артефактах нет);
- что AVFoundation при открытии `destinationURL` использует `O_NOFOLLOW`
  или `/.nofollow` (в извлечённом `AVFoundation` строки `nofollow` нет;
  реальный код `AVAssetDownloadSession` в этом образе не локализован);
- что `temporaryDestinationURL` достижим из обычного app **без** прямого
  XPC: публичный `AVAssetDownloadURLSession` его не выставляет, а
  Foundation-клиент шлёт только `destinationURL`. Прямой XPC технически
  возможен (mach-lookup открыт, `_supportsAVAssetDownloads` — клиентский
  флаг), но приём сессии нефреймворковым клиентом не проверялся.

Сценарий-кандидат (не подтверждён): app создаёт
`destinationURL = <свой контейнер>/Documents/x.mov`, проверка родителя
проходит; после проверки app заменяет `x.mov` на symlink в
`/private/var/mobile/Media/Downloads/...`; AVFoundation в демоне открывает
сырой путь и пишет по symlink. Ущерб ограничен списком из §3.

---

## 5. CacheDelete / `deleted`

Бинарь: `System/Library/PrivateFrameworks/CacheDelete.framework/deleted`,
850 384 Б. Энтайтлменты: `com.apple.private.security.storage.AppDataContainers`,
`com.apple.private.MobileContainerManager.lookup = {appData, appGroup, pluginData}`,
`userManagedAssets`, `com.apple.private.CacheDelete = {PURGE, ITEMIZED_PURGEABLE,
CANCEL_PURGE, PERIODIC, SERVICE_REQUEST, ...}`,
`com.apple.private.vfs.entitled-reserve-access`.

Протоколы (декларации в `ipsw macho info --objc`):

- `CacheDeleteClientProtocol`: `clientPurge:replyBlock:`,
  `clientUnifiedPurgeableSpace:queryType:replyBlock:`,
  `clientCancelPurge`, `clientSetState:key:`, `clientGetState:replyBlock:`,
  `clientCheckin:endpoint:info:reply:`, `clientPerformOperation:replyBlock:`,
  `clientPerformServiceRequest:replyBlock:`, `clientRegisterLowDiskFailure:...`.
- `CacheDeletePrivateClientProtocol` (наследник): `queryAppContainers:replyBlock:`,
  `clientGetPendingStorageThreshold:replyBlock:`.
- `CacheDeleteServiceProtocol` (daemon → зарегистрированный сервис):
  `servicePurge:info:replyBlock:`, `servicePurgeable:info:replyBlock:`,
  `servicePeriodic:...`, `serviceCancelPurge`, …

`clientPurge:` по сигнатуре принимает один info-объект (volume/urgency/опции),
а не массив путей; полный дизасм этой ветки не делался. Удаление по путям
выполняют внутренние классы:

- `AppContainerCaches` `0x100020aa4` `+deleteAppCaches:...` —
  на входе `CDPurgeableAppInfo` (bundle id/размеры), пути контейнеров
  резолвятся через MCM (`container_query`), не из клиентского сообщения;
- `CacheDeletePruner` `0x1000425f4` `pruneContainerTmps`,
  `0x100042990` `pruneDir:bundleID:` — обход контейнеров, не произвольный путь;
- `cdVolumeForPath:` `0x1000220b4` / `mountPointForPath:` — только маппинг
  путь → том.

Публичный listener `com.apple.cache_delete.public` доступен из `container`.
`clientPurge:`/`clientPerformOperation:` гейтятся энтайтлментами
(`CLIENT_ENTITLEMENT`, `PURGE_ENTITLEMENT` и т.п.) в
`-[CacheDelete checkSettingEntitlements:onConnection:]` `0x100007bf8` и
`_entitlementToCheck:` `0x100001b7c`; какие именно ключи info-словаря
допускает публичный интерфейс — не подтверждено.

Вердикт: **приёма произвольного пути на удаление из обычного app не
подтверждено; в разобранных публичных entry points путь не принимается.**
Ошибка в резолве контейнера теоретически дала бы удаление чужого кэша, но
такой ошибки в дизасме не найдено. **Не подтверждено** также, что
непривилегированный клиент вообще проходит entitlement-гейт `clientPurge:`.

---

## 6. Итоговый вердикт

| вопрос | вердикт |
|---|---|
| app задаёт `destinationURL`/`downloadFilePath` и демон пишет по нему | **Да, поле принимается**, но для обычной загрузки путь проверяется `sandbox_check_by_audit_token` от имени клиента; при `!isPrivileged` `downloadFilePath` вообще игнорируется |
| проверка принадлежности контейнеру | Не «принадлежность контейнеру», а **права клиента на запись**: `realpath(parent)` + `sandbox_check_by_audit_token(token, "file-write-data", CANONICAL\|POSIX_WRITEABLE)`. Для app это фактически его контейнер/разрешённые им каталоги |
| обход проверки через `sandboxToken`/`sandbox-extension` | В download-пути расширения не потребляются; `sandbox_extension_consume` есть только в upload-пути (`fromFile: sandboxExtensionData:`) — расширение выдаёт сам клиент, демон лишь потребляет его для чтения файла. Для записи вне контейнера не применимо |
| TOCTOU/symlink на `destinationURL` | **Не подтверждено.** Проверяется только родитель; safe URL с `/.nofollow` для AV-пути выбрасывается, AVFoundation получает сырой URL. Нужен дизасм открытия файла в AVFoundation и подтверждение семантики `/.nofollow` |
| `temporaryDestinationURL` | **Не валидируется**, приоритетнее `destinationURL`, уходит в `AVAssetDownloadSession`. Достижим только прямым XPC (не публичным API); приём такой сессии не подтверждён |
| entitlement `can-specify-destination-url` | Метод-гейт есть (`0x10007e57c`), но **не вызывается**; в пути AV-задачи проверки нет |
| запись вне контейнера app обычным app | **Не подтверждено.** Основной путь закрыт проверкой прав клиента + sandbox-профилем демона (запись только в `Caches/com.apple.nsurlsessiond`, `UserManagedAssets`, cookies, `Media/Downloads|Purchases`). Остаётся неподтверждённый AV-symlink/`temporaryDestinationURL`-вектор с ограниченным blast radius |
| CacheDelete удаляет чужой файл по пути от клиента | **Не подтверждено.** Публичный вход — volume/urgency, пути резолвятся демоном через MCM; `cdVolumeForPath:` только маппит том |

### Что проверять дальше

1. `AVAssetDownloadSession`/`AVFCore`: фактические `open/openat` для
   `destinationURL` — есть ли `O_NOFOLLOW`/`/.nofollow`.
2. Прямой XPC-клиент: `createSessionWithConfiguration:...` с
   `_supportsAVAssetDownloads=YES` и вызов
   `avAssetDownloadTaskWith...temporaryDestinationURL:`; проверить, принимает
   ли демон сессию не от Foundation (нет ли проверки клиента/протокола).
3. `deleted`: дизасм `clientPurge:`/`CDService servicePurge:` — какие ключи
   info-словаря доходят до `AppContainerCaches`; есть ли путь в обход MCM.
4. Подтвердить mount-флаги `/.nofollow` по kernelcache/`mount` на живой
   системе.
5. Дотрассировать `copyAndSanitizeClientConfiguration:` при
   `safeDirectoryForDownloads == nil`: подменяется ли клиентский каталог
   загрузки на дефолтный или сырой путь остаётся в конфигурации сессии.
