// FUN_fffffff008c8fb08 @ fffffff008c8fb08 size=52
// CALLERS:
//   fffffff00afd12c8 ?
//   fffffff007e29460 ?
// CALLS:
//   fffffff008c86bd4 FUN_fffffff008c86bd4

undefined8
FUN_fffffff008c8fb08
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,undefined8 param_8,long param_9)

{
  undefined8 uVar1;
  
  if (*(long *)(param_7 + 0xe0) != 0) {
    uVar1 = FUN_fffffff008c86bd4
                      (param_1,param_2,param_3,param_4,param_5,param_6,*(long *)(param_7 + 0xe0),
                       *(undefined4 **)(param_9 + 0x30),*(long *)(param_9 + 0x58),
                       *(undefined8 *)(param_7 + 0xf0),param_7);
    return uVar1;
  }
  return 0xe00002bc;
}

