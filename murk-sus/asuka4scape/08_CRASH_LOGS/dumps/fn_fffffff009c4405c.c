// FUN_fffffff009c4405c @ fffffff009c4405c size=276
// CALLERS:
//   fffffff00afec1d4 no-fn
//   fffffff009c1ef98 FUN_fffffff009c1e624@fffffff009c1e624
// CALLEES:
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c
//   fffffff009c42814 FUN_fffffff009c42814
//   fffffff009c44170 FUN_fffffff009c44170
//   fffffff009c443e0 FUN_fffffff009c443e0

long * FUN_fffffff009c4405c
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
                 ulong param_8,ulong param_9,long param_10,long param_11,int param_12)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar6 [16];
  undefined4 uVar7;
  undefined1 auVar8 [12];
  undefined4 uVar9;
  undefined1 auVar10 [12];
  
  uVar9 = param_4._0_4_;
  auVar10 = param_4._4_12_;
  uVar7 = param_3._0_4_;
  auVar8 = param_3._4_12_;
  plVar3 = (long *)FUN_fffffff009c42814
                             (param_1,param_2,param_3,param_4,param_5,param_6,(long)param_7,param_10
                             );
  if (plVar3 == (long *)0x0) {
    plVar5 = (long *)0x0;
  }
  else {
    uVar4 = FUN_fffffff009c44170
                      (extraout_q0,param_2,uVar7,uVar9,param_5,param_6,(long)plVar3,param_11);
    if ((uVar4 & 1) == 0) {
      thunk_FUN_fffffff00a8df19c
                (extraout_q0_00,param_2,uVar7,uVar9,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"%s pool off limits for poolId 0x%llX\n");
      plVar5 = (long *)0x0;
    }
    else {
      auVar6 = extraout_q0_00;
      if (param_7 != (long *)0x0) {
        auVar6 = (**(code **)(*param_7 + 0x20))(param_7);
      }
      auVar1._4_12_ = auVar8;
      auVar1._0_4_ = uVar7;
      auVar2._4_12_ = auVar10;
      auVar2._0_4_ = uVar9;
      plVar5 = FUN_fffffff009c443e0
                         (auVar6,param_2,auVar1,auVar2,param_5,param_6,(long)plVar3,param_8,param_9,
                          param_10,param_7,param_12);
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return plVar5;
}

