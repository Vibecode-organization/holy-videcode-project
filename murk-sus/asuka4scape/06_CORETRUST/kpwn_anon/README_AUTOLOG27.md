# AutoLog27 — headless диагностический IPA для iOS 27.2 RC

Собрано: 2026-11-04  
Цель: iPhone14,7 / T8110, iOS 27.2 RC (24B115)  
IPA: `/home/femboychik/Рабочий стол/AutoLog27.ipa`

## Что делает

При запуске (без кнопок, чёрный экран) автоматически:

1. Пишет device info (`uname`, build, model, cpufamily, ncpu, page size).
2. Читает DeviceTree `/arm-io/sgx` и `/chosen` (если доступны).
3. Пробует `IOServiceOpen` для `IOSurfaceRoot`, `AGXAcceleratorG14P`,
   `IOGPU`, `AppleM2ScalerCSCDriver`, `AppleT8110DART` (типы 0..2).
4. Создаёт `IOSurface` 64x64 BGRA и проверяет base address.
5. Сканирует RW-регионы процесса на kernel-указатели (KASLR-хуки).
6. Сканирует все submap-регионы и для каждого пробует
   `mach_make_memory_entry_64` (0x4000..0x40000 и полный размер) —
   это проверка, не запечатаны ли в 27.2 все submaps.
7. Запускает **Coruna Kread Bootstrap** (этап 1, без SPTM-стадии).
7. Пишет всё в `Documents/AutoLog27/auto-YYYYMMDD-HHMMSS.log`
   и дублирует в `NSLog` с префиксом `[AutoLog27]`.

По умолчанию SPTM-стадия **не запускается** — чтобы не паниковать на
17.0-оффсетах.

## Режимы (необязательно)

Создай файл в `Documents` приложения (через Finder/File Sharing или
`idevice`/`ifuse`) **до** запуска:

- `run_kwrite` — после успешного kread запустить `kwrite_test()` и
  начальные стадии kernel R/W (может паниковать).
- `run_full` — после kread запустить полный SPTM pipeline из Coruna
  (17.0-оффсеты; на 27.2 почти наверняка паника). Только на тестовом
  устройстве.

Без файлов: kread + пробы.

## Установка

1. Подписать `AutoLog27.ipa` своим dev-профилем (как `Coruna27.ipa`).
2. Установить, запустить, оставить на переднем плане (чёрный экран).
3. Дождаться `=== AUTOLOG27 DONE ===` в логе (или паники).
4. Забрать из `Documents`:
   - `AutoLog27/auto-*.log` — основной лог;
   - `sptm_bypass.log` — лог Coruna;
   - `last_status.txt` — статус.

Если приложение не может писать в `Documents`, смотри `idevicesyslog`:

```bash
idevicesyslog | grep -E 'AutoLog27|\[kread\]|\[race\]|klog'
```

## Что прислать

- `AutoLog27/auto-*.log`
- `sptm_bypass.log`
- `last_status.txt`
- если есть паника — `.ips` из `Settings > Privacy & Security > Analytics`
  или `idevicecrashreport`.

## Ограничения

- Приложение sandboxed, без приватных entitlement'ов.
- `AGXAcceleratorG14P`/`IOGPU`/DART, скорее всего, дадут `0xe00002c2`;
  это ожидаемо и фиксируется.
- Kread Bootstrap — единственный публичный кандидат на kernel R/W;
  если он упадёт, лог покажет точку отказа.
