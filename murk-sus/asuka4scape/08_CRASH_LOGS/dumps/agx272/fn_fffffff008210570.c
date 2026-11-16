// FUN_fffffff008210570 @ fffffff008210570 size=72

void FUN_fffffff008210570(long param_1)

{
  undefined8 *puVar1;
  
  if (*(int *)(param_1 + 0xcc) != 0) {
    DataSynchronizationBarrier(3,3,0);
    return;
  }
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x10) + 0xcf8);
                    /* WARNING: Could not recover jumptable at 0xfffffff0082105b4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x10),puVar1);
  return;
}

