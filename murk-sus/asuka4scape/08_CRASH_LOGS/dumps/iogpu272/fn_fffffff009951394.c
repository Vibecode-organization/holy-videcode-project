// FUN_fffffff009951394 @ fffffff009951394 size=8

void FUN_fffffff009951394(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af223d0);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af223a8);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22380);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22358);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22330);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099513fc);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22308);
  return;
}

