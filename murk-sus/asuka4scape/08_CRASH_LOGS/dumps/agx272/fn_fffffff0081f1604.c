// FUN_fffffff0081f1604 @ fffffff0081f1604 size=664

undefined8 FUN_fffffff0081f1604(long param_1,byte *param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  char *pcVar5;
  ulong *puVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  byte bVar15;
  bool bVar16;
  long lVar17;
  long lVar18;
  uint *puVar19;
  long lVar20;
  ulong uVar21;
  ulong uVar22;
  uint uVar23;
  
  if (param_2 == (byte *)0x0) {
    return 0;
  }
  lVar17 = *(long *)(param_1 + 8);
  if (lVar17 == 0) {
    return 0;
  }
  uVar14 = *(uint *)(param_1 + 0x1518);
  if (0xdf < uVar14) {
    return 0;
  }
  bVar15 = *param_2;
  if (*(uint *)(lVar17 + 0x48) < (uint)bVar15) {
    return 0;
  }
  lVar20 = *(long *)(*(long *)(lVar17 + 0x40) + (ulong)(uint)bVar15 * 8);
  uVar21 = (ulong)*(uint *)(param_1 + 0x14) * 0xe0 | 4;
  puVar4 = (uint *)(*(long *)(lVar17 + 0x70) + (long)(int)uVar21);
  if (uVar21 != (long)(int)uVar21) {
    puVar4 = (uint *)(*(long *)(lVar17 + 0x70) + uVar21 & 0xffffffffffff | 0x2bad000000000000);
  }
  if ((*puVar4 & *(uint *)(lVar20 + 0x14)) == 0) {
    return 0;
  }
  uVar21 = *(ulong *)(param_2 + 8);
  iVar13 = *(int *)(lVar20 + 8);
  if ((bVar15 == 1) && ((*(byte *)(param_1 + 0x10) & 1) == 0)) {
    uVar22 = uVar21 >> 0x3c;
    uVar3 = ((uint)uVar21 & 0x7fff) << 3;
    if (uVar22 != 4) {
      uVar3 = (uint)uVar21 & 0xfffff;
    }
    if ((uVar22 != 0) && (uVar22 - 5 < 0xfffffffffffffffe)) {
      return 0;
    }
    uVar23 = *(uint *)(lVar17 + 0x28);
    if (uVar23 == 0) {
      return 0;
    }
    lVar18 = 0;
    uVar22 = 1;
    do {
      puVar19 = (uint *)(*(ulong *)(lVar17 + 0x20) + lVar18 * 8);
      if (((*(ulong *)(lVar17 + 0x20) ^ (ulong)puVar19) & 0xffc0000000000000) != 0) {
        puVar19 = (uint *)((ulong)puVar19 & 0xffffffffffff | 0xc8a2000000000000);
      }
      if (uVar3 < *puVar19) {
        if (uVar23 <= uVar22) {
          return 0;
        }
      }
      else if ((uVar23 <= uVar22) || (uVar3 <= puVar19[1])) goto LAB_fffffff0081f1714;
      lVar18 = lVar18 + 1;
      uVar22 = uVar22 + 1;
    } while( true );
  }
LAB_fffffff0081f171c:
  bVar16 = (*puVar4 & 1) != 0;
  uVar3 = (uint)param_2[2];
  if (bVar16) {
    uVar3 = 0x40;
  }
  uVar23 = (uint)param_2[1];
  if (bVar16) {
    uVar23 = 0x40;
  }
  if ((((0x3f < uVar23 - 1) || ((uVar23 & 0xf) != 0)) || (0x3f < uVar3 - 1)) ||
     (((uVar3 & 0xf) != 0 || (uVar2 = iVar13 + (uVar23 >> 4), *(uint *)(lVar20 + 4) < uVar2)))) {
    return 0;
  }
  if ((uVar14 != 0) && (bVar15 == 0)) {
    lVar17 = (ulong)(uVar14 - 1) * 0x18 + 8;
    pcVar5 = (char *)(param_1 + 0x18 + (long)(int)lVar17);
    if (lVar17 != (int)lVar17) {
      pcVar5 = (char *)(param_1 + 0x18 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if (*pcVar5 != '\0') {
      return 0;
    }
  }
  lVar17 = param_1 + 0x18;
  lVar18 = (ulong)uVar14 * 0x18;
  puVar6 = (ulong *)(lVar17 + (int)lVar18);
  if (lVar18 - (int)lVar18 != 0) {
    puVar6 = (ulong *)(lVar17 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
  }
  lVar1 = lVar18 + 8;
  pbVar7 = (byte *)(lVar17 + (int)lVar1);
  if (lVar1 != (int)lVar1) {
    pbVar7 = (byte *)(lVar17 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  lVar1 = lVar18 + 9;
  puVar8 = (undefined1 *)(lVar17 + (int)lVar1);
  if (lVar1 != (int)lVar1) {
    puVar8 = (undefined1 *)(lVar17 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  lVar1 = lVar18 + 10;
  puVar9 = (undefined1 *)(lVar17 + (int)lVar1);
  if (lVar1 != (int)lVar1) {
    puVar9 = (undefined1 *)(lVar17 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar6 = uVar21;
  lVar1 = lVar18 + 0xb;
  puVar10 = (undefined1 *)(lVar17 + (int)lVar1);
  if (lVar1 != (int)lVar1) {
    puVar10 = (undefined1 *)(lVar17 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *pbVar7 = bVar15;
  lVar1 = lVar18 + 0xc;
  puVar11 = (undefined1 *)(lVar17 + (int)lVar1);
  if (lVar1 != (int)lVar1) {
    puVar11 = (undefined1 *)(lVar17 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar8 = (char)iVar13;
  *puVar9 = (char)uVar23;
  *puVar10 = (char)uVar3;
  *puVar11 = (char)uVar14;
  lVar18 = lVar18 + 0x10;
  puVar12 = (undefined4 *)(lVar17 + (int)lVar18);
  if (lVar18 != (int)lVar18) {
    puVar12 = (undefined4 *)(lVar17 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar12 = *(undefined4 *)(param_2 + 4);
  *(uint *)(param_1 + 0x1518) = uVar14 + 1;
  *(uint *)(lVar20 + 8) = uVar2;
  *(undefined1 *)(param_1 + 0x151c) = 0;
  return 1;
LAB_fffffff0081f1714:
  if (puVar19[1] < uVar3) {
    return 0;
  }
  goto LAB_fffffff0081f171c;
}

