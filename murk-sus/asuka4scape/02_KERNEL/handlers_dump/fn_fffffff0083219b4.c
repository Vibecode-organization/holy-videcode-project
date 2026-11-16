// FUN_fffffff0083219b4 @ fffffff0083219b4 size=104 depth=1
// CALLERS:
//   fffffff00afc2ef6 ?
//   fffffff008321150 FUN_fffffff008321104
// CALLS:
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff008321618 FUN_fffffff008321618
//   fffffff00832144c FUN_fffffff00832144c

void FUN_fffffff0083219b4
               (long param_1,uint *param_2,ulong param_3,undefined8 param_4,undefined *param_5)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::setFreqList\n");
  FUN_fffffff008321618(param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008321a18);
    (*pcVar1)();
  }
  FUN_fffffff00832144c(param_1,param_2,param_3,(undefined8 *)0x0,param_5);
  return;
}

