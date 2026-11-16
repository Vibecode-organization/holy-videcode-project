// FUN_fffffff0081edfb0 @ fffffff0081edfb0 size=144

void FUN_fffffff0081edfb0(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007c9d828;
  if (param_1[0x13] != 0) {
    thunk_EXT_FUN_80110000038fe6b0(param_1[0x13],(ulong)*(uint *)(param_1 + 0x14) << 3);
  }
  if ((long *)param_1[4] != (long *)0x0) {
    (**(code **)(*(long *)param_1[4] + 0x28))();
  }
  param_1[4] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ee03c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000029497ac(param_1);
  return;
}

