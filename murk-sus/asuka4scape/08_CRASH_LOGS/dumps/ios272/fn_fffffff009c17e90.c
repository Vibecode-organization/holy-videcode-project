// FUN_fffffff009c17e90 @ fffffff009c17e90 size=184

long * FUN_fffffff009c17e90
                 (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af481c0 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = FUN_fffffff009c18984(plVar1,param_1,param_2,param_3,param_4,param_5), (uVar2 & 1) == 0
     )) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

