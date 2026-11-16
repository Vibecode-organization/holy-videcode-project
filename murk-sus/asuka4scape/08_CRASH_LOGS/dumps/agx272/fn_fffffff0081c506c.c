// FUN_fffffff0081c506c @ fffffff0081c506c size=524

long * FUN_fffffff0081c506c(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  long *local_70;
  uint local_68;
  undefined4 local_64;
  
  plVar3 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  if (plVar3 != (long *)0x0) {
    plVar4 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
    if (plVar4 == (long *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
      plVar3 = (long *)0x0;
    }
    else {
      local_64 = 0;
      if (param_2 == 1) {
        local_68 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d1c);
      }
      else {
        local_68 = 0;
        if (param_2 == 0) {
          local_68 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d18);
        }
      }
      (**(code **)(*plVar4 + 200))(plVar4,&local_68,4);
      for (uVar1 = local_68; uVar1 != 0; uVar1 = uVar1 & (uVar2 ^ 0xffffffff)) {
        if (param_2 == 1) {
          uVar6 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d1c);
        }
        else if (param_2 == 0) {
          uVar6 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d18);
        }
        else {
          uVar6 = 0;
        }
        uVar2 = (uVar1 & 0xaaaaaaaa) >> 1 | (uVar1 & 0x55555555) << 1;
        uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
        uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
        uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
        lVar5 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
        uVar2 = 1 << (ulong)((uint)lVar5 & 0x1f);
        if ((uVar6 & uVar2) == 0) {
LAB_fffffff0081c5154:
          local_64 = 0;
        }
        else {
          if (param_2 == 1) {
            lVar7 = *(long *)(param_1 + 0x2c0) + 0x2d08;
          }
          else {
            if (param_2 != 0) goto LAB_fffffff0081c5154;
            lVar7 = *(long *)(param_1 + 0x2c0) + 0x2cc8;
          }
          local_64 = *(undefined4 *)(lVar7 + lVar5 * 4);
        }
        (**(code **)(*plVar4 + 200))(plVar4,&local_64,4);
      }
      local_70 = plVar4;
      (**(code **)(*plVar4 + 0x20))(plVar4);
      thunk_EXT_FUN_801100000389d40c(plVar3,"ConfigData",&local_70);
      if (local_70 != (long *)0x0) {
        (**(code **)(*local_70 + 0x28))();
      }
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  return plVar3;
}

