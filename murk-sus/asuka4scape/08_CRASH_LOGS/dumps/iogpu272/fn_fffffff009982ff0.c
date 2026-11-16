// FUN_fffffff009982ff0 @ fffffff009982ff0 size=188

void FUN_fffffff009982ff0(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x10) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  if (*(long **)(param_1 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  if (*(long *)(param_1 + 0x20) != 0) {
    thunk_EXT_FUN_80110000039a3d60();
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  if (*(long *)(param_1 + 0x28) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099830a0);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

