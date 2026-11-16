// FUN_fffffff008167aac @ fffffff008167aac size=64

void FUN_fffffff008167aac(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x1ac60);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008167ae4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0xa0))(plVar1,(undefined8 *)(*plVar1 + 0xa0));
    return;
  }
  return;
}

