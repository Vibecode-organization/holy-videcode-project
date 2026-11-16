// FUN_fffffff0081fbde8 @ fffffff0081fbde8 size=460

undefined8 FUN_fffffff0081fbde8(long param_1,undefined8 param_2,ulong param_3)

{
  ulong *puVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  
  if (*(long **)(param_1 + 0x2d8) != (long *)0x0) {
    uVar3 = (**(code **)(**(long **)(param_1 + 0x2d8) + 0x160))();
    if ((7 < uVar3) || ((0x8bU >> (ulong)(uVar3 & 0x1f) & 1) == 0)) goto LAB_fffffff0081fbf8c;
    lVar2 = (ulong)uVar3 * 8;
    puVar1 = (ulong *)(&DAT_fffffff007115328 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar1 = (ulong *)((ulong)(&DAT_fffffff007115328 + lVar2) & 0xffffffffffff |
                        0x2bad000000000000);
    }
    if (((*puVar1 & param_3) != 0) &&
       (uVar4 = FUN_fffffff0081fbfb4(*(undefined8 *)(param_1 + 0x2d8),param_2), (int)uVar4 == 0)) {
      return uVar4;
    }
  }
  if (*(long **)(param_1 + 0x2e0) != (long *)0x0) {
    uVar3 = (**(code **)(**(long **)(param_1 + 0x2e0) + 0x160))();
    if ((7 < uVar3) || ((0x8bU >> (ulong)(uVar3 & 0x1f) & 1) == 0)) goto LAB_fffffff0081fbf8c;
    lVar2 = (ulong)uVar3 * 8;
    puVar1 = (ulong *)(&DAT_fffffff007115328 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar1 = (ulong *)((ulong)(&DAT_fffffff007115328 + lVar2) & 0xffffffffffff |
                        0x2bad000000000000);
    }
    if (((*puVar1 & param_3) != 0) &&
       (uVar4 = FUN_fffffff0081fbfb4(*(undefined8 *)(param_1 + 0x2e0),param_2), (int)uVar4 == 0)) {
      return uVar4;
    }
  }
  if (*(long **)(param_1 + 0x2e8) != (long *)0x0) {
    uVar3 = (**(code **)(**(long **)(param_1 + 0x2e8) + 0x160))();
    if ((7 < uVar3) || ((0x8bU >> (ulong)(uVar3 & 0x1f) & 1) == 0)) {
LAB_fffffff0081fbf8c:
      uVar4 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! unsupported\n");
      return uVar4;
    }
    lVar2 = (ulong)uVar3 * 8;
    puVar1 = (ulong *)(&DAT_fffffff007115328 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar1 = (ulong *)((ulong)(&DAT_fffffff007115328 + lVar2) & 0xffffffffffff |
                        0x2bad000000000000);
    }
    if (((*puVar1 & param_3) != 0) &&
       (uVar4 = FUN_fffffff0081fbfb4(*(undefined8 *)(param_1 + 0x2e8),param_2), (int)uVar4 == 0)) {
      return uVar4;
    }
  }
  return 1;
}

