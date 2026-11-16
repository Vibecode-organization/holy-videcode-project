// FUN_fffffff0081d6780 @ fffffff0081d6780 size=64

bool FUN_fffffff0081d6780(undefined8 param_1,ulong *param_2,uint param_3,ulong param_4)

{
  ulong uVar1;
  
  if (3 < param_3) {
    return false;
  }
  uVar1 = (ulong)((param_3 & 1) << 5);
  *param_2 = ~(0xffffffffL << uVar1);
  param_2[1] = uVar1;
  *(short *)(param_2 + 2) = (short)(param_3 >> 1);
  return param_4 >> 0x20 == 0;
}

