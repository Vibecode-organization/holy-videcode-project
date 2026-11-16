// FUN_fffffff009c16c68 @ fffffff009c16c68 size=116

void FUN_fffffff009c16c68(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(int *)((long)param_1 + 0x1c) != 0) {
    FUN_fffffff009c364c0(param_1[2],param_1);
    *(undefined4 *)((long)param_1 + 0x1c) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c16cd0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c16cd8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x70))(param_1,(undefined8 *)(*param_1 + 0x70));
  return;
}

