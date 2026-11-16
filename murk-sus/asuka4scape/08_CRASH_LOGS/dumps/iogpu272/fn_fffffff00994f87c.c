// FUN_fffffff00994f87c @ fffffff00994f87c size=116

void FUN_fffffff00994f87c(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0xd0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xd0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xd0) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994f8e4);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00994f8ec. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
  return;
}

