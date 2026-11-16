// FUN_fffffff009ab0cdc @ fffffff009ab0cdc size=700
// CALLERS:
// CALLEES:
//   fffffff009abd9ac thunk_FUN_fffffff009c223d4
//   fffffff009abd82c thunk_FUN_fffffff009c2a3d0
//   fffffff009abd88c thunk_FUN_fffffff009c23a14
//   fffffff009ab0f98 FUN_fffffff009ab0f98
//   fffffff009abd9fc thunk_FUN_fffffff009c22264
//   fffffff009abd93c thunk_FUN_fffffff009c223c8
//   fffffff009abd8cc thunk_FUN_fffffff009c1f1a8
//   fffffff009abd5fc thunk_FUN_fffffff00a980234
//   fffffff009abd8fc thunk_FUN_fffffff009c2235c
//   fffffff009aaefbc FUN_fffffff009aaefbc

undefined4 FUN_fffffff009ab0cdc(long *param_1,ulong param_2,uint param_3)

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
  code *pcVar13;
  int iVar14;
  undefined4 uVar15;
  long lVar16;
  ulong uVar17;
  long *plVar18;
  ulong uVar19;
  undefined8 uVar20;
  long lVar21;
  long lVar22;
  ulong unaff_x30;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 uVar23;
  undefined4 uVar24;
  long lVar25;
  undefined4 in_s3;
  undefined1 in_register_00005064 [12];
  undefined4 in_s4;
  undefined4 in_s5;
  long local_c0;
  long lStack_b8;
  undefined8 uStack_b0;
  long lStack_a8;
  undefined8 local_a0;
  long lStack_98;
  undefined8 uStack_90;
  long lStack_88;
  long local_80;
  long lStack_78;
  long lStack_70;
  long lStack_68;
  long local_60;
  long lStack_58;
  
  if (param_1[0x36b] == 0) {
    return 0;
  }
  lVar16 = thunk_FUN_fffffff009c22264(param_1[0x36b]);
  lVar22 = param_1[0x36b];
  if (lVar16 != 0) goto joined_r0xfffffff009ab0f38;
  if (((int)param_2 == 0) || (param_3 == 0)) {
    param_2 = (ulong)*(uint *)(param_1 + 0x37e);
    if (((*(byte *)(param_1 + 0x399) & 1) == 0) && (*(uint *)(param_1 + 0x37e) == 0x438)) {
      if (*(int *)((long)param_1 + 0x1bf4) == 0x780) {
        param_2 = 0x4da;
        param_3 = 0x8a0;
        goto LAB_fffffff009ab0d68;
      }
      param_2 = 0x438;
    }
    param_3 = *(uint *)((long)param_1 + 0x1bf4);
  }
LAB_fffffff009ab0d68:
  lStack_88 = param_1[0x38f];
  uStack_90 = *(undefined8 *)*(undefined1 (*) [16])(param_1 + 0x38e);
  lStack_78 = param_1[0x391];
  local_80 = param_1[0x390];
  lStack_68 = param_1[0x393];
  lStack_70 = param_1[0x392];
  lStack_58 = param_1[0x395];
  local_60 = param_1[0x394];
  lStack_b8 = param_1[0x389];
  local_c0 = param_1[0x388];
  lVar25 = param_1[0x38b];
  uStack_b0 = *(undefined8 *)*(undefined1 (*) [16])(param_1 + 0x38a);
  uVar15 = (undefined4)uStack_b0;
  uVar24 = (undefined4)((ulong)uStack_b0 >> 0x20);
  lVar16 = param_1[0x38d];
  uVar23 = *(undefined8 *)*(undefined1 (*) [16])(param_1 + 0x38c);
  auVar3._4_12_ = in_register_00005064;
  auVar3._0_4_ = in_s3;
  lStack_a8 = lVar25;
  local_a0 = uVar23;
  lStack_98 = lVar16;
  uVar17 = FUN_fffffff009ab0f98
                     (*(undefined1 (*) [16])(param_1 + 0x38e),
                      *(undefined1 (*) [16])(param_1 + 0x38c),
                      *(undefined1 (*) [16])(param_1 + 0x38a),auVar3,in_s4,in_s5,lVar22,param_2,
                      param_3,(undefined4 *)&local_c0);
  if ((int)uVar17 != 0) {
    plVar18 = (long *)thunk_FUN_fffffff009c223d4(lVar22);
    uVar17 = thunk_FUN_fffffff009c223c8(lVar22);
    uVar19 = thunk_FUN_fffffff009c1f1a8(lVar22);
    uVar20 = (**(code **)(*plVar18 + 0x90))(plVar18);
    auVar1._8_8_ = extraout_var;
    auVar1._0_8_ = extraout_d0;
    auVar5._8_8_ = lVar16;
    auVar5._0_8_ = uVar23;
    auVar9._4_4_ = uVar24;
    auVar9._0_4_ = uVar15;
    auVar9._8_8_ = lVar25;
    auVar11._4_12_ = in_register_00005064;
    auVar11._0_4_ = in_s3;
    plVar18 = thunk_FUN_fffffff00a980234
                        (auVar1,auVar5,auVar9,auVar11,in_s4,in_s5,uVar20,uVar17 & 0xffffffff,
                         uVar19 & 0xffffffff,0x100003);
    auVar2._8_8_ = extraout_var_00;
    auVar2._0_8_ = extraout_d0_00;
    auVar6._8_8_ = lVar16;
    auVar6._0_8_ = uVar23;
    thunk_FUN_fffffff009c2a3d0(auVar2,auVar6,uVar15,in_s3,in_s4,in_s5,lVar22,plVar18);
    (**(code **)(*plVar18 + 0x28))(plVar18);
  }
  lVar21 = thunk_FUN_fffffff009c22264(lVar22);
  if (lVar21 != 0) {
    (**(code **)(*param_1 + 0xa80))(param_1,0x5a,1);
    plVar18 = (long *)param_1[0x24d];
    if (plVar18 != (long *)0x0) {
      auVar3 = (**(code **)(*plVar18 + 0x90))(plVar18,1);
      auVar7._8_8_ = lVar16;
      auVar7._0_8_ = uVar23;
      auVar10._4_4_ = uVar24;
      auVar10._0_4_ = uVar15;
      auVar10._8_8_ = lVar25;
      auVar12._4_12_ = in_register_00005064;
      auVar12._0_4_ = in_s3;
      FUN_fffffff009aaefbc(auVar3,auVar7,auVar10,auVar12,in_s4,in_s5,(long)param_1,0);
      (**(code **)(*(long *)param_1[0x3a4] + 0x90))((long *)param_1[0x3a4],param_1[0x24d]);
    }
    iVar14 = (**(code **)(*param_1 + 0xb88))(param_1,param_1 + 0x1de,0,lVar22);
    if (iVar14 != 0) {
      auVar4._8_8_ = extraout_var_01;
      auVar4._0_8_ = extraout_d0_01;
      auVar8._8_8_ = lVar16;
      auVar8._0_8_ = uVar23;
      thunk_FUN_fffffff009c23a14(auVar4,auVar8,uVar15,in_s3,in_s4,in_s5,param_1[0x36b]);
      (**(code **)(*(long *)param_1[0x36b] + 0x28))();
      param_1[0x36b] = 0;
    }
    *(int *)((long)param_1 + 0x1e4) = (int)param_2;
    *(uint *)(param_1 + 0x3d) = param_3;
  }
  lVar22 = param_1[0x36b];
joined_r0xfffffff009ab0f38:
  if ((lVar22 != 0) && (lVar22 = thunk_FUN_fffffff009c22264(lVar22), lVar22 != 0)) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ab0f74);
      (*pcVar13)();
    }
    uVar15 = thunk_FUN_fffffff009c2235c(param_1[0x36b]);
    return uVar15;
  }
  return 0;
}

