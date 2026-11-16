// FUN_fffffff009c2fc24 @ fffffff009c2fc24 size=724

undefined8
FUN_fffffff009c2fc24
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          uint param_6)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  
  iVar1 = (*DAT_fffffff008067b70)();
  if (iVar1 == 0) {
    return 0;
  }
  plVar2 = (long *)thunk_EXT_FUN_801100000392f2f0(param_4,0);
  plVar3 = (long *)thunk_EXT_FUN_801100000392ece0(plVar2,0xffffffffffffffff);
  if (*(long **)(param_1 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
  }
  *(long **)(param_1 + 0x28) = plVar3;
  if (plVar3 == (long *)0x0) {
    uVar5 = 0;
    goto joined_r0xfffffff009c2fe24;
  }
  plVar3 = (long *)(**(code **)(*plVar3 + 0x3c8))(plVar3,param_5);
  *(long **)(param_1 + 0x38) = plVar3;
  if (plVar3 == (long *)0x0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
               "IOSurfaceDeviceMemoryRegion: Couldn\'t get device memory with index %u for service %s\n"
              );
joined_r0xfffffff009c2fe24:
    uVar5 = 0;
  }
  else {
    *(uint *)(param_1 + 0x58) = param_6 & 0xf00;
    lVar4 = (**(code **)(*plVar3 + 0xb0))();
    *(long *)(param_1 + 0x48) = lVar4;
    if (lVar4 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,
                 "IOSurfaceDeviceMemoryRegion: zero-length device memory with index %u for service %s\n"
                );
    }
    else {
      plVar3 = (long *)(**(code **)(**(long **)(param_1 + 0x38) + 0xe8))
                                 (*(long **)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x58));
      if (*(long **)(param_1 + 0x40) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x40) + 0x28))();
      }
      *(long **)(param_1 + 0x40) = plVar3;
      if (plVar3 != (long *)0x0) {
        uVar5 = (**(code **)(*plVar3 + 0x78))(plVar3);
        *(undefined8 *)(param_1 + 0x50) = uVar5;
        lVar4 = thunk_EXT_FUN_801100000397b408
                          (*(long *)(param_1 + 0x48) + -1,*(undefined8 *)PTR_DAT_fffffff00806ca78,0,
                           0);
        if (*(long **)(param_1 + 0x30) != (long *)0x0) {
          (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
        }
        *(long *)(param_1 + 0x30) = lVar4;
        if (lVar4 != 0) {
          uVar5 = 1;
          goto joined_r0xfffffff009c2fe24;
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "%s: Couldn\'t allocate range allocator for graphics memory\n");
        goto joined_r0xfffffff009c2fe24;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurfaceDeviceMemoryRegion: Couldn\'t map device memory\n");
    }
    uVar5 = 0;
  }
joined_r0xfffffff009c2fe24:
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar5;
}

