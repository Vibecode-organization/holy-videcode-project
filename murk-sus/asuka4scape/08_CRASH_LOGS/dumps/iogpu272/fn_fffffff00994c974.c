// FUN_fffffff00994c974 @ fffffff00994c974 size=532

void FUN_fffffff00994c974(long param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  uint uVar11;
  long lVar12;
  uint local_64;
  
  uVar7 = FUN_fffffff00994bc54(param_1,param_2,param_4);
  if ((uVar7 & 1) == 0) {
    local_64 = 0;
    uVar3 = *param_2;
    uVar11 = uVar3 | 0x8000;
    uVar3 = (uVar3 & 0xaaaaaaaa | 0x8000) >> 1 | (uVar3 & 0x55555555) << 1;
    uVar3 = (uVar3 & 0xcccccccc) >> 2 | (uVar3 & 0x33333333) << 2;
    uVar3 = (uVar3 & 0xf0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f) << 4;
    uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
    lVar12 = LZCOUNT(uVar3 >> 0x10 | uVar3 << 0x10);
    if ((int)lVar12 != 0xf) {
LAB_fffffff00994c9e8:
      uVar3 = param_2[lVar12 + 1];
      if (uVar3 << 0x18 != -0x1000000 && (int)(char)uVar3 != (int)param_4) {
        uVar2 = *param_3;
        uVar10 = uVar2 | 0x8000;
        do {
          uVar4 = (uVar10 & 0xaaaaaaaa) >> 1 | (uVar10 & 0x55555555) << 1;
          uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
          uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
          uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
          lVar9 = LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10);
          local_64 = (uint)lVar9;
          if (0xe < local_64) {
            uVar10 = (~uVar2 & 0xaaaaaaaa) >> 1 | (~uVar2 & 0x55555555) << 1;
            uVar10 = (uVar10 & 0xcccccccc) >> 2 | (uVar10 & 0x33333333) << 2;
            uVar10 = (uVar10 & 0xf0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f) << 4;
            uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
            lVar9 = LZCOUNT(uVar10 >> 0x10 | uVar10 << 0x10);
            local_64 = (uint)lVar9;
            if (0xe < local_64) {
              lVar9 = 0;
              local_64 = 0;
              lVar8 = -0xf;
              goto LAB_fffffff00994ca8c;
            }
            *param_3 = 1 << (ulong)(local_64 & 0x1f) | uVar2;
            param_3[lVar9 + 1] = uVar3;
            goto LAB_fffffff00994cb18;
          }
          uVar10 = 1 << (ulong)(local_64 & 0x1f) ^ uVar10;
          uVar4 = param_3[lVar9 + 1];
        } while (uVar3 << 0x18 != uVar4 * 0x1000000);
        if (0 < (int)((uVar3 & 0xffffff00) - (uVar4 & 0xffffff00))) {
          param_3[lVar9 + 1] = uVar4 & 0xff | uVar3 & 0xffffff00;
        }
      }
      goto LAB_fffffff00994cb18;
    }
  }
LAB_fffffff00994cb30:
  iVar6 = FUN_fffffff00994b4ec(param_1,param_3);
  if (iVar6 != 0) {
    lVar12 = 0;
    *param_3 = 0;
    lVar9 = 0xf;
    do {
      param_3[lVar12 + 1] = 0xff;
      lVar12 = lVar12 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
  }
  return;
  while( true ) {
    lVar9 = lVar9 + 1;
    local_64 = (int)lVar8 + 0x10;
    bVar5 = lVar8 == -1;
    lVar8 = lVar8 + 1;
    if (bVar5) break;
LAB_fffffff00994ca8c:
    iVar6 = param_3[lVar9 + 1] << 0x18;
    if ((iVar6 == -0x1000000) ||
       ((int)((param_3[lVar9 + 1] & 0xffffff00) -
             **(int **)(*(long *)(param_1 + 0x20) + (long)(iVar6 >> 0x18) * 8)) < 1)) {
      param_3[lVar9 + 1] = uVar3;
      goto LAB_fffffff00994cb18;
    }
  }
  FUN_fffffff00994bcd8(param_1,param_3,&local_64);
  *param_3 = 1 << (ulong)(local_64 & 0x1f) | uVar2;
  lVar9 = (long)(int)local_64 * 4;
  iVar6 = (int)lVar9;
  puVar1 = (uint *)((long)param_3 + (long)iVar6 + 4);
  if (lVar9 - iVar6 != 0) {
    puVar1 = (uint *)((ulong)(param_3 + (long)(int)local_64 + 1) & 0xffffffffffff |
                     0x2bad000000000000);
  }
  *puVar1 = uVar3;
LAB_fffffff00994cb18:
  uVar11 = 1 << (ulong)((uint)lVar12 & 0x1f) ^ uVar11;
  uVar3 = (uVar11 & 0xaaaaaaaa) >> 1 | (uVar11 & 0x55555555) << 1;
  uVar3 = (uVar3 & 0xcccccccc) >> 2 | (uVar3 & 0x33333333) << 2;
  uVar3 = (uVar3 & 0xf0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f) << 4;
  uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
  lVar12 = LZCOUNT(uVar3 >> 0x10 | uVar3 << 0x10);
  if (0xe < (uint)lVar12) goto LAB_fffffff00994cb30;
  goto LAB_fffffff00994c9e8;
}

