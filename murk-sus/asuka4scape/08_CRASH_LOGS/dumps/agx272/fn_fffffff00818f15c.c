// FUN_fffffff00818f15c @ fffffff00818f15c size=860

void FUN_fffffff00818f15c(long param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  code *pcVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined4 uVar8;
  ulong uVar9;
  ulong unaff_x30;
  
  lVar5 = *(long *)(param_1 + 0x610);
  if (lVar5 == 0) {
    return;
  }
  if (*(int *)(lVar5 + 0x98) != 0) {
    uVar9 = 0;
    do {
      if (*(int *)(param_1 + 0x44c) == 1) {
        uVar8 = *(undefined4 *)(param_1 + 0x450);
      }
      else {
        uVar8 = 2;
      }
      lVar5 = *(long *)(lVar5 + 0x28 + uVar9 * 8);
      uVar2 = *(uint *)(param_1 + 0x7ec);
      uVar7 = (ulong)uVar2;
      plVar4 = *(long **)(lVar5 + 0x218);
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x110))(plVar4,uVar7,uVar8);
      }
      (**(code **)(**(long **)(lVar5 + 0x220) + 0x110))(*(long **)(lVar5 + 0x220),uVar7,uVar8);
      if ((5 < uVar2) || ((0x37U >> (ulong)(uVar2 & 0x1f) & 1) == 0)) goto LAB_fffffff00818f48c;
      lVar6 = uVar7 * 4;
      puVar1 = (undefined4 *)(&DAT_fffffff007115cc0 + (int)lVar6);
      if (lVar6 - (int)lVar6 != 0) {
        puVar1 = (undefined4 *)
                 ((ulong)(&DAT_fffffff007115cc0 + lVar6) & 0xffffffffffff | 0x2bad000000000000);
      }
      thunk_EXT_FUN_8011000002958c50(lVar5,*puVar1);
      uVar9 = uVar9 + 1;
      lVar5 = *(long *)(param_1 + 0x610);
    } while (uVar9 < *(uint *)(lVar5 + 0x98));
  }
  if (*(int *)(lVar5 + 0x9c) != 0) {
    uVar9 = 0;
    do {
      if (*(int *)(param_1 + 0x44c) == 1) {
        uVar8 = *(undefined4 *)(param_1 + 0x450);
      }
      else {
        uVar8 = 2;
      }
      lVar5 = *(long *)(lVar5 + 0x48 + uVar9 * 8);
      uVar2 = *(uint *)(param_1 + 0x7ec);
      plVar4 = *(long **)(lVar5 + 0x218);
      (**(code **)(*plVar4 + 0x110))(plVar4,(ulong)uVar2,uVar8);
      if ((5 < uVar2) || ((0x37U >> (ulong)(uVar2 & 0x1f) & 1) == 0)) {
LAB_fffffff00818f48c:
        thunk_EXT_FUN_8011000003a49114
                  ("AGXk: %s:%d:%s: !!! Invalid priority %d used for work queue 0x%p\n");
        return;
      }
      lVar6 = (ulong)uVar2 * 4;
      puVar1 = (undefined4 *)(&DAT_fffffff007115cc0 + (int)lVar6);
      if (lVar6 - (int)lVar6 != 0) {
        puVar1 = (undefined4 *)
                 ((ulong)(&DAT_fffffff007115cc0 + lVar6) & 0xffffffffffff | 0x2bad000000000000);
      }
      thunk_EXT_FUN_8011000002958c50(lVar5,*puVar1);
      uVar9 = uVar9 + 1;
      lVar5 = *(long *)(param_1 + 0x610);
    } while (uVar9 < *(uint *)(lVar5 + 0x9c));
  }
  if (*(long *)(lVar5 + 0x68) == 0) {
    lVar6 = *(long *)(lVar5 + 0x80);
  }
  else {
    if (*(int *)(param_1 + 0x44c) == 1) {
      uVar8 = *(undefined4 *)(param_1 + 0x450);
    }
    else {
      uVar8 = 2;
    }
    FUN_fffffff0082148e8(*(long *)(lVar5 + 0x68),*(undefined4 *)(param_1 + 0x7ec),uVar8);
    lVar5 = *(long *)(param_1 + 0x610);
    lVar6 = *(long *)(lVar5 + 0x80);
  }
  if (lVar6 == 0) {
    lVar6 = *(long *)(lVar5 + 0x70);
  }
  else {
    if (*(int *)(param_1 + 0x44c) == 1) {
      uVar8 = *(undefined4 *)(param_1 + 0x450);
    }
    else {
      uVar8 = 2;
    }
    FUN_fffffff0082149fc(lVar6,*(undefined4 *)(param_1 + 0x7ec),uVar8);
    lVar5 = *(long *)(param_1 + 0x610);
    lVar6 = *(long *)(lVar5 + 0x70);
  }
  if (lVar6 == 0) {
    lVar6 = *(long *)(lVar5 + 0x88);
  }
  else {
    if (*(int *)(param_1 + 0x44c) == 1) {
      uVar8 = *(undefined4 *)(param_1 + 0x450);
    }
    else {
      uVar8 = 2;
    }
    FUN_fffffff0082148e8(lVar6,*(undefined4 *)(param_1 + 0x7ec),uVar8);
    lVar5 = *(long *)(param_1 + 0x610);
    lVar6 = *(long *)(lVar5 + 0x88);
  }
  if (lVar6 == 0) {
    lVar6 = *(long *)(lVar5 + 0x78);
  }
  else {
    if (*(int *)(param_1 + 0x44c) == 1) {
      uVar8 = *(undefined4 *)(param_1 + 0x450);
    }
    else {
      uVar8 = 2;
    }
    FUN_fffffff0082149fc(lVar6,*(undefined4 *)(param_1 + 0x7ec),uVar8);
    lVar5 = *(long *)(param_1 + 0x610);
    lVar6 = *(long *)(lVar5 + 0x78);
  }
  if (lVar6 == 0) {
    lVar5 = *(long *)(lVar5 + 0x90);
  }
  else {
    if (*(int *)(param_1 + 0x44c) == 1) {
      uVar8 = *(undefined4 *)(param_1 + 0x450);
    }
    else {
      uVar8 = 2;
    }
    FUN_fffffff0082148e8(lVar6,*(undefined4 *)(param_1 + 0x7ec),uVar8);
    lVar5 = *(long *)(*(long *)(param_1 + 0x610) + 0x90);
  }
  if (lVar5 != 0) {
    if (*(int *)(param_1 + 0x44c) == 1) {
      uVar8 = *(undefined4 *)(param_1 + 0x450);
    }
    else {
      uVar8 = 2;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      FUN_fffffff0082149fc(lVar5,*(undefined4 *)(param_1 + 0x7ec),uVar8);
      return;
    }
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818f488);
    (*pcVar3)();
  }
  return;
}

