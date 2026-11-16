# progress — installcoordinationd (subagent AJ)

- [x] Достал `installcoordinationd` из root FS 27.2 (`System/Library/PrivateFrameworks/InstallCoordination.framework/Support/installcoordinationd`),
  снял entitlements (ldid-парсер): `mobileinstall.allowedSPI` (PrepareAppReplacement, SetAppReplacementStatus,
  RemoveAppReplacementState, InstallForInstallCoordination...), `MobileContainerManager.allowed`,
  `installcoordination.app-data-migration.host`.
- [x] Sandbox: в `container` (all.json 27.2) нет ни одного `allow mach-lookup` на `com.apple.installcoordinationd`
  (и `com.apple.InstallProgress.xpc`); `com.apple.mobile.installd` — есть (общий allow-лист 515 записей);
  `com.apple.containermanagerd(.system)` — через `common-containermanagerd-rules`, открыт всем.
- [x] XPC-гейты replacement: `_IXHasTrueValueForEntitlement(xpcConnection, ...)`:
  ReplaceApp (0x100069cb0, 0x100069fb4), GetAppReplacementSource (0x100069540),
  AppReplacementRefused (0x1000697b8), ResetAppReplacementState (0x100069a30).
- [x] Координатор читает `com.apple.developer.superseded-application-identifiers` (Swift 0x10008da00,
  add #0xd30 @0x10008dd58); конфликт двух кандидатов — `%s and %s both supersede %s` (0x10008e49c).
- [x] Резолвер: `-[IXAppReplacementSourceResolver resolveAppReplacementSource:...]` @0x1c2fe5844,
  фильтры `_appIsHidden:`, `_appIsRestricted:`, `_personaForIdentity:record:error:`.
- [x] Контейнеры: `canSupersedeContainer` -> `com.apple.private.MobileContainerManager.supersede`
  (CFString 0x26a1fc620 -> 0x207f1d252); `isAllowedToSupersedeContainer` = `allowed` || `canSupersede`;
  план supersede — только класс + пользователь (0x207f0569c / 0x207f05738); чужой lookup — `otherIDLookup`
  в `isAllowedToPerformOperationType:` (0x207e10d90).
- [x] `libcontainer` в 27.2 отсутствует; C-API (`_container_replace`, `_container_operation_copy_superseded`)
  в `libsystem_containermanager.dylib`; `supersedeExistingContainer:error:` — в `InstalledContentLibrary`
  (`MIMCMContainer` 0x1ab4c9910, `MIDataContainer` 0x1ab50e44c), клиент проверяет только валидность
  predecessor/successor (`SPI MISUSE`), решение — за демоном.
- [x] Проверил держателей `InstallCoordination.ReplaceApp`: нет у installd, containermanagerd,
  appstored, appconduitd, managedappdistributiond, installcoordination_proxy (у последних четырёх
  только `InstallCoordination.allowed`). Кто держит — открыто.
- [x] Отчёт: `REPORT.md`.

Осталось (не подтверждено): полная семантика Swift-функции 0x10008da00 (что делает с массивом),
сверка team id / application-identifier source vs destination в резолвере, проверка владельца
контейнера внутри `MCMCommandSupersedeExecutor`.
