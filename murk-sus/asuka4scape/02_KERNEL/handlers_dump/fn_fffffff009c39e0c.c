// FUN_fffffff009c39e0c @ fffffff009c39e0c size=172 depth=0
// CALLERS:
//   fffffff00afec08d ?
//   fffffff008069338 ?
// CALLS:
//   fffffff009c497d4 thunk_FUN_fffffff00a8d8814
//   fffffff009c3eb68 FUN_fffffff009c3eb68

int FUN_fffffff009c39e0c
              (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
              undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
              undefined8 param_8,long param_9)

{
  int iVar1;
  long *plVar2;
  undefined1 extraout_q0 [16];
  
  iVar1 = -0x1ffffd43;
  if (*(long *)(param_9 + 0x78) == 0) {
    iVar1 = -0x1ffffd3e;
  }
  else {
    plVar2 = thunk_FUN_fffffff00a8d8814(0x100000,0,0);
    if (plVar2 != (long *)0x0) {
      iVar1 = FUN_fffffff009c3eb68
                        (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,
                         **(uint **)(param_9 + 0x20),plVar2);
      if (iVar1 == 0) {
        **(undefined8 **)(param_9 + 0x78) = plVar2;
      }
      else {
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
    }
  }
  return iVar1;
}

