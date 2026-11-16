// FUN_fffffff00994aa50 @ fffffff00994aa50 size=152

void FUN_fffffff00994aa50(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  ulong unaff_x30;
  
  *(undefined8 *)(param_1 + 0x10) = 0;
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 != 0 && lVar2 != param_1 + 0x18) {
    lVar3 = (long)(int)*(uint *)(param_1 + 0x28) << 3;
    if (0x7fffffff < *(uint *)(param_1 + 0x28)) {
      lVar3 = -0x8000000000000000;
    }
    *(undefined8 *)(param_1 + 0x20) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1278,lVar2,lVar3);
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (*(long *)(param_1 + 0x840) != 0) {
    thunk_EXT_FUN_80110000038ff1d4();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994aadc);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00994aae4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
  return;
}

