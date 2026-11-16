// FUN_fffffff009945558 @ fffffff009945558 size=132

void FUN_fffffff009945558(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x10) != 0) {
    FUN_fffffff00994d0f4(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),param_1);
  }
  lVar3 = *(long *)(param_1 + 0x20);
  if (lVar3 != 0) {
    lVar2 = thunk_EXT_FUN_80110000031cd4a0(lVar3,0x400);
    thunk_EXT_FUN_80110000038fe6b0(lVar3,lVar2 + 1);
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099455d0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0099455d8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
  return;
}

