// FUN_fffffff00996bb88 @ fffffff00996bb88 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff00996c0f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00996c514) */

undefined8 FUN_fffffff00996bb88(long *param_1)

{
  int *piVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  ulong *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long *plVar15;
  uint uVar16;
  int iVar17;
  ulong uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  ulong uVar24;
  uint uVar25;
  ulong uVar26;
  long lVar27;
  int iVar28;
  long *plVar29;
  long lVar30;
  ulong uVar31;
  long lVar32;
  ulong unaff_x22;
  long unaff_x23;
  ulong unaff_x24;
  ulong uVar33;
  ulong unaff_x25;
  ulong unaff_x26;
  undefined8 uVar34;
  int iVar35;
  undefined4 *puVar36;
  undefined1 auVar37 [16];
  undefined8 uStack_f8;
  undefined4 *puStack_f0;
  undefined8 uStack_e8;
  ulong uStack_e0;
  ulong uStack_d8;
  ulong uStack_d0;
  long lStack_c8;
  ulong uStack_c0;
  ulong uStack_b8;
  long *plStack_b0;
  long *plStack_a8;
  undefined1 *puStack_a0;
  code *pcStack_98;
  ulong uStack_90;
  uint uStack_88;
  uint uStack_84;
  ulong uStack_80;
  ulong uStack_78;
  int iStack_70;
  int iStack_6c;
  undefined8 uStack_68;
  
  uVar34 = 0x85180189;
  puVar36 = &DAT_fffffff00af227e8;
  if (DAT_fffffff00af227e8 != 0) {
    lVar30 = param_1[0x19];
    unaff_x22 = param_1[0x24];
    uVar13 = (**(code **)(*param_1 + 0xe0))(param_1);
    uStack_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar13,&uStack_68);
    uVar13 = uStack_68;
    uVar14 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    thunk_EXT_FUN_80110000036da494(0x85180189,unaff_x22 + lVar30,uVar13,uVar14,0,0);
  }
  uVar21 = *(uint *)(param_1 + 0x17);
  plVar29 = (long *)(ulong)uVar21;
  if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
    uVar31 = 0;
  }
  else {
    uVar31 = 0;
    uVar18 = 0;
    unaff_x22 = 0;
    unaff_x23 = 1;
    do {
      uVar33 = *(ulong *)(param_1[0x13] + unaff_x22 * 8);
      if (uVar33 != 0) {
        unaff_x25 = (ulong)(uint)((int)unaff_x22 << 6);
        do {
          uVar24 = (uVar33 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar33 & 0x5555555555555555) << 1;
          uVar24 = (uVar24 & 0xcccccccccccccccc) >> 2 | (uVar24 & 0x3333333333333333) << 2;
          uVar24 = (uVar24 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar24 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar24 = (uVar24 & 0xff00ff00ff00ff00) >> 8 | (uVar24 & 0xff00ff00ff00ff) << 8;
          uVar24 = (uVar24 & 0xffff0000ffff0000) >> 0x10 | (uVar24 & 0xffff0000ffff) << 0x10;
          unaff_x26 = LZCOUNT(uVar24 >> 0x20 | uVar24 << 0x20);
          if ((uint)uVar18 < uVar21) {
            lVar30 = (unaff_x26 | unaff_x25) * 8;
            puVar4 = (undefined8 *)(param_1[0x10] + (long)(int)lVar30);
            if (lVar30 - (int)lVar30 != 0) {
              puVar4 = (undefined8 *)(param_1[0x10] + lVar30 & 0xffffffffffffU | 0x2bad000000000000)
              ;
            }
            FUN_fffffff0099437a0(*puVar4);
            uVar18 = (ulong)((int)uVar31 + 1);
            uVar31 = uVar18;
          }
          uVar33 = uVar33 & (1L << (unaff_x26 & 0x3f) ^ 0xffffffffffffffffU);
        } while (uVar33 != 0);
      }
      unaff_x24 = 0;
      uVar22 = (int)unaff_x22 + 1;
      unaff_x22 = (ulong)uVar22;
    } while (uVar22 <= *(uint *)(param_1 + 0x16));
  }
  if ((uint)uVar31 == uVar21) {
    iVar35 = (int)param_1[0x22];
    if (iVar35 == 0) {
LAB_fffffff00996c1c0:
      uVar34 = FUN_fffffff00997db18(*(long *)(param_1[2] + 0x160) + 0x1b8,param_1);
      if (DAT_fffffff00af227e8 != 0) {
        lVar30 = param_1[0x19];
        lVar32 = param_1[0x24];
        uVar34 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
        uVar34 = thunk_EXT_FUN_80110000036da494(0x8518018a,lVar32 + lVar30,0,uVar34,0,0);
      }
      return uVar34;
    }
    iStack_70 = iVar35;
    if ((*(byte *)(param_1 + 0x25) & 1) != 0) {
      iStack_6c = 0;
      unaff_x26 = 0;
      uVar18 = 0;
      uVar34 = 1;
      uVar31 = 0xffffffffffffffff;
      unaff_x22 = 0x40;
      do {
        uVar21 = (uint)uVar18;
        uVar33 = *(ulong *)(param_1[0x1e] + uVar18 * 8);
        if (uVar33 != 0) {
          uVar24 = (ulong)(uVar21 << 6);
          uStack_90 = uVar24;
          uStack_88 = uVar21;
          do {
            uVar26 = (uVar33 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar33 & 0x5555555555555555) << 1;
            uVar26 = (uVar26 & 0xcccccccccccccccc) >> 2 | (uVar26 & 0x3333333333333333) << 2;
            uVar26 = (uVar26 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar26 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar26 = (uVar26 & 0xff00ff00ff00ff00) >> 8 | (uVar26 & 0xff00ff00ff00ff) << 8;
            uVar26 = (uVar26 & 0xffff0000ffff0000) >> 0x10 | (uVar26 & 0xffff0000ffff) << 0x10;
            uVar26 = LZCOUNT(uVar26 >> 0x20 | uVar26 << 0x20);
            lVar30 = (uVar26 | uVar24) * 4;
            puVar2 = (uint *)(param_1[0x1c] + (long)(int)lVar30);
            if (lVar30 - (int)lVar30 != 0) {
              puVar2 = (uint *)(param_1[0x1c] + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar21 = *puVar2;
            unaff_x25 = (ulong)uVar21;
            if (uVar21 != 0) {
              puVar36 = (undefined4 *)0x0;
              bVar12 = (int)unaff_x26 == -1;
              uStack_84 = (int)unaff_x26 + uVar21;
              unaff_x23 = (uVar26 | uVar24) * 8;
              uStack_80 = uVar26;
              uStack_78 = uVar33;
              do {
                if (bVar12) goto LAB_fffffff00996c19c;
                puVar4 = (undefined8 *)(param_1[0x1b] + (long)(int)unaff_x23);
                if (unaff_x23 - (int)unaff_x23 != 0) {
                  puVar4 = (undefined8 *)
                           (param_1[0x1b] + unaff_x23 & 0xffffffffffffU | 0x2bad000000000000);
                }
                plVar29 = (long *)*puVar4;
                unaff_x24 = (long)plVar29 * -0x61c8864680b583eb;
                uVar18 = unaff_x24 >> ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
                lVar30 = (uVar18 & 0xffffffff) * 4;
                puVar2 = (uint *)(param_1[0x12] + (long)(int)lVar30);
                if (lVar30 != (int)lVar30) {
                  puVar2 = (uint *)(param_1[0x12] + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
                }
                uVar22 = *puVar2;
                do {
                  iVar35 = (int)puVar36;
                  if (uVar22 == 0) goto LAB_fffffff00996bfa4;
                  uVar20 = (uVar22 & 0xaaaaaaaa) >> 1 | (uVar22 & 0x55555555) << 1;
                  uVar20 = (uVar20 & 0xcccccccc) >> 2 | (uVar20 & 0x33333333) << 2;
                  uVar20 = (uVar20 & 0xf0f0f0f0) >> 4 | (uVar20 & 0xf0f0f0f) << 4;
                  uVar20 = (uVar20 & 0xff00ff00) >> 8 | (uVar20 & 0xff00ff) << 8;
                  uVar20 = (uint)LZCOUNT(uVar20 >> 0x10 | uVar20 << 0x10);
                  uVar22 = uVar22 & (1 << (ulong)(uVar20 & 0x1f) ^ 0xffffffffU);
                  uVar33 = (ulong)(uVar20 + (int)uVar18 & (int)param_1[0x15] - 1U);
                  lVar30 = uVar33 * 8;
                  plVar15 = (long *)(param_1[0x10] + (long)(int)lVar30);
                  if (lVar30 != (int)lVar30) {
                    plVar15 = (long *)(param_1[0x10] + lVar30 & 0xffffffffffffU | 0x2bad000000000000
                                      );
                  }
                } while ((long *)*plVar15 != plVar29);
                lVar30 = uVar33 * 4;
                piVar1 = (int *)(param_1[0x11] + (long)(int)lVar30);
                if (lVar30 - (int)lVar30 != 0) {
                  piVar1 = (int *)(param_1[0x11] + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
                }
                *piVar1 = *piVar1 + 1;
                if (iVar35 == 0) goto LAB_fffffff00996c22c;
LAB_fffffff00996c158:
                uVar22 = (int)unaff_x26 + 1;
                unaff_x26 = (ulong)uVar22;
                if (uVar22 == 0xffffffff) goto LAB_fffffff00996c19c;
                bVar12 = false;
                puVar36 = (undefined4 *)(ulong)(iVar35 + 1U);
              } while (iVar35 + 1U != uVar21);
              uVar18 = (ulong)uStack_88;
              unaff_x26 = (ulong)uStack_84;
              uVar33 = uStack_78;
              uVar24 = uStack_90;
              uVar26 = uStack_80;
            }
            uVar21 = (uint)uVar18;
            uVar33 = uVar33 & (1L << (uVar26 & 0x3f) ^ 0xffffffffffffffffU);
          } while (uVar33 != 0);
        }
        uVar18 = (ulong)(uVar21 + 1);
      } while (uVar21 + 1 <= *(uint *)(param_1 + 0x21));
LAB_fffffff00996c19c:
      if (iStack_6c == iStack_70) {
        FUN_fffffff009968d64(param_1 + 0x1b);
        goto LAB_fffffff00996c1c0;
      }
      goto LAB_fffffff00996c234;
    }
LAB_fffffff00996c228:
    FUN_fffffff009983ee4();
LAB_fffffff00996c22c:
    FUN_fffffff009983eb4();
  }
  FUN_fffffff009983e84();
LAB_fffffff00996c234:
  auVar37 = FUN_fffffff009983f14();
  uVar18 = auVar37._8_8_;
  plVar15 = auVar37._0_8_;
  pcStack_98 = FUN_fffffff00996c238;
  puStack_f0 = puVar36;
  uStack_e8 = uVar34;
  uStack_e0 = unaff_x26;
  uStack_d8 = unaff_x25;
  uStack_d0 = unaff_x24;
  lStack_c8 = unaff_x23;
  uStack_c0 = unaff_x22;
  uStack_b8 = uVar31;
  plStack_b0 = plVar29;
  plStack_a8 = param_1;
  puStack_a0 = &stack0xfffffffffffffff0;
  if ((int)plVar15[0x22] != 0) {
LAB_fffffff00996c460:
    lVar30 = FUN_fffffff009983f44();
    FUN_fffffff009942d70();
    if ((*(byte *)(lVar30 + 0xd0) & 1) != 0) {
      uVar31 = 0;
      do {
        uVar18 = *(ulong *)(*(long *)(lVar30 + 0x98) + uVar31 * 8);
        if (uVar18 != 0) {
          do {
            uVar33 = (uVar18 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar18 & 0x5555555555555555) << 1;
            uVar33 = (uVar33 & 0xcccccccccccccccc) >> 2 | (uVar33 & 0x3333333333333333) << 2;
            uVar33 = (uVar33 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar33 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar33 = (uVar33 & 0xff00ff00ff00ff00) >> 8 | (uVar33 & 0xff00ff00ff00ff) << 8;
            uVar33 = (uVar33 & 0xffff0000ffff0000) >> 0x10 | (uVar33 & 0xffff0000ffff) << 0x10;
            uVar33 = LZCOUNT(uVar33 >> 0x20 | uVar33 << 0x20);
            uVar18 = uVar18 & (1L << (uVar33 & 0x3f) ^ 0xffffffffffffffffU);
            lVar32 = (uVar33 | (uint)((int)uVar31 << 6)) * 8;
            puVar4 = (undefined8 *)(*(long *)(lVar30 + 0x80) + (long)(int)lVar32);
            if (lVar32 - (int)lVar32 != 0) {
              puVar4 = (undefined8 *)
                       (*(long *)(lVar30 + 0x80) + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
            }
            FUN_fffffff009942c08(*puVar4);
          } while (uVar18 != 0);
        }
        uVar21 = (int)uVar31 + 1;
        uVar31 = (ulong)uVar21;
      } while (uVar21 <= *(uint *)(lVar30 + 0xb0));
    }
    uVar34 = FUN_fffffff009942d7c(lVar30);
    return uVar34;
  }
  if (DAT_fffffff00af227e8 != 0) {
    uVar34 = (**(code **)(*plVar15 + 0xe0))(plVar15);
    uStack_f8 = 0;
    thunk_EXT_FUN_80110000032db760(uVar34,&uStack_f8);
    uVar34 = uStack_f8;
    lVar30 = plVar15[5];
    uVar13 = thunk_EXT_FUN_801100000390ebc0(plVar15[2]);
    thunk_EXT_FUN_80110000036da494(0x851801c9,uVar34,lVar30,uVar18,uVar13,0);
  }
  if (((*(byte *)((long)plVar15 + 0x24) >> 1 & 1) == 0) || ((plVar15[5] & uVar18) != 0)) {
    uVar34 = 0;
  }
  else if ((*(byte *)(plVar15 + 0x1a) & 1) == 0) {
    uVar34 = 0xe00002bc;
  }
  else {
    uVar20 = 0;
    uVar21 = 0;
    uVar31 = 0;
    uVar22 = *(uint *)(plVar15 + 0x17);
    do {
      uVar33 = *(ulong *)(plVar15[0x13] + uVar31 * 8);
      if (uVar33 != 0) {
        do {
          uVar24 = (uVar33 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar33 & 0x5555555555555555) << 1;
          uVar24 = (uVar24 & 0xcccccccccccccccc) >> 2 | (uVar24 & 0x3333333333333333) << 2;
          uVar24 = (uVar24 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar24 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar24 = (uVar24 & 0xff00ff00ff00ff00) >> 8 | (uVar24 & 0xff00ff00ff00ff) << 8;
          uVar24 = (uVar24 & 0xffff0000ffff0000) >> 0x10 | (uVar24 & 0xffff0000ffff) << 0x10;
          uVar24 = LZCOUNT(uVar24 >> 0x20 | uVar24 << 0x20);
          if (uVar21 < uVar22) {
            lVar30 = (uVar24 | (uint)((int)uVar31 << 6)) * 8;
            puVar4 = (undefined8 *)(plVar15[0x10] + (long)(int)lVar30);
            if (lVar30 - (int)lVar30 != 0) {
              puVar4 = (undefined8 *)(plVar15[0x10] + lVar30 & 0xffffffffffffU | 0x2bad000000000000)
              ;
            }
            uVar13 = *puVar4;
            uVar26 = FUN_fffffff0099437e4(uVar13);
            if ((uVar26 & 1) == 0) {
              FUN_fffffff009983f74();
              goto LAB_fffffff00996c460;
            }
            uVar34 = FUN_fffffff0099436e4(uVar13,uVar18);
            if ((int)uVar34 != 0) goto LAB_fffffff00996c300;
            FUN_fffffff0099437a0(uVar13);
            uVar21 = uVar20 + 1;
            uVar20 = uVar21;
          }
          uVar33 = uVar33 & (1L << (uVar24 & 0x3f) ^ 0xffffffffffffffffU);
        } while (uVar33 != 0);
      }
      uVar23 = (int)uVar31 + 1;
      uVar31 = (ulong)uVar23;
    } while (uVar23 <= *(uint *)(plVar15 + 0x16));
    uVar34 = 0;
  }
LAB_fffffff00996c300:
  if (DAT_fffffff00af227e8 != 0) {
    uVar13 = (**(code **)(*plVar15 + 0xe0))(plVar15);
    uStack_f8 = 0;
    thunk_EXT_FUN_80110000032db760(uVar13,&uStack_f8);
    uVar13 = uStack_f8;
    uVar14 = thunk_EXT_FUN_801100000390ebc0(plVar15[2]);
    thunk_EXT_FUN_80110000036da494(0x851801ca,uVar13,(int)uVar34 == 0,uVar18,uVar14,0);
  }
  return uVar34;
LAB_fffffff00996bfa4:
  uVar22 = 0;
  uVar9 = (int)param_1[0x15] - 1;
  uVar20 = *(uint *)(param_1 + 0x16);
  uVar18 = unaff_x24 >> ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
  uVar19 = (uint)uVar18;
  uVar23 = uVar19 >> 6;
  lVar30 = param_1[0x13];
  uVar33 = *(ulong *)(lVar30 + (ulong)uVar23 * 8) | -1L << (uVar18 & 0x3f) ^ 0xffffffffffffffffU;
  iVar28 = 0x40 - (uVar19 & 0x3f);
  iVar17 = uVar23 << 6;
  do {
    uVar23 = uVar23 + 1;
    if (uVar33 != 0xffffffffffffffff) {
      uVar33 = (~uVar33 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar33 & 0x5555555555555555) << 1;
      uVar33 = (uVar33 & 0xcccccccccccccccc) >> 2 | (uVar33 & 0x3333333333333333) << 2;
      uVar33 = (uVar33 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar33 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar33 = (uVar33 & 0xff00ff00ff00ff00) >> 8 | (uVar33 & 0xff00ff00ff00ff) << 8;
      uVar33 = (uVar33 & 0xffff0000ffff0000) >> 0x10 | (uVar33 & 0xffff0000ffff) << 0x10;
      uVar22 = (int)LZCOUNT(uVar33 >> 0x20 | uVar33 << 0x20) + iVar17;
      uVar33 = (ulong)uVar22;
      if (uVar22 - uVar19 < 0x80) goto LAB_fffffff00996be30;
      break;
    }
    lVar32 = (ulong)(uVar23 & uVar20) * 8;
    puVar5 = (ulong *)(lVar30 + (int)lVar32);
    if (lVar32 != (int)lVar32) {
      puVar5 = (ulong *)(lVar30 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar22 = iVar28 + uVar22;
    uVar33 = *puVar5;
    iVar17 = iVar17 + 0x40;
    iVar28 = 0x40;
  } while (uVar22 < 0x80);
  goto LAB_fffffff00996c040;
  while( true ) {
    uVar23 = uVar22 - 0x1f;
    if (0x1e < uVar22) {
      lVar32 = param_1[0x12];
      uVar25 = 0xffffffe1;
      while( true ) {
        uVar23 = uVar22 + uVar25;
        lVar27 = (ulong)(uVar23 & uVar9) * 4;
        puVar2 = (uint *)(lVar32 + (int)lVar27);
        if (lVar27 != (int)lVar27) {
          puVar2 = (uint *)(lVar32 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar6 = *puVar2;
        uVar8 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
        uVar8 = (uVar8 & 0xcccccccc) >> 2 | (uVar8 & 0x33333333) << 2;
        uVar8 = (uVar8 & 0xf0f0f0f0) >> 4 | (uVar8 & 0xf0f0f0f) << 4;
        uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
        uVar16 = (uint)LZCOUNT(uVar8 >> 0x10 | uVar8 << 0x10);
        uVar8 = uVar23 + uVar16;
        if (uVar6 != 0 && uVar8 < uVar22) break;
        uVar25 = uVar25 + 1;
        if (!CARRY4(uVar22,uVar25)) goto LAB_fffffff00996c040;
      }
      lVar27 = (ulong)(uVar23 & uVar9) * 4;
      puVar2 = (uint *)(lVar32 + (int)lVar27);
      if (lVar27 - (int)lVar27 != 0) {
        puVar2 = (uint *)(lVar32 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar10 = (ulong)(uVar8 & uVar9) * 8;
      lVar32 = param_1[0x10];
      lVar27 = param_1[0x11];
      iVar17 = (int)lVar10;
      puVar4 = (undefined8 *)(lVar32 + iVar17);
      if (lVar10 != iVar17) {
        puVar4 = (undefined8 *)(lVar32 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar13 = *puVar4;
      lVar11 = (ulong)(uVar8 & uVar9) * 4;
      puVar3 = (undefined4 *)(lVar27 + (int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar3 = (undefined4 *)(lVar27 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar7 = *puVar3;
      *puVar2 = uVar6 & (1 << (ulong)(uVar16 & 0x1f) ^ 0xffffffffU) | 1 << (ulong)(-uVar25 & 0x1f);
      uVar25 = uVar20 & uVar22 >> 6;
      *(ulong *)(lVar30 + (ulong)uVar25 * 8) =
           *(ulong *)(lVar30 + (ulong)uVar25 * 8) | 1L << (uVar33 & 0x3f);
      lVar30 = (ulong)(uVar22 & uVar9) * 8;
      puVar4 = (undefined8 *)(lVar32 + (int)lVar30);
      if (lVar30 != (int)lVar30) {
        puVar4 = (undefined8 *)(lVar32 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar4 = uVar13;
      lVar30 = (ulong)(uVar22 & uVar9) * 4;
      puVar3 = (undefined4 *)(lVar27 + (int)lVar30);
      if (lVar30 != (int)lVar30) {
        puVar3 = (undefined4 *)(lVar27 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = uVar7;
      puVar4 = (undefined8 *)(param_1[0x10] + (long)iVar17);
      if (lVar10 != iVar17) {
        puVar4 = (undefined8 *)(param_1[0x10] + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar4 = 0;
      lVar30 = param_1[0x13];
      uVar25 = uVar20 & uVar8 >> 6;
      *(ulong *)(lVar30 + (ulong)uVar25 * 8) =
           *(ulong *)(lVar30 + (ulong)uVar25 * 8) &
           (1L << ((ulong)uVar8 & 0x3f) ^ 0xffffffffffffffffU);
      uVar33 = (ulong)uVar8;
    }
    if (uVar23 == uVar22) break;
LAB_fffffff00996be30:
    uVar22 = (uint)uVar33;
    if (uVar22 - uVar19 < 0x20) {
      lVar32 = (ulong)(uVar22 & uVar9) * 8;
      lVar30 = param_1[0x11];
      puVar4 = (undefined8 *)(param_1[0x10] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar4 = (undefined8 *)(param_1[0x10] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar4 = plVar29;
      lVar32 = (ulong)(uVar22 & uVar9) * 4;
      puVar3 = (undefined4 *)(lVar30 + (int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar3 = (undefined4 *)(lVar30 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = 1;
      lVar32 = (uVar18 & 0xffffffff) * 4;
      lVar30 = param_1[0x13];
      puVar2 = (uint *)(param_1[0x12] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar2 = (uint *)(param_1[0x12] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar2 = *puVar2 | 1 << (ulong)(uVar22 - uVar19 & 0x1f);
      uVar20 = uVar20 & uVar22 >> 6;
      *(ulong *)(lVar30 + (ulong)uVar20 * 8) =
           *(ulong *)(lVar30 + (ulong)uVar20 * 8) | 1L << (uVar33 & 0x3f);
      lVar30 = (**(code **)(*plVar29 + 0x108))(*plVar29 + 0x108,plVar29);
      param_1[0x19] = param_1[0x19] + lVar30;
      *(int *)(param_1 + 0x17) = (int)param_1[0x17] + 1;
      (**(code **)(*plVar29 + 0x20))(plVar29);
      if (iVar35 != 0) goto LAB_fffffff00996c22c;
      iStack_6c = iStack_6c + 1;
      goto LAB_fffffff00996c158;
    }
  }
LAB_fffffff00996c040:
  uVar18 = FUN_fffffff00996a418(param_1 + 0x10,0);
  if ((uVar18 & 1) == 0) goto LAB_fffffff00996c228;
  goto LAB_fffffff00996bfa4;
}

