// FUN_fffffff0099687b8 @ fffffff0099687b8 size=104

void FUN_fffffff0099687b8(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007fed448;
  FUN_fffffff009968820(param_1 + 0x1b);
  FUN_fffffff009968820(param_1 + 0x10);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996881c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038942e0(param_1);
  return;
}

