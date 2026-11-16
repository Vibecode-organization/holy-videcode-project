// FUN_fffffff0081b8914 @ fffffff0081b8914 size=56

void FUN_fffffff0081b8914(long param_1,undefined8 param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x210);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081b8944. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x30))(plVar1,param_2,(undefined8 *)(*plVar1 + 0x30));
    return;
  }
  return;
}

