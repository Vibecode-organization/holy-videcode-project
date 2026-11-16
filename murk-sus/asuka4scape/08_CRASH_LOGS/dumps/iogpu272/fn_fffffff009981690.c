// FUN_fffffff009981690 @ fffffff009981690 size=176

undefined8 FUN_fffffff009981690(long param_1)

{
  long *plVar1;
  
  if (*(int *)(param_1 + 0x84) != 0) {
    return 0;
  }
  if (*(long *)(param_1 + 0x88) != 0) {
    plVar1 = (long *)thunk_EXT_FUN_80110000039772b0(*(undefined8 *)(param_1 + 0x90));
    if (plVar1 == (long *)0x0) {
      *(undefined4 *)(param_1 + 0x84) = 1;
      return 0;
    }
    if (*(long **)(param_1 + 0x90) == plVar1) {
      (**(code **)(*plVar1 + 0x28))();
      return 1;
    }
    *(undefined4 *)(param_1 + 0x84) = 1;
    (**(code **)(*plVar1 + 0x28))();
  }
  return 0;
}

