# F1 GPU OOB + shmem-адреса: что реально подтверждено (10.11.2026, 27.2/24B115)

## 1. Итог одной строкой

- **F1 cross-object GPU OOB write подтверждён на живом устройстве** (same-context,
  same-process).
- **Kernel R/W через него не получен**: GPU VA-пространство приложения содержит
  только свои ресурсы; kernel/TTBAT/firmware-маппингов в нём нет.
- **«Адрес shmem» из sel46 — не адрес, а серийный номер** (глобальный счётчик).
- **Все address-based пути** (replace_backing, IOSurfaceAddress, type-0/0x80)
  валидируют адрес в task клиента → kernel VA/DVA не проходят.

## 2. F1 cross-object OOB write — подтверждено

Сборка: `02_KERNEL/f1poc_desktop/main.m` (копия PoC с рабочего стола + pre-touch).

Лог последнего успешного запуска:

```
[METAL] F1 MTLBuffer len=65536 gpuAddress=0x1500000000 agxVA=0x1500000000 span=0x10000
[METAL] victim MTLBuffer len=65536 gpuAddress=0x15000a8000
[METAL] delta=0xa8000
[METAL] PRE-TOUCH status=4 victim[0]=0x47474747 expect=0x47474747
[METAL] WRITE idx=0x2a000 marker=0x43434343 status=4
[METAL] VICTIM[0]=0x43434343
[METAL] *** CROSS-OBJECT GPU OOB WRITE CONFIRMED ***
```

Ключевое: **pre-touch жертвы через её собственный GPU VA обязателен** — без него
PTE жертвы не создан и запись через F1-алиас молча теряется.

Чтение через тот же алиас тоже работает:

```
[HIGHVA] target=0x15000a8000 -> value=0x4242424242424242
```

## 3. GPU VA-пространство приложения — только свои ресурсы

Mappedness-oracle: пишем маркер через F1-алиас, читаем обратно; если совпал —
страница реально замаплена (даже если была нулевой).

Просканировано:
- f1ga .. f1ga+4 МБ (шаг 4 КБ),
- f1ga-2 МБ .. f1ga (шаг 4 КБ),
- 0x13400000000 .. +1 МБ (TTBAT-guess),
- f1ga+4 МБ .. +64 МБ (шаг 64 КБ),
- 0x13400000000+1 МБ .. +16 МБ (шаг 64 КБ).

Найдено ровно 80 страниц, все — в первых 4 МБ после f1ga:

```
+0xC0000..+0xDF000   (32 страницы)
+0x100000..+0x11F000 (32 страницы)
+0x178000..+0x187000 (16 страниц)
```

Это наши же Metal-буферы (fillers/victim) и служебные страницы; содержимое —
нули/таймстампы. **Ни одного kernel-указателя и ни одного TTBAT/firmware
маппинга.**

Страницы, найденные по содержимому:
- `+0xC4000`, `+0xC5000` — таблицы убывающих значений (GPU timestamps).
- `+0x148000` — `0x0001800000003002`, `0x0000000100000001`,
  `0x4000000060000160` — fence/stamp-структура.

## 4. sel46 `f` — серийник, не адрес

```
IOGPUIOCommandBuffer::init:
  adrp x1,#0xaf22000 ; add x1,x1,#0xc0   ; &global_counter
  mov w0,#1 ; bl 0x99843dc                ; ldadd x0,x0,[x1] -> old
  stur x0,[x21,#-8]                       ; cb+0x38 = old
sel46:
  ldr x8,[x19,#0x38] ; str x8,[x20]       ; out[1] = cb+0x38
```

`out[1]` — глобальный счётчик (в образе ядра `0xaf220c0` инициализирован 1),
а не PA/DVA/VA. `mach_vm_read` по нему всегда `KERN_FAILURE`.

## 5. Address-based пути — закрыты

- `replace_backing_bytes` (`sel38`): нужен resType **0x80** sysmemory + `sel37`
  detach + точное совпадение длины; адрес проверяется `mach_vm_region(task)`.
  С нашим VA → `0x0`, с kernel VA `0xfffffff007004000` → `0xe00002c2`.
- `replace_backing_ranges` (`sel39`): `{rid, flags, ptr_to_ranges, count}`;
  ranges валидируются поштучно в task, executable запрещён.
- `IOSurfaceAddress` (`sel6/7`): kernel text/data → create failed;
  DVA → `allocate error - invalid address range`.
- `sel8` resType 0 (`IOGPUSysMemory` из client buffer) — пока `0xe00002bc`
  (init failed) при layout `@0x20/0x28/0x30/0x48`; требует добивки полей.

## 6. AGX command queue — ABI найден

`IOGPUDeviceUserClient sel6` (create command queue):

- `structureInputSize` должен быть **0x410** (не 0x408);
- `structureOutput` — **0x10 байт** (не scalarOutput!);
- priority at +0x400 (<5);
- результат: `{u32 id, u64 serial}`.

Подтверждено:

```
[QEARLY] AGX sz=0x410 pri=0 -> 0x0 osz=0x10 id=1 q550=0x5cbce1f0
[QEARLY] AGX sz=0x410 pri=1 -> 0x0 osz=0x10 id=2 q550=0x5cbce1f4
```

`q550` — снова серийник (+4 на очередь), не адрес.

`sel25` (submit_command_buffers) с нулевой записью `{0x30}` возвращает
`0xe00002c2`; нужен реальный формат записи Metal command buffer
(поля +0x10/+0x18/+0x20) и/или старт очереди.

## 7. Вывод по SPTM/kernel R/W

SPTM TTBAT-путь в 27.2 закрыт violation-проверками (см.
`01_REPORTS/ОТЧЁТ_27.2_ФИНАЛ.md` §1.4). GPU VA-контекст приложения не содержит
TTBAT/firmware/kernel-маппингов, поэтому F1 OOB не даёт DMA в kernel-память.

Дальнейшие реальные кандидаты:
1. Добить `sel25`/AGXCommandQueue submit и получить управление GPU-командами
   (command buffer descriptor format).
2. Добить resType 0 (`IOGPUSysMemory` из client buffer) — это даст GPU VA
   для произвольного client buffer, но не kernel.
3. Искать kernel-object в GPU-контексте (device shmem/fence page) и его
   corruption → kernel bug; сейчас таких маппингов не найдено.

## 8. Файлы

- `02_KERNEL/f1poc_desktop/main.m` — PoC + все пробы.
- `02_KERNEL/f1poc_desktop/README.md` — исходный README.
- `/tmp/F1AT-signed.ipa` — последняя подписанная сборка (может быть очищена).
- Логи: `Documents/F1OOB-PoC/run-*.log` на устройстве.
