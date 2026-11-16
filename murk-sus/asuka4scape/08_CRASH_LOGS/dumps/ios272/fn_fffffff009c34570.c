// FUN_fffffff009c34570 @ fffffff009c34570 size=96

void FUN_fffffff009c34570(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
             "Failed to install %s memory region; checking in anyway\n");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c345cc);
    (*pcVar1)();
  }
  FUN_fffffff009c34034(param_1);
  return;
}

