// FUN_fffffff00994ea4c @ fffffff00994ea4c size=120

undefined8 FUN_fffffff00994ea4c(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))();
  if ((int)uVar1 != 0) {
    *(undefined8 *)(param_1 + 0x10) = param_2;
    FUN_fffffff00994af14(param_1 + 0x30);
    FUN_fffffff00994af14(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0xc0) = param_3;
    uVar2 = thunk_EXT_FUN_8011000003397c88();
    *(undefined8 *)(param_1 + 0x18) = uVar2;
  }
  return uVar1;
}

