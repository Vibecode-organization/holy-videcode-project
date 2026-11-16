// FUN_fffffff00997fdd0 @ fffffff00997fdd0 size=96

void FUN_fffffff00997fdd0(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x18) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997fe24);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

