// FUN_fffffff009955e04 @ fffffff009955e04 size=56

void FUN_fffffff009955e04(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x98);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009955e34. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x88))(plVar1,(undefined8 *)(*plVar1 + 0x88));
    return;
  }
  return;
}

