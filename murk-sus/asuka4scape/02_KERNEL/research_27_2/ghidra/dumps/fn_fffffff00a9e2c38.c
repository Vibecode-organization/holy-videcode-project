// FUN_fffffff00a9e2c38 @ fffffff00a9e2c38 size=380
// CALLERS:
//   fffffff00afbfad4 no-fn
//   fffffff00a9e2ba4 FUN_fffffff00a9e2a8c@fffffff00a9e2a8c
// CALLEES:
//   fffffff00a22c2dc FUN_fffffff00a22c2dc
//   fffffff00a27cacc FUN_fffffff00a27cacc
//   fffffff00a393464 FUN_fffffff00a393464
//   fffffff00a22c478 FUN_fffffff00a22c478
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a20bb9c FUN_fffffff00a20bb9c
//   fffffff00aa61ea0 FUN_fffffff00aa61ea0

void FUN_fffffff00a9e2c38
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               long param_8,undefined **param_9,ulong param_10,ulong param_11)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  undefined1 auVar7 [16];
  int iVar8;
  undefined8 extraout_x1;
  long *plVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  uVar12 = param_4._0_4_;
  uVar11 = param_3._0_4_;
  lVar6 = tpidr_el1;
  uVar4 = daif;
  if (((uint)uVar4 >> 9 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114
              (param_1,param_2,param_3,param_4,param_5,param_6,
               (byte *)"%s: debug exceptions enabled in kernel mode @%s:%d");
  }
  plVar9 = *(long **)(param_7 + 0x30);
  if ((uVar4 & 0x1c0) != 0x1c0) {
    uVar5 = daif;
    daif = uVar5 | 0x1c0;
  }
  *(int *)(lVar6 + 0x1c0) = *(int *)(lVar6 + 0x1c0) + 1;
  if (*plVar9 == 0) {
    if (*plVar9 != 0) goto LAB_fffffff00a9e2d58;
    *plVar9 = lVar6;
  }
  else {
    WaitForEvent();
LAB_fffffff00a9e2d58:
    param_9 = &PTR_s_hw_lock_t_fffffff007bc34b8;
    FUN_fffffff00a22c2dc(plVar9,lVar6,-0xff843cb48);
  }
  puVar10 = (undefined8 *)(*(ulong *)(param_7 + 0x18) + param_8 * 0x38);
  if (((*(ulong *)(param_7 + 0x18) ^ (ulong)puVar10) & 0xffc0000000000000) != 0) {
    puVar10 = (undefined8 *)((ulong)puVar10 & 0xffffffffffff | 0xc8a2000000000000);
  }
  puVar2 = (undefined8 *)*puVar10;
  puVar3 = (undefined8 *)puVar10[1];
  puVar10[3] = 0;
  puVar10[2] = 0;
  puVar10[5] = 0;
  puVar10[4] = 0;
  puVar10[6] = 0;
  puVar10[1] = 0;
  *puVar10 = 0;
  *(long *)(param_7 + 0x28) = param_8;
  auVar7 = FUN_fffffff00a22c478(*(undefined8 **)(param_7 + 0x30));
  FUN_fffffff00a393464
            (auVar7,param_2,uVar11,uVar12,param_5,param_6,(ulong)((uVar4 & 0x1c0) != 0x1c0),
             extraout_x1,param_9,param_10,param_11);
  piVar1 = (int *)(puVar2 + 5);
  iVar8 = *piVar1;
  *piVar1 = iVar8 + -1;
  LORelease();
  if (iVar8 != 0) {
    if (iVar8 == 1) {
      FUN_fffffff00a27cacc(puVar2);
    }
    if (puVar3 != (undefined8 *)0x0) {
      iVar8 = *(int *)(puVar3 + 2);
      *(int *)(puVar3 + 2) = iVar8 + -1;
      LORelease();
      if (iVar8 == 0) goto LAB_fffffff00a9e2d28;
      if (iVar8 == 1) {
        FUN_fffffff00a20bb9c(puVar3);
        return;
      }
    }
    return;
  }
LAB_fffffff00a9e2d28:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa61ea0();
}

