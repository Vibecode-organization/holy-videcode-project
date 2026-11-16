// FUN_fffffff009958808 @ fffffff009958808 size=28

void FUN_fffffff009958808(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  undefined8 uStack0000000000000000;
  
  uStack0000000000000000 = param_1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009958820);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003a49114("\"Unexpected memory type\" @%s:%d");
  return;
}

