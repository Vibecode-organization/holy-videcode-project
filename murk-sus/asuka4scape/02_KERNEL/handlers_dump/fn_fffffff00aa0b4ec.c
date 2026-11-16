// FUN_fffffff00aa0b4ec @ fffffff00aa0b4ec size=504 depth=1
// CALLERS:
//   fffffff00afbfd7c ?
//   fffffff00a9e0254 FUN_fffffff00a9dfff0
// CALLS:
//   fffffff00a9eff54 FUN_fffffff00a9eff54
//   fffffff00a9fa524 FUN_fffffff00a9fa524
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a8df19c FUN_fffffff00a8df19c
//   fffffff00a9fe314 FUN_fffffff00a9fe314
//   fffffff00a9029a0 FUN_fffffff00a9029a0

void FUN_fffffff00aa0b4ec
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               int param_8,uint param_9)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  bool bVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  undefined1 extraout_q0 [16];
  undefined1 auVar9 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined4 uVar10;
  undefined1 auVar11 [12];
  undefined4 uVar12;
  undefined1 auVar13 [12];
  
  uVar12 = param_4._0_4_;
  auVar13 = param_4._4_12_;
  uVar10 = param_3._0_4_;
  auVar11 = param_3._4_12_;
  uVar7 = (**(code **)(*DAT_fffffff00add78a0 + 0x98))();
  if ((uVar7 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00aa0b5f8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_fffffff00add78a0 + 0x100))
              (DAT_fffffff00add78a0,FUN_fffffff00aa0b4ec,param_7,param_8,param_9,0,0,
               (undefined8 *)(*DAT_fffffff00add78a0 + 0x100));
    return;
  }
  uVar1 = *(uint *)((long)param_7 + 0x224);
  uVar8 = uVar1 | param_9;
  if (param_8 == 0) {
    uVar8 = uVar1 & (param_9 ^ 0xffffffff);
  }
  *(uint *)((long)param_7 + 0x224) = uVar8;
  if ((DAT_fffffff00ad1fb18._2_1_ >> 1 & 1) == 0) {
    auVar9 = FUN_fffffff00a8df19c
                       (extraout_q0,param_2,uVar10,uVar12,param_5,param_6,&MACH_HEADER,
                        (short *)&DAT_fffffff00ad98ba0,0,
                        (byte *)"PMRD: setClamShellSleepDisable(%x->%x)\n");
  }
  else {
    FUN_fffffff00a9029a0((byte *)"PMRD: setClamShellSleepDisable(%x->%x)\n");
    auVar9 = extraout_q0_00;
  }
  uVar8 = *(uint *)((long)param_7 + 0x1ec);
  if (((((uVar8 ^ 0xffffffff) & 0x18) == 0) && (uVar1 != 0)) &&
     (*(int *)((long)param_7 + 0x224) == 0)) {
    if (DAT_fffffff00add78a0 != (long *)0x0) {
      iVar6 = (**(code **)(*DAT_fffffff00add78a0 + 0x98))();
      if (iVar6 == 0) {
        auVar9._4_12_ = auVar11;
        auVar9._0_4_ = uVar10;
        auVar3._4_12_ = auVar13;
        auVar3._0_4_ = uVar12;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114
                  (extraout_q0_01,param_2,auVar9,auVar3,param_5,param_6,
                   (byte *)"RootDomain: not inside PM gate @%s:%d");
      }
      uVar8 = *(uint *)((long)param_7 + 0x1ec);
      auVar9 = extraout_q0_01;
    }
    if ((uVar8 >> 4 & 1) != 0) {
      bVar5 = FUN_fffffff00a9fe314(auVar9,param_2,uVar10,uVar12,param_5,param_6,(long)param_7);
      if (bVar5) {
        FUN_fffffff00a9eff54
                  (extraout_q0_02,param_2,uVar10,uVar12,param_5,param_6,(long)param_7,0x65);
        return;
      }
      auVar2._4_12_ = auVar11;
      auVar2._0_4_ = uVar10;
      auVar4._4_12_ = auVar13;
      auVar4._0_4_ = uVar12;
      FUN_fffffff00a9fa524
                (extraout_q0_02,param_2,auVar2,auVar4,param_5,param_6,param_7,8,(undefined **)0x0);
      return;
    }
  }
  return;
}

