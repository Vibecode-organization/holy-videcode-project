# surf_lookup — progress (IOSurfaceAcceleratorClient, 27.2/24B115)

- [x] kc.py + xref.py (adrp.idx 635k) + brscan.py (br.idx 793k) — индексы построены
- [x] подтверждён объект: vtable 0x7e3b0d8, meta-vtable 0x7e3b6c0 (alloc 0x8d136dc, sizeof 0x180),
      таблица 0x7e3b738 (12×0x30), getTargetAndMethodForIndex vtable+0x5b0 = 0x8d13c38 (idx<=0xb, umull+overflow)
- [x] формат записи: +0x08 fn, +0x10 discr, +0x18 shape, +0x20 structInSize (0xffffffff=любой),
      +0x28 structOutSize; проверку размера делает ЯДРО (0xa9a3c48)
- [x] 0x8e00070 = PLT (GOT 0x7e60f08) -> 0xa97ae84 = конструктор IOMemoryDescriptor
      (IOGeneralMemoryDescriptor, метакласс 0xad97200, vtable 0x7c2fd08, init слот +0x78 = 0xa977cc8).
      НЕ lookup: user-u64 = адрес, csel(task==0 ? 0x20 physical : 0x10 virtual64)
- [x] 0x8d56a18 = гейт sel6 на стороне провайдера + 0x8d56a50 (4 вызова через таблицу 0x7e4af60,
      индекс clz(rbit([p+0x1c0])) — при 0 даёт 64 -> OOB)
- [x] все 12 селекторов разобраны, таблица в REPORT.md
- [x] гейты: +0x164 = kModuleClient ("must called from user space!", 0x8de6604 -> 0x8d15408 -> panic);
      гейта НЕТ у sel 9/10/11; +0x160 bit0 читает только sel7, писателей нет
- [x] free/stop: stop vt+0x560 = 0x8d13c78 (флаг +0x138, дерегистрация, закрытие gate 0x8dca080);
      free vt+0x70 = 0x8d13a1c -> teardown 0x8d1392c (release +0x120/+0x108/+0x118/+0x140/+0x100,
      free +0x158; +0x130 зануляется БЕЗ release)
- [ ] не подтверждено: вызывающий 0x8d13ffc (withProvider) в бинаре отсутствует; может ли x1==0
- [ ] не подтверждено: длина источника sel11 ([[p+...]+0xb8]) и размер назначения
- [ ] не подтверждено: может ли [provider+0x1c0] == 0 на входе sel6
- [ ] рантайм: открывается ли сервис из container, поведение sel7 с addr=0, содержимое дампа sel11
