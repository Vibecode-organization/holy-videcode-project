// FUN_fffffff0099d2b74 @ fffffff0099d2b74 size=48 depth=0
// CALLERS:
//   fffffff00afe6fb3 ?
//   fffffff008007f20 ?
// CALLS:
//   fffffff0099d52e4 FUN_fffffff0099d52e4
//   fffffff0099d50f8 FUN_fffffff0099d50f8

void FUN_fffffff0099d2b74
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8,long param_9,undefined8 param_10,undefined *param_11)

{
  if (*(long **)(param_9 + 0x68) != (long *)0x0) {
    FUN_fffffff0099d50f8
              (param_1,param_2,param_3,param_4,param_5,param_6,param_7,**(int **)(param_9 + 0x20),
               *(long **)(param_9 + 0x68),(uint *)(param_9 + 0x70),param_11);
    return;
  }
  FUN_fffffff0099d52e4
            (param_7,**(int **)(param_9 + 0x20),*(undefined8 **)(param_9 + 0x58),
             (uint *)(param_9 + 0x60));
  return;
}

