// FUN_fffffff0081b2624 @ fffffff0081b2624 size=1612

undefined8 FUN_fffffff0081b2624(long param_1,uint param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long *plVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auVar9 [16];
  long lVar10;
  byte bVar11;
  bool bVar12;
  ulong uVar13;
  long lVar14;
  undefined8 uVar15;
  ulong uVar16;
  long lVar17;
  ulong uVar18;
  ulong *puVar19;
  int iVar20;
  ulong uVar21;
  long lVar22;
  undefined8 *puVar23;
  ulong uVar24;
  ulong uVar25;
  undefined8 *puVar26;
  ulong uVar27;
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
  undefined8 uVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  undefined8 uVar41;
  ulong local_80 [4];
  
  uVar7 = *(int *)(param_1 + 0x48) * param_2;
  uVar1 = uVar7 + 0xff;
  uVar27 = *(ulong *)(param_1 + 0x80);
  if (param_2 == 0) {
    if (*(long *)(param_1 + 0x88) != 0) {
      *(undefined8 *)(param_1 + 0x88) = 0;
    }
    lVar14 = -0x8000000000000000;
    if (-1 < (long)(uVar27 * 8) && (uVar27 & 0xe000000000000000) == 0) {
      lVar14 = uVar27 * 8;
    }
    uVar15 = *(undefined8 *)(param_1 + 0x78);
    *(undefined8 *)(param_1 + 0x78) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca36f8,uVar15,lVar14);
    uVar13 = 0;
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x90) = 0;
    uVar27 = *(ulong *)(param_1 + 0x98);
    goto LAB_fffffff0081b2c0c;
  }
  if ((0x4000 < (uVar1 & 0xffffff00)) && (*(int *)(param_1 + 0xa4) == 0x4000)) {
    return 0;
  }
  uVar5 = uVar1 >> 8;
  uVar13 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca3928,uVar5 << 5);
  if (uVar13 == 0) {
    return 0;
  }
  uVar8 = param_2 - (uint)uVar27;
  if (param_2 < (uint)uVar27 || uVar8 == 0) {
    uVar21 = (ulong)param_2;
    uVar27 = *(ulong *)(param_1 + 0x88);
    if (uVar21 < uVar27) {
      *(ulong *)(param_1 + 0x88) = uVar21;
      uVar27 = uVar21;
    }
    else if (uVar27 == 0) {
      lVar14 = 0;
      goto LAB_fffffff0081b2900;
    }
    lVar14 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca36a8,uVar27 << 3);
    if (lVar14 == 0) {
LAB_fffffff0081b2c54:
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3978,uVar13,uVar5 << 5);
      return 0;
    }
    uVar21 = *(ulong *)(param_1 + 0x88);
    if (uVar21 != 0) {
      uVar18 = 0;
      uVar16 = *(ulong *)(param_1 + 0x78);
      if ((3 < uVar21) && (0x1f < lVar14 - uVar16)) {
        lVar22 = 0;
        uVar18 = uVar21 & 0xfffffffffffffffc;
        uVar24 = uVar18;
        do {
          puVar23 = (undefined8 *)(uVar16 + lVar22 * 8);
          if (((uVar16 ^ (ulong)puVar23) & 0xffc0000000000000) != 0) {
            puVar23 = (undefined8 *)((ulong)puVar23 & 0xffffffffffff | 0xc8a2000000000000);
          }
          lVar17 = lVar22 * 8;
          puVar26 = (undefined8 *)(lVar14 + (int)lVar17);
          if (lVar17 - (int)lVar17 != 0) {
            puVar26 = (undefined8 *)(lVar14 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar15 = *puVar23;
          uVar31 = puVar23[3];
          uVar29 = puVar23[2];
          puVar26[1] = puVar23[1];
          *puVar26 = uVar15;
          puVar26[3] = uVar31;
          puVar26[2] = uVar29;
          lVar22 = lVar22 + 4;
          uVar24 = uVar24 - 4;
        } while (uVar24 != 0);
        if (uVar21 == uVar18) goto LAB_fffffff0081b2900;
      }
      lVar22 = uVar21 - uVar18;
      do {
        lVar17 = uVar18 * 8;
        iVar20 = (int)lVar17;
        puVar23 = (undefined8 *)(uVar16 + (long)iVar20);
        if (lVar17 - iVar20 != 0) {
          puVar23 = (undefined8 *)(uVar16 + lVar17 & 0xffffffffffff | 0x2bad000000000000);
        }
        puVar26 = (undefined8 *)(lVar14 + iVar20);
        if (lVar17 - iVar20 != 0) {
          puVar26 = (undefined8 *)(lVar14 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar26 = *puVar23;
        uVar18 = uVar18 + 1;
        lVar22 = lVar22 + -1;
      } while (lVar22 != 0);
    }
  }
  else {
    uVar27 = *(long *)(param_1 + 0x80) + (ulong)uVar8;
    if (uVar27 == 0) {
      lVar14 = 0;
      uVar21 = *(ulong *)(param_1 + 0x88);
    }
    else {
      lVar14 = -0x8000000000000000;
      if (-1 < (long)(uVar27 * 8) && (uVar27 & 0xe000000000000000) == 0) {
        lVar14 = uVar27 * 8;
      }
      lVar14 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca36a8,lVar14);
      if (lVar14 == 0) goto LAB_fffffff0081b2c54;
      uVar21 = *(ulong *)(param_1 + 0x88);
    }
    if (uVar21 != 0) {
      uVar18 = 0;
      uVar16 = *(ulong *)(param_1 + 0x78);
      if ((3 < uVar21) && (0x1f < lVar14 - uVar16)) {
        lVar22 = 0;
        uVar18 = uVar21 & 0xfffffffffffffffc;
        uVar24 = uVar18;
        do {
          puVar23 = (undefined8 *)(uVar16 + lVar22 * 8);
          if (((uVar16 ^ (ulong)puVar23) & 0xffc0000000000000) != 0) {
            puVar23 = (undefined8 *)((ulong)puVar23 & 0xffffffffffff | 0xc8a2000000000000);
          }
          lVar17 = lVar22 * 8;
          puVar26 = (undefined8 *)(lVar14 + (int)lVar17);
          if (lVar17 - (int)lVar17 != 0) {
            puVar26 = (undefined8 *)(lVar14 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar15 = *puVar23;
          uVar31 = puVar23[3];
          uVar29 = puVar23[2];
          puVar26[1] = puVar23[1];
          *puVar26 = uVar15;
          puVar26[3] = uVar31;
          puVar26[2] = uVar29;
          lVar22 = lVar22 + 4;
          uVar24 = uVar24 - 4;
        } while (uVar24 != 0);
        if (uVar21 == uVar18) goto LAB_fffffff0081b2900;
      }
      lVar22 = uVar21 - uVar18;
      do {
        lVar17 = uVar18 * 8;
        iVar20 = (int)lVar17;
        puVar23 = (undefined8 *)(uVar16 + (long)iVar20);
        if (lVar17 - iVar20 != 0) {
          puVar23 = (undefined8 *)(uVar16 + lVar17 & 0xffffffffffff | 0x2bad000000000000);
        }
        puVar26 = (undefined8 *)(lVar14 + iVar20);
        if (lVar17 - iVar20 != 0) {
          puVar26 = (undefined8 *)(lVar14 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar26 = *puVar23;
        uVar18 = uVar18 + 1;
        lVar22 = lVar22 + -1;
      } while (lVar22 != 0);
    }
  }
LAB_fffffff0081b2900:
  uVar15 = *(undefined8 *)(param_1 + 0x78);
  lVar17 = *(ulong *)(param_1 + 0x80) * 8;
  lVar22 = -0x8000000000000000;
  if (-1 < lVar17 && (*(ulong *)(param_1 + 0x80) & 0xe000000000000000) == 0) {
    lVar22 = lVar17;
  }
  *(undefined8 *)(param_1 + 0x78) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca36f8,uVar15,lVar22);
  *(long *)(param_1 + 0x78) = lVar14;
  *(ulong *)(param_1 + 0x80) = uVar27;
  uVar21 = *(ulong *)(param_1 + 0x88);
  for (lVar14 = uVar27 - uVar21; lVar14 != 0; lVar14 = lVar14 + -1) {
    if (uVar21 < uVar27) {
      lVar22 = uVar21 * 8;
      uVar21 = uVar21 + 1;
      *(ulong *)(param_1 + 0x88) = uVar21;
      puVar23 = (undefined8 *)(*(long *)(param_1 + 0x78) + (long)(int)lVar22);
      if (lVar22 - (int)lVar22 != 0) {
        puVar23 = (undefined8 *)
                  (*(long *)(param_1 + 0x78) + lVar22 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar23 = 0;
    }
  }
  uVar27 = *(ulong *)(param_1 + 0x98);
  if (uVar27 != 0) {
    uVar8 = *(uint *)(param_1 + 0xa4) >> 8;
    if (uVar5 <= uVar8) {
      uVar8 = uVar5;
    }
    uVar21 = (ulong)uVar8;
    if (uVar8 != 0) {
      if ((uVar8 < 4) || (uVar13 < uVar27 + uVar21 * 0x20 && uVar27 < uVar13 + uVar21 * 0x20)) {
        uVar18 = 0;
      }
      else {
        lVar14 = 0;
        uVar18 = uVar21 & 0xfffffc;
        uVar16 = uVar18;
        do {
          puVar23 = (undefined8 *)(uVar27 + lVar14 * 0x20);
          if (((uVar27 ^ (ulong)puVar23) & 0xffc0000000000000) != 0) {
            puVar23 = (undefined8 *)((ulong)puVar23 & 0xffffffffffff | 0xc8a2000000000000);
          }
          uVar24 = lVar14 * 0x20;
          uVar25 = uVar24 | 0x40;
          puVar26 = (undefined8 *)(uVar27 + uVar25);
          if (((uVar27 ^ (ulong)puVar26) & 0xffc0000000000000) != 0) {
            puVar26 = (undefined8 *)((ulong)puVar26 & 0xffffffffffff | 0xc8a2000000000000);
          }
          uVar29 = puVar23[1];
          uVar15 = *puVar23;
          uVar33 = puVar23[3];
          uVar31 = puVar23[2];
          uVar28 = puVar23[4];
          uVar32 = puVar23[7];
          uVar30 = puVar23[6];
          puVar2 = (undefined8 *)(uVar13 + (long)(int)uVar24);
          if (uVar24 - (long)(int)uVar24 != 0) {
            puVar2 = (undefined8 *)(uVar13 + uVar24 & 0xffffffffffff | 0x2bad000000000000);
          }
          uVar37 = puVar26[1];
          uVar36 = *puVar26;
          uVar35 = puVar26[3];
          uVar34 = puVar26[2];
          puVar3 = (undefined8 *)(uVar13 + (long)(int)uVar25);
          if (uVar25 != (long)(int)uVar25) {
            puVar3 = (undefined8 *)(uVar13 + uVar25 & 0xffffffffffff | 0x2bad000000000000);
          }
          uVar41 = puVar26[5];
          uVar40 = puVar26[4];
          uVar39 = puVar26[7];
          uVar38 = puVar26[6];
          puVar2[5] = puVar23[5];
          puVar2[4] = uVar28;
          puVar2[7] = uVar32;
          puVar2[6] = uVar30;
          puVar2[1] = uVar29;
          *puVar2 = uVar15;
          puVar2[3] = uVar33;
          puVar2[2] = uVar31;
          puVar3[5] = uVar41;
          puVar3[4] = uVar40;
          puVar3[7] = uVar39;
          puVar3[6] = uVar38;
          puVar3[1] = uVar37;
          *puVar3 = uVar36;
          puVar3[3] = uVar35;
          puVar3[2] = uVar34;
          lVar14 = lVar14 + 4;
          uVar16 = uVar16 - 4;
        } while (uVar16 != 0);
        if (uVar18 == uVar21) goto LAB_fffffff0081b2ab0;
      }
      lVar14 = uVar18 - uVar21;
      do {
        lVar22 = uVar18 * 0x20;
        iVar20 = (int)lVar22;
        puVar23 = (undefined8 *)(uVar27 + (long)iVar20);
        if (lVar22 - iVar20 != 0) {
          puVar23 = (undefined8 *)(uVar27 + lVar22 & 0xffffffffffff | 0x2bad000000000000);
        }
        puVar26 = (undefined8 *)(uVar13 + (long)iVar20);
        if (lVar22 - iVar20 != 0) {
          puVar26 = (undefined8 *)(uVar13 + lVar22 & 0xffffffffffff | 0x2bad000000000000);
        }
        *puVar26 = *puVar23;
        puVar26[1] = puVar23[1];
        puVar26[2] = puVar23[2];
        puVar26[3] = puVar23[3];
        uVar18 = uVar18 + 1;
        bVar12 = lVar14 != -1;
        lVar14 = lVar14 + 1;
      } while (bVar12);
    }
  }
LAB_fffffff0081b2ab0:
  bVar12 = uVar1 >> 0xe == 0;
  uVar8 = uVar1 >> 8 & 0x3f;
  if (bVar12) {
    uVar8 = uVar5;
  }
  uVar21 = 0xffffffffffffffff;
  if (bVar12) {
    uVar21 = ~(-1L << ((ulong)uVar8 & 0x3f));
  }
  puVar19 = (ulong *)(param_1 + 0x90);
  *puVar19 = *puVar19 & uVar21;
  uVar8 = uVar7 & 0xff;
  if (uVar8 == 0) {
    uVar21 = (ulong)(uVar5 - 1);
  }
  else {
    local_80[1] = 0;
    local_80[0] = 0;
    local_80[3] = 0;
    local_80[2] = 0;
    if (uVar8 < 0x40) {
      uVar18 = 0;
      uVar21 = 0;
LAB_fffffff0081b2b74:
      local_80[uVar21] = uVar18 | -1L << ((ulong)uVar8 & 0x3f) ^ 0xffffffffffffffffU;
    }
    else {
      uVar6 = uVar8 - 0x40 >> 6;
      bVar11 = (byte)(uVar8 - 0x40 >> 0x18);
      local_80[0] = 0xffffffffffffffff;
      uVar8 = CONCAT13(bVar11 >> 6,(int3)uVar6);
      if (uVar8 != 0) {
        local_80[1] = 0xffffffffffffffff;
      }
      if ((uVar6 + 2 & 0x7fffffe) != 2) {
        if (1 < CONCAT13(bVar11 >> 6,(int3)uVar6)) {
          local_80[2] = 0xffffffffffffffff;
        }
        if (2 < uVar8) {
          local_80[3] = 0xffffffffffffffff;
        }
      }
      uVar8 = uVar7 & 0x3f;
      if (uVar8 != 0) {
        uVar21 = (ulong)(uVar6 + 1);
        uVar18 = local_80[uVar21];
        goto LAB_fffffff0081b2b74;
      }
    }
    uVar21 = (ulong)(uVar5 - 1);
    lVar14 = uVar21 * 0x20;
    puVar23 = (undefined8 *)(uVar13 + (long)(int)lVar14);
    if (lVar14 != (int)lVar14) {
      puVar23 = (undefined8 *)(uVar13 + lVar14 & 0xffffffffffff | 0x2bad000000000000);
    }
    uVar29 = puVar23[1];
    uVar15 = *puVar23;
    uVar33 = puVar23[3];
    uVar31 = puVar23[2];
    puVar23[1] = CONCAT17((byte)((ulong)uVar29 >> 0x38) & (byte)(local_80[1] >> 0x38),
                          CONCAT16((byte)((ulong)uVar29 >> 0x30) & (byte)(local_80[1] >> 0x30),
                                   CONCAT15((byte)((ulong)uVar29 >> 0x28) &
                                            (byte)(local_80[1] >> 0x28),
                                            CONCAT14((byte)((ulong)uVar29 >> 0x20) &
                                                     (byte)(local_80[1] >> 0x20),
                                                     CONCAT13((byte)((ulong)uVar29 >> 0x18) &
                                                              (byte)(local_80[1] >> 0x18),
                                                              CONCAT12((byte)((ulong)uVar29 >> 0x10)
                                                                       & (byte)(local_80[1] >> 0x10)
                                                                       ,CONCAT11((byte)((ulong)
                                                  uVar29 >> 8) & (byte)(local_80[1] >> 8),
                                                  (byte)uVar29 & (byte)local_80[1])))))));
    *puVar23 = CONCAT17((byte)((ulong)uVar15 >> 0x38) & (byte)(local_80[0] >> 0x38),
                        CONCAT16((byte)((ulong)uVar15 >> 0x30) & (byte)(local_80[0] >> 0x30),
                                 CONCAT15((byte)((ulong)uVar15 >> 0x28) &
                                          (byte)(local_80[0] >> 0x28),
                                          CONCAT14((byte)((ulong)uVar15 >> 0x20) &
                                                   (byte)(local_80[0] >> 0x20),
                                                   CONCAT13((byte)((ulong)uVar15 >> 0x18) &
                                                            (byte)(local_80[0] >> 0x18),
                                                            CONCAT12((byte)((ulong)uVar15 >> 0x10) &
                                                                     (byte)(local_80[0] >> 0x10),
                                                                     CONCAT11((byte)((ulong)uVar15
                                                                                    >> 8) &
                                                                              (byte)(local_80[0] >>
                                                                                    8),(byte)uVar15
                                                                                       & (byte)
                                                  local_80[0])))))));
    puVar23[3] = CONCAT17((byte)((ulong)uVar33 >> 0x38) & (byte)(local_80[3] >> 0x38),
                          CONCAT16((byte)((ulong)uVar33 >> 0x30) & (byte)(local_80[3] >> 0x30),
                                   CONCAT15((byte)((ulong)uVar33 >> 0x28) &
                                            (byte)(local_80[3] >> 0x28),
                                            CONCAT14((byte)((ulong)uVar33 >> 0x20) &
                                                     (byte)(local_80[3] >> 0x20),
                                                     CONCAT13((byte)((ulong)uVar33 >> 0x18) &
                                                              (byte)(local_80[3] >> 0x18),
                                                              CONCAT12((byte)((ulong)uVar33 >> 0x10)
                                                                       & (byte)(local_80[3] >> 0x10)
                                                                       ,CONCAT11((byte)((ulong)
                                                  uVar33 >> 8) & (byte)(local_80[3] >> 8),
                                                  (byte)uVar33 & (byte)local_80[3])))))));
    puVar23[2] = CONCAT17((byte)((ulong)uVar31 >> 0x38) & (byte)(local_80[2] >> 0x38),
                          CONCAT16((byte)((ulong)uVar31 >> 0x30) & (byte)(local_80[2] >> 0x30),
                                   CONCAT15((byte)((ulong)uVar31 >> 0x28) &
                                            (byte)(local_80[2] >> 0x28),
                                            CONCAT14((byte)((ulong)uVar31 >> 0x20) &
                                                     (byte)(local_80[2] >> 0x20),
                                                     CONCAT13((byte)((ulong)uVar31 >> 0x18) &
                                                              (byte)(local_80[2] >> 0x18),
                                                              CONCAT12((byte)((ulong)uVar31 >> 0x10)
                                                                       & (byte)(local_80[2] >> 0x10)
                                                                       ,CONCAT11((byte)((ulong)
                                                  uVar31 >> 8) & (byte)(local_80[2] >> 8),
                                                  (byte)uVar31 & (byte)local_80[2])))))));
  }
  lVar14 = uVar21 * 0x20;
  plVar4 = (long *)(uVar13 + (long)(int)lVar14);
  if (lVar14 - (int)lVar14 != 0) {
    plVar4 = (long *)(uVar13 + lVar14 & 0xffffffffffff | 0x2bad000000000000);
  }
  lVar14 = -(ulong)(plVar4[2] == 0);
  lVar22 = -(ulong)(plVar4[3] == 0);
  lVar17 = -(ulong)(*plVar4 == 0);
  lVar10 = -(ulong)(plVar4[1] == 0);
  auVar9[1] = ~(byte)((ulong)lVar17 >> 8);
  auVar9[0] = ~(byte)lVar17;
  auVar9[2] = ~(byte)((ulong)lVar17 >> 0x10);
  auVar9[3] = ~(byte)((ulong)lVar17 >> 0x18);
  auVar9[4] = ~(byte)lVar10;
  auVar9[5] = ~(byte)((ulong)lVar10 >> 8);
  auVar9[6] = ~(byte)((ulong)lVar10 >> 0x10);
  auVar9[7] = ~(byte)((ulong)lVar10 >> 0x18);
  auVar9[8] = ~(byte)lVar14;
  auVar9[9] = ~(byte)((ulong)lVar14 >> 8);
  auVar9[10] = ~(byte)((ulong)lVar14 >> 0x10);
  auVar9[0xb] = ~(byte)((ulong)lVar14 >> 0x18);
  auVar9[0xc] = ~(byte)lVar22;
  auVar9[0xd] = ~(byte)((ulong)lVar22 >> 8);
  auVar9[0xe] = ~(byte)((ulong)lVar22 >> 0x10);
  auVar9[0xf] = ~(byte)((ulong)lVar22 >> 0x18);
  uVar7 = NEON_umaxv(auVar9,4);
  if ((uVar7 & 1) == 0) {
    uVar18 = uVar21 >> 3 & 0x1ffffff8;
    *(ulong *)((long)puVar19 + uVar18) =
         *(ulong *)((long)puVar19 + uVar18) & (1L << (uVar21 & 0x3f) ^ 0xffffffffffffffffU);
  }
LAB_fffffff0081b2c0c:
  *(undefined8 *)(param_1 + 0x98) = 0;
  thunk_EXT_FUN_80110000038fe768
            (&DAT_fffffff007ca39c8,uVar27,*(uint *)(param_1 + 0xa4) >> 3 & 0x1fffffe0);
  *(ulong *)(param_1 + 0x98) = uVar13;
  *(uint *)(param_1 + 0xa4) = uVar1 & 0xffffff00;
  return 1;
}

