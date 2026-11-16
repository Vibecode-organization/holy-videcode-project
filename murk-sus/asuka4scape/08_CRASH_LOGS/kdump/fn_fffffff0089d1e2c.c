// FUN_fffffff0089d1e2c @ fffffff0089d1e2c size=496
// CALLERS:
//   fffffff00afcc9cc ?
//   fffffff0089bf2bc FUN_fffffff0089bf1d4@fffffff0089bf1d4
// CALLS:
//   fffffff0089c46a4 FUN_fffffff0089c46a4
//   fffffff0089c46cc FUN_fffffff0089c46cc
//   fffffff0089d215c FUN_fffffff0089d215c
//   fffffff008a81ed4 thunk_FUN_fffffff00a8df19c
//   fffffff0089cf69c FUN_fffffff0089cf69c
//   fffffff0089d1d94 FUN_fffffff0089d1d94
//   fffffff0089d201c FUN_fffffff0089d201c
//   fffffff008a81534 thunk_FUN_fffffff00a903214
//   fffffff008a81574 thunk_FUN_fffffff00a9032e0

ulong FUN_fffffff0089d1e2c
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                undefined8 *param_8,undefined1 param_9,char *param_10,undefined *param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  long *plVar7;
  ulong uVar8;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  undefined8 extraout_x1_02;
  undefined8 uVar9;
  ulong *puVar10;
  ulong uVar11;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined1 auVar12 [16];
  undefined8 extraout_d0_01;
  undefined8 extraout_var_01;
  undefined1 auVar13 [16];
  undefined4 uVar14;
  undefined1 auVar15 [12];
  undefined4 uVar16;
  undefined1 auVar17 [12];
  ulong local_80;
  long *plStack_78;
  undefined1 local_70;
  undefined4 local_6c;
  undefined8 *local_68;
  undefined4 local_60;
  undefined8 local_58;
  ulong local_50;
  long *plStack_48;
  
  uVar16 = param_4._0_4_;
  auVar17 = param_4._4_12_;
  uVar14 = param_3._0_4_;
  auVar15 = param_3._4_12_;
  uVar8 = FUN_fffffff0089d201c(param_1,param_2,uVar14,uVar16,param_5,param_6,param_7,(long)param_8);
  if ((int)uVar8 == 0) {
    plStack_48 = (long *)0x0;
    puVar10 = &local_50;
    auVar1._8_8_ = extraout_var;
    auVar1._0_8_ = extraout_d0;
    auVar3._4_12_ = auVar15;
    auVar3._0_4_ = uVar14;
    auVar5._4_12_ = auVar17;
    auVar5._0_4_ = uVar16;
    uVar8 = FUN_fffffff0089d215c
                      (auVar1,param_2,auVar3,auVar5,param_5,param_6,param_7,param_8,(long *)puVar10,
                       param_10,param_11);
    if ((int)uVar8 == 0) {
      local_58 = 0;
      uVar11 = *(ulong *)(param_7 + 0x20);
      if (uVar11 != 0) {
        thunk_FUN_fffffff00a903214(uVar11);
      }
      plVar7 = plStack_48;
      plStack_78 = plStack_48;
      local_80 = local_50;
      auVar12._8_8_ = 0;
      auVar12._0_8_ = local_50;
      if (plStack_48 != (long *)0x0) {
        auVar12 = FUN_fffffff0089c46a4((long)plStack_48);
      }
      local_6c = 2;
      local_68 = &local_58;
      local_60 = *(undefined4 *)(param_8 + 0x104);
      auVar4._4_12_ = auVar15;
      auVar4._0_4_ = uVar14;
      auVar6._4_12_ = auVar17;
      auVar6._0_4_ = uVar16;
      local_70 = param_9;
      uVar8 = FUN_fffffff0089cf69c
                        (auVar12,param_2,auVar4,auVar6,param_5,param_6,param_7,
                         (undefined1 (*) [16])&local_80);
      auVar13._8_8_ = extraout_var_01;
      auVar13._0_8_ = extraout_d0_01;
      uVar9 = extraout_x1;
      if (plVar7 != (long *)0x0) {
        auVar13 = FUN_fffffff0089c46cc(plVar7);
        uVar9 = extraout_x1_00;
      }
      if ((int)uVar8 != 0) {
        param_10 = "[ERROR] %s: %s: ANE_MemoryMapRequest_locked failed. result: 0x%x\n";
        puVar10 = (ulong *)&DAT_00000010;
        auVar13 = thunk_FUN_fffffff00a8df19c
                            (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,
                             (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                             (byte *)
                             "[ERROR] %s: %s: ANE_MemoryMapRequest_locked failed. result: 0x%x\n");
        uVar9 = extraout_x1_01;
      }
      if (uVar11 != 0) {
        auVar13 = thunk_FUN_fffffff00a9032e0(uVar11);
        uVar9 = extraout_x1_02;
      }
      FUN_fffffff0089d1d94
                (auVar13,param_2,uVar14,uVar16,param_5,param_6,&local_58,uVar9,puVar10,param_10,
                 param_11);
    }
    else {
      auVar2._8_8_ = extraout_var_00;
      auVar2._0_8_ = extraout_d0_00;
      thunk_FUN_fffffff00a8df19c
                (auVar2,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                 (byte *)"[ERROR] %s: %s: createMapRequestFromParams failed. result: 0x%x\n");
      plVar7 = plStack_48;
    }
    if (plVar7 != (long *)0x0) {
      FUN_fffffff0089c46cc(plVar7);
    }
  }
  return uVar8;
}

