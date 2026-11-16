// FUN_fffffff00994cc40 @ fffffff00994cc40 size=80

bool FUN_fffffff00994cc40(undefined8 param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  
  uVar1 = *param_2 | 0x8000;
  do {
    uVar2 = (uVar1 & 0xaaaaaaaa) >> 1 | (uVar1 & 0x55555555) << 1;
    uVar2 = (uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2;
    uVar2 = (uVar2 & 0xf0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f) << 4;
    uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
    lVar3 = LZCOUNT(uVar2 >> 0x10 | uVar2 << 0x10);
    uVar2 = (uint)lVar3;
    if (0xe < uVar2) break;
    uVar1 = 1 << (ulong)(uVar2 & 0x1f) ^ uVar1;
  } while ((param_2[lVar3 + 1] & 0xff) == 0xff || (char)param_2[lVar3 + 1] != param_3);
  return uVar2 < 0xf;
}

