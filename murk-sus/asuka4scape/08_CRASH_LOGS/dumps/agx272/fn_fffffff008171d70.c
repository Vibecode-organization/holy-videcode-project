// FUN_fffffff008171d70 @ fffffff008171d70 size=216

long * FUN_fffffff008171d70(long *param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  
  plVar2 = (long *)(**(code **)(*param_1 + 0x860))();
  if (plVar2 == (long *)0x0) {
    plVar3 = (long *)0x0;
  }
  else {
    iVar1 = (**(code **)(*plVar2 + 0xa8))(plVar2,param_1,param_2,0);
    if (iVar1 == 0) {
      plVar3 = (long *)0x0;
    }
    else {
      (**(code **)(*plVar2 + 0x20))(plVar2);
      plVar3 = plVar2;
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return plVar3;
}

