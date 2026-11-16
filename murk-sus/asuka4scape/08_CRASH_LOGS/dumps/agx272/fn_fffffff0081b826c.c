// FUN_fffffff0081b826c @ fffffff0081b826c size=168

void FUN_fffffff0081b826c(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x280) + 0x1ac60);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 200))();
    plVar2 = *(long **)(*(long *)(param_1 + 0x280) + 0x1ac60);
    if (plVar2 != (long *)0x0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b82fc);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081b8304. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*plVar2 + 0xd8))(plVar2,(undefined8 *)(*plVar2 + 0xd8));
      return;
    }
  }
  return;
}

