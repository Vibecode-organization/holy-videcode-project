// FUN_fffffff0081669b0 @ fffffff0081669b0 size=656

void FUN_fffffff0081669b0(long param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  ulong unaff_x30;
  
  if ((*(byte *)(param_1 + 0x241) & 1) != 0) {
    uVar5 = (ulong)*(uint *)(param_1 + 0x350);
    if (*(uint *)(param_1 + 0x350) != 0) {
      uVar7 = 0;
      do {
        lVar6 = *(long *)(param_1 + 0x358 + uVar7 * 8);
        if (lVar6 != 0) {
          lVar8 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
          uVar5 = 0;
          if (*(ulong *)(lVar8 + 0x12b0) != 0) {
            uVar5 = (ulong)(uint)((int)lVar6 - *(int *)(lVar8 + 0x12a0)) /
                    *(ulong *)(lVar8 + 0x12b0);
          }
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x12c8));
          cVar2 = *(char *)(*(long *)(lVar8 + 0x12a8) + uVar5);
          if (cVar2 != '\0') {
            *(char *)(*(long *)(lVar8 + 0x12a8) + uVar5) = cVar2 + -1;
          }
          if (*(int *)(lVar8 + 0x12c0) != 0) {
            thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar8 + 0x1290) + 0x160));
          }
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x12c8));
          *(undefined8 *)(param_1 + 0x358 + uVar7 * 8) = 0;
          uVar5 = (ulong)*(uint *)(param_1 + 0x350);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar5);
    }
    *(undefined4 *)(param_1 + 0x350) = 0;
    if (*(long *)(param_1 + 0x468) != 0) {
      lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
      uVar5 = 0;
      if (*(ulong *)(lVar6 + 0x1230) != 0) {
        uVar5 = (ulong)(uint)((int)*(long *)(param_1 + 0x468) - *(int *)(lVar6 + 0x1220)) /
                *(ulong *)(lVar6 + 0x1230);
      }
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x1248));
      cVar2 = *(char *)(*(long *)(lVar6 + 0x1228) + uVar5);
      if (cVar2 != '\0') {
        *(char *)(*(long *)(lVar6 + 0x1228) + uVar5) = cVar2 + -1;
      }
      if (*(int *)(lVar6 + 0x1240) != 0) {
        thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar6 + 0x1210) + 0x160));
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x1248));
      *(undefined8 *)(param_1 + 0x468) = 0;
    }
    if (*(long *)(param_1 + 0x480) != 0) {
      lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
      uVar5 = 0;
      if (*(ulong *)(lVar6 + 0x11f0) != 0) {
        uVar5 = (ulong)(uint)((int)*(long *)(param_1 + 0x480) - *(int *)(lVar6 + 0x11e0)) /
                *(ulong *)(lVar6 + 0x11f0);
      }
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x1208));
      cVar2 = *(char *)(*(long *)(lVar6 + 0x11e8) + uVar5);
      if (cVar2 != '\0') {
        *(char *)(*(long *)(lVar6 + 0x11e8) + uVar5) = cVar2 + -1;
      }
      if (*(int *)(lVar6 + 0x1200) != 0) {
        thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar6 + 0x11d0) + 0x160));
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x1208));
      *(undefined8 *)(param_1 + 0x480) = 0;
    }
    iVar3 = *(int *)(param_1 + 0x1dc);
    if (iVar3 != -1) {
      lVar6 = *(long *)(param_1 + 0x10);
      if (iVar3 < *(int *)(lVar6 + 0x11e00)) {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x11df8));
        if (iVar3 < *(int *)(lVar6 + 0x11e00)) {
          lVar8 = (long)iVar3 * 4;
          piVar1 = (int *)(*(long *)(lVar6 + 0x11e28) + (long)(int)lVar8);
          if (lVar8 - (int)lVar8 != 0) {
            piVar1 = (int *)(*(long *)(lVar6 + 0x11e28) + lVar8 & 0xffffffffffffU |
                            0x2bad000000000000);
          }
          if (((*piVar1 == 0) || (iVar3 = *piVar1 + -1, *piVar1 = iVar3, iVar3 == 0)) &&
             ((*(byte *)(lVar6 + 0x11e0c) & 1) != 0)) {
            thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar6 + 0x11df0) + 0x160));
          }
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x11df8));
      }
    }
    *(undefined4 *)(param_1 + 0x1dc) = 0xffffffff;
    lVar6 = *(long *)(param_1 + 0x178);
    if (lVar6 != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x40));
      if (0 < *(long *)(lVar6 + 0x38)) {
        if (*(long *)(lVar6 + 0x50) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        if (*(long *)(lVar6 + 0x58) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        *(long *)(lVar6 + 0x38) = *(long *)(lVar6 + 0x38) + -1;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x40));
      if (*(long **)(param_1 + 0x178) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x178) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x178) = 0;
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008166c1c);
    (*pcVar4)();
  }
  thunk_EXT_FUN_801100000296a1d0(param_1);
  return;
}

