// FUN_fffffff00996e540 @ fffffff00996e540 size=24

void FUN_fffffff00996e540(long param_1,ulong param_2)

{
  if (0xffff < param_2) {
    param_2 = 0x10000;
  }
  *(int *)(param_1 + 0x120) = (int)param_2;
  return;
}

