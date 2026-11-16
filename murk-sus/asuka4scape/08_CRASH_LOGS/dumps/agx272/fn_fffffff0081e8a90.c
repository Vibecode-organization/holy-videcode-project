// FUN_fffffff0081e8a90 @ fffffff0081e8a90 size=52

void FUN_fffffff0081e8a90(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae23b70);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e8ac0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae23b08);
  return;
}

