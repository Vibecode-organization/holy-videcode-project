// FUN_fffffff00994965c @ fffffff00994965c size=4

undefined8
FUN_fffffff00994965c(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  ulong uStack_30;
  uint uStack_24;
  
  uStack_24 = 0;
  uVar1 = FUN_fffffff009966668(*(undefined8 *)(param_1 + 0x120),param_2,param_3,&uStack_24);
  if ((int)uVar1 == 0) {
    uStack_30 = (ulong)uStack_24;
    thunk_EXT_FUN_8011000003386690(&uStack_30,param_4,8);
  }
  return uVar1;
}

