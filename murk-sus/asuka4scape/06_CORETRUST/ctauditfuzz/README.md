# CoreTrust / iOS 27.2 (24B115, iPhone14,7) — итог сессии 2026-11-09

## Что проверено на железе (не теория)

Устройство: iPhone 14 (D27AP, T8110), iOS 27.2, build 24B115.
Инструменты: свой подписчик (`ctsign.py`), on-device oracle (`ctoracle`),
install-path тесты через `pymobiledevice3`.

### 1. Свой signer работает
`v4.ipa` — собственный CodeDirectory + CMS (наш p12, Apple-цепочка) — установлен:
`Installation succeed`.
Сверено с эталоном: при `pad=0x9000` CD-хэш совпадает с Apple-CD
(`7bac38b03977a3b90c127e640f6f07709bb2713b992654794ea3a1a2330c6f69`).

Две ловушки, которые давали `0xe8008019`:
- последний code-slot хэшируется **без паддинга** до страницы;
- `LC_CODE_SIGNATURE.datasize` должен быть кратен 0x1000, файл должен
  содержать ровно эту область (иначе CD не сходится с файлом).

### 2. On-device oracle
`ctoracle` через `dlsym` дергает `CTEvaluateAMFICodeSignatureCMS` из
`/usr/lib/libmis.dylib` и логирует ret/policy/cdhash.
- реальная цепочка: `ret=0x0`, `policy=0x10000` (IPHONE_DISTRIBUTION),
  cdhash = 7bac38...
- фейковая цепочка: `0x70002` / `0xa0120` / `0x2000b`.

### 3. Encoding, который режет CoreTrust
Сертификаты с `sha256WithRSAEncryption` **и NULL-параметрами** умирают в
парсере (`0xa0120`). Apple кодирует параметры **отсутствующими**.
После пересборки с absent-params фейковая цепочка доходит до identity-гейта
(`0xe8008018`), т.е. парсер и подпись проходятся.

### 4. Настоящие гейты 27.2 (по логам trustd/installd)
1. **trustd**: политика `iPhoneProfileApplicationSigning`, провал
   `[leaf AnchorApple IntermediateMarkerOid LeafMarkerOid] [root AnchorTrusted]`.
   Фейковый корень не проходит — нужен настоящий Apple-анкер.
   С реальным Apple-сертом trustd проходит (result 5 tolerated).
2. **Профиль**: с реальным сертом и лишними entitlements —
   `0xe8008015` ("A valid provisioning profile ... was not found").
   `platform-application` вне профиля не ставится.
3. **Multi-signer**: два SignerInfo в одном CMS — `0x2000b` (запрещено,
   фикс CVE-2023-41991).
4. **Agility**: dual-CD (SHA1 main + SHA256 alt, agility на alt) —
   `0xe8008019`/`0xe8008001`. Agility обязан сходиться с проверенным CD.

### 5. App Store vs Distribution
Из реального App Store CMS (`TemplateSignatureBlob.h`, ChOma):
лист — CN `Apple iPhone OS Application Signing`, O `Apple Inc.`,
маркер **1.2.840.113635.100.6.1.3**.
Distribution-маркер (mkct) — 6.1.2. Политика листа берётся из его расширений,
CN-гранты (`0xf00` для `Apple iPhone Certification Authority`) применяются
только к промежуточным/корневым сертам (в `FUN_94c8638` вызов `94c8c04`
идёт при `uVar14 != 0`).

## Вывод

Логического CoreTrust-байпаса на 27.2 нет: цепочка проверяется
криптографически до pinned Apple-корня с проверкой подписи анкера ключом
из pin-таблицы, multi-signer запрещён, agility привязан к проверенному CD,
а установку независимо валидирует trustd по `AnchorTrusted`.
Фейковая цепочка не ставится by design, реальная distribution-цепочка
упирается в профильные entitlements.

Остаётся один путь к полному байпасу — **memory corruption в парсере
CoreTrust** (kext/ libmis, достижим из amfid/installd). Для него готов
in-process фаззер в `ctoracle/main.m` (мутации реального CMS, сохранение
`last.cms` перед каждым вызовом, лог прогресса).

## Артефакты
- `ctsign.py` — подписчик (CD+CMS, Apple-раскладка)
- `mkmulti.py` — dual-CD/duplicate-blob суперблоб
- `mkmultisigner.py` — CMS с несколькими подписантами
- `mkappstore.py` — фейковая App Store-цепочка (absent params, маркер 6.1.3)
- `mkcase.py`, `mkcase2.py` — генераторы тест-кейсов
- `fake_test.py`, `splice_cms.py`, `resign_cms.py` — сборка IPA/сплайс CMS
- `main.m` — oracle + фаззер
- `f7sys.log`, `f8sys.log` — логи trustd/installd по фейковым цепочкам
- `oracle_now.log`, `ms.log` — вывод oracle

## Следующий шаг
Телефон должен быть стабильно на USB с валидным pairing (сейчас pairing
слетает: `lockdownd Mux error -8`, USB-интерфейс держит чужой usbmuxd).
После этого:
1. залить `fuzz.cms` (реальный CMS) + `fuzz.on` в Documents `ctoracle`;
2. запустить, гонять мутации, собирать `last.cms` и crash-логи;
3. найденный crash в libmis → воспроизвести через install (amfid) → эксплойт.

---

## Sandbox escape — сессия 2

### Реальная поверхность из sandbox (живой bootstrap_look_up)
`services.txt` — 560 имён из `container.sb` (27.2), из них **339 доступны**
(см. `reachable.txt`). Ключевые:
- `com.apple.accessibility.AXBackBoardServer` — доступен lookup;
- `com.apple.mobile.installd` — доступен lookup (операции требуют allowedSPI);
- `com.apple.mobileassetd(.v2)`, `com.apple.tccd`, `com.apple.securityd`,
  `com.apple.trustd`, `com.apple.springboard.services`,
  `com.apple.backboard.hid.services`, `com.apple.cache_delete.public`,
  `com.apple.lsd.openurl`, `com.apple.pasteboard.pasted`,
  `com.apple.iconservices`, `com.apple.browserkitd`, `com.apple.sharingd.nsxpc`.

### AX — проверено на железе
`AXUIElementCreateSystemWide` из AXRuntime работает (элемент создаётся),
но `AXUIElementCopyAttributeValue("AXFocusedApplication")` → **-25216**,
т.е. сервер режет клиента по доверию (accessibility entitlement/TCC).
Lookup ≠ доступ. См. `ax2.log`.

### Вывод по escape
Логических дверей в CoreTrust нет (см. выше). Sandbox пускает к 339 сервисам,
но каждый проверяет клиента по audit token/entitlements. Полный escape
на 27.2 = 0-day в одном из этих сервисов (parser/memory) либо kernel-0day.
Кампания: fuzz приоритетных парсеров (iconservices/browserkitd/lsd/openurl,
mobileassetd, cache_delete) из sandbox, триаж crash-логов.
