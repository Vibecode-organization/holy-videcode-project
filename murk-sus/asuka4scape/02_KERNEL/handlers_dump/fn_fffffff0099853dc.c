// FUN_fffffff0099853dc @ fffffff0099853dc size=4 depth=0
// CALLERS:
//   fffffff00afe6531 ?
//   fffffff007ff2fe8 ?
// CALLS:

undefined8 FUN_fffffff0099853dc(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  ulong *in_x3;
  undefined *in_x4;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 in_q0 [16];
  undefined1 extraout_q0 [16];
  undefined1 in_q1 [16];
  undefined1 in_q2 [16];
  undefined1 in_q3 [16];
  undefined4 in_s4;
  undefined4 in_s5;
  uint uStack_54;
  
  uVar4 = 0xe00002c9;
  uStack_54 = 0;
  plVar2 = FUN_fffffff009995ba8
                     (in_q0,in_q1,in_q2,in_q3,in_s4,in_s5,param_1,param_3,param_3,in_x3,in_x4);
  if (plVar2 == (long *)0x0) {
    return 0xe00002c9;
  }
  uVar5 = 0xe00002c2;
  if (**(long **)(param_3 + 0x20) != 0) goto LAB_fffffff009985524;
  plVar3 = (long *)(**(code **)(*(long *)PTR_DAT_fffffff007ff5140 + 0x68))();
  if (plVar3 == (long *)0x0) {
    uVar5 = 0xe00002bd;
    goto LAB_fffffff009985524;
  }
  iVar1 = (**(code **)(*plVar3 + 0xa8))(plVar3,plVar2);
  if ((iVar1 != 0) &&
     (iVar1 = (**(code **)(*plVar3 + 0x360))(plVar3,param_1), uVar5 = uVar4, iVar1 != 0)) {
    iVar1 = (**(code **)(*plVar3 + 0x2b0))(plVar3,param_1);
    if (iVar1 != 0) {
      uVar4 = thunk_FUN_fffffff00a9a7b30
                        (extraout_q0,in_q1,in_q2,in_q3,in_s4,in_s5,*(long *)(param_1 + 0xd8),plVar3,
                         &uStack_54);
      if ((int)uVar4 == 0) {
        **(ulong **)(param_3 + 0x48) = (ulong)uStack_54;
        uVar5 = uVar4;
        goto LAB_fffffff00998550c;
      }
      (**(code **)(*plVar3 + 0x2b8))(plVar3,param_1);
    }
    (**(code **)(*plVar3 + 0x368))(plVar3,param_1);
    uVar5 = uVar4;
  }
LAB_fffffff00998550c:
  (**(code **)(*plVar3 + 0x28))(plVar3);
LAB_fffffff009985524:
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return uVar5;
}

