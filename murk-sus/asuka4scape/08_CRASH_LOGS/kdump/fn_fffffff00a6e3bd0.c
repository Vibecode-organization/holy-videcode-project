// FUN_fffffff00a6e3bd0 @ fffffff00a6e3bd0 size=552
// CALLERS:
//   fffffff00afbc4da ?
//   fffffff00a6e3bac FUN_fffffff00a6e3b70@fffffff00a6e3b70
//   fffffff00a6e4720 FUN_fffffff00a6e4700@fffffff00a6e4700
//   fffffff00a6e475c FUN_fffffff00a6e473c@fffffff00a6e473c
//   fffffff00a6e525c FUN_fffffff00a6e5250@fffffff00a6e5250
//   fffffff00a6e526c FUN_fffffff00a6e5260@fffffff00a6e5260
// CALLS:
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a6e42a0 FUN_fffffff00a6e42a0
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a6e22f8 FUN_fffffff00a6e22f8
//   fffffff00a6e4430 FUN_fffffff00a6e4430
//   fffffff00a6e3df8 FUN_fffffff00a6e3df8
//   fffffff00a6d94a4 FUN_fffffff00a6d94a4
//   fffffff00a6e2494 FUN_fffffff00a6e2494

ulong FUN_fffffff00a6e3bd0
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                undefined8 *param_8,undefined4 param_9,undefined8 param_10,undefined *param_11)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined *******pppppppuVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  undefined8 extraout_x1_02;
  undefined8 extraout_x1_03;
  undefined8 extraout_x1_04;
  undefined8 uVar7;
  undefined8 extraout_x1_05;
  ulong uVar8;
  undefined ********ppppppppuVar9;
  long lVar10;
  long lVar11;
  undefined *******pppppppuVar12;
  uint in_wzr;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar13 [16];
  byte local_49;
  undefined *******local_48;
  
  local_48 = (undefined *******)0x0;
  local_49 = 0;
  ppppppppuVar9 = &local_48;
  uVar5 = FUN_fffffff00a6e3df8
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     (ulong *)ppppppppuVar9,(ulong)param_11);
  pppppppuVar4 = local_48;
  if ((int)uVar5 != 0) {
    return uVar5;
  }
  bVar3 = *(byte *)(local_48 + 0x16);
  uVar7 = extraout_x1;
  auVar13 = extraout_q0;
  if (DAT_fffffff007c06978 == 0) {
LAB_fffffff00a6e3c38:
    uVar5 = param_7 + 0x50;
  }
  else {
    lVar10 = *(long *)(param_7 + 0x640);
    if (lVar10 == 0) {
      auVar13 = FUN_fffffff00a6e22f8(param_7);
      lVar10 = *(long *)(param_7 + 0x640);
      uVar7 = extraout_x1_00;
      if (lVar10 == 0) goto LAB_fffffff00a6e3c38;
    }
    uVar5 = lVar10 + 0x18;
  }
  lVar10 = tpidr_el1;
  if (*(ulong *)(uVar5 + 8) == 0) {
    *(ulong *)(uVar5 + 8) = (ulong)*(uint *)(lVar10 + 0x4e8);
  }
  else {
    auVar13 = FUN_fffffff00a2262d4(uVar5,lVar10,(undefined **)0x0);
    uVar7 = extraout_x1_03;
  }
  pppppppuVar12 = pppppppuVar4 + 0xf;
  if (*(int *)pppppppuVar12 == 4) {
    if ((*(byte *)((long)pppppppuVar4 + 0x31) >> 3 & 1) == 0) {
      ppppppppuVar9 = (undefined ********)pppppppuVar4[9];
      param_11 = (undefined *)0xfffffffd;
      uVar5 = FUN_fffffff00a6e42a0
                        (auVar13,param_2,param_3,param_4,param_5,param_6,param_7,pppppppuVar4,
                         (long)pppppppuVar12,ppppppppuVar9,(undefined ********)0xfffffffd,0x1135,
                         (long *)0x0);
      uVar7 = extraout_x1_01;
      if ((int)uVar5 == 0) {
        *(uint *)(pppppppuVar4 + 6) = *(uint *)(pppppppuVar4 + 6) | 0x400;
        auVar13 = extraout_q0_00;
        goto LAB_fffffff00a6e3ca0;
      }
    }
    else {
      uVar5 = 0x16;
    }
  }
  else {
LAB_fffffff00a6e3ca0:
    uVar5 = FUN_fffffff00a6e4430
                      (auVar13,param_2,param_3,param_4,param_5,param_6,param_7,pppppppuVar4,0,
                       (uint)bVar3,&local_49);
    if ((uVar5 & 1) != 0) {
      if (DAT_fffffff007c06978 == 0) {
LAB_fffffff00a6e3da8:
        uVar5 = param_7 + 0x50;
      }
      else {
        lVar11 = *(long *)(param_7 + 0x640);
        if (lVar11 == 0) {
          FUN_fffffff00a6e22f8(param_7);
          lVar11 = *(long *)(param_7 + 0x640);
          if (lVar11 == 0) goto LAB_fffffff00a6e3da8;
        }
        uVar5 = lVar11 + 0x18;
      }
      uVar1 = *(uint *)(uVar5 + 8);
      if (uVar1 == *(uint *)(lVar10 + 0x4e8)) {
        *(uint *)(uVar5 + 8) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(uVar5,lVar10,uVar1);
      }
      if ((local_49 & 1) != 0) {
        FUN_fffffff00a6d94a4(0,(ulong)bVar3);
        return 0;
      }
      return 0;
    }
    ppppppppuVar9 = (undefined ********)pppppppuVar4[9];
    param_11 = (undefined *)0xfffffffd;
    uVar5 = FUN_fffffff00a6e42a0
                      (extraout_q0_01,param_2,param_3,param_4,param_5,param_6,param_7,pppppppuVar4,
                       (long)pppppppuVar12,ppppppppuVar9,(undefined ********)0xfffffffd,0x1102,
                       (long *)0x0);
    if ((int)uVar5 == 0) {
      *(uint *)(pppppppuVar4 + 6) = *(uint *)(pppppppuVar4 + 6) & 0xfffffbff;
    }
    uVar5 = 0x23;
    uVar7 = extraout_x1_02;
  }
  if (DAT_fffffff007c06978 == 0) {
LAB_fffffff00a6e3d4c:
    uVar6 = param_7 + 0x50;
  }
  else {
    lVar11 = *(long *)(param_7 + 0x640);
    if (lVar11 == 0) {
      FUN_fffffff00a6e22f8(param_7);
      lVar11 = *(long *)(param_7 + 0x640);
      uVar7 = extraout_x1_04;
      if (lVar11 == 0) goto LAB_fffffff00a6e3d4c;
    }
    uVar6 = lVar11 + 0x18;
  }
  uVar2 = *(uint *)(lVar10 + 0x4e8);
  uVar1 = *(uint *)(uVar6 + 8);
  if (uVar1 == uVar2) {
    *(uint *)(uVar6 + 8) = in_wzr;
  }
  uVar8 = (ulong)uVar1;
  if (uVar1 != uVar2) {
    FUN_fffffff00a226e08(uVar6,lVar10,uVar1);
    uVar7 = extraout_x1_05;
  }
  FUN_fffffff00a6e2494(pppppppuVar4,uVar7,uVar8,(undefined **)ppppppppuVar9,param_11);
  return uVar5;
}

