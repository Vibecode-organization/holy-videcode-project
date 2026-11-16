// FUN_fffffff00995ddac @ fffffff00995ddac size=28

byte FUN_fffffff00995ddac(long param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  if (*(long *)(param_1 + 0x18) != 0) {
    bVar1 = *(byte *)(*(long *)(param_1 + 0x18) + 0x5c8);
  }
  return bVar1 & 1;
}

