// FUN_fffffff0081e2c3c @ fffffff0081e2c3c size=208

void FUN_fffffff0081e2c3c(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007c9cb08;
  if ((((param_1[10] == 0) && (param_1[0xb] == 0)) && (param_1[0xc] == 0)) &&
     (((param_1[5] == 0 && (param_1[6] == 0)) && (param_1[7] == 0)))) {
    thunk_EXT_FUN_80110000038942e0(param_1);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      thunk_EXT_FUN_8011000003894430(&DAT_fffffff007ca1e08,param_1,0x70);
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e2cd4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! growable array is not empty at destruction\n")
  ;
  return;
}

