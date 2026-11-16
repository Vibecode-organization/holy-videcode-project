// FUN_fffffff00997e0b0 @ fffffff00997e0b0 size=252

long FUN_fffffff00997e0b0(long *param_1)

{
  long *plVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  
  if ((long *)param_1[1] != (long *)0x0) {
    (**(code **)(*(long *)param_1[1] + 0x28))();
  }
  param_1[1] = 0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(*param_1 + 0x28));
  lVar6 = *param_1;
  iVar2 = *(int *)(lVar6 + 0x1c);
  if (*(int *)((long)param_1 + 0x14) == iVar2) {
    uVar3 = *(uint *)(param_1 + 2);
    iVar5 = *(int *)(lVar6 + 0x14);
    if ((int)uVar3 < iVar5) goto joined_r0xfffffff00997e134;
  }
  else {
    iVar5 = *(int *)(lVar6 + 0x14);
  }
  uVar3 = iVar5 - 1;
  *(uint *)(param_1 + 2) = uVar3;
  *(int *)((long)param_1 + 0x14) = iVar2;
joined_r0xfffffff00997e134:
  while (-1 < (int)uVar3) {
    while( true ) {
      uVar4 = (ulong)uVar3;
      lVar7 = *(long *)(*param_1 + 8);
      uVar3 = uVar3 - 1;
      *(uint *)(param_1 + 2) = uVar3;
      lVar6 = uVar4 * 0x10;
      plVar1 = (long *)(lVar7 + (int)lVar6);
      if (lVar6 != (int)lVar6) {
        plVar1 = (long *)(lVar7 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar6 = *plVar1;
      if (lVar6 == 0) break;
      uVar4 = FUN_fffffff00994d91c(lVar6);
      if ((uVar4 & 1) != 0) {
        param_1[1] = lVar6;
        goto LAB_fffffff00997e190;
      }
      uVar3 = *(uint *)(param_1 + 2);
      if ((int)uVar3 < 0) goto LAB_fffffff00997e190;
    }
  }
LAB_fffffff00997e190:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(*param_1 + 0x28));
  return param_1[1];
}

