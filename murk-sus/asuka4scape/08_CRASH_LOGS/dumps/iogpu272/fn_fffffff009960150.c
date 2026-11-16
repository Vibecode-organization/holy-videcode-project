// FUN_fffffff009960150 @ fffffff009960150 size=48

void FUN_fffffff009960150(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x10) + 0x98);
                    /* WARNING: Could not recover jumptable at 0xfffffff00996017c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x10),puVar1);
  return;
}

