// FUN_fffffff00819f31c @ fffffff00819f31c size=204

void FUN_fffffff00819f31c(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007c94c10;
  if ((long *)param_1[6] != (long *)0x0) {
    (**(code **)(*(long *)param_1[6] + 0x28))();
  }
  param_1[6] = 0;
  if ((long *)param_1[5] != (long *)0x0) {
    (**(code **)(*(long *)param_1[5] + 0x28))();
  }
  param_1[5] = 0;
  if ((long *)param_1[4] != (long *)0x0) {
    (**(code **)(*(long *)param_1[4] + 0x28))();
  }
  param_1[4] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819f3e4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038942e0(param_1);
  return;
}

