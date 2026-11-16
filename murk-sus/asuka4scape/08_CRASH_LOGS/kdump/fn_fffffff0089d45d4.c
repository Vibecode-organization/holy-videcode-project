// FUN_fffffff0089d45d4 @ fffffff0089d45d4 size=460
// CALLERS:
//   fffffff00afcc9de ?
//   fffffff0089bf398 FUN_fffffff0089bf2c4@fffffff0089bf2c4
// CALLS:
//   fffffff0089c46a4 FUN_fffffff0089c46a4
//   fffffff0089c46cc FUN_fffffff0089c46cc
//   fffffff0089d215c FUN_fffffff0089d215c
//   fffffff008a81ed4 thunk_FUN_fffffff00a8df19c
//   fffffff0089d47a0 FUN_fffffff0089d47a0
//   fffffff0089d201c FUN_fffffff0089d201c
//   fffffff008a81534 thunk_FUN_fffffff00a903214
//   fffffff008a81574 thunk_FUN_fffffff00a9032e0

ulong FUN_fffffff0089d45d4
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                undefined8 *param_8,undefined8 param_9,undefined8 param_10,undefined *param_11)

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
  ulong uVar10;
  int iVar11;
  long *plVar12;
  ulong uVar13;
  undefined8 extraout_d0;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined1 auVar14 [16];
  undefined8 extraout_var_01;
  undefined4 uVar15;
  undefined1 auVar16 [12];
  undefined4 uVar17;
  undefined1 auVar18 [12];
  long local_50;
  long *plStack_48;
  long local_40;
  long *plStack_38;
  
  uVar17 = param_4._0_4_;
  auVar18 = param_4._4_12_;
  uVar15 = param_3._0_4_;
  auVar16 = param_3._4_12_;
  uVar10 = FUN_fffffff0089d201c(param_1,param_2,uVar15,uVar17,param_5,param_6,param_7,(long)param_8)
  ;
  if ((int)uVar10 == 0) {
    plStack_38 = (long *)0x0;
    auVar1._8_8_ = extraout_var;
    auVar1._0_8_ = extraout_d0;
    auVar3._4_12_ = auVar16;
    auVar3._0_4_ = uVar15;
    auVar6._4_12_ = auVar18;
    auVar6._0_4_ = uVar17;
    uVar10 = FUN_fffffff0089d215c
                       (auVar1,param_2,auVar3,auVar6,param_5,param_6,param_7,param_8,&local_40,
                        param_10,param_11);
    if ((int)uVar10 == 0) {
      uVar13 = *(ulong *)(param_7 + 0x20);
      if (uVar13 != 0) {
        thunk_FUN_fffffff00a903214(uVar13);
      }
      plVar12 = plStack_38;
      auVar9._8_8_ = plStack_38;
      auVar9._0_8_ = local_40;
      plStack_48 = plStack_38;
      local_50 = local_40;
      if (plStack_38 == (long *)0x0) {
        auVar4._4_12_ = auVar16;
        auVar4._0_4_ = uVar15;
        auVar7._4_12_ = auVar18;
        auVar7._0_4_ = uVar17;
        uVar10 = FUN_fffffff0089d47a0
                           (auVar9,param_2,auVar4,auVar7,param_5,param_6,param_7,&local_50);
        auVar14._8_8_ = extraout_var_01;
        auVar14._0_8_ = extraout_d0_01;
        iVar11 = (int)uVar10;
      }
      else {
        auVar1 = FUN_fffffff0089c46a4((long)plStack_38);
        auVar5._4_12_ = auVar16;
        auVar5._0_4_ = uVar15;
        auVar8._4_12_ = auVar18;
        auVar8._0_4_ = uVar17;
        uVar10 = FUN_fffffff0089d47a0
                           (auVar1,param_2,auVar5,auVar8,param_5,param_6,param_7,&local_50);
        auVar14 = FUN_fffffff0089c46cc(plVar12);
        iVar11 = (int)uVar10;
      }
      if (iVar11 != 0) {
        thunk_FUN_fffffff00a8df19c
                  (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                   (byte *)"[ERROR] %s: %s: ANE_MemoryUnMapRequest_locked failed. result: 0x%x\n");
      }
      if (uVar13 != 0) {
        thunk_FUN_fffffff00a9032e0(uVar13);
      }
    }
    else {
      auVar2._8_8_ = extraout_var_00;
      auVar2._0_8_ = extraout_d0_00;
      thunk_FUN_fffffff00a8df19c
                (auVar2,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                 (byte *)"[ERROR] %s: %s: createMapRequestFromParams failed. result: 0x%x\n");
      plVar12 = plStack_38;
    }
    if (plVar12 != (long *)0x0) {
      FUN_fffffff0089c46cc(plVar12);
    }
  }
  return uVar10;
}

