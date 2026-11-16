// FUN_fffffff00996d494 @ fffffff00996d494 size=628

void FUN_fffffff00996d494(long param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  ulong unaff_x30;
  
  lVar3 = *(long *)(param_1 + 0x18);
  if (lVar3 != 0) {
    if (0 < *(int *)(param_1 + 0x20)) {
      lVar3 = 0;
      do {
        (**(code **)(**(long **)(*(long *)(param_1 + 0x18) + lVar3 * 8) + 0x28))();
        lVar3 = lVar3 + 1;
      } while (lVar3 < *(int *)(param_1 + 0x20));
      lVar3 = *(long *)(param_1 + 0x18);
    }
    lVar5 = -0x8000000000000000;
    if (-1 < *(int *)(param_1 + 0x24)) {
      lVar5 = (long)*(int *)(param_1 + 0x24) << 3;
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1818,lVar3,lVar5);
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  lVar3 = *(long *)(param_1 + 0x28);
  if (lVar3 != 0) {
    lVar5 = -0x8000000000000000;
    if (-1 < *(int *)(param_1 + 0x34)) {
      lVar5 = (long)*(int *)(param_1 + 0x34) << 3;
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1868,lVar3,lVar5);
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (*(long *)(param_1 + 0x38) != 0) {
    lVar3 = *(long *)(param_1 + 0x38);
    do {
      plVar6 = (long *)(lVar3 + 0x50);
      lVar5 = *plVar6;
      uVar1 = 0xe00002eb;
      if ((*(byte *)(param_1 + 0x4c) & 1) == 0) {
        uVar1 = 0;
      }
      thunk_EXT_FUN_8011000002c3d314(*(undefined8 *)(lVar3 + 0x40),uVar1);
      lVar4 = *plVar6;
      if (lVar4 == 0) {
        plVar6 = *(long **)(lVar3 + 0x58);
        if (*plVar6 != lVar3) goto LAB_fffffff00996d6f8;
        *(long **)(param_1 + 0x40) = plVar6;
      }
      else {
        if (*(long **)(lVar4 + 0x58) != plVar6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00996d708);
          (*pcVar2)();
        }
        if (**(long **)(lVar3 + 0x58) != lVar3) {
LAB_fffffff00996d6f8:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00996d700);
          (*pcVar2)();
        }
        *(long **)(lVar4 + 0x58) = *(long **)(lVar3 + 0x58);
        plVar6 = *(long **)(lVar3 + 0x58);
      }
      *plVar6 = lVar4;
      (**(code **)(**(long **)(lVar3 + 0x40) + 0x28))();
      *(undefined8 *)(lVar3 + 0x40) = 0;
      thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff0ae8,lVar3);
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + -1;
      lVar3 = lVar5;
    } while (lVar5 != 0);
  }
  if (*(long **)(param_1 + 0x68) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x68) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x68) = 0;
  if (*(long **)(param_1 + 0x60) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x60) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x60) = 0;
  if (*(long **)(param_1 + 0x58) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x58) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x58) = 0;
  if (*(long **)(param_1 + 0x50) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x50) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996d6ec);
    (*pcVar2)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

