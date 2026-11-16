// FUN_fffffff00816aba4 @ fffffff00816aba4 size=180

long * FUN_fffffff00816aba4(long *param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(*param_1 + 0x860))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 0xb0))(plVar1,param_1,0,param_2), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

