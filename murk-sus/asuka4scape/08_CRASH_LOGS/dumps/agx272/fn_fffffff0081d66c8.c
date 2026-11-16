// FUN_fffffff0081d66c8 @ fffffff0081d66c8 size=60

bool FUN_fffffff0081d66c8(undefined8 param_1,ulong *param_2,uint param_3,ulong param_4)

{
  ulong uVar1;
  
  if (0xf < param_3) {
    return false;
  }
  uVar1 = (ulong)((param_3 & 3) << 4);
  *param_2 = ~(0xffffL << uVar1);
  param_2[1] = uVar1;
  *(short *)(param_2 + 2) = (short)(param_3 >> 2);
  return param_4 < 0x10000;
}

