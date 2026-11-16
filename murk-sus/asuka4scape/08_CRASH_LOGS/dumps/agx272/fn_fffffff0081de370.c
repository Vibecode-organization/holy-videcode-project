// FUN_fffffff0081de370 @ fffffff0081de370 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081de3f0) */

void FUN_fffffff0081de370(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((*(byte *)((long)param_1 + 0x5ca) >> 1 & 1) == 0) {
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! Verification failed: %s: DPE must be enabled on G14.\n");
    return;
  }
  param_1[0x2235] = param_1[0x96] + 0x930;
  (**(code **)(*param_1 + 0x9a8))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081de428. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x968))(param_1,param_2,*param_1 + 0x968);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081de420);
  (*pcVar1)();
}

