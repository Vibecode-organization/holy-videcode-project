// FUN_fffffff009944574 @ fffffff009944574 size=96

void FUN_fffffff009944574(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff0099445d4();
  if (*(long *)(param_1 + 0x20) != 0) {
    thunk_EXT_FUN_80110000038ff1d4();
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099445c8);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0099445d0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
  return;
}

