// FUN_fffffff008320f50 @ fffffff008320f50 size=80 depth=0
// CALLERS:
//   fffffff00afc2ee1 ?
//   fffffff007cda310 ?
// CALLS:
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff0083212b4 FUN_fffffff0083212b4

undefined4 FUN_fffffff008320f50(long param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::sSetAggressorKey\n");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008320f9c);
    (*pcVar1)();
  }
  uVar2 = FUN_fffffff0083212b4(param_1,(int *)(param_3 + 0x38),*(long *)(param_3 + 0x30));
  return uVar2;
}

