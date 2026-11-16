// FUN_fffffff0081b7c6c @ fffffff0081b7c6c size=448

ulong FUN_fffffff0081b7c6c(long param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  
  lVar5 = *(long *)(param_1 + 0x10);
  if (lVar5 == 0) {
    uVar6 = thunk_EXT_FUN_8011000003a49114
                      ("AGXk: %s:%d:%s: !!! Using uninitialized validator class\n");
    return uVar6;
  }
  uVar3 = *(uint *)(param_1 + 0x18);
  if (uVar3 == *(uint *)(param_1 + 0x1c)) {
    uVar6 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Fetching entry from empty ring\n");
    return uVar6;
  }
  uVar6 = *(ulong *)(param_1 + 0x28);
  if (uVar6 <= uVar3) {
    uVar6 = thunk_EXT_FUN_8011000003a49114
                      ("AGXk: %s:%d:%s: !!! Accessing ring index that is out of bounds\n");
    return uVar6;
  }
  lVar7 = (ulong)uVar3 * 0x48;
  puVar2 = (uint *)(lVar5 + (int)lVar7);
  if (lVar7 - (int)lVar7 != 0) {
    puVar2 = (uint *)(lVar5 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar3 = *puVar2;
  *param_2 = uVar3;
  param_2[1] = puVar2[1];
  param_2[2] = puVar2[2];
  param_2[3] = puVar2[3];
  param_2[4] = puVar2[4];
  param_2[5] = puVar2[5];
  param_2[6] = puVar2[6];
  param_2[7] = puVar2[7];
  param_2[8] = puVar2[8];
  param_2[9] = puVar2[9];
  param_2[10] = puVar2[10];
  param_2[0xb] = puVar2[0xb];
  param_2[0xc] = puVar2[0xc];
  param_2[0xd] = puVar2[0xd];
  param_2[0xe] = puVar2[0xe];
  param_2[0xf] = puVar2[0xf];
  param_2[0x10] = puVar2[0x10];
  param_2[0x11] = puVar2[0x11];
  if ((*(ulong *)(param_1 + 0x20) >> ((ulong)uVar3 & 0x3f) & 1) != 0) {
    uVar1 = *(int *)(param_1 + 0x18) + 1;
    iVar4 = 0;
    if (uVar6 != 0) {
      iVar4 = (int)(uVar1 / uVar6);
    }
    *(uint *)(param_1 + 0x18) = uVar1 - iVar4 * (int)uVar6;
    DataMemoryBarrier(2,3);
    **(undefined4 **)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
    return (ulong)uVar3;
  }
  uVar6 = thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Ring is processing event of incorrect type\n");
  return uVar6;
}

