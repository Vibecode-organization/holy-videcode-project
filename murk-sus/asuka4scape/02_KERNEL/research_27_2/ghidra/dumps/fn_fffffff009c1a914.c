// FUN_fffffff009c1a914 @ fffffff009c1a914 size=1536
// CALLERS:
//   fffffff00afebcbf no-fn
//   fffffff009c33cac FUN_fffffff009c33c34@fffffff009c33c34
//   fffffff009c1a910 FUN_fffffff009c1a908@fffffff009c1a908
// CALLEES:
//   fffffff009c49c14 thunk_FUN_fffffff00a6de494
//   fffffff009c31488 FUN_fffffff009c31488
//   fffffff009c372c4 FUN_fffffff009c372c4
//   fffffff009c49594 thunk_FUN_fffffff00a903010
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c
//   fffffff009c36818 FUN_fffffff009c36818
//   fffffff009c1e624 FUN_fffffff009c1e624
//   fffffff009c49e74 thunk_FUN_fffffff00a2df760
//   fffffff009c35bd8 FUN_fffffff009c35bd8
//   fffffff009c49a54 thunk_FUN_fffffff00a89a1f4
//   fffffff009c16670 FUN_fffffff009c16670
//   fffffff009c49d54 thunk_FUN_fffffff00a7265e0
//   fffffff009c46f98 FUN_fffffff009c46f98
//   fffffff009c1af14 FUN_fffffff009c1af14
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c49c34 thunk_FUN_fffffff00a6e0388

/* WARNING: Removing unreachable block (ram,0xfffffff009c1ad18) */

bool FUN_fffffff009c1a914
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8,long param_9,long *param_10,long *param_11)

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
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  bool bVar16;
  uint uVar17;
  undefined4 uVar18;
  long lVar19;
  ulong uVar20;
  long *plVar21;
  long lVar22;
  undefined8 *puVar23;
  long *plVar24;
  undefined1 *puVar25;
  ulong uVar26;
  undefined1 *puVar27;
  ulong uVar28;
  ulong uVar29;
  undefined8 extraout_d0;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_07;
  undefined8 extraout_d0_00;
  undefined8 uVar30;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 uVar33;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined1 auVar31 [16];
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined1 auVar32 [16];
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined8 extraout_var_07;
  undefined4 uVar34;
  undefined1 auVar35 [12];
  undefined4 uVar36;
  undefined1 auVar37 [12];
  ulong local_68;
  undefined1 *local_60;
  undefined1 *local_58;
  long local_50;
  long local_48;
  
  uVar36 = param_4._0_4_;
  auVar37 = param_4._4_12_;
  uVar34 = param_3._0_4_;
  auVar35 = param_3._4_12_;
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  lVar22 = param_9;
  plVar21 = param_10;
  plVar24 = param_11;
  FUN_fffffff009c46f98
            (param_1,param_2,param_3,param_4,param_5,param_6,(int *)((long)param_7 + 0xc),1);
  lVar19 = FUN_fffffff009c372c4();
  param_7[0x70] = lVar19;
  uVar30 = extraout_d0;
  uVar33 = extraout_var;
  if (param_11 != (long *)0x0) {
    if (param_11[0x6f] != 0) {
      auVar7._8_8_ = extraout_var;
      auVar7._0_8_ = extraout_d0;
      thunk_FUN_fffffff00a8df19c
                (auVar7,param_2,uVar34,uVar36,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"%s error - invalid parent (can\'t be child)\n");
      bVar16 = false;
      goto LAB_fffffff009c1ac5c;
    }
    FUN_fffffff009c16670(param_7 + 0x6f,param_11);
    uVar30 = extraout_d0_00;
    uVar33 = extraout_var_00;
  }
  auVar1._8_8_ = uVar33;
  auVar1._0_8_ = uVar30;
  auVar8._4_12_ = auVar35;
  auVar8._0_4_ = uVar34;
  auVar12._4_12_ = auVar37;
  auVar12._0_4_ = uVar36;
  uVar20 = FUN_fffffff009c35bd8
                     (auVar1,param_2,auVar8,auVar12,param_5,param_6,DAT_fffffff00af483b0,
                      (int *)(param_7 + 2),lVar22,plVar21,(undefined *)plVar24);
  if ((uVar20 & 1) == 0) {
    auVar2._8_8_ = extraout_var_01;
    auVar2._0_8_ = extraout_d0_01;
    thunk_FUN_fffffff00a8df19c
              (auVar2,param_2,uVar34,uVar36,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,
               (byte *)"%s error - failed to alloc surface id\n");
    bVar16 = false;
  }
  else {
    plVar21 = (long *)(**(code **)(*param_10 + 0x138))(param_10,"IOSurfacePixelSizeCastingAllowed");
    plVar21 = thunk_FUN_fffffff00a894f30(plVar21,*(long *)PTR_PTR_fffffff00806ca20);
    if (plVar21 == (long *)0x0) {
      uVar17 = FUN_fffffff009c31488(2);
      puVar23 = (undefined8 *)PTR_PTR_fffffff00806ca60;
      if (uVar17 != 0) {
        puVar23 = (undefined8 *)PTR_PTR_fffffff00806ca58;
      }
      (**(code **)(*param_10 + 0x100))
                (param_10,"IOSurfacePixelSizeCastingAllowed",*(undefined8 *)*puVar23);
    }
    FUN_fffffff009c16670(param_7 + 0x4d,param_10);
    if (param_9 != 0) {
      param_7[0x2e] = param_9;
    }
    param_7[0xf] = 0;
    *(uint *)(param_7 + 0x7a) = *(uint *)(param_7 + 0x7a) & 0xffffef33;
    param_7[0x13] = 0;
    *(undefined4 *)(param_7 + 0x32) = 0;
    if ((long *)param_7[0x35] != (long *)0x0) {
      (**(code **)(*(long *)param_7[0x35] + 0x28))();
    }
    param_7[0x35] = 0;
    if ((long *)param_7[0x42] != (long *)0x0) {
      (**(code **)(*(long *)param_7[0x42] + 0x28))();
    }
    param_7[8] = 0;
    param_7[0x43] = 0;
    param_7[0x42] = 0;
    param_7[9] = (long)(param_7 + 8);
    param_7[0x5e] = 0;
    param_7[0x5f] = (long)(param_7 + 0x5e);
    param_7[7] = 0;
    *(undefined4 *)(param_7 + 0xe) = 0x1010001;
    param_7[0x2a] = 0;
    *(undefined4 *)(param_7 + 0x6d) = 3;
    *(undefined4 *)((long)param_7 + 0x22c) = 0;
    *(uint *)(param_7 + 0x7a) = *(uint *)(param_7 + 0x7a) & 0xffedb3fd | 0x800;
    lVar22 = thunk_FUN_fffffff00a903010();
    param_7[10] = lVar22;
    if (lVar22 != 0) {
      lVar22 = thunk_FUN_fffffff00a903010();
      param_7[0x73] = lVar22;
      if (lVar22 != 0) {
        plVar21 = thunk_FUN_fffffff00a89a1f4(1);
        auVar31._8_8_ = extraout_var_02;
        auVar31._0_8_ = extraout_d0_02;
        if ((long *)param_7[0x7b] != (long *)0x0) {
          auVar31 = (**(code **)(*(long *)param_7[0x7b] + 0x28))();
        }
        param_7[0x7b] = (long)plVar21;
        if (plVar21 != (long *)0x0) {
          *(uint *)(param_7 + 0x14) = *(uint *)(param_7 + 2);
          param_7[0x2f] = 0;
          param_7[0x60] = 0;
          *(undefined4 *)(param_7 + 0x44) = 0;
          param_7[0x48] = 0;
          param_7[0x49] = (long)(param_7 + 0x48);
          param_7[0x4a] = 0;
          param_7[0x4b] = (long)(param_7 + 0x4a);
          *(uint *)(param_7 + 0x7a) = *(uint *)(param_7 + 0x7a) & 0xffff5fcf | 0x8000;
          *(undefined4 *)(param_7 + 0x45) = 2;
          local_60 = &DAT_aaaaaaaaaaaaaaaa;
          local_58 = &DAT_aaaaaaaaaaaaaaaa;
          auVar9._4_12_ = auVar35;
          auVar9._0_4_ = uVar34;
          auVar13._4_12_ = auVar37;
          auVar13._0_4_ = uVar36;
          uVar20 = FUN_fffffff009c36818
                             (auVar31,param_2,auVar9,auVar13,param_5,param_6,DAT_fffffff00af483b0,
                              *(uint *)(param_7 + 2),(long *)&local_58,&local_60);
          if ((uVar20 & 1) == 0) {
            auVar3._8_8_ = extraout_var_03;
            auVar3._0_8_ = extraout_d0_03;
            thunk_FUN_fffffff00a8df19c
                      (auVar3,param_2,uVar34,uVar36,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00806ca48,0x10,
                       (byte *)"%s error - failed to alloc shmem\n");
            bVar16 = false;
          }
          else {
            puVar25 = local_58;
            if (local_58 == (undefined1 *)0x0) {
              puVar25 = (undefined1 *)0x0;
            }
            param_7[0x2f] = (long)puVar25;
            puVar27 = local_60;
            if (local_60 == (undefined1 *)0x0) {
              puVar27 = (undefined1 *)0x0;
            }
            param_7[0x60] = (long)puVar27;
            *(uint *)(param_7 + 0x7a) = *(uint *)(param_7 + 0x7a) | 0x10000;
            puVar25[0x2c] = 1;
            *(uint *)(param_7 + 0x7a) = *(uint *)(param_7 + 0x7a) | 0x40000;
            puVar25[0x2e] = 1;
            plVar21 = thunk_FUN_fffffff00a89a1f4(0x10);
            auVar32._8_8_ = extraout_var_04;
            auVar32._0_8_ = extraout_d0_04;
            if ((long *)param_7[0x79] != (long *)0x0) {
              auVar32 = (**(code **)(*(long *)param_7[0x79] + 0x28))();
            }
            param_7[0x79] = (long)plVar21;
            auVar10._4_12_ = auVar35;
            auVar10._0_4_ = uVar34;
            auVar14._4_12_ = auVar37;
            auVar14._0_4_ = uVar36;
            uVar20 = FUN_fffffff009c1af14
                               (auVar32,param_2,auVar10,auVar14,param_5,param_6,(long)param_7,
                                param_10);
            if ((uVar20 & 1) == 0) {
              auVar4._8_8_ = extraout_var_05;
              auVar4._0_8_ = extraout_d0_05;
              thunk_FUN_fffffff00a8df19c
                        (auVar4,param_2,uVar34,uVar36,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff00806ca48,0x10,
                         (byte *)"%s error - failed to parse properties\n");
              bVar16 = false;
            }
            else {
              uVar18 = thunk_FUN_fffffff00a7265e0();
              *(undefined4 *)((long)param_7 + 0x3d4) = uVar18;
              uVar20 = param_7[0x2a];
              if (uVar20 == 0) {
                lVar22 = param_7[0x12];
              }
              else {
                uVar28 = -*(long *)PTR_DAT_fffffff00806ca78;
                uVar26 = *(long *)PTR_DAT_fffffff00806ca78 - 1;
                uVar29 = uVar26 & uVar20;
                lVar22 = param_7[0x12];
                param_7[0x2b] = uVar20 & uVar28;
                param_7[0x2c] = uVar29 + uVar26 + lVar22 & uVar28;
                param_7[0x2d] = uVar29;
              }
              uVar17 = 0x100;
              if (lVar22 == 0) {
                bVar16 = true;
              }
              else {
                auVar5._8_8_ = extraout_var_06;
                auVar5._0_8_ = extraout_d0_06;
                auVar11._4_12_ = auVar35;
                auVar11._0_4_ = uVar34;
                auVar15._4_12_ = auVar37;
                auVar15._0_4_ = uVar36;
                uVar20 = FUN_fffffff009c1e624
                                   (auVar5,param_2,auVar11,auVar15,param_5,param_6,param_7);
                bVar16 = (int)uVar20 == 0;
                uVar17 = 0x100;
                if (!bVar16) {
                  uVar17 = 0;
                }
              }
              *(uint *)(param_7 + 0x7a) = *(uint *)(param_7 + 0x7a) & 0xfffffeff | uVar17;
              local_68 = 0;
              plVar21 = (long *)param_7[0x35];
              if (plVar21 != (long *)0x0) {
                plVar21 = (long *)(**(code **)(*plVar21 + 0x138))(plVar21,"IOSurfaceName");
                plVar21 = thunk_FUN_fffffff00a894f30(plVar21,*(long *)PTR_PTR_fffffff00806ca10);
                if (plVar21 != (long *)0x0) {
                  puVar23 = (undefined8 *)(**(code **)(*plVar21 + 0xa8))();
                  auVar6._8_8_ = extraout_var_07;
                  auVar6._0_8_ = extraout_d0_07;
                  thunk_FUN_fffffff00a6e0388
                            (auVar6,param_2,uVar34,uVar36,param_5,param_6,0x85210040,&local_68,
                             puVar23);
                }
              }
              local_50 = 0;
              auVar7 = thunk_FUN_fffffff00a2df760(param_7[6],&local_50);
              thunk_FUN_fffffff00a6de494
                        (auVar7,param_2,uVar34,uVar36,param_5,param_6,0x85210018,local_50,
                         (ulong)*(uint *)(param_7 + 2),(ulong)*(uint *)(param_7 + 0x10),
                         param_7[0xb] | param_7[0xc] << 0x20);
              local_50 = 0;
              auVar7 = thunk_FUN_fffffff00a2df760(param_7[6],&local_50);
              thunk_FUN_fffffff00a6de494
                        (auVar7,param_2,uVar34,uVar36,param_5,param_6,0x8521003c,local_50,
                         (ulong)*(uint *)(param_7 + 2),param_7[0x12],local_68);
            }
          }
          goto LAB_fffffff009c1ac5c;
        }
      }
    }
    bVar16 = false;
  }
LAB_fffffff009c1ac5c:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return bVar16;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

