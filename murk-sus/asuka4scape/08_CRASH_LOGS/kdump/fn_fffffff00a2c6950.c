// FUN_fffffff00a2c6950 @ fffffff00a2c6950 size=3040
// CALLERS:
//   fffffff00afb9300 ?
//   fffffff00a2c6840 FUN_fffffff00a2c6284@fffffff00a2c6284
// CALLS:
//   fffffff00a2de0fc FUN_fffffff00a2de0fc
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a247a70 FUN_fffffff00a247a70
//   fffffff00a3ec1d8 FUN_fffffff00a3ec1d8
//   fffffff00a3f1334 FUN_fffffff00a3f1334
//   fffffff00a2dcc04 FUN_fffffff00a2dcc04
//   fffffff00a2c7710 FUN_fffffff00a2c7710
//   fffffff00a2bf044 FUN_fffffff00a2bf044
//   fffffff00a2c0e50 FUN_fffffff00a2c0e50
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a2c0f88 FUN_fffffff00a2c0f88
//   fffffff00aa65b10 FUN_fffffff00aa65b10
//   fffffff00a28c5d4 FUN_fffffff00a28c5d4
//   fffffff00a22e064 FUN_fffffff00a22e064
//   fffffff00a246cd0 FUN_fffffff00a246cd0
//   fffffff00a3e8aa8 FUN_fffffff00a3e8aa8
//   fffffff00a402304 FUN_fffffff00a402304
//   fffffff00a2212a8 FUN_fffffff00a2212a8
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a2c7530 FUN_fffffff00a2c7530
//   fffffff00a7e0f00 FUN_fffffff00a7e0f00
//   fffffff00a2defc4 FUN_fffffff00a2defc4

void FUN_fffffff00a2c6950
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
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
  code *pcVar15;
  ulong uVar16;
  uint uVar17;
  int iVar18;
  undefined8 uVar19;
  undefined **extraout_x1;
  undefined **extraout_x1_00;
  undefined8 extraout_x1_01;
  undefined8 extraout_x1_02;
  undefined **ppuVar21;
  undefined **extraout_x1_03;
  undefined **extraout_x1_04;
  uint *puVar22;
  undefined ********ppppppppuVar23;
  undefined8 ***pppuVar24;
  undefined *puVar25;
  ulong uVar26;
  ulong uVar27;
  long lVar28;
  undefined8 *puVar29;
  long lVar30;
  undefined8 *puVar31;
  uint *puVar32;
  ulong uVar33;
  uint *puVar34;
  undefined4 *****pppppuVar35;
  uint in_wzr;
  undefined8 extraout_d0;
  undefined8 extraout_var;
  undefined1 auVar36 [16];
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_07;
  undefined8 extraout_d0_08;
  undefined8 extraout_d0_09;
  undefined8 extraout_d0_10;
  undefined8 extraout_d0_11;
  undefined8 extraout_d0_12;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined8 extraout_var_07;
  undefined8 extraout_var_08;
  undefined8 extraout_var_09;
  undefined8 extraout_var_10;
  undefined8 extraout_var_11;
  undefined8 extraout_var_12;
  undefined1 auVar37 [16];
  undefined4 uVar38;
  undefined1 auVar39 [12];
  undefined4 uVar40;
  undefined1 auVar41 [12];
  undefined1 auVar42 [16];
  undefined4 *****local_68;
  undefined **ppuVar20;
  
  uVar40 = param_4._0_4_;
  auVar41 = param_4._4_12_;
  uVar38 = param_3._0_4_;
  auVar39 = param_3._4_12_;
  local_68 = (undefined4 *****)0x0;
  puVar22 = (uint *)0x8101;
  pppuVar24 = (undefined8 ***)0xe;
  auVar42 = FUN_fffffff00a2dcc04
                      ((long *)DAT_fffffff00ad46000,(ulong *)(ulong)DAT_fffffff00ad950ec,
                       (undefined ********)0x0,(undefined ********)0x8101,(undefined ********)0xe,0)
  ;
  auVar36._8_8_ = extraout_var;
  auVar36._0_8_ = extraout_d0;
  ppuVar20 = auVar42._8_8_;
  lVar4 = tpidr_el1;
  ppuVar21 = ppuVar20;
  uVar33 = (ulong)*(uint *)(lVar4 + 0x4e8);
  if (DAT_fffffff00ad8a2e8 != 0) {
    auVar36 = FUN_fffffff00a2262d4(0xfffffff00ad8a2e0,lVar4,(undefined **)0x0);
    ppuVar21 = extraout_x1_03;
    uVar33 = DAT_fffffff00ad8a2e8;
  }
  while (DAT_fffffff00ad8a2e8 = uVar33, (DAT_fffffff00adb9d61 & 1) != 0) {
    while( true ) {
      auVar36 = FUN_fffffff00a246cd0((uint *)&DAT_fffffff00adb9d61,0);
      if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar4 + 0x4e8)) {
        DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
      }
      else {
        auVar36 = FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar4,(uint)DAT_fffffff00ad8a2e8);
      }
      FUN_fffffff00a247a70
                (auVar36,param_2,uVar38,uVar40,param_5,param_6,0,0,0,(ulong)puVar22,(ulong)pppuVar24
                );
      auVar36._8_8_ = extraout_var_00;
      auVar36._0_8_ = extraout_d0_00;
      ppuVar21 = extraout_x1;
      uVar33 = (ulong)*(uint *)(lVar4 + 0x4e8);
      if (DAT_fffffff00ad8a2e8 == 0) break;
      auVar36 = FUN_fffffff00a2262d4(0xfffffff00ad8a2e0,lVar4,(undefined **)0x0);
      ppuVar21 = extraout_x1_00;
      if ((DAT_fffffff00adb9d61 & 1) == 0) goto LAB_fffffff00a2c6a54;
    }
  }
LAB_fffffff00a2c6a54:
  puVar31 = &DAT_fffffff00ad44380;
  if ((undefined8 **)DAT_fffffff00ad44380 == &DAT_fffffff00ad44380) goto LAB_fffffff00a2c7328;
  puVar31 = (undefined8 *)0x0;
  uVar33 = 0;
  puVar29 = DAT_fffffff00ad44380;
  if (DAT_fffffff00ad44390 != 0) {
    uVar33 = DAT_fffffff007c1d770 / DAT_fffffff00ad44390;
  }
  do {
    if (((*(byte *)(puVar29 + 8) & 1) != 0) && (*(uint *)(puVar29 + 7) <= uVar33)) {
      uVar33 = (ulong)*(uint *)(puVar29 + 7);
      puVar31 = puVar29;
    }
    puVar29 = (undefined8 *)*puVar29;
  } while ((undefined8 **)puVar29 != &DAT_fffffff00ad44380);
  if (puVar31 == (undefined8 *)0x0) {
    puVar31 = &DAT_fffffff00ad44380;
    goto LAB_fffffff00a2c7328;
  }
  puVar32 = (uint *)(puVar31 + 8);
  *puVar32 = *puVar32 & 0xfffffffc | 2;
  uVar33 = DAT_fffffff00ad8a2e8;
  if (*(int *)(puVar31 + 0xc) == 0) {
LAB_fffffff00a2c6afc:
    DAT_fffffff00ad8a2e8 = uVar33;
    iVar18 = *(int *)((long)puVar31 + 0x34);
  }
  else {
    uVar3 = (uint)DAT_fffffff00ad8a2e8;
    if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar4 + 0x4e8)) {
      DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
    }
    uVar33 = uVar33 & 0xffffffff;
    if (uVar3 != *(uint *)(lVar4 + 0x4e8)) {
      auVar36 = FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar4,uVar3);
      ppuVar21 = extraout_x1_04;
    }
    auVar42._4_12_ = auVar39;
    auVar42._0_4_ = uVar38;
    auVar12._4_12_ = auVar41;
    auVar12._0_4_ = uVar40;
    FUN_fffffff00a2c7530
              (auVar36,param_2,auVar42,auVar12,param_5,param_6,(long)puVar31,ppuVar21,uVar33,puVar22
               ,(undefined4 **)pppuVar24);
    auVar36._8_8_ = extraout_var_01;
    auVar36._0_8_ = extraout_d0_01;
    uVar33 = (ulong)*(uint *)(lVar4 + 0x4e8);
    if (DAT_fffffff00ad8a2e8 == 0) goto LAB_fffffff00a2c6afc;
    auVar36 = FUN_fffffff00a2262d4(0xfffffff00ad8a2e0,lVar4,(undefined **)0x0);
    iVar18 = *(int *)((long)puVar31 + 0x34);
  }
  if (iVar18 != 0) {
    uVar33 = 0;
LAB_fffffff00a2c6b14:
    uVar26 = uVar33 >> 3;
    uVar3 = 1 << (ulong)((uint)uVar33 & 7);
    uVar27 = DAT_fffffff00ad8a2e8;
    do {
      while (DAT_fffffff00ad8a2e8 = uVar27, *(int *)(puVar31 + 9) != 0) {
        *puVar32 = *puVar32 | 4;
        auVar36 = FUN_fffffff00a246cd0(puVar32,0);
        if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar4 + 0x4e8)) {
          DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
        }
        else {
          auVar36 = FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar4,(uint)DAT_fffffff00ad8a2e8);
        }
        FUN_fffffff00a247a70
                  (auVar36,param_2,uVar38,uVar40,param_5,param_6,0,0,0,(ulong)puVar22,
                   (ulong)pppuVar24);
        auVar36._8_8_ = extraout_var_02;
        auVar36._0_8_ = extraout_d0_02;
LAB_fffffff00a2c6b78:
        uVar27 = (ulong)*(uint *)(lVar4 + 0x4e8);
        if (DAT_fffffff00ad8a2e8 != 0) {
          auVar36 = FUN_fffffff00a2262d4(0xfffffff00ad8a2e0,lVar4,(undefined **)0x0);
          uVar27 = DAT_fffffff00ad8a2e8;
        }
      }
      if ((DAT_fffffff00ad950f0 == 1) ||
         (((DAT_fffffff00ad44378 == 0 &&
           ((uint)(DAT_fffffff00ad95040 - DAT_fffffff00ad95048) <= DAT_fffffff00ad95060)) ||
          (DAT_fffffff00ad94ff0 + DAT_fffffff00ad94fec + DAT_fffffff00ad94ff4 != 0 &&
           DAT_fffffff00ad0e390 == 0)))) {
        DAT_fffffff00ad44410 = DAT_fffffff00ad44410 + 1;
        break;
      }
      if ((uVar3 & *(byte *)(puVar31[5] + uVar26)) == 0) goto LAB_fffffff00a2c71ac;
      puVar34 = *(uint **)(puVar31[10] + uVar33 * 8);
      *(int *)(lVar4 + 0x1c0) = *(int *)(lVar4 + 0x1c0) + 1;
      if (*(ulong *)(puVar34 + 2) == 0) {
        *(ulong *)(puVar34 + 2) = (ulong)*(uint *)(lVar4 + 0x4e8) | 0x30000000;
        uVar2 = *(ushort *)((long)puVar34 + 0x89);
      }
      else {
        FUN_fffffff00a2262d4((ulong)puVar34,lVar4,(undefined **)0x2);
        uVar2 = *(ushort *)((long)puVar34 + 0x89);
      }
      if ((uVar2 & 1) != 0) {
        if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar4 + 0x4e8)) {
          DAT_fffffff00ad8a2e8._4_4_ = (undefined4)(DAT_fffffff00ad8a2e8 >> 0x20);
          DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
        }
        else {
          FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar4,(uint)DAT_fffffff00ad8a2e8);
        }
        auVar36 = FUN_fffffff00a2bf044(puVar34);
        goto LAB_fffffff00a2c6b78;
      }
      *(byte *)(puVar31[5] + uVar26) = *(byte *)(puVar31[5] + uVar26) & ~(byte)uVar3;
      pppppuVar35 = (undefined4 *****)(DAT_fffffff00ad44390 * uVar33);
      *(undefined8 *)(puVar31[10] + uVar33 * 8) = 0;
      *(int *)(puVar31 + 7) = *(int *)(puVar31 + 7) + -1;
      DAT_fffffff00ad95048 = DAT_fffffff00ad95048 + -1;
      local_68 = pppppuVar35;
      if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar4 + 0x4e8)) {
        DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
      }
      else {
        FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar4,(uint)DAT_fffffff00ad8a2e8);
      }
      *(long *)(puVar34 + 0x1e) = lVar4;
      *(ushort *)((long)puVar34 + 0x89) = *(ushort *)((long)puVar34 + 0x89) | 3;
      uVar17 = FUN_fffffff00a2c0e50((long)puVar34);
      if (uVar17 != 0) {
        uVar27 = (ulong)uVar17;
        if (DAT_fffffff00ad94fa0 < uVar27) {
                    /* WARNING: Does not return */
          pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c7430);
          DAT_fffffff00ad94fa0 = DAT_fffffff00ad94fa0 - uVar27;
          (*pcVar15)();
        }
        uVar16 = *(ulong *)(&DAT_fffffff00ad94fa8 +
                           ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8);
        DAT_fffffff00ad94fa0 = DAT_fffffff00ad94fa0 - uVar27;
        *(ulong *)(&DAT_fffffff00ad94fa8 +
                  ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8) = uVar16 - uVar27;
        if (uVar16 < uVar27) {
                    /* WARNING: Does not return */
          pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c743c);
          (*pcVar15)();
        }
      }
      uVar17 = puVar34[0x1b] * 4 + 0x3fff;
      if (0xffffc000 < puVar34[0x1b] * 4) {
        auVar5._8_8_ = extraout_var_03;
        auVar5._0_8_ = extraout_d0_03;
        auVar10._4_12_ = auVar39;
        auVar10._0_4_ = uVar38;
        auVar13._4_12_ = auVar41;
        auVar13._0_4_ = uVar40;
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114
                  (auVar5,param_2,auVar10,auVar13,param_5,param_6,(byte *)"overflow detected @%s:%d"
                  );
      }
      uVar1 = puVar34[2];
      if (uVar1 == *(uint *)(lVar4 + 0x4e8)) {
        puVar34[2] = in_wzr;
      }
      else {
        FUN_fffffff00a226e08((ulong)puVar34,lVar4,uVar1);
      }
      iVar18 = FUN_fffffff00a3ec1d8(puVar31[3]);
      auVar36._8_8_ = extraout_var_04;
      auVar36._0_8_ = extraout_d0_04;
      if (iVar18 == 0) {
        uVar1 = uVar17 >> 0xe;
        uVar16 = (ulong)uVar1;
        pppuVar24 = (undefined8 ***)0x1;
        ppuVar21 = ppuVar20;
        uVar27 = uVar16;
        iVar18 = FUN_fffffff00a7e0f00
                           ((undefined8 *)puVar31[3],pppppuVar35,ppuVar20,uVar1,1,
                            (undefined4 ****)0x0);
        if (iVar18 == 0) {
          uVar17 = uVar17 & 0xffffc000;
          FUN_fffffff00a3e8aa8
                    ((undefined8 *)puVar31[3],extraout_x1_01,ppuVar21,uVar27,
                     (undefined4 **)pppuVar24);
          *(ulong *)(PTR_DAT_fffffff00ad18900 + (ulong)*(ushort *)(lVar4 + 0x1b0) * 0x4000) =
               *(long *)(PTR_DAT_fffffff00ad18900 + (ulong)*(ushort *)(lVar4 + 0x1b0) * 0x4000) +
               uVar16;
          DAT_fffffff00ad95080 = DAT_fffffff00ad95080 + uVar16;
          pppuVar24 = (undefined8 ***)0x0;
          auVar6._8_8_ = extraout_var_07;
          auVar6._0_8_ = extraout_d0_07;
          puVar22 = puVar34;
          uVar19 = FUN_fffffff00a2c7710
                             (auVar6,param_2,uVar38,uVar40,param_5,param_6,ppuVar20,
                              (ulong *)&local_68,uVar17,puVar34,(undefined4 **)0x0);
          auVar36._8_8_ = extraout_var_08;
          auVar36._0_8_ = extraout_d0_08;
          if ((int)uVar19 == 0) {
            *(ulong *)(PTR_DAT_fffffff00ad188f8 + (ulong)*(ushort *)(lVar4 + 0x1b0) * 0x4000) =
                 *(long *)(PTR_DAT_fffffff00ad188f8 + (ulong)*(ushort *)(lVar4 + 0x1b0) * 0x4000) +
                 uVar16;
            *(int *)(lVar4 + 0x1c0) = *(int *)(lVar4 + 0x1c0) + 1;
            if (*(ulong *)(puVar34 + 2) == 0) {
              *(ulong *)(puVar34 + 2) = (ulong)*(uint *)(lVar4 + 0x4e8) | 0x30000000;
            }
            else {
              auVar36 = FUN_fffffff00a2262d4((ulong)puVar34,lVar4,(undefined **)0x2);
            }
            *(undefined1 *)(puVar34 + 0x22) = 0;
            *(undefined4 ******)(puVar34 + 0x1c) = local_68;
            *(ushort *)((long)puVar34 + 0x89) = *(ushort *)((long)puVar34 + 0x89) & 0xfffd;
          }
          else {
            puVar29 = (undefined8 *)
                      (DAT_fffffff00ad6d0b0 + (ulong)DAT_fffffff00ad8a910 * (ulong)puVar34[0x12]);
            FUN_fffffff00a2de0fc
                      ((long)puVar29,(undefined **)(ulong)uVar17,0x201,(undefined **)0xe,
                       (byte)pppuVar24);
            FUN_fffffff00aa65b10(puVar29,ppuVar20,(ulong)uVar17);
            *(undefined8 **)(puVar34 + 0x1c) = puVar29;
            puVar22 = (uint *)0x0;
            auVar36 = FUN_fffffff00a2c0f88((undefined8 *)puVar34,1,1,0);
            DAT_fffffff00ad8a468 = DAT_fffffff00ad8a468 + (int)puVar34[0x16];
            uVar17 = puVar34[0x18];
            iVar18 = DAT_fffffff00ad94f60 + uVar17;
            lVar30 = (ulong)uVar17 + (long)DAT_fffffff00ad94f60;
            lVar28 = lVar30 * 0x80000000;
            DAT_fffffff00ad94f60 = iVar18;
            if ((lVar30 != lVar28 >> 0x1f) || (lVar28 + 0x4000000000000000 >> 0x1f < 0)) {
                    /* WARNING: Does not return */
              pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c74d8);
              (*pcVar15)();
            }
            if ((*(ushort *)((long)puVar34 + 0x89) >> 9 & 1) != 0) {
              iVar18 = DAT_fffffff00ad94f64 + uVar17;
              lVar30 = (ulong)uVar17 + (long)DAT_fffffff00ad94f64;
              lVar28 = lVar30 * 0x80000000;
              DAT_fffffff00ad94f64 = iVar18;
              if ((lVar30 != lVar28 >> 0x1f) || (lVar28 + 0x4000000000000000 >> 0x1f < 0)) {
                    /* WARNING: Does not return */
                pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c7514);
                (*pcVar15)();
              }
            }
            if (DAT_fffffff00ad94fa0 < uVar16) {
                    /* WARNING: Does not return */
              pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c74e4);
              DAT_fffffff00ad94fa0 = DAT_fffffff00ad94fa0 - uVar16;
              (*pcVar15)();
            }
            uVar27 = *(ulong *)(&DAT_fffffff00ad94fa8 +
                               ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8);
            DAT_fffffff00ad94fa0 = DAT_fffffff00ad94fa0 - uVar16;
            *(ulong *)(&DAT_fffffff00ad94fa8 +
                      ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8) = uVar27 - uVar16;
            if (uVar27 < uVar16) {
                    /* WARNING: Does not return */
              pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c74f0);
              (*pcVar15)();
            }
            uVar17 = puVar34[0x18];
            if (DAT_fffffff00ad94f6c < uVar17) {
                    /* WARNING: Does not return */
              pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c74fc);
              DAT_fffffff00ad94f6c = DAT_fffffff00ad94f6c - uVar17;
              (*pcVar15)();
            }
            uVar27 = *(ulong *)(&DAT_fffffff00ad94f70 +
                               ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8);
            DAT_fffffff00ad94f6c = DAT_fffffff00ad94f6c - uVar17;
            *(ulong *)(&DAT_fffffff00ad94f70 +
                      ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8) = uVar27 - uVar17;
            if (uVar27 < uVar17) {
                    /* WARNING: Does not return */
              pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c7508);
              (*pcVar15)();
            }
            *(ushort *)((long)puVar34 + 0x89) = *(ushort *)((long)puVar34 + 0x89) & 0xe3ff;
          }
        }
        else {
          ppuVar21 = (undefined **)0x1;
          puVar22 = (uint *)0x0;
          FUN_fffffff00a2c0f88((undefined8 *)puVar34,0,1,0);
          if (DAT_fffffff00ad94fa0 < uVar16) {
                    /* WARNING: Does not return */
            pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c7448);
            DAT_fffffff00ad94fa0 = DAT_fffffff00ad94fa0 - uVar16;
            (*pcVar15)();
          }
          uVar27 = *(ulong *)(&DAT_fffffff00ad94fa8 +
                             ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8);
          DAT_fffffff00ad94fa0 = DAT_fffffff00ad94fa0 - uVar16;
          *(ulong *)(&DAT_fffffff00ad94fa8 +
                    ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8) = uVar27 - uVar16;
          if (uVar27 < uVar16) {
                    /* WARNING: Does not return */
            pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c7454);
            (*pcVar15)();
          }
          uVar17 = puVar34[0x18];
          if (DAT_fffffff00ad94f6c < uVar17) {
                    /* WARNING: Does not return */
            pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c7460);
            DAT_fffffff00ad94f6c = DAT_fffffff00ad94f6c - uVar17;
            (*pcVar15)();
          }
          uVar27 = *(ulong *)(&DAT_fffffff00ad94f70 +
                             ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8);
          DAT_fffffff00ad94f6c = DAT_fffffff00ad94f6c - uVar17;
          *(ulong *)(&DAT_fffffff00ad94f70 +
                    ((ulong)(*(ushort *)((long)puVar34 + 0x89) >> 10) & 7) * 8) = uVar27 - uVar17;
          if (uVar27 < uVar17) {
                    /* WARNING: Does not return */
            pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2c746c);
            (*pcVar15)();
          }
          *(ushort *)((long)puVar34 + 0x89) = *(ushort *)((long)puVar34 + 0x89) & 0xe3ff;
          FUN_fffffff00a3e8aa8
                    ((undefined8 *)puVar31[3],extraout_x1_02,ppuVar21,puVar22,
                     (undefined4 **)pppuVar24);
          auVar36._8_8_ = extraout_var_05;
          auVar36._0_8_ = extraout_d0_05;
          *(long *)(PTR_DAT_fffffff00ad0e3a0 + (ulong)*(ushort *)(lVar4 + 0x1b0) * 0x4000) =
               *(long *)(PTR_DAT_fffffff00ad0e3a0 + (ulong)*(ushort *)(lVar4 + 0x1b0) * 0x4000) + 1;
        }
      }
      else {
        *(long *)(PTR_DAT_fffffff00ad0e3a0 + (ulong)*(ushort *)(lVar4 + 0x1b0) * 0x4000) =
             *(long *)(PTR_DAT_fffffff00ad0e3a0 + (ulong)*(ushort *)(lVar4 + 0x1b0) * 0x4000) + 1;
      }
      uVar2 = *(ushort *)((long)puVar34 + 0x89);
      *(ushort *)((long)puVar34 + 0x89) = uVar2 & 0xfffe;
      puVar34[0x1e] = 0;
      puVar34[0x1f] = 0;
      if ((uVar2 >> 2 & 1) != 0) {
        *(ushort *)((long)puVar34 + 0x89) = uVar2 & 0xfffa;
        puVar22 = (uint *)0x0;
        pppuVar24 = (undefined8 ***)0x0;
        FUN_fffffff00a22e064((ulong)puVar34,(undefined **)0x0,2,0,(ulong *)0x0);
        auVar36._8_8_ = extraout_var_06;
        auVar36._0_8_ = extraout_d0_06;
      }
      uVar17 = puVar34[2];
      if (uVar17 == *(uint *)(lVar4 + 0x4e8)) {
        puVar34[2] = in_wzr;
      }
      else {
        auVar36 = FUN_fffffff00a226e08((ulong)puVar34,lVar4,uVar17);
      }
      uVar27 = (ulong)*(uint *)(lVar4 + 0x4e8);
      if (DAT_fffffff00ad8a2e8 != 0) {
        auVar36 = FUN_fffffff00a2262d4(0xfffffff00ad8a2e0,lVar4,(undefined **)0x0);
        uVar27 = DAT_fffffff00ad8a2e8;
      }
      DAT_fffffff00ad8a2e8 = uVar27;
      uVar27 = DAT_fffffff00ad8a2e8;
      if (*(uint *)((long)puVar31 + 0x34) <= (uint)uVar33) break;
    } while( true );
  }
LAB_fffffff00a2c71e4:
  if (*(int *)(puVar31 + 7) == 0) {
    DAT_fffffff00ad95040 = DAT_fffffff00ad95040 - *(int *)((long)puVar31 + 0x34);
    if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar4 + 0x4e8)) {
      DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
    }
    else {
      FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar4,(uint)DAT_fffffff00ad8a2e8);
    }
    ppppppppuVar23 = (undefined ********)puVar31[2];
    puVar29 = (undefined8 *)puVar31[3];
    FUN_fffffff00a3ec1d8((ulong)puVar29);
    auVar7._8_8_ = extraout_var_09;
    auVar7._0_8_ = extraout_d0_09;
    FUN_fffffff00a3f1334
              (auVar7,param_2,uVar38,uVar40,param_5,param_6,puVar29,0,
               (undefined8 ***)&DAT_fffffff007c07e10,puVar22,pppuVar24);
    puVar25 = (undefined *)0x2;
    auVar8._8_8_ = extraout_var_10;
    auVar8._0_8_ = extraout_d0_10;
    auVar11._4_12_ = auVar39;
    auVar11._0_4_ = uVar38;
    auVar14._4_12_ = auVar41;
    auVar14._0_4_ = uVar40;
    FUN_fffffff00a402304
              (auVar8,param_2,auVar11,auVar14,param_5,param_6,
               (undefined ********)&DAT_fffffff007c07e10,-2,(undefined4 ***)0x0,ppppppppuVar23,
               (undefined ********)0x2,0);
    ppuVar21 = (undefined **)puVar31[10];
    puVar31[10] = 0;
    auVar9._8_8_ = extraout_var_11;
    auVar9._0_8_ = extraout_d0_11;
    auVar36 = FUN_fffffff00a2212a8
                        (auVar9,param_2,uVar38,uVar40,param_5,param_6,(long *)&DAT_fffffff007c82731,
                         ppuVar21,(undefined *)((ulong)*(uint *)((long)puVar31 + 0x34) << 3),
                         ppppppppuVar23,puVar25);
    uVar3 = *(uint *)((long)puVar31 + 0x34);
    if (uVar3 < 0x10) {
      uVar3 = 0xf;
    }
    ppuVar21 = (undefined **)puVar31[5];
    puVar31[5] = 0;
    FUN_fffffff00a2212a8
              (auVar36,param_2,uVar38,uVar40,param_5,param_6,&DAT_fffffff007c6afb0,ppuVar21,
               (undefined *)(ulong)(uVar3 >> 3),ppppppppuVar23,puVar25);
    uVar33 = (ulong)*(uint *)(lVar4 + 0x4e8);
    if (DAT_fffffff00ad8a2e8 != 0) {
      FUN_fffffff00a2262d4(0xfffffff00ad8a2e0,lVar4,(undefined **)0x0);
      uVar33 = DAT_fffffff00ad8a2e8;
    }
    DAT_fffffff00ad8a2e8 = uVar33;
    if (((byte)*puVar32 >> 4 & 1) != 0) {
      DAT_fffffff00ad44328 = DAT_fffffff00ad44328 + -1;
      DAT_fffffff00ad44350 = DAT_fffffff00ad44350 + puVar31[4];
    }
    puVar31[4] = 0;
    puVar31[3] = 0;
    *(undefined4 *)((long)puVar31 + 0x34) = 0;
    auVar36._8_8_ = 0;
    auVar36._0_8_ = DAT_fffffff00700d9e0;
    puVar31[8] = DAT_fffffff00700d9e0;
    DAT_fffffff00ad9503c = DAT_fffffff00ad9503c + -1;
  }
  else {
    *puVar32 = *puVar32 & 0xfffffffc | 1;
  }
LAB_fffffff00a2c7328:
  puVar31 = puVar31 + 8;
  uVar33 = ((ulong)puVar31 ^ (ulong)puVar31 >> 0x1f) * 0x7fb5d329728ea185;
  lVar30 = (uVar33 ^ uVar33 >> 0x1b) * -0x7e25210b43d22bb3;
  puVar22 = (uint *)(PTR_DAT_fffffff007bc7040 +
                    (ulong)(DAT_fffffff007bc7048 - 1U &
                           ((uint)((ulong)lVar30 >> 0x21) ^ (uint)lVar30)) * 0x18);
  if ((((ulong)PTR_DAT_fffffff007bc7040 ^ (ulong)puVar22) & 0xffc0000000000000) != 0) {
    puVar22 = (uint *)((ulong)puVar22 & 0xffffffffffff | 0xc8a2000000000000);
  }
  FUN_fffffff00a28c5d4
            (auVar36,param_2,uVar38,uVar40,param_5,param_6,puVar22,(long)puVar31,0,0,0xffffffff);
  auVar37._8_8_ = extraout_var_12;
  auVar37._0_8_ = extraout_d0_12;
  if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar4 + 0x4e8)) {
    DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
  }
  else {
    auVar37 = FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar4,(uint)DAT_fffffff00ad8a2e8);
  }
  FUN_fffffff00a2defc4
            (auVar37,param_2,uVar38,uVar40,param_5,param_6,DAT_fffffff00ad46000,ppuVar20,
             (ulong)DAT_fffffff00ad950ec,0,(undefined **)0x0);
  return;
LAB_fffffff00a2c71ac:
  uVar33 = uVar33 + 1;
  if (*(uint *)((long)puVar31 + 0x34) <= uVar33) goto LAB_fffffff00a2c71e4;
  goto LAB_fffffff00a2c6b14;
}

