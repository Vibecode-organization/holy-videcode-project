// FUN_fffffff009cce910 @ fffffff009cce910

/* WARNING: Removing unreachable block (ram,0xfffffff009ccec90) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cceb18) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ccec58) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ccee8c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ccecf4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ccefd0) */

undefined8
FUN_fffffff009cce910
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  bool bVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined1 *puVar10;
  long extraout_x0;
  long *plVar11;
  short *psVar12;
  undefined4 extraout_s0;
  undefined4 extraout_s0_00;
  undefined4 extraout_s0_01;
  undefined4 extraout_s0_02;
  undefined4 uVar13;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined4 uVar14;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined4 uVar15;
  undefined1 auVar16 [12];
  undefined4 uVar17;
  undefined1 auVar18 [12];
  undefined1 *local_38;
  
  uVar17 = param_4._0_4_;
  auVar18 = param_4._4_12_;
  uVar15 = param_3._0_4_;
  auVar16 = param_3._4_12_;
  thunk_FUN_fffffff00a894f30((long *)param_7[0x17],*(long *)PTR_PTR_fffffff008089ca8);
  uVar9 = (*(code *)PTR_FUN_fffffff008087690)(param_7);
  if ((int)uVar9 == 0) {
    iVar7 = (**(code **)(*param_7 + 0x858))(param_7);
    if (iVar7 != 0) {
      (**(code **)(*param_7 + 0x928))(param_7);
      (**(code **)(*param_7 + 0x908))(param_7);
      iVar7 = (**(code **)(*(long *)param_7[0x4d1] + 0x78))((long *)param_7[0x4d1],2,0x20000,500);
      if ((iVar7 != 0) ||
         (iVar7 = (**(code **)(*(long *)param_7[0x4d0] + 0x78))
                            ((long *)param_7[0x4d0],2,0x20000,500), iVar7 != 0)) {
        if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
          if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
             (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
            psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
            auVar3._4_4_ = extraout_var;
            auVar3._0_4_ = extraout_s0;
            auVar3._8_8_ = extraout_var_03;
            thunk_FUN_fffffff00a8df19c
                      (auVar3,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0,
                       (byte *)"%s@%s: %s::%s: failed to open AppleTypeCPhy session\n");
          }
          else {
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(param_7,0);
            thunk_FUN_fffffff00a9029a0
                      ((byte *)"%s@%s: %s::%s: failed to open AppleTypeCPhy session\n");
          }
        }
        iVar7 = (**(code **)(*(long *)param_7[0x4d1] + 0x88))();
        if (iVar7 != 0) {
          (**(code **)(*(long *)param_7[0x4d1] + 0x80))();
        }
        iVar7 = (**(code **)(*(long *)param_7[0x4d0] + 0x88))();
        if (iVar7 != 0) {
          (**(code **)(*(long *)param_7[0x4d0] + 0x80))();
        }
        if ((*(byte *)((long)param_7 + 0x2691) & 1) == 0) {
          *(int *)(param_7 + 0x4df) = (int)DAT_fffffff0078bddc0;
        }
        (**(code **)(*(long *)param_7[0x4d4] + 0xf0))((long *)param_7[0x4d4],0x32);
        (**(code **)(*param_7 + 0x920))(*param_7 + 0x920,param_7);
        (**(code **)(*param_7 + 0x900))(*param_7 + 0x900,param_7);
        return 0xe00002c5;
      }
      thunk_FUN_fffffff00a902988(100);
      (**(code **)(*param_7 + 0x920))(param_7);
      (**(code **)(*param_7 + 0x900))(*param_7 + 0x900,param_7);
    }
    local_38 = &DAT_aaaaaaaaaaaaaaaa;
    thunk_FUN_fffffff00a208ed8(1000,1000000,(long *)&local_38);
    while ((uVar8 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x20),
           (uVar8 >> 0x1e & 1) == 0 &&
           (puVar10 = (undefined1 *)thunk_FUN_fffffff00a39bc88(), puVar10 < local_38))) {
      thunk_FUN_fffffff00a902968(1);
    }
    uVar8 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x20);
    if ((uVar8 >> 0x1e & 1) == 0) {
      if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
         (bVar6 = thunk_FUN_fffffff00a394140(), bVar6)) {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: kT8027USB31DRD_CFG_PHY_STATUS_PIPE_PHY_READY is not set\n");
        uVar13 = extraout_s0_00;
        uVar14 = extraout_var_00;
        uVar9 = extraout_var_04;
      }
      else {
        psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar1._4_4_ = extraout_var_01;
        auVar1._0_4_ = extraout_s0_01;
        auVar1._8_8_ = extraout_var_05;
        thunk_FUN_fffffff00a8df19c
                  (auVar1,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0x11,
                   (byte *)
                   "%s@%s: %s::%s: kT8027USB31DRD_CFG_PHY_STATUS_PIPE_PHY_READY is not set\n");
        uVar13 = extraout_s0_02;
        uVar14 = extraout_var_02;
        uVar9 = extraout_var_06;
      }
      if (*(int *)((long)param_7 + 500) < 0) {
        auVar2._4_4_ = uVar14;
        auVar2._0_4_ = uVar13;
        auVar2._8_8_ = uVar9;
        auVar4._4_12_ = auVar16;
        auVar4._0_4_ = uVar15;
        auVar5._4_12_ = auVar18;
        auVar5._0_4_ = uVar17;
        FUN_fffffff009d14eac(auVar2,param_2,auVar4,auVar5,param_5,param_6);
        plVar11 = thunk_FUN_fffffff00a894f30
                            (*(long **)(extraout_x0 + 0xb8),*(long *)PTR_PTR_fffffff008089ca8);
        iVar7 = (**(code **)(*plVar11 + 0x2d0))(plVar11,extraout_x0);
        if (iVar7 != 0) {
          (**(code **)(**(long **)(extraout_x0 + 0x2680) + 0x80))();
          (**(code **)(**(long **)(extraout_x0 + 0x2688) + 0x80))();
        }
        uVar9 = (*(code *)PTR_FUN_fffffff008087698)(extraout_x0,&PTR_FUN_fffffff008087698);
        return uVar9;
      }
      uVar9 = 0xe00002d6;
    }
    else {
      uVar9 = 0;
    }
  }
  return uVar9;
}

