// FUN_fffffff0083210b4 @ fffffff0083210b4 size=80 depth=0
// CALLERS:
//   fffffff00afc2ee7 ?
//   fffffff007cda370 ?
// CALLS:
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff008321690 FUN_fffffff008321690

void FUN_fffffff0083210b4(long param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::sGetFreqList\n");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008321100);
    (*pcVar1)();
  }
  FUN_fffffff008321690(param_1,(uint *)(param_3 + 0x60),*(long *)(param_3 + 0x58));
  return;
}

