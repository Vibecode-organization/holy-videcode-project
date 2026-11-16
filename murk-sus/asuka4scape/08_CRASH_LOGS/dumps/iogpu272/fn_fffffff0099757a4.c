// FUN_fffffff0099757a4 @ fffffff0099757a4 size=288

void FUN_fffffff0099757a4(long param_1)

{
  char *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  undefined8 local_38;
  
  local_38 = 0;
  if (*(long **)(param_1 + 0x140) == (long *)0x0) {
    pcVar1 = "Undefined";
  }
  else {
    pcVar1 = (char *)(**(code **)(**(long **)(param_1 + 0x140) + 0xa8))();
  }
  thunk_EXT_FUN_80110000036dc388(0x850900dc,&local_38,pcVar1);
  uVar2 = thunk_EXT_FUN_801100000390ebc0(param_1);
  thunk_EXT_FUN_80110000036da494(0x850900dc,uVar2,local_38,0,0,0);
  if (DAT_fffffff00af227e8 != 0) {
    lVar3 = *(long *)(param_1 + 0x128);
    lVar4 = *(long *)(param_1 + 0x130);
    uVar2 = thunk_EXT_FUN_801100000390ebc0(param_1);
    thunk_EXT_FUN_80110000036da494(0x85180034,lVar4 + lVar3,uVar2,0,0,0);
  }
  if ((*(byte *)(param_1 + 0x1fd) & 1) == 0) {
    (**(code **)(**(long **)(param_1 + 0xb0) + 0xf8))(*(long **)(param_1 + 0xb0),0,0,0);
  }
  else {
    FUN_fffffff009972e28(param_1);
  }
  return;
}

