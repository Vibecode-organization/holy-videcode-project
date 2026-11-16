// FUN_fffffff00818275c @ fffffff00818275c size=1016

undefined8 FUN_fffffff00818275c(long param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  undefined8 *puVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  
  *(undefined8 *)(param_1 + 0x138) = 0;
  *(undefined8 *)(param_1 + 0x130) = 0;
  *(undefined8 *)(param_1 + 0x148) = 0;
  *(undefined8 *)(param_1 + 0x140) = 0;
  uVar2 = (**(code **)(PTR_DAT_fffffff007ca6110 + 0xa0))();
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0xc80));
  uVar3 = *(ulong *)(lVar6 + 0xbf8);
  if (uVar3 == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0xc80));
    *(undefined8 *)(param_1 + 0x130) = 0;
LAB_fffffff008182830:
    lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0xc80));
    uVar3 = *(ulong *)(lVar6 + 0xbf8);
    if (uVar3 == 0) {
      puVar7 = (undefined8 *)(lVar6 + 0xc80);
      goto LAB_fffffff008182a88;
    }
    lVar8 = *(long *)(lVar6 + 0x920);
    uVar5 = (uVar3 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar3 & 0x5555555555555555) << 1;
    uVar5 = (uVar5 & 0xcccccccccccccccc) >> 2 | (uVar5 & 0x3333333333333333) << 2;
    uVar5 = (uVar5 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
    uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
    lVar9 = LZCOUNT(uVar5 >> 0x20 | uVar5 << 0x20);
    uVar5 = *(ulong *)(lVar6 + 0xc00 + lVar9 * 8);
    uVar10 = (uVar5 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar5 & 0x5555555555555555) << 1;
    uVar10 = (uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x3333333333333333) << 2;
    uVar10 = (uVar10 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
    uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
    uVar10 = LZCOUNT(uVar10 >> 0x20 | uVar10 << 0x20);
    uVar5 = uVar5 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
    *(ulong *)(lVar6 + 0xc00 + lVar9 * 8) = uVar5;
    *(ulong *)(lVar6 + 0xbf8) =
         uVar3 & (long)(int)~((uint)(uVar5 == 0) << (ulong)((uint)lVar9 & 0x1f));
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0xc80));
    lVar6 = lVar8 + lVar9 * 0x200 + uVar10 * 8 + 0x4c28;
    *(long *)(param_1 + 0x130) = lVar6;
    if (lVar6 != 0) goto LAB_fffffff0081828ac;
LAB_fffffff008182a94:
    uVar3 = *(ulong *)(param_1 + 0x138);
  }
  else {
    lVar8 = *(long *)(lVar6 + 0x920);
    uVar5 = (uVar3 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar3 & 0x5555555555555555) << 1;
    uVar5 = (uVar5 & 0xcccccccccccccccc) >> 2 | (uVar5 & 0x3333333333333333) << 2;
    uVar5 = (uVar5 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
    uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
    lVar9 = LZCOUNT(uVar5 >> 0x20 | uVar5 << 0x20);
    uVar5 = *(ulong *)(lVar6 + 0xc00 + lVar9 * 8);
    uVar10 = (uVar5 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar5 & 0x5555555555555555) << 1;
    uVar10 = (uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x3333333333333333) << 2;
    uVar10 = (uVar10 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
    uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
    uVar10 = LZCOUNT(uVar10 >> 0x20 | uVar10 << 0x20);
    uVar5 = uVar5 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
    *(ulong *)(lVar6 + 0xc00 + lVar9 * 8) = uVar5;
    *(ulong *)(lVar6 + 0xbf8) =
         uVar3 & (long)(int)~((uint)(uVar5 == 0) << (ulong)((uint)lVar9 & 0x1f));
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0xc80));
    lVar6 = lVar8 + lVar9 * 0x200 + uVar10 * 8 + 0x4c28;
    *(long *)(param_1 + 0x130) = lVar6;
    if (lVar6 == 0) goto LAB_fffffff008182830;
LAB_fffffff0081828ac:
    lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0xc80));
    uVar3 = *(ulong *)(lVar6 + 0xbf8);
    if (uVar3 == 0) {
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0xc80));
      *(undefined8 *)(param_1 + 0x138) = 0;
    }
    else {
      lVar8 = *(long *)(lVar6 + 0x920);
      uVar5 = (uVar3 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar3 & 0x5555555555555555) << 1;
      uVar5 = (uVar5 & 0xcccccccccccccccc) >> 2 | (uVar5 & 0x3333333333333333) << 2;
      uVar5 = (uVar5 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
      uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
      lVar9 = LZCOUNT(uVar5 >> 0x20 | uVar5 << 0x20);
      uVar5 = *(ulong *)(lVar6 + 0xc00 + lVar9 * 8);
      uVar10 = (uVar5 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar5 & 0x5555555555555555) << 1;
      uVar10 = (uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x3333333333333333) << 2;
      uVar10 = (uVar10 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
      uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
      uVar10 = LZCOUNT(uVar10 >> 0x20 | uVar10 << 0x20);
      uVar5 = uVar5 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
      *(ulong *)(lVar6 + 0xc00 + lVar9 * 8) = uVar5;
      *(ulong *)(lVar6 + 0xbf8) =
           uVar3 & (long)(int)~((uint)(uVar5 == 0) << (ulong)((uint)lVar9 & 0x1f));
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0xc80));
      uVar3 = lVar8 + lVar9 * 0x200 + uVar10 * 8 + 0x4c28;
      *(ulong *)(param_1 + 0x138) = uVar3;
      if (uVar3 != 0) {
        if (*(long *)(param_1 + 0x130) != 0) {
          return uVar2;
        }
        goto LAB_fffffff008182a9c;
      }
    }
    lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0xc80));
    uVar3 = *(ulong *)(lVar6 + 0xbf8);
    if (uVar3 == 0) {
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0xc80));
      *(undefined8 *)(param_1 + 0x138) = 0;
      uVar5 = *(ulong *)(param_1 + 0x130);
      if (uVar5 == 0) {
        return uVar2;
      }
LAB_fffffff0081829e4:
      lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
      puVar7 = (undefined8 *)(lVar6 + 0xc80);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0xc80));
      uVar3 = *(long *)(lVar6 + 0x920) + 0x4c28;
      uVar10 = uVar5 - uVar3;
      if (((uVar3 <= uVar5) && (uVar5 < *(long *)(lVar6 + 0x920) + 0x6c28U)) &&
         ((uVar10 & 0x7fffffff8) != 0x7fffffff8)) {
        uVar3 = uVar10 >> 9 & 0x3ffffff;
        *(ulong *)(lVar6 + 0xc00 + uVar3 * 8) =
             *(ulong *)(lVar6 + 0xc00 + uVar3 * 8) | 1L << (uVar10 >> 3 & 0x3f);
        *(ulong *)(lVar6 + 0xbf8) = *(ulong *)(lVar6 + 0xbf8) | 1L << (uVar10 >> 9 & 0x3f);
        lVar6 = *(long *)(lVar6 + 0x910) + 0x4c28;
        uVar10 = uVar10 & 0x7fffffff8;
        puVar1 = (undefined8 *)(lVar6 + (int)uVar10);
        if (uVar10 != (long)(int)uVar10) {
          puVar1 = (undefined8 *)(lVar6 + uVar10 & 0xffffffffffff | 0x2bad000000000000);
        }
        *puVar1 = 0;
      }
LAB_fffffff008182a88:
      thunk_EXT_FUN_8011000003222de0(*puVar7);
      *(undefined8 *)(param_1 + 0x130) = 0;
      goto LAB_fffffff008182a94;
    }
    lVar8 = *(long *)(lVar6 + 0x920);
    uVar5 = (uVar3 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar3 & 0x5555555555555555) << 1;
    uVar5 = (uVar5 & 0xcccccccccccccccc) >> 2 | (uVar5 & 0x3333333333333333) << 2;
    uVar5 = (uVar5 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
    uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
    lVar9 = LZCOUNT(uVar5 >> 0x20 | uVar5 << 0x20);
    uVar5 = *(ulong *)(lVar6 + 0xc00 + lVar9 * 8);
    uVar10 = (uVar5 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar5 & 0x5555555555555555) << 1;
    uVar10 = (uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x3333333333333333) << 2;
    uVar10 = (uVar10 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
    uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
    uVar10 = LZCOUNT(uVar10 >> 0x20 | uVar10 << 0x20);
    uVar5 = uVar5 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
    *(ulong *)(lVar6 + 0xc00 + lVar9 * 8) = uVar5;
    *(ulong *)(lVar6 + 0xbf8) =
         uVar3 & (long)(int)~((uint)(uVar5 == 0) << (ulong)((uint)lVar9 & 0x1f));
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0xc80));
    uVar3 = lVar8 + lVar9 * 0x200 + uVar10 * 8 + 0x4c28;
    *(ulong *)(param_1 + 0x138) = uVar3;
    uVar5 = *(ulong *)(param_1 + 0x130);
    if (uVar5 != 0) {
      if (uVar3 != 0) {
        return uVar2;
      }
      goto LAB_fffffff0081829e4;
    }
  }
  if (uVar3 == 0) {
    return uVar2;
  }
LAB_fffffff008182a9c:
  lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0xc80));
  uVar5 = *(long *)(lVar6 + 0x920) + 0x4c28;
  uVar10 = uVar3 - uVar5;
  uVar4 = uVar10 & 0x7fffffff8;
  if ((uVar5 <= uVar3 && uVar3 < *(long *)(lVar6 + 0x920) + 0x6c28U) && uVar4 != 0x7fffffff8) {
    uVar3 = uVar10 >> 9 & 0x3ffffff;
    *(ulong *)(lVar6 + 0xc00 + uVar3 * 8) =
         *(ulong *)(lVar6 + 0xc00 + uVar3 * 8) | 1L << (uVar10 >> 3 & 0x3f);
    *(ulong *)(lVar6 + 0xbf8) = *(ulong *)(lVar6 + 0xbf8) | 1L << (uVar10 >> 9 & 0x3f);
    lVar8 = *(long *)(lVar6 + 0x910) + 0x4c28;
    puVar7 = (undefined8 *)(lVar8 + (int)uVar4);
    if (uVar4 != (long)(int)uVar4) {
      puVar7 = (undefined8 *)(lVar8 + uVar4 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar7 = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0xc80));
  *(undefined8 *)(param_1 + 0x138) = 0;
  return uVar2;
}

