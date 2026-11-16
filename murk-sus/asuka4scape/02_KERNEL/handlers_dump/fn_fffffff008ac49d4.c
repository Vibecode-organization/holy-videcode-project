// FUN_fffffff008ac49d4 @ fffffff008ac49d4 size=88 depth=1
// CALLERS:
//   fffffff00afcde04 ?
//   fffffff008a87014 FUN_fffffff008a86e58
//   fffffff008aec2b8 FUN_fffffff008aec278
//   fffffff008aed358 FUN_fffffff008aed31c
// CALLS:

void FUN_fffffff008ac49d4
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x180) + 0xe8);
                    /* WARNING: Could not recover jumptable at 0xfffffff008ac4a28. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x180),&LAB_fffffff008ac4a2c,param_2,param_3,param_4,
                     param_5,puVar1);
  return;
}

