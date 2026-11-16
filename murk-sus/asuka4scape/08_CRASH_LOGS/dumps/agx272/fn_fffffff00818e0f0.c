// FUN_fffffff00818e0f0 @ fffffff00818e0f0 size=4

void FUN_fffffff00818e0f0(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ulong uVar2;
  code *UNRECOVERED_JUMPTABLE;
  ulong unaff_x30;
  
  if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x10a71) & 1) == 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(PTR_DAT_fffffff007ca6130 + 0x130);
  }
  else {
    iVar1 = thunk_EXT_FUN_80110000029479f8
                      (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498);
    if (iVar1 == 0) {
      uVar2 = thunk_EXT_FUN_8011000002c13584(param_2);
      if ((uVar2 & 1) == 0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
          FUN_fffffff00818e21c(param_1,param_2,param_3,0,0);
          return;
        }
                    /* WARNING: Does not return */
        UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818e1d0);
        (*UNRECOVERED_JUMPTABLE)();
      }
    }
    else {
      thunk_EXT_FUN_8011000002c13530(param_2);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,1,
                 "Event ID %u signal value (%llu) will use fallback path since queue is idle");
    }
    UNRECOVERED_JUMPTABLE = *(code **)(PTR_DAT_fffffff007ca6130 + 0x130);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00818e218. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,PTR_DAT_fffffff007ca6130 + 0x130);
    return;
  }
                    /* WARNING: Does not return */
  UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818e210);
  (*UNRECOVERED_JUMPTABLE)();
}

