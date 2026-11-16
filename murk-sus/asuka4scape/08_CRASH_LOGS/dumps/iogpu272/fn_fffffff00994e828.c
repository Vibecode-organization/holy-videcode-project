// FUN_fffffff00994e828 @ fffffff00994e828 size=132

void FUN_fffffff00994e828(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
    thunk_EXT_FUN_80110000039a3d30(param_1 + 0x10);
  }
  if (*(long **)(param_1 + 0x50) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x50) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994e8a0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00994e8a8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
  return;
}

