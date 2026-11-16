// FUN_fffffff00996fbd0 @ fffffff00996fbd0 size=160

void FUN_fffffff00996fbd0(long *param_1)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  ulong unaff_x30;
  
  (**(code **)(*param_1 + 0x80))();
  lVar2 = param_1[3];
  if (lVar2 != 0) {
    uVar3 = param_1[5] << 3;
    if (0x7fffffffffffffff < uVar3) {
      uVar3 = 0x8000000000000000;
    }
    if ((ulong)param_1[5] >> 0x3d != 0) {
      uVar3 = 0x8000000000000000;
    }
    param_1[3] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1a48,lVar2,uVar3);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996fc64);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00996fc6c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
  return;
}

