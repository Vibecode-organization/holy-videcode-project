// FUN_fffffff009c3ab8c @ fffffff009c3ab8c size=1328
// CALLERS:
//   fffffff00afec0b6 ?
//   fffffff009c389d8 FUN_fffffff009c38890@fffffff009c38890
// CALLS:
//   fffffff009c44170 FUN_fffffff009c44170
//   fffffff009c3eeac FUN_fffffff009c3eeac
//   fffffff009c3f1d0 FUN_fffffff009c3f1d0
//   fffffff009c3f2b0 FUN_fffffff009c3f2b0
//   fffffff009c3f478 FUN_fffffff009c3f478
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c42814 FUN_fffffff009c42814
//   fffffff009c33dc4 FUN_fffffff009c33dc4
//   fffffff009c49764 thunk_FUN_fffffff00a8d8754
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c
//   fffffff009c33c34 FUN_fffffff009c33c34
//   fffffff009c2b810 FUN_fffffff009c2b810
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c2c18c FUN_fffffff009c2c18c
//   fffffff009c372dc FUN_fffffff009c372dc

/* WARNING: Removing unreachable block (ram,0xfffffff009c3ae0c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3ada8) */

undefined8
FUN_fffffff009c3ab8c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,char *param_8,
          uint param_9,undefined8 *param_10,ulong param_11)

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
  bool bVar12;
  undefined ******ppppppuVar13;
  long *plVar14;
  long *plVar15;
  long *plVar16;
  long lVar17;
  long *plVar18;
  long *plVar19;
  ulong uVar20;
  undefined8 extraout_x1;
  undefined8 uVar21;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 auVar22 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 extraout_q0_07 [16];
  undefined1 extraout_q0_08 [16];
  undefined1 extraout_q0_09 [16];
  undefined4 uVar23;
  undefined1 auVar24 [12];
  undefined4 uVar25;
  undefined1 auVar26 [12];
  
  uVar25 = param_4._0_4_;
  auVar26 = param_4._4_12_;
  uVar23 = param_3._0_4_;
  auVar24 = param_3._4_12_;
  uVar21 = 0xe00002c2;
  if (0x3fff < *(uint *)(param_7 + 0x128)) {
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,uVar23,uVar25,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,
               (byte *)"%s error - exceeded client limit (0x%x)\n");
    return 0xe00002be;
  }
  if (param_8 == (char *)0x0) {
    return 0xe00002c2;
  }
  ppppppuVar13 = thunk_FUN_fffffff00a8d8754(param_8,param_11 & 0xffffffff,(undefined8 *)0x0);
  if (ppppppuVar13 == (undefined ******)0x0) {
    return 0xe00002c2;
  }
  plVar14 = thunk_FUN_fffffff00a894f30((long *)ppppppuVar13,*(long *)PTR_PTR_fffffff00806c9c8);
  if (plVar14 == (long *)0x0) {
    uVar21 = 0xe00002c2;
    goto LAB_fffffff009c3b078;
  }
  if (param_9 == 0) {
    plVar15 = (long *)0x0;
  }
  else {
    auVar22._4_12_ = auVar24;
    auVar22._0_4_ = uVar23;
    auVar6._4_12_ = auVar26;
    auVar6._0_4_ = uVar25;
    plVar15 = FUN_fffffff009c3f1d0
                        (extraout_q0,param_2,auVar22,auVar6,param_5,param_6,param_7,param_9);
    if (plVar15 == (long *)0x0) {
      thunk_FUN_fffffff00a8df19c
                (extraout_q0_00,param_2,uVar23,uVar25,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"%s error - invalid parent id (0x%x)\n");
      goto LAB_fffffff009c3b078;
    }
  }
  plVar16 = (long *)(**(code **)(*plVar14 + 0x138))
                              (plVar14,PTR_s_IOSurfaceAllocateFromSuperbuffer_fffffff008066fc0);
  plVar16 = thunk_FUN_fffffff00a894f30(plVar16,*(long *)PTR_PTR_fffffff00806c9f8);
  auVar22 = extraout_q0_01;
  if (plVar16 == (long *)0x0) {
LAB_fffffff009c3ade4:
    lVar17 = *(long *)(param_7 + 0xf8);
    if (lVar17 == 0) {
      lVar17 = 0;
    }
    auVar2._4_12_ = auVar24;
    auVar2._0_4_ = uVar23;
    plVar18 = plVar15;
    auVar8._4_12_ = auVar26;
    auVar8._0_4_ = uVar25;
    plVar14 = FUN_fffffff009c33c34
                        (auVar22,param_2,auVar2,auVar8,param_5,param_6,*(long *)(param_7 + 0xe8),
                         lVar17,plVar14,plVar15);
    if (plVar14 == (long *)0x0) {
      thunk_FUN_fffffff00a8df19c
                (extraout_q0_06,param_2,uVar23,uVar25,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"%s error - failed to alloc surface buffer\n");
      uVar21 = 0xe00002c2;
    }
    else {
      if ((*(byte *)(plVar14 + 0x7a) >> 1 & 1) != 0) {
        FUN_fffffff009c3eeac(param_7);
      }
      plVar19 = FUN_fffffff009c2b810(*(undefined8 *)(param_7 + 0x118),plVar14,1);
      if (plVar19 == (long *)0x0) {
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_07,param_2,uVar23,uVar25,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                   (byte *)"%s error - failed to alloc client buffer\n");
        uVar21 = 0xe00002bd;
      }
      else {
        auVar22 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0xd8));
        auVar3._4_12_ = auVar24;
        auVar3._0_4_ = uVar23;
        auVar9._4_12_ = auVar26;
        auVar9._0_4_ = uVar25;
        uVar21 = FUN_fffffff009c33dc4
                           (auVar22,param_2,auVar3,auVar9,param_5,param_6,*(long *)(param_7 + 0xe8),
                            (long)plVar14,(ulong)*(uint *)(plVar14 + 2));
        if ((int)uVar21 == 0) {
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_08,param_2,uVar23,uVar25,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00806ca48,0x10,(byte *)"%s error - set surface id\n");
LAB_fffffff009c3afd0:
          uVar21 = 0xe00002bd;
        }
        else {
          auVar4._4_12_ = auVar24;
          auVar4._0_4_ = uVar23;
          auVar10._4_12_ = auVar26;
          auVar10._0_4_ = uVar25;
          uVar21 = FUN_fffffff009c3f2b0
                             (extraout_q0_08,param_2,auVar4,auVar10,param_5,param_6,param_7,plVar19,
                              (ulong)*(uint *)(plVar14 + 2),plVar18,(undefined *)param_11);
          if ((int)uVar21 == 0) {
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_09,param_2,uVar23,uVar25,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00806ca48,0x10,
                       (byte *)"%s error - set surface handle\n");
            goto LAB_fffffff009c3afd0;
          }
          auVar22 = FUN_fffffff009c3f478
                              (extraout_q0_09,param_2,uVar23,uVar25,param_5,param_6,param_7,
                               extraout_x1,1);
          auVar5._4_12_ = auVar24;
          auVar5._0_4_ = uVar23;
          auVar11._4_12_ = auVar26;
          auVar11._0_4_ = uVar25;
          FUN_fffffff009c2c18c
                    (auVar22,param_2,auVar5,auVar11,param_5,param_6,(long)plVar19,param_10);
          uVar21 = 0;
        }
        thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0xd8));
        (**(code **)(*plVar19 + 0x28))(plVar19);
      }
    }
    bVar12 = true;
    if (plVar16 != (long *)0x0) goto LAB_fffffff009c3b004;
  }
  else {
    (**(code **)(*plVar16 + 0x20))(plVar16);
    lVar17 = (**(code **)(*plVar16 + 0xb0))(plVar16);
    auVar22 = extraout_q0_02;
    if (lVar17 == 0) goto LAB_fffffff009c3ade4;
    plVar18 = FUN_fffffff009c372dc(*(long *)(param_7 + 0xe8));
    auVar1._4_12_ = auVar24;
    auVar1._0_4_ = uVar23;
    auVar7._4_12_ = auVar26;
    auVar7._0_4_ = uVar25;
    plVar19 = (long *)FUN_fffffff009c42814
                                (extraout_q0_03,param_2,auVar1,auVar7,param_5,param_6,(long)plVar18,
                                 lVar17);
    auVar22 = extraout_q0_04;
    if (plVar18 != (long *)0x0) {
      auVar22 = (**(code **)(*plVar18 + 0x28))(plVar18);
    }
    if (plVar19 == (long *)0x0) goto LAB_fffffff009c3ade4;
    lVar17 = *(long *)(param_7 + 0xf8);
    if (lVar17 == 0) {
      lVar17 = 0;
    }
    uVar20 = FUN_fffffff009c44170
                       (auVar22,param_2,uVar23,uVar25,param_5,param_6,(long)plVar19,lVar17);
    if ((uVar20 & 1) != 0) {
      auVar22 = (**(code **)(*plVar19 + 0x28))(plVar19);
      goto LAB_fffffff009c3ade4;
    }
    thunk_FUN_fffffff00a8df19c
              (extraout_q0_05,param_2,uVar23,uVar25,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,(byte *)"%s error - pool off limits (%llu)\n")
    ;
    (**(code **)(*plVar19 + 0x28))(plVar19);
    bVar12 = false;
    plVar14 = (long *)0x0;
    uVar21 = 0xe00002c2;
LAB_fffffff009c3b004:
    (**(code **)(*plVar16 + 0x28))(plVar16);
  }
  if (plVar15 != (long *)0x0) {
    (**(code **)(*plVar15 + 0x28))(plVar15);
  }
  if (plVar14 != (long *)0x0) {
    (**(code **)(*plVar14 + 0x28))(plVar14);
  }
  if (!bVar12) {
    uVar21 = 0xe00002e2;
  }
LAB_fffffff009c3b078:
  (*(code *)(*ppppppuVar13)[5])(ppppppuVar13);
  return uVar21;
}

