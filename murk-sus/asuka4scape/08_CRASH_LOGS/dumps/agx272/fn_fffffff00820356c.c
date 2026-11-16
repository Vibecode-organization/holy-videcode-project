// FUN_fffffff00820356c @ fffffff00820356c size=256

void FUN_fffffff00820356c(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x80) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x80) = 0;
  }
  if (*(long **)(param_1 + 0x58) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x58) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x58) = 0;
  plVar2 = *(long **)(*(long *)(param_1 + 0x30) + 0x1e0);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x48))();
  }
  if (*(long **)(param_1 + 0x50) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x50) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  if (*(long **)(param_1 + 0x30) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008203660);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008203668. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

