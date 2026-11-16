// FUN_fffffff009c4107c @ fffffff009c4107c size=96

void FUN_fffffff009c4107c(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    thunk_EXT_FUN_8011000003a49114("\"fence freed before completion: %p\" @%s:%d");
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c410a0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c410a8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))();
  return;
}

