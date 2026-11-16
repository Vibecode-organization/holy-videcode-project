// FUN_fffffff009c3e384 @ fffffff009c3e384 size=492
// CALLERS:
//   fffffff00afec104 no-fn
//   fffffff009c39b60 FUN_fffffff009c39a7c@fffffff009c39a7c
// CALLEES:
//   fffffff009c372dc FUN_fffffff009c372dc
//   fffffff009c43898 FUN_fffffff009c43898
//   fffffff009c49834 thunk_FUN_fffffff00a9a7b30
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c49764 thunk_FUN_fffffff00a8d8754

/* WARNING: Removing unreachable block (ram,0xfffffff009c3e4cc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3e43c) */

undefined8
FUN_fffffff009c3e384
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined4 *param_8,long *param_9,char *param_10,uint param_11)

{
  undefined ******ppppppuVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  undefined1 extraout_q0 [16];
  
  uVar6 = 0xe00002c2;
  ppppppuVar1 = thunk_FUN_fffffff00a8d8754(param_10,(ulong)param_11,(undefined8 *)0x0);
  plVar2 = thunk_FUN_fffffff00a894f30((long *)ppppppuVar1,*(long *)PTR_PTR_fffffff00806c9c8);
  if (plVar2 == (long *)0x0) {
    if (ppppppuVar1 != (undefined ******)0x0) {
      (*(code *)(*ppppppuVar1)[5])(ppppppuVar1);
    }
    plVar3 = FUN_fffffff009c372dc(*(long *)(param_7 + 0xe8));
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
  }
  else {
    plVar3 = FUN_fffffff009c372dc(*(long *)(param_7 + 0xe8));
    if (plVar3 == (long *)0x0) goto LAB_fffffff009c3e534;
    auVar7 = (**(code **)(*plVar2 + 0x20))(plVar2);
    lVar5 = *(long *)(param_7 + 0xf8);
    if (lVar5 == 0) {
      lVar5 = 0;
    }
    plVar4 = FUN_fffffff009c43898
                       (auVar7,param_2,param_3,param_4,param_5,param_6,plVar3,plVar2,lVar5);
    if (plVar4 != (long *)0x0) {
      *param_9 = plVar4[5];
      lVar5 = *(long *)(param_7 + 0xf8);
      if (lVar5 == 0) {
        lVar5 = 0;
      }
      uVar6 = thunk_FUN_fffffff00a9a7b30
                        (extraout_q0,param_2,param_3,param_4,param_5,param_6,lVar5,plVar4,param_8);
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  (**(code **)(*plVar3 + 0x28))(plVar3);
  if (plVar2 == (long *)0x0) {
    return uVar6;
  }
LAB_fffffff009c3e534:
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return uVar6;
}

