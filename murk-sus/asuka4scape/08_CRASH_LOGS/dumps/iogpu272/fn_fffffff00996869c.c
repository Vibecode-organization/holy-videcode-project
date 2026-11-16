// FUN_fffffff00996869c @ fffffff00996869c size=64

void FUN_fffffff00996869c(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af225d8);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af225b0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099686d8);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22588);
  return;
}

