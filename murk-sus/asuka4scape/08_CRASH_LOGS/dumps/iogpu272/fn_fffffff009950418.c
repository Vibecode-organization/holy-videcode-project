// FUN_fffffff009950418 @ fffffff009950418 size=212

void FUN_fffffff009950418(long param_1,long *param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  long *plVar3;
  long lVar4;
  uint uVar5;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  lVar4 = *(long *)(param_1 + 0x28);
  if (lVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    do {
      uVar2 = FUN_fffffff00994b4ec(*(undefined8 *)(param_1 + 0x18),lVar4);
      uVar5 = uVar2 | uVar5;
      lVar4 = *(long *)(lVar4 + 0x50);
    } while (lVar4 != 0);
  }
  if (*param_2 != 0) {
    plVar3 = *(long **)(param_1 + 0x30);
    *plVar3 = *param_2;
    lVar4 = param_2[1];
    *(long **)(*param_2 + 0x58) = plVar3;
    *(long *)(param_1 + 0x30) = lVar4;
    *param_2 = 0;
    param_2[1] = (long)param_2;
  }
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + param_3;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  if ((uVar5 & 1) == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff0099601b0(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x160));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099504d4);
  (*pcVar1)();
}

