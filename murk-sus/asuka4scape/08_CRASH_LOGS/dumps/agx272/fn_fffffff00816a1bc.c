// FUN_fffffff00816a1bc @ fffffff00816a1bc size=56

void FUN_fffffff00816a1bc(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x4b0) + 0x260);
                    /* WARNING: Could not recover jumptable at 0xfffffff00816a1f0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x4b0),puVar1);
  return;
}

