// FUN_fffffff00996150c @ fffffff00996150c size=72

void FUN_fffffff00996150c(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0x130);
  while (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0x20);
    FUN_fffffff0099611ac(param_1,lVar1,0);
    lVar1 = lVar2;
  }
  return;
}

