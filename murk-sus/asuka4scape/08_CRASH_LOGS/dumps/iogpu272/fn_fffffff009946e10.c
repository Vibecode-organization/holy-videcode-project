// FUN_fffffff009946e10 @ fffffff009946e10 size=164

undefined8
FUN_fffffff009946e10(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar2 = (**(code **)(PTR_DAT_fffffff007ff27d0 + 0xb8))();
  if ((int)uVar2 != 0) {
    lVar3 = thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff0028);
    *(long *)(param_1 + 0xd8) = lVar3;
    uVar2 = 0;
    if (lVar3 != 0) {
      lVar3 = thunk_EXT_FUN_80110000038ff010();
      *(long *)(param_1 + 0xf0) = lVar3;
      uVar2 = 0;
      if (lVar3 != 0) {
        thunk_EXT_FUN_801100000326c6a4(param_3);
        **(undefined8 **)(param_1 + 0xd8) = param_3;
        *(undefined8 *)(param_1 + 0x128) = param_4;
        lVar3 = thunk_EXT_FUN_80110000032970b4(param_3);
        if (lVar3 == 0) {
          uVar1 = 0xffffffff;
        }
        else {
          uVar1 = thunk_EXT_FUN_8011000003720f30();
        }
        *(undefined4 *)(param_1 + 0xe0) = uVar1;
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

