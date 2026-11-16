// FUN_fffffff009c11b60 @ fffffff009c11b60

void FUN_fffffff009c11b60(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *(undefined8 *)(param_1 + 0xc0) = 0;
  if (*(long **)(param_1 + 0xa0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa0) + 0x28))();
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  if (*(long **)(param_1 + 0x98) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x98) + 0x28))();
    *(undefined8 *)(param_1 + 0x98) = 0;
  }
  *(undefined8 *)(param_1 + 0xb8) = 0;
  if (*(long **)(param_1 + 0xb0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb0) + 0x28))();
    *(undefined8 *)(param_1 + 0xb0) = 0;
  }
  if (*(long **)(param_1 + 0xa8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa8) + 0x28))();
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  if (*(long **)(param_1 + 0x88) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x88) + 0x28))();
    *(undefined8 *)(param_1 + 0x88) = 0;
  }
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c11c74);
    (*pcVar1)();
  }
  (**(code **)(PTR_DAT_fffffff008066548 + 0x80))(param_1);
  return;
}

