// FUN_fffffff0088cf69c @ fffffff0088cf69c size=84 depth=0
// CALLERS:
//   fffffff00afcb0a6 ?
//   fffffff007daa4b0 ?
// CALLS:

void FUN_fffffff0088cf69c(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0xe0) + 0xe8);
                    /* WARNING: Could not recover jumptable at 0xfffffff0088cf6ec. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0xe0),FUN_fffffff0088d062c,param_2,param_3,0,0,puVar1);
  return;
}

