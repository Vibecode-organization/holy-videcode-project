// FUN_fffffff009c48be4 @ fffffff009c48be4 size=116

void FUN_fffffff009c48be4(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c48c4c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c48c54. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

