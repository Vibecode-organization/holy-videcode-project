// FUN_fffffff009952080 @ fffffff009952080 size=48

void FUN_fffffff009952080(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x48) + 0x78);
                    /* WARNING: Could not recover jumptable at 0xfffffff0099520ac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x48),puVar1);
  return;
}

