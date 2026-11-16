// FUN_fffffff009a932e4 @ fffffff009a932e4 size=220
// CALLERS:
//   fffffff00afe85bf no-fn
//   fffffff007e74548 no-fn
//   fffffff009a6f094 FUN_fffffff009a6efc0@fffffff009a6efc0
//   fffffff009a73f0c FUN_fffffff009a73db8@fffffff009a73db8
//   fffffff009a74958 FUN_fffffff009a74904@fffffff009a74904
//   fffffff009a74c48 FUN_fffffff009a74a2c@fffffff009a74a2c
//   fffffff009a74f1c FUN_fffffff009a74edc@fffffff009a74edc
//   fffffff009a75090 FUN_fffffff009a74edc@fffffff009a74edc
//   fffffff009a75108 FUN_fffffff009a750b4@fffffff009a750b4
//   fffffff009a752d8 FUN_fffffff009a750b4@fffffff009a750b4
//   fffffff009a7533c FUN_fffffff009a752fc@fffffff009a752fc
//   fffffff009a754ac FUN_fffffff009a752fc@fffffff009a752fc
//   fffffff009a755d0 FUN_fffffff009a754cc@fffffff009a754cc
//   fffffff009a75818 FUN_fffffff009a756f8@fffffff009a756f8
//   fffffff009a75bfc FUN_fffffff009a756f8@fffffff009a756f8
//   fffffff009a75c54 FUN_fffffff009a756f8@fffffff009a756f8
//   fffffff009a75cdc FUN_fffffff009a756f8@fffffff009a756f8
//   fffffff009a75d8c FUN_fffffff009a756f8@fffffff009a756f8
//   fffffff009a760fc FUN_fffffff009a75f3c@fffffff009a75f3c
//   fffffff009a761c0 FUN_fffffff009a75f3c@fffffff009a75f3c
//   fffffff009a76530 FUN_fffffff009a76434@fffffff009a76434
//   fffffff009a765d0 FUN_fffffff009a76434@fffffff009a76434
//   fffffff009a76630 FUN_fffffff009a765f4@fffffff009a765f4
//   fffffff009a78134 FUN_fffffff009a780fc@fffffff009a780fc
//   fffffff009a7819c FUN_fffffff009a780fc@fffffff009a780fc
//   fffffff009a7825c FUN_fffffff009a781b4@fffffff009a781b4
//   fffffff009a769f4 FUN_fffffff009a769c0@fffffff009a769c0
//   fffffff009a76bd0 FUN_fffffff009a769c0@fffffff009a769c0
//   fffffff009a77d78 FUN_fffffff009a77bd0@fffffff009a77bd0
//   fffffff009a77eb8 FUN_fffffff009a77e64@fffffff009a77e64
//   fffffff009a77edc FUN_fffffff009a77e64@fffffff009a77e64
//   fffffff009a784e0 FUN_fffffff009a783ac@fffffff009a783ac
//   fffffff009a785f0 FUN_fffffff009a783ac@fffffff009a783ac
//   fffffff009a7c3b8 FUN_fffffff009a7c314@fffffff009a7c314
//   fffffff009a7c478 FUN_fffffff009a7c314@fffffff009a7c314
//   fffffff009a7c190 FUN_fffffff009a7bf5c@fffffff009a7bf5c
//   fffffff009a7c238 FUN_fffffff009a7bf5c@fffffff009a7bf5c
//   fffffff009a812c4 FUN_fffffff009a80844@fffffff009a80844
//   fffffff009a819d0 FUN_fffffff009a80844@fffffff009a80844
//   fffffff009a914b0 FUN_fffffff009a9138c@fffffff009a9138c
//   fffffff009a91508 FUN_fffffff009a9138c@fffffff009a9138c
//   fffffff009a91678 FUN_fffffff009a9138c@fffffff009a9138c
//   fffffff009a84154 FUN_fffffff009a83f18@fffffff009a83f18
//   fffffff009a84190 FUN_fffffff009a83f18@fffffff009a83f18
//   fffffff009a742e0 FUN_fffffff009a74138@fffffff009a74138
//   fffffff009a76728 FUN_fffffff009a765f4@fffffff009a765f4
//   fffffff009a78388 FUN_fffffff009a781b4@fffffff009a781b4
//   fffffff009a76c08 FUN_fffffff009a769c0@fffffff009a769c0
//   fffffff009a779e4 FUN_fffffff009a779a8@fffffff009a779a8
//   fffffff008eb906c thunk_FUN_fffffff009a932e4@fffffff008eb9060
//   fffffff009a83ec8 no-fn
// CALLEES:
//   fffffff009a9311c FUN_fffffff009a9311c
//   fffffff009a9a2c0 thunk_FUN_fffffff009aabc94
//   fffffff009a92b1c FUN_fffffff009a92b1c

void FUN_fffffff009a932e4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               ulong param_8,int param_9)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  code *pcVar3;
  int iVar4;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 auVar5 [16];
  undefined4 uVar6;
  undefined1 auVar7 [12];
  undefined4 uVar8;
  undefined1 auVar9 [12];
  
  uVar8 = param_4._0_4_;
  auVar9 = param_4._4_12_;
  uVar6 = param_3._0_4_;
  auVar7 = param_3._4_12_;
  iVar4 = FUN_fffffff009a92b1c((long)param_7);
  if (iVar4 != 0) {
    return;
  }
  if ((param_9 != 0) && ((int)param_8 == 0)) {
    auVar5 = (**(code **)(*(long *)param_7[6] + 0x20))();
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009a93394);
      (*pcVar3)();
    }
    auVar1._4_12_ = auVar7;
    auVar1._0_4_ = uVar6;
    auVar2._4_12_ = auVar9;
    auVar2._0_4_ = uVar8;
    thunk_FUN_fffffff009aabc94
              (auVar5,param_2,auVar1,auVar2,param_5,param_6,(undefined8 *)(param_7[0xe] + 0x10),
               -0xff656bd50,(int *)0x0,param_7,param_7[6],param_8 & 0xffffffff,0);
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009a933bc);
    (*pcVar3)();
  }
  FUN_fffffff009a9311c(extraout_q0,param_2,uVar6,uVar8,param_5,param_6,param_7,param_8);
  return;
}

