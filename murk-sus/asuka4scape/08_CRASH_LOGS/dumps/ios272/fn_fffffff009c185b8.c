// FUN_fffffff009c185b8 @ fffffff009c185b8 size=72

void FUN_fffffff009c185b8(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009c184ec();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c185fc);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff00806ae70,param_1,0x70);
  return;
}

