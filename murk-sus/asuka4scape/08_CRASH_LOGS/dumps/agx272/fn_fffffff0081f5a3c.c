// FUN_fffffff0081f5a3c @ fffffff0081f5a3c size=724

void FUN_fffffff0081f5a3c(undefined8 *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff007c9e070;
  if ((long *)param_1[0x7d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x7d] + 0x28))();
  }
  param_1[0x7d] = 0;
  if ((long *)param_1[0x75] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x75] + 0x28))();
  }
  param_1[0x75] = 0;
  if ((long *)param_1[0x6d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x6d] + 0x28))();
  }
  param_1[0x6d] = 0;
  if ((long *)param_1[0x65] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x65] + 0x28))();
  }
  param_1[0x65] = 0;
  if ((long *)param_1[0x5d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x5d] + 0x28))();
  }
  param_1[0x5d] = 0;
  if ((long *)param_1[0x55] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x55] + 0x28))();
  }
  param_1[0x55] = 0;
  if ((long *)param_1[0x4d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x4d] + 0x28))();
  }
  param_1[0x4d] = 0;
  if ((long *)param_1[0x45] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x45] + 0x28))();
  }
  param_1[0x45] = 0;
  if ((long *)param_1[0x3d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3d] + 0x28))();
  }
  param_1[0x3d] = 0;
  if ((long *)param_1[0x35] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x35] + 0x28))();
  }
  param_1[0x35] = 0;
  if ((long *)param_1[0x2d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x2d] + 0x28))();
  }
  param_1[0x2d] = 0;
  if ((long *)param_1[0x25] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x25] + 0x28))();
  }
  param_1[0x25] = 0;
  if ((long *)param_1[0x1d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x1d] + 0x28))();
  }
  param_1[0x1d] = 0;
  if ((long *)param_1[0x15] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x15] + 0x28))();
  }
  param_1[0x15] = 0;
  if ((long *)param_1[0xd] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0xd] + 0x28))();
  }
  param_1[0xd] = 0;
  if ((long *)param_1[5] != (long *)0x0) {
    (**(code **)(*(long *)param_1[5] + 0x28))();
  }
  param_1[5] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f5d0c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038942e0(param_1);
  return;
}

