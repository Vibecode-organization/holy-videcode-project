// FUN_fffffff0099437a0 @ fffffff0099437a0 size=68

void FUN_fffffff0099437a0(long param_1)

{
  uint uVar1;
  
  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(*(long *)(param_1 + 0x10) + 0x168);
  uVar1 = *(uint *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x24) = uVar1 - 4;
  LORelease();
  if ((uVar1 & 0xfffffffc) == 4) {
    FUN_fffffff00996097c(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x160));
    return;
  }
  if (3 < uVar1) {
    return;
  }
  FUN_fffffff009983334();
  return;
}

