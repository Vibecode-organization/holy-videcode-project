// FUN_fffffff0081fb17c @ fffffff0081fb17c size=48

void FUN_fffffff0081fb17c(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x18) + 0x88);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081fb1a8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x18),puVar1);
  return;
}

