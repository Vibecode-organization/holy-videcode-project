// FUN_fffffff0081af724 @ fffffff0081af724 size=688

bool FUN_fffffff0081af724(long *param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 *puVar4;
  long *plVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auVar9 [16];
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  undefined8 uVar13;
  long lVar14;
  bool bVar15;
  int *piVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  long lVar20;
  int iVar21;
  ulong uVar22;
  uint uVar23;
  long lVar24;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  byte bVar31;
  byte bVar32;
  byte bVar33;
  byte bVar34;
  byte bVar35;
  byte bVar36;
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
  byte bVar51;
  byte bVar52;
  byte bVar53;
  byte bVar54;
  byte bVar55;
  byte bVar56;
  undefined8 uVar57;
  undefined8 uVar58;
  ulong local_80 [4];
  
  lVar24 = (ulong)param_2 * 8;
  puVar2 = (undefined8 *)(param_1[0xf] + (long)(int)lVar24);
  if (lVar24 != (int)lVar24) {
    puVar2 = (undefined8 *)(param_1[0xf] + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
  }
  piVar16 = (int *)*puVar2;
  iVar6 = *piVar16;
  if (iVar6 == 0) {
    uVar17 = (ulong)param_2;
    uVar7 = *(uint *)(param_1 + 9);
    if (uVar7 != 0) {
      uVar23 = 0;
      lVar24 = param_1[0x13];
      do {
        uVar1 = uVar23 + uVar7 * param_2;
        uVar3 = uVar7 - uVar23;
        if (0xff < (uVar1 & 0xff) + (uVar7 - uVar23)) {
          uVar3 = 0x100 - (uVar1 & 0xff);
        }
        puVar2 = (undefined8 *)(lVar24 + (ulong)(uVar1 >> 8) * 0x20);
        local_80[1] = 0;
        local_80[0] = 0;
        local_80[3] = 0;
        local_80[2] = 0;
        uVar8 = uVar3 - 0x40;
        if (uVar3 < 0x40) {
          uVar18 = 0;
          uVar8 = uVar3;
        }
        else {
          uVar18 = (ulong)((uVar8 >> 6) + 1);
          if (uVar8 < 0xc0) {
            uVar19 = 0;
LAB_fffffff0081af84c:
            lVar20 = ((ulong)(uVar8 >> 6) ^ 0xffffffffffffffff) + uVar19;
            do {
              iVar21 = (int)(uVar19 * 8);
              puVar4 = (undefined8 *)((long)local_80 + (long)iVar21);
              if (uVar19 * 8 - (long)iVar21 != 0) {
                puVar4 = (undefined8 *)
                         ((ulong)(local_80 + uVar19) & 0xffffffffffff | 0x2bad000000000000);
              }
              *puVar4 = 0xffffffffffffffff;
              uVar19 = uVar19 + 1;
              bVar15 = lVar20 != -1;
              lVar20 = lVar20 + 1;
            } while (bVar15);
          }
          else {
            lVar20 = 0;
            uVar19 = uVar18 & 0x7fffffc;
            uVar22 = uVar19;
            do {
              local_80[lVar20 + 1] = 0xffffffffffffffff;
              local_80[lVar20] = 0xffffffffffffffff;
              local_80[lVar20 + 3] = 0xffffffffffffffff;
              local_80[lVar20 + 2] = 0xffffffffffffffff;
              lVar20 = lVar20 + 4;
              uVar22 = uVar22 - 4;
            } while (uVar22 != 0);
            if (uVar19 != uVar18) goto LAB_fffffff0081af84c;
          }
          uVar8 = uVar3 & 0x3f;
        }
        if (uVar8 != 0) {
          local_80[uVar18] = local_80[uVar18] | -1L << ((ulong)uVar8 & 0x3f) ^ 0xffffffffffffffffU;
        }
        FUN_fffffff0081ad280(local_80);
        uVar13 = puVar2[1];
        uVar11 = *puVar2;
        uVar58 = puVar2[3];
        uVar57 = puVar2[2];
        bVar25 = (byte)uVar11 & ~(byte)local_80[0];
        bVar26 = (byte)((ulong)uVar11 >> 8) & ~(byte)(local_80[0] >> 8);
        bVar27 = (byte)((ulong)uVar11 >> 0x10) & ~(byte)(local_80[0] >> 0x10);
        bVar28 = (byte)((ulong)uVar11 >> 0x18) & ~(byte)(local_80[0] >> 0x18);
        bVar29 = (byte)((ulong)uVar11 >> 0x20) & ~(byte)(local_80[0] >> 0x20);
        bVar30 = (byte)((ulong)uVar11 >> 0x28) & ~(byte)(local_80[0] >> 0x28);
        bVar31 = (byte)((ulong)uVar11 >> 0x30) & ~(byte)(local_80[0] >> 0x30);
        bVar32 = (byte)((ulong)uVar11 >> 0x38) & ~(byte)(local_80[0] >> 0x38);
        bVar33 = (byte)uVar13 & ~(byte)local_80[1];
        bVar34 = (byte)((ulong)uVar13 >> 8) & ~(byte)(local_80[1] >> 8);
        bVar35 = (byte)((ulong)uVar13 >> 0x10) & ~(byte)(local_80[1] >> 0x10);
        bVar36 = (byte)((ulong)uVar13 >> 0x18) & ~(byte)(local_80[1] >> 0x18);
        bVar37 = (byte)((ulong)uVar13 >> 0x20) & ~(byte)(local_80[1] >> 0x20);
        bVar38 = (byte)((ulong)uVar13 >> 0x28) & ~(byte)(local_80[1] >> 0x28);
        bVar39 = (byte)((ulong)uVar13 >> 0x30) & ~(byte)(local_80[1] >> 0x30);
        bVar40 = (byte)((ulong)uVar13 >> 0x38) & ~(byte)(local_80[1] >> 0x38);
        puVar2[1] = CONCAT17(bVar40,CONCAT16(bVar39,CONCAT15(bVar38,CONCAT14(bVar37,CONCAT13(bVar36,
                                                  CONCAT12(bVar35,CONCAT11(bVar34,bVar33)))))));
        *puVar2 = CONCAT17(bVar32,CONCAT16(bVar31,CONCAT15(bVar30,CONCAT14(bVar29,CONCAT13(bVar28,
                                                  CONCAT12(bVar27,CONCAT11(bVar26,bVar25)))))));
        bVar41 = (byte)uVar57 & ~(byte)local_80[2];
        bVar42 = (byte)((ulong)uVar57 >> 8) & ~(byte)(local_80[2] >> 8);
        bVar43 = (byte)((ulong)uVar57 >> 0x10) & ~(byte)(local_80[2] >> 0x10);
        bVar44 = (byte)((ulong)uVar57 >> 0x18) & ~(byte)(local_80[2] >> 0x18);
        bVar45 = (byte)((ulong)uVar57 >> 0x20) & ~(byte)(local_80[2] >> 0x20);
        bVar46 = (byte)((ulong)uVar57 >> 0x28) & ~(byte)(local_80[2] >> 0x28);
        bVar47 = (byte)((ulong)uVar57 >> 0x30) & ~(byte)(local_80[2] >> 0x30);
        bVar48 = (byte)((ulong)uVar57 >> 0x38) & ~(byte)(local_80[2] >> 0x38);
        bVar49 = (byte)uVar58 & ~(byte)local_80[3];
        bVar50 = (byte)((ulong)uVar58 >> 8) & ~(byte)(local_80[3] >> 8);
        bVar51 = (byte)((ulong)uVar58 >> 0x10) & ~(byte)(local_80[3] >> 0x10);
        bVar52 = (byte)((ulong)uVar58 >> 0x18) & ~(byte)(local_80[3] >> 0x18);
        bVar53 = (byte)((ulong)uVar58 >> 0x20) & ~(byte)(local_80[3] >> 0x20);
        bVar54 = (byte)((ulong)uVar58 >> 0x28) & ~(byte)(local_80[3] >> 0x28);
        bVar55 = (byte)((ulong)uVar58 >> 0x30) & ~(byte)(local_80[3] >> 0x30);
        bVar56 = (byte)((ulong)uVar58 >> 0x38) & ~(byte)(local_80[3] >> 0x38);
        puVar2[3] = CONCAT17(bVar56,CONCAT16(bVar55,CONCAT15(bVar54,CONCAT14(bVar53,CONCAT13(bVar52,
                                                  CONCAT12(bVar51,CONCAT11(bVar50,bVar49)))))));
        puVar2[2] = CONCAT17(bVar48,CONCAT16(bVar47,CONCAT15(bVar46,CONCAT14(bVar45,CONCAT13(bVar44,
                                                  CONCAT12(bVar43,CONCAT11(bVar42,bVar41)))))));
        lVar20 = -(ulong)(CONCAT17(bVar32,CONCAT16(bVar31,CONCAT15(bVar30,CONCAT14(bVar29,CONCAT13(
                                                  bVar28,CONCAT12(bVar27,CONCAT11(bVar26,bVar25)))))
                                                  )) == 0);
        lVar10 = -(ulong)(CONCAT17(bVar40,CONCAT16(bVar39,CONCAT15(bVar38,CONCAT14(bVar37,CONCAT13(
                                                  bVar36,CONCAT12(bVar35,CONCAT11(bVar34,bVar33)))))
                                                  )) == 0);
        lVar12 = -(ulong)(CONCAT17(bVar48,CONCAT16(bVar47,CONCAT15(bVar46,CONCAT14(bVar45,CONCAT13(
                                                  bVar44,CONCAT12(bVar43,CONCAT11(bVar42,bVar41)))))
                                                  )) == 0);
        lVar14 = -(ulong)(CONCAT17(bVar56,CONCAT16(bVar55,CONCAT15(bVar54,CONCAT14(bVar53,CONCAT13(
                                                  bVar52,CONCAT12(bVar51,CONCAT11(bVar50,bVar49)))))
                                                  )) == 0);
        auVar9[1] = ~(byte)((ulong)lVar12 >> 8);
        auVar9[0] = ~(byte)lVar12;
        auVar9[2] = ~(byte)((ulong)lVar12 >> 0x10);
        auVar9[3] = ~(byte)((ulong)lVar12 >> 0x18);
        auVar9[4] = ~(byte)lVar14;
        auVar9[5] = ~(byte)((ulong)lVar14 >> 8);
        auVar9[6] = ~(byte)((ulong)lVar14 >> 0x10);
        auVar9[7] = ~(byte)((ulong)lVar14 >> 0x18);
        auVar9[8] = ~(byte)lVar20;
        auVar9[9] = ~(byte)((ulong)lVar20 >> 8);
        auVar9[10] = ~(byte)((ulong)lVar20 >> 0x10);
        auVar9[0xb] = ~(byte)((ulong)lVar20 >> 0x18);
        auVar9[0xc] = ~(byte)lVar10;
        auVar9[0xd] = ~(byte)((ulong)lVar10 >> 8);
        auVar9[0xe] = ~(byte)((ulong)lVar10 >> 0x10);
        auVar9[0xf] = ~(byte)((ulong)lVar10 >> 0x18);
        uVar8 = NEON_umaxv(auVar9,4);
        if ((uVar8 & 1) == 0) {
          uVar18 = (ulong)(uVar1 >> 0xb) & 0x1ffff8;
          *(ulong *)((long)param_1 + uVar18 + 0x90) =
               *(ulong *)((long)param_1 + uVar18 + 0x90) &
               (1L << ((ulong)(uVar1 >> 8) & 0x3f) ^ 0xffffffffffffffffU);
        }
        uVar23 = uVar3 + uVar23;
      } while (uVar23 < uVar7);
    }
    (**(code **)(*param_1 + 8))(param_1,piVar16);
    lVar24 = param_1[0xf];
    lVar20 = uVar17 * 8;
    puVar2 = (undefined8 *)(lVar24 + (int)lVar20);
    if (lVar20 - (int)lVar20 != 0) {
      puVar2 = (undefined8 *)(lVar24 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar2 = 0;
    *(int *)(param_1 + 0x14) = (int)param_1[0x14] + -1;
    if ((param_3 != 0) && (param_1[0x10] - 1U == uVar17)) {
      uVar18 = param_1[0x10];
      if (param_2 != 0) {
        do {
          lVar20 = uVar18 * 8 + -0x10;
          plVar5 = (long *)(lVar24 + (int)lVar20);
          if (lVar20 != (int)lVar20) {
            plVar5 = (long *)(lVar24 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
          }
          if (*plVar5 != 0) goto LAB_fffffff0081af9a4;
          uVar19 = uVar17 - 1;
          uVar18 = uVar17;
          uVar17 = uVar19;
        } while (uVar19 != 0);
      }
      uVar17 = 0;
LAB_fffffff0081af9a4:
      FUN_fffffff0081af9d4(param_1,uVar17);
    }
  }
  return iVar6 == 0;
}

