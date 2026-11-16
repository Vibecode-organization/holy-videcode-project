// FUN_fffffff009c2b810 @ fffffff009c2b810 size=184
// CALLERS:
//   fffffff009c3ae4c FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c3b6e0 FUN_fffffff009c3b628@fffffff009c3b628
//   fffffff009c3b934 FUN_fffffff009c3b7b0@fffffff009c3b7b0
//   fffffff009c3bd34 FUN_fffffff009c3bb20@fffffff009c3bb20
//   fffffff009c3c16c FUN_fffffff009c3bf44@fffffff009c3bf44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * FUN_fffffff009c2b810(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(_DAT_fffffff00af48238 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 0x78))(plVar1,param_1,param_2,param_3), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

