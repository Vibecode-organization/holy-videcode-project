// FUN_fffffff008167c34 @ fffffff008167c34 size=64

void FUN_fffffff008167c34(long param_1)

{
  if (*(long **)(param_1 + 0x1ac60) != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008167c6c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(long **)(param_1 + 0x1ac60) + 0xb0))();
    return;
  }
  return;
}

