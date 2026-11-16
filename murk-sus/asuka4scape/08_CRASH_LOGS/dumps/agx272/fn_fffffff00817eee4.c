// FUN_fffffff00817eee4 @ fffffff00817eee4 size=1020

void FUN_fffffff00817eee4(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  undefined4 *puVar2;
  int *piVar3;
  float *pfVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  undefined8 *puVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  
  uVar5 = *(uint *)(param_1 + 0x19440);
  uVar8 = (ulong)uVar5;
  if (0x10 < uVar5) {
    thunk_EXT_FUN_8011000003a49114
              (
              "AGXk: %s:%d:%s: !!! Verification failed: %s: max pState greater than num supported.\n"
              );
    return;
  }
  uVar6 = *(uint *)(param_1 + 0x414);
  uVar9 = (ulong)uVar6;
  if (uVar6 == 0) {
    iVar16 = 0;
    iVar17 = 0;
  }
  else {
    lVar13 = param_1 + 0x1a760;
    lVar10 = (ulong)(uVar5 - 1) * 0x40;
    if (uVar6 < 8) {
      uVar12 = 0;
      iVar16 = 0;
LAB_fffffff00817efa4:
      lVar14 = uVar9 - uVar12;
      do {
        lVar1 = lVar10 + uVar12 * 4;
        piVar3 = (int *)(lVar13 + (int)lVar1);
        if (lVar1 != (int)lVar1) {
          piVar3 = (int *)(lVar13 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
        }
        iVar16 = *piVar3 + iVar16;
        uVar12 = uVar12 + 1;
        lVar14 = lVar14 + -1;
      } while (lVar14 != 0);
      if (7 < uVar6) goto LAB_fffffff00817eff0;
      uVar12 = 0;
      iVar17 = 0;
    }
    else {
      lVar14 = 0;
      uVar12 = uVar9 & 0xfffffff8;
      iVar16 = 0;
      iVar17 = 0;
      iVar19 = 0;
      iVar20 = 0;
      iVar21 = 0;
      iVar22 = 0;
      iVar23 = 0;
      iVar24 = 0;
      uVar11 = uVar12;
      do {
        lVar1 = lVar10 + lVar14 * 4;
        puVar15 = (undefined8 *)(lVar13 + (int)lVar1);
        if (lVar1 != (int)lVar1) {
          puVar15 = (undefined8 *)(lVar13 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
        }
        iVar16 = (int)*puVar15 + iVar16;
        iVar17 = (int)((ulong)*puVar15 >> 0x20) + iVar17;
        iVar19 = (int)puVar15[1] + iVar19;
        iVar20 = (int)((ulong)puVar15[1] >> 0x20) + iVar20;
        iVar21 = (int)puVar15[2] + iVar21;
        iVar22 = (int)((ulong)puVar15[2] >> 0x20) + iVar22;
        iVar23 = (int)puVar15[3] + iVar23;
        iVar24 = (int)((ulong)puVar15[3] >> 0x20) + iVar24;
        lVar14 = lVar14 + 8;
        uVar11 = uVar11 - 8;
      } while (uVar11 != 0);
      iVar16 = iVar21 + iVar16 + iVar22 + iVar17 + iVar23 + iVar19 + iVar24 + iVar20;
      if (uVar12 != uVar9) goto LAB_fffffff00817efa4;
LAB_fffffff00817eff0:
      uVar12 = uVar9 & 0xfffffff8;
      lVar10 = 0;
      iVar17 = 0;
      iVar19 = 0;
      iVar20 = 0;
      iVar21 = 0;
      iVar22 = 0;
      iVar23 = 0;
      iVar24 = 0;
      iVar25 = 0;
      uVar11 = uVar12;
      do {
        lVar14 = (param_3 & 0xffffffff) * 0x40 + lVar10 * 4;
        puVar15 = (undefined8 *)(lVar13 + (int)lVar14);
        if (lVar14 != (int)lVar14) {
          puVar15 = (undefined8 *)(lVar13 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
        }
        iVar17 = (int)*puVar15 + iVar17;
        iVar19 = (int)((ulong)*puVar15 >> 0x20) + iVar19;
        iVar20 = (int)puVar15[1] + iVar20;
        iVar21 = (int)((ulong)puVar15[1] >> 0x20) + iVar21;
        iVar22 = (int)puVar15[2] + iVar22;
        iVar23 = (int)((ulong)puVar15[2] >> 0x20) + iVar23;
        iVar24 = (int)puVar15[3] + iVar24;
        iVar25 = (int)((ulong)puVar15[3] >> 0x20) + iVar25;
        lVar10 = lVar10 + 8;
        uVar11 = uVar11 - 8;
      } while (uVar11 != 0);
      iVar17 = iVar22 + iVar17 + iVar23 + iVar19 + iVar24 + iVar20 + iVar25 + iVar21;
      if (uVar12 == uVar9) goto LAB_fffffff00817f07c;
    }
    lVar10 = uVar9 - uVar12;
    do {
      lVar14 = (param_3 & 0xffffffff) * 0x40 + uVar12 * 4;
      piVar3 = (int *)(lVar13 + (int)lVar14);
      if (lVar14 != (int)lVar14) {
        piVar3 = (int *)(lVar13 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      iVar17 = *piVar3 + iVar17;
      uVar12 = uVar12 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
  }
LAB_fffffff00817f07c:
  uVar7 = (uint)param_3;
  if (uVar7 != 0) {
    if (uVar7 < 8) {
      uVar12 = 0;
    }
    else {
      lVar13 = 0;
      uVar12 = param_3 & 0xfffffff8;
      uVar11 = uVar12;
      do {
        puVar15 = (undefined8 *)(param_2 + lVar13 * 4);
        if (((param_2 ^ (ulong)puVar15) & 0xffc0000000000000) != 0) {
          puVar15 = (undefined8 *)((ulong)puVar15 & 0xffffffffffff | 0xc8a2000000000000);
        }
        puVar15[1] = 0;
        *puVar15 = 0;
        puVar15[3] = 0;
        puVar15[2] = 0;
        lVar13 = lVar13 + 8;
        uVar11 = uVar11 - 8;
      } while (uVar11 != 0);
      if (uVar12 == (param_3 & 0xffffffff)) goto LAB_fffffff00817f0fc;
    }
    lVar13 = (param_3 & 0xffffffff) - uVar12;
    do {
      lVar10 = uVar12 * 4;
      puVar2 = (undefined4 *)(param_2 + (long)(int)lVar10);
      if (lVar10 - (int)lVar10 != 0) {
        puVar2 = (undefined4 *)(param_2 + lVar10 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar2 = 0;
      uVar12 = uVar12 + 1;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
  }
LAB_fffffff00817f0fc:
  if (uVar7 < uVar5) {
    if (uVar6 == 0) {
      fVar18 = ((float)(uint)-iVar17 * 100.0) / (float)(uint)(iVar16 - iVar17);
      param_3 = param_3 & 0xffffffff;
      uVar9 = uVar8 - param_3;
      if (7 < uVar9) {
        lVar13 = 0;
        uVar11 = uVar9 & 0xfffffffffffffff8;
        uVar12 = uVar11;
        do {
          lVar10 = (lVar13 + param_3) * 4;
          puVar15 = (undefined8 *)(param_2 + (long)(int)lVar10);
          if (lVar10 - (int)lVar10 != 0) {
            puVar15 = (undefined8 *)(param_2 + lVar10 & 0xffffffffffff | 0x2bad000000000000);
          }
          puVar15[1] = CONCAT44(fVar18,fVar18);
          *puVar15 = CONCAT44(fVar18,fVar18);
          puVar15[3] = CONCAT44(fVar18,fVar18);
          puVar15[2] = CONCAT44(fVar18,fVar18);
          lVar13 = lVar13 + 8;
          uVar12 = uVar12 - 8;
        } while (uVar12 != 0);
        if (uVar9 == uVar11) {
          return;
        }
        param_3 = uVar11 + param_3;
      }
      lVar13 = uVar8 - param_3;
      do {
        lVar10 = param_3 * 4;
        pfVar4 = (float *)(param_2 + (long)(int)lVar10);
        if (lVar10 - (int)lVar10 != 0) {
          pfVar4 = (float *)(param_2 + lVar10 & 0xffffffffffff | 0x2bad000000000000);
        }
        *pfVar4 = fVar18;
        param_3 = param_3 + 1;
        lVar13 = lVar13 + -1;
      } while (lVar13 != 0);
    }
    else {
      param_1 = param_1 + 0x1a760;
      param_3 = param_3 & 0xffffffff;
      uVar12 = uVar9 & 0xfffffff8;
      do {
        if (uVar6 < 8) {
          iVar19 = 0;
          uVar11 = 0;
LAB_fffffff00817f1d4:
          lVar13 = uVar9 - uVar11;
          do {
            lVar10 = param_3 * 0x40 + uVar11 * 4;
            piVar3 = (int *)(param_1 + (int)lVar10);
            if (lVar10 != (int)lVar10) {
              piVar3 = (int *)(param_1 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
            }
            iVar19 = *piVar3 + iVar19;
            uVar11 = uVar11 + 1;
            lVar13 = lVar13 + -1;
          } while (lVar13 != 0);
        }
        else {
          lVar13 = 0;
          iVar19 = 0;
          iVar20 = 0;
          iVar21 = 0;
          iVar22 = 0;
          iVar23 = 0;
          iVar24 = 0;
          iVar25 = 0;
          iVar26 = 0;
          uVar11 = uVar12;
          do {
            lVar10 = param_3 * 0x40 + lVar13 * 4;
            puVar15 = (undefined8 *)(param_1 + (int)lVar10);
            if (lVar10 != (int)lVar10) {
              puVar15 = (undefined8 *)(param_1 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
            }
            iVar19 = (int)*puVar15 + iVar19;
            iVar20 = (int)((ulong)*puVar15 >> 0x20) + iVar20;
            iVar21 = (int)puVar15[1] + iVar21;
            iVar22 = (int)((ulong)puVar15[1] >> 0x20) + iVar22;
            iVar23 = (int)puVar15[2] + iVar23;
            iVar24 = (int)((ulong)puVar15[2] >> 0x20) + iVar24;
            iVar25 = (int)puVar15[3] + iVar25;
            iVar26 = (int)((ulong)puVar15[3] >> 0x20) + iVar26;
            lVar13 = lVar13 + 8;
            uVar11 = uVar11 - 8;
          } while (uVar11 != 0);
          iVar19 = iVar23 + iVar19 + iVar24 + iVar20 + iVar25 + iVar21 + iVar26 + iVar22;
          uVar11 = uVar12;
          if (uVar12 != uVar9) goto LAB_fffffff00817f1d4;
        }
        lVar13 = param_3 * 4;
        pfVar4 = (float *)(param_2 + (long)(int)lVar13);
        if (lVar13 - (int)lVar13 != 0) {
          pfVar4 = (float *)(param_2 + lVar13 & 0xffffffffffff | 0x2bad000000000000);
        }
        *pfVar4 = ((float)(uint)(iVar19 - iVar17) * 100.0) / (float)(uint)(iVar16 - iVar17);
        param_3 = param_3 + 1;
      } while (param_3 != uVar8);
    }
  }
  return;
}

