// FUN_fffffff008169fe0 @ fffffff008169fe0 size=56

void FUN_fffffff008169fe0(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x4b0) + 0x688);
                    /* WARNING: Could not recover jumptable at 0xfffffff00816a014. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x4b0),param_2,puVar1);
  return;
}

