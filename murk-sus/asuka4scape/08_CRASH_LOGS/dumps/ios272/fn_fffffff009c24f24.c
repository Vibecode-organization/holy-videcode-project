// FUN_fffffff009c24f24 @ fffffff009c24f24 size=72

void FUN_fffffff009c24f24(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038e9dac(*(undefined8 *)(param_1 + 0x28),8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c24f68);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038e9dac(*(undefined8 *)(param_1 + 0x20),8);
  return;
}

