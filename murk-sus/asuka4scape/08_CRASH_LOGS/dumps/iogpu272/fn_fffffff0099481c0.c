// FUN_fffffff0099481c0 @ fffffff0099481c0 size=52

void FUN_fffffff0099481c0(long param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x120) + 0xb0);
                    /* WARNING: Could not recover jumptable at 0xfffffff0099481f0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x120),*(undefined8 *)(param_3 + 0x48),puVar1);
  return;
}

