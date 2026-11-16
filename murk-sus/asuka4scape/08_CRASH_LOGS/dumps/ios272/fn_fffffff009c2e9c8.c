// FUN_fffffff009c2e9c8 @ fffffff009c2e9c8 size=64

undefined4 FUN_fffffff009c2e9c8(long param_1,uint param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  
  if (param_2 < 3) {
    lVar1 = *(long *)(param_1 + 0x10) + 0x30;
    lVar3 = (ulong)param_2 * 0x60;
    puVar2 = (undefined4 *)(lVar1 + (int)lVar3);
    if (lVar3 - (int)lVar3 != 0) {
      puVar2 = (undefined4 *)(lVar1 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
    }
    return *puVar2;
  }
  return 0;
}

