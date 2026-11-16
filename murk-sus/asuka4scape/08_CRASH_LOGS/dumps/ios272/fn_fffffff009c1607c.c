// FUN_fffffff009c1607c @ fffffff009c1607c size=136

long * FUN_fffffff009c1607c(undefined8 param_1)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af48148 + 0x68))();
  if ((plVar1 != (long *)0x0) && (uVar2 = FUN_fffffff009c16104(plVar1,param_1), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

