// FUN_fffffff008167b6c @ fffffff008167b6c size=72

void FUN_fffffff008167b6c(long param_1,undefined8 param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x1ac60);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008167bac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x100))(plVar1,param_2,(undefined8 *)(*plVar1 + 0x100));
    return;
  }
  return;
}

