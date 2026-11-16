// FUN_fffffff0081e19c0 @ fffffff0081e19c0 size=72

void FUN_fffffff0081e19c0(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038942e0();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e1a04);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff007ca1d48,param_1,200);
  return;
}

