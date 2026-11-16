// FUN_fffffff009951f54 @ fffffff009951f54 size=148

void FUN_fffffff009951f54(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x48) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x48) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x48) = 0;
  if (*(long **)(param_1 + 0x40) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x40) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x40) = 0;
  if (*(long *)(param_1 + 0x60) != 0) {
    thunk_EXT_FUN_80110000038ff1d4();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009951fe4);
    (*pcVar1)();
  }
  FUN_fffffff009951750(param_1);
  return;
}

