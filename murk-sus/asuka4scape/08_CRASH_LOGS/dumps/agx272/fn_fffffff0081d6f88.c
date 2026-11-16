// FUN_fffffff0081d6f88 @ fffffff0081d6f88 size=100

byte FUN_fffffff0081d6f88(long param_1)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = (**(code **)(**(long **)(*(long *)(param_1 + 0x10) + 0x4b0) + 0x2f0))();
  if (iVar1 == 0) {
    bVar2 = 1;
  }
  else {
    bVar2 = *(byte *)(param_1 + 8);
  }
  return bVar2 & 1;
}

