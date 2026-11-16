// FUN_fffffff009c371ac @ fffffff009c371ac size=60

void FUN_fffffff009c371ac(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x1b8) + 0x108);
                    /* WARNING: Could not recover jumptable at 0xfffffff009c371e4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x1b8),param_2,0,puVar1);
  return;
}

