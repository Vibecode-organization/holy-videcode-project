// FUN_fffffff009c24ed0 @ fffffff009c24ed0 size=84

void FUN_fffffff009c24ed0(long param_1,long param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038e9c08(param_1 + 0x20,*(undefined8 *)(param_2 + 0x20),8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c24f20);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038e9c08(param_1 + 0x28,*(undefined8 *)(param_2 + 0x28),8);
  return;
}

