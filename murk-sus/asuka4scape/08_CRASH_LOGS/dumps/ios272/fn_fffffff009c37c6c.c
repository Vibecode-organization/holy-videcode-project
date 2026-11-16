// FUN_fffffff009c37c6c @ fffffff009c37c6c size=136

void FUN_fffffff009c37c6c(long param_1)

{
  ulong uVar1;
  long *plVar2;
  
  uVar1 = *(ulong *)(param_1 + 0x3c8);
  if (*(ulong *)(param_1 + 0x3c0) < uVar1) {
    do {
      *(ulong *)(param_1 + 0x3c0) = uVar1;
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x3b0));
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x3b8));
      for (plVar2 = *(long **)(param_1 + 0x3d8); plVar2 != (long *)0x0; plVar2 = (long *)*plVar2) {
        (*(code *)plVar2[2])(plVar2[3]);
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x3b8));
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x3b0));
      uVar1 = *(ulong *)(param_1 + 0x3c8);
    } while (*(ulong *)(param_1 + 0x3c0) < uVar1);
  }
  return;
}

