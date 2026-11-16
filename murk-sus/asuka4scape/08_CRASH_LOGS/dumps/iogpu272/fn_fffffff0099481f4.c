// FUN_fffffff0099481f4 @ fffffff0099481f4 size=56

void FUN_fffffff0099481f4(long param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x120) + 0xb8);
                    /* WARNING: Could not recover jumptable at 0xfffffff009948228. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20),puVar1);
  return;
}

