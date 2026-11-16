// FUN_fffffff00994c508 @ fffffff00994c508 size=324

undefined8 FUN_fffffff00994c508(long param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  long lVar10;
  
  uVar1 = *param_2;
  uVar7 = uVar1 | 0x8000;
  uVar1 = (uVar1 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar1 & 0x55555555) << 1;
  uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
  uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
  uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
  lVar8 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
  if ((int)lVar8 == 0xf) {
    return 1;
  }
  do {
    uVar1 = param_2[lVar8 + 1];
    iVar3 = uVar1 << 0x18;
    if (iVar3 != -0x1000000) {
      uVar9 = uVar1 & 0xffffff00;
      if (0 < (int)(uVar9 - **(int **)(*(long *)(param_1 + 0x20) + (long)(iVar3 >> 0x18) * 8))) {
        uVar2 = *param_3;
        uVar6 = uVar2 | 0x8000;
        do {
          uVar4 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
          uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
          uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
          uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
          lVar5 = LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10);
          if (0xe < (uint)lVar5) {
            uVar9 = (~uVar2 & 0xaaaaaaaa) >> 1 | (~uVar2 & 0x55555555) << 1;
            uVar9 = (uVar9 & 0xcccccccc) >> 2 | (uVar9 & 0x33333333) << 2;
            uVar9 = (uVar9 & 0xf0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f) << 4;
            uVar9 = (uVar9 & 0xff00ff00) >> 8 | (uVar9 & 0xff00ff) << 8;
            lVar5 = LZCOUNT(uVar9 >> 0x10 | uVar9 << 0x10);
            uVar9 = (uint)lVar5;
            if (uVar9 < 0xf) {
              *param_3 = 1 << (ulong)(uVar9 & 0x1f) | uVar2;
              param_3[lVar5 + 1] = uVar1;
            }
            else {
              lVar5 = 0;
              lVar10 = 0xf;
              while( true ) {
                iVar3 = param_3[lVar5 + 1] << 0x18;
                if ((iVar3 == -0x1000000) ||
                   ((int)((param_3[lVar5 + 1] & 0xffffff00) -
                         **(int **)(*(long *)(param_1 + 0x20) + (long)(iVar3 >> 0x18) * 8)) < 1))
                break;
                lVar5 = lVar5 + 1;
                lVar10 = lVar10 + -1;
                if (lVar10 == 0) {
                  return 0;
                }
              }
              param_3[lVar5 + 1] = uVar1;
            }
            goto LAB_fffffff00994c624;
          }
          uVar6 = 1 << (ulong)((uint)lVar5 & 0x1f) ^ uVar6;
          uVar4 = param_3[lVar5 + 1];
        } while (iVar3 != uVar4 * 0x1000000);
        if (0 < (int)(uVar9 - (uVar4 & 0xffffff00))) {
          param_3[lVar5 + 1] = uVar4 & 0xff | uVar9;
        }
      }
    }
LAB_fffffff00994c624:
    uVar7 = 1 << (ulong)((uint)lVar8 & 0x1f) ^ uVar7;
    uVar1 = (uVar7 & 0xaaaaaaaa) >> 1 | (uVar7 & 0x55555555) << 1;
    uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
    uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
    uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
    lVar8 = LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
    if (0xe < (uint)lVar8) {
      return 1;
    }
  } while( true );
}

