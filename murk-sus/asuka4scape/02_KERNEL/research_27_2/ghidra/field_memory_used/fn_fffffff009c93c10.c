// FUN_fffffff009c93c10 @ fffffff009c93c10

void FUN_fffffff009c93c10(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 400) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 400) + 0x28))();
  }
  *(undefined8 *)(param_1 + 400) = 0;
  if (*(long **)(param_1 + 0x1a0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1a0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1a0) = 0;
  if (*(long **)(param_1 + 0x3f0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x3f0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x3f0) = 0;
  if (*(long **)(param_1 + 0x88) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x88) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x88) = 0;
  if (*(long **)(param_1 + 0xb8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xb8) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c93d18);
    (*pcVar1)();
  }
  (**(code **)(PTR_DAT_fffffff00807fae8 + 0x80))(param_1);
  return;
}

