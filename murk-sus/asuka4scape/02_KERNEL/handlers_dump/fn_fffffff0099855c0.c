// FUN_fffffff0099855c0 @ fffffff0099855c0 size=4 depth=0
// CALLERS:
//   fffffff00afe6533 ?
//   fffffff007ff3010 ?
// CALLS:

undefined8 FUN_fffffff0099855c0(long param_1,undefined8 param_2,long param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  int iVar5;
  long *plVar6;
  long *plVar7;
  ulong *in_x3;
  undefined *in_x4;
  undefined **ppuVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 in_q0 [16];
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined1 in_register_00005044 [12];
  undefined4 in_s3;
  undefined1 in_register_00005064 [12];
  undefined4 in_s4;
  undefined4 in_s5;
  uint uStack_54;
  
  uVar9 = 0xe00002c9;
  uStack_54 = 0;
  if (((*(byte *)(param_1 + 0xe8) & 1) == 0) && ((*(byte *)(param_1 + 0xe9) & 1) == 0)) {
    FUN_fffffff009995d34(in_q0,in_q1,in_s2,in_s3,in_s4,in_s5,param_1);
    return 0xe00002e2;
  }
  auVar1._4_12_ = in_register_00005044;
  auVar1._0_4_ = in_s2;
  auVar3._4_12_ = in_register_00005064;
  auVar3._0_4_ = in_s3;
  plVar6 = FUN_fffffff009995ba8
                     (in_q0,in_q1,auVar1,auVar3,in_s4,in_s5,param_1,param_3,param_3,in_x3,in_x4);
  if (plVar6 == (long *)0x0) {
    return 0xe00002c9;
  }
  uVar10 = 0xe00002c2;
  if (**(long **)(param_3 + 0x20) == 4) {
    ppuVar8 = &PTR_DAT_fffffff007ff5748;
  }
  else {
    if (**(long **)(param_3 + 0x20) != 5) goto LAB_fffffff009985738;
    ppuVar8 = &PTR_DAT_fffffff007ff5d50;
  }
  plVar7 = (long *)(**(code **)(*(long *)*ppuVar8 + 0x68))();
  if (plVar7 == (long *)0x0) {
    uVar10 = 0xe00002bd;
    goto LAB_fffffff009985738;
  }
  iVar5 = (**(code **)(*plVar7 + 0xa8))(plVar7,plVar6);
  if ((iVar5 != 0) &&
     (iVar5 = (**(code **)(*plVar7 + 0x360))(plVar7,param_1), uVar10 = uVar9, iVar5 != 0)) {
    iVar5 = (**(code **)(*plVar7 + 0x2b0))(plVar7,param_1);
    if (iVar5 != 0) {
      auVar2._4_12_ = in_register_00005044;
      auVar2._0_4_ = in_s2;
      auVar4._4_12_ = in_register_00005064;
      auVar4._0_4_ = in_s3;
      uVar9 = thunk_FUN_fffffff00a9a7b30
                        (extraout_q0,in_q1,auVar2,auVar4,in_s4,in_s5,*(long *)(param_1 + 0xd8),
                         plVar7,&uStack_54);
      if ((int)uVar9 == 0) {
        **(ulong **)(param_3 + 0x48) = (ulong)uStack_54;
        uVar10 = uVar9;
        goto LAB_fffffff009985714;
      }
      (**(code **)(*plVar7 + 0x2b8))(plVar7,param_1);
    }
    (**(code **)(*plVar7 + 0x368))(plVar7,param_1);
    uVar10 = uVar9;
  }
LAB_fffffff009985714:
  (**(code **)(*plVar7 + 0x28))(plVar7);
LAB_fffffff009985738:
  (**(code **)(*plVar6 + 0x28))(plVar6);
  return uVar10;
}

