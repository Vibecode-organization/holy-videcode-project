// FUN_fffffff0099689dc @ fffffff0099689dc size=8

void FUN_fffffff0099689dc(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ff0928,0x130);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009968a10);
    (*pcVar1)();
  }
  FUN_fffffff009968a30();
  return;
}

