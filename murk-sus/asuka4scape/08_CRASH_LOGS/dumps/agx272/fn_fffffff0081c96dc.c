// FUN_fffffff0081c96dc @ fffffff0081c96dc size=76

void FUN_fffffff0081c96dc(long param_1,int param_2)

{
  long *plVar1;
  
  if (param_2 != 0) {
    **(undefined4 **)(param_1 + 0x910) = 1;
    return;
  }
  plVar1 = *(long **)(param_1 + 0x210);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081c9720. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x38))(plVar1,(undefined8 *)(*plVar1 + 0x38));
    return;
  }
  return;
}

