// FUN_fffffff008167c74 @ fffffff008167c74 size=64

void FUN_fffffff008167c74(long param_1)

{
  if (*(long **)(param_1 + 0x1ac60) != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008167cac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(long **)(param_1 + 0x1ac60) + 0xd0))();
    return;
  }
  return;
}

