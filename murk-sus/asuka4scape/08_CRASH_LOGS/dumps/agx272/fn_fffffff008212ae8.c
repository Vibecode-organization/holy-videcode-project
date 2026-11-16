// FUN_fffffff008212ae8 @ fffffff008212ae8 size=96

void FUN_fffffff008212ae8(long param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x218) != 0) {
    FUN_fffffff00819f6e4(param_2);
  }
  if (*(long *)(param_1 + 0x220) != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008212b38);
      (*pcVar1)();
    }
    FUN_fffffff00819f6e4(param_2);
    return;
  }
  return;
}

