// FUN_fffffff00997684c @ fffffff00997684c size=168

void FUN_fffffff00997684c(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (-1 < *(char *)(param_1[0xa6] + 0x1fd)) {
    *(undefined1 *)(param_1 + 0xb9) = 1;
  }
  *(undefined4 *)(param_1 + 0x84) = 0;
  thunk_EXT_FUN_80110000032222a8(param_1[0x8b]);
  (**(code **)(*param_1 + 0x88))(param_1);
  thunk_EXT_FUN_8011000003222de0(param_1[0x8b]);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099768e8);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0099768f0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x28))(param_1,(undefined8 *)(*param_1 + 0x28));
  return;
}

