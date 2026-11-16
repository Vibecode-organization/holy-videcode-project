// FUN_fffffff009963f80 @ fffffff009963f80 size=144

void FUN_fffffff009963f80(long param_1,undefined8 param_2)

{
  long *plVar1;
  long *local_28;
  
  for (plVar1 = *(long **)(param_1 + 0x20); plVar1 != (long *)0x0; plVar1 = (long *)*plVar1) {
    local_28 = (long *)plVar1[2];
    if (local_28 != (long *)0x0) {
      (**(code **)(*local_28 + 0x20))();
    }
    thunk_EXT_FUN_80110000038cceec(param_2,&local_28);
    if (local_28 != (long *)0x0) {
      (**(code **)(*local_28 + 0x28))();
    }
  }
  return;
}

