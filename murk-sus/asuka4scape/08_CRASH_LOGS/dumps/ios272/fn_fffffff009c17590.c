// FUN_fffffff009c17590 @ fffffff009c17590 size=24

bool FUN_fffffff009c17590(long param_1)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x50) >> 1 & 1) == 0) {
    return false;
  }
  iVar1 = FUN_fffffff009c31488(0x80000);
  return iVar1 == 0;
}

