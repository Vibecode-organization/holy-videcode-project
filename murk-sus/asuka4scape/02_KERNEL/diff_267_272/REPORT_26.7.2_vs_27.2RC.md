# Ядро iOS 26.7.2 (23H128) → iOS 27.2 RC (24B115)

Одно и то же железо: **iPhone14,7 / D27AP, T8110 (A15)**. Сравнение level-таблиц и
структуры fileset, без декомпиляции отдельных функций.

| | 26.7.2 | 27.2 RC |
|---|---|---|
| сборка | 23H128 | 24B115 |
| Darwin | 25.6.0 | 27.2.0 |
| xnu | 12377.162.13.701.45~1 | 13432.42.3~28 |
| kernelcache | 62 865 408 B | 67 239 936 B (+4 374 528, +7,0 %) |
| kext'ов (prelink) | 265 | 267 |
| fileset-энтри | 248 | 250 |
| sha256 | `99c9d0b5…21c01` | `7afbff54…5205b` |

Всего 251 kext в выборке, изменения есть у 247. Версии подняты у 67.

## Kext-инвентарь

Новые:

- `com.apple.security.Image4` — отдельный kext, 551 553 B. Раньше Image4 был
  только частью `com.apple.security.AppleImage4`; теперь вынесен в собственный
  бинарь.
- `com.apple.driver.AFKHIDTBDevice` — HID-транспорт (TB = Trusted Beach).
- `com.apple.driver.VideoProcessing`.

Удалён:

- `com.apple.filesystems.hfs.kext` — HFS+ из ядра выпилен, остаётся APFS.

## Крупнейшие изменения кода

| kext | Δ размера | Δ funcs | комментарий |
|---|---|---|---|
| `com.apple.driver.AppleM2ScalerCSCDriver` | +763 KB | +1717 | скалер дисплея, почти удвоил код |
| `com.apple.driver.AppleH11ANEInterface` | +532 KB | +2062 | ANE, самый большой прирост функций |
| `com.apple.driver.AppleAVE2` | +329 KB | +213 | видеоэнкодер |
| `com.apple.driver.AppleAVD` | +328 KB | +306 | видеодекодер |
| `com.apple.kernel` | +193 KB | +537 | XNU |
| `com.apple.security.sandbox` | +176 KB | +4 | правила, не код |
| `com.apple.driver.AppleMultitouchSPI` | −140 KB | −441 | вырезан целый слой |

## XNU (`com.apple.kernel`)

Сегменты, файловый размер:

| сегмент | 26.7.2 | 27.2 RC | Δ |
|---|---|---|---|
| `__TEXT` | 971 568 | 1 010 680 | +39 112 |
| `__TEXT_EXEC` | 8 713 944 | 9 018 904 | +304 960 |
| `__DATA_CONST` | 836 248 | 855 416 | +19 168 |
| `__DATA_SPTM` | 245 760 | 311 296 | +65 536 |
| `__DATA` | 163 840 | 163 840 | 0 (vmsize +81 920, bss) |

- Функций: 20 366 → 20 903 (+537).
- `__DATA_SPTM` вырос ровно на блок 64 KB — это данные, которые ядро держит для
  монитора, а не код самого SPTM.
- `__DATA` в файле не вырос, но vmsize +81 920: новые статические массивы
  нулевого заполнения.

Новые экспортируемые символы (выборка из 56):

- MACF-хуки под IOKit: `_mac_iokit_check_register_service`,
  `_mac_iokit_check_start_service`, `_mac_iokit_check_send_isp_command`.
  Три новые точки контроля на пути регистрации и запуска сервисов.
- Image4 v2: `_image4_v2_evaluate`, `_image4_v2_interface_register`,
  `_image4_v2_load_diavlo_root_ca`, `_image4_v2_load_local_policy`,
  `_image4_v2_roll_nonce`, `_image4_v2_set_nonce_digest`.
- Exclaves + IOSurface: `_exclaves_exsurfaceroot_lookup`,
  `_exclaves_exsurfaceroot_surface_memory_range`,
  `_exclaves_exsurfaceroot_backing_surface_memory_range`,
  `_exclaves_exsurfaceroot_surface_usecount_update`. Поверхности уезжают в
  exclave-домен, ядро оставляет себе только ручки.
- Content protection: `_proc_is_strict_content_protection`,
  `_vfs_context_is_strict_content_protection`,
  `_vfs_context_ignores_content_protection`.
- Диагностика памяти: `_ecc_panic_non_acc`, `_ecc_panic_physical_address`
  (вместо двух `_ecc_log_memory_error*`, которые ушли).
- `_task_get_sanitizer_config`, `_os_log_coprocessor_with_handle`,
  `_tb_delegated_c_*` (transport), `IOServiceStateNotificationEventSource`,
  `IOPerfControlClient::workCanSubmit`.

Удалено: `_ecc_log_memory_error`, `_ecc_log_memory_error_delayed`.

## Syscalls и MIG

Syscall-таблица: 558 слотов в обеих сборках, но в 27.2 включены восемь ранее
пустых (`nosys`):

| # | вызов |
|---|---|
| 148 | `pipe2` |
| 149 | `sys_dup3` |
| 214 | `fchflagsat` |
| 215 | `getumask` |
| 246 | `aio_readv` |
| 247 | `aio_writev` |
| 249 | `fsctlat` |
| 352 | `guarded_ftruncate_np` |

MIG: 17 подсистем / 343 routine → 18 / 348. Новая подсистема (start 866900,
имени в дампе нет) и `is_iokit_subsystem` 90 → 91 routine.

Mach traps: **не сравнены.** `ipsw` на 26.7.2 нашёл таблицу по сигнатуре
неверно (46 % записей `<unknown>`, адреса вида `0xfffffff007004001`), на 27.2 —
корректно (0 %). Число слотов 128 в обеих сборках, но по именам выводов делать
нельзя.

## Security-релевантные зоны

**sandbox** — `__TEXT` +152 345 B при +4 функциях; строк +4407 / −3755.
Код почти не менялся, переписан слой профилей и правил. Это ожидаемый паттерн
для мажорного релиза: не новые проверки, а другой набор разрешений.

**corecrypto** 26.0 → 27.0 — стал меньше на 37 468 B, но функций +108
(1847 → 1955). Строки FIPS POST содержат новые pairwise-проверки:
`CCMLKEM_KEM_PAIRWISE_CHECK`, `CCMLDSA_KEYGEN_PAIRWISE_CHECK` и
`DlCompositeAlgorithmSignatures2025` — пост-квантовые ML-KEM и ML-DSA. Код
переписан, а не дополнен.

**IOSurface** 393.5.10 → 403.1 — +44 407 B, +73 функции. Новые ветки ошибок:
`copyObjectForPortNameInTask failed`, `invalid memory pool port`, `invalid shared
event port`, `ensureMemory failed`. Вместе с `exclaves_exsurfaceroot_*` это одна
линия изменений: перенос владения поверхностями.

**apfs** 2811.160.7 → 3288.42.1 — +81 967 B, +59 функций. Новые проверки длин
ключа и IV в `apfs_crypto_state_init`, обработка `PATH TOO LONG`, аккуратная
работа с blockmap LUT (`return EIO` вместо тихого продолжения).

**AppleImage4** — +45 084 B; строки `cryptex1 certificate format`,
`cryptex1 key scheme`, `CRYPTEX1-BOOT-SECURE-BOOT`. Плюс новый kext
`com.apple.security.Image4`.

**CoreTrust** — +43 036 B, +8 функций, 260 новых строк, ни одной удалённой:
только добавления.

**AppleSEPManager** — +54 991 B, +54 функции, среди новых —
`AppleSEPUserClient::DispatchGetEpochs`.

**IOGPUFamily** 130.16.5 → 162.16.1, **IOAccessoryManager** +6 672 B,
**IOUSBMassStorageDriver** 280 → 283, **IOTimeSyncFamily** 1460.3 → 1510.9.

## Границы этого дифа

- Сравнение структурное и табличное. Совпадение размеров kext'а не значит
  «код не менялся» — это значит, что объём не изменился.
- Байтовое сравнение `__TEXT_EXEC` бессмысленно: fileset раскладывает kext'ы по
  общим регионам, адреса сдвигаются, chained fixups пересчитываются.
- Символы в релизном kernelcache урезаны до экспортируемых; полного symtab нет,
  поэтому диф по именам функций ограничен `com.apple.kpi.*`.
- Mach traps не разобраны на стороне 26.7.2 (см. выше).
- Отдельная функция-в-функцию декомпила не делалась: для этого нужен импорт
  обеих сборок в Ghidra и матчинг по хешам тел функций.

## Воспроизведение

```sh
cd /home/femboychik/work/diff_267_272
python3 kcdiff.py kc/23H128__iPhone14,7/kernelcache.release.iphone14b \
                  kernelcache.27.2RC.24B115.iphone14b \
                  --label-old "iOS 26.7.2 (23H128)" \
                  --label-new "iOS 27.2 RC (24B115)" --out out
```

26.7.x для iPhone14,7 существует только как OTA: Restore IPSW в публичном
наборе Apple нет. Ядро вытащено из AEA-контейнера, ключ — из метаданных Pallas
(`pull_267.sh`). Полный машинный отчёт — `out/REPORT.md` и `out/diff.json`.
