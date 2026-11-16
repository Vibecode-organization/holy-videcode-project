// FUN_fffffff009c46270 @ fffffff009c46270 size=104

void FUN_fffffff009c46270(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009c43fc0(param_1[7],param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c462cc);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c462d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x70))(param_1,(undefined8 *)(*param_1 + 0x70));
  return;
}

