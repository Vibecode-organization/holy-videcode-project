// FUN_fffffff009a7e020 @ fffffff009a7e020 size=776
// CALLERS:
// CALLEES:
//   fffffff009a9a600 thunk_FUN_fffffff009c2a3c4
//   fffffff009a9a5e0 thunk_FUN_fffffff009c2a65c
//   fffffff009a9a6a0 thunk_FUN_fffffff009c1e624
//   fffffff009a7805c FUN_fffffff009a7805c
//   fffffff009a9a7a0 thunk_FUN_fffffff009c223d4
//   fffffff009a717c4 FUN_fffffff009a717c4
//   fffffff009a9a4a0 thunk_FUN_fffffff00a8d2200
//   fffffff009a7d764 FUN_fffffff009a7d764
//   fffffff009a9a370 thunk_FUN_fffffff009abc0d0
//   fffffff009a9a750 thunk_FUN_fffffff009c2235c
//   fffffff009a99e30 thunk_FUN_fffffff00a8a10d8
//   fffffff009a99e70 thunk_FUN_fffffff009c33c28
//   fffffff009a9a470 thunk_FUN_fffffff00a8cae24
//   fffffff009a9a640 thunk_FUN_fffffff009c2a3d0
//   fffffff009a7bb4c FUN_fffffff009a7bb4c
//   fffffff009a89710 FUN_fffffff009a89710
//   fffffff009a99bc0 thunk_FUN_fffffff00a9029a0
//   fffffff009a9a5f0 thunk_FUN_fffffff009c2a640

/* WARNING: Removing unreachable block (ram,0xfffffff009a7e114) */

uint FUN_fffffff009a7e020
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               uint param_8,uint param_9)

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
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  code *pcVar20;
  int iVar21;
  uint uVar22;
  long *plVar23;
  long *plVar24;
  undefined8 uVar25;
  long *plVar26;
  long *extraout_x0;
  ulong uVar27;
  long lVar28;
  char *pcVar29;
  ulong unaff_x30;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 uVar30;
  undefined8 uVar31;
  long lVar32;
  undefined4 uVar33;
  undefined1 auVar34 [12];
  undefined4 uVar35;
  undefined1 auVar36 [12];
  long local_c0;
  long lStack_b8;
  long lStack_b0;
  long lStack_a8;
  long local_a0;
  long lStack_98;
  long lStack_90;
  long lStack_88;
  long local_80;
  long lStack_78;
  long lStack_70;
  long lStack_68;
  long local_60;
  long lStack_58;
  
  uVar31 = param_2._8_8_;
  uVar30 = param_2._0_8_;
  uVar35 = param_4._0_4_;
  auVar36 = param_4._4_12_;
  uVar33 = param_3._0_4_;
  auVar34 = param_3._4_12_;
  iVar21 = FUN_fffffff009a717c4();
  if (iVar21 == 2) {
    if (param_7[0x2c] != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar20 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009a7e08c);
        (*pcVar20)();
      }
      auVar3._8_8_ = extraout_var;
      auVar3._0_8_ = extraout_d0;
      auVar9._8_8_ = uVar31;
      auVar9._0_8_ = uVar30;
      auVar14._4_12_ = auVar34;
      auVar14._0_4_ = uVar33;
      auVar19._4_12_ = auVar36;
      auVar19._0_4_ = uVar35;
      uVar22 = FUN_fffffff009a89710
                         (auVar3,auVar9,auVar14,auVar19,param_5,param_6,param_7,param_7[0x2c]);
      return uVar22;
    }
  }
  else {
    plVar23 = thunk_FUN_fffffff00a8a10d8(2);
    plVar24 = thunk_FUN_fffffff00a8cae24(0x700,0x20);
    (**(code **)(*plVar23 + 0x100))(plVar23,*(undefined8 *)PTR_PTR_fffffff008022330,plVar24);
    uVar25 = (**(code **)(*param_7 + 0xa90))(*param_7 + 0xa90,param_7);
    plVar26 = thunk_FUN_fffffff00a8d2200(uVar25);
    if (plVar26 != (long *)0x0) {
      (**(code **)(*plVar23 + 0x100))(plVar23,*(undefined8 *)PTR_PTR_fffffff008022340,plVar26);
      (**(code **)(*plVar26 + 0x28))(plVar26);
    }
    uVar25 = (**(code **)(*param_7 + 0xa90))(param_7);
    auVar1 = (**(code **)(*param_7 + 0xd0))(param_7,"IOMFBCarveoutRegion",uVar25);
    auVar4._8_8_ = uVar31;
    auVar4._0_8_ = uVar30;
    auVar10._4_12_ = auVar34;
    auVar10._0_4_ = uVar33;
    auVar15._4_12_ = auVar36;
    auVar15._0_4_ = uVar35;
    thunk_FUN_fffffff009c33c28
              (auVar1,auVar4,auVar10,auVar15,param_5,param_6,param_7[0x28],0,plVar23);
    (**(code **)(*plVar24 + 0x28))(plVar24);
    (**(code **)(*plVar23 + 0x28))(plVar23);
    auVar1 = thunk_FUN_fffffff009abc0d0(param_7 + 0x8de);
    if (extraout_x0 != (long *)0x0) {
      auVar5._8_8_ = uVar31;
      auVar5._0_8_ = uVar30;
      auVar11._4_12_ = auVar34;
      auVar11._0_4_ = uVar33;
      auVar16._4_12_ = auVar36;
      auVar16._0_4_ = uVar35;
      plVar23 = (long *)FUN_fffffff009a7805c(auVar1,auVar5,auVar11,auVar16,param_5,param_6,param_7);
      thunk_FUN_fffffff009c2a3c4((long)extraout_x0,plVar23);
      auVar1 = thunk_FUN_fffffff009c2a640((long)extraout_x0,(int)param_7[0x78]);
      auVar6._8_8_ = uVar31;
      auVar6._0_8_ = uVar30;
      thunk_FUN_fffffff009c2a3d0
                (auVar1,auVar6,uVar33,uVar35,param_5,param_6,(long)extraout_x0,(long *)0x0);
      thunk_FUN_fffffff009c2a65c((long)extraout_x0,1);
      lStack_78 = param_7[0x81];
      local_80 = param_7[0x80];
      lStack_68 = param_7[0x83];
      lStack_70 = param_7[0x82];
      lStack_58 = param_7[0x85];
      local_60 = param_7[0x84];
      lStack_b8 = param_7[0x79];
      local_c0 = param_7[0x78];
      lStack_a8 = param_7[0x7b];
      lStack_b0 = param_7[0x7a];
      lVar32 = param_7[0x7d];
      lVar28 = param_7[0x7c];
      lStack_88 = param_7[0x7f];
      lStack_90 = param_7[0x7e];
      local_a0 = lVar28;
      lStack_98 = lVar32;
      uVar22 = FUN_fffffff009a7bb4c((long)param_7,(long)extraout_x0,param_8,param_9);
      auVar1._8_8_ = extraout_var_00;
      auVar1._0_8_ = extraout_d0_00;
      auVar7._8_8_ = lVar32;
      auVar7._0_8_ = lVar28;
      auVar12._4_12_ = auVar34;
      auVar12._0_4_ = uVar33;
      auVar17._4_12_ = auVar36;
      auVar17._0_4_ = uVar35;
      uVar27 = FUN_fffffff009a7d764
                         (auVar1,auVar7,auVar12,auVar17,param_5,param_6,(long)extraout_x0,param_8,
                          param_9,(undefined4 *)&local_c0,(ulong)uVar22);
      if ((int)uVar27 == 0) {
        pcVar29 = "IOMFB: %s : layout_buffers - failed for Surface = 0x%p, sid = %d\n";
      }
      else {
        auVar2._8_8_ = extraout_var_01;
        auVar2._0_8_ = extraout_d0_01;
        auVar8._8_8_ = lVar32;
        auVar8._0_8_ = lVar28;
        auVar13._4_12_ = auVar34;
        auVar13._0_4_ = uVar33;
        auVar18._4_12_ = auVar36;
        auVar18._0_4_ = uVar35;
        thunk_FUN_fffffff009c1e624(auVar2,auVar8,auVar13,auVar18,param_5,param_6,extraout_x0);
        lVar28 = thunk_FUN_fffffff009c223d4((long)extraout_x0);
        if (lVar28 != 0) {
          param_7[0x2d] = (long)extraout_x0;
          return 0;
        }
        pcVar29 = "IOMFB: %s : getMemoryRegion Failed for Surface = 0x%p, sid = %d\n";
      }
      thunk_FUN_fffffff009c2235c((long)extraout_x0);
      thunk_FUN_fffffff00a9029a0((byte *)pcVar29);
    }
  }
  return 0;
}

