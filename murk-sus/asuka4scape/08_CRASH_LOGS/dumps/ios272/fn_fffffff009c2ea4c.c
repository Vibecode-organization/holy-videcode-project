// FUN_fffffff009c2ea4c @ fffffff009c2ea4c size=68

undefined4 FUN_fffffff009c2ea4c(long param_1,uint param_2)

{
  long lVar1;
  undefined4 *puVar2;
  ulong uVar3;
  
  if (param_2 < 3) {
    lVar1 = *(long *)(param_1 + 0x10) + 0x30;
    uVar3 = (ulong)(param_2 * 0x60) | 8;
    puVar2 = (undefined4 *)(lVar1 + (int)uVar3);
    if (uVar3 != (long)(int)uVar3) {
      puVar2 = (undefined4 *)(lVar1 + uVar3 & 0xffffffffffff | 0x2bad000000000000);
    }
    return *puVar2;
  }
  return 0;
}

