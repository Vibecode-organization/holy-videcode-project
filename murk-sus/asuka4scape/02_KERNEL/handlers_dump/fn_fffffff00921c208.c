// FUN_fffffff00921c208 @ fffffff00921c208 size=88 depth=1
// CALLERS:
//   fffffff00afdc5c9 ?
//   fffffff009251e8c FUN_fffffff009251e28
// CALLS:

void FUN_fffffff00921c208(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x88) + 0xe8);
                    /* WARNING: Could not recover jumptable at 0xfffffff00921c25c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x88),&LAB_fffffff009248e44,param_2,param_3,0,0,puVar1);
  return;
}

