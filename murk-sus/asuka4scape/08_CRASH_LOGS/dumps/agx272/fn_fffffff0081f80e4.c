// FUN_fffffff0081f80e4 @ fffffff0081f80e4 size=48

void FUN_fffffff0081f80e4(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x60) + 0xe0);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f8110. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x60),param_2,puVar1);
  return;
}

