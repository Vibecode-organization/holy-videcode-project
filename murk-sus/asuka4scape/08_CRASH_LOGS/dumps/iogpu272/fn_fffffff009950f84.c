// FUN_fffffff009950f84 @ fffffff009950f84 size=60

void FUN_fffffff009950f84(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff0099509ac();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009950fbc);
    (*pcVar1)();
  }
  FUN_fffffff0099504ec(param_1);
  return;
}

