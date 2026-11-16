// FUN_fffffff0270ab040 @ fffffff0270ab040 size=668
// CALLERS:
//   fffffff0270f3e1c FUN_fffffff0270f3d64@fffffff0270f3d64
// CALLEES:

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0270ab040
               (undefined1 (*param_1) [16],undefined1 (*param_2) [16],undefined1 (*param_3) [16],
               long param_4)

{
  long lVar1;
  undefined1 (*pauVar2) [16];
  long lVar3;
  long lVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  byte bVar20;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  byte bVar31;
  byte bVar32;
  byte bVar33;
  byte bVar34;
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  byte bVar35;
  byte bVar37;
  byte bVar38;
  byte bVar39;
  byte bVar40;
  byte bVar41;
  byte bVar42;
  byte bVar43;
  byte bVar44;
  byte bVar45;
  byte bVar46;
  byte bVar47;
  byte bVar48;
  byte bVar49;
  byte bVar50;
  undefined1 auVar36 [16];
  byte bVar51;
  byte bVar52;
  byte bVar54;
  byte bVar55;
  byte bVar56;
  byte bVar57;
  byte bVar58;
  byte bVar59;
  byte bVar60;
  byte bVar61;
  byte bVar62;
  byte bVar63;
  byte bVar64;
  byte bVar65;
  byte bVar66;
  byte bVar67;
  undefined1 auVar53 [16];
  byte bVar68;
  byte bVar70;
  byte bVar71;
  byte bVar72;
  byte bVar73;
  byte bVar74;
  byte bVar75;
  undefined1 auVar69 [16];
  byte bVar76;
  undefined1 auVar27 [16];
  
  auVar5 = a64_TBL(ZEXT816(0),*param_1,_DAT_fffffff0270ab300);
  while( true ) {
    lVar1 = param_4 + -0x80;
    if (param_4 < 0x80) break;
    auVar21 = a64_TBL(ZEXT816(0),param_3[7],_DAT_fffffff0270ab300);
    auVar6 = NEON_ext(auVar21,auVar21,8,1);
    auVar36 = NEON_pmull(SUB168(*param_2,0),auVar21._0_8_,8);
    auVar53 = NEON_pmull2(*param_2,auVar21,8);
    auVar69 = NEON_pmull(*(undefined8 *)param_2[8],
                         CONCAT17(auVar21[7] ^ auVar6[7],
                                  CONCAT16(auVar21[6] ^ auVar6[6],
                                           CONCAT15(auVar21[5] ^ auVar6[5],
                                                    CONCAT14(auVar21[4] ^ auVar6[4],
                                                             CONCAT13(auVar21[3] ^ auVar6[3],
                                                                      CONCAT12(auVar21[2] ^
                                                                               auVar6[2],
                                                                               CONCAT11(auVar21[1] ^
                                                                                        auVar6[1],
                                                                                        auVar21[0] ^
                                                                                        auVar6[0])))
                                                            )))),8);
    auVar21 = a64_TBL(ZEXT816(0),param_3[6],_DAT_fffffff0270ab300);
    auVar6 = NEON_ext(auVar21,auVar21,8,1);
    auVar13 = NEON_pmull(SUB168(param_2[1],0),auVar21._0_8_,8);
    auVar7 = NEON_pmull2(param_2[1],auVar21,8);
    auVar6 = NEON_pmull(*(undefined8 *)param_2[9],
                        CONCAT17(auVar21[7] ^ auVar6[7],
                                 CONCAT16(auVar21[6] ^ auVar6[6],
                                          CONCAT15(auVar21[5] ^ auVar6[5],
                                                   CONCAT14(auVar21[4] ^ auVar6[4],
                                                            CONCAT13(auVar21[3] ^ auVar6[3],
                                                                     CONCAT12(auVar21[2] ^ auVar6[2]
                                                                              ,CONCAT11(auVar21[1] ^
                                                                                        auVar6[1],
                                                                                        auVar21[0] ^
                                                                                        auVar6[0])))
                                                           )))),8);
    auVar22 = a64_TBL(ZEXT816(0),param_3[5],_DAT_fffffff0270ab300);
    auVar21 = NEON_ext(auVar22,auVar22,8,1);
    auVar14 = NEON_pmull(SUB168(param_2[2],0),auVar22._0_8_,8);
    auVar8 = NEON_pmull2(param_2[2],auVar22,8);
    auVar21 = NEON_pmull(*(undefined8 *)param_2[10],
                         CONCAT17(auVar22[7] ^ auVar21[7],
                                  CONCAT16(auVar22[6] ^ auVar21[6],
                                           CONCAT15(auVar22[5] ^ auVar21[5],
                                                    CONCAT14(auVar22[4] ^ auVar21[4],
                                                             CONCAT13(auVar22[3] ^ auVar21[3],
                                                                      CONCAT12(auVar22[2] ^
                                                                               auVar21[2],
                                                                               CONCAT11(auVar22[1] ^
                                                                                        auVar21[1],
                                                                                        auVar22[0] ^
                                                                                        auVar21[0]))
                                                                     ))))),8);
    auVar23 = a64_TBL(ZEXT816(0),param_3[4],_DAT_fffffff0270ab300);
    auVar22 = NEON_ext(auVar23,auVar23,8,1);
    auVar15 = NEON_pmull(SUB168(param_2[3],0),auVar23._0_8_,8);
    auVar9 = NEON_pmull2(param_2[3],auVar23,8);
    auVar22 = NEON_pmull(*(undefined8 *)param_2[0xb],
                         CONCAT17(auVar23[7] ^ auVar22[7],
                                  CONCAT16(auVar23[6] ^ auVar22[6],
                                           CONCAT15(auVar23[5] ^ auVar22[5],
                                                    CONCAT14(auVar23[4] ^ auVar22[4],
                                                             CONCAT13(auVar23[3] ^ auVar22[3],
                                                                      CONCAT12(auVar23[2] ^
                                                                               auVar22[2],
                                                                               CONCAT11(auVar23[1] ^
                                                                                        auVar22[1],
                                                                                        auVar23[0] ^
                                                                                        auVar22[0]))
                                                                     ))))),8);
    auVar24 = a64_TBL(ZEXT816(0),param_3[3],_DAT_fffffff0270ab300);
    auVar23 = NEON_ext(auVar24,auVar24,8,1);
    auVar16 = NEON_pmull(SUB168(param_2[4],0),auVar24._0_8_,8);
    auVar10 = NEON_pmull2(param_2[4],auVar24,8);
    auVar23 = NEON_pmull(*(undefined8 *)param_2[0xc],
                         CONCAT17(auVar24[7] ^ auVar23[7],
                                  CONCAT16(auVar24[6] ^ auVar23[6],
                                           CONCAT15(auVar24[5] ^ auVar23[5],
                                                    CONCAT14(auVar24[4] ^ auVar23[4],
                                                             CONCAT13(auVar24[3] ^ auVar23[3],
                                                                      CONCAT12(auVar24[2] ^
                                                                               auVar23[2],
                                                                               CONCAT11(auVar24[1] ^
                                                                                        auVar23[1],
                                                                                        auVar24[0] ^
                                                                                        auVar23[0]))
                                                                     ))))),8);
    auVar25 = a64_TBL(ZEXT816(0),param_3[2],_DAT_fffffff0270ab300);
    auVar24 = NEON_ext(auVar25,auVar25,8,1);
    auVar17 = NEON_pmull(SUB168(param_2[5],0),auVar25._0_8_,8);
    auVar11 = NEON_pmull2(param_2[5],auVar25,8);
    auVar24 = NEON_pmull(*(undefined8 *)param_2[0xd],
                         CONCAT17(auVar25[7] ^ auVar24[7],
                                  CONCAT16(auVar25[6] ^ auVar24[6],
                                           CONCAT15(auVar25[5] ^ auVar24[5],
                                                    CONCAT14(auVar25[4] ^ auVar24[4],
                                                             CONCAT13(auVar25[3] ^ auVar24[3],
                                                                      CONCAT12(auVar25[2] ^
                                                                               auVar24[2],
                                                                               CONCAT11(auVar25[1] ^
                                                                                        auVar24[1],
                                                                                        auVar25[0] ^
                                                                                        auVar24[0]))
                                                                     ))))),8);
    auVar26 = a64_TBL(ZEXT816(0),param_3[1],_DAT_fffffff0270ab300);
    auVar25 = NEON_ext(auVar26,auVar26,8,1);
    auVar18 = NEON_pmull(SUB168(param_2[6],0),auVar26._0_8_,8);
    auVar12 = NEON_pmull2(param_2[6],auVar26,8);
    auVar25 = NEON_pmull(*(undefined8 *)param_2[0xe],
                         CONCAT17(auVar26[7] ^ auVar25[7],
                                  CONCAT16(auVar26[6] ^ auVar25[6],
                                           CONCAT15(auVar26[5] ^ auVar25[5],
                                                    CONCAT14(auVar26[4] ^ auVar25[4],
                                                             CONCAT13(auVar26[3] ^ auVar25[3],
                                                                      CONCAT12(auVar26[2] ^
                                                                               auVar25[2],
                                                                               CONCAT11(auVar26[1] ^
                                                                                        auVar25[1],
                                                                                        auVar26[0] ^
                                                                                        auVar25[0]))
                                                                     ))))),8);
    auVar26 = a64_TBL(ZEXT816(0),*param_3,_DAT_fffffff0270ab300);
    bVar20 = auVar26[0] ^ auVar5[0];
    bVar28 = auVar26[1] ^ auVar5[1];
    bVar29 = auVar26[2] ^ auVar5[2];
    bVar30 = auVar26[3] ^ auVar5[3];
    bVar31 = auVar26[4] ^ auVar5[4];
    bVar32 = auVar26[5] ^ auVar5[5];
    bVar33 = auVar26[6] ^ auVar5[6];
    bVar34 = auVar26[7] ^ auVar5[7];
    auVar27._0_8_ =
         CONCAT17(bVar34,CONCAT16(bVar33,CONCAT15(bVar32,CONCAT14(bVar31,CONCAT13(bVar30,CONCAT12(
                                                  bVar29,CONCAT11(bVar28,bVar20)))))));
    auVar27[8] = auVar26[8] ^ auVar5[8];
    auVar27[9] = auVar26[9] ^ auVar5[9];
    auVar27[10] = auVar26[10] ^ auVar5[10];
    auVar27[0xb] = auVar26[0xb] ^ auVar5[0xb];
    auVar27[0xc] = auVar26[0xc] ^ auVar5[0xc];
    auVar27[0xd] = auVar26[0xd] ^ auVar5[0xd];
    auVar27[0xe] = auVar26[0xe] ^ auVar5[0xe];
    auVar27[0xf] = auVar26[0xf] ^ auVar5[0xf];
    auVar5 = NEON_ext(auVar27,auVar27,8,1);
    auVar19 = NEON_pmull(SUB168(param_2[7],0),auVar27._0_8_,8);
    auVar26 = NEON_pmull2(param_2[7],auVar27,8);
    bVar35 = auVar36[0] ^ auVar13[0] ^ auVar14[0] ^ auVar15[0] ^ auVar16[0] ^ auVar17[0] ^
             auVar18[0] ^ auVar19[0];
    bVar37 = auVar36[1] ^ auVar13[1] ^ auVar14[1] ^ auVar15[1] ^ auVar16[1] ^ auVar17[1] ^
             auVar18[1] ^ auVar19[1];
    bVar38 = auVar36[2] ^ auVar13[2] ^ auVar14[2] ^ auVar15[2] ^ auVar16[2] ^ auVar17[2] ^
             auVar18[2] ^ auVar19[2];
    bVar39 = auVar36[3] ^ auVar13[3] ^ auVar14[3] ^ auVar15[3] ^ auVar16[3] ^ auVar17[3] ^
             auVar18[3] ^ auVar19[3];
    bVar40 = auVar36[4] ^ auVar13[4] ^ auVar14[4] ^ auVar15[4] ^ auVar16[4] ^ auVar17[4] ^
             auVar18[4] ^ auVar19[4];
    bVar41 = auVar36[5] ^ auVar13[5] ^ auVar14[5] ^ auVar15[5] ^ auVar16[5] ^ auVar17[5] ^
             auVar18[5] ^ auVar19[5];
    bVar42 = auVar36[6] ^ auVar13[6] ^ auVar14[6] ^ auVar15[6] ^ auVar16[6] ^ auVar17[6] ^
             auVar18[6] ^ auVar19[6];
    bVar43 = auVar36[7] ^ auVar13[7] ^ auVar14[7] ^ auVar15[7] ^ auVar16[7] ^ auVar17[7] ^
             auVar18[7] ^ auVar19[7];
    bVar44 = auVar36[8] ^ auVar13[8] ^ auVar14[8] ^ auVar15[8] ^ auVar16[8] ^ auVar17[8] ^
             auVar18[8] ^ auVar19[8];
    bVar45 = auVar36[9] ^ auVar13[9] ^ auVar14[9] ^ auVar15[9] ^ auVar16[9] ^ auVar17[9] ^
             auVar18[9] ^ auVar19[9];
    bVar46 = auVar36[10] ^ auVar13[10] ^ auVar14[10] ^ auVar15[10] ^ auVar16[10] ^ auVar17[10] ^
             auVar18[10] ^ auVar19[10];
    bVar47 = auVar36[0xb] ^ auVar13[0xb] ^ auVar14[0xb] ^ auVar15[0xb] ^ auVar16[0xb] ^ auVar17[0xb]
             ^ auVar18[0xb] ^ auVar19[0xb];
    bVar48 = auVar36[0xc] ^ auVar13[0xc] ^ auVar14[0xc] ^ auVar15[0xc] ^ auVar16[0xc] ^ auVar17[0xc]
             ^ auVar18[0xc] ^ auVar19[0xc];
    bVar49 = auVar36[0xd] ^ auVar13[0xd] ^ auVar14[0xd] ^ auVar15[0xd] ^ auVar16[0xd] ^ auVar17[0xd]
             ^ auVar18[0xd] ^ auVar19[0xd];
    bVar50 = auVar36[0xe] ^ auVar13[0xe] ^ auVar14[0xe] ^ auVar15[0xe] ^ auVar16[0xe] ^ auVar17[0xe]
             ^ auVar18[0xe] ^ auVar19[0xe];
    bVar51 = auVar36[0xf] ^ auVar13[0xf] ^ auVar14[0xf] ^ auVar15[0xf] ^ auVar16[0xf] ^ auVar17[0xf]
             ^ auVar18[0xf] ^ auVar19[0xf];
    bVar52 = auVar53[0] ^ auVar7[0] ^ auVar8[0] ^ auVar9[0] ^ auVar10[0] ^ auVar11[0] ^ auVar12[0] ^
             auVar26[0];
    bVar54 = auVar53[1] ^ auVar7[1] ^ auVar8[1] ^ auVar9[1] ^ auVar10[1] ^ auVar11[1] ^ auVar12[1] ^
             auVar26[1];
    bVar55 = auVar53[2] ^ auVar7[2] ^ auVar8[2] ^ auVar9[2] ^ auVar10[2] ^ auVar11[2] ^ auVar12[2] ^
             auVar26[2];
    bVar56 = auVar53[3] ^ auVar7[3] ^ auVar8[3] ^ auVar9[3] ^ auVar10[3] ^ auVar11[3] ^ auVar12[3] ^
             auVar26[3];
    bVar57 = auVar53[4] ^ auVar7[4] ^ auVar8[4] ^ auVar9[4] ^ auVar10[4] ^ auVar11[4] ^ auVar12[4] ^
             auVar26[4];
    bVar58 = auVar53[5] ^ auVar7[5] ^ auVar8[5] ^ auVar9[5] ^ auVar10[5] ^ auVar11[5] ^ auVar12[5] ^
             auVar26[5];
    bVar59 = auVar53[6] ^ auVar7[6] ^ auVar8[6] ^ auVar9[6] ^ auVar10[6] ^ auVar11[6] ^ auVar12[6] ^
             auVar26[6];
    bVar60 = auVar53[7] ^ auVar7[7] ^ auVar8[7] ^ auVar9[7] ^ auVar10[7] ^ auVar11[7] ^ auVar12[7] ^
             auVar26[7];
    bVar61 = auVar53[8] ^ auVar7[8] ^ auVar8[8] ^ auVar9[8] ^ auVar10[8] ^ auVar11[8] ^ auVar12[8] ^
             auVar26[8];
    bVar62 = auVar53[9] ^ auVar7[9] ^ auVar8[9] ^ auVar9[9] ^ auVar10[9] ^ auVar11[9] ^ auVar12[9] ^
             auVar26[9];
    bVar63 = auVar53[10] ^ auVar7[10] ^ auVar8[10] ^ auVar9[10] ^ auVar10[10] ^ auVar11[10] ^
             auVar12[10] ^ auVar26[10];
    bVar64 = auVar53[0xb] ^ auVar7[0xb] ^ auVar8[0xb] ^ auVar9[0xb] ^ auVar10[0xb] ^ auVar11[0xb] ^
             auVar12[0xb] ^ auVar26[0xb];
    bVar65 = auVar53[0xc] ^ auVar7[0xc] ^ auVar8[0xc] ^ auVar9[0xc] ^ auVar10[0xc] ^ auVar11[0xc] ^
             auVar12[0xc] ^ auVar26[0xc];
    bVar66 = auVar53[0xd] ^ auVar7[0xd] ^ auVar8[0xd] ^ auVar9[0xd] ^ auVar10[0xd] ^ auVar11[0xd] ^
             auVar12[0xd] ^ auVar26[0xd];
    bVar67 = auVar53[0xe] ^ auVar7[0xe] ^ auVar8[0xe] ^ auVar9[0xe] ^ auVar10[0xe] ^ auVar11[0xe] ^
             auVar12[0xe] ^ auVar26[0xe];
    bVar68 = auVar53[0xf] ^ auVar7[0xf] ^ auVar8[0xf] ^ auVar9[0xf] ^ auVar10[0xf] ^ auVar11[0xf] ^
             auVar12[0xf] ^ auVar26[0xf];
    auVar5 = NEON_pmull(*(undefined8 *)param_2[0xf],
                        CONCAT17(bVar34 ^ auVar5[7],
                                 CONCAT16(bVar33 ^ auVar5[6],
                                          CONCAT15(bVar32 ^ auVar5[5],
                                                   CONCAT14(bVar31 ^ auVar5[4],
                                                            CONCAT13(bVar30 ^ auVar5[3],
                                                                     CONCAT12(bVar29 ^ auVar5[2],
                                                                              CONCAT11(bVar28 ^ 
                                                  auVar5[1],bVar20 ^ auVar5[0]))))))),8);
    auVar7[0] = bVar52 ^ bVar35 ^ auVar69[0] ^ auVar6[0] ^ auVar21[0] ^ auVar22[0] ^ auVar23[0] ^
                                  auVar24[0] ^ auVar25[0] ^ auVar5[0];
    auVar7[1] = bVar54 ^ bVar37 ^ auVar69[1] ^ auVar6[1] ^ auVar21[1] ^ auVar22[1] ^ auVar23[1] ^
                                  auVar24[1] ^ auVar25[1] ^ auVar5[1];
    auVar7[2] = bVar55 ^ bVar38 ^ auVar69[2] ^ auVar6[2] ^ auVar21[2] ^ auVar22[2] ^ auVar23[2] ^
                                  auVar24[2] ^ auVar25[2] ^ auVar5[2];
    auVar7[3] = bVar56 ^ bVar39 ^ auVar69[3] ^ auVar6[3] ^ auVar21[3] ^ auVar22[3] ^ auVar23[3] ^
                                  auVar24[3] ^ auVar25[3] ^ auVar5[3];
    auVar7[4] = bVar57 ^ bVar40 ^ auVar69[4] ^ auVar6[4] ^ auVar21[4] ^ auVar22[4] ^ auVar23[4] ^
                                  auVar24[4] ^ auVar25[4] ^ auVar5[4];
    auVar7[5] = bVar58 ^ bVar41 ^ auVar69[5] ^ auVar6[5] ^ auVar21[5] ^ auVar22[5] ^ auVar23[5] ^
                                  auVar24[5] ^ auVar25[5] ^ auVar5[5];
    auVar7[6] = bVar59 ^ bVar42 ^ auVar69[6] ^ auVar6[6] ^ auVar21[6] ^ auVar22[6] ^ auVar23[6] ^
                                  auVar24[6] ^ auVar25[6] ^ auVar5[6];
    auVar7[7] = bVar60 ^ bVar43 ^ auVar69[7] ^ auVar6[7] ^ auVar21[7] ^ auVar22[7] ^ auVar23[7] ^
                                  auVar24[7] ^ auVar25[7] ^ auVar5[7];
    auVar7[8] = bVar61 ^ bVar44 ^ auVar69[8] ^ auVar6[8] ^ auVar21[8] ^ auVar22[8] ^ auVar23[8] ^
                                  auVar24[8] ^ auVar25[8] ^ auVar5[8];
    auVar7[9] = bVar62 ^ bVar45 ^ auVar69[9] ^ auVar6[9] ^ auVar21[9] ^ auVar22[9] ^ auVar23[9] ^
                                  auVar24[9] ^ auVar25[9] ^ auVar5[9];
    auVar7[10] = bVar63 ^ bVar46 ^ auVar69[10] ^ auVar6[10] ^ auVar21[10] ^ auVar22[10] ^
                                   auVar23[10] ^ auVar24[10] ^ auVar25[10] ^ auVar5[10];
    auVar7[0xb] = bVar64 ^ bVar47 ^ auVar69[0xb] ^ auVar6[0xb] ^ auVar21[0xb] ^ auVar22[0xb] ^
                                    auVar23[0xb] ^ auVar24[0xb] ^ auVar25[0xb] ^ auVar5[0xb];
    auVar7[0xc] = bVar65 ^ bVar48 ^ auVar69[0xc] ^ auVar6[0xc] ^ auVar21[0xc] ^ auVar22[0xc] ^
                                    auVar23[0xc] ^ auVar24[0xc] ^ auVar25[0xc] ^ auVar5[0xc];
    auVar7[0xd] = bVar66 ^ bVar49 ^ auVar69[0xd] ^ auVar6[0xd] ^ auVar21[0xd] ^ auVar22[0xd] ^
                                    auVar23[0xd] ^ auVar24[0xd] ^ auVar25[0xd] ^ auVar5[0xd];
    auVar7[0xe] = bVar67 ^ bVar50 ^ auVar69[0xe] ^ auVar6[0xe] ^ auVar21[0xe] ^ auVar22[0xe] ^
                                    auVar23[0xe] ^ auVar24[0xe] ^ auVar25[0xe] ^ auVar5[0xe];
    auVar7[0xf] = bVar68 ^ bVar51 ^ auVar69[0xf] ^ auVar6[0xf] ^ auVar21[0xf] ^ auVar22[0xf] ^
                                    auVar23[0xf] ^ auVar24[0xf] ^ auVar25[0xf] ^ auVar5[0xf];
    auVar5 = NEON_ext(ZEXT216(0),auVar7,8,1);
    auVar22 = NEON_ext(auVar7,ZEXT216(0),8,1);
    auVar6._0_8_ = CONCAT17(bVar43 ^ auVar5[7],
                            CONCAT16(bVar42 ^ auVar5[6],
                                     CONCAT15(bVar41 ^ auVar5[5],
                                              CONCAT14(bVar40 ^ auVar5[4],
                                                       CONCAT13(bVar39 ^ auVar5[3],
                                                                CONCAT12(bVar38 ^ auVar5[2],
                                                                         CONCAT11(bVar37 ^ auVar5[1]
                                                                                  ,bVar35 ^ auVar5[0
                                                  ])))))));
    auVar6[8] = bVar44 ^ auVar5[8];
    auVar6[9] = bVar45 ^ auVar5[9];
    auVar6[10] = bVar46 ^ auVar5[10];
    auVar6[0xb] = bVar47 ^ auVar5[0xb];
    auVar6[0xc] = bVar48 ^ auVar5[0xc];
    auVar6[0xd] = bVar49 ^ auVar5[0xd];
    auVar6[0xe] = bVar50 ^ auVar5[0xe];
    auVar6[0xf] = bVar51 ^ auVar5[0xf];
    auVar23 = NEON_pmull(_DAT_fffffff0270ab310,auVar6._0_8_,8);
    auVar5 = NEON_ext(auVar6,auVar6,8,1);
    auVar21._0_8_ =
         CONCAT17(auVar23[7] ^ auVar5[7],
                  CONCAT16(auVar23[6] ^ auVar5[6],
                           CONCAT15(auVar23[5] ^ auVar5[5],
                                    CONCAT14(auVar23[4] ^ auVar5[4],
                                             CONCAT13(auVar23[3] ^ auVar5[3],
                                                      CONCAT12(auVar23[2] ^ auVar5[2],
                                                               CONCAT11(auVar23[1] ^ auVar5[1],
                                                                        auVar23[0] ^ auVar5[0]))))))
                 );
    auVar21[8] = auVar23[8] ^ auVar5[8];
    auVar21[9] = auVar23[9] ^ auVar5[9];
    auVar21[10] = auVar23[10] ^ auVar5[10];
    auVar21[0xb] = auVar23[0xb] ^ auVar5[0xb];
    auVar21[0xc] = auVar23[0xc] ^ auVar5[0xc];
    auVar21[0xd] = auVar23[0xd] ^ auVar5[0xd];
    auVar21[0xe] = auVar23[0xe] ^ auVar5[0xe];
    auVar21[0xf] = auVar23[0xf] ^ auVar5[0xf];
    auVar23 = NEON_pmull(_DAT_fffffff0270ab310,auVar21._0_8_,8);
    auVar6 = NEON_ext(auVar21,auVar21,8,1);
    auVar5[0] = bVar52 ^ auVar22[0] ^ auVar23[0] ^ auVar6[0];
    auVar5[1] = bVar54 ^ auVar22[1] ^ auVar23[1] ^ auVar6[1];
    auVar5[2] = bVar55 ^ auVar22[2] ^ auVar23[2] ^ auVar6[2];
    auVar5[3] = bVar56 ^ auVar22[3] ^ auVar23[3] ^ auVar6[3];
    auVar5[4] = bVar57 ^ auVar22[4] ^ auVar23[4] ^ auVar6[4];
    auVar5[5] = bVar58 ^ auVar22[5] ^ auVar23[5] ^ auVar6[5];
    auVar5[6] = bVar59 ^ auVar22[6] ^ auVar23[6] ^ auVar6[6];
    auVar5[7] = bVar60 ^ auVar22[7] ^ auVar23[7] ^ auVar6[7];
    auVar5[8] = bVar61 ^ auVar22[8] ^ auVar23[8] ^ auVar6[8];
    auVar5[9] = bVar62 ^ auVar22[9] ^ auVar23[9] ^ auVar6[9];
    auVar5[10] = bVar63 ^ auVar22[10] ^ auVar23[10] ^ auVar6[10];
    auVar5[0xb] = bVar64 ^ auVar22[0xb] ^ auVar23[0xb] ^ auVar6[0xb];
    auVar5[0xc] = bVar65 ^ auVar22[0xc] ^ auVar23[0xc] ^ auVar6[0xc];
    auVar5[0xd] = bVar66 ^ auVar22[0xd] ^ auVar23[0xd] ^ auVar6[0xd];
    auVar5[0xe] = bVar67 ^ auVar22[0xe] ^ auVar23[0xe] ^ auVar6[0xe];
    auVar5[0xf] = bVar68 ^ auVar22[0xf] ^ auVar23[0xf] ^ auVar6[0xf];
    param_3 = param_3 + 8;
    param_4 = lVar1;
  }
  if (-0x71 < lVar1) {
    auVar6 = a64_TBL(ZEXT816(0),*param_3,_DAT_fffffff0270ab300);
    bVar20 = auVar5[0] ^ auVar6[0];
    bVar28 = auVar5[1] ^ auVar6[1];
    bVar29 = auVar5[2] ^ auVar6[2];
    bVar30 = auVar5[3] ^ auVar6[3];
    bVar31 = auVar5[4] ^ auVar6[4];
    bVar32 = auVar5[5] ^ auVar6[5];
    bVar33 = auVar5[6] ^ auVar6[6];
    bVar34 = auVar5[7] ^ auVar6[7];
    auVar25._0_8_ =
         CONCAT17(bVar34,CONCAT16(bVar33,CONCAT15(bVar32,CONCAT14(bVar31,CONCAT13(bVar30,CONCAT12(
                                                  bVar29,CONCAT11(bVar28,bVar20)))))));
    auVar25[8] = auVar5[8] ^ auVar6[8];
    auVar25[9] = auVar5[9] ^ auVar6[9];
    auVar25[10] = auVar5[10] ^ auVar6[10];
    auVar25[0xb] = auVar5[0xb] ^ auVar6[0xb];
    auVar25[0xc] = auVar5[0xc] ^ auVar6[0xc];
    auVar25[0xd] = auVar5[0xd] ^ auVar6[0xd];
    auVar25[0xe] = auVar5[0xe] ^ auVar6[0xe];
    auVar25[0xf] = auVar5[0xf] ^ auVar6[0xf];
    auVar5 = NEON_ext(auVar25,auVar25,8,1);
    auVar22 = NEON_pmull(auVar25._0_8_,SUB168(*(undefined1 (*) [16])(param_2[7] + lVar1),0),8);
    auVar23 = NEON_pmull2(auVar25,*(undefined1 (*) [16])(param_2[7] + lVar1),8);
    auVar24 = NEON_pmull(CONCAT17(bVar34 ^ auVar5[7],
                                  CONCAT16(bVar33 ^ auVar5[6],
                                           CONCAT15(bVar32 ^ auVar5[5],
                                                    CONCAT14(bVar31 ^ auVar5[4],
                                                             CONCAT13(bVar30 ^ auVar5[3],
                                                                      CONCAT12(bVar29 ^ auVar5[2],
                                                                               CONCAT11(bVar28 ^ 
                                                  auVar5[1],bVar20 ^ auVar5[0]))))))),
                         *(undefined8 *)((undefined1 (*) [16])(param_2[7] + lVar1))[8],8);
    pauVar2 = (undefined1 (*) [16])(param_2[7] + lVar1);
    lVar4 = param_4 + -0x20;
    lVar1 = param_4 + -0x10;
    while( true ) {
      lVar3 = lVar4;
      bVar20 = auVar22[0];
      bVar28 = auVar22[1];
      bVar29 = auVar22[2];
      bVar30 = auVar22[3];
      bVar31 = auVar22[4];
      bVar32 = auVar22[5];
      bVar33 = auVar22[6];
      bVar34 = auVar22[7];
      bVar35 = auVar22[8];
      bVar37 = auVar22[9];
      bVar38 = auVar22[10];
      bVar39 = auVar22[0xb];
      bVar40 = auVar22[0xc];
      bVar41 = auVar22[0xd];
      bVar42 = auVar22[0xe];
      bVar43 = auVar22[0xf];
      bVar44 = auVar23[0];
      bVar45 = auVar23[1];
      bVar46 = auVar23[2];
      bVar47 = auVar23[3];
      bVar48 = auVar23[4];
      bVar49 = auVar23[5];
      bVar50 = auVar23[6];
      bVar51 = auVar23[7];
      bVar52 = auVar23[8];
      bVar54 = auVar23[9];
      bVar55 = auVar23[10];
      bVar56 = auVar23[0xb];
      bVar57 = auVar23[0xc];
      bVar58 = auVar23[0xd];
      bVar59 = auVar23[0xe];
      bVar60 = auVar23[0xf];
      bVar61 = auVar24[1];
      bVar62 = auVar24[2];
      bVar63 = auVar24[3];
      bVar64 = auVar24[4];
      bVar65 = auVar24[5];
      bVar66 = auVar24[6];
      bVar67 = auVar24[7];
      bVar68 = auVar24[8];
      bVar70 = auVar24[9];
      bVar71 = auVar24[10];
      bVar72 = auVar24[0xb];
      bVar73 = auVar24[0xc];
      bVar74 = auVar24[0xd];
      bVar75 = auVar24[0xe];
      bVar76 = auVar24[0xf];
      if (lVar1 < 0x10) break;
      param_3 = param_3 + 1;
      auVar22 = a64_TBL(ZEXT816(0),*param_3,_DAT_fffffff0270ab300);
      auVar6 = NEON_ext(auVar22,auVar22,8,1);
      auVar5 = pauVar2[-1];
      auVar21 = NEON_pmull(auVar22._0_8_,auVar5._0_8_,8);
      auVar5 = NEON_pmull2(auVar22,auVar5,8);
      auVar6 = NEON_pmull(CONCAT17(auVar22[7] ^ auVar6[7],
                                   CONCAT16(auVar22[6] ^ auVar6[6],
                                            CONCAT15(auVar22[5] ^ auVar6[5],
                                                     CONCAT14(auVar22[4] ^ auVar6[4],
                                                              CONCAT13(auVar22[3] ^ auVar6[3],
                                                                       CONCAT12(auVar22[2] ^
                                                                                auVar6[2],
                                                                                CONCAT11(auVar22[1]
                                                                                         ^ auVar6[1]
                                                                                         ,auVar22[0]
                                                                                          ^ auVar6[0
                                                  ]))))))),*(undefined8 *)pauVar2[7],8);
      auVar22[0] = bVar20 ^ auVar21[0];
      auVar22[1] = bVar28 ^ auVar21[1];
      auVar22[2] = bVar29 ^ auVar21[2];
      auVar22[3] = bVar30 ^ auVar21[3];
      auVar22[4] = bVar31 ^ auVar21[4];
      auVar22[5] = bVar32 ^ auVar21[5];
      auVar22[6] = bVar33 ^ auVar21[6];
      auVar22[7] = bVar34 ^ auVar21[7];
      auVar22[8] = bVar35 ^ auVar21[8];
      auVar22[9] = bVar37 ^ auVar21[9];
      auVar22[10] = bVar38 ^ auVar21[10];
      auVar22[0xb] = bVar39 ^ auVar21[0xb];
      auVar22[0xc] = bVar40 ^ auVar21[0xc];
      auVar22[0xd] = bVar41 ^ auVar21[0xd];
      auVar22[0xe] = bVar42 ^ auVar21[0xe];
      auVar22[0xf] = bVar43 ^ auVar21[0xf];
      auVar23[0] = bVar44 ^ auVar5[0];
      auVar23[1] = bVar45 ^ auVar5[1];
      auVar23[2] = bVar46 ^ auVar5[2];
      auVar23[3] = bVar47 ^ auVar5[3];
      auVar23[4] = bVar48 ^ auVar5[4];
      auVar23[5] = bVar49 ^ auVar5[5];
      auVar23[6] = bVar50 ^ auVar5[6];
      auVar23[7] = bVar51 ^ auVar5[7];
      auVar23[8] = bVar52 ^ auVar5[8];
      auVar23[9] = bVar54 ^ auVar5[9];
      auVar23[10] = bVar55 ^ auVar5[10];
      auVar23[0xb] = bVar56 ^ auVar5[0xb];
      auVar23[0xc] = bVar57 ^ auVar5[0xc];
      auVar23[0xd] = bVar58 ^ auVar5[0xd];
      auVar23[0xe] = bVar59 ^ auVar5[0xe];
      auVar23[0xf] = bVar60 ^ auVar5[0xf];
      auVar24[0] = auVar24[0] ^ auVar6[0];
      auVar24[1] = bVar61 ^ auVar6[1];
      auVar24[2] = bVar62 ^ auVar6[2];
      auVar24[3] = bVar63 ^ auVar6[3];
      auVar24[4] = bVar64 ^ auVar6[4];
      auVar24[5] = bVar65 ^ auVar6[5];
      auVar24[6] = bVar66 ^ auVar6[6];
      auVar24[7] = bVar67 ^ auVar6[7];
      auVar24[8] = bVar68 ^ auVar6[8];
      auVar24[9] = bVar70 ^ auVar6[9];
      auVar24[10] = bVar71 ^ auVar6[10];
      auVar24[0xb] = bVar72 ^ auVar6[0xb];
      auVar24[0xc] = bVar73 ^ auVar6[0xc];
      auVar24[0xd] = bVar74 ^ auVar6[0xd];
      auVar24[0xe] = bVar75 ^ auVar6[0xe];
      auVar24[0xf] = bVar76 ^ auVar6[0xf];
      pauVar2 = pauVar2 + -1;
      lVar4 = lVar3 + -0x10;
      lVar1 = lVar3;
    }
    auVar10[0] = bVar44 ^ bVar20 ^ auVar24[0];
    auVar10[1] = bVar45 ^ bVar28 ^ bVar61;
    auVar10[2] = bVar46 ^ bVar29 ^ bVar62;
    auVar10[3] = bVar47 ^ bVar30 ^ bVar63;
    auVar10[4] = bVar48 ^ bVar31 ^ bVar64;
    auVar10[5] = bVar49 ^ bVar32 ^ bVar65;
    auVar10[6] = bVar50 ^ bVar33 ^ bVar66;
    auVar10[7] = bVar51 ^ bVar34 ^ bVar67;
    auVar10[8] = bVar52 ^ bVar35 ^ bVar68;
    auVar10[9] = bVar54 ^ bVar37 ^ bVar70;
    auVar10[10] = bVar55 ^ bVar38 ^ bVar71;
    auVar10[0xb] = bVar56 ^ bVar39 ^ bVar72;
    auVar10[0xc] = bVar57 ^ bVar40 ^ bVar73;
    auVar10[0xd] = bVar58 ^ bVar41 ^ bVar74;
    auVar10[0xe] = bVar59 ^ bVar42 ^ bVar75;
    auVar10[0xf] = bVar60 ^ bVar43 ^ bVar76;
    auVar5 = NEON_ext(ZEXT216(0),auVar10,8,1);
    auVar21 = NEON_ext(auVar10,ZEXT216(0),8,1);
    auVar8._0_8_ = CONCAT17(bVar34 ^ auVar5[7],
                            CONCAT16(bVar33 ^ auVar5[6],
                                     CONCAT15(bVar32 ^ auVar5[5],
                                              CONCAT14(bVar31 ^ auVar5[4],
                                                       CONCAT13(bVar30 ^ auVar5[3],
                                                                CONCAT12(bVar29 ^ auVar5[2],
                                                                         CONCAT11(bVar28 ^ auVar5[1]
                                                                                  ,bVar20 ^ auVar5[0
                                                  ])))))));
    auVar8[8] = bVar35 ^ auVar5[8];
    auVar8[9] = bVar37 ^ auVar5[9];
    auVar8[10] = bVar38 ^ auVar5[10];
    auVar8[0xb] = bVar39 ^ auVar5[0xb];
    auVar8[0xc] = bVar40 ^ auVar5[0xc];
    auVar8[0xd] = bVar41 ^ auVar5[0xd];
    auVar8[0xe] = bVar42 ^ auVar5[0xe];
    auVar8[0xf] = bVar43 ^ auVar5[0xf];
    auVar6 = NEON_pmull(_DAT_fffffff0270ab310,auVar8._0_8_,8);
    auVar5 = NEON_ext(auVar8,auVar8,8,1);
    auVar9._0_8_ = CONCAT17(auVar6[7] ^ auVar5[7],
                            CONCAT16(auVar6[6] ^ auVar5[6],
                                     CONCAT15(auVar6[5] ^ auVar5[5],
                                              CONCAT14(auVar6[4] ^ auVar5[4],
                                                       CONCAT13(auVar6[3] ^ auVar5[3],
                                                                CONCAT12(auVar6[2] ^ auVar5[2],
                                                                         CONCAT11(auVar6[1] ^
                                                                                  auVar5[1],
                                                                                  auVar6[0] ^
                                                                                  auVar5[0])))))));
    auVar9[8] = auVar6[8] ^ auVar5[8];
    auVar9[9] = auVar6[9] ^ auVar5[9];
    auVar9[10] = auVar6[10] ^ auVar5[10];
    auVar9[0xb] = auVar6[0xb] ^ auVar5[0xb];
    auVar9[0xc] = auVar6[0xc] ^ auVar5[0xc];
    auVar9[0xd] = auVar6[0xd] ^ auVar5[0xd];
    auVar9[0xe] = auVar6[0xe] ^ auVar5[0xe];
    auVar9[0xf] = auVar6[0xf] ^ auVar5[0xf];
    auVar22 = NEON_pmull(_DAT_fffffff0270ab310,auVar9._0_8_,8);
    auVar6 = NEON_ext(auVar9,auVar9,8,1);
    auVar5[0] = bVar44 ^ auVar21[0] ^ auVar22[0] ^ auVar6[0];
    auVar5[1] = bVar45 ^ auVar21[1] ^ auVar22[1] ^ auVar6[1];
    auVar5[2] = bVar46 ^ auVar21[2] ^ auVar22[2] ^ auVar6[2];
    auVar5[3] = bVar47 ^ auVar21[3] ^ auVar22[3] ^ auVar6[3];
    auVar5[4] = bVar48 ^ auVar21[4] ^ auVar22[4] ^ auVar6[4];
    auVar5[5] = bVar49 ^ auVar21[5] ^ auVar22[5] ^ auVar6[5];
    auVar5[6] = bVar50 ^ auVar21[6] ^ auVar22[6] ^ auVar6[6];
    auVar5[7] = bVar51 ^ auVar21[7] ^ auVar22[7] ^ auVar6[7];
    auVar5[8] = bVar52 ^ auVar21[8] ^ auVar22[8] ^ auVar6[8];
    auVar5[9] = bVar54 ^ auVar21[9] ^ auVar22[9] ^ auVar6[9];
    auVar5[10] = bVar55 ^ auVar21[10] ^ auVar22[10] ^ auVar6[10];
    auVar5[0xb] = bVar56 ^ auVar21[0xb] ^ auVar22[0xb] ^ auVar6[0xb];
    auVar5[0xc] = bVar57 ^ auVar21[0xc] ^ auVar22[0xc] ^ auVar6[0xc];
    auVar5[0xd] = bVar58 ^ auVar21[0xd] ^ auVar22[0xd] ^ auVar6[0xd];
    auVar5[0xe] = bVar59 ^ auVar21[0xe] ^ auVar22[0xe] ^ auVar6[0xe];
    auVar5[0xf] = bVar60 ^ auVar21[0xf] ^ auVar22[0xf] ^ auVar6[0xf];
  }
  auVar5 = a64_TBL(ZEXT816(0),auVar5,_DAT_fffffff0270ab300);
  *(int *)*param_1 = auVar5._0_4_;
  *(int *)(*param_1 + 4) = auVar5._4_4_;
  *(int *)(*param_1 + 8) = auVar5._8_4_;
  *(int *)(*param_1 + 0xc) = auVar5._12_4_;
  return;
}

