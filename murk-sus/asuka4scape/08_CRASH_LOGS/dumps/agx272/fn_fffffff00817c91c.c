// FUN_fffffff00817c91c @ fffffff00817c91c size=76

void FUN_fffffff00817c91c(long param_1)

{
  undefined8 *puVar1;
  
  if ((*(byte *)(param_1 + 0x520) & 1) != 0) {
    return;
  }
  *(undefined1 *)(param_1 + 0x520) = 1;
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x518) + 0xf0);
                    /* WARNING: Could not recover jumptable at 0xfffffff00817c964. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x518),*(undefined1 *)(param_1 + 0x654),puVar1);
  return;
}

