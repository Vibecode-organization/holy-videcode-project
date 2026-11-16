# SBX — sandbox-escape probe / 27.2 (24B115)

Приложение `SBX` и варианты подписи. Каждая проверка внутри — **реальный** syscall/API;
логи не выдуманы. Результат пишется в `Documents/escape.log` (включён UIFileSharing,
видно в Files) и на экран.

## Варианты IPA

| файл | подпись | что проверяет |
|---|---|---|
| `SBX.ipa` | ldid ad-hoc + полные entitlements, без `_CodeSignature` | подписать своим сертификатом/профилем; если инструмент умеет `-e`, дать `entitlements.plist` |
| `SBX_adhoc_full.ipa` | zsign ad-hoc + полные entitlements + `_CodeSignature` | поставить напрямую (`ideviceinstaller -i`); если device принимает ad-hoc + entitlements (developer mode / local signature) — app вне песочницы |
| `SBX_sym.ipa` | zsign ad-hoc + полные entitlements + symlink'и | install-time symlink: `sbx` → `../../../../../../../private/var/mobile/Library/Preferences`, `sbx_abs` → абсолютный; в `Info.plist` ключ `com.apple.MobileInstallation.WorkaroundBundleSymlinkName=sbx` |
| `ent_min.plist` | — | минимальный набор (`platform-application`, `get-task-allow`) для более безопасного теста |

## Что означает лог

* `csops(ents)` — если в списке есть `platform-application`, подпись с этим entitlement принята.
* `open(/private/var/mobile/Library/Preferences/...) OK` — приложение читает **вне** контейнера.
* `LIST /private/var/containers/Bundle/Application OK` — видит чужие бандлы.
* `SPAWN /bin/ls OK` — `posix_spawn` вне песочницы.
* `task_for_pid(launchd=1) -> kr=0` — есть task port launchd (полный контроль userland).
* `IOSurface sel26 -> kr=0` и qword `0xfffffff...` — сработал `com.apple.private.iosurfaceinfo`.
* `container_query(com.apple.Preferences, Data) -> path` — доступ к чужому контейнеру.

Если все строки — `FAIL`, приложение осталось в `container`; если `OK` — это и есть
sandbox escape, без фейков.

## Установка

1. Разблокируй телефон, developer mode включён.
2. Попробуй `SBX_adhoc_full.ipa` напрямую:
   `ideviceinstaller -i SBX_adhoc_full.ipa`
   (или через свой установщик, **не переподписывая**).
3. Если install rejected — подпиши `SBX.ipa` своим сертификатом; если инструмент
   поддерживает entitlements, передай `entitlements.plist` (или `ent_min.plist`).
4. `SBX_sym.ipa` — отдельный тест install-time symlink; если install падает,
   это ответ установщика, а не лог приложения.

## Исходники

`main.m` — все проверки; `Info.plist`; `Makefile` (Theos). Сборка:
`make ipa` (путь без пробелов; Theos не любит пробелы).

## Честная граница

Это **не** готовый эксплойт с гарантией. Это проверка трёх дверей: local/ad-hoc
подпись с entitlements, install-time symlink по `WorkaroundBundleSymlinkName`,
и доступ к чужим контейнерам. Если дверь закрыта — лог покажет `FAIL`/ошибку
установки. Если открыта — лог покажет `OK` и реальный доступ.

## 11:48 — LOOKUP (global IOSurface)

`IOSurfaceRoot` из app sandbox открывается (`KRWProbe: kr=0x0`), значит публичный
`IOSurfaceLookup` доступен. В SBX добавлен `try_surface_lookup`:
`IOSurfaceLookup(1..65535)` → для каждой найденной surface логирует id, width, height,
bytesPerRow, allocSize, pixelFormat, base; `IOSurfaceLock(kIOSurfaceLockReadOnly)` +
`IOSurfaceGetBaseAddress` + первый байт.

Если найдётся **системная/global** surface (например 2560x1170 BGRA) — приложение
может читать (и потенциально писать) её: это экран/framebuffer, т.е. выход из
app sandbox в чужую/системную поверхность. Это не root/kernel, но реальный
cross-app доступ. `sel 26` (kernel pointer) по-прежнему заперт `iosurfaceinfo`.

Ставить: `SBX.ipa` переподписать своим сертификатом (lookup не требует entitlements),
либо `SBX_adhoc_full.ipa` напрямую (если AMFI примет ad-hoc+entitlements).
Лог: `Documents/escape.log`, строки `LOOKUP ...`.
