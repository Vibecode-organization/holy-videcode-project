# дипсик 1 — iOS 27.2 (24B115) / iPhone14,7 (T8110): kernel R/W

Рабочая папка. Цель: произвольный kernel R/W на iOS 27.2, IPA собираются здесь,
подписывает и ставит Kai.

## Что сделать утром

1. `probe/out/KRWProbe.ipa` — подписать своим Apple ID, поставить, открыть.
2. **RUN SAFE** — покажет `kern.version`, сборку, и главное: какие user client'ы
   песочница реально пускает (`IOSurfaceRoot`, `AppleAVE2*`, `AppleH11ANEInterface`,
   `AGXAcceleratorG14P`). Это ответ на вопрос, который мы до сих пор только предполагали.
3. **RACE 30s** — 5 потоков SetValue/Lock/Unlock/подмена `IOSurfacePlaneInfo` на одной
   поверхности. Если 27.2 где-то недосчитал — паника.
4. **FUZZ 50k** — случайные compressed-plane конфиги. Перед каждой попыткой конфиг
   пишется в `last_config.json` в контейнере; после паники он покажется вверху экрана.
5. Если что-то упало — скинь скриншот/лог, разберу по адресу паники.

## Статус

**Kernel R/W нет.** За ночь закрыто:

- **SPTM TTBAT** — скип проверки только для фиксированного PA `gpu-region-base`
  (штатный GPU MMIO), произвольный PA не замапить. MAP_BEGIN 27.2 = `0xfffffff0270adf30`.
- **IOSurface** — фикс найден: 6 инструкций в 3 функциях, флаг `child+0xf1` под локом
  `surface+0x150`. Гонка CVE-2026-112477 закрыта. Подробно: `reports/FINDING_IOSurface_27.2.md`.
- **AppleAVE2** — собран полный список проверок, добавленных в 27.2 (HEVC VPS/SPS/PPS/RPS,
  AVC log2/counts, MCTF, temporal layers). Это фиксы CVE-2026-112468/112469/112470/112689.
- **Ядро** — карта изменений 27.0→27.2: 20 393 из 20 876 функций идентичны, 392 изменены.
  `reports/kcore_shape_diff.txt`, опознание — `scripts/ident_changed.py`.
- **task_set_special_port** — в 27.2 добавлена проверка refcount порта.

Всё найденное ранее («живое») в 27.2 закрыто. Новый баг за ночь не найден.

## Структура

| Путь | Что |
|---|---|
| `kc/27.2_24B115_kernelcache` | kernelcache 27.2 (Mach-O, 67 MB) |
| `kc/27.0_24A437_kernelcache` | kernelcache 27.0 (для fix-diff) |
| `sptm/27.2/`, `sptm/27.0.1/` | SPTM + DeviceTree |
| `kexts/{ane,iosurface,ave,avd}/` | кексты 27.0 и 27.2 |
| `kcore/{270,272}/com.apple.kernel` | ядро для диффа |
| `dumps/ios272/` | 1702 декомпиляции IOSurface-кекста |
| `probe/` | исходники и IPA probe/фаззера |
| `reports/` | отчёты ночи + прошлые |
| `scripts/` | `compare_text.py`, `diff_func.py`, `ident_changed.py`, `fdiff_kernel_shape.py`, java-скрипты Ghidra |
| `ghidra/` | Ghidra-проекты (sptm272, ane_gh, ane_gh270, ave272) |

Полный IPSW: `/home/femboychik/work/rc115/iPhone14,7_27.2_24B115_Restore.ipsw` (11.4 GB, CRC битый
на rootfs AEA — дипсик 2 качает чистый).
Ghidra-проект ядра: `/home/femboychik/Загрузки/AyuGram Desktop/Архив/123`.

## Методика (важно)

- Сравнивать кексты/фреймворки только **по секции `__text`**, не по первому сегменту:
  первый прогон дал ложное «IOSurface-кекс не менялся».
- `ipsw dyld extract` на этих кэшах падает (`invalid argument`); рабочий обход —
  `dsc_extract.py` + `scripts/compare_text.py` (по секции).
- Новые строки кекста — самый быстрый способ найти фиксы: assertion-строки в AVE2
  содержат точные условия проверок.
