// FUN_fffffff0099704d8 @ fffffff0099704d8 size=64

void FUN_fffffff0099704d8(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22718);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af226f0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009970514);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af226c8);
  return;
}

