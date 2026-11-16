# progress — physical vs virtual addr (AppleM2ScalerCSCDriver 27.2)

## 2026-10-29 — разбор `IOMemoryDescriptor::withAddressRange` в AppleM2ScalerCSCDriver

Готово: REPORT.md.

* Карта файла: MH_FILESET, 250 kext; `fo = va - 0xfffffff007004000` для kernel-сегментов, у kext-сегментов свой сдвиг (`fo = va - 0x700000` для AppleM2ScalerCSCDriver). GOT-слот `0x7e60f08` = auth-rebase на `0xa97ae84`.
* Целевая: `0xa97ae84` = `IOMemoryDescriptor::withAddressRange(addr,len,dir,task)`. `cmp x19,#0` + `csel w8,#0x20,#0x10,eq` @`0xa97aecc..ed8` → task==0 = physical64 (0x20), иначе virtual64 (0x10).
* В kext 7 вызовов: `0x8d13e44` (helper `0x8d13dec`, из sel4), `0x8d14d3c` (sel7), `0x8d14fec` (sel8), `0x8d150a8`+`0x8d150c4` (sel9), `0x8dbbebc`+`0x8dbbfac` (helper `0x8dbbd78`, init-путь).
* task везде `[obj+0x130]`. Записей в `+0x130` всего две: `0x8d14068` (фабрика с task) и `0x8d1396c` (xzr в деструкторе).
* Фабрики: `0x8d13ff8` (withTask; **единственный указатель — таблица `0x7e4adb0` → `0x8d55e4c` = слот +0x460 vtable `0x7e4a950`**, т.е. `newUserClient`, task = owningTask) и `0x8d13a6c` (без task, 5 вызовов из init: `0x8d092cc/0x8d09ad4/0x8d09c44/0x8d09ea4/0x8d0a1c0`, `+0x130` остаётся 0).
* Таблица селекторов `0x7e3b738`, 12×0x30, fn@+8: sel7 `0x8d14ce0`, sel8 `0x8d14f84`, sel9 `0x8d15064` — все с user-u64 (InOut/In), task = owningTask → virtual64.
* Кросс-kext: 33 импортёра, 120 точек bl. Явный `task=NULL` только 4: IOPCIFamily `0x9b4747c`/`0x9b47fc8` (BAR), IOMobileGraphicsFamily-DCP `0x9a7c090`, IOSurface `0x9c1ebf8` (`ldp x0,x1,[surf+0x158]`, `[surf+0x170]==0` → physical; адрес из kernel-полей).
* Вердикт: примитива маппинга произвольной физики из песочницы в Scaler нет. Открыто: IOSurface `+0x158/+0x160/+0x170` — кто заполняет.
