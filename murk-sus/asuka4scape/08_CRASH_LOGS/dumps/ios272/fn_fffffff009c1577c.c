// FUN_fffffff009c1577c @ fffffff009c1577c size=88

void FUN_fffffff009c1577c(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000036da494(0x85210030,1,0,0,0,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c157d0);
    (*pcVar1)();
  }
  FUN_fffffff009c159b4(param_1);
  return;
}

