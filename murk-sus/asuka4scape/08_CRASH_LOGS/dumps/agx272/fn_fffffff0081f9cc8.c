// FUN_fffffff0081f9cc8 @ fffffff0081f9cc8 size=104

undefined8 FUN_fffffff0081f9cc8(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ca60f0 + 0x90))();
  thunk_EXT_FUN_8011000002946f14(param_1 + 0x100);
  thunk_EXT_FUN_8011000002946f14(param_1 + 0x140);
  *(undefined8 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  *(undefined2 *)(param_1 + 0xb0) = 0;
  *(undefined2 *)(param_1 + 0xc0) = 0;
  *(undefined1 *)(param_1 + 0xc2) = 0;
  return uVar1;
}

