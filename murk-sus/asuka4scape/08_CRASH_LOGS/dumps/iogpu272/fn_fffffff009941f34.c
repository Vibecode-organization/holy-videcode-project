// FUN_fffffff009941f34 @ fffffff009941f34 size=4

ulong FUN_fffffff009941f34(long *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong uVar8;
  long *plVar9;
  int iVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  long *plStack_80;
  undefined4 uStack_78;
  uint uStack_74;
  undefined8 uStack_70;
  uint uStack_64;
  
  lVar11 = param_1[0x10];
  if ((long *)param_1[0x16] == (long *)0x0) {
    lVar4 = 0;
  }
  else {
    lVar4 = (**(code **)(*(long *)param_1[0x16] + 0xb0))();
  }
  if ((long *)param_1[0x17] == (long *)0x0) {
    lVar5 = 0;
  }
  else {
    lVar5 = (**(code **)(*(long *)param_1[0x17] + 0xb0))();
  }
  uVar6 = (**(code **)(*param_1 + 0x108))(param_1);
  if (DAT_fffffff00af227e8 != 0) {
    lVar14 = param_1[0x12];
    uVar7 = (**(code **)(*param_1 + 0xe0))(param_1);
    plStack_80 = (long *)0x0;
    thunk_EXT_FUN_80110000032db760(uVar7,&plStack_80);
    plVar9 = plStack_80;
    uVar7 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    thunk_EXT_FUN_80110000036da494(0x8518019d,lVar4 + lVar11 + lVar5,(int)lVar14,plVar9,uVar7,0);
  }
  if (*(char *)((long)param_1 + 0x35) == '\x02') {
    uVar12 = 0;
  }
  else {
    uVar1 = 0xe00002bd;
    if (*(int *)((long)param_1 + 0xa4) != 0) {
      uVar1 = 0xe00002c7;
    }
    uVar12 = (ulong)uVar1;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Failed to mark virtual memory non-volatile err 0x%x\n");
  }
  uVar1 = *(uint *)(param_1 + 6) & (*(byte *)(param_1[2] + 0x1fd) & 0x3f) >> 5;
  if ((*(uint *)(param_1 + 6) >> 2 & 1) == 0) {
    uVar8 = FUN_fffffff0099758f0();
    if ((uVar8 & 1) == 0) {
      uVar12 = 0xe00002be;
      if (DAT_fffffff00af227e8 == 0) {
        return 0xe00002be;
      }
      uVar2 = (undefined4)param_1[0x12];
      uVar7 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
      uVar6 = 0;
      goto LAB_fffffff009942398;
    }
  }
  else {
    FUN_fffffff0099758c4(param_1[2],uVar6,uVar1);
  }
  uVar3 = *(uint *)(param_1[2] + 0x1f0) >> 2;
  uStack_64 = 0;
  uStack_74 = (int)param_1[0x14] + 0x3fU >> 6;
  uStack_78 = 0;
  uStack_70 = 0xffffffff00000000;
  plStack_80 = param_1;
  plVar9 = (long *)FUN_fffffff009942410(&plStack_80,&uStack_64);
  if (plVar9 != (long *)0x0) {
    do {
      uVar12 = (**(code **)(*plVar9 + 0xd8))(plVar9,uVar3 & 0x20);
      if ((int)uVar12 != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Failed to prepare memory descriptor(%p) at index %u\n");
        goto LAB_fffffff009942304;
      }
      plVar9 = (long *)FUN_fffffff009942410(&plStack_80,&uStack_64);
    } while (plVar9 != (long *)0x0);
    uVar12 = 0;
  }
  iVar10 = (int)uVar12;
  if (((iVar10 == 0) && (plVar9 = (long *)param_1[0x16], plVar9 != (long *)0x0)) &&
     (uVar8 = (**(code **)(*plVar9 + 0xd8))(plVar9,uVar3 & 0x20), (int)uVar8 != 0)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to prepare metadata (%p)\n");
    uVar12 = uVar8;
LAB_fffffff009942304:
    uVar8 = (ulong)uStack_64;
    if (uStack_64 != 0) {
      lVar13 = 0;
      lVar14 = 0;
      do {
        plVar9 = *(long **)(param_1[0x13] + lVar14 * 8);
        if (plVar9 != (long *)0x0) {
          (**(code **)(*plVar9 + 0xe0))(plVar9,uVar3 & 0x20);
        }
        lVar14 = lVar14 + 1;
        lVar13 = lVar13 + 8;
      } while (uVar8 * 8 - lVar13 != 0);
    }
    FUN_fffffff0099758d8(param_1[2],uVar6,uVar1);
    uVar6 = 0;
  }
  else {
    if ((iVar10 != 0) || (plVar9 = (long *)param_1[0x17], plVar9 == (long *)0x0)) {
      if (iVar10 == 0) goto LAB_fffffff0099423c4;
      goto LAB_fffffff009942304;
    }
    uVar12 = (**(code **)(*plVar9 + 0xd8))(plVar9,uVar3 & 0x20);
    if ((int)uVar12 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Failed to prepare residency data (%p)\n");
      plVar9 = (long *)param_1[0x16];
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0xe0))(plVar9,0);
      }
      goto LAB_fffffff009942304;
    }
LAB_fffffff0099423c4:
    if ((*(byte *)(param_1 + 6) >> 1 & 1) == 0) {
      FUN_fffffff00997d900(*(long *)(param_1[2] + 0x160) + 0x1b8,param_1);
    }
    uVar12 = 0;
    uVar6 = 1;
  }
  if (DAT_fffffff00af227e8 == 0) {
    return uVar12;
  }
  uVar2 = (undefined4)param_1[0x12];
  uVar7 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
LAB_fffffff009942398:
  thunk_EXT_FUN_80110000036da494(0x8518019e,lVar4 + lVar11 + lVar5,uVar2,uVar6,uVar7,0);
  return uVar12;
}

