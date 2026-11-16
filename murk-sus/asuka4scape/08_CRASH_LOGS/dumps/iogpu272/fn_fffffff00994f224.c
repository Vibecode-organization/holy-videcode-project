// FUN_fffffff00994f224 @ fffffff00994f224 size=92

void FUN_fffffff00994f224(long param_1)

{
  ulong uVar1;
  
  if ((*(byte *)(param_1 + 0x104) & 1) == 0) {
    if (*(long *)(param_1 + 0xf0) != 0) {
      FUN_fffffff009975710(*(undefined8 *)(param_1 + 0x10));
    }
    *(undefined1 *)(param_1 + 0x104) = 1;
    uVar1 = thunk_EXT_FUN_8011000003397c88();
    if (*(ulong *)(param_1 + 0x20) < uVar1) {
      *(ulong *)(param_1 + 0x20) = uVar1;
    }
  }
  return;
}

