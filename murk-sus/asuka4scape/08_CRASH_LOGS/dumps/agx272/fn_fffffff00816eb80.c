// FUN_fffffff00816eb80 @ fffffff00816eb80 size=160

long * FUN_fffffff00816eb80(long param_1)

{
  long *plVar1;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00ae23f50 + 0x68))();
  *(long **)(param_1 + 0x1ac50) = plVar1;
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return plVar1;
}

