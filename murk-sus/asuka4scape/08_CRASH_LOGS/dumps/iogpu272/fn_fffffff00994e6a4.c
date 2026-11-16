// FUN_fffffff00994e6a4 @ fffffff00994e6a4 size=160

long * FUN_fffffff00994e6a4(undefined8 param_1)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af22308 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 0x80))(plVar1,param_1), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

