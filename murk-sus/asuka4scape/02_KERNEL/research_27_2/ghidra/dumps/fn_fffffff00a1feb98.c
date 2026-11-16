// FUN_fffffff00a1feb98 @ fffffff00a1feb98 size=1848
// CALLERS:
//   fffffff00afb8389 no-fn
//   fffffff00a2a4aa8 FUN_fffffff00a2a4a54@fffffff00a2a4a54
// CALLEES:
//   fffffff00a21d6b8 FUN_fffffff00a21d6b8
//   fffffff00a1f1060 FUN_fffffff00a1f1060
//   fffffff00a220c30 FUN_fffffff00a220c30
//   fffffff00a2defc4 FUN_fffffff00a2defc4
//   fffffff00a22b850 FUN_fffffff00a22b850
//   fffffff00a2212a8 FUN_fffffff00a2212a8
//   fffffff00a1fac50 FUN_fffffff00a1fac50
//   fffffff00a22b804 FUN_fffffff00a22b804
//   fffffff00aa65cc0 FUN_fffffff00aa65cc0
//   fffffff00a2eb688 FUN_fffffff00a2eb688
//   fffffff00a1f036c FUN_fffffff00a1f036c
//   fffffff00a2ed330 FUN_fffffff00a2ed330
//   fffffff00a22b5a8 FUN_fffffff00a22b5a8
//   fffffff00a2dcc04 FUN_fffffff00a2dcc04
//   fffffff00aa61ea0 FUN_fffffff00aa61ea0
//   fffffff00a2df590 FUN_fffffff00a2df590

undefined8
FUN_fffffff00a1feb98
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,byte *param_7,
          undefined4 *param_8,undefined8 *param_9,undefined4 *param_10,undefined8 *param_11,
          undefined4 *param_12)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  long lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined8 extraout_x1;
  undefined4 *puVar11;
  undefined *puVar12;
  ulong uVar13;
  ulong *puVar14;
  ulong uVar15;
  ulong uVar16;
  undefined **ppuVar17;
  ulong uVar18;
  long lVar19;
  ulong uVar20;
  undefined **ppuVar21;
  uint *puVar22;
  undefined **ppuVar23;
  undefined **ppuVar24;
  undefined **ppuVar25;
  ulong *puVar26;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar27 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined4 uVar28;
  undefined1 auVar29 [12];
  undefined4 uVar30;
  undefined1 auVar31 [12];
  undefined8 local_68;
  
  uVar30 = param_4._0_4_;
  auVar31 = param_4._4_12_;
  uVar28 = param_3._0_4_;
  auVar29 = param_3._4_12_;
  puVar11 = param_10;
  puVar9 = param_11;
  puVar7 = (uint *)FUN_fffffff00a21d6b8(param_7,1,0xc);
  if (puVar7 == (uint *)0x0) {
    return 4;
  }
  local_68 = 0;
  lVar19 = tpidr_el1;
  *(int *)(lVar19 + 0x1c0) = *(int *)(lVar19 + 0x1c0) + 1;
  LOAcquire();
  uVar5 = puVar7[2];
  puVar7[2] = uVar5 + 0x1000000;
  if ((uVar5 >> 0x10 & 0xff) == uVar5 >> 0x18) {
    puVar7[3] = *(uint *)(lVar19 + 0x4e8);
  }
  else {
    FUN_fffffff00a22b5a8((long)puVar7,(ulong)(uVar5 >> 0x18),lVar19);
  }
  puVar14 = (ulong *)(puVar7 + 0x12);
  uVar15 = *puVar14;
  if (uVar15 != 0) {
    ppuVar23 = (undefined **)0x0;
    ppuVar21 = (undefined **)0x0;
    ppuVar24 = (undefined **)0x0;
    uVar20 = 0;
LAB_fffffff00a1fecb8:
    do {
      uVar18 = uVar20;
      ppuVar25 = ppuVar24;
      if (uVar15 == 0) break;
      uVar15 = *puVar14;
      if (uVar15 == 0) {
        uVar13 = 0;
        uVar16 = 0;
      }
      else {
        uVar16 = 0;
        if (uVar15 != 0) {
          uVar16 = uVar15;
        }
        uVar13 = 0;
        if (uVar15 != 0) {
          uVar13 = (uVar15 & 0x3fff) << 0xe;
        }
        if ((uVar15 & 0x4000000000) != 0) {
          uVar13 = (uVar15 & 0x10 | 0x20) << (uVar15 & 0xf);
          uVar16 = uVar15;
        }
      }
      if (DAT_fffffff007bc72a8 == (ulong *)0x0) {
        uVar6 = 0xe;
        uVar5 = 0x3fff;
      }
      else {
        uVar6 = (uint)*(byte *)((long)DAT_fffffff007bc72a8 + 0x2c);
        uVar5 = ~(-1 << (ulong)(*(byte *)((long)DAT_fffffff007bc72a8 + 0x2c) & 0x1f));
      }
      auVar27._8_8_ = 0;
      auVar27._0_8_ = uVar13;
      uVar18 = SUB168(auVar27 * ZEXT816(0xaaaaaaaaaaaaaab),8);
      ppuVar25 = (undefined **)
                 (ulong)(uVar5 + SUB164(auVar27 * ZEXT816(0xaaaaaaaaaaaaaab),8) * 0x1c &
                        -1 << (ulong)(uVar6 & 0x1f));
      if (ppuVar25 <= ppuVar24 && uVar20 == uVar18) {
        uVar15 = uVar20;
        if (0x17 < uVar13) {
          uVar18 = 0;
          uVar13 = uVar20;
          do {
            puVar22 = (uint *)((long)ppuVar21 + uVar18 * 0x1c);
            if ((((ulong)ppuVar21 ^ (ulong)puVar22) & 0xffc0000000000000) != 0) {
              puVar22 = (uint *)((ulong)puVar22 & 0xffffffffffff | 0xc8a2000000000000);
            }
            uVar15 = 0;
            if (uVar16 != 0) {
              uVar15 = uVar16 & 0xffffffffffffc000 | 0x4000000000;
            }
            if ((uVar16 & 0x4000000000) != 0) {
              uVar15 = uVar16 & 0xffffffffffffffe0;
            }
            puVar26 = (ulong *)(uVar15 + uVar18 * 0x18);
            if (((uVar15 ^ (ulong)puVar26) & 0xffc0000000000000) != 0) {
              puVar26 = (ulong *)((ulong)puVar26 & 0xffffffffffff | 0xc8a2000000000000);
            }
            if (uVar18 == 0) {
              uVar5 = 0xfc000000;
            }
            else {
              uVar5 = (uint)puVar26[1];
            }
            *puVar22 = (uint)((uVar18 << 0x20) >> 0x18) | uVar5 >> 0x18 | 3;
            puVar22[1] = 0;
            puVar22[2] = uVar5 & 0x1f0000;
            if (((uVar5 & 0x70000) != 0) && (*(int *)((long)puVar26 + 0xc) != 0)) {
              uVar15 = *puVar26;
              if (uVar15 == 0) {
                uVar15 = 0;
              }
              FUN_fffffff00a1f036c(uVar15);
              uVar6 = FUN_fffffff00a1f1060(uVar15,extraout_x1,*(uint *)((long)puVar26 + 0xc));
              puVar22[2] = puVar22[2] | uVar6;
              if ((*(byte *)(uVar15 + 2) & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1ff274);
                (*pcVar4)();
              }
              FUN_fffffff00a22b804(uVar15 + 0x14);
            }
            puVar22[3] = uVar5 & 0xffff;
            ppuVar23[uVar18] = (undefined *)*puVar26;
            puVar22[5] = *(uint *)((long)puVar26 + 0xc);
            puVar22[6] = *(uint *)((long)puVar26 + 0x14);
            uVar18 = uVar18 + 1;
            uVar15 = uVar13;
            if (((uVar18 & 0xfff) == 0) && (uVar18 < uVar13)) {
              FUN_fffffff00a22b850((long)puVar7);
              *(int *)(lVar19 + 0x1c0) = *(int *)(lVar19 + 0x1c0) + 1;
              LOAcquire();
              uVar5 = puVar7[2];
              puVar7[2] = uVar5 + 0x1000000;
              if ((uVar5 >> 0x10 & 0xff) == uVar5 >> 0x18) {
                puVar7[3] = *(uint *)(lVar19 + 0x4e8);
              }
              else {
                FUN_fffffff00a22b5a8((long)puVar7,(ulong)(uVar5 >> 0x18),lVar19);
              }
              if ((*puVar14 == 0) || (*puVar14 == 0)) goto LAB_fffffff00a1feca8;
              uVar16 = *puVar14;
              if (uVar16 == 0) {
                uVar16 = 0;
LAB_fffffff00a1fef40:
                uVar15 = 0;
              }
              else if ((uVar16 >> 0x26 & 1) == 0) {
                if (uVar16 == 0) goto LAB_fffffff00a1fef40;
                uVar15 = (uVar16 & 0x3fff) << 0xe;
              }
              else {
                uVar15 = (uVar16 & 0x10 | 0x20) << (uVar16 & 0xf);
              }
              auVar1._8_8_ = 0;
              auVar1._0_8_ = uVar15;
              uVar15 = SUB168(auVar1 * ZEXT816(0xaaaaaaaaaaaaaab),8);
              if (uVar13 < uVar15) goto LAB_fffffff00a1feca8;
            }
            uVar13 = uVar15;
            if (uVar15 <= uVar18) break;
          } while( true );
        }
        *param_8 = 0xff;
        param_8[1] = (int)uVar15;
        auVar27 = FUN_fffffff00a22b850((long)puVar7);
        if (ppuVar24 == (undefined **)0x0) {
          uVar28 = 0;
          *param_9 = 0;
        }
        else {
          ppuVar25 = (undefined **)(uVar15 * 0x1c);
          if (DAT_fffffff007bc72a8 == (ulong *)0x0) {
            uVar5 = 0xe;
            uVar18 = 0x3fff;
          }
          else {
            uVar5 = (uint)*(byte *)((long)DAT_fffffff007bc72a8 + 0x2c);
            uVar18 = (ulong)(uint)~(-1 << (ulong)(*(byte *)((long)DAT_fffffff007bc72a8 + 0x2c) &
                                                 0x1f));
          }
          ppuVar17 = (undefined **)(uVar18 + (long)ppuVar25 & (long)(-1 << (ulong)(uVar5 & 0x1f)));
          if (uVar15 != 0) {
            lVar19 = 0;
            uVar18 = uVar15;
            do {
              lVar8 = FUN_fffffff00a2df590((ulong)ppuVar23[lVar19],DAT_fffffff007c17560);
              uVar16 = (long)ppuVar21 + lVar19 * 0x1c;
              if ((((ulong)ppuVar21 ^ uVar16) & 0xffc0000000000000) != 0) {
                uVar16 = uVar16 & 0xffffffffffff | 0xc8a2000000000000;
              }
              *(int *)(uVar16 + 0x10) = (int)lVar8;
              ppuVar23[lVar19] = (undefined *)0x0;
              lVar19 = lVar19 + 1;
              uVar18 = uVar18 - 1;
              auVar27 = extraout_q0_02;
            } while (uVar18 != 0);
          }
          auVar27 = FUN_fffffff00a2212a8
                              (auVar27,param_2,uVar28,uVar30,param_5,param_6,
                               (long *)&DAT_fffffff007c81741,ppuVar23,(undefined *)(uVar20 << 3),
                               puVar11,(undefined *)puVar9);
          if (ppuVar17 <= ppuVar24 && (long)ppuVar24 - (long)ppuVar17 != 0) {
            FUN_fffffff00a2defc4
                      (auVar27,param_2,uVar28,uVar30,param_5,param_6,(uint *)DAT_fffffff007bc72a8,
                       (undefined **)((long)ppuVar17 + (long)ppuVar21),
                       (long)ppuVar24 - (long)ppuVar17,0,(undefined **)0x0);
            ppuVar24 = ppuVar17;
          }
          uVar15 = (long)ppuVar24 + uVar15 * -0x1c;
          if (ppuVar25 <= ppuVar24 && uVar15 != 0) {
            puVar9 = (undefined8 *)((long)ppuVar21 + (ulong)(uint)param_8[1] * 0x1c);
            if ((((ulong)ppuVar21 ^ (ulong)puVar9) & 0xffc0000000000000) != 0) {
              puVar9 = (undefined8 *)((ulong)puVar9 & 0xffffffffffff | 0xc8a2000000000000);
            }
            FUN_fffffff00aa65cc0(puVar9,uVar15);
          }
          FUN_fffffff00a2eb688
                    ((long)DAT_fffffff007bc72a8,(ulong)ppuVar21,(long)ppuVar24 + (long)ppuVar21,0,
                     -0xff8434738);
          FUN_fffffff00a2ed330(DAT_fffffff007bc72a8,ppuVar21,ppuVar25,(undefined **)0x1,&local_68);
          *param_9 = local_68;
          uVar28 = param_8[1];
        }
        uVar10 = 0;
        *param_10 = uVar28;
        *param_11 = 0;
        *param_12 = 0;
        goto LAB_fffffff00a1ff1dc;
      }
      auVar27 = FUN_fffffff00a22b850((long)puVar7);
      if (ppuVar24 != (undefined **)0x0) {
        uVar10 = 0;
        puVar12 = (undefined *)0x0;
        FUN_fffffff00a2defc4
                  (auVar27,param_2,uVar28,uVar30,param_5,param_6,(uint *)DAT_fffffff007bc72a8,
                   ppuVar21,(ulong)ppuVar24,0,(undefined **)0x0);
        FUN_fffffff00a2212a8
                  (extraout_q0,param_2,uVar28,uVar30,param_5,param_6,(long *)&DAT_fffffff007c816a1,
                   ppuVar23,(undefined *)(uVar20 << 3),uVar10,puVar12);
      }
      puVar9 = (undefined8 *)0x7;
      auVar27 = FUN_fffffff00a2dcc04
                          ((long *)DAT_fffffff007bc72a8,(ulong *)ppuVar25,(undefined ********)0x0,
                           (undefined ********)0x8000,(undefined ********)0x7,0);
      ppuVar21 = auVar27._8_8_;
      if (auVar27._0_4_ != 0) {
        uVar10 = 6;
        goto LAB_fffffff00a1ff1dc;
      }
      puVar11 = (undefined4 *)0x0;
      auVar2._4_12_ = auVar29;
      auVar2._0_4_ = uVar28;
      auVar3._4_12_ = auVar31;
      auVar3._0_4_ = uVar30;
      auVar27 = FUN_fffffff00a220c30
                          (extraout_q0_00,param_2,auVar2,auVar3,param_5,param_6,
                           (long *)&DAT_fffffff007c816f1,(ulong *)(uVar18 << 3),
                           (ulong *)&DAT_00000004,(undefined ********)0x0);
      ppuVar23 = auVar27._0_8_;
      if (ppuVar23 == (undefined **)0x0) {
        FUN_fffffff00a2defc4
                  (extraout_q0_01,param_2,uVar28,uVar30,param_5,param_6,(uint *)DAT_fffffff007bc72a8
                   ,ppuVar21,(ulong)ppuVar25,0,(undefined **)0x0);
        uVar10 = 6;
        goto LAB_fffffff00a1ff1dc;
      }
      *(int *)(lVar19 + 0x1c0) = *(int *)(lVar19 + 0x1c0) + 1;
      LOAcquire();
      uVar5 = puVar7[2];
      puVar7[2] = uVar5 + 0x1000000;
      if ((uVar5 >> 0x10 & 0xff) == uVar5 >> 0x18) {
        puVar7[3] = *(uint *)(lVar19 + 0x4e8);
      }
      else {
        FUN_fffffff00a22b5a8((long)puVar7,(ulong)(uVar5 >> 0x18),lVar19);
      }
      uVar15 = *puVar14;
      ppuVar24 = ppuVar25;
      uVar20 = uVar18;
    } while (uVar15 != 0);
    goto LAB_fffffff00a1ff224;
  }
  FUN_fffffff00a22b850((long)puVar7);
  uVar10 = 0x10;
LAB_fffffff00a1ff1dc:
  uVar5 = puVar7[4];
  puVar7[4] = uVar5 - 0x40;
  LORelease();
  if (0x3f < uVar5) {
    if ((uVar5 & 0xffffffc0) == 0x40) {
      FUN_fffffff00a1fac50(puVar7);
    }
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa61ea0();
LAB_fffffff00a1feca8:
  uVar15 = *puVar14;
  uVar18 = uVar20;
  ppuVar25 = ppuVar24;
  if (uVar15 == 0) goto LAB_fffffff00a1ff224;
  goto LAB_fffffff00a1fecb8;
LAB_fffffff00a1ff224:
  auVar27 = FUN_fffffff00a22b850((long)puVar7);
  if (ppuVar25 != (undefined **)0x0) {
    uVar10 = 0;
    puVar12 = (undefined *)0x0;
    FUN_fffffff00a2defc4
              (auVar27,param_2,uVar28,uVar30,param_5,param_6,(uint *)DAT_fffffff007bc72a8,ppuVar21,
               (ulong)ppuVar25,0,(undefined **)0x0);
    FUN_fffffff00a2212a8
              (extraout_q0_03,param_2,uVar28,uVar30,param_5,param_6,(long *)&DAT_fffffff007c81651,
               ppuVar23,(undefined *)(uVar18 << 3),uVar10,puVar12);
  }
  uVar10 = 0x10;
  goto LAB_fffffff00a1ff1dc;
}

