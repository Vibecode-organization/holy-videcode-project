// FUN_fffffff009aa3f10 @ fffffff009aa3f10 size=128 depth=0
// CALLERS:
//   fffffff00afe8872 ?
//   fffffff008024818 ?
// CALLS:

undefined8 FUN_fffffff009aa3f10(long param_1,undefined8 param_2,long param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  
  if (*(long *)(param_3 + 0x30) != 0) {
    iVar2 = *(uint *)(param_3 + 0x28) - 2;
    if (1 < *(uint *)(param_3 + 0x28)) {
      puVar4 = *(undefined4 **)(param_3 + 0x20);
      puVar1 = (undefined4 *)0x0;
      if (iVar2 != 0) {
        puVar1 = puVar4 + 4;
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff009aa3f8c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(**(long **)(param_1 + 0xd8) + 0x738))
                        (*(long **)(param_1 + 0xd8),*(undefined8 *)(param_1 + 0xe8),*puVar4,
                         puVar4[2],puVar1,iVar2,*(long *)(param_3 + 0x30),
                         *(undefined4 *)(param_3 + 0x38));
      return uVar3;
    }
  }
  return 0xe00002c2;
}

