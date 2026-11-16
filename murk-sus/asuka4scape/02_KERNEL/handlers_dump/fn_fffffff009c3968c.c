// FUN_fffffff009c3968c @ fffffff009c3968c size=188 depth=0
// CALLERS:
//   fffffff00afec075 ?
//   fffffff008069040 ?
// CALLS:
//   fffffff009c497d4 thunk_FUN_fffffff00a8d8814
//   fffffff009c40430 FUN_fffffff009c40430

int FUN_fffffff009c3968c
              (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
              undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
              undefined8 param_8,long param_9)

{
  int iVar1;
  long *plVar2;
  undefined1 extraout_q0 [16];
  
  iVar1 = -0x1ffffd43;
  if ((*(byte *)(param_7 + 0x122) & 1) == 0) {
    iVar1 = -0x1ffffd3f;
  }
  else if (*(long *)(param_9 + 0x78) == 0) {
    iVar1 = -0x1ffffd3e;
  }
  else {
    plVar2 = thunk_FUN_fffffff00a8d8814(0x100000,0,0);
    if (plVar2 != (long *)0x0) {
      iVar1 = FUN_fffffff009c40430
                        (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,
                         **(long **)(param_9 + 0x20),plVar2);
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

