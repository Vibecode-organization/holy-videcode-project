// FUN_fffffff0081bee10 @ fffffff0081bee10 size=84

undefined4 FUN_fffffff0081bee10(long param_1,int param_2)

{
  undefined4 *puVar1;
  long lVar2;
  
  if ((*(byte *)(param_1 + param_2 + 0x1b56) & 1) == 0) {
    param_1 = *(long *)(param_1 + 0x280) + 0x10f50;
  }
  else {
    param_1 = param_1 + 0x1b49;
  }
  lVar2 = (long)param_2 * 4;
  puVar1 = (undefined4 *)(param_1 + (int)lVar2);
  if (lVar2 - (int)lVar2 != 0) {
    puVar1 = (undefined4 *)(param_1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
  }
  return *puVar1;
}

