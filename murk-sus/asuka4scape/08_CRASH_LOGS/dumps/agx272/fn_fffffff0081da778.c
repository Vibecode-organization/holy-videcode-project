// FUN_fffffff0081da778 @ fffffff0081da778 size=64

bool FUN_fffffff0081da778(undefined8 param_1,uint *param_2)

{
  if (0x4000 < *param_2) {
    return false;
  }
  if (0x4000 < param_2[1]) {
    return false;
  }
  return param_2[2] - 1 < 7;
}

