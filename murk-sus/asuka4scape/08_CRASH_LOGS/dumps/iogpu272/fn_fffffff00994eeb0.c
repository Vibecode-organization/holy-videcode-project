// FUN_fffffff00994eeb0 @ fffffff00994eeb0 size=160

void FUN_fffffff00994eeb0(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0xf0) != 0) {
    FUN_fffffff009975758(*(undefined8 *)(param_1 + 0x10),*(long *)(param_1 + 0xf0),0,1);
  }
  lVar2 = *(long *)(param_1 + 0xf8);
  if (lVar2 != 0) {
    *(undefined8 *)(param_1 + 0xf8) = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar2,0x1000);
  }
  if (*(long **)(param_1 + 0xe8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xe8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xe8) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994ef44);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00994ef4c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
  return;
}

