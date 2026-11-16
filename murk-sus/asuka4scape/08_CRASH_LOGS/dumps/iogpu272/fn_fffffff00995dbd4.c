// FUN_fffffff00995dbd4 @ fffffff00995dbd4 size=156

void FUN_fffffff00995dbd4(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(param_1 + 0x50);
  for (uVar2 = *(uint *)(param_1 + 0x48); uVar2 != uVar6; uVar2 = uVar2 + 1) {
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
    (**(code **)(*(long *)*puVar1 + 0xb0))((long *)*puVar1,param_2);
  }
  return;
}

