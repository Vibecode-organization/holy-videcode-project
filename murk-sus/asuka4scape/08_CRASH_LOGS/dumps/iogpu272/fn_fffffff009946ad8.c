// FUN_fffffff009946ad8 @ fffffff009946ad8 size=8

void FUN_fffffff009946ad8(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af221f0);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af221c8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009946b1c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af221a0);
  return;
}

