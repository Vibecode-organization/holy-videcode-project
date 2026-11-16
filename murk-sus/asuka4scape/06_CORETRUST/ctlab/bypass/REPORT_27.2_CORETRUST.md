# 27.2 / 24B115 — CoreTrust: полный байпас не получен. Точная карта стены

Дата: 2026-11-09. Устройство: iPhone14,7 (D27AP, A15/t8110), iOS 27.2 RC, build
24B115. UDID `REDACTED-UDID`. Устройство спарено, установка IPA
доходит до стадии `VerifyingApplication`.

## 0. Вердикт

Полный CoreTrust-байпас (TrollStore-класс: установка приложения с
`platform-application` без профиля) на этой сборке **не подтверждён**. Известная
цепочка CVE-2023-41991 (два подписанта CMS) закрыта на уровне **Security**, до
CoreTrust. Три независимых барьера проверены на телефоне и подтверждены логами:

1. `Security` требует ровно одного подписанта CMS:
   `CMS message has 2 signers, expected 1` → `-25293` → `0xe8008001`.
2. Донорский App Store leaf из шаблона ChOma истёк **14.08.2021**; на 2026
   `SecTrust` валит `iPhoneApplicationSigning` по `LeafMarkerOid`/`SubjectCommonName`.
   Перевод часов через lockdown на активированном iOS невозможен
   (`idevicedate`: setting time is only supported in the setup wizard).
3. `SecTrust` оценивает **сертификат подписанта** (`sid`), а не первый сертификат
   набора. Поэтому перестановка цепочки (App Store leaf первой, dist leaf первой)
   не помогает: подписант-самозванец всё равно не проходит `AnchorApple`.

Единственный Apple-подписанный ключ, который есть, — `iPhone Distribution:
Mustafa Muhammad (8F9U9JSYJ9)`. Он проходит trust, но политика distribution
требует provisioning profile, а профиль не содержит `platform-application`:
   - с приватными entitlements и профилем → `0xe8008015` (valid provisioning
     profile not found);
   - без профиля / с чужой цепочкой → `0xe8008019` (invalid signature).

## 1. Что именно проверено на устройстве

### 1.1. Историческая двухподписантная CMS

Собрано: `artifacts/ctlab-bypass2.ipa` — main CD = реальный App Store
CodeDirectory (SHA1, донор `com.icraze.gtatracker`), alternate CD = наш SHA256 CD
(platform-application, no-sandbox, AMFI entitlements), CMS = App Store signer +
TrollStore CA signer, hash agility второго подписанта указывает на наш CD.

Установка:
```
ApplicationVerificationFailed: ... 0xe8008001 (An unknown error has occurred.)
```
Syslog (`artifacts/syslog_dist.log` / `syslog_prof.log`):
```
mobile_installation_proxy{Security}: CMS message has 2 signers, expected 1
mobile_installation_proxy{Security}: verifySignatureEmbeddedPolicy: verification failed
mobile_installation_proxy{Security}: MacOS error: -25293
```
То есть фикс стоит в CMS-декодере Security, а не в логике CoreTrust.

### 1.2. Один самоподписанный подписант + App Store chain первой

Собрано: `artifacts/ctlab-time.ipa` — один SignerInfo (TrollStore CA,
valid 2019-01-01..2021-12-31), набор сертификатов
`[Apple iPhone OS Application Signing, Apple iPhone CA, Apple Root CA, TrollStore CA]`,
hash agility = `[SHA1(AppStore CD), SHA256(наш CD)]`.

Проверка на текущих часах (2026) и с dist-first вариантом
(`artifacts/ctlab-distfirst.ipa`, первый сертификат — валидный distribution leaf):
```
Trust evaluate failure: [leaf IssuerCommonName LeafMarkerOid SubjectCommonName]
```
То есть порядок сертификатов не решает: trust идёт по подписанту, а не по первому
сертификату набора. Часы вернуть нельзя, поэтому истёкший App Store leaf не
спасти.

### 1.3. Distribution signer + profile

Собрано: `artifacts/ctlab-prof.ipa` — подписант = реальный distribution leaf
(8F9U9JSYJ9), cert set = App Store chain первой + distribution chain, профиль
ipa_dark внутри, entitlements = профильные + `platform-application`/AMFI.

```
Trust evaluate failure: [leaf IssuerCommonName LeafMarkerOid SubjectCommonName]
... 0xe8008019 (The application does not have a valid signature.)
```
Без приватных entitlements тот же профиль ставится (ctoracle), с
`platform-application` — отказ. Профиль ограничивает entitlements, а не только
подпись.

### 1.3a. Наш CD как main CD + distribution signer + App Store chain

Собрано: `artifacts/ctlab-prof2.ipa` (App Store CD как main, team переписан на
8F9) и `artifacts/ctlab-prof3.ipa` (наш SHA256 CD как main, distribution
signer, App Store chain в cert set, профиль). Логика: `SecStaticCode` видит
наши page hashes, `SecTrust` — валидный distribution signer с профилем,
CoreTrust — App Store chain впереди.

Результат тот же:
```
Trust evaluate failure: [leaf IssuerCommonName LeafMarkerOid SubjectCommonName]
Using Provisioning Profile '<private>'
... LibMISErrorNumber=-402620391 ... 0xe8008019
```
То есть наличие App Store chain в наборе само по себе ломает trust/signature
проверку, а без него distribution-политика упирается в entitlement-гейт профиля.

### 1.4. Системные бинарники как донор

Из rootfs 24B115 вытащен `/usr/bin/vm_stat` (APFS, 7z). Подпись:
`flags 0x2` (adhoc), `CSSLOT_SIGNATURESLOT` пустой (8 байт). Системные бинарники
на этой сборке trust-cached/ad-hoc, а не CMS-подписаны, поэтому как App Store
донор не годятся.

### 1.5. AMFI user client из обычного profile-приложения

Собран `artifacts/ctprobe2.ipa` (profile-only entitlements, без приватных).
Запуск: `pymobiledevice3 developer dvt launch --stream <bundle>` через no-root
userspace tunnel. Приложение реально работает (uid 501, sandbox):

```
AMFI service=0x6533
IOServiceOpen(AMFI) -> 0xe00002e2 conn=0x0
```

`0xe00002e2` = `kIOReturnNotPermitted`: AMFI user client не открывается
sandbox-приложению, trust-cache-путь с платформенным флагом закрыт на open.
Песочница режет и prefs: `write /var/mobile/Library/Preferences/... -> 0`.

### 1.6. CoreTrust/libmis policy oracle

`libmis.dylib` экспортирует `CTEvaluateAMFICodeSignatureCMS`, `CTEvaluateSavageCerts`,
`CTEvaluateCertsForPolicy`, `CTEvaluatePragueSignatureCMS`. Обычное profile-приложение
вызывает их напрямую. Результаты на 27.2:

| CMS | r | policy | digest |
|---|---|---|---|
| реальный App Store template | 0 | **0x100** | 937219c3… (signed 9.2) |
| custom CA signer + App Store chain первой | 0 | 0 | наш 32b |
| distribution signer + App Store chain первой | 0x2000b | 0 | — |
| two-signer (App Store + TrollStore/time CA) | 0x70002 | 0 | — |
| App Store template + unsigned 9.2 с нашим digest | 0 | **0x100** | 937219c3… (unsigned проигнорирован) |
| App Store template + duplicate signedAttrs (наш 9.2) | 0x30105 | 0 | — |
| App Store + fake leaf с тем же issuer/serial (наш ключ) | 0xa0120 | 0 | — |

Выводы, доказанные на устройстве:

- CoreTrust-политика **не смотрит на срок сертификата**: App Store template
  (leaf истёк в 2021) даёт `policy=0x100` в 2026.
- Политика идёт по **подписанту**, а не по первому сертификату набора;
  App Store chain первой с custom/dist signer не даёт App Store policy.
- Два подписанта режет **и libmis** (`0x70002`), не только Security.
- `unsignedAttrs` с 9.2 не читаются: digest остаётся подписанным (донорским).
- Distribution signer без профиля/с чужой цепочкой — `0x2000b`, policy 0.

Итого: единственный источник App Store policy — App Store **signer**, а его
hash agility — донорский CD. Чтобы получить policy 0x100 + **наш** cdhash,
нужен либо второй подписант (закрыт в libmis), либо новый parser/logic bug,
либо валидный App Store signing key.

## 2. Почему это не «ещё чуть-чуть»

- Мультиподписант закрыт явной проверкой количества подписантов в Security.
- App Store leaf из публичного шаблона ChOma истёк в 2021; на активированном
  iOS 27.2 часы через lockdown не меняются, а Settings — ручная операция.
- Даже с валидным App Store leaf на 2021 год нужен **второй подписант** с нашим
  CD hash: одного App Store подписанта недостаточно, его hash agility указывает
  на донорский CD, а не на наш.
- Любая перестановка cert set не меняет trust: он привязан к `sid`.
- Distribution-ключ есть, но его политика профильная; приватные entitlements
  профиль не разрешает.

## 3. Что остаётся реальными направлениями

1. **Parser differential** между CMS-декодером Security и парсером, который
   передаёт сертификаты в CoreTrust/AMFI: один подписант для проверки количества,
   два — для hash agility, либо разные наборы сертификатов. Это новый баг, не
   продолжение CVE-2023-41991.
2. **Свежий App Store CMS** (валидный leaf 2026) + контроль hash agility. Нужен
   либо оригинальный App Store IPA с валидной подписью, либо Apple-подписанный
   CMS, у которого можно подменить hash agility без инвалидации подписи.
3. **Kernel/AMFI primitive** для прямой загрузки trust cache (как в TrollStore
   после установки): тогда CoreTrust-подпись не нужна, но нужен kernel r/w или
   платформенный entitlement.
4. **Ручной перевод часов в Settings на 2021-06-01** и повтор `ctlab-time.ipa`
   имеет смысл только если найдётся Apple-подписант, валидный в 2019–2021, с
   нашим ключом. Такого ключа в наборе нет; текущий distribution-ключ в 2021
   ещё не валиден.

## 4. Артефакты

В `06_CORETRUST/ctlab/bypass/artifacts/`:

| Файл | Что |
|---|---|
| `ctlab-bypass2.ipa` | двухподписантная CMS (историческая схема) |
| `ctlab-time.ipa` | один CA-подписант + App Store chain, valid 2019–2021 |
| `ctlab-distfirst.ipa` | первый сертификат — валидный distribution leaf |
| `ctlab-prof.ipa` | distribution signer + реальный профиль + приватные entitlements |
| `ctlab-dist.ipa` | distribution signer без профиля |
| `syslog_*.log` | сырые логи installd/Security/trustd по каждой попытке |
| `build_bypass.py`, `build.py` | сборщики CMS/CD/IPA |

Сборщик подписывает bundle, считает SHA1+SHA256 CodeDirectory, пишет
`_CodeSignature/CodeResources`, собирает superblob и правит `__LINKEDIT`.
Команда установки:
```
USBMUXD_SOCKET_ADDRESS=/proc/<usbmuxd-pid>/root/run/usbmuxd \
  pymobiledevice3 apps install <ipa>
```

## 5. Честная граница

Проверено на живом устройстве, не по README: количество подписантов, trust по
`sid`, истёкший донорский leaf, профильный гейт distribution, ad-hoc системные
бинарники. Не получен: новый CMS parser bug, валидный App Store CMS 2026,
kernel/AMFI primitive. Всё, что можно было выжать из известной цепочки на этой
сборке, выжато; дальше — новый баг, а не перебор флагов.
