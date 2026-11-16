// FUN_fffffff0081e21f0 @ fffffff0081e21f0 size=64

void FUN_fffffff0081e21f0(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae230c8);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae230a0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e222c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae23078);
  return;
}

