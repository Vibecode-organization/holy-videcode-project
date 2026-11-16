// FUN_fffffff00994276c @ fffffff00994276c size=76

long * FUN_fffffff00994276c(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0xb0);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1);
  }
  return plVar1;
}

