// FUN_fffffff00994c02c @ fffffff00994c02c size=228

undefined8 FUN_fffffff00994c02c(long param_1,uint param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  
  uVar2 = *param_3;
  uVar6 = uVar2 | 0x8000;
  do {
    uVar4 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
    uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
    uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
    uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
    lVar5 = LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10);
    if (0xe < (uint)lVar5) {
      uVar6 = (~uVar2 & 0xaaaaaaaa) >> 1 | (~uVar2 & 0x55555555) << 1;
      uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
      uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
      uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
      lVar5 = LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10);
      if ((uint)lVar5 < 0xf) {
        *param_3 = 1 << (ulong)((uint)lVar5 & 0x1f) | uVar2;
      }
      else {
        lVar5 = 0;
        while( true ) {
          iVar3 = param_3[lVar5 + 1] << 0x18;
          if ((iVar3 == -0x1000000) ||
             ((int)((param_3[lVar5 + 1] & 0xffffff00) -
                   **(int **)(*(long *)(param_1 + 0x20) + (long)(iVar3 >> 0x18) * 8)) < 1)) break;
          lVar5 = lVar5 + 1;
          if (lVar5 == 0xf) {
            return 0;
          }
        }
      }
      break;
    }
    uVar6 = 1 << (ulong)((uint)lVar5 & 0x1f) ^ uVar6;
  } while (param_2 != (int)(char)param_3[lVar5 + 1]);
  uVar7 = (long)(int)param_2 << 4 | 8;
  puVar1 = (uint *)(param_1 + 0x40 + (long)(int)uVar7);
  if (uVar7 != (long)(int)uVar7) {
    puVar1 = (uint *)(param_1 + 0x40 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
  }
  param_3[lVar5 + 1] = *puVar1 & 0xffffff00 | param_2 & 0xff;
  return 1;
}

