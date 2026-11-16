// FUN_fffffff009c18ab4 @ fffffff009c18ab4 size=92

void FUN_fffffff009c18ab4(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x60) != 0) {
    thunk_EXT_FUN_80110000038e9960();
    *(undefined8 *)(param_1 + 0x60) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c18b04);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c18b0c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

