// FUN_fffffff00996f84c @ fffffff00996f84c size=64

void FUN_fffffff00996f84c(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af226a0);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22678);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996f888);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00af22650);
  return;
}

