// FUN_fffffff0081d6e74 @ fffffff0081d6e74 size=212

long * FUN_fffffff0081d6e74(long param_1)

{
  ulong uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x1ac60);
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)(**(code **)(DAT_fffffff00ae22b10 + 0x68))();
    if ((plVar2 != (long *)0x0) &&
       (uVar1 = (**(code **)(*plVar2 + 0x88))(plVar2,param_1), (uVar1 & 1) == 0)) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
      plVar2 = (long *)0x0;
    }
  }
  else {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  return plVar2;
}

