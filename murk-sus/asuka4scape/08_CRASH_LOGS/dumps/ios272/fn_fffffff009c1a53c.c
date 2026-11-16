// FUN_fffffff009c1a53c @ fffffff009c1a53c size=524

void FUN_fffffff009c1a53c(undefined8 *param_1)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff008067138;
  if ((long *)param_1[0x7b] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x7b] + 0x28))();
  }
  param_1[0x7b] = 0;
  if ((long *)param_1[0x79] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x79] + 0x28))();
  }
  param_1[0x79] = 0;
  if ((long *)param_1[0x78] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x78] + 0x28))();
  }
  param_1[0x78] = 0;
  if ((long *)param_1[0x6f] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x6f] + 0x28))();
  }
  param_1[0x6f] = 0;
  if ((long *)param_1[0x4d] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x4d] + 0x28))();
  }
  param_1[0x4d] = 0;
  if ((long *)param_1[0x42] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x42] + 0x28))();
  }
  param_1[0x42] = 0;
  if ((long *)param_1[0x35] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x35] + 0x28))();
  }
  param_1[0x35] = 0;
  lVar3 = -0x10;
  lVar4 = 0x1a8;
  do {
    lVar4 = lVar4 + -8;
    if (*(long **)((long)param_1 + lVar4) != (long *)0x0) {
      (**(code **)(**(long **)((long)param_1 + lVar4) + 0x28))();
    }
    *(undefined8 *)((long)param_1 + lVar4) = 0;
    lVar3 = lVar3 + 8;
  } while (lVar3 != 0);
  plVar2 = (long *)param_1[6];
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x50))(plVar2,*(undefined8 *)PTR_DAT_fffffff00806c9c0);
  }
  param_1[6] = 0;
  if ((long *)param_1[5] != (long *)0x0) {
    (**(code **)(*(long *)param_1[5] + 0x28))();
  }
  param_1[5] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1a744);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038942e0(param_1);
  return;
}

