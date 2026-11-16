// FUN_fffffff009c16368 @ fffffff009c16368 size=124

void FUN_fffffff009c16368(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff0080668e8;
  if ((long *)param_1[2] != (long *)0x0) {
    (**(code **)(*(long *)param_1[2] + 0x28))();
  }
  param_1[2] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c163e0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038942e0(param_1);
  return;
}

