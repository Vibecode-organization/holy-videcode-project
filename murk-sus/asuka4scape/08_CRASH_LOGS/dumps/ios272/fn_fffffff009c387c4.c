// FUN_fffffff009c387c4 @ fffffff009c387c4 size=8

void FUN_fffffff009c387c4(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038943cc(&DAT_fffffff00806b670,0x148);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c387f8);
    (*pcVar1)();
  }
  FUN_fffffff009c38818();
  return;
}

