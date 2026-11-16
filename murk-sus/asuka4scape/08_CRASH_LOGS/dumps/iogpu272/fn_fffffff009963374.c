// FUN_fffffff009963374 @ fffffff009963374 size=60

void FUN_fffffff009963374(long param_1)

{
  undefined8 *puVar1;
  
  *(undefined8 *)(param_1 + 0xd8) = 0;
  puVar1 = (undefined8 *)(**(long **)(param_1 + 200) + 0x138);
                    /* WARNING: Could not recover jumptable at 0xfffffff0099633ac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 200),puVar1);
  return;
}

