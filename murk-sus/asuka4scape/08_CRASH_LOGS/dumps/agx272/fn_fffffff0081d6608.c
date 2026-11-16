// FUN_fffffff0081d6608 @ fffffff0081d6608 size=64

bool FUN_fffffff0081d6608(undefined8 param_1,ulong *param_2,uint param_3,ulong param_4)

{
  ulong uVar1;
  
  if (0xf < param_3) {
    return false;
  }
  uVar1 = (ulong)((param_3 & 1) << 5);
  *param_2 = ~(0x7ffffffL << uVar1);
  param_2[1] = uVar1;
  *(short *)(param_2 + 2) = (short)(param_3 >> 1);
  return param_4 >> 0x1b == 0;
}

