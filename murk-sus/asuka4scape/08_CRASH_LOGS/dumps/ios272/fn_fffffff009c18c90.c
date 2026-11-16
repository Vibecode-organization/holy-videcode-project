// FUN_fffffff009c18c90 @ fffffff009c18c90 size=88

void FUN_fffffff009c18c90(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af481c0);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af48198);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af48170);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af48148);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c18ce4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af48120);
  return;
}

