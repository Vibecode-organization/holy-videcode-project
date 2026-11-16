// FUN_fffffff0081b8d90 @ fffffff0081b8d90 size=44

undefined8 FUN_fffffff0081b8d90(long param_1,ulong param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0x348) + 0xa08;
  lVar3 = (param_2 & 0xffffffff) * 8;
  puVar2 = (undefined8 *)(lVar1 + (int)lVar3);
  if (lVar3 != (int)lVar3) {
    puVar2 = (undefined8 *)(lVar1 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
  }
  return *puVar2;
}

