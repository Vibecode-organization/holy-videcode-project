// FUN_fffffff00820d97c @ fffffff00820d97c size=316

void FUN_fffffff00820d97c(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x28) + 0x78))();
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (*(long **)(param_1 + 0x20) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x20) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  if ((*(long *)(param_1 + 0x18) != 0) && (*(long **)(param_1 + 0x30) != (long *)0x0)) {
    (**(code **)(**(long **)(param_1 + 0x30) + 0xb8))();
    (**(code **)(**(long **)(param_1 + 0x18) + 0xa8))
              (*(long **)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x30));
  }
  if (*(long **)(param_1 + 0x30) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
  if (*(long **)(param_1 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820daac);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00820dab4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

