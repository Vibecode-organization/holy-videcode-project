// FUN_fffffff0081b5d60 @ fffffff0081b5d60 size=68

void FUN_fffffff0081b5d60(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff0081b5da4();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b5da0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ca16c8,param_1);
  return;
}

