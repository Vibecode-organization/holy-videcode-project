// FUN_fffffff0082121e4 @ fffffff0082121e4 size=116

void FUN_fffffff0082121e4(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x108) != 0) {
    thunk_EXT_FUN_80110000038fe6b0(*(long *)(param_1 + 0x108),(ulong)*(byte *)(param_1 + 0xda) << 2)
    ;
  }
  if (*(long *)(param_1 + 0xf0) != 0) {
    thunk_EXT_FUN_80110000038fe6b0(*(long *)(param_1 + 0xf0),(ulong)*(uint *)(param_1 + 0xf8) << 2);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00821224c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008212254. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6140 + 0x80))(param_1);
  return;
}

