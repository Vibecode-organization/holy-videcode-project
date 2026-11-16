// FUN_fffffff00994ba48 @ fffffff00994ba48 size=160

undefined8 FUN_fffffff00994ba48(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  long lVar7;
  
  uVar1 = *param_2;
  uVar4 = uVar1 | 0x8000;
  uVar6 = (uVar1 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar1 & 0x55555555) << 1;
  uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
  uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
  uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
  lVar7 = LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10);
  uVar5 = 1;
  uVar6 = uVar1;
  if ((int)lVar7 != 0xf) {
    do {
      uVar2 = 1 << (ulong)((uint)lVar7 & 0x1f);
      iVar3 = param_2[lVar7 + 1] << 0x18;
      if (iVar3 != -0x1000000) {
        if ((int)((param_2[lVar7 + 1] & 0xffffff00) -
                 **(int **)(*(long *)(param_1 + 0x20) + (long)(iVar3 >> 0x18) * 8)) < 1) {
          uVar6 = uVar6 & (uVar2 ^ 0xffffffff);
          param_2[lVar7 + 1] = 0xff;
        }
        else {
          uVar5 = 0;
        }
      }
      uVar4 = uVar2 ^ uVar4;
      uVar2 = (uVar4 & 0xaaaaaaaa) >> 1 | (uVar4 & 0x55555555) << 1;
      uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
      uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
      uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
      lVar7 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
    } while ((uint)lVar7 < 0xf);
    if (uVar1 != uVar6) {
      *param_2 = uVar6;
    }
  }
  return uVar5;
}

