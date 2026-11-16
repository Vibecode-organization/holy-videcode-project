// FUN_fffffff0099761f4 @ fffffff0099761f4 size=288

void FUN_fffffff0099761f4(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (DAT_fffffff00af22840 != (long *)0x0) {
    (**(code **)(*DAT_fffffff00af22840 + 0x28))();
  }
  DAT_fffffff00af22840 = (long *)0x0;
  if (DAT_fffffff00af22838 != (long *)0x0) {
    (**(code **)(*DAT_fffffff00af22838 + 0x28))();
  }
  DAT_fffffff00af22838 = (long *)0x0;
  if (DAT_fffffff00af22830 != (long *)0x0) {
    (**(code **)(*DAT_fffffff00af22830 + 0x28))();
  }
  DAT_fffffff00af22830 = (long *)0x0;
  if (DAT_fffffff00af22828 != (long *)0x0) {
    (**(code **)(*DAT_fffffff00af22828 + 0x28))();
  }
  DAT_fffffff00af22828 = (long *)0x0;
  if (DAT_fffffff00af22820 != (long *)0x0) {
    (**(code **)(*DAT_fffffff00af22820 + 0x28))();
  }
  DAT_fffffff00af22820 = (long *)0x0;
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22790);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009976310);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22768);
  return;
}

