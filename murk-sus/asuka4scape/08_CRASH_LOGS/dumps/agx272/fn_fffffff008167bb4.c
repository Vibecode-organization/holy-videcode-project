// FUN_fffffff008167bb4 @ fffffff008167bb4 size=64

void FUN_fffffff008167bb4(long param_1,undefined8 param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x1ac60);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008167bec. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0xf0))(plVar1,param_2,(undefined8 *)(*plVar1 + 0xf0));
    return;
  }
  return;
}

