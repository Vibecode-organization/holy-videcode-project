// FUN_fffffff0081c4e48 @ fffffff0081c4e48 size=4

long * FUN_fffffff0081c4e48(long param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long *plStack_68;
  ulong uStack_60;
  undefined4 uStack_54;
  
  plVar4 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  if (plVar4 == (long *)0x0) {
    return (long *)0x0;
  }
  plVar5 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
  if (plVar5 == (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
    return (long *)0x0;
  }
  uStack_54 = 0;
  if (param_2 == 0) {
    lVar7 = 0x2278;
  }
  else {
    if (param_2 != 1) {
      uStack_60 = 0;
      goto LAB_fffffff0081c4ee8;
    }
    lVar7 = 0x2f28;
  }
  uStack_60 = *(ulong *)(*(long *)(param_1 + 0x2c0) + lVar7);
LAB_fffffff0081c4ee8:
  (**(code **)(*plVar5 + 200))(plVar5,&uStack_60,8);
  if (uStack_60 != 0) {
    uVar10 = (uStack_60 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uStack_60 & 0x5555555555555555) << 1;
    uVar10 = (uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x3333333333333333) << 2;
    uVar10 = (uVar10 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
    uVar10 = (uVar10 & 0xffff0000ffff0000) >> 0x10 | (uVar10 & 0xffff0000ffff) << 0x10;
    uVar9 = LZCOUNT(uVar10 >> 0x20 | uVar10 << 0x20);
    uVar10 = uVar9;
    do {
      if (param_2 == 0) {
        lVar7 = 0x2420;
LAB_fffffff0081c4f3c:
        lVar7 = *(long *)(param_1 + 0x2c0) + lVar7;
        lVar8 = uVar9 * 4;
        puVar2 = (undefined4 *)(lVar7 + (int)lVar8);
        if (lVar8 - (int)lVar8 != 0) {
          puVar2 = (undefined4 *)(lVar7 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uStack_54 = *puVar2;
      }
      else {
        uStack_54 = 0;
        if (param_2 == 1) {
          lVar7 = 0x3038;
          goto LAB_fffffff0081c4f3c;
        }
      }
      (**(code **)(*plVar5 + 200))(plVar5,&uStack_54,4);
      uVar6 = (uint)uVar10 & 0x3f;
      uVar9 = 0;
      if (uVar6 != 0x3f) {
        uVar9 = -1L << ((ulong)(uVar6 + 1) & 0x3f);
      }
      uVar9 = uStack_60 & uVar9;
      uVar3 = (uVar9 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar9 & 0x5555555555555555) << 1;
      uVar3 = (uVar3 & 0xcccccccccccccccc) >> 2 | (uVar3 & 0x3333333333333333) << 2;
      uVar3 = (uVar3 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar3 = (uVar3 & 0xff00ff00ff00ff00) >> 8 | (uVar3 & 0xff00ff00ff00ff) << 8;
      uVar3 = (uVar3 & 0xffff0000ffff0000) >> 0x10 | (uVar3 & 0xffff0000ffff) << 0x10;
      uVar6 = (uint)LZCOUNT(uVar3 >> 0x20 | uVar3 << 0x20);
      if (uVar9 == 0) {
        uVar6 = 0xffffffff;
      }
      uVar1 = uVar6 + ((uint)uVar10 & 0xffffffc0);
      uVar10 = (ulong)uVar1;
      if (0x7fffffff < uVar6) {
        uVar1 = 0xffffffff;
      }
      uVar9 = (ulong)uVar1;
    } while (uVar1 != 0xffffffff);
  }
  plStack_68 = plVar5;
  (**(code **)(*plVar5 + 0x20))(plVar5);
  thunk_EXT_FUN_801100000389d40c(plVar4,"ConfigData",&plStack_68);
  if (plStack_68 != (long *)0x0) {
    (**(code **)(*plStack_68 + 0x28))();
  }
  (**(code **)(*plVar5 + 0x28))(plVar5);
  return plVar4;
}

