// FUN_fffffff008180ef4 @ fffffff008180ef4 size=56

void FUN_fffffff008180ef4(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x4b0) + 0x300);
                    /* WARNING: Could not recover jumptable at 0xfffffff008180f28. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x4b0),puVar1);
  return;
}

