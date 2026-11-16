// FUN_fffffff00819a800 @ fffffff00819a800 size=72

void FUN_fffffff00819a800(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000029723d8();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819a844);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff007ca0dc8,param_1,0x948);
  return;
}

