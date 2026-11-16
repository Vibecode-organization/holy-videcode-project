// FUN_fffffff009c418cc @ fffffff009c418cc size=160

long * FUN_fffffff009c418cc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af48408 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = FUN_fffffff009c4196c(plVar1,param_1,param_2,param_3), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

