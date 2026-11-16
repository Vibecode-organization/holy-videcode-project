// FUN_fffffff009948410 @ fffffff009948410 size=60

void FUN_fffffff009948410(long param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x120) + 0x90);
                    /* WARNING: Could not recover jumptable at 0xfffffff009948448. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x120),**(undefined4 **)(param_3 + 0x20),
                     (*(undefined4 **)(param_3 + 0x20))[2],puVar1);
  return;
}

