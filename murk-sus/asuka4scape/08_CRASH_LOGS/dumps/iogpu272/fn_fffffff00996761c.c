// FUN_fffffff00996761c @ fffffff00996761c size=64

void FUN_fffffff00996761c(long param_1,long param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_2 + 0x20);
  *(long **)(param_1 + 0x20) = plVar1;
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009967654. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x20))(plVar1,(undefined8 *)(*plVar1 + 0x20));
    return;
  }
  return;
}

