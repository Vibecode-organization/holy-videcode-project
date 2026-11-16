// FUN_fffffff009961d28 @ fffffff009961d28 size=504

void FUN_fffffff009961d28(long param_1)

{
  uint uVar1;
  ulong uVar2;
  uint *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  bool bVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  int iVar14;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  uVar2 = *(ulong *)(param_1 + 0xa8);
  if (DAT_fffffff00af227b8 != 0) {
    uVar2 = (ulong)DAT_fffffff00af227b8 << 0x14;
  }
  lVar9 = *(long *)(param_1 + 0x60);
  if (lVar9 == 0) {
    uVar10 = 0xffffffffffffffff;
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x6c);
    uVar12 = (ulong)uVar5;
    do {
      uVar13 = uVar12 << 4 | 8;
      puVar3 = (uint *)(lVar9 + (int)uVar13);
      if (uVar13 != (long)(int)uVar13) {
        puVar3 = (uint *)(lVar9 + uVar13 & 0xffffffffffff | 0x2bad000000000000);
      }
      uVar13 = uVar12;
    } while (((uint)(*(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x74)) < *puVar3) &&
            (uVar1 = *(int *)(param_1 + 0x68) - 1U & (int)uVar12 - 1U, uVar12 = (ulong)uVar1,
            uVar13 = (ulong)uVar5, uVar1 != uVar5));
    lVar11 = uVar13 * 0x10;
    puVar4 = (undefined8 *)(lVar9 + (int)lVar11);
    if (lVar11 - (int)lVar11 != 0) {
      puVar4 = (undefined8 *)(lVar9 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar10 = *puVar4;
  }
  *(undefined8 *)(param_1 + 0xa0) = uVar10;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  FUN_fffffff00997dff4(&local_58,param_1 + 0x1b8);
  iVar14 = 0;
  bVar6 = false;
  do {
    do {
      bVar8 = bVar6;
      lVar9 = FUN_fffffff00997e0b0(&local_58);
      if (lVar9 == 0) goto LAB_fffffff009961e7c;
      iVar7 = FUN_fffffff009942bf8();
      bVar6 = bVar8;
    } while ((iVar7 != 0) || (bVar6 = true, 0 < *(int *)(lVar9 + 0x18) - *(int *)(param_1 + 0xa0)));
    iVar7 = FUN_fffffff009942c08(lVar9);
    iVar14 = iVar14 + iVar7;
    lVar9 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x1a8),0);
    lVar11 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x1a8),1);
    bVar6 = bVar8;
  } while (uVar2 < (ulong)(lVar11 + lVar9));
LAB_fffffff009961e7c:
  if (((bVar8) &&
      ((*(uint *)(*(long *)(param_1 + 0x1a8) + 0x1fc) & 0x40) == 0 && DAT_fffffff00af227cc == 0)) &&
     (*(int *)(param_1 + 0x94) == 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xc0));
    if (*(int *)(param_1 + 0x88) == 0) {
      local_60 = 0;
      *(undefined4 *)(param_1 + 0x88) = 1;
      thunk_EXT_FUN_8011000003204ed8(*(undefined4 *)(param_1 + 0x90),1000000,&local_60);
      thunk_EXT_FUN_8011000003277924(*(undefined8 *)(param_1 + 0xb8),local_60);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xc0));
  }
  if (iVar14 != 0) {
    *(long *)(param_1 + 0x120) = *(long *)(param_1 + 0x120) + (long)iVar14;
  }
  FUN_fffffff00997e060(&local_58);
  return;
}

