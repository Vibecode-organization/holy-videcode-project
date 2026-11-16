// FUN_fffffff00998030c @ fffffff00998030c size=124

void FUN_fffffff00998030c(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007fefb10;
  if ((long *)param_1[0x1c] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x1c] + 0x28))();
  }
  param_1[0x1c] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009980384);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038942e0(param_1);
  return;
}

