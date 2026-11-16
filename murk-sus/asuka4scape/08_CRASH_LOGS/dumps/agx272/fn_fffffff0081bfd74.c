// FUN_fffffff0081bfd74 @ fffffff0081bfd74 size=156

undefined8
FUN_fffffff0081bfd74(long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  long lVar6;
  
  uVar5 = *(uint *)(*(long *)(param_1 + 0x348) + 0x980);
  if (uVar5 < 0x10) {
    lVar1 = *(long *)(param_1 + 0x348) + 0x800;
    lVar6 = (ulong)uVar5 * 0x18;
    lVar2 = lVar6 + 0x10;
    puVar3 = (undefined4 *)(lVar1 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar3 = (undefined4 *)(lVar1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar3 = param_2;
    puVar4 = (undefined8 *)(lVar1 + (int)lVar6);
    if (lVar6 - (int)lVar6 != 0) {
      puVar4 = (undefined8 *)(lVar1 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar4 = param_3;
    lVar6 = lVar6 + 8;
    puVar4 = (undefined8 *)(lVar1 + (int)lVar6);
    if (lVar6 != (int)lVar6) {
      puVar4 = (undefined8 *)(lVar1 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar4 = param_4;
    DataMemoryBarrier(2,3);
    *(int *)(*(long *)(param_1 + 0x348) + 0x980) = *(int *)(*(long *)(param_1 + 0x348) + 0x980) + 1;
    return 0;
  }
  return 0xe00002be;
}

