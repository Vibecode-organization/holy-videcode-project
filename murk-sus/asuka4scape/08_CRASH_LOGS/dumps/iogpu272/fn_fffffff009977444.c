// FUN_fffffff009977444 @ fffffff009977444 size=56

bool FUN_fffffff009977444(long param_1)

{
  if (*(int *)(param_1 + 0x44c) == 2) {
    return true;
  }
  if (*(int *)(param_1 + 0x44c) == 1) {
    return *(int *)(param_1 + 0x450) == 4;
  }
  return false;
}

