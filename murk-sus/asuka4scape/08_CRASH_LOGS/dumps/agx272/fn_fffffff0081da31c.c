// FUN_fffffff0081da31c @ fffffff0081da31c size=1116

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081da31c(long param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined1 auVar12 [16];
  bool bVar13;
  bool bVar14;
  ulong uVar15;
  uint uVar16;
  uint uVar24;
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  uint uVar25;
  ulong uVar26;
  int iVar31;
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  int iVar32;
  int iVar36;
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined8 uVar37;
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  
  uVar15 = 0;
  uVar16 = (int)*(undefined8 *)(param_1 + 0x40) + 0x1f;
  uVar24 = (int)((ulong)*(undefined8 *)(param_1 + 0x40) >> 0x20) + 0x1f;
  uVar25 = ((uVar16 >> 5) + 3 >> 2) + 3;
  uVar26 = CONCAT44(((uVar24 >> 5) + 3 >> 2) + 3,uVar25) & 0xfffffffcfffffffc;
  iVar31 = (int)(uVar26 >> 0x20);
  uVar37 = NEON_ushl(uVar26,DAT_fffffff007113fe0,4);
  iVar32 = (int)uVar26 * 3;
  iVar36 = iVar31 * 3;
  uVar11 = NEON_ushl(uVar26,DAT_fffffff007113fe8,4);
  iVar6 = *(int *)(param_1 + 0x90);
  bVar13 = *(int *)(param_1 + 0x94) == 0x10;
  uVar16 = uVar16 >> 5;
  uVar24 = uVar24 >> 5;
  iVar8 = ((uVar25 & 0xfffffffc) << 2) << (iVar6 == 0x10);
  uVar9 = iVar8 * (iVar31 * 4 << bVar13) * 5;
  *(uint *)(param_1 + 0x18) = uVar9 >> 6;
  *(undefined8 *)(param_1 + 0x20) = 0;
  uVar7 = *(uint *)(param_1 + 0x98);
  *(ulong *)(param_1 + 0x10) = (ulong)uVar7 * (ulong)uVar9;
  uVar9 = iVar31 * 4 * iVar8 << (ulong)bVar13;
  *(uint *)(param_1 + 0x28) = uVar9 >> 3 & 0x3ffffff;
  *(ulong *)(param_1 + 0x140) = (ulong)uVar7 * (ulong)(uVar9 << 3);
  *(undefined8 *)(param_1 + 0x180) = 0x40;
  uVar1 = 0x100;
  if (uVar7 < 2) {
    uVar1 = 0;
  }
  *(undefined8 *)(param_1 + 0x30) = uVar1;
  *(ulong *)(param_1 + 0x260) =
       (ulong)(*(uint *)(*(long *)(param_1 + 0x120) + 0x5c8) >> 0xb ^ 0xffffffff) & 0x200;
  bVar14 = (*(byte *)(param_1 + 0xa4) & 1) == 0;
  lVar2 = 0x9c;
  if (bVar14) {
    lVar2 = 0x40;
  }
  lVar3 = 0xa0;
  if (bVar14) {
    lVar3 = 0x44;
  }
  uVar7 = *(uint *)(param_1 + lVar2);
  uVar9 = *(uint *)(param_1 + lVar3);
  *(uint *)(param_1 + 0x100) = uVar9 * 0x10000 - 0x10000 | uVar7 - 1;
  uVar10 = uVar24 * 0x1000 - 0x1000 | uVar16 - 1;
  *(uint *)(param_1 + 0x104) = uVar10;
  *(uint *)(param_1 + 0x114) = uVar10;
  *(uint *)(param_1 + 0x118) = uVar24 * uVar16;
  *(ulong *)(param_1 + 0x108) =
       CONCAT17((byte)((ulong)uVar37 >> 0x38) | (byte)((ulong)uVar11 >> 0x38) |
                (byte)((uint)iVar36 >> 0x18),
                CONCAT16((byte)((ulong)uVar37 >> 0x30) | (byte)((ulong)uVar11 >> 0x30) |
                         (byte)((uint)iVar36 >> 0x10),
                         CONCAT15((byte)((ulong)uVar37 >> 0x28) | (byte)((ulong)uVar11 >> 0x28) |
                                  (byte)((uint)iVar36 >> 8),
                                  CONCAT14((byte)((ulong)uVar37 >> 0x20) |
                                           (byte)((ulong)uVar11 >> 0x20) | (byte)iVar36,
                                           CONCAT13((byte)((ulong)uVar37 >> 0x18) |
                                                    (byte)((ulong)uVar11 >> 0x18) |
                                                    (byte)((uint)iVar32 >> 0x18),
                                                    CONCAT12((byte)((ulong)uVar37 >> 0x10) |
                                                             (byte)((ulong)uVar11 >> 0x10) |
                                                             (byte)((uint)iVar32 >> 0x10),
                                                             CONCAT11((byte)((ulong)uVar37 >> 8) |
                                                                      (byte)((ulong)uVar11 >> 8) |
                                                                      (byte)((uint)iVar32 >> 8),
                                                                      (byte)uVar37 | (byte)uVar11 |
                                                                      (byte)iVar32)))))));
  *(uint *)(param_1 + 0x110) = iVar31 * (uVar25 & 0xfffffffc);
  uVar26 = 0x2000;
  if (iVar6 != 0x20) {
    uVar26 = 0x1000;
  }
  uVar4 = 0x8000;
  if (*(int *)(param_1 + 0x94) != 0x20) {
    uVar4 = 0x4000;
  }
  *(ulong *)(param_1 + 0xf0) = uVar4 | uVar26;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  iVar8 = *(int *)(param_1 + 0x48);
  if (iVar8 < 4) {
    if (iVar8 == 1) goto LAB_fffffff0081da570;
    if (iVar8 == 2) goto LAB_fffffff0081da564;
  }
  else {
    if (iVar8 != 4) {
      if (iVar8 != 8) goto LAB_fffffff0081da580;
      auVar33._0_8_ = *(ulong *)(param_1 + 0x74) & 0xffffffff;
      auVar33._8_8_ = *(ulong *)(param_1 + 0x74) >> 0x20;
      auVar38._0_8_ = *(ulong *)(param_1 + 0x84) & 0xffffffff;
      auVar38._8_8_ = *(ulong *)(param_1 + 0x84) >> 0x20;
      auVar40._0_8_ = *(ulong *)(param_1 + 0x6c) & 0xffffffff;
      auVar40._8_8_ = *(ulong *)(param_1 + 0x6c) >> 0x20;
      auVar29._0_8_ = *(ulong *)(param_1 + 0x7c) & 0xffffffff;
      auVar29._8_8_ = *(ulong *)(param_1 + 0x7c) >> 0x20;
      auVar29 = NEON_ushl(auVar29,_DAT_fffffff007113b50,8);
      auVar40 = NEON_ushl(auVar40,_DAT_fffffff007113b60,8);
      auVar38 = NEON_ushl(auVar38,_DAT_fffffff007113b70,8);
      auVar20._8_8_ = _UNK_fffffff007113b88;
      auVar20._0_8_ = _DAT_fffffff007113b80;
      auVar20 = NEON_ushl(auVar33,auVar20,8);
      auVar35[0] = auVar40[0] | auVar29[0] | auVar20[0] | auVar38[0];
      auVar35[1] = auVar40[1] | auVar29[1] | auVar20[1] | auVar38[1];
      auVar35[2] = auVar40[2] | auVar29[2] | auVar20[2] | auVar38[2];
      auVar35[3] = auVar40[3] | auVar29[3] | auVar20[3] | auVar38[3];
      auVar35[4] = auVar40[4] | auVar29[4] | auVar20[4] | auVar38[4];
      auVar35[5] = auVar40[5] | auVar29[5] | auVar20[5] | auVar38[5];
      auVar35[6] = auVar40[6] | auVar29[6] | auVar20[6] | auVar38[6];
      auVar35[7] = auVar40[7] | auVar29[7] | auVar20[7] | auVar38[7];
      auVar35[8] = auVar40[8] | auVar29[8] | auVar20[8] | auVar38[8];
      auVar35[9] = auVar40[9] | auVar29[9] | auVar20[9] | auVar38[9];
      auVar35[10] = auVar40[10] | auVar29[10] | auVar20[10] | auVar38[10];
      auVar35[0xb] = auVar40[0xb] | auVar29[0xb] | auVar20[0xb] | auVar38[0xb];
      auVar35[0xc] = auVar40[0xc] | auVar29[0xc] | auVar20[0xc] | auVar38[0xc];
      auVar35[0xd] = auVar40[0xd] | auVar29[0xd] | auVar20[0xd] | auVar38[0xd];
      auVar35[0xe] = auVar40[0xe] | auVar29[0xe] | auVar20[0xe] | auVar38[0xe];
      auVar35[0xf] = auVar40[0xf] | auVar29[0xf] | auVar20[0xf] | auVar38[0xf];
      auVar20 = NEON_ext(auVar35,auVar35,8,1);
      uVar15 = CONCAT17(auVar35[7] | auVar20[7],
                        CONCAT16(auVar35[6] | auVar20[6],
                                 CONCAT15(auVar35[5] | auVar20[5],
                                          CONCAT14(auVar35[4] | auVar20[4],
                                                   CONCAT13(auVar35[3] | auVar20[3],
                                                            CONCAT12(auVar35[2] | auVar20[2],
                                                                     CONCAT11(auVar35[1] |
                                                                              auVar20[1],
                                                                              auVar35[0] |
                                                                              auVar20[0])))))));
    }
    auVar27._0_8_ = *(ulong *)(param_1 + 0x5c) & 0xffffffff;
    auVar27._8_8_ = *(ulong *)(param_1 + 0x5c) >> 0x20;
    auVar17._0_8_ = *(ulong *)(param_1 + 100) & 0xffffffff;
    auVar17._8_8_ = *(ulong *)(param_1 + 100) >> 0x20;
    auVar20 = NEON_ushl(auVar17,_DAT_fffffff007113b90,8);
    auVar29 = NEON_ushl(auVar27,_DAT_fffffff007113ba0,8);
    auVar18[0] = auVar29[0] | auVar20[0];
    auVar18[1] = auVar29[1] | auVar20[1];
    auVar18[2] = auVar29[2] | auVar20[2];
    auVar18[3] = auVar29[3] | auVar20[3];
    auVar18[4] = auVar29[4] | auVar20[4];
    auVar18[5] = auVar29[5] | auVar20[5];
    auVar18[6] = auVar29[6] | auVar20[6];
    auVar18[7] = auVar29[7] | auVar20[7];
    auVar18[8] = auVar29[8] | auVar20[8];
    auVar18[9] = auVar29[9] | auVar20[9];
    auVar18[10] = auVar29[10] | auVar20[10];
    auVar18[0xb] = auVar29[0xb] | auVar20[0xb];
    auVar18[0xc] = auVar29[0xc] | auVar20[0xc];
    auVar18[0xd] = auVar29[0xd] | auVar20[0xd];
    auVar18[0xe] = auVar29[0xe] | auVar20[0xe];
    auVar18[0xf] = auVar29[0xf] | auVar20[0xf];
    auVar20 = NEON_ext(auVar18,auVar18,8,1);
    uVar15 = CONCAT17(auVar18[7] | auVar20[7],
                      CONCAT16(auVar18[6] | auVar20[6],
                               CONCAT15(auVar18[5] | auVar20[5],
                                        CONCAT14(auVar18[4] | auVar20[4],
                                                 CONCAT13(auVar18[3] | auVar20[3],
                                                          CONCAT12(auVar18[2] | auVar20[2],
                                                                   CONCAT11(auVar18[1] | auVar20[1],
                                                                            auVar18[0] | auVar20[0])
                                                                  )))))) | uVar15;
LAB_fffffff0081da564:
    uVar15 = uVar15 | (ulong)*(uint *)(param_1 + 0x54) << 8 |
             (ulong)*(uint *)(param_1 + 0x58) << 0xc;
LAB_fffffff0081da570:
    *(ulong *)(param_1 + 0xf8) =
         uVar15 | *(uint *)(param_1 + 0x4c) | (ulong)*(uint *)(param_1 + 0x50) << 4;
  }
LAB_fffffff0081da580:
  uVar16 = 0x1f - (int)LZCOUNT(iVar8);
  if (2 < uVar16) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Not supported\n");
    return;
  }
  uVar15 = 0;
  lVar2 = (ulong)uVar16 * 4;
  puVar5 = (uint *)(&DAT_fffffff007114e5c + (int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar5 = (uint *)((ulong)(&DAT_fffffff007114e5c + lVar2) & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar16 = *puVar5;
  *(ulong *)(param_1 + 0xe8) = (ulong)param_3;
  *(ulong *)(param_1 + 0xf0) = uVar4 | uVar26 | (ulong)uVar16;
  uVar16 = (uVar25 & 0xfffffffc) << (ulong)(iVar6 == 0x10);
  uVar24 = iVar31 << bVar13;
  if (uVar16 < 2) {
    uVar16 = 1;
  }
  if (uVar24 < 2) {
    uVar24 = 1;
  }
  *(int *)(param_1 + 0xb8) = iVar8;
  *(uint *)(param_1 + 0xbc) = (uVar16 & 0x3fd) << 0x10 | uVar24 & 0x3fd;
  *(undefined8 *)(param_1 + 0xb0) = 0;
  if (iVar8 < 4) {
    if (iVar8 != 1) {
      if (iVar8 != 2) goto LAB_fffffff0081da6dc;
      goto LAB_fffffff0081da6c0;
    }
  }
  else {
    if (iVar8 != 4) {
      if (iVar8 != 8) goto LAB_fffffff0081da6dc;
      auVar34._0_8_ = *(ulong *)(param_1 + 0x74) & 0xffffffff;
      auVar34._8_8_ = *(ulong *)(param_1 + 0x74) >> 0x20;
      auVar39._0_8_ = *(ulong *)(param_1 + 0x84) & 0xffffffff;
      auVar39._8_8_ = *(ulong *)(param_1 + 0x84) >> 0x20;
      auVar28._0_8_ = *(ulong *)(param_1 + 0x6c) & 0xffffffff;
      auVar28._8_8_ = *(ulong *)(param_1 + 0x6c) >> 0x20;
      auVar19._0_8_ = *(ulong *)(param_1 + 0x7c) & 0xffffffff;
      auVar19._8_8_ = *(ulong *)(param_1 + 0x7c) >> 0x20;
      auVar20 = NEON_ushl(auVar19,_DAT_fffffff007113b50,8);
      auVar29 = NEON_ushl(auVar28,_DAT_fffffff007113b60,8);
      auVar40 = NEON_ushl(auVar39,_DAT_fffffff007113b70,8);
      auVar12._8_8_ = _UNK_fffffff007113b88;
      auVar12._0_8_ = _DAT_fffffff007113b80;
      auVar35 = NEON_ushl(auVar34,auVar12,8);
      auVar21[0] = auVar29[0] | auVar20[0] | auVar35[0] | auVar40[0];
      auVar21[1] = auVar29[1] | auVar20[1] | auVar35[1] | auVar40[1];
      auVar21[2] = auVar29[2] | auVar20[2] | auVar35[2] | auVar40[2];
      auVar21[3] = auVar29[3] | auVar20[3] | auVar35[3] | auVar40[3];
      auVar21[4] = auVar29[4] | auVar20[4] | auVar35[4] | auVar40[4];
      auVar21[5] = auVar29[5] | auVar20[5] | auVar35[5] | auVar40[5];
      auVar21[6] = auVar29[6] | auVar20[6] | auVar35[6] | auVar40[6];
      auVar21[7] = auVar29[7] | auVar20[7] | auVar35[7] | auVar40[7];
      auVar21[8] = auVar29[8] | auVar20[8] | auVar35[8] | auVar40[8];
      auVar21[9] = auVar29[9] | auVar20[9] | auVar35[9] | auVar40[9];
      auVar21[10] = auVar29[10] | auVar20[10] | auVar35[10] | auVar40[10];
      auVar21[0xb] = auVar29[0xb] | auVar20[0xb] | auVar35[0xb] | auVar40[0xb];
      auVar21[0xc] = auVar29[0xc] | auVar20[0xc] | auVar35[0xc] | auVar40[0xc];
      auVar21[0xd] = auVar29[0xd] | auVar20[0xd] | auVar35[0xd] | auVar40[0xd];
      auVar21[0xe] = auVar29[0xe] | auVar20[0xe] | auVar35[0xe] | auVar40[0xe];
      auVar21[0xf] = auVar29[0xf] | auVar20[0xf] | auVar35[0xf] | auVar40[0xf];
      auVar20 = NEON_ext(auVar21,auVar21,8,1);
      uVar15 = CONCAT17(auVar21[7] | auVar20[7],
                        CONCAT16(auVar21[6] | auVar20[6],
                                 CONCAT15(auVar21[5] | auVar20[5],
                                          CONCAT14(auVar21[4] | auVar20[4],
                                                   CONCAT13(auVar21[3] | auVar20[3],
                                                            CONCAT12(auVar21[2] | auVar20[2],
                                                                     CONCAT11(auVar21[1] |
                                                                              auVar20[1],
                                                                              auVar21[0] |
                                                                              auVar20[0])))))));
    }
    auVar30._0_8_ = *(ulong *)(param_1 + 0x5c) & 0xffffffff;
    auVar30._8_8_ = *(ulong *)(param_1 + 0x5c) >> 0x20;
    auVar22._0_8_ = *(ulong *)(param_1 + 100) & 0xffffffff;
    auVar22._8_8_ = *(ulong *)(param_1 + 100) >> 0x20;
    auVar20 = NEON_ushl(auVar22,_DAT_fffffff007113b90,8);
    auVar29 = NEON_ushl(auVar30,_DAT_fffffff007113ba0,8);
    auVar23[0] = auVar29[0] | auVar20[0];
    auVar23[1] = auVar29[1] | auVar20[1];
    auVar23[2] = auVar29[2] | auVar20[2];
    auVar23[3] = auVar29[3] | auVar20[3];
    auVar23[4] = auVar29[4] | auVar20[4];
    auVar23[5] = auVar29[5] | auVar20[5];
    auVar23[6] = auVar29[6] | auVar20[6];
    auVar23[7] = auVar29[7] | auVar20[7];
    auVar23[8] = auVar29[8] | auVar20[8];
    auVar23[9] = auVar29[9] | auVar20[9];
    auVar23[10] = auVar29[10] | auVar20[10];
    auVar23[0xb] = auVar29[0xb] | auVar20[0xb];
    auVar23[0xc] = auVar29[0xc] | auVar20[0xc];
    auVar23[0xd] = auVar29[0xd] | auVar20[0xd];
    auVar23[0xe] = auVar29[0xe] | auVar20[0xe];
    auVar23[0xf] = auVar29[0xf] | auVar20[0xf];
    auVar20 = NEON_ext(auVar23,auVar23,8,1);
    uVar15 = CONCAT17(auVar23[7] | auVar20[7],
                      CONCAT16(auVar23[6] | auVar20[6],
                               CONCAT15(auVar23[5] | auVar20[5],
                                        CONCAT14(auVar23[4] | auVar20[4],
                                                 CONCAT13(auVar23[3] | auVar20[3],
                                                          CONCAT12(auVar23[2] | auVar20[2],
                                                                   CONCAT11(auVar23[1] | auVar20[1],
                                                                            auVar23[0] | auVar20[0])
                                                                  )))))) | uVar15;
LAB_fffffff0081da6c0:
    uVar15 = uVar15 | (ulong)*(uint *)(param_1 + 0x54) << 8 |
             (ulong)*(uint *)(param_1 + 0x58) << 0xc;
  }
  *(ulong *)(param_1 + 0xb0) =
       uVar15 | *(uint *)(param_1 + 0x4c) | (ulong)*(uint *)(param_1 + 0x50) << 4;
LAB_fffffff0081da6dc:
  if (uVar7 == 0) {
    *(undefined4 *)(param_1 + 200) = 0x38ddb3d7;
  }
  else {
    *(float *)(param_1 + 200) = 1.732051 / (float)uVar7;
  }
  if (uVar9 == 0) {
    *(undefined4 *)(param_1 + 0xcc) = 0x38ddb3d7;
    return;
  }
  *(float *)(param_1 + 0xcc) = 1.732051 / (float)uVar9;
  return;
}

