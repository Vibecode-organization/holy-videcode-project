// FUN_fffffff008188144 @ fffffff008188144 size=952

void FUN_fffffff008188144(long param_1)

{
  int *piVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  ulong unaff_x30;
  
  uVar6 = (ulong)*(uint *)(param_1 + 0x358);
  if (*(uint *)(param_1 + 0x358) != 0) {
    uVar9 = 0;
    do {
      lVar7 = *(long *)(param_1 + 0x360 + uVar9 * 8);
      if (lVar7 != 0) {
        lVar10 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
        uVar6 = 0;
        if (*(ulong *)(lVar10 + 0x12b0) != 0) {
          uVar6 = (ulong)(uint)((int)lVar7 - *(int *)(lVar10 + 0x12a0)) /
                  *(ulong *)(lVar10 + 0x12b0);
        }
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar10 + 0x12c8));
        cVar2 = *(char *)(*(long *)(lVar10 + 0x12a8) + uVar6);
        if (cVar2 != '\0') {
          *(char *)(*(long *)(lVar10 + 0x12a8) + uVar6) = cVar2 + -1;
        }
        if (*(int *)(lVar10 + 0x12c0) != 0) {
          thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar10 + 0x1290) + 0x160));
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar10 + 0x12c8));
        *(undefined8 *)(param_1 + 0x360 + uVar9 * 8) = 0;
        uVar6 = (ulong)*(uint *)(param_1 + 0x358);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar6);
  }
  *(undefined4 *)(param_1 + 0x358) = 0;
  if (*(long *)(param_1 + 0x480) != 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    uVar6 = 0;
    if (*(ulong *)(lVar7 + 0x1430) != 0) {
      uVar6 = (ulong)(uint)((int)*(long *)(param_1 + 0x480) - *(int *)(lVar7 + 0x1420)) /
              *(ulong *)(lVar7 + 0x1430);
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x1448));
    cVar2 = *(char *)(*(long *)(lVar7 + 0x1428) + uVar6);
    if (cVar2 != '\0') {
      *(char *)(*(long *)(lVar7 + 0x1428) + uVar6) = cVar2 + -1;
    }
    if (*(int *)(lVar7 + 0x1440) != 0) {
      thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar7 + 0x1410) + 0x160));
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x1448));
    *(undefined8 *)(param_1 + 0x480) = 0;
  }
  if (*(long *)(param_1 + 0x470) != 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    uVar6 = 0;
    if (*(ulong *)(lVar7 + 0x13f0) != 0) {
      uVar6 = (ulong)(uint)((int)*(long *)(param_1 + 0x470) - *(int *)(lVar7 + 0x13e0)) /
              *(ulong *)(lVar7 + 0x13f0);
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x1408));
    cVar2 = *(char *)(*(long *)(lVar7 + 0x13e8) + uVar6);
    if (cVar2 != '\0') {
      *(char *)(*(long *)(lVar7 + 0x13e8) + uVar6) = cVar2 + -1;
    }
    if (*(int *)(lVar7 + 0x1400) != 0) {
      thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar7 + 0x13d0) + 0x160));
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x1408));
    *(undefined8 *)(param_1 + 0x470) = 0;
  }
  if (*(long *)(param_1 + 0x490) != 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    uVar6 = 0;
    if (*(ulong *)(lVar7 + 0x1270) != 0) {
      uVar6 = (ulong)(uint)((int)*(long *)(param_1 + 0x490) - *(int *)(lVar7 + 0x1260)) /
              *(ulong *)(lVar7 + 0x1270);
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x1288));
    cVar2 = *(char *)(*(long *)(lVar7 + 0x1268) + uVar6);
    if (cVar2 != '\0') {
      *(char *)(*(long *)(lVar7 + 0x1268) + uVar6) = cVar2 + -1;
    }
    if (*(int *)(lVar7 + 0x1280) != 0) {
      thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar7 + 0x1250) + 0x160));
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x1288));
    *(undefined8 *)(param_1 + 0x490) = 0;
  }
  iVar4 = *(int *)(param_1 + 0x1dc);
  if (iVar4 != -1) {
    lVar7 = *(long *)(param_1 + 0x10);
    if (iVar4 < *(int *)(lVar7 + 0x11e00)) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x11df8));
      if (iVar4 < *(int *)(lVar7 + 0x11e00)) {
        lVar10 = (long)iVar4 * 4;
        piVar1 = (int *)(*(long *)(lVar7 + 0x11e28) + (long)(int)lVar10);
        if (lVar10 - (int)lVar10 != 0) {
          piVar1 = (int *)(*(long *)(lVar7 + 0x11e28) + lVar10 & 0xffffffffffffU |
                          0x2bad000000000000);
        }
        if (((*piVar1 == 0) || (iVar4 = *piVar1 + -1, *piVar1 = iVar4, iVar4 == 0)) &&
           ((*(byte *)(lVar7 + 0x11e0c) & 1) != 0)) {
          thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar7 + 0x11df0) + 0x160));
        }
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x11df8));
    }
  }
  if (*(long *)(param_1 + 0x168) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(*(long *)(param_1 + 0x160) + 0x50));
    iVar4 = (**(code **)(**(long **)(param_1 + 0x168) + 0x90))();
    if (iVar4 != 0) {
      uVar8 = 0;
      do {
        lVar7 = (**(code **)(**(long **)(param_1 + 0x168) + 0x118))
                          (*(long **)(param_1 + 0x168),uVar8);
        thunk_EXT_FUN_801100000297b408(*(undefined8 *)(lVar7 + 0x58));
        uVar8 = uVar8 + 1;
        uVar5 = (**(code **)(**(long **)(param_1 + 0x168) + 0x90))();
      } while (uVar8 < uVar5);
    }
    if (*(long **)(param_1 + 0x168) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x168) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x168) = 0;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(*(long *)(param_1 + 0x160) + 0x50));
  }
  lVar7 = *(long *)(param_1 + 0x178);
  if (lVar7 != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x40));
    if (0 < *(long *)(lVar7 + 0x38)) {
      if (*(long *)(lVar7 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar7 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar7 + 0x38) = *(long *)(lVar7 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x40));
    if (*(long **)(param_1 + 0x178) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x178) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x178) = 0;
  }
  *(undefined4 *)(param_1 + 0x1dc) = 0xffffffff;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081884c8);
    (*pcVar3)();
  }
  thunk_EXT_FUN_801100000296a1d0(param_1);
  return;
}

