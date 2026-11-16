// FUN_fffffff0082137a0 @ fffffff0082137a0 size=144

void FUN_fffffff0082137a0(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007ca0370;
  if ((long *)param_1[0x3a] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3a] + 0x28))();
  }
  param_1[0x3a] = 0;
  thunk_EXT_FUN_80110000029583b8(param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00821382c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff007ca2a08,param_1,0x240);
  return;
}

