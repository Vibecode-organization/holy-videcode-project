# svc_map — карта Mach/XPC-сервисов для обычного приложения (iOS 27.2, 24B115)

## step 1 — вход
- `sb272/all.json` = 293 профиля (name/default_decision/sbpl). Парсер s-выражений `sbparse.py` (токенайзер с балансировкой скобок, `#"..."` regex-литералы, `;`-комментарии).
- 106 правил `mach-lookup`: 60 с энтайтлментом, 13 с profile-flag, 1 только `disable-enforcement`, 32 открытых. 600 уникальных имён.

## step 2 — что реально видит приложение
- `container.sb:13159..13631` — одно `(allow mach-lookup (require-any ...))`: 3 `extension` + 463 `global-name` + 48 `xpc-service-name` плоским списком. В `require-any` имя — самостоятельная альтернатива, значит всё это доступно без энтайтлментов.
- Калибровка: `com.apple.mobile.installd` (стр. 13515) в том же блоке, доступность подтверждена аудитом AK.
- `containermanagerd` — отдельное правило под `common-containermanagerd-rules` (flag, не app-энтайтлмент) → в основной список не попал.
- `installcoordinationd` в `container`/`baseline` отсутствует; он только в `appconduitd`/`appstored`.

## step 3 — привязка к бинарям
- Из `rc115/out272_clean/141-10327-211.dmg` вынуты 689 launchd-плистов (`7z x`, один проход). `MachServices` → 2414 имён, 331 из 463 привязаны, 174 уникальных бинаря.
- Размеры — из `root272_clean_fs.txt` (262913 записей), без распаковки.

## step 4 — энтайтлменты
- `ldid -e` на 27.2 — пусто (DER-only). Написан `ent.py`: LC_CODE_SIGNATURE → SuperBlob (big-endian) → CSSLOT_ENTITLEMENTS, снято 173/174 бинаря (`exe_ents.json`).

## step 5 — сироты
- 132 имени без launchd-плиста: 103 бинаря-кандидата вынуты, `grep -aF` по каждому; плюс сплошной grep по 9.1 ГБ DSC.
- Итог: 42 правила без хоста нигде (мёртвые), 15 — хост есть, имя не подтверждено, остальные — XPC-сервисы в бандлах/динамические порты.

## step 6 — топ-8
- passd, managedappdistributiond, mediaanalysisd, maild, nsurlsessiond, deleted, searchd, ThumbnailsAgent. Для каждого: размер, энтайтлменты, протоколы, селекторы (`profile_*.txt`).

## step 7 — выхлоп
- `REPORT.md` (639 строк): полная таблица 463 + 48 xpc, топ-8, 42 мёртвых, гейтованные, «не подтверждено».
- Запись в `CHAT_дипсики.md` добавлена.

## Открыто
- Гейты на входе в listener у топ-8 (аудиотокен/энтайтлменты) — дизасм не делался.
- Валидация `destinationURL` (nsurlsessiond) и `cdVolumeForPath:` (deleted) — по строкам не видно, не доказано.
- Криптекс в образе — симлинк; хост мёртвых имён там не исключён.
- `xpc-service-name` из списка 48 — сервис есть, фильтрация клиента внутри не смотрелась.
