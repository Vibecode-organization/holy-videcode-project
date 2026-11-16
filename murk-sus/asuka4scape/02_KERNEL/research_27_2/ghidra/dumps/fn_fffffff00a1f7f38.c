// FUN_fffffff00a1f7f38 @ fffffff00a1f7f38 size=384
// CALLERS:
//   fffffff00afb831f no-fn
//   fffffff00a1f8754 FUN_fffffff00a1f8614@fffffff00a1f8614
//   fffffff00a1f87c4 FUN_fffffff00a1f8614@fffffff00a1f8614
//   fffffff00a1f9cbc FUN_fffffff00a1f9b10@fffffff00a1f9b10
//   fffffff00a1f9da4 FUN_fffffff00a1f9b10@fffffff00a1f9b10
//   fffffff00a1f9df4 FUN_fffffff00a1f9b10@fffffff00a1f9b10
//   fffffff00a1f7ad0 FUN_fffffff00a1f79e8@fffffff00a1f79e8
//   fffffff00a1f8cf0 FUN_fffffff00a202714@fffffff00a202714
//   fffffff00a1f8df4 FUN_fffffff00a202714@fffffff00a202714
//   fffffff00a1f8e48 FUN_fffffff00a202714@fffffff00a202714
//   fffffff00a1f97ec FUN_fffffff00a1f9784@fffffff00a1f9784
// CALLEES:
//   fffffff00a1f1060 FUN_fffffff00a1f1060
//   fffffff00a1f036c FUN_fffffff00a1f036c
//   fffffff00a1e1fe4 FUN_fffffff00a1e1fe4
//   fffffff00a22b804 FUN_fffffff00a22b804
//   fffffff00aa4ccac FUN_fffffff00aa4ccac

undefined8
FUN_fffffff00a1f7f38(long param_1,ulong param_2,undefined8 param_3,undefined8 *param_4,int param_5)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  
  FUN_fffffff00a1f036c(param_2);
  if (((*(byte *)(param_2 + 1) & 7) == 0) &&
     (((param_5 != 1 || (*(int *)((long)param_4 + 0xc) != 0)) ||
      ((*(byte *)((long)param_4 + 10) >> 2 & 1) == 0)))) {
    uVar1 = *(uint *)(param_4 + 1);
    uVar6 = (uint)((ulong)param_3 >> 8) & 0xffffff;
    if ((uVar1 >> 0x10 & 1) == 0) {
      iVar3 = *(int *)(param_2 + 0x8c);
      *(int *)(param_2 + 0x8c) = iVar3 + -1;
      uVar4 = extraout_x1;
      if (iVar3 == 0) {
LAB_fffffff00a1f80ac:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4ccac();
      }
    }
    else {
      iVar3 = *(int *)(param_2 + 0x88);
      *(int *)(param_2 + 0x88) = iVar3 + -1;
      if (iVar3 == 0) goto LAB_fffffff00a1f80ac;
      uVar5 = *(ulong *)(param_1 + 0x48);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      if (uVar5 == 0) {
        uVar5 = 0;
      }
      FUN_fffffff00a1e1fe4(uVar5,param_2,uVar6);
      uVar4 = extraout_x1_00;
    }
    uVar7 = uVar1 & 0xffa0ffff | 0x100000;
    if (*(uint *)((long)param_4 + 0xc) != 0) {
      iVar3 = FUN_fffffff00a1f1060(param_2,uVar4,*(uint *)((long)param_4 + 0xc));
      if (iVar3 != 0 && ((uVar1 ^ 0xffffffff) & 0xffff) != 0) {
        uVar7 = (uVar1 & 0xffa0ffff) + 0x100001;
      }
      *(undefined4 *)((long)param_4 + 0xc) = 0;
    }
    *(uint *)(param_4 + 1) = uVar7;
    *param_4 = 0;
    if ((*(byte *)(param_2 + 2) & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f80a8);
      (*pcVar2)();
    }
    FUN_fffffff00a22b804(param_2 + 0x14);
    if (uVar6 < *(uint *)(param_1 + 0x70)) {
      *(uint *)(param_1 + 0x70) = uVar6;
    }
    if (*(uint *)(param_1 + 0x74) < uVar6) {
      *(uint *)(param_1 + 0x74) = uVar6;
    }
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

