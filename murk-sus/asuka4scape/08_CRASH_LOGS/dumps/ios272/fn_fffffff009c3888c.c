// FUN_fffffff009c3888c @ fffffff009c3888c size=4

undefined8 FUN_fffffff009c3888c(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  
  uVar4 = **(ulong **)(param_3 + 0x20);
  if (uVar4 >> 0x20 == 0) {
    plVar2 = *(long **)(param_3 + 0x40);
    if (plVar2 == (long *)0x0) {
      plVar2 = (long *)0x0;
      iVar1 = *(int *)(param_3 + 0x38);
      lVar3 = *(long *)(param_3 + 0x30);
    }
    else {
      plVar2 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0x1000);
      if (plVar2 == (long *)0x0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - failed to map shmem\n");
        return 0xe00002c8;
      }
      lVar3 = (**(code **)(*plVar2 + 0x78))();
      iVar1 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
    }
    if (lVar3 == 0 || iVar1 == 0) {
      uVar5 = 0xe00002c2;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - no args\n");
    }
    else {
      uVar5 = FUN_fffffff009c3ab8c(param_1,lVar3,uVar4,*(undefined8 *)(param_3 + 0x58));
    }
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  else {
    uVar5 = 0xe00002c2;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,"%s error - invalid parentID (0x%llx)\n");
  }
  return uVar5;
}

