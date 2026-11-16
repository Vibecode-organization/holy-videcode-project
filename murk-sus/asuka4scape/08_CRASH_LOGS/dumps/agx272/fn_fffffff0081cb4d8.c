// FUN_fffffff0081cb4d8 @ fffffff0081cb4d8 size=360

undefined8 FUN_fffffff0081cb4d8(long param_1)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  uVar5 = FUN_fffffff0081a7e94();
  if ((int)uVar5 == 0) {
    return uVar5;
  }
  iVar4 = FUN_fffffff0081e0b20(*(undefined8 *)(param_1 + 0x14a8));
  if (iVar4 != 0) goto LAB_fffffff0081cb5ec;
  lVar7 = 0;
  lVar2 = param_1 + 0x14f0;
  lVar6 = 1;
  do {
    if ((*(long *)(lVar2 + lVar7 * 8) != 0) &&
       (iVar4 = thunk_EXT_FUN_801100000297b3fc(), lVar3 = lVar6, iVar4 != 0))
    goto LAB_fffffff0081cb598;
    lVar7 = lVar7 + 1;
    lVar6 = lVar6 + 1;
  } while (lVar6 != 0x3d);
  iVar4 = thunk_EXT_FUN_801100000297b3fc(*(undefined8 *)(param_1 + 0x1470));
  if (iVar4 == 0) {
    iVar4 = thunk_EXT_FUN_801100000297b3fc(*(undefined8 *)(param_1 + 0x14a0));
    if ((iVar4 == 0) &&
       ((*(long *)(param_1 + 0x17c0) == 0 || (iVar4 = thunk_EXT_FUN_801100000297b3fc(), iVar4 == 0))
       )) {
      thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x14d0));
      *(undefined1 *)(param_1 + 0x14e8) = 1;
      thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x14d0));
      return 1;
    }
    thunk_EXT_FUN_801100000297b408(*(undefined8 *)(param_1 + 0x1470));
  }
  lVar7 = 0;
  lVar6 = 0x3c;
  do {
    if (*(long *)(lVar2 + lVar7 * 8) != 0) {
      thunk_EXT_FUN_801100000297b408();
    }
    lVar7 = lVar7 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
LAB_fffffff0081cb5a8:
  lVar7 = *(long *)(param_1 + 0x14a8);
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
LAB_fffffff0081cb5ec:
  FUN_fffffff0081a7a84(param_1);
  return 0;
LAB_fffffff0081cb598:
  do {
    if (*(long *)(lVar2 + (lVar3 + -1) * 8) != 0) {
      thunk_EXT_FUN_801100000297b408();
    }
    lVar7 = lVar6 + -1;
    bVar1 = 0 < lVar6;
    lVar6 = lVar7;
    lVar3 = lVar3 + -1;
  } while (lVar7 != 0 && bVar1);
  goto LAB_fffffff0081cb5a8;
}

