// FUN_fffffff009968d64 @ fffffff009968d64 size=340

long * FUN_fffffff009968d64(long *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  int iVar11;
  
  plVar5 = param_1;
  if ((*(byte *)(param_1 + 10) & 1) != 0) {
    uVar8 = 0;
    lVar6 = param_1[3];
    do {
      uVar9 = *(ulong *)(lVar6 + uVar8 * 8);
      if (uVar9 != 0) {
        do {
          uVar7 = (uVar9 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar9 & 0x5555555555555555) << 1;
          uVar7 = (uVar7 & 0xcccccccccccccccc) >> 2 | (uVar7 & 0x3333333333333333) << 2;
          uVar7 = (uVar7 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar7 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar7 = (uVar7 & 0xff00ff00ff00ff00) >> 8 | (uVar7 & 0xff00ff00ff00ff) << 8;
          uVar7 = (uVar7 & 0xffff0000ffff0000) >> 0x10 | (uVar7 & 0xffff0000ffff) << 0x10;
          uVar7 = LZCOUNT(uVar7 >> 0x20 | uVar7 << 0x20);
          uVar10 = uVar7 | (uint)((int)uVar8 << 6);
          lVar6 = uVar10 * 8;
          iVar11 = (int)lVar6;
          puVar2 = (undefined8 *)(*param_1 + (long)iVar11);
          if (lVar6 - iVar11 != 0) {
            puVar2 = (undefined8 *)(*param_1 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar9 = uVar9 & (1L << (uVar7 & 0x3f) ^ 0xffffffffffffffffU);
          lVar4 = (**(code **)(*(long *)*puVar2 + 0x108))();
          puVar2 = (undefined8 *)(*param_1 + (long)iVar11);
          if (lVar6 - iVar11 != 0) {
            puVar2 = (undefined8 *)(*param_1 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
          }
          param_1[9] = param_1[9] - lVar4;
          plVar5 = (long *)(**(code **)(*(long *)*puVar2 + 0x28))();
          lVar6 = uVar10 * 4;
          puVar3 = (undefined4 *)(param_1[1] + (long)(int)lVar6);
          if (lVar6 - (int)lVar6 != 0) {
            puVar3 = (undefined4 *)(param_1[1] + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar2 = 0;
          *puVar3 = 0;
          *(int *)(param_1 + 7) = (int)param_1[7] + -1;
        } while (uVar9 != 0);
        lVar6 = param_1[3];
        *(undefined8 *)(lVar6 + uVar8 * 8) = 0;
      }
      uVar1 = (int)uVar8 + 1;
      uVar8 = (ulong)uVar1;
    } while (uVar1 <= *(uint *)(param_1 + 6));
    if ((int)param_1[7] != 0) {
      FUN_fffffff009983c74();
      return (long *)0x0;
    }
  }
  return plVar5;
}

