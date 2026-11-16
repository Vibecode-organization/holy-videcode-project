// FUN_fffffff0081cac88 @ fffffff0081cac88 size=64

void FUN_fffffff0081cac88(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x1460);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081cacc0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x5d8))(plVar1,(undefined8 *)(*plVar1 + 0x5d8));
    return;
  }
  return;
}

