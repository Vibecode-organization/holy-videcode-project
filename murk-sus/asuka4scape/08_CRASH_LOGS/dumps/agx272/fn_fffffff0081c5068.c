// FUN_fffffff0081c5068 @ fffffff0081c5068 size=4

long * FUN_fffffff0081c5068(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  long *plStack_70;
  uint uStack_68;
  undefined4 uStack_64;
  
  plVar3 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  if (plVar3 != (long *)0x0) {
    plVar4 = (long *)thunk_EXT_FUN_801100000389a1c8(4);
    if (plVar4 == (long *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
      plVar3 = (long *)0x0;
    }
    else {
      uStack_64 = 0;
      if (param_2 == 1) {
        uStack_68 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d1c);
      }
      else {
        uStack_68 = 0;
        if (param_2 == 0) {
          uStack_68 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x2d18);
        }
      }
      (**(code **)(*plVar4 + 200))(plVar4,&uStack_68,4);
      for (uVar1 = uStack_68; uVar1 != 0; uVar1 = uVar1 & (uVar2 ^ 0xffffffff)) {
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
          uStack_64 = 0;
        }
        else {
          if (param_2 == 1) {
            lVar7 = *(long *)(param_1 + 0x2c0) + 0x2d08;
          }
          else {
            if (param_2 != 0) goto LAB_fffffff0081c5154;
            lVar7 = *(long *)(param_1 + 0x2c0) + 0x2cc8;
          }
          uStack_64 = *(undefined4 *)(lVar7 + lVar5 * 4);
        }
        (**(code **)(*plVar4 + 200))(plVar4,&uStack_64,4);
      }
      plStack_70 = plVar4;
      (**(code **)(*plVar4 + 0x20))(plVar4);
      thunk_EXT_FUN_801100000389d40c(plVar3,"ConfigData",&plStack_70);
      if (plStack_70 != (long *)0x0) {
        (**(code **)(*plStack_70 + 0x28))();
      }
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  return plVar3;
}

