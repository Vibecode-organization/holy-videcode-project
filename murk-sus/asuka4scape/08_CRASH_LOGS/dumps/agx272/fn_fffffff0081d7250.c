// FUN_fffffff0081d7250 @ fffffff0081d7250 size=272

void FUN_fffffff0081d7250(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(int *)(*(long *)(param_1 + 0x10) + 0xdfbc) != 1) {
    FUN_fffffff0081f2fb8(*(long *)(param_1 + 0x10),0xd01010);
    if (*(int *)(*(long *)(param_1 + 0x10) + 0xdfbc) != 1) {
      FUN_fffffff0081f2fb8(*(long *)(param_1 + 0x10),0xd01014);
      if (*(int *)(*(long *)(param_1 + 0x10) + 0xdfbc) != 1) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
          FUN_fffffff0081f2fb8(*(long *)(param_1 + 0x10),0xd01000);
          return;
        }
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d72e8);
        (*pcVar1)();
      }
    }
  }
  return;
}

