// FUN_fffffff008214464 @ fffffff008214464 size=8

void FUN_fffffff008214464(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae25b88);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae25b60);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae25b38);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0082144b4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae25b10);
  return;
}

