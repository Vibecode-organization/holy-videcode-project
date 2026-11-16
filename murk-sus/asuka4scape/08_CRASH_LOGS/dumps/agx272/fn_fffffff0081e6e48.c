// FUN_fffffff0081e6e48 @ fffffff0081e6e48 size=172

int FUN_fffffff0081e6e48(long param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  
  uVar5 = *(ulong *)(param_1 + 0x90);
  if (uVar5 != 0) {
    iVar4 = 0;
    uVar5 = (uVar5 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar5 & 0x5555555555555555) << 1;
    uVar5 = (uVar5 & 0xcccccccccccccccc) >> 2 | (uVar5 & 0x3333333333333333) << 2;
    uVar5 = (uVar5 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
    uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
    uVar6 = LZCOUNT(uVar5 >> 0x20 | uVar5 << 0x20);
    uVar5 = uVar6;
    do {
      lVar8 = uVar5 * 8;
      puVar3 = (undefined8 *)(*(long *)(param_1 + 0x98) + (long)(int)lVar8);
      if (lVar8 - (int)lVar8 != 0) {
        puVar3 = (undefined8 *)
                 (*(long *)(param_1 + 0x98) + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar9 = *puVar3;
      iVar4 = iVar4 + (uint)(byte)(POPCOUNT((char)uVar9) + POPCOUNT((char)((ulong)uVar9 >> 8)) +
                                   POPCOUNT((char)((ulong)uVar9 >> 0x10)) +
                                   POPCOUNT((char)((ulong)uVar9 >> 0x18)) +
                                   POPCOUNT((char)((ulong)uVar9 >> 0x20)) +
                                   POPCOUNT((char)((ulong)uVar9 >> 0x28)) +
                                   POPCOUNT((char)((ulong)uVar9 >> 0x30)) +
                                  POPCOUNT((char)((ulong)uVar9 >> 0x38)));
      uVar7 = (uint)uVar6 & 0x3f;
      uVar2 = 0;
      if (uVar7 != 0x3f) {
        uVar2 = -1L << ((ulong)(uVar7 + 1) & 0x3f);
      }
      uVar2 = *(ulong *)(param_1 + 0x90 + (uVar5 >> 3 & 0x1ffffffffffffff8)) & uVar2;
      uVar5 = (uVar2 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar2 & 0x5555555555555555) << 1;
      uVar5 = (uVar5 & 0xcccccccccccccccc) >> 2 | (uVar5 & 0x3333333333333333) << 2;
      uVar5 = (uVar5 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
      uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
      uVar7 = (uint)LZCOUNT(uVar5 >> 0x20 | uVar5 << 0x20);
      if (uVar2 == 0) {
        uVar7 = 0xffffffff;
      }
      uVar1 = uVar7 + ((uint)uVar6 & 0xffffffc0);
      uVar6 = (ulong)uVar1;
      if (0x7fffffff < uVar7) {
        uVar1 = 0xffffffff;
      }
      uVar5 = (ulong)uVar1;
    } while (uVar1 != 0xffffffff);
    return iVar4;
  }
  return 0;
}

