// FUN_fffffff00995fbdc @ fffffff00995fbdc size=60

void FUN_fffffff00995fbdc(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0xd0) + 0xf8);
                    /* WARNING: Could not recover jumptable at 0xfffffff00995fc14. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0xd0),0,0,0,puVar1);
  return;
}

