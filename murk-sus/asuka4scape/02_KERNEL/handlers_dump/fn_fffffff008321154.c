// FUN_fffffff008321154 @ fffffff008321154 size=80 depth=0
// CALLERS:
//   fffffff00afc2ee9 ?
//   fffffff007cda3a0 ?
// CALLS:
//   fffffff008321728 FUN_fffffff008321728
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0

void FUN_fffffff008321154
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,long param_9,undefined8 param_10,undefined *param_11)

{
  code *pcVar1;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  
  thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::sGetSafeFreqList\n");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0083211a0);
    (*pcVar1)();
  }
  FUN_fffffff008321728
            (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,(uint *)(param_9 + 0x60),
             *(ulong *)(param_9 + 0x58),param_10,param_11);
  return;
}

