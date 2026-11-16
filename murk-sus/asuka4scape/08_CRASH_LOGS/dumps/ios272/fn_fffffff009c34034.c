// FUN_fffffff009c34034 @ fffffff009c34034 size=92

void FUN_fffffff009c34034(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  *(int *)(param_1 + 0x16c) = *(int *)(param_1 + 0x16c) + 1;
  thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x140),param_1 + 0x16c,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c3408c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  return;
}

