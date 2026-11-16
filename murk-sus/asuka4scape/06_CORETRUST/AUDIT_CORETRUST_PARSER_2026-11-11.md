# Аудит парсера CoreTrust — первый проход (2026-11-11)

Устройство/сборка: iPhone14,7 (D27AP, A15), iOS 27.2, build 24B115.
Артефакты: `coretrust_decomp.txt`, `libmis_full_decomp.txt`, `kext115/com.apple.kext.CoreTrust`,
Ghidra-проект `123.rep` (kernelcache.release.iphone14b).

## 0. Короткий итог

1. **«Непиннутый корень» — это не баг, а test hierarchy.**
   Ветка `FUN_94c2bd8` / `FUN_94c2bd4` / `FUN_94c2e68` вызывает `FUN_94c264c` с
   `param_4 = 0`, из-за чего `FUN_94c82cc` получает `param_4 ^ 1 = 1` и принимает
   любой unpinned root. Но этот `param_4` — **явный флаг `allowTestHierarchy`**,
   который передаёт вызывающий (libmis/Security), а не поле из CMS/подписи.
   В `_CTEvaluateAMFICodeSignatureCMS_MaxDigestType` он кладётся в опции
   `_X509ChainCheckPathWithOptions` (`local_69f = param_5`). Штатный AMFI-путь
   передаёт 0; 1 — только тестовый режим.
2. **DER/X.509-парсер kext’а в первом проходе выглядит защищённым.**
   Все длины, которые я разобрал, проверяются на CARRY8/границы/точный конец;
   явных OOB/overflow не найдено. Это не доказательство отсутствия багов, но
   «низко висящего» логического байпаса здесь нет.
3. **Оставшийся реалистичный путь — memory corruption в CMS/SignerInfo-парсере**
   (`_CMSParseContentInfoSignedData`, `_CMSParseSignerInfos` в Security.framework,
   вызываются из libmis), либо в `FUN_94c7a20`/`FUN_94c8638` (проверка подписи
   цепочки). Это уже фаззинг, а не чтение декомпилятора.

## 1. Как шёл разбор

Цепочка вызовов от userland:

```
CTEvaluateAMFICodeSignatureCMS (libmis, 0x226045a70)
  -> _CTEvaluateAMFICodeSignatureCMS_MaxDigestType (0x226045700)
     -> _CMSParseContentInfoSignedData
     -> _CMSParseSignerInfos(..., _validateSignerInfoAndChain)
        -> _X509ChainCheckPathWithOptions(0x1d, 7, chain, options, err)
```

В kext:

```
FUN_94c264c  — главный вход (CMS blob + policy)
  FUN_94c8058 — разбор до 4 сертификатов в массив 4 * 0x130
    FUN_94c6be4 -> FUN_94c6ac4 -> FUN_94c5408 (X.509 tbsCertificate)
  FUN_94c82cc — построение цепочки issuer/subject + pinned root
  FUN_94c8638 — проход по цепочке, OID, подпись, flags
  FUN_94c8c04 — классификация по subject-строке CA
```

## 2. Finding: allowTestHierarchy (закрывает старый лид)

В `libmis_full_decomp.txt`:

```c
void _CTEvaluateAMFICodeSignatureCMS_MaxDigestType(..., undefined1 param_5, ...)
{
    ...
    local_69f = param_5;                 // options byte
    _X509ChainCheckPathWithOptions(0x1d, 7, &chain, &local_6b0, &local_678);
}
```

`param_5` — это пятый аргумент публичной функции, то есть `allowTestHierarchy`
(см. прототип в `ctoracle/main.m`).

В kext:

```c
// strict wrappers: FUN_94bee68 и т.п.
FUN_94c264c(..., param_4 = 1, ...);
  -> FUN_94c82cc(..., param_4 ^ 1 = 0);   // только pinned root

// test wrappers: FUN_94c2bd8 / FUN_94c2bd4 / FUN_94c2e68
FUN_94c264c(..., param_4 = 0, ...);
  -> FUN_94c82cc(..., param_4 ^ 1 = 1);   // unpinned root принимается
```

В `FUN_94c82cc`:

```c
lVar10 = FUN_94c84c4(root, 1);   // pin store #1
if (lVar10 != 0) return 0;
lVar10 = FUN_94c8580(root);      // pin store #2
uVar3 = 0;
if (param_4 == 0) uVar3 = 0x80008;  // strict: unpinned => error
if (lVar10 != 0) uVar3 = 0;
return uVar3;                        // loose: unpinned => success
```

Вывод: ветка «unpinned root accepted» — это **by design тестовый режим**.
Она не выбирается полями сертификата/профиля; её включает только вызывающий
код через `allowTestHierarchy`. Чтобы назвать это байпасом, нужно доказать,
что какой-то production-вызывающий (amfid/installd/securityd) передаёт 1
на основании attacker-controlled данных. Пока таких доказательств нет;
наоборот, `oracle_now.log` с `allowTestHierarchy = 0` даёт отказ на фейковой
цепочке (`0x70002` / `0xa0120` / `0x2000b`), а реальная Apple-цепочка даёт
`0x0` / policy `0x10000`.

## 3. Что проверено в парсере (без находок)

| Функция | Что разбирает | Проверки |
|---|---|---|
| `FUN_94c6ac4` | внешний SEQUENCE сертификата | CARRY8, точный конец, `param_2[1]` |
| `FUN_94c5408` | tbsCertificate: serial, sig alg, issuer, validity, subject, SPKI, extensions | длина каждого элемента, `local_138 - local_140`, точный конец, счётчик расширений |
| `FUN_94c6bf4` | AlgorithmIdentifier: SEQUENCE { OID, optional BIT STRING } | `0xfffffffffffffff8 < bitlen` (overflow), `(len+7)>>3`, bounds, trailing-data check `0xa0005` |
| `FUN_94c5d84` | critical BOOLEAN | `local_40 == 1`, значение только 0x00/0xff, границы |
| `FUN_94c5e88` | keyUsage BIT STRING | `local_30 == end`, `len <= 8`, `local_30 > local_38` |
| `FUN_94c5f5c` | basicConstraints | SEQUENCE, optional BOOLEAN, INTEGER pathLen, clamp `0xf` |
| `FUN_94c602c` | subject/authority key id | SEQUENCE, `[0]`, точный конец |
| `FUN_94c6324` | OID → table entry | `param_3 < 10`, запись в массив 10*0x10 |
| `FUN_94c63b0` | extension dispatcher | OID length 9/10/11, `memcmp`, только flags |
| `FUN_94c786c` / `FUN_94c79bc` | Apple marker / 32-byte blob | точная длина, границы |

Потенциально интересные места для второго прохода (не «баги», а зоны риска):

- `FUN_94c7a20` — проверка подписи цепочки (большая функция, много указателей).
- `FUN_94c8638` — основной проход по цепочке; сюда сходятся OID/policy/flag.
- `FUN_94c63b0` — логика policy-флагов по OID; ошибка здесь даёт не OOB, а
  неверные entitlements/policy.
- `FUN_94c8058` — жёсткий лимит 4 сертификата; интересно поведение при
  ровно 4 + хвост (проверяется `local_560 != local_558` → `0x5000a`).

## 4. Где искать memory corruption дальше

1. **CMS SignerInfo / signed attrs** (`_CMSParseSignerInfos` в
   Security.framework): attacker-controlled `SignerInfo`, `signedAttrs`,
   hash-agility (`1.2.840.113635.100.9.1/9.2`), multi-signer. Это userland,
   падение не паникует кернел — безопаснее для фаззинга.
2. **CoreTrust kext** `FUN_94c7a20` / `FUN_94c8638`: если фаззинг даст
   crash в kext, это уже kernel panic; нужен запасной девайс.
3. **libmis Swift/ObjC glue**: `MISValidateSignature`, преобразование
   `NSData`/указателей; искать unsafe pointer arithmetic.

## 5. Следующий эксперимент (дешёвый и решающий)

Модифицировать `ctoracle` так, чтобы `test_libmis` вызывал
`CTEvaluateAMFICodeSignatureCMS` дважды: `allowTestHierarchy = 0` и `1`,
на одном и том же `case_apple_iphone.cms` + `.cd`.

Ожидание:
- `0` → отказ (`0x70002`/`0xa0120`/`0x2000b`);
- `1` → успех (или другой код), что подтвердит: «unpinned root» — это
  исключительно тестовый режим, а не байпас.

Если `1` **не** даёт успех — значит, в цепочке есть ещё один гейт, и его
надо смотреть отдельно. Если даёт — лид окончательно закрыт, и дальше только
memory corruption/fuzzing.

## 6. Ограничения

- Это ручной обзор декомпилятора, а не доказательство безопасности.
-Адреса — unslid, из kernelcache 24B115; код kext’а совпадает с устройством.
- Устройство сейчас на USB, pairing живой (`ideviceinfo` отвечает), но
  фаззинг kext’а может паниковать телефон — только с бэкапом/запасным девайсом.
