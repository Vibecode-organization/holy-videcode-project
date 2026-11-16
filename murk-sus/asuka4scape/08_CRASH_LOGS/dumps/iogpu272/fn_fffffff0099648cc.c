// FUN_fffffff0099648cc @ fffffff0099648cc size=92

void FUN_fffffff0099648cc(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x18) != 0) {
    thunk_EXT_FUN_8011000003413868();
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996491c);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

