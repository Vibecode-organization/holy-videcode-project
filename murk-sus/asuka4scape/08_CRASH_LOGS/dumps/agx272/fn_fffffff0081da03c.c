// FUN_fffffff0081da03c @ fffffff0081da03c size=460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081da03c(long param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  ulong uVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  
  uVar8 = 0;
  uVar4 = *(uint *)(param_1 + 0x10) >> 5;
  uVar5 = *(uint *)(param_1 + 0x14) >> 5;
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar2 = *(uint *)(param_1 + 0x1c);
  bVar6 = *(int *)(param_1 + 0x68) == 0x10;
  bVar7 = *(int *)(param_1 + 0x6c) == 0x10;
  *(uint *)(param_1 + 0x98) = uVar5 << bVar7 | (uVar4 << bVar6) << 0x10;
  iVar3 = *(int *)(param_1 + 0x20);
  uVar4 = (*(uint *)(param_1 + 0x10) + uVar1 + 0x1f >> 5) - uVar4 << (ulong)bVar6;
  uVar5 = (*(uint *)(param_1 + 0x14) + uVar2 + 0x1f >> 5) - uVar5 << (ulong)bVar7;
  if (uVar4 < 2) {
    uVar4 = 1;
  }
  if (uVar5 < 2) {
    uVar5 = 1;
  }
  *(int *)(param_1 + 0x78) = iVar3;
  *(uint *)(param_1 + 0x7c) = uVar5 & 0x3ff | (uVar4 & 0x3ff) << 0x10;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if (iVar3 < 4) {
    if (iVar3 != 1) {
      if (iVar3 != 2) goto LAB_fffffff0081da1a4;
      goto LAB_fffffff0081da188;
    }
  }
  else {
    if (iVar3 != 4) {
      if (iVar3 != 8) goto LAB_fffffff0081da1a4;
      auVar15._0_8_ = *(ulong *)(param_1 + 0x4c) & 0xffffffff;
      auVar15._8_8_ = *(ulong *)(param_1 + 0x4c) >> 0x20;
      auVar16._0_8_ = *(ulong *)(param_1 + 0x5c) & 0xffffffff;
      auVar16._8_8_ = *(ulong *)(param_1 + 0x5c) >> 0x20;
      auVar12._0_8_ = *(ulong *)(param_1 + 0x44) & 0xffffffff;
      auVar12._8_8_ = *(ulong *)(param_1 + 0x44) >> 0x20;
      auVar9._0_8_ = *(ulong *)(param_1 + 0x54) & 0xffffffff;
      auVar9._8_8_ = *(ulong *)(param_1 + 0x54) >> 0x20;
      auVar9 = NEON_ushl(auVar9,_DAT_fffffff007113b50,8);
      auVar12 = NEON_ushl(auVar12,_DAT_fffffff007113b60,8);
      auVar16 = NEON_ushl(auVar16,_DAT_fffffff007113b70,8);
      auVar15 = NEON_ushl(auVar15,_DAT_fffffff007113b80,8);
      auVar14[0] = auVar12[0] | auVar9[0] | auVar15[0] | auVar16[0];
      auVar14[1] = auVar12[1] | auVar9[1] | auVar15[1] | auVar16[1];
      auVar14[2] = auVar12[2] | auVar9[2] | auVar15[2] | auVar16[2];
      auVar14[3] = auVar12[3] | auVar9[3] | auVar15[3] | auVar16[3];
      auVar14[4] = auVar12[4] | auVar9[4] | auVar15[4] | auVar16[4];
      auVar14[5] = auVar12[5] | auVar9[5] | auVar15[5] | auVar16[5];
      auVar14[6] = auVar12[6] | auVar9[6] | auVar15[6] | auVar16[6];
      auVar14[7] = auVar12[7] | auVar9[7] | auVar15[7] | auVar16[7];
      auVar14[8] = auVar12[8] | auVar9[8] | auVar15[8] | auVar16[8];
      auVar14[9] = auVar12[9] | auVar9[9] | auVar15[9] | auVar16[9];
      auVar14[10] = auVar12[10] | auVar9[10] | auVar15[10] | auVar16[10];
      auVar14[0xb] = auVar12[0xb] | auVar9[0xb] | auVar15[0xb] | auVar16[0xb];
      auVar14[0xc] = auVar12[0xc] | auVar9[0xc] | auVar15[0xc] | auVar16[0xc];
      auVar14[0xd] = auVar12[0xd] | auVar9[0xd] | auVar15[0xd] | auVar16[0xd];
      auVar14[0xe] = auVar12[0xe] | auVar9[0xe] | auVar15[0xe] | auVar16[0xe];
      auVar14[0xf] = auVar12[0xf] | auVar9[0xf] | auVar15[0xf] | auVar16[0xf];
      auVar9 = NEON_ext(auVar14,auVar14,8,1);
      uVar8 = CONCAT17(auVar14[7] | auVar9[7],
                       CONCAT16(auVar14[6] | auVar9[6],
                                CONCAT15(auVar14[5] | auVar9[5],
                                         CONCAT14(auVar14[4] | auVar9[4],
                                                  CONCAT13(auVar14[3] | auVar9[3],
                                                           CONCAT12(auVar14[2] | auVar9[2],
                                                                    CONCAT11(auVar14[1] | auVar9[1],
                                                                             auVar14[0] | auVar9[0])
                                                                   ))))));
    }
    auVar13._0_8_ = *(ulong *)(param_1 + 0x34) & 0xffffffff;
    auVar13._8_8_ = *(ulong *)(param_1 + 0x34) >> 0x20;
    auVar10._0_8_ = *(ulong *)(param_1 + 0x3c) & 0xffffffff;
    auVar10._8_8_ = *(ulong *)(param_1 + 0x3c) >> 0x20;
    auVar9 = NEON_ushl(auVar10,_DAT_fffffff007113b90,8);
    auVar14 = NEON_ushl(auVar13,_DAT_fffffff007113ba0,8);
    auVar11[0] = auVar14[0] | auVar9[0];
    auVar11[1] = auVar14[1] | auVar9[1];
    auVar11[2] = auVar14[2] | auVar9[2];
    auVar11[3] = auVar14[3] | auVar9[3];
    auVar11[4] = auVar14[4] | auVar9[4];
    auVar11[5] = auVar14[5] | auVar9[5];
    auVar11[6] = auVar14[6] | auVar9[6];
    auVar11[7] = auVar14[7] | auVar9[7];
    auVar11[8] = auVar14[8] | auVar9[8];
    auVar11[9] = auVar14[9] | auVar9[9];
    auVar11[10] = auVar14[10] | auVar9[10];
    auVar11[0xb] = auVar14[0xb] | auVar9[0xb];
    auVar11[0xc] = auVar14[0xc] | auVar9[0xc];
    auVar11[0xd] = auVar14[0xd] | auVar9[0xd];
    auVar11[0xe] = auVar14[0xe] | auVar9[0xe];
    auVar11[0xf] = auVar14[0xf] | auVar9[0xf];
    auVar9 = NEON_ext(auVar11,auVar11,8,1);
    uVar8 = CONCAT17(auVar11[7] | auVar9[7],
                     CONCAT16(auVar11[6] | auVar9[6],
                              CONCAT15(auVar11[5] | auVar9[5],
                                       CONCAT14(auVar11[4] | auVar9[4],
                                                CONCAT13(auVar11[3] | auVar9[3],
                                                         CONCAT12(auVar11[2] | auVar9[2],
                                                                  CONCAT11(auVar11[1] | auVar9[1],
                                                                           auVar11[0] | auVar9[0])))
                                               )))) | uVar8;
LAB_fffffff0081da188:
    uVar8 = uVar8 | (ulong)*(uint *)(param_1 + 0x2c) << 8 | (ulong)*(uint *)(param_1 + 0x30) << 0xc;
  }
  *(ulong *)(param_1 + 0x70) =
       uVar8 | *(uint *)(param_1 + 0x24) | (ulong)*(uint *)(param_1 + 0x28) << 4;
LAB_fffffff0081da1a4:
  if (uVar1 == 0) {
    *(undefined4 *)(param_1 + 0x88) = 0x38ddb3d7;
  }
  else {
    *(float *)(param_1 + 0x88) = 1.732051 / (float)uVar1;
  }
  if (uVar2 == 0) {
    *(undefined4 *)(param_1 + 0x8c) = 0x38ddb3d7;
    return;
  }
  *(float *)(param_1 + 0x8c) = 1.732051 / (float)uVar2;
  return;
}

