// FUN_fffffff0081ac138 @ fffffff0081ac138 size=52

void FUN_fffffff0081ac138(long param_1,uint param_2)

{
  long lVar1;
  undefined1 *puVar2;
  
  lVar1 = (ulong)param_2 * 0x130 + 0x128;
  puVar2 = (undefined1 *)(param_1 + 0x7e0 + (long)(int)lVar1);
  if (lVar1 != (int)lVar1) {
    puVar2 = (undefined1 *)(param_1 + 0x7e0 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar2 = 1;
  return;
}

