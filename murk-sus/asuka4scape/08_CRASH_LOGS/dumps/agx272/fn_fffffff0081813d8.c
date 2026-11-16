// FUN_fffffff0081813d8 @ fffffff0081813d8 size=4

undefined8 FUN_fffffff0081813d8(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  lVar11 = *(long *)(param_1 + 0x28);
  FUN_fffffff0081b759c(*(undefined8 *)(lVar11 + 0x4b0));
  lVar11 = *(long *)(lVar11 + 0x1ac50);
  uVar12 = *(ulong *)(*(long *)(lVar11 + 0x10) + 0x105f8);
  plVar8 = (long *)thunk_EXT_FUN_801100000389a1c8
                             ((uint)(byte)(POPCOUNT((char)uVar12) + POPCOUNT((char)(uVar12 >> 8)) +
                                           POPCOUNT((char)(uVar12 >> 0x10)) +
                                           POPCOUNT((char)(uVar12 >> 0x18)) +
                                           POPCOUNT((char)(uVar12 >> 0x20)) +
                                           POPCOUNT((char)(uVar12 >> 0x28)) +
                                           POPCOUNT((char)(uVar12 >> 0x30)) +
                                          POPCOUNT((char)(uVar12 >> 0x38))) * 0x18 + 0x10);
  if (plVar8 != (long *)0x0) {
    uStack_68 = thunk_EXT_FUN_80110000039b575c(*(undefined8 *)(lVar11 + 0xc0),0x54454d5053554d00);
    uStack_70 = thunk_EXT_FUN_80110000039b575c(*(undefined8 *)(lVar11 + 0xc0),0x54454d50434e5400);
    uVar4 = (**(code **)(*plVar8 + 200))(plVar8,&uStack_68,8);
    uVar5 = (**(code **)(*plVar8 + 200))(plVar8,&uStack_70,8);
    uVar4 = uVar4 & uVar5;
    if (uVar12 != 0) {
      uVar14 = (uVar12 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar12 & 0x5555555555555555) << 1;
      uVar14 = (uVar14 & 0xcccccccccccccccc) >> 2 | (uVar14 & 0x3333333333333333) << 2;
      uVar14 = (uVar14 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar14 = (uVar14 & 0xff00ff00ff00ff00) >> 8 | (uVar14 & 0xff00ff00ff00ff) << 8;
      uVar14 = (uVar14 & 0xffff0000ffff0000) >> 0x10 | (uVar14 & 0xffff0000ffff) << 0x10;
      uVar13 = LZCOUNT(uVar14 >> 0x20 | uVar14 << 0x20);
      lVar1 = lVar11 + 0x5e0;
      uVar14 = uVar13;
      do {
        lVar10 = uVar13 * 0x28;
        puVar2 = (undefined8 *)(lVar1 + (int)lVar10);
        if (lVar10 - (int)lVar10 != 0) {
          puVar2 = (undefined8 *)(lVar1 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uStack_78 = uVar13;
        uStack_68 = thunk_EXT_FUN_80110000039b575c(*(undefined8 *)(lVar11 + 0xc0),*puVar2);
        lVar10 = uStack_78 * 0x28 + 8;
        puVar2 = (undefined8 *)(lVar1 + (int)lVar10);
        if (lVar10 != (int)lVar10) {
          puVar2 = (undefined8 *)(lVar1 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uStack_70 = thunk_EXT_FUN_80110000039b575c(*(undefined8 *)(lVar11 + 0xc0),*puVar2);
        uVar5 = (**(code **)(*plVar8 + 200))(plVar8,&uStack_78,8);
        uVar6 = (**(code **)(*plVar8 + 200))(plVar8,&uStack_68,8);
        uVar7 = (**(code **)(*plVar8 + 200))(plVar8,&uStack_70,8);
        if ((uVar7 & uVar6 & uVar5) == 0) {
          uVar4 = 0;
        }
        uVar5 = (uint)uVar14 & 0x3f;
        uVar13 = 0;
        if (uVar5 != 0x3f) {
          uVar13 = -1L << ((ulong)(uVar5 + 1) & 0x3f);
        }
        uVar13 = uVar12 & uVar13;
        uVar3 = (uVar13 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar13 & 0x5555555555555555) << 1;
        uVar3 = (uVar3 & 0xcccccccccccccccc) >> 2 | (uVar3 & 0x3333333333333333) << 2;
        uVar3 = (uVar3 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar3 = (uVar3 & 0xff00ff00ff00ff00) >> 8 | (uVar3 & 0xff00ff00ff00ff) << 8;
        uVar3 = (uVar3 & 0xffff0000ffff0000) >> 0x10 | (uVar3 & 0xffff0000ffff) << 0x10;
        uVar5 = (uint)LZCOUNT(uVar3 >> 0x20 | uVar3 << 0x20);
        if (uVar13 == 0) {
          uVar5 = 0xffffffff;
        }
        uVar6 = uVar5 + ((uint)uVar14 & 0xffffffc0);
        uVar14 = (ulong)uVar6;
        if (0x7fffffff < uVar5) {
          uVar6 = 0xffffffff;
        }
        uVar13 = (ulong)uVar6;
      } while (uVar6 != 0xffffffff);
    }
    if (uVar4 == 0) {
      (**(code **)(*plVar8 + 0x28))(plVar8);
      plVar8 = (long *)0x0;
    }
  }
  lVar11 = *(long *)(*(long *)(param_1 + 0x20) + 8);
  plVar9 = *(long **)(lVar11 + 0x28);
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 0x28))();
  }
  *(long **)(lVar11 + 0x28) = plVar8;
  return 0;
}

