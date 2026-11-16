// FUN_fffffff009c16a78 @ fffffff009c16a78 size=152

long * FUN_fffffff009c16a78(undefined8 param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af48198 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = FUN_fffffff009c16b10(plVar1,param_1,param_2), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

