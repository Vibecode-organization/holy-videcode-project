// FUN_fffffff009c30fa0 @ fffffff009c30fa0 size=524

void FUN_fffffff009c30fa0(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff008067db0;
  if ((long *)param_1[0x92] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x92] + 0x28))();
  }
  param_1[0x92] = 0;
  if ((long *)param_1[0x91] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x91] + 0x28))();
  }
  param_1[0x91] = 0;
  if ((long *)param_1[0x86] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x86] + 0x28))();
  }
  param_1[0x86] = 0;
  if ((long *)param_1[0x44] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x44] + 0x28))();
  }
  param_1[0x44] = 0;
  if ((long *)param_1[0x43] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x43] + 0x28))();
  }
  param_1[0x43] = 0;
  if ((long *)param_1[0x3f] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3f] + 0x28))();
  }
  param_1[0x3f] = 0;
  if ((long *)param_1[0x3d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3d] + 0x28))();
  }
  param_1[0x3d] = 0;
  if ((long *)param_1[0x38] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x38] + 0x28))();
  }
  param_1[0x38] = 0;
  if ((long *)param_1[0x37] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x37] + 0x28))();
  }
  param_1[0x37] = 0;
  if ((long *)param_1[0x36] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x36] + 0x28))();
  }
  param_1[0x36] = 0;
  if ((long *)param_1[0x2b] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x2b] + 0x28))();
  }
  param_1[0x2b] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c311a8);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000039289a4(param_1);
  return;
}

