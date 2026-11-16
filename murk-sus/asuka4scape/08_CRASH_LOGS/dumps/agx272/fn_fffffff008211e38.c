// FUN_fffffff008211e38 @ fffffff008211e38 size=928

void FUN_fffffff008211e38(long param_1,uint param_2,int param_3)

{
  undefined8 *puVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  long *plVar11;
  ulong uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ulong uVar16;
  ulong uVar17;
  long lVar18;
  int iVar19;
  int iVar20;
  ulong uVar21;
  uint uVar22;
  ulong uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  long lVar27;
  undefined4 uVar28;
  
  lVar27 = *(long *)(param_1 + 200);
  if (lVar27 == 0) {
    return;
  }
  plVar11 = *(long **)(param_1 + 0xb8);
  if (plVar11 == (long *)0x0) {
    return;
  }
  if ((*(byte *)(param_1 + 0xd1) & 1) == 0) {
    uVar12 = (**(code **)(*plVar11 + 0xb0))();
    if ((ulong)param_2 < uVar12 >> 4) {
      uVar28 = 0;
      if (param_3 != 0) {
        uVar28 = 0x3f800000;
      }
      lVar27 = (ulong)(param_2 << 2) * 4;
      puVar1 = (undefined8 *)(*(long *)(param_1 + 200) + (long)(int)lVar27);
      if (lVar27 != (int)lVar27) {
        puVar1 = (undefined8 *)
                 (*(long *)(param_1 + 200) + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar1[1] = CONCAT44(uVar28,uVar28);
      *puVar1 = CONCAT44(uVar28,uVar28);
      return;
    }
    return;
  }
  uVar16 = *(ulong *)(param_1 + 0x100);
  uVar12 = 0;
  if (uVar16 != 0) {
    uVar12 = param_2 / uVar16;
  }
  if (*(ushort *)(param_1 + 0xd6) <= uVar12) {
    return;
  }
  param_2 = param_2 - (int)uVar12 * (int)uVar16;
  if (*(uint *)(param_1 + 0x124) < param_2) {
    return;
  }
  bVar5 = *(byte *)(param_1 + 0xda);
  uVar16 = (ulong)bVar5;
  if (bVar5 == 0) {
    uVar17 = 0;
  }
  else {
    uVar24 = **(uint **)(param_1 + 0xf0);
    if (param_2 < uVar24) {
      uVar16 = 0;
      uVar17 = 0;
    }
    else {
      uVar23 = uVar16 - 1;
      uVar21 = 0;
      do {
        uVar16 = (ulong)uVar24;
        uVar17 = (ulong)(bVar5 - 1);
        if (uVar23 == uVar21) break;
        uVar17 = uVar21 + 1;
        uVar24 = (*(uint **)(param_1 + 0xf0))[uVar17];
        uVar21 = uVar17;
      } while (uVar24 <= param_2);
    }
  }
  uVar15 = (uint)uVar17;
  bVar5 = *(byte *)(param_1 + 0xe4);
  uVar24 = 0;
  if (bVar5 != 0) {
    uVar24 = (((uint)bVar5 + (uint)(*(ushort *)(param_1 + 0xd2) >> (ulong)(uVar15 & 0x1f))) - 1) /
             (uint)bVar5;
  }
  bVar5 = *(byte *)(param_1 + 0xe5);
  uVar26 = 0;
  if (bVar5 != 0) {
    uVar26 = (((uint)bVar5 + (uint)(*(ushort *)(param_1 + 0xd4) >> (ulong)(uVar15 & 0x1f))) - 1) /
             (uint)bVar5;
  }
  if (uVar24 < 2) {
    uVar24 = 0;
  }
  else {
    uVar24 = 0x20 - (int)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar24 - 1) & 0x1f)));
  }
  if (uVar26 < 2) {
    uVar26 = 0;
  }
  else {
    uVar26 = 0x20 - (int)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar26 - 1) & 0x1f)));
  }
  uVar13 = (uint)*(byte *)(param_1 + 0xde);
  iVar19 = 0;
  if (uVar13 <= uVar24) {
    iVar19 = uVar24 - uVar13;
  }
  uVar14 = (uint)*(byte *)(param_1 + 0xdf);
  iVar20 = 0;
  if (uVar14 <= uVar26) {
    iVar20 = uVar26 - uVar14;
  }
  uVar15 = *(uint *)(param_1 + 300) >> (ulong)(uVar15 & 0x1f);
  if (uVar15 < 2) {
    uVar15 = 1;
  }
  lVar18 = (uVar17 & 0xffffffff) * 4;
  piVar2 = (int *)(*(long *)(param_1 + 0x108) + (long)(int)lVar18);
  if (lVar18 != (int)lVar18) {
    piVar2 = (int *)(*(long *)(param_1 + 0x108) + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar22 = 0;
  if (iVar20 != 0 || iVar19 != 0) {
    uVar25 = 0;
    uVar22 = 0;
    uVar7 = param_2 - (int)uVar16;
    uVar4 = *(uint *)(param_1 + 0x130);
    uVar8 = 0;
    if (uVar4 != 0) {
      uVar8 = ((uVar4 + uVar15) - 1) / uVar4;
    }
    uVar15 = 0;
    if (uVar8 != 0) {
      uVar15 = uVar7 / uVar8;
    }
    bVar10 = uVar14 <= uVar26 && uVar26 != *(byte *)(param_1 + 0xdf);
    bVar9 = uVar13 <= uVar24 && uVar24 != *(byte *)(param_1 + 0xde);
    uVar24 = 1;
    do {
      uVar26 = uVar25 & 0x1f;
      iVar6 = iVar19 + -1;
      iVar19 = 0;
      if (bVar9) {
        uVar25 = uVar25 + 1;
        uVar22 = (uVar24 & uVar7 - uVar15 * uVar8) << (ulong)uVar26 | uVar22;
        iVar19 = iVar6;
      }
      uVar26 = uVar25 & 0x1f;
      iVar6 = iVar20 + -1;
      iVar20 = 0;
      if (bVar10) {
        uVar25 = uVar25 + 1;
        uVar22 = (uVar24 & uVar15) << (ulong)uVar26 | uVar22;
        iVar20 = iVar6;
      }
      uVar24 = uVar24 << 1;
      uVar25 = uVar25 - 1;
      bVar9 = iVar19 != 0;
      bVar10 = iVar20 != 0;
    } while (iVar19 != 0 || iVar20 != 0);
  }
  uVar22 = *piVar2 + *(int *)(param_1 + 0x110) * (int)uVar12 + uVar22;
  uVar24 = 0;
  if (param_3 != 0) {
    uVar24 = (uint)(*(ulong *)(param_1 + 0x118) >> 0xe) | 0x80000000;
  }
  uVar12 = (**(code **)(*plVar11 + 0xb0))();
  uVar15 = (uint)(uVar12 >> 2) & 0x3fffffff;
  uVar17 = (ulong)uVar22 & 0xff;
  uVar12 = (ulong)(uVar22 >> 8) << 9;
  uVar16 = uVar17 | uVar12;
  if ((uint)uVar16 < uVar15) {
    lVar18 = (uVar17 | uVar12 & 0xfffffe00) * 4;
    puVar3 = (uint *)(lVar27 + (int)lVar18);
    if (lVar18 - (int)lVar18 != 0) {
      puVar3 = (uint *)(lVar27 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar3 = uVar24;
  }
  if ((*(uint *)(param_1 + 0x124) == param_2) &&
     (uVar12 = (ulong)*(uint *)(param_1 + 0x128), 1 < *(uint *)(param_1 + 0x128))) {
    uVar17 = 1;
    do {
      uVar21 = uVar17 + uVar16;
      uVar23 = uVar21 & 0xff;
      uVar21 = (uVar21 >> 8) << 9;
      if (((uint)uVar23 | (uint)uVar21) < uVar15) {
        lVar18 = (uVar23 | uVar21 & 0xfffffe00) * 4;
        puVar3 = (uint *)(lVar27 + (int)lVar18);
        if (lVar18 - (int)lVar18 != 0) {
          puVar3 = (uint *)(lVar27 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar3 = uVar24;
        uVar12 = (ulong)*(uint *)(param_1 + 0x128);
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 < uVar12);
  }
  return;
}

