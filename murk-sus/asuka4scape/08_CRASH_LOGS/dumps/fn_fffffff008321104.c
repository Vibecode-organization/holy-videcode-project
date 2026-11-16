// FUN_fffffff008321104 @ fffffff008321104 size=80
// CALLERS:
//   fffffff00afc2ee8 no-fn
//   fffffff007cda388 no-fn
// CALLEES:
//   fffffff0083219b4 FUN_fffffff0083219b4
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0

void FUN_fffffff008321104
               (long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined *param_5)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::sSetFreqList\n");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008321150);
    (*pcVar1)();
  }
  FUN_fffffff0083219b4(param_1,(uint *)(param_3 + 0x38),*(ulong *)(param_3 + 0x30),param_4,param_5);
  return;
}

