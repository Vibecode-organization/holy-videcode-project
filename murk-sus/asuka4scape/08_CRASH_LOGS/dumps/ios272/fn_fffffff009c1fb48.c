// FUN_fffffff009c1fb48 @ fffffff009c1fb48 size=276

void FUN_fffffff009c1fb48(long param_1)

{
  long *plVar1;
  
  if (*(long **)(param_1 + 0x3c0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x3c0) + 0x28))();
    *(undefined8 *)(param_1 + 0x3c0) = 0;
  }
  if (*(long *)(param_1 + 0x30) != 0) {
    if (-1 < *(char *)(param_1 + 0x3d2)) {
      FUN_fffffff009c3760c(DAT_fffffff00af483b0);
    }
    FUN_fffffff009c22140(param_1);
    plVar1 = *(long **)(param_1 + 0x30);
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x50))(plVar1,*(undefined8 *)PTR_DAT_fffffff00806c9c0);
    }
    *(undefined8 *)(param_1 + 0x30) = 0;
    thunk_EXT_FUN_80110000036da494(0x540000c,*(undefined4 *)(param_1 + 0x10),0,0,0,0);
  }
  plVar1 = *(long **)(param_1 + 0x28);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x88))(plVar1,param_1);
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}

