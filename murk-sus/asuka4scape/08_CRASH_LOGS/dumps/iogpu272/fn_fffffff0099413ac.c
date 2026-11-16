// FUN_fffffff0099413ac @ fffffff0099413ac size=48

undefined8 FUN_fffffff0099413ac(long param_1,undefined8 param_2,uint *param_3)

{
  if (*(int *)(param_1 + 0xa4) != 0) {
    if (param_3 != (uint *)0x0) {
      *param_3 = (uint)*(byte *)(param_1 + 0x35);
    }
    return 0xe00002c7;
  }
  return 0xe00002bd;
}

