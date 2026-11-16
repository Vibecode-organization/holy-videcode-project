// FUN_fffffff00995bdf0 @ fffffff00995bdf0 size=64

void FUN_fffffff00995bdf0(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af224c0);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22498);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995be2c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22470);
  return;
}

