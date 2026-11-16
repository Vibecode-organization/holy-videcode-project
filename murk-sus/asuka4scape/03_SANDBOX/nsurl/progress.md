# progress — nsurlsessiond / CacheDelete (subagent AP)

- 08:03 извлечён `usr/libexec/nsurlsessiond` из `141-10327-211.dmg`; энтайтлменты через `ipsw macho info --ent` (ldid -e пуст).
- 08:10–08:20 разобран ObjC-метаданные (relative method lists, +8 к imp offset), категория `NDAVAdditions`; найдены `safeURLForDownload:auditToken:` и `safeDirectoryForDownloads:auditToken:`.
- 08:21 извлечены `libsystem_sandbox`, CFNetwork, Foundation, CoreFoundation, AVFoundation; подтверждены флаги SANDBOX_CHECK и обработка в `_sandbox_check_common`.
- 08:24 извлечён `CacheDelete.framework/deleted`; протоколы `CacheDeleteClientProtocol` / `CacheDeleteServiceProtocol`, `AppContainerCaches`, `CacheDeletePruner`.
- 08:30 подтверждено: `container` профиль разрешает mach-lookup `com.apple.nsurlsessiond` и `com.apple.cache_delete.public`; профиль `nsurlsessiond` ограничивает file-write* узким набором путей.
- 08:40 ключевой дизасм: `safeDirectoryForDownloads` (realpath + sandbox_check_by_audit_token + `/.nofollow`), `_URLSession:openFileAtPath:` → клиентский `openFileAtPath:mode:withReply:`, AV `temporaryDestinationURL` без проверки, `hasEntitlementToSpecifyDownloadDestinationURL` без call sites.
- 08:50 написан `REPORT.md`; вердикт: запись/удаление вне контейнера обычным app не подтверждены; основной путь закрыт проверкой прав клиента + sandbox демона; AV-symlink/`temporaryDestinationURL` — не подтверждённые кандидаты с ограниченным blast radius.
