// FUN_fffffff0088c3d4c @ fffffff0088c3d4c size=1116 depth=1
// CALLERS:
//   fffffff00afcae89 ?
//   fffffff0088c319c FUN_fffffff0088c3194
// CALLS:
//   fffffff0088c21bc FUN_fffffff0088c21bc
//   fffffff008909364 thunk_FUN_fffffff00a27b31c
//   fffffff008908844 thunk_FUN_fffffff00a902580
//   fffffff008908b64 thunk_FUN_fffffff00a894f30
//   fffffff0089087d4 thunk_FUN_fffffff00a9026b0
//   fffffff0088fe778 FUN_fffffff0088fe778
//   fffffff0088c3bb0 FUN_fffffff0088c3bb0
//   fffffff008908a84 thunk_FUN_fffffff00a960120
//   fffffff008909154 thunk_FUN_fffffff00a1d14a0
//   fffffff008908934 thunk_FUN_fffffff00a8d8754
//   fffffff008909324 thunk_FUN_fffffff00a27b29c
//   fffffff0088fe5b8 FUN_fffffff0088fe5b8
//   fffffff0088fe588 FUN_fffffff0088fe588
//   fffffff0088fe734 FUN_fffffff0088fe734
//   fffffff0088fe664 FUN_fffffff0088fe664

ulong FUN_fffffff0088c3d4c
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                long param_8,undefined **param_9,ulong *param_10,undefined *param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  int iVar12;
  long *plVar13;
  ulong *puVar14;
  undefined **extraout_x0;
  ulong uVar15;
  ulong *puVar16;
  undefined ******ppppppuVar17;
  long *plVar18;
  long lVar19;
  long *plVar20;
  long extraout_x0_00;
  long *extraout_x0_01;
  uint *extraout_x1;
  undefined8 extraout_x1_00;
  ulong uVar21;
  undefined **ppuVar22;
  ulong uVar23;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined1 auVar25 [16];
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_07;
  undefined8 extraout_d0_08;
  undefined8 extraout_d0_09;
  undefined8 extraout_d0_10;
  undefined8 uVar24;
  undefined8 extraout_d0_11;
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined8 extraout_var_07;
  undefined8 extraout_var_08;
  undefined8 extraout_var_09;
  undefined8 extraout_var_10;
  undefined8 uVar27;
  undefined8 extraout_var_11;
  undefined1 auVar26 [16];
  undefined4 uVar28;
  undefined1 auVar29 [12];
  undefined4 uVar30;
  undefined1 auVar31 [12];
  undefined *local_d8;
  undefined8 local_d0;
  code *local_c8;
  undefined *local_c0;
  long *plStack_b8;
  uint *local_b0;
  undefined *local_a8;
  undefined **local_a0;
  ulong *puStack_98;
  long *local_90;
  long *plStack_88;
  undefined1 *local_80;
  undefined8 uStack_78;
  uint local_64;
  
  uVar30 = param_4._0_4_;
  auVar31 = param_4._4_12_;
  uVar28 = param_3._0_4_;
  auVar29 = param_3._4_12_;
  uVar21 = 0xe00002c2;
  ppuVar22 = (undefined **)(param_7 + 0xe0);
  if (*ppuVar22 != (undefined *)0x0) {
    plVar18 = (long *)0x0;
    plVar13 = (long *)0x0;
    uVar23 = 0xe00002c9;
    goto LAB_fffffff0088c3fe0;
  }
  plVar13 = FUN_fffffff0088c3bb0(param_7,param_8);
  uVar24 = extraout_d0;
  uVar27 = extraout_var;
  if (plVar13 != (long *)0x0) {
    puVar14 = (ulong *)(**(code **)(*plVar13 + 0xb0))(plVar13);
    param_1._8_8_ = extraout_var_00;
    param_1._0_8_ = extraout_d0_00;
    uVar23 = 0xe00002be;
    if (puVar14 == (ulong *)0x0) {
      plVar18 = (long *)0x0;
      goto LAB_fffffff0088c3fe0;
    }
    auVar1._8_8_ = extraout_var_00;
    auVar1._0_8_ = extraout_d0_00;
    auVar4._4_12_ = auVar29;
    auVar4._0_4_ = uVar28;
    auVar8._4_12_ = auVar31;
    auVar8._0_4_ = uVar30;
    thunk_FUN_fffffff00a902580(auVar1,param_2,auVar4,auVar8,param_5,param_6,puVar14);
    uVar24 = extraout_d0_01;
    uVar27 = extraout_var_01;
    if (extraout_x0 != (undefined **)0x0) {
      uVar15 = (**(code **)(*plVar13 + 0xd8))(plVar13,0);
      auVar25._8_8_ = extraout_var_02;
      auVar25._0_8_ = extraout_d0_02;
      if ((int)uVar15 == 0) {
        param_9 = extraout_x0;
        param_10 = puVar14;
        (**(code **)(*plVar13 + 200))(plVar13,0);
        (**(code **)(*plVar13 + 0xe0))(plVar13,0);
        puVar16 = (ulong *)thunk_FUN_fffffff00a1d14a0((ulong)extraout_x0,(long)puVar14);
        auVar25._8_8_ = extraout_var_03;
        auVar25._0_8_ = extraout_d0_03;
        uVar15 = uVar21;
        if (puVar16 < puVar14) {
          param_9 = (undefined **)0x0;
          ppppppuVar17 = thunk_FUN_fffffff00a8d8754
                                   ((char *)extraout_x0,(ulong)puVar14,(undefined8 *)0x0);
          plVar18 = thunk_FUN_fffffff00a894f30
                              ((long *)ppppppuVar17,*(long *)PTR_PTR_fffffff007db4718);
          auVar25._8_8_ = extraout_var_04;
          auVar25._0_8_ = extraout_d0_04;
          if (plVar18 != (long *)0x0) {
            lVar19 = (**(code **)(*plVar18 + 0x138))(plVar18,"IOUserClientClass");
            auVar25._8_8_ = extraout_var_05;
            auVar25._0_8_ = extraout_d0_05;
            if (lVar19 == 0) {
              lVar19 = (**(code **)(*plVar18 + 0x138))(plVar18,"IOClass");
              auVar25._8_8_ = extraout_var_06;
              auVar25._0_8_ = extraout_d0_06;
              if (lVar19 == 0) {
                lVar19 = (**(code **)(*plVar18 + 0x138))(plVar18,"IOProviderClass");
                auVar25._8_8_ = extraout_var_07;
                auVar25._0_8_ = extraout_d0_07;
                if (lVar19 == 0) {
                  lVar19 = (**(code **)(*plVar18 + 0x138))(plVar18,"IOKitDebug");
                  auVar25._8_8_ = extraout_var_08;
                  auVar25._0_8_ = extraout_d0_08;
                  if (lVar19 == 0) {
                    auVar2._8_8_ = extraout_var_08;
                    auVar2._0_8_ = extraout_d0_08;
                    auVar5._4_12_ = auVar29;
                    auVar5._0_4_ = uVar28;
                    auVar9._4_12_ = auVar31;
                    auVar9._0_4_ = uVar30;
                    plVar20 = FUN_fffffff0088c21bc
                                        (auVar2,param_2,auVar5,auVar9,param_5,param_6,plVar18);
                    auVar25._8_8_ = extraout_var_09;
                    auVar25._0_8_ = extraout_d0_09;
                    if ((long *)*ppuVar22 != (long *)0x0) {
                      auVar25 = (**(code **)(*(long *)*ppuVar22 + 0x28))();
                    }
                    *ppuVar22 = (undefined *)plVar20;
                    uVar15 = uVar23;
                    if (plVar20 != (long *)0x0) {
                      auVar6._4_12_ = auVar29;
                      auVar6._0_4_ = uVar28;
                      auVar10._4_12_ = auVar31;
                      auVar10._0_4_ = uVar30;
                      thunk_FUN_fffffff00a27b29c
                                (auVar25,param_2,auVar6,auVar10,param_5,param_6,-0xff773bfac,param_7
                                );
                      if (extraout_x0_00 == 0) {
                        auVar3._8_8_ = extraout_var_10;
                        auVar3._0_8_ = extraout_d0_10;
                        auVar7._4_12_ = auVar29;
                        auVar7._0_4_ = uVar28;
                        auVar11._4_12_ = auVar31;
                        auVar11._0_4_ = uVar30;
                        FUN_fffffff0088fe588(auVar3,param_2,auVar7,auVar11,param_5,param_6);
                        uStack_78 = 0xfffffff0088c4054;
                        plVar18 = (long *)extraout_x0_01[0x1c];
                        local_a0 = extraout_x0;
                        puStack_98 = puVar14;
                        local_90 = plVar20;
                        plStack_88 = plVar13;
                        local_80 = &stack0xfffffffffffffff0;
                        iVar12 = (**(code **)(*plVar18 + 0x360))(plVar18,extraout_x0_01);
                        auVar26._8_8_ = extraout_var_11;
                        auVar26._0_8_ = extraout_d0_11;
                        if (iVar12 != 0) {
                          iVar12 = (**(code **)(*(long *)extraout_x0_01[0x1c] + 0x2b0))
                                             ((long *)extraout_x0_01[0x1c],extraout_x0_01);
                          if (iVar12 != 0) goto LAB_fffffff0088c40e0;
                          auVar26 = FUN_fffffff0088fe734();
                        }
                        param_9 = &local_a8;
                        FUN_fffffff0088fe778
                                  (auVar26,param_2,uVar28,uVar30,param_5,param_6,extraout_x0_01,
                                   extraout_x0_01 + 0x1c,(long *)param_9);
LAB_fffffff0088c40e0:
                        local_d8 = PTR_DAT_fffffff007db4708;
                        local_d0 = DAT_fffffff00742dce0;
                        local_c8 = FUN_fffffff0088c41a8;
                        local_c0 = &DAT_fffffff007da5c98;
                        plStack_b8 = extraout_x0_01;
                        local_b0 = extraout_x1;
                        thunk_FUN_fffffff00a960120((long *)extraout_x0_01[0x1d],&local_d8);
                        (**(code **)(*extraout_x0_01 + 0x28))(extraout_x0_01);
                        uVar21 = thunk_FUN_fffffff00a27b31c
                                           (extraout_x1,extraout_x1_00,(ulong)param_9);
                        return uVar21;
                      }
                      param_10 = (ulong *)&local_64;
                      auVar25 = FUN_fffffff0088fe5b8(param_7,extraout_x0_00,(ulong)ppuVar22);
                      param_9 = ppuVar22;
                      uVar15 = (ulong)local_64;
                    }
                  }
                }
              }
            }
            goto LAB_fffffff0088c3fd4;
          }
          if (ppppppuVar17 != (undefined ******)0x0) {
            auVar25 = (*(code *)(*ppppppuVar17)[5])(ppppppuVar17);
          }
        }
        plVar18 = (long *)0x0;
      }
      else {
        plVar18 = (long *)0x0;
      }
LAB_fffffff0088c3fd4:
      param_1 = thunk_FUN_fffffff00a9026b0
                          (auVar25,param_2,uVar28,uVar30,param_5,param_6,extraout_x0,
                           (undefined *)puVar14,param_9,param_10,param_11);
      uVar23 = uVar15;
      goto LAB_fffffff0088c3fe0;
    }
  }
  param_1._8_8_ = uVar27;
  param_1._0_8_ = uVar24;
  plVar18 = (long *)0x0;
  uVar23 = 0xe00002bd;
LAB_fffffff0088c3fe0:
  FUN_fffffff0088fe664(param_1,param_2,uVar28,uVar30,param_5,param_6,plVar13,plVar18);
  return uVar23;
}

