// FUN_fffffff009c3bb20 @ fffffff009c3bb20 size=1060
// CALLERS:
//   fffffff00afec0c7 ?
//   fffffff009c38ad8 FUN_fffffff009c38acc@fffffff009c38acc
// CALLS:
//   fffffff009c49a84 thunk_FUN_fffffff00a8cae24
//   fffffff009c33c34 FUN_fffffff009c33c34
//   fffffff009c2c18c FUN_fffffff009c2c18c
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c3eeac FUN_fffffff009c3eeac
//   fffffff009c3f2b0 FUN_fffffff009c3f2b0
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c3f478 FUN_fffffff009c3f478
//   fffffff009c33dc4 FUN_fffffff009c33dc4
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c
//   fffffff009c2b810 FUN_fffffff009c2b810
//   fffffff009c49864 thunk_FUN_fffffff00a8a10d8

/* WARNING: Removing unreachable block (ram,0xfffffff009c3bcf4) */

undefined8
FUN_fffffff009c3bb20
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long *param_8,
          undefined8 *param_9,undefined8 param_10,undefined *param_11)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  long *plVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  undefined8 uVar12;
  undefined8 extraout_x1;
  undefined8 uVar13;
  long lVar14;
  long lVar15;
  undefined1 extraout_q0 [16];
  undefined1 auVar16 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar17 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined4 uVar18;
  undefined1 auVar19 [12];
  undefined4 uVar20;
  undefined1 auVar21 [12];
  char *local_98 [4];
  char *local_78;
  char *pcStack_70;
  long local_68;
  
  uVar20 = param_4._0_4_;
  auVar21 = param_4._4_12_;
  uVar18 = param_3._0_4_;
  auVar19 = param_3._4_12_;
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  if (*(uint *)(param_7 + 0x128) < 0x4000) {
    plVar8 = thunk_FUN_fffffff00a8a10d8(8);
    if (*param_8 == 0) {
      plVar9 = (long *)0x0;
      auVar16 = extraout_q0;
    }
    else {
      plVar9 = thunk_FUN_fffffff00a8cae24(*param_8,0x40);
      auVar16 = (**(code **)(*plVar8 + 0x100))(plVar8,"IOSurfaceAddress",plVar9);
    }
    lVar14 = 0;
    local_98[0] = "IOSurfaceWidth";
    local_98[1] = "IOSurfaceHeight";
    local_98[2] = "IOSurfacePixelFormat";
    local_98[3] = "IOSurfaceBytesPerElement";
    local_78 = "IOSurfaceBytesPerRow";
    pcStack_70 = "IOSurfaceAllocSize";
    lVar15 = 6;
    do {
      uVar1 = *(uint *)((long)param_8 + lVar14 * 4 + 8);
      plVar10 = plVar9;
      if (uVar1 != 0) {
        plVar10 = thunk_FUN_fffffff00a8cae24((ulong)uVar1,0x40);
        if (plVar9 != (long *)0x0) {
          (**(code **)(*plVar9 + 0x28))(plVar9);
        }
        auVar16 = (**(code **)(*plVar8 + 0x100))(plVar8,local_98[lVar14],plVar10);
      }
      lVar14 = lVar14 + 1;
      lVar15 = lVar15 + -1;
      plVar9 = plVar10;
    } while (lVar15 != 0);
    lVar14 = *(long *)(param_7 + 0xf8);
    if (lVar14 == 0) {
      lVar14 = 0;
    }
    uVar13 = 0;
    auVar17._4_12_ = auVar19;
    auVar17._0_4_ = uVar18;
    auVar4._4_12_ = auVar21;
    auVar4._0_4_ = uVar20;
    plVar9 = FUN_fffffff009c33c34
                       (auVar16,param_2,auVar17,auVar4,param_5,param_6,*(long *)(param_7 + 0xe8),
                        lVar14,plVar8,(long *)0x0);
    if (plVar9 == (long *)0x0) {
      thunk_FUN_fffffff00a8df19c
                (extraout_q0_00,param_2,uVar18,uVar20,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"%s error - failed to alloc surface buffer\n");
      uVar13 = 0xe00002c2;
    }
    else {
      if ((*(byte *)(plVar9 + 0x7a) >> 1 & 1) != 0) {
        FUN_fffffff009c3eeac(param_7);
      }
      plVar11 = FUN_fffffff009c2b810(*(undefined8 *)(param_7 + 0x118),plVar9,1);
      if (plVar11 == (long *)0x0) {
        uVar13 = 0xe00002bd;
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_01,param_2,uVar18,uVar20,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                   (byte *)"%s error - failed to alloc client buffer\n");
      }
      else {
        auVar17 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0xd8));
        auVar16._4_12_ = auVar19;
        auVar16._0_4_ = uVar18;
        auVar5._4_12_ = auVar21;
        auVar5._0_4_ = uVar20;
        uVar12 = FUN_fffffff009c33dc4
                           (auVar17,param_2,auVar16,auVar5,param_5,param_6,*(long *)(param_7 + 0xe8)
                            ,(long)plVar9,(ulong)*(uint *)(plVar9 + 2));
        if ((int)uVar12 == 0) {
          uVar13 = 0xe00002bd;
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_02,param_2,uVar18,uVar20,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00806ca48,0x10,(byte *)"%s error - set surface id\n");
        }
        else {
          auVar2._4_12_ = auVar19;
          auVar2._0_4_ = uVar18;
          auVar6._4_12_ = auVar21;
          auVar6._0_4_ = uVar20;
          uVar13 = FUN_fffffff009c3f2b0
                             (extraout_q0_02,param_2,auVar2,auVar6,param_5,param_6,param_7,plVar11,
                              (ulong)*(uint *)(plVar9 + 2),uVar13,param_11);
          if ((int)uVar13 == 0) {
            uVar13 = 0xe00002bd;
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_03,param_2,uVar18,uVar20,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00806ca48,0x10,
                       (byte *)"%s error - set surface handle\n");
          }
          else {
            auVar16 = FUN_fffffff009c3f478
                                (extraout_q0_03,param_2,uVar18,uVar20,param_5,param_6,param_7,
                                 extraout_x1,1);
            auVar3._4_12_ = auVar19;
            auVar3._0_4_ = uVar18;
            auVar7._4_12_ = auVar21;
            auVar7._0_4_ = uVar20;
            FUN_fffffff009c2c18c
                      (auVar16,param_2,auVar3,auVar7,param_5,param_6,(long)plVar11,param_9);
            uVar13 = 0;
          }
        }
        thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0xd8));
        (**(code **)(*plVar11 + 0x28))(plVar11);
      }
      (**(code **)(*plVar9 + 0x28))(plVar9);
    }
    if (plVar10 != (long *)0x0) {
      (**(code **)(*plVar10 + 0x28))(plVar10);
    }
    if (plVar8 != (long *)0x0) {
      (**(code **)(*plVar8 + 0x28))(plVar8);
    }
  }
  else {
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,uVar18,uVar20,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,
               (byte *)"%s error - exceeded client limit (%d)\n");
    uVar13 = 0xe00002be;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar13;
}

