// FUN_fffffff0081e5c24 @ fffffff0081e5c24 size=104

void FUN_fffffff0081e5c24(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  (**(code **)(*param_1 + 0x88))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e5c80);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e5c88. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

