// FUN_fffffff0081dc878 @ fffffff0081dc878 size=56

bool FUN_fffffff0081dc878(undefined8 param_1,ulong *param_2,uint param_3,ulong param_4)

{
  if (3 < param_3) {
    return false;
  }
  *param_2 = ~(0xffffL << (((ulong)param_3 & 3) << 4));
  param_2[1] = ((ulong)param_3 & 0xfff) << 4;
  *(undefined2 *)(param_2 + 2) = 0;
  return param_4 < 0x10000;
}

