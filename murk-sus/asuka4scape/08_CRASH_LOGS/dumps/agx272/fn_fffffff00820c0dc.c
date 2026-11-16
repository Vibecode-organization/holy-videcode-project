// FUN_fffffff00820c0dc @ fffffff00820c0dc size=1940

void FUN_fffffff00820c0dc(long param_1)

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
  
  uVar6 = (ulong)*(uint *)(param_1 + 0xcb0);
  if (*(uint *)(param_1 + 0xcb0) != 0) {
    uVar9 = 0;
    do {
      lVar7 = *(long *)(param_1 + 0xcb8 + uVar9 * 8);
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
        *(undefined8 *)(param_1 + 0xcb8 + uVar9 * 8) = 0;
        uVar6 = (ulong)*(uint *)(param_1 + 0xcb0);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar6);
  }
  *(undefined4 *)(param_1 + 0xcb0) = 0;
  if (*(long *)(param_1 + 0xdc8) != 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    uVar6 = 0;
    if (*(ulong *)(lVar7 + 0x1330) != 0) {
      uVar6 = (ulong)(uint)((int)*(long *)(param_1 + 0xdc8) - *(int *)(lVar7 + 0x1320)) /
              *(ulong *)(lVar7 + 0x1330);
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x1348));
    cVar2 = *(char *)(*(long *)(lVar7 + 0x1328) + uVar6);
    if (cVar2 != '\0') {
      *(char *)(*(long *)(lVar7 + 0x1328) + uVar6) = cVar2 + -1;
    }
    if (*(int *)(lVar7 + 0x1340) != 0) {
      thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar7 + 0x1310) + 0x160));
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x1348));
    *(undefined8 *)(param_1 + 0xdc8) = 0;
  }
  if (*(long *)(param_1 + 0xdd8) != 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    uVar6 = 0;
    if (*(ulong *)(lVar7 + 0x12f0) != 0) {
      uVar6 = (ulong)(uint)((int)*(long *)(param_1 + 0xdd8) - *(int *)(lVar7 + 0x12e0)) /
              *(ulong *)(lVar7 + 0x12f0);
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x1308));
    cVar2 = *(char *)(*(long *)(lVar7 + 0x12e8) + uVar6);
    if (cVar2 != '\0') {
      *(char *)(*(long *)(lVar7 + 0x12e8) + uVar6) = cVar2 + -1;
    }
    if (*(int *)(lVar7 + 0x1300) != 0) {
      thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar7 + 0x12d0) + 0x160));
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x1308));
    *(undefined8 *)(param_1 + 0xdd8) = 0;
  }
  if (*(long *)(param_1 + 0xde8) != 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    uVar6 = 0;
    if (*(ulong *)(lVar7 + 0x11b0) != 0) {
      uVar6 = (ulong)(uint)((int)*(long *)(param_1 + 0xde8) - *(int *)(lVar7 + 0x11a0)) /
              *(ulong *)(lVar7 + 0x11b0);
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x11c8));
    cVar2 = *(char *)(*(long *)(lVar7 + 0x11a8) + uVar6);
    if (cVar2 != '\0') {
      *(char *)(*(long *)(lVar7 + 0x11a8) + uVar6) = cVar2 + -1;
    }
    if (*(int *)(lVar7 + 0x11c0) != 0) {
      thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar7 + 0x1190) + 0x160));
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x11c8));
    *(undefined8 *)(param_1 + 0xde8) = 0;
  }
  if ((*(byte *)(param_1 + 0xcac) & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(*(long *)(param_1 + 0xbe8) + 0x120));
    lVar7 = *(long *)(param_1 + 0xbe8);
    lVar10 = *(long *)(param_1 + 0xbf0);
    if ((*(int *)(lVar10 + 0x10) == *(int *)(param_1 + 0x1010)) &&
       (iVar4 = *(int *)(lVar10 + 0x30) + -1, *(int *)(lVar10 + 0x30) = iVar4, iVar4 == 0)) {
      lVar10 = *(long *)(*(long *)(lVar7 + 0x20) + 0x48);
      (**(code **)(**(long **)(lVar7 + 0x10) + 0xcc0))
                (*(long **)(lVar7 + 0x10),lVar10,*(long *)(lVar7 + 0x20) + 0x34);
      *(undefined4 *)(lVar10 + 8) = 0xffffffff;
      lVar7 = *(long *)(param_1 + 0xbe8);
    }
    *(undefined1 *)(param_1 + 0xcac) = 0;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x120));
  }
  if (*(long *)(param_1 + 0xbf0) != 0) {
    FUN_fffffff0081dff40
              (*(long *)(param_1 + 0x10) + 0x11da8,*(long *)(param_1 + 0xbf0),
               *(undefined4 *)(param_1 + 0x1010));
    *(undefined4 *)(param_1 + 0x1010) = 0xffffffff;
  }
  if (*(long *)(param_1 + 0xbf8) != 0) {
    thunk_EXT_FUN_801100000293f7a0();
    if (*(long **)(param_1 + 0xbf8) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xbf8) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xbf8) = 0;
  }
  if (*(long **)(param_1 + 0xc00) != (long *)0x0) {
    iVar4 = (**(code **)(**(long **)(param_1 + 0xc00) + 0x90))();
    if (iVar4 != 0) {
      uVar8 = 0;
      do {
        (**(code **)(**(long **)(param_1 + 0xc00) + 0x118))(*(long **)(param_1 + 0xc00),uVar8);
        thunk_EXT_FUN_801100000297b408();
        uVar8 = uVar8 + 1;
        uVar5 = (**(code **)(**(long **)(param_1 + 0xc00) + 0x90))();
      } while (uVar8 < uVar5);
    }
    if (*(long **)(param_1 + 0xc00) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xc00) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xc00) = 0;
  }
  if (*(long *)(param_1 + 0xc08) != 0) {
    thunk_EXT_FUN_801100000297b408();
    if (*(long **)(param_1 + 0xc08) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xc08) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xc08) = 0;
  }
  if (*(long *)(param_1 + 0xc10) != 0) {
    thunk_EXT_FUN_801100000297b408();
    if (*(long **)(param_1 + 0xc10) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xc10) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xc10) = 0;
  }
  lVar7 = *(long *)(param_1 + 0xc28);
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
    if (*(long **)(param_1 + 0xc28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xc28) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xc28) = 0;
  }
  lVar7 = *(long *)(param_1 + 0xc20);
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
    if (*(long **)(param_1 + 0xc20) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xc20) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xc20) = 0;
  }
  lVar7 = *(long *)(param_1 + 0xc38);
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
    if (*(long **)(param_1 + 0xc38) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xc38) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xc38) = 0;
  }
  if (*(long *)(param_1 + 0xc30) != 0) {
    thunk_EXT_FUN_801100000297b408();
    if (*(long **)(param_1 + 0xc30) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xc30) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xc30) = 0;
  }
  if (*(long *)(param_1 + 0xc18) != 0) {
    thunk_EXT_FUN_801100000297b408();
    if (*(long **)(param_1 + 0xc18) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0xc18) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0xc18) = 0;
  }
  iVar4 = *(int *)(param_1 + 0x1054);
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
  *(undefined4 *)(param_1 + 0x1054) = 0xffffffff;
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
  if (*(long **)(param_1 + 0xc98) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xc98) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xc98) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820c83c);
    (*pcVar3)();
  }
  FUN_fffffff0081669b0(param_1);
  return;
}

