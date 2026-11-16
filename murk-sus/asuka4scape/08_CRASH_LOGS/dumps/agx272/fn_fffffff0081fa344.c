// FUN_fffffff0081fa344 @ fffffff0081fa344 size=316

void FUN_fffffff0081fa344(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0xc0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xc0) + 0x28))();
    *(undefined8 *)(param_1 + 0xc0) = 0;
  }
  if (*(long **)(param_1 + 0xb8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb8) + 0x28))();
    *(undefined8 *)(param_1 + 0xb8) = 0;
  }
  if (*(long **)(param_1 + 0xb0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb0) + 0x28))();
    *(undefined8 *)(param_1 + 0xb0) = 0;
  }
  if (*(long **)(param_1 + 0xa8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa8) + 0x28))();
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  if (*(long **)(param_1 + 0xa0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa0) + 0x28))();
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  if (*(long **)(param_1 + 0x98) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x98) + 0x28))();
    *(undefined8 *)(param_1 + 0x98) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fa474);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081fa47c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

