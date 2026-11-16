// FUN_fffffff00996dc74 @ fffffff00996dc74 size=76

long * FUN_fffffff00996dc74(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x50);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1);
  }
  return plVar1;
}

