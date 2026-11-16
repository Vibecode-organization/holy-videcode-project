// FUN_fffffff009959180 @ fffffff009959180 size=144

void FUN_fffffff009959180(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *(undefined4 *)(param_1 + 2) = 0;
  thunk_EXT_FUN_80110000032222a8(param_1[3]);
  (**(code **)(*param_1 + 0x80))(param_1);
  thunk_EXT_FUN_8011000003222de0(param_1[3]);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009959204);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00995920c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x28))(param_1,(undefined8 *)(*param_1 + 0x28));
  return;
}

