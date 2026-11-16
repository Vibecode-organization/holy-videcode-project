// FUN_fffffff009c41424 @ fffffff009c41424 size=108

void FUN_fffffff009c41424(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (param_1[3] != 0) {
    FUN_fffffff009c196c8(param_1[3],param_1);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c41484);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c4148c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x70))(param_1,(undefined8 *)(*param_1 + 0x70));
  return;
}

