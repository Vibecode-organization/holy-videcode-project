// FUN_fffffff0081bed88 @ fffffff0081bed88 size=52

byte FUN_fffffff0081bed88(long param_1)

{
  if ((*(byte *)(param_1 + 7000) & 1) != 0) {
    return *(byte *)(param_1 + 0x1b51) & 1;
  }
  return *(byte *)(*(long *)(param_1 + 0x280) + 0x10f3c) & 1;
}

