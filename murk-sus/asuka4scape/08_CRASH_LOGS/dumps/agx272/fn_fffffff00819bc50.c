// FUN_fffffff00819bc50 @ fffffff00819bc50 size=64

void FUN_fffffff00819bc50(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae21fa0);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae21f78);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819bc8c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae21f50);
  return;
}

