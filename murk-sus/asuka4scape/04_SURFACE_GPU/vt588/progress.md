# vt588 — прогресс

## 2026-10-29 subagent AG — IOGPU vt+0x588

- [x] Разобрал chained fixups (LC_DYLD_CHAINED_FIXUPS @0x401c000, format 8
      `PTR_64_KERNEL_CACHE`). Грабли: `page_start[]` в 8-байтовых единицах,
      `next` в 4-байтовых — с 4/4 теряется половина vtable'ов, `0x9964c38`
      «не находится» ни одним указателем.
- [x] Нашёл слот `+0x588`: `0x9974304`, ровно 4 vtable'а — база `IOGPU`
      `0x7fee6c0` и три AGX-акселератора `0x7c99740 / 0x7c9a5b0 / 0x7c9b420`.
- [x] Разобрал: `vt[0x630]` = `metaclass+0x68` = `alloc` (`0x9964ad0` для
      IOGPUDevice, `0x8200c0c` для AGXShared) → kalloc + ctor, без поиска.
- [x] `AGXShared::init 0x8200704` кладёт secid в `+0xd8`, task через базовый
      init в `+0x50`.
- [x] Вердикт: пер-клиентский, кэша нет. Отчёт: `work/vt588/REPORT.md`.
- [ ] Не подтверждено: цель базового init `[0x7ca60d0]+0x90` (level-2
      указатель, область в файле нулевая).
- [ ] Рантайм-проверка двумя процессами не делалась.

Инструменты: `kc.py`, `ctors.pkl`, `ref.pkl`.
