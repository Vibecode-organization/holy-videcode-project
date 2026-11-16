// FUN_fffffff009c2d138 @ fffffff009c2d138 size=108

void FUN_fffffff009c2d138(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((*(long *)(param_1 + 0x10) != 0) || (*(long *)(param_1 + 0x18) != 0)) {
    FUN_fffffff009c37b10(DAT_fffffff00af483b0,param_1);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2d198);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2d1a0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

