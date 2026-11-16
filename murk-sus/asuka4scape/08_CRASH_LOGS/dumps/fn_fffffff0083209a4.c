// FUN_fffffff0083209a4 @ fffffff0083209a4 size=168
// CALLERS:
//   fffffff00afc2eda no-fn
//   fffffff007cd9f60 no-fn
// CALLEES:
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff008357544 thunk_FUN_fffffff00a894f30
//   fffffff0083571e4 thunk_FUN_fffffff00aa16d84
//   fffffff00a91e808 FUN_fffffff00a91e808

undefined4 FUN_fffffff0083209a4(long param_1,long *param_2)

{
  int iVar1;
  long *plVar2;
  char *pcVar3;
  
  iVar1 = thunk_FUN_fffffff00aa16d84((undefined4 *)0x0);
  if (iVar1 != 0) {
    thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::start\n");
    iVar1 = (**(code **)(PTR_DAT_fffffff007ce9cb8 + 0x2c0))(param_1,param_2);
    if (iVar1 == 0) {
      pcVar3 = "AggressorUserClient::start failed to start provider\n";
    }
    else {
      plVar2 = thunk_FUN_fffffff00a894f30(param_2,(long)PTR_DAT_fffffff007ce3900);
      *(long **)(param_1 + 0x108) = plVar2;
      if (plVar2 != (long *)0x0) {
        return 1;
      }
      pcVar3 = "AggressorUserClient::start failed to init _mDriver\n";
    }
    thunk_FUN_fffffff00a9029a0((byte *)pcVar3);
  }
  return 0;
}

