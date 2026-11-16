// FUN_fffffff008dba6e8 @ fffffff008dba6e8 size=248
// CALLERS:
//   fffffff00afba2a3 no-fn
//   fffffff008d56ca8 FUN_fffffff008d56c68@fffffff008d56c68
// CALLEES:
//   fffffff008dfd5e8 FUN_fffffff008dfd5e8
//   fffffff008cd5954 FUN_fffffff008cd5954

long * FUN_fffffff008dba6e8(long *param_1,long param_2)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  
  plVar2 = (long *)(**(code **)(DAT_fffffff00ae70008 + 0x68))();
  if ((plVar2 == (long *)0x0) || (uVar3 = (**(code **)(*plVar2 + 0x68))(plVar2), (uVar3 & 1) == 0))
  {
    iVar1 = FUN_fffffff008cd5954(1,0xf);
    if (iVar1 != 0) {
      FUN_fffffff008dfd5e8();
    }
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
      plVar2 = (long *)0x0;
    }
  }
  else {
    (**(code **)(*param_1 + 0x20))(param_1);
    plVar2[10] = (long)param_1;
    plVar2[0x185] = param_2;
    plVar2[0x202] = 0;
  }
  return plVar2;
}

