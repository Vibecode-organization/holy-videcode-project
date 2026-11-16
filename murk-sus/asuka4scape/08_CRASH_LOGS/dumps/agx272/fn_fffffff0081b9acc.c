// FUN_fffffff0081b9acc @ fffffff0081b9acc size=60

bool FUN_fffffff0081b9acc(long param_1,ulong param_2)

{
  long lVar1;
  
  if ((param_2 & 0xfc) == 0) {
    lVar1 = *(long *)(param_1 + 0x348) + 0x9e7 + (param_2 & 3) * 6;
    *(char *)(lVar1 + 4) = (char)(param_2 >> 0x10);
    *(char *)(lVar1 + 5) = (char)(param_2 >> 8);
  }
  return (param_2 & 0xfc) == 0;
}

