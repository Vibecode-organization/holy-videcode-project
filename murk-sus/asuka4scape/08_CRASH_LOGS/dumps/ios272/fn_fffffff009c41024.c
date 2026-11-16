// FUN_fffffff009c41024 @ fffffff009c41024 size=88

void FUN_fffffff009c41024(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009c46f98(param_1 + 0xc,1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c41070);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c41078. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))(param_1);
  return;
}

