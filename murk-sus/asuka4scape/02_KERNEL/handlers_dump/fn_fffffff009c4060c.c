// FUN_fffffff009c4060c @ fffffff009c4060c size=284 depth=1
// CALLERS:
//   fffffff00afec138 ?
//   fffffff009c39f24 FUN_fffffff009c39eec
// CALLS:
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c2a8b4 FUN_fffffff009c2a8b4
//   fffffff009c3f1d0 FUN_fffffff009c3f1d0

undefined8
FUN_fffffff009c4060c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8,
          ulong param_9,ulong param_10,long *param_11,ulong *param_12,undefined4 *param_13,
          undefined8 *param_14)

{
  undefined8 *puVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined1 extraout_q0 [16];
  ulong local_60;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar3 = FUN_fffffff009c3f1d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (plVar3 == (long *)0x0) {
    uVar4 = 0xe00002c2;
  }
  else {
    puVar1 = (undefined8 *)0x0;
    if (param_10 != 0) {
      puVar1 = param_14;
    }
    local_60 = 0;
    uVar4 = FUN_fffffff009c2a8b4
                      (extraout_q0,param_2,param_3,param_4,param_5,param_6,(long)plVar3,param_9,
                       param_10,&local_60,puVar1);
    iVar2 = (int)uVar4;
    if ((iVar2 == 0) || (iVar2 == -0x1ffffd18)) {
      *param_12 = local_60;
      uVar5 = (undefined4)local_60;
      if (iVar2 != 0 || puVar1 == (undefined8 *)0x0) {
        uVar5 = 0;
      }
      *param_13 = uVar5;
      *param_11 = (long)iVar2;
      uVar4 = 0;
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

