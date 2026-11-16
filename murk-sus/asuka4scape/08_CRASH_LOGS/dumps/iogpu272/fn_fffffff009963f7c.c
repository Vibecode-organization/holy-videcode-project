// FUN_fffffff009963f7c @ fffffff009963f7c size=4

void FUN_fffffff009963f7c(long param_1,undefined8 param_2)

{
  long *plVar1;
  long *plStack_28;
  
  for (plVar1 = *(long **)(param_1 + 0x20); plVar1 != (long *)0x0; plVar1 = (long *)*plVar1) {
    plStack_28 = (long *)plVar1[2];
    if (plStack_28 != (long *)0x0) {
      (**(code **)(*plStack_28 + 0x20))();
    }
    thunk_EXT_FUN_80110000038cceec(param_2,&plStack_28);
    if (plStack_28 != (long *)0x0) {
      (**(code **)(*plStack_28 + 0x28))();
    }
  }
  return;
}

