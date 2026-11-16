// FUN_fffffff00994c1a8 @ fffffff00994c1a8 size=328

void FUN_fffffff00994c1a8(long param_1,uint param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  
  uVar2 = *param_3;
  uVar7 = uVar2 | 0x8000;
  do {
    uVar4 = (uVar7 & 0xaaaaaaaa) >> 1 | (uVar7 & 0x55555555) << 1;
    uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
    uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
    uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
    lVar5 = LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10);
    if (0xe < (uint)lVar5) {
      uVar7 = (~uVar2 & 0xaaaaaaaa) >> 1 | (~uVar2 & 0x55555555) << 1;
      uVar7 = (uVar7 & 0xcccccccc) >> 2 | (uVar7 & 0x33333333) << 2;
      uVar7 = (uVar7 & 0xf0f0f0f0) >> 4 | (uVar7 & 0xf0f0f0f) << 4;
      uVar7 = (uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8;
      lVar5 = LZCOUNT(uVar7 >> 0x10 | uVar7 << 0x10);
      if (0xe < (uint)lVar5) {
        lVar5 = 0;
        lVar6 = 0xf;
        while( true ) {
          iVar3 = param_3[lVar5 + 1] << 0x18;
          if ((iVar3 == -0x1000000) ||
             ((int)((param_3[lVar5 + 1] & 0xffffff00) -
                   **(int **)(*(long *)(param_1 + 0x20) + (long)(iVar3 >> 0x18) * 8)) < 1)) break;
          lVar5 = lVar5 + 1;
          lVar6 = lVar6 + -1;
          if (lVar6 == 0) {
            FUN_fffffff00994c110();
            return;
          }
        }
        uVar8 = (long)(int)param_2 << 4 | 8;
        puVar1 = (uint *)(param_1 + 0x40 + (long)(int)uVar8);
        if (uVar8 != (long)(int)uVar8) {
          puVar1 = (uint *)(param_1 + 0x40 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
        }
        param_3[lVar5 + 1] = *puVar1 & 0xffffff00 | param_2 & 0xff;
        return;
      }
      uVar8 = (long)(int)param_2 << 4 | 8;
      puVar1 = (uint *)(param_1 + 0x40 + (long)(int)uVar8);
      if (uVar8 != (long)(int)uVar8) {
        puVar1 = (uint *)(param_1 + 0x40 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
      }
      *param_3 = 1 << (ulong)((uint)lVar5 & 0x1f) | uVar2;
      uVar7 = *puVar1;
      goto LAB_fffffff00994c260;
    }
    uVar7 = 1 << (ulong)((uint)lVar5 & 0x1f) ^ uVar7;
  } while (param_2 != (int)(char)param_3[lVar5 + 1]);
  uVar8 = (long)(int)param_2 << 4 | 8;
  puVar1 = (uint *)(param_1 + 0x40 + (long)(int)uVar8);
  if (uVar8 != (long)(int)uVar8) {
    puVar1 = (uint *)(param_1 + 0x40 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar7 = *puVar1;
LAB_fffffff00994c260:
  param_3[lVar5 + 1] = uVar7 & 0xffffff00 | param_2 & 0xff;
  return;
}

