// FUN_fffffff0081adf58 @ fffffff0081adf58 size=76

void FUN_fffffff0081adf58(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x38));
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081adfa0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x38));
  return;
}

