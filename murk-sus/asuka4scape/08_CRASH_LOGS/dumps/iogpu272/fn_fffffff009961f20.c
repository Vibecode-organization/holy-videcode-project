// FUN_fffffff009961f20 @ fffffff009961f20 size=192

void FUN_fffffff009961f20(long param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  int *piVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  long local_28;
  
  local_28 = 0;
  thunk_EXT_FUN_8011000003205048(&local_28);
  iVar1 = 0;
  if (*(ulong *)(param_1 + 0x80) != 0) {
    iVar1 = (int)((ulong)(local_28 - *(long *)(param_1 + 0x78)) / *(ulong *)(param_1 + 0x80));
  }
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0x70) + iVar1;
    *(int *)(param_1 + 0x70) = iVar1;
    *(long *)(param_1 + 0x78) = local_28;
    lVar5 = *(long *)(param_1 + 0x60);
    if (lVar5 != 0) {
      uVar2 = *(int *)(param_1 + 0x68) - 1U & *(int *)(param_1 + 0x6c) + 1U;
      *(uint *)(param_1 + 0x6c) = uVar2;
      uVar7 = -(ulong)(uVar2 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar2 << 4;
      iVar6 = (int)((ulong)uVar2 << 4);
      puVar3 = (undefined8 *)(lVar5 + iVar6);
      if (uVar7 != (long)iVar6) {
        puVar3 = (undefined8 *)(lVar5 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar3 = *(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0x168);
      uVar7 = (long)(int)uVar2 << 4 | 8;
      piVar4 = (int *)(lVar5 + (int)uVar7);
      if (uVar7 != (long)(int)uVar7) {
        piVar4 = (int *)(lVar5 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
      }
      *piVar4 = iVar1;
    }
  }
  return;
}

