// FUN_fffffff008321024 @ fffffff008321024 size=84
// CALLERS:
//   fffffff00afc2ee4 no-fn
//   fffffff007cda340 no-fn
// CALLEES:
//   fffffff00832144c FUN_fffffff00832144c
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0

void FUN_fffffff008321024
               (long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined *param_5)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::sRegisterAggressor\n");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008321074);
    (*pcVar1)();
  }
  FUN_fffffff00832144c
            (param_1,(uint *)(param_3 + 0x38),*(ulong *)(param_3 + 0x30),
             *(undefined8 **)(param_3 + 0x10),param_5);
  return;
}

