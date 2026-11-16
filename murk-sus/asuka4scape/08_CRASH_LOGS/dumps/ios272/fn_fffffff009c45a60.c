// FUN_fffffff009c45a60 @ fffffff009c45a60 size=8

void FUN_fffffff009c45a60(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038943cc(&DAT_fffffff00806b930,0xb0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c45a94);
    (*pcVar1)();
  }
  FUN_fffffff009c45ab4();
  return;
}

