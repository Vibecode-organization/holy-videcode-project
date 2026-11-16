// FUN_fffffff00994c2f0 @ fffffff00994c2f0 size=368

void FUN_fffffff00994c2f0(long param_1,uint param_2,uint *param_3,ulong param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  
  uVar7 = (long)(int)param_2 << 4 | 8;
  uVar1 = param_2 & 0xff;
  puVar2 = (uint *)(param_1 + 0x40 + (long)(int)uVar7);
  if (uVar7 != (long)(int)uVar7) {
    puVar2 = (uint *)(param_1 + 0x40 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
  }
  do {
    uVar5 = *param_3;
    uVar9 = uVar5 | 0x8000;
    do {
      uVar6 = (uVar9 & 0xaaaaaaaa) >> 1 | (uVar9 & 0x55555555) << 1;
      uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
      uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
      uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
      lVar11 = LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10);
      if (0xe < (uint)lVar11) {
        uVar9 = (~uVar5 & 0xaaaaaaaa) >> 1 | (~uVar5 & 0x55555555) << 1;
        uVar9 = (uVar9 & 0xcccccccc) >> 2 | (uVar9 & 0x33333333) << 2;
        uVar9 = (uVar9 & 0xf0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f) << 4;
        uVar9 = (uVar9 & 0xff00ff00) >> 8 | (uVar9 & 0xff00ff) << 8;
        lVar11 = LZCOUNT(uVar9 >> 0x10 | uVar9 << 0x10);
        if ((uint)lVar11 < 0xf) {
          iVar8 = (int)(lVar11 * 4);
          puVar4 = (uint *)((long)param_3 + (long)iVar8 + 4);
          if (lVar11 * 4 != (long)iVar8) {
            puVar4 = (uint *)((ulong)(param_3 + lVar11 + 1) & 0xffffffffffff | 0x2bad000000000000);
          }
          *param_3 = 1 << (ulong)((uint)lVar11 & 0x1f) | uVar5;
          *puVar4 = *puVar2 & 0xffffff00 | uVar1;
        }
        else {
          lVar11 = 0;
          lVar10 = 0xf;
          while( true ) {
            iVar8 = param_3[lVar11 + 1] << 0x18;
            if ((iVar8 == -0x1000000) ||
               ((int)((param_3[lVar11 + 1] & 0xffffff00) -
                     **(int **)(*(long *)(param_1 + 0x20) + (long)(iVar8 >> 0x18) * 8)) < 1)) break;
            lVar11 = lVar11 + 1;
            lVar10 = lVar10 + -1;
            if (lVar10 == 0) {
              FUN_fffffff00994c110();
              return;
            }
          }
          param_3[lVar11 + 1] = *puVar2 & 0xffffff00 | uVar1;
        }
        goto joined_r0xfffffff00994c394;
      }
      uVar9 = 1 << (ulong)((uint)lVar11 & 0x1f) ^ uVar9;
      iVar8 = (int)(lVar11 * 4);
      puVar3 = (undefined4 *)((long)param_3 + (long)iVar8 + 4);
      if (lVar11 * 4 != (long)iVar8) {
        puVar3 = (undefined4 *)((ulong)(param_3 + lVar11 + 1) & 0xffffffffffff | 0x2bad000000000000)
        ;
      }
    } while (param_2 != (int)(char)*puVar3);
    iVar8 = (int)(lVar11 * 4);
    puVar4 = (uint *)((long)param_3 + (long)iVar8 + 4);
    if (lVar11 * 4 - (long)iVar8 != 0) {
      puVar4 = (uint *)((ulong)(param_3 + lVar11 + 1) & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar4 = *puVar2 & 0xffffff00 | uVar1;
joined_r0xfffffff00994c394:
    if ((param_4 & 1) == 0) {
      return;
    }
    param_4 = 0;
    param_3 = param_3 + 0x10;
  } while( true );
}

