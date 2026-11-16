// FUN_fffffff00994c860 @ fffffff00994c860 size=276

void FUN_fffffff00994c860(undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  
  lVar5 = 0;
  *param_3 = 0;
  lVar7 = 0xf;
  do {
    param_3[lVar5 + 1] = 0xff;
    lVar5 = lVar5 + 1;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  uVar3 = FUN_fffffff00994bc54(param_1,param_2,param_4);
  if ((uVar3 & 1) == 0) {
    uVar4 = *param_3;
    uVar8 = *param_2;
    uVar6 = uVar8 | 0x8000;
    uVar8 = (uVar8 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar8 & 0x55555555) << 1;
    uVar8 = (uVar8 & 0xcccccccc) >> 2 | (uVar8 & 0x33333333) << 2;
    uVar8 = (uVar8 & 0xf0f0f0f0) >> 4 | (uVar8 & 0xf0f0f0f) << 4;
    uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
    lVar5 = LZCOUNT(uVar8 >> 0x10 | uVar8 << 0x10);
    if ((int)lVar5 != 0xf) {
      uVar8 = 0;
      do {
        uVar1 = param_2[lVar5 + 1];
        if ((uVar1 & 0xff) != 0xff && (int)(char)uVar1 != (int)param_4) {
          uVar4 = uVar4 | 1 << (ulong)(uVar8 & 0x1f);
          param_3[(long)(int)uVar8 + 1] = uVar1;
          uVar8 = uVar8 + 1;
        }
        uVar6 = 1 << (ulong)((uint)lVar5 & 0x1f) ^ uVar6;
        uVar1 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
        uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
        uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
        uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
        lVar5 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
      } while ((uint)lVar5 < 0xf);
    }
    *param_3 = uVar4;
  }
  iVar2 = FUN_fffffff00994b4ec(param_1,param_3);
  if (iVar2 != 0) {
    lVar5 = 0;
    *param_3 = 0;
    lVar7 = 0xf;
    do {
      param_3[lVar5 + 1] = 0xff;
      lVar5 = lVar5 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
  }
  return;
}

