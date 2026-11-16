// FUN_fffffff009c99990 @ fffffff009c99990

void FUN_fffffff009c99990(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x10) + 0xb8);
                    /* WARNING: Could not recover jumptable at 0xfffffff009c999bc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x10),puVar1);
  return;
}

