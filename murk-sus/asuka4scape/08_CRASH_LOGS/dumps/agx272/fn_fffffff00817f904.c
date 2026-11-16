// FUN_fffffff00817f904 @ fffffff00817f904 size=160

long * FUN_fffffff00817f904(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x2f0);
  uVar1 = (**(code **)(**(long **)(param_1 + 0x4b0) + 0x2f8))();
  (**(code **)(*plVar2 + 0xc0))(plVar2,uVar1);
  plVar2 = *(long **)(param_1 + 0x2f0);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  return plVar2;
}

