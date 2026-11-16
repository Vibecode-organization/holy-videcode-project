// FUN_fffffff0089d1978 @ fffffff0089d1978 size=892
// CALLERS:
//   fffffff00afcc9c7 no-fn
//   fffffff0089ce208 FUN_fffffff0089cdb18@fffffff0089cdb18
// CALLEES:
//   fffffff0089c46cc FUN_fffffff0089c46cc
//   fffffff0089e9820 FUN_fffffff0089e9820
//   fffffff008933d44 FUN_fffffff008933d44
//   fffffff008a81ed4 thunk_FUN_fffffff00a8df19c
//   fffffff008a82064 thunk_FUN_fffffff00a6de494
//   fffffff008a81fc4 thunk_FUN_fffffff00a2600a0
//   fffffff008a817c4 thunk_FUN_fffffff009c33890
//   fffffff0089c46a4 FUN_fffffff0089c46a4

ulong FUN_fffffff0089d1978
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                long param_8,undefined8 *param_9,long *param_10,undefined *param_11)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  bool bVar9;
  long lVar10;
  long *plVar11;
  ulong uVar12;
  uint *puVar13;
  long *plVar14;
  long lVar15;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined1 auVar16 [16];
  undefined8 extraout_d0_01;
  undefined8 extraout_var_01;
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined8 extraout_d0_02;
  undefined8 extraout_var_02;
  undefined1 auVar19 [16];
  undefined4 uVar20;
  undefined1 auVar21 [12];
  undefined4 uVar22;
  undefined1 auVar23 [12];
  ulong local_120;
  long *plStack_118;
  uint local_110 [2];
  undefined8 local_108;
  long *local_100;
  undefined4 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined1 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined1 local_ac;
  undefined4 local_a8;
  undefined1 local_a4;
  undefined8 local_a0;
  undefined1 local_98;
  undefined4 local_94;
  undefined2 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined4 local_80;
  long local_78;
  long *local_70;
  long *local_68;
  ulong local_60;
  long *plStack_58;
  
  lVar15 = DAT_fffffff00ae43158;
  uVar22 = param_4._0_4_;
  auVar23 = param_4._4_12_;
  uVar20 = param_3._0_4_;
  auVar21 = param_3._4_12_;
  uVar1 = *(uint *)(param_9 + 0x105);
  if (uVar1 != 0) {
    plVar14 = param_10;
    lVar10 = thunk_FUN_fffffff00a2600a0();
    auVar16._8_8_ = extraout_var;
    auVar16._0_8_ = extraout_d0;
    auVar3._4_12_ = auVar21;
    auVar3._0_4_ = uVar20;
    auVar6._4_12_ = auVar23;
    auVar6._0_4_ = uVar22;
    plVar11 = (long *)thunk_FUN_fffffff009c33890
                                (auVar16,param_2,auVar3,auVar6,param_5,param_6,lVar15,(ulong)uVar1,
                                 lVar10);
    if (plVar11 == (long *)0x0) {
      auVar2._8_8_ = extraout_var_00;
      auVar2._0_8_ = extraout_d0_00;
      thunk_FUN_fffffff00a8df19c
                (auVar2,param_2,uVar20,uVar22,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                 (byte *)"[ERROR] %s: %s: Statsbuffer IOSurface lookup failed. SurfaceID: %u\n");
      return 0xe00002c2;
    }
    auVar16 = ZEXT816(0);
    plStack_58 = (long *)0x0;
    local_60 = 0;
    lVar15 = *(long *)(param_7 + 0x10);
    uStack_e8 = 0;
    local_f0 = 0;
    uStack_d8 = 0;
    uStack_e0 = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    local_c0 = 0;
    local_bc = 0;
    local_b8 = 0;
    local_b0 = 10;
    local_ac = 0;
    local_a8 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_98 = 0;
    local_78 = *param_10;
    local_70 = (long *)param_10[1];
    local_94 = *(undefined4 *)(local_78 + 0x280);
    local_90 = 0;
    local_8c = 10000;
    local_88 = *param_9;
    local_80 = 0xff;
    if (local_70 != (long *)0x0) {
      auVar16 = FUN_fffffff0089c46a4((long)local_70);
    }
    local_110[0] = 0;
    local_108 = 0;
    local_100 = (long *)0x0;
    local_f8 = 5;
    puVar13 = local_110;
    auVar4._4_12_ = auVar21;
    auVar4._0_4_ = uVar20;
    auVar7._4_12_ = auVar23;
    auVar7._0_4_ = uVar22;
    local_68 = plVar11;
    FUN_fffffff008933d44
              (&local_60,auVar16,param_2,auVar4,auVar7,param_5,param_6,lVar15,&local_f0,puVar13,
               (char *)plVar14,param_11);
    auVar17._8_8_ = extraout_var_01;
    auVar17._0_8_ = extraout_d0_01;
    if (local_100 != (long *)0x0) {
      auVar17 = FUN_fffffff0089c46cc(local_100);
    }
    if (local_70 != (long *)0x0) {
      auVar17 = FUN_fffffff0089c46cc(local_70);
    }
    if (local_60 == 0) {
      thunk_FUN_fffffff00a8df19c
                (auVar17,param_2,uVar20,uVar22,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                 (byte *)"[ERROR] %s: %s: aneClientResource allocation failed for statsbuffer\n");
      bVar9 = false;
      uVar12 = 0xe00002bd;
    }
    else {
      (**(code **)(*plVar11 + 0x28))(plVar11);
      *(undefined1 *)(param_8 + 0x4209) = 1;
      plStack_118 = plStack_58;
      local_120 = local_60;
      auVar18._8_8_ = 0;
      auVar18._0_8_ = local_60;
      if (plStack_58 != (long *)0x0) {
        auVar18 = FUN_fffffff0089c46a4((long)plStack_58);
      }
      auVar5._4_12_ = auVar21;
      auVar5._0_4_ = uVar20;
      auVar8._4_12_ = auVar23;
      auVar8._0_4_ = uVar22;
      uVar12 = FUN_fffffff0089e9820
                         (auVar18,param_2,auVar5,auVar8,param_5,param_6,param_8,(long *)&local_120,
                          puVar13,plVar14,param_11);
      auVar19._8_8_ = extraout_var_02;
      auVar19._0_8_ = extraout_d0_02;
      if (plStack_118 != (long *)0x0) {
        auVar19 = FUN_fffffff0089c46cc(plStack_118);
      }
      if ((uVar12 & 1) == 0) {
        uVar12 = 0xe00002e2;
        if ((DAT_fffffff00ae430b1 >> 2 & 1) == 0) {
          bVar9 = false;
        }
        else {
          thunk_FUN_fffffff00a8df19c
                    (auVar19,param_2,uVar20,uVar22,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff007ddeaa8,0,
                     (byte *)"%s: %s: Failed to add statistics buffer resource to request!\n");
          bVar9 = false;
        }
      }
      else {
        thunk_FUN_fffffff00a6de494
                  (auVar19,param_2,uVar20,uVar22,param_5,param_6,0x61b0058,0x19,0,0,0);
        bVar9 = true;
      }
    }
    if (plStack_58 != (long *)0x0) {
      FUN_fffffff0089c46cc(plStack_58);
    }
    if (!bVar9) {
      return uVar12;
    }
  }
  return 0;
}

