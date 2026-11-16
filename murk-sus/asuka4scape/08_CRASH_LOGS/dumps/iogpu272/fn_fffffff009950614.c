// FUN_fffffff009950614 @ fffffff009950614 size=292

void FUN_fffffff009950614(long param_1,long param_2,long *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  ulong unaff_x30;
  
  (**(code **)(*param_3 + 0x20))(param_3);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  iVar2 = FUN_fffffff00994b9f8(*(undefined8 *)(param_1 + 0x18),param_3 + 6);
  if (iVar2 == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = thunk_EXT_FUN_8011000003397c88();
  }
  param_3[4] = lVar3;
  if (param_2 == 0) {
    param_3[0x16] = 0;
    plVar4 = *(long **)(param_1 + 0x68);
    param_3[0x17] = (long)plVar4;
    *plVar4 = (long)param_3;
    *(long **)(param_1 + 0x68) = param_3 + 0x16;
  }
  else {
    if (*(long *)(param_2 + 0x460) == 0) {
      *(undefined8 *)(param_2 + 0x470) = 0;
      plVar4 = *(long **)(param_1 + 0x48);
      *(long **)(param_2 + 0x478) = plVar4;
      *plVar4 = param_2;
      *(long *)(param_1 + 0x48) = param_2 + 0x470;
    }
    param_3[0x16] = 0;
    plVar4 = *(long **)(param_2 + 0x468);
    param_3[0x17] = (long)plVar4;
    *plVar4 = (long)param_3;
    *(long **)(param_2 + 0x468) = param_3 + 0x16;
  }
  *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  iVar2 = FUN_fffffff00994b9f8(*(undefined8 *)(param_1 + 0x18),param_3 + 0xe);
  if (iVar2 != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009950724);
      (*pcVar1)();
    }
    FUN_fffffff0099601b0(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x160));
    return;
  }
  return;
}

