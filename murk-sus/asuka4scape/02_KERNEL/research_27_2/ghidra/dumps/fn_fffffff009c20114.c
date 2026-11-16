// FUN_fffffff009c20114 @ fffffff009c20114 size=176
// CALLERS:
//   fffffff00afebceb no-fn
//   fffffff009c1b6dc FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b70c FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b73c FUN_fffffff009c1af14@fffffff009c1af14
// CALLEES:
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c20038 FUN_fffffff009c20038
//   fffffff009c49b74 thunk_FUN_fffffff00a8df19c

undefined8
FUN_fffffff009c20114
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,undefined8 param_8,undefined1 *param_9
          )

{
  bool bVar1;
  undefined8 uVar2;
  undefined1 extraout_q0 [16];
  undefined1 *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = &DAT_aaaaaaaaaaaaaaaa;
  bVar1 = FUN_fffffff009c20038(param_7,param_8,(ulong *)&local_30);
  if (bVar1) {
    if ((undefined1 *)0xff < local_30) {
      thunk_FUN_fffffff00a8df19c
                (extraout_q0,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)"IOSurface: %s exceeds maximum value\n");
      uVar2 = 0;
      goto LAB_fffffff009c20198;
    }
    *param_9 = (char)local_30;
  }
  uVar2 = 1;
LAB_fffffff009c20198:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

