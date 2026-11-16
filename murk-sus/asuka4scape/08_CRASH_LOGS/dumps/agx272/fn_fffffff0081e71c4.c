// FUN_fffffff0081e71c4 @ fffffff0081e71c4 size=1320

undefined8 FUN_fffffff0081e71c4(long param_1,uint param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong *puVar14;
  int iVar15;
  ulong uVar16;
  undefined8 *puVar17;
  long lVar18;
  long lVar19;
  ulong uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  
  uVar5 = *(int *)(param_1 + 0x48) * param_2;
  uVar1 = uVar5 + 0x3f;
  uVar20 = *(ulong *)(param_1 + 0x80);
  if (param_2 == 0) {
    if (*(long *)(param_1 + 0x88) != 0) {
      *(undefined8 *)(param_1 + 0x88) = 0;
    }
    uVar11 = uVar20 << 3;
    if (0x7fffffffffffffff < uVar11) {
      uVar11 = 0x8000000000000000;
    }
    if (uVar20 >> 0x3d != 0) {
      uVar11 = 0x8000000000000000;
    }
    uVar10 = *(undefined8 *)(param_1 + 0x78);
    *(undefined8 *)(param_1 + 0x78) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4558,uVar10,uVar11);
    lVar8 = 0;
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x90) = 0;
    uVar20 = *(ulong *)(param_1 + 0x98);
    goto LAB_fffffff0081e762c;
  }
  if ((0x1000 < (uVar1 & 0xffffffc0)) && (*(int *)(param_1 + 0xa4) == 0x1000)) {
    return 0;
  }
  uVar4 = uVar1 >> 6;
  lVar8 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca45a8,uVar4 << 3);
  if (lVar8 == 0) {
    return 0;
  }
  uVar6 = param_2 - (uint)uVar20;
  if (param_2 < (uint)uVar20 || uVar6 == 0) {
    uVar11 = (ulong)param_2;
    uVar20 = *(ulong *)(param_1 + 0x88);
    if (uVar11 < uVar20) {
      *(ulong *)(param_1 + 0x88) = uVar11;
      uVar20 = uVar11;
    }
    else if (uVar20 == 0) {
      lVar9 = 0;
      goto LAB_fffffff0081e74a4;
    }
    lVar9 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4508,uVar20 << 3);
    if (lVar9 == 0) {
LAB_fffffff0081e76d0:
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca45f8,lVar8,uVar4 << 3);
      return 0;
    }
    uVar11 = *(ulong *)(param_1 + 0x88);
    if (uVar11 != 0) {
      uVar13 = 0;
      uVar12 = *(ulong *)(param_1 + 0x78);
      if ((3 < uVar11) && (0x1f < lVar9 - uVar12)) {
        lVar18 = 0;
        uVar13 = uVar11 & 0xfffffffffffffffc;
        uVar16 = uVar13;
        do {
          puVar17 = (undefined8 *)(uVar12 + lVar18 * 8);
          if (((uVar12 ^ (ulong)puVar17) & 0xffc0000000000000) != 0) {
            puVar17 = (undefined8 *)((ulong)puVar17 & 0xffffffffffff | 0xc8a2000000000000);
          }
          lVar19 = lVar18 * 8;
          puVar2 = (undefined8 *)(lVar9 + (int)lVar19);
          if (lVar19 - (int)lVar19 != 0) {
            puVar2 = (undefined8 *)(lVar9 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar10 = *puVar17;
          uVar22 = puVar17[3];
          uVar21 = puVar17[2];
          puVar2[1] = puVar17[1];
          *puVar2 = uVar10;
          puVar2[3] = uVar22;
          puVar2[2] = uVar21;
          lVar18 = lVar18 + 4;
          uVar16 = uVar16 - 4;
        } while (uVar16 != 0);
        if (uVar11 == uVar13) goto LAB_fffffff0081e74a4;
      }
      lVar18 = uVar11 - uVar13;
      do {
        lVar19 = uVar13 * 8;
        iVar15 = (int)lVar19;
        puVar17 = (undefined8 *)(uVar12 + (long)iVar15);
        if (lVar19 - iVar15 != 0) {
          puVar17 = (undefined8 *)(uVar12 + lVar19 & 0xffffffffffff | 0x2bad000000000000);
        }
        puVar2 = (undefined8 *)(lVar9 + iVar15);
        if (lVar19 - iVar15 != 0) {
          puVar2 = (undefined8 *)(lVar9 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar2 = *puVar17;
        uVar13 = uVar13 + 1;
        lVar18 = lVar18 + -1;
      } while (lVar18 != 0);
    }
  }
  else {
    uVar20 = *(long *)(param_1 + 0x80) + (ulong)uVar6;
    if (uVar20 == 0) {
      lVar9 = 0;
      uVar11 = *(ulong *)(param_1 + 0x88);
    }
    else {
      uVar11 = uVar20 * 8;
      if (0x7fffffffffffffff < uVar11) {
        uVar11 = 0x8000000000000000;
      }
      if (uVar20 >> 0x3d != 0) {
        uVar11 = 0x8000000000000000;
      }
      lVar9 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4508,uVar11);
      if (lVar9 == 0) goto LAB_fffffff0081e76d0;
      uVar11 = *(ulong *)(param_1 + 0x88);
    }
    if (uVar11 != 0) {
      uVar13 = 0;
      uVar12 = *(ulong *)(param_1 + 0x78);
      if ((3 < uVar11) && (0x1f < lVar9 - uVar12)) {
        lVar18 = 0;
        uVar13 = uVar11 & 0xfffffffffffffffc;
        uVar16 = uVar13;
        do {
          puVar17 = (undefined8 *)(uVar12 + lVar18 * 8);
          if (((uVar12 ^ (ulong)puVar17) & 0xffc0000000000000) != 0) {
            puVar17 = (undefined8 *)((ulong)puVar17 & 0xffffffffffff | 0xc8a2000000000000);
          }
          lVar19 = lVar18 * 8;
          puVar2 = (undefined8 *)(lVar9 + (int)lVar19);
          if (lVar19 - (int)lVar19 != 0) {
            puVar2 = (undefined8 *)(lVar9 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar10 = *puVar17;
          uVar22 = puVar17[3];
          uVar21 = puVar17[2];
          puVar2[1] = puVar17[1];
          *puVar2 = uVar10;
          puVar2[3] = uVar22;
          puVar2[2] = uVar21;
          lVar18 = lVar18 + 4;
          uVar16 = uVar16 - 4;
        } while (uVar16 != 0);
        if (uVar11 == uVar13) goto LAB_fffffff0081e74a4;
      }
      lVar18 = uVar11 - uVar13;
      do {
        lVar19 = uVar13 * 8;
        iVar15 = (int)lVar19;
        puVar17 = (undefined8 *)(uVar12 + (long)iVar15);
        if (lVar19 - iVar15 != 0) {
          puVar17 = (undefined8 *)(uVar12 + lVar19 & 0xffffffffffff | 0x2bad000000000000);
        }
        puVar2 = (undefined8 *)(lVar9 + iVar15);
        if (lVar19 - iVar15 != 0) {
          puVar2 = (undefined8 *)(lVar9 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar2 = *puVar17;
        uVar13 = uVar13 + 1;
        lVar18 = lVar18 + -1;
      } while (lVar18 != 0);
    }
  }
LAB_fffffff0081e74a4:
  uVar10 = *(undefined8 *)(param_1 + 0x78);
  uVar11 = *(ulong *)(param_1 + 0x80) << 3;
  if (0x7fffffffffffffff < uVar11) {
    uVar11 = 0x8000000000000000;
  }
  if (*(ulong *)(param_1 + 0x80) >> 0x3d != 0) {
    uVar11 = 0x8000000000000000;
  }
  *(undefined8 *)(param_1 + 0x78) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4558,uVar10,uVar11);
  *(long *)(param_1 + 0x78) = lVar9;
  *(ulong *)(param_1 + 0x80) = uVar20;
  uVar11 = *(ulong *)(param_1 + 0x88);
  for (lVar9 = uVar20 - uVar11; lVar9 != 0; lVar9 = lVar9 + -1) {
    if (uVar11 < uVar20) {
      lVar18 = uVar11 * 8;
      uVar11 = uVar11 + 1;
      *(ulong *)(param_1 + 0x88) = uVar11;
      puVar17 = (undefined8 *)(*(long *)(param_1 + 0x78) + (long)(int)lVar18);
      if (lVar18 - (int)lVar18 != 0) {
        puVar17 = (undefined8 *)
                  (*(long *)(param_1 + 0x78) + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar17 = 0;
    }
  }
  uVar20 = *(ulong *)(param_1 + 0x98);
  if (uVar20 != 0) {
    uVar6 = *(uint *)(param_1 + 0xa4) >> 6;
    if (uVar4 <= uVar6) {
      uVar6 = uVar4;
    }
    uVar11 = (ulong)uVar6;
    if (uVar6 != 0) {
      uVar13 = 0;
      if ((3 < uVar6) && (0x1f < lVar8 - uVar20)) {
        lVar9 = 0;
        uVar13 = uVar11 & 0x3fffffc;
        uVar12 = uVar13;
        do {
          puVar17 = (undefined8 *)(uVar20 + lVar9 * 8);
          if (((uVar20 ^ (ulong)puVar17) & 0xffc0000000000000) != 0) {
            puVar17 = (undefined8 *)((ulong)puVar17 & 0xffffffffffff | 0xc8a2000000000000);
          }
          lVar18 = lVar9 * 8;
          puVar2 = (undefined8 *)(lVar8 + (int)lVar18);
          if (lVar18 - (int)lVar18 != 0) {
            puVar2 = (undefined8 *)(lVar8 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar10 = *puVar17;
          uVar22 = puVar17[3];
          uVar21 = puVar17[2];
          puVar2[1] = puVar17[1];
          *puVar2 = uVar10;
          puVar2[3] = uVar22;
          puVar2[2] = uVar21;
          lVar9 = lVar9 + 4;
          uVar12 = uVar12 - 4;
        } while (uVar12 != 0);
        if (uVar13 == uVar11) goto LAB_fffffff0081e75b0;
      }
      lVar9 = uVar13 - uVar11;
      do {
        lVar18 = uVar13 * 8;
        iVar15 = (int)lVar18;
        puVar17 = (undefined8 *)(uVar20 + (long)iVar15);
        if (lVar18 - iVar15 != 0) {
          puVar17 = (undefined8 *)(uVar20 + lVar18 & 0xffffffffffff | 0x2bad000000000000);
        }
        puVar2 = (undefined8 *)(lVar8 + iVar15);
        if (lVar18 - iVar15 != 0) {
          puVar2 = (undefined8 *)(lVar8 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar2 = *puVar17;
        uVar13 = uVar13 + 1;
        bVar7 = lVar9 != -1;
        lVar9 = lVar9 + 1;
      } while (bVar7);
    }
  }
LAB_fffffff0081e75b0:
  uVar6 = uVar1 >> 6 & 0x3f;
  if (uVar1 < 0x1000) {
    uVar6 = uVar4;
  }
  uVar11 = 0xffffffffffffffff;
  if (uVar1 < 0x1000) {
    uVar11 = ~(-1L << ((ulong)uVar6 & 0x3f));
  }
  puVar14 = (ulong *)(param_1 + 0x90);
  *puVar14 = *puVar14 & uVar11;
  uVar11 = (ulong)(uVar4 - 1);
  uVar5 = uVar5 & 0x3f;
  if (uVar5 == 0) {
    lVar9 = uVar11 * 8;
    puVar3 = (ulong *)(lVar8 + (int)lVar9);
    if (lVar9 != (int)lVar9) {
      puVar3 = (ulong *)(lVar8 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar13 = *puVar3;
  }
  else {
    lVar9 = uVar11 * 8;
    puVar3 = (ulong *)(lVar8 + (int)lVar9);
    if (lVar9 != (int)lVar9) {
      puVar3 = (ulong *)(lVar8 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar13 = *puVar3 & (-1L << uVar5 ^ 0xffffffffffffffffU);
    *puVar3 = uVar13;
  }
  if (uVar13 == 0) {
    uVar13 = (ulong)(uVar4 - 1 >> 3) & 0x1ffffff8;
    *(ulong *)((long)puVar14 + uVar13) =
         *(ulong *)((long)puVar14 + uVar13) & (1L << (uVar11 & 0x3f) ^ 0xffffffffffffffffU);
  }
LAB_fffffff0081e762c:
  *(undefined8 *)(param_1 + 0x98) = 0;
  thunk_EXT_FUN_80110000038fe768
            (&DAT_fffffff007ca4648,uVar20,*(uint *)(param_1 + 0xa4) >> 3 & 0x1ffffff8);
  *(long *)(param_1 + 0x98) = lVar8;
  *(uint *)(param_1 + 0xa4) = uVar1 & 0xffffffc0;
  return 1;
}

