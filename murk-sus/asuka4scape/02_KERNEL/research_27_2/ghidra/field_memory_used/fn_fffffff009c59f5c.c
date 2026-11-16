// FUN_fffffff009c59f5c @ fffffff009c59f5c

void FUN_fffffff009c59f5c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,undefined **param_9,undefined **param_10,ulong param_11)

{
  long *plVar1;
  undefined *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  
  puVar4 = *(undefined8 **)(param_7 + 0x160);
  while (puVar4 != (undefined8 *)0x0) {
    plVar1 = (long *)puVar4[1];
    *(undefined8 *)(param_7 + 0x160) = *puVar4;
    if (plVar1 != (long *)0x0) {
      FUN_fffffff009c63f2c(plVar1);
    }
    param_1 = thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff00807a620,puVar4);
    puVar4 = *(undefined8 **)(param_7 + 0x160);
  }
  puVar4 = *(undefined8 **)(param_7 + 0x168);
  while (puVar4 != (undefined8 *)0x0) {
    plVar1 = (long *)puVar4[1];
    *(undefined8 *)(param_7 + 0x168) = *puVar4;
    if (plVar1 != (long *)0x0) {
      FUN_fffffff009c63f2c(plVar1);
    }
    param_1 = thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff00807a660,puVar4);
    puVar4 = *(undefined8 **)(param_7 + 0x168);
  }
  if (*(long **)(param_7 + 0x1b8) != (long *)0x0) {
    param_1 = (**(code **)(**(long **)(param_7 + 0x1b8) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x1b8) = 0;
  if (*(long **)(param_7 + 0x90) != (long *)0x0) {
    param_1 = (**(code **)(**(long **)(param_7 + 0x90) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x90) = 0;
  if (*(long **)(param_7 + 0xb8) != (long *)0x0) {
    param_1 = (**(code **)(**(long **)(param_7 + 0xb8) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0xb8) = 0;
  if (*(long **)(param_7 + 0x98) != (long *)0x0) {
    param_1 = (**(code **)(**(long **)(param_7 + 0x98) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x98) = 0;
  if (*(long **)(param_7 + 0x138) != (long *)0x0) {
    param_1 = (**(code **)(**(long **)(param_7 + 0x138) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x138) = 0;
  if (*(long **)(param_7 + 0x148) != (long *)0x0) {
    param_1 = (**(code **)(**(long **)(param_7 + 0x148) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x148) = 0;
  puVar2 = PTR_DAT_fffffff00807b660;
  if (*(long **)(param_7 + 0x118) != (long *)0x0) {
    thunk_FUN_fffffff00a25a7a0
              (param_1,param_2,param_3,param_4,param_5,param_6,*(ulong *)PTR_DAT_fffffff00807b660,
               *(long **)(param_7 + 0x118),param_9,param_10,param_11);
    param_1 = extraout_q0;
  }
  if (*(long **)(param_7 + 0x120) != (long *)0x0) {
    thunk_FUN_fffffff00a25a7a0
              (param_1,param_2,param_3,param_4,param_5,param_6,*(ulong *)puVar2,
               *(long **)(param_7 + 0x120),param_9,param_10,param_11);
    param_1 = extraout_q0_00;
  }
  if (*(long **)(param_7 + 0x128) != (long *)0x0) {
    thunk_FUN_fffffff00a25a7a0
              (param_1,param_2,param_3,param_4,param_5,param_6,*(ulong *)puVar2,
               *(long **)(param_7 + 0x128),param_9,param_10,param_11);
  }
  if (*(undefined8 **)(param_7 + 200) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 200));
    *(undefined8 *)(param_7 + 200) = 0;
  }
  if (*(undefined8 **)(param_7 + 0x100) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x100));
    *(undefined8 *)(param_7 + 0x100) = 0;
  }
  if (*(undefined8 **)(param_7 + 0xd0) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0xd0));
    *(undefined8 *)(param_7 + 0xd0) = 0;
  }
  if (*(undefined8 **)(param_7 + 0x140) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x140));
    *(undefined8 *)(param_7 + 0x140) = 0;
  }
  if (*(undefined8 **)(param_7 + 0x150) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x150));
    *(undefined8 *)(param_7 + 0x150) = 0;
  }
  if (*(undefined8 **)(param_7 + 0x170) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x170));
    *(undefined8 *)(param_7 + 0x170) = 0;
  }
  if (*(undefined8 **)(param_7 + 0x178) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x178));
    *(undefined8 *)(param_7 + 0x178) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c5a1a4);
    (*pcVar3)();
  }
  (**(code **)(PTR_DAT_fffffff00807b628 + 0x80))(param_7);
  return;
}

