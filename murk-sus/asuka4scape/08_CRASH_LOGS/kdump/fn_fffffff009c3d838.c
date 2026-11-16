// FUN_fffffff009c3d838 @ fffffff009c3d838 size=208
// CALLERS:
//   fffffff00afec0f3 ?
//   fffffff009c39678 FUN_fffffff009c39660@fffffff009c39660
// CALLS:
//   fffffff009c3f1d0 FUN_fffffff009c3f1d0
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c26438 FUN_fffffff009c26438

undefined4
FUN_fffffff009c3d838
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8,
          undefined8 *param_9,undefined4 *param_10)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long *plVar3;
  ulong local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar2 = 0xe00002c2;
  plVar3 = FUN_fffffff009c3f1d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (plVar3 == (long *)0x0) {
    *param_10 = 0xa0;
  }
  else {
    local_40 = 0x84;
    FUN_fffffff009c26438((long)plVar3,param_9,&local_40);
    uVar1 = 0;
    if (local_40 != 0x84) {
      uVar1 = uVar2;
    }
    *param_10 = 0xa0;
    (**(code **)(*plVar3 + 0x28))(plVar3);
    uVar2 = uVar1;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

