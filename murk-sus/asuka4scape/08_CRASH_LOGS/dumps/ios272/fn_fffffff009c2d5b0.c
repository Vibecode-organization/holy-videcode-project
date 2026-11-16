// FUN_fffffff009c2d5b0 @ fffffff009c2d5b0 size=228

long * FUN_fffffff009c2d5b0
                 (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af48288 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 0x78))
                        (plVar1,param_1,param_2,param_3,param_4,param_5,1,param_6), (uVar2 & 1) == 0
     )) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

