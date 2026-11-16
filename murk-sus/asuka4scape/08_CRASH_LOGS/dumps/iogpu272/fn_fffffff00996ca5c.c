// FUN_fffffff00996ca5c @ fffffff00996ca5c size=152

void FUN_fffffff00996ca5c(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  if (*(long **)(param_1 + 0x20) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x20) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  if (*(long *)(param_1 + 0x18) != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996cae4);
      (*pcVar1)();
    }
    thunk_EXT_FUN_80110000038ff1d4();
    return;
  }
  return;
}

