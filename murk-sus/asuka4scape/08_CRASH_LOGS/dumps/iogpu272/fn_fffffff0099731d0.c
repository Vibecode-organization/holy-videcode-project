// FUN_fffffff0099731d0 @ fffffff0099731d0 size=576

void FUN_fffffff0099731d0(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x90) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x90) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x90) = 0;
  if (*(long **)(param_1 + 0x148) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x148) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x148) = 0;
  if (*(long **)(param_1 + 0xb0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xb0) = 0;
  if (*(long **)(param_1 + 0x140) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x140) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x140) = 0;
  if (*(long **)(param_1 + 0x160) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x160) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x160) = 0;
  if (*(long **)(param_1 + 0x158) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x158) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x158) = 0;
  if (*(long *)(param_1 + 0x2c0) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x2c0) = 0;
  }
  if (*(long **)(param_1 + 0x1d8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1d8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1d8) = 0;
  if (*(long **)(param_1 + 0x1c8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1c8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  if (*(long **)(param_1 + 0x1d0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1d0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  if (*(long **)(param_1 + 0x150) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x150) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x150) = 0;
  if (*(long **)(param_1 + 0x170) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x170) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x170) = 0;
  if (*(long **)(param_1 + 0xf8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xf8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xf8) = 0;
  if (*(long *)(param_1 + 0xf0) != 0) {
    *(undefined8 *)(param_1 + 0xf0) = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff0d28);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997340c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000039221b0(param_1);
  return;
}

