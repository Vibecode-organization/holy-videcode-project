// FUN_fffffff009974f6c @ fffffff009974f6c size=40

undefined8 FUN_fffffff009974f6c(long param_1,ulong param_2)

{
  undefined8 *puVar1;
  long lVar2;
  
  lVar2 = (param_2 & 0xffffffff) * 8;
  puVar1 = (undefined8 *)(param_1 + 0x128 + (long)(int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar1 = (undefined8 *)(param_1 + 0x128 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
  }
  return *puVar1;
}

