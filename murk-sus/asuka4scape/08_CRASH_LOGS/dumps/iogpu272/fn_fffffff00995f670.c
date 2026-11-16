// FUN_fffffff00995f670 @ fffffff00995f670 size=212

void FUN_fffffff00995f670(long *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if (DAT_fffffff00af227e8 != 0) {
    uVar2 = thunk_EXT_FUN_801100000390ebc0(param_1[0x35]);
    thunk_EXT_FUN_80110000036da494(0x85180161,uVar2,0,0,0,0);
  }
  (**(code **)(*param_1 + 0x90))(param_1);
  if (DAT_fffffff00af227e8 != 0) {
    uVar2 = thunk_EXT_FUN_801100000390ebc0(param_1[0x35]);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995f730);
      (*pcVar1)();
    }
    thunk_EXT_FUN_80110000036da494(0x85180162,uVar2,0,0,0,0);
    return;
  }
  return;
}

