// FUN_fffffff00830b034 @ fffffff00830b034 size=80
// CALLERS:
//   fffffff00afc2c50 no-fn
//   fffffff007cd44f8 no-fn
// CALLEES:
//   fffffff00830b448 FUN_fffffff00830b448
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0

void FUN_fffffff00830b034(long param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::sGetFreqList\n");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00830b080);
    (*pcVar1)();
  }
  FUN_fffffff00830b448(param_1,(uint *)(param_3 + 0x60),*(undefined8 **)(param_3 + 0x58));
  return;
}

