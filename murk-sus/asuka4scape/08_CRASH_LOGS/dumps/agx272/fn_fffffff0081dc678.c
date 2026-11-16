// FUN_fffffff0081dc678 @ fffffff0081dc678 size=68

bool FUN_fffffff0081dc678(undefined8 param_1,ulong *param_2,uint param_3,ulong param_4)

{
  ulong uVar1;
  ulong uVar2;
  
  if (0xf < param_3) {
    return false;
  }
  uVar1 = (ulong)((param_3 & 3) << 4);
  uVar2 = 0xfc0L << uVar1;
  *(short *)(param_2 + 2) = (short)(param_3 >> 2);
  uVar1 = uVar1 | 6;
  *param_2 = ~uVar2;
  param_2[1] = uVar1;
  return (param_4 & (uVar2 >> uVar1 ^ 0xffffffffffffffff)) == 0;
}

