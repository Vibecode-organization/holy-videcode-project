// FUN_fffffff009974304 @ fffffff009974304 size=196

long * FUN_fffffff009974304(long *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = (long *)(**(code **)(*param_1 + 0x630))();
  if ((plVar2 == (long *)0x0) ||
     (iVar1 = (**(code **)(*plVar2 + 0x88))(plVar2,param_1,param_2,param_3), iVar1 != 0)) {
    FUN_fffffff009964f18(plVar2);
  }
  else {
    (**(code **)(*plVar2 + 0x28))(plVar2);
    plVar2 = (long *)0x0;
  }
  return plVar2;
}

