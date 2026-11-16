// FUN_fffffff009a7d52c @ fffffff009a7d52c size=568
// CALLERS:
// CALLEES:
//   fffffff009a75f3c FUN_fffffff009a75f3c
//   fffffff009a9a600 thunk_FUN_fffffff009c2a3c4
//   fffffff009a9a6a0 thunk_FUN_fffffff009c1e624
//   fffffff009a7805c FUN_fffffff009a7805c
//   fffffff009a780fc FUN_fffffff009a780fc
//   fffffff009a895f4 FUN_fffffff009a895f4
//   fffffff009a7d764 FUN_fffffff009a7d764
//   fffffff009a9a7b0 thunk_FUN_fffffff009c22264
//   fffffff009a9a6b0 thunk_FUN_fffffff009c23a14
//   fffffff009a9a750 thunk_FUN_fffffff009c2235c
//   fffffff009a99b60 thunk_FUN_fffffff00a2262a8
//   fffffff009a99ba0 thunk_FUN_fffffff00a226de0
//   fffffff009a99bc0 thunk_FUN_fffffff00a9029a0

undefined4
FUN_fffffff009a7d52c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,uint param_8,
          uint param_9)

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
  undefined4 uVar20;
  uint uVar21;
  long lVar22;
  ulong uVar23;
  long *plVar24;
  long lVar25;
  undefined8 uVar26;
  long *plVar27;
  undefined8 extraout_d0;
  undefined8 extraout_var;
  undefined1 auVar28 [16];
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined1 auVar29 [16];
  undefined8 uVar30;
  undefined1 auVar31 [12];
  undefined4 uVar32;
  undefined1 auVar33 [12];
  long local_b0;
  long lStack_a8;
  long lStack_a0;
  long lStack_98;
  undefined8 local_90;
  long lStack_88;
  undefined8 uStack_80;
  long lStack_78;
  long local_70;
  long lStack_68;
  long lStack_60;
  long lStack_58;
  long local_50;
  long lStack_48;
  undefined8 local_38;
  
  uVar32 = param_4._0_4_;
  auVar33 = param_4._4_12_;
  uVar20 = param_3._0_4_;
  auVar31 = param_3._4_12_;
  if (param_7[0x2c] == 0) {
    return 0;
  }
  lVar22 = thunk_FUN_fffffff009c22264(param_7[0x2c]);
  if (lVar22 != 0) goto LAB_fffffff009a7d560;
  plVar27 = (long *)param_7[0x2c];
  local_38 = 0;
  (**(code **)(*param_7 + 0x828))(param_7,(long)&local_38 + 4,&local_38);
  if ((param_8 == 0) || (param_9 == 0)) {
    param_8 = local_38._4_4_;
    param_9 = (uint)local_38;
    if (((*(byte *)(param_7 + 0x86) & 1) == 0) &&
       ((local_38._4_4_ == 0x438 && ((uint)local_38 == 0x780)))) {
      param_9 = 0x8a0;
      param_8 = 0x4da;
      goto LAB_fffffff009a7d5f0;
    }
  }
  else {
LAB_fffffff009a7d5f0:
    local_38 = CONCAT44(param_8,param_9);
  }
  lStack_68 = param_7[0x81];
  local_70 = param_7[0x80];
  lStack_58 = param_7[0x83];
  lStack_60 = param_7[0x82];
  lStack_48 = param_7[0x85];
  local_50 = param_7[0x84];
  lStack_a8 = param_7[0x79];
  local_b0 = param_7[0x78];
  lStack_98 = param_7[0x7b];
  lStack_a0 = param_7[0x7a];
  lVar22 = param_7[0x7d];
  uVar30 = *(undefined8 *)*(undefined1 (*) [16])(param_7 + 0x7c);
  lStack_78 = param_7[0x7f];
  uStack_80 = *(undefined8 *)*(undefined1 (*) [16])(param_7 + 0x7e);
  uVar26 = 0;
  auVar2._4_12_ = auVar31;
  auVar2._0_4_ = uVar20;
  auVar14._4_12_ = auVar33;
  auVar14._0_4_ = uVar32;
  local_90 = uVar30;
  lStack_88 = lVar22;
  uVar23 = FUN_fffffff009a7d764
                     (*(undefined1 (*) [16])(param_7 + 0x7e),*(undefined1 (*) [16])(param_7 + 0x7c),
                      auVar2,auVar14,param_5,param_6,(long)plVar27,param_8,param_9,
                      (undefined4 *)&local_b0,0);
  if ((int)uVar23 == 0) {
    thunk_FUN_fffffff00a9029a0
              ((byte *)
               "IOMFB: %s: Failed to update layout for surface = %p. width = %d, height = %d\n");
  }
  else {
    auVar1._8_8_ = extraout_var;
    auVar1._0_8_ = extraout_d0;
    auVar3._8_8_ = lVar22;
    auVar3._0_8_ = uVar30;
    auVar9._4_12_ = auVar31;
    auVar9._0_4_ = uVar20;
    auVar15._4_12_ = auVar33;
    auVar15._0_4_ = uVar32;
    plVar24 = (long *)FUN_fffffff009a7805c(auVar1,auVar3,auVar9,auVar15,param_5,param_6,param_7);
    auVar2 = thunk_FUN_fffffff009c2a3c4((long)plVar27,plVar24);
    auVar4._8_8_ = lVar22;
    auVar4._0_8_ = uVar30;
    auVar10._4_12_ = auVar31;
    auVar10._0_4_ = uVar20;
    auVar16._4_12_ = auVar33;
    auVar16._0_4_ = uVar32;
    thunk_FUN_fffffff009c1e624(auVar2,auVar4,auVar10,auVar16,param_5,param_6,plVar27);
  }
  lVar25 = thunk_FUN_fffffff009c22264((long)plVar27);
  if (lVar25 != 0) {
    auVar28 = (**(code **)(*param_7 + 0xaf8))(param_7,0x5a,1);
    if ((long *)param_7[0x94d] != (long *)0x0) {
      auVar5._8_8_ = lVar22;
      auVar5._0_8_ = uVar30;
      auVar11._4_12_ = auVar31;
      auVar11._0_4_ = uVar20;
      auVar17._4_12_ = auVar33;
      auVar17._0_4_ = uVar32;
      FUN_fffffff009a780fc
                (auVar28,auVar5,auVar11,auVar17,param_5,param_6,(long)param_7,(long *)param_7[0x94d]
                 ,(long *)param_7[0x26],0);
      auVar28._8_8_ = extraout_var_00;
      auVar28._0_8_ = extraout_d0_00;
    }
    auVar6._8_8_ = lVar22;
    auVar6._0_8_ = uVar30;
    auVar12._4_12_ = auVar31;
    auVar12._0_4_ = uVar20;
    auVar18._4_12_ = auVar33;
    auVar18._0_4_ = uVar32;
    uVar26 = FUN_fffffff009a75f3c
                       (auVar28,auVar6,auVar12,auVar18,param_5,param_6,param_7,param_7[0x2c],
                        param_7 + 0x94d,param_7 + 0x934,uVar26,0,0);
    auVar29._8_8_ = extraout_var_01;
    auVar29._0_8_ = extraout_d0_01;
    if ((int)uVar26 != 0) {
      auVar2 = thunk_FUN_fffffff00a2262a8(param_7[0x9a5]);
      auVar7._8_8_ = lVar22;
      auVar7._0_8_ = uVar30;
      thunk_FUN_fffffff009c23a14(auVar2,auVar7,uVar20,uVar32,param_5,param_6,param_7[0x2c]);
      (**(code **)(*(long *)param_7[0x2c] + 0x28))();
      param_7[0x2c] = 0;
      auVar29 = thunk_FUN_fffffff00a226de0(param_7[0x9a5]);
    }
    auVar8._8_8_ = lVar22;
    auVar8._0_8_ = uVar30;
    auVar13._4_12_ = auVar31;
    auVar13._0_4_ = uVar20;
    auVar19._4_12_ = auVar33;
    auVar19._0_4_ = uVar32;
    uVar21 = FUN_fffffff009a895f4
                       (auVar29,auVar8,auVar13,auVar19,param_5,param_6,param_7,param_7[0x2c],
                        local_38._4_4_,(uint)local_38,param_7[0x934]);
    if ((uVar21 & 1) == 0) {
      param_7[0x2c] = 0;
      thunk_FUN_fffffff00a9029a0((byte *)"%s: Failed to update default FB on DCP\n");
    }
  }
LAB_fffffff009a7d560:
  uVar20 = 0;
  if (param_7[0x2c] != 0) {
    lVar22 = thunk_FUN_fffffff009c22264(param_7[0x2c]);
    uVar20 = 0;
    if (lVar22 != 0) {
      uVar20 = thunk_FUN_fffffff009c2235c(param_7[0x2c]);
    }
  }
  return uVar20;
}

