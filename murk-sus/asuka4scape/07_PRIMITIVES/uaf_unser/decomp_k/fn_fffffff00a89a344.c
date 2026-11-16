// FUN_fffffff00a89a344 @ fffffff00a89a344 size=172
// CALLERS:

long * FUN_fffffff00a89a344(undefined8 param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00ad95bd0 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 0xe0))(plVar1,param_1,param_2), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

