// FUN_fffffff009c25834 @ fffffff009c25834 size=364

ulong FUN_fffffff009c25834(long param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long *plVar5;
  ulong uVar6;
  undefined1 auStack_3c [4];
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  iVar2 = FUN_fffffff009c371e8(DAT_fffffff00af483b0);
  if (iVar2 == 0) {
    uVar6 = 0;
    goto LAB_fffffff009c2596c;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  plVar3 = (long *)FUN_fffffff009c259a0(param_2,"IOSurfaceTimingInfo",auStack_3c);
  lVar4 = thunk_EXT_FUN_8011000003890f30(plVar3,*(undefined8 *)PTR_DAT_fffffff00806c9c8);
  if (lVar4 == 0) {
    uVar6 = 0;
LAB_fffffff009c25940:
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  }
  else {
    uVar6 = 0xe00002bc;
    plVar5 = (long *)thunk_EXT_FUN_801100000389d2fc(lVar4,0);
    if (plVar5 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface::copyTimingInfo() - dictionary copy failed\n");
      goto LAB_fffffff009c25940;
    }
    iVar2 = FUN_fffffff009c25a44(param_1,"IOSurfaceTimingInfo",plVar5,auStack_3c);
    uVar1 = 0;
    if (iVar2 == 0) {
      uVar1 = 0xe00002bc;
    }
    uVar6 = (ulong)uVar1;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
LAB_fffffff009c2596c:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar6;
  }
  uVar6 = thunk_EXT_FUN_8011000003a48590();
  return uVar6;
}

