// FUN_fffffff0081f189c @ fffffff0081f189c size=152

void FUN_fffffff0081f189c(long param_1)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  
  uVar2 = *(uint *)(*(long *)(param_1 + 8) + 0x48);
  uVar5 = (ulong)uVar2;
  if (uVar2 != 0) {
    lVar3 = *(long *)(*(long *)(param_1 + 8) + 0x40);
    if (uVar2 == 1) {
      uVar4 = 0;
    }
    else {
      lVar6 = 0;
      uVar4 = uVar5 & 0xfffffffe;
      uVar8 = uVar4;
      do {
        lVar7 = *(long *)(lVar3 + (lVar6 * 8 | 8U));
        *(undefined4 *)(*(long *)(lVar3 + lVar6 * 8) + 8) = 0;
        *(undefined4 *)(lVar7 + 8) = 0;
        lVar6 = lVar6 + 2;
        uVar8 = uVar8 - 2;
      } while (uVar8 != 0);
      if (uVar4 == uVar5) goto LAB_fffffff0081f1928;
    }
    lVar6 = uVar5 - uVar4;
    do {
      lVar7 = uVar4 * 8;
      plVar1 = (long *)(lVar3 + (int)lVar7);
      if (lVar7 - (int)lVar7 != 0) {
        plVar1 = (long *)(lVar3 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(undefined4 *)(*plVar1 + 8) = 0;
      uVar4 = uVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
LAB_fffffff0081f1928:
  thunk_EXT_FUN_8011000003a61cc0(param_1 + 0x18,0x1505);
  return;
}

