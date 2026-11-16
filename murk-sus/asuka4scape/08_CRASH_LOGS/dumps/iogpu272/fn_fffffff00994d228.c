// FUN_fffffff00994d228 @ fffffff00994d228 size=168

void FUN_fffffff00994d228(long *param_1,uint *param_2)

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
      if (iVar2 != -0x1000000) {
        (**(code **)(*param_1 + 0xb8))(param_1,iVar2 >> 0x18,param_2[lVar4 + 1] & 0xffffff00);
      }
      uVar3 = 1 << (ulong)((uint)lVar4 & 0x1f) ^ uVar3;
      uVar1 = (uVar3 & 0xaaaaaaaa) >> 1 | (uVar3 & 0x55555555) << 1;
      uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
      uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
      uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      lVar4 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
    } while ((uint)lVar4 < 0xf);
  }
  return;
}

