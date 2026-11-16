// FUN_fffffff009c33c34 @ fffffff009c33c34 size=400
// CALLERS:
//   fffffff00afebfc0 no-fn
//   fffffff009c33bd4 FUN_fffffff009c33bbc@fffffff009c33bbc
//   fffffff009c3ae24 FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c3bd0c FUN_fffffff009c3bb20@fffffff009c3bb20
//   fffffff009c3c154 FUN_fffffff009c3bf44@fffffff009c3bf44
// CALLEES:
//   fffffff009c1fc5c FUN_fffffff009c1fc5c
//   fffffff009c1a914 FUN_fffffff009c1a914
//   fffffff009c33ed4 FUN_fffffff009c33ed4
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c

long * FUN_fffffff009c33c34
                 (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                 undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                 long param_8,long *param_9,long *param_10)

{
  undefined1 auVar1 [16];
  bool bVar2;
  int iVar3;
  long *plVar4;
  long *plVar5;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar6 [16];
  undefined4 uVar7;
  undefined1 auVar8 [12];
  undefined4 uVar9;
  undefined1 auVar10 [12];
  
  uVar9 = param_4._0_4_;
  auVar10 = param_4._4_12_;
  uVar7 = param_3._0_4_;
  auVar8 = param_3._4_12_;
  if (param_9 == (long *)0x0) {
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,uVar7,uVar9,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,(byte *)"%s error - no properties\n");
    plVar4 = (long *)0x0;
  }
  else {
    plVar4 = (long *)(**(code **)(*(long *)PTR_DAT_fffffff008067118 + 0x68))();
    if (plVar4 == (long *)0x0) {
      thunk_FUN_fffffff00a8df19c
                (extraout_q0,param_2,uVar7,uVar9,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"%s error - failed to alloc surface buffer\n");
    }
    else {
      auVar6._4_12_ = auVar8;
      auVar6._0_4_ = uVar7;
      auVar1._4_12_ = auVar10;
      auVar1._0_4_ = uVar9;
      bVar2 = FUN_fffffff009c1a914
                        (extraout_q0,param_2,auVar6,auVar1,param_5,param_6,plVar4,param_7,param_8,
                         param_9,param_10);
      if (bVar2) {
        plVar5 = (long *)plVar4[6];
        auVar6 = extraout_q0_00;
        if (((plVar5 != (long *)0x0) && ((*(byte *)((long)plVar4 + 0x3d1) >> 3 & 1) != 0)) &&
           (iVar3 = (**(code **)(*plVar5 + 0xd8))(plVar5,0), auVar6 = extraout_q0_01, iVar3 == 0)) {
          auVar6 = (**(code **)(*(long *)plVar4[6] + 0xe0))((long *)plVar4[6],0);
        }
        FUN_fffffff009c1fc5c(auVar6,param_2,uVar7,uVar9,param_5,param_6,(long)plVar4);
      }
      else {
        (**(code **)(*plVar4 + 0x28))(plVar4);
        plVar4 = (long *)0x0;
      }
    }
    FUN_fffffff009c33ed4(param_7);
  }
  return plVar4;
}

