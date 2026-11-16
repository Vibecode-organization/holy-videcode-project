// FUN_fffffff00995d1bc @ fffffff00995d1bc size=60

undefined8 FUN_fffffff00995d1bc(long param_1)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(param_1 + 0x54);
  uVar4 = 0;
  if (uVar2 != 0) {
    uVar4 = *(uint *)(param_1 + 0x4c) / uVar2;
  }
  lVar3 = (ulong)(*(uint *)(param_1 + 0x4c) - uVar4 * uVar2) * 8;
  plVar1 = (long *)(*(long *)(param_1 + 0x58) + (long)(int)lVar3);
  if (lVar3 != (int)lVar3) {
    plVar1 = (long *)(*(long *)(param_1 + 0x58) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
  }
  return *(undefined8 *)(*plVar1 + 0x130);
}

