// FUN_fffffff00818184c @ fffffff00818184c size=60

void FUN_fffffff00818184c(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x4b0) + 0x968);
                    /* WARNING: Could not recover jumptable at 0xfffffff008181884. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x4b0),param_3,puVar1);
  return;
}

