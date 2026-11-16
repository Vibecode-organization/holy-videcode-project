// FUN_fffffff00997ad78 @ fffffff00997ad78 size=388

undefined8
FUN_fffffff00997ad78
          (long *param_1,undefined8 param_2,undefined8 param_3,int param_4,undefined8 param_5)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  
  uVar3 = 0xe00002bc;
  iVar1 = FUN_fffffff009975b64(param_1[0xa6],param_1);
  if (iVar1 == 0) {
    uVar3 = 0xe00002d7;
  }
  else {
    thunk_EXT_FUN_80110000032222a8(param_1[0xa5]);
    *(undefined1 *)((long)param_1 + 0x526) = 1;
    thunk_EXT_FUN_8011000003222de0(param_1[0xa5]);
    thunk_EXT_FUN_80110000032222a8(param_1[0x8b]);
    if (((param_1[0x85] != 0) && (param_1[0x91] != 0)) &&
       (FUN_fffffff00997a918(param_1), (int)param_1[0xa4] == 0)) {
      FUN_fffffff0099616bc(*(undefined8 *)(param_1[0xa6] + 0x160),4);
      plVar2 = (long *)FUN_fffffff009965c94(param_1[0x91],param_2);
      if (plVar2 == (long *)0x0) {
        *(undefined4 *)(param_1 + 0xa4) = 10;
      }
      else {
        if (param_4 == 0) {
          FUN_fffffff00997af80(param_1,plVar2,param_3,param_5,param_2);
        }
        else {
          FUN_fffffff00997aefc();
        }
        *(int *)(param_1[0xa6] + 0x2e8) = (int)param_1[0x92];
        (**(code **)(*plVar2 + 0x28))(plVar2);
        uVar3 = 0;
      }
    }
    thunk_EXT_FUN_80110000032222a8(param_1[0xa5]);
    if ((*(byte *)((long)param_1 + 0x525) & 1) != 0) {
      (**(code **)(*param_1 + 0xe0))(param_1);
      *(undefined1 *)((long)param_1 + 0x525) = 0;
    }
    *(undefined1 *)((long)param_1 + 0x526) = 0;
    thunk_EXT_FUN_8011000003222de0(param_1[0xa5]);
    thunk_EXT_FUN_8011000003222de0(param_1[0x8b]);
    FUN_fffffff009975bcc(param_1[0xa6]);
  }
  return uVar3;
}

