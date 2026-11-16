// FUN_fffffff00820d50c @ fffffff00820d50c size=144

void FUN_fffffff00820d50c(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007c9f788;
  if ((long *)param_1[0x17e] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x17e] + 0x28))();
  }
  param_1[0x17e] = 0;
  thunk_EXT_FUN_8011000002969154(param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820d598);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff007ca27c8,param_1,0x1280);
  return;
}

