// FUN_fffffff008212ce4 @ fffffff008212ce4 size=196

void FUN_fffffff008212ce4(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x218) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x218) + 0x158))();
  }
  if (*(long **)(param_1 + 0x220) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x220) + 0x158))();
  }
  plVar2 = *(long **)(param_1 + 0x230);
  if (plVar2 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008212d90);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff008212d98. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0x80))(plVar2,(undefined8 *)(*plVar2 + 0x80));
    return;
  }
  return;
}

