// FUN_fffffff009c2cf30 @ fffffff009c2cf30 size=160
// CALLERS:
//   fffffff00afebe76 no-fn
//   fffffff009c1e6f0 FUN_fffffff009c1e624@fffffff009c1e624
//   fffffff009c24d48 FUN_fffffff009c24b28@fffffff009c24b28
// CALLEES:

long * FUN_fffffff009c2cf30(undefined8 param_1)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af48260 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 0x78))(plVar1,param_1), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

