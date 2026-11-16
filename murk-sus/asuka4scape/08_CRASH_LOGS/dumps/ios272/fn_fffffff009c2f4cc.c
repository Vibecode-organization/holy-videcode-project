// FUN_fffffff009c2f4cc @ fffffff009c2f4cc size=176

long * FUN_fffffff009c2f4cc
                 (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af482d8 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = FUN_fffffff009c2f57c(plVar1,param_1,param_2,param_3,param_4), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

