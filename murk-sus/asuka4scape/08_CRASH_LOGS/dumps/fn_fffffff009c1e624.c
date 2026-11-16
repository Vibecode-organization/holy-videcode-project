// FUN_fffffff009c1e624 @ fffffff009c1e624 size=2948
// CALLERS:
//   fffffff00afebcc2 no-fn
//   fffffff008022088 no-fn
//   fffffff00802a1a8 no-fn
//   fffffff009c1ae04 FUN_fffffff009c1a914@fffffff009c1a914
//   fffffff009a9a6ac thunk_FUN_fffffff009c1e624@fffffff009a9a6a0
//   fffffff009abd888 thunk_FUN_fffffff009c1e624@fffffff009abd87c
// CALLEES:
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c372dc FUN_fffffff009c372dc
//   fffffff009c21f08 FUN_fffffff009c21f08
//   fffffff009c48f64 FUN_fffffff009c48f64
//   fffffff009c2cf30 FUN_fffffff009c2cf30
//   fffffff009c499f4 thunk_FUN_fffffff00a966900
//   fffffff009c16670 FUN_fffffff009c16670
//   fffffff009c49974 thunk_FUN_fffffff00a97b010
//   fffffff009c48f28 FUN_fffffff009c48f28
//   fffffff009c2200c FUN_fffffff009c2200c
//   fffffff009c4405c FUN_fffffff009c4405c
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c
//   fffffff009c21f78 FUN_fffffff009c21f78
//   fffffff009c49964 thunk_FUN_fffffff00a97ae84
//   fffffff009c48f3c FUN_fffffff009c48f3c
//   fffffff009c495f4 thunk_FUN_fffffff00a9029a0
//   fffffff009c48f50 FUN_fffffff009c48f50
//   fffffff009c499b4 thunk_FUN_fffffff00a980234
//   fffffff009c49924 thunk_FUN_fffffff00a97ba94

/* WARNING: Removing unreachable block (ram,0xfffffff009c1ea94) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1ebe4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1eb4c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1ed50) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1f13c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1e97c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1e8e8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1ec5c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1e7f0) */

ulong FUN_fffffff009c1e624
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  undefined8 *puVar1;
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
  undefined1 auVar16 [16];
  undefined *puVar17;
  int iVar18;
  long *plVar19;
  long lVar20;
  long *plVar21;
  undefined8 uVar22;
  uint uVar23;
  uint uVar24;
  ulong *puVar25;
  ulong uVar26;
  ulong uVar27;
  ulong uVar28;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar29 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 extraout_q0_07 [16];
  undefined1 extraout_q0_08 [16];
  undefined1 extraout_q0_09 [16];
  undefined1 extraout_q0_10 [16];
  undefined1 extraout_q0_11 [16];
  undefined1 extraout_q0_12 [16];
  undefined1 extraout_q0_13 [16];
  undefined4 uVar30;
  undefined1 auVar31 [12];
  undefined4 uVar32;
  undefined1 auVar33 [12];
  uint local_6c;
  long local_68;
  
  uVar32 = param_4._0_4_;
  auVar33 = param_4._4_12_;
  uVar30 = param_3._0_4_;
  auVar31 = param_3._4_12_;
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  if (param_7[0x6f] != 0) {
    FUN_fffffff009c21f78(param_7 + 6,*(long **)(param_7[0x6f] + 0x30));
    param_1 = extraout_q0;
    goto LAB_fffffff009c1e674;
  }
  if (((((*(byte *)((long)param_7 + 0x3d3) & 1) != 0) || (param_7[0x74] != 0)) &&
      (*(long **)(DAT_fffffff00af483b0 + 0x430) != (long *)0x0)) &&
     (iVar18 = (**(code **)(**(long **)(DAT_fffffff00af483b0 + 0x430) + 0x80))(),
     param_1 = extraout_q0_00, iVar18 != 0)) {
    (**(code **)(*param_7 + 0x20))(param_7);
    lVar20 = (**(code **)(**(long **)(DAT_fffffff00af483b0 + 0x430) + 0x78))
                       (*(long **)(DAT_fffffff00af483b0 + 0x430),param_7);
    auVar29 = extraout_q0_01;
    if ((long *)param_7[0x78] != (long *)0x0) {
      auVar29 = (**(code **)(*(long *)param_7[0x78] + 0x28))();
    }
    param_7[0x78] = lVar20;
    if (lVar20 == 0) {
      thunk_FUN_fffffff00a8df19c
                (auVar29,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"%s error - can\'t prepare mapping\n");
      uVar27 = 0xe00002be;
    }
    else {
      uVar27 = 0;
    }
    (**(code **)(*param_7 + 0x28))(param_7);
    goto LAB_fffffff009c1e780;
  }
  puVar17 = PTR_DAT_fffffff00806ca78;
  if (param_7[0x2a] == 0) {
    if (param_7[0x6e] == 0) {
      if ((int)param_7[0x32] != 0) {
        if ((*(byte *)((long)param_7 + 0x3d3) >> 3 & 1) != 0) {
          plVar19 = param_7 + 0x33;
          uVar27 = (long)(param_7 + 0x35) - (long)plVar19;
          if ((param_7 + 0x35 < plVar19) || (uVar27 >> 0x20 != 0)) {
            auVar29._4_12_ = auVar31;
            auVar29._0_4_ = uVar30;
            auVar9._4_12_ = auVar33;
            auVar9._0_4_ = uVar32;
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f64(param_1,param_2,auVar29,auVar9,param_5,param_6);
          }
          uVar28 = 0;
          lVar20 = 0;
          uVar23 = 0;
          while( true ) {
            if ((lVar20 < 0) || ((uint)uVar27 < (int)uVar28 + 8U)) {
              auVar2._4_12_ = auVar31;
              auVar2._0_4_ = uVar30;
              auVar10._4_12_ = auVar33;
              auVar10._0_4_ = uVar32;
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f28(param_1,param_2,auVar2,auVar10,param_5,param_6);
            }
            puVar1 = (undefined8 *)((long)plVar19 + uVar28);
            uVar26 = -(ulong)CARRY8((ulong)plVar19,uVar28);
            if ((uVar26 != CARRY8((ulong)plVar19,uVar28)) || ((long)uVar26 < 0)) {
              auVar3._4_12_ = auVar31;
              auVar3._0_4_ = uVar30;
              auVar11._4_12_ = auVar33;
              auVar11._0_4_ = uVar32;
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f50(param_1,param_2,auVar3,auVar11,param_5,param_6);
            }
            iVar18 = (**(code **)(*(long *)*puVar1 + 0xb8))();
            if (*(uint *)((long)param_7 + 0x9c) == 0) {
              *(int *)((long)param_7 + 0x9c) = iVar18;
            }
            else if (((iVar18 == 0x400) || (iVar18 == 0x100)) &&
                    ((*(uint *)((long)param_7 + 0x9c) | 0x100) == 0x300)) {
              uVar27 = 0xe00002c2;
              auVar29 = (**(code **)(*(long *)*puVar1 + 0xb8))();
              puVar17 = PTR_DAT_fffffff00806ca48;
              auVar29 = thunk_FUN_fffffff00a8df19c
                                  (auVar29,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,
                                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                                   (byte *)
                                   "IOSurface::allocate() - requested cache mode %08x incompatible with memory region cache mode %08x\n"
                                  );
              thunk_FUN_fffffff00a8df19c
                        (auVar29,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,(short *)puVar17
                         ,0x10,(byte *)"%s error - incompatible cache mode (0x%x in 0x%x)\n");
              goto LAB_fffffff009c1e780;
            }
            param_1 = extraout_q0_06;
            if ((param_7[0x74] == 0) &&
               (iVar18 = (**(code **)(*(long *)*puVar1 + 0x80))((long *)*puVar1,param_7),
               param_1 = extraout_q0_07, iVar18 != 0)) break;
            uVar23 = uVar23 + 1;
            uVar24 = *(uint *)(param_7 + 0x32);
            if (uVar24 <= uVar23) goto LAB_fffffff009c1eab4;
            lVar20 = lVar20 + 0x800000000;
            uVar28 = uVar28 + 8;
            if (uVar28 != (long)(int)uVar28) {
              auVar5._4_12_ = auVar31;
              auVar5._0_4_ = uVar30;
              auVar13._4_12_ = auVar33;
              auVar13._0_4_ = uVar32;
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f3c(param_1,param_2,auVar5,auVar13,param_5,param_6);
            }
          }
          FUN_fffffff009c16670(param_7 + 5,(long *)*puVar1);
          uVar22 = (**(code **)(*(long *)param_7[5] + 0x90))();
          uVar27 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f));
          auVar4._4_12_ = auVar31;
          auVar4._0_4_ = uVar30;
          auVar12._4_12_ = auVar33;
          auVar12._0_4_ = uVar32;
          plVar19 = thunk_FUN_fffffff00a980234
                              (extraout_q0_12,param_2,auVar4,auVar12,param_5,param_6,uVar22,
                               param_7[0x11],param_7[0x12] + uVar27 & (uVar27 ^ 0xffffffffffffffff),
                               0x100003);
          param_1 = FUN_fffffff009c21f08
                              (extraout_q0_13,param_2,uVar30,uVar32,param_5,param_6,(long)param_7,
                               plVar19);
          if (plVar19 == (long *)0x0) {
            if ((long *)param_7[5] != (long *)0x0) {
              param_1 = (**(code **)(*(long *)param_7[5] + 0x28))();
            }
            param_7[5] = 0;
          }
          else {
            *(undefined1 *)(param_7[0x2f] + 0x30) = 1;
            param_1 = (**(code **)(*plVar19 + 0x28))(plVar19);
          }
        }
        uVar24 = *(uint *)(param_7 + 0x32);
LAB_fffffff009c1eab4:
        if ((uVar24 != 0) && (param_7[6] != 0)) goto LAB_fffffff009c1e674;
      }
      uVar23 = 0x110023;
      if ((*(uint *)(param_7 + 0x7a) & 0x20000) != 0) {
        uVar23 = 0x910023;
      }
      uVar24 = *(uint *)(param_7 + 0x7a) >> 9 & 0x40 | *(uint *)((long)param_7 + 0x9c);
      if ((param_7[0x68] != 0) &&
         (plVar19 = FUN_fffffff009c372dc(DAT_fffffff00af483b0), param_1 = extraout_q0_04,
         plVar19 != (long *)0x0)) {
        uVar27 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f));
        lVar20 = param_7[0x2e];
        if (lVar20 == 0) {
          lVar20 = 0;
        }
        auVar6._4_12_ = auVar31;
        auVar6._0_4_ = uVar30;
        auVar14._4_12_ = auVar33;
        auVar14._0_4_ = uVar32;
        plVar21 = FUN_fffffff009c4405c
                            (extraout_q0_04,param_2,auVar6,auVar14,param_5,param_6,plVar19,
                             param_7[0x12] + uVar27 & (uVar27 ^ 0xffffffffffffffff),
                             (ulong)(uVar24 | uVar23),param_7[0x68],lVar20,
                             *(uint *)(param_7 + 0x7a) >> 0xb & 1);
        FUN_fffffff009c21f08
                  (extraout_q0_10,param_2,uVar30,uVar32,param_5,param_6,(long)param_7,plVar21);
        if (plVar21 != (long *)0x0) {
          (**(code **)(*plVar21 + 0x28))(plVar21);
        }
        param_1 = (**(code **)(*plVar19 + 0x28))(plVar19);
      }
      if (param_7[6] == 0) {
        param_7[0x68] = 0;
        uVar27 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f));
        plVar19 = thunk_FUN_fffffff00a966900
                            (0,(ulong)(uVar24 | uVar23),
                             param_7[0x12] + uVar27 & (uVar27 ^ 0xffffffffffffffff),
                             *(undefined8 *)PTR_DAT_fffffff00806ca78);
        param_1 = FUN_fffffff009c21f08
                            (extraout_q0_11,param_2,uVar30,uVar32,param_5,param_6,(long)param_7,
                             plVar19);
        if (plVar19 != (long *)0x0) {
          param_1 = (**(code **)(*plVar19 + 0x28))(plVar19);
        }
        if (param_7[6] != 0) goto LAB_fffffff009c1f074;
LAB_fffffff009c1f09c:
        uVar23 = *(uint *)(param_7 + 0x7a) | 0x20;
      }
      else {
LAB_fffffff009c1f074:
        iVar18 = *(int *)((long)param_7 + 0x9c);
        if (((iVar18 != 0x100) && (iVar18 != 0x700)) && (iVar18 != 0x400))
        goto LAB_fffffff009c1f09c;
        uVar23 = *(uint *)(param_7 + 0x7a) & 0xffffffdf;
      }
      *(uint *)(param_7 + 0x7a) = uVar23;
    }
    else {
      uVar23 = *(uint *)(param_7 + 0x6d);
      local_6c = uVar23;
      if (*(int *)((long)param_7 + 0x3b4) == 0) {
        uVar27 = 0;
      }
      else {
        uVar28 = 0;
        do {
          puVar25 = (ulong *)(param_7[0x6e] + uVar28 * 0x10);
          if (((param_7[0x6e] ^ (ulong)puVar25) & 0xffc0000000000000) != 0) {
            puVar25 = (ulong *)((ulong)puVar25 & 0xffffffffffff | 0xc8a2000000000000);
          }
          uVar27 = *puVar25;
          if ((*(long *)puVar17 - 1U & uVar27) != 0) {
            uVar27 = 0xe00002c2;
            thunk_FUN_fffffff00a8df19c
                      (param_1,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00806ca48,0x10,
                       (byte *)"%s error - unaligned addr (0x%llx)\n");
            goto LAB_fffffff009c1e780;
          }
          uVar26 = puVar25[1];
          if (uVar26 == 0 || (*(long *)puVar17 - 1U & uVar26) != 0) {
            uVar27 = 0xe00002c2;
            thunk_FUN_fffffff00a8df19c
                      (param_1,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00806ca48,0x10,
                       (byte *)"%s error - unaligned length (0x%llx)\n");
            goto LAB_fffffff009c1e780;
          }
          lVar20 = param_7[0x2e];
          if (lVar20 == 0) {
            lVar20 = 0;
          }
          auVar7._4_12_ = auVar31;
          auVar7._0_4_ = uVar30;
          auVar15._4_12_ = auVar33;
          auVar15._0_4_ = uVar32;
          uVar27 = FUN_fffffff009c2200c
                             (param_1,param_2,auVar7,auVar15,param_5,param_6,lVar20,uVar27,
                              uVar26 + uVar27,&local_6c);
          if ((int)uVar27 != 0) {
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_02,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00806ca48,0x10,
                       (byte *)"%s error - invalid range (0x%llx - 0x%llx)\n");
            goto LAB_fffffff009c1e780;
          }
          uVar28 = uVar28 + 1;
          uVar27 = (ulong)*(uint *)((long)param_7 + 0x3b4);
          param_1 = extraout_q0_02;
        } while (uVar28 < uVar27);
        uVar23 = *(uint *)(param_7 + 0x6d);
        if (local_6c != uVar23) {
          uVar27 = 0xe00002c2;
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_02,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00806ca48,0x10,
                     (byte *)"%s error - invalid direction (0x%x vs 0x%x)\n");
          goto LAB_fffffff009c1e780;
        }
      }
      lVar20 = param_7[0x2e];
      if (lVar20 == 0) {
        lVar20 = 0;
      }
      plVar19 = thunk_FUN_fffffff00a97b010(param_7[0x6e],uVar27,uVar23 | 0x110100,lVar20);
      param_1 = extraout_q0_08;
      if (plVar19 != (long *)0x0) {
        uVar27 = param_7[0x2d];
        uVar28 = param_7[0x12];
        auVar29 = extraout_q0_08;
        if ((CARRY8(uVar27,uVar28)) ||
           (uVar26 = (**(code **)(*plVar19 + 0xb0))(plVar19), auVar29 = extraout_q0_09,
           uVar26 < uVar27 + uVar28)) {
          thunk_FUN_fffffff00a8df19c
                    (auVar29,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00806ca48,0x10,
                     (byte *)"%s error - Address ranges do not cover requested allocation size\n");
        }
        else {
          FUN_fffffff009c21f08
                    (extraout_q0_09,param_2,uVar30,uVar32,param_5,param_6,(long)param_7,plVar19);
        }
        param_1 = (**(code **)(*plVar19 + 0x28))(plVar19);
      }
    }
  }
  else {
    local_6c = *(uint *)(param_7 + 0x6d);
    lVar20 = param_7[0x2e];
    if (lVar20 == 0) {
      lVar20 = 0;
    }
    auVar8._4_12_ = auVar31;
    auVar8._0_4_ = uVar30;
    auVar16._4_12_ = auVar33;
    auVar16._0_4_ = uVar32;
    uVar27 = FUN_fffffff009c2200c
                       (param_1,param_2,auVar8,auVar16,param_5,param_6,lVar20,param_7[0x2b],
                        param_7[0x2c] + param_7[0x2b],&local_6c);
    if ((int)uVar27 != 0) {
      thunk_FUN_fffffff00a8df19c
                (extraout_q0_03,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"%s error - invalid address range (0x%llx - 0x%llx) : (0x%llx - 0x%llx)\n")
      ;
      goto LAB_fffffff009c1e780;
    }
    lVar20 = param_7[0x2e];
    if (lVar20 == 0) {
      lVar20 = 0;
    }
    plVar19 = thunk_FUN_fffffff00a97ae84(param_7[0x2b],param_7[0x2c],local_6c | 0x110000,lVar20);
    param_1 = FUN_fffffff009c21f08
                        (extraout_q0_05,param_2,uVar30,uVar32,param_5,param_6,(long)param_7,plVar19)
    ;
    if (plVar19 != (long *)0x0) {
      param_1 = (**(code **)(*plVar19 + 0x28))(plVar19);
    }
    *(uint *)(param_7 + 0x7a) = *(uint *)(param_7 + 0x7a) | 0x20;
    lVar20 = param_7[0x2f];
    *(int *)(lVar20 + 0xc) = *(int *)(lVar20 + 0xc) + 1;
    *(uint *)(param_7 + 0x7a) = *(uint *)(param_7 + 0x7a) | 0xc;
    *(int *)(lVar20 + 0x10) = *(int *)(lVar20 + 0x10) + 1;
  }
LAB_fffffff009c1e674:
  if (param_7[6] == 0) {
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,uVar30,uVar32,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,
               (byte *)
               "%s error - buffer allocation failed (%llu x %llu fmt: %08x size: %llu bytes)\n");
    thunk_FUN_fffffff00a9029a0
              ((byte *)
               "IOSurface warning: buffer allocation failed.  %llu x %llu fmt: %08x size: %llu bytes\n"
              );
    if (param_7[6] != 0) goto LAB_fffffff009c1e6e4;
  }
  else {
LAB_fffffff009c1e6e4:
    if (param_7[0x6f] == 0) {
      plVar19 = FUN_fffffff009c2cf30(param_7);
      thunk_FUN_fffffff00a97ba94(param_7[6],(long)plVar19);
      if (plVar19 != (long *)0x0) {
        (**(code **)(*plVar19 + 0x28))(plVar19);
      }
    }
  }
  uVar23 = *(uint *)(param_7 + 0x7a);
  if ((uVar23 >> 0x1a & 1) != 0) {
    if ((long *)param_7[6] != (long *)0x0) {
      iVar18 = (**(code **)(*(long *)param_7[6] + 0xa8))();
      if (iVar18 == 2) goto LAB_fffffff009c1e768;
      uVar23 = *(uint *)(param_7 + 0x7a);
    }
    *(uint *)(param_7 + 0x7a) = uVar23 & 0xfbffffff;
  }
LAB_fffffff009c1e768:
  uVar23 = 0xe00002be;
  if (param_7[6] != 0) {
    uVar23 = 0;
  }
  uVar27 = (ulong)uVar23;
LAB_fffffff009c1e780:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar27;
}

