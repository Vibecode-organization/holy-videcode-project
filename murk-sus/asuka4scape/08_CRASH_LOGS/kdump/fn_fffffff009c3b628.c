// FUN_fffffff009c3b628 @ fffffff009c3b628 size=392
// CALLERS:
//   fffffff00afec0bf ?
//   fffffff009c38ab4 FUN_fffffff009c38aa4@fffffff009c38aa4
// CALLS:
//   fffffff009c3f478 FUN_fffffff009c3f478
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c2c18c FUN_fffffff009c2c18c
//   fffffff009c33a4c FUN_fffffff009c33a4c
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c3f2b0 FUN_fffffff009c3f2b0
//   fffffff009c3f044 FUN_fffffff009c3f044
//   fffffff009c2b810 FUN_fffffff009c2b810

/* WARNING: Removing unreachable block (ram,0xfffffff009c3b6b0) */

undefined8
FUN_fffffff009c3b628
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,ulong param_8,
          undefined8 *param_9,undefined8 param_10,undefined *param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  ulong uVar7;
  long *plVar8;
  long *plVar9;
  undefined8 uVar10;
  undefined8 extraout_x1;
  long lVar11;
  long lVar12;
  undefined8 uVar13;
  undefined1 auVar14 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar15 [16];
  undefined4 uVar16;
  undefined1 auVar17 [12];
  undefined4 uVar18;
  undefined1 auVar19 [12];
  long lStack_50;
  long local_48;
  
  uVar18 = param_4._0_4_;
  auVar19 = param_4._4_12_;
  uVar16 = param_3._0_4_;
  auVar17 = param_3._4_12_;
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar13 = 0xe00002bd;
  auVar14 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0xd8));
  auVar15._4_12_ = auVar17;
  auVar15._0_4_ = uVar16;
  auVar3._4_12_ = auVar19;
  auVar3._0_4_ = uVar18;
  uVar7 = FUN_fffffff009c3f044
                    (auVar14,param_2,auVar15,auVar3,param_5,param_6,param_7,(uint)param_8,&lStack_50
                    );
  if ((uVar7 & 1) == 0) {
    lVar12 = *(long *)(param_7 + 0xf8);
    if (lVar12 == 0) {
      lVar12 = 0;
    }
    auVar14._4_12_ = auVar17;
    auVar14._0_4_ = uVar16;
    lVar11 = param_7;
    auVar4._4_12_ = auVar19;
    auVar4._0_4_ = uVar18;
    plVar8 = (long *)FUN_fffffff009c33a4c
                               (extraout_q0,param_2,auVar14,auVar4,param_5,param_6,
                                *(long *)(param_7 + 0xe8),param_8,lVar12,param_7);
    if (plVar8 != (long *)0x0) {
      plVar9 = FUN_fffffff009c2b810(*(undefined8 *)(param_7 + 0x118),plVar8,0);
      if ((plVar9 != (long *)0x0) &&
         (auVar1._4_12_ = auVar17, auVar1._0_4_ = uVar16, auVar5._4_12_ = auVar19,
         auVar5._0_4_ = uVar18,
         uVar10 = FUN_fffffff009c3f2b0
                            (extraout_q0_00,param_2,auVar1,auVar5,param_5,param_6,param_7,plVar9,
                             (ulong)*(uint *)(plVar8 + 2),lVar11,param_11), (int)uVar10 != 0)) {
        auVar15 = FUN_fffffff009c3f478
                            (extraout_q0_01,param_2,uVar16,uVar18,param_5,param_6,param_7,
                             extraout_x1,0);
        auVar2._4_12_ = auVar17;
        auVar2._0_4_ = uVar16;
        auVar6._4_12_ = auVar19;
        auVar6._0_4_ = uVar18;
        FUN_fffffff009c2c18c(auVar15,param_2,auVar2,auVar6,param_5,param_6,(long)plVar9,param_9);
        uVar13 = 0;
      }
      thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0xd8));
      (**(code **)(*plVar8 + 0x28))(plVar8);
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0x28))(plVar9);
      }
      goto LAB_fffffff009c3b778;
    }
  }
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0xd8));
  uVar13 = 0xe00002c2;
LAB_fffffff009c3b778:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return uVar13;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

