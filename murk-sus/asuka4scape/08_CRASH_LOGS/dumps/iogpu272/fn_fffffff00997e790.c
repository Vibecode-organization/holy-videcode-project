// FUN_fffffff00997e790 @ fffffff00997e790 size=148

/* WARNING: Removing unreachable block (ram,0xfffffff00997e7ec) */

void FUN_fffffff00997e790(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *(undefined1 *)(param_1 + 0x1b) = 0;
  (**(code **)(PTR_DAT_fffffff007ff27d0 + 0x2c8))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00997e820. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x368))(param_1,param_2,*param_1 + 0x368);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997e818);
  (*pcVar1)();
}

