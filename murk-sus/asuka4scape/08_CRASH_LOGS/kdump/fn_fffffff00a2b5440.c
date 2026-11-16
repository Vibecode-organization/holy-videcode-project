// FUN_fffffff00a2b5440 @ fffffff00a2b5440 size=284
// CALLERS:
//   fffffff00afb9206 ?
//   fffffff007bc97e8 ?
// CALLS:
//   fffffff00a270c78 FUN_fffffff00a270c78
//   fffffff00a21dab8 FUN_fffffff00a21dab8
//   fffffff00a277460 FUN_fffffff00a277460
//   fffffff00aa61ea0 FUN_fffffff00aa61ea0

void FUN_fffffff00a2b5440
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,int *param_7,
               long param_8,undefined8 param_9,long param_10,undefined8 *param_11)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  undefined8 extraout_x1;
  undefined **ppuVar4;
  undefined8 *puVar5;
  undefined **ppuVar6;
  undefined1 extraout_q0 [16];
  
  if ((*param_7 < 0) || (param_7[1] != 0x30)) {
    *(undefined4 *)(param_10 + 0x28) = 0xfffffed0;
    *(undefined8 *)(param_10 + 0x20) = DAT_fffffff00ad0e748;
  }
  else {
    puVar5 = param_11;
    plVar3 = (long *)FUN_fffffff00a21dab8(*(byte **)(param_7 + 2));
    ppuVar6 = (undefined **)((long)param_11 + 0xc);
    *(undefined4 *)ppuVar6 = 0x20;
    uVar1 = *(uint *)(param_8 + 0xc);
    if (0x1f < uVar1) {
      uVar1 = 0x20;
    }
    *(uint *)ppuVar6 = uVar1;
    ppuVar4 = (undefined **)(param_11 + 2);
    iVar2 = FUN_fffffff00a277460
                      (extraout_q0,param_2,param_3,param_4,param_5,param_6,plVar3,
                       *(int *)(param_8 + 8),ppuVar4,(uint *)ppuVar6,(ulong)puVar5);
    *(int *)(param_11 + 1) = iVar2;
    if (plVar3 != (long *)0x0) {
      iVar2 = (int)plVar3[0x43];
      *(int *)(plVar3 + 0x43) = iVar2 + -1;
      LORelease();
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa61ea0();
      }
      if (iVar2 == 1) {
        FUN_fffffff00a270c78(plVar3,extraout_x1,(long)ppuVar4,ppuVar6,(undefined *)puVar5);
      }
      iVar2 = *(int *)(param_11 + 1);
    }
    if (iVar2 == 0) {
      *param_11 = DAT_fffffff00ad0e748;
      *(int *)(param_10 + 4) = *(int *)((long)param_11 + 0xc) * 4 + 0x30;
    }
    else {
      *(int *)(param_10 + 0x28) = iVar2;
      *(undefined8 *)(param_10 + 0x20) = DAT_fffffff00ad0e748;
    }
  }
  return;
}

