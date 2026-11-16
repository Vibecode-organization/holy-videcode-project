// FUN_fffffff008188cc8 @ fffffff008188cc8 size=112

void FUN_fffffff008188cc8(long param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = (ulong)*(uint *)(param_2 + 0x28) * 8;
  iVar3 = (int)lVar4;
  puVar2 = (undefined8 *)(param_2 + 0x3a0 + (long)iVar3);
  if (lVar4 - iVar3 != 0) {
    puVar2 = (undefined8 *)(param_2 + 0x3a0 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  puVar1 = (undefined8 *)(param_2 + 0x38 + (long)iVar3);
  if (lVar4 - iVar3 != 0) {
    puVar1 = (undefined8 *)(param_2 + 0x38 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *(undefined8 *)(param_1 + 0x200) = *puVar2;
  *(undefined8 *)(param_1 + 0x210) = *puVar1;
  puVar2 = (undefined8 *)(param_2 + 0x280 + (long)iVar3);
  if (lVar4 - iVar3 != 0) {
    puVar2 = (undefined8 *)(param_2 + 0x280 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *(undefined8 *)(param_1 + 0x208) = *puVar2;
  return;
}

