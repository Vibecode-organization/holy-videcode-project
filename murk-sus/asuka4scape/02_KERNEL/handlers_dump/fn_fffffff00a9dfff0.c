// FUN_fffffff00a9dfff0 @ fffffff00a9dfff0 size=1532 depth=0
// CALLERS:
//   fffffff00afbfa78 ?
//   fffffff007c65ab8 ?
//   fffffff007c65ae0 ?
//   fffffff007c65b08 ?
//   fffffff007c65b30 ?
//   fffffff007c65b58 ?
//   fffffff007c65b80 ?
//   fffffff007c65ba8 ?
//   fffffff007c65bd0 ?
//   fffffff007c65bf8 ?
//   fffffff007c65c20 ?
//   fffffff007c65c48 ?
//   fffffff007c65c70 ?
//   fffffff007c65c98 ?
//   fffffff007c65cc0 ?
//   fffffff007c65ce8 ?
//   fffffff007c65d10 ?
//   fffffff007c65d60 ?
//   fffffff007c65d88 ?
//   fffffff007c65db0 ?
//   fffffff007c65dd8 ?
// CALLS:
//   fffffff00aa65b10 FUN_fffffff00aa65b10
//   fffffff00a9e0640 FUN_fffffff00a9e0640
//   fffffff00a9515cc FUN_fffffff00a9515cc
//   fffffff00aa0a3b4 FUN_fffffff00aa0a3b4
//   fffffff00aa0b4ec FUN_fffffff00aa0b4ec
//   fffffff00aa0eacc FUN_fffffff00aa0eacc
//   fffffff00aa119e4 FUN_fffffff00aa119e4
//   fffffff00aa0a77c FUN_fffffff00aa0a77c
//   fffffff00aa0ee74 FUN_fffffff00aa0ee74
//   fffffff00a97ae84 FUN_fffffff00a97ae84
//   fffffff00a9a63f4 FUN_fffffff00a9a63f4

ulong FUN_fffffff00a9dfff0
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                undefined8 param_8,long param_9,ulong *param_10,undefined *param_11)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  bool bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  long *plVar10;
  long *plVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  char *pcVar14;
  undefined8 extraout_x1;
  long lVar15;
  ulong *puVar16;
  long *plVar17;
  long *plVar18;
  ulong uVar19;
  long lVar20;
  uint *puVar21;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined4 uVar22;
  undefined1 auVar23 [12];
  undefined4 uVar24;
  undefined1 auVar25 [12];
  
  uVar24 = param_4._0_4_;
  auVar25 = param_4._4_12_;
  uVar22 = param_3._0_4_;
  auVar23 = param_3._4_12_;
  uVar9 = 0xe00002c1;
  lVar15 = param_9;
  if ((*(uint *)(param_9 + 0x60) != 0) || (*(int *)(param_9 + 0x70) != 0)) {
    plVar18 = *(long **)(param_9 + 0x68);
    if (plVar18 == (long *)0x0) {
      lVar15 = 1;
      param_10 = DAT_fffffff007c68058;
      plVar18 = FUN_fffffff00a97ae84
                          (*(undefined8 *)(param_9 + 0x58),(ulong)*(uint *)(param_9 + 0x60),1,
                           (long)DAT_fffffff007c68058);
      if (plVar18 == (long *)0x0) {
        return 0xe00002bc;
      }
    }
    else {
      (**(code **)(*plVar18 + 0x20))(plVar18);
    }
    plVar10 = (long *)(**(code **)(*plVar18 + 0xe8))(plVar18,0);
    param_1 = extraout_q0;
    if (plVar10 != (long *)0x0) goto LAB_fffffff00a9e00a8;
    uVar19 = 0xe00002bc;
    goto LAB_fffffff00a9e0488;
  }
  plVar18 = (long *)0x0;
  plVar10 = (long *)0x0;
LAB_fffffff00a9e00a8:
  if (0x14 < *(uint *)(param_9 + 4)) {
code_r0xfffffff00a9e0310:
    uVar19 = 0xe00002c2;
    goto code_r0xfffffff00a9e0440;
  }
  uVar19 = 0xe00002c7;
  switch(*(uint *)(param_9 + 4)) {
  default:
    uVar12 = **(undefined8 **)(param_9 + 0x20);
    uVar1 = (*(undefined8 **)(param_9 + 0x20))[1];
    puVar21 = *(uint **)(param_9 + 0x48);
    iVar7 = FUN_fffffff00a9a63f4
                      (*(undefined8 **)(param_7 + 0xe0),(byte *)"local",lVar15,param_10,param_11);
    iVar8 = FUN_fffffff00a9a63f4
                      (*(undefined8 **)(param_7 + 0xe0),&DAT_fffffff0070439ba,lVar15,param_10,
                       param_11);
    if (((iVar7 == 0) || (iVar8 == 0)) &&
       (plVar11 = *(long **)(param_7 + 0xd8), plVar11 != (long *)0x0)) {
      uVar9 = (**(code **)(*plVar11 + 0x4b0))(plVar11,uVar12,uVar1);
    }
    uVar19 = 0;
    *puVar21 = uVar9;
    break;
  case 1:
    uVar19 = (**(code **)(**(long **)(param_7 + 0xd8) + 0x4b8))
                       (*(long **)(param_7 + 0xd8),**(undefined8 **)(param_9 + 0x20),
                        *(undefined8 *)(param_9 + 0x48));
    break;
  case 2:
    puVar16 = *(ulong **)(param_9 + 0x48);
    pcVar14 = (char *)0x0;
    uVar19 = 0;
    goto LAB_fffffff00a9e0368;
  case 3:
    uVar19 = (**(code **)(**(long **)(param_7 + 0xd8) + 0x528))
                       (*(long **)(param_7 + 0xd8),**(undefined8 **)(param_9 + 0x20));
    break;
  case 4:
    uVar19 = (**(code **)(**(long **)(param_7 + 0xd8) + 0x530))
                       (*(long **)(param_7 + 0xd8),**(undefined8 **)(param_9 + 0x20));
    break;
  case 5:
  case 6:
    break;
  case 7:
    pcVar14 = *(char **)(param_9 + 0x30);
    uVar19 = (ulong)*(uint *)(param_9 + 0x38);
    puVar16 = (ulong *)(param_9 + 0x58);
LAB_fffffff00a9e0368:
    FUN_fffffff00a9e0640
              (param_1,param_2,uVar22,uVar24,param_5,param_6,param_7,pcVar14,uVar19,puVar16,param_11
              );
    goto LAB_fffffff00a9e03c8;
  case 8:
    lVar20 = *(long *)(param_9 + 0x30);
    iVar7 = FUN_fffffff00a9a63f4
                      (*(undefined8 **)(param_7 + 0xe0),&DAT_fffffff0070439ba,lVar15,param_10,
                       param_11);
    if ((iVar7 == 0) && (*(long *)(param_7 + 0xd8) != 0)) {
      uVar12 = FUN_fffffff00aa0a77c
                         (extraout_q0_01,param_2,uVar22,uVar24,param_5,param_6,
                          *(long *)(param_7 + 0xd8),lVar20,lVar15,param_10,param_11);
      uVar9 = (uint)uVar12;
    }
    uVar19 = 0;
    *(uint *)(param_9 + 0x58) = uVar9;
    *(undefined4 *)(param_9 + 0x60) = 4;
    break;
  case 9:
    uVar9 = **(uint **)(param_9 + 0x20);
    iVar7 = FUN_fffffff00a9a63f4
                      (*(undefined8 **)(param_7 + 0xe0),&DAT_fffffff0070439ba,lVar15,param_10,
                       param_11);
    if ((iVar7 == 0) && (*(long *)(param_7 + 0xd8) != 0)) {
      FUN_fffffff00aa119e4(*(long *)(param_7 + 0xd8),(ulong)uVar9);
    }
    goto LAB_fffffff00a9e03c8;
  case 10:
    uVar12 = FUN_fffffff00aa0eacc
                       (param_1,param_2,uVar22,uVar24,param_5,param_6,*(long *)(param_7 + 0xd8));
    if ((int)uVar12 != 0) {
      plVar11 = *(long **)(param_7 + 0xd8);
      plVar17 = (long *)plVar11[0x11];
      if (plVar17 != (long *)0x0) {
        (**(code **)(*plVar17 + 0x4a8))(plVar17,0,0);
        plVar11 = *(long **)(param_7 + 0xd8);
      }
      (**(code **)(*plVar11 + 0xd0))(plVar11,"Wake Type","UserActivity Assertion");
    }
    goto LAB_fffffff00a9e03c8;
  case 0xb:
    iVar7 = FUN_fffffff00a9a63f4
                      (*(undefined8 **)(param_7 + 0xe0),&DAT_fffffff0070439ba,lVar15,param_10,
                       param_11);
    uVar19 = 0xe00002c1;
    if (iVar7 == 0) {
      if (*(long *)(param_7 + 0xd8) != 0) {
        uVar9 = 0xe00002c7;
      }
      uVar19 = (ulong)uVar9;
    }
    break;
  case 0xc:
    auVar3._4_12_ = auVar23;
    auVar3._0_4_ = uVar22;
    auVar5._4_12_ = auVar25;
    auVar5._0_4_ = uVar24;
    FUN_fffffff00aa0b4ec
              (param_1,param_2,auVar3,auVar5,param_5,param_6,*(long **)(param_7 + 0xd8),
               (uint)(**(long **)(param_9 + 0x20) != 0),2);
LAB_fffffff00a9e03c8:
    uVar19 = 0;
    break;
  case 0xd:
  case 0xe:
  case 0x10:
    goto code_r0xfffffff00a9e0310;
  case 0xf:
    uVar9 = FUN_fffffff00a9a63f4
                      (*(undefined8 **)(param_7 + 0xe0),&DAT_fffffff0070439ba,lVar15,param_10,
                       param_11);
    uVar19 = (ulong)uVar9;
    if (uVar9 == 0) {
      FUN_fffffff00a9515cc
                (*(long *)(*(long *)(param_7 + 0xd8) + 0xb0),0xe,0,
                 (ulong)**(uint **)(param_9 + 0x20));
    }
    break;
  case 0x11:
    puVar21 = *(uint **)(param_9 + 0x48);
    iVar7 = FUN_fffffff00a9a63f4
                      (*(undefined8 **)(param_7 + 0xe0),&DAT_fffffff0070439ba,lVar15,param_10,
                       param_11);
    if (iVar7 == 0) {
      uVar19 = 0xe00002c1;
      if (*(long **)(param_7 + 0xd8) != (long *)0x0) {
        auVar2._4_12_ = auVar23;
        auVar2._0_4_ = uVar22;
        auVar4._4_12_ = auVar25;
        auVar4._0_4_ = uVar24;
        bVar6 = FUN_fffffff00aa0ee74
                          (extraout_q0_00,param_2,auVar2,auVar4,param_5,param_6,
                           *(long **)(param_7 + 0xd8),extraout_x1,lVar15);
        uVar19 = 0;
        *puVar21 = (uint)bVar6;
      }
    }
    else {
      uVar19 = 0xe00002c1;
    }
    break;
  case 0x12:
code_r0xfffffff00a9e0438:
    uVar19 = 0xe00002bc;
    break;
  case 0x13:
    if (plVar10 == (long *)0x0) {
      uVar19 = 0xe00002c2;
      if (plVar18 == (long *)0x0) {
        return 0xe00002c2;
      }
      goto LAB_fffffff00a9e0488;
    }
    puVar13 = (undefined8 *)(**(code **)(*plVar10 + 0x78))(plVar10);
    lVar15 = *(long *)(param_7 + 0xd8);
    if (lVar15 == 0) {
      uVar19 = 0xe00002bc;
    }
    else {
      uVar19 = (**(code **)(*DAT_fffffff00add78a0 + 0x98))();
      if ((uVar19 & 1) == 0) {
        uVar19 = (**(code **)(*DAT_fffffff00add78a0 + 0x100))
                           ((undefined8 *)(*DAT_fffffff00add78a0 + 0x100),DAT_fffffff00add78a0,
                            FUN_fffffff00aa0a1e0,lVar15,puVar13,0,0,0);
      }
      else if (*(long *)(lVar15 + 0xd0) == 0) {
        uVar19 = 0xe00002f0;
      }
      else {
        FUN_fffffff00aa65b10(puVar13,(undefined8 *)(*(long *)(lVar15 + 0xd0) + 0x60),0x3c10);
        uVar19 = 0;
      }
    }
    goto LAB_fffffff00a9e044c;
  case 0x14:
    if (*(long *)(param_7 + 0xd8) == 0) goto code_r0xfffffff00a9e0438;
    uVar19 = FUN_fffffff00aa0a3b4(*(long *)(param_7 + 0xd8),**(ulong **)(param_9 + 0x20));
  }
code_r0xfffffff00a9e0440:
  if (plVar10 != (long *)0x0) {
LAB_fffffff00a9e044c:
    (**(code **)(*plVar10 + 0xa8))(plVar10);
    (**(code **)(*plVar10 + 0x28))(plVar10);
  }
  if (plVar18 != (long *)0x0) {
LAB_fffffff00a9e0488:
    (**(code **)(*plVar18 + 0x28))(plVar18);
  }
  return uVar19;
}

