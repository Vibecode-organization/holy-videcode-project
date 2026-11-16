// FUN_fffffff009aa424c @ fffffff009aa424c size=4 depth=0
// CALLERS:
//   fffffff00afe887c ?
//   fffffff008024a48 ?
// CALLS:

undefined8 FUN_fffffff009aa424c(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  uint uStack_24;
  
  if (*(int *)(param_3 + 0x38) == 0x10) {
    uStack_24 = 0;
    uVar1 = (**(code **)(**(long **)(param_1 + 0xd8) + 0x770))
                      (*(long **)(param_1 + 0xd8),*(undefined8 *)(param_1 + 0xe8),param_1,
                       *(undefined8 *)(param_3 + 0x30),&uStack_24);
    if ((int)uVar1 == 0) {
      **(ulong **)(param_3 + 0x48) = (ulong)uStack_24;
    }
  }
  else {
    uVar1 = 0xe00002c2;
  }
  return uVar1;
}

