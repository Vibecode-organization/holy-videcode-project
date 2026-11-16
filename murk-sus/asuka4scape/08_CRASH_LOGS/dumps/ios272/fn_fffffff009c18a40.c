// FUN_fffffff009c18a40 @ fffffff009c18a40 size=116

undefined8 * FUN_fffffff009c18a40(undefined8 *param_1,long *param_2)

{
  long *plVar1;
  
  plVar1 = (long *)*param_1;
  *param_1 = param_2;
  (**(code **)(*param_2 + 0x20))(param_2);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return param_1;
}

