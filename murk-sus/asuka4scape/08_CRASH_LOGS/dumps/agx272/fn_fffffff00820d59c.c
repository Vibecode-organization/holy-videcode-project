// FUN_fffffff00820d59c @ fffffff00820d59c size=128

void FUN_fffffff00820d59c(undefined8 *param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007c9f788;
  plVar2 = (long *)param_1[0x17e];
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  param_1[0x17e] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820d618);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000002969154();
  return;
}

