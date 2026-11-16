// FUN_fffffff0081eccf4 @ fffffff0081eccf4 size=8

void FUN_fffffff0081eccf4(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae23390);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae23368);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae234a8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ecd44);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae23458);
  return;
}

