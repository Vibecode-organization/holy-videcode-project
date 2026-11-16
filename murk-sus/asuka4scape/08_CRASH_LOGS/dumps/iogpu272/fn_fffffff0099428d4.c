// FUN_fffffff0099428d4 @ fffffff0099428d4 size=156

long FUN_fffffff0099428d4(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  if ((*(byte *)(param_1 + 0xd0) & 1) == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x80);
  }
  if (*(long **)(param_1 + 0xb0) == (long *)0x0) {
    lVar1 = 0;
  }
  else {
    lVar1 = (**(code **)(**(long **)(param_1 + 0xb0) + 0xb0))();
  }
  lVar2 = 0;
  if (*(long **)(param_1 + 0xb8) != (long *)0x0) {
    lVar2 = (**(code **)(**(long **)(param_1 + 0xb8) + 0xb0))();
  }
  return lVar1 + lVar3 + lVar2;
}

