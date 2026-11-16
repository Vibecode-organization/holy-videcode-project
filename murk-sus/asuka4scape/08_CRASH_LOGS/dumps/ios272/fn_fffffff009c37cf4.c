// FUN_fffffff009c37cf4 @ fffffff009c37cf4 size=120

void FUN_fffffff009c37cf4(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[0x76]);
  FUN_fffffff009c37c6c(param_1);
  *(undefined1 *)(param_1 + 0x7a) = 0;
  thunk_EXT_FUN_8011000003222de0(param_1[0x76]);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c37d60);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c37d68. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x28))(param_1,(undefined8 *)(*param_1 + 0x28));
  return;
}

