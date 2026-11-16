// FUN_fffffff0270a9830 @ fffffff0270a9830 size=5228
// CALLERS:
//   fffffff0270a6c88 thunk_FUN_fffffff0270a9830@fffffff0270a6c84
// CALLEES:

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0270a9830(ulong *param_1,long param_2,undefined1 (*param_3) [16])

{
  bool bVar1;
  long lVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  long *plVar8;
  long *plVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  int iVar18;
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  ulong uVar26;
  undefined1 auVar27 [16];
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  long lVar31;
  long lVar32;
  long lVar33;
  long lVar34;
  long lVar35;
  ulong uVar36;
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  ulong uVar44;
  undefined1 auVar46 [16];
  ulong uVar45;
  ulong uVar56;
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  ulong uVar57;
  ulong uVar58;
  long local_80;
  long lStack_78;
  long local_70;
  long lStack_68;
  long local_60;
  long lStack_58;
  long local_50;
  long lStack_48;
  long local_40;
  long lStack_38;
  long local_30;
  long lStack_28;
  long local_20;
  long lStack_18;
  long local_10;
  long lStack_8;
  
  if (param_2 == 0) {
    return;
  }
  auVar19 = NEON_rev64(*param_3,1);
  auVar20 = NEON_rev64(param_3[1],1);
  auVar21 = NEON_rev64(param_3[2],1);
  auVar22 = NEON_rev64(param_3[3],1);
  auVar23 = NEON_rev64(param_3[4],1);
  auVar24 = NEON_rev64(param_3[5],1);
  auVar25 = NEON_rev64(param_3[6],1);
  auVar27 = NEON_rev64(param_3[7],1);
  local_80 = _DAT_fffffff027019ba0 + auVar19._0_8_;
  lStack_78 = _UNK_fffffff027019ba8 + auVar19._8_8_;
  plVar8 = (long *)&DAT_fffffff027019c20;
  local_70 = _DAT_fffffff027019bb0 + auVar20._0_8_;
  lStack_68 = _UNK_fffffff027019bb8 + auVar20._8_8_;
  local_60 = _DAT_fffffff027019bc0 + auVar21._0_8_;
  lStack_58 = _UNK_fffffff027019bc8 + auVar21._8_8_;
  local_50 = _DAT_fffffff027019bd0 + auVar22._0_8_;
  lStack_48 = _UNK_fffffff027019bd8 + auVar22._8_8_;
  local_40 = _DAT_fffffff027019be0 + auVar23._0_8_;
  lStack_38 = _UNK_fffffff027019be8 + auVar23._8_8_;
  local_30 = _DAT_fffffff027019bf0 + auVar24._0_8_;
  lStack_28 = _UNK_fffffff027019bf8 + auVar24._8_8_;
  local_20 = _DAT_fffffff027019c00 + auVar25._0_8_;
  lStack_18 = _UNK_fffffff027019c08 + auVar25._8_8_;
  local_10 = _DAT_fffffff027019c10 + auVar27._0_8_;
  lStack_8 = _UNK_fffffff027019c18 + auVar27._8_8_;
  while( true ) {
    uVar10 = *param_1;
    uVar11 = param_1[1];
    uVar12 = param_1[2];
    uVar13 = param_1[3];
    uVar14 = param_1[4];
    uVar15 = param_1[5];
    uVar16 = param_1[6];
    uVar17 = param_1[7];
    iVar18 = 4;
    do {
      plVar9 = plVar8;
      auVar37 = NEON_ext(auVar23,auVar24,8,1);
      auVar46 = NEON_ext(auVar19,auVar20,8,1);
      uVar26 = auVar27._0_8_;
      uVar29 = uVar26 >> 0x13;
      uVar28 = auVar27._8_8_;
      uVar30 = uVar28 >> 0x13;
      lVar31 = uVar26 << 3;
      lVar34 = uVar28 << 3;
      lVar33 = auVar19._8_8_;
      uVar36 = uVar26 >> 6;
      lVar2 = uVar17 + local_80 +
              ((uVar14 >> 0xe | uVar14 << 0x32) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
              (uVar14 >> 0x29 | uVar14 << 0x17)) + ((uVar15 ^ uVar16) & uVar14 ^ uVar16);
      uVar44 = auVar46._0_8_;
      uVar57 = uVar44 >> 1;
      uVar56 = auVar46._8_8_;
      uVar58 = uVar56 >> 1;
      uVar13 = uVar13 + lVar2;
      uVar45 = uVar44 >> 7;
      bVar4 = auVar27[7];
      bVar5 = auVar27[0xf];
      bVar7 = auVar46[7];
      bVar6 = auVar46[0xf];
      auVar48[9] = (byte)((uVar28 >> 6) >> 8) ^ (byte)(uVar30 >> 8) ^ (byte)((ulong)lVar34 >> 8);
      auVar48[10] = (byte)((auVar27._9_7_ >> 6) >> 8) ^ (byte)(uVar30 >> 0x10) ^
                    (byte)((ulong)lVar34 >> 0x10);
      auVar48[0xb] = (byte)((auVar27._10_6_ >> 6) >> 8) ^ (byte)(uVar30 >> 0x18) ^
                     (byte)((ulong)lVar34 >> 0x18);
      auVar48[0xc] = (byte)((auVar27._11_5_ >> 6) >> 8) ^ (byte)(uVar30 >> 0x20) ^
                     (byte)((ulong)lVar34 >> 0x20);
      lVar32 = uVar26 << 0x2d;
      lVar35 = uVar28 << 0x2d;
      uVar17 = lVar2 + ((uVar10 >> 0x1c | uVar10 << 0x24) ^ (uVar10 >> 0x22 | uVar10 << 0x1e) ^
                       (uVar10 >> 0x27 | uVar10 << 0x19)) +
               ((uVar11 ^ uVar12) & uVar10 ^ uVar11 & uVar12);
      auVar48[8] = (byte)(uVar28 >> 6) ^ (byte)uVar30 ^ (byte)lVar34 ^ bVar5 >> 5;
      auVar47[8] = (byte)(uVar56 >> 7) ^ (byte)uVar58 ^ auVar46[9];
      auVar47[9] = (byte)((uVar56 >> 7) >> 8) ^ (byte)(uVar58 >> 8) ^ auVar46[10];
      auVar47[10] = (byte)((auVar46._9_7_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x10) ^ auVar46[0xb];
      auVar47[0xb] = (byte)((auVar46._10_6_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x18) ^ auVar46[0xc];
      auVar47[0xc] = (byte)((auVar46._11_5_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x20) ^ auVar46[0xd];
      auVar47[0xd] = (byte)((auVar46._12_4_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x28) ^ auVar46[0xe];
      auVar47[0xe] = (byte)((uint3)(auVar46._13_3_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x30) ^ bVar6;
      auVar48._0_8_ =
           CONCAT17(bVar4 >> 6 ^ (byte)((ulong)lVar31 >> 0x38) ^ (byte)((ulong)lVar32 >> 0x38),
                    CONCAT16((byte)(uVar36 >> 0x30) ^ (byte)((ulong)lVar31 >> 0x30) ^
                             (byte)((ulong)lVar32 >> 0x30),
                             CONCAT15((byte)(uVar36 >> 0x28) ^ bVar4 >> 3 ^
                                      (byte)((ulong)lVar31 >> 0x28) ^ (byte)((ulong)lVar32 >> 0x28),
                                      CONCAT14((byte)(uVar36 >> 0x20) ^ (byte)(uVar29 >> 0x20) ^
                                               (byte)((ulong)lVar31 >> 0x20),
                                               CONCAT13((byte)(uVar36 >> 0x18) ^
                                                        (byte)(uVar29 >> 0x18) ^
                                                        (byte)((ulong)lVar31 >> 0x18),
                                                        CONCAT12((byte)(uVar36 >> 0x10) ^
                                                                 (byte)(uVar29 >> 0x10) ^
                                                                 (byte)((ulong)lVar31 >> 0x10),
                                                                 CONCAT11((byte)(uVar36 >> 8) ^
                                                                          (byte)(uVar29 >> 8) ^
                                                                          (byte)((ulong)lVar31 >> 8)
                                                                          ,(byte)uVar36 ^
                                                                           (byte)uVar29 ^
                                                                           (byte)lVar31 ^ bVar4 >> 5
                                                                         )))))));
      auVar48[0xd] = (byte)((auVar27._12_4_ >> 6) >> 8) ^ bVar5 >> 3 ^ (byte)((ulong)lVar34 >> 0x28)
                     ^ (byte)((ulong)lVar35 >> 0x28);
      auVar48[0xe] = (byte)((uint3)(auVar27._13_3_ >> 6) >> 8) ^ (byte)((ulong)lVar34 >> 0x30) ^
                     (byte)((ulong)lVar35 >> 0x30);
      auVar48[0xf] = bVar5 >> 6 ^ (byte)((ulong)lVar34 >> 0x38) ^ (byte)((ulong)lVar35 >> 0x38);
      auVar47._0_8_ =
           CONCAT17(bVar7 >> 7 ^ bVar7 >> 1 ^ auVar46[0] ^ (byte)((uVar44 << 0x3f) >> 0x38),
                    CONCAT16((byte)(uVar45 >> 0x30) ^ (byte)(uVar57 >> 0x30) ^ bVar7,
                             CONCAT15((byte)(uVar45 >> 0x28) ^ (byte)(uVar57 >> 0x28) ^ auVar46[6],
                                      CONCAT14((byte)(uVar45 >> 0x20) ^ (byte)(uVar57 >> 0x20) ^
                                               auVar46[5],
                                               CONCAT13((byte)(uVar45 >> 0x18) ^
                                                        (byte)(uVar57 >> 0x18) ^ auVar46[4],
                                                        CONCAT12((byte)(uVar45 >> 0x10) ^
                                                                 (byte)(uVar57 >> 0x10) ^ auVar46[3]
                                                                 ,CONCAT11((byte)(uVar45 >> 8) ^
                                                                           (byte)(uVar57 >> 8) ^
                                                                           auVar46[2],
                                                                           (byte)uVar45 ^
                                                                           (byte)uVar57 ^ auVar46[1]
                                                                          )))))));
      auVar47[0xf] = bVar6 >> 7 ^ bVar6 >> 1 ^ auVar46[8] ^ (byte)((uVar56 << 0x3f) >> 0x38);
      lVar2 = uVar16 + lStack_78;
      auVar19._0_8_ = auVar19._0_8_ + auVar37._0_8_ + auVar48._0_8_ + auVar47._0_8_;
      auVar19._8_8_ = lVar33 + auVar37._8_8_ + auVar48._8_8_ + auVar47._8_8_;
      local_80 = *plVar9 + auVar19._0_8_;
      lStack_78 = plVar9[1] + auVar19._8_8_;
      lVar2 = lVar2 + ((uVar13 >> 0xe | uVar13 << 0x32) ^ (uVar13 >> 0x12 | uVar13 << 0x2e) ^
                      (uVar13 >> 0x29 | uVar13 * 0x800000)) + ((uVar14 ^ uVar15) & uVar13 ^ uVar15);
      uVar12 = uVar12 + lVar2;
      uVar16 = lVar2 + ((uVar17 >> 0x1c | uVar17 << 0x24) ^ (uVar17 >> 0x22 | uVar17 * 0x40000000) ^
                       (uVar17 >> 0x27 | uVar17 * 0x2000000)) +
               ((uVar10 ^ uVar11) & uVar17 ^ uVar10 & uVar11);
      auVar37 = NEON_ext(auVar24,auVar25,8,1);
      auVar48 = NEON_ext(auVar20,auVar21,8,1);
      uVar29 = auVar19._0_8_ >> 0x13;
      uVar30 = auVar19._8_8_ >> 0x13;
      lVar31 = auVar19._0_8_ * 8;
      lVar34 = auVar19._8_8_ * 8;
      lVar33 = auVar20._8_8_;
      uVar36 = auVar19._0_8_ >> 6;
      lVar2 = uVar15 + local_70 +
              ((uVar12 >> 0xe | uVar12 << 0x32) ^ (uVar12 >> 0x12 | uVar12 << 0x2e) ^
              (uVar12 >> 0x29 | uVar12 * 0x800000)) + ((uVar13 ^ uVar14) & uVar12 ^ uVar14);
      uVar44 = auVar48._0_8_;
      uVar57 = uVar44 >> 1;
      uVar56 = auVar48._8_8_;
      uVar58 = uVar56 >> 1;
      uVar11 = uVar11 + lVar2;
      uVar45 = uVar44 >> 7;
      bVar4 = (byte)(auVar19._0_8_ >> 0x38);
      bVar5 = (byte)(auVar19._8_8_ >> 0x38);
      bVar7 = auVar48[7];
      bVar6 = auVar48[0xf];
      auVar46[9] = (byte)((auVar19._8_8_ >> 6) >> 8) ^ (byte)(uVar30 >> 8) ^
                   (byte)((ulong)lVar34 >> 8);
      auVar46[10] = (byte)((uint7)(auVar19._8_8_ >> 0xe) >> 8) ^ (byte)(uVar30 >> 0x10) ^
                    (byte)((ulong)lVar34 >> 0x10);
      auVar46[0xb] = (byte)((uint6)(auVar19._8_8_ >> 0x16) >> 8) ^ (byte)(uVar30 >> 0x18) ^
                     (byte)((ulong)lVar34 >> 0x18);
      auVar46[0xc] = (byte)((uint5)(auVar19._8_8_ >> 0x1e) >> 8) ^ (byte)(uVar30 >> 0x20) ^
                     (byte)((ulong)lVar34 >> 0x20);
      lVar32 = auVar19._0_8_ << 0x2d;
      lVar35 = auVar19._8_8_ << 0x2d;
      uVar15 = lVar2 + ((uVar16 >> 0x1c | uVar16 << 0x24) ^ (uVar16 >> 0x22 | uVar16 * 0x40000000) ^
                       (uVar16 >> 0x27 | uVar16 * 0x2000000)) +
               ((uVar17 ^ uVar10) & uVar16 ^ uVar17 & uVar10);
      auVar46[8] = (byte)(auVar19._8_8_ >> 6) ^ (byte)uVar30 ^ (byte)lVar34 ^ bVar5 >> 5;
      auVar49[8] = (byte)(uVar56 >> 7) ^ (byte)uVar58 ^ auVar48[9];
      auVar49[9] = (byte)((uVar56 >> 7) >> 8) ^ (byte)(uVar58 >> 8) ^ auVar48[10];
      auVar49[10] = (byte)((auVar48._9_7_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x10) ^ auVar48[0xb];
      auVar49[0xb] = (byte)((auVar48._10_6_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x18) ^ auVar48[0xc];
      auVar49[0xc] = (byte)((auVar48._11_5_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x20) ^ auVar48[0xd];
      auVar49[0xd] = (byte)((auVar48._12_4_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x28) ^ auVar48[0xe];
      auVar49[0xe] = (byte)((uint3)(auVar48._13_3_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x30) ^ bVar6;
      auVar46._0_8_ =
           CONCAT17(bVar4 >> 6 ^ (byte)((ulong)lVar31 >> 0x38) ^ (byte)((ulong)lVar32 >> 0x38),
                    CONCAT16((byte)(uVar36 >> 0x30) ^ (byte)((ulong)lVar31 >> 0x30) ^
                             (byte)((ulong)lVar32 >> 0x30),
                             CONCAT15((byte)(uVar36 >> 0x28) ^ bVar4 >> 3 ^
                                      (byte)((ulong)lVar31 >> 0x28) ^ (byte)((ulong)lVar32 >> 0x28),
                                      CONCAT14((byte)(uVar36 >> 0x20) ^ (byte)(uVar29 >> 0x20) ^
                                               (byte)((ulong)lVar31 >> 0x20),
                                               CONCAT13((byte)(uVar36 >> 0x18) ^
                                                        (byte)(uVar29 >> 0x18) ^
                                                        (byte)((ulong)lVar31 >> 0x18),
                                                        CONCAT12((byte)(uVar36 >> 0x10) ^
                                                                 (byte)(uVar29 >> 0x10) ^
                                                                 (byte)((ulong)lVar31 >> 0x10),
                                                                 CONCAT11((byte)(uVar36 >> 8) ^
                                                                          (byte)(uVar29 >> 8) ^
                                                                          (byte)((ulong)lVar31 >> 8)
                                                                          ,(byte)uVar36 ^
                                                                           (byte)uVar29 ^
                                                                           (byte)lVar31 ^ bVar4 >> 5
                                                                         )))))));
      auVar46[0xd] = (byte)((uint)(auVar19._8_8_ >> 0x26) >> 8) ^ bVar5 >> 3 ^
                     (byte)((ulong)lVar34 >> 0x28) ^ (byte)((ulong)lVar35 >> 0x28);
      auVar46[0xe] = (byte)((uint3)(auVar19._8_8_ >> 0x2e) >> 8) ^ (byte)((ulong)lVar34 >> 0x30) ^
                     (byte)((ulong)lVar35 >> 0x30);
      auVar46[0xf] = bVar5 >> 6 ^ (byte)((ulong)lVar34 >> 0x38) ^ (byte)((ulong)lVar35 >> 0x38);
      auVar49._0_8_ =
           CONCAT17(bVar7 >> 7 ^ bVar7 >> 1 ^ auVar48[0] ^ (byte)((uVar44 << 0x3f) >> 0x38),
                    CONCAT16((byte)(uVar45 >> 0x30) ^ (byte)(uVar57 >> 0x30) ^ bVar7,
                             CONCAT15((byte)(uVar45 >> 0x28) ^ (byte)(uVar57 >> 0x28) ^ auVar48[6],
                                      CONCAT14((byte)(uVar45 >> 0x20) ^ (byte)(uVar57 >> 0x20) ^
                                               auVar48[5],
                                               CONCAT13((byte)(uVar45 >> 0x18) ^
                                                        (byte)(uVar57 >> 0x18) ^ auVar48[4],
                                                        CONCAT12((byte)(uVar45 >> 0x10) ^
                                                                 (byte)(uVar57 >> 0x10) ^ auVar48[3]
                                                                 ,CONCAT11((byte)(uVar45 >> 8) ^
                                                                           (byte)(uVar57 >> 8) ^
                                                                           auVar48[2],
                                                                           (byte)uVar45 ^
                                                                           (byte)uVar57 ^ auVar48[1]
                                                                          )))))));
      auVar49[0xf] = bVar6 >> 7 ^ bVar6 >> 1 ^ auVar48[8] ^ (byte)((uVar56 << 0x3f) >> 0x38);
      lVar2 = uVar14 + lStack_68;
      auVar20._0_8_ = auVar20._0_8_ + auVar37._0_8_ + auVar46._0_8_ + auVar49._0_8_;
      auVar20._8_8_ = lVar33 + auVar37._8_8_ + auVar46._8_8_ + auVar49._8_8_;
      local_70 = plVar9[2] + auVar20._0_8_;
      lStack_68 = plVar9[3] + auVar20._8_8_;
      lVar2 = lVar2 + ((uVar11 >> 0xe | uVar11 << 0x32) ^ (uVar11 >> 0x12 | uVar11 << 0x2e) ^
                      (uVar11 >> 0x29 | uVar11 * 0x800000)) + ((uVar12 ^ uVar13) & uVar11 ^ uVar13);
      uVar10 = uVar10 + lVar2;
      uVar14 = lVar2 + ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
                       (uVar15 >> 0x27 | uVar15 * 0x2000000)) +
               ((uVar16 ^ uVar17) & uVar15 ^ uVar16 & uVar17);
      auVar37 = NEON_ext(auVar25,auVar27,8,1);
      auVar48 = NEON_ext(auVar21,auVar22,8,1);
      uVar29 = auVar20._0_8_ >> 0x13;
      uVar30 = auVar20._8_8_ >> 0x13;
      lVar31 = auVar20._0_8_ * 8;
      lVar34 = auVar20._8_8_ * 8;
      lVar33 = auVar21._8_8_;
      uVar36 = auVar20._0_8_ >> 6;
      lVar2 = uVar13 + local_60 +
              ((uVar10 >> 0xe | uVar10 << 0x32) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
              (uVar10 >> 0x29 | uVar10 * 0x800000)) + ((uVar11 ^ uVar12) & uVar10 ^ uVar12);
      uVar44 = auVar48._0_8_;
      uVar57 = uVar44 >> 1;
      uVar56 = auVar48._8_8_;
      uVar58 = uVar56 >> 1;
      uVar17 = uVar17 + lVar2;
      uVar45 = uVar44 >> 7;
      bVar4 = (byte)(auVar20._0_8_ >> 0x38);
      bVar5 = (byte)(auVar20._8_8_ >> 0x38);
      bVar7 = auVar48[7];
      bVar6 = auVar48[0xf];
      auVar38[9] = (byte)((auVar20._8_8_ >> 6) >> 8) ^ (byte)(uVar30 >> 8) ^
                   (byte)((ulong)lVar34 >> 8);
      auVar38[10] = (byte)((uint7)(auVar20._8_8_ >> 0xe) >> 8) ^ (byte)(uVar30 >> 0x10) ^
                    (byte)((ulong)lVar34 >> 0x10);
      auVar38[0xb] = (byte)((uint6)(auVar20._8_8_ >> 0x16) >> 8) ^ (byte)(uVar30 >> 0x18) ^
                     (byte)((ulong)lVar34 >> 0x18);
      auVar38[0xc] = (byte)((uint5)(auVar20._8_8_ >> 0x1e) >> 8) ^ (byte)(uVar30 >> 0x20) ^
                     (byte)((ulong)lVar34 >> 0x20);
      lVar32 = auVar20._0_8_ << 0x2d;
      lVar35 = auVar20._8_8_ << 0x2d;
      uVar13 = lVar2 + ((uVar14 >> 0x1c | uVar14 << 0x24) ^ (uVar14 >> 0x22 | uVar14 * 0x40000000) ^
                       (uVar14 >> 0x27 | uVar14 * 0x2000000)) +
               ((uVar15 ^ uVar16) & uVar14 ^ uVar15 & uVar16);
      auVar38[8] = (byte)(auVar20._8_8_ >> 6) ^ (byte)uVar30 ^ (byte)lVar34 ^ bVar5 >> 5;
      auVar50[8] = (byte)(uVar56 >> 7) ^ (byte)uVar58 ^ auVar48[9];
      auVar50[9] = (byte)((uVar56 >> 7) >> 8) ^ (byte)(uVar58 >> 8) ^ auVar48[10];
      auVar50[10] = (byte)((auVar48._9_7_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x10) ^ auVar48[0xb];
      auVar50[0xb] = (byte)((auVar48._10_6_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x18) ^ auVar48[0xc];
      auVar50[0xc] = (byte)((auVar48._11_5_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x20) ^ auVar48[0xd];
      auVar50[0xd] = (byte)((auVar48._12_4_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x28) ^ auVar48[0xe];
      auVar50[0xe] = (byte)((uint3)(auVar48._13_3_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x30) ^ bVar6;
      auVar38._0_8_ =
           CONCAT17(bVar4 >> 6 ^ (byte)((ulong)lVar31 >> 0x38) ^ (byte)((ulong)lVar32 >> 0x38),
                    CONCAT16((byte)(uVar36 >> 0x30) ^ (byte)((ulong)lVar31 >> 0x30) ^
                             (byte)((ulong)lVar32 >> 0x30),
                             CONCAT15((byte)(uVar36 >> 0x28) ^ bVar4 >> 3 ^
                                      (byte)((ulong)lVar31 >> 0x28) ^ (byte)((ulong)lVar32 >> 0x28),
                                      CONCAT14((byte)(uVar36 >> 0x20) ^ (byte)(uVar29 >> 0x20) ^
                                               (byte)((ulong)lVar31 >> 0x20),
                                               CONCAT13((byte)(uVar36 >> 0x18) ^
                                                        (byte)(uVar29 >> 0x18) ^
                                                        (byte)((ulong)lVar31 >> 0x18),
                                                        CONCAT12((byte)(uVar36 >> 0x10) ^
                                                                 (byte)(uVar29 >> 0x10) ^
                                                                 (byte)((ulong)lVar31 >> 0x10),
                                                                 CONCAT11((byte)(uVar36 >> 8) ^
                                                                          (byte)(uVar29 >> 8) ^
                                                                          (byte)((ulong)lVar31 >> 8)
                                                                          ,(byte)uVar36 ^
                                                                           (byte)uVar29 ^
                                                                           (byte)lVar31 ^ bVar4 >> 5
                                                                         )))))));
      auVar38[0xd] = (byte)((uint)(auVar20._8_8_ >> 0x26) >> 8) ^ bVar5 >> 3 ^
                     (byte)((ulong)lVar34 >> 0x28) ^ (byte)((ulong)lVar35 >> 0x28);
      auVar38[0xe] = (byte)((uint3)(auVar20._8_8_ >> 0x2e) >> 8) ^ (byte)((ulong)lVar34 >> 0x30) ^
                     (byte)((ulong)lVar35 >> 0x30);
      auVar38[0xf] = bVar5 >> 6 ^ (byte)((ulong)lVar34 >> 0x38) ^ (byte)((ulong)lVar35 >> 0x38);
      auVar50._0_8_ =
           CONCAT17(bVar7 >> 7 ^ bVar7 >> 1 ^ auVar48[0] ^ (byte)((uVar44 << 0x3f) >> 0x38),
                    CONCAT16((byte)(uVar45 >> 0x30) ^ (byte)(uVar57 >> 0x30) ^ bVar7,
                             CONCAT15((byte)(uVar45 >> 0x28) ^ (byte)(uVar57 >> 0x28) ^ auVar48[6],
                                      CONCAT14((byte)(uVar45 >> 0x20) ^ (byte)(uVar57 >> 0x20) ^
                                               auVar48[5],
                                               CONCAT13((byte)(uVar45 >> 0x18) ^
                                                        (byte)(uVar57 >> 0x18) ^ auVar48[4],
                                                        CONCAT12((byte)(uVar45 >> 0x10) ^
                                                                 (byte)(uVar57 >> 0x10) ^ auVar48[3]
                                                                 ,CONCAT11((byte)(uVar45 >> 8) ^
                                                                           (byte)(uVar57 >> 8) ^
                                                                           auVar48[2],
                                                                           (byte)uVar45 ^
                                                                           (byte)uVar57 ^ auVar48[1]
                                                                          )))))));
      auVar50[0xf] = bVar6 >> 7 ^ bVar6 >> 1 ^ auVar48[8] ^ (byte)((uVar56 << 0x3f) >> 0x38);
      lVar2 = uVar12 + lStack_58;
      auVar21._0_8_ = auVar21._0_8_ + auVar37._0_8_ + auVar38._0_8_ + auVar50._0_8_;
      auVar21._8_8_ = lVar33 + auVar37._8_8_ + auVar38._8_8_ + auVar50._8_8_;
      local_60 = plVar9[4] + auVar21._0_8_;
      lStack_58 = plVar9[5] + auVar21._8_8_;
      lVar2 = lVar2 + ((uVar17 >> 0xe | uVar17 << 0x32) ^ (uVar17 >> 0x12 | uVar17 << 0x2e) ^
                      (uVar17 >> 0x29 | uVar17 * 0x800000)) + ((uVar10 ^ uVar11) & uVar17 ^ uVar11);
      uVar16 = uVar16 + lVar2;
      uVar12 = lVar2 + ((uVar13 >> 0x1c | uVar13 << 0x24) ^ (uVar13 >> 0x22 | uVar13 * 0x40000000) ^
                       (uVar13 >> 0x27 | uVar13 * 0x2000000)) +
               ((uVar14 ^ uVar15) & uVar13 ^ uVar14 & uVar15);
      auVar37 = NEON_ext(auVar27,auVar19,8,1);
      auVar48 = NEON_ext(auVar22,auVar23,8,1);
      uVar29 = auVar21._0_8_ >> 0x13;
      uVar30 = auVar21._8_8_ >> 0x13;
      lVar31 = auVar21._0_8_ * 8;
      lVar34 = auVar21._8_8_ * 8;
      lVar33 = auVar22._8_8_;
      uVar36 = auVar21._0_8_ >> 6;
      lVar2 = uVar11 + local_50 +
              ((uVar16 >> 0xe | uVar16 << 0x32) ^ (uVar16 >> 0x12 | uVar16 << 0x2e) ^
              (uVar16 >> 0x29 | uVar16 * 0x800000)) + ((uVar17 ^ uVar10) & uVar16 ^ uVar10);
      uVar44 = auVar48._0_8_;
      uVar57 = uVar44 >> 1;
      uVar56 = auVar48._8_8_;
      uVar58 = uVar56 >> 1;
      uVar15 = uVar15 + lVar2;
      uVar45 = uVar44 >> 7;
      bVar4 = (byte)(auVar21._0_8_ >> 0x38);
      bVar5 = (byte)(auVar21._8_8_ >> 0x38);
      bVar7 = auVar48[7];
      bVar6 = auVar48[0xf];
      auVar39[9] = (byte)((auVar21._8_8_ >> 6) >> 8) ^ (byte)(uVar30 >> 8) ^
                   (byte)((ulong)lVar34 >> 8);
      auVar39[10] = (byte)((uint7)(auVar21._8_8_ >> 0xe) >> 8) ^ (byte)(uVar30 >> 0x10) ^
                    (byte)((ulong)lVar34 >> 0x10);
      auVar39[0xb] = (byte)((uint6)(auVar21._8_8_ >> 0x16) >> 8) ^ (byte)(uVar30 >> 0x18) ^
                     (byte)((ulong)lVar34 >> 0x18);
      auVar39[0xc] = (byte)((uint5)(auVar21._8_8_ >> 0x1e) >> 8) ^ (byte)(uVar30 >> 0x20) ^
                     (byte)((ulong)lVar34 >> 0x20);
      lVar32 = auVar21._0_8_ << 0x2d;
      lVar35 = auVar21._8_8_ << 0x2d;
      uVar11 = lVar2 + ((uVar12 >> 0x1c | uVar12 << 0x24) ^ (uVar12 >> 0x22 | uVar12 * 0x40000000) ^
                       (uVar12 >> 0x27 | uVar12 * 0x2000000)) +
               ((uVar13 ^ uVar14) & uVar12 ^ uVar13 & uVar14);
      auVar39[8] = (byte)(auVar21._8_8_ >> 6) ^ (byte)uVar30 ^ (byte)lVar34 ^ bVar5 >> 5;
      auVar51[8] = (byte)(uVar56 >> 7) ^ (byte)uVar58 ^ auVar48[9];
      auVar51[9] = (byte)((uVar56 >> 7) >> 8) ^ (byte)(uVar58 >> 8) ^ auVar48[10];
      auVar51[10] = (byte)((auVar48._9_7_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x10) ^ auVar48[0xb];
      auVar51[0xb] = (byte)((auVar48._10_6_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x18) ^ auVar48[0xc];
      auVar51[0xc] = (byte)((auVar48._11_5_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x20) ^ auVar48[0xd];
      auVar51[0xd] = (byte)((auVar48._12_4_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x28) ^ auVar48[0xe];
      auVar51[0xe] = (byte)((uint3)(auVar48._13_3_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x30) ^ bVar6;
      auVar39._0_8_ =
           CONCAT17(bVar4 >> 6 ^ (byte)((ulong)lVar31 >> 0x38) ^ (byte)((ulong)lVar32 >> 0x38),
                    CONCAT16((byte)(uVar36 >> 0x30) ^ (byte)((ulong)lVar31 >> 0x30) ^
                             (byte)((ulong)lVar32 >> 0x30),
                             CONCAT15((byte)(uVar36 >> 0x28) ^ bVar4 >> 3 ^
                                      (byte)((ulong)lVar31 >> 0x28) ^ (byte)((ulong)lVar32 >> 0x28),
                                      CONCAT14((byte)(uVar36 >> 0x20) ^ (byte)(uVar29 >> 0x20) ^
                                               (byte)((ulong)lVar31 >> 0x20),
                                               CONCAT13((byte)(uVar36 >> 0x18) ^
                                                        (byte)(uVar29 >> 0x18) ^
                                                        (byte)((ulong)lVar31 >> 0x18),
                                                        CONCAT12((byte)(uVar36 >> 0x10) ^
                                                                 (byte)(uVar29 >> 0x10) ^
                                                                 (byte)((ulong)lVar31 >> 0x10),
                                                                 CONCAT11((byte)(uVar36 >> 8) ^
                                                                          (byte)(uVar29 >> 8) ^
                                                                          (byte)((ulong)lVar31 >> 8)
                                                                          ,(byte)uVar36 ^
                                                                           (byte)uVar29 ^
                                                                           (byte)lVar31 ^ bVar4 >> 5
                                                                         )))))));
      auVar39[0xd] = (byte)((uint)(auVar21._8_8_ >> 0x26) >> 8) ^ bVar5 >> 3 ^
                     (byte)((ulong)lVar34 >> 0x28) ^ (byte)((ulong)lVar35 >> 0x28);
      auVar39[0xe] = (byte)((uint3)(auVar21._8_8_ >> 0x2e) >> 8) ^ (byte)((ulong)lVar34 >> 0x30) ^
                     (byte)((ulong)lVar35 >> 0x30);
      auVar39[0xf] = bVar5 >> 6 ^ (byte)((ulong)lVar34 >> 0x38) ^ (byte)((ulong)lVar35 >> 0x38);
      auVar51._0_8_ =
           CONCAT17(bVar7 >> 7 ^ bVar7 >> 1 ^ auVar48[0] ^ (byte)((uVar44 << 0x3f) >> 0x38),
                    CONCAT16((byte)(uVar45 >> 0x30) ^ (byte)(uVar57 >> 0x30) ^ bVar7,
                             CONCAT15((byte)(uVar45 >> 0x28) ^ (byte)(uVar57 >> 0x28) ^ auVar48[6],
                                      CONCAT14((byte)(uVar45 >> 0x20) ^ (byte)(uVar57 >> 0x20) ^
                                               auVar48[5],
                                               CONCAT13((byte)(uVar45 >> 0x18) ^
                                                        (byte)(uVar57 >> 0x18) ^ auVar48[4],
                                                        CONCAT12((byte)(uVar45 >> 0x10) ^
                                                                 (byte)(uVar57 >> 0x10) ^ auVar48[3]
                                                                 ,CONCAT11((byte)(uVar45 >> 8) ^
                                                                           (byte)(uVar57 >> 8) ^
                                                                           auVar48[2],
                                                                           (byte)uVar45 ^
                                                                           (byte)uVar57 ^ auVar48[1]
                                                                          )))))));
      auVar51[0xf] = bVar6 >> 7 ^ bVar6 >> 1 ^ auVar48[8] ^ (byte)((uVar56 << 0x3f) >> 0x38);
      lVar2 = uVar10 + lStack_48;
      auVar22._0_8_ = auVar22._0_8_ + auVar37._0_8_ + auVar39._0_8_ + auVar51._0_8_;
      auVar22._8_8_ = lVar33 + auVar37._8_8_ + auVar39._8_8_ + auVar51._8_8_;
      local_50 = plVar9[6] + auVar22._0_8_;
      lStack_48 = plVar9[7] + auVar22._8_8_;
      lVar2 = lVar2 + ((uVar15 >> 0xe | uVar15 << 0x32) ^ (uVar15 >> 0x12 | uVar15 << 0x2e) ^
                      (uVar15 >> 0x29 | uVar15 * 0x800000)) + ((uVar16 ^ uVar17) & uVar15 ^ uVar17);
      uVar14 = uVar14 + lVar2;
      uVar10 = lVar2 + ((uVar11 >> 0x1c | uVar11 << 0x24) ^ (uVar11 >> 0x22 | uVar11 * 0x40000000) ^
                       (uVar11 >> 0x27 | uVar11 * 0x2000000)) +
               ((uVar12 ^ uVar13) & uVar11 ^ uVar12 & uVar13);
      auVar37 = NEON_ext(auVar19,auVar20,8,1);
      auVar48 = NEON_ext(auVar23,auVar24,8,1);
      uVar29 = auVar22._0_8_ >> 0x13;
      uVar30 = auVar22._8_8_ >> 0x13;
      lVar31 = auVar22._0_8_ * 8;
      lVar34 = auVar22._8_8_ * 8;
      lVar33 = auVar23._8_8_;
      uVar36 = auVar22._0_8_ >> 6;
      lVar2 = uVar17 + local_40 +
              ((uVar14 >> 0xe | uVar14 << 0x32) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
              (uVar14 >> 0x29 | uVar14 * 0x800000)) + ((uVar15 ^ uVar16) & uVar14 ^ uVar16);
      uVar44 = auVar48._0_8_;
      uVar57 = uVar44 >> 1;
      uVar56 = auVar48._8_8_;
      uVar58 = uVar56 >> 1;
      uVar13 = uVar13 + lVar2;
      uVar45 = uVar44 >> 7;
      bVar4 = (byte)(auVar22._0_8_ >> 0x38);
      bVar5 = (byte)(auVar22._8_8_ >> 0x38);
      bVar7 = auVar48[7];
      bVar6 = auVar48[0xf];
      auVar40[9] = (byte)((auVar22._8_8_ >> 6) >> 8) ^ (byte)(uVar30 >> 8) ^
                   (byte)((ulong)lVar34 >> 8);
      auVar40[10] = (byte)((uint7)(auVar22._8_8_ >> 0xe) >> 8) ^ (byte)(uVar30 >> 0x10) ^
                    (byte)((ulong)lVar34 >> 0x10);
      auVar40[0xb] = (byte)((uint6)(auVar22._8_8_ >> 0x16) >> 8) ^ (byte)(uVar30 >> 0x18) ^
                     (byte)((ulong)lVar34 >> 0x18);
      auVar40[0xc] = (byte)((uint5)(auVar22._8_8_ >> 0x1e) >> 8) ^ (byte)(uVar30 >> 0x20) ^
                     (byte)((ulong)lVar34 >> 0x20);
      lVar32 = auVar22._0_8_ << 0x2d;
      lVar35 = auVar22._8_8_ << 0x2d;
      uVar17 = lVar2 + ((uVar10 >> 0x1c | uVar10 << 0x24) ^ (uVar10 >> 0x22 | uVar10 * 0x40000000) ^
                       (uVar10 >> 0x27 | uVar10 * 0x2000000)) +
               ((uVar11 ^ uVar12) & uVar10 ^ uVar11 & uVar12);
      auVar40[8] = (byte)(auVar22._8_8_ >> 6) ^ (byte)uVar30 ^ (byte)lVar34 ^ bVar5 >> 5;
      auVar52[8] = (byte)(uVar56 >> 7) ^ (byte)uVar58 ^ auVar48[9];
      auVar52[9] = (byte)((uVar56 >> 7) >> 8) ^ (byte)(uVar58 >> 8) ^ auVar48[10];
      auVar52[10] = (byte)((auVar48._9_7_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x10) ^ auVar48[0xb];
      auVar52[0xb] = (byte)((auVar48._10_6_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x18) ^ auVar48[0xc];
      auVar52[0xc] = (byte)((auVar48._11_5_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x20) ^ auVar48[0xd];
      auVar52[0xd] = (byte)((auVar48._12_4_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x28) ^ auVar48[0xe];
      auVar52[0xe] = (byte)((uint3)(auVar48._13_3_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x30) ^ bVar6;
      auVar40._0_8_ =
           CONCAT17(bVar4 >> 6 ^ (byte)((ulong)lVar31 >> 0x38) ^ (byte)((ulong)lVar32 >> 0x38),
                    CONCAT16((byte)(uVar36 >> 0x30) ^ (byte)((ulong)lVar31 >> 0x30) ^
                             (byte)((ulong)lVar32 >> 0x30),
                             CONCAT15((byte)(uVar36 >> 0x28) ^ bVar4 >> 3 ^
                                      (byte)((ulong)lVar31 >> 0x28) ^ (byte)((ulong)lVar32 >> 0x28),
                                      CONCAT14((byte)(uVar36 >> 0x20) ^ (byte)(uVar29 >> 0x20) ^
                                               (byte)((ulong)lVar31 >> 0x20),
                                               CONCAT13((byte)(uVar36 >> 0x18) ^
                                                        (byte)(uVar29 >> 0x18) ^
                                                        (byte)((ulong)lVar31 >> 0x18),
                                                        CONCAT12((byte)(uVar36 >> 0x10) ^
                                                                 (byte)(uVar29 >> 0x10) ^
                                                                 (byte)((ulong)lVar31 >> 0x10),
                                                                 CONCAT11((byte)(uVar36 >> 8) ^
                                                                          (byte)(uVar29 >> 8) ^
                                                                          (byte)((ulong)lVar31 >> 8)
                                                                          ,(byte)uVar36 ^
                                                                           (byte)uVar29 ^
                                                                           (byte)lVar31 ^ bVar4 >> 5
                                                                         )))))));
      auVar40[0xd] = (byte)((uint)(auVar22._8_8_ >> 0x26) >> 8) ^ bVar5 >> 3 ^
                     (byte)((ulong)lVar34 >> 0x28) ^ (byte)((ulong)lVar35 >> 0x28);
      auVar40[0xe] = (byte)((uint3)(auVar22._8_8_ >> 0x2e) >> 8) ^ (byte)((ulong)lVar34 >> 0x30) ^
                     (byte)((ulong)lVar35 >> 0x30);
      auVar40[0xf] = bVar5 >> 6 ^ (byte)((ulong)lVar34 >> 0x38) ^ (byte)((ulong)lVar35 >> 0x38);
      auVar52._0_8_ =
           CONCAT17(bVar7 >> 7 ^ bVar7 >> 1 ^ auVar48[0] ^ (byte)((uVar44 << 0x3f) >> 0x38),
                    CONCAT16((byte)(uVar45 >> 0x30) ^ (byte)(uVar57 >> 0x30) ^ bVar7,
                             CONCAT15((byte)(uVar45 >> 0x28) ^ (byte)(uVar57 >> 0x28) ^ auVar48[6],
                                      CONCAT14((byte)(uVar45 >> 0x20) ^ (byte)(uVar57 >> 0x20) ^
                                               auVar48[5],
                                               CONCAT13((byte)(uVar45 >> 0x18) ^
                                                        (byte)(uVar57 >> 0x18) ^ auVar48[4],
                                                        CONCAT12((byte)(uVar45 >> 0x10) ^
                                                                 (byte)(uVar57 >> 0x10) ^ auVar48[3]
                                                                 ,CONCAT11((byte)(uVar45 >> 8) ^
                                                                           (byte)(uVar57 >> 8) ^
                                                                           auVar48[2],
                                                                           (byte)uVar45 ^
                                                                           (byte)uVar57 ^ auVar48[1]
                                                                          )))))));
      auVar52[0xf] = bVar6 >> 7 ^ bVar6 >> 1 ^ auVar48[8] ^ (byte)((uVar56 << 0x3f) >> 0x38);
      lVar2 = uVar16 + lStack_38;
      auVar23._0_8_ = auVar23._0_8_ + auVar37._0_8_ + auVar40._0_8_ + auVar52._0_8_;
      auVar23._8_8_ = lVar33 + auVar37._8_8_ + auVar40._8_8_ + auVar52._8_8_;
      local_40 = plVar9[8] + auVar23._0_8_;
      lStack_38 = plVar9[9] + auVar23._8_8_;
      lVar2 = lVar2 + ((uVar13 >> 0xe | uVar13 << 0x32) ^ (uVar13 >> 0x12 | uVar13 << 0x2e) ^
                      (uVar13 >> 0x29 | uVar13 * 0x800000)) + ((uVar14 ^ uVar15) & uVar13 ^ uVar15);
      uVar12 = uVar12 + lVar2;
      uVar16 = lVar2 + ((uVar17 >> 0x1c | uVar17 << 0x24) ^ (uVar17 >> 0x22 | uVar17 * 0x40000000) ^
                       (uVar17 >> 0x27 | uVar17 * 0x2000000)) +
               ((uVar10 ^ uVar11) & uVar17 ^ uVar10 & uVar11);
      auVar37 = NEON_ext(auVar20,auVar21,8,1);
      auVar48 = NEON_ext(auVar24,auVar25,8,1);
      uVar29 = auVar23._0_8_ >> 0x13;
      uVar30 = auVar23._8_8_ >> 0x13;
      lVar31 = auVar23._0_8_ * 8;
      lVar34 = auVar23._8_8_ * 8;
      lVar33 = auVar24._8_8_;
      uVar36 = auVar23._0_8_ >> 6;
      lVar2 = uVar15 + local_30 +
              ((uVar12 >> 0xe | uVar12 << 0x32) ^ (uVar12 >> 0x12 | uVar12 << 0x2e) ^
              (uVar12 >> 0x29 | uVar12 * 0x800000)) + ((uVar13 ^ uVar14) & uVar12 ^ uVar14);
      uVar44 = auVar48._0_8_;
      uVar57 = uVar44 >> 1;
      uVar56 = auVar48._8_8_;
      uVar58 = uVar56 >> 1;
      uVar11 = uVar11 + lVar2;
      uVar45 = uVar44 >> 7;
      bVar4 = (byte)(auVar23._0_8_ >> 0x38);
      bVar5 = (byte)(auVar23._8_8_ >> 0x38);
      bVar7 = auVar48[7];
      bVar6 = auVar48[0xf];
      auVar41[9] = (byte)((auVar23._8_8_ >> 6) >> 8) ^ (byte)(uVar30 >> 8) ^
                   (byte)((ulong)lVar34 >> 8);
      auVar41[10] = (byte)((uint7)(auVar23._8_8_ >> 0xe) >> 8) ^ (byte)(uVar30 >> 0x10) ^
                    (byte)((ulong)lVar34 >> 0x10);
      auVar41[0xb] = (byte)((uint6)(auVar23._8_8_ >> 0x16) >> 8) ^ (byte)(uVar30 >> 0x18) ^
                     (byte)((ulong)lVar34 >> 0x18);
      auVar41[0xc] = (byte)((uint5)(auVar23._8_8_ >> 0x1e) >> 8) ^ (byte)(uVar30 >> 0x20) ^
                     (byte)((ulong)lVar34 >> 0x20);
      lVar32 = auVar23._0_8_ << 0x2d;
      lVar35 = auVar23._8_8_ << 0x2d;
      uVar15 = lVar2 + ((uVar16 >> 0x1c | uVar16 << 0x24) ^ (uVar16 >> 0x22 | uVar16 * 0x40000000) ^
                       (uVar16 >> 0x27 | uVar16 * 0x2000000)) +
               ((uVar17 ^ uVar10) & uVar16 ^ uVar17 & uVar10);
      auVar41[8] = (byte)(auVar23._8_8_ >> 6) ^ (byte)uVar30 ^ (byte)lVar34 ^ bVar5 >> 5;
      auVar53[8] = (byte)(uVar56 >> 7) ^ (byte)uVar58 ^ auVar48[9];
      auVar53[9] = (byte)((uVar56 >> 7) >> 8) ^ (byte)(uVar58 >> 8) ^ auVar48[10];
      auVar53[10] = (byte)((auVar48._9_7_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x10) ^ auVar48[0xb];
      auVar53[0xb] = (byte)((auVar48._10_6_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x18) ^ auVar48[0xc];
      auVar53[0xc] = (byte)((auVar48._11_5_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x20) ^ auVar48[0xd];
      auVar53[0xd] = (byte)((auVar48._12_4_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x28) ^ auVar48[0xe];
      auVar53[0xe] = (byte)((uint3)(auVar48._13_3_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x30) ^ bVar6;
      auVar41._0_8_ =
           CONCAT17(bVar4 >> 6 ^ (byte)((ulong)lVar31 >> 0x38) ^ (byte)((ulong)lVar32 >> 0x38),
                    CONCAT16((byte)(uVar36 >> 0x30) ^ (byte)((ulong)lVar31 >> 0x30) ^
                             (byte)((ulong)lVar32 >> 0x30),
                             CONCAT15((byte)(uVar36 >> 0x28) ^ bVar4 >> 3 ^
                                      (byte)((ulong)lVar31 >> 0x28) ^ (byte)((ulong)lVar32 >> 0x28),
                                      CONCAT14((byte)(uVar36 >> 0x20) ^ (byte)(uVar29 >> 0x20) ^
                                               (byte)((ulong)lVar31 >> 0x20),
                                               CONCAT13((byte)(uVar36 >> 0x18) ^
                                                        (byte)(uVar29 >> 0x18) ^
                                                        (byte)((ulong)lVar31 >> 0x18),
                                                        CONCAT12((byte)(uVar36 >> 0x10) ^
                                                                 (byte)(uVar29 >> 0x10) ^
                                                                 (byte)((ulong)lVar31 >> 0x10),
                                                                 CONCAT11((byte)(uVar36 >> 8) ^
                                                                          (byte)(uVar29 >> 8) ^
                                                                          (byte)((ulong)lVar31 >> 8)
                                                                          ,(byte)uVar36 ^
                                                                           (byte)uVar29 ^
                                                                           (byte)lVar31 ^ bVar4 >> 5
                                                                         )))))));
      auVar41[0xd] = (byte)((uint)(auVar23._8_8_ >> 0x26) >> 8) ^ bVar5 >> 3 ^
                     (byte)((ulong)lVar34 >> 0x28) ^ (byte)((ulong)lVar35 >> 0x28);
      auVar41[0xe] = (byte)((uint3)(auVar23._8_8_ >> 0x2e) >> 8) ^ (byte)((ulong)lVar34 >> 0x30) ^
                     (byte)((ulong)lVar35 >> 0x30);
      auVar41[0xf] = bVar5 >> 6 ^ (byte)((ulong)lVar34 >> 0x38) ^ (byte)((ulong)lVar35 >> 0x38);
      auVar53._0_8_ =
           CONCAT17(bVar7 >> 7 ^ bVar7 >> 1 ^ auVar48[0] ^ (byte)((uVar44 << 0x3f) >> 0x38),
                    CONCAT16((byte)(uVar45 >> 0x30) ^ (byte)(uVar57 >> 0x30) ^ bVar7,
                             CONCAT15((byte)(uVar45 >> 0x28) ^ (byte)(uVar57 >> 0x28) ^ auVar48[6],
                                      CONCAT14((byte)(uVar45 >> 0x20) ^ (byte)(uVar57 >> 0x20) ^
                                               auVar48[5],
                                               CONCAT13((byte)(uVar45 >> 0x18) ^
                                                        (byte)(uVar57 >> 0x18) ^ auVar48[4],
                                                        CONCAT12((byte)(uVar45 >> 0x10) ^
                                                                 (byte)(uVar57 >> 0x10) ^ auVar48[3]
                                                                 ,CONCAT11((byte)(uVar45 >> 8) ^
                                                                           (byte)(uVar57 >> 8) ^
                                                                           auVar48[2],
                                                                           (byte)uVar45 ^
                                                                           (byte)uVar57 ^ auVar48[1]
                                                                          )))))));
      auVar53[0xf] = bVar6 >> 7 ^ bVar6 >> 1 ^ auVar48[8] ^ (byte)((uVar56 << 0x3f) >> 0x38);
      lVar2 = uVar14 + lStack_28;
      auVar24._0_8_ = auVar24._0_8_ + auVar37._0_8_ + auVar41._0_8_ + auVar53._0_8_;
      auVar24._8_8_ = lVar33 + auVar37._8_8_ + auVar41._8_8_ + auVar53._8_8_;
      local_30 = plVar9[10] + auVar24._0_8_;
      lStack_28 = plVar9[0xb] + auVar24._8_8_;
      lVar2 = lVar2 + ((uVar11 >> 0xe | uVar11 << 0x32) ^ (uVar11 >> 0x12 | uVar11 << 0x2e) ^
                      (uVar11 >> 0x29 | uVar11 * 0x800000)) + ((uVar12 ^ uVar13) & uVar11 ^ uVar13);
      uVar10 = uVar10 + lVar2;
      uVar14 = lVar2 + ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
                       (uVar15 >> 0x27 | uVar15 * 0x2000000)) +
               ((uVar16 ^ uVar17) & uVar15 ^ uVar16 & uVar17);
      auVar37 = NEON_ext(auVar21,auVar22,8,1);
      auVar48 = NEON_ext(auVar25,auVar27,8,1);
      uVar29 = auVar24._0_8_ >> 0x13;
      uVar30 = auVar24._8_8_ >> 0x13;
      lVar31 = auVar24._0_8_ * 8;
      lVar34 = auVar24._8_8_ * 8;
      lVar33 = auVar25._8_8_;
      uVar36 = auVar24._0_8_ >> 6;
      lVar2 = uVar13 + local_20 +
              ((uVar10 >> 0xe | uVar10 << 0x32) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
              (uVar10 >> 0x29 | uVar10 * 0x800000)) + ((uVar11 ^ uVar12) & uVar10 ^ uVar12);
      uVar44 = auVar48._0_8_;
      uVar57 = uVar44 >> 1;
      uVar56 = auVar48._8_8_;
      uVar58 = uVar56 >> 1;
      uVar17 = uVar17 + lVar2;
      uVar45 = uVar44 >> 7;
      bVar4 = (byte)(auVar24._0_8_ >> 0x38);
      bVar5 = (byte)(auVar24._8_8_ >> 0x38);
      bVar7 = auVar48[7];
      bVar6 = auVar48[0xf];
      auVar42[9] = (byte)((auVar24._8_8_ >> 6) >> 8) ^ (byte)(uVar30 >> 8) ^
                   (byte)((ulong)lVar34 >> 8);
      auVar42[10] = (byte)((uint7)(auVar24._8_8_ >> 0xe) >> 8) ^ (byte)(uVar30 >> 0x10) ^
                    (byte)((ulong)lVar34 >> 0x10);
      auVar42[0xb] = (byte)((uint6)(auVar24._8_8_ >> 0x16) >> 8) ^ (byte)(uVar30 >> 0x18) ^
                     (byte)((ulong)lVar34 >> 0x18);
      auVar42[0xc] = (byte)((uint5)(auVar24._8_8_ >> 0x1e) >> 8) ^ (byte)(uVar30 >> 0x20) ^
                     (byte)((ulong)lVar34 >> 0x20);
      lVar32 = auVar24._0_8_ << 0x2d;
      lVar35 = auVar24._8_8_ << 0x2d;
      uVar13 = lVar2 + ((uVar14 >> 0x1c | uVar14 << 0x24) ^ (uVar14 >> 0x22 | uVar14 * 0x40000000) ^
                       (uVar14 >> 0x27 | uVar14 * 0x2000000)) +
               ((uVar15 ^ uVar16) & uVar14 ^ uVar15 & uVar16);
      auVar42[8] = (byte)(auVar24._8_8_ >> 6) ^ (byte)uVar30 ^ (byte)lVar34 ^ bVar5 >> 5;
      auVar54[8] = (byte)(uVar56 >> 7) ^ (byte)uVar58 ^ auVar48[9];
      auVar54[9] = (byte)((uVar56 >> 7) >> 8) ^ (byte)(uVar58 >> 8) ^ auVar48[10];
      auVar54[10] = (byte)((auVar48._9_7_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x10) ^ auVar48[0xb];
      auVar54[0xb] = (byte)((auVar48._10_6_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x18) ^ auVar48[0xc];
      auVar54[0xc] = (byte)((auVar48._11_5_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x20) ^ auVar48[0xd];
      auVar54[0xd] = (byte)((auVar48._12_4_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x28) ^ auVar48[0xe];
      auVar54[0xe] = (byte)((uint3)(auVar48._13_3_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x30) ^ bVar6;
      auVar42._0_8_ =
           CONCAT17(bVar4 >> 6 ^ (byte)((ulong)lVar31 >> 0x38) ^ (byte)((ulong)lVar32 >> 0x38),
                    CONCAT16((byte)(uVar36 >> 0x30) ^ (byte)((ulong)lVar31 >> 0x30) ^
                             (byte)((ulong)lVar32 >> 0x30),
                             CONCAT15((byte)(uVar36 >> 0x28) ^ bVar4 >> 3 ^
                                      (byte)((ulong)lVar31 >> 0x28) ^ (byte)((ulong)lVar32 >> 0x28),
                                      CONCAT14((byte)(uVar36 >> 0x20) ^ (byte)(uVar29 >> 0x20) ^
                                               (byte)((ulong)lVar31 >> 0x20),
                                               CONCAT13((byte)(uVar36 >> 0x18) ^
                                                        (byte)(uVar29 >> 0x18) ^
                                                        (byte)((ulong)lVar31 >> 0x18),
                                                        CONCAT12((byte)(uVar36 >> 0x10) ^
                                                                 (byte)(uVar29 >> 0x10) ^
                                                                 (byte)((ulong)lVar31 >> 0x10),
                                                                 CONCAT11((byte)(uVar36 >> 8) ^
                                                                          (byte)(uVar29 >> 8) ^
                                                                          (byte)((ulong)lVar31 >> 8)
                                                                          ,(byte)uVar36 ^
                                                                           (byte)uVar29 ^
                                                                           (byte)lVar31 ^ bVar4 >> 5
                                                                         )))))));
      auVar42[0xd] = (byte)((uint)(auVar24._8_8_ >> 0x26) >> 8) ^ bVar5 >> 3 ^
                     (byte)((ulong)lVar34 >> 0x28) ^ (byte)((ulong)lVar35 >> 0x28);
      auVar42[0xe] = (byte)((uint3)(auVar24._8_8_ >> 0x2e) >> 8) ^ (byte)((ulong)lVar34 >> 0x30) ^
                     (byte)((ulong)lVar35 >> 0x30);
      auVar42[0xf] = bVar5 >> 6 ^ (byte)((ulong)lVar34 >> 0x38) ^ (byte)((ulong)lVar35 >> 0x38);
      auVar54._0_8_ =
           CONCAT17(bVar7 >> 7 ^ bVar7 >> 1 ^ auVar48[0] ^ (byte)((uVar44 << 0x3f) >> 0x38),
                    CONCAT16((byte)(uVar45 >> 0x30) ^ (byte)(uVar57 >> 0x30) ^ bVar7,
                             CONCAT15((byte)(uVar45 >> 0x28) ^ (byte)(uVar57 >> 0x28) ^ auVar48[6],
                                      CONCAT14((byte)(uVar45 >> 0x20) ^ (byte)(uVar57 >> 0x20) ^
                                               auVar48[5],
                                               CONCAT13((byte)(uVar45 >> 0x18) ^
                                                        (byte)(uVar57 >> 0x18) ^ auVar48[4],
                                                        CONCAT12((byte)(uVar45 >> 0x10) ^
                                                                 (byte)(uVar57 >> 0x10) ^ auVar48[3]
                                                                 ,CONCAT11((byte)(uVar45 >> 8) ^
                                                                           (byte)(uVar57 >> 8) ^
                                                                           auVar48[2],
                                                                           (byte)uVar45 ^
                                                                           (byte)uVar57 ^ auVar48[1]
                                                                          )))))));
      auVar54[0xf] = bVar6 >> 7 ^ bVar6 >> 1 ^ auVar48[8] ^ (byte)((uVar56 << 0x3f) >> 0x38);
      lVar2 = uVar12 + lStack_18;
      auVar25._0_8_ = auVar25._0_8_ + auVar37._0_8_ + auVar42._0_8_ + auVar54._0_8_;
      auVar25._8_8_ = lVar33 + auVar37._8_8_ + auVar42._8_8_ + auVar54._8_8_;
      local_20 = plVar9[0xc] + auVar25._0_8_;
      lStack_18 = plVar9[0xd] + auVar25._8_8_;
      lVar2 = lVar2 + ((uVar17 >> 0xe | uVar17 << 0x32) ^ (uVar17 >> 0x12 | uVar17 << 0x2e) ^
                      (uVar17 >> 0x29 | uVar17 * 0x800000)) + ((uVar10 ^ uVar11) & uVar17 ^ uVar11);
      uVar16 = uVar16 + lVar2;
      uVar12 = lVar2 + ((uVar13 >> 0x1c | uVar13 << 0x24) ^ (uVar13 >> 0x22 | uVar13 * 0x40000000) ^
                       (uVar13 >> 0x27 | uVar13 * 0x2000000)) +
               ((uVar14 ^ uVar15) & uVar13 ^ uVar14 & uVar15);
      auVar37 = NEON_ext(auVar22,auVar23,8,1);
      auVar27 = NEON_ext(auVar27,auVar19,8,1);
      uVar29 = auVar25._0_8_ >> 0x13;
      uVar30 = auVar25._8_8_ >> 0x13;
      lVar33 = auVar25._0_8_ * 8;
      lVar32 = auVar25._8_8_ * 8;
      uVar36 = auVar25._0_8_ >> 6;
      lVar2 = uVar11 + local_10 +
              ((uVar16 >> 0xe | uVar16 << 0x32) ^ (uVar16 >> 0x12 | uVar16 << 0x2e) ^
              (uVar16 >> 0x29 | uVar16 * 0x800000)) + ((uVar17 ^ uVar10) & uVar16 ^ uVar10);
      uVar44 = auVar27._0_8_;
      uVar57 = uVar44 >> 1;
      uVar56 = auVar27._8_8_;
      uVar58 = uVar56 >> 1;
      uVar15 = uVar15 + lVar2;
      uVar45 = uVar44 >> 7;
      bVar4 = (byte)(auVar25._0_8_ >> 0x38);
      bVar5 = (byte)(auVar25._8_8_ >> 0x38);
      bVar7 = auVar27[7];
      bVar6 = auVar27[0xf];
      auVar43[9] = (byte)((auVar25._8_8_ >> 6) >> 8) ^ (byte)(uVar30 >> 8) ^
                   (byte)((ulong)lVar32 >> 8);
      auVar43[10] = (byte)((uint7)(auVar25._8_8_ >> 0xe) >> 8) ^ (byte)(uVar30 >> 0x10) ^
                    (byte)((ulong)lVar32 >> 0x10);
      auVar43[0xb] = (byte)((uint6)(auVar25._8_8_ >> 0x16) >> 8) ^ (byte)(uVar30 >> 0x18) ^
                     (byte)((ulong)lVar32 >> 0x18);
      auVar43[0xc] = (byte)((uint5)(auVar25._8_8_ >> 0x1e) >> 8) ^ (byte)(uVar30 >> 0x20) ^
                     (byte)((ulong)lVar32 >> 0x20);
      lVar31 = auVar25._0_8_ << 0x2d;
      lVar34 = auVar25._8_8_ << 0x2d;
      uVar11 = lVar2 + ((uVar12 >> 0x1c | uVar12 << 0x24) ^ (uVar12 >> 0x22 | uVar12 * 0x40000000) ^
                       (uVar12 >> 0x27 | uVar12 * 0x2000000)) +
               ((uVar13 ^ uVar14) & uVar12 ^ uVar13 & uVar14);
      auVar43[8] = (byte)(auVar25._8_8_ >> 6) ^ (byte)uVar30 ^ (byte)lVar32 ^ bVar5 >> 5;
      auVar55[8] = (byte)(uVar56 >> 7) ^ (byte)uVar58 ^ auVar27[9];
      auVar55[9] = (byte)((uVar56 >> 7) >> 8) ^ (byte)(uVar58 >> 8) ^ auVar27[10];
      auVar55[10] = (byte)((auVar27._9_7_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x10) ^ auVar27[0xb];
      auVar55[0xb] = (byte)((auVar27._10_6_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x18) ^ auVar27[0xc];
      auVar55[0xc] = (byte)((auVar27._11_5_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x20) ^ auVar27[0xd];
      auVar55[0xd] = (byte)((auVar27._12_4_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x28) ^ auVar27[0xe];
      auVar55[0xe] = (byte)((uint3)(auVar27._13_3_ >> 7) >> 8) ^ (byte)(uVar58 >> 0x30) ^ bVar6;
      auVar43._0_8_ =
           CONCAT17(bVar4 >> 6 ^ (byte)((ulong)lVar33 >> 0x38) ^ (byte)((ulong)lVar31 >> 0x38),
                    CONCAT16((byte)(uVar36 >> 0x30) ^ (byte)((ulong)lVar33 >> 0x30) ^
                             (byte)((ulong)lVar31 >> 0x30),
                             CONCAT15((byte)(uVar36 >> 0x28) ^ bVar4 >> 3 ^
                                      (byte)((ulong)lVar33 >> 0x28) ^ (byte)((ulong)lVar31 >> 0x28),
                                      CONCAT14((byte)(uVar36 >> 0x20) ^ (byte)(uVar29 >> 0x20) ^
                                               (byte)((ulong)lVar33 >> 0x20),
                                               CONCAT13((byte)(uVar36 >> 0x18) ^
                                                        (byte)(uVar29 >> 0x18) ^
                                                        (byte)((ulong)lVar33 >> 0x18),
                                                        CONCAT12((byte)(uVar36 >> 0x10) ^
                                                                 (byte)(uVar29 >> 0x10) ^
                                                                 (byte)((ulong)lVar33 >> 0x10),
                                                                 CONCAT11((byte)(uVar36 >> 8) ^
                                                                          (byte)(uVar29 >> 8) ^
                                                                          (byte)((ulong)lVar33 >> 8)
                                                                          ,(byte)uVar36 ^
                                                                           (byte)uVar29 ^
                                                                           (byte)lVar33 ^ bVar4 >> 5
                                                                         )))))));
      auVar43[0xd] = (byte)((uint)(auVar25._8_8_ >> 0x26) >> 8) ^ bVar5 >> 3 ^
                     (byte)((ulong)lVar32 >> 0x28) ^ (byte)((ulong)lVar34 >> 0x28);
      auVar43[0xe] = (byte)((uint3)(auVar25._8_8_ >> 0x2e) >> 8) ^ (byte)((ulong)lVar32 >> 0x30) ^
                     (byte)((ulong)lVar34 >> 0x30);
      auVar43[0xf] = bVar5 >> 6 ^ (byte)((ulong)lVar32 >> 0x38) ^ (byte)((ulong)lVar34 >> 0x38);
      auVar55._0_8_ =
           CONCAT17(bVar7 >> 7 ^ bVar7 >> 1 ^ auVar27[0] ^ (byte)((uVar44 << 0x3f) >> 0x38),
                    CONCAT16((byte)(uVar45 >> 0x30) ^ (byte)(uVar57 >> 0x30) ^ bVar7,
                             CONCAT15((byte)(uVar45 >> 0x28) ^ (byte)(uVar57 >> 0x28) ^ auVar27[6],
                                      CONCAT14((byte)(uVar45 >> 0x20) ^ (byte)(uVar57 >> 0x20) ^
                                               auVar27[5],
                                               CONCAT13((byte)(uVar45 >> 0x18) ^
                                                        (byte)(uVar57 >> 0x18) ^ auVar27[4],
                                                        CONCAT12((byte)(uVar45 >> 0x10) ^
                                                                 (byte)(uVar57 >> 0x10) ^ auVar27[3]
                                                                 ,CONCAT11((byte)(uVar45 >> 8) ^
                                                                           (byte)(uVar57 >> 8) ^
                                                                           auVar27[2],
                                                                           (byte)uVar45 ^
                                                                           (byte)uVar57 ^ auVar27[1]
                                                                          )))))));
      auVar55[0xf] = bVar6 >> 7 ^ bVar6 >> 1 ^ auVar27[8] ^ (byte)((uVar56 << 0x3f) >> 0x38);
      lVar2 = uVar10 + lStack_8;
      auVar27._0_8_ = uVar26 + auVar37._0_8_ + auVar43._0_8_ + auVar55._0_8_;
      auVar27._8_8_ = uVar28 + auVar37._8_8_ + auVar43._8_8_ + auVar55._8_8_;
      local_10 = plVar9[0xe] + auVar27._0_8_;
      lStack_8 = plVar9[0xf] + auVar27._8_8_;
      lVar2 = lVar2 + ((uVar15 >> 0xe | uVar15 << 0x32) ^ (uVar15 >> 0x12 | uVar15 << 0x2e) ^
                      (uVar15 >> 0x29 | uVar15 * 0x800000)) + ((uVar16 ^ uVar17) & uVar15 ^ uVar17);
      uVar14 = uVar14 + lVar2;
      uVar10 = lVar2 + ((uVar11 >> 0x1c | uVar11 << 0x24) ^ (uVar11 >> 0x22 | uVar11 * 0x40000000) ^
                       (uVar11 >> 0x27 | uVar11 * 0x2000000)) +
               ((uVar12 ^ uVar13) & uVar11 ^ uVar12 & uVar13);
      iVar3 = iVar18 + -1;
      bVar1 = 0 < iVar18;
      plVar8 = plVar9 + 0x10;
      iVar18 = iVar3;
    } while (iVar3 != 0 && bVar1);
    param_2 = param_2 + -1;
    if (param_2 == 0) break;
    lVar2 = uVar17 + local_80 +
            ((uVar14 >> 0xe | uVar14 << 0x32) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
            (uVar14 >> 0x29 | uVar14 * 0x800000)) + ((uVar15 ^ uVar16) & uVar14 ^ uVar16);
    uVar13 = uVar13 + lVar2;
    uVar17 = lVar2 + ((uVar10 >> 0x1c | uVar10 << 0x24) ^ (uVar10 >> 0x22 | uVar10 * 0x40000000) ^
                     (uVar10 >> 0x27 | uVar10 * 0x2000000)) +
             ((uVar11 ^ uVar12) & uVar10 ^ uVar11 & uVar12);
    auVar19 = NEON_rev64(param_3[8],1);
    lVar2 = uVar16 + lStack_78 +
            ((uVar13 >> 0xe | uVar13 << 0x32) ^ (uVar13 >> 0x12 | uVar13 << 0x2e) ^
            (uVar13 >> 0x29 | uVar13 * 0x800000)) + ((uVar14 ^ uVar15) & uVar13 ^ uVar15);
    local_80 = plVar9[-0x40] + auVar19._0_8_;
    lStack_78 = plVar9[-0x3f] + auVar19._8_8_;
    uVar12 = uVar12 + lVar2;
    uVar16 = lVar2 + ((uVar17 >> 0x1c | uVar17 << 0x24) ^ (uVar17 >> 0x22 | uVar17 * 0x40000000) ^
                     (uVar17 >> 0x27 | uVar17 * 0x2000000)) +
             ((uVar10 ^ uVar11) & uVar17 ^ uVar10 & uVar11);
    lVar2 = uVar15 + local_70 +
            ((uVar12 >> 0xe | uVar12 << 0x32) ^ (uVar12 >> 0x12 | uVar12 << 0x2e) ^
            (uVar12 >> 0x29 | uVar12 * 0x800000)) + ((uVar13 ^ uVar14) & uVar12 ^ uVar14);
    uVar11 = uVar11 + lVar2;
    uVar15 = lVar2 + ((uVar16 >> 0x1c | uVar16 << 0x24) ^ (uVar16 >> 0x22 | uVar16 * 0x40000000) ^
                     (uVar16 >> 0x27 | uVar16 * 0x2000000)) +
             ((uVar17 ^ uVar10) & uVar16 ^ uVar17 & uVar10);
    auVar20 = NEON_rev64(param_3[9],1);
    lVar2 = uVar14 + lStack_68 +
            ((uVar11 >> 0xe | uVar11 << 0x32) ^ (uVar11 >> 0x12 | uVar11 << 0x2e) ^
            (uVar11 >> 0x29 | uVar11 * 0x800000)) + ((uVar12 ^ uVar13) & uVar11 ^ uVar13);
    local_70 = plVar9[-0x3e] + auVar20._0_8_;
    lStack_68 = plVar9[-0x3d] + auVar20._8_8_;
    uVar10 = uVar10 + lVar2;
    uVar14 = lVar2 + ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
                     (uVar15 >> 0x27 | uVar15 * 0x2000000)) +
             ((uVar16 ^ uVar17) & uVar15 ^ uVar16 & uVar17);
    lVar2 = uVar13 + local_60 +
            ((uVar10 >> 0xe | uVar10 << 0x32) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
            (uVar10 >> 0x29 | uVar10 * 0x800000)) + ((uVar11 ^ uVar12) & uVar10 ^ uVar12);
    uVar17 = uVar17 + lVar2;
    uVar13 = lVar2 + ((uVar14 >> 0x1c | uVar14 << 0x24) ^ (uVar14 >> 0x22 | uVar14 * 0x40000000) ^
                     (uVar14 >> 0x27 | uVar14 * 0x2000000)) +
             ((uVar15 ^ uVar16) & uVar14 ^ uVar15 & uVar16);
    auVar21 = NEON_rev64(param_3[10],1);
    lVar2 = uVar12 + lStack_58 +
            ((uVar17 >> 0xe | uVar17 << 0x32) ^ (uVar17 >> 0x12 | uVar17 << 0x2e) ^
            (uVar17 >> 0x29 | uVar17 * 0x800000)) + ((uVar10 ^ uVar11) & uVar17 ^ uVar11);
    local_60 = plVar9[-0x3c] + auVar21._0_8_;
    lStack_58 = plVar9[-0x3b] + auVar21._8_8_;
    uVar16 = uVar16 + lVar2;
    uVar12 = lVar2 + ((uVar13 >> 0x1c | uVar13 << 0x24) ^ (uVar13 >> 0x22 | uVar13 * 0x40000000) ^
                     (uVar13 >> 0x27 | uVar13 * 0x2000000)) +
             ((uVar14 ^ uVar15) & uVar13 ^ uVar14 & uVar15);
    lVar2 = uVar11 + local_50 +
            ((uVar16 >> 0xe | uVar16 << 0x32) ^ (uVar16 >> 0x12 | uVar16 << 0x2e) ^
            (uVar16 >> 0x29 | uVar16 * 0x800000)) + ((uVar17 ^ uVar10) & uVar16 ^ uVar10);
    uVar15 = uVar15 + lVar2;
    uVar11 = lVar2 + ((uVar12 >> 0x1c | uVar12 << 0x24) ^ (uVar12 >> 0x22 | uVar12 * 0x40000000) ^
                     (uVar12 >> 0x27 | uVar12 * 0x2000000)) +
             ((uVar13 ^ uVar14) & uVar12 ^ uVar13 & uVar14);
    auVar22 = NEON_rev64(param_3[0xb],1);
    lVar2 = uVar10 + lStack_48 +
            ((uVar15 >> 0xe | uVar15 << 0x32) ^ (uVar15 >> 0x12 | uVar15 << 0x2e) ^
            (uVar15 >> 0x29 | uVar15 * 0x800000)) + ((uVar16 ^ uVar17) & uVar15 ^ uVar17);
    local_50 = plVar9[-0x3a] + auVar22._0_8_;
    lStack_48 = plVar9[-0x39] + auVar22._8_8_;
    uVar14 = uVar14 + lVar2;
    uVar10 = lVar2 + ((uVar11 >> 0x1c | uVar11 << 0x24) ^ (uVar11 >> 0x22 | uVar11 * 0x40000000) ^
                     (uVar11 >> 0x27 | uVar11 * 0x2000000)) +
             ((uVar12 ^ uVar13) & uVar11 ^ uVar12 & uVar13);
    lVar2 = uVar17 + local_40 +
            ((uVar14 >> 0xe | uVar14 << 0x32) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
            (uVar14 >> 0x29 | uVar14 * 0x800000)) + ((uVar15 ^ uVar16) & uVar14 ^ uVar16);
    uVar13 = uVar13 + lVar2;
    uVar26 = lVar2 + ((uVar10 >> 0x1c | uVar10 << 0x24) ^ (uVar10 >> 0x22 | uVar10 * 0x40000000) ^
                     (uVar10 >> 0x27 | uVar10 * 0x2000000)) +
             ((uVar11 ^ uVar12) & uVar10 ^ uVar11 & uVar12);
    auVar23 = NEON_rev64(param_3[0xc],1);
    lVar2 = uVar16 + lStack_38 +
            ((uVar13 >> 0xe | uVar13 << 0x32) ^ (uVar13 >> 0x12 | uVar13 << 0x2e) ^
            (uVar13 >> 0x29 | uVar13 * 0x800000)) + ((uVar14 ^ uVar15) & uVar13 ^ uVar15);
    local_40 = plVar9[-0x38] + auVar23._0_8_;
    lStack_38 = plVar9[-0x37] + auVar23._8_8_;
    uVar12 = uVar12 + lVar2;
    uVar28 = lVar2 + ((uVar26 >> 0x1c | uVar26 << 0x24) ^ (uVar26 >> 0x22 | uVar26 * 0x40000000) ^
                     (uVar26 >> 0x27 | uVar26 * 0x2000000)) +
             ((uVar10 ^ uVar11) & uVar26 ^ uVar10 & uVar11);
    lVar2 = uVar15 + local_30 +
            ((uVar12 >> 0xe | uVar12 << 0x32) ^ (uVar12 >> 0x12 | uVar12 << 0x2e) ^
            (uVar12 >> 0x29 | uVar12 * 0x800000)) + ((uVar13 ^ uVar14) & uVar12 ^ uVar14);
    uVar11 = uVar11 + lVar2;
    uVar29 = lVar2 + ((uVar28 >> 0x1c | uVar28 << 0x24) ^ (uVar28 >> 0x22 | uVar28 * 0x40000000) ^
                     (uVar28 >> 0x27 | uVar28 * 0x2000000)) +
             ((uVar26 ^ uVar10) & uVar28 ^ uVar26 & uVar10);
    auVar24 = NEON_rev64(param_3[0xd],1);
    lVar2 = uVar14 + lStack_28 +
            ((uVar11 >> 0xe | uVar11 << 0x32) ^ (uVar11 >> 0x12 | uVar11 << 0x2e) ^
            (uVar11 >> 0x29 | uVar11 * 0x800000)) + ((uVar12 ^ uVar13) & uVar11 ^ uVar13);
    local_30 = plVar9[-0x36] + auVar24._0_8_;
    lStack_28 = plVar9[-0x35] + auVar24._8_8_;
    uVar10 = uVar10 + lVar2;
    uVar17 = lVar2 + ((uVar29 >> 0x1c | uVar29 << 0x24) ^ (uVar29 >> 0x22 | uVar29 * 0x40000000) ^
                     (uVar29 >> 0x27 | uVar29 * 0x2000000)) +
             ((uVar28 ^ uVar26) & uVar29 ^ uVar28 & uVar26);
    lVar2 = uVar13 + local_20 +
            ((uVar10 >> 0xe | uVar10 << 0x32) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
            (uVar10 >> 0x29 | uVar10 * 0x800000)) + ((uVar11 ^ uVar12) & uVar10 ^ uVar12);
    uVar26 = uVar26 + lVar2;
    uVar16 = lVar2 + ((uVar17 >> 0x1c | uVar17 << 0x24) ^ (uVar17 >> 0x22 | uVar17 * 0x40000000) ^
                     (uVar17 >> 0x27 | uVar17 * 0x2000000)) +
             ((uVar29 ^ uVar28) & uVar17 ^ uVar29 & uVar28);
    auVar25 = NEON_rev64(param_3[0xe],1);
    lVar2 = uVar12 + lStack_18 +
            ((uVar26 >> 0xe | uVar26 << 0x32) ^ (uVar26 >> 0x12 | uVar26 << 0x2e) ^
            (uVar26 >> 0x29 | uVar26 * 0x800000)) + ((uVar10 ^ uVar11) & uVar26 ^ uVar11);
    local_20 = plVar9[-0x34] + auVar25._0_8_;
    lStack_18 = plVar9[-0x33] + auVar25._8_8_;
    uVar28 = uVar28 + lVar2;
    uVar15 = lVar2 + ((uVar16 >> 0x1c | uVar16 << 0x24) ^ (uVar16 >> 0x22 | uVar16 * 0x40000000) ^
                     (uVar16 >> 0x27 | uVar16 * 0x2000000)) +
             ((uVar17 ^ uVar29) & uVar16 ^ uVar17 & uVar29);
    lVar2 = uVar11 + local_10 +
            ((uVar28 >> 0xe | uVar28 << 0x32) ^ (uVar28 >> 0x12 | uVar28 << 0x2e) ^
            (uVar28 >> 0x29 | uVar28 * 0x800000)) + ((uVar26 ^ uVar10) & uVar28 ^ uVar10);
    plVar8 = plVar9 + -0x30;
    uVar29 = uVar29 + lVar2;
    uVar14 = lVar2 + ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
                     (uVar15 >> 0x27 | uVar15 * 0x2000000)) +
             ((uVar16 ^ uVar17) & uVar15 ^ uVar16 & uVar17);
    auVar27 = NEON_rev64(param_3[0xf],1);
    lVar2 = uVar10 + lStack_8 +
            ((uVar29 >> 0xe | uVar29 << 0x32) ^ (uVar29 >> 0x12 | uVar29 << 0x2e) ^
            (uVar29 >> 0x29 | uVar29 * 0x800000)) + ((uVar28 ^ uVar26) & uVar29 ^ uVar26);
    local_10 = plVar9[-0x32] + auVar27._0_8_;
    lStack_8 = plVar9[-0x31] + auVar27._8_8_;
    *param_1 = *param_1 +
               lVar2 + ((uVar14 >> 0x1c | uVar14 << 0x24) ^ (uVar14 >> 0x22 | uVar14 * 0x40000000) ^
                       (uVar14 >> 0x27 | uVar14 * 0x2000000)) +
               ((uVar15 ^ uVar16) & uVar14 ^ uVar15 & uVar16);
    param_1[1] = param_1[1] + uVar14;
    param_1[2] = param_1[2] + uVar15;
    param_1[3] = param_1[3] + uVar16;
    param_1[4] = param_1[4] + uVar17 + lVar2;
    param_1[5] = param_1[5] + uVar29;
    param_1[6] = param_1[6] + uVar28;
    param_1[7] = param_1[7] + uVar26;
    param_3 = param_3 + 8;
  }
  lVar2 = uVar17 + local_80 +
          ((uVar14 >> 0xe | uVar14 << 0x32) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
          (uVar14 >> 0x29 | uVar14 * 0x800000)) + ((uVar15 ^ uVar16) & uVar14 ^ uVar16);
  uVar13 = uVar13 + lVar2;
  uVar17 = lVar2 + ((uVar10 >> 0x1c | uVar10 << 0x24) ^ (uVar10 >> 0x22 | uVar10 * 0x40000000) ^
                   (uVar10 >> 0x27 | uVar10 * 0x2000000)) +
           ((uVar11 ^ uVar12) & uVar10 ^ uVar11 & uVar12);
  lVar2 = uVar16 + lStack_78 +
          ((uVar13 >> 0xe | uVar13 << 0x32) ^ (uVar13 >> 0x12 | uVar13 << 0x2e) ^
          (uVar13 >> 0x29 | uVar13 * 0x800000)) + ((uVar14 ^ uVar15) & uVar13 ^ uVar15);
  uVar12 = uVar12 + lVar2;
  uVar16 = lVar2 + ((uVar17 >> 0x1c | uVar17 << 0x24) ^ (uVar17 >> 0x22 | uVar17 * 0x40000000) ^
                   (uVar17 >> 0x27 | uVar17 * 0x2000000)) +
           ((uVar10 ^ uVar11) & uVar17 ^ uVar10 & uVar11);
  lVar2 = uVar15 + local_70 +
          ((uVar12 >> 0xe | uVar12 << 0x32) ^ (uVar12 >> 0x12 | uVar12 << 0x2e) ^
          (uVar12 >> 0x29 | uVar12 * 0x800000)) + ((uVar13 ^ uVar14) & uVar12 ^ uVar14);
  uVar11 = uVar11 + lVar2;
  uVar15 = lVar2 + ((uVar16 >> 0x1c | uVar16 << 0x24) ^ (uVar16 >> 0x22 | uVar16 * 0x40000000) ^
                   (uVar16 >> 0x27 | uVar16 * 0x2000000)) +
           ((uVar17 ^ uVar10) & uVar16 ^ uVar17 & uVar10);
  lVar2 = uVar14 + lStack_68 +
          ((uVar11 >> 0xe | uVar11 << 0x32) ^ (uVar11 >> 0x12 | uVar11 << 0x2e) ^
          (uVar11 >> 0x29 | uVar11 * 0x800000)) + ((uVar12 ^ uVar13) & uVar11 ^ uVar13);
  uVar10 = uVar10 + lVar2;
  uVar14 = lVar2 + ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
                   (uVar15 >> 0x27 | uVar15 * 0x2000000)) +
           ((uVar16 ^ uVar17) & uVar15 ^ uVar16 & uVar17);
  lVar2 = uVar13 + local_60 +
          ((uVar10 >> 0xe | uVar10 << 0x32) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
          (uVar10 >> 0x29 | uVar10 * 0x800000)) + ((uVar11 ^ uVar12) & uVar10 ^ uVar12);
  uVar17 = uVar17 + lVar2;
  uVar13 = lVar2 + ((uVar14 >> 0x1c | uVar14 << 0x24) ^ (uVar14 >> 0x22 | uVar14 * 0x40000000) ^
                   (uVar14 >> 0x27 | uVar14 * 0x2000000)) +
           ((uVar15 ^ uVar16) & uVar14 ^ uVar15 & uVar16);
  lVar2 = uVar12 + lStack_58 +
          ((uVar17 >> 0xe | uVar17 << 0x32) ^ (uVar17 >> 0x12 | uVar17 << 0x2e) ^
          (uVar17 >> 0x29 | uVar17 * 0x800000)) + ((uVar10 ^ uVar11) & uVar17 ^ uVar11);
  uVar16 = uVar16 + lVar2;
  uVar12 = lVar2 + ((uVar13 >> 0x1c | uVar13 << 0x24) ^ (uVar13 >> 0x22 | uVar13 * 0x40000000) ^
                   (uVar13 >> 0x27 | uVar13 * 0x2000000)) +
           ((uVar14 ^ uVar15) & uVar13 ^ uVar14 & uVar15);
  lVar2 = uVar11 + local_50 +
          ((uVar16 >> 0xe | uVar16 << 0x32) ^ (uVar16 >> 0x12 | uVar16 << 0x2e) ^
          (uVar16 >> 0x29 | uVar16 * 0x800000)) + ((uVar17 ^ uVar10) & uVar16 ^ uVar10);
  uVar15 = uVar15 + lVar2;
  uVar11 = lVar2 + ((uVar12 >> 0x1c | uVar12 << 0x24) ^ (uVar12 >> 0x22 | uVar12 * 0x40000000) ^
                   (uVar12 >> 0x27 | uVar12 * 0x2000000)) +
           ((uVar13 ^ uVar14) & uVar12 ^ uVar13 & uVar14);
  lVar2 = uVar10 + lStack_48 +
          ((uVar15 >> 0xe | uVar15 << 0x32) ^ (uVar15 >> 0x12 | uVar15 << 0x2e) ^
          (uVar15 >> 0x29 | uVar15 * 0x800000)) + ((uVar16 ^ uVar17) & uVar15 ^ uVar17);
  uVar14 = uVar14 + lVar2;
  uVar10 = lVar2 + ((uVar11 >> 0x1c | uVar11 << 0x24) ^ (uVar11 >> 0x22 | uVar11 * 0x40000000) ^
                   (uVar11 >> 0x27 | uVar11 * 0x2000000)) +
           ((uVar12 ^ uVar13) & uVar11 ^ uVar12 & uVar13);
  lVar2 = uVar17 + local_40 +
          ((uVar14 >> 0xe | uVar14 << 0x32) ^ (uVar14 >> 0x12 | uVar14 << 0x2e) ^
          (uVar14 >> 0x29 | uVar14 * 0x800000)) + ((uVar15 ^ uVar16) & uVar14 ^ uVar16);
  uVar13 = uVar13 + lVar2;
  uVar26 = lVar2 + ((uVar10 >> 0x1c | uVar10 << 0x24) ^ (uVar10 >> 0x22 | uVar10 * 0x40000000) ^
                   (uVar10 >> 0x27 | uVar10 * 0x2000000)) +
           ((uVar11 ^ uVar12) & uVar10 ^ uVar11 & uVar12);
  lVar2 = uVar16 + lStack_38 +
          ((uVar13 >> 0xe | uVar13 << 0x32) ^ (uVar13 >> 0x12 | uVar13 << 0x2e) ^
          (uVar13 >> 0x29 | uVar13 * 0x800000)) + ((uVar14 ^ uVar15) & uVar13 ^ uVar15);
  uVar12 = uVar12 + lVar2;
  uVar28 = lVar2 + ((uVar26 >> 0x1c | uVar26 << 0x24) ^ (uVar26 >> 0x22 | uVar26 * 0x40000000) ^
                   (uVar26 >> 0x27 | uVar26 * 0x2000000)) +
           ((uVar10 ^ uVar11) & uVar26 ^ uVar10 & uVar11);
  lVar2 = uVar15 + local_30 +
          ((uVar12 >> 0xe | uVar12 << 0x32) ^ (uVar12 >> 0x12 | uVar12 << 0x2e) ^
          (uVar12 >> 0x29 | uVar12 * 0x800000)) + ((uVar13 ^ uVar14) & uVar12 ^ uVar14);
  uVar11 = uVar11 + lVar2;
  uVar29 = lVar2 + ((uVar28 >> 0x1c | uVar28 << 0x24) ^ (uVar28 >> 0x22 | uVar28 * 0x40000000) ^
                   (uVar28 >> 0x27 | uVar28 * 0x2000000)) +
           ((uVar26 ^ uVar10) & uVar28 ^ uVar26 & uVar10);
  lVar2 = uVar14 + lStack_28 +
          ((uVar11 >> 0xe | uVar11 << 0x32) ^ (uVar11 >> 0x12 | uVar11 << 0x2e) ^
          (uVar11 >> 0x29 | uVar11 * 0x800000)) + ((uVar12 ^ uVar13) & uVar11 ^ uVar13);
  uVar10 = uVar10 + lVar2;
  uVar17 = lVar2 + ((uVar29 >> 0x1c | uVar29 << 0x24) ^ (uVar29 >> 0x22 | uVar29 * 0x40000000) ^
                   (uVar29 >> 0x27 | uVar29 * 0x2000000)) +
           ((uVar28 ^ uVar26) & uVar29 ^ uVar28 & uVar26);
  lVar2 = uVar13 + local_20 +
          ((uVar10 >> 0xe | uVar10 << 0x32) ^ (uVar10 >> 0x12 | uVar10 << 0x2e) ^
          (uVar10 >> 0x29 | uVar10 * 0x800000)) + ((uVar11 ^ uVar12) & uVar10 ^ uVar12);
  uVar26 = uVar26 + lVar2;
  uVar16 = lVar2 + ((uVar17 >> 0x1c | uVar17 << 0x24) ^ (uVar17 >> 0x22 | uVar17 * 0x40000000) ^
                   (uVar17 >> 0x27 | uVar17 * 0x2000000)) +
           ((uVar29 ^ uVar28) & uVar17 ^ uVar29 & uVar28);
  lVar2 = uVar12 + lStack_18 +
          ((uVar26 >> 0xe | uVar26 << 0x32) ^ (uVar26 >> 0x12 | uVar26 << 0x2e) ^
          (uVar26 >> 0x29 | uVar26 * 0x800000)) + ((uVar10 ^ uVar11) & uVar26 ^ uVar11);
  uVar28 = uVar28 + lVar2;
  uVar15 = lVar2 + ((uVar16 >> 0x1c | uVar16 << 0x24) ^ (uVar16 >> 0x22 | uVar16 * 0x40000000) ^
                   (uVar16 >> 0x27 | uVar16 * 0x2000000)) +
           ((uVar17 ^ uVar29) & uVar16 ^ uVar17 & uVar29);
  lVar2 = uVar11 + local_10 +
          ((uVar28 >> 0xe | uVar28 << 0x32) ^ (uVar28 >> 0x12 | uVar28 << 0x2e) ^
          (uVar28 >> 0x29 | uVar28 * 0x800000)) + ((uVar26 ^ uVar10) & uVar28 ^ uVar10);
  uVar29 = uVar29 + lVar2;
  uVar14 = lVar2 + ((uVar15 >> 0x1c | uVar15 << 0x24) ^ (uVar15 >> 0x22 | uVar15 * 0x40000000) ^
                   (uVar15 >> 0x27 | uVar15 * 0x2000000)) +
           ((uVar16 ^ uVar17) & uVar15 ^ uVar16 & uVar17);
  lVar2 = uVar10 + lStack_8 +
          ((uVar29 >> 0xe | uVar29 << 0x32) ^ (uVar29 >> 0x12 | uVar29 << 0x2e) ^
          (uVar29 >> 0x29 | uVar29 * 0x800000)) + ((uVar28 ^ uVar26) & uVar29 ^ uVar26);
  *param_1 = *param_1 +
             lVar2 + ((uVar14 >> 0x1c | uVar14 << 0x24) ^ (uVar14 >> 0x22 | uVar14 * 0x40000000) ^
                     (uVar14 >> 0x27 | uVar14 * 0x2000000)) +
             ((uVar15 ^ uVar16) & uVar14 ^ uVar15 & uVar16);
  param_1[1] = param_1[1] + uVar14;
  param_1[2] = param_1[2] + uVar15;
  param_1[3] = param_1[3] + uVar16;
  param_1[4] = param_1[4] + uVar17 + lVar2;
  param_1[5] = param_1[5] + uVar29;
  param_1[6] = param_1[6] + uVar28;
  param_1[7] = param_1[7] + uVar26;
  return;
}

