// FUN_fffffff0081a318c @ fffffff0081a318c size=48

undefined4 FUN_fffffff0081a318c(long param_1,ulong param_2)

{
  long lVar1;
  undefined4 *puVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(param_1 + 0x280) + 0x10f40;
  uVar3 = (param_2 & 0xffffffff) << 2;
  uVar5 = -(param_2 >> 0x1f & 1) & 0xfffffffc00000000 | uVar3;
  iVar4 = (int)uVar3;
  puVar2 = (undefined4 *)(lVar1 + iVar4);
  if (uVar5 != (long)iVar4) {
    puVar2 = (undefined4 *)(lVar1 + uVar5 & 0xffffffffffff | 0x2bad000000000000);
  }
  return *puVar2;
}

