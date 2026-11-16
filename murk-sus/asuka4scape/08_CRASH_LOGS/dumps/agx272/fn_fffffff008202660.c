// FUN_fffffff008202660 @ fffffff008202660 size=172

void FUN_fffffff008202660(long param_1)

{
  long *plVar1;
  long *plVar2;
  
  if (*(long *)(param_1 + 0x40) != 0) {
    thunk_EXT_FUN_80110000038fe6b0(*(long *)(param_1 + 0x40),(ulong)*(uint *)(param_1 + 0x48) << 6);
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  plVar1 = *(long **)(param_1 + 0x18);
  if (plVar1 != (long *)0x0) {
    plVar2 = *(long **)(param_1 + 0x20);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
      *(undefined8 *)(param_1 + 0x20) = 0;
      plVar1 = *(long **)(param_1 + 0x18);
    }
    (**(code **)(*plVar1 + 0x28))();
    *(undefined8 *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  return;
}

