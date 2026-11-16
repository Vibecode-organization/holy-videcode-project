// FUN_fffffff00997f0a0 @ fffffff00997f0a0 size=88

void FUN_fffffff00997f0a0(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009942f14(*(undefined8 *)(param_1 + 0x18),param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997f0ec);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb270)(param_1);
  return;
}

