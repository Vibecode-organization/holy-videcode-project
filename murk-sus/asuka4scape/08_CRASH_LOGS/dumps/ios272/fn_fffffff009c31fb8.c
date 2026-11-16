// FUN_fffffff009c31fb8 @ fffffff009c31fb8 size=88

void FUN_fffffff009c31fb8(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000036da494(0x85210030,0,0,0,0,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c3200c);
    (*pcVar1)();
  }
  FUN_fffffff009c37cf4(param_1);
  return;
}

