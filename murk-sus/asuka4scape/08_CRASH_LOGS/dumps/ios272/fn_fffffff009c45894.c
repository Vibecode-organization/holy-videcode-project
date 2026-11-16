// FUN_fffffff009c45894 @ fffffff009c45894 size=272

void FUN_fffffff009c45894(undefined8 *param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  ulong unaff_x30;
  
  *param_1 = &DAT_fffffff00806a740;
  if ((long *)param_1[0x15] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x15] + 0x28))();
  }
  param_1[0x15] = 0;
  if ((long *)param_1[0x13] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x13] + 0x28))();
  }
  param_1[0x13] = 0;
  lVar2 = -0x50;
  lVar3 = 0x98;
  do {
    lVar3 = lVar3 + -8;
    if (*(long **)((long)param_1 + lVar3) != (long *)0x0) {
      (**(code **)(**(long **)((long)param_1 + lVar3) + 0x28))();
    }
    *(undefined8 *)((long)param_1 + lVar3) = 0;
    lVar2 = lVar2 + 8;
  } while (lVar2 != 0);
  if ((long *)param_1[7] != (long *)0x0) {
    (**(code **)(*(long *)param_1[7] + 0x28))();
  }
  param_1[7] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c459a0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038942e0(param_1);
  return;
}

