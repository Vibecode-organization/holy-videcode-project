// FUN_fffffff0081ec650 @ fffffff0081ec650 size=112

void FUN_fffffff0081ec650(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  (**(code **)(*param_1 + 0x140))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ec6b4);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ec6bc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca60e0 + 0x80))(param_1);
  return;
}

