// FUN_fffffff009944e20 @ fffffff009944e20 size=152

long * FUN_fffffff009944e20(void)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af22150 + 0x68))();
  if ((plVar1 != (long *)0x0) && (uVar2 = (**(code **)(*plVar1 + 0x68))(plVar1), (uVar2 & 1) == 0))
  {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

