// FUN_fffffff0081e4580 @ fffffff0081e4580 size=928

long FUN_fffffff0081e4580(long param_1,ulong param_2)

{
  ulong uVar1;
  long lVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  ushort uVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  ulong uVar19;
  long lVar20;
  ulong uVar21;
  ulong uVar22;
  int local_70;
  uint uStack_6c;
  int local_68;
  int iStack_64;
  
  bVar3 = *(byte *)(param_1 + 0xd);
  bVar4 = *(byte *)(param_1 + 0xc);
  bVar5 = *(byte *)(param_1 + 0x11);
  bVar6 = *(byte *)(param_1 + 8);
  if (bVar6 == 0) {
    uVar17 = 0;
    uVar8 = *(ushort *)(param_1 + 6);
    lVar20 = -1;
  }
  else {
    lVar20 = 0;
    uVar18 = 0;
    bVar7 = *(byte *)(param_1 + 9);
    uVar8 = *(ushort *)(param_1 + 6);
    do {
      lVar12 = FUN_fffffff0081e4230(param_1,uVar18,&iStack_64,&local_68,&uStack_6c,&local_70);
      uVar13 = (ulong)((uint)uVar8 * (uint)bVar7 * uStack_6c * local_70);
      uVar17 = uVar18;
      if ((ulong)(lVar12 << 2) / 3 <= uVar13) break;
      lVar20 = lVar20 + uVar13;
      uVar18 = uVar18 + 1;
      uVar17 = (uint)bVar6;
    } while (bVar6 != uVar18);
    lVar20 = lVar20 + -1;
  }
  uVar19 = (ulong)uVar8;
  uVar18 = (uint)bVar6;
  lVar12 = FUN_fffffff0081e39cc(param_1,uVar17,uVar18 - uVar17);
  uVar22 = lVar20 + uVar19 + lVar12 & -uVar19;
  uVar13 = 0;
  if (uVar22 != 0) {
    uVar13 = param_2 / uVar22;
  }
  uVar21 = (ulong)*(ushort *)(param_1 + 4);
  uVar1 = uVar13;
  if (uVar21 <= uVar13) {
    uVar1 = uVar21;
  }
  lVar20 = FUN_fffffff0081e39cc(param_1,0,(uint)bVar6);
  if (*(char *)(param_1 + 0x15) == '\0') {
    bVar11 = *(char *)(param_1 + 0x16) != '\0';
  }
  else {
    bVar11 = true;
  }
  uVar14 = (lVar20 + uVar19) - 1 & -uVar19;
  lVar20 = 0x4000;
  if (!(bool)((uVar14 & 0xffffffffffffc000) != 0 & bVar11)) {
    lVar20 = 0x80;
  }
  lVar12 = 0x4000;
  if (!(bool)((uVar14 & 0xffffffffffffc000) != 0 & bVar11)) {
    lVar12 = 0x80;
  }
  if (bVar5 != 4) {
    lVar12 = 0;
  }
  if (bVar5 != 3) {
    lVar20 = lVar12;
  }
  lVar12 = 0x4000;
  if (!(bool)((uVar14 & 0xffffffffffffc000) != 0 & bVar11)) {
    lVar12 = 0x40;
  }
  lVar2 = 0x4000;
  if (!(bool)((uVar14 & 0xffffffffffffc000) != 0 & bVar11)) {
    lVar2 = 0x80;
  }
  if (bVar5 != 2) {
    lVar2 = 0;
  }
  if (bVar5 != 1) {
    lVar12 = lVar2;
  }
  if (bVar5 < 3) {
    lVar20 = lVar12;
  }
  lVar20 = ((uVar14 + lVar20) - 1 & -lVar20) * uVar1;
  param_2 = param_2 - uVar1 * uVar22;
  uVar22 = param_2;
  if (uVar13 < uVar21) {
    uVar22 = 0;
  }
  if (uVar13 < uVar21 && uVar18 != 0) {
    uVar17 = 0;
    bVar6 = *(byte *)(param_1 + 9);
    uVar13 = 0;
    if (uVar19 != 0) {
      uVar13 = param_2 / uVar19;
    }
    do {
      lVar12 = FUN_fffffff0081e4230(param_1,uVar17,&iStack_64,&local_68,&uStack_6c,&local_70);
      uVar22 = (ulong)(local_70 * uStack_6c * (uint)bVar6);
      if (uVar13 < uVar22) {
        uVar17 = 0;
        if (bVar6 != 0) {
          uVar17 = (uint)uVar13 / (uint)bVar6;
        }
        lVar12 = uVar13 - (ulong)uVar17 * (ulong)(uint)bVar6;
        uVar18 = 0;
        if (uStack_6c != 0) {
          uVar18 = uVar17 / uStack_6c;
        }
        uVar17 = uVar17 - uVar18 * uStack_6c;
        if (bVar4 < bVar3 == 2 < bVar5) {
          if (local_68 == 0 && iStack_64 == 0) goto LAB_fffffff0081e48f8;
          uVar22 = 0;
          uVar13 = 0;
          uVar15 = 1;
          do {
            bVar10 = local_68 != 0;
            bVar11 = iStack_64 != 0;
            iVar9 = local_68 + -1;
            uVar16 = (uint)uVar22;
            local_68 = 0;
            if (bVar10) {
              uVar16 = uVar16 + 1;
              uVar13 = (ulong)(uVar15 & uVar18) << (uVar22 & 0x3f) | uVar13;
              local_68 = iVar9;
            }
            uVar22 = (ulong)uVar16;
            iVar9 = iStack_64 + -1;
            iStack_64 = 0;
            if (bVar11) {
              uVar16 = uVar16 + 1;
              uVar13 = (ulong)(uVar15 & uVar17) << (uVar22 & 0x3f) | uVar13;
              iStack_64 = iVar9;
            }
            uVar15 = uVar15 << 1;
            uVar22 = (ulong)(uVar16 - 1);
          } while (iStack_64 != 0 || local_68 != 0);
        }
        else {
          if (local_68 == 0 && iStack_64 == 0) goto LAB_fffffff0081e48f8;
          uVar22 = 0;
          uVar13 = 0;
          uVar15 = 1;
          do {
            bVar10 = iStack_64 != 0;
            bVar11 = local_68 != 0;
            iVar9 = iStack_64 + -1;
            uVar16 = (uint)uVar22;
            iStack_64 = 0;
            if (bVar10) {
              uVar16 = uVar16 + 1;
              uVar13 = (ulong)(uVar15 & uVar17) << (uVar22 & 0x3f) | uVar13;
              iStack_64 = iVar9;
            }
            uVar22 = (ulong)uVar16;
            iVar9 = local_68 + -1;
            local_68 = 0;
            if (bVar11) {
              uVar16 = uVar16 + 1;
              uVar13 = (ulong)(uVar15 & uVar18) << (uVar22 & 0x3f) | uVar13;
              local_68 = iVar9;
            }
            uVar15 = uVar15 << 1;
            uVar22 = (ulong)(uVar16 - 1);
          } while (local_68 != 0 || iStack_64 != 0);
        }
        lVar12 = lVar12 + uVar13 * bVar6;
LAB_fffffff0081e48f8:
        return lVar20 + lVar12 * uVar19;
      }
      lVar20 = lVar12 + lVar20;
      uVar17 = uVar17 + 1;
      uVar13 = uVar13 - uVar22;
    } while (uVar18 != uVar17);
  }
  else {
    lVar20 = lVar20 + uVar22;
  }
  return lVar20;
}

