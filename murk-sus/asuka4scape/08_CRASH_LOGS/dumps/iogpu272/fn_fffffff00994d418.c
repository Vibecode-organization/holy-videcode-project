// FUN_fffffff00994d418 @ fffffff00994d418 size=100

bool FUN_fffffff00994d418(undefined8 param_1,uint *param_2,uint *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  
  uVar3 = *param_2 | 0x8000;
  do {
    uVar4 = (uVar3 & 0xaaaaaaaa) >> 1 | (uVar3 & 0x55555555) << 1;
    uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
    uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
    uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
    lVar5 = LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10);
    uVar4 = (uint)lVar5;
    if (0xe < uVar4) goto LAB_fffffff00994d470;
    uVar2 = 1 << (ulong)(uVar4 & 0x1f);
    uVar3 = uVar2 ^ uVar3;
    uVar1 = param_2[lVar5 + 1];
  } while ((uVar1 & 0xff) == 0xff || (char)uVar1 != param_4);
  *param_3 = uVar2 | *param_3;
  param_3[lVar5 + 1] = uVar1;
LAB_fffffff00994d470:
  return uVar4 < 0xf;
}

