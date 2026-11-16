// FUN_fffffff009cd0d70 @ fffffff009cd0d70

/* WARNING: Removing unreachable block (ram,0xfffffff009cd2258) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd2100) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1f2c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1d84) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1bdc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1ae4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd19a0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd168c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd14f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd288c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd26e0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1424) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1270) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd10d0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd17fc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd0fc8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1164) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1318) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd2640) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd27e8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd2970) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd15fc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd18e8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd19dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1ba0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1ce4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd1e8c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd2038) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd2478) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd23cc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd2538) */

undefined8
FUN_fffffff009cd0d70
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7)

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
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  bool bVar16;
  int iVar17;
  uint uVar18;
  undefined8 uVar19;
  ulong uVar20;
  undefined8 uVar21;
  long lVar22;
  short *psVar23;
  undefined4 extraout_s0;
  undefined4 extraout_s0_00;
  undefined4 extraout_s0_01;
  undefined4 extraout_s0_02;
  undefined4 extraout_s0_03;
  undefined4 extraout_s0_04;
  undefined4 extraout_s0_05;
  undefined4 extraout_s0_06;
  undefined4 extraout_s0_07;
  undefined4 extraout_s0_08;
  undefined4 extraout_s0_09;
  undefined4 extraout_s0_10;
  undefined4 extraout_s0_11;
  undefined4 extraout_s0_12;
  undefined4 extraout_s0_13;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined4 extraout_var_04;
  undefined4 extraout_var_05;
  undefined4 extraout_var_06;
  undefined4 extraout_var_07;
  undefined4 extraout_var_08;
  undefined4 extraout_var_09;
  undefined4 extraout_var_10;
  undefined4 extraout_var_11;
  undefined4 extraout_var_12;
  undefined4 extraout_var_13;
  undefined8 extraout_var_14;
  undefined8 extraout_var_15;
  undefined8 extraout_var_16;
  undefined8 extraout_var_17;
  undefined8 extraout_var_18;
  undefined8 extraout_var_19;
  undefined8 extraout_var_20;
  undefined8 extraout_var_21;
  undefined8 extraout_var_22;
  undefined8 extraout_var_23;
  undefined8 extraout_var_24;
  undefined8 extraout_var_25;
  undefined8 extraout_var_26;
  undefined8 extraout_var_27;
  undefined8 extraout_var_28;
  ulong local_48;
  
  thunk_FUN_fffffff00a894f30((long *)param_7[0x17],*(long *)PTR_PTR_fffffff008089ca8);
  uVar19 = (*(code *)PTR_FUN_fffffff008087690)(param_7);
  if ((int)uVar19 != 0) {
    if ((*(byte *)((long)param_7 + 0x2691) & 1) == 0) {
      *(int *)(param_7 + 0x4df) = (int)DAT_fffffff0078bddc0;
    }
    (**(code **)(*(long *)param_7[0x4d4] + 0xf0))((long *)param_7[0x4d4],0x32);
    return uVar19;
  }
  iVar17 = (**(code **)(*param_7 + 0x858))(param_7);
  if ((iVar17 != 0) &&
     (iVar17 = (**(code **)(*(long *)param_7[0x4d0] + 0x78))((long *)param_7[0x4d0],2,0x20000,500),
     iVar17 != 0)) {
    if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
        psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar15._4_4_ = extraout_var_03;
        auVar15._0_4_ = extraout_s0_03;
        auVar15._8_8_ = extraout_var_18;
        thunk_FUN_fffffff00a8df19c
                  (auVar15,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)"%s@%s: %s::%s: failed to open AppleTypeCPhy USB2 session\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"%s@%s: %s::%s: failed to open AppleTypeCPhy USB2 session\n");
      }
    }
    if ((*(byte *)((long)param_7 + 0x2691) & 1) == 0) {
      *(int *)(param_7 + 0x4df) = (int)DAT_fffffff0078bddc0;
    }
    (**(code **)(*(long *)param_7[0x4d4] + 0xf0))((long *)param_7[0x4d4],0x32);
    return 0xe00002c5;
  }
  iVar17 = (**(code **)(*param_7 + 0x858))(param_7);
  if ((((iVar17 == 0) || ((*(byte *)((long)param_7 + 0x26f9) & 1) == 0)) ||
      (iVar17 = (**(code **)(*param_7 + 0x688))(param_7), iVar17 < 3)) ||
     (iVar17 = (**(code **)(*(long *)param_7[0x4d1] + 0x78))((long *)param_7[0x4d1],2,0x20000,500),
     iVar17 != 0)) {
    lVar22 = param_7[0x4e5];
    uVar18 = (**(code **)(*param_7 + 0x818))(param_7,lVar22,0xc);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar22,0xc,uVar18 & 0xffffffc7);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
        psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar4._4_4_ = extraout_var;
        auVar4._0_4_ = extraout_s0;
        auVar4._8_8_ = extraout_var_14;
        thunk_FUN_fffffff00a8df19c
                  (auVar4,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                  );
      }
    }
    lVar22 = param_7[0x4e5];
    uVar18 = (**(code **)(*param_7 + 0x818))(param_7,lVar22,0xc);
    (**(code **)(*param_7 + 0x820))(param_7,lVar22,0xc,uVar18 & 0xfffffffc | 2);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
        psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar5._4_4_ = extraout_var_00;
        auVar5._0_4_ = extraout_s0_00;
        auVar5._8_8_ = extraout_var_15;
        thunk_FUN_fffffff00a8df19c
                  (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_MODE = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_MODE = 0x%x\n"
                  );
      }
    }
    lVar22 = param_7[0x4e5];
    uVar18 = (**(code **)(*param_7 + 0x818))(param_7,lVar22,0xc);
    (**(code **)(*param_7 + 0x820))(param_7,lVar22,0xc,uVar18 & 0xffffffc7 | 0x20);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) == 0) goto LAB_fffffff009cd1480;
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
      psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar6._4_4_ = extraout_var_01;
      auVar6._0_4_ = extraout_s0_01;
      auVar6._8_8_ = extraout_var_16;
      thunk_FUN_fffffff00a8df19c
                (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                 (byte *)
                 "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                );
      goto LAB_fffffff009cd1480;
    }
    (**(code **)(*param_7 + 0x1e8))(param_7,0);
    (**(code **)(*param_7 + 0x218))(param_7,0);
  }
  else {
    lVar22 = param_7[0x4e5];
    uVar18 = (**(code **)(*param_7 + 0x818))(param_7,lVar22,0xc);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar22,0xc,uVar18 & 0xffffffc7);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
        psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar1._4_4_ = extraout_var_11;
        auVar1._0_4_ = extraout_s0_11;
        auVar1._8_8_ = extraout_var_26;
        thunk_FUN_fffffff00a8df19c
                  (auVar1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                  );
      }
    }
    lVar22 = param_7[0x4e5];
    uVar18 = (**(code **)(*param_7 + 0x818))(param_7,lVar22,0xc);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar22,0xc,uVar18 & 0xfffffffc);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
        psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar2._4_4_ = extraout_var_12;
        auVar2._0_4_ = extraout_s0_12;
        auVar2._8_8_ = extraout_var_27;
        thunk_FUN_fffffff00a8df19c
                  (auVar2,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_MODE = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_MODE = 0x%x\n"
                  );
      }
    }
    lVar22 = param_7[0x4e5];
    uVar18 = (**(code **)(*param_7 + 0x818))(param_7,lVar22,0xc);
    (**(code **)(*param_7 + 0x820))(param_7,lVar22,0xc,uVar18 & 0xffffffc7 | 8);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) == 0) goto LAB_fffffff009cd1480;
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
      psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar3._4_4_ = extraout_var_13;
      auVar3._0_4_ = extraout_s0_13;
      auVar3._8_8_ = extraout_var_28;
      thunk_FUN_fffffff00a8df19c
                (auVar3,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                 (byte *)
                 "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
                );
      goto LAB_fffffff009cd1480;
    }
    (**(code **)(*param_7 + 0x1e8))(param_7,0);
    (**(code **)(*param_7 + 0x218))(param_7,0);
  }
  thunk_FUN_fffffff00a9029a0
            ((byte *)
             "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_PHY_MUX_SELECT.PIPE_CLK_EN = 0x%x\n"
            );
LAB_fffffff009cd1480:
  uVar20 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0x10);
  if ((uVar20 & 1) != 0) {
    lVar22 = param_7[0x4e5];
    uVar18 = (**(code **)(*param_7 + 0x818))(param_7,lVar22,0x10);
    (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar22,0x10,uVar18 & 0xfffffffe);
    if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
        psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar7._4_4_ = extraout_var_02;
        auVar7._0_4_ = extraout_s0_02;
        auVar7._8_8_ = extraout_var_17;
        thunk_FUN_fffffff00a8df19c
                  (auVar7,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_LOCK_PIPE_IF_REQ.LOCK_PIPE_IF_REQ = 0x%x\n"
                  );
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_PIPE_HANDLER_LOCK_PIPE_IF_REQ.LOCK_PIPE_IF_REQ = 0x%x\n"
                  );
      }
    }
    local_48 = 0;
    thunk_FUN_fffffff00a208ed8(6,1000000,(long *)&local_48);
    uVar20 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e5],0x14);
    while (((uVar20 & 1) != 0 && (uVar20 = thunk_FUN_fffffff00a39bc88(), uVar20 < local_48))) {
      thunk_FUN_fffffff00a902988(500);
      uVar20 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0x14);
    }
    uVar20 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0x14);
    if (((uVar20 & 1) != 0) && ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0)) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
        psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar8._4_4_ = extraout_var_04;
        auVar8._0_4_ = extraout_s0_04;
        auVar8._8_8_ = extraout_var_19;
        thunk_FUN_fffffff00a8df19c
                  (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)"%s@%s: %s::%s: failed PIPE_HANDLER_LOCK_PIPE_IF_ACK\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: failed PIPE_HANDLER_LOCK_PIPE_IF_ACK\n");
      }
    }
  }
  uVar19 = (**(code **)(*(long *)param_7[0x89] + 0x78))();
  uVar21 = (**(code **)(*(long *)param_7[0x89] + 0x78))();
  uVar18 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,uVar21,0x200);
  (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,uVar19,0x200,uVar18 & 0xffffffbf);
  if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
      psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar9._4_4_ = extraout_var_05;
      auVar9._0_4_ = extraout_s0_05;
      auVar9._8_8_ = extraout_var_20;
      thunk_FUN_fffffff00a8df19c
                (auVar9,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_DWC_USB31_BLOCK_GBL_GUSB2PHYCFG_REGS_GUSB2_PHYCFG.SUSPENDUSB20 = 0x%x\n"
                );
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_DWC_USB31_BLOCK_GBL_GUSB2PHYCFG_REGS_GUSB2_PHYCFG.SUSPENDUSB20 = 0x%x\n"
                );
    }
  }
  uVar19 = (**(code **)(*(long *)param_7[0x89] + 0x78))();
  uVar21 = (**(code **)(*(long *)param_7[0x89] + 0x78))();
  uVar18 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,uVar21,0x2c0);
  (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,uVar19,0x2c0,uVar18 & 0xfffdffff);
  if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
      psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar10._4_4_ = extraout_var_06;
      auVar10._0_4_ = extraout_s0_06;
      auVar10._8_8_ = extraout_var_21;
      thunk_FUN_fffffff00a8df19c
                (auVar10,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_DWC_USB31_BLOCK_GBL_GUSB3PIPECTL_REGS_GUSB3_PIPECTL.SUSPENDENABLE = 0x%x\n"
                );
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_DWC_USB31_BLOCK_GBL_GUSB3PIPECTL_REGS_GUSB3_PIPECTL.SUSPENDENABLE = 0x%x\n"
                );
    }
  }
  lVar22 = param_7[0x4e5];
  uVar18 = (**(code **)(*param_7 + 0x818))(param_7,lVar22,0x1c);
  (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar22,0x1c,uVar18 & 0xffffffef);
  if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
      psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar11._4_4_ = extraout_var_07;
      auVar11._0_4_ = extraout_s0_07;
      auVar11._8_8_ = extraout_var_22;
      thunk_FUN_fffffff00a8df19c
                (auVar11,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                 (byte *)
                 "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_AUSBC_AON_GENERAL_REGS.ATC_USB31_DRD_FORCE_CLAMP_EN = 0x%x\n"
                );
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_AUSBC_AON_GENERAL_REGS.ATC_USB31_DRD_FORCE_CLAMP_EN = 0x%x\n"
                );
    }
  }
  lVar22 = param_7[0x4e5];
  uVar18 = (**(code **)(*param_7 + 0x818))(param_7,lVar22,0x1c);
  (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar22,0x1c,uVar18 | 1);
  if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
      psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar12._4_4_ = extraout_var_08;
      auVar12._0_4_ = extraout_s0_08;
      auVar12._8_8_ = extraout_var_23;
      thunk_FUN_fffffff00a8df19c
                (auVar12,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                 (byte *)
                 "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_AUSBC_AON_GENERAL_REGS.ATC_USB31_DRD_SW_VCC_RESET = 0x%x\n"
                );
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: AUSBC_PIPE_HANDLER_BLK_AUSBC_AON_GENERAL_REGS.ATC_USB31_DRD_SW_VCC_RESET = 0x%x\n"
                );
    }
  }
  uVar18 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e5],0xc);
  if ((uVar18 & 3) != 2) {
    local_48 = 0;
    thunk_FUN_fffffff00a208ed8(100,1000000,(long *)&local_48);
    uVar18 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e3],0x28);
    while (((uVar18 >> 0x1e & 1) == 0 && (uVar20 = thunk_FUN_fffffff00a39bc88(), uVar20 < local_48))
          ) {
      thunk_FUN_fffffff00a902968(1);
      uVar18 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x28);
    }
    uVar18 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x28);
    if ((uVar18 >> 0x1e & 1) == 0) {
      if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
          psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          auVar14._4_4_ = extraout_var_10;
          auVar14._0_4_ = extraout_s0_10;
          auVar14._8_8_ = extraout_var_25;
          thunk_FUN_fffffff00a8df19c
                    (auVar14,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                     (byte *)"%s@%s: %s::%s: USB31DRD_PIPE_PHY_READY is 0\n");
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: USB31DRD_PIPE_PHY_READY is 0\n");
        }
      }
      return 0xe00002bc;
    }
  }
  local_48 = 0;
  thunk_FUN_fffffff00a208ed8(100,1000000,(long *)&local_48);
  iVar17 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e7],0x20);
  while ((iVar17 == 0 && (uVar20 = thunk_FUN_fffffff00a39bc88(), uVar20 < local_48))) {
    thunk_FUN_fffffff00a902968(1);
    iVar17 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e7],0x20);
  }
  iVar17 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e7],0x20);
  if ((iVar17 == 0) && ((*(uint *)((long)param_7 + 500) & 1) != 0)) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar16 = thunk_FUN_fffffff00a394140(), !bVar16)) {
      psVar23 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar13._4_4_ = extraout_var_09;
      auVar13._0_4_ = extraout_s0_09;
      auVar13._8_8_ = extraout_var_24;
      thunk_FUN_fffffff00a8df19c
                (auVar13,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar23,0,
                 (byte *)"%s@%s: %s::%s: C0_UTMI_CLK_ACTIVE_EVT_CNT is 0\n");
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: C0_UTMI_CLK_ACTIVE_EVT_CNT is 0\n");
    }
  }
  return 0;
}

