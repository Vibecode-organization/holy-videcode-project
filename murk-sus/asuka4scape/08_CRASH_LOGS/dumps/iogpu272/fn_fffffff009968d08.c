// FUN_fffffff009968d08 @ fffffff009968d08 size=92

void FUN_fffffff009968d08(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009968d64(param_1 + 0x80);
  FUN_fffffff009968d64(param_1 + 0xd8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009968d58);
    (*pcVar1)();
  }
  (*DAT_fffffff007fe9080)(param_1);
  return;
}

