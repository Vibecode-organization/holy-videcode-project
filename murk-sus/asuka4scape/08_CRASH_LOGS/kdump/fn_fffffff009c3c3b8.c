// FUN_fffffff009c3c3b8 @ fffffff009c3c3b8 size=384
// CALLERS:
//   fffffff00afec0cc ?
//   fffffff009c38bf8 FUN_fffffff009c38b2c@fffffff009c38b2c
// CALLS:
//   fffffff009c3f1d0 FUN_fffffff009c3f1d0
//   fffffff009c49764 thunk_FUN_fffffff00a8d8754
//   fffffff009c28220 FUN_fffffff009c28220
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30

undefined4
FUN_fffffff009c3c3b8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint *param_8,
          ulong param_9,int *param_10)

{
  byte bVar1;
  long *plVar2;
  undefined ******ppppppuVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  undefined4 uVar7;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar8 [16];
  undefined4 uVar9;
  undefined4 uVar10;
  
  uVar10 = param_4._0_4_;
  uVar9 = param_3._0_4_;
  uVar7 = 0xe00002c2;
  plVar2 = FUN_fffffff009c3f1d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,*param_8);
  if (plVar2 != (long *)0x0) {
    ppppppuVar3 = thunk_FUN_fffffff00a8d8754
                            ((char *)(param_8 + 3),
                             (long)param_8 + ((param_9 & 0xffffffff) - (long)(param_8 + 3)),
                             (undefined8 *)0x0);
    if (ppppppuVar3 != (undefined ******)0x0) {
      plVar4 = thunk_FUN_fffffff00a894f30((long *)ppppppuVar3,*(long *)PTR_PTR_fffffff00806c9f0);
      if (plVar4 != (long *)0x0) {
        plVar5 = (long *)(**(code **)(*plVar4 + 0x118))(plVar4,0);
        plVar4 = (long *)(**(code **)(*plVar4 + 0x118))(plVar4,1);
        if (plVar4 == (long *)0x0) {
          plVar6 = (long *)0x0;
          auVar8 = extraout_q0;
        }
        else {
          plVar6 = thunk_FUN_fffffff00a894f30(plVar4,*(long *)PTR_PTR_fffffff00806ca10);
          auVar8 = extraout_q0_00;
        }
        if (plVar5 != (long *)0x0 && (plVar4 == (long *)0x0 || plVar6 != (long *)0x0)) {
          bVar1 = FUN_fffffff009c28220
                            (auVar8,param_2,uVar9,uVar10,param_5,param_6,(long)plVar2,plVar6,plVar5,
                             param_10);
          uVar7 = 0;
          if (bVar1 == 0) {
            uVar7 = 0xe00002c9;
          }
        }
      }
      (*(code *)(*ppppppuVar3)[5])(ppppppuVar3);
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar7;
}

