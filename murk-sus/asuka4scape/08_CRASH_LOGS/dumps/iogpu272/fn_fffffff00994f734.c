// FUN_fffffff00994f734 @ fffffff00994f734 size=212

long * FUN_fffffff00994f734(long *param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = (long *)(**(code **)(DAT_fffffff00af22380 + 0x68))();
  if (plVar2 != (long *)0x0) {
    iVar1 = FUN_fffffff00994ea4c(plVar2,param_3,param_4);
    if (iVar1 == 0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
      plVar2 = (long *)0x0;
    }
    else {
      plVar2[0x1a] = (long)param_1;
      (**(code **)(*param_1 + 0x20))(param_1);
      plVar2[0x1b] = param_2;
    }
  }
  return plVar2;
}

