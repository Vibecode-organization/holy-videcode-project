// FUN_fffffff0081f9d30 @ fffffff0081f9d30 size=156

void FUN_fffffff0081f9d30(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0xa0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa0) + 0x28))();
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  if (*(long **)(param_1 + 0xb8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb8) + 0x28))();
    *(undefined8 *)(param_1 + 0xb8) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f9dc0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f9dc8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca60f0 + 0x80))(param_1);
  return;
}

