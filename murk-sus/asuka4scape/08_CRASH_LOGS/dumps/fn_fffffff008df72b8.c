// FUN_fffffff008df72b8 @ fffffff008df72b8 size=72
// CALLERS:
//   fffffff00afd46b1 no-fn
//   fffffff008d5e4a8 FUN_fffffff008d5e02c@fffffff008d5e02c
// CALLEES:
//   fffffff008d6003c FUN_fffffff008d6003c
//   fffffff008d602a8 FUN_fffffff008d602a8
//   fffffff008cd5990 FUN_fffffff008cd5990
//   fffffff008d600bc FUN_fffffff008d600bc
//   fffffff008e005f0 thunk_FUN_fffffff009c29028

void FUN_fffffff008df72b8
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,undefined8 *param_7,
               undefined8 param_8,uint param_9,undefined8 param_10,undefined8 param_11)

{
  long lVar1;
  uint extraout_w1;
  char *pcVar2;
  undefined1 extraout_q0 [16];
  undefined1 auVar3 [16];
  
  lVar1 = FUN_fffffff008d602a8(param_7);
  thunk_FUN_fffffff009c29028(extraout_q0,param_2,param_3,param_4,param_5,param_6,lVar1,extraout_w1);
  FUN_fffffff008d6003c();
  pcVar2 = "bytesPerRowOfTileDataOfPlane[%u]=%u\n";
  auVar3 = FUN_fffffff008d600bc();
  FUN_fffffff008cd5990(auVar3._0_4_,auVar3._8_4_,param_9,param_10,param_11,0x1aa6,pcVar2);
  return;
}

