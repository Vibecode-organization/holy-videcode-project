// FUN_fffffff0081deea0 @ fffffff0081deea0 size=296

void FUN_fffffff0081deea0(long *param_1)

{
  int iVar1;
  long *plVar2;
  undefined8 *puVar3;
  
  param_1[0x359f] = (long)"AGXFirmwareKextG14RTBuddy";
  param_1[0x35a0] = (long)"AGXFirmwareKextRTBuddy - AGXFirmwareKextG14RTBuddy";
  *(undefined4 *)((long)param_1 + 0x10954) = 1;
  *(undefined1 *)((long)param_1 + 0x10959) = 1;
  iVar1 = FUN_fffffff0081a1e64();
  if (iVar1 != 0) {
    plVar2 = (long *)thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca22c8,0x98);
    puVar3 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(plVar2,&DAT_fffffff00ae23608);
    puVar3[7] = 0;
    *(undefined4 *)(puVar3 + 8) = 0;
    *puVar3 = &DAT_fffffff007c9dd00;
    thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23608);
    param_1[0x2236] = (long)plVar2;
    iVar1 = (**(code **)(*plVar2 + 0x78))(plVar2,param_1,&DAT_fffffff00ae20830);
    if (iVar1 != 0) {
      thunk_EXT_FUN_8011000002970c08(param_1);
      (**(code **)(*param_1 + 0x2a0))(param_1,0);
      *(undefined1 *)(param_1 + 0x2238) = 1;
    }
  }
  return;
}

