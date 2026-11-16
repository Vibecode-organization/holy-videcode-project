// FUN_fffffff009c4060c @ fffffff009c4060c size=284

undefined8
FUN_fffffff009c4060c
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4,long *param_5,
          undefined8 *param_6,undefined4 *param_7,long param_8)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 local_60;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar3 = (long *)FUN_fffffff009c3f1d0();
  if (plVar3 == (long *)0x0) {
    uVar4 = 0xe00002c2;
  }
  else {
    lVar1 = 0;
    if (param_4 != 0) {
      lVar1 = param_8;
    }
    local_60 = 0;
    uVar4 = FUN_fffffff009c2a8b4(plVar3,param_3,param_4,&local_60,lVar1);
    iVar2 = (int)uVar4;
    if ((iVar2 == 0) || (iVar2 == -0x1ffffd18)) {
      *param_6 = local_60;
      uVar5 = (undefined4)local_60;
      if (iVar2 != 0 || lVar1 == 0) {
        uVar5 = 0;
      }
      *param_7 = uVar5;
      *param_5 = (long)iVar2;
      uVar4 = 0;
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return uVar4;
  }
  uVar4 = thunk_EXT_FUN_8011000003a48590();
  return uVar4;
}

