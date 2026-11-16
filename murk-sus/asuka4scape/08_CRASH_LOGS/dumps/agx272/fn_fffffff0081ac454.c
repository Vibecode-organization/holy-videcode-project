// FUN_fffffff0081ac454 @ fffffff0081ac454 size=200

void FUN_fffffff0081ac454(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((long *)param_1[0x42] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x42] + 8))();
    param_1[0x42] = 0;
  }
  (**(code **)(*param_1 + 0xa0))(param_1);
  param_1[0x51] = 0;
  param_1[0x50] = 0;
  if (param_1[0x120] != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  if (param_1[400] != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  if (param_1[0x178] != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  param_1[0x178] = 0;
  *(undefined1 *)((long)param_1 + 0x292) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ac510);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ac518. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

