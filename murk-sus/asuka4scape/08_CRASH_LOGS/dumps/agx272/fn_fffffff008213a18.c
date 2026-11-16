// FUN_fffffff008213a18 @ fffffff008213a18 size=64

void FUN_fffffff008213a18(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x218);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008213a50. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x158))(plVar1,(undefined8 *)(*plVar1 + 0x158));
    return;
  }
  return;
}

