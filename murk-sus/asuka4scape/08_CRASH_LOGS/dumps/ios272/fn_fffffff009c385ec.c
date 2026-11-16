// FUN_fffffff009c385ec @ fffffff009c385ec size=284

void FUN_fffffff009c385ec(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff008068520;
  if ((long *)param_1[0x28] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x28] + 0x28))();
  }
  param_1[0x28] = 0;
  if ((long *)param_1[0x27] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x27] + 0x28))();
  }
  param_1[0x27] = 0;
  if ((long *)param_1[0x26] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x26] + 0x28))();
  }
  param_1[0x26] = 0;
  if ((long *)param_1[0x23] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x23] + 0x28))();
  }
  param_1[0x23] = 0;
  if ((long *)param_1[0x20] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x20] + 0x28))();
  }
  param_1[0x20] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c38704);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000039a3888(param_1);
  return;
}

