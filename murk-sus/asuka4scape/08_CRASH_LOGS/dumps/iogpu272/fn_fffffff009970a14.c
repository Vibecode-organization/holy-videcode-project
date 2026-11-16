// FUN_fffffff009970a14 @ fffffff009970a14 size=72

void FUN_fffffff009970a14(long param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x18));
  *(undefined8 *)(param_1 + 0x30) = param_2;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009970a58);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x18));
  return;
}

