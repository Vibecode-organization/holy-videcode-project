// FUN_fffffff0081ce734 @ fffffff0081ce734 size=504

void FUN_fffffff0081ce734(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x1470) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1470) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1470) = 0;
  if (*(long **)(param_1 + 0x1468) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1468) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1468) = 0;
  if (*(long **)(param_1 + 0x1478) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1478) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1478) = 0;
  if (*(long **)(param_1 + 0x1480) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1480) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1480) = 0;
  if (*(long **)(param_1 + 0x14a0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x14a0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x14a0) = 0;
  if (*(long **)(param_1 + 0x1498) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1498) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1498) = 0;
  if (*(long *)(param_1 + 0x14d0) != 0) {
    thunk_EXT_FUN_80110000038ff1d4();
    *(undefined8 *)(param_1 + 0x14d0) = 0;
  }
  if (*(long **)(param_1 + 0x14a8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x14a8) + 0x28))();
  }
  lVar3 = 0;
  *(undefined8 *)(param_1 + 0x14a8) = 0;
  lVar4 = 0x3c;
  do {
    plVar2 = *(long **)(param_1 + 0x14f0 + lVar3 * 8);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x14f0 + lVar3 * 8) = 0;
    lVar3 = lVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  (**(code **)(*(long *)(param_1 + 0xf68) + 0x28))(param_1 + 0xf68);
  (**(code **)(*(long *)(param_1 + 0x1020) + 0x28))(param_1 + 0x1020);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ce928);
    (*pcVar1)();
  }
  FUN_fffffff0081a9cac(param_1);
  return;
}

