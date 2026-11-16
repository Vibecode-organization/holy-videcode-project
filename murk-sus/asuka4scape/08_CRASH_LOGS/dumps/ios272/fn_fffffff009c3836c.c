// FUN_fffffff009c3836c @ fffffff009c3836c size=112

void FUN_fffffff009c3836c(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (DAT_fffffff00af485a0 != (long *)0x0) {
    (**(code **)(*DAT_fffffff00af485a0 + 0x28))();
  }
  DAT_fffffff00af485a0 = (long *)0x0;
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af48388);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c383d8);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af48360);
  return;
}

