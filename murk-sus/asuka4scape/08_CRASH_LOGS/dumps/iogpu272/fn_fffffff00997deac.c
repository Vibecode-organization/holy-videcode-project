// FUN_fffffff00997deac @ fffffff00997deac size=300

long FUN_fffffff00997deac(long *param_1)

{
  long *plVar1;
  ulong uVar2;
  long *plVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  
  if ((long *)param_1[1] != (long *)0x0) {
    (**(code **)(*(long *)param_1[1] + 0x28))();
  }
  param_1[1] = 0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(*param_1 + 0x28));
  while( true ) {
    plVar3 = (long *)*param_1;
    iVar4 = *(int *)((long)plVar3 + 0x1c);
    if (*(int *)((long)param_1 + 0x14) == iVar4) {
      uVar5 = (ulong)*(uint *)(param_1 + 2);
    }
    else {
      uVar5 = 0;
      *(undefined4 *)(param_1 + 2) = 0;
      *(int *)((long)param_1 + 0x14) = iVar4;
    }
    while( true ) {
      iVar4 = (int)uVar5;
      if (*(int *)((long)plVar3 + 0x14) <= iVar4) break;
      lVar6 = plVar3[1];
      uVar2 = uVar5 << 4;
      uVar7 = -(uVar5 >> 0x1f) & 0xfffffff000000000 | uVar2;
      uVar5 = (ulong)(iVar4 + 1U);
      *(uint *)(param_1 + 2) = iVar4 + 1U;
      iVar4 = (int)uVar2;
      plVar1 = (long *)(lVar6 + iVar4);
      if (uVar7 != (long)iVar4) {
        plVar1 = (long *)(lVar6 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
      }
      lVar6 = *plVar1;
      if (((lVar6 != 0) && (*(ulong *)(lVar6 + 0x18) != 0)) &&
         (*(ulong *)(lVar6 + 0x18) <= (ulong)plVar3[4])) {
        uVar5 = FUN_fffffff00994d91c(lVar6);
        if ((uVar5 & 1) != 0) {
          param_1[1] = lVar6;
          plVar3 = (long *)*param_1;
          goto LAB_fffffff00997dfc0;
        }
        uVar5 = (ulong)*(uint *)(param_1 + 2);
        plVar3 = (long *)*param_1;
      }
    }
    if ((param_1[1] != 0 || iVar4 < *(int *)((long)plVar3 + 0x14)) ||
       (lVar6 = *plVar3, plVar3 = (long *)*param_1,
       *(ulong *)(*(long *)(lVar6 + 0x160) + 0x178) <= (ulong)plVar3[4])) break;
    FUN_fffffff00997dbb4();
  }
LAB_fffffff00997dfc0:
  thunk_EXT_FUN_8011000003222de0(plVar3[5]);
  return param_1[1];
}

