// FUN_fffffff009c25af4 @ fffffff009c25af4 size=836

ulong FUN_fffffff009c25af4(long param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  undefined8 uVar6;
  long *plVar7;
  ulong uVar8;
  ulong uVar9;
  long *plVar10;
  undefined1 auStack_6c [4];
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  iVar2 = FUN_fffffff009c371e8(DAT_fffffff00af483b0);
  if (iVar2 == 0) {
    uVar9 = 0;
    goto LAB_fffffff009c25da4;
  }
  uVar9 = 0xe00002bc;
  if (param_4 == (long *)0x0) {
    uVar3 = thunk_EXT_FUN_8011000003397c88();
    param_4 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar3,0x40);
    if (param_4 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface::setTimestamp() - timestamp create failed\n");
      goto LAB_fffffff009c25da4;
    }
    (**(code **)(*param_4 + 0x28))();
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  plVar4 = (long *)FUN_fffffff009c259a0(param_1,"IOSurfaceTimingInfo",auStack_6c);
  uVar3 = *(undefined8 *)PTR_DAT_fffffff00806c9c8;
  plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(plVar4,uVar3);
  if (plVar5 == (long *)0x0) {
    plVar10 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
    if (plVar10 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface::setTimestamp() - dictionary create failure\n");
    }
    else {
      uVar8 = FUN_fffffff009c25a44(param_1,"IOSurfaceTimingInfo",plVar10,auStack_6c);
      plVar5 = plVar10;
      if ((uVar8 & 1) != 0) goto LAB_fffffff009c25bc8;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface::setTimestamp() - setValue for timing info failed\n");
    }
LAB_fffffff009c25e24:
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  }
  else {
    plVar10 = (long *)0x0;
LAB_fffffff009c25bc8:
    uVar6 = (**(code **)(*plVar5 + 0x138))(plVar5,param_2);
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(uVar6,uVar3);
    if (plVar7 == (long *)0x0) {
      plVar7 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
      if (plVar7 == (long *)0x0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "IOSurface::setTimestamp() - timing dictionary create failed\n");
        goto LAB_fffffff009c25e24;
      }
      uVar8 = (**(code **)(*plVar5 + 0x100))(plVar5,param_2,plVar7);
      plVar5 = plVar7;
      if ((uVar8 & 1) != 0) goto LAB_fffffff009c25c04;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                 "IOSurface::setTimestamp() - setValue for timing dictionary failed\n");
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    }
    else {
      plVar5 = (long *)0x0;
LAB_fffffff009c25c04:
      iVar2 = (**(code **)(*plVar7 + 0x100))(plVar7,param_3,param_4);
      uVar1 = 0;
      if (iVar2 == 0) {
        uVar1 = 0xe00002bc;
      }
      uVar9 = (ulong)uVar1;
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
      plVar7 = plVar5;
      if (plVar5 == (long *)0x0) goto joined_r0xfffffff009c25e2c;
    }
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
joined_r0xfffffff009c25e2c:
  if (plVar10 != (long *)0x0) {
    (**(code **)(*plVar10 + 0x28))(plVar10);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
LAB_fffffff009c25da4:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
    uVar9 = thunk_EXT_FUN_8011000003a48590();
    return uVar9;
  }
  return uVar9;
}

