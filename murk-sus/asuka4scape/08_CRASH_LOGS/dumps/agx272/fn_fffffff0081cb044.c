// FUN_fffffff0081cb044 @ fffffff0081cb044 size=76

void FUN_fffffff0081cb044(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x14d0));
  *(undefined1 *)(param_1 + 0x14e8) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081cb08c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x14d0));
  return;
}

