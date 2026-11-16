// FUN_fffffff0099673c8 @ fffffff0099673c8 size=56

void FUN_fffffff0099673c8(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x48) + 0x5e8);
                    /* WARNING: Could not recover jumptable at 0xfffffff0099673fc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x48),param_2,puVar1);
  return;
}

