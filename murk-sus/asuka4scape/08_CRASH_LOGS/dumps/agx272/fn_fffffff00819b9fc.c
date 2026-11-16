// FUN_fffffff00819b9fc @ fffffff00819b9fc size=72

void FUN_fffffff00819b9fc(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_801100000296b950();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819ba40);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff007ca0e48,param_1,0x30);
  return;
}

