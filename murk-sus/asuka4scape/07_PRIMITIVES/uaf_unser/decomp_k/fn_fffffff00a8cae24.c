// FUN_fffffff00a8cae24 @ fffffff00a8cae24 size=172
// CALLERS:
//   fffffff00a8c7bc8 FUN_fffffff00a8c7968@fffffff00a8c7968
//   fffffff00a9d435c FUN_fffffff00a9d4100@fffffff00a9d4100
//   fffffff00a98b4b0 FUN_fffffff00a98b174@fffffff00a98b174

long * FUN_fffffff00a8cae24(undefined8 param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00ad95dc8 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 0x78))(plVar1,param_1,param_2), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

