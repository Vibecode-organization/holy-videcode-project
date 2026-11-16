// FUN_fffffff009972f74 @ fffffff009972f74 size=604

void FUN_fffffff009972f74(long *param_1,undefined8 param_2)

{
  int *piVar1;
  long lVar2;
  code *pcVar3;
  long *plVar4;
  long lVar5;
  ulong unaff_x30;
  
  if (param_1[0x5c] != 0) {
    thunk_EXT_FUN_801100000332d484();
  }
  if ((long *)param_1[0x38] != (long *)0x0) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xffffffbf;
    (**(code **)(*(long *)param_1[0x38] + 0x78))();
    param_1[0x38] = 0;
  }
  plVar4 = (long *)param_1[0x21];
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x88))(plVar4,param_1,param_1[0x27]);
    (**(code **)(*(long *)param_1[0x21] + 0x28))();
    param_1[0x21] = 0;
  }
  if (param_1[0x29] != 0) {
    FUN_fffffff00994b6b0();
    (**(code **)(*(long *)param_1[0x29] + 0xc0))();
  }
  if ((long *)param_1[0x2c] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x2c] + 0x28))();
  }
  param_1[0x2c] = 0;
  if (param_1[0x17] != 0) {
    thunk_EXT_FUN_8011000003277d90();
    thunk_EXT_FUN_801100000327731c(param_1[0x17]);
    param_1[0x17] = 0;
  }
  if (param_1[0x18] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x18] = 0;
  }
  if (param_1[0x16] != 0) {
    (**(code **)(*(long *)param_1[0x12] + 0xa8))();
  }
  if (param_1[0x2b] != 0) {
    thunk_FUN_fffffff0099509ac();
    (**(code **)(*(long *)param_1[0x2b] + 0x28))();
    param_1[0x2b] = 0;
  }
  if (param_1[0x37] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x37] = 0;
  }
  lVar2 = param_1[0x33];
  while (lVar2 != 0) {
    lVar5 = *(long *)(lVar2 + 0x10);
    piVar1 = (int *)(lVar2 + 0x38);
    lVar2 = lVar5;
    if (*piVar1 == 0) {
      FUN_fffffff009951a44();
    }
  }
  if (param_1[0x32] != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  if (param_1[0x1a] != 0) {
    FUN_fffffff009944a04(param_1[0x3a],*(undefined4 *)(param_1[0x1a] + 0x20));
    FUN_fffffff0099710dc(param_1[0x1a],0);
    (**(code **)(*(long *)param_1[0x1a] + 0x28))();
    param_1[0x1a] = 0;
  }
  (**(code **)(*param_1 + 0x620))(param_1,param_1[0x27]);
  param_1[0x27] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099731cc);
    (*pcVar3)();
  }
  thunk_EXT_FUN_801100000391a7e0(param_1,param_2);
  return;
}

