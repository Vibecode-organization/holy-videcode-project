// FUN_fffffff009c46f4c @ fffffff009c46f4c size=76

void FUN_fffffff009c46f4c(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af484a8);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af48480);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af48458);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c46f94);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af48430);
  return;
}

