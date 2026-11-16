// FUN_fffffff009c16670 @ fffffff009c16670 size=120

long * FUN_fffffff009c16670(long *param_1,long *param_2)

{
  long *plVar1;
  
  plVar1 = (long *)*param_1;
  *param_1 = (long)param_2;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return param_1;
}

