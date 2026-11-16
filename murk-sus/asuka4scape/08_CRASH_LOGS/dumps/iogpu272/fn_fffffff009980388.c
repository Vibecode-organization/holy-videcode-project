// FUN_fffffff009980388 @ fffffff009980388 size=72

void FUN_fffffff009980388(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff00998030c();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099803cc);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff007ff0f28,param_1,0xe8);
  return;
}

