// FUN_fffffff009c1a818 @ fffffff009c1a818 size=40

void FUN_fffffff009c1a818(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009c1a840(0x3e0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1a83c);
    (*pcVar1)();
  }
  FUN_fffffff009c1a868();
  return;
}

