// FUN_fffffff008348398 @ fffffff008348398 size=404
// CALLERS:
// CALLEES:
//   fffffff009bf372c FUN_fffffff009bf372c
//   fffffff0083579b4 thunk_FUN_fffffff00aa4c590
//   fffffff0083571e4 thunk_FUN_fffffff00aa16d84
//   fffffff0083577c4 thunk_FUN_fffffff00a8d2200
//   fffffff008357764 thunk_FUN_fffffff00a89a290
//   fffffff0083059c4 FUN_fffffff0083059c4

undefined8 FUN_fffffff008348398(long *param_1,long *param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  bool bVar5;
  long **pplVar6;
  long *local_58;
  long *local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff007ce9d28;
  uVar3 = (**(code **)(PTR_DAT_fffffff007ce9d00 + 0x2c0))();
  if ((int)uVar3 != 0) {
    iVar2 = thunk_FUN_fffffff00aa16d84((undefined4 *)0x0);
    if (iVar2 != 0) {
      local_58 = thunk_FUN_fffffff00a8d2200("VictimUserClient");
      local_50 = thunk_FUN_fffffff00a8d2200("AggressorUserClient");
      plVar4 = thunk_FUN_fffffff00a89a290(&local_58,2,0);
      (**(code **)(*param_1 + 200))(param_1,"IOUserClientClass",plVar4);
      (**(code **)(*plVar4 + 0x28))(plVar4);
      pplVar6 = &local_58;
      bVar1 = true;
      do {
        bVar5 = bVar1;
        (**(code **)(**pplVar6 + 0x28))();
        pplVar6 = &local_50;
        bVar1 = false;
      } while (bVar5);
    }
    FUN_fffffff0083059c4(param_2,param_1);
    (**(code **)(*param_1 + 0x2a0))(param_1,0);
  }
  if (*(long *)PTR_DAT_fffffff007ce9d28 == local_48) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

