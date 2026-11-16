// FUN_fffffff009981d0c @ fffffff009981d0c size=92

long * FUN_fffffff009981d0c(long param_1)

{
  long *plVar1;
  
  FUN_fffffff009942d70();
  plVar1 = *(long **)(param_1 + 0x90);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1);
  }
  FUN_fffffff009942d7c(param_1);
  return plVar1;
}

