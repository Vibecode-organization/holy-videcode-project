// FUN_fffffff0081c24ac @ fffffff0081c24ac size=88

void FUN_fffffff0081c24ac(long param_1,uint param_2,int param_3)

{
  long lVar1;
  
  if (param_3 == 2) {
    lVar1 = *(long *)(param_1 + 0x348);
    param_2 = *(uint *)(lVar1 + 0x9a8) & 0xfffff0ff | param_2 << 8;
  }
  else if (param_3 == 1) {
    lVar1 = *(long *)(param_1 + 0x348);
    param_2 = *(uint *)(lVar1 + 0x9a8) & 0xffffff0f | param_2 << 4;
  }
  else {
    if (param_3 != 0) {
      return;
    }
    lVar1 = *(long *)(param_1 + 0x348);
    param_2 = *(uint *)(lVar1 + 0x9a8) & 0xfffffff0 | param_2;
  }
  *(uint *)(lVar1 + 0x9a8) = param_2;
  return;
}

