// FUN_fffffff009c4078c @ fffffff009c4078c size=96
// CALLERS:
//   fffffff00afec13c no-fn
//   fffffff009c3e6ac FUN_fffffff009c3e570@fffffff009c3e570
//   fffffff009c3e9a8 FUN_fffffff009c3e86c@fffffff009c3e86c
//   fffffff009c3ecb4 FUN_fffffff009c3eb68@fffffff009c3eb68
// CALLEES:
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30

long * FUN_fffffff009c4078c(undefined8 *param_1)

{
  long *plVar1;
  
  plVar1 = thunk_FUN_fffffff00a894f30((long *)*param_1,(long)PTR_DAT_fffffff00806a720);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1);
  }
  return plVar1;
}

