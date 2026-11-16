// FUN_fffffff0081df4b4 @ fffffff0081df4b4 size=1092

undefined8 FUN_fffffff0081df4b4(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  ulong uVar1;
  undefined1 (*pauVar2) [16];
  undefined8 *puVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 uVar17;
  undefined1 auVar18 [16];
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  
  puVar11 = (undefined8 *)param_2[2];
  if (((puVar11 < (undefined8 *)*param_2) ||
      (puVar13 = puVar11 + 0x18, (undefined8 *)0xffffffffffffff3f < puVar11)) ||
     ((undefined8 *)param_2[1] < puVar13)) goto LAB_fffffff0081df4dc;
  uVar17 = puVar11[1];
  uVar6 = *puVar11;
  uVar7 = puVar11[2];
  uVar8 = puVar11[3];
  uVar20 = puVar11[5];
  uVar19 = puVar11[4];
  uVar22 = puVar11[7];
  uVar21 = puVar11[6];
  uVar24 = puVar11[9];
  uVar23 = puVar11[8];
  uVar26 = puVar11[0xb];
  uVar25 = puVar11[10];
  uVar28 = puVar11[0xd];
  uVar27 = puVar11[0xc];
  uVar30 = puVar11[0xf];
  uVar29 = puVar11[0xe];
  uVar32 = puVar11[0x11];
  uVar31 = puVar11[0x10];
  uVar34 = puVar11[0x13];
  uVar33 = puVar11[0x12];
  uVar35 = puVar11[0x14];
  uVar37 = puVar11[0x17];
  uVar36 = puVar11[0x16];
  *(undefined8 *)(param_1 + 0xb8) = puVar11[0x15];
  *(undefined8 *)(param_1 + 0xb0) = uVar35;
  *(undefined8 *)(param_1 + 200) = uVar37;
  *(undefined8 *)(param_1 + 0xc0) = uVar36;
  *(undefined8 *)(param_1 + 0x98) = uVar32;
  *(undefined8 *)(param_1 + 0x90) = uVar31;
  *(undefined8 *)(param_1 + 0xa8) = uVar34;
  *(undefined8 *)(param_1 + 0xa0) = uVar33;
  *(undefined8 *)(param_1 + 0x78) = uVar28;
  *(undefined8 *)(param_1 + 0x70) = uVar27;
  *(undefined8 *)(param_1 + 0x88) = uVar30;
  *(undefined8 *)(param_1 + 0x80) = uVar29;
  *(undefined8 *)(param_1 + 0x58) = uVar24;
  *(undefined8 *)(param_1 + 0x50) = uVar23;
  *(undefined8 *)(param_1 + 0x68) = uVar26;
  *(undefined8 *)(param_1 + 0x60) = uVar25;
  *(undefined8 *)(param_1 + 0x38) = uVar20;
  *(undefined8 *)(param_1 + 0x30) = uVar19;
  *(undefined8 *)(param_1 + 0x48) = uVar22;
  *(undefined8 *)(param_1 + 0x40) = uVar21;
  *(undefined8 *)(param_1 + 0x18) = uVar17;
  *(undefined8 *)(param_1 + 0x10) = uVar6;
  *(undefined8 *)(param_1 + 0x28) = uVar8;
  *(undefined8 *)(param_1 + 0x20) = uVar7;
  param_2[2] = puVar13;
  pauVar2 = (undefined1 (*) [16])(param_1 + 0xb4);
  uVar6 = *(undefined8 *)*pauVar2;
  auVar18 = NEON_ext(*pauVar2,*pauVar2,8,1);
  uVar10 = CONCAT13((byte)((ulong)uVar6 >> 0x18) | auVar18[3],
                    CONCAT12((byte)((ulong)uVar6 >> 0x10) | auVar18[2],
                             CONCAT11((byte)((ulong)uVar6 >> 8) | auVar18[1],
                                      (byte)uVar6 | auVar18[0])));
  if (0x3ff < (uVar10 | *(uint *)(param_1 + 0xc4) |
               (uint)(CONCAT17((byte)((ulong)uVar6 >> 0x38) | auVar18[7],
                               CONCAT16((byte)((ulong)uVar6 >> 0x30) | auVar18[6],
                                        CONCAT15((byte)((ulong)uVar6 >> 0x28) | auVar18[5],
                                                 CONCAT14((byte)((ulong)uVar6 >> 0x20) | auVar18[4],
                                                          uVar10)))) >> 0x20) |
              *(uint *)(param_1 + 200))) {
    uVar9 = 0x109;
    goto LAB_fffffff0081df4e0;
  }
  if (((puVar13 < (undefined8 *)*param_2) ||
      (puVar11 = (undefined8 *)((long)puVar13 + (ulong)*(uint *)(param_1 + 0xac)),
      CARRY8((ulong)puVar13,(ulong)*(uint *)(param_1 + 0xac)))) ||
     ((undefined8 *)param_2[1] < puVar11)) {
    *(undefined8 *)(param_1 + 0xd0) = 0;
    *(undefined8 *)(param_1 + 0xd8) = 0;
    uVar9 = 0x100;
    *(undefined8 *)(param_1 + 0xe0) = 0;
    goto LAB_fffffff0081df4e0;
  }
  param_2[2] = puVar11;
  *(undefined8 **)(param_1 + 0xd8) = puVar11;
  *(undefined8 **)(param_1 + 0xd0) = puVar13;
  *(undefined8 **)(param_1 + 0xe0) = puVar13;
  if (puVar11 != puVar13) {
    if (*(uint *)(param_1 + 0xa0) == 0) {
LAB_fffffff0081df664:
      uVar10 = *(uint *)(param_1 + 0x98);
      if (uVar10 == 0) {
        uVar10 = *(uint *)(param_1 + 0xa4);
        if (uVar10 == 0) goto LAB_fffffff0081df8b0;
        puVar13 = (undefined8 *)param_3[2];
        puVar11 = (undefined8 *)*param_3;
        if (((puVar11 <= puVar13) &&
            (puVar14 = (undefined8 *)((long)puVar13 + (ulong)*(uint *)(param_1 + 0xa8)),
            !CARRY8((ulong)puVar13,(ulong)*(uint *)(param_1 + 0xa8)))) &&
           (puVar14 <= (undefined8 *)param_3[1])) {
          param_3[2] = puVar14;
LAB_fffffff0081df804:
          if (puVar14 < puVar11) {
            puVar12 = (undefined8 *)0x0;
            puVar13 = (undefined8 *)0x0;
          }
          else {
            puVar13 = (undefined8 *)0x0;
            puVar11 = (undefined8 *)((long)puVar14 + (ulong)uVar10);
            if (CARRY8((ulong)puVar14,(ulong)uVar10)) {
              puVar12 = (undefined8 *)0x0;
            }
            else {
              puVar12 = (undefined8 *)0x0;
              if (puVar11 <= (undefined8 *)param_3[1]) {
                param_3[2] = puVar11;
                puVar12 = puVar11;
                puVar13 = puVar14;
              }
            }
          }
          puVar11 = puVar13 + 2;
          if ((puVar13 < (undefined8 *)0xfffffffffffffff0) && (puVar11 <= puVar12)) {
            uVar6 = *puVar13;
            *(undefined8 *)(param_1 + 0x158) = puVar13[1];
            *(undefined8 *)(param_1 + 0x150) = uVar6;
            lVar4 = (ulong)*(uint *)(param_1 + 0x154) + (ulong)*(uint *)(param_1 + 0x150);
            puVar14 = puVar11 + lVar4;
            if ((CARRY8((ulong)puVar11,lVar4 * 8)) || (puVar12 < puVar14)) {
              *(undefined8 *)(param_1 + 0x160) = 0;
              return 0;
            }
            *(undefined8 **)(param_1 + 0x160) = puVar11;
            if (puVar11 == (undefined8 *)0x0) {
              return 0;
            }
            if (((puVar14 < puVar13) ||
                (lVar4 = (ulong)*(uint *)(param_1 + 0x15c) + (ulong)*(uint *)(param_1 + 0x158),
                CARRY8((ulong)puVar14,lVar4 * 8))) || (puVar12 < puVar14 + lVar4)) {
              *(undefined8 *)(param_1 + 0x168) = 0;
              return 0;
            }
            *(undefined8 **)(param_1 + 0x168) = puVar14;
            if (puVar14 == (undefined8 *)0x0) {
              return 0;
            }
LAB_fffffff0081df8b0:
            *(undefined1 *)(param_1 + 8) = 1;
            return 1;
          }
        }
      }
      else {
        puVar11 = (undefined8 *)param_3[2];
        if ((((undefined8 *)*param_3 <= puVar11) &&
            (puVar13 = (undefined8 *)((long)puVar11 + (ulong)*(uint *)(param_1 + 0x9c)),
            !CARRY8((ulong)puVar11,(ulong)*(uint *)(param_1 + 0x9c)))) &&
           (puVar13 <= (undefined8 *)param_3[1])) {
          param_3[2] = puVar13;
          if (puVar13 < (undefined8 *)*param_3) {
            puVar14 = (undefined8 *)0x0;
            puVar12 = (undefined8 *)0x0;
          }
          else {
            puVar14 = (undefined8 *)0x0;
            puVar11 = (undefined8 *)((long)puVar13 + (ulong)uVar10);
            if (CARRY8((ulong)puVar13,(ulong)uVar10)) {
              puVar12 = (undefined8 *)0x0;
            }
            else {
              puVar12 = (undefined8 *)0x0;
              if (puVar11 <= (undefined8 *)param_3[1]) {
                param_3[2] = puVar11;
                puVar14 = puVar13;
                puVar12 = puVar11;
              }
            }
          }
          puVar11 = puVar14 + 2;
          if ((puVar14 < (undefined8 *)0xfffffffffffffff0) && (puVar11 <= puVar12)) {
            uVar6 = *puVar14;
            *(undefined8 *)(param_1 + 0x128) = puVar14[1];
            *(undefined8 *)(param_1 + 0x120) = uVar6;
            uVar1 = (ulong)*(uint *)(param_1 + 0x120) * 2;
            puVar13 = (undefined8 *)((long)puVar11 + uVar1);
            puVar15 = puVar11;
            if (puVar13 <= puVar12 && !CARRY8((ulong)puVar11,uVar1)) {
              puVar15 = puVar13;
            }
            puVar5 = (undefined8 *)0x0;
            if (puVar13 <= puVar12 && !CARRY8((ulong)puVar11,uVar1)) {
              puVar5 = puVar11;
            }
            *(undefined8 **)(param_1 + 0x130) = puVar5;
            if (puVar15 < puVar14) {
              puVar13 = (undefined8 *)0x0;
            }
            else {
              uVar1 = (ulong)*(uint *)(param_1 + 0x124) * 2;
              puVar11 = (undefined8 *)((long)puVar15 + uVar1);
              puVar13 = (undefined8 *)0x0;
              if (puVar11 <= puVar12 && !CARRY8((ulong)puVar15,uVar1)) {
                puVar13 = puVar15;
                puVar15 = puVar11;
              }
            }
            *(undefined8 **)(param_1 + 0x138) = puVar13;
            puVar11 = puVar15;
            if (puVar15 < puVar14) {
              puVar16 = (undefined8 *)0x0;
            }
            else {
              uVar1 = (ulong)*(uint *)(param_1 + 0x128) * 2;
              puVar3 = (undefined8 *)((long)puVar15 + uVar1);
              puVar16 = (undefined8 *)0x0;
              if (puVar3 <= puVar12 && !CARRY8((ulong)puVar15,uVar1)) {
                puVar11 = puVar3;
                puVar16 = puVar15;
              }
            }
            *(undefined8 **)(param_1 + 0x140) = puVar16;
            if ((puVar11 < puVar14) ||
               (uVar1 = (ulong)*(uint *)(param_1 + 300) * 2, CARRY8((ulong)puVar11,uVar1))) {
              puVar11 = (undefined8 *)0x0;
            }
            else if (puVar12 < (undefined8 *)((long)puVar11 + uVar1)) {
              puVar11 = (undefined8 *)0x0;
            }
            *(undefined8 **)(param_1 + 0x148) = puVar11;
            if ((((puVar5 != (undefined8 *)0x0) && (puVar13 != (undefined8 *)0x0)) &&
                (puVar16 != (undefined8 *)0x0)) && (puVar11 != (undefined8 *)0x0)) {
              uVar10 = *(uint *)(param_1 + 0xa4);
              if (uVar10 == 0) goto LAB_fffffff0081df8b0;
              puVar14 = (undefined8 *)param_3[2];
              puVar11 = (undefined8 *)*param_3;
              goto LAB_fffffff0081df804;
            }
            *(undefined8 *)(param_1 + 0x138) = 0;
            *(undefined8 *)(param_1 + 0x130) = 0;
            *(undefined8 *)(param_1 + 0x148) = 0;
            *(undefined8 *)(param_1 + 0x140) = 0;
          }
        }
      }
      uVar9 = 0x102;
      goto LAB_fffffff0081df4e0;
    }
    puVar11 = (undefined8 *)param_2[2];
    if (puVar11 < (undefined8 *)*param_2) {
      puVar14 = (undefined8 *)0x0;
      puVar12 = (undefined8 *)0x0;
    }
    else {
      puVar14 = (undefined8 *)0x0;
      uVar1 = (ulong)*(uint *)(param_1 + 0xa0) + 0x10;
      puVar13 = (undefined8 *)((long)puVar11 + uVar1);
      if (CARRY8((ulong)puVar11,uVar1)) {
        puVar12 = (undefined8 *)0x0;
      }
      else {
        puVar12 = (undefined8 *)0x0;
        if (puVar13 <= (undefined8 *)param_2[1]) {
          param_2[2] = puVar13;
          puVar14 = puVar11;
          puVar12 = puVar13;
        }
      }
    }
    puVar11 = puVar14 + 2;
    if ((puVar14 < (undefined8 *)0xfffffffffffffff0) && (puVar11 <= puVar12)) {
      uVar6 = *puVar14;
      *(undefined8 *)(param_1 + 0xf0) = puVar14[1];
      *(undefined8 *)(param_1 + 0xe8) = uVar6;
      uVar1 = (ulong)*(uint *)(param_1 + 0xe8) * 2;
      puVar13 = (undefined8 *)((long)puVar11 + uVar1);
      puVar15 = puVar11;
      if (puVar13 <= puVar12 && !CARRY8((ulong)puVar11,uVar1)) {
        puVar15 = puVar13;
      }
      puVar5 = (undefined8 *)0x0;
      if (puVar13 <= puVar12 && !CARRY8((ulong)puVar11,uVar1)) {
        puVar5 = puVar11;
      }
      *(undefined8 **)(param_1 + 0xf8) = puVar5;
      if ((((puVar14 <= puVar15) &&
           (!CARRY8((ulong)puVar15,(ulong)*(uint *)(param_1 + 0xec) * 0x18))) &&
          (puVar15 + (ulong)*(uint *)(param_1 + 0xec) * 3 <= puVar12)) &&
         ((*(undefined8 **)(param_1 + 0x100) = puVar15, puVar5 != (undefined8 *)0x0 &&
          (puVar15 != (undefined8 *)0x0)))) goto LAB_fffffff0081df664;
      *(undefined8 *)(param_1 + 0xf8) = 0;
      *(undefined8 *)(param_1 + 0x100) = 0;
    }
  }
LAB_fffffff0081df4dc:
  uVar9 = 0x100;
LAB_fffffff0081df4e0:
  *(undefined4 *)(param_1 + 0xc) = uVar9;
  return 0;
}

