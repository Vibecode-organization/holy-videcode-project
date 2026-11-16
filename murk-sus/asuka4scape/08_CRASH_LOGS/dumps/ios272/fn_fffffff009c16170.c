// FUN_fffffff009c16170 @ fffffff009c16170 size=68

void FUN_fffffff009c16170(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x50) != 0) {
    thunk_EXT_FUN_80110000039a3d30();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c161b0);
    (*pcVar1)();
  }
  FUN_fffffff009c157d4(param_1);
  return;
}

