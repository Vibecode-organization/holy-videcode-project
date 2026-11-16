// FUN_fffffff0081b8a50 @ fffffff0081b8a50 size=28

void FUN_fffffff0081b8a50(long param_1)

{
  *(int *)(*(long *)(param_1 + 0x348) + 0xe40) = *(int *)(*(long *)(param_1 + 0x348) + 0xe40) + 1;
  DataMemoryBarrier(2,3);
  return;
}

