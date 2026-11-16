# KRWProbe — dev bundle

Что внутри:
- `theos/` — полный Theos SDK (собранный), с `sdks/`, `makefiles/`, `vendor/`, `bin/`.
- `probe/` — исходники приложения (main.m, Makefile, Info.plist, entitlements.plist) и собранный IPA в `probe/out/`.
- `design/` — макет интерфейса.
- `reports/` — вся аналитика: ABI user client'а, аудит фиксов ядра 27.2, аудит валидатора IOSurface, F1, COW, отчёты по прогонам.
- `scripts/` — инструменты: Ghidra-скрипты, диффы Mach-O, идентификация функций.

Сборка:
```
cp -a probe/KRWProbe /tmp/krwprobe      # Theos не любит пробелы в пути
cd /tmp/krwprobe && make ipa            # IPA появится рядом
```
Требуется `ldid` (в бандле не лежит): https://github.com/ProcursusTeam/ldid

Приложение: iOS 14.0+, arm64, без энтайтлментов. Подпись — своим Apple ID.
