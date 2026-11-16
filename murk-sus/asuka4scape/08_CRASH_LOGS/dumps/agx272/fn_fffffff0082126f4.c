// FUN_fffffff0082126f4 @ fffffff0082126f4 size=100

void FUN_fffffff0082126f4(long param_1)

{
  int iVar1;
  undefined4 in_w4;
  undefined8 in_x5;
  
  iVar1 = (**(code **)(PTR_DAT_fffffff007ca6108 + 0x90))();
  if (iVar1 != 0) {
    *(undefined8 *)(param_1 + 0xd8) = 0;
    *(undefined4 *)(param_1 + 0xe8) = in_w4;
    *(undefined8 **)(param_1 + 0xe0) = (undefined8 *)(param_1 + 0xd8);
    *(undefined4 *)(param_1 + 0x210) = 0;
    *(undefined8 *)(param_1 + 0xf8) = 0;
    *(undefined8 *)(param_1 + 0x100) = in_x5;
  }
  return;
}

