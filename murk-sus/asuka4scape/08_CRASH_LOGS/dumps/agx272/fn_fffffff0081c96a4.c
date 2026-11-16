// FUN_fffffff0081c96a4 @ fffffff0081c96a4 size=56

void FUN_fffffff0081c96a4(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x1460) + 0x580);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081c96d8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x1460),param_2,puVar1);
  return;
}

