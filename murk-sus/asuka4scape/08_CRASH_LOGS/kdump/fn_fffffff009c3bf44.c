// FUN_fffffff009c3bf44 @ fffffff009c3bf44 size=1040
// CALLERS:
//   fffffff00afec0c8 ?
//   fffffff009c38af0 FUN_fffffff009c38adc@fffffff009c38adc
// CALLS:
//   fffffff009c3f478 FUN_fffffff009c3f478
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c33dc4 FUN_fffffff009c33dc4
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c2c18c FUN_fffffff009c2c18c
//   fffffff009c49a84 thunk_FUN_fffffff00a8cae24
//   fffffff009c3f2b0 FUN_fffffff009c3f2b0
//   fffffff009c33c34 FUN_fffffff009c33c34
//   fffffff009c49864 thunk_FUN_fffffff00a8a10d8
//   fffffff009c2b810 FUN_fffffff009c2b810

/* WARNING: Removing unreachable block (ram,0xfffffff009c3c0ec) */

undefined8
FUN_fffffff009c3bf44
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long param_8,
          long param_9,undefined8 *param_10,undefined *param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  undefined8 uVar11;
  undefined8 extraout_x1;
  long lVar12;
  undefined8 uVar13;
  undefined1 extraout_q0 [16];
  undefined1 auVar14 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 auVar15 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined4 uVar16;
  undefined1 auVar17 [12];
  undefined4 uVar18;
  undefined1 auVar19 [12];
  
  uVar18 = param_4._0_4_;
  auVar19 = param_4._4_12_;
  uVar16 = param_3._0_4_;
  auVar17 = param_3._4_12_;
  if ((param_8 == 0) || (param_9 == 0)) {
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,uVar16,uVar18,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,
               (byte *)"%s error - invalid memory range (addr=0x%llx size=0x%llx)\n");
    uVar13 = 0xe00002c2;
  }
  else if (*(uint *)(param_7 + 0x128) < 0x4000) {
    plVar7 = thunk_FUN_fffffff00a8a10d8(3);
    if (plVar7 == (long *)0x0) {
      uVar13 = 0xe00002bd;
      thunk_FUN_fffffff00a8df19c
                (extraout_q0,param_2,uVar16,uVar18,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,(byte *)"%s error - no properties\n");
    }
    else {
      plVar8 = thunk_FUN_fffffff00a8cae24(param_8,0x40);
      if (plVar8 == (long *)0x0) {
        plVar9 = thunk_FUN_fffffff00a8cae24(param_9,0x40);
        auVar14 = extraout_q0_00;
      }
      else {
        (**(code **)(*plVar7 + 0x100))(plVar7,"IOSurfaceAddress",plVar8);
        plVar9 = thunk_FUN_fffffff00a8cae24(param_9,0x40);
        auVar14 = (**(code **)(*plVar8 + 0x28))(plVar8);
      }
      if (plVar9 != (long *)0x0) {
        auVar14 = (**(code **)(*plVar7 + 0x100))(plVar7,"IOSurfaceAllocSize",plVar9);
      }
      lVar12 = *(long *)(param_7 + 0xf8);
      if (lVar12 == 0) {
        lVar12 = 0;
      }
      uVar13 = 0;
      auVar15._4_12_ = auVar17;
      auVar15._0_4_ = uVar16;
      auVar3._4_12_ = auVar19;
      auVar3._0_4_ = uVar18;
      plVar8 = FUN_fffffff009c33c34
                         (auVar14,param_2,auVar15,auVar3,param_5,param_6,*(long *)(param_7 + 0xe8),
                          lVar12,plVar7,(long *)0x0);
      if (plVar8 == (long *)0x0) {
        thunk_FUN_fffffff00a8df19c
                  (extraout_q0_01,param_2,uVar16,uVar18,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                   (byte *)"%s error - failed to alloc surface buffer\n");
        uVar13 = 0xe00002c2;
      }
      else {
        plVar10 = FUN_fffffff009c2b810(*(undefined8 *)(param_7 + 0x118),plVar8,1);
        if (plVar10 == (long *)0x0) {
          uVar13 = 0xe00002bd;
          thunk_FUN_fffffff00a8df19c
                    (extraout_q0_02,param_2,uVar16,uVar18,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00806ca48,0x10,
                     (byte *)"%s error - failed to alloc client buffer\n");
        }
        else {
          auVar15 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0xd8));
          auVar14._4_12_ = auVar17;
          auVar14._0_4_ = uVar16;
          auVar4._4_12_ = auVar19;
          auVar4._0_4_ = uVar18;
          uVar11 = FUN_fffffff009c33dc4
                             (auVar15,param_2,auVar14,auVar4,param_5,param_6,
                              *(long *)(param_7 + 0xe8),(long)plVar8,(ulong)*(uint *)(plVar8 + 2));
          if ((int)uVar11 == 0) {
            uVar13 = 0xe00002bd;
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_03,param_2,uVar16,uVar18,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00806ca48,0x10,(byte *)"%s error - set surface id\n")
            ;
          }
          else {
            auVar1._4_12_ = auVar17;
            auVar1._0_4_ = uVar16;
            auVar5._4_12_ = auVar19;
            auVar5._0_4_ = uVar18;
            uVar13 = FUN_fffffff009c3f2b0
                               (extraout_q0_03,param_2,auVar1,auVar5,param_5,param_6,param_7,plVar10
                                ,(ulong)*(uint *)(plVar8 + 2),uVar13,param_11);
            if ((int)uVar13 == 0) {
              uVar13 = 0xe00002bd;
              thunk_FUN_fffffff00a8df19c
                        (extraout_q0_04,param_2,uVar16,uVar18,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff00806ca48,0x10,
                         (byte *)"%s error - set surface handle\n");
            }
            else {
              auVar14 = FUN_fffffff009c3f478
                                  (extraout_q0_04,param_2,uVar16,uVar18,param_5,param_6,param_7,
                                   extraout_x1,1);
              auVar2._4_12_ = auVar17;
              auVar2._0_4_ = uVar16;
              auVar6._4_12_ = auVar19;
              auVar6._0_4_ = uVar18;
              FUN_fffffff009c2c18c
                        (auVar14,param_2,auVar2,auVar6,param_5,param_6,(long)plVar10,param_10);
              uVar13 = 0;
            }
          }
          thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0xd8));
          (**(code **)(*plVar10 + 0x28))(plVar10);
        }
        (**(code **)(*plVar8 + 0x28))(plVar8);
      }
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0x28))(plVar9);
      }
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
  }
  else {
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,uVar16,uVar18,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,
               (byte *)"%s error - exceeded client limit (%d)\n");
    uVar13 = 0xe00002be;
  }
  return uVar13;
}

