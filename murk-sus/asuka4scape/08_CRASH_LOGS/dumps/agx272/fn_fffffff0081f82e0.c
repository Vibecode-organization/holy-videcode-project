// FUN_fffffff0081f82e0 @ fffffff0081f82e0 size=128

void FUN_fffffff0081f82e0(undefined8 *param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007c9e530;
  plVar2 = (long *)param_1[0xc];
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  param_1[0xc] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f835c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003976530();
  return;
}

