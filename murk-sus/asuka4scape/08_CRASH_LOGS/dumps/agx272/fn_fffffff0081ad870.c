// FUN_fffffff0081ad870 @ fffffff0081ad870 size=68

void FUN_fffffff0081ad870(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff0081ad8b4();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ad8b0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ca10c8,param_1);
  return;
}

