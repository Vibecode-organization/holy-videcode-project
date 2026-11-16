// FUN_fffffff009951a44 @ fffffff009951a44 size=100

bool FUN_fffffff009951a44(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x30);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    *(undefined8 *)(param_1 + 0x30) = 0;
    FUN_fffffff00997511c(*(undefined8 *)(param_1 + 0x20),param_1);
  }
  return plVar1 != (long *)0x0;
}

