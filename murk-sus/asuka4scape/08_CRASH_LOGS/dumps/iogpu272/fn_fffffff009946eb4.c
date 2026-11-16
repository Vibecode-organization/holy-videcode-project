// FUN_fffffff009946eb4 @ fffffff009946eb4 size=144

void FUN_fffffff009946eb4(long *param_1,undefined8 param_2)

{
  undefined1 uVar1;
  int iVar2;
  long lVar3;
  
  iVar2 = (**(code **)(PTR_DAT_fffffff007ff27d0 + 0x2c0))();
  if (iVar2 != 0) {
    lVar3 = thunk_EXT_FUN_8011000003890f30(param_2,DAT_fffffff007fee6a0);
    param_1[0x1f] = lVar3;
    if (lVar3 != 0) {
      uVar1 = (**(code **)(*param_1 + 0x5d0))(param_1);
      *(undefined1 *)(param_1 + 0x20) = uVar1;
    }
  }
  return;
}

