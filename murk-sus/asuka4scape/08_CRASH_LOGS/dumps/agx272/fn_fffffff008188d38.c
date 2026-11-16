// FUN_fffffff008188d38 @ fffffff008188d38 size=176

undefined8
FUN_fffffff008188d38
          (long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5,
          long *param_6)

{
  (**(code **)(PTR_DAT_fffffff007ca6160 + 0x90))();
  *(undefined8 *)(param_1 + 0x228) = param_5;
  *(long **)(param_1 + 0x230) = param_6;
  if (param_6 != (long *)0x0) {
    (**(code **)(*param_6 + 0x20))(param_6);
  }
  *(undefined8 *)(param_1 + 0x158) = 0;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x170) = 5;
  *(undefined8 *)(param_1 + 0x178) = 0;
  thunk_EXT_FUN_8011000002946f14(param_1 + 0x180);
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  *(undefined8 *)(param_1 + 0x1e8) = *(undefined8 *)(param_3 + 0x548);
  *(undefined8 *)(param_1 + 0x1f0) = 0;
  return 1;
}

