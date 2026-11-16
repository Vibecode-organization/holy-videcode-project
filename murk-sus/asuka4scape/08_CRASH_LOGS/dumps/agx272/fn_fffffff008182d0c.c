// FUN_fffffff008182d0c @ fffffff008182d0c size=72

void FUN_fffffff008182d0c(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_801100000294aba4();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008182d50);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff007ca0bc8,param_1,0x158);
  return;
}

