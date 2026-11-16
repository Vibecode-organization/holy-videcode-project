// FUN_fffffff00995db74 @ fffffff00995db74 size=96

void FUN_fffffff00995db74(long param_1,undefined4 param_2)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  
  for (uVar5 = *(uint *)(param_1 + 0x48); uVar5 != *(uint *)(param_1 + 0x50); uVar5 = uVar5 + 1) {
    uVar2 = *(uint *)(param_1 + 0x54);
    uVar4 = 0;
    if (uVar2 != 0) {
      uVar4 = uVar5 / uVar2;
    }
    lVar3 = (ulong)(uVar5 - uVar4 * uVar2) * 8;
    plVar1 = (long *)(*(long *)(param_1 + 0x58) + (long)(int)lVar3);
    if (lVar3 != (int)lVar3) {
      plVar1 = (long *)(*(long *)(param_1 + 0x58) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if (*(long *)(*plVar1 + 0x68) != 0) {
      *(undefined4 *)(*(long *)(*plVar1 + 0x68) + 200) = param_2;
    }
  }
  return;
}

