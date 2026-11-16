// FUN_fffffff00817dad8 @ fffffff00817dad8 size=64

void FUN_fffffff00817dad8(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x4b0) + 0x9d8);
                    /* WARNING: Could not recover jumptable at 0xfffffff00817db14. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x4b0),*param_2,*param_3,puVar1);
  return;
}

