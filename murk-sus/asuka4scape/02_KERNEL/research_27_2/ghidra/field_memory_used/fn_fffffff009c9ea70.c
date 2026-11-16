// FUN_fffffff009c9ea70 @ fffffff009c9ea70

void FUN_fffffff009c9ea70(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((long *)param_1[0x36] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x36] + 0xb8))();
  }
  if ((long *)param_1[0x30] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x30] + 0x28))();
  }
  param_1[0x30] = 0;
  if ((long *)param_1[0x2d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x2d] + 0x28))();
  }
  param_1[0x2d] = 0;
  if ((long *)param_1[0x2e] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x2e] + 0x28))();
  }
  param_1[0x2e] = 0;
  if ((long *)param_1[0x2f] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x2f] + 0x28))();
  }
  param_1[0x2f] = 0;
  if ((long *)param_1[0x31] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x31] + 0x28))();
  }
  param_1[0x31] = 0;
  if ((long *)param_1[0x3c] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3c] + 0x28))();
  }
  param_1[0x3c] = 0;
  if (param_1[0x2a] != 0) {
    FUN_fffffff009c99990(param_1[0x2a]);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c9ebf0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c9ebf8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x100))(param_1,"DeviceDescription",(undefined8 *)(*param_1 + 0x100));
  return;
}

