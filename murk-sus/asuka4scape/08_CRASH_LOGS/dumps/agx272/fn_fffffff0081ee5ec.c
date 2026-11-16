// FUN_fffffff0081ee5ec @ fffffff0081ee5ec size=172

void FUN_fffffff0081ee5ec(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007c9d988;
  if (((param_1[0x10] == 0) && (param_1[0x11] == 0)) && (param_1[0x12] == 0)) {
    thunk_EXT_FUN_801100000293ea74(param_1);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ee66c);
      (*pcVar1)();
    }
    thunk_EXT_FUN_8011000003894430(&DAT_fffffff007ca21c8,param_1,0xa0);
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! growable array is not empty at destruction\n")
  ;
  return;
}

