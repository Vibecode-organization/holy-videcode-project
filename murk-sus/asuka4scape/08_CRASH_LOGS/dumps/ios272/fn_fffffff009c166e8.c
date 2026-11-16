// FUN_fffffff009c166e8 @ fffffff009c166e8 size=92

void FUN_fffffff009c166e8(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009c16db0(*(undefined8 *)(param_1 + 0x10),0xffffffffffffffff,1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c16738);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c16740. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

