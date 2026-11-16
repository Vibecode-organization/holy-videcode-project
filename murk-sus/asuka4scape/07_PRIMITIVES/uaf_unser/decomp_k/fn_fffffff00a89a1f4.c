// FUN_fffffff00a89a1f4 @ fffffff00a89a1f4 size=156
// CALLERS:
//   fffffff00a8c1e74 FUN_fffffff00a8c0908@fffffff00a8c0908
//   fffffff00a9d4388 FUN_fffffff00a9d4100@fffffff00a9d4100
//   fffffff00a940ae0 FUN_fffffff00a94080c@fffffff00a94080c

long * FUN_fffffff00a89a1f4(undefined8 param_1)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00ad95bd0 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 0xd0))(plVar1,param_1), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

