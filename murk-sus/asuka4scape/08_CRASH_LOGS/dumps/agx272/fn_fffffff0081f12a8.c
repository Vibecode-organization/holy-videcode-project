// FUN_fffffff0081f12a8 @ fffffff0081f12a8 size=624

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0081f12a8(long param_1,ulong param_2,uint param_3,uint *param_4)

{
  int iVar1;
  byte bVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined1 auVar20 [16];
  undefined8 uVar21;
  undefined8 uVar22;
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined8 uVar26;
  ulong uVar27;
  undefined8 *puVar28;
  uint *puVar29;
  undefined8 uVar30;
  uint uVar31;
  undefined4 *puVar32;
  byte bVar33;
  byte bVar34;
  byte bVar37;
  byte bVar38;
  byte bVar39;
  byte bVar40;
  byte bVar41;
  byte bVar42;
  uint uVar35;
  byte bVar43;
  byte bVar44;
  byte bVar45;
  byte bVar46;
  byte bVar47;
  byte bVar48;
  byte bVar49;
  byte bVar50;
  byte bVar51;
  byte bVar52;
  uint uVar53;
  byte bVar56;
  byte bVar57;
  byte bVar60;
  byte bVar61;
  byte bVar62;
  byte bVar63;
  undefined1 auVar54 [16];
  byte bVar58;
  byte bVar59;
  undefined1 auVar55 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  uint uVar68;
  uint uVar69;
  undefined1 auVar66 [16];
  uint uVar70;
  undefined1 auVar67 [16];
  byte bVar71;
  byte bVar72;
  byte bVar73;
  byte bVar74;
  byte bVar75;
  byte bVar76;
  byte bVar77;
  byte bVar78;
  byte bVar79;
  byte bVar80;
  byte bVar81;
  byte bVar82;
  byte bVar83;
  byte bVar84;
  byte bVar85;
  byte bVar86;
  byte bVar87;
  byte bVar88;
  byte bVar89;
  byte bVar90;
  byte bVar91;
  byte bVar92;
  undefined1 auVar36 [16];
  
  auVar25 = _DAT_fffffff007113cb0;
  auVar24 = _DAT_fffffff007113ca0;
  auVar23 = _DAT_fffffff007113c90;
  uVar22 = _UNK_fffffff007113c88;
  uVar21 = _DAT_fffffff007113c80;
  auVar20 = _DAT_fffffff007113c70;
  uVar19 = _UNK_fffffff0071138cc;
  uVar18 = _UNK_fffffff0071138c8;
  uVar17 = _UNK_fffffff0071138c4;
  uVar16 = _DAT_fffffff0071138c0;
  uVar15 = _UNK_fffffff0071138bc;
  uVar14 = _UNK_fffffff0071138b8;
  uVar13 = _UNK_fffffff0071138b4;
  uVar12 = _DAT_fffffff0071138b0;
  uVar11 = _UNK_fffffff0071138ac;
  uVar10 = _UNK_fffffff0071138a8;
  uVar9 = _UNK_fffffff0071138a4;
  uVar8 = _DAT_fffffff0071138a0;
  uVar7 = _UNK_fffffff00711389c;
  uVar6 = _UNK_fffffff007113898;
  uVar5 = _UNK_fffffff007113894;
  uVar4 = _DAT_fffffff007113890;
  uVar26 = 0;
  if ((param_2 != 0) && (param_4 != (uint *)0x0)) {
    if (param_3 < *(uint *)(param_1 + 0x1518)) {
      return 0;
    }
    if (*(uint *)(param_1 + 0x1518) == 0) {
      uVar53 = 0;
    }
    else {
      uVar27 = 0;
      do {
        puVar28 = (undefined8 *)(param_1 + 0x18U + uVar27 * 0x18);
        if (((param_1 + 0x18U ^ (ulong)puVar28) & 0xffc0000000000000) != 0) {
          puVar28 = (undefined8 *)((ulong)puVar28 & 0xffffffffffff | 0xc8a2000000000000);
        }
        bVar2 = *(byte *)(puVar28 + 1);
        puVar29 = (uint *)(param_2 + uVar27 * 0x20);
        if (((param_2 ^ (ulong)puVar29) & 0xffc0000000000000) != 0) {
          puVar29 = (uint *)((ulong)puVar29 & 0xffffffffffff | 0xc8a2000000000000);
        }
        if ((ulong)bVar2 == 1) {
          *(undefined1 *)puVar29 = 1;
          *(undefined8 *)(puVar29 + 2) = *puVar28;
          *(undefined1 *)(puVar29 + 4) = *(undefined1 *)((long)puVar28 + 0xc);
        }
        else {
          uVar53 = 0xff000001;
          if ((*(byte *)(param_1 + 0x1525) & 1) == 0) {
            uVar53 = 1;
          }
          if (*(byte *)((long)puVar28 + 10) < 0x10) {
            uVar35 = 0xff001803;
          }
          else {
            iVar1 = *(byte *)((long)puVar28 + 9) + 2;
            uVar31 = (uint)(*(byte *)((long)puVar28 + 10) >> 4);
            uVar35 = uVar31 + 3 & 0x1c;
            auVar66._4_4_ = iVar1;
            auVar66._0_4_ = iVar1;
            auVar66._8_4_ = iVar1;
            auVar66._12_4_ = iVar1;
            auVar64 = ZEXT416(uVar53);
            auVar54 = NEON_ushl(auVar20,auVar66,4);
            bVar33 = auVar54[0] | (byte)uVar21;
            bVar79 = auVar54[1];
            bVar37 = bVar79 | (byte)((ulong)uVar21 >> 8);
            bVar80 = auVar54[2];
            bVar39 = bVar80 | (byte)((ulong)uVar21 >> 0x10);
            bVar41 = auVar54[3] | (byte)((ulong)uVar21 >> 0x18);
            bVar81 = auVar54[4];
            bVar43 = bVar81 | (byte)((ulong)uVar21 >> 0x20);
            bVar82 = auVar54[5];
            bVar45 = bVar82 | (byte)((ulong)uVar21 >> 0x28);
            bVar83 = auVar54[6];
            bVar47 = bVar83 | (byte)((ulong)uVar21 >> 0x30);
            bVar84 = auVar54[7];
            bVar49 = bVar84 | (byte)((ulong)uVar21 >> 0x38);
            auVar65._0_8_ =
                 CONCAT17(bVar49,CONCAT16(bVar47,CONCAT15(bVar45,CONCAT14(bVar43,CONCAT13(bVar41,
                                                  CONCAT12(bVar39,CONCAT11(bVar37,bVar33)))))));
            auVar55[8] = auVar54[8];
            auVar65[8] = auVar55[8] | (byte)uVar22;
            auVar55[9] = auVar54[9];
            auVar65[9] = auVar55[9] | (byte)((ulong)uVar22 >> 8);
            auVar55[10] = auVar54[10];
            auVar65[10] = auVar55[10] | (byte)((ulong)uVar22 >> 0x10);
            auVar55[0xb] = auVar54[0xb];
            auVar65[0xb] = auVar55[0xb] | (byte)((ulong)uVar22 >> 0x18);
            auVar55[0xc] = auVar54[0xc];
            auVar65[0xc] = auVar55[0xc] | (byte)((ulong)uVar22 >> 0x20);
            auVar55[0xd] = auVar54[0xd];
            auVar65[0xd] = auVar55[0xd] | (byte)((ulong)uVar22 >> 0x28);
            auVar55[0xe] = auVar54[0xe];
            auVar65[0xe] = auVar55[0xe] | (byte)((ulong)uVar22 >> 0x30);
            auVar55[0xf] = auVar54[0xf];
            auVar65[0xf] = auVar55[0xf] | (byte)((ulong)uVar22 >> 0x38);
            bVar51 = auVar54[0] | (byte)uVar53;
            bVar58 = auVar54[3] | (byte)(uVar53 >> 0x18);
            auVar55._0_8_ =
                 CONCAT17(bVar84,CONCAT16(bVar83,CONCAT15(bVar82,CONCAT14(bVar81,CONCAT13(bVar58,
                                                  CONCAT12(bVar80,CONCAT11(bVar79,bVar51)))))));
            auVar54 = auVar65;
            uVar26 = uVar21;
            uVar30 = uVar22;
            uVar53 = uVar4;
            uVar68 = uVar5;
            uVar69 = uVar6;
            uVar70 = uVar7;
            if (uVar35 != 4) {
              auVar54 = NEON_ushl(auVar23,auVar66,4);
              bVar33 = auVar54[0] | bVar33;
              bVar37 = auVar54[1] | bVar37;
              bVar39 = auVar54[2] | bVar39;
              bVar41 = auVar54[3] | bVar41;
              bVar43 = auVar54[4] | bVar43;
              bVar45 = auVar54[5] | bVar45;
              bVar47 = auVar54[6] | bVar47;
              bVar49 = auVar54[7] | bVar49;
              bVar71 = auVar54[8] | auVar65[8];
              bVar72 = auVar54[9] | auVar65[9];
              bVar73 = auVar54[10] | auVar65[10];
              bVar74 = auVar54[0xb] | auVar65[0xb];
              bVar75 = auVar54[0xc] | auVar65[0xc];
              bVar76 = auVar54[0xd] | auVar65[0xd];
              bVar77 = auVar54[0xe] | auVar65[0xe];
              bVar78 = auVar54[0xf] | auVar65[0xf];
              bVar51 = auVar54[0] | bVar51;
              bVar79 = auVar54[1] | bVar79;
              bVar80 = auVar54[2] | bVar80;
              bVar58 = auVar54[3] | bVar58;
              bVar81 = auVar54[4] | bVar81;
              bVar82 = auVar54[5] | bVar82;
              bVar83 = auVar54[6] | bVar83;
              bVar84 = auVar54[7] | bVar84;
              bVar85 = auVar54[8] | auVar55[8];
              bVar86 = auVar54[9] | auVar55[9];
              bVar87 = auVar54[10] | auVar55[10];
              bVar88 = auVar54[0xb] | auVar55[0xb];
              bVar89 = auVar54[0xc] | auVar55[0xc];
              bVar90 = auVar54[0xd] | auVar55[0xd];
              bVar91 = auVar54[0xe] | auVar55[0xe];
              bVar92 = auVar54[0xf] | auVar55[0xf];
              if (uVar35 == 8) {
                auVar64._8_8_ = auVar55._8_8_;
                auVar64._0_8_ = auVar55._0_8_;
                auVar54[9] = bVar72;
                auVar54[8] = bVar71;
                auVar54[10] = bVar73;
                auVar54[0xb] = bVar74;
                auVar54[0xc] = bVar75;
                auVar54[0xd] = bVar76;
                auVar54[0xe] = bVar77;
                auVar54[0xf] = bVar78;
                auVar54[1] = bVar37;
                auVar54[0] = bVar33;
                auVar54[2] = bVar39;
                auVar54[3] = bVar41;
                auVar54[4] = bVar43;
                auVar54[5] = bVar45;
                auVar54[6] = bVar47;
                auVar54[7] = bVar49;
                auVar55[9] = bVar86;
                auVar55[8] = bVar85;
                auVar55[10] = bVar87;
                auVar55[0xb] = bVar88;
                auVar55[0xc] = bVar89;
                auVar55[0xd] = bVar90;
                auVar55[0xe] = bVar91;
                auVar55[0xf] = bVar92;
                auVar55[1] = bVar79;
                auVar55[0] = bVar51;
                auVar55[2] = bVar80;
                auVar55[3] = bVar58;
                auVar55[4] = bVar81;
                auVar55[5] = bVar82;
                auVar55[6] = bVar83;
                auVar55[7] = bVar84;
                uVar26 = auVar65._0_8_;
                uVar30 = auVar65._8_8_;
                uVar53 = uVar8;
                uVar68 = uVar9;
                uVar69 = uVar10;
                uVar70 = uVar11;
              }
              else {
                auVar54 = NEON_ushl(auVar24,auVar66,4);
                bVar34 = auVar54[0] | bVar33;
                bVar38 = auVar54[1] | bVar37;
                bVar40 = auVar54[2] | bVar39;
                bVar42 = auVar54[3] | bVar41;
                bVar44 = auVar54[4] | bVar43;
                bVar46 = auVar54[5] | bVar45;
                bVar48 = auVar54[6] | bVar47;
                bVar50 = auVar54[7] | bVar49;
                auVar36._0_8_ =
                     CONCAT17(bVar50,CONCAT16(bVar48,CONCAT15(bVar46,CONCAT14(bVar44,CONCAT13(bVar42
                                                  ,CONCAT12(bVar40,CONCAT11(bVar38,bVar34)))))));
                auVar36[8] = auVar54[8] | bVar71;
                auVar36[9] = auVar54[9] | bVar72;
                auVar36[10] = auVar54[10] | bVar73;
                auVar36[0xb] = auVar54[0xb] | bVar74;
                auVar36[0xc] = auVar54[0xc] | bVar75;
                auVar36[0xd] = auVar54[0xd] | bVar76;
                auVar36[0xe] = auVar54[0xe] | bVar77;
                auVar36[0xf] = auVar54[0xf] | bVar78;
                bVar52 = auVar54[0] | bVar51;
                bVar56 = auVar54[1] | bVar79;
                bVar57 = auVar54[2] | bVar80;
                bVar59 = auVar54[3] | bVar58;
                bVar60 = auVar54[4] | bVar81;
                bVar61 = auVar54[5] | bVar82;
                bVar62 = auVar54[6] | bVar83;
                bVar63 = auVar54[7] | bVar84;
                auVar55._0_8_ =
                     CONCAT17(bVar63,CONCAT16(bVar62,CONCAT15(bVar61,CONCAT14(bVar60,CONCAT13(bVar59
                                                  ,CONCAT12(bVar57,CONCAT11(bVar56,bVar52)))))));
                auVar55[8] = auVar54[8] | bVar85;
                auVar55[9] = auVar54[9] | bVar86;
                auVar55[10] = auVar54[10] | bVar87;
                auVar55[0xb] = auVar54[0xb] | bVar88;
                auVar55[0xc] = auVar54[0xc] | bVar89;
                auVar55[0xd] = auVar54[0xd] | bVar90;
                auVar55[0xe] = auVar54[0xe] | bVar91;
                auVar55[0xf] = auVar54[0xf] | bVar92;
                if (uVar35 == 0xc) {
                  auVar64[9] = bVar86;
                  auVar64[8] = bVar85;
                  auVar64[10] = bVar87;
                  auVar64[0xb] = bVar88;
                  auVar64[0xc] = bVar89;
                  auVar64[0xd] = bVar90;
                  auVar64[0xe] = bVar91;
                  auVar64[0xf] = bVar92;
                  auVar64[1] = bVar79;
                  auVar64[0] = bVar51;
                  auVar64[2] = bVar80;
                  auVar64[3] = bVar58;
                  auVar64[4] = bVar81;
                  auVar64[5] = bVar82;
                  auVar64[6] = bVar83;
                  auVar64[7] = bVar84;
                  auVar54 = auVar36;
                  uVar26 = CONCAT17(bVar49,CONCAT16(bVar47,CONCAT15(bVar45,CONCAT14(bVar43,CONCAT13(
                                                  bVar41,CONCAT12(bVar39,CONCAT11(bVar37,bVar33)))))
                                                  ));
                  uVar30 = CONCAT17(bVar78,CONCAT16(bVar77,CONCAT15(bVar76,CONCAT14(bVar75,CONCAT13(
                                                  bVar74,CONCAT12(bVar73,CONCAT11(bVar72,bVar71)))))
                                                  ));
                  uVar53 = uVar12;
                  uVar68 = uVar13;
                  uVar69 = uVar14;
                  uVar70 = uVar15;
                }
                else {
                  auVar65 = NEON_ushl(auVar25,auVar66,4);
                  auVar54[0] = auVar65[0] | bVar34;
                  auVar54[1] = auVar65[1] | bVar38;
                  auVar54[2] = auVar65[2] | bVar40;
                  auVar54[3] = auVar65[3] | bVar42;
                  auVar54[4] = auVar65[4] | bVar44;
                  auVar54[5] = auVar65[5] | bVar46;
                  auVar54[6] = auVar65[6] | bVar48;
                  auVar54[7] = auVar65[7] | bVar50;
                  auVar54[8] = auVar65[8] | auVar36[8];
                  auVar54[9] = auVar65[9] | auVar36[9];
                  auVar54[10] = auVar65[10] | auVar36[10];
                  auVar54[0xb] = auVar65[0xb] | auVar36[0xb];
                  auVar54[0xc] = auVar65[0xc] | auVar36[0xc];
                  auVar54[0xd] = auVar65[0xd] | auVar36[0xd];
                  auVar54[0xe] = auVar65[0xe] | auVar36[0xe];
                  auVar54[0xf] = auVar65[0xf] | auVar36[0xf];
                  auVar64._8_8_ = auVar55._8_8_;
                  auVar64._0_8_ = auVar55._0_8_;
                  auVar55[0] = auVar65[0] | bVar52;
                  auVar55[1] = auVar65[1] | bVar56;
                  auVar55[2] = auVar65[2] | bVar57;
                  auVar55[3] = auVar65[3] | bVar59;
                  auVar55[4] = auVar65[4] | bVar60;
                  auVar55[5] = auVar65[5] | bVar61;
                  auVar55[6] = auVar65[6] | bVar62;
                  auVar55[7] = auVar65[7] | bVar63;
                  auVar55[8] = auVar65[8] | auVar55[8];
                  auVar55[9] = auVar65[9] | auVar55[9];
                  auVar55[10] = auVar65[10] | auVar55[10];
                  auVar55[0xb] = auVar65[0xb] | auVar55[0xb];
                  auVar55[0xc] = auVar65[0xc] | auVar55[0xc];
                  auVar55[0xd] = auVar65[0xd] | auVar55[0xd];
                  auVar55[0xe] = auVar65[0xe] | auVar55[0xe];
                  auVar55[0xf] = auVar65[0xf] | auVar55[0xf];
                  uVar26 = auVar36._0_8_;
                  uVar30 = auVar36._8_8_;
                  uVar53 = uVar16;
                  uVar68 = uVar17;
                  uVar69 = uVar18;
                  uVar70 = uVar19;
                }
              }
            }
            uVar31 = uVar31 - 1;
            auVar67._0_4_ = -(uint)(uVar31 < uVar53);
            auVar67._4_4_ = -(uint)(uVar31 < uVar68);
            auVar67._8_4_ = -(uint)(uVar31 < uVar69);
            auVar67._12_4_ = -(uint)(uVar31 < uVar70);
            auVar3._8_8_ = uVar30;
            auVar3._0_8_ = uVar26;
            auVar54 = auVar54 ^ (auVar54 ^ auVar3) & auVar67;
            auVar55 = auVar55 ^ (auVar55 ^ auVar64) & auVar67;
            auVar65 = NEON_ext(auVar55,auVar55,8,1);
            uVar53 = CONCAT13(auVar55[3] | auVar65[3],
                              CONCAT12(auVar55[2] | auVar65[2],
                                       CONCAT11(auVar55[1] | auVar65[1],auVar55[0] | auVar65[0])));
            uVar53 = uVar53 | (uint)(CONCAT17(auVar55[7] | auVar65[7],
                                              CONCAT16(auVar55[6] | auVar65[6],
                                                       CONCAT15(auVar55[5] | auVar65[5],
                                                                CONCAT14(auVar55[4] | auVar65[4],
                                                                         uVar53)))) >> 0x20);
            auVar65 = NEON_ext(auVar54,auVar54,8,1);
            uVar35 = CONCAT13(auVar54[3] | auVar65[3],
                              CONCAT12(auVar54[2] | auVar65[2],
                                       CONCAT11(auVar54[1] | auVar65[1],auVar54[0] | auVar65[0])));
            uVar35 = uVar35 | (uint)(CONCAT17(auVar54[7] | auVar65[7],
                                              CONCAT16(auVar54[6] | auVar65[6],
                                                       CONCAT15(auVar54[5] | auVar65[5],
                                                                CONCAT14(auVar54[4] | auVar65[4],
                                                                         uVar35)))) >> 0x20);
          }
          puVar32 = *(undefined4 **)(*(long *)(*(long *)(param_1 + 8) + 0x40) + (ulong)bVar2 * 8);
          *(byte *)puVar29 = bVar2;
          *puVar29 = (uint)bVar2 | ((uint)puVar32[3] >> 2) << 8;
          puVar29[3] = uVar53;
          puVar29[4] = uVar35;
          if (*(long *)(puVar32 + 6) == 0) {
            uVar26 = 0;
          }
          else {
            uVar26 = *(undefined8 *)
                      (*(long *)(puVar32 + 6) + (ulong)*(byte *)((long)puVar28 + 9) * 8);
          }
          uVar30 = *puVar28;
          *(undefined8 *)(puVar29 + 1) = uVar26;
          uVar53 = puVar32[4];
          puVar29[5] = (uint)uVar30;
          puVar29[6] = uVar53;
          *(char *)(puVar29 + 7) = (char)*puVar32;
          *(byte *)((long)puVar29 + 0x1d) = *(byte *)((long)puVar28 + 10) >> 4;
          *(undefined1 *)((long)puVar29 + 0x1e) = *(undefined1 *)((long)puVar28 + 0xc);
        }
        uVar27 = uVar27 + 1;
        uVar53 = *(uint *)(param_1 + 0x1518);
      } while (uVar27 < uVar53);
    }
    *param_4 = uVar53;
    uVar26 = 1;
  }
  return uVar26;
}

