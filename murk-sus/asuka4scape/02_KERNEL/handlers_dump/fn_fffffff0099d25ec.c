// FUN_fffffff0099d25ec @ fffffff0099d25ec size=4 depth=0
// CALLERS:
//   fffffff00afe6fad ?
//   fffffff008007ea8 ?
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff0099d26bc) */
/* WARNING: Removing unreachable block (ram,0xfffffff0099d2714) */

undefined8 FUN_fffffff0099d25ec(long *param_1,undefined8 param_2,long param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  long *plVar11;
  long *plVar12;
  undefined8 extraout_x0;
  undefined8 *puVar13;
  undefined8 uVar14;
  ulong uVar15;
  long lVar16;
  undefined1 uVar17;
  undefined1 extraout_b0;
  undefined1 extraout_b0_00;
  undefined1 uVar18;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 uVar19;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 uVar20;
  undefined1 extraout_var_03;
  undefined1 extraout_var_04;
  undefined1 uVar21;
  undefined1 extraout_var_05;
  undefined1 extraout_var_06;
  undefined1 uVar22;
  undefined1 extraout_var_07;
  undefined1 extraout_var_08;
  undefined1 uVar23;
  undefined1 extraout_var_09;
  undefined1 extraout_var_10;
  undefined1 uVar24;
  undefined1 extraout_var_11;
  undefined1 extraout_var_12;
  undefined1 uVar25;
  undefined1 extraout_var_13;
  undefined1 extraout_var_14;
  undefined1 uVar26;
  undefined1 extraout_var_15;
  undefined1 extraout_var_16;
  undefined1 uVar27;
  undefined1 extraout_var_17;
  undefined1 extraout_var_18;
  undefined1 uVar28;
  undefined1 extraout_var_19;
  undefined1 extraout_var_20;
  undefined1 uVar29;
  undefined1 extraout_var_21;
  undefined1 extraout_var_22;
  undefined1 uVar30;
  undefined1 extraout_var_23;
  undefined1 extraout_var_24;
  undefined1 uVar31;
  undefined1 extraout_var_25;
  undefined1 extraout_var_26;
  undefined1 uVar32;
  undefined1 extraout_var_27;
  undefined1 extraout_var_28;
  undefined1 *in_d1;
  undefined1 *in_register_00005028;
  undefined4 in_s2;
  undefined1 in_register_00005044 [12];
  undefined4 in_s3;
  undefined1 in_register_00005064 [12];
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 *puStack_c0;
  undefined1 *puStack_b8;
  undefined1 *puStack_b0;
  undefined1 *puStack_a8;
  undefined1 *puStack_a0;
  undefined1 *puStack_98;
  undefined1 *puStack_90;
  undefined1 *puStack_88;
  undefined1 *puStack_80;
  undefined1 *puStack_78;
  long *plStack_70;
  undefined1 *puStack_68;
  undefined1 *puStack_60;
  
  uVar14 = 0xe00002bd;
  puStack_60 = &DAT_aaaaaaaaaaaaaaaa;
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
  uVar29 = 0xaa;
  uVar30 = 0xaa;
  uVar31 = 0xaa;
  uVar32 = 0xaa;
  puStack_78 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_68 = &DAT_aaaaaaaaaaaaaaaa;
  plStack_70 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  puStack_98 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_a0 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_88 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_90 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_b8 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_c0 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_a8 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_b0 = &DAT_aaaaaaaaaaaaaaaa;
  if (*(long *)(param_3 + 8) == 0) {
    uVar15 = 0;
    lVar16 = 0;
    plVar11 = (long *)0x0;
LAB_fffffff0099d272c:
    if (*(long *)(param_3 + 0x68) != 0) {
      auVar2[1] = uVar18;
      auVar2[0] = uVar17;
      auVar2[2] = uVar19;
      auVar2[3] = uVar20;
      auVar2[4] = uVar21;
      auVar2[5] = uVar22;
      auVar2[6] = uVar23;
      auVar2[7] = uVar24;
      auVar2[8] = uVar25;
      auVar2[9] = uVar26;
      auVar2[10] = uVar27;
      auVar2[0xb] = uVar28;
      auVar2[0xc] = uVar29;
      auVar2[0xd] = uVar30;
      auVar2[0xe] = uVar31;
      auVar2[0xf] = uVar32;
      auVar5._8_8_ = in_register_00005028;
      auVar5._0_8_ = in_d1;
      auVar8._4_12_ = in_register_00005044;
      auVar8._0_4_ = in_s2;
      auVar10._4_12_ = in_register_00005064;
      auVar10._0_4_ = in_s3;
      plVar12 = FUN_fffffff0099d1cfc
                          (auVar2,auVar5,auVar8,auVar10,in_s4,in_s5,
                           *(long *)PTR_DAT_fffffff008017480,(undefined8 *)0x0,
                           (ulong)*(uint *)(param_3 + 0x70),3,0);
      if (plVar12 != (long *)0x0) {
        auVar3[1] = extraout_var_00;
        auVar3[0] = extraout_b0_00;
        auVar3[2] = extraout_var_02;
        auVar3[3] = extraout_var_04;
        auVar3[4] = extraout_var_06;
        auVar3[5] = extraout_var_08;
        auVar3[6] = extraout_var_10;
        auVar3[7] = extraout_var_12;
        auVar3[8] = extraout_var_14;
        auVar3[9] = extraout_var_16;
        auVar3[10] = extraout_var_18;
        auVar3[0xb] = extraout_var_20;
        auVar3[0xc] = extraout_var_22;
        auVar3[0xd] = extraout_var_24;
        auVar3[0xe] = extraout_var_26;
        auVar3[0xf] = extraout_var_28;
        auVar6._8_8_ = in_register_00005028;
        auVar6._0_8_ = in_d1;
        uVar14 = FUN_fffffff0099d6ac4
                           (auVar3,auVar6,in_s2,in_s3,in_s4,in_s5,param_1,plVar12,
                            (uint *)(param_3 + 0x70),(ulong)**(uint **)(param_3 + 0x20),
                            (ulong)(*(uint **)(param_3 + 0x20))[2],uVar15,lVar16);
        if ((int)uVar14 == 0 && lVar16 == 0) {
          uVar14 = (**(code **)(**(long **)(param_3 + 0x68) + 0xd8))(*(long **)(param_3 + 0x68),0);
          if ((int)uVar14 == 0) {
            plVar11 = *(long **)(param_3 + 0x68);
            uVar14 = (**(code **)(*plVar12 + 0x148))(plVar12);
            (**(code **)(*plVar11 + 0xd0))(plVar11,0,uVar14,*(undefined4 *)(param_3 + 0x70));
            (**(code **)(**(long **)(param_3 + 0x68) + 0xe0))(*(long **)(param_3 + 0x68),0);
            uVar14 = 0;
            goto LAB_fffffff0099d28d0;
          }
        }
        else if ((int)uVar14 == 0) goto LAB_fffffff0099d2810;
      }
      goto LAB_fffffff0099d2798;
    }
    auVar1[1] = uVar18;
    auVar1[0] = uVar17;
    auVar1[2] = uVar19;
    auVar1[3] = uVar20;
    auVar1[4] = uVar21;
    auVar1[5] = uVar22;
    auVar1[6] = uVar23;
    auVar1[7] = uVar24;
    auVar1[8] = uVar25;
    auVar1[9] = uVar26;
    auVar1[10] = uVar27;
    auVar1[0xb] = uVar28;
    auVar1[0xc] = uVar29;
    auVar1[0xd] = uVar30;
    auVar1[0xe] = uVar31;
    auVar1[0xf] = uVar32;
    auVar4._8_8_ = in_register_00005028;
    auVar4._0_8_ = in_d1;
    auVar7._4_12_ = in_register_00005044;
    auVar7._0_4_ = in_s2;
    auVar9._4_12_ = in_register_00005064;
    auVar9._0_4_ = in_s3;
    FUN_fffffff009a2c984
              (auVar1,auVar4,auVar7,auVar9,in_s4,in_s5,param_1,*(undefined8 *)(param_3 + 0x58),
               (uint *)(param_3 + 0x60),(ulong)**(uint **)(param_3 + 0x20),
               (ulong)(*(uint **)(param_3 + 0x20))[2],uVar15,lVar16);
    plVar12 = (long *)0x0;
    uVar14 = extraout_x0;
    if ((int)extraout_x0 != 0) goto LAB_fffffff0099d2798;
  }
  else {
    (**(code **)(*param_1 + 0x20))(param_1);
    puVar13 = *(undefined8 **)(param_3 + 0x10);
    puStack_b8 = (undefined1 *)puVar13[1];
    puStack_c0 = (undefined1 *)*puVar13;
    puStack_a8 = (undefined1 *)puVar13[3];
    puStack_b0 = (undefined1 *)puVar13[2];
    puStack_98 = (undefined1 *)puVar13[5];
    puStack_a0 = (undefined1 *)puVar13[4];
    in_register_00005028 = (undefined1 *)puVar13[7];
    in_d1 = (undefined1 *)puVar13[6];
    puStack_68 = &LAB_fffffff0099d697c;
    puStack_90 = in_d1;
    puStack_88 = in_register_00005028;
    plStack_70 = param_1;
    plVar11 = FUN_fffffff0099d69d8(&puStack_c0);
    if (plVar11 != (long *)0x0) {
      *(long **)(plVar11[2] + 0x60) = plVar11;
      (**(code **)(*(long *)param_1[0x29] + 0xf0))((long *)param_1[0x29],plVar11);
      uVar15 = (ulong)*(uint *)(*(long *)(param_3 + 0x20) + 0x10);
      lVar16 = plVar11[2] + 0x50;
      uVar17 = extraout_b0;
      uVar18 = extraout_var;
      uVar19 = extraout_var_01;
      uVar20 = extraout_var_03;
      uVar21 = extraout_var_05;
      uVar22 = extraout_var_07;
      uVar23 = extraout_var_09;
      uVar24 = extraout_var_11;
      uVar25 = extraout_var_13;
      uVar26 = extraout_var_15;
      uVar27 = extraout_var_17;
      uVar28 = extraout_var_19;
      uVar29 = extraout_var_21;
      uVar30 = extraout_var_23;
      uVar31 = extraout_var_25;
      uVar32 = extraout_var_27;
      goto LAB_fffffff0099d272c;
    }
    plVar12 = (long *)0x0;
LAB_fffffff0099d2798:
    if (*(long *)(param_3 + 8) != 0) {
      (**(code **)(*(long *)param_1[0x29] + 0x108))((long *)param_1[0x29],plVar11);
      (**(code **)(*param_1 + 0x28))(param_1);
      if (plVar11 != (long *)0x0) {
        (**(code **)(*plVar11 + 0x28))(plVar11);
      }
    }
  }
LAB_fffffff0099d2810:
  if (plVar12 == (long *)0x0) {
    return uVar14;
  }
LAB_fffffff0099d28d0:
  (**(code **)(*plVar12 + 0x28))(plVar12);
  return uVar14;
}

