// FUN_fffffff00996333c @ fffffff00996333c size=56

void FUN_fffffff00996333c(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 200) + 0x130);
                    /* WARNING: Could not recover jumptable at 0xfffffff009963370. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 200),param_2,puVar1);
  return;
}

