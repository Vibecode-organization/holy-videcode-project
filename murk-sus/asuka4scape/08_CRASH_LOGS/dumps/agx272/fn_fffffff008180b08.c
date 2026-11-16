// FUN_fffffff008180b08 @ fffffff008180b08 size=56

void FUN_fffffff008180b08(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x111b0) + 0x80);
                    /* WARNING: Could not recover jumptable at 0xfffffff008180b3c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x111b0),puVar1);
  return;
}

