// FUN_fffffff008167bf4 @ fffffff008167bf4 size=64

void FUN_fffffff008167bf4(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x1ac60);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008167c2c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0xb8))(plVar1,(undefined8 *)(*plVar1 + 0xb8));
    return;
  }
  return;
}

