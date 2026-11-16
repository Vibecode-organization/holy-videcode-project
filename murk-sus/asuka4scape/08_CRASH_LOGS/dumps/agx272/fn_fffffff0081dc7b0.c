// FUN_fffffff0081dc7b0 @ fffffff0081dc7b0 size=60

bool FUN_fffffff0081dc7b0(undefined8 param_1,ulong *param_2,uint param_3,ulong param_4)

{
  ulong uVar1;
  
  if (3 < param_3) {
    return false;
  }
  uVar1 = (ulong)((param_3 & 1) << 4);
  *param_2 = ~(0xffffL << uVar1);
  param_2[1] = uVar1;
  *(short *)(param_2 + 2) = (short)(param_3 >> 1);
  return param_4 < 0x10000;
}

