// FUN_fffffff0081bb618 @ fffffff0081bb618 size=40

bool FUN_fffffff0081bb618(long param_1,uint param_2,uint param_3)

{
  if (param_2 < 0x10) {
    *(uint *)(*(long *)(param_1 + 0x348) + 0xec + (ulong)param_2 * 4) = param_3 & 0xffff;
  }
  return param_2 < 0x10;
}

