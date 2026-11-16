// FUN_fffffff00830b124 @ fffffff00830b124 size=80 depth=0
// CALLERS:
//   fffffff00afc2c53 ?
//   fffffff007cd4540 ?
// CALLS:
//   fffffff00830baf4 FUN_fffffff00830baf4
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0

void FUN_fffffff00830b124
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,long param_9,undefined8 param_10,undefined *param_11)

{
  code *pcVar1;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  
  thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::sRemoveFreqs\n");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00830b170);
    (*pcVar1)();
  }
  FUN_fffffff00830baf4
            (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,(uint *)(param_9 + 0x38),
             *(long *)(param_9 + 0x30),param_10,param_11);
  return;
}

