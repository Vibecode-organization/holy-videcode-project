// FUN_fffffff00a273d34 @ fffffff00a273d34 size=1500
// CALLERS:
//   fffffff00afb8ca2 ?
//   fffffff00a2774b0 FUN_fffffff00a277460@fffffff00a277460
//   fffffff00a77ba88 FUN_fffffff00a77b798@fffffff00a77b798
//   fffffff00a29c728 FUN_fffffff00a29c674@fffffff00a29c674
// CALLS:
//   fffffff00a274310 FUN_fffffff00a274310
//   fffffff00a22c2dc FUN_fffffff00a22c2dc
//   fffffff00a393464 FUN_fffffff00a393464
//   fffffff00a29b0b4 FUN_fffffff00a29b0b4
//   fffffff00a22c478 FUN_fffffff00a22c478
//   fffffff00a29bafc FUN_fffffff00a29bafc
//   fffffff00aa4d114 FUN_fffffff00aa4d114

undefined4
FUN_fffffff00a273d34
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,int param_8,
          undefined **param_9,uint *param_10,ulong param_11)

{
  long *plVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined *puVar14;
  long lVar15;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  undefined8 extraout_x1_02;
  undefined8 extraout_x1_03;
  undefined **ppuVar16;
  uint *puVar17;
  int iVar18;
  undefined8 *puVar19;
  ulong uVar20;
  ulong uVar21;
  undefined *puVar22;
  undefined8 uVar23;
  undefined *puVar24;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 uVar25;
  undefined *puVar26;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined *puVar27;
  undefined *puVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined *puVar31;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined *local_60;
  undefined *puStack_58;
  undefined8 local_50;
  
  uVar25 = param_1._8_8_;
  uVar23 = param_1._0_8_;
  uVar30 = param_4._0_4_;
  uVar29 = param_3._0_4_;
  puVar27 = param_2._0_8_;
  puVar28 = param_2._8_8_;
  if (param_7 == (long *)0x0) {
    return 4;
  }
  if (param_8 < 6) {
    if (param_8 == 3) {
      if (*param_10 < 10) {
        return 4;
      }
      lVar15 = tpidr_el1;
      uVar21 = daif;
      if (((uint)uVar21 >> 9 & 1) == 0) goto LAB_fffffff00a2741fc;
      if ((uVar21 & 0x1c0) != 0x1c0) {
        uVar20 = daif;
        daif = uVar20 | 0x1c0;
      }
      plVar1 = param_7 + 0x15;
      *(int *)(lVar15 + 0x1c0) = *(int *)(lVar15 + 0x1c0) + 1;
      puVar17 = param_10;
      if (*plVar1 == 0) {
        if (*plVar1 == 0) {
          *plVar1 = lVar15;
          goto LAB_fffffff00a273f70;
        }
      }
      else {
        WaitForEvent();
      }
      FUN_fffffff00a22c2dc(plVar1,lVar15,-0xff843cb48);
      uVar23 = extraout_d0;
      uVar25 = extraout_var;
LAB_fffffff00a273f70:
      auVar6._8_8_ = uVar25;
      auVar6._0_8_ = uVar23;
      auVar7._8_8_ = puVar28;
      auVar7._0_8_ = puVar27;
      FUN_fffffff00a274310
                (auVar6,auVar7,uVar29,uVar30,param_5,param_6,param_7,(undefined4 *)param_9);
      auVar6 = FUN_fffffff00a22c478(plVar1);
      auVar8._8_8_ = puVar28;
      auVar8._0_8_ = puVar27;
      FUN_fffffff00a393464
                (auVar6,auVar8,uVar29,uVar30,param_5,param_6,(ulong)((uVar21 & 0x1c0) != 0x1c0),
                 extraout_x1,param_9,(ulong)puVar17,param_11);
      *param_10 = 10;
      return 0;
    }
    if (param_8 != 4) {
      if (param_8 != 5) {
        return 4;
      }
      local_50 = 0;
      uVar23 = 0;
      uVar25 = 0;
      uStack_68 = 0;
      local_70 = 0;
      puStack_58 = (undefined *)0x0;
      local_60 = (undefined *)0x0;
      if (*param_10 < 0x1c) {
        return 4;
      }
      lVar15 = tpidr_el1;
      uVar21 = daif;
      if (((uint)uVar21 >> 9 & 1) == 0) goto LAB_fffffff00a2741fc;
      if ((uVar21 & 0x1c0) != 0x1c0) {
        uVar20 = daif;
        daif = uVar20 | 0x1c0;
      }
      plVar1 = param_7 + 0x15;
      *(int *)(lVar15 + 0x1c0) = *(int *)(lVar15 + 0x1c0) + 1;
      puVar17 = param_10;
      if (*plVar1 == 0) {
        if (*plVar1 == 0) {
          *plVar1 = lVar15;
          ppuVar16 = param_9;
          goto LAB_fffffff00a273e78;
        }
      }
      else {
        WaitForEvent();
      }
      ppuVar16 = &PTR_s_hw_lock_t_fffffff007bc34b8;
      FUN_fffffff00a22c2dc(plVar1,lVar15,-0xff843cb48);
      uVar23 = extraout_d0_00;
      uVar25 = extraout_var_00;
LAB_fffffff00a273e78:
      auVar4._8_8_ = uVar25;
      auVar4._0_8_ = uVar23;
      auVar10._8_8_ = puVar28;
      auVar10._0_8_ = puVar27;
      FUN_fffffff00a274310
                (auVar4,auVar10,uVar29,uVar30,param_5,param_6,param_7,(undefined4 *)&local_70);
      *param_9 = (undefined *)((long)(int)local_70 * 1000000000 + (long)local_70._4_4_ * 1000);
      param_9[1] = (undefined *)((long)(int)uStack_68 * 1000000000 + (long)uStack_68._4_4_ * 1000);
      param_9[3] = puStack_58;
      param_9[2] = local_60;
      *(undefined4 *)(param_9 + 4) = local_50._4_4_;
      *(int *)((long)param_9 + 0x24) = (int)*(short *)((long)param_7 + 0x204);
      *(int *)(param_9 + 5) = (int)*(short *)((long)param_7 + 0x206);
      *(int *)((long)param_9 + 0x2c) = (int)*(short *)((long)param_7 + 0x20a);
      puVar19 = (undefined8 *)param_7[0xee];
      if (puVar19 == (undefined8 *)0x0) {
        *(undefined1 *)(param_9 + 6) = 0;
      }
      else {
        puVar26 = (undefined *)puVar19[1];
        puVar24 = (undefined *)*puVar19;
        puVar28 = (undefined *)puVar19[3];
        puVar27 = (undefined *)puVar19[2];
        puVar22 = (undefined *)puVar19[4];
        uVar29 = SUB84(puVar22,0);
        puVar31 = (undefined *)puVar19[7];
        puVar14 = (undefined *)puVar19[6];
        uVar30 = SUB84(puVar14,0);
        param_9[0xb] = (undefined *)puVar19[5];
        param_9[10] = puVar22;
        param_9[0xd] = puVar31;
        param_9[0xc] = puVar14;
        param_9[7] = puVar26;
        param_9[6] = puVar24;
        param_9[9] = puVar28;
        param_9[8] = puVar27;
      }
      auVar6 = FUN_fffffff00a22c478(plVar1);
      auVar11._8_8_ = puVar28;
      auVar11._0_8_ = puVar27;
      FUN_fffffff00a393464
                (auVar6,auVar11,uVar29,uVar30,param_5,param_6,(ulong)((uVar21 & 0x1c0) != 0x1c0),
                 extraout_x1_01,ppuVar16,(ulong)puVar17,param_11);
      *param_10 = 0x1c;
      return 0;
    }
    if (*param_10 < 6) {
      return 4;
    }
    lVar15 = tpidr_el1;
    uVar21 = daif;
    if (((uint)uVar21 >> 9 & 1) == 0) goto LAB_fffffff00a2741fc;
    if ((uVar21 & 0x1c0) != 0x1c0) {
      uVar20 = daif;
      daif = uVar20 | 0x1c0;
    }
    plVar1 = param_7 + 0x15;
    *(int *)(lVar15 + 0x1c0) = *(int *)(lVar15 + 0x1c0) + 1;
    if (*plVar1 == 0) {
      if (*plVar1 != 0) goto LAB_fffffff00a2742e8;
      *plVar1 = lVar15;
    }
    else {
      WaitForEvent();
LAB_fffffff00a2742e8:
      FUN_fffffff00a22c2dc(plVar1,lVar15,-0xff843cb48);
    }
    *param_9 = (undefined *)param_7[0x9c];
    puVar22 = (undefined *)param_7[0x28];
    param_9[1] = puVar22;
    if (puVar22 == (undefined *)0x0) {
      puVar22 = (undefined *)0x0;
    }
    else {
      lVar15 = FUN_fffffff00a29bafc((long)param_7);
      uVar20 = FUN_fffffff00a29b0b4(lVar15);
      if ((*(byte *)((long)param_7 + 0x42b) >> 4 & 1) == 0) {
        if (uVar20 == 0) {
          puVar22 = (undefined *)0x0;
          goto LAB_fffffff00a274120;
        }
        lVar15 = *(long *)(uVar20 + 0x680);
      }
      else {
        lVar15 = *(long *)(lVar15 + 0x600);
      }
      puVar22 = puVar22 + lVar15;
    }
LAB_fffffff00a274120:
    param_9[2] = puVar22;
    auVar6 = FUN_fffffff00a22c478(plVar1);
    auVar9._8_8_ = puVar28;
    auVar9._0_8_ = puVar27;
    FUN_fffffff00a393464
              (auVar6,auVar9,uVar29,uVar30,param_5,param_6,(ulong)((uVar21 & 0x1c0) != 0x1c0),
               extraout_x1_02,param_9,(ulong)param_10,param_11);
    return 0;
  }
  if (10 < param_8) {
    if (param_8 != 0xb) {
      if (param_8 != 0xc) {
        return 4;
      }
      if (3 < *param_10) {
        return 0x1c;
      }
      return 4;
    }
    if (*param_10 < 5) {
      return 4;
    }
    lVar15 = tpidr_el1;
    uVar21 = daif;
    if (((uint)uVar21 >> 9 & 1) == 0) goto LAB_fffffff00a2741fc;
    if ((uVar21 & 0x1c0) != 0x1c0) {
      uVar20 = daif;
      daif = uVar20 | 0x1c0;
    }
    uVar21 = (ulong)((uVar21 & 0x1c0) != 0x1c0);
    plVar1 = param_7 + 0x15;
    *(int *)(lVar15 + 0x1c0) = *(int *)(lVar15 + 0x1c0) + 1;
    if (*plVar1 == 0) {
      if (*plVar1 != 0) goto LAB_fffffff00a274258;
      *plVar1 = lVar15;
    }
    else {
      WaitForEvent();
LAB_fffffff00a274258:
      FUN_fffffff00a22c2dc(plVar1,lVar15,-0xff843cb48);
    }
    if (*(int *)((long)param_7 + 0x1ec) == 3) goto LAB_fffffff00a274000;
    uVar2 = *(uint *)(param_7 + 0x40);
    *(uint *)((long)param_9 + 0xc) = (uint)((uVar2 & 0xc0) != 0);
    if ((uVar2 & 0xc0) == 0) {
      *(int *)((long)param_9 + 4) = (int)*(short *)((long)param_7 + 0x206);
      iVar18 = -1;
    }
    else {
      *(undefined4 *)((long)param_9 + 4) = 0;
      iVar18 = (int)*(short *)((long)param_7 + 0x206);
    }
    *(int *)(param_9 + 2) = iVar18;
    uVar20 = (ulong)DAT_fffffff00ad08000;
    uVar2 = 0;
    if (DAT_fffffff00ad08000 != 0) {
      uVar2 = DAT_fffffff00ad34c30 / DAT_fffffff00ad08000;
    }
    uVar3 = 0;
    if (uVar20 != 0) {
      uVar3 = (((ulong)DAT_fffffff00ad34c30 - uVar20 * uVar2) * 1000000000) / uVar20;
    }
    *(int *)param_9 = (int)*(short *)((long)param_7 + 0x20a);
    *(int *)(param_9 + 1) = (int)((uVar3 + (ulong)uVar2 * 1000000000) / 1000000);
    goto LAB_fffffff00a2741c4;
  }
  if (param_8 == 6) {
    return 0x2e;
  }
  if (param_8 != 10) {
    return 4;
  }
  if (*param_10 < 5) {
    return 4;
  }
  lVar15 = tpidr_el1;
  uVar21 = daif;
  if (((uint)uVar21 >> 9 & 1) == 0) {
LAB_fffffff00a2741fc:
    auVar5._8_8_ = uVar25;
    auVar5._0_8_ = uVar23;
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114
              (auVar5,param_2,param_3,param_4,param_5,param_6,
               (byte *)"%s: debug exceptions enabled in kernel mode @%s:%d");
  }
  if ((uVar21 & 0x1c0) != 0x1c0) {
    uVar20 = daif;
    daif = uVar20 | 0x1c0;
  }
  uVar21 = (ulong)((uVar21 & 0x1c0) != 0x1c0);
  plVar1 = param_7 + 0x15;
  *(int *)(lVar15 + 0x1c0) = *(int *)(lVar15 + 0x1c0) + 1;
  if (*plVar1 == 0) {
    if (*plVar1 != 0) goto LAB_fffffff00a27428c;
    *plVar1 = lVar15;
  }
  else {
    WaitForEvent();
LAB_fffffff00a27428c:
    FUN_fffffff00a22c2dc(plVar1,lVar15,-0xff843cb48);
  }
  if (*(int *)((long)param_7 + 0x1ec) != 3) {
LAB_fffffff00a274000:
    auVar6 = FUN_fffffff00a22c478(param_7 + 0x15);
    auVar12._8_8_ = puVar28;
    auVar12._0_8_ = puVar27;
    FUN_fffffff00a393464
              (auVar6,auVar12,uVar29,uVar30,param_5,param_6,uVar21,extraout_x1_00,param_9,
               (ulong)param_10,param_11);
    return 0x1c;
  }
  uVar2 = *(uint *)(param_7 + 0x40);
  *(uint *)((long)param_9 + 0xc) = (uint)((uVar2 & 0xc0) != 0);
  if ((uVar2 & 0xc0) == 0) {
    *(int *)((long)param_9 + 4) = (int)*(short *)((long)param_7 + 0x206);
    iVar18 = -1;
  }
  else {
    *(undefined4 *)((long)param_9 + 4) = 0;
    iVar18 = (int)*(short *)((long)param_7 + 0x206);
  }
  *(int *)(param_9 + 2) = iVar18;
  *(int *)(param_9 + 1) = (int)*(short *)((long)param_7 + 0x204);
  *(int *)param_9 = (int)*(short *)((long)param_7 + 0x20a);
LAB_fffffff00a2741c4:
  puVar17 = param_10;
  auVar6 = FUN_fffffff00a22c478(param_7 + 0x15);
  auVar13._8_8_ = puVar28;
  auVar13._0_8_ = puVar27;
  FUN_fffffff00a393464
            (auVar6,auVar13,uVar29,uVar30,param_5,param_6,uVar21,extraout_x1_03,param_9,
             (ulong)puVar17,param_11);
  *param_10 = 5;
  return 0;
}

