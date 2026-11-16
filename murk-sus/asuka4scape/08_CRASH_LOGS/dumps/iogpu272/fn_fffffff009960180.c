// FUN_fffffff009960180 @ fffffff009960180 size=48

void FUN_fffffff009960180(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x18) + 0x98);
                    /* WARNING: Could not recover jumptable at 0xfffffff0099601ac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x18),puVar1);
  return;
}

