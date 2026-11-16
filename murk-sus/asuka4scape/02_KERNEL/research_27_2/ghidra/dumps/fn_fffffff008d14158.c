// FUN_fffffff008d14158 @ fffffff008d14158 size=120
// CALLERS:
//   fffffff00afb8d36 no-fn
//   fffffff008d1473c FUN_fffffff008d1465c@fffffff008d1465c
//   fffffff008d147d4 FUN_fffffff008d1475c@fffffff008d1475c
// CALLEES:
//   fffffff008e006b0 thunk_EXT_FUN_8011000003398228
//   fffffff008d142e8 FUN_fffffff008d142e8
//   fffffff008d141d0 FUN_fffffff008d141d0
//   fffffff008e00760 thunk_EXT_FUN_8011000003397c88

void FUN_fffffff008d14158(long param_1,long param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 local_38;
  
  lVar4 = *(long *)(param_2 + 8);
  piVar1 = (int *)(param_1 + 0xdc);
  LOAcquire();
  iVar2 = *piVar1;
  *piVar1 = iVar2 + 1;
  LORelease();
  local_38 = 0;
  uVar3 = thunk_EXT_FUN_8011000003397c88(CONCAT44((int)((ulong)piVar1 >> 0x20),iVar2));
  thunk_EXT_FUN_8011000003398228(uVar3,&local_38);
  *(undefined8 *)(param_1 + 0xf8) = local_38;
  if (lVar4 == 0) {
    FUN_fffffff008d141d0(param_1,param_2);
  }
  else {
    FUN_fffffff008d142e8();
  }
  return;
}

