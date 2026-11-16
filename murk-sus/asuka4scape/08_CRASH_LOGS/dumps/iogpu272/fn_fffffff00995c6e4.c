// FUN_fffffff00995c6e4 @ fffffff00995c6e4 size=104

void FUN_fffffff00995c6e4(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((*(long *)(param_1 + 0xc0) != 0) && (*(int *)(param_1 + 0x70) != 0)) {
    FUN_fffffff009944a04(*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x1d8));
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995c740);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb270)(param_1);
  return;
}

