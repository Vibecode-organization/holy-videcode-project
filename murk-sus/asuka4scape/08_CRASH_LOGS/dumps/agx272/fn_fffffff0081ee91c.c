// FUN_fffffff0081ee91c @ fffffff0081ee91c size=8

void FUN_fffffff0081ee91c(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae234d0);
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae23480);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ee960);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003891910(&DAT_fffffff00ae23430);
  return;
}

