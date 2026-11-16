// FUN_fffffff009975568 @ fffffff009975568 size=88

void FUN_fffffff009975568(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xc0));
  if ((*(byte *)(param_1 + 200) & 1) == 0) {
    *(undefined1 *)(param_1 + 200) = 1;
    thunk_EXT_FUN_8011000003277760(*(undefined8 *)(param_1 + 0xb8));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099755bc);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xc0));
  return;
}

