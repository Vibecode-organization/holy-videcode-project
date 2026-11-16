// FUN_fffffff0081d18b4 @ fffffff0081d18b4 size=36

bool FUN_fffffff0081d18b4(long param_1)

{
  if (*(long *)(param_1 + 0x2a0) != 0) {
    return *(int *)(*(long *)(param_1 + 0x2a0) + 0xffc) != 0;
  }
  return false;
}

