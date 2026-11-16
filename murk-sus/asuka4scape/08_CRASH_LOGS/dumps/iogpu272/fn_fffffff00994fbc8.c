// FUN_fffffff00994fbc8 @ fffffff00994fbc8 size=196

long * FUN_fffffff00994fbc8(long *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = (long *)(**(code **)(DAT_fffffff00af223a8 + 0x68))();
  if (plVar2 != (long *)0x0) {
    iVar1 = FUN_fffffff00994ea4c(plVar2,param_2,param_3);
    if (iVar1 == 0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
      plVar2 = (long *)0x0;
    }
    else {
      (**(code **)(*param_1 + 0x20))(param_1);
      plVar2[0x1a] = (long)param_1;
    }
  }
  return plVar2;
}

