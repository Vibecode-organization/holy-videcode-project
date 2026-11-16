// FUN_fffffff008183b4c @ fffffff008183b4c size=464

void FUN_fffffff008183b4c(long param_1)

{
  ulong uVar1;
  int *piVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = *(long *)(param_1 + 0x160);
  if ((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x40));
    if (0 < *(long *)(lVar4 + 0x38)) {
      if (*(long *)(lVar4 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar4 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar4 + 0x38) = *(long *)(lVar4 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x40));
  }
  piVar2 = *(int **)(param_1 + 0x68);
  if (piVar2 != (int *)0x0) {
    do {
    } while (*piVar2 != piVar2[0x10]);
  }
  lVar4 = *(long *)(param_1 + 200);
  if ((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x40));
    if (0 < *(long *)(lVar4 + 0x38)) {
      if (*(long *)(lVar4 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar4 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar4 + 0x38) = *(long *)(lVar4 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x40));
  }
  lVar4 = *(long *)(param_1 + 0xd0);
  if ((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x40));
    if (0 < *(long *)(lVar4 + 0x38)) {
      if (*(long *)(lVar4 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar4 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar4 + 0x38) = *(long *)(lVar4 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x40));
  }
  lVar4 = *(long *)(param_1 + 0xd8);
  if ((lVar4 != 0) && (*(long *)(lVar4 + 0x38) != 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x40));
    if (0 < *(long *)(lVar4 + 0x38)) {
      if (*(long *)(lVar4 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar4 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar4 + 0x38) = *(long *)(lVar4 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x40));
  }
  if (*(long *)(param_1 + 0x60) != 0) {
    uVar5 = *(ulong *)(*(long *)(param_1 + 0x60) + 0x74);
    uVar3 = *(ulong *)(param_1 + 0xb8);
    uVar1 = -uVar3;
    if (uVar5 < uVar3) {
      uVar1 = ~uVar3;
    }
    if (uVar5 + uVar1 != 0) {
      thunk_EXT_FUN_801100000320d864(1,0,0,((uVar5 + uVar1) * 0x7d) / 3,0);
      *(ulong *)(param_1 + 0xb8) = uVar5;
    }
  }
  return;
}

