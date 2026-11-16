// FUN_fffffff00997f0f8 @ fffffff00997f0f8 size=196

void FUN_fffffff00997f0f8(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((*(ushort *)(param_1 + 2) & 1) != 0) {
    (**(code **)(*param_1 + 0xc0))(param_1);
  }
  if ((long *)param_1[3] != (long *)0x0) {
    (**(code **)(*(long *)param_1[3] + 0x28))();
  }
  param_1[3] = 0;
  if ((long *)param_1[4] != (long *)0x0) {
    (**(code **)(*(long *)param_1[4] + 0x28))();
  }
  param_1[4] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997f1b0);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

