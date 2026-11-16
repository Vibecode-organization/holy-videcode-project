// FUN_fffffff009aa41ec @ fffffff009aa41ec size=96 depth=0
// CALLERS:
//   fffffff00afe887a ?
//   fffffff008024a70 ?
// CALLS:

undefined8 FUN_fffffff009aa41ec(long param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_3 + 0x38) == 0x10) {
    puVar1 = (undefined8 *)(**(long **)(param_1 + 0xd8) + 0x768);
                    /* WARNING: Could not recover jumptable at 0xfffffff009aa423c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)*puVar1)(*(long **)(param_1 + 0xd8),*(undefined8 *)(param_1 + 0xe8),param_1,
                               *(undefined8 *)(param_3 + 0x30),puVar1);
    return uVar2;
  }
  return 0xe00002c2;
}

