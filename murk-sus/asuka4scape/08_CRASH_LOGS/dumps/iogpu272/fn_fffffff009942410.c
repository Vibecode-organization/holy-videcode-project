// FUN_fffffff009942410 @ fffffff009942410 size=232

undefined8 FUN_fffffff009942410(long *param_1,uint *param_2)

{
  ulong uVar1;
  ulong *puVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 uVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  uint uVar11;
  long lVar12;
  
  lVar4 = *param_1;
  if ((int)param_1[1] != *(int *)(lVar4 + 0xa4)) {
    uVar11 = *(uint *)(param_1 + 2);
    uVar7 = (ulong)uVar11;
    if (uVar11 < *(uint *)((long)param_1 + 0xc)) {
      lVar8 = *(long *)(lVar4 + 0xa8);
      iVar6 = *(int *)((long)param_1 + 0x14);
      lVar10 = *(uint *)((long)param_1 + 0xc) - uVar7;
      iVar9 = uVar11 * -0x40;
      while( true ) {
        uVar11 = uVar11 + 1;
        lVar12 = uVar7 * 8;
        puVar2 = (ulong *)(lVar8 + (int)lVar12);
        if (lVar12 - (int)lVar12 != 0) {
          puVar2 = (ulong *)(lVar8 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar1 = 0;
        if (iVar6 < 0x3f) {
          uVar1 = -1L << ((ulong)(iVar6 + 1) & 0x3f);
        }
        uVar1 = uVar1 & *puVar2;
        if (uVar1 != 0) break;
        uVar7 = uVar7 + 1;
        *(uint *)(param_1 + 2) = uVar11;
        iVar9 = iVar9 + -0x40;
        iVar6 = -1;
        lVar10 = lVar10 + -1;
        if (lVar10 == 0) {
          *(undefined4 *)((long)param_1 + 0x14) = 0xffffffff;
          return 0;
        }
      }
      uVar7 = (uVar1 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar1 & 0x5555555555555555) << 1;
      uVar7 = (uVar7 & 0xcccccccccccccccc) >> 2 | (uVar7 & 0x3333333333333333) << 2;
      uVar7 = (uVar7 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar7 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar7 = (uVar7 & 0xff00ff00ff00ff00) >> 8 | (uVar7 & 0xff00ff00ff00ff) << 8;
      uVar7 = (uVar7 & 0xffff0000ffff0000) >> 0x10 | (uVar7 & 0xffff0000ffff) << 0x10;
      iVar6 = (int)LZCOUNT(uVar7 >> 0x20 | uVar7 << 0x20);
      uVar11 = iVar6 - iVar9;
      lVar10 = (ulong)uVar11 * 8;
      puVar3 = (undefined8 *)(*(long *)(lVar4 + 0x98) + (long)(int)lVar10);
      if (lVar10 != (int)lVar10) {
        puVar3 = (undefined8 *)
                 (*(long *)(lVar4 + 0x98) + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(int *)((long)param_1 + 0x14) = iVar6;
      *param_2 = uVar11;
      uVar5 = *puVar3;
      *(int *)(param_1 + 1) = (int)param_1[1] + 1;
      return uVar5;
    }
  }
  return 0;
}

