// FUN_fffffff009c18420 @ fffffff009c18420 size=204

void FUN_fffffff009c18420(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff008066b40;
  if ((long *)param_1[10] != (long *)0x0) {
    (**(code **)(*(long *)param_1[10] + 0x28))();
  }
  param_1[10] = 0;
  if ((long *)param_1[8] != (long *)0x0) {
    (**(code **)(*(long *)param_1[8] + 0x28))();
  }
  param_1[8] = 0;
  if ((long *)param_1[7] != (long *)0x0) {
    (**(code **)(*(long *)param_1[7] + 0x28))();
  }
  param_1[7] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c184e8);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038942e0(param_1);
  return;
}

