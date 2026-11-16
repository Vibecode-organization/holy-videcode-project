// FUN_fffffff0081b89e4 @ fffffff0081b89e4 size=108

bool FUN_fffffff0081b89e4(long param_1,ulong param_2)

{
  if ((param_2 & 0x3f000000000000) == 0x2000000000000) {
    (**(code **)(**(long **)(*(long *)(param_1 + 0x280) + 0x4d0 +
                            (ulong)*(byte *)(*(long *)(param_1 + 0x280) + 0x644) * 8) + 0x118))();
  }
  return (param_2 & 0x3f000000000000) == 0x2000000000000;
}

