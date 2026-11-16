// FUN_fffffff008ca76b0 @ fffffff008ca76b0 size=132
// CALLERS:
//   fffffff00afd1821 no-fn
//   fffffff008ca901c FUN_fffffff008ca83a4@fffffff008ca83a4
// CALLEES:
//   fffffff008ca9708 thunk_FUN_fffffff009c29268
//   fffffff008ca96f8 thunk_FUN_fffffff009c29028
//   fffffff008ca96e8 thunk_FUN_fffffff009c291a8

void FUN_fffffff008ca76b0
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,undefined8 param_7,
               long param_8)

{
  undefined4 uVar1;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  
  uVar1 = thunk_FUN_fffffff009c29028
                    (param_1,param_2,param_3,param_4,param_5,param_6,*(long *)(param_8 + 0x2b8),0);
  *(undefined4 *)(param_8 + 0x230) = uVar1;
  uVar1 = thunk_FUN_fffffff009c29028
                    (extraout_q0,param_2,param_3,param_4,param_5,param_6,*(long *)(param_8 + 0x2b8),
                     1);
  *(undefined4 *)(param_8 + 0x234) = uVar1;
  uVar1 = thunk_FUN_fffffff009c291a8
                    (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,
                     *(long *)(param_8 + 0x2b8),0);
  *(undefined4 *)(param_8 + 0x238) = uVar1;
  uVar1 = thunk_FUN_fffffff009c291a8
                    (extraout_q0_01,param_2,param_3,param_4,param_5,param_6,
                     *(long *)(param_8 + 0x2b8),1);
  *(undefined4 *)(param_8 + 0x23c) = uVar1;
  uVar1 = thunk_FUN_fffffff009c29268
                    (extraout_q0_02,param_2,param_3,param_4,param_5,param_6,
                     *(long *)(param_8 + 0x2b8),0);
  *(undefined4 *)(param_8 + 0x240) = uVar1;
  uVar1 = thunk_FUN_fffffff009c29268
                    (extraout_q0_03,param_2,param_3,param_4,param_5,param_6,
                     *(long *)(param_8 + 0x2b8),1);
  *(undefined4 *)(param_8 + 0x244) = uVar1;
  return;
}

