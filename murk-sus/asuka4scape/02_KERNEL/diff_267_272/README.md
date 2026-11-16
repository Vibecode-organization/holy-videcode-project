# diff_267_272 — kernelcache 26.7.2 vs 27.2 RC

Сравнение kernelcache одного и того же устройства (iPhone14,7, D27AP) между
iOS 26.7.2 (23H128) и iOS 27.2 RC (24B115).

## Источники

| сборка | откуда | файл |
|---|---|---|
| 26.7.2 (23H128) | OTA-ассет Apple, AEA-запечатан | `kc/kernelcache.release.iphone14b` |
| 27.2 RC (24B115) | Restore IPSW | `/home/femboychik/work/rc115/24B115__iPhone14,7/kernelcache.release.iphone14b` |

26.7.x для iPhone14,7 не существует в виде Restore IPSW — только OTA. Поэтому
ядро вытаскивается из AEA-контейнера (`pull_267.sh`), ключ берётся из метаданных
Pallas (`ipsw download ota --fcs-keys`).

## Запуск

```sh
bash pull_267.sh                       # только если kc/ пуст
python3 kcdiff.py <OLD> <NEW> \
    --label-old "iOS 26.7.2 (23H128)" \
    --label-new "iOS 27.2 RC (24B115)" \
    --out out
```

Выход: `out/diff.json` (машинный) и `out/REPORT.md` (читаемый).

## Что считается

- kext-инвентарь: наличие, версии (`ipsw kernel kexts`), включая aux-kext'ы,
  у которых нет собственного fileset-энтри
- по каждому kext: размер span в файле, размеры сегментов (`__TEXT`,
  `__TEXT_EXEC`, `__DATA*`, `__PRELINK_*`), число function starts
  (LC_FUNCTION_STARTS, ULEB128-цепочка)
- строки: cstrings ≥4 символов, привязанные к span своего kext; отдельно —
  фильтр по security-лексике (panic/entitlement/userclient/SPTM/bounds/…)
- таблицы: BSD syscalls, mach traps, MIG-подсистемы и routines
- symbol sets (`com.apple.kpi.*`): версия набора, новые и ушедшие символы

## Границы

- span kext'а считается как «от его fileoff до следующего fileset-энтри»;
  выравнивание внутри span относится к kext'у-хозяину
- символы ядра в релизном kernelcache урезаны до экспортируемых (kpi); полного
  symtab нет, поэтому диф по именам функций ограничен symbol sets
- байтовое сравнение `__TEXT_EXEC` между сборками бессмысленно: адреса в
  fileset сдвигаются, chained fixups пересчитываются
