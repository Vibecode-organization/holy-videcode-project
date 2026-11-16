// FUN_fffffff00994cbb8 @ fffffff00994cbb8 size=136

undefined8 FUN_fffffff00994cbb8(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  
  uVar1 = *param_2;
  uVar2 = uVar1 | 0x8000;
  uVar1 = (uVar1 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar1 & 0x55555555) << 1;
  uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
  uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
  uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
  lVar3 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
  if ((int)lVar3 != 0xf) {
    do {
      uVar1 = param_2[lVar3 + 1] << 0x18;
      if ((uVar1 != 0xff000000) &&
         (0 < (int)((param_2[lVar3 + 1] & 0xffffff00) -
                   *(int *)(param_1 + 0x40 + (((long)((ulong)uVar1 << 0x20) >> 0x38) << 4 | 0xcU))))
         ) {
        return 0;
      }
      uVar2 = 1 << (ulong)((uint)lVar3 & 0x1f) ^ uVar2;
      uVar1 = (uVar2 & 0xaaaaaaaa) >> 1 | (uVar2 & 0x55555555) << 1;
      uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
      uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
      uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      lVar3 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
    } while ((uint)lVar3 < 0xf);
  }
  return 1;
}

