// FUN_fffffff00995c258 @ fffffff00995c258 size=104

void FUN_fffffff00995c258(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x18) == 1) {
    FUN_fffffff009961ccc(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x160));
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995c2b4);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

