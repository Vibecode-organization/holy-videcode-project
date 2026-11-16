// FUN_fffffff009c40e18 @ fffffff009c40e18 size=72

void FUN_fffffff009c40e18(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009c40d4c();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c40e5c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff00806b6b0,param_1,0xd8);
  return;
}

