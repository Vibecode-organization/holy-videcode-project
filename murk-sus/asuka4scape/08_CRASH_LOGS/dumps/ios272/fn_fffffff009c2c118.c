// FUN_fffffff009c2c118 @ fffffff009c2c118 size=40

undefined4 FUN_fffffff009c2c118(long param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (1 < param_2) {
    return 0;
  }
  uVar1 = (undefined4)*(undefined8 *)(param_1 + 0x90);
  if (param_2 != 0) {
    uVar1 = (undefined4)((ulong)*(undefined8 *)(param_1 + 0x90) >> 0x20);
  }
  return uVar1;
}

