// FUN_fffffff0081fd04c @ fffffff0081fd04c size=228

void FUN_fffffff0081fd04c(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x2d8) != 0) {
    (**(code **)(**(long **)(*(long *)(param_1 + 0x2d8) + 0x1e0) + 0x28))();
  }
  if (*(long *)(param_1 + 0x2e0) != 0) {
    (**(code **)(**(long **)(*(long *)(param_1 + 0x2e0) + 0x1e0) + 0x28))();
  }
  if (*(long *)(param_1 + 0x2e8) != 0) {
    (**(code **)(**(long **)(*(long *)(param_1 + 0x2e8) + 0x1e0) + 0x28))();
  }
  plVar2 = *(long **)(param_1 + 0x1e0);
  if (plVar2 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fd118);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081fd120. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
    return;
  }
  return;
}

