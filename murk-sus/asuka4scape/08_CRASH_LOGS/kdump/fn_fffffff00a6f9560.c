// FUN_fffffff00a6f9560 @ fffffff00a6f9560 size=104
// CALLERS:
//   fffffff00afbc66e ?
//   fffffff007c234c8 ?
// CALLS:
//   fffffff00a407178 FUN_fffffff00a407178
//   fffffff00a389b14 FUN_fffffff00a389b14

void FUN_fffffff00a6f9560
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,ulong param_7,
               uint *param_8,undefined4 **param_9,ulong *param_10)

{
  undefined8 uVar1;
  undefined1 extraout_q0 [16];
  undefined8 local_38;
  
  local_38 = 0;
  uVar1 = FUN_fffffff00a389b14(*(undefined8 **)(param_8 + 2),&local_38,8,param_10);
  if ((int)uVar1 == 0) {
    FUN_fffffff00a407178
              (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,*param_8,
               *(ulong *)(param_8 + 4),&local_38,param_9);
  }
  return;
}

