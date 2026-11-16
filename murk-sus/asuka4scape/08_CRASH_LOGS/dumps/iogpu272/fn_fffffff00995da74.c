// FUN_fffffff00995da74 @ fffffff00995da74 size=88

undefined8 FUN_fffffff00995da74(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  
  if (*(uint *)(param_1 + 0x48) == *(uint *)(param_1 + 0x4c)) {
    return 0;
  }
  uVar2 = *(uint *)(param_1 + 0x48);
  uVar3 = *(uint *)(param_1 + 0x54);
  uVar5 = 0;
  if (uVar3 != 0) {
    uVar5 = uVar2 / uVar3;
  }
  lVar4 = (ulong)(uVar2 - uVar5 * uVar3) * 8;
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0x58) + (long)(int)lVar4);
  if (lVar4 != (int)lVar4) {
    puVar1 = (undefined8 *)
             (*(long *)(param_1 + 0x58) + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  return *puVar1;
}

