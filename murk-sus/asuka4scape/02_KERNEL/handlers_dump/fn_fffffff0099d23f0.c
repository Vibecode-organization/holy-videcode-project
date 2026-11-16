// FUN_fffffff0099d23f0 @ fffffff0099d23f0 size=4 depth=0
// CALLERS:
//   fffffff00afe6fac ?
//   fffffff008007e80 ?
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff0099d2504) */
/* WARNING: Removing unreachable block (ram,0xfffffff0099d24ac) */

ulong * FUN_fffffff0099d23f0(long *param_1,undefined8 param_2,long param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  long *plVar5;
  ulong *puVar6;
  char *pcVar7;
  undefined *puVar8;
  undefined8 *puVar9;
  undefined1 uVar10;
  undefined1 extraout_b0;
  undefined1 uVar11;
  undefined1 extraout_var;
  undefined1 uVar12;
  undefined1 extraout_var_00;
  undefined1 uVar13;
  undefined1 extraout_var_01;
  undefined1 uVar14;
  undefined1 extraout_var_02;
  undefined1 uVar15;
  undefined1 extraout_var_03;
  undefined1 uVar16;
  undefined1 extraout_var_04;
  undefined1 uVar17;
  undefined1 extraout_var_05;
  undefined1 uVar18;
  undefined1 extraout_var_06;
  undefined1 uVar19;
  undefined1 extraout_var_07;
  undefined1 uVar20;
  undefined1 extraout_var_08;
  undefined1 uVar21;
  undefined1 extraout_var_09;
  undefined1 uVar22;
  undefined1 extraout_var_10;
  undefined1 uVar23;
  undefined1 extraout_var_11;
  undefined1 uVar24;
  undefined1 extraout_var_12;
  undefined1 uVar25;
  undefined1 extraout_var_13;
  undefined1 *in_d1;
  undefined1 *in_register_00005028;
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 *puStack_90;
  undefined1 *puStack_88;
  undefined1 *puStack_80;
  undefined1 *puStack_78;
  undefined1 *puStack_70;
  undefined1 *puStack_68;
  undefined1 *puStack_60;
  undefined1 *puStack_58;
  long *plStack_50;
  code *pcStack_48;
  undefined1 *puStack_40;
  undefined1 *puStack_38;
  
  uVar10 = 0xaa;
  uVar11 = 0xaa;
  uVar12 = 0xaa;
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
  pcStack_48 = (code *)&DAT_aaaaaaaaaaaaaaaa;
  plStack_50 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  puStack_38 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_40 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_68 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_70 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_58 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_60 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_88 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_90 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_78 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
  if (*(long *)(param_3 + 8) == 0) {
    puVar8 = (undefined *)0x0;
    plVar5 = (long *)0x0;
    pcVar7 = (char *)0x0;
  }
  else {
    (**(code **)(*param_1 + 0x20))(param_1);
    puVar9 = *(undefined8 **)(param_3 + 0x10);
    puStack_88 = (undefined1 *)puVar9[1];
    puStack_90 = (undefined1 *)*puVar9;
    puStack_78 = (undefined1 *)puVar9[3];
    puStack_80 = (undefined1 *)puVar9[2];
    puStack_68 = (undefined1 *)puVar9[5];
    puStack_70 = (undefined1 *)puVar9[4];
    in_register_00005028 = (undefined1 *)puVar9[7];
    in_d1 = (undefined1 *)puVar9[6];
    pcStack_48 = FUN_fffffff0099d6024;
    puStack_38 = (undefined1 *)0x0;
    puStack_60 = in_d1;
    puStack_58 = in_register_00005028;
    plStack_50 = param_1;
    plVar5 = FUN_fffffff0099d6080(&puStack_90);
    if (plVar5 == (long *)0x0) {
      puVar6 = (ulong *)0xe00002bd;
      goto LAB_fffffff0099d2540;
    }
    *(long **)(plVar5[2] + 0x50) = plVar5;
    (**(code **)(*(long *)param_1[0x29] + 0xf0))((long *)param_1[0x29],plVar5);
    pcVar7 = (char *)(ulong)**(uint **)(param_3 + 0x20);
    puVar8 = (undefined *)(plVar5[2] + 0x40);
    uVar10 = extraout_b0;
    uVar11 = extraout_var;
    uVar12 = extraout_var_00;
    uVar13 = extraout_var_01;
    uVar14 = extraout_var_02;
    uVar15 = extraout_var_03;
    uVar16 = extraout_var_04;
    uVar17 = extraout_var_05;
    uVar18 = extraout_var_06;
    uVar19 = extraout_var_07;
    uVar20 = extraout_var_08;
    uVar21 = extraout_var_09;
    uVar22 = extraout_var_10;
    uVar23 = extraout_var_11;
    uVar24 = extraout_var_12;
    uVar25 = extraout_var_13;
  }
  if (*(long **)(param_3 + 0x40) == (long *)0x0) {
    auVar2[1] = uVar11;
    auVar2[0] = uVar10;
    auVar2[2] = uVar12;
    auVar2[3] = uVar13;
    auVar2[4] = uVar14;
    auVar2[5] = uVar15;
    auVar2[6] = uVar16;
    auVar2[7] = uVar17;
    auVar2[8] = uVar18;
    auVar2[9] = uVar19;
    auVar2[10] = uVar20;
    auVar2[0xb] = uVar21;
    auVar2[0xc] = uVar22;
    auVar2[0xd] = uVar23;
    auVar2[0xe] = uVar24;
    auVar2[0xf] = uVar25;
    auVar4._8_8_ = in_register_00005028;
    auVar4._0_8_ = in_d1;
    puVar6 = FUN_fffffff009a2c86c
                       (auVar2,auVar4,in_q2,in_q3,in_s4,in_s5,param_1,*(long *)(param_3 + 0x30),
                        (ulong)*(uint *)(param_3 + 0x38),pcVar7,puVar8);
  }
  else {
    auVar1[1] = uVar11;
    auVar1[0] = uVar10;
    auVar1[2] = uVar12;
    auVar1[3] = uVar13;
    auVar1[4] = uVar14;
    auVar1[5] = uVar15;
    auVar1[6] = uVar16;
    auVar1[7] = uVar17;
    auVar1[8] = uVar18;
    auVar1[9] = uVar19;
    auVar1[10] = uVar20;
    auVar1[0xb] = uVar21;
    auVar1[0xc] = uVar22;
    auVar1[0xd] = uVar23;
    auVar1[0xe] = uVar24;
    auVar1[0xf] = uVar25;
    auVar3._8_8_ = in_register_00005028;
    auVar3._0_8_ = in_d1;
    puVar6 = FUN_fffffff009a2c5fc
                       (auVar1,auVar3,in_q2,in_q3,in_s4,in_s5,param_1,*(long **)(param_3 + 0x40),
                        pcVar7,puVar8);
  }
  if ((int)puVar6 == 0) {
    return puVar6;
  }
LAB_fffffff0099d2540:
  if (*(long *)(param_3 + 8) != 0) {
    (**(code **)(*(long *)param_1[0x29] + 0x108))((long *)param_1[0x29],plVar5);
    (**(code **)(*param_1 + 0x28))(param_1);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  return puVar6;
}

