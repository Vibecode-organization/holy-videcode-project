// FUN_fffffff009a459b0 @ fffffff009a459b0 size=4 depth=0
// CALLERS:
//   fffffff00afe7cdf ?
//   fffffff0080120f8 ?
// CALLS:

undefined8 FUN_fffffff009a459b0(long *param_1,undefined8 param_2,long param_3)

{
  undefined ******ppppppuVar1;
  long *plVar2;
  undefined8 uVar3;
  long lStack_38;
  
  uVar3 = 0xe00002c2;
  lStack_38 = 0;
  if (*(long *)(param_3 + 0x78) == 0) {
    return 0xe00002c2;
  }
  if ((*(char **)(param_3 + 0x30) == (char *)0x0) || (*(uint *)(param_3 + 0x38) == 0)) {
    ppppppuVar1 = (undefined ******)0x0;
    plVar2 = (long *)0x0;
  }
  else {
    ppppppuVar1 = thunk_FUN_fffffff00a8d8754
                            (*(char **)(param_3 + 0x30),(ulong)*(uint *)(param_3 + 0x38),
                             (undefined8 *)0x0);
    if (ppppppuVar1 == (undefined ******)0x0) {
      return 0xe00002c2;
    }
    plVar2 = thunk_FUN_fffffff00a894f30((long *)ppppppuVar1,*(long *)PTR_PTR_fffffff008017358);
    if (plVar2 == (long *)0x0) goto LAB_fffffff009a45a74;
  }
  uVar3 = (**(code **)(*param_1 + 0x5f8))(param_1,plVar2,&lStack_38);
  if (((int)uVar3 == 0) && (lStack_38 != 0)) {
    **(long **)(param_3 + 0x78) = lStack_38;
  }
  if (ppppppuVar1 == (undefined ******)0x0) {
    return uVar3;
  }
LAB_fffffff009a45a74:
  (*(code *)(*ppppppuVar1)[5])(ppppppuVar1);
  return uVar3;
}

