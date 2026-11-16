// FUN_fffffff00994b4ec @ fffffff00994b4ec size=144

undefined8 FUN_fffffff00994b4ec(long param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  
  uVar1 = *param_2;
  uVar3 = uVar1 | 0x8000;
  uVar1 = (uVar1 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar1 & 0x55555555) << 1;
  uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
  uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
  uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
  lVar4 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
  if ((int)lVar4 != 0xf) {
    do {
      iVar2 = param_2[lVar4 + 1] << 0x18;
      if (((iVar2 != -0x1000000) &&
          (0 < (int)((param_2[lVar4 + 1] & 0xffffff00) -
                    **(int **)(*(long *)(param_1 + 0x20) + (long)(iVar2 >> 0x18) * 8)))) &&
         (*(int *)(*(long *)(param_1 + 0x10) + 0x2d0) == 0)) {
        return 0;
      }
      uVar3 = 1 << (ulong)((uint)lVar4 & 0x1f) ^ uVar3;
      uVar1 = (uVar3 & 0xaaaaaaaa) >> 1 | (uVar3 & 0x55555555) << 1;
      uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
      uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
      uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      lVar4 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
    } while ((uint)lVar4 < 0xf);
  }
  return 1;
}

