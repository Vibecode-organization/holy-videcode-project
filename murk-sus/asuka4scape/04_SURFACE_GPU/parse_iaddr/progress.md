## step 1 — sel 7 цепочка
- 0x9c38adc: x1=args->scalarInput[0], x2=scalarInput[1], x3=args->structureOutput(0x58) -> tail 0x9c3bf44
- 0x9c3bf44 = create_surface_client_mem(self, addr, size, out); addr==0||size==0 -> 0xe00002c2
- строит OSDictionary{ IOSurfaceAddress: OSNumber(addr,64), IOSurfaceAllocSize: OSNumber(size,64) }
- 0x9c33c34(root, task, dict, 0) -> 0x9c1a914 -> 0x9c1af14 (initWithProperties)
## step 2 — initWithProperties
- 0x9c1e03c: str addr -> [surface+0x150] (единственная запись), проверки: [0x308]==0 (не сжатая), [0x3a0]==0
- 0x9c1ad80 (в 0x9c1a914): выравнивание base/size по странице -> [0x158]=aligned base, [0x160]=aligned size, [0x168]=offset
- 0x9c1adfc: if fAllocSize(0x90)!=0 -> 0x9c1e624 (allocateMemory)
## step 3 — санитайзер НАЙДЕН
- 0x9c1e8b0: client-address ветка; 0x9c1e9xx/0x9c1ea10 -> 0x9c2200c(task=fOwnerTask[0x170], start, end, &flag)
- 0x9c2200c: map=task->map (0xa29b7b0), mach_vm_region flavor9 (0xa344acc); требует полное покрытие [start,end), запрет VM_PROT_EXECUTE, ошибка 0xe00002c8
- затем 0x9c1ebf4: IOMemoryDescriptor::withAddressRange(aligned_base, aligned_size, flags, fOwnerTask)
## step 4 — fOwnerTask = task юзер-клиента (0x9c3a33c: PAC-store task в [uc+0xf8], task_reference 0x9c49df4)
## step 5 — вердикт
- селектор 7 ЗАБЛОКИРОВАН: 0x9c2200c (mach_vm_region по fOwnerTask->map) отбивает ядерные/чужие адреса, код 0xe00002c8
- второй барьер: IOMemoryDescriptor::withAddressRange(..., task=fOwnerTask) 0x9c1ebf8
- IOSurfaceAddressRanges (0x9c1dac4) — тот же санитайзер на каждый диапазон (0x9c1e98c)
- IOSurfaceBaseAddress / IOSurfaceCompressedTileWidth в 27.2 НЕ существуют как ключи
- sel 7 без энтайтлментов (таблица 0x8068b90); у gpu-restricted — заглушка 0x9c3a1dc (0xe00002e2)
- REPORT.md записан
