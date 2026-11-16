// FUN_fffffff0081ff47c @ fffffff0081ff47c size=332

void FUN_fffffff0081ff47c(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x38) != 0) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    (**(code **)(**(long **)(param_1 + 0x28) + 0xe0))(*(long **)(param_1 + 0x28),0);
    if (*(long **)(param_1 + 0x30) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x30) = 0;
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (*(long *)(param_1 + 0x20) != 0) {
    *(undefined8 *)(param_1 + 0x20) = 0;
    (**(code **)(**(long **)(param_1 + 0x10) + 0xe0))(*(long **)(param_1 + 0x10),0);
    if (*(long **)(param_1 + 0x18) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    if (*(long **)(param_1 + 0x10) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ff5bc);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ff5c4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

