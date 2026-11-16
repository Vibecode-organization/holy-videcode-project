// FUN_fffffff009c2fef8 @ fffffff009c2fef8 size=112

void FUN_fffffff009c2fef8(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x40) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x40) + 0xa8))();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2ff5c);
    (*pcVar1)();
  }
  (*DAT_fffffff008067b68)(param_1);
  return;
}

