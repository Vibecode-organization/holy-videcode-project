// FUN_fffffff0081dee48 @ fffffff0081dee48 size=88

void FUN_fffffff0081dee48(long param_1)

{
  long *plVar1;
  
  FUN_fffffff008172450();
  plVar1 = *(long **)(param_1 + 0x1acf0);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))();
  }
  *(long *)(param_1 + 0x1acf0) = 0;
  return;
}

