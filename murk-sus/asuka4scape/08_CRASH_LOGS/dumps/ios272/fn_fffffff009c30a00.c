// FUN_fffffff009c30a00 @ fffffff009c30a00 size=88

void FUN_fffffff009c30a00(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x18) != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c30a4c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c30a54. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

