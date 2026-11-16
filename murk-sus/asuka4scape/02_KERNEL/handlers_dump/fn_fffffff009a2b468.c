// FUN_fffffff009a2b468 @ fffffff009a2b468 size=4 depth=0
// CALLERS:
//   fffffff00afe7a54 ?
//   fffffff008007e58 ?
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff009a2b55c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009a2b5ac) */

ulong FUN_fffffff009a2b468(long *param_1,undefined8 param_2,long param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  long *plVar6;
  long *plVar7;
  ulong extraout_x0;
  undefined8 uVar8;
  undefined8 in_x4;
  undefined8 *puVar9;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  long extraout_x16_02;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined1 uVar13;
  undefined1 extraout_b0;
  undefined1 extraout_b0_00;
  undefined1 uVar14;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 uVar15;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 uVar16;
  undefined1 extraout_var_03;
  undefined1 extraout_var_04;
  undefined1 uVar17;
  undefined1 extraout_var_05;
  undefined1 extraout_var_06;
  undefined1 uVar18;
  undefined1 extraout_var_07;
  undefined1 extraout_var_08;
  undefined1 uVar19;
  undefined1 extraout_var_09;
  undefined1 extraout_var_10;
  undefined1 uVar20;
  undefined1 extraout_var_11;
  undefined1 extraout_var_12;
  undefined1 uVar21;
  undefined1 extraout_var_13;
  undefined1 extraout_var_14;
  undefined1 uVar22;
  undefined1 extraout_var_15;
  undefined1 extraout_var_16;
  undefined1 uVar23;
  undefined1 extraout_var_17;
  undefined1 extraout_var_18;
  undefined1 uVar24;
  undefined1 extraout_var_19;
  undefined1 extraout_var_20;
  undefined1 uVar25;
  undefined1 extraout_var_21;
  undefined1 extraout_var_22;
  undefined1 uVar26;
  undefined1 extraout_var_23;
  undefined1 extraout_var_24;
  undefined1 uVar27;
  undefined1 extraout_var_25;
  undefined1 extraout_var_26;
  undefined1 uVar28;
  undefined1 extraout_var_27;
  undefined1 extraout_var_28;
  undefined1 *in_d1;
  undefined1 *in_register_00005028;
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar29 [16];
  undefined1 *puStack_a0;
  undefined1 *puStack_98;
  undefined1 *puStack_90;
  undefined1 *puStack_88;
  undefined1 *puStack_80;
  undefined1 *puStack_78;
  undefined1 *puStack_70;
  undefined1 *puStack_68;
  long *plStack_60;
  code *pcStack_58;
  undefined1 *puStack_50;
  long *plStack_48;
  
  uVar12 = 0xe00002bd;
  uVar11 = *(ulong *)(*(long *)(param_3 + 0x20) + 8);
  if (uVar11 >> 0x11 != 0) {
    return 0xe00002bd;
  }
  uVar10 = (ulong)*(uint *)(*(long *)(param_3 + 0x20) + 0x10);
  uVar13 = 0xaa;
  uVar14 = 0xaa;
  uVar15 = 0xaa;
  uVar16 = 0xaa;
  uVar17 = 0xaa;
  uVar18 = 0xaa;
  uVar19 = 0xaa;
  uVar20 = 0xaa;
  uVar21 = 0xaa;
  uVar22 = 0xaa;
  uVar23 = 0xaa;
  uVar24 = 0xaa;
  uVar25 = 0xaa;
  uVar26 = 0xaa;
  uVar27 = 0xaa;
  uVar28 = 0xaa;
  pcStack_58 = (code *)&DAT_aaaaaaaaaaaaaaaa;
  plStack_60 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  plStack_48 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  puStack_50 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_78 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_68 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_70 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_98 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_a0 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_88 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_90 = &DAT_aaaaaaaaaaaaaaaa;
  if (*(long *)(param_3 + 8) == 0) {
    uVar12 = 0;
    uVar11 = 0;
    plVar6 = (long *)0x0;
LAB_fffffff009a2b5c4:
    if (*(long **)(param_3 + 0x68) == (long *)0x0) {
      auVar2[1] = uVar14;
      auVar2[0] = uVar13;
      auVar2[2] = uVar15;
      auVar2[3] = uVar16;
      auVar2[4] = uVar17;
      auVar2[5] = uVar18;
      auVar2[6] = uVar19;
      auVar2[7] = uVar20;
      auVar2[8] = uVar21;
      auVar2[9] = uVar22;
      auVar2[10] = uVar23;
      auVar2[0xb] = uVar24;
      auVar2[0xc] = uVar25;
      auVar2[0xd] = uVar26;
      auVar2[0xe] = uVar27;
      auVar2[0xf] = uVar28;
      auVar5._8_8_ = in_register_00005028;
      auVar5._0_8_ = in_d1;
      uVar12 = FUN_fffffff0099d6164
                         (auVar2,auVar5,in_q2,in_q3,in_s4,in_s5,param_1,*(ulong *)(param_3 + 0x30),
                          (ulong)*(uint *)(param_3 + 0x38),*(long *)(param_3 + 0x58),
                          (ulong)*(uint *)(param_3 + 0x60),uVar10,uVar11,uVar12,(ulong)plVar6);
    }
    else {
      auVar29[1] = uVar14;
      auVar29[0] = uVar13;
      auVar29[2] = uVar15;
      auVar29[3] = uVar16;
      auVar29[4] = uVar17;
      auVar29[5] = uVar18;
      auVar29[6] = uVar19;
      auVar29[7] = uVar20;
      auVar29[8] = uVar21;
      auVar29[9] = uVar22;
      auVar29[10] = uVar23;
      auVar29[0xb] = uVar24;
      auVar29[0xc] = uVar25;
      auVar29[0xd] = uVar26;
      auVar29[0xe] = uVar27;
      auVar29[0xf] = uVar28;
      auVar4._8_8_ = in_register_00005028;
      auVar4._0_8_ = in_d1;
      FUN_fffffff009a2c37c
                (auVar29,auVar4,in_q2,in_q3,in_s4,in_s5,param_1,*(ulong *)(param_3 + 0x30),
                 (ulong)*(uint *)(param_3 + 0x38),*(long **)(param_3 + 0x68),in_x4,uVar10,uVar11,
                 uVar12);
      uVar12 = extraout_x0;
    }
  }
  else {
    FUN_fffffff0099cd43c();
    (**(code **)(extraout_x16 + 0x20))(param_1);
    auVar29 = FUN_fffffff0099d8814();
    in_x4 = 0;
    auVar1[1] = extraout_var;
    auVar1[0] = extraout_b0;
    auVar1[2] = extraout_var_01;
    auVar1[3] = extraout_var_03;
    auVar1[4] = extraout_var_05;
    auVar1[5] = extraout_var_07;
    auVar1[6] = extraout_var_09;
    auVar1[7] = extraout_var_11;
    auVar1[8] = extraout_var_13;
    auVar1[9] = extraout_var_15;
    auVar1[10] = extraout_var_17;
    auVar1[0xb] = extraout_var_19;
    auVar1[0xc] = extraout_var_21;
    auVar1[0xd] = extraout_var_23;
    auVar1[0xe] = extraout_var_25;
    auVar1[0xf] = extraout_var_27;
    auVar3._8_8_ = in_register_00005028;
    auVar3._0_8_ = in_d1;
    plVar6 = FUN_fffffff0099d1cfc
                       (auVar1,auVar3,in_q2,in_q3,in_s4,in_s5,auVar29._0_8_,auVar29._8_8_,uVar11,3,0
                       );
    if (plVar6 != (long *)0x0) {
      puVar9 = *(undefined8 **)(param_3 + 0x10);
      puStack_98 = (undefined1 *)puVar9[1];
      puStack_a0 = (undefined1 *)*puVar9;
      puStack_88 = (undefined1 *)puVar9[3];
      puStack_90 = (undefined1 *)puVar9[2];
      puStack_78 = (undefined1 *)puVar9[5];
      puStack_80 = (undefined1 *)puVar9[4];
      in_register_00005028 = (undefined1 *)puVar9[7];
      in_d1 = (undefined1 *)puVar9[6];
      pcStack_58 = FUN_fffffff0099d6024;
      puStack_70 = in_d1;
      puStack_68 = in_register_00005028;
      plStack_60 = param_1;
      plStack_48 = plVar6;
      plVar7 = FUN_fffffff0099d6080(&puStack_a0);
      if (plVar7 != (long *)0x0) {
        *(long **)(plVar7[2] + 0x50) = plVar7;
        FUN_fffffff0099cd400();
        (**(code **)(extraout_x16_00 + 0xf0))();
        uVar11 = (ulong)**(uint **)(param_3 + 0x20);
        uVar12 = plVar7[2] + 0x40;
        uVar13 = extraout_b0_00;
        uVar14 = extraout_var_00;
        uVar15 = extraout_var_02;
        uVar16 = extraout_var_04;
        uVar17 = extraout_var_06;
        uVar18 = extraout_var_08;
        uVar19 = extraout_var_10;
        uVar20 = extraout_var_12;
        uVar21 = extraout_var_14;
        uVar22 = extraout_var_16;
        uVar23 = extraout_var_18;
        uVar24 = extraout_var_20;
        uVar25 = extraout_var_22;
        uVar26 = extraout_var_24;
        uVar27 = extraout_var_26;
        uVar28 = extraout_var_28;
        goto LAB_fffffff009a2b5c4;
      }
    }
    if (*(long *)(param_3 + 8) != 0) {
      uVar8 = FUN_fffffff0099cd400();
      (**(code **)(extraout_x16_01 + 0x108))(uVar8,0);
      (**(code **)(*param_1 + 0x28))(param_1);
      if (plVar6 != (long *)0x0) {
        FUN_fffffff0099d87a8();
        (**(code **)(extraout_x16_02 + 0x28))(plVar6);
      }
    }
  }
  return uVar12;
}

