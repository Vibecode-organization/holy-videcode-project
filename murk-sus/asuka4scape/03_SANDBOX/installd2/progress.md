# installd2 — subagent AI (app replacement, 27.2 vs 27.0)

## step 1 — вход
- `work/installd2/` не существовал, создан. Бинарники: `root272/installd` (961 888 Б) и `root270/installd` (928 032 Б), arm64e, decrypted rootfs.
- Инструменты: `ipsw 3.1.736` (macho disass/class-dump/dyld extract/str), `capstone 5.0.7`, `llvm-objdump`, `ldid-amd64`, `7z 26.03`.
- `ldid -e`: entitlement-наборы 27.2 и 27.0 идентичны.

## step 2 — XPC и гейты
- `ipsw class-dump`: 97 методов `MIClientConnection` в 27.2, 91 в 27.0.
- Найден центральный гейт `_ValidateMIAllowedSPIEntitlement` (`0x10001c7c4` в 27.2, `0x10001adc8` в 27.0): `allowedSPI` как строка или массив, `containsObject:`.
- Автомат по всем `bl` гейта: 50 вызовов в 27.2, 43 в 27.0. Новые 7 — ровно 6 replacement-методов (`end...` требует два ключа).
- `MobileInstallationServiceDelegate` `0x10001b280` принимает любое соединение без проверки audit token.

## step 3 — sandbox и держатели SPI
- `sb272/baseline.sb`: `(deny default)`, `(deny mach*)`, `(deny mach-lookup)`; `com.apple.mobile.installd` в allow-листах нет.
- `sb272/all.json`: имя сервиса только у 10 daemon-профилей (appstored, gamed, bird, lockdownd, appconduitd, streaming_zip_conduit, maild, container, AirTraffic, CommCenter).
- `ldid -e`: все 4 replacement-ключа только у `installcoordinationd`; у остальных даемонов их нет. Helper service accept-гейт — `com.apple.private.MobileInstallationHelperService.allowed`.

## step 4 — MIAppReplacementOperation
- `prepareWithError:` `0x100018ef0`: offline signing info нового бандла → `com.apple.developer.superseded-application-identifiers` только «непустой массив строк» (`sub_1000617d8`); сверки с source app id/team id нет.
- Source: `saveAppLaunchProhibition` (`0x1000190b0`). Dest: `MIAppReplacementState(status=3, source)` (`0x10001914c`). Handover: `supersedeExistingContainer:` (`0x100019794`), расширения — по маппингу из `appExtensionBundlesWithError:` (`0x100019928`/`0x10001996c`).
- Путей из клиента нет: только контейнеры и фиксированные `AppReplacementState.plist` / `AppLaunchProhibition.plist` в bundle-контейнере.

## step 5 — симлинки/App Clips и diff
- `validateSymlinksInURLDoNotEscapeURL:` в `MIInstaller` не изменился (27.0 `0x1000313ec`, 27.2 `0x1000351c8`).
- 27.2 добавил App Clips management-domain проверки (`com.apple.AppClips`, wrapper-bundle) — только валидация.
- Diff: 0 строк `replacement` в 27.0 → 79 в 27.2; +3 класса, +6 XPC-методов, +7 гейтов, `__text` +28 272 Б.

## step 6 — результат
- `REPORT.md` записан: таблица входов/гейтов/вердиктов, дизасм ключевых функций, список недоказанного.
- Итог: из обычного приложения replacement недостижим (sandbox + allowedSPI); единственный клиент — installcoordinationd; внутри installd нет сверки пары «кто кого замещает».
