// FUN_fffffff00995fd1c @ fffffff00995fd1c size=60

void FUN_fffffff00995fd1c(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x20) + 0xf8);
                    /* WARNING: Could not recover jumptable at 0xfffffff00995fd54. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x20),0,0,0,puVar1);
  return;
}

