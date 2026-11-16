// FUN_fffffff00816a184 @ fffffff00816a184 size=56

void FUN_fffffff00816a184(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x4b0) + 0x290);
                    /* WARNING: Could not recover jumptable at 0xfffffff00816a1b8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x4b0),param_2,puVar1);
  return;
}

