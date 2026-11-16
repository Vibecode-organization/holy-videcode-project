// FUN_fffffff0099616e0 @ fffffff0099616e0 size=72

void FUN_fffffff0099616e0(long param_1,undefined1 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *(undefined1 *)(param_1 + 0x195) = param_2;
  FUN_fffffff0099601b0();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009961724);
    (*pcVar1)();
  }
  FUN_fffffff00995f52c(param_1,3,0);
  return;
}

