// FUN_fffffff00926e534 @ fffffff00926e534 size=24 depth=0
// CALLERS:
//   fffffff00afdd1c3 ?
//   fffffff007efe3b8 ?
// CALLS:

undefined8 FUN_fffffff00926e534(long *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  ulong uStack_28;
  
  uStack_28 = (ulong)*(uint *)(param_3 + 0x60);
  if (*(uint *)(param_3 + 0x60) != 0) {
    uVar1 = (**(code **)(*param_1 + 0x598))
                      (param_1,**(undefined4 **)(param_3 + 0x20),*(undefined8 *)(param_3 + 0x58),
                       &uStack_28);
    *(int *)(param_3 + 0x60) = (int)uStack_28;
    return uVar1;
  }
  return 0xe00002c2;
}

