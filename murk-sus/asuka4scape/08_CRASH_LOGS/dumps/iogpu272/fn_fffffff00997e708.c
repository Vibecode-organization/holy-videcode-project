// FUN_fffffff00997e708 @ fffffff00997e708 size=136

void FUN_fffffff00997e708(long param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  *(undefined1 *)(param_1 + 0xd8) = 1;
  lVar2 = thunk_EXT_FUN_8011000003890f30(param_2,DAT_fffffff007fee6a0);
  *(long *)(param_1 + 0xe0) = lVar2;
  if (lVar2 == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997e778);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00997e780. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27d0 + 0x2c0))(param_1,param_2,PTR_DAT_fffffff007ff27d0 + 0x2c0);
  return;
}

