// FUN_fffffff00996e9f0 @ fffffff00996e9f0 size=328

long * FUN_fffffff00996e9f0
                 (undefined8 param_1,long *param_2,long *param_3,undefined8 param_4,
                 undefined8 param_5)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af22678 + 0x68))();
  if (plVar1 != (long *)0x0) {
    if (param_2 != (long *)0x0) {
      (**(code **)(*param_2 + 0x20))(param_2);
    }
    if (param_3 != (long *)0x0) {
      (**(code **)(*param_3 + 0x20))(param_3);
    }
    uVar2 = FUN_fffffff00996eb38(plVar1,param_1,param_2,param_3,param_4,param_5);
    if ((uVar2 & 1) == 0) {
      (**(code **)(*plVar1 + 0x28))(plVar1);
      plVar1 = (long *)0x0;
    }
  }
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x28))(param_3);
  }
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  return plVar1;
}

