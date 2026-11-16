// FUN_fffffff008203f64 @ fffffff008203f64 size=116

undefined8 FUN_fffffff008203f64(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ca6120 + 0x88))();
  if ((int)uVar1 != 0) {
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(undefined8 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    thunk_EXT_FUN_8011000003a61cc0(param_1 + 0x5e0,0xa00);
    FUN_fffffff008203fd8(param_1);
    *(long *)(*(long *)(param_1 + 0x10) + 0x1ac50) = param_1;
  }
  return uVar1;
}

