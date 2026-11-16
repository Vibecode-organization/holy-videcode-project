// FUN_fffffff00a1f9784 @ fffffff00a1f9784 size=380
// CALLERS:
//   fffffff00afb832b no-fn
//   fffffff00a202274 FUN_fffffff00a202204@fffffff00a202204
//   fffffff00a202684 FUN_fffffff00a202610@fffffff00a202610
// CALLEES:
//   fffffff00a1f1060 FUN_fffffff00a1f1060
//   fffffff00a1f036c FUN_fffffff00a1f036c
//   fffffff00a22b850 FUN_fffffff00a22b850
//   fffffff00a1ed700 FUN_fffffff00a1ed700
//   fffffff00a22b804 FUN_fffffff00a22b804
//   fffffff00aa61ea0 FUN_fffffff00aa61ea0
//   fffffff00a1f7f38 FUN_fffffff00a1f7f38
//   fffffff00aa4cc7c FUN_fffffff00aa4cc7c

undefined8
FUN_fffffff00a1f9784(long param_1,undefined8 param_2,long *param_3,uint *param_4,uint *param_5)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  char *pcVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(param_3 + 1);
  uVar3 = *(uint *)((long)param_3 + 0xc);
  pcVar5 = (char *)*param_3;
  if (pcVar5 == (char *)0x0) {
    pcVar5 = (char *)0x0;
    if ((uVar6 >> 0x11 & 1) != 0) goto LAB_fffffff00a1f9830;
LAB_fffffff00a1f97d0:
    if ((uVar6 & 0x50000) == 0) {
      FUN_fffffff00a22b850(param_1);
    }
    else {
      uVar4 = FUN_fffffff00a1f7f38(param_1,(ulong)pcVar5,param_2,param_3,0);
      if ((uVar4 & 1) == 0) {
        if (uVar3 != 0) {
          uVar3 = FUN_fffffff00a1f1060((long)pcVar5,extraout_x1,uVar3);
        }
        if ((pcVar5[2] & 1U) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f98f8);
          (*pcVar1)();
        }
        FUN_fffffff00a22b804((long)(pcVar5 + 0x14));
        goto LAB_fffffff00a1f98a8;
      }
      uVar6 = *(uint *)(param_3 + 1);
      FUN_fffffff00a22b850(param_1);
      iVar2 = *(int *)(pcVar5 + 4);
      *(int *)(pcVar5 + 4) = iVar2 + -1;
      LORelease();
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa61ea0();
      }
      if (iVar2 == 1) {
        FUN_fffffff00a1ed700(pcVar5);
      }
    }
    uVar3 = 0;
  }
  else {
    if ((uVar6 >> 0x11 & 1) == 0) goto LAB_fffffff00a1f97d0;
LAB_fffffff00a1f9830:
    if (uVar3 != 0) {
      FUN_fffffff00a1f036c((ulong)pcVar5);
      if ((pcVar5[1] & 7U) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4cc7c();
      }
      uVar3 = FUN_fffffff00a1f1060((long)pcVar5,extraout_x1_00,uVar3);
      if ((pcVar5[2] & 1U) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1f98e8);
        (*pcVar1)();
      }
      FUN_fffffff00a22b804((long)(pcVar5 + 0x14));
    }
LAB_fffffff00a1f98a8:
    FUN_fffffff00a22b850(param_1);
  }
  *param_4 = uVar3 | uVar6 & 0x1f0000;
  *param_5 = uVar6 & 0xffff;
  return 0;
}

