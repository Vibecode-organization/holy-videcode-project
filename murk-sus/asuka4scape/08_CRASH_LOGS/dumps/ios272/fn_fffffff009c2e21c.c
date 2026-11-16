// FUN_fffffff009c2e21c @ fffffff009c2e21c size=104

void FUN_fffffff009c2e21c(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x10) != 0) {
    *(undefined8 *)(param_1 + 0x10) = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b130);
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2e278);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2e280. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

