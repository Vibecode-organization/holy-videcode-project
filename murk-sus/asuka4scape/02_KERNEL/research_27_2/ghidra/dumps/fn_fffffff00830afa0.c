// FUN_fffffff00830afa0 @ fffffff00830afa0 size=80
// CALLERS:
//   fffffff00afc2c4d no-fn
//   fffffff007cd44c8 no-fn
// CALLEES:
//   fffffff00830b278 FUN_fffffff00830b278
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0

void FUN_fffffff00830afa0(long param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::sRegisterVictim\n");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00830afec);
    (*pcVar1)();
  }
  FUN_fffffff00830b278(param_1,(uint *)(param_3 + 0x38),*(long *)(param_3 + 0x30));
  return;
}

