// FUN_fffffff0081c4e4c @ fffffff0081c4e4c size=540

long * FUN_fffffff0081c4e4c(long param_1,int param_2)

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
  long *local_68;
  ulong local_60;
  undefined4 local_54;
  
  plVar4 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  if (plVar4 == (long *)0x0) {
    return (long *)0x0;
  }
  plVar5 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
  if (plVar5 == (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
    return (long *)0x0;
  }
  local_54 = 0;
  if (param_2 == 0) {
    lVar7 = 0x2278;
  }
  else {
    if (param_2 != 1) {
      local_60 = 0;
      goto LAB_fffffff0081c4ee8;
    }
    lVar7 = 0x2f28;
  }
  local_60 = *(ulong *)(*(long *)(param_1 + 0x2c0) + lVar7);
LAB_fffffff0081c4ee8:
  (**(code **)(*plVar5 + 200))(plVar5,&local_60,8);
  if (local_60 != 0) {
    uVar10 = (local_60 & 0xaaaaaaaaaaaaaaaa) >> 1 | (local_60 & 0x5555555555555555) << 1;
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
        local_54 = *puVar2;
      }
      else {
        local_54 = 0;
        if (param_2 == 1) {
          lVar7 = 0x3038;
          goto LAB_fffffff0081c4f3c;
        }
      }
      (**(code **)(*plVar5 + 200))(plVar5,&local_54,4);
      uVar6 = (uint)uVar10 & 0x3f;
      uVar9 = 0;
      if (uVar6 != 0x3f) {
        uVar9 = -1L << ((ulong)(uVar6 + 1) & 0x3f);
      }
      uVar9 = local_60 & uVar9;
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
  local_68 = plVar5;
  (**(code **)(*plVar5 + 0x20))(plVar5);
  thunk_EXT_FUN_801100000389d40c(plVar4,"ConfigData",&local_68);
  if (local_68 != (long *)0x0) {
    (**(code **)(*local_68 + 0x28))();
  }
  (**(code **)(*plVar5 + 0x28))(plVar5);
  return plVar4;
}

