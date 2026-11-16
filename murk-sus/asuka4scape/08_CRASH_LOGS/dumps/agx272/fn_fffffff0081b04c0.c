// FUN_fffffff0081b04c0 @ fffffff0081b04c0 size=68

void FUN_fffffff0081b04c0(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff0081b0504();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b0500);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ca12c8,param_1);
  return;
}

