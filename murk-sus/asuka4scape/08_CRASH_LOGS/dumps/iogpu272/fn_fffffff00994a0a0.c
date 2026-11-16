// FUN_fffffff00994a0a0 @ fffffff00994a0a0 size=196

/* WARNING: Removing unreachable block (ram,0xfffffff00994a12c) */

void FUN_fffffff00994a0a0(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((*(byte *)(param_1 + 0x20) & 1) == 0) {
    return;
  }
  (**(code **)(*param_1 + 0x5d8))();
  (**(code **)(PTR_DAT_fffffff007ff27d0 + 0x2c8))(param_1,param_1[0x1f]);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00994a15c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x368))(param_1,param_1[0x1f],*param_1 + 0x368);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994a154);
  (*pcVar1)();
}

