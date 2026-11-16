// FUN_fffffff00995cba8 @ fffffff00995cba8 size=152

void FUN_fffffff00995cba8(long param_1,undefined4 *param_2)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  *param_2 = *(undefined4 *)(param_1 + 0x68);
  uVar2 = *(uint *)(param_1 + 0x4c);
  if (*(uint *)(param_1 + 0x50) == uVar2) {
    uVar7 = 0;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x54);
    uVar5 = 0;
    if (uVar3 != 0) {
      uVar5 = uVar2 / uVar3;
    }
    lVar4 = (ulong)(uVar2 - uVar5 * uVar3) * 8;
    plVar1 = (long *)(*(long *)(param_1 + 0x58) + (long)(int)lVar4);
    if (lVar4 != (int)lVar4) {
      plVar1 = (long *)(*(long *)(param_1 + 0x58) + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
    }
    iVar6 = FUN_fffffff00994cbb8(*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x148),*plVar1 + 0xc0);
    uVar7 = 3;
    if (iVar6 == 0) {
      uVar7 = 1;
    }
  }
  *(undefined4 *)(param_1 + 0x68) = uVar7;
  return;
}

