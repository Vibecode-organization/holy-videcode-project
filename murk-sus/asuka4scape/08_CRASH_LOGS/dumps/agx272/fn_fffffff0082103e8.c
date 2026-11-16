// FUN_fffffff0082103e8 @ fffffff0082103e8 size=40

void FUN_fffffff0082103e8(long param_1,ulong param_2)

{
  undefined8 *puVar1;
  long lVar2;
  
  lVar2 = (param_2 & 0xffffffff) * 0x40;
  puVar1 = (undefined8 *)(param_1 + 0x30 + (long)(int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar1 = (undefined8 *)(param_1 + 0x30 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
  }
  thunk_EXT_FUN_80110000039788dc(*puVar1);
  return;
}

