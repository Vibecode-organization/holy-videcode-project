// FUN_fffffff008c33490 @ fffffff008c33490 size=48 depth=0
// CALLERS:
//   fffffff00afd0464 ?
//   fffffff007e12f78 ?
// CALLS:
//   fffffff008c334c0 FUN_fffffff008c334c0

undefined8 FUN_fffffff008c33490(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(long *)(param_3 + 8) != 0) {
    uVar1 = FUN_fffffff008c334c0
                      (param_2,(long *)param_2,**(undefined8 **)(param_3 + 0x20),
                       (*(undefined8 **)(param_3 + 0x20))[1],*(undefined8 **)(param_3 + 0x10));
    return uVar1;
  }
  return 0xe00002c7;
}

