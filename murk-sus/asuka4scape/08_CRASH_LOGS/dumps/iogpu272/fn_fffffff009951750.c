// FUN_fffffff009951750 @ fffffff009951750 size=144

void FUN_fffffff009951750(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  (**(code **)(*param_1 + 0x90))();
  if ((long *)param_1[5] != (long *)0x0) {
    (**(code **)(*(long *)param_1[5] + 0x28))();
  }
  param_1[5] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099517d4);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

