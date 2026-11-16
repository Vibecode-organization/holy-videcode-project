// FUN_fffffff009942f14 @ fffffff009942f14 size=300

void FUN_fffffff009942f14(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x48));
  if (*(int *)(param_1 + 0x50) == 2) {
    lVar3 = param_1 + 0x60;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x58);
  }
  uVar1 = *(uint *)(param_1 + 0x54);
  uVar4 = (ulong)uVar1;
  if ((int)uVar1 < 1) {
    uVar5 = 0;
LAB_fffffff009942f94:
    if ((int)uVar5 < (int)uVar4) {
      lVar6 = uVar4 - (uVar5 & 0xffffffff);
      uVar5 = uVar5 & 0xffffffff;
      do {
        *(undefined8 *)(lVar3 + uVar5 * 8) = *(undefined8 *)(lVar3 + (uVar5 + 1) * 8);
        lVar6 = lVar6 + -1;
        uVar5 = uVar5 + 1;
      } while (lVar6 != 0);
    }
    if ((0 < (int)uVar1) && ((*(byte *)(param_1 + 0x24) >> 1 & 1) != 0)) {
      FUN_fffffff00997f598(param_2,*(undefined8 *)(param_1 + 0x28));
      uVar4 = (ulong)*(uint *)(param_1 + 0x54);
    }
  }
  else {
    uVar5 = 0;
    do {
      if (*(long *)(lVar3 + uVar5 * 8) == param_2) {
        *(undefined8 *)(lVar3 + uVar5 * 8) = 0;
        *(uint *)(param_1 + 0x54) = uVar1 - 1;
        uVar4 = (ulong)(uVar1 - 1);
        goto LAB_fffffff009942f94;
      }
      uVar5 = uVar5 + 1;
    } while (uVar4 != uVar5);
    uVar4 = 1;
  }
  if ((int)uVar4 != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009943000);
      (*pcVar2)();
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
    return;
  }
  uVar1 = *(uint *)(param_1 + 0x24);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
  if ((uVar1 >> 1 & 1) == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994303c);
    (*pcVar2)();
  }
  FUN_fffffff009942c08(param_1);
  return;
}

