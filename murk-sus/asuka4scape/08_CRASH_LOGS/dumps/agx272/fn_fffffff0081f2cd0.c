// FUN_fffffff0081f2cd0 @ fffffff0081f2cd0 size=120

void FUN_fffffff0081f2cd0(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007c9dec8;
  if (param_1[7] != 0) {
    thunk_EXT_FUN_80110000038fe768
              (&DAT_fffffff007ca49b8,param_1[7],(ulong)*(uint *)(param_1 + 8) * 0x68);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f2d44);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038942e0(param_1);
  return;
}

