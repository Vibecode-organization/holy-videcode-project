// FUN_fffffff0081f8114 @ fffffff0081f8114 size=48

void FUN_fffffff0081f8114(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x60) + 0xd8);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f8140. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x60),param_2,puVar1);
  return;
}

