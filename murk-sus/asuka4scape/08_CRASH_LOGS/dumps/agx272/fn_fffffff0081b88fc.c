// FUN_fffffff0081b88fc @ fffffff0081b88fc size=24

byte FUN_fffffff0081b88fc(long param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  if (*(long *)(param_1 + 0x210) != 0) {
    bVar1 = *(byte *)(*(long *)(param_1 + 0x210) + 9);
  }
  return bVar1 & 1;
}

